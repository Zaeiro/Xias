#pragma once

#include <vector>
#include <cstdint>
#include <memory>

namespace Xias {

	using x_long = int64_t;
	using x_ulong = uint64_t;
	using x_double = double;

	struct _x_fieldID;
	using x_fieldID = _x_fieldID*;

	struct _x_methodID;
	using x_methodID = _x_methodID*;

	struct Function;

	typedef union
	{
		x_double Double;
		x_long Int;
		x_ulong UInt;
	} Value;

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
