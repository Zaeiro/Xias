#include "object.h"

#include "memory.h"
#include "types.h"

#define ALLOCATE_OBJ(type, objectType) \
    (type*)allocateObject(sizeof(type), objectType)

namespace Xias {

    static Object* allocateObject(size_t size, ObjectType type) {
        Object* object = (Object*)reallocate(NULL, 0, size);
        object->Type = type;
        return object;
    }

    static StringObject* allocateString(char* chars, x_ulong length) {
        StringObject* string = ALLOCATE_OBJ(StringObject, ObjectType::string_object);
        string->Size = length;
        string->Chars = chars;
        return string;
    }

    StringObject* takeString(char* chars, x_ulong length) {
        return allocateString(chars, length);
    }

    StringObject* copyString(const char* chars, x_ulong length) {
        char* heapChars = ALLOCATE(char, length + 1);
        memcpy(heapChars, chars, length);
        heapChars[length] = '\0';
        return allocateString(heapChars, length);
    }

}
