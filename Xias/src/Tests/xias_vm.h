#pragma once

#include "Xias.h"

#include <iostream>
#include <sstream>
#include <cstdint>

inline void test_vm()
{
	std::vector<uint8_t> data;
	data.resize(11);
	uint8_t* pdata = data.data();
	*pdata = (uint8_t)Xias::Instructions::push_1;
	pdata++;
	*((Xias::x_byte*)pdata) = (Xias::x_byte)34;
	pdata += sizeof(Xias::x_byte);

	*pdata = (uint8_t)Xias::Instructions::byte_casts;
	pdata++;
	*pdata = (uint8_t)Xias::InstructionVariants::_to_float;
	pdata++;

	*pdata = (uint8_t)Xias::Instructions::push_4;
	pdata++;
	*((float*)pdata) = 10.0f;
	pdata += sizeof(float);

	*pdata = (uint8_t)Xias::Instructions::float_s_arithmetic;
	pdata++;
	*pdata = (uint8_t)Xias::InstructionVariants::_div;
	pdata++;

	Xias::Vm xvm;

	xvm.Callfunction(data);

	std::cin.get();
}
