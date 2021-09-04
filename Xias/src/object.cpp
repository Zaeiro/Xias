#include "object.h"

#include "memory.h"
#include "types.h"

#define ALLOCATE_OBJ(type, objectType) AllocObject<type>(objectType)

namespace Xias {

	template<typename T>
	static T* AllocObject(ObjectType type)
	{
		T* obj = new T();
		obj->Object.Type = type;
		return obj;
	}

    static StringObject* AllocateString(char* chars, x_ulong length)
	{
        StringObject* string = ALLOCATE_OBJ(StringObject, ObjectType::string_object);
        string->Size = length;
        string->Chars = chars;
        return string;
    }

	FunctionObject* NewFunction()
	{
		FunctionObject* function = ALLOCATE_OBJ(FunctionObject, ObjectType::function_object);
		function->Arity = 0;
		function->Code = Bytecode{};
		function->Name = nullptr;
		return function;
	}

	NativeObject* NewNative(NativeFn function)
	{
		NativeObject* native = ALLOCATE_OBJ(NativeObject, ObjectType::native_function_object);
		native->Function = function;
		return native;
	}

	VoidNativeObject* NewVoidNative(VoidNativeFn function)
	{
		VoidNativeObject* native = ALLOCATE_OBJ(VoidNativeObject, ObjectType::void_native_function_object);
		native->Function = function;
		return native;
	}

	StringObject* TakeString(char* chars, x_ulong length)
	{
        return AllocateString(chars, length);
    }

    StringObject* CopyString(const char* chars, x_ulong length)
	{
        char* heapChars = ALLOCATE(char, length + 1);
        memcpy(heapChars, chars, length);
        heapChars[length] = '\0';
        return AllocateString(heapChars, length);
    }

}
