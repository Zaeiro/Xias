#pragma once

#include "Xias.h"

#include <iostream>

inline void test_lexer()
{
	Xias::Lexer lexer;

	lexer.Analyse("print(\"hello world\")");
	
	std::cin.get();
}
