#include "types.h"

bool Xias::operator==(const Value& lhs, const Value& rhs)
{
	return lhs.Type == rhs.Type && lhs.as.UInt == rhs.as.UInt;
}

std::string Xias::GetTypeInitial(const std::string& type)
{
	std::string result;
	size_t delimiter;
	if ((delimiter = type.find("[")) != std::string::npos)
		result = type.substr(0, delimiter);
	else
		result = type;

	if (result == "int") result = "I;";
	else if (result == "uint") result = "U;";
	else if (result == "char") result = "U;"; // No char type
	else if (result == "double") result = "D;";
	else if (result == "float") result = "F;";
	else if (result == "bool") result = "B;";
	else if (result == "string") result = "S;";
	else if (result == "object") result = "O";
	else if (result == "void") result = "V;";
	else result += ';';
	if ((delimiter = type.find("[")) != std::string::npos)
		result += type.substr(delimiter);
	return result;
}
