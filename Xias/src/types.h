#pragma once

#include <vector>
#include <cstdint>

namespace Xias {

    using x_double = double;
    using x_float = float;
    using x_long = int64_t;
	using x_ulong = uint64_t;
    using x_bool = bool;

//	struct _x_fieldID;
//	using x_fieldID = _x_fieldID*;
//
//	struct _x_methodID;
//	using x_methodID = _x_methodID*;

	struct Object;

	typedef union
	{
		x_double Double;
        x_float Float;
		x_long Int;
		x_ulong UInt;
        x_bool Bool;
		Object* Object;
	} Value;

//	// Classes, structs, etc
//	struct Type
//	{
//		int Size;
//
//		std::vector<int> MemberIndices;
//
//		// Non-Virtual Functions
//		std::vector<Function> Functions;
//	};
//
//	struct Function
//	{
//		Type ReturnType;
//
//		std::vector<Type> ParameterTypes;
//	};
//
//	// Runtime object
//	struct Object
//	{
//		std::shared_ptr<Type> Type;
//
//		std::vector<uint8_t> MemberVars;
//		// Virtual Functions
//		std::vector<Function> Functions;
//	};
//
//	struct Scope
//	{
//		std::vector<Scope> Children;
//	};

}
