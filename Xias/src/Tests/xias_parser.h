#pragma once

#include "Xias.h"

#include <iostream>
#include <vector>

inline void test_lexer()
{
	Xias::Lexer lexer;

	std::vector<Xias::Token> tokens = lexer.Analyse("myInt++; // this line increments the int, if you didnt know\nmyInt = 3 / 4;\n");
	lexer.PrintTokens(tokens);
}
