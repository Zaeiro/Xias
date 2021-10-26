#include "XiasVisitor.h"

#include "compilation_unit.h"

using namespace Xias;

#define BASIC_STATEMENT(type) do { \
	Statement* statement; \
	statement = &m_StatementStack.top()->m_Children.emplace_back(); \
	m_StatementStack.emplace(statement); \
	statement->m_Type = Statement::type; \
	auto& ret = visitChildren(ctx); \
	m_StatementStack.pop(); \
	return ret; \
} while (0)

static std::vector<bool> ClassModifiers = { true, true, true, true, true, false, true, false, true, false, true };
static std::vector<bool> FieldModifiers = { true, true, true, true, true, false, false, false, false, true, true };
static std::vector<bool> PropertyModifiers = { true, true, true, true, true, true, true, true, true, false, true };
static std::vector<bool> MethodModifiers = { true, true, true, true, true, true, true, true, true, false, true };

static std::unordered_map<std::string, int> ModifierID = {
	{"new", 0},
	{"public", 1},
	{"protected", 2},
	{"private", 3},
	{"static", 4},
	{"virtual", 5},
	{"sealed", 6},
	{"override", 7},
	{"abstract", 8},
	{"readonly", 9},
	{"extern", 10}
};

antlrcpp::Any XiasVisitor::visitCompilation_unit(XiasParser::Compilation_unitContext* ctx)
{
	CompilationUnit cUnit;
	m_cInfo = &cUnit;
	m_NamespaceInfo = &cUnit.m_GlobalNamespace;
	visitChildren(ctx);
    return cUnit;
}

antlrcpp::Any XiasVisitor::visitUsingNamespaceDirective(XiasParser::UsingNamespaceDirectiveContext* ctx)
{
	UsingInfo uInfo;
	uInfo.Using = ctx->namespace_or_type_name()->getText();
	m_cInfo->m_Usings.emplace_back(uInfo);
	return visitChildren(ctx);
}

antlrcpp::Any XiasVisitor::visitNamespace_declaration(XiasParser::Namespace_declarationContext* ctx)
{
	int namespaceCount = AddNamespaces(ctx->qi->getText());
	antlrcpp::Any& result = visitNamespace_body(ctx->namespace_body());
	RemoveNamespaces(namespaceCount);
	return result;
}

antlrcpp::Any XiasVisitor::visitClass_declaration(XiasParser::Class_declarationContext* ctx)
{
	ClassInfo* cInfo = &m_cInfo->m_Classes.emplace_back();

	AddModifiers(&cInfo->m_Modifiers, ctx->all_modifier(), ModifierType::Class);

	cInfo->m_QualifiedName = CreateQualifiedName(ctx->identifier()->getText());
	size_t begin = cInfo->m_QualifiedName.find_last_of(".");
	if (begin == std::string::npos) begin = 0;
	m_NamespaceInfo->m_Classes.emplace_back(cInfo->m_QualifiedName.substr(begin));

	// Base classes
	auto base = ctx->class_base();
	if (base)
	{
		auto class_base = base->class_type();
		auto interface_list = base->interface_type_list();
		if (class_base)
		{
			cInfo->m_Parents.emplace_back(class_base->getText());
		}
	}

	m_ClassStack.push(cInfo);
	AddNamespaces(ctx->identifier()->getText());
	antlrcpp::Any& result = visitClass_body(ctx->class_body());
	RemoveNamespaces(1);
	m_ClassStack.pop();

	return result;
}

antlrcpp::Any XiasVisitor::visitField_declaration(XiasParser::Field_declarationContext* ctx)
{
	ClassInfo* cInfo = m_ClassStack.top();
	Modifiers modifiers;
	AddModifiers(&modifiers, ctx->all_modifier(), ModifierType::Field);

	auto declarators = ctx->variable_declarators()->variable_declarator();
	for (auto declarator : declarators)
	{
		FieldInfo* field = &cInfo->m_Fields.emplace_back();
		field->m_Name = declarator->identifier()->getText();
		field->m_Modifiers = modifiers;
		if (auto initializer = declarator->variable_initializer())
			field->m_VariableInitializer = CreateExpression(initializer);
		field->m_Type = ctx->type_()->getText();
	}

	return antlrcpp::Any();
}

antlrcpp::Any XiasVisitor::visitMethod_declaration(XiasParser::Method_declarationContext* ctx)
{
	ClassInfo* cInfo = m_ClassStack.top();
	auto header = ctx->method_header();

	MethodInfo& mInfo = cInfo->m_Methods.emplace_back();
	mInfo.m_Name = header->member_name()->getText();
	AddModifiers(&mInfo.m_Modifiers, header->all_modifier(), ModifierType::Field);
	mInfo.m_Body = CreateStatement(ctx->method_body());
	mInfo.m_Type = header->return_type()->getText();

	for (auto parameter : header->formal_parameter_list()->fixed_parameters()->fixed_parameter())
	{
		ParameterInfo& pInfo = mInfo.m_Parameters.emplace_back();
		pInfo.m_Name = parameter->identifier()->getText();
		if (auto defaultArg = parameter->default_argument())
			pInfo.m_Default = CreateExpression(defaultArg->expression());
		pInfo.m_Type = parameter->type_()->getText();
	}

	return antlrcpp::Any();
}

antlrcpp::Any XiasVisitor::visitExpression(XiasParser::ExpressionContext* ctx)
{
	return visitChildren(ctx);
}

antlrcpp::Any XiasVisitor::visitNon_assignment_expression(XiasParser::Non_assignment_expressionContext* ctx)
{
	return visitChildren(ctx);
}

antlrcpp::Any XiasVisitor::visitConditional_expression(XiasParser::Conditional_expressionContext* ctx)
{
	switch (ctx->getAltNumber())
	{
		case 1: return visitChildren(ctx);
		case 2:
		{
			Expression* expression;
			expression = &m_ExpressionStack.top()->m_Children.emplace_back();
			m_ExpressionStack.emplace(expression);
			expression->m_Type = Expression::conditional_expression;
			auto& ret = visitChildren(ctx);
			m_ExpressionStack.pop();
			return ret;
		}
		default:
		{
			std::cerr << "Unknown modifier type!\n";
			return visitChildren(ctx);;
			// TODO: Real errors
		}
	}
}

antlrcpp::Any XiasVisitor::visitNull_coalescing_expression(XiasParser::Null_coalescing_expressionContext* ctx)
{
	switch (ctx->getAltNumber())
	{
		case 1: return visitChildren(ctx);
		case 2:
		{
			Expression* expression;
			expression = &m_ExpressionStack.top()->m_Children.emplace_back();
			m_ExpressionStack.emplace(expression);
			expression->m_Type = Expression::null_coalescing_expression;
			auto& ret = visitChildren(ctx);
			m_ExpressionStack.pop();
			return ret;
		}
		default:
		{
			std::cerr << "Unknown modifier type!\n";
			return visitChildren(ctx);;
			// TODO: Real errors
		}
	}
}

antlrcpp::Any XiasVisitor::visitConditional_or_expression(XiasParser::Conditional_or_expressionContext* ctx)
{
	if (ctx->conditional_or_expression())
	{
		Expression* expression;
		expression = &m_ExpressionStack.top()->m_Children.emplace_back();
		m_ExpressionStack.emplace(expression);
		expression->m_Type = Expression::conditional_or_expression;
		auto& ret = visitChildren(ctx);
		m_ExpressionStack.pop();
		return ret;
	}
	else
		return visitChildren(ctx);
}

antlrcpp::Any XiasVisitor::visitConditional_and_expression(XiasParser::Conditional_and_expressionContext* ctx)
{
	if (ctx->conditional_and_expression())
	{
		Expression* expression;
		expression = &m_ExpressionStack.top()->m_Children.emplace_back();
		m_ExpressionStack.emplace(expression);
		expression->m_Type = Expression::conditional_and_expression;
		auto& ret = visitChildren(ctx);
		m_ExpressionStack.pop();
		return ret;
	}
	else
		return visitChildren(ctx);
}

antlrcpp::Any XiasVisitor::visitInclusive_or_expression(XiasParser::Inclusive_or_expressionContext* ctx)
{
	if (ctx->inclusive_or_expression())
	{
		Expression* expression;
		expression = &m_ExpressionStack.top()->m_Children.emplace_back();
		m_ExpressionStack.emplace(expression);
		expression->m_Type = Expression::inclusive_or_expression;
		auto& ret = visitChildren(ctx);
		m_ExpressionStack.pop();
		return ret;
	}
	else
		return visitChildren(ctx);
}

antlrcpp::Any XiasVisitor::visitExclusive_or_expression(XiasParser::Exclusive_or_expressionContext* ctx)
{
	if (ctx->exclusive_or_expression())
	{
		Expression* expression;
		expression = &m_ExpressionStack.top()->m_Children.emplace_back();
		m_ExpressionStack.emplace(expression);
		expression->m_Type = Expression::exclusive_or_expression;
		auto& ret = visitChildren(ctx);
		m_ExpressionStack.pop();
		return ret;
	}
	else
		return visitChildren(ctx);
}

antlrcpp::Any XiasVisitor::visitAnd_expression(XiasParser::And_expressionContext* ctx)
{
	if (ctx->and_expression())
	{
		Expression* expression;
		expression = &m_ExpressionStack.top()->m_Children.emplace_back();
		m_ExpressionStack.emplace(expression);
		expression->m_Type = Expression::and_expression;
		auto& ret = visitChildren(ctx);
		m_ExpressionStack.pop();
		return ret;
	}
	else
		return visitChildren(ctx);
}

antlrcpp::Any XiasVisitor::visitEquality_expression(XiasParser::Equality_expressionContext* ctx)
{
	if (ctx->OP_EQ())
	{
		Expression* expression;
		expression = &m_ExpressionStack.top()->m_Children.emplace_back();
		m_ExpressionStack.emplace(expression);
		expression->m_Type = Expression::equality_expression_EQ;
		auto& ret = visitChildren(ctx);
		m_ExpressionStack.pop();
		return ret;
	}
	else if (ctx->OP_NE())
	{
		Expression* expression;
		expression = &m_ExpressionStack.top()->m_Children.emplace_back();
		m_ExpressionStack.emplace(expression);
		expression->m_Type = Expression::equality_expression_NE;
		auto& ret = visitChildren(ctx);
		m_ExpressionStack.pop();
		return ret;
	}
	else
		return visitChildren(ctx);
}

antlrcpp::Any XiasVisitor::visitRelational_expression(XiasParser::Relational_expressionContext* ctx)
{
	if (ctx->LT())
	{
		Expression* expression;
		expression = &m_ExpressionStack.top()->m_Children.emplace_back();
		m_ExpressionStack.emplace(expression);
		expression->m_Type = Expression::relational_expression_LT;
		auto& ret = visitChildren(ctx);
		m_ExpressionStack.pop();
		return ret;
	}
	else if (ctx->GT())
	{
		Expression* expression;
		expression = &m_ExpressionStack.top()->m_Children.emplace_back();
		m_ExpressionStack.emplace(expression);
		expression->m_Type = Expression::relational_expression_GT;
		auto& ret = visitChildren(ctx);
		m_ExpressionStack.pop();
		return ret;
	}
	else if (ctx->OP_LE())
	{
		Expression* expression;
		expression = &m_ExpressionStack.top()->m_Children.emplace_back();
		m_ExpressionStack.emplace(expression);
		expression->m_Type = Expression::relational_expression_OP_LE;
		auto& ret = visitChildren(ctx);
		m_ExpressionStack.pop();
		return ret;
	}
	else if (ctx->OP_GE())
	{
		Expression* expression;
		expression = &m_ExpressionStack.top()->m_Children.emplace_back();
		m_ExpressionStack.emplace(expression);
		expression->m_Type = Expression::relational_expression_OP_GE;
		auto& ret = visitChildren(ctx);
		m_ExpressionStack.pop();
		return ret;
	}
	else if (ctx->IS())
	{
		Expression* expression;
		expression = &m_ExpressionStack.top()->m_Children.emplace_back();
		m_ExpressionStack.emplace(expression);
		expression->m_Type = Expression::relational_expression_IS;
		expression->m_Data.emplace_back(ctx->type_()->getText());
		auto& ret = visitChildren(ctx);
		m_ExpressionStack.pop();
		return ret;
	}
	else if (ctx->AS())
	{
		Expression* expression;
		expression = &m_ExpressionStack.top()->m_Children.emplace_back();
		m_ExpressionStack.emplace(expression);
		expression->m_Type = Expression::relational_expression_AS;
		expression->m_Data.emplace_back(ctx->type_()->getText());
		auto& ret = visitChildren(ctx);
		m_ExpressionStack.pop();
		return ret;
	}
	else
		return visitChildren(ctx);
}

antlrcpp::Any XiasVisitor::visitShift_expression(XiasParser::Shift_expressionContext* ctx)
{
	if (ctx->OP_LEFT_SHIFT())
	{
		Expression* expression;
		expression = &m_ExpressionStack.top()->m_Children.emplace_back();
		m_ExpressionStack.emplace(expression);
		expression->m_Type = Expression::shift_expression_LEFT;
		auto& ret = visitChildren(ctx);
		m_ExpressionStack.pop();
		return ret;
	}
	else if (ctx->right_shift())
	{
		Expression* expression;
		expression = &m_ExpressionStack.top()->m_Children.emplace_back();
		m_ExpressionStack.emplace(expression);
		expression->m_Type = Expression::shift_expression_RIGHT;
		auto& ret = visitChildren(ctx);
		m_ExpressionStack.pop();
		return ret;
	}
	else
		return visitChildren(ctx);
}

antlrcpp::Any XiasVisitor::visitAdditive_expression(XiasParser::Additive_expressionContext* ctx)
{
	if (ctx->PLUS())
	{
		Expression* expression;
		expression = &m_ExpressionStack.top()->m_Children.emplace_back();
		m_ExpressionStack.emplace(expression);
		expression->m_Type = Expression::additive_expression_PLUS;
		auto& ret = visitChildren(ctx);
		m_ExpressionStack.pop();
		return ret;
	}
	else if (ctx->MINUS())
	{
		Expression* expression;
		expression = &m_ExpressionStack.top()->m_Children.emplace_back();
		m_ExpressionStack.emplace(expression);
		expression->m_Type = Expression::additive_expression_MINUS;
		auto& ret = visitChildren(ctx);
		m_ExpressionStack.pop();
		return ret;
	}
	else
		return visitChildren(ctx);
}

antlrcpp::Any XiasVisitor::visitMultiplicative_expression(XiasParser::Multiplicative_expressionContext* ctx)
{
	if (ctx->STAR())
	{
		Expression* expression;
		expression = &m_ExpressionStack.top()->m_Children.emplace_back();
		m_ExpressionStack.emplace(expression);
		expression->m_Type = Expression::multiplicative_expression_STAR;
		auto& ret = visitChildren(ctx);
		m_ExpressionStack.pop();
		return ret;
	}
	else if (ctx->DIV())
	{
		Expression* expression;
		expression = &m_ExpressionStack.top()->m_Children.emplace_back();
		m_ExpressionStack.emplace(expression);
		expression->m_Type = Expression::multiplicative_expression_DIV;
		auto& ret = visitChildren(ctx);
		m_ExpressionStack.pop();
		return ret;
	}
	else if (ctx->PERCENT())
	{
		Expression* expression;
		expression = &m_ExpressionStack.top()->m_Children.emplace_back();
		m_ExpressionStack.emplace(expression);
		expression->m_Type = Expression::multiplicative_expression_MOD;
		auto& ret = visitChildren(ctx);
		m_ExpressionStack.pop();
		return ret;
	}
	else
		return visitChildren(ctx);
}

antlrcpp::Any XiasVisitor::visitCast_expression(XiasParser::Cast_expressionContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::cast_expression;
	expression->m_Data.emplace_back(ctx->type_()->getText());
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitPre_decrement_expression(XiasParser::Pre_decrement_expressionContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::pre_decrement_expression;
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitPre_increment_expression(XiasParser::Pre_increment_expressionContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::pre_increment_expression;
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitUnary_tilde_expression(XiasParser::Unary_tilde_expressionContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::unary_tilde_expression;
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitUnary_bang_expression(XiasParser::Unary_bang_expressionContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::unary_bang_expression;
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitUnary_minus_expression(XiasParser::Unary_minus_expressionContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::unary_minus_expression;
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitUnary_plus_expression(XiasParser::Unary_plus_expressionContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::unary_plus_expression;
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitPrimary_no_array_creation_expression_base(XiasParser::Primary_no_array_creation_expression_baseContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::primary_no_array_creation_base;
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitLiteral(XiasParser::LiteralContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Data.emplace_back(ctx->getText());
	switch (ctx->getAltNumber())
	{
		case 1:
		{
			if (expression->m_Data[0] == "true")
				expression->m_Type = Expression::true_literal;
			else
				expression->m_Type = Expression::false_literal;
			break;
		}
		case 2:
		{
			// TODO: Clean up the input strings
			auto string = ctx->string_literal();
			if (string->REGULAR_STRING())
			{
				expression->m_Type = Expression::string_literal;
				// TODO: Convert special characters
			}
			else
			{
				expression->m_Type = Expression::verbatim_literal;
			}
			break;
		}
		// Remove any '_'s, prefixes, and suffixes
		case 3: expression->m_Type = Expression::integer_literal; break;
		case 4: expression->m_Type = Expression::unsigned_literal; break;
		case 5:
		{
			// TODO: Convert hex to integer
			expression->m_Type = Expression::integer_literal;
			break;
		}
		case 6: expression->m_Type = Expression::float_literal; break;
		case 7: expression->m_Type = Expression::double_literal; break;
		case 8: expression->m_Type = Expression::null_literal; break;
	}
	m_ExpressionStack.pop();
	return visitChildren(ctx);
}

antlrcpp::Any XiasVisitor::visitSimple_name(XiasParser::Simple_nameContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::simple_name;
	expression->m_Data.emplace_back(ctx->identifier()->getText());
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitParenthesized_expression(XiasParser::Parenthesized_expressionContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::parenthesized;
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitThis_access(XiasParser::This_accessContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	expression->m_Type = Expression::this_access;
	return visitChildren(ctx);
}

antlrcpp::Any XiasVisitor::visitBase_access(XiasParser::Base_accessContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::this_access;
	auto identifier = ctx->identifier();
	if (identifier)
		expression->m_Data.emplace_back(ctx->identifier()->getText());
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitObject_creation_expression(XiasParser::Object_creation_expressionContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::object_creation;
	expression->m_Data.emplace_back(ctx->type_()->getText());
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitObject_initializer(XiasParser::Object_initializerContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::object_initializer;
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitMember_initializer(XiasParser::Member_initializerContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::object_initializer;
	expression->m_Data.emplace_back(ctx->identifier()->getText());
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitCollection_initializer(XiasParser::Collection_initializerContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::collection_initializer;
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitElement_initializer(XiasParser::Element_initializerContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::element_initializer;
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitTypeof_expression(XiasParser::Typeof_expressionContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::typeof_expression;
	switch (ctx->getAltNumber())
	{
		case 1: expression->m_Data.emplace_back(ctx->type_()->getText()); break;
		case 2: expression->m_Data.emplace_back(ctx->unbound_type_name()->getText()); break;
		case 3: expression->m_Data.emplace_back("void"); break;
	}
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitDefault_value_expression(XiasParser::Default_value_expressionContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::default_value;
	expression->m_Data.emplace_back(ctx->type_()->getText());
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitMember_access(XiasParser::Member_accessContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::member_access;
	expression->m_Data.emplace_back(ctx->identifier()->getText());
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitPredefined_type(XiasParser::Predefined_typeContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::predefined_type;
	expression->m_Data.emplace_back(ctx->getText());
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitQualified_alias_member(XiasParser::Qualified_alias_memberContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::qualified_alias_member;
	auto& identifiers = ctx->identifier();
	for (auto& identifer : identifiers)
		expression->m_Data.emplace_back(identifer->getText());
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitInvocation_expression(XiasParser::Invocation_expressionContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::invocation_expression;
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitElement_access(XiasParser::Element_accessContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::element_access;
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitPost_increment_expression(XiasParser::Post_increment_expressionContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::post_increment_expression;
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitPost_decrement_expression(XiasParser::Post_decrement_expressionContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::post_decrement_expression;
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitArrayCreationWithExpressionSize(XiasParser::ArrayCreationWithExpressionSizeContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::array_creation_with_expression_size;
	expression->m_Data.emplace_back(ctx->non_array_type()->getText());
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitArrayCreationWithInitializer(XiasParser::ArrayCreationWithInitializerContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::array_creation_with_initializer;
	expression->m_Data.emplace_back(ctx->array_type()->getText());
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}
antlrcpp::Any XiasVisitor::visitRank_specifier(XiasParser::Rank_specifierContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::rank_specifier;
	auto& ranks = ctx->dim_separator();
	expression->m_Data.emplace_back(std::to_string(ranks.size()));
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitAssignment(XiasParser::AssignmentContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	switch (ctx->getAltNumber())
	{
		case 1: expression->m_Type = Expression::assignment; break;
		case 2: expression->m_Type = Expression::ADD_assignment; break;
		case 3: expression->m_Type = Expression::SUB_assignment; break;
		case 4: expression->m_Type = Expression::MULT_assignment; break;
		case 5: expression->m_Type = Expression::DIV_assignment; break;
		case 6: expression->m_Type = Expression::MOD_assignment; break;
		case 7: expression->m_Type = Expression::AND_assignment; break;
		case 8: expression->m_Type = Expression::OR_assignment; break;
		case 9: expression->m_Type = Expression::XOR_assignment; break;
		case 10: expression->m_Type = Expression::LEFT_SHIFT_assignment; break;
		case 11: expression->m_Type = Expression::RIGHT_SHIFT_assignment; break;
	}
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitArray_initializer(XiasParser::Array_initializerContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::array_initializer;
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitVariable_initializer_list(XiasParser::Variable_initializer_listContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::variable_initializer_list;
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitVariable_initializer(XiasParser::Variable_initializerContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::variable_initializer;
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitType_argument_list(XiasParser::Type_argument_listContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::simple_name;

	auto types = ctx->type_();
	expression->m_Data.reserve(types.size());

	for (auto& type : types)
	{
		expression->m_Data.emplace_back(type->getText());
	}
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitExpression_list(XiasParser::Expression_listContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::expression_list;
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitArgument_list(XiasParser::Argument_listContext* ctx)
{
	Expression* expression;
	expression = &m_ExpressionStack.top()->m_Children.emplace_back();
	m_ExpressionStack.emplace(expression);
	expression->m_Type = Expression::argument_list;
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	return ret;
}


antlrcpp::Any XiasVisitor::visitBlock(XiasParser::BlockContext* ctx)
{
	BASIC_STATEMENT(block);
}

antlrcpp::Any XiasVisitor::visitStatement_list(XiasParser::Statement_listContext* ctx)
{
	BASIC_STATEMENT(block);
}

antlrcpp::Any XiasVisitor::visitLabeled_statement(XiasParser::Labeled_statementContext* ctx)
{
	Statement* statement;
	statement = &m_StatementStack.top()->m_Children.emplace_back();
	m_StatementStack.emplace(statement);
	statement->m_Type = Statement::labeled_statement;
	statement->m_Data.emplace_back(ctx->identifier()->getText());
	auto& ret = visitChildren(ctx);
	m_StatementStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitLocal_variable_declaration(XiasParser::Local_variable_declarationContext* ctx)
{
	Statement* statement;
	statement = &m_StatementStack.top()->m_Children.emplace_back();
	m_StatementStack.emplace(statement);
	statement->m_Type = Statement::local_variable_declaration;
	statement->m_Data.emplace_back(ctx->local_variable_type()->getText());
	auto& ret = visitChildren(ctx);
	m_StatementStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitLocal_variable_declarator(XiasParser::Local_variable_declaratorContext* ctx)
{
	Statement* statement;
	statement = &m_StatementStack.top()->m_Children.emplace_back();
	m_StatementStack.emplace(statement);
	statement->m_Type = Statement::local_variable_declarator;
	statement->m_Data.emplace_back(ctx->identifier()->getText());
	Expression* expression = &statement->m_Expressions.emplace_back();
	expression->m_Type = Expression::local_variable_initializer;
	m_ExpressionStack.push(expression);
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	m_StatementStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitLocal_constant_declaration(XiasParser::Local_constant_declarationContext* ctx)
{
	Statement* statement;
	statement = &m_StatementStack.top()->m_Children.emplace_back();
	m_StatementStack.emplace(statement);
	statement->m_Type = Statement::local_constant_declaration;
	statement->m_Data.emplace_back(ctx->type_()->getText());
	auto& ret = visitChildren(ctx);
	m_StatementStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitConstant_declarator(XiasParser::Constant_declaratorContext* ctx)
{
	Statement* statement;
	statement = &m_StatementStack.top()->m_Children.emplace_back();
	m_StatementStack.emplace(statement);
	statement->m_Type = Statement::constant_declarator;
	statement->m_Data.emplace_back(ctx->identifier()->getText());
	Expression* expression = &statement->m_Expressions.emplace_back();
	expression->m_Type = Expression::expression;
	m_ExpressionStack.push(expression);
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	m_StatementStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitEmpty_statement(XiasParser::Empty_statementContext* ctx)
{
	BASIC_STATEMENT(empty);
}

antlrcpp::Any XiasVisitor::visitStatement_expression(XiasParser::Statement_expressionContext* ctx)
{
	Statement* statement;
	statement = &m_StatementStack.top()->m_Children.emplace_back();
	m_StatementStack.emplace(statement);
	statement->m_Type = Statement::statement_expression;
	Expression* expression = &statement->m_Expressions.emplace_back();
	expression->m_Type = Expression::expression;
	m_ExpressionStack.push(expression);
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	m_StatementStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitIf_statement(XiasParser::If_statementContext* ctx)
{
	Statement* statement;
	statement = &m_StatementStack.top()->m_Children.emplace_back();
	m_StatementStack.emplace(statement);
	statement->m_Type = Statement::if_statement;
	Expression* expression = &statement->m_Expressions.emplace_back();
	expression->m_Type = Expression::expression;
	m_ExpressionStack.push(expression);
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	m_StatementStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitStatement_expression_list(XiasParser::Statement_expression_listContext* ctx)
{
	BASIC_STATEMENT(statement_expression_list);
}

antlrcpp::Any XiasVisitor::visitSwitch_statement(XiasParser::Switch_statementContext* ctx)
{
	Statement* statement;
	statement = &m_StatementStack.top()->m_Children.emplace_back();
	m_StatementStack.emplace(statement);
	statement->m_Type = Statement::switch_statement;
	Expression* expression = &statement->m_Expressions.emplace_back();
	expression->m_Type = Expression::expression;
	m_ExpressionStack.push(expression);
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	m_StatementStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitSwitch_section(XiasParser::Switch_sectionContext* ctx)
{
	Statement* statement;
	statement = &m_StatementStack.top()->m_Children.emplace_back();
	m_StatementStack.emplace(statement);
	statement->m_Type = Statement::switch_section;
	auto& ret = visitChildren(ctx);
	m_StatementStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitSwitch_label(XiasParser::Switch_labelContext* ctx)
{
	Statement* statement;
	statement = &m_StatementStack.top()->m_Children.emplace_back();
	m_StatementStack.emplace(statement);
	statement->m_Type = Statement::switch_label;
	Expression* expression = &statement->m_Expressions.emplace_back();
	expression->m_Type = Expression::expression;
	m_ExpressionStack.push(expression);
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	m_StatementStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitWhile_statement(XiasParser::While_statementContext* ctx)
{
	Statement* statement;
	statement = &m_StatementStack.top()->m_Children.emplace_back();
	m_StatementStack.emplace(statement);
	statement->m_Type = Statement::while_statement;
	Expression* expression = &statement->m_Expressions.emplace_back();
	expression->m_Type = Expression::expression;
	m_ExpressionStack.push(expression);
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	m_StatementStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitDo_statement(XiasParser::Do_statementContext* ctx)
{
	Statement* statement;
	statement = &m_StatementStack.top()->m_Children.emplace_back();
	m_StatementStack.emplace(statement);
	statement->m_Type = Statement::do_statement;
	Expression* expression = &statement->m_Expressions.emplace_back();
	expression->m_Type = Expression::expression;
	m_ExpressionStack.push(expression);
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	m_StatementStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitFor_statement(XiasParser::For_statementContext* ctx)
{
	Statement* statement;
	statement = &m_StatementStack.top()->m_Children.emplace_back();
	m_StatementStack.emplace(statement);
	statement->m_Type = Statement::for_statement;
	auto& ret = visitChildren(ctx);
	m_StatementStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitFor_initializer(XiasParser::For_initializerContext* ctx)
{
	Statement* statement;
	statement = &m_StatementStack.top()->m_Children.emplace_back();
	m_StatementStack.emplace(statement);
	statement->m_Type = Statement::for_initializer;
	auto& ret = visitChildren(ctx);
	m_StatementStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitFor_condition(XiasParser::For_conditionContext* ctx)
{
	Statement* statement;
	statement = &m_StatementStack.top()->m_Children.emplace_back();
	m_StatementStack.emplace(statement);
	statement->m_Type = Statement::for_condition;
	Expression* expression = &statement->m_Expressions.emplace_back();
	expression->m_Type = Expression::expression;
	m_ExpressionStack.push(expression);
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	m_StatementStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitFor_iterator(XiasParser::For_iteratorContext* ctx)
{
	Statement* statement;
	statement = &m_StatementStack.top()->m_Children.emplace_back();
	m_StatementStack.emplace(statement);
	statement->m_Type = Statement::switch_statement;
	auto& ret = visitChildren(ctx);
	m_StatementStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitForeach_statement(XiasParser::Foreach_statementContext* ctx)
{
	Statement* statement;
	statement = &m_StatementStack.top()->m_Children.emplace_back();
	m_StatementStack.emplace(statement);
	statement->m_Type = Statement::switch_statement;
	statement->m_Data.emplace_back(ctx->local_variable_type()->getText());
	statement->m_Data.emplace_back(ctx->identifier()->getText());
	Expression* expression = &statement->m_Expressions.emplace_back();
	expression->m_Type = Expression::expression;
	m_ExpressionStack.push(expression);
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	m_StatementStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitBreak_statement(XiasParser::Break_statementContext* ctx)
{
	BASIC_STATEMENT(break_statement);
}

antlrcpp::Any XiasVisitor::visitContinue_statement(XiasParser::Continue_statementContext* ctx)
{
	BASIC_STATEMENT(continue_statement);
}

antlrcpp::Any XiasVisitor::visitGoto_statement(XiasParser::Goto_statementContext* ctx)
{
	Statement* statement;
	statement = &m_StatementStack.top()->m_Children.emplace_back();
	m_StatementStack.emplace(statement);
	switch (ctx->getAltNumber())
	{
		case 1:
		{
			statement->m_Type = Statement::goto_label;
			statement->m_Data.emplace_back(ctx->identifier()->getText());
			auto& ret = visitChildren(ctx);
			m_StatementStack.pop();
			return ret;
		}
		case 2:
		{
			statement->m_Type = Statement::goto_case;
			Expression* expression = &statement->m_Expressions.emplace_back();
			expression->m_Type = Expression::expression;
			m_ExpressionStack.push(expression);
			auto& ret = visitChildren(ctx);
			m_ExpressionStack.pop();
			m_StatementStack.pop();
			return ret;
		}
		case 3:
		default:
		{
			statement->m_Type = Statement::goto_default;
			auto& ret = visitChildren(ctx);
			m_StatementStack.pop();
			return ret;
		}
	}
}

antlrcpp::Any XiasVisitor::visitReturn_statement(XiasParser::Return_statementContext* ctx)
{
	Statement* statement;
	statement = &m_StatementStack.top()->m_Children.emplace_back();
	m_StatementStack.emplace(statement);
	statement->m_Type = Statement::return_statement;
	Expression* expression = &statement->m_Expressions.emplace_back();
	expression->m_Type = Expression::expression;
	m_ExpressionStack.push(expression);
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	m_StatementStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitThrow_statement(XiasParser::Throw_statementContext* ctx)
{
	Statement* statement;
	statement = &m_StatementStack.top()->m_Children.emplace_back();
	m_StatementStack.emplace(statement);
	statement->m_Type = Statement::throw_statement;
	Expression* expression = &statement->m_Expressions.emplace_back();
	expression->m_Type = Expression::expression;
	m_ExpressionStack.push(expression);
	auto& ret = visitChildren(ctx);
	m_ExpressionStack.pop();
	m_StatementStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitTry_statement(XiasParser::Try_statementContext* ctx)
{
	Statement* statement;
	statement = &m_StatementStack.top()->m_Children.emplace_back();
	m_StatementStack.emplace(statement);
	statement->m_Type = Statement::try_statement;
	auto& ret = visitChildren(ctx);
	m_StatementStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitCatch_clause(XiasParser::Catch_clauseContext* ctx)
{
	Statement* statement;
	statement = &m_StatementStack.top()->m_Children.emplace_back();
	m_StatementStack.emplace(statement);
	statement->m_Type = Statement::catch_clause;
	auto& ret = visitChildren(ctx);
	m_StatementStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitFinally_clause(XiasParser::Finally_clauseContext* ctx)
{
	Statement* statement;
	statement = &m_StatementStack.top()->m_Children.emplace_back();
	m_StatementStack.emplace(statement);
	statement->m_Type = Statement::finally_clause;
	auto& ret = visitChildren(ctx);
	m_StatementStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitException_specifier(XiasParser::Exception_specifierContext* ctx)
{
	Statement* statement;
	statement = &m_StatementStack.top()->m_Children.emplace_back();
	m_StatementStack.emplace(statement);
	statement->m_Type = Statement::exception_specifier;
	statement->m_Data.emplace_back(ctx->type_()->getText());
	if (auto identifier = ctx->identifier())
		statement->m_Data.emplace_back(identifier->getText());
	auto& ret = visitChildren(ctx);
	m_StatementStack.pop();
	return ret;
}

antlrcpp::Any XiasVisitor::visitException_filter(XiasParser::Exception_filterContext* ctx)
{
	Statement* statement;
	statement = &m_StatementStack.top()->m_Children.emplace_back();
	m_StatementStack.emplace(statement);
	statement->m_Type = Statement::exception_filter;
	auto& ret = visitChildren(ctx);
	m_StatementStack.pop();
	return ret;
}


int XiasVisitor::AddNamespaces(const std::string& name)
{
	size_t count = 1, begin = 0, delimiter;
	while ((delimiter = name.find(".", begin)) != std::string::npos)
	{
		std::string subName = name.substr(begin, delimiter);
		NamespaceInfo* nSpace = new Xias::NamespaceInfo;
		nSpace->m_Name = subName;
		m_QualifierStack.push(nSpace);
		begin += delimiter + 1;
		count++;
	}
	NamespaceInfo* nSpace = new Xias::NamespaceInfo;
	nSpace->m_Name = name.substr(begin);
	m_QualifierStack.push(nSpace);
	m_NamespaceInfo = m_QualifierStack.top();
	// TODO: Real errors
	if (count > INT_MAX)
		std::cerr << "namespace count overflow";
	return count;
}

void XiasVisitor::RemoveNamespaces(int amount)
{
	while (amount > 0)
	{
		delete m_QualifierStack.top();
		m_QualifierStack.pop();
		amount--;
	}
	if (m_QualifierStack.empty())
		m_NamespaceInfo = &m_cInfo->m_GlobalNamespace;
	else
		m_NamespaceInfo = m_QualifierStack.top();
}

std::string XiasVisitor::CreateQualifiedName(const std::string& name)
{
	std::string qualifiedName;
	size_t nameSize = name.size();
	for (NamespaceInfo* qualifier : m_QualifierStack._Get_container())
	{
		nameSize += qualifier->m_Name.size() + 1;
	}
	qualifiedName.reserve(nameSize);
	for (NamespaceInfo* qualifier : m_QualifierStack._Get_container())
	{
		qualifiedName += qualifier->m_Name;
		qualifiedName += '.';
	}
	qualifiedName += name;

	return qualifiedName;
}

Expression XiasVisitor::CreateExpression(XiasParser::Variable_initializerContext* ctx)
{
	Expression expression;
	m_ExpressionStack.emplace(&expression);
	expression.m_Type = Expression::variable_initializer;
	visitChildren(ctx);
	m_ExpressionStack.pop();
	return expression;
}

Expression XiasVisitor::CreateExpression(XiasParser::ExpressionContext* ctx)
{
	Expression expression;
	m_ExpressionStack.emplace(&expression);
	expression.m_Type = Expression::expression;
	visitChildren(ctx);
	m_ExpressionStack.pop();
	return expression;
}

Xias::Statement XiasVisitor::CreateStatement(XiasParser::Method_bodyContext* ctx)
{
	Statement statement;
	m_StatementStack.emplace(&statement);
	statement.m_Type = Statement::block;
	if (auto block = ctx->block())
		visitChildren(block);
	m_StatementStack.pop();
	return statement;
}

void XiasVisitor::AddModifiers(Modifiers* mods, std::vector<XiasParser::All_modifierContext*> modifiers, ModifierType type)
{
	bool duplicateAccess = false;
	AccessModifier previous = AccessModifier::Public;
	std::vector<bool>* allowedModifiers = nullptr;
	switch (type)
	{
		case ModifierType::Class: allowedModifiers = &ClassModifiers; break;
		case ModifierType::Field: allowedModifiers = &FieldModifiers; break;
		case ModifierType::Property: allowedModifiers = &PropertyModifiers; break;
		case ModifierType::Method: allowedModifiers = &MethodModifiers; break;
		default:
		{
			std::cerr << "Unknown modifier type!\n";
			return;
			// TODO: Real errors
		}
	}

	for (auto modifier : modifiers)
	{
		if (!(*allowedModifiers)[modifier->altNum])
		{
			// TODO: Error
			continue;
		}

		switch (ModifierID.at(modifier->getText()))
		{
			case 0: AddModifier(mods, Modifier::New, modifier); break;
			case 1: if (!duplicateAccess) { mods->m_Access = AccessModifier::Public; duplicateAccess = true; } break;
			case 2: if (!duplicateAccess) { mods->m_Access = AccessModifier::Protected; duplicateAccess = true; } break;
			case 3: if (!duplicateAccess) { mods->m_Access = AccessModifier::Private; duplicateAccess = true; } break;
			case 4: AddModifier(mods, Modifier::Static, modifier); break;
			case 5: AddModifier(mods, Modifier::Virtual, modifier); break;
			case 6: AddModifier(mods, Modifier::Sealed, modifier); break;
			case 7: AddModifier(mods, Modifier::Override, modifier); break;
			case 8: AddModifier(mods, Modifier::Abstract, modifier); break;
			case 9: AddModifier(mods, Modifier::Readonly, modifier); break;
			case 10: AddModifier(mods, Modifier::Readonly, modifier); break;
		}
	}
}

void XiasVisitor::AddModifier(Modifiers* mods, Modifier modifier, XiasParser::All_modifierContext* ctx)
{
	auto iter = std::find(mods->m_Modifiers.begin(), mods->m_Modifiers.end(), modifier);
	if (iter == mods->m_Modifiers.end())
		mods->m_Modifiers.emplace_back(modifier);
	else
		std::cerr << "duplicate modifier \"" + ctx->getText() + "\"\n";
	// TODO: Real errors
}

bool XiasVisitor::HasModifier(Modifiers* mods, Modifier modifier)
{
	auto iter = std::find(mods->m_Modifiers.begin(), mods->m_Modifiers.end(), modifier);
	return iter != mods->m_Modifiers.end();
}
