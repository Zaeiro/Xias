#pragma once

#include "Xias.h"

#include <iostream>
#include <sstream>
#include <cstdint>

inline void test_vm()
{
	Xias::Bytecode bytecode;
	bytecode.Code.emplace_back(Xias::Instruction::push_value);
	bytecode.Code.emplace_back(0);
	bytecode.Code.emplace_back(Xias::Instruction::double_from_int);
	bytecode.Code.emplace_back(Xias::Instruction::push_value);
	bytecode.Code.emplace_back(1);
	bytecode.Code.emplace_back(Xias::Instruction::double_add);
	bytecode.Code.emplace_back(Xias::Instruction::print_double);
	bytecode.Code.emplace_back(Xias::Instruction::push_value);
	bytecode.Code.emplace_back(2);
	bytecode.Code.emplace_back(Xias::Instruction::double_add);
	bytecode.Code.emplace_back(Xias::Instruction::print_double);
	bytecode.Code.emplace_back(Xias::Instruction::push_value);
	bytecode.Code.emplace_back(3);
	bytecode.Code.emplace_back(Xias::Instruction::print_string);
	bytecode.Code.emplace_back(Xias::Instruction::push_value);
	bytecode.Code.emplace_back(4);
	bytecode.Code.emplace_back(Xias::Instruction::print_string);
	bytecode.Code.emplace_back(Xias::Instruction::string_add);
	bytecode.Code.emplace_back(Xias::Instruction::print_string);
	bytecode.Code.emplace_back(Xias::Instruction::push_value);
	bytecode.Code.emplace_back(5);
	bytecode.Code.emplace_back(Xias::Instruction::print_string);
	bytecode.Code.emplace_back(Xias::Instruction::string_add);
	bytecode.Code.emplace_back(Xias::Instruction::print_string);
	
	bytecode.Code.resize(24);
	Xias::Value xint;
	xint.Int = 3;
	bytecode.Constants.emplace_back(xint);
	bytecode.Constants.emplace_back(Xias::Value{4.3746});
	bytecode.Constants.emplace_back(Xias::Value{2.1});
	bytecode.Constants.emplace_back(OBJ_VAL(Xias::CopyString("s", 1)));
	bytecode.Constants.emplace_back(OBJ_VAL(Xias::CopyString("tr", 2)));
	bytecode.Constants.emplace_back(OBJ_VAL(Xias::CopyString("ing", 3)));
	
	Xias::Vm xvm;

	xvm.CallFunction(bytecode);

	std::cin.get();
}
