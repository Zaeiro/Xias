#pragma once

#include "types.h"
#include "bytecode.h"
#include "instructions.h"
#include "object.h"

#include <string>
#include <vector>
#include <unordered_map>

namespace Xias {

	struct FunctionObject;

	struct CallFrame
	{
		FunctionObject* Function;
		// Return address
		OpType* ip;
		// Frame pointer
		Value* fp;
	};

	class Vm
	{
		std::vector<CallFrame> m_Frames;
		int m_FrameCount = 0;

		std::unordered_map<std::string, x_ulong> m_GlobalNames;
		std::vector<Value> m_Globals;
		std::vector<Value> m_Stack;
		Value* sp = nullptr;
	public:
		Vm();
		
		void RegisterFunction(const std::string&, NativeFn function);
		void RegisterVoidFunction(const std::string&, VoidNativeFn function);

		void AddGlobal(const std::string& name, Value& value);
		Value GetGlobal(const std::string& name);
		
		void CallFunction(Bytecode& bytecode);

//		template <typename TReturn, typename... TArgs>
//		TReturn CallStaticMethod(x_methodID method, TArgs... args)
//		{
//
//		}
	private:
		void Error(const char* msg);

		inline void push(Value& value);
	};

}
