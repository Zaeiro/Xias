#include "compiler.h"

#include "compilation_unit.h"
#include "object.h"
#include "vm.h"

// This was just a temporary hack.
// Ideally, the expression tree is converted to a tree of function calls,
// then certain functions like a + a get replaced by their intruction counterparts

namespace Xias {

	std::string Compiler::Compile(Vm* vm, const Expression& expression, x_method method)
	{
		switch (expression.m_Type)
		{
			case Expression::conditional_expression:
			{
				// Condition
				Compile(vm, expression.m_Children[0], method);
				// Jump to second expression if condition evaluates to false
				method->Code.Code.emplace_back(Instruction::jump_if_false);
				size_t jumpL = method->Code.Code.size();
				method->Code.Code.emplace_back(0);
				size_t offsetL = method->Code.Code.size();
				std::string type = Compile(vm, expression.m_Children[1], method);
				// Jump over second expression if condition was true
				method->Code.Code.emplace_back(Instruction::jump);
				int jumpR = method->Code.Code.size();
				method->Code.Code.emplace_back(0);
				method->Code.Code[jumpL] = method->Code.Code.size() - offsetL;

				size_t offsetR = method->Code.Code.size();
				Compile(vm, expression.m_Children[2], method);
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
				Compile(vm, expression.m_Children[0], method);
				// Jump over second condition if first is true
				method->Code.Code.emplace_back(Instruction::jump_if_true_chain);
				int jump = method->Code.Code.size();
				method->Code.Code.emplace_back(0);
				size_t offset = method->Code.Code.size();
				method->Code.Code.emplace_back(Instruction::pop_value);
				Compile(vm, expression.m_Children[1], method);
				method->Code.Code[jump] = method->Code.Code.size() - offset;

				return "bool";
			}
			case Expression::conditional_and_expression:
			{
				Compile(vm, expression.m_Children[0], method);
				method->Code.Code.emplace_back(Instruction::jump_if_false_chain);
				int jump = method->Code.Code.size();
				method->Code.Code.emplace_back(0);
				size_t offset = method->Code.Code.size();
				method->Code.Code.emplace_back(Instruction::pop_value);
				Compile(vm, expression.m_Children[1], method);
				method->Code.Code[jump] = method->Code.Code.size() - offset;

				return "bool";
			}
			case Expression::inclusive_or_expression:
			{
				std::string left = Compile(vm, expression.m_Children[0], method);
				Compile(vm, expression.m_Children[1], method);
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
				std::string left = Compile(vm, expression.m_Children[0], method);
				Compile(vm, expression.m_Children[1], method);
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
				std::string left = Compile(vm, expression.m_Children[0], method);
				Compile(vm, expression.m_Children[1], method);
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
				std::string left = Compile(vm, expression.m_Children[0], method);
				Compile(vm, expression.m_Children[1], method);
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
				std::string left = Compile(vm, expression.m_Children[0], method);
				Compile(vm, expression.m_Children[1], method);
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
				std::string left = Compile(vm, expression.m_Children[0], method);
				Compile(vm, expression.m_Children[1], method);
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
				std::string left = Compile(vm, expression.m_Children[0], method);
				Compile(vm, expression.m_Children[1], method);
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
				std::string left = Compile(vm, expression.m_Children[0], method);
				Compile(vm, expression.m_Children[1], method);
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
				std::string left = Compile(vm, expression.m_Children[0], method);
				Compile(vm, expression.m_Children[1], method);
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
				std::string left = Compile(vm, expression.m_Children[0], method);
				Compile(vm, expression.m_Children[1], method);
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
				std::string left = Compile(vm, expression.m_Children[0], method);
				Compile(vm, expression.m_Children[1], method);
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
				std::string left = Compile(vm, expression.m_Children[0], method);
				Compile(vm, expression.m_Children[1], method);
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
				std::string left = Compile(vm, expression.m_Children[0], method);
				Compile(vm, expression.m_Children[1], method);
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
				std::string left = Compile(vm, expression.m_Children[0], method);
				Compile(vm, expression.m_Children[1], method);
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
				std::string left = Compile(vm, expression.m_Children[0], method);
				Compile(vm, expression.m_Children[1], method);
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
				std::string left = Compile(vm, expression.m_Children[0], method);
				Compile(vm, expression.m_Children[1], method);
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
				std::string type = Compile(vm, expression.m_Children[0], method);
				return "int";
			}
			case Expression::unary_minus_expression:
			{
				std::string type = Compile(vm, expression.m_Children[0], method);
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
				std::string type = Compile(vm, expression.m_Children[0], method);
				Instruction op;
				if (type == "bool") op = Instruction::bool_negate;
				else return type;

				method->Code.Code.emplace_back(op);
				return type;
			}
			case Expression::unary_tilde_expression:
			{
				std::string type = Compile(vm, expression.m_Children[0], method);
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
				auto rvalue = Compile(vm, expression.m_Children[0], method);
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
				Compile(vm, expression.m_Children[0], method);
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
					return Compile(vm, expression.m_Children[0], method);
				else
				{
					std::string type;
					for (const Expression& child : expression.m_Children)
						type = Compile(vm, child, method);
					return type;
				}
			}
		}
	}

	void Compiler::Compile(Vm* vm, const Statement& statement, x_method method)
	{
		switch (statement.m_Type)
		{
			case Statement::return_statement:
			{
				if (statement.m_Expressions.size())
				{
					Compile(vm, statement.m_Expressions[0], method);
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
					Compile(vm, child, method);
			}
		}
	}

}
