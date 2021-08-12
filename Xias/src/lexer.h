#pragma once
#include <vector>
#include <functional>
#include <stdio.h>
#include <ctype.h>

namespace Xias {

	enum class TokenType : uint8_t
	{
		Identifier = 0U,
		Keyword,
		Operator,
		String,
		Number,

		Colon,
		Semicolon,

		LCurly, // Left curly bracket
		RCurly, // Right curly bracket

		LParen, // Left parentheses
		RParen, // Right parentheses

		Assignment, // =
		Comment,

	};

	struct Token
	{
		TokenType type;
		std::string value;
		int start;
		int offset;
	};

	class Lexer
	{
		std::vector<std::string> keywords{
			"public",
			"private",
			"class",
			"struct",
			"int",
			"float",
			"string"
		};

		std::vector<Token> tokens;

		Token PushToken(TokenType type, const std::string& value, int start, int offset)
		{
			Token token;
			token.type = type;
			token.value = value;
			token.start = start;
			token.offset = offset;
			tokens.push_back(token);
			return token;
		}

		int Parse(int index, const std::string& code, TokenType type, std::function<bool(char)> condition) {
			int start = index;

			char c = code[index];
			do {
				index++;
				c = code[index];
			} while (condition(c));

			std::string value = code.substr(start, index - start);
			//std::cout << "Parse(" << start << "," << index << ",\"" << value << "\")" << std::endl;
			PushToken(type, value, start, index - start);
			return index;
		}

		// TODO: add block comments
		int ParseComment(int index, const std::string& code) {
			int start = index;

			char c;
			do {
				index++;
				c = code[index];
			} while (c != '\n');

			std::string value = code.substr(start + 2, index - start - 2);
			PushToken(TokenType::Comment, value, start, index - start);
			return index;
		}

		int ParseString(int index, const std::string& code) {
			int start = index;

			do {
				index++;
			} while (code[index] != '"');

			std::string value = code.substr(start + 1, index - start - 1);
			PushToken(TokenType::String, value, start, index - start);
			return index + 1;
		}

	public:
		void PrintTokens(std::vector<Token> tokens) {
			for (Token token : tokens) {
				PrintToken(token);
			}
		}

		void PrintToken(Token token) {
			std::string type;

			switch (token.type)
			{
			case TokenType::Identifier: type = "Identifier"; break;
			case TokenType::Keyword: type = "Keyword"; break;
			case TokenType::Operator: type = "Operator"; break;
			case TokenType::String: type = "String"; break;
			case TokenType::Number: type = "Number"; break;
			case TokenType::Colon: type = "Colon"; break;
			case TokenType::Semicolon: type = "Semicolon"; break;
			case TokenType::LCurly: type = "LCurly"; break;
			case TokenType::RCurly: type = "RCurly"; break;
			case TokenType::LParen: type = "LParen"; break;
			case TokenType::RParen: type = "RParen"; break;
			case TokenType::Assignment: type = "Assignment"; break;
			case TokenType::Comment: type = "Comment"; break;

			default: type = "UNIDENTIFIED"; break;
			}

			std::cout << "Token<" << type << ">(" << token.start << "," << token.offset + token.start << ")" << " = \"" << token.value << "\"" << std::endl;
		}

		std::vector<Token> Analyse(const std::string& code)
		{
			tokens.clear();

			int index = 0;
			while (index < code.length())
			{
				char current = code[index];
				char next = code[index + 1];
				
				if (current == '/' && next == '/') { index = ParseComment(index, code); continue; }

				if (isalpha(current)) { index = Parse(index, code, TokenType::Identifier, [](char c) { return isalpha(c) || isdigit(c); }); continue; }
				if (isdigit(current)) { index = Parse(index, code, TokenType::Number, [](char c) { return isdigit(c); }); continue; }

				// check if literal

				if (current == '=') { index = Parse(index, code, TokenType::Assignment, [](char c) { return false; }); continue; }
				if (current == '+') { index = Parse(index, code, TokenType::Operator, [](char c) { return c == '+'; }); continue; }
				if (current == '-') { index = Parse(index, code, TokenType::Operator, [](char c) { return c == '-'; }); continue; }
				if (current == '*') { index = Parse(index, code, TokenType::Operator, [](char c) { return false; }); continue; }
				if (current == '/') { index = Parse(index, code, TokenType::Operator, [](char c) { return false; }); continue; }
				if (current == '%') { index = Parse(index, code, TokenType::Operator, [](char c) { return false; }); continue; }
				if (current == '^') { index = Parse(index, code, TokenType::Operator, [](char c) { return false; }); continue; }

				if (current == '{') { index = Parse(index, code, TokenType::LCurly, [](char c) { return false; }); continue; }
				if (current == '}') { index = Parse(index, code, TokenType::RCurly, [](char c) { return false; }); continue; }

				if (current == '(') { index = Parse(index, code, TokenType::LParen, [](char c) { return false; }); continue; }
				if (current == ')') { index = Parse(index, code, TokenType::RParen, [](char c) { return false; }); continue; }

				if (current == ';') { index = Parse(index, code, TokenType::Semicolon, [](char c) { return false; }); continue; }

				if (current == '"') { index = ParseString(index, code); continue; }

				// Advance one char if nothing found
				index++;
			}

			// Replace identifiers with keywords if their value matches any defined keywords
			for (Token& token : tokens) {
				if (std::find(keywords.begin(), keywords.end(), token.value) != keywords.end()) {
					token.type = TokenType::Keyword;
				}
			}

			return tokens;
		}
	};
}
