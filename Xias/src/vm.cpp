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

#define LEFT_OPERAND(type) ((stackFront - 2)->type)
#define RIGHT_OPERAND(type) ((stackFront - 1)->type)
#define UNARY_OPERAND(type) ((stackFront - 1)->type)

namespace Xias {

	Vm::Vm()
	{
		m_Stack.resize(32 * sizeof(int));
	}

	void Vm::CallFunction(std::vector<Instruction>& function, std::vector<Value>& constants)
	{
		Value* stackFront = m_Stack.data();
		Instruction* functionData = function.data();
		Instruction* functionEnd = &(*function.begin()) + function.size();
		if (functionData == functionEnd)
			return;

        Value* constantsFront = constants.data();
        
		while (functionData != functionEnd)
		{
#ifdef X_DEBUG
			if (functionData >= functionEnd)
			{
				std::cout << "overpassed function end!\n";
			}
#endif
			switch (*functionData)
			{
                // Arithmetic
                case Instruction::int_inc: { UNARY_OPERAND(Int)++; break; }
                case Instruction::int_dec: { UNARY_OPERAND(Int)--; break; }
                case Instruction::int_add: { LEFT_OPERAND(Int) += RIGHT_OPERAND(Int); stackFront--; break; }
                case Instruction::int_sub: { LEFT_OPERAND(Int) -= RIGHT_OPERAND(Int); stackFront--; break; }
                case Instruction::int_mul: { LEFT_OPERAND(Int) *= RIGHT_OPERAND(Int); stackFront--; break; }
                case Instruction::int_div: { LEFT_OPERAND(Int) /= RIGHT_OPERAND(Int); stackFront--; break; }
                case Instruction::int_mod: { LEFT_OPERAND(Int) %= RIGHT_OPERAND(Int); stackFront--; break; }
                case Instruction::int_pow:
                {
                    LEFT_OPERAND(Int) = (x_long)std::pow(LEFT_OPERAND(Int), RIGHT_OPERAND(Int));
                    stackFront--;
                    break;
                }
                case Instruction::uint_inc: { UNARY_OPERAND(UInt)++; break; }
                case Instruction::uint_dec: { UNARY_OPERAND(UInt)--; break; }
                case Instruction::uint_add: { LEFT_OPERAND(UInt) += RIGHT_OPERAND(UInt); stackFront--; break; }
                case Instruction::uint_sub: { LEFT_OPERAND(UInt) -= RIGHT_OPERAND(UInt); stackFront--; break; }
                case Instruction::uint_mul: { LEFT_OPERAND(UInt) *= RIGHT_OPERAND(UInt); stackFront--; break; }
                case Instruction::uint_div: { LEFT_OPERAND(UInt) /= RIGHT_OPERAND(UInt); stackFront--; break; }
                case Instruction::uint_mod: { LEFT_OPERAND(UInt) %= RIGHT_OPERAND(UInt); stackFront--; break; }
                case Instruction::uint_pow:
                {
                    LEFT_OPERAND(UInt) = (x_ulong)std::pow(LEFT_OPERAND(UInt), RIGHT_OPERAND(UInt));
                    stackFront--;
                    break;
                }
                case Instruction::double_inc: { UNARY_OPERAND(Double)++; break; }
                case Instruction::double_dec: { UNARY_OPERAND(Double)--; break; }
                case Instruction::double_add: { LEFT_OPERAND(Double) += RIGHT_OPERAND(Double); stackFront--; break; }
                case Instruction::double_sub: { LEFT_OPERAND(Double) -= RIGHT_OPERAND(Double); stackFront--; break; }
                case Instruction::double_mul: { LEFT_OPERAND(Double) *= RIGHT_OPERAND(Double); stackFront--; break; }
                case Instruction::double_div: { LEFT_OPERAND(Double) /= RIGHT_OPERAND(Double); stackFront--; break; }
                case Instruction::double_mod:
                {
                    LEFT_OPERAND(Double) = (x_double)std::fmod(LEFT_OPERAND(Double), RIGHT_OPERAND(Double));
                    stackFront--;
                    break;
                }
                case Instruction::double_pow:
                {
                    LEFT_OPERAND(Double) = (x_double)std::pow(LEFT_OPERAND(Double), RIGHT_OPERAND(Double));
                    stackFront--;
                    break;
                }
                case Instruction::float_inc: { UNARY_OPERAND(Float)++; break; }
                case Instruction::float_dec: { UNARY_OPERAND(Float)--; break; }
                case Instruction::float_add: { LEFT_OPERAND(Float) += RIGHT_OPERAND(Float); stackFront--; break; }
                case Instruction::float_sub: { LEFT_OPERAND(Float) -= RIGHT_OPERAND(Float); stackFront--; break; }
                case Instruction::float_mul: { LEFT_OPERAND(Float) *= RIGHT_OPERAND(Float); stackFront--; break; }
                case Instruction::float_div: { LEFT_OPERAND(Float) /= RIGHT_OPERAND(Float); stackFront--; break; }
                case Instruction::float_mod:
                {
                    LEFT_OPERAND(Float) = (x_float)std::fmod(LEFT_OPERAND(Float), RIGHT_OPERAND(Float));
                    stackFront--;
                    break;
                }
                case Instruction::float_pow:
                {
                    LEFT_OPERAND(Float) = (x_float)std::powf(LEFT_OPERAND(Float), RIGHT_OPERAND(Float));
                    stackFront--;
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
                    LEFT_OPERAND(Object) = (Object*)takeString(chars, length);
                    stackFront--;
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
                case Instruction::bool_from_string: { UNARY_OPERAND(Bool) = ((StringObject*)UNARY_OPERAND(Object))->Size > 0; break; }
                    
                // Comparisons
                case Instruction::int_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Int) == RIGHT_OPERAND(Int)); stackFront--; break; }
                case Instruction::int_not_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Int) != RIGHT_OPERAND(Int)); stackFront--; break; }
                case Instruction::int_greater: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Int) > RIGHT_OPERAND(Int)); stackFront--; break; }
                case Instruction::int_less: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Int) < RIGHT_OPERAND(Int)); stackFront--; break; }
                case Instruction::int_greater_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Int) >= RIGHT_OPERAND(Int)); stackFront--; break; }
                case Instruction::int_less_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Int) <= RIGHT_OPERAND(Int)); stackFront--; break; }
                case Instruction::uint_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(UInt) == RIGHT_OPERAND(UInt)); stackFront--; break; }
                case Instruction::uint_not_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(UInt) != RIGHT_OPERAND(UInt)); stackFront--; break; }
                case Instruction::uint_greater: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(UInt) > RIGHT_OPERAND(UInt)); stackFront--; break; }
                case Instruction::uint_less: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(UInt) < RIGHT_OPERAND(UInt)); stackFront--; break; }
                case Instruction::uint_greater_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(UInt) >= RIGHT_OPERAND(UInt)); stackFront--; break; }
                case Instruction::uint_less_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(UInt) <= RIGHT_OPERAND(UInt)); stackFront--; break; }
                case Instruction::double_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Double) == RIGHT_OPERAND(Double)); stackFront--; break; }
                case Instruction::double_not_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Double) != RIGHT_OPERAND(Double)); stackFront--; break; }
                case Instruction::double_greater: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Double) > RIGHT_OPERAND(Double)); stackFront--; break; }
                case Instruction::double_less: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Double) < RIGHT_OPERAND(Double)); stackFront--; break; }
                case Instruction::double_greater_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Double) >= RIGHT_OPERAND(Double)); stackFront--; break; }
                case Instruction::double_less_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Double) <= RIGHT_OPERAND(Double)); stackFront--; break; }
                case Instruction::float_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Float) == RIGHT_OPERAND(Float)); stackFront--; break; }
                case Instruction::float_not_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Float) != RIGHT_OPERAND(Float)); stackFront--; break; }
                case Instruction::float_greater: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Float) > RIGHT_OPERAND(Float)); stackFront--; break; }
                case Instruction::float_less: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Float) < RIGHT_OPERAND(Float)); stackFront--; break; }
                case Instruction::float_greater_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Float) >= RIGHT_OPERAND(Float)); stackFront--; break; }
                case Instruction::float_less_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Float) <= RIGHT_OPERAND(Float)); stackFront--; break; }
                case Instruction::string_equal:
                {
                    StringObject* left = ((StringObject*)LEFT_OPERAND(Object));
                    StringObject* right = ((StringObject*)RIGHT_OPERAND(Object));
                    LEFT_OPERAND(Bool) = (left->Size == right->Size) && (std::memcmp(left->Chars, right->Chars, left->Size) == 0);
                    delete[] left->Chars;
                    delete left;
                    delete[] right->Chars;
                    delete right;
                    stackFront--;
                    break;
                }
                case Instruction::string_not_equal:
                {
                    StringObject* left = ((StringObject*)LEFT_OPERAND(Object));
                    StringObject* right = ((StringObject*)RIGHT_OPERAND(Object));
                    LEFT_OPERAND(Bool) = (left->Size != right->Size) || (std::memcmp(left->Chars, right->Chars, left->Size) != 0);
                    delete[] left->Chars;
                    delete left;
                    delete[] right->Chars;
                    delete right;
                    stackFront--;
                    break;
                }
                
                // Control flow
                case Instruction::jump_if_false:
                {
                    x_ulong offset = constantsFront->UInt;
                    if (UNARY_OPERAND(Bool) == false)
                        functionData += offset;
                    constantsFront++;
                    // Doesn't decrement the stack pointer
                }
                case Instruction::jump:
                {
                    x_ulong offset = constantsFront->UInt;
                    functionData += offset;
                    constantsFront++;
                }
                    
                // Variables
                case Instruction::set_global:
                {
                    x_ulong address = constantsFront->UInt;
                    m_Globals[address] = *(stackFront - 1);
                    constantsFront++;
                    stackFront--;
                    break;
                }
                case Instruction::get_global:
                {
                    x_ulong address = constantsFront->UInt;
                    *stackFront = m_Globals[address];
                    constantsFront++;
                    stackFront++;
                    break;
                }
                case Instruction::set_local:
                {
                    x_ulong slot = constantsFront->UInt;
                    m_Stack[slot] = *(stackFront - 1);
                    constantsFront++;
                    break;
                }
                case Instruction::get_local:
                {
                    x_ulong slot = constantsFront->UInt;
                    *stackFront = m_Stack[slot];
                    constantsFront++;
                    stackFront++;
                    break;
                }
                    
                // Stack Usage
                case Instruction::push_value: { *stackFront = *constantsFront; constantsFront++; stackFront++; break; }
                case Instruction::push_size:
                {
                    x_ulong size = constantsFront->UInt;
                    std::memcpy(stackFront, constantsFront + 1, size);
                    stackFront += size;
                    constantsFront += size + 1;
                    break;
                }
                case Instruction::pop_value: { stackFront--; }
                case Instruction::pop_size:
                {
                    x_ulong size = constantsFront->UInt;
                    stackFront -= size;
                    constantsFront++;
                    break;
                }
                case Instruction::print_int: { std::cout << UNARY_OPERAND(Int) << std::endl; break; }
                case Instruction::print_uint: { std::cout << UNARY_OPERAND(UInt) << std::endl; break; }
                case Instruction::print_double: { std::cout << UNARY_OPERAND(Double) << std::endl; break; }
                case Instruction::print_float: { std::cout << UNARY_OPERAND(Float) << std::endl; break; }
                case Instruction::print_bool: { std::cout << UNARY_OPERAND(Bool) << std::endl; break; }
                case Instruction::print_string: { std::cout << ((StringObject*)UNARY_OPERAND(Object))->Chars << std::endl; break; }
                default: Error("Unknown instruction!"); break;
            }
			functionData++;
		}
	}

	void Vm::Error(const char* msg)
	{
		std::cerr << msg;
    }

    void Vm::AddGlobal(std::string name, Value value) {
        m_GlobalNames.insert({ name, m_Globals.size() });
        m_Globals.emplace_back(value);
    }

    Value Vm::GetGlobal(std::string name) {
        auto iter = m_GlobalNames.find(name);
        if (iter != m_GlobalNames.end())
            return m_Globals[iter->second];
        Error("Global not found!");
        return Value{.UInt = 0};
    }



}
