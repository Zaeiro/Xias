#pragma once

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
    };

    struct x_object
    {
        ObjectType Type;
    };

    struct StringObject
    {
        x_object Object;
        x_ulong Size;
        char* Chars = nullptr;
    };

	struct FunctionObject
	{
		x_object Object;
		int Arity;
		Bytecode Code;
		StringObject* Name;
	};

	typedef Value(*NativeFn)(int argCount, Value* args);

	struct NativeObject
	{
		x_object Object;
		NativeFn Function;
	};

	typedef void(*VoidNativeFn)(int argCount, Value* args);

	struct VoidNativeObject
	{
		x_object Object;
		VoidNativeFn Function;
	};

	FunctionObject* NewFunction();
	NativeObject* NewNative(NativeFn function);
	VoidNativeObject* NewVoidNative(VoidNativeFn function);
    StringObject* TakeString(char* chars, x_ulong length);
    StringObject* CopyString(const char* chars, x_ulong length);

}
