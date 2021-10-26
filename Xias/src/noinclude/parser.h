#pragma once

#include "lexer.h"
#include "object.h"

#include <vector>

namespace Xias {

	class Vm;

	struct SyntaxError : public std::exception
	{
		SyntaxError(unsigned long long line, const char* msg_)
		{
			msg = "Line " + line;
			msg += ": Error: ";
			msg += msg_;
		}

		SyntaxError(unsigned long long line, const std::string& msg_)
		{
			msg = "Line " + line;
			msg += ": Error: ";
			msg += msg_;
		}

		const char* what() const throw ()
		{
			return msg.c_str();
		}
	private:
		std::string msg;
	};

	enum class AccessibilityLevel
	{
		Public = 1,
		Protected = 2,
		Private = 4,
		Interal = 8
	};

	struct Staticable
	{
		int Accessibility;
		bool IsStatic = false;
	};

	struct Modifiers : public Staticable
	{
		bool IsVirtual = false;
		bool IsOverride = false;
	};

	struct ClassInfo;

	struct MemberInfo : public Modifiers
	{
		std::string Name;
		std::shared_ptr<ClassInfo> Type;
	};

	struct PropertyInfo : public MemberInfo
	{
		int Modifiers = 0;
		const NeoToken* AssignmentStart = nullptr;
		int AssignmentLength = 0;
	};

	struct MethodInfo : public MemberInfo
	{
		std::vector<NeoToken> Body;
		std::vector<std::pair<std::shared_ptr<ClassInfo>, std::string>> Parameters;
	};

	enum class OperatorType
	{
		UPlus,
		UMinus,
		PlusPlus,
		MinusMinus,
		True,
		False,
		BPlus,
		BMinus,
		Multiply,
		Divide,
		Modulo,
		And,
		Or,
		EqualEqual,
		BangEqual,
		Less,
		Greater,
		LessEqual,
		GreaterEqual
	};

	struct OperatorOverloadInfo : public Modifiers
	{
		OperatorType Operator;
		std::vector<NeoToken> Body;
	};

	struct ClassInfo : Staticable
	{
		std::string_view Name;
		int Modifiers = 0;
		std::vector<PropertyInfo> Properties;
		std::vector<MethodInfo> Methods;
		std::vector<OperatorOverloadInfo> OverloadedOperators;
	};

	namespace Modifier
	{
		enum
		{
			Public = 1,
			Protected = 2,
			Private = 4,
			Internal = 8,
			Static = 16,
			Virtual = 32,
			Override = 64
		};
	}

	class Parser
	{
		enum class Precedence
		{
			None,
			Lowest,
			Assignment,
			Conditional, // a ? b : c
			ConditionalOR,
			ConditionalAND,
			//LogicalOR,
			//LogicalXOR,
			//LogicalAND,
			Equality,
			Relational,
			Additive,
			Multiplicative,
			Switch,
			Unary,
			Primary,
		};

		typedef x_class(Parser::*ParseFn)();
		struct ParseRule
		{
			ParseFn Prefix;
			ParseFn Infix;
			Precedence Precedence;
		};

		enum class Scope
		{
			Namespace,
			Class,
			Function
		};

		static ParseRule m_Rules[(int)NeoTokenType::TokenCount];

		std::vector<NeoToken>::const_iterator m_TokensStart;
		std::vector<NeoToken>::const_iterator m_Previous;
		std::vector<NeoToken>::const_iterator m_Current;
		std::vector<NeoToken>::const_iterator m_TokensEnd;

		std::vector<std::shared_ptr<ClassInfo>> m_Classes;
		std::vector<int> m_ClassStack;
		int m_Modifiers = 0;

		std::vector<bool> m_ConstantExpressionTokens;

		std::vector<x_class> m_Builtins;
		std::unordered_map<x_class, ValueType> m_Types;

		std::unordered_map<std::string, std::vector<x_class>> m_FunctionParameters;

		x_class m_LastType;
		FunctionObject* m_Code;
		Scope m_CurrentScope;
		Vm* XVM;
	public:
		Parser();
		void Analyse(Vm* XVM, const std::vector<NeoToken>& tokens);

	private:
		void WriteOp(OpType op);
		ParseRule* GetRule(NeoTokenType tokenType);
		x_class ClassFromToken(const NeoToken* token);
		void Advance();
		bool Ensure(NeoTokenType token);
		void Consume(NeoTokenType token);
		
		std::shared_ptr<ClassInfo> FindClassInfo(std::string_view name);

		x_class Statement();
		x_class Expression();
		x_class ParsePrecedence(Precedence precedence);

		x_class VariableDeclaration(x_class expectedClass);

		void MakeConstant(Value value);
		x_class ParseDouble();
		x_class ParseFloat();
		x_class ParseInt();
		x_class ParseUInt();
		x_class ParseBool();
		x_class ParseString();

		x_class ParseLiteral();

		x_class ParseGroup();
		x_class ParseUnary();
		x_class ParseBinary();

		void Error(const char* msg);
		void Error(std::string& msg);
	};
}
