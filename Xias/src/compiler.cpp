#include "compiler.h"

#include "compilation_unit.h"
#include "object.h"
#include "vm.h"
#include "messages.h"

// This was just a temporary hack.
// Ideally, the expression tree is converted to a tree of function calls,
// then certain functions like a + a get replaced by their intruction counterparts

namespace Xias {

	Compiler::Compiler()
	{
	}

	Compiler::Compiler(Vm* vm)
	{
		this->vm = vm;
		doubleClass = vm->GetClass("double");
		floatClass = vm->GetClass("float");
		intClass = vm->GetClass("int");
		uintClass = vm->GetClass("uint");
		boolClass = vm->GetClass("bool");
		objectClass = vm->GetClass("Object");
		stringClass = vm->GetClass("String");
	}

	std::vector<CompilationMessage> Compiler::Compile(x_class xclass, x_method method, Statement& statement)
	{
		std::vector<CompilationMessage> messages;
		this->messages = &messages;
		containingClass = xclass;
		StaticCheck(statement);
		CreateDAG(statement);
		// convert to IR following SSA structure
		// optimizations
		// then convert to xias

		return messages;
	}

	void Compiler::StaticCheck(Statement& statement)
	{
		Walk(statement);
	}

	void Compiler::Walk(Statement& statement)
	{
		line = statement.m_Line;
		column = statement.m_Column;
		switch (statement.m_Type)
		{
			case Statement::local_variable_declaration:
			{
				Type type = CreateType(statement.m_Data[0]);
				if (type.Class == nullptr)
					AddMessage(no_type_or_namespace, { statement.m_Data[0] });
				for (Statement& declarator : statement.m_Children)
				{
					for (StackElementInfo& element : stack)
					{
						if (element.Name == declarator.m_Data[0])
						{
							AddMessage(variable_shadowed, { declarator.m_Data[0] });
						}
					}

					StackElementInfo e;
					e.ScopeDepth = currentScopeDepth;
					e.Name = declarator.m_Data[0];
					e.ElementType = type;
					stack.push_back(e);
				}
				break;
			}
			case Statement::if_statement:
			{
				ExpressionResult result = Walk(statement.m_Expressions[0]);
				Type& type = result.m_Type;
				// TODO: Move this to a function
				bool success = false;
				for (auto& [castSignature, castIndex] : type.Class->ImplicitCastIndices)
				{
					std::vector<std::string> castElements = vm->SplitSignature(castSignature);
					Type castType = CreateType(castElements[0]);
					if (castType.Dimensions.size() == 0 && castType.Class == boolClass)
						success = true;
				}
				if (!success)
					AddMessage(implicit_type_conversion, { CreateName(result.m_Type), "bool" });
				currentScopeDepth++;
				Walk(statement.m_Children[0]);
				ObliterateScope();
				break;
			}
			//case Statement::if_statement:
			//{
			//	Type ret = Walk(vm, statement.m_Expressions[0]);
			//	if (ret.Dimensions.size() != 0)
			//	{
			//		if (ret.Class != vm->GetClass("Bool"))
			//		AddMessage(0, { CreateName(ret) });
			//	}
			//	break;
			//}
			default:
			{
				for (Expression& expr : statement.m_Expressions)
					Walk(expr);
				for (Statement& statement : statement.m_Children)
					Walk(statement);
			}
		}
	}

	ExpressionResult& Compiler::Walk(Expression& expression)
	{
		line = expression.m_Line;
		column = expression.m_Column;
		switch (expression.m_Type)
		{
			case Expression::boolean_expression:
			{
				ExpressionResult result = Walk(expression.m_Children[0]);
				Type& ret = result.m_Type;
				Type bType;
				bType.Class = boolClass;
				if (ret.Dimensions.size() == 0)
				{
					if (ret.Class == nullptr)
						AddMessage(implicit_type_conversion, { CreateName(ret), "bool" });
					else
					{
						if (ret.Class != boolClass)
						{
							if (vm->GetImplicitConversion(ret.Class, boolClass))
							{
								Expression cast;
								cast.m_Type = Expression::cast_expression;
								cast.m_Data.emplace_back("bool");
								cast.m_Children.emplace_back(expression.m_Children[0]);
								expression.m_Children[0] = cast;
								bType.Category = Type::rvalue;
							}
							else
								AddMessage(implicit_type_conversion, { CreateName(ret), "bool" });
						}
						else
						{
							bType.Category = ret.Category;
						}
					}
				}
				else
					AddMessage(implicit_type_conversion, { CreateName(ret), "bool" });
				return ExpressionResult(ExpressionResult::Category::_Value, bType);
			}
			case Expression::relational_expression_LT:
			case Expression::relational_expression_GT:
			case Expression::relational_expression_OP_LE:
			case Expression::relational_expression_OP_GE:
			case Expression::relational_expression_IS:
			case Expression::relational_expression_AS:
			case Expression::shift_expression_LEFT:
			case Expression::shift_expression_RIGHT:
			case Expression::additive_expression_PLUS:
			case Expression::additive_expression_MINUS:
			case Expression::multiplicative_expression_STAR:
			case Expression::multiplicative_expression_DIV:
			case Expression::multiplicative_expression_MOD:
			{
				ExpressionResult resultL = Walk(expression.m_Children[0]);
				ExpressionResult resultR = Walk(expression.m_Children[1]);
				Type& right = resultL.m_Type;
				Type& left = resultR.m_Type;

				OverloadResolution resolution = ResolveOverload(expression.m_Data[0], { left, right });
				if (resolution.Return.Class == nullptr)
					AddMessage(wrong_binary_operator, { expression.m_Data[0], CreateName(left), CreateName(right) });

				return ExpressionResult(ExpressionResult::Category::_Value, resolution.Return);
			}
			case Expression::unary_plus_expression:
			case Expression::unary_minus_expression:
			case Expression::unary_bang_expression:
			case Expression::unary_tilde_expression:
			case Expression::pre_increment_expression:
			case Expression::pre_decrement_expression:
			{
				ExpressionResult result = Walk(expression.m_Children[0]);
				Type& type = result.m_Type;

				OverloadResolution resolution = ResolveOverload(expression.m_Data[0], { type });
				if (resolution.Return.Class == nullptr)
					AddMessage(wrong_unary_operator, { expression.m_Data[0], CreateName(type) });

				return ExpressionResult(ExpressionResult::Category::_Value, resolution.Return);
			}
			case Expression::cast_expression:
			{
				ExpressionResult result = Walk(expression.m_Children[0]);
				Type& type = result.m_Type;

				OverloadResolution resolution = ResolveOverload(expression.m_Data[0], { type });
				if (resolution.Return.Class == nullptr)
					AddMessage(type_conversion, { CreateName(type), expression.m_Data[0] });

				// This crashes
				//return ExpressionResult(ExpressionResult::Category::_Value, resolution.Return);

				// This does not
				ExpressionResult vsBug = ExpressionResult(ExpressionResult::Category::_Value, resolution.Return);
				return vsBug;
			}
			case Expression::primary_no_array_creation_base:
			{
				//Type type = Walk(expression.m_Children[0]);

				//std::string identifier;
				//for (Expression& expr : expression.m_Children)
				//{
				//	switch (expr.m_Type)
				//	{
				//		case Expression::primary_member_access:
				//		{

				//		}
				//		case Expression::primary_invocation:
				//		{
				//			OverloadResolution resolution = ResolveOverload(expr.m_Data[0], { type });
				//			if (resolution.Return.Class == nullptr)
				//				AddMessage(3, { expression.m_Data[0], CreateName(type) });
				//		}
				//	}
				//}

				return WalkPrimary(expression.m_Children);

				//for (int i = expression.m_Children.size() - 1; i >= 0; i++)
				//{
				//	Type type = Walk(expression.m_Children[i])
				//}
			}
			case Expression::integer_literal:
			{
				Type type;
				type.Class = intClass;
				type.Category = Type::rvalue;
				return ExpressionResult(ExpressionResult::Category::_Value, type);
			}
			case Expression::invocation_expression:
			{
				return WalkPrimary(expression.m_Children);
				//ExpressionResult result = Walk(expression.m_Children[0]);
				//if (result.m_Category != ExpressionResult::Category::_MethodGroup)
				//	AddMessage(member_not_method,
				//		{ result.m_Name });
				//std::string signature = ';' + result.m_Name + ';';
				//for (auto& param : expression.m_Children[1].m_Children)
				//{
				//	ExpressionResult& paramResult = Walk(param);
				//	signature += CreateName(paramResult.m_Type) + ';';
				//}
				//std::string candidate = vm->CompleteSignature(signature);
				//if (candidate == "")
				//	AddMessage(method_not_found, { signature });
				//return ExpressionResult(ExpressionResult::Category::_Nothing, Type());
			}
			default:
			{
				ExpressionResult result;
				for (Expression& expr : expression.m_Children)
					result = Walk(expr);
				return result;
			}
		}
	}

	ExpressionResult& Compiler::WalkPrimary(std::vector<Expression>& expressions)
	{
		ExpressionResult result;
		result.m_Category = ExpressionResult::Category::_Nothing;
		Type& ret = result.m_Type;
		Member classMember;
		for (int i = 0; i < expressions.size(); i++)
		{
			Expression& expr = expressions[i];
			switch (expr.m_Type)
			{
				case Expression::integer_literal:
				{
					ret.Class = intClass;
					ret.Category = Type::rvalue;
					result.m_Category = ExpressionResult::Category::_Value;
					break;
				}
				case Expression::simple_name:
				{
					// https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/language-specification/expressions#11741-general
					// Check variable name in scope
					//		local variable - _Variable
					//		named constant - _Value
					/*
						* if the simple_name appears within a generic method declaration but
						* outside the attributes of its method_header, and if that declaration
						* includes a type parameter with name I, then the simple_name refers
						* to that type parameter.
					*/
					// for each instance type T, starting with the instance type of the
					//		immediately enclosing type declaration and continuing with the
					//		instance type of each enclosing class or struct declaration (if any):

						// if the declaration of T includes a type parameter with name I, then the
						//		simple_name refers to that type parameter.

					bool found = false;
					for (int i = stack.size() - 1; i >= 0; i--)
					{
						StackElementInfo& element = stack[i];
						if (element.Name == expr.m_Data[0])
						{
							ret = element.ElementType;
							ret.Category = Type::lvalue;
							result.m_Category = ExpressionResult::Category::_Variable;
							found = true;
							break;
						}
					}

					if (!found)
					{
						ret.Class = vm->GetClass(expr.m_Data[0]);

						ret.Category = Type::lvalue;
						result.m_Category = ExpressionResult::Category::_Variable;
					}
					break;
				}
				case Expression::parenthesized:
				{
					result = Walk(expr.m_Children[0]);
					break;
				}
				case Expression::this_access:
				{
					ret.Class = containingClass;
					ret.Category = Type::lvalue;
					result.m_Category = ExpressionResult::Category::_Variable;
					break;
				}
				case Expression::base_access:
				{
					if (!containingClass->Parent)
						AddMessage(unknown_error, { });
					ret.Class = containingClass->Parent;
					ret.Category = Type::lvalue;
					result.m_Category = ExpressionResult::Category::_Variable;
					break;
				}
				case Expression::object_creation:
					break;
				case Expression::typeof_expression:
					break;
				case Expression::default_value:
					break;
				case Expression::primary_member_access:
				{
					if (ret.Class != nullptr)
					{
						if (ret.Dimensions.size() == 0)
						{
							classMember = vm->GetMember(ret.Class, expr.m_Data[0]);
							result.m_Name = expr.m_Data[0];
						}
						else
						{
							//member = vm->GetMember(arrayClass, expr.m_Data[0]);
						}

						if (classMember.m_Type == Member::Category::NotFound)
						{
							AddMessage(12, { ret.Class->Name, expr.m_Data[0] });
						}
						else if (!MemberAccessible(containingClass->Name, classMember))
						{
							AddMessage(13, { expr.m_Data[0] });
						}
						else
						{
							switch (classMember.m_Type)
							{
								case Member::Category::Field:
									result.m_Category = ExpressionResult::Category::_Variable;
									break;
								case Member::Category::Property:
									result.m_Category = ExpressionResult::Category::_Value;
									break;
								case Member::Category::Method:
									result.m_Category = ExpressionResult::Category::_MethodGroup;
									break;
								case Member::Category::Constructor:
									AddMessage(unknown_error, {});
									break;
							}
							ret = CreateType(classMember.m_Data);
						}
					}
					break;
				}
				case Expression::primary_invocation:
				{
					//if (result.m_Category != ExpressionResult::Category::_MethodGroup)
					//	AddMessage(member_not_method,
					//		{ classMember.m_ContainingClass + '.' + classMember.m_Data });
					//std::string signature = ';' + result.m_Name + ';';
					//for (auto& param : expr.m_Children[0].m_Children)
					//{
					//	ExpressionResult& paramResult = Walk(param);
					//	signature += CreateName(paramResult.m_Type) + ';';
					//}
					//std::string candidate = vm->CompleteSignature(signature);
					//if (candidate == "")
					//	AddMessage(method_not_found, { signature });

					//result.m_Category = ExpressionResult::Category::_Value;
					//ret = CreateType(classMember.m_Data);
					if (result.m_Category != ExpressionResult::Category::_MethodGroup)
						AddMessage(member_not_method,
							{ classMember.m_ContainingClass + '.' + classMember.m_Data });
					std::vector<Type> types;
					for (auto& param : expr.m_Children[0].m_Children)
					{
						ExpressionResult paramResult = Walk(param);
						types.push_back(paramResult.m_Type);
					}
					OverloadResolution resolution = ResolveOverload(result.m_Name, types);
					if (resolution.Return.Class == nullptr)
						AddMessage(method_not_found, { resolution.GivenSignature });

					result.m_Category = ExpressionResult::Category::_Value;
					ret = resolution.Return;
					break;
				}
				case Expression::primary_element_access:
					break;
				case Expression::primary_post_increment:
				case Expression::primary_post_decrement:
				{
					if (result.m_Category != ExpressionResult::Category::_Variable)
						AddMessage(member_not_method, // TODO: fix
							{ classMember.m_ContainingClass + '.' + classMember.m_Data });
					
					OverloadResolution resolution = ResolveOverload(expr.m_Data[0], { result.m_Type });
					if (resolution.Return.Class == nullptr)
						AddMessage(wrong_unary_operator, { expr.m_Data[0], CreateName(result.m_Type) });
					
					result.m_Category = ExpressionResult::Category::_Value;
					ret = resolution.Return;
				}
			}
		}
		return result;
	}

	void Compiler::CreateDAG(Statement& statement)
	{

	}

	/*
	std::string Compiler::Compilea(Vm* vm, const Expression& expression, x_method method)
	{
		switch (expression.m_Type)
		{
			case Expression::conditional_expression:
			{
				// Condition
				Compilea(vm, expression.m_Children[0], method);
				// Jump to second expression if condition evaluates to false
				method->Code.Code.emplace_back(Instruction::jump_if_false);
				size_t jumpL = method->Code.Code.size();
				method->Code.Code.emplace_back(0);
				size_t offsetL = method->Code.Code.size();
				std::string type = Compilea(vm, expression.m_Children[1], method);
				// Jump over second expression if condition was true
				method->Code.Code.emplace_back(Instruction::jump);
				int jumpR = method->Code.Code.size();
				method->Code.Code.emplace_back(0);
				method->Code.Code[jumpL] = method->Code.Code.size() - offsetL;

				size_t offsetR = method->Code.Code.size();
				Compilea(vm, expression.m_Children[2], method);
				method->Code.Code[jumpR] = method->Code.Code.size() - offsetR;

				return type;
			}
			case Expression::null_coalescing_expression:
			{
				return "int";
				// TODO: unimplemented
			}
			case Expression::conditional_or_expression:
			{
				Compilea(vm, expression.m_Children[0], method);
				// Jump over second condition if first is true
				method->Code.Code.emplace_back(Instruction::jump_if_true_chain);
				int jump = method->Code.Code.size();
				method->Code.Code.emplace_back(0);
				size_t offset = method->Code.Code.size();
				method->Code.Code.emplace_back(Instruction::pop_value);
				Compilea(vm, expression.m_Children[1], method);
				method->Code.Code[jump] = method->Code.Code.size() - offset;

				return "bool";
			}
			case Expression::conditional_and_expression:
			{
				Compilea(vm, expression.m_Children[0], method);
				method->Code.Code.emplace_back(Instruction::jump_if_false_chain);
				int jump = method->Code.Code.size();
				method->Code.Code.emplace_back(0);
				size_t offset = method->Code.Code.size();
				method->Code.Code.emplace_back(Instruction::pop_value);
				Compilea(vm, expression.m_Children[1], method);
				method->Code.Code[jump] = method->Code.Code.size() - offset;

				return "bool";
			}
			case Expression::inclusive_or_expression:
			{
				std::string left = Compilea(vm, expression.m_Children[0], method);
				Compilea(vm, expression.m_Children[1], method);
				Instruction op;
				if (left == "int") op = Instruction::int_bit_or;
				else if (left == "uint") op = Instruction::uint_bit_or;
				else if (left == "char") op = Instruction::uint_bit_or; // No char type
				else if (left == "bool") op = Instruction::bool_or;
				else return left;

				method->Code.Code.emplace_back(op);
				return left;
			}
			case Expression::exclusive_or_expression:
			{
				std::string left = Compilea(vm, expression.m_Children[0], method);
				Compilea(vm, expression.m_Children[1], method);
				Instruction op;
				if (left == "int") op = Instruction::int_bit_and;
				else if (left == "uint") op = Instruction::uint_bit_and;
				else if (left == "char") op = Instruction::uint_bit_and;
				else if (left == "bool") op = Instruction::bool_and;
				else return left;

				method->Code.Code.emplace_back(op);
				return left;
			}
			case Expression::and_expression:
			{
				std::string left = Compilea(vm, expression.m_Children[0], method);
				Compilea(vm, expression.m_Children[1], method);
				Instruction op;
				if (left == "int") op = Instruction::int_bit_xor;
				else if (left == "uint") op = Instruction::uint_bit_xor;
				else if (left == "char") op = Instruction::uint_bit_xor;
				else if (left == "bool") op = Instruction::bool_xor;
				else return left;

				method->Code.Code.emplace_back(op);
				return left;
			}
			case Expression::equality_expression_EQ:
			{
				std::string left = Compilea(vm, expression.m_Children[0], method);
				Compilea(vm, expression.m_Children[1], method);
				Instruction op;
				if (left == "int") op = Instruction::int_equal;
				else if (left == "uint") op = Instruction::uint_equal;
				else if (left == "char") op = Instruction::uint_equal;
				else if (left == "double") op = Instruction::double_equal;
				else if (left == "float") op = Instruction::float_equal;
				else if (left == "bool") op = Instruction::bool_equal;
				else if (left == "string") op = Instruction::string_equal;
				//else if (left == "null") op = Instruction::float_add; // TODO: Objects
				else return left;

				method->Code.Code.emplace_back(op);
				return left;
			}
			case Expression::equality_expression_NE:
			{
				std::string left = Compilea(vm, expression.m_Children[0], method);
				Compilea(vm, expression.m_Children[1], method);
				Instruction op;
				if (left == "int") op = Instruction::int_not_equal;
				else if (left == "uint") op = Instruction::uint_not_equal;
				else if (left == "char") op = Instruction::uint_not_equal;
				else if (left == "double") op = Instruction::double_not_equal;
				else if (left == "float") op = Instruction::float_not_equal;
				else if (left == "bool") op = Instruction::bool_not_equal;
				else if (left == "string") op = Instruction::string_not_equal;
				else return left;

				method->Code.Code.emplace_back(op);
				return left;
			}
			case Expression::relational_expression_LT:
			{
				std::string left = Compilea(vm, expression.m_Children[0], method);
				Compilea(vm, expression.m_Children[1], method);
				Instruction op;
				if (left == "int") op = Instruction::int_less;
				else if (left == "uint") op = Instruction::uint_less;
				else if (left == "char") op = Instruction::uint_less;
				else if (left == "double") op = Instruction::double_less;
				else if (left == "float") op = Instruction::float_less;
				else return left;

				method->Code.Code.emplace_back(op);
				return left;
			}
			case Expression::relational_expression_GT:
			{
				std::string left = Compilea(vm, expression.m_Children[0], method);
				Compilea(vm, expression.m_Children[1], method);
				Instruction op;
				if (left == "int") op = Instruction::int_greater;
				else if (left == "uint") op = Instruction::uint_greater;
				else if (left == "char") op = Instruction::uint_greater;
				else if (left == "double") op = Instruction::double_greater;
				else if (left == "float") op = Instruction::float_greater;
				else return left;

				method->Code.Code.emplace_back(op);
				return left;
			}
			case Expression::relational_expression_OP_LE:
			{
				std::string left = Compilea(vm, expression.m_Children[0], method);
				Compilea(vm, expression.m_Children[1], method);
				Instruction op;
				if (left == "int") op = Instruction::int_less_or_equal;
				else if (left == "uint") op = Instruction::uint_less_or_equal;
				else if (left == "char") op = Instruction::uint_less_or_equal;
				else if (left == "double") op = Instruction::double_less_or_equal;
				else if (left == "float") op = Instruction::float_less_or_equal;
				else return left;

				method->Code.Code.emplace_back(op);
				return left;
			}
			case Expression::relational_expression_OP_GE:
			{
				std::string left = Compilea(vm, expression.m_Children[0], method);
				Compilea(vm, expression.m_Children[1], method);
				Instruction op;
				if (left == "int") op = Instruction::int_greater_or_equal;
				else if (left == "uint") op = Instruction::uint_greater_or_equal;
				else if (left == "char") op = Instruction::uint_greater_or_equal;
				else if (left == "double") op = Instruction::double_greater_or_equal;
				else if (left == "float") op = Instruction::float_greater_or_equal;
				else return left;

				method->Code.Code.emplace_back(op);
				return left;
			}
			case Expression::relational_expression_IS:
			{
				return "int";
				// TODO: unimplemented
			}
			case Expression::relational_expression_AS:
			{
				return "int";
				// TODO: unimplemented
			}
			case Expression::shift_expression_LEFT:
			{
				std::string left = Compilea(vm, expression.m_Children[0], method);
				Compilea(vm, expression.m_Children[1], method);
				Instruction op;
				if (left == "int") op = Instruction::int_shift_left;
				else if (left == "uint") op = Instruction::uint_shift_left;
				else if (left == "char") op = Instruction::uint_shift_left;
				else return left;

				method->Code.Code.emplace_back(op);
				return left;
			}
			case Expression::shift_expression_RIGHT:
			{
				std::string left = Compilea(vm, expression.m_Children[0], method);
				Compilea(vm, expression.m_Children[1], method);
				Instruction op;
				if (left == "int") op = Instruction::int_shift_right;
				else if (left == "uint") op = Instruction::uint_shift_right;
				else if (left == "char") op = Instruction::uint_shift_right;
				else return left;

				method->Code.Code.emplace_back(op);
				return left;
			}
			case Expression::additive_expression_PLUS:
			{
				std::string left = Compilea(vm, expression.m_Children[0], method);
				Compilea(vm, expression.m_Children[1], method);
				Instruction op;
				if (left == "int") op = Instruction::int_add;
				else if (left == "uint") op = Instruction::uint_add;
				else if (left == "char") op = Instruction::uint_add;
				else if (left == "double") op = Instruction::double_add;
				else if (left == "float") op = Instruction::float_add;
				else if (left == "string") op = Instruction::string_add;
				else return left;

				method->Code.Code.emplace_back(op);
				return left;
			}
			case Expression::additive_expression_MINUS:
			{
				std::string left = Compilea(vm, expression.m_Children[0], method);
				Compilea(vm, expression.m_Children[1], method);
				Instruction op;
				if (left == "int") op = Instruction::int_sub;
				else if (left == "uint") op = Instruction::uint_sub;
				else if (left == "char") op = Instruction::uint_sub;
				else if (left == "double") op = Instruction::double_sub;
				else if (left == "float") op = Instruction::float_sub;
				else return left;

				method->Code.Code.emplace_back(op);
				return left;
			}
			case Expression::multiplicative_expression_STAR:
			{
				std::string left = Compilea(vm, expression.m_Children[0], method);
				Compilea(vm, expression.m_Children[1], method);
				Instruction op;
				if (left == "int") op = Instruction::int_mul;
				else if (left == "uint") op = Instruction::uint_mul;
				else if (left == "char") op = Instruction::uint_mul;
				else if (left == "double") op = Instruction::double_mul;
				else if (left == "float") op = Instruction::float_mul;
				else return left;

				method->Code.Code.emplace_back(op);
				return left;
			}
			case Expression::multiplicative_expression_DIV:
			{
				std::string left = Compilea(vm, expression.m_Children[0], method);
				Compilea(vm, expression.m_Children[1], method);
				Instruction op;
				if (left == "int") op = Instruction::int_div;
				else if (left == "uint") op = Instruction::uint_div;
				else if (left == "char") op = Instruction::uint_div;
				else if (left == "double") op = Instruction::double_div;
				else if (left == "float") op = Instruction::float_div;
				else return left;

				method->Code.Code.emplace_back(op);
				return left;
			}
			case Expression::multiplicative_expression_MOD:
			{
				std::string left = Compilea(vm, expression.m_Children[0], method);
				Compilea(vm, expression.m_Children[1], method);
				Instruction op;
				if (left == "int") op = Instruction::int_mod;
				else if (left == "uint") op = Instruction::uint_mod;
				else if (left == "char") op = Instruction::uint_mod;
				else if (left == "double") op = Instruction::double_mod;
				else if (left == "float") op = Instruction::float_mod;
				else return left;

				method->Code.Code.emplace_back(op);
				return left;
			}
			case Expression::unary_plus_expression:
			{
				std::string type = Compilea(vm, expression.m_Children[0], method);
				return "int";
			}
			case Expression::unary_minus_expression:
			{
				std::string type = Compilea(vm, expression.m_Children[0], method);
				Instruction op;
				if (type == "int") op = Instruction::int_negate;
				else if (type == "uint") op = Instruction::int_negate;
				else if (type == "char") op = Instruction::int_negate;
				else if (type == "double") op = Instruction::double_negate;
				else if (type == "float") op = Instruction::float_negate;
				else return type;

				method->Code.Code.emplace_back(op);
				return type;
			}
			case Expression::unary_bang_expression:
			{
				std::string type = Compilea(vm, expression.m_Children[0], method);
				Instruction op;
				if (type == "bool") op = Instruction::bool_negate;
				else return type;

				method->Code.Code.emplace_back(op);
				return type;
			}
			case Expression::unary_tilde_expression:
			{
				std::string type = Compilea(vm, expression.m_Children[0], method);
				Instruction op;
				if (type == "int") op = Instruction::bit_flip;
				else if (type == "uint") op = Instruction::bit_flip;
				else if (type == "char") op = Instruction::bit_flip;
				else
				{

				}

				method->Code.Code.emplace_back(op);
				return type;
			}
			case Expression::pre_increment_expression:
			{
				auto rvalue = Compilea(vm, expression.m_Children[0], method);
				Instruction op;
				if (rvalue == "int") op = Instruction::int_inc;
				else if (rvalue == "uint") op = Instruction::uint_inc;
				else if (rvalue == "char") op = Instruction::uint_inc;
				else if (rvalue == "double") op = Instruction::double_inc;
				else if (rvalue == "float") op = Instruction::float_inc;
				else return rvalue;
				method->Code.Code.emplace_back(op);
				method->Code.Code.emplace_back(Instruction::duplicate);

				//switch (rvalue.location)
				//{
				//	case location::stack_object:
				//	{
				//		method->Code.Code.emplace_back(Instruction::set_field);
				//		method->Code.Code.emplace_back(rvalue.id);
				//	}
				//	case location::member_function:
				//	{
				//		method->Code.Code.emplace_back(Instruction::set_member_field);
				//		method->Code.Code.emplace_back(rvalue.id);
				//	}
				//	case location::global_variable:
				//	{
				//		method->Code.Code.emplace_back(Instruction::set_global);
				//		method->Code.Code.emplace_back(rvalue.id);
				//	}
				//	case location::local_variable:
				//	{
				//		method->Code.Code.emplace_back(Instruction::set_local);
				//		method->Code.Code.emplace_back(rvalue.id);
				//	}
				//}
				return rvalue;
			}
			case Expression::pre_decrement_expression:
			case Expression::cast_expression:
			{
				Compilea(vm, expression.m_Children[0], method);
				return expression.m_Data[0];
			}



			case Expression::true_literal:
			{
				method->Code.Code.emplace_back(Instruction::literal_true);
				return "bool";
			}
			case Expression::false_literal:
			{
				method->Code.Code.emplace_back(Instruction::literal_false);
				return "bool";
			}
			case Expression::string_literal:
			{
				return "string";
				// TODO: unimplemented
			}
			case Expression::verbatim_literal:
			{
				method->Code.Code.emplace_back(Instruction::push_value);
				method->Code.Code.emplace_back(method->Code.Constants.size());
				method->Code.Constants.emplace_back(Value{ vm->CopyString(expression.m_Data[0]) });
				return "string";
			}
			case Expression::integer_literal:
			{
				method->Code.Code.emplace_back(Instruction::push_value);
				method->Code.Code.emplace_back(method->Code.Constants.size());
				method->Code.Constants.emplace_back(Value{ std::stoll(expression.m_Data[0]) });
				return "int";
			}
			case Expression::unsigned_literal:
			{
				method->Code.Code.emplace_back(Instruction::push_value);
				method->Code.Code.emplace_back(method->Code.Constants.size());
				method->Code.Constants.emplace_back(Value{ std::stoull(expression.m_Data[0]) });
				return "uint";
			}
			case Expression::float_literal:
			{
				method->Code.Code.emplace_back(Instruction::push_value);
				method->Code.Code.emplace_back(method->Code.Constants.size());
				method->Code.Constants.emplace_back(Value{ std::stof(expression.m_Data[0]) });
				return "float";
			}
			case Expression::double_literal:
			{
				method->Code.Code.emplace_back(Instruction::push_value);
				method->Code.Code.emplace_back(method->Code.Constants.size());
				method->Code.Constants.emplace_back(Value{ std::stod(expression.m_Data[0]) });
				return "double";
			}
			case Expression::null_literal:
			{
				method->Code.Code.emplace_back(Instruction::literal_nullptr);
				return "null";
			}

			default:
			{
				if (expression.m_Children.size() == 1)
					return Compilea(vm, expression.m_Children[0], method);
				else
				{
					std::string type;
					for (const Expression& child : expression.m_Children)
						type = Compilea(vm, child, method);
					return type;
				}
			}
		}
	}

	void Compiler::Compilea(Vm* vm, const Statement& statement, x_method method)
	{
		switch (statement.m_Type)
		{
			case Statement::return_statement:
			{
				if (statement.m_Expressions.size())
				{
					Compilea(vm, statement.m_Expressions[0], method);
					method->Code.Code.emplace_back(Instruction::func_return);
				}
				else
				{
					method->Code.Code.emplace_back(Instruction::func_return_void);
				}
				break;
			}
			default:
			{
				for (const Statement& child : statement.m_Children)
					Compilea(vm, child, method);
			}
		}
	}
	*/

	void Compiler::AddMessage(x_ulong errorID, std::vector<std::string> params)
	{
		auto& message = messages->emplace_back();
		message.Line = line;
		message.Column = column;
		message.ErrorID = errorID;
		message.Params = params;
	}

	std::string Compiler::CreateName(const Type& type)
	{
		std::string name;
		if (type.Class == nullptr) name = "<unknown_type>";
		else name = type.Class->Name;
		for (x_ulong dim : type.Dimensions)
		{
			name += '[';
			while (dim-- > 1)
				name += ',';
			name += ']';
		}
		return name;
	}

	Type Compiler::CreateType(const std::string& type)
	{
		Type result;
		std::string xClass;
		size_t delimiter;
		if ((delimiter = type.find("[")) != std::string::npos)
			result.Class = vm->GetClass(type.substr(0, delimiter));
		else
			result.Class = vm->GetClass(type);
		while (delimiter != std::string::npos)
		{
			if (type[delimiter] == '[')
				result.Dimensions.push_back(0);
			else if (type[delimiter] == ',')
				result.Dimensions.back()++;
			delimiter++;
		}
		return result;
	}

	// This doesn't work because a class's implicit cast list is not all of them since other classes could contain their own
	// for example
	/*
	class first <- this is given as "left"
	{
		public static implicit operator second(first f) { return new second(); }
	}
	class second
	{
		public static implicit operator second(first f) { return new second(); } <- this should also cause an error when compiling though since duplicate
	}
	class third
	{
		public static implicit operator third(first f) { return new third(); } <- the problem
		public static int operator+ (third t, int i) { return 3; }				  since this type could have the operator overload we want
	}

	I have decided that this cast would then get moved to the first class's cast list since it is casting from first
	*/

	// Finds a function of given name that takes the two parameter types
	x_method Compiler::FindMethod(std::string name, Type& left, Type& right)
	{
		if (left.Class == nullptr || right.Class == nullptr)
			return nullptr;

		std::vector<x_method> candidates;

		// Check each of the left type's implicit casts (and the left type too) for a function that takes itself
		// as well as the other type (or one of its implicit casts) as is named the given name

		// Loop the left type's implicit casts
		// TODO: check from "left" aswell
		for (auto& [lcastSignature, castIndex] : left.Class->ImplicitCastIndices)
		{
			// Get the cast's signature
			std::vector<std::string> lcastElements = vm->SplitSignature(lcastSignature);
			x_class lcastClass = vm->GetClass(lcastElements[0]);
			// Skip if the cast-to type is the left type (casting from another type to left)
			if (lcastClass == left.Class)
				continue;

			// look for a function of name "name" in the casted type
			for (auto& [methodSignature, methodIndex] : lcastClass->FunctionIndices)
			{
				// Split the method signature
				std::vector<std::string> rmethodElements = vm->SplitSignature(methodSignature);
				// Check if the name is correct and if the other parameter is present
				if (rmethodElements[1] != name || rmethodElements.size() != 4)
					continue;

				// Loop the right type's implicit casts
				// TODO: check for "right" aswell
				for (auto& [rcastSignature, rcastIndex] : right.Class->ImplicitCastIndices)
				{
					// Get the cast's signature
					std::vector<std::string> rcastElements = vm->SplitSignature(rcastSignature);
					x_class rcastClass = vm->GetClass(lcastElements[0]);
					// Skip if the cast-to type is the right type (casting from another type to right)
					if (rcastClass == left.Class)
						continue;

					if (rmethodElements[3] == rcastElements[0])
						candidates.emplace_back(lcastClass->Functions[methodIndex]);
				}
			}
		}
	}

	OverloadResolution Compiler::ResolveOverload(const std::string& methodName, std::vector<Type> givenTypes)
	{
		OverloadResolution result;
		result.OriginalParameters = givenTypes;
		std::vector<std::vector<Type>> candidateTypes;
		candidateTypes.resize(givenTypes.size());
		result.GivenSignature = ';' + methodName + ';';
		for (int i = 0; i < givenTypes.size(); i++)
		{
			if (givenTypes[i].Class == nullptr)
				return result;
			result.GivenSignature += CreateName(givenTypes[i]) + ';';
			candidateTypes[i].emplace_back(givenTypes[i]);
		}

		for (int i = 0; i < givenTypes.size(); i++)
		{
			const Type& type = givenTypes[i];
			if (type.Dimensions.size() != 0)
				continue;
			candidateTypes[i].resize(type.Class->ImplicitCastIndices.size() + 1);
			for (auto& [castSignature, castIndex] : type.Class->ImplicitCastIndices)
			{
				std::vector<std::string> castElements = vm->SplitSignature(castSignature);
				candidateTypes[i][castIndex] = CreateType(castElements[0]);
			}
		}

		std::vector<std::string> methodCandidates;
		std::vector<x_ulong> methodScores;
		std::vector<x_ulong> indexes;
		indexes.resize(givenTypes.size());
		while (true)
		{
			std::string candidateName = methodName + ';';
			for (int i = 0; i < candidateTypes.size(); i++)
			{
				candidateName += CreateName(candidateTypes[i][indexes[i]]);
				candidateName += ';';
			}
			std::string candidate = vm->CompleteSignature(candidateName);
			if (!candidate.empty())
			{
				methodCandidates.emplace_back(candidate);
				x_ulong score = 0;
				for (x_ulong i : indexes)
					if (i > 0) score++;
				methodScores.emplace_back(score);
			}
			indexes[0]++;
			bool exhausted = false;
			for (int i = 0; i < indexes.size(); i++)
			{
				if (indexes[i] == candidateTypes[i].size())
				{
					if (i == indexes.size() - 1)
					{
						exhausted = true;
						break;
					}
					indexes[i] = 0;
					indexes[i + 1]++;
				}
			}
			if (exhausted)
				break;
		}

		if (methodCandidates.size())
		{
			x_ulong lowScoreIndex = 0;
			for (int i = 1; i < methodScores.size(); i++)
			{
				if (methodScores[lowScoreIndex] > methodScores[i])
					lowScoreIndex = i;
			}

			// Finish assigning result's fields.
			std::vector<std::string> finalElements = vm->SplitSignature(methodCandidates[lowScoreIndex]);
			result.Return = CreateType(finalElements[0]);

			for (int i = 2; i < finalElements.size(); i++)
			{
				std::string castSignature = finalElements[i] + ";();" + CreateName(givenTypes[i - 2]) + ';';
				result.CastMethods.emplace_back(vm->GetImplicitCast(givenTypes[i - 2].Class, castSignature));
				result.FinalParameters.emplace_back(CreateType(finalElements[i]));
			}
		}

		return result;
	}

	bool Compiler::MemberAccessible(const std::string& containingClass, Member& member)
	{
		if (containingClass == member.m_ContainingClass)
			return true;
		else
		{
			if (vm->IsClassDescendent(containingClass, member.m_ContainingClass))
				if (member.m_Modifiers.m_Access == AccessModifier::Protected)
					return true;
			if (member.m_Modifiers.m_Access == AccessModifier::Public)
				return true;
			return false;
		}
	}

	void Compiler::ObliterateScope()
	{
		currentScopeDepth--;
		for (int i = stack.size() - 1; i >= 0; i--)
		{
			StackElementInfo& element = stack[i];
			if (element.ScopeDepth > currentScopeDepth)
			{
				stack.pop_back();
			}
			else
				return;
		}
	}

	CompilationPass::CompilationPass(Vm* xvm)
	{
		XVM = xvm;
	}

	void CompilationPass::SetClass(ClassInfo& cInfo, x_class xClass)
	{
		m_CInfo = &cInfo;
		m_XClass = xClass;
	}

}
