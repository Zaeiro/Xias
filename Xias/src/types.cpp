#include "types.h"

bool Xias::operator==(const Value& lhs, const Value& rhs)
{
	return lhs.Type == rhs.Type && lhs.as.UInt == rhs.as.UInt;
}

std::string Xias::GetTypeInitial(const std::string& type)
{
	if (type == "int") return "I;";
	else if (type == "uint") return "U;";
	else if (type == "char") return "U;"; // No char type
	else if (type == "double") return "D;";
	else if (type == "float") return "F;";
	else if (type == "bool") return "B;";
	else if (type == "string") return "S;";
	else if (type == "void") return "V;";
	else return type + ';';
}
