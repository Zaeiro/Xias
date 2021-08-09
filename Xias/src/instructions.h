#pragma once

#include <cstdint>

namespace Xias {

	enum class Instructions : uint8_t
	{
		// Uses the top value on the stack, as well as one provided by the function.
		byte_arithmetic = 0U,
		// Uses the top two values on the stack.
		byte_s_arithmetic,
		// Casts to other types
		byte_casts,

		short_arithmetic,
		short_s_arithmetic,
		short_casts,

		int_arithmetic,
		int_s_arithmetic,
		int_casts,

		long_arithmetic,
		long_s_arithmetic,
		long_casts,

		// Alternatives
		sbyte_arithmetic,
		sbyte_s_arithmetic,
		sbyte_casts,

		ushort_arithmetic,
		ushort_s_arithmetic,
		ushort_casts,

		uint_arithmetic,
		uint_s_arithmetic,
		uint_casts,

		ulong_arithmetic,
		ulong_s_arithmetic,
		ulong_casts,

		// Floating point
		float_arithmetic,
		float_s_arithmetic,
		float_casts,

		double_arithmetic,
		double_s_arithmetic,
		double_casts,

		push,
		push_1,
		push_2,
		push_4,
		push_8,

		pop,
		pop_1,
		pop_2,
		pop_4,
		pop_8,
	};

	enum class InstructionVariants : uint8_t
	{
		_inc,
		_dec,
		_add,
		_sub,
		_mul,
		_div,
		_mod,
		_pow,

		_to_byte,
		_to_short,
		_to_int,
		_to_long,
		_to_sbyte,
		_to_ushort,
		_to_uint,
		_to_ulong,
		_to_float,
		_to_double,
	};

}
