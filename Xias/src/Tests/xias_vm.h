#pragma once

#include "Xias.h"

#include <iostream>
#include <sstream>
#include <cstdint>

Xias::Value CFunc(int argCount, Xias::Value* args)
{
	std::printf("%F\n", args->Float);
	return 1;
}

inline void test_vm()
{
	Xias::Bytecode bytecode;
	bytecode.Code.emplace_back(Xias::Instruction::get_global);
	bytecode.Code.emplace_back(0);
	bytecode.Code.emplace_back(Xias::Instruction::push_value);
	bytecode.Code.emplace_back(0);
	bytecode.Code.emplace_back(Xias::Instruction::float_from_int);
	bytecode.Code.emplace_back(Xias::Instruction::func_call);
	bytecode.Code.emplace_back(1);
	bytecode.Code.emplace_back(Xias::Instruction::print_int);

	bytecode.Constants.emplace_back(3);
	
	Xias::Vm xvm;

	xvm.RegisterFunction("CFunc", CFunc);

	xvm.CallFunction(bytecode);

	std::cin.get();
}
