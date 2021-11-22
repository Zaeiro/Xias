#include "Xias.h"

#include "XiasLexer.h"
#include "XiasParser.h"
#include "XiasVisitor.h"
#include "compilation_unit.h"

#include "Tests/xias_vm.h"

#include "antlr4-runtime.h"

#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <chrono>

int main()
{
	// test_lexer();
	// test_parser();
	// test_vm();

	std::ifstream stream;
	stream.open("input.xs");

	antlr4::ANTLRInputStream input(stream);
	XiasLexer lexer(&input);
	antlr4::CommonTokenStream tokens(&lexer);
	XiasParser parser(&tokens);
	XiasParser::Compilation_unitContext* tree = parser.compilation_unit();

	XiasVisitor visitor;
	Xias::CompilationUnit unitInfo = visitor.visitCompilation_unit(tree).as<Xias::CompilationUnit>();
	Xias::Vm vm;
	vm.Compile(unitInfo);

	Xias::x_class clas = vm.GetClass("Apple");
	Xias::x_method method = vm.GetStaticMethod(clas, "I;VeryCoolFunction;I;");
	std::cout << vm.CallStaticMethod(method, 1).as.Int << "\n";

	//size_t acc = 0;
	//auto begin = std::chrono::high_resolution_clock::now();
	//for (int i = 0; i < 100000; i++)
	//	acc += vm.CallStaticMethod(method, 1).as.Int;
	//auto end = std::chrono::high_resolution_clock::now();
	//std::cout << "xias code took: " << (float)std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() / 1.0f << "ms" << std::endl;


	std::cout << "All tests done" << std::endl;
	std::cin.get();
}
