#pragma once

#include "types.h"

#define OBJ_VAL(object) (Xias::Value{ .Object = (Xias::Object*)object })

#define OBJ_TYPE(value) (AS_OBJ(value)->Type)

#define AS_STRING(value) ((StringObject*)AS_OBJ(value))
#define AS_CSTRING(value) (((StringObject*)AS_OBJ(value))->Chars)

namespace Xias {

    enum class ObjectType
    {
        string_object,
    };

    struct Object
    {
        ObjectType Type;
    };

    struct StringObject
    {
        Object Object;
        x_ulong Size;
        char* Chars = nullptr;
    };

    StringObject* takeString(char* chars, x_ulong length);
    StringObject* copyString(const char* chars, x_ulong length);

}
