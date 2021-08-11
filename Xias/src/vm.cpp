#include "vm.h"

#include "instructions.h"

#define ARITHMETIC(thisType)                                                                           \
{																									   \
thisType* stackType = (thisType*)(m_StackFront - sizeof(thisType));									   \
thisType* functionType = (thisType*)(functionData + 1);												   \
switch ((InstructionVariants)*functionData)															   \
{																									   \
	case InstructionVariants::_inc: (*stackType)++; break;											   \
	case InstructionVariants::_dec: (*stackType)--; break;											   \
	case InstructionVariants::_add: *stackType += *functionType; break;								   \
	case InstructionVariants::_sub: *stackType -= *functionType; break;								   \
	case InstructionVariants::_mul: *stackType *= *functionType; break;								   \
	case InstructionVariants::_div:	*stackType /= *functionType; break;								   \
	case InstructionVariants::_mod:	*stackType %= *functionType; break;								   \
	case InstructionVariants::_pow: *stackType = (thisType)std::pow(*stackType, *functionType); break; \
	default: Error("Unknown arithmetic operator!"); break;											   \
}																									   \
functionData++;																						   \
functionData += sizeof(thisType);																	   \
} static_assert(true, "")

#define STACK_ARITHMETIC(thisType)                                                                     \
{																									   \
thisType* stackType = (thisType*)(m_StackFront - sizeof(thisType) * 2);								   \
thisType* functionType = (thisType*)(m_StackFront - sizeof(thisType));								   \
switch ((InstructionVariants)*functionData)															   \
{																									   \
	case InstructionVariants::_inc: (*stackType)++; break;											   \
	case InstructionVariants::_dec: (*stackType)--; break;											   \
	case InstructionVariants::_add: *stackType += *functionType; break;								   \
	case InstructionVariants::_sub: *stackType -= *functionType; break;								   \
	case InstructionVariants::_mul: *stackType *= *functionType; break;								   \
	case InstructionVariants::_div:	*stackType /= *functionType; break;								   \
	case InstructionVariants::_mod:	*stackType %= *functionType; break;								   \
	case InstructionVariants::_pow: *stackType = (thisType)std::pow(*stackType, *functionType); break; \
	default: Error("Unknown stack arithmetic operator!"); break;									   \
}																									   \
functionData++;																						   \
m_StackFront -= sizeof(thisType);																	   \
} static_assert(true, "")

#define CASTS(thisType)																																	\
{																																						\
thisType* stackType = (thisType*)(m_StackFront - sizeof(thisType));																						\
switch ((InstructionVariants)*functionData)																												\
{																																						\
	case InstructionVariants::_to_byte   : *(uint8_t*)  stackType = (uint8_t) *stackType; m_StackFront += (sizeof(uint8_t)  - sizeof(thisType)); break; \
	case InstructionVariants::_to_short  : *(int16_t*)  stackType = (int16_t) *stackType; m_StackFront += (sizeof(int16_t)  - sizeof(thisType)); break; \
	case InstructionVariants::_to_int    : *(int32_t*)  stackType = (int32_t) *stackType; m_StackFront += (sizeof(int32_t)  - sizeof(thisType)); break; \
	case InstructionVariants::_to_long   : *(int64_t*)  stackType = (int64_t) *stackType; m_StackFront += (sizeof(int64_t)  - sizeof(thisType)); break; \
	case InstructionVariants::_to_sbyte  : *(int8_t*)   stackType = (int8_t)  *stackType; m_StackFront += (sizeof(int8_t)   - sizeof(thisType)); break; \
	case InstructionVariants::_to_ushort : *(uint16_t*) stackType = (uint16_t)*stackType; m_StackFront += (sizeof(uint16_t) - sizeof(thisType)); break; \
	case InstructionVariants::_to_uint   : *(uint32_t*) stackType = (uint32_t)*stackType; m_StackFront += (sizeof(uint32_t) - sizeof(thisType)); break; \
	case InstructionVariants::_to_ulong  : *(uint64_t*) stackType = (uint64_t)*stackType; m_StackFront += (sizeof(uint64_t) - sizeof(thisType)); break; \
	case InstructionVariants::_to_float  : *(float*)    stackType = (float)   *stackType; m_StackFront += (sizeof(float)    - sizeof(thisType)); break; \
	case InstructionVariants::_to_double : *(double*)   stackType = (double)  *stackType; m_StackFront += (sizeof(double)   - sizeof(thisType)); break; \
	default: Error("Unknown cast!"); break;																												\
}																																						\
functionData++;																																			\
} static_assert(true, "")

namespace Xias {

	Vm::Vm()
	{
		m_Stack.resize(32 * sizeof(int));
		m_StackFront = m_Stack.data();
	}

	void Vm::CallFunction(std::vector<Instruction>& function, std::vector<Value>& constants)
	{
		//m_StackFront = m_Stack.data();
		Value* stackFront = m_Stack.data();
		Instruction* functionData = function.data();
		Instruction* functionEnd = &(*function.begin()) + function.size();
		if (functionData == functionEnd)
			return;

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
			case Instruction::int_inc: { (stackFront - sizeof(Value))->Int++; break; }
			case Instruction::int_dec: { (stackFront - sizeof(Value))->Int--; break; }
			case Instruction::int_add: { (stackFront - sizeof(Value) * 2)->Int += (stackFront - sizeof(Value))->Int; break; }
			case Instruction::int_sub: { (stackFront - sizeof(Value) * 2)->Int -= (stackFront - sizeof(Value))->Int; break; }
			case Instruction::int_mul: { (stackFront - sizeof(Value) * 2)->Int *= (stackFront - sizeof(Value))->Int; break; }
			case Instruction::int_div: { (stackFront - sizeof(Value) * 2)->Int /= (stackFront - sizeof(Value))->Int; break; }
			case Instruction::int_mod: { (stackFront - sizeof(Value) * 2)->Int %= (stackFront - sizeof(Value))->Int; break; }
			case Instruction::int_pow:
			{
				Value* first = (stackFront - sizeof(Value) * 2);
				Value* second = (stackFront - sizeof(Value));
				first->Int = (x_long)std::pow(first->Int, second->Int);
				break;
			}
			case Instruction::uint_inc: { (stackFront - sizeof(Value))->UInt++; break; }
			case Instruction::uint_dec: { (stackFront - sizeof(Value))->UInt--; break; }
			case Instruction::uint_add: { (stackFront - sizeof(Value) * 2)->UInt += (stackFront - sizeof(Value))->UInt; break; }
			case Instruction::uint_sub: { (stackFront - sizeof(Value) * 2)->UInt -= (stackFront - sizeof(Value))->UInt; break; }
			case Instruction::uint_mul: { (stackFront - sizeof(Value) * 2)->UInt *= (stackFront - sizeof(Value))->UInt; break; }
			case Instruction::uint_div: { (stackFront - sizeof(Value) * 2)->UInt /= (stackFront - sizeof(Value))->UInt; break; }
			case Instruction::uint_mod: { (stackFront - sizeof(Value) * 2)->UInt %= (stackFront - sizeof(Value))->UInt; break; }
			case Instruction::uint_pow:
			{
				Value* first = (stackFront - sizeof(Value) * 2);
				Value* second = (stackFront - sizeof(Value));
				first->UInt = (x_ulong)std::pow(first->UInt, second->UInt);
				break;
			}
			case Instruction::double_inc: { (stackFront - sizeof(Value))->Double++; break; }
			case Instruction::double_dec: { (stackFront - sizeof(Value))->Double--; break; }
			case Instruction::double_add: { (stackFront - sizeof(Value) * 2)->Double += (stackFront - sizeof(Value))->Double; break; }
			case Instruction::double_sub: { (stackFront - sizeof(Value) * 2)->Double -= (stackFront - sizeof(Value))->Double; break; }
			case Instruction::double_mul: { (stackFront - sizeof(Value) * 2)->Double *= (stackFront - sizeof(Value))->Double; break; }
			case Instruction::double_div: { (stackFront - sizeof(Value) * 2)->Double /= (stackFront - sizeof(Value))->Double; break; }
			case Instruction::double_mod:
			{
				Value* first = (stackFront - sizeof(Value) * 2);
				Value* second = (stackFront - sizeof(Value));
				first->Double = (x_double)std::fmod(first->Double, second->Double);
				break;
			}
			case Instruction::double_pow:
			{
				Value* first = (stackFront - sizeof(Value) * 2);
				Value* second = (stackFront - sizeof(Value));
				first->Double = (x_double)std::pow(first->Double, second->Double);
				break;
			}
			case Instruction::int_from_uint: { (stackFront - sizeof(Value))->Int = (stackFront - sizeof(Value))->UInt; }
			case Instruction::int_from_double: { (stackFront - sizeof(Value))->Int = (stackFront - sizeof(Value))->Double; }
			case Instruction::uint_from_int: { (stackFront - sizeof(Value))->UInt = (stackFront - sizeof(Value))->Int; }
			case Instruction::uint_from_double: { (stackFront - sizeof(Value))->UInt = (stackFront - sizeof(Value))->Double; }
			case Instruction::double_from_int: { (stackFront - sizeof(Value))->Double = (stackFront - sizeof(Value))->Int; }
			case Instruction::double_from_uint: { (stackFront - sizeof(Value))->Double = (stackFront - sizeof(Value))->UInt; }
			case Instruction::push:
			{
				functionData++;
				uint32_t size = *(uint32_t*)functionData;
				std::memcpy(m_StackFront, functionData + sizeof(uint32_t), size);
				m_StackFront += size;
				functionData += size + sizeof(uint32_t);
				break;
			}
			case Instruction::push_1: { functionData++; std::memcpy(m_StackFront, functionData, 1); m_StackFront++; functionData++; break; }
			case Instruction::push_2: { functionData++; std::memcpy(m_StackFront, functionData, 2); m_StackFront += 2; functionData += 2; break; }
			case Instruction::push_4: { functionData++; std::memcpy(m_StackFront, functionData, 4); m_StackFront += 4; functionData += 4; break; }
			case Instruction::push_8: { functionData++; std::memcpy(m_StackFront, functionData, 8); m_StackFront += 8; functionData += 8; break; }
			case Instruction::pop:
			{
				functionData++;
				m_StackFront -= *(uint32_t*)functionData;
				functionData += sizeof(uint32_t);
				break;
			}
			case Instruction::pop_1: { functionData++; m_StackFront--; break; }
			case Instruction::pop_2: { functionData++; m_StackFront -= 2; break; }
			case Instruction::pop_4: { functionData++; m_StackFront -= 4; break; }
			case Instruction::pop_8: { functionData++; m_StackFront -= 8; break; }
			default: Error("Unknown instruction!"); break;
			}
			functionData++;
		}
	}

	void Vm::Error(const char* msg)
	{
		std::cerr << msg;
	}

}
