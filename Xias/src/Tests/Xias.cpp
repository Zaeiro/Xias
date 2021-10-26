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

int main()
{
	//std::vector<Xias::Token> tokens = lexer.Analyse("int myInt = 32;");
	//Xias::Node* node = parser.Analyse(tokens);

	// are we making a parser or compiler?
	// a parser, then a compiler
	// aight

	// The vm has to handle compilation itself
	// because of reasons

	// test_lexer();
	// test_parser();
	// test_vm();

	//std::ifstream stream;
	//stream.open("sample.x");

	std::ifstream stream;
	stream.open("input.xs");

	antlr4::ANTLRInputStream input(stream);
	XiasLexer lexer(&input);
	antlr4::CommonTokenStream tokens(&lexer);
	XiasParser parser(&tokens);
	XiasParser::Compilation_unitContext* tree = parser.compilation_unit();

	XiasVisitor visitor;
	Xias::CompilationUnit unitInfo = visitor.visitCompilation_unit(tree).as<Xias::CompilationUnit>();
	//visitor.visitCompilation_unit(tree);
	//Xias::Vm vm;
	//vm.ReadUnit(unitInfo);
	//vm.ReadUnit(unitInfo2);

	std::cout << "All tests done" << std::endl;
	std::cin.get();
}
