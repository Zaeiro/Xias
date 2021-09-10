#pragma once

#include "Xias.h"

#include <iostream>
#include <sstream>
#include <cstdint>

Xias::Value CFunc(Xias::Vm* xvm, int argCount, Xias::Value* args)
{
	std::printf("%F\n", args->as.Float);
	return xvm->CopyString("test", 4);
}

Xias::Value CFuncB(Xias::Vm* xvm, int argCount, Xias::Value* args)
{
	return xvm->CopyString("anotherstring\n", 14);
}

inline void test_vm()
{
	Xias::Vm xvm;
	xvm.RegisterFunction("CFunc", CFunc);

	Xias::Bytecode bytecode;
	bytecode.Code.emplace_back(Xias::Instruction::get_global);
	bytecode.Code.emplace_back(0); // Global index
	bytecode.Code.emplace_back(Xias::Instruction::push_value);
	bytecode.Code.emplace_back(0); // Constants index
	bytecode.Code.emplace_back(Xias::Instruction::func_call);
	bytecode.Code.emplace_back(1); // Parameter count
	bytecode.Code.emplace_back(Xias::Instruction::get_global);
	bytecode.Code.emplace_back(0); // Global index
	bytecode.Code.emplace_back(Xias::Instruction::push_value);
	bytecode.Code.emplace_back(0); // Constants index
	bytecode.Code.emplace_back(Xias::Instruction::func_call);
	bytecode.Code.emplace_back(1); // Parameter count
	bytecode.Code.emplace_back(Xias::Instruction::string_add);
	bytecode.Code.emplace_back(Xias::Instruction::print_string);
	bytecode.Code.emplace_back(Xias::Instruction::pop_value);
	bytecode.Code.emplace_back(Xias::Instruction::get_global);
	bytecode.Code.emplace_back(1); // Global index
	bytecode.Code.emplace_back(Xias::Instruction::func_call);
	bytecode.Code.emplace_back(0); // Parameter count

	bytecode.Constants.emplace_back(3.0f);
	//bytecode.Constants.emplace_back(xvm.CopyString("apple", 5));

	xvm.RegisterFunction("CFuncB", CFuncB);

	xvm.CallFunction(bytecode);

	std::cin.get();
}
