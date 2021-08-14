#pragma once

#include <cstdint>

namespace Xias {

	enum class Instruction : uint16_t
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

        float_inc,
        float_dec,
        float_add,
        float_sub,
        float_mul,
        float_div,
        float_mod,
        float_pow,
        
        string_add,
        string_size,
        
		int_from_uint,
		int_from_double,
        int_from_float,
        
		uint_from_int,
		uint_from_double,
        uint_from_float,
        
		double_from_int,
		double_from_uint,
        double_from_float,
        
        float_from_int,
        float_from_uint,
        float_from_double,
        
        string_from_int,
        string_from_uint,
        string_from_double,
        string_from_float,
        
        bool_from_int,
        bool_from_uint,
        bool_from_double,
        bool_from_float,
        bool_from_string,
        
        int_equal,
        int_not_equal,
        int_greater,
        int_less,
        int_greater_or_equal,
        int_less_or_equal,
        
        uint_equal,
        uint_not_equal,
        uint_greater,
        uint_less,
        uint_greater_or_equal,
        uint_less_or_equal,
        
        double_equal,
        double_not_equal,
        double_greater,
        double_less,
        double_greater_or_equal,
        double_less_or_equal,
        
        float_equal,
        float_not_equal,
        float_greater,
        float_less,
        float_greater_or_equal,
        float_less_or_equal,
        
        string_equal,
        string_not_equal,
        
        jump_if_false,
        jump,
        
        set_global,
        get_global,
        
        set_local,
        get_local,
        
		push_value,
		push_size,

		pop_value,
		pop_size,
        
        print_int,
        print_uint,
        print_double,
        print_float,
        print_bool,
        print_string,
	};

}
