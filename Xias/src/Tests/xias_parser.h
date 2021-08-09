#pragma once

#include "Xias.h"

#include <iostream>
#include <vector>

inline void test_lexer()
{
	Xias::Lexer lexer;

	std::vector<Xias::Token> tokens = lexer.Analyse("myInt += 1;");
	lexer.PrintTokens(tokens);
	
	std::cout << "All tests done" << std::endl;
	std::cin.get();
}
