#pragma once

#include <cstdint>

namespace Xias {

	enum class Instruction : uint8_t
	{
		int_inc,
		int_dec,
		int_add,
		int_sub,
		int_mul,
		int_div,
		int_mod,
		int_pow,

		uint_inc,
		uint_dec,
		uint_add,
		uint_sub,
		uint_mul,
		uint_div,
		uint_mod,
		uint_pow,

		double_inc,
		double_dec,
		double_add,
		double_sub,
		double_mul,
		double_div,
		double_mod,
		double_pow,

		int_from_uint,
		int_from_double,

		uint_from_int,
		uint_from_double,

		double_from_int,
		double_from_uint,

		push_int,
		push_uint,
		push_double,
		push_size,

		pop_int,
		pop_uint,
		pop_double,
		pop_size,
	};

}
