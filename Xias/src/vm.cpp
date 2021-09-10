#include "vm.h"

#include "types.h"
#include "object.h"
#include "memory.h"

#include <iostream>

#define AS_DOUBLE(value) (value->as.Double)
#define AS_FLOAT(value) (value->as.Float)
#define AS_INT(value) (value->as.Int)
#define AS_UINT(value) (value->as.UInt)
#define AS_BOOL(value) (value->as.Bool)
#define AS_OBJ(value) (value->as.Object)

#define LEFT_OPERAND(type) ((sp - 2)->as.type)
#define RIGHT_OPERAND(type) ((sp - 1)->as.type)
#define UNARY_OPERAND(type) ((sp - 1)->as.type)

#define READ_CONSTANT(type) frame->Function->Code.Constants[(++frame->ip)->Data].as.type;
#define READ_CONST() frame->Function->Code.Constants[(++frame->ip)->Data] 
#define READ_SHORT() (++frame->ip)->Data

#define DEC() (sp--)
#define POP() (*sp--)

#define GC_HEAP_GROW_FACTOR 1.75f

#ifdef DEBUG_LOG_GC 
#define ALLOCATE_OBJ(type, objectType) \
	AllocObject<type>(objectType); \
	printf("allocate %zu bytes for %s\n", sizeof(type), #objectType);
#else
#define ALLOCATE_OBJ(type, objectType) AllocObject<type>(objectType)
#endif

namespace Xias {

	Vm::Vm()
	{
		m_Frames.resize(64);
		m_Stack.resize(64);
		sp = m_Stack.data();
		m_StackBack = sp;
	}

	Vm::~Vm()
	{
		FreeObjects();
	}

	void Vm::RegisterFunction(const std::string& name, NativeFn function)
	{
		push(OBJ_VAL(NewNative(function)));
		AddGlobal(name, m_Stack[0]);
		DEC();
	}

	void Vm::RegisterVoidFunction(const std::string& name, VoidNativeFn function)
	{
		push(OBJ_VAL(NewVoidNative(function)));
		AddGlobal(name, m_Stack[0]);
		DEC();
	}

	StringObject* Vm::TakeString(char* chars, x_ulong length)
	{
		StringObject* interned = FindInternedString(chars, length);
		if (interned)
		{
			delete[] chars;
			return interned;
		}

		return AllocateString(chars, length);
	}

	StringObject* Vm::CopyString(const char* chars, x_ulong length)
	{
		StringObject* interned = FindInternedString(chars, length);
		if (interned) return interned;

		char* heapChars = AllocArray<char>(length + 1);
		memcpy(heapChars, chars, length);
		heapChars[length] = '\0';
		return AllocateString(heapChars, length);
	}

	InstanceObject* Vm::NewInstance(x_class xClass)
	{
		InstanceObject* native = ALLOCATE_OBJ(InstanceObject, ObjectType::instance_object);
		native->Class = xClass;
		native->Members.resize(xClass->MemberCount);
		return native;
	}

	void Vm::AddGlobal(const std::string& name, Value& value)
	{
		m_GlobalNames.insert({ name, m_Globals.size() });
		m_Globals.emplace_back(value);
	}

	Value Vm::GetGlobal(const std::string& name)
	{
		auto iter = m_GlobalNames.find(name);
		if (iter != m_GlobalNames.end())
			return m_Globals[iter->second];
		Error("Global not found!");
		return Value{ 0U };
	}

	void Vm::CallFunction(Bytecode& bytecode)
	{
		// Creating function to hold supplied bytecode
		FunctionObject* function = NewFunction();
		function->Code = bytecode;
#ifdef X_DEBUG
		if (sp != &m_Stack[0])
		{
			Error("Stack pointer was not at the front!");
		}
		if (m_FrameCount != 0)
		{
			Error("There are residual stack frames!");
		}
#endif
		RunMethod(function);
	}

	void Vm::CollectGarbage()
	{
#ifdef DEBUG_LOG_GC
		size_t before = m_BytesAllocated;
		std::printf("-- gc begin\n");
		std::printf("   %zu bytes currently allocated\n", before);
#endif

		MarkRoots();
		TraceReferences();
		RemoveInterned();
		Sweep();

		m_NextGC = (size_t)(m_BytesAllocated * GC_HEAP_GROW_FACTOR);

#ifdef DEBUG_LOG_GC
		printf("-- gc end\n");
		printf("   collected %zu bytes (from %zu to %zu)\n", before - m_BytesAllocated, before, m_BytesAllocated);
		printf("   next gc at %zu\n", m_NextGC);
#endif
	}

	void Vm::FreeObjects()
	{
		x_object* obj = m_Objects;
		while (obj != nullptr)
		{
			x_object* next = obj->Next;
			FreeObject(obj);
			obj = next;
		}
	}

	void Vm::FreeObject(x_object* object)
	{
#ifdef DEBUG_LOG_GC
		printf("%p free type %d\n", (void*)object, object->Type);
#endif

		switch (object->Type)
		{
			case ObjectType::string_object:
			{
				StringObject* string = (StringObject*)object;
				DeallocArray(string->Chars, string->Size);
				Dealloc(string);
				break;
			}
			case ObjectType::instance_object:
			{
				InstanceObject* instance = (InstanceObject*)object;
				Dealloc(instance);
				break;
			}
			case ObjectType::function_object:
			{
				FunctionObject* function = (FunctionObject*)object;
				Dealloc(function);
				break;
			}
			case ObjectType::native_function_object:
			{
				NativeObject* function = (NativeObject*)object;
				Dealloc(function);
				break;
			}
			case ObjectType::void_native_function_object:
			{
				VoidNativeObject* function = (VoidNativeObject*)object;
				Dealloc(function);
				break;
			}
			default:
			{
				Error("FreeObject: Unknown object type!");
			}
		}
	}

	void Vm::Error(const char* msg)
	{
		std::cerr << msg << std::endl;
	}

	StringObject* Vm::FindInternedString(const char* chars, x_ulong length)
	{
		for (StringObject* string : m_InternedStrings)
		{
			if (length == string->Size &&
				std::memcmp(chars, string->Chars, length) == 0)
			{
				return string;
			}
		}
		return nullptr;
	}

	void Vm::MarkRoots()
	{
		for (int i = 0; i < sp - m_Stack.data(); i++)
		{
			if (m_Stack[i].Type == ValueType::Object)
				MarkObject(m_Stack[i].as.Object);
		}

		for (auto const& [key, val] : m_GlobalNames)
		{
			if (m_Globals[val].Type == ValueType::Object)
				MarkObject(m_Globals[val].as.Object);
		}

		for (x_class xClass : m_Classes)
		{
			for (FunctionObject* function : xClass->Functions)
			{
				MarkObject((x_object*)function);
			}
		}
	}

	void Vm::TraceReferences()
	{
		for (int i = 0; i < m_GrayStack.size(); i++)
		{
			BlackenObject(m_GrayStack[i]);
		}
		m_GrayStack.clear();
	}

	void Vm::RemoveInterned()
	{
		for (auto iter = m_InternedStrings.begin(); iter != m_InternedStrings.end();)
		{
			if (!(*iter)->Object.IsMarked)
			{
				iter = m_InternedStrings.erase(iter);
			}
			else
			{
				iter++;
			}
		}
	}

	void Vm::Sweep()
	{
		x_object* previous = nullptr;
		x_object* object = m_Objects;
		while (object != nullptr)
		{
			if (object->IsMarked)
			{
				object->IsMarked = false;
				previous = object;
				object = object->Next;
			}
			else
			{
				x_object* unreached = object;
				object = object->Next;
				if (previous != nullptr)
					previous->Next = object;
				else
					m_Objects = object;

				FreeObject(unreached);
			}
		}
	}

	void Vm::BlackenObject(x_object* object)
	{
		switch (object->Type)
		{
			case ObjectType::native_function_object: break;
			case ObjectType::void_native_function_object: break;
			case ObjectType::instance_object:
			{
				InstanceObject* instance = (InstanceObject*)object;
				for (const Value& value : instance->Members)
				{
					if (value.Type == ValueType::Object)
						MarkObject(value.as.Object);
				}
				break;
			}
			case ObjectType::function_object:
			{
				FunctionObject* function = (FunctionObject*)object;
				MarkObject((x_object*)function->Name);
				for (Value value : function->Code.Constants)
				{
					if (value.Type == ValueType::Object)
						MarkObject(value.as.Object);
				}

				break;
			}
			case ObjectType::string_object: break;
			default:
			{
				Error("Blackenobject: Unknown object type!");
			}
		}
#ifdef DEBUG_LOG_GC
		printf("%p blacken ", (void*)object);
		printf("\n");
#endif
	}

	void Vm::MarkObject(x_object* object)
	{
		if (object == nullptr) return;
		if (object->IsMarked) return;
		object->IsMarked = true;

		m_GrayStack.emplace_back(object);
#ifdef DEBUG_LOG_GC
		printf("%p mark ", (void*)object);
		// TODO: A function that prints any object type
		printf("\n");
#endif
	}

	template<typename T>
	inline T* Vm::Alloc()
	{
		m_BytesAllocated += sizeof(T);
#ifdef DEBUG_STRESS_GC
		CollectGarbage();
#else
		if (m_BytesAllocated > m_NextGC) { CollectGarbage(); }
#endif
		return new T();
	}

	template<typename T>
	inline T* Vm::AllocArray(x_ulong count)
	{
		m_BytesAllocated += sizeof(T) * count;
#ifdef DEBUG_STRESS_GC
		CollectGarbage();
#else
		if (m_BytesAllocated > m_NextGC) { CollectGarbage(); }
#endif
		return new T[count]();
	}

	template<typename T>
	void Vm::Dealloc(T* ptr)
	{
		m_BytesAllocated -= sizeof(T);
		delete ptr;
	}

	template<typename T>
	void Vm::DeallocArray(T* ptr, x_ulong size)
	{
		m_BytesAllocated -= sizeof(T) * size;
		delete[] ptr;
	}

	template<typename T>
	T* Vm::AllocObject(ObjectType type)
	{
		T* obj = Alloc<T>();
		obj->Object.Type = type;
		obj->Object.IsMarked = false;

		obj->Object.Next = m_Objects;
		m_Objects = &obj->Object;
		return obj;
	}

	StringObject* Vm::AllocateString(char* chars, x_ulong length)
	{
		StringObject* string = ALLOCATE_OBJ(StringObject, ObjectType::string_object);
		string->Size = length;
		string->Chars = chars;
		m_InternedStrings.emplace(string);
		return string;
	}

	FunctionObject* Vm::NewFunction()
	{
		FunctionObject* function = ALLOCATE_OBJ(FunctionObject, ObjectType::function_object);
		function->Arity = 0;
		// function->Code is default initalized
		function->Name = nullptr;
		return function;
	}

	NativeObject* Vm::NewNative(NativeFn function)
	{
		NativeObject* native = ALLOCATE_OBJ(NativeObject, ObjectType::native_function_object);
		native->Function = function;
		return native;
	}

	VoidNativeObject* Vm::NewVoidNative(VoidNativeFn function)
	{
		VoidNativeObject* native = ALLOCATE_OBJ(VoidNativeObject, ObjectType::void_native_function_object);
		native->Function = function;
		return native;
	}

	void Vm::CallFunction(FunctionObject* function)
	{
		CallFrame* newFrame = &m_Frames[m_FrameCount++];
		newFrame->Function = function;
		newFrame->ip = function->Code.Code.data();
		newFrame->fp = sp - function->Arity - 1;
	}

	inline void Vm::push(Value& value)
	{
		*sp++ = value;
	}

	Value Vm::RunMethod(x_method method)
	{
		push(OBJ_VAL(method));
		CallFunction(method);
		return Run();
	}

	Value Vm::Run()
	{
		CallFrame* frame = &m_Frames[m_FrameCount - 1];

		sp = &m_Stack[1];
		OpType* ie = &(*frame->Function->Code.Code.begin()) + frame->Function->Code.Code.size();
		if (frame->ip == ie)
			return 0;

		while (frame->ip != ie)
		{
#ifdef X_DEBUG
			if (frame->ip >= ie)
			{
				std::cout << "overpassed function end!\n";
			}
#endif
			switch (frame->ip->Op)
			{
				// Arithmetic
				case Instruction::int_inc: { UNARY_OPERAND(Int)++; break; }
				case Instruction::int_dec: { UNARY_OPERAND(Int)--; break; }
				case Instruction::int_add: { LEFT_OPERAND(Int) += RIGHT_OPERAND(Int); DEC(); break; }
				case Instruction::int_sub: { LEFT_OPERAND(Int) -= RIGHT_OPERAND(Int); DEC(); break; }
				case Instruction::int_mul: { LEFT_OPERAND(Int) *= RIGHT_OPERAND(Int); DEC(); break; }
				case Instruction::int_div: { LEFT_OPERAND(Int) /= RIGHT_OPERAND(Int); DEC(); break; }
				case Instruction::int_mod: { LEFT_OPERAND(Int) %= RIGHT_OPERAND(Int); DEC(); break; }
				case Instruction::int_pow:
				{
					LEFT_OPERAND(Int) = (x_long)std::pow(LEFT_OPERAND(Int), RIGHT_OPERAND(Int));
					DEC();
					break;
				}
				case Instruction::uint_inc: { UNARY_OPERAND(UInt)++; break; }
				case Instruction::uint_dec: { UNARY_OPERAND(UInt)--; break; }
				case Instruction::uint_add: { LEFT_OPERAND(UInt) += RIGHT_OPERAND(UInt); DEC(); break; }
				case Instruction::uint_sub: { LEFT_OPERAND(UInt) -= RIGHT_OPERAND(UInt); DEC(); break; }
				case Instruction::uint_mul: { LEFT_OPERAND(UInt) *= RIGHT_OPERAND(UInt); DEC(); break; }
				case Instruction::uint_div: { LEFT_OPERAND(UInt) /= RIGHT_OPERAND(UInt); DEC(); break; }
				case Instruction::uint_mod: { LEFT_OPERAND(UInt) %= RIGHT_OPERAND(UInt); DEC(); break; }
				case Instruction::uint_pow:
				{
					LEFT_OPERAND(UInt) = (x_ulong)std::pow(LEFT_OPERAND(UInt), RIGHT_OPERAND(UInt));
					DEC();
					break;
				}
				case Instruction::double_inc: { UNARY_OPERAND(Double)++; break; }
				case Instruction::double_dec: { UNARY_OPERAND(Double)--; break; }
				case Instruction::double_add: { LEFT_OPERAND(Double) += RIGHT_OPERAND(Double); DEC(); break; }
				case Instruction::double_sub: { LEFT_OPERAND(Double) -= RIGHT_OPERAND(Double); DEC(); break; }
				case Instruction::double_mul: { LEFT_OPERAND(Double) *= RIGHT_OPERAND(Double); DEC(); break; }
				case Instruction::double_div: { LEFT_OPERAND(Double) /= RIGHT_OPERAND(Double); DEC(); break; }
				case Instruction::double_mod:
				{
					LEFT_OPERAND(Double) = (x_double)std::fmod(LEFT_OPERAND(Double), RIGHT_OPERAND(Double));
					DEC();
					break;
				}
				case Instruction::double_pow:
				{
					LEFT_OPERAND(Double) = (x_double)std::pow(LEFT_OPERAND(Double), RIGHT_OPERAND(Double));
					DEC();
					break;
				}
				case Instruction::float_inc: { UNARY_OPERAND(Float)++; break; }
				case Instruction::float_dec: { UNARY_OPERAND(Float)--; break; }
				case Instruction::float_add: { LEFT_OPERAND(Float) += RIGHT_OPERAND(Float); DEC(); break; }
				case Instruction::float_sub: { LEFT_OPERAND(Float) -= RIGHT_OPERAND(Float); DEC(); break; }
				case Instruction::float_mul: { LEFT_OPERAND(Float) *= RIGHT_OPERAND(Float); DEC(); break; }
				case Instruction::float_div: { LEFT_OPERAND(Float) /= RIGHT_OPERAND(Float); DEC(); break; }
				case Instruction::float_mod:
				{
					LEFT_OPERAND(Float) = (x_float)std::fmod(LEFT_OPERAND(Float), RIGHT_OPERAND(Float));
					DEC();
					break;
				}
				case Instruction::float_pow:
				{
					LEFT_OPERAND(Float) = (x_float)std::powf(LEFT_OPERAND(Float), RIGHT_OPERAND(Float));
					DEC();
					break;
				}

				// String operations
				case Instruction::string_add:
				{
					StringObject* left = ((StringObject*)LEFT_OPERAND(Object));
					StringObject* right = ((StringObject*)RIGHT_OPERAND(Object));
					x_ulong length = left->Size + right->Size;
					char* chars = AllocArray<char>(length + 1);
					memcpy(chars, left->Chars, left->Size);
					memcpy(chars + left->Size, right->Chars, right->Size);
					chars[length] = '\0';
					LEFT_OPERAND(Object) = (x_object*)TakeString(chars, length);
					DEC();
					break;
				}
				case Instruction::string_size:
				{
					StringObject* string = ((StringObject*)UNARY_OPERAND(Object));
					UNARY_OPERAND(UInt) = string->Size;
					break;
				}

				// Casting
				case Instruction::int_from_uint: { UNARY_OPERAND(Int) = (x_long)UNARY_OPERAND(UInt); break; }
				case Instruction::int_from_double: { UNARY_OPERAND(Int) = (x_long)UNARY_OPERAND(Double); break; }
				case Instruction::int_from_float: { UNARY_OPERAND(Int) = (x_long)UNARY_OPERAND(Float); break; }
				case Instruction::uint_from_int: { UNARY_OPERAND(UInt) = (x_ulong)UNARY_OPERAND(Int); break; }
				case Instruction::uint_from_double: { UNARY_OPERAND(UInt) = (x_ulong)UNARY_OPERAND(Double); break; }
				case Instruction::uint_from_float: { UNARY_OPERAND(UInt) = (x_ulong)UNARY_OPERAND(Float); break; }
				case Instruction::double_from_int: { UNARY_OPERAND(Double) = (x_double)UNARY_OPERAND(Int); break; }
				case Instruction::double_from_uint: { UNARY_OPERAND(Double) = (x_double)UNARY_OPERAND(UInt); break; }
				case Instruction::double_from_float: { UNARY_OPERAND(Double) = (x_double)UNARY_OPERAND(Float); break; }
				case Instruction::float_from_int: { UNARY_OPERAND(Float) = (x_float)UNARY_OPERAND(Int); break; }
				case Instruction::float_from_uint: { UNARY_OPERAND(Float) = (x_float)UNARY_OPERAND(UInt); break; }
				case Instruction::float_from_double: { UNARY_OPERAND(Float) = (x_float)UNARY_OPERAND(Double); break; }

				// Trueness testing
				case Instruction::bool_from_int: { UNARY_OPERAND(Bool) = UNARY_OPERAND(Int) == true; break; }
				case Instruction::bool_from_uint: { UNARY_OPERAND(Bool) = UNARY_OPERAND(UInt) == true; break; }
				case Instruction::bool_from_double: { UNARY_OPERAND(Bool) = UNARY_OPERAND(Double) == true; break; }
				case Instruction::bool_from_float: { UNARY_OPERAND(Bool) = UNARY_OPERAND(Float) == true; break; }
				case Instruction::bool_from_string:
				{
					StringObject* string = (StringObject*)UNARY_OPERAND(Object);
					UNARY_OPERAND(Bool) = string->Size > 0;
					break;
				}

				// Comparisons
				case Instruction::int_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Int) == RIGHT_OPERAND(Int)); DEC(); break; }
				case Instruction::int_not_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Int) != RIGHT_OPERAND(Int)); DEC(); break; }
				case Instruction::int_greater: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Int) > RIGHT_OPERAND(Int)); DEC(); break; }
				case Instruction::int_less: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Int) < RIGHT_OPERAND(Int)); DEC(); break; }
				case Instruction::int_greater_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Int) >= RIGHT_OPERAND(Int)); DEC(); break; }
				case Instruction::int_less_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Int) <= RIGHT_OPERAND(Int)); DEC(); break; }
				case Instruction::uint_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(UInt) == RIGHT_OPERAND(UInt)); DEC(); break; }
				case Instruction::uint_not_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(UInt) != RIGHT_OPERAND(UInt)); DEC(); break; }
				case Instruction::uint_greater: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(UInt) > RIGHT_OPERAND(UInt)); DEC(); break; }
				case Instruction::uint_less: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(UInt) < RIGHT_OPERAND(UInt)); DEC(); break; }
				case Instruction::uint_greater_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(UInt) >= RIGHT_OPERAND(UInt)); DEC(); break; }
				case Instruction::uint_less_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(UInt) <= RIGHT_OPERAND(UInt)); DEC(); break; }
				case Instruction::double_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Double) == RIGHT_OPERAND(Double)); DEC(); break; }
				case Instruction::double_not_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Double) != RIGHT_OPERAND(Double)); DEC(); break; }
				case Instruction::double_greater: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Double) > RIGHT_OPERAND(Double)); DEC(); break; }
				case Instruction::double_less: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Double) < RIGHT_OPERAND(Double)); DEC(); break; }
				case Instruction::double_greater_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Double) >= RIGHT_OPERAND(Double)); DEC(); break; }
				case Instruction::double_less_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Double) <= RIGHT_OPERAND(Double)); DEC(); break; }
				case Instruction::float_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Float) == RIGHT_OPERAND(Float)); DEC(); break; }
				case Instruction::float_not_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Float) != RIGHT_OPERAND(Float)); DEC(); break; }
				case Instruction::float_greater: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Float) > RIGHT_OPERAND(Float)); DEC(); break; }
				case Instruction::float_less: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Float) < RIGHT_OPERAND(Float)); DEC(); break; }
				case Instruction::float_greater_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Float) >= RIGHT_OPERAND(Float)); DEC(); break; }
				case Instruction::float_less_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Float) <= RIGHT_OPERAND(Float)); DEC(); break; }
				case Instruction::string_equal:
				{
					StringObject* left = ((StringObject*)LEFT_OPERAND(Object));
					StringObject* right = ((StringObject*)RIGHT_OPERAND(Object));
					LEFT_OPERAND(Bool) = left == right;
					DEC();
					break;
				}
				case Instruction::string_not_equal:
				{
					StringObject* left = ((StringObject*)LEFT_OPERAND(Object));
					StringObject* right = ((StringObject*)RIGHT_OPERAND(Object));
					LEFT_OPERAND(Bool) = left != right;
					DEC();
					break;
				}

				// Control flow
				case Instruction::jump_if_false:
				{
					_x_short offset = READ_SHORT();
					if (UNARY_OPERAND(Bool) == false)
						frame->ip += offset;
					DEC();
					break;
				}
				case Instruction::jump_if_false_chain:
				{
					_x_short offset = READ_SHORT();
					if (UNARY_OPERAND(Bool) == false)
						frame->ip += offset;
					break;
					// NOTE: Doesn't decrement the stack pointer
				}
				case Instruction::jump:
				{
					_x_short offset = READ_SHORT();
					frame->ip += offset;
					break;
				}
				case Instruction::loop:
				{
					_x_short offset = READ_SHORT();
					frame->ip -= offset;
					break;
				}

				// Functions
				case Instruction::func_call:
				{
					_x_short argCount = READ_SHORT();
					Value* callable = (sp - (argCount + 1));
					switch (OBJ_TYPE(callable))
					{
					case ObjectType::function_object:
					{
						CallFunction((FunctionObject*)(AS_OBJ(callable)));
						frame = &m_Frames[m_FrameCount - 1];
						break;
					}
					case ObjectType::native_function_object:
					{
						NativeObject* native = (NativeObject*)(AS_OBJ(callable));
						sp -= argCount + 1;
						push(native->Function(this, argCount, sp + 1));
						break;
					}
					case ObjectType::void_native_function_object:
					{
						VoidNativeObject* native = (VoidNativeObject*)(AS_OBJ(callable));
						native->Function(this, argCount, sp - argCount);
						sp -= argCount + 1;
						break;
					}
					default:
					{
						Error("Can not call supplied object.");
						break;
					}
					}
					break;
				}
				case Instruction::func_return:
				{
					Value result = POP();
					m_FrameCount--;
					sp = frame->fp;
					if (m_FrameCount == 0)
					{
						DEC();
						return result;
					}

					push(result);
					frame = &m_Frames[m_FrameCount - 1];
					break;
				}
				case Instruction::func_return_void:
				{
					m_FrameCount--;
					sp = frame->fp;
					if (m_FrameCount == 0)
					{
						DEC();
						return 0;
					}

					frame = &m_Frames[m_FrameCount - 1];
					break;
				}

				// Variables
				case Instruction::set_global:
				{
					_x_short address = READ_SHORT();
					m_Globals[address] = *(sp - 1);
					break;
				}
				case Instruction::get_global:
				{
					_x_short address = READ_SHORT();
					push(m_Globals[address]);
					break;
				}
				case Instruction::set_local:
				{
					_x_short slot = READ_SHORT();
					frame->fp[slot] = *(sp - 1);
					break;
				}
				case Instruction::get_local:
				{
					_x_short slot = READ_SHORT();
					push(frame->fp[slot]);
					break;
				}

				case Instruction::get_field:
				{
					InstanceObject* instance = (InstanceObject*)UNARY_OPERAND(Object);
					*sp = instance->Members[READ_SHORT()];
					break;
				}
				case Instruction::set_field:
				{
					InstanceObject* instance = (InstanceObject*)LEFT_OPERAND(Object);
					instance->Members[READ_SHORT()] = POP();
					break;
				}
				case Instruction::get_member_field:
				{
					InstanceObject* instance = (InstanceObject*)AS_OBJ(frame->fp);
					*sp = instance->Members[READ_SHORT()];
					break;
				}
				case Instruction::set_member_field:
				{
					InstanceObject* instance = (InstanceObject*)AS_OBJ(frame->fp);
					instance->Members[READ_SHORT()] = POP();
					break;
				}

				case Instruction::member_method_call:
				{
					_x_short argCount = READ_SHORT();
					_x_short functionID = READ_SHORT();
					InstanceObject* instance = (InstanceObject*)AS_OBJ((sp - (argCount + 1)));
					FunctionObject* function = (instance->Class->Functions[functionID]);
					CallFunction(function);
					frame = &m_Frames[m_FrameCount - 1];
					break;
				}
				case Instruction::static_method_call:
				{
					_x_short classID = READ_SHORT();
					_x_short argCount = READ_SHORT();
					_x_short functionID = READ_SHORT();
					x_class xClass = m_Classes[classID];
					CallFunction(xClass->Functions[functionID]);
					frame = &m_Frames[m_FrameCount - 1];
					break;
				}

				// Stack Usage
				case Instruction::push_value: { *sp++ = READ_CONST(); break; }
				case Instruction::push_size:
				{
					x_ulong size = READ_CONSTANT(UInt);
					std::memcpy(sp, &READ_CONST(), size * sizeof(Value));
					sp += size;
					break;
				}
				case Instruction::pop_value: { DEC(); break; }
				case Instruction::pop_size:
				{
					x_ulong size = READ_CONSTANT(UInt);
					sp -= size;
					break;
				}

				// Printing
				case Instruction::print_int: { std::cout << UNARY_OPERAND(Int) << std::endl; break; }
				case Instruction::print_uint: { std::cout << UNARY_OPERAND(UInt) << std::endl; break; }
				case Instruction::print_double: { std::cout << UNARY_OPERAND(Double) << std::endl; break; }
				case Instruction::print_float: { std::cout << UNARY_OPERAND(Float) << std::endl; break; }
				case Instruction::print_bool: { std::cout << UNARY_OPERAND(Bool) << std::endl; break; }
				case Instruction::print_string: { std::cout << ((StringObject*)UNARY_OPERAND(Object))->Chars << std::endl; break; }
				default: Error("Unknown instruction!"); break;
			}
			frame->ip++;
		}

		return Value(0);
	}

}

#undef LEFT_OPERAND
#undef RIGHT_OPERAND
#undef UNARY_OPERAND

#undef READ_CONSTANT
#undef READ_CONST
#undef READ_SHORT

#undef DEC
#undef POP

#undef ALLOCATE_OBJ
