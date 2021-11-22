#pragma once

#include "common.h"
#include "types.h"
#include "bytecode.h"

#define OBJ_VAL(object) ( Xias::Value{(Xias::x_object*)object} )

#define OBJ_TYPE(value) (AS_OBJ(value)->Type)

#define AS_STRING(value) ((StringObject*)AS_OBJ(value))
#define AS_CSTRING(value) (((StringObject*)AS_OBJ(value))->Chars)

namespace Xias {

    enum class ObjectType
    {
		function_object,
		native_function_object,
		void_native_function_object,
        string_object,
		instance_object,
    };

    struct x_object
    {
        ObjectType Type;
		bool IsMarked;
		x_object* Next;
    };

    struct StringObject
    {
        x_object Object;
        x_ulong Size;
        char* Chars = nullptr;
    };

	enum class XType
	{
		Double,
		Float,
		Int,
		UInt,
		Bool,
		String,
		Instance,

		Function,
		NativeFunction,
		VoidNativeFunction,
	};

	struct FunctionObject
	{
		x_object Object;
		int Arity;
		int RequiredStackSize;
		int LocalCount;
		Bytecode Code;
		StringObject* Name;
	};

	struct InstanceObject
	{
		x_object Object;
		x_class Class;
		std::vector<Value> Members;
	};

	class Vm;

	typedef Value(*NativeFn)(Vm* xvm, int argCount, Value* args);

	struct NativeObject
	{
		x_object Object;
		NativeFn Function;
	};

	typedef void(*VoidNativeFn)(Vm* xvm, int argCount, Value* args);

	struct VoidNativeObject
	{
		x_object Object;
		VoidNativeFn Function;
	};

}
