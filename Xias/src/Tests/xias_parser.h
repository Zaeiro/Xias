#pragma once

#include "Xias.h"

#include <iostream>
#include <vector>

inline void test_lexer()
{
	Xias::Lexer lexer;

	std::vector<Xias::Token> tokens = lexer.Analyse("myInt++;myInt--;\n// comment test\nmyInt += 1;/*myInt = 1;\nmyInt += 2;*/myInt--;");
	lexer.PrintTokens(tokens);
}
