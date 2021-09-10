#pragma once

#include <vector>
#include <cstdint>
#include <unordered_map>

namespace Xias {

	using _x_short = uint16_t;

	using x_double = double;
	using x_float = float;
	using x_long = int64_t;
	using x_ulong = uint64_t;
	using x_bool = bool;

	struct x_object;
	struct StringObject;
	struct NativeObject;
	struct VoidNativeObject;
	struct FunctionObject;
	struct InstanceObject;

	using x_method = FunctionObject*;

	enum class ValueType
	{
		Double,
		Float,
		Int,
		UInt,
		Bool,
		Object
	};

	struct Value
	{
		union Data
		{
			x_double Double;
			x_float Float;
			x_long Int;
			x_ulong UInt;
			x_bool Bool;
			x_object* Object;
		} as;
		ValueType Type;

		Value() {}
		Value(x_double _double) { Type = ValueType::Double; as.Double = _double; }
		Value(x_float _float) { Type = ValueType::Float; as.Float = _float; }
		Value(int _int) { Type = ValueType::Int; as.Int = _int; }
		Value(unsigned int _uint) { Type = ValueType::UInt; as.UInt = _uint; }
		Value(x_long _int) { Type = ValueType::Int; as.Int = _int; }
		Value(x_ulong _uint) { Type = ValueType::UInt; as.UInt = _uint; }
		Value(x_bool _bool) { Type = ValueType::Bool; as.Bool = _bool; }
		Value(x_object* _object) { Type = ValueType::Object; as.Object = _object; }
		Value(StringObject* _object) { Type = ValueType::Object; as.Object = (x_object*)_object; }
		Value(NativeObject* _object) { Type = ValueType::Object; as.Object = (x_object*)_object; }
		Value(VoidNativeObject* _object) { Type = ValueType::Object; as.Object = (x_object*)_object; }
		Value(FunctionObject* _object) { Type = ValueType::Object; as.Object = (x_object*)_object; }
		Value(InstanceObject* _object) { Type = ValueType::Object; as.Object = (x_object*)_object; }
	};

	struct _x_class;
	using x_class = _x_class*;

	struct _x_class
	{
		x_long MemberCount;
		std::unordered_map<std::string, x_ulong> MemberIndices;
		x_class Parent = nullptr;

		std::unordered_map<std::string, x_ulong> FunctionIndices;
		std::vector<FunctionObject*> Functions;
	};

}
