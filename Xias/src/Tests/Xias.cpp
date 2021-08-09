#include "Xias.h"

#include "Tests/xias_vm.h"
#include "Tests/xias_parser.h"

#include <iostream>

#include <string>
#include <stdio.h>
#include <ctype.h>


int main()
{
	//test_vm();
	test_lexer();

	//std::string msg = "abcdef 1245 @[]";
	//for (char c : msg) {
	//	std::cout << c << "=" << (bool)isalpha(c) << std::endl;
	//}

	std::cout << "All tests done" << std::endl;
	std::cin.get();
}
