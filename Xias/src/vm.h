#pragma once

#include "types.h"

#include <vector>
#include <cstdint>
#include <iostream>
#include <cmath>

namespace Xias {

	class Vm
	{
		std::vector<uint8_t> m_Stack;
		// The next open byte.
		uint8_t* m_StackFront;

		Scope m_GlobalScope;
	public:
		Vm();

		void Callfunction(std::vector<uint8_t>& function);

		template <typename TReturn, typename... TArgs>
		TReturn CallStaticMethod(x_methodID method, TArgs... args)
		{

		}
	private:
		void Error(const char* msg);
	};

}
