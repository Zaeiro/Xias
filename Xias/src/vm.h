#pragma once

#include "types.h"
#include "bytecode.h"
#include "instructions.h"

#include <string>
#include <vector>
#include <unordered_map>

namespace Xias {

	struct FunctionObject;

	struct CallFrame
	{
		FunctionObject* Function;
		OpType* ip;
	};

	class Vm
	{
		std::unordered_map<std::string, x_ulong> m_GlobalNames;
		std::vector<Value> m_Globals;
		std::vector<Value> m_Stack;

		//Scope m_GlobalScope;
	public:
		Vm();
		
		void AddGlobal(std::string name, Value value);
		Value GetGlobal(std::string name);
		
		void CallFunction(Bytecode& bytecode);

//		template <typename TReturn, typename... TArgs>
//		TReturn CallStaticMethod(x_methodID method, TArgs... args)
//		{
//
//		}
	private:
		void Error(const char* msg);
	};

}
