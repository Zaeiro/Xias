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
	using x_member_method = x_ulong;

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

	bool operator==(const Value& lhs, const Value& rhs);

	struct _x_class;
	using x_class = _x_class*;

	struct _x_class
	{
		std::string Name;

		x_long MemberCount;
		std::unordered_map<std::string, x_ulong> MemberIndices;
		x_class Parent = nullptr;

		std::unordered_map<std::string, x_ulong> FunctionIndices;
		std::vector<x_method> Functions;

		// // Multiple classes do not refer to the same operator method
		// std::unordered_map<std::string, x_ulong> OperatorIndices;
		// std::vector<x_method> Operators;

		// Implicit casts are stored here and FunctionIndices, while explicit casts are stored only in FunctionIndices 
		// All cast methods are from this containing class to another
		std::unordered_map<std::string, x_ulong> ImplicitCastIndices;
		//std::vector<x_method> Casts;
	};

	struct CompilationMessage
	{
		x_ulong Line = 0;
		x_ulong Column = 0;
		x_ulong ErrorID = 0;
		std::vector<std::string> Params;
		enum Severity
		{
			Hint,
			Warning,
			Fatal
		};
	};

	// TODO: Add qualifiers like const and static
	struct Type
	{
		x_class Class = nullptr;
		// [,,][] -> { 3, 1 }
		std::vector<x_ulong> Dimensions;
		enum
		{
			rvalue,
			lvalue
		} Category;
	};

	struct ExpressionResult
	{
		enum Category
		{
			_Value,
			_Variable,
			_NullLiteral,
			_PropertyAccess,
			_IndexerAccess,
			_Nothing,

			_Namespace,
			_Type,
			_MethodGroup,
		} m_Category;
		Type m_Type;
		std::string m_Name;
		std::vector<std::string> m_Data;

		ExpressionResult()
			: m_Category(Category::_Nothing), m_Type(), m_Name("") {}
		ExpressionResult(Category category, const Type& type)
			: m_Category(category), m_Type(type), m_Name("") {}
	};

	std::string GetTypeInitial(const std::string& type);
}
