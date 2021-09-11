#include "Xias.h"

#include "Tests/xias_vm.h"
#include "Tests/xias_parser.h"
#include "Tests/xias_lexer.h"

#include <iostream>

#include <string>
#include <stdio.h>
#include <ctype.h>


int main()
{
	std::vector<Xias::Token> tokens = lexer.Analyse("int myInt = 32;");
	Xias::Node* node = parser.Analyse(tokens);

	// are we making a parser or compiler?
	// a parser, then a compiler
	// aight

	// The vm has to handle compilation itself
	// because of reasons

	// test_vm();
	// test_lexer();

	std::cout << "All tests done" << std::endl;
	std::cin.get();
}
