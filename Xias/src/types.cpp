#include "types.h"

bool Xias::operator==(const Value& lhs, const Value& rhs)
{
	return lhs.Type == rhs.Type && lhs.as.UInt == rhs.as.UInt;
}
