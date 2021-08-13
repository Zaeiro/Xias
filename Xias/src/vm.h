#pragma once

#include "types.h"

#include "instructions.h"

#include <vector>
#include <cstdint>
#include <iostream>
#include <cmath>

namespace Xias {

	class Vm
	{
		std::vector<Value> m_Stack;
		// The next open byte.
		Value* m_StackFront;

		//Scope m_GlobalScope;
	public:
		Vm();

		void CallFunction(std::vector<Instruction>& function, std::vector<Value>& constants);

//		template <typename TReturn, typename... TArgs>
//		TReturn CallStaticMethod(x_methodID method, TArgs... args)
//		{
//
//		}
	private:
		void Error(const char* msg);
	};

}
