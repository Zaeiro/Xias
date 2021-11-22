#pragma once

#include "Xias.h"

#include <iostream>
#include <vector>

inline void test_parser()
{
	Xias::Parser parser;
	Xias::Vm XVM;

	std::vector<Xias::NeoToken> tokens;
	//tokens.emplace_back(Xias::NeoTokenType::Identifier, "apple");
	//tokens.emplace_back(Xias::NeoTokenType::Equal, "=");
	tokens.emplace_back(Xias::NeoTokenType::LeftParen, "(");
	tokens.emplace_back(Xias::NeoTokenType::LeftParen, "(");
	tokens.emplace_back(Xias::NeoTokenType::I, "3");
	tokens.emplace_back(Xias::NeoTokenType::Plus, "+");
	tokens.emplace_back(Xias::NeoTokenType::I, "2");
	tokens.emplace_back(Xias::NeoTokenType::Star, "*");
	tokens.emplace_back(Xias::NeoTokenType::I, "8");
	tokens.emplace_back(Xias::NeoTokenType::RightParen, ")");
	tokens.emplace_back(Xias::NeoTokenType::Less, "<");
	tokens.emplace_back(Xias::NeoTokenType::I, "100");
	tokens.emplace_back(Xias::NeoTokenType::RightParen, ")");
	tokens.emplace_back(Xias::NeoTokenType::EqualEqual, "==");
	tokens.emplace_back(Xias::NeoTokenType::LeftParen, "(");
	tokens.emplace_back(Xias::NeoTokenType::String, "yoyoasusyiaodwbd");
	tokens.emplace_back(Xias::NeoTokenType::EqualEqual, "==");
	tokens.emplace_back(Xias::NeoTokenType::String, "");
	tokens.emplace_back(Xias::NeoTokenType::RightParen, ")");
	tokens.emplace_back(Xias::NeoTokenType::Semicolon, ";");

	//tokens.emplace_back(Xias::NeoTokenType::LeftParen, "(");
	//tokens.emplace_back(Xias::NeoTokenType::True, "true");
	//tokens.emplace_back(Xias::NeoTokenType::RightParen, ")");
	//tokens.emplace_back(Xias::NeoTokenType::EqualEqual, "==");
	//tokens.emplace_back(Xias::NeoTokenType::LeftParen, "(");
	//tokens.emplace_back(Xias::NeoTokenType::True, "true");
	//tokens.emplace_back(Xias::NeoTokenType::RightParen, ")");
	//tokens.emplace_back(Xias::NeoTokenType::Semicolon, ";");

	Xias::Bytecode code = parser.Analyse(&XVM, tokens);
	XVM.CallFunction(code);
}
