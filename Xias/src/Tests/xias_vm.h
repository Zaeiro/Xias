#pragma once

#include "Xias.h"

#include <iostream>
#include <sstream>
#include <cstdint>

inline void test_vm()
{
	std::vector<Xias::Instruction> data;
    data.emplace_back(Xias::Instruction::push_value);
    data.emplace_back(Xias::Instruction::double_from_int);
    data.emplace_back(Xias::Instruction::push_value);
    data.emplace_back(Xias::Instruction::double_add);
    data.emplace_back(Xias::Instruction::print_double);
    data.emplace_back(Xias::Instruction::push_value);
    data.emplace_back(Xias::Instruction::double_add);
    data.emplace_back(Xias::Instruction::print_double);
    data.emplace_back(Xias::Instruction::push_value);
    data.emplace_back(Xias::Instruction::print_string);
    data.emplace_back(Xias::Instruction::push_value);
    data.emplace_back(Xias::Instruction::print_string);
    data.emplace_back(Xias::Instruction::string_add);
    data.emplace_back(Xias::Instruction::print_string);
    data.emplace_back(Xias::Instruction::push_value);
    data.emplace_back(Xias::Instruction::print_string);
    data.emplace_back(Xias::Instruction::string_add);
    data.emplace_back(Xias::Instruction::print_string);
    
    data.resize(18);
    std::vector<Xias::Value> constants;
    Xias::Value xint;
    xint.Int = 3;
    constants.emplace_back(xint);
    constants.emplace_back(Xias::Value{4.3746});
    constants.emplace_back(Xias::Value{2.1});
    constants.emplace_back(OBJ_VAL(Xias::copyString("s", 1)));
    constants.emplace_back(OBJ_VAL(Xias::copyString("tr", 2)));
    constants.emplace_back(OBJ_VAL(Xias::copyString("ing", 3)));
    
	Xias::Vm xvm;

	xvm.CallFunction(data, constants);

	std::cin.get();
}
