#pragma once

#include <vector>
#include <cstdint>
#include <memory>

namespace Xias {

	using x_byte = uint8_t;
	using x_short = int16_t;
	using x_int = int32_t;
	using x_long = int64_t;
	using x_sbyte = int8_t;
	using x_ushort = uint16_t;
	using x_uint = uint32_t;
	using x_ulong = uint64_t;
	using x_float = float;
	using x_double = double;

	struct _x_fieldID;
	using x_fieldID = _x_fieldID*;

	struct _x_methodID;
	using x_methodID = _x_methodID*;

	struct Function;

	// Classes, structs, etc
	struct Type
	{
		int Size;

		std::vector<int> MemberIndices;

		// Non-Virtual Functions
		std::vector<Function> Functions;
	};

	struct Function
	{
		Type ReturnType;

		std::vector<Type> ParameterTypes;
	};

	// Runtime object
	struct Object
	{
		std::shared_ptr<Type> Type;

		std::vector<uint8_t> MemberVars;
		// Virtual Functions
		std::vector<Function> Functions;
	};

	struct Scope
	{
		std::vector<Scope> Children;
	};

}
