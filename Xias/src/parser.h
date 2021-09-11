#pragma once

#include "lexer.h"

#include <vector>

namespace Xias {

	struct Node {
		enum class Type
		{
			Expression,
			Constant,
			Keyword,
			Operator,
		} Type;
		Token value;

		std::vector<Node> Children;
	};

	class Parser {


		Node Analyse(std::vector<Token> tokens) {
			/*
				Token<Keyword>("int")
				Token<Identifier>("myInt")
				Token<Assignment>("=")
				Token<Number>("32")
				Token<Semicolon>(";")
			*/


		}
	};
}
