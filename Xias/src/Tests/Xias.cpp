#include "Xias.h"

#include "Tests/xias_vm.h"
#include "Tests/xias_parser.h"

#include <iostream>

#include <string>
#include <stdio.h>
#include <ctype.h>


int main()
{
	std::cin.get();

	test_vm();
	test_lexer();

	std::cout << "All tests done" << std::endl;
	std::cin.get();
}
