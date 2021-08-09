#pragma once
#include <vector>
#include <functional>
#include <stdio.h>
#include <ctype.h>

namespace Xias {

	enum class TokenType : uint8_t
	{
		Identifier = 0U,
		String,
		Number,

		Colon,
		Semicolon,

		LCurly, // Left curly bracket
		RCurly, // Right curly bracket

		LParen, // Left parentheses
		RParen, // Right parentheses

	};

	struct Token
	{
		TokenType type;
		const char* value;
	};

	class Lexer
	{
		std::vector<Token> tokens;

		void PushToken(TokenType type, const char* value)
		{
			Token token;
			token.type = type;
			token.value = value;
			tokens.push_back(token);
		}

		int ParseIdentifier(int index, const std::string& code)
		{
			int startIndex = index;

			while (code[index] != ' ') {
				index++;
			}

			PushToken(TokenType::Identifier, code.substr(startIndex, index).c_str());

			return index;
		}

	public:
		std::vector<Token> Analyse(const std::string& code)
		{
			tokens.clear();

			uint64_t index = 0;
			while (index < code.length())
			{
				std::function<int(int, std::string)> parser;

				auto character = code[index];
				// check if alphabetic
				// check if numeric
				// check if literal

			}

			return tokens;
		}
	};
}
