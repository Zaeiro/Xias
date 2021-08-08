
#include <vector>
#include <cstdint>
#include <string>
#include <iostream>

namespace Xias {

	struct _x_fieldID;
	using x_fieldID = _x_fieldID*;

	struct _x_methodID;
	using x_methodID = _x_methodID*;

	enum class Instructions : uint8_t
	{
		// Puts an int onto the stack after adding the given int to the int at the top of the stack
		int_add_int_int = 0U,
		// Puts an int onto the stack after adding the two ints at the top of the stack
		int_s_add_int_int,

		float_add_float_float,
		float_s_add_float_float,

		push_int,
		push_float,

		pop_int,
		pop_float,
	};

	struct Function;

	// Classes, structs, etc
	struct Type
	{
		int Size;

		std::vector<int> MemberIndices;

		// Non-Virtual Functions
		std::vector<Function> Functions;
	};

	struct Function
	{
		Type ReturnType;

		std::vector<Type> ParameterTypes;
	};

	// Runtime object
	struct Object
	{
		std::shared_ptr<Type> Type;

		std::vector<uint8_t> MemberVars;
		// Virtual Functions
		std::vector<Function> Functions;
	};

	struct Scope
	{
		std::vector<Scope> Children;
	};

	class Vm
	{
		std::vector<uint8_t> m_Stack;
		// The next open byte
		uint8_t* m_StackFront;

		Scope m_GlobalScope;
	public:
		Vm()
		{
			m_Stack.resize(32 * sizeof(int));
			m_StackFront = m_Stack.data();
		}

		void callfunction(std::vector<uint8_t>& function)
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
					case Instructions::int_add_int_int:
					{
						functionData++;
						*((int*)(m_StackFront - sizeof(int))) += *((int*)functionData);
						functionData += sizeof(int);
						break;
					}
					case Instructions::int_s_add_int_int:
					{
						functionData++;
						*((int*)(m_StackFront - sizeof(int) * 2)) += *((int*)m_StackFront);
						m_StackFront -= sizeof(int);
						break;
					}
					case Instructions::float_add_float_float:
					{
						functionData++;
						*((float*)(m_StackFront - sizeof(float))) += *((float*)functionData);
						functionData += sizeof(float);
						acc += 3;
						break;
					}
					case Instructions::float_s_add_float_float:
					{
						functionData++;
						*((float*)(m_StackFront - sizeof(float) * 2)) += *((float*)m_StackFront);
						m_StackFront -= sizeof(float);
						break;
					}
					case Instructions::push_int:
					{
						functionData++;
						*((int*)m_StackFront) = *((int*)functionData);
						m_StackFront += sizeof(int);
						functionData += sizeof(int);
						break;
					}
					case Instructions::push_float:
					{
						functionData++;
						*((float*)m_StackFront) = *((float*)functionData);
						m_StackFront += sizeof(float);
						functionData += sizeof(float);
						break;
					}
					case Instructions::pop_int:
					{
						functionData++;
						m_StackFront -= sizeof(int);
						break;
					}
					case Instructions::pop_float:
					{
						functionData++;
						m_StackFront -= sizeof(float);
						break;
					}
				}
			}
		}

		template <typename TReturn, typename... TArgs>
		TReturn CallStaticMethod(x_methodID method, TArgs... args)
		{

		}
	};

}
