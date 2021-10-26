#include "parser.h"

#include "vm.h"
#include "common.h"

#include <string>

namespace Xias {

	Parser::ParseRule Parser::m_Rules[(int)NeoTokenType::TokenCount] = {
		{&Parser::ParseGroup,nullptr, Precedence::None}, // LeftParen
		{nullptr, nullptr, Precedence::None}, // RightParen
		{nullptr, nullptr, Precedence::None}, // LeftBrace
		{nullptr, nullptr, Precedence::None}, // RightBrace
		{nullptr, nullptr, Precedence::None}, // Comma
		{nullptr, nullptr, Precedence::None}, // Dot
		{&Parser::ParseUnary, &Parser::ParseBinary, Precedence::Additive}, // Minus
		{nullptr, &Parser::ParseBinary, Precedence::Additive}, // Plus
		{nullptr, nullptr, Precedence::None}, // Semicolon
		{nullptr, &Parser::ParseBinary, Precedence::Multiplicative}, // Slash
		{nullptr, &Parser::ParseBinary, Precedence::Multiplicative}, // Star
		{nullptr, &Parser::ParseBinary, Precedence::Multiplicative}, // Percent
		{nullptr, &Parser::ParseBinary, Precedence::Multiplicative}, // Caret,
		{nullptr, &Parser::ParseBinary, Precedence::None}, // Colon,
		{&Parser::ParseUnary, nullptr, Precedence::None}, // Bang
		{nullptr, &Parser::ParseBinary, Precedence::Equality}, // BangEqual
		{nullptr, nullptr, Precedence::None}, // Equal
		{nullptr, &Parser::ParseBinary, Precedence::Equality}, // EqualEqual
		{nullptr, &Parser::ParseBinary, Precedence::Relational}, // Greater
		{nullptr, &Parser::ParseBinary, Precedence::Relational}, // GreaterEqual
		{nullptr, &Parser::ParseBinary, Precedence::Relational}, // Less
		{nullptr, &Parser::ParseBinary, Precedence::Relational}, // LessEqual
		{nullptr, nullptr, Precedence::None}, // MinusEqual
		{nullptr, nullptr, Precedence::None}, // PlusEqual
		{nullptr, nullptr, Precedence::None}, // SlashEqual
		{nullptr, nullptr, Precedence::None}, // StarEqual
		{&Parser::ParseUnary, nullptr, Precedence::None}, // MinusMinus
		{&Parser::ParseUnary, nullptr, Precedence::None}, // PlusPlus
		{nullptr, nullptr, Precedence::None}, // Identifier
		{&Parser::ParseString, nullptr, Precedence::None}, // String
		{&Parser::ParseInt, nullptr, Precedence::None}, // I
		{&Parser::ParseUInt, nullptr, Precedence::None}, // U
		{&Parser::ParseFloat, nullptr, Precedence::None}, // F
		{&Parser::ParseDouble, nullptr, Precedence::None}, // D
		{nullptr, nullptr, Precedence::None}, // And
		{nullptr, nullptr, Precedence::None}, // Class
		{nullptr, nullptr, Precedence::None}, // Else
		{&Parser::ParseLiteral, nullptr, Precedence::None}, // False
		{nullptr, nullptr, Precedence::None}, // For
		{nullptr, nullptr, Precedence::None}, // If
		{nullptr, nullptr, Precedence::None}, // Or
		{nullptr, nullptr, Precedence::None}, // Return
		{nullptr, nullptr, Precedence::None}, // Super
		{nullptr, nullptr, Precedence::None}, // This
		{&Parser::ParseLiteral, nullptr, Precedence::None}, // Null
		{&Parser::ParseLiteral, nullptr, Precedence::None}, // True
		{nullptr, nullptr, Precedence::None}, // While
		{nullptr, nullptr, Precedence::None}, // Switch
		{nullptr, nullptr, Precedence::None}, // Break
		{nullptr, nullptr, Precedence::None}, // Static
		{nullptr, nullptr, Precedence::None}, // Virtual
		{nullptr, nullptr, Precedence::None}, // Override
		{nullptr, nullptr, Precedence::None}, // Public
		{nullptr, nullptr, Precedence::None}, // Protected
		{nullptr, nullptr, Precedence::None}, // Private
		{nullptr, nullptr, Precedence::None}, // Namespace
		{nullptr, nullptr, Precedence::None}, // New
		{nullptr, nullptr, Precedence::None}, // Operator
		{nullptr, nullptr, Precedence::None}, // Get
		{nullptr, nullptr, Precedence::None}, // Set
		{nullptr, nullptr, Precedence::None}, // Double
		{nullptr, nullptr, Precedence::None}, // Float
		{nullptr, nullptr, Precedence::None}, // Int
		{nullptr, nullptr, Precedence::None}, // UInt
		{nullptr, nullptr, Precedence::None}, // Bool
		{nullptr, nullptr, Precedence::None}, // Object
	};

	//const std::unordered_map<std::string, Parser::Precedence> Parser::m_Precedences = {
	//	//{".", Parser::Precedence::Equality},
	//	//{"!=", Parser::Precedence::Equality},
	//	//{"<", Parser::Precedence::LessGreater},
	//	//{">", Parser::Precedence::LessGreater},
	//};

	Parser::Parser()
	{
		m_Classes.resize(7);
		m_Classes[0]->Name = "double";
		m_Classes[1]->Name = "float";
		m_Classes[2]->Name = "int";
		m_Classes[3]->Name = "uint";
		m_Classes[4]->Name = "bool";
		m_Classes[5]->Name = "Object";
		m_Classes[6]->Name = "String";
		for (std::shared_ptr<ClassInfo> cinfo : m_Classes)
			cinfo->Modifiers = Modifier::Public;
	}

	void Parser::Analyse(Vm* XVM, const std::vector<NeoToken>& tokens)
	{
		/*
			Token<Keyword>("int")
			Token<Identifier>("myInt")
			Token<Assignment>("=")
			Token<Number>("32")
			Token<Semicolon>(";")
		*/

		this->XVM = XVM;

		m_Builtins.emplace_back(XVM->GetClass("Double"));
		m_Builtins.emplace_back(XVM->GetClass("Float"));
		m_Builtins.emplace_back(XVM->GetClass("Int"));
		m_Builtins.emplace_back(XVM->GetClass("UInt"));
		m_Builtins.emplace_back(XVM->GetClass("Bool"));
		m_Builtins.emplace_back(XVM->GetClass("Object"));
		m_Builtins.emplace_back(XVM->GetClass("String"));

		m_Types.emplace(m_Builtins[(int)ValueType::Double], ValueType::Double);
		m_Types.emplace(m_Builtins[(int)ValueType::Float], ValueType::Float);
		m_Types.emplace(m_Builtins[(int)ValueType::Int], ValueType::Int);
		m_Types.emplace(m_Builtins[(int)ValueType::UInt], ValueType::UInt);
		m_Types.emplace(m_Builtins[(int)ValueType::Bool], ValueType::Bool);
		m_Types.emplace(m_Builtins[(int)ValueType::Object], ValueType::Object);

		m_TokensStart = tokens.begin();
		m_Previous = tokens.begin();
		m_Current = tokens.begin();
		m_TokensEnd = tokens.end();

		m_CurrentScope = Scope::Namespace;
		try
		{
			while (m_Current < m_TokensEnd)
			{
				Statement();
			}
		}
		catch (SyntaxError& error)
		{

			std::cout << error.what() << std::endl;
		}
	}

	void Parser::WriteOp(OpType op)
	{
		m_Code->Code.Code.emplace_back(op);
	}

	Parser::ParseRule* Parser::GetRule(NeoTokenType tokenType)
	{
		return &m_Rules[(int)tokenType];
	}

	x_class Parser::ClassFromToken(const NeoToken* token)
	{
		x_class type = nullptr;
		int index = (int)token->type - (int)NeoTokenType::Double;
		if (index >= 0 && index <= (int)ValueType::Object)
		{
			type = m_Builtins[index];
		}
		else if (token->type == NeoTokenType::Identifier)
		{
			type = XVM->GetClass(token->value);
			if (!type)
			{
				std::cout << "class \"" << token->value << "\" not found" << std::endl;
				return nullptr;
			}
		}
		else
		{
			std::cout << "not an identifier" << std::endl;
			return nullptr;
		}

		return type;
	}

	void Parser::Advance()
	{
		m_Previous = m_Current++;
	}

	bool Parser::Ensure(NeoTokenType token)
	{
		Advance();
		return m_Current != m_TokensEnd && m_Current->type == token;
	}

	void Parser::Consume(NeoTokenType token)
	{
		if (m_Current->type == token)
		{
			Advance();
			return;
		}

		// ugh
		std::cout << "error" << std::endl;
	}

	std::shared_ptr<ClassInfo> Parser::FindClassInfo(std::string_view name)
	{
		for (std::shared_ptr<ClassInfo> info : m_Classes)
		{
			if (info->Name == name)
				return info;
		}
		return nullptr;
	}

	x_class Parser::Statement()
	{
		switch (m_Current->type)
		{
			case NeoTokenType::Public:
			{
				if (m_Modifiers & Modifier::Public)
					Error("Duplicate 'public' modifier");
				m_Modifiers |= Modifier::Public;
			}
			case NeoTokenType::Protected:
			{
				if (m_Modifiers & Modifier::Protected)
					Error("Duplicate 'protected' modifier");
				if (m_CurrentScope == Scope::Namespace)
					Error("Elements defined in a namespace cannot be explicitly declared as private, protected, or protected internal");
				m_Modifiers |= Modifier::Protected;
			}
			case NeoTokenType::Private:
			{
				if (m_Modifiers & Modifier::Private)
					Error("Duplicate 'private' modifier");
				if ((m_Modifiers & Modifier::Virtual) && m_CurrentScope == Scope::Class)
					Error("Virtual members cannot be private");
				if (m_CurrentScope == Scope::Namespace)
					Error("Elements defined in a namespace cannot be explicitly declared as private, protected, or protected internal");
				m_Modifiers |= Modifier::Private;
			}
			case NeoTokenType::Static:
			{
				if (m_Modifiers & Modifier::Static)
					Error("Duplicate 'static' modifier");
				m_Modifiers |= Modifier::Static;
			}
			case NeoTokenType::Virtual:
			{
				if (m_Modifiers & Modifier::Virtual)
					Error("Duplicate 'virtual' modifier");
				m_Modifiers |= Modifier::Virtual;
			}
			case NeoTokenType::Override:
			{
				if (m_Modifiers & Modifier::Override)
					Error("Duplicate 'override' modifier");
				m_Modifiers |= Modifier::Override;
			}
			case NeoTokenType::Class:
			{
				if (m_CurrentScope == Scope::Function)
					Error("Class declarations are disallowed inside method bodys");
				if (!Ensure(NeoTokenType::Identifier))
					Error("Identifier expected");
				std::string_view name = m_Current->value;
				if (!Ensure(NeoTokenType::LeftBrace))
					Error("{ Expected");

				m_CurrentScope = Scope::Class;
				m_ClassStack.emplace_back(m_Classes.size());
				std::shared_ptr<ClassInfo> cinfo = m_Classes.emplace_back();
				cinfo->Name = name;

				cinfo->Modifiers = m_Modifiers;
				m_Modifiers = 0;
			}
			case NeoTokenType::Identifier:
			{
				if (m_CurrentScope == Scope::Class)
				{
					std::shared_ptr<ClassInfo> cinfo = m_Classes[m_ClassStack.back()];
					std::string_view typeName = m_Current->value;
					std::shared_ptr<ClassInfo> idClass = FindClassInfo(typeName);
					if (!idClass)
						Error(std::string("The type '") + idClass->Name.data() + "' could not be found");

					if (!Ensure(NeoTokenType::Identifier))
						Error("Member name expected");
					std::string_view idName = m_Current->value;

					if (cinfo->Modifiers & Modifier::Static)
					{
						if ((m_Modifiers & Modifier::Static) == 0)
							Error(std::string("'") + idName.data() + "': cannot declare instance members in static class");
					}

					Advance();
					if (m_Current->type == NeoTokenType::Semicolon)
					{
						PropertyInfo pinfo;
						pinfo.Modifiers = m_Modifiers;
						pinfo.Name = idName;
						pinfo.Type = idClass;
						cinfo->Properties.emplace_back(pinfo);
					}
					else if (m_Current->type == NeoTokenType::Equal)
					{
						PropertyInfo pinfo;
						pinfo.Modifiers = m_Modifiers;
						pinfo.Name = idName;
						pinfo.Type = idClass;

						Advance();
						pinfo.AssignmentStart = &*m_Current;
						auto start = m_Current;
						while (m_Current != m_TokensEnd && m_Current->type != NeoTokenType::Semicolon && m_Current->type != NeoTokenType::Comma)
						{
							Advance();
						}
						pinfo.AssignmentLength = m_Current - start;
						cinfo->Properties.emplace_back(pinfo);
					}
					m_Modifiers = 0;
				}
			}

			//case NeoTokenType::If:
			//{
			//	Consume(NeoTokenType::LeftParen);
			//	x_class xClass = Expression();
			//	Consume(NeoTokenType::RightParen);
			//	WriteOp(Instruction::pop_value);
			//	break;
			//}
			case NeoTokenType::Class:
			{
				if (m_CurrentScope == Scope::Function)
				{
					std::cout << "error" << std::endl;
					break;
				}
				m_CurrentScope = Scope::Class;
				Ensure(NeoTokenType::Identifier);
				x_class xClass = XVM->GetClass(m_Current->value);
				if (xClass)
				{
					std::cout << "error" << std::endl;
					return;
				}
				xClass = XVM->AddClass(m_Current->value);

				bool isChild = false;
				Advance();
				if (m_Current->type == NeoTokenType::Colon)
				{
					Ensure(NeoTokenType::Identifier);
					x_class parentClass = XVM->GetClass(m_Current->value);
					if (!parentClass)
					{
						std::cout << "error" << std::endl;
						return;
					}
					isChild = true;
					xClass->Parent = parentClass;
				}

				FunctionObject* defaultInit = XVM->NewFunction();
				XVM->PinObject((x_object*)defaultInit);
				m_Code = defaultInit;

				//xClass->FunctionIndices.emplace("new", xClass->Functions.size());
				//FunctionObject* defaultCtor = xClass->Functions.emplace_back(XVM->NewFunction());
				//m_Code = defaultCtor;

				Ensure(NeoTokenType::LeftBrace);
				Advance();
				while (m_Current->type != NeoTokenType::RightBrace)
				{
					bool isStatic = false;
					bool isVirtual = false;
					bool isOverride = false;

					bool isPublic = false;
					bool isProtected = false;
					bool isPrivate = false;
					while (m_Current->type != NeoTokenType::Semicolon)
					{
						if (m_Current->type == NeoTokenType::Static) isStatic = true;
						if (m_Current->type == NeoTokenType::Virtual) isVirtual = true;
						if (m_Current->type == NeoTokenType::Override) isOverride = true;
						if (m_Current->type == NeoTokenType::Public) isPublic = true;
						if (m_Current->type == NeoTokenType::Protected) isProtected = true;
						if (m_Current->type == NeoTokenType::Private) isPrivate = true;

						x_class type = ClassFromToken(&*m_Current);
						
						// Compiling a ctor
						// Example:
						// class Apple
						// {
						//		Apple()
						//		{
						//		}
						// }
						if (type == xClass)
						{
							Consume(NeoTokenType::LeftParen);
							std::string functionName = xClass->Name + "::" + "new";
							std::vector<x_class> parameterTypes;
							while (m_Current->type != NeoTokenType::RightParen)
							{
								x_class param = ClassFromToken(&*m_Current);
								if (param)
									parameterTypes.emplace_back(param);
								Consume(NeoTokenType::Identifier);
								Advance();
							}
							m_FunctionParameters.emplace(functionName, parameterTypes);

							Consume(NeoTokenType::LeftBrace);
							m_CurrentScope = Scope::Function;
							xClass->FunctionIndices.emplace("new", xClass->Functions.size());
							FunctionObject* func = xClass->Functions.emplace_back(XVM->NewFunction());
							m_Code = func;
							while (m_Current->type != NeoTokenType::RightBrace)
							{
								Statement();
							}
							Consume(NeoTokenType::RightBrace);
						}

						Ensure(NeoTokenType::Identifier);
						std::string identifier = m_Current->value;

						Advance();
						if (m_Current->type == NeoTokenType::LeftParen)
						{
							Advance();
							std::string functionName = xClass->Name + "::" + identifier;
							std::vector<x_class> parameterTypes;
							while (m_Current->type != NeoTokenType::RightParen)
							{
								x_class param = ClassFromToken(&*m_Current);
								if (param)
									parameterTypes.emplace_back(param);
								Consume(NeoTokenType::Identifier);
								Advance();
							}
							m_FunctionParameters.emplace(functionName, parameterTypes);

							Consume(NeoTokenType::LeftBrace);
							m_CurrentScope = Scope::Function;
							xClass->FunctionIndices.emplace(identifier, xClass->Functions.size());
							FunctionObject* func = xClass->Functions.emplace_back(XVM->NewFunction());
							m_Code = func;
							while (m_Current->type != NeoTokenType::RightBrace)
							{
								Statement();
							}
							Consume(NeoTokenType::RightBrace);
						}
						else
						{
							xClass->MemberIndices.emplace(identifier, xClass->MemberCount++);
							Advance();
							if (m_Current->type == NeoTokenType::Equal)
							{
								Advance();

							}
						}
					}
				}

				XVM->UnPinObject((x_object*)defaultInit);
				Consume(NeoTokenType::RightBrace);
			}
		}
		x_class xClass = Expression();
		Consume(NeoTokenType::Semicolon);
		WriteOp(Instruction::pop_value);
		return xClass;
	}

	x_class Parser::Expression()
	{
		return ParsePrecedence(Precedence::Lowest);
	}

	x_class Parser::ParsePrecedence(Precedence precedence)
	{
		Advance();
		ParseFn prefixRule = GetRule(m_Previous->type)->Prefix;
		if (prefixRule == nullptr)
		{
			//error("Expect expression.");
			return nullptr;
		}

		m_LastType = (this->*prefixRule)();

		while (m_Current != m_TokensEnd && precedence <= GetRule(m_Current->type)->Precedence)
		{
			Advance();
			ParseFn infixRule = GetRule(m_Previous->type)->Infix;
			m_LastType = (this->*infixRule)();
		}

		return m_LastType;
	}

	x_class Parser::VariableDeclaration(x_class expectedClass)
	{
		m_Code->LocalCount++;
	}

	void Parser::MakeConstant(Value value)
	{
		WriteOp(Instruction::push_value);
#ifdef COMPRESS_CONSTANTS
		auto element = std::find(m_Code->Code.Constants.begin(), m_Code->Code.Constants.end(), value);
		if (element != m_Code->Code.Constants.end())
		{
			WriteOp((_x_short)(element - m_Code->Code.Constants.begin()));
		}
		else
		{
			WriteOp((_x_short)m_Code->Code.Constants.size());
			m_Code->Code.Constants.emplace_back(value);
		}
#else
		WriteOp((_x_short)m_Code.Code.Constants.size());
		m_Code.Code.Constants.emplace_back(value);
#endif
	}

	x_class Parser::ParseDouble()
	{
		MakeConstant(std::stod(m_Previous->value));
		return m_Builtins[(int)ValueType::Double];
	}

	x_class Parser::ParseFloat()
	{
		MakeConstant(std::stof(m_Previous->value));
		return m_Builtins[(int)ValueType::Float];
	}

	x_class Parser::ParseInt()
	{
		MakeConstant(std::stoll(m_Previous->value));
		return m_Builtins[(int)ValueType::Int];
	}

	x_class Parser::ParseUInt()
	{
		MakeConstant(std::stoull(m_Previous->value));
		return m_Builtins[(int)ValueType::UInt];
	}

	x_class Parser::ParseBool()
	{
		if (m_Previous->type == NeoTokenType::True)
			MakeConstant(true);
		else if (m_Previous->type == NeoTokenType::False)
			MakeConstant(false);
		else
			exit(1);
		return m_Builtins[(int)ValueType::Bool];
	}

	x_class Parser::ParseString()
	{
		MakeConstant(XVM->CopyString(m_Previous->value));
		return m_Builtins[(int)ValueType::Object + 1];
	}

	x_class Parser::ParseLiteral()
	{
		switch (m_Previous->type)
		{
			case NeoTokenType::False: WriteOp(Instruction::literal_false); return m_Builtins[(int)ValueType::Bool];
			case NeoTokenType::True: WriteOp(Instruction::literal_true); return m_Builtins[(int)ValueType::Bool];
			case NeoTokenType::Null: WriteOp(Instruction::literal_nullptr); return m_Builtins[(int)ValueType::Object];
		}
		return nullptr;
	}

	x_class Parser::ParseGroup()
	{
		x_class type = Expression();
		if (m_Current->type != NeoTokenType::RightParen)
			std::cout << "Missing ')'.";
		Advance();

		return type;
	}

	x_class Parser::ParseUnary()
	{
		auto op = m_Previous;
		NeoTokenType operatorType = op->type;

		// Compile the operand.
		x_class type = Expression();

		auto iter = m_Types.find(type);
		ValueType valueType = (ValueType)-1;
		if (iter != m_Types.end())
			valueType = iter->second;

		// Emit the operator instruction.
		switch (operatorType)
		{
			case NeoTokenType::Minus:
			{
				switch (valueType)
				{
					case ValueType::Double: WriteOp(Instruction::double_negate); return m_Builtins[(int)ValueType::Double];
					case ValueType::Float: WriteOp(Instruction::float_negate); return m_Builtins[(int)ValueType::Float];
					case ValueType::Int: WriteOp(Instruction::int_negate); return m_Builtins[(int)ValueType::Int];
					case ValueType::UInt: /* error */ break;
					case ValueType::Bool: /* error */ break;
					case ValueType::Object: /* error */ break;
					default: break;
				}
				break;
			}
			case NeoTokenType::Bang:
			{
				if (valueType == ValueType::Bool)
				{
					WriteOp(Instruction::bool_negate);
					return m_Builtins[(int)ValueType::Bool];
				}
				else
					std::cout << "Bang (!) operator only works on Boolean types.";
				break;
			}
			case NeoTokenType::MinusMinus:
			{
				//if (op - 1 >= m_TokensStart && (op - 1)->type == NeoTokenType::Identifier)
				//{
				//	// decrease the var after using
				//}
				//else if ()
				//if (m_Current == m_TokensStart)
				//	std::cout << "The increment operator must be used on a variable or field.";
				//if ((m_Token - 1)->type != NeoTokenType::Identifier)
				//	std::cout << "The decrement operator must be used on a variable or field.";
				//// TODO: Make this an actual error.
				//	
				//switch (type)
				//{
				//	case ValueType::Double: WriteOp(Instruction::double_dec); break;
				//	case ValueType::Float: WriteOp(Instruction::float_dec); break;
				//	case ValueType::Int: WriteOp(Instruction::int_dec); break;
				//	case ValueType::UInt: WriteOp(Instruction::uint_dec); break;
				//	case ValueType::Bool: /* error */ break;
				//	case ValueType::Object: /* error */ break;
				//}
				break;
			}
			case NeoTokenType::PlusPlus:
			{
				//if (m_Token == m_TokensStart)
				//	std::cout << "The increment operator must be used on a variable or field.";
				//if ((m_Token - 1)->type != NeoTokenType::Identifier)
				//	std::cout << "The increment operator must be used on a variable or field.";
				//// TODO: Make these actual errors.

				//switch (type)
				//{
				//	case ValueType::Double: WriteOp(Instruction::double_dec); break;
				//	case ValueType::Float: WriteOp(Instruction::float_dec); break;
				//	case ValueType::Int: WriteOp(Instruction::int_dec); break;
				//	case ValueType::UInt: WriteOp(Instruction::uint_dec); break;
				//	case ValueType::Bool: /* error */ break;
				//	case ValueType::Object: /* error */ break;
				//}
				break;
			}
		}
		return nullptr;
	}

	x_class Parser::ParseBinary()
	{
		x_class leftType = m_LastType;

		auto last = m_Previous;
		NeoTokenType operatorType = m_Previous->type;
		ParseRule* rule = GetRule(operatorType);
		x_class rightType = ParsePrecedence((Precedence)((int)rule->Precedence + 1));

		std::cout << "adding operator " << last->value << " between types of " << leftType->Name << " and " << rightType->Name << std::endl;;

		if (leftType != rightType)
		{
			std::cout << "wrong types!\n";
			return nullptr;
		}
		// TODO: Make this an actual error.

		auto iter = m_Types.find(leftType);
		ValueType valueType = (ValueType)-1;
		if (iter != m_Types.end())
			valueType = iter->second;

		switch (operatorType)
		{
			case NeoTokenType::Plus:
			{
				switch (valueType)
				{
					case ValueType::Double: WriteOp(Instruction::double_add); return m_Builtins[(int)ValueType::Double];
					case ValueType::Float:  WriteOp(Instruction::float_add); return m_Builtins[(int)ValueType::Float];
					case ValueType::Int:    WriteOp(Instruction::int_add); return m_Builtins[(int)ValueType::Int];
					case ValueType::UInt:   WriteOp(Instruction::uint_add); return m_Builtins[(int)ValueType::UInt];
					case ValueType::Bool: /* error */ break;
					case ValueType::Object: /* error */ break;
					default:
					{
						if (leftType == m_Builtins[(int)ValueType::Object + 1])
						{
							WriteOp(Instruction::string_add);
							return m_Builtins[(int)ValueType::Object + 1];
						}
					}
				}
				break;
			}
			case NeoTokenType::Minus:
			{
				switch (valueType)
				{
					case ValueType::Double: WriteOp(Instruction::double_sub); return m_Builtins[(int)ValueType::Double];
					case ValueType::Float:  WriteOp(Instruction::float_sub); return m_Builtins[(int)ValueType::Float];
					case ValueType::Int:    WriteOp(Instruction::int_sub); return m_Builtins[(int)ValueType::Int];
					case ValueType::UInt:   WriteOp(Instruction::uint_sub); return m_Builtins[(int)ValueType::UInt];
					case ValueType::Bool: /* error */ break;
					case ValueType::Object: /* error */ break;
					default: break;
				}
				break;
			}
			case NeoTokenType::Star:
			{
				switch (valueType)
				{
					case ValueType::Double: WriteOp(Instruction::double_mul); return m_Builtins[(int)ValueType::Double];
					case ValueType::Float:  WriteOp(Instruction::float_mul); return m_Builtins[(int)ValueType::Float];
					case ValueType::Int:    WriteOp(Instruction::int_mul); return m_Builtins[(int)ValueType::Int];
					case ValueType::UInt:   WriteOp(Instruction::uint_mul); return m_Builtins[(int)ValueType::UInt];
					case ValueType::Bool: /* error */ break;
					case ValueType::Object: /* error */ break;
					default: break;
				}
				break;
			}
			case NeoTokenType::Slash:
			{
				switch (valueType)
				{
					case ValueType::Double: WriteOp(Instruction::double_div); return m_Builtins[(int)ValueType::Double];
					case ValueType::Float:  WriteOp(Instruction::float_div); return m_Builtins[(int)ValueType::Float];
					case ValueType::Int:    WriteOp(Instruction::int_div); return m_Builtins[(int)ValueType::Int];
					case ValueType::UInt:   WriteOp(Instruction::uint_div); return m_Builtins[(int)ValueType::UInt];
					case ValueType::Bool: /* error */ break;
					case ValueType::Object: /* error */ break;
					default: break;
				}
				break;
			}
			case NeoTokenType::Percent:
			{
				switch (valueType)
				{
					case ValueType::Double: WriteOp(Instruction::double_mod); return m_Builtins[(int)ValueType::Double];
					case ValueType::Float:  WriteOp(Instruction::float_mod); return m_Builtins[(int)ValueType::Float];
					case ValueType::Int:    WriteOp(Instruction::int_mod); return m_Builtins[(int)ValueType::Int];
					case ValueType::UInt:   WriteOp(Instruction::uint_mod); return m_Builtins[(int)ValueType::UInt];
					case ValueType::Bool: /* error */ break;
					case ValueType::Object: /* error */ break;
					default: break;
				}
				break;
			}
			case NeoTokenType::Caret:
			{
				switch (valueType)
				{
					case ValueType::Double: WriteOp(Instruction::double_pow); return m_Builtins[(int)ValueType::Double];
					case ValueType::Float:  WriteOp(Instruction::float_pow); return m_Builtins[(int)ValueType::Float];
					case ValueType::Int:    WriteOp(Instruction::int_pow); return m_Builtins[(int)ValueType::Int];
					case ValueType::UInt:   WriteOp(Instruction::uint_pow); return m_Builtins[(int)ValueType::UInt];
					case ValueType::Bool: /* error */ break;
					case ValueType::Object: /* error */ break;
					default: break;
				}
				break;
			}
			case NeoTokenType::BangEqual:
			{
				switch (valueType)
				{
					case ValueType::Double:
					case ValueType::Float:
					case ValueType::Int:
					case ValueType::UInt:
						WriteOp((Instruction)((int)Instruction::double_not_equal + 6 * (int)valueType)); return m_Builtins[(int)ValueType::Bool];
					case ValueType::Bool: WriteOp(Instruction::bool_not_equal); return m_Builtins[(int)ValueType::Bool];
					default:
					{
						if (leftType == m_Builtins[(int)ValueType::Object + 1])
						{
							WriteOp(Instruction::string_not_equal);
							return m_Builtins[(int)ValueType::Bool];
						}
					}
				}
				break;
			}
			case NeoTokenType::EqualEqual:
			{
				switch (valueType)
				{
					case ValueType::Double:
					case ValueType::Float:
					case ValueType::Int:
					case ValueType::UInt:
						WriteOp((Instruction)((int)Instruction::double_equal + 6 * (int)valueType)); return m_Builtins[(int)ValueType::Bool];
					case ValueType::Bool: WriteOp(Instruction::bool_equal); return m_Builtins[(int)ValueType::Bool];
					default:
					{
						if (leftType == m_Builtins[(int)ValueType::Object + 1])
						{
							WriteOp(Instruction::string_equal);
							return m_Builtins[(int)ValueType::Bool];
						}
					}
				}
				break;
			}
			case NeoTokenType::Greater:
			{
				switch (valueType)
				{
					case ValueType::Double:
					case ValueType::Float:
					case ValueType::Int:
					case ValueType::UInt:
						WriteOp((Instruction)((int)Instruction::double_greater + 6 * (int)valueType)); return m_Builtins[(int)ValueType::Bool];
					default: break;
				}
				break;
			}
			case NeoTokenType::GreaterEqual:
			{
				switch (valueType)
				{
					case ValueType::Double:
					case ValueType::Float:
					case ValueType::Int:
					case ValueType::UInt:
						WriteOp((Instruction)((int)Instruction::double_greater_or_equal + 6 * (int)valueType)); return m_Builtins[(int)ValueType::Bool];
					default: break;
				}
				break;
			}
			case NeoTokenType::Less:
			{
				switch (valueType)
				{
					case ValueType::Double:
					case ValueType::Float:
					case ValueType::Int:
					case ValueType::UInt:
						WriteOp((Instruction)((int)Instruction::double_less + 6 * (int)valueType)); return m_Builtins[(int)ValueType::Bool];
					default: break;
				}
				break;
			}
			case NeoTokenType::LessEqual:
			{
				switch (valueType)
				{
					case ValueType::Double:
					case ValueType::Float:
					case ValueType::Int:
					case ValueType::UInt:
						WriteOp((Instruction)((int)Instruction::double_less_or_equal + 6 * (int)valueType)); return m_Builtins[(int)ValueType::Bool];
					default: break;
				}
				break;
			}
		}
		return nullptr;
	}

	void Parser::Error(const char* msg)
	{
		throw SyntaxError(m_Current->line, msg);
	}

	void Parser::Error(std::string& msg)
	{
		throw SyntaxError(m_Current->line, msg);
	}
}
