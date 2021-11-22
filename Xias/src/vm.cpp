#include "vm.h"

#include "types.h"
#include "object.h"
#include "memory.h"
#include "compilation_unit.h"
#include "compiler.h"

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
		m_FrameCount = 0;
		m_Frames.resize(64);
		m_Stack.resize(64);
		m_StackSize = 64;
		sp = m_Stack.data();
		m_StackBack = sp;

		m_BytesAllocated = 0;
		m_NextGC = 1024 * 4;

		AddClass("Double");
		AddClass("Float");
		AddClass("Int");
		AddClass("UInt");
		AddClass("Bool");
		AddClass("Object");
		AddClass("String");
	}

	Vm::~Vm()
	{
		FreeObjects();
	}

	bool Vm::Compile(const CompilationUnit& compilationUnit)
	{
		for (const ClassInfo& cInfo : compilationUnit.m_Classes)
		{
			AddClass(cInfo.m_QualifiedName);
		}

		for (const ClassInfo& cInfo : compilationUnit.m_Classes)
		{
			CompileClass(cInfo);
		}

		return false;
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

	StringObject* Vm::CopyString(const std::string& string)
	{
		size_t length = string.size();
		StringObject* interned = FindInternedString(string.c_str(), length);
		if (interned) return interned;

		char* heapChars = AllocArray<char>(length + 1);
		memcpy(heapChars, string.c_str(), length);
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

	x_class Vm::GetClass(const std::string& name)
	{
		auto iter = m_ClassNames.find(name);
		if (iter != m_ClassNames.end())
			return m_Classes[iter->second];
		return nullptr;
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

		for (x_class xClass : m_Classes)
		{
			delete xClass;
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
		std::cerr << sp - &m_Stack[0] << " : " << msg << std::endl;
	}

	void Vm::CompileClass(const ClassInfo& classInfo)
	{
		// If compilation fails, remove the class.

		size_t functionCount = 0;
		x_class xClass = GetClass(classInfo.m_QualifiedName);
		xClass->MemberCount = classInfo.m_Fields.size();

		FunctionObject* defaultInit = NewFunction();
		ForcePinObject((x_object*)defaultInit);
		defaultInit->Name = CopyString("<>");
		defaultInit->Code.Code.emplace_back(Instruction::create_instance);
		auto iter = m_ClassNames.find(classInfo.m_QualifiedName);
		if (iter == m_ClassNames.end())
			return;
		defaultInit->Code.Code.emplace_back(iter->second);

		for (const FieldInfo& fInfo : classInfo.m_Fields)
		{
			x_ulong fieldID = xClass->MemberIndices.size();
			xClass->MemberIndices.emplace(fInfo.m_Name, fieldID);
			CompileField(fieldID, fInfo, defaultInit);
		}

		// Default constructor
		if (classInfo.m_Constructors.empty())
		{
			defaultInit->Code.Code.emplace_back(Instruction::func_return);
			AddMethod(xClass, defaultInit);
		}
		else
		{
			for (const ConstructorInfo& mInfo : classInfo.m_Constructors)
			{
				FunctionObject* ctor = DuplicateFunction(defaultInit);
				ForcePinObject((x_object*)ctor);
				ctor->Name = CopyString(";<>;" + mInfo.m_Signature);
				ctor->Arity = mInfo.m_Parameters.size();
				CompileStatement(mInfo.m_Body, ctor);
				ctor->Code.Code.emplace_back(Instruction::func_return);
				AddMethod(xClass, ctor);
				UnPinObject((x_object*)ctor);
			}
		}

		for (const MethodInfo& mInfo : classInfo.m_Methods)
		{
			FunctionObject* method = NewFunction();
			ForcePinObject((x_object*)method);
			method->Name = CopyString(mInfo.m_Name);
			method->Arity = mInfo.m_Parameters.size();
			CompileStatement(mInfo.m_Body, method);
			AddMethod(xClass, method);
			UnPinObject((x_object*)method);
		}

		UnPinObject((x_object*)defaultInit);
	}

	void Vm::AddField(x_class xClass, const std::string& name)
	{
		xClass->MemberIndices.emplace(name, xClass->MemberIndices.size());
	}

	void Vm::AddMethod(x_class xClass, x_method method)
	{
		xClass->FunctionIndices.emplace(method->Name->Chars, xClass->FunctionIndices.size());
		xClass->Functions.emplace_back(method);
	}

	void Vm::CompileField(x_ulong fieldID, const FieldInfo& fieldInfo, x_method method)
	{
		// TODO: Account for default initialized fields
		if (fieldInfo.m_VariableInitializer.m_Children.size() > 0)
			CompileExpression(fieldInfo.m_VariableInitializer, method);
		else
			method->Code.Code.emplace_back(Instruction::literal_nullptr);

		method->Code.Code.emplace_back(Instruction::set_field);
		method->Code.Code.emplace_back(fieldID);
	}

	x_method Vm::CompileStatement(const Statement& statement)
	{
		FunctionObject* method = NewFunction();
		CompileStatement(statement, method);
		return method;
	}

	void Vm::CompileStatement(const Statement& statement, x_method method)
	{
		Compiler::Compile(this, statement, method);
	}

	XType Vm::CompileExpression(const Expression& expression, x_method method)
	{
		Compiler::Compile(this, expression, method);
		return XType::Instance; // ???
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

		for (x_object* object : m_PinnedObjects)
		{
			MarkObject(object);
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

	x_object* Vm::FindPinnedObject(x_object* object)
	{
		x_object* value;
		auto iter = std::find(m_PinnedObjects.rbegin(), m_PinnedObjects.rend(), object);
		if (iter != m_PinnedObjects.rend())
			value = *iter;
		else
			value = nullptr;
		return value;
	}

	void Vm::PinObject(x_object* object)
	{
		if (!FindPinnedObject(object))
			ForcePinObject(object);
	}

	void Vm::ForcePinObject(x_object* object)
	{
		m_PinnedObjects.emplace_back(object);
	}

	void Vm::UnPinObject(x_object* object)
	{
		std::remove(m_PinnedObjects.rbegin(), m_PinnedObjects.rend(), object);
	}

	template<typename T>
	inline T* Vm::Alloc()
	{
#ifdef DEBUG_STRESS_GC
		CollectGarbage();
#else
		if (m_BytesAllocated + sizeof(T) > m_NextGC) { CollectGarbage(); }
#endif
		m_BytesAllocated += sizeof(T);
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
		function->RequiredStackSize = 0;
		// function->Code is default initalized
		function->LocalCount = 0;
		function->Name = nullptr;
		return function;
	}

	FunctionObject* Vm::DuplicateFunction(FunctionObject* oldFunction)
	{
		FunctionObject* function = NewFunction();
		function->Arity = oldFunction->Arity;
		function->RequiredStackSize = oldFunction->RequiredStackSize;
		function->Code = oldFunction->Code;
		function->LocalCount = oldFunction->LocalCount;
		function->Name = oldFunction->Name;
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

	x_class Vm::AddClass(const std::string& name)
	{
		x_class xClass = new _x_class();
		m_ClassNames.emplace(name, m_Classes.size());
		xClass = m_Classes.emplace_back(xClass);
		xClass->Name = name;
		return xClass;
	}

	void Vm::CallFunction(FunctionObject* function)
	{
		m_StackSize += function->RequiredStackSize;
		size_t stackCapacity = m_Stack.capacity();
		if (m_StackSize > stackCapacity)
		{
			Value* oldStack = m_Stack.data();

			size_t stackMax = m_Stack.max_size();
			if (stackCapacity > stackMax / 2)
			{
				// Growth would overflow
				m_Stack.reserve(m_Stack.max_size());
#ifdef DEBUG_LOG_GC
				printf("reached max stack size\n");
#endif
			}
			else if (stackCapacity * 2 < m_StackSize)
			{
				// Find the next highest power of two
				// From The Aggregate Magic Algorithms
				// http://aggregate.org/MAGIC/
				size_t size = m_StackSize;
				size |= (size >> 1);
				size |= (size >> 2);
				size |= (size >> 4);
				size |= (size >> 8);
				size |= (size >> 16);
				size |= (size >> 32);
				m_Stack.reserve(size + 1);
#ifdef DEBUG_LOG_GC
				printf("resized stack from %zu to %zu\n", stackCapacity, size + 1);
#endif
			}
			else
			{
				m_Stack.reserve(stackCapacity * 2);
#ifdef DEBUG_LOG_GC
				printf("doubled stack from %zu to %zu\n", stackCapacity, stackCapacity * 2);
#endif
			}

			sp = m_Stack.data() + (sp - oldStack);
			for (int i = 0; i < m_FrameCount; i++)
			{
				CallFrame* frame = &m_Frames[i];
				frame->fp = m_Stack.data() + (frame->fp - oldStack);
			}
		}
		CallFrame* newFrame = &m_Frames[m_FrameCount++];
		newFrame->Function = function;
		newFrame->ip = function->Code.Code.data();
		newFrame->fp = sp - function->Arity - 1;
		newFrame->Locals.reserve(function->LocalCount);
	}

	void Vm::push(Value& value)
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
				Error("Overpassed function end!");
			}
#endif
			switch (frame->ip->Op)
			{
				// Arithmetic
				case Instruction::double_negate: { UNARY_OPERAND(Double) = -UNARY_OPERAND(Double); break; }
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
				case Instruction::float_negate: { UNARY_OPERAND(Float) = -UNARY_OPERAND(Float); break; }
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
				case Instruction::int_negate: { UNARY_OPERAND(Int) = -UNARY_OPERAND(Int); break; }
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
				case Instruction::int_shift_left: { LEFT_OPERAND(Int) = LEFT_OPERAND(Int) << RIGHT_OPERAND(Int); DEC(); break; }
				case Instruction::int_shift_right: { LEFT_OPERAND(Int) = LEFT_OPERAND(Int) >> RIGHT_OPERAND(Int); DEC(); break; }
				case Instruction::int_bit_and: { LEFT_OPERAND(Int) = LEFT_OPERAND(Int) & RIGHT_OPERAND(Int); DEC(); break; }
				case Instruction::int_bit_or: { LEFT_OPERAND(Int) = LEFT_OPERAND(Int) | RIGHT_OPERAND(Int); DEC(); break; }
				case Instruction::int_bit_xor: { LEFT_OPERAND(Int) = LEFT_OPERAND(Int) ^ RIGHT_OPERAND(Int); DEC(); break; }
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
				case Instruction::uint_shift_left: { LEFT_OPERAND(UInt) = LEFT_OPERAND(UInt) << RIGHT_OPERAND(UInt); DEC(); break; }
				case Instruction::uint_shift_right: { LEFT_OPERAND(UInt) = LEFT_OPERAND(UInt) >> RIGHT_OPERAND(UInt); DEC(); break; }
				case Instruction::uint_bit_and: { LEFT_OPERAND(UInt) = LEFT_OPERAND(UInt) & RIGHT_OPERAND(UInt); DEC(); break; }
				case Instruction::uint_bit_or: { LEFT_OPERAND(UInt) = LEFT_OPERAND(UInt) | RIGHT_OPERAND(UInt); DEC(); break; }
				case Instruction::uint_bit_xor: { LEFT_OPERAND(UInt) = LEFT_OPERAND(UInt) ^ RIGHT_OPERAND(UInt); DEC(); break; }
				case Instruction::bool_negate: { UNARY_OPERAND(Bool) = !UNARY_OPERAND(Bool); break; }
				case Instruction::bool_and: { LEFT_OPERAND(Bool) = LEFT_OPERAND(Bool) & RIGHT_OPERAND(Bool); break; }
				case Instruction::bool_or: { LEFT_OPERAND(Bool) = LEFT_OPERAND(Bool) | RIGHT_OPERAND(Bool); break; }
				case Instruction::bool_xor: { LEFT_OPERAND(Bool) = LEFT_OPERAND(Bool) ^ RIGHT_OPERAND(Bool); break; }

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
					(sp - 1)->Type = ValueType::UInt;
					break;
				}

				// Casting
#ifdef COMPLETE_TYPING
				case Instruction::double_from_int: { UNARY_OPERAND(Double) = (x_double)UNARY_OPERAND(Int); (sp - 1)->Type = ValueType::Double; break; }
				case Instruction::double_from_uint: { UNARY_OPERAND(Double) = (x_double)UNARY_OPERAND(UInt); (sp - 1)->Type = ValueType::Double; break; }
				case Instruction::double_from_float: { UNARY_OPERAND(Double) = (x_double)UNARY_OPERAND(Float); (sp - 1)->Type = ValueType::Double; break; }
				case Instruction::float_from_int: { UNARY_OPERAND(Float) = (x_float)UNARY_OPERAND(Int); (sp - 1)->Type = ValueType::Float; break; }
				case Instruction::float_from_uint: { UNARY_OPERAND(Float) = (x_float)UNARY_OPERAND(UInt); (sp - 1)->Type = ValueType::Float; break; }
				case Instruction::float_from_double: { UNARY_OPERAND(Float) = (x_float)UNARY_OPERAND(Double); (sp - 1)->Type = ValueType::Float; break; }
				case Instruction::int_from_uint: { UNARY_OPERAND(Int) = (x_long)UNARY_OPERAND(UInt); (sp - 1)->Type = ValueType::Int; break; }
				case Instruction::int_from_double: { UNARY_OPERAND(Int) = (x_long)UNARY_OPERAND(Double); (sp - 1)->Type = ValueType::Int; break; }
				case Instruction::int_from_float: { UNARY_OPERAND(Int) = (x_long)UNARY_OPERAND(Float); (sp - 1)->Type = ValueType::Int; break; }
				case Instruction::uint_from_int: { UNARY_OPERAND(UInt) = (x_ulong)UNARY_OPERAND(Int); (sp - 1)->Type = ValueType::UInt; break; }
				case Instruction::uint_from_double: { UNARY_OPERAND(UInt) = (x_ulong)UNARY_OPERAND(Double); (sp - 1)->Type = ValueType::UInt; break; }
				case Instruction::uint_from_float: { UNARY_OPERAND(UInt) = (x_ulong)UNARY_OPERAND(Float); (sp - 1)->Type = ValueType::UInt; break; }
#else
				case Instruction::double_from_int: { UNARY_OPERAND(Double) = (x_double)UNARY_OPERAND(Int); break; }
				case Instruction::double_from_uint: { UNARY_OPERAND(Double) = (x_double)UNARY_OPERAND(UInt); break; }
				case Instruction::double_from_float: { UNARY_OPERAND(Double) = (x_double)UNARY_OPERAND(Float); break; }
				case Instruction::float_from_int: { UNARY_OPERAND(Float) = (x_float)UNARY_OPERAND(Int); break; }
				case Instruction::float_from_uint: { UNARY_OPERAND(Float) = (x_float)UNARY_OPERAND(UInt); break; }
				case Instruction::float_from_double: { UNARY_OPERAND(Float) = (x_float)UNARY_OPERAND(Double); break; }
				case Instruction::int_from_uint: { UNARY_OPERAND(Int) = (x_long)UNARY_OPERAND(UInt); break; }
				case Instruction::int_from_double: { UNARY_OPERAND(Int) = (x_long)UNARY_OPERAND(Double); break; }
				case Instruction::int_from_float: { UNARY_OPERAND(Int) = (x_long)UNARY_OPERAND(Float); break; }
				case Instruction::uint_from_int: { UNARY_OPERAND(UInt) = (x_ulong)UNARY_OPERAND(Int); break; }
				case Instruction::uint_from_double: { UNARY_OPERAND(UInt) = (x_ulong)UNARY_OPERAND(Double); break; }
				case Instruction::uint_from_float: { UNARY_OPERAND(UInt) = (x_ulong)UNARY_OPERAND(Float); break; }
#endif
				// Trueness testing
#ifdef COMPLETE_TYPING
				case Instruction::bool_from_double: { UNARY_OPERAND(Bool) = UNARY_OPERAND(Double) == true; (sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::bool_from_float: { UNARY_OPERAND(Bool) = UNARY_OPERAND(Float) == true; (sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::bool_from_int: { UNARY_OPERAND(Bool) = UNARY_OPERAND(Int) == true; (sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::bool_from_uint: { UNARY_OPERAND(Bool) = UNARY_OPERAND(UInt) == true; (sp - 1)->Type = ValueType::Bool; break; }
#else
				case Instruction::bool_from_double: { UNARY_OPERAND(Bool) = UNARY_OPERAND(Double) == true; break; }
				case Instruction::bool_from_float: { UNARY_OPERAND(Bool) = UNARY_OPERAND(Float) == true; break; }
				case Instruction::bool_from_int: { UNARY_OPERAND(Bool) = UNARY_OPERAND(Int) == true; break; }
				case Instruction::bool_from_uint: { UNARY_OPERAND(Bool) = UNARY_OPERAND(UInt) == true; break; }
#endif
				case Instruction::bool_from_string:
				{
					StringObject* string = (StringObject*)UNARY_OPERAND(Object);
					UNARY_OPERAND(Bool) = string->Size > 0;
					(sp - 1)->Type = ValueType::Bool;
					break;
				}

				// Comparisons
#ifdef COMPLETE_TYPING
				case Instruction::double_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Double) == RIGHT_OPERAND(Double)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::double_not_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Double) != RIGHT_OPERAND(Double)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::double_greater: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Double) > RIGHT_OPERAND(Double)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::double_less: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Double) < RIGHT_OPERAND(Double)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::double_greater_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Double) >= RIGHT_OPERAND(Double)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::double_less_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Double) <= RIGHT_OPERAND(Double)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::float_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Float) == RIGHT_OPERAND(Float)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::float_not_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Float) != RIGHT_OPERAND(Float)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::float_greater: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Float) > RIGHT_OPERAND(Float)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::float_less: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Float) < RIGHT_OPERAND(Float)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::float_greater_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Float) >= RIGHT_OPERAND(Float)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::float_less_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Float) <= RIGHT_OPERAND(Float)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::int_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Int) == RIGHT_OPERAND(Int)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::int_not_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Int) != RIGHT_OPERAND(Int)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::int_greater: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Int) > RIGHT_OPERAND(Int)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::int_less: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Int) < RIGHT_OPERAND(Int)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::int_greater_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Int) >= RIGHT_OPERAND(Int)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::int_less_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Int) <= RIGHT_OPERAND(Int)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::uint_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(UInt) == RIGHT_OPERAND(UInt)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::uint_not_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(UInt) != RIGHT_OPERAND(UInt)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::uint_greater: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(UInt) > RIGHT_OPERAND(UInt)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::uint_less: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(UInt) < RIGHT_OPERAND(UInt)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::uint_greater_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(UInt) >= RIGHT_OPERAND(UInt)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::uint_less_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(UInt) <= RIGHT_OPERAND(UInt)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
#else
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
#endif
				case Instruction::bool_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Bool) == RIGHT_OPERAND(Bool)); DEC(); break; }
				case Instruction::bool_not_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Bool) != RIGHT_OPERAND(Bool)); DEC(); break; }

				case Instruction::string_equal:
				{
					StringObject* left = ((StringObject*)LEFT_OPERAND(Object));
					StringObject* right = ((StringObject*)RIGHT_OPERAND(Object));
					LEFT_OPERAND(Bool) = left == right;
					DEC();
					(sp - 1)->Type = ValueType::Bool;
					break;
				}
				case Instruction::string_not_equal:
				{
					StringObject* left = ((StringObject*)LEFT_OPERAND(Object));
					StringObject* right = ((StringObject*)RIGHT_OPERAND(Object));
					LEFT_OPERAND(Bool) = left != right;
					DEC();
					(sp - 1)->Type = ValueType::Bool;
					break;
				}

				case Instruction::bit_flip: { UNARY_OPERAND(UInt) = ~UNARY_OPERAND(UInt); break; }

				// Control flow
				case Instruction::jump_if_true:
				{
					_x_short offset = READ_SHORT();
					if (UNARY_OPERAND(Bool) == true)
						frame->ip += offset;
					DEC();
					break;
				}
				case Instruction::jump_if_true_chain:
				{
					_x_short offset = READ_SHORT();
					if (UNARY_OPERAND(Bool) == true)
						frame->ip += offset;
					break;
					// NOTE: Doesn't decrement the stack pointer
				}
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
					m_StackSize -= frame->Function->RequiredStackSize;
					if (m_FrameCount == 0)
					{
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
					m_StackSize -= frame->Function->RequiredStackSize;
					if (m_FrameCount == 0)
					{
						return 0;
					}

					frame = &m_Frames[m_FrameCount - 1];
					break;
				}

				// Variables
				case Instruction::set_global:
				{
					_x_short address = READ_SHORT();
					m_Globals[address] = POP();
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
					frame->fp[slot] = POP();
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
					push(instance->Members[READ_SHORT()]);
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
					push(instance->Members[READ_SHORT()]);
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
				case Instruction::create_instance:
				{
					_x_short classID = READ_SHORT();
					push(Value{ NewInstance(m_Classes[classID]) });
					break;
				}

				// Stack Usage
				case Instruction::push_value: { push(READ_CONST()); break; }
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

				case Instruction::duplicate:
				{
					push(*(sp - 1));
					break;
				}
				
				case Instruction::literal_true: push(Value{ true }); break;
				case Instruction::literal_false: push(Value{ false }); break;
				case Instruction::literal_nullptr: push(Value{ (x_object*)nullptr }); break;

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
