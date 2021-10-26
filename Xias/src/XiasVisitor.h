#include "antlr4-runtime.h"
#include "XiasParserBaseVisitor.h"

#include "compilation_unit.h"

#include <string>
#include <stack>

enum class ModifierType
{
	Class,
	Field,
	Property,
	Method,
};

class XiasVisitor : XiasParserBaseVisitor {
	Xias::NamespaceInfo* m_NamespaceInfo;
	Xias::CompilationUnit* m_cInfo;
	std::stack<Xias::NamespaceInfo*> m_QualifierStack;
	std::stack<Xias::ClassInfo*> m_ClassStack;
	std::stack<Xias::Expression*> m_ExpressionStack;
	std::stack<Xias::Statement*> m_StatementStack;
public:    
    virtual antlrcpp::Any visitCompilation_unit(XiasParser::Compilation_unitContext* ctx) override;
private:
	virtual antlrcpp::Any visitUsingNamespaceDirective(XiasParser::UsingNamespaceDirectiveContext* ctx) override;
	virtual antlrcpp::Any visitNamespace_declaration(XiasParser::Namespace_declarationContext* ctx) override;

	virtual antlrcpp::Any visitClass_declaration(XiasParser::Class_declarationContext* ctx) override;
	// constant_declaration
	virtual antlrcpp::Any visitField_declaration(XiasParser::Field_declarationContext* ctx) override;
	virtual antlrcpp::Any visitMethod_declaration(XiasParser::Method_declarationContext* ctx) override;
	// property_declaration
    // indexer_declaration
    // operator_declaration
    // constructor_declaration
    // static_constructor_declaration
    // destructor_declaration
    // type_declaration

	virtual antlrcpp::Any visitExpression(XiasParser::ExpressionContext* ctx) override;
	virtual antlrcpp::Any visitNon_assignment_expression(XiasParser::Non_assignment_expressionContext* ctx) override;

	virtual antlrcpp::Any visitConditional_expression(XiasParser::Conditional_expressionContext* ctx) override;
	virtual antlrcpp::Any visitNull_coalescing_expression(XiasParser::Null_coalescing_expressionContext* ctx) override;
	virtual antlrcpp::Any visitConditional_or_expression(XiasParser::Conditional_or_expressionContext* ctx) override;
	virtual antlrcpp::Any visitConditional_and_expression(XiasParser::Conditional_and_expressionContext* ctx) override;
	virtual antlrcpp::Any visitInclusive_or_expression(XiasParser::Inclusive_or_expressionContext* ctx) override;
	virtual antlrcpp::Any visitExclusive_or_expression(XiasParser::Exclusive_or_expressionContext* ctx) override;
	virtual antlrcpp::Any visitAnd_expression(XiasParser::And_expressionContext* ctx) override;
	virtual antlrcpp::Any visitEquality_expression(XiasParser::Equality_expressionContext* ctx) override;
	virtual antlrcpp::Any visitRelational_expression(XiasParser::Relational_expressionContext* ctx) override;
	virtual antlrcpp::Any visitShift_expression(XiasParser::Shift_expressionContext* ctx) override;
	virtual antlrcpp::Any visitAdditive_expression(XiasParser::Additive_expressionContext* ctx) override;
	virtual antlrcpp::Any visitMultiplicative_expression(XiasParser::Multiplicative_expressionContext* ctx) override;

	virtual antlrcpp::Any visitCast_expression(XiasParser::Cast_expressionContext* ctx) override;
	virtual antlrcpp::Any visitPre_decrement_expression(XiasParser::Pre_decrement_expressionContext* ctx) override;
	virtual antlrcpp::Any visitPre_increment_expression(XiasParser::Pre_increment_expressionContext* ctx) override;
	virtual antlrcpp::Any visitUnary_tilde_expression(XiasParser::Unary_tilde_expressionContext* ctx) override;
	virtual antlrcpp::Any visitUnary_bang_expression(XiasParser::Unary_bang_expressionContext* ctx) override;
	virtual antlrcpp::Any visitUnary_minus_expression(XiasParser::Unary_minus_expressionContext* ctx) override;
	virtual antlrcpp::Any visitUnary_plus_expression(XiasParser::Unary_plus_expressionContext* ctx) override;

	virtual antlrcpp::Any visitPrimary_no_array_creation_expression_base(XiasParser::Primary_no_array_creation_expression_baseContext* ctx) override;

	virtual antlrcpp::Any visitLiteral(XiasParser::LiteralContext* ctx) override;
	virtual antlrcpp::Any visitSimple_name(XiasParser::Simple_nameContext* ctx) override;
	virtual antlrcpp::Any visitParenthesized_expression(XiasParser::Parenthesized_expressionContext* ctx) override;
	virtual antlrcpp::Any visitThis_access(XiasParser::This_accessContext* ctx) override;
	virtual antlrcpp::Any visitBase_access(XiasParser::Base_accessContext* ctx) override;
	virtual antlrcpp::Any visitObject_creation_expression(XiasParser::Object_creation_expressionContext* ctx) override;
	virtual antlrcpp::Any visitObject_initializer(XiasParser::Object_initializerContext* ctx) override;
	virtual antlrcpp::Any visitMember_initializer(XiasParser::Member_initializerContext* ctx) override;
	virtual antlrcpp::Any visitCollection_initializer(XiasParser::Collection_initializerContext* ctx) override;
	virtual antlrcpp::Any visitElement_initializer(XiasParser::Element_initializerContext* ctx) override;
	virtual antlrcpp::Any visitTypeof_expression(XiasParser::Typeof_expressionContext* ctx) override;
	virtual antlrcpp::Any visitDefault_value_expression(XiasParser::Default_value_expressionContext* ctx) override;

	virtual antlrcpp::Any visitMember_access(XiasParser::Member_accessContext* ctx) override;
	virtual antlrcpp::Any visitPredefined_type(XiasParser::Predefined_typeContext* ctx) override;
	virtual antlrcpp::Any visitQualified_alias_member(XiasParser::Qualified_alias_memberContext* ctx) override;
	virtual antlrcpp::Any visitInvocation_expression(XiasParser::Invocation_expressionContext* ctx) override;
	virtual antlrcpp::Any visitElement_access(XiasParser::Element_accessContext* ctx) override;
	virtual antlrcpp::Any visitPost_increment_expression(XiasParser::Post_increment_expressionContext* ctx) override;
	virtual antlrcpp::Any visitPost_decrement_expression(XiasParser::Post_decrement_expressionContext* ctx) override;

	virtual antlrcpp::Any visitArrayCreationWithExpressionSize(XiasParser::ArrayCreationWithExpressionSizeContext* ctx) override;
	virtual antlrcpp::Any visitArrayCreationWithInitializer(XiasParser::ArrayCreationWithInitializerContext* ctx) override;
	virtual antlrcpp::Any visitRank_specifier(XiasParser::Rank_specifierContext* ctx) override;

	virtual antlrcpp::Any visitAssignment(XiasParser::AssignmentContext* ctx) override;

	virtual antlrcpp::Any visitArray_initializer(XiasParser::Array_initializerContext* ctx) override;
	virtual antlrcpp::Any visitVariable_initializer_list(XiasParser::Variable_initializer_listContext* ctx) override;
	virtual antlrcpp::Any visitVariable_initializer(XiasParser::Variable_initializerContext* ctx) override;

	virtual antlrcpp::Any visitType_argument_list(XiasParser::Type_argument_listContext* ctx) override;
	virtual antlrcpp::Any visitExpression_list(XiasParser::Expression_listContext* ctx) override;

	virtual antlrcpp::Any visitArgument_list(XiasParser::Argument_listContext* ctx) override;


	virtual antlrcpp::Any visitBlock(XiasParser::BlockContext* ctx) override;

	virtual antlrcpp::Any visitStatement_list(XiasParser::Statement_listContext* ctx) override;

	virtual antlrcpp::Any visitLabeled_statement(XiasParser::Labeled_statementContext* ctx) override;

	virtual antlrcpp::Any visitLocal_variable_declaration(XiasParser::Local_variable_declarationContext* ctx) override;
	virtual antlrcpp::Any visitLocal_variable_declarator(XiasParser::Local_variable_declaratorContext* ctx) override;
	virtual antlrcpp::Any visitLocal_constant_declaration(XiasParser::Local_constant_declarationContext* ctx) override;
	virtual antlrcpp::Any visitConstant_declarator(XiasParser::Constant_declaratorContext* ctx) override;

	virtual antlrcpp::Any visitEmpty_statement(XiasParser::Empty_statementContext* ctx) override;
	virtual antlrcpp::Any visitStatement_expression(XiasParser::Statement_expressionContext* ctx) override;
	virtual antlrcpp::Any visitStatement_expression_list(XiasParser::Statement_expression_listContext* ctx) override;
	virtual antlrcpp::Any visitIf_statement(XiasParser::If_statementContext* ctx) override;
	virtual antlrcpp::Any visitSwitch_statement(XiasParser::Switch_statementContext* ctx) override;
	virtual antlrcpp::Any visitSwitch_section(XiasParser::Switch_sectionContext* ctx) override;
	virtual antlrcpp::Any visitSwitch_label(XiasParser::Switch_labelContext* ctx) override;
	virtual antlrcpp::Any visitWhile_statement(XiasParser::While_statementContext* ctx) override;
	virtual antlrcpp::Any visitDo_statement(XiasParser::Do_statementContext* ctx) override;
	virtual antlrcpp::Any visitFor_statement(XiasParser::For_statementContext* ctx) override;
	virtual antlrcpp::Any visitFor_initializer(XiasParser::For_initializerContext* ctx) override;
	virtual antlrcpp::Any visitFor_condition(XiasParser::For_conditionContext* ctx) override;
	virtual antlrcpp::Any visitFor_iterator(XiasParser::For_iteratorContext* ctx) override;
	virtual antlrcpp::Any visitForeach_statement(XiasParser::Foreach_statementContext* ctx) override;
	virtual antlrcpp::Any visitBreak_statement(XiasParser::Break_statementContext* ctx) override;
	virtual antlrcpp::Any visitContinue_statement(XiasParser::Continue_statementContext* ctx) override;
	virtual antlrcpp::Any visitGoto_statement(XiasParser::Goto_statementContext* ctx) override;
	virtual antlrcpp::Any visitReturn_statement(XiasParser::Return_statementContext* ctx) override;
	virtual antlrcpp::Any visitThrow_statement(XiasParser::Throw_statementContext* ctx) override;
	virtual antlrcpp::Any visitTry_statement(XiasParser::Try_statementContext* ctx) override;
	virtual antlrcpp::Any visitCatch_clause(XiasParser::Catch_clauseContext* ctx) override;
	virtual antlrcpp::Any visitFinally_clause(XiasParser::Finally_clauseContext* ctx) override;
	virtual antlrcpp::Any visitException_specifier(XiasParser::Exception_specifierContext* ctx) override;
	virtual antlrcpp::Any visitException_filter(XiasParser::Exception_filterContext* ctx) override;
private:
	int AddNamespaces(const std::string& name);
	void RemoveNamespaces(int amount);
	std::string CreateQualifiedName(const std::string& name);
	Xias::Expression CreateExpression(XiasParser::Variable_initializerContext* ctx);
	Xias::Expression CreateExpression(XiasParser::ExpressionContext* ctx);
	Xias::Statement CreateStatement(XiasParser::Method_bodyContext* ctx);
	void AddModifiers(Xias::Modifiers* mods, std::vector<XiasParser::All_modifierContext*> modifiers, ModifierType type);
	void AddModifier(Xias::Modifiers* mods, Xias::Modifier modifier, XiasParser::All_modifierContext* ctx);
	bool HasModifier(Xias::Modifiers* mods, Xias::Modifier modifier);
};
