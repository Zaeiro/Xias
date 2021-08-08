#include "Xias.h"
#include <iostream>

int main() {
	Xias::Lexer lexer;

	lexer.Analyse("print(\"hello world\")");
	
	std::cin.get();
	return 0;
}
