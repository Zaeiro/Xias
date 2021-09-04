#include "vm.h"

#include "types.h"
#include "object.h"
#include "memory.h"

#include <iostream>

#define AS_DOUBLE(value) (value->Double)
#define AS_FLOAT(value) (value->Float)
#define AS_INT(value) (value->Int)
#define AS_UINT(value) (value->UInt)
#define AS_BOOL(value) (value->Bool)
#define AS_OBJ(value) (value->Object)

#define LEFT_OPERAND(type) ((sp - 2)->type)
#define RIGHT_OPERAND(type) ((sp - 1)->type)
#define UNARY_OPERAND(type) ((sp - 1)->type)

#define READ_CONSTANT(type) frame->Function->Code.Constants[(++frame->ip)->Data].type;
#define READ_CONST() frame->Function->Code.Constants[(++frame->ip)->Data] 
#define READ_SHORT() (++frame->ip)->Data;

#define DEC() (sp--)
#define POP() (*sp--)

namespace Xias {

	Vm::Vm()
	{
		m_Frames.resize(64);
		m_Stack.resize(64);
		sp = m_Stack.data();
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
		m_Stack[0] = OBJ_VAL(function);

		// Calling this function
		CallFrame* newFrame = &m_Frames[m_FrameCount++];
		newFrame->Function = function;
		newFrame->ip = &function->Code.Code.front();
		newFrame->fp = m_Stack.data();

		// Running the VM
		CallFrame* frame = &m_Frames[m_FrameCount - 1];

		sp = &m_Stack[1];
		OpType* ie = &(*frame->Function->Code.Code.begin()) + frame->Function->Code.Code.size();
		if (frame->ip == ie)
			return;

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
					char* chars = ALLOCATE(char, length + 1);
					memcpy(chars, left->Chars, left->Size);
					memcpy(chars + left->Size, right->Chars, right->Size);
					chars[length] = '\0';
					delete[] left->Chars;
					delete left;
					delete[] right->Chars;
					delete right;
					LEFT_OPERAND(Object) = (x_object*)TakeString(chars, length);
					DEC();
					break;
				}
				case Instruction::string_size: { break; } // Unimplemented
				
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
					bool result = string->Size > 0;
					delete[] string->Chars;
					delete[] string;
					UNARY_OPERAND(Bool) = result;
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
					bool result = (left->Size == right->Size) && (std::memcmp(left->Chars, right->Chars, left->Size) == 0);
					delete[] left->Chars;
					delete left;
					delete[] right->Chars;
					delete right;
					LEFT_OPERAND(Bool) = result;
					DEC();
					break;
				}
				case Instruction::string_not_equal:
				{
					StringObject* left = ((StringObject*)LEFT_OPERAND(Object));
					StringObject* right = ((StringObject*)RIGHT_OPERAND(Object));
					bool result = (left->Size != right->Size) || (std::memcmp(left->Chars, right->Chars, left->Size) != 0);
					delete[] left->Chars;
					delete left;
					delete[] right->Chars;
					delete right;
					LEFT_OPERAND(Bool) = result;
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
					// Doesn't decrement the stack pointer
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
					// TODO: Extract to lone function
					switch (OBJ_TYPE(callable))
					{
						case ObjectType::function_object:
						{
							CallFrame* newFrame = &m_Frames[m_FrameCount++];
							newFrame->Function = (FunctionObject*)(callable->Object);
							newFrame->ip = newFrame->Function->Code.Code.data();
							newFrame->fp = sp - argCount - 1;

							frame = newFrame;
							break;
						}
						case ObjectType::native_function_object:
						{
							NativeObject* native = (NativeObject*)(callable->Object);
							Value result = native->Function(argCount, sp - argCount);
							sp -= argCount + 1;
							*sp++ = result;
							break;
						}
						case ObjectType::void_native_function_object:
						{
							VoidNativeObject* native = (VoidNativeObject*)(callable->Object);
							native->Function(argCount, sp - argCount);
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
					Value result = *sp++;
					m_FrameCount--;
					if (m_FrameCount == 0)
					{
						DEC();
						return;
					}

					sp = frame->fp;
					push(result);
					frame = &m_Frames[m_FrameCount - 1];
					break;
				}
				case Instruction::func_return_void:
				{
					m_FrameCount--;
					if (m_FrameCount == 0)
					{
						DEC();
						return;
					}

					sp = frame->fp;
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
	}

	void Vm::Error(const char* msg)
	{
		std::cerr << msg;
	}

	inline void Vm::push(Value& value)
	{
		*sp++ = value;
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
