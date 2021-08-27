#include "object.h"

#include "memory.h"
#include "types.h"

#define ALLOCATE_OBJ(type, objectType) \
    (type*)AllocateObject(sizeof(type), objectType)

namespace Xias {

    static x_object* AllocateObject(size_t size, ObjectType type)
	{
        x_object* object = (x_object*)reallocate(NULL, 0, size);
		object->Type = type;
        return object;
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
		function->Name = nullptr;
		return function;
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
