#pragma once

#include <vector>
#include <cstdint>

namespace Xias {

	using _x_short = uint16_t;

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

	struct x_object;

	union Value
	{
		x_double Double;
		x_float Float;
		x_long Int;
		x_ulong UInt;
		x_bool Bool;
		x_object* Object;

		Value() {}
		Value(x_double _double) : Double(_double) {}
		Value(x_float _float) : Float(_float) {}
		Value(int _int) : Int(_int) {}
		Value(unsigned int _uint) : UInt(_uint) {}
		Value(x_long _int) : Int(_int) {}
		Value(x_ulong _uint) : UInt(_uint) {}
		Value(x_bool _bool) : Bool(_bool) {}
		Value(x_object* _object) : Object(_object) {}
	};

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
