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

Xias::Vm::Vm()
{
	m_Stack.resize(32 * sizeof(int));
	m_StackFront = m_Stack.data();
}

void Xias::Vm::Callfunction(std::vector<uint8_t>& function)
{
	int acc = 0;
	m_StackFront = m_Stack.data();
	uint8_t* functionData = function.data();
	uint8_t* functionEnd = function.empty() ? 0 : (&(*function.begin()) + function.size());
	while (functionData != functionEnd)
	{
#ifdef X_DEBUG
		if (functionData >= functionEnd)
		{
			std::cout << "overpassed function end!\n";
		}
#endif
		switch ((Instructions)*functionData)
		{
			case Instructions::byte_arithmetic: { functionData++; ARITHMETIC(x_byte); break; }
			case Instructions::byte_s_arithmetic: { functionData++; STACK_ARITHMETIC(x_byte); break; }
			case Instructions::byte_casts: { functionData++; CASTS(x_byte); break; }
			case Instructions::short_arithmetic: { functionData++; ARITHMETIC(x_short); break; }
			case Instructions::short_s_arithmetic: { functionData++; STACK_ARITHMETIC(x_short); break; }
			case Instructions::short_casts: { functionData++; CASTS(x_short); break; }
			case Instructions::int_arithmetic: { functionData++; ARITHMETIC(x_int); break; }
			case Instructions::int_s_arithmetic: { functionData++; STACK_ARITHMETIC(x_int); break; }
			case Instructions::int_casts: { functionData++; CASTS(x_int); break; }
			case Instructions::long_arithmetic: { functionData++; ARITHMETIC(x_long); break; }
			case Instructions::long_s_arithmetic: { functionData++; STACK_ARITHMETIC(x_long); break; }
			case Instructions::long_casts: { functionData++; CASTS(x_long); break; }
			case Instructions::sbyte_arithmetic: { functionData++; ARITHMETIC(x_sbyte); break; }
			case Instructions::sbyte_s_arithmetic: { functionData++; STACK_ARITHMETIC(x_sbyte); break; }
			case Instructions::sbyte_casts: { functionData++; CASTS(x_sbyte); break; }
			case Instructions::ushort_arithmetic: { functionData++; ARITHMETIC(x_ushort); break; }
			case Instructions::ushort_s_arithmetic: { functionData++; STACK_ARITHMETIC(x_ushort); break; }
			case Instructions::ushort_casts: { functionData++; CASTS(x_ushort); break; }
			case Instructions::uint_arithmetic: { functionData++; ARITHMETIC(x_uint); break; }
			case Instructions::uint_s_arithmetic: { functionData++; STACK_ARITHMETIC(x_uint); break; }
			case Instructions::uint_casts: { functionData++; CASTS(x_uint); break; }
			case Instructions::ulong_arithmetic: { functionData++; ARITHMETIC(x_ulong); break; }
			case Instructions::ulong_s_arithmetic: { functionData++; STACK_ARITHMETIC(x_ulong); break; }
			case Instructions::ulong_casts: { functionData++; CASTS(x_ulong); break; }
			case Instructions::float_arithmetic:
			{
				functionData++;
				using thisType = x_float;
				thisType* stackType = (thisType*)(m_StackFront - sizeof(thisType));
				thisType* functionType = (thisType*)(functionData + 1);
				switch ((InstructionVariants)*functionData)
				{
					case InstructionVariants::_inc: (*stackType)++; break;
					case InstructionVariants::_dec: (*stackType)--; break;
					case InstructionVariants::_add: *stackType += *functionType; break;
					case InstructionVariants::_sub: *stackType -= *functionType; break;
					case InstructionVariants::_mul: *stackType *= *functionType; break;
					case InstructionVariants::_div:	*stackType /= *functionType; break;
					case InstructionVariants::_mod:	*stackType = std::fmodf(*stackType, *functionType); break;
					case InstructionVariants::_pow: *stackType = (thisType)std::pow(*stackType, *functionType); break;
					default: Error("Unknown arithmetic operator!"); break;
				}
				functionData++;
				m_StackFront -= sizeof(thisType);
				break;
			}
			case Instructions::float_s_arithmetic:
			{
				functionData++;
				using thisType = x_float;
				thisType* stackType = (thisType*)(m_StackFront - sizeof(thisType) * 2);
				thisType* functionType = (thisType*)(m_StackFront - sizeof(thisType));
				switch ((InstructionVariants)*functionData)
				{
					case InstructionVariants::_inc: (*stackType)++; break;
					case InstructionVariants::_dec: (*stackType)--; break;
					case InstructionVariants::_add: *stackType += *functionType; break;
					case InstructionVariants::_sub: *stackType -= *functionType; break;
					case InstructionVariants::_mul: *stackType *= *functionType; break;
					case InstructionVariants::_div:	*stackType /= *functionType; break;
					case InstructionVariants::_mod:	*stackType = std::fmodf(*stackType, *functionType); break;
					case InstructionVariants::_pow: *stackType = (thisType)std::pow(*stackType, *functionType); break;
					default: Error("Unknown stack arithmetic operator!"); break;
				}
				functionData++;
				m_StackFront -= sizeof(thisType);
				break;
			}
			case Instructions::float_casts: { functionData++; CASTS(x_float); break; }
			case Instructions::double_arithmetic:
			{
				functionData++;
				using thisType = x_double;
				thisType* stackType = (thisType*)(m_StackFront - sizeof(thisType));
				thisType* functionType = (thisType*)(functionData + 1);
				switch ((InstructionVariants)*functionData)
				{
					case InstructionVariants::_inc: (*stackType)++; break;
					case InstructionVariants::_dec: (*stackType)--; break;
					case InstructionVariants::_add: *stackType += *functionType; break;
					case InstructionVariants::_sub: *stackType -= *functionType; break;
					case InstructionVariants::_mul: *stackType *= *functionType; break;
					case InstructionVariants::_div:	*stackType /= *functionType; break;
					case InstructionVariants::_mod:	*stackType = std::fmod(*stackType, *functionType); break;
					case InstructionVariants::_pow: *stackType = (thisType)std::pow(*stackType, *functionType); break;
					default: Error("Unknown arithmetic operator!"); break;
				}
				functionData++;
				m_StackFront -= sizeof(thisType);
				break;
			}
			case Instructions::double_s_arithmetic:
			{
				functionData++;
				using thisType = x_double;
				thisType* stackType = (thisType*)(m_StackFront - sizeof(thisType) * 2);
				thisType* functionType = (thisType*)(m_StackFront - sizeof(thisType));
				switch ((InstructionVariants)*functionData)
				{
					case InstructionVariants::_inc: (*stackType)++; break;
					case InstructionVariants::_dec: (*stackType)--; break;
					case InstructionVariants::_add: *stackType += *functionType; break;
					case InstructionVariants::_sub: *stackType -= *functionType; break;
					case InstructionVariants::_mul: *stackType *= *functionType; break;
					case InstructionVariants::_div:	*stackType /= *functionType; break;
					case InstructionVariants::_mod:	*stackType = std::fmod(*stackType, *functionType); break;
					case InstructionVariants::_pow: *stackType = (thisType)std::pow(*stackType, *functionType); break;
					default: Error("Unknown stack arithmetic operator!"); break;
				}
				functionData++;
				m_StackFront -= sizeof(thisType);
				break;
			}
			case Instructions::double_casts: { functionData++; CASTS(x_double); break; }
			case Instructions::push:
			{
				functionData++;
				uint32_t size = *(uint32_t*)functionData;
				std::memcpy(m_StackFront, functionData + sizeof(uint32_t), size);
				m_StackFront += size;
				functionData += size + sizeof(uint32_t);
				break;
			}
			case Instructions::push_1: { functionData++; std::memcpy(m_StackFront, functionData, 1); m_StackFront++; functionData++; break; }
			case Instructions::push_2: { functionData++; std::memcpy(m_StackFront, functionData, 2); m_StackFront += 2; functionData += 2; break; }
			case Instructions::push_4: { functionData++; std::memcpy(m_StackFront, functionData, 4); m_StackFront += 4; functionData += 4; break; }
			case Instructions::push_8: { functionData++; std::memcpy(m_StackFront, functionData, 8); m_StackFront += 8; functionData += 8; break; }
			case Instructions::pop:
			{
				functionData++;
				m_StackFront -= *(uint32_t*)functionData;
				functionData += sizeof(uint32_t);
				break;
			}
			case Instructions::pop_1: { functionData++; m_StackFront--; break; }
			case Instructions::pop_2: { functionData++; m_StackFront -= 2; break; }
			case Instructions::pop_4: { functionData++; m_StackFront -= 4; break; }
			case Instructions::pop_8: { functionData++; m_StackFront -= 8; break; }
			default: Error("Unknown instruction!"); break;
		}
	}
}

void Xias::Vm::Error(const char* msg)
{
	std::cerr << msg;
}
