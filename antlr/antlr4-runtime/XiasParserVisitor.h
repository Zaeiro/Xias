
// Generated from c:\dev\Xias\antlr\XiasParser.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "XiasParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by XiasParser.
 */
class  XiasParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by XiasParser.
   */
    virtual antlrcpp::Any visitCompilation_unit(XiasParser::Compilation_unitContext *context) = 0;

    virtual antlrcpp::Any visitUsingAliasDirective(XiasParser::UsingAliasDirectiveContext *context) = 0;

    virtual antlrcpp::Any visitUsingNamespaceDirective(XiasParser::UsingNamespaceDirectiveContext *context) = 0;

    virtual antlrcpp::Any visitUsingStaticDirective(XiasParser::UsingStaticDirectiveContext *context) = 0;

    virtual antlrcpp::Any visitNamespace_member_declaration(XiasParser::Namespace_member_declarationContext *context) = 0;

    virtual antlrcpp::Any visitNamespace_declaration(XiasParser::Namespace_declarationContext *context) = 0;

    virtual antlrcpp::Any visitQualified_identifier(XiasParser::Qualified_identifierContext *context) = 0;

    virtual antlrcpp::Any visitNamespace_body(XiasParser::Namespace_bodyContext *context) = 0;

    virtual antlrcpp::Any visitQualified_alias_member(XiasParser::Qualified_alias_memberContext *context) = 0;

    virtual antlrcpp::Any visitType_declaration(XiasParser::Type_declarationContext *context) = 0;

    virtual antlrcpp::Any visitType_parameter_list(XiasParser::Type_parameter_listContext *context) = 0;

    virtual antlrcpp::Any visitType_argument_list(XiasParser::Type_argument_listContext *context) = 0;

    virtual antlrcpp::Any visitType_parameter(XiasParser::Type_parameterContext *context) = 0;

    virtual antlrcpp::Any visitType_parameter_constraints_clause(XiasParser::Type_parameter_constraints_clauseContext *context) = 0;

    virtual antlrcpp::Any visitType_parameter_constraints(XiasParser::Type_parameter_constraintsContext *context) = 0;

    virtual antlrcpp::Any visitConstructor_constraint(XiasParser::Constructor_constraintContext *context) = 0;

    virtual antlrcpp::Any visitBasic_modifier(XiasParser::Basic_modifierContext *context) = 0;

    virtual antlrcpp::Any visitType_(XiasParser::Type_Context *context) = 0;

    virtual antlrcpp::Any visitNamespace_name(XiasParser::Namespace_nameContext *context) = 0;

    virtual antlrcpp::Any visitType_name(XiasParser::Type_nameContext *context) = 0;

    virtual antlrcpp::Any visitNamespace_or_type_name(XiasParser::Namespace_or_type_nameContext *context) = 0;

    virtual antlrcpp::Any visitValue_type(XiasParser::Value_typeContext *context) = 0;

    virtual antlrcpp::Any visitStruct_type(XiasParser::Struct_typeContext *context) = 0;

    virtual antlrcpp::Any visitBase_type(XiasParser::Base_typeContext *context) = 0;

    virtual antlrcpp::Any visitSimple_type(XiasParser::Simple_typeContext *context) = 0;

    virtual antlrcpp::Any visitNumeric_type(XiasParser::Numeric_typeContext *context) = 0;

    virtual antlrcpp::Any visitIntegral_type(XiasParser::Integral_typeContext *context) = 0;

    virtual antlrcpp::Any visitFloating_point_type(XiasParser::Floating_point_typeContext *context) = 0;

    virtual antlrcpp::Any visitEnum_type(XiasParser::Enum_typeContext *context) = 0;

    virtual antlrcpp::Any visitReference_type(XiasParser::Reference_typeContext *context) = 0;

    virtual antlrcpp::Any visitClass_type(XiasParser::Class_typeContext *context) = 0;

    virtual antlrcpp::Any visitInterface_type(XiasParser::Interface_typeContext *context) = 0;

    virtual antlrcpp::Any visitArray_type(XiasParser::Array_typeContext *context) = 0;

    virtual antlrcpp::Any visitNon_array_type(XiasParser::Non_array_typeContext *context) = 0;

    virtual antlrcpp::Any visitRank_specifier(XiasParser::Rank_specifierContext *context) = 0;

    virtual antlrcpp::Any visitDim_separator(XiasParser::Dim_separatorContext *context) = 0;

    virtual antlrcpp::Any visitPredefined_type(XiasParser::Predefined_typeContext *context) = 0;

    virtual antlrcpp::Any visitClass_declaration(XiasParser::Class_declarationContext *context) = 0;

    virtual antlrcpp::Any visitClass_base(XiasParser::Class_baseContext *context) = 0;

    virtual antlrcpp::Any visitInterface_type_list(XiasParser::Interface_type_listContext *context) = 0;

    virtual antlrcpp::Any visitClass_body(XiasParser::Class_bodyContext *context) = 0;

    virtual antlrcpp::Any visitClass_member_declaration(XiasParser::Class_member_declarationContext *context) = 0;

    virtual antlrcpp::Any visitConstant_declaration(XiasParser::Constant_declarationContext *context) = 0;

    virtual antlrcpp::Any visitField_declaration(XiasParser::Field_declarationContext *context) = 0;

    virtual antlrcpp::Any visitVariable_declarators(XiasParser::Variable_declaratorsContext *context) = 0;

    virtual antlrcpp::Any visitVariable_declarator(XiasParser::Variable_declaratorContext *context) = 0;

    virtual antlrcpp::Any visitVariable_initializer(XiasParser::Variable_initializerContext *context) = 0;

    virtual antlrcpp::Any visitMethod_declaration(XiasParser::Method_declarationContext *context) = 0;

    virtual antlrcpp::Any visitMethod_header(XiasParser::Method_headerContext *context) = 0;

    virtual antlrcpp::Any visitReturn_type(XiasParser::Return_typeContext *context) = 0;

    virtual antlrcpp::Any visitMember_name(XiasParser::Member_nameContext *context) = 0;

    virtual antlrcpp::Any visitFormal_parameter_list(XiasParser::Formal_parameter_listContext *context) = 0;

    virtual antlrcpp::Any visitFixed_parameters(XiasParser::Fixed_parametersContext *context) = 0;

    virtual antlrcpp::Any visitFixed_parameter(XiasParser::Fixed_parameterContext *context) = 0;

    virtual antlrcpp::Any visitDefault_argument(XiasParser::Default_argumentContext *context) = 0;

    virtual antlrcpp::Any visitParameter_modifier(XiasParser::Parameter_modifierContext *context) = 0;

    virtual antlrcpp::Any visitMethod_body(XiasParser::Method_bodyContext *context) = 0;

    virtual antlrcpp::Any visitProperty_declaration(XiasParser::Property_declarationContext *context) = 0;

    virtual antlrcpp::Any visitProperty_body(XiasParser::Property_bodyContext *context) = 0;

    virtual antlrcpp::Any visitAccessor_declarations(XiasParser::Accessor_declarationsContext *context) = 0;

    virtual antlrcpp::Any visitGet_accessor_declaration(XiasParser::Get_accessor_declarationContext *context) = 0;

    virtual antlrcpp::Any visitSet_accessor_declaration(XiasParser::Set_accessor_declarationContext *context) = 0;

    virtual antlrcpp::Any visitAccessor_modifier(XiasParser::Accessor_modifierContext *context) = 0;

    virtual antlrcpp::Any visitAccessor_body(XiasParser::Accessor_bodyContext *context) = 0;

    virtual antlrcpp::Any visitProperty_initializer(XiasParser::Property_initializerContext *context) = 0;

    virtual antlrcpp::Any visitIndexer_declaration(XiasParser::Indexer_declarationContext *context) = 0;

    virtual antlrcpp::Any visitIndexer_modifier(XiasParser::Indexer_modifierContext *context) = 0;

    virtual antlrcpp::Any visitIndexer_declarator(XiasParser::Indexer_declaratorContext *context) = 0;

    virtual antlrcpp::Any visitIndexer_body(XiasParser::Indexer_bodyContext *context) = 0;

    virtual antlrcpp::Any visitOperator_declaration(XiasParser::Operator_declarationContext *context) = 0;

    virtual antlrcpp::Any visitOperator_modifier(XiasParser::Operator_modifierContext *context) = 0;

    virtual antlrcpp::Any visitOperator_declarator(XiasParser::Operator_declaratorContext *context) = 0;

    virtual antlrcpp::Any visitUnary_operator_declarator(XiasParser::Unary_operator_declaratorContext *context) = 0;

    virtual antlrcpp::Any visitOverloadable_unary_operator(XiasParser::Overloadable_unary_operatorContext *context) = 0;

    virtual antlrcpp::Any visitBinary_operator_declarator(XiasParser::Binary_operator_declaratorContext *context) = 0;

    virtual antlrcpp::Any visitOverloadable_binary_operator(XiasParser::Overloadable_binary_operatorContext *context) = 0;

    virtual antlrcpp::Any visitConversion_operator_declarator(XiasParser::Conversion_operator_declaratorContext *context) = 0;

    virtual antlrcpp::Any visitOperator_body(XiasParser::Operator_bodyContext *context) = 0;

    virtual antlrcpp::Any visitConstructor_declaration(XiasParser::Constructor_declarationContext *context) = 0;

    virtual antlrcpp::Any visitConstructor_modifier(XiasParser::Constructor_modifierContext *context) = 0;

    virtual antlrcpp::Any visitConstructor_declarator(XiasParser::Constructor_declaratorContext *context) = 0;

    virtual antlrcpp::Any visitConstructor_initializer(XiasParser::Constructor_initializerContext *context) = 0;

    virtual antlrcpp::Any visitConstructor_body(XiasParser::Constructor_bodyContext *context) = 0;

    virtual antlrcpp::Any visitStatic_constructor_declaration(XiasParser::Static_constructor_declarationContext *context) = 0;

    virtual antlrcpp::Any visitStatic_constructor_modifiers(XiasParser::Static_constructor_modifiersContext *context) = 0;

    virtual antlrcpp::Any visitStatic_constructor_body(XiasParser::Static_constructor_bodyContext *context) = 0;

    virtual antlrcpp::Any visitDestructor_declaration(XiasParser::Destructor_declarationContext *context) = 0;

    virtual antlrcpp::Any visitDestructor_body(XiasParser::Destructor_bodyContext *context) = 0;

    virtual antlrcpp::Any visitInterface_declaration(XiasParser::Interface_declarationContext *context) = 0;

    virtual antlrcpp::Any visitVariant_type_parameter_list(XiasParser::Variant_type_parameter_listContext *context) = 0;

    virtual antlrcpp::Any visitVariant_type_parameters(XiasParser::Variant_type_parametersContext *context) = 0;

    virtual antlrcpp::Any visitVariance_annotation(XiasParser::Variance_annotationContext *context) = 0;

    virtual antlrcpp::Any visitInterface_base(XiasParser::Interface_baseContext *context) = 0;

    virtual antlrcpp::Any visitInterface_body(XiasParser::Interface_bodyContext *context) = 0;

    virtual antlrcpp::Any visitInterface_member_declaration(XiasParser::Interface_member_declarationContext *context) = 0;

    virtual antlrcpp::Any visitInterface_method_declaration(XiasParser::Interface_method_declarationContext *context) = 0;

    virtual antlrcpp::Any visitInterface_property_declaration(XiasParser::Interface_property_declarationContext *context) = 0;

    virtual antlrcpp::Any visitInterface_accessors(XiasParser::Interface_accessorsContext *context) = 0;

    virtual antlrcpp::Any visitInterface_indexer_declaration(XiasParser::Interface_indexer_declarationContext *context) = 0;

    virtual antlrcpp::Any visitBlock(XiasParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitStatement_list(XiasParser::Statement_listContext *context) = 0;

    virtual antlrcpp::Any visitStatement(XiasParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitLabeled_statement(XiasParser::Labeled_statementContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration_statement(XiasParser::Declaration_statementContext *context) = 0;

    virtual antlrcpp::Any visitLocal_variable_declaration(XiasParser::Local_variable_declarationContext *context) = 0;

    virtual antlrcpp::Any visitLocal_variable_type(XiasParser::Local_variable_typeContext *context) = 0;

    virtual antlrcpp::Any visitLocal_variable_declarators(XiasParser::Local_variable_declaratorsContext *context) = 0;

    virtual antlrcpp::Any visitLocal_variable_declarator(XiasParser::Local_variable_declaratorContext *context) = 0;

    virtual antlrcpp::Any visitLocal_variable_initializer(XiasParser::Local_variable_initializerContext *context) = 0;

    virtual antlrcpp::Any visitLocal_constant_declaration(XiasParser::Local_constant_declarationContext *context) = 0;

    virtual antlrcpp::Any visitConstant_declarators(XiasParser::Constant_declaratorsContext *context) = 0;

    virtual antlrcpp::Any visitConstant_declarator(XiasParser::Constant_declaratorContext *context) = 0;

    virtual antlrcpp::Any visitEmbedded_statement(XiasParser::Embedded_statementContext *context) = 0;

    virtual antlrcpp::Any visitEmpty_statement(XiasParser::Empty_statementContext *context) = 0;

    virtual antlrcpp::Any visitExpression_statement(XiasParser::Expression_statementContext *context) = 0;

    virtual antlrcpp::Any visitStatement_expression(XiasParser::Statement_expressionContext *context) = 0;

    virtual antlrcpp::Any visitSelection_statement(XiasParser::Selection_statementContext *context) = 0;

    virtual antlrcpp::Any visitIf_statement(XiasParser::If_statementContext *context) = 0;

    virtual antlrcpp::Any visitSwitch_statement(XiasParser::Switch_statementContext *context) = 0;

    virtual antlrcpp::Any visitSwitch_block(XiasParser::Switch_blockContext *context) = 0;

    virtual antlrcpp::Any visitSwitch_section(XiasParser::Switch_sectionContext *context) = 0;

    virtual antlrcpp::Any visitSwitch_label(XiasParser::Switch_labelContext *context) = 0;

    virtual antlrcpp::Any visitIteration_statement(XiasParser::Iteration_statementContext *context) = 0;

    virtual antlrcpp::Any visitWhile_statement(XiasParser::While_statementContext *context) = 0;

    virtual antlrcpp::Any visitDo_statement(XiasParser::Do_statementContext *context) = 0;

    virtual antlrcpp::Any visitFor_statement(XiasParser::For_statementContext *context) = 0;

    virtual antlrcpp::Any visitFor_initializer(XiasParser::For_initializerContext *context) = 0;

    virtual antlrcpp::Any visitFor_condition(XiasParser::For_conditionContext *context) = 0;

    virtual antlrcpp::Any visitFor_iterator(XiasParser::For_iteratorContext *context) = 0;

    virtual antlrcpp::Any visitStatement_expression_list(XiasParser::Statement_expression_listContext *context) = 0;

    virtual antlrcpp::Any visitForeach_statement(XiasParser::Foreach_statementContext *context) = 0;

    virtual antlrcpp::Any visitJump_statement(XiasParser::Jump_statementContext *context) = 0;

    virtual antlrcpp::Any visitBreak_statement(XiasParser::Break_statementContext *context) = 0;

    virtual antlrcpp::Any visitContinue_statement(XiasParser::Continue_statementContext *context) = 0;

    virtual antlrcpp::Any visitGoto_statement(XiasParser::Goto_statementContext *context) = 0;

    virtual antlrcpp::Any visitReturn_statement(XiasParser::Return_statementContext *context) = 0;

    virtual antlrcpp::Any visitThrow_statement(XiasParser::Throw_statementContext *context) = 0;

    virtual antlrcpp::Any visitTry_statement(XiasParser::Try_statementContext *context) = 0;

    virtual antlrcpp::Any visitCatch_clause(XiasParser::Catch_clauseContext *context) = 0;

    virtual antlrcpp::Any visitException_specifier(XiasParser::Exception_specifierContext *context) = 0;

    virtual antlrcpp::Any visitException_filter(XiasParser::Exception_filterContext *context) = 0;

    virtual antlrcpp::Any visitFinally_clause(XiasParser::Finally_clauseContext *context) = 0;

    virtual antlrcpp::Any visitArgument_list(XiasParser::Argument_listContext *context) = 0;

    virtual antlrcpp::Any visitPrimary_expression(XiasParser::Primary_expressionContext *context) = 0;

    virtual antlrcpp::Any visitPrimary_no_array_creation_expression_base(XiasParser::Primary_no_array_creation_expression_baseContext *context) = 0;

    virtual antlrcpp::Any visitPrimary_expression_start(XiasParser::Primary_expression_startContext *context) = 0;

    virtual antlrcpp::Any visitPrimary_no_array_creation_expression(XiasParser::Primary_no_array_creation_expressionContext *context) = 0;

    virtual antlrcpp::Any visitSimple_name(XiasParser::Simple_nameContext *context) = 0;

    virtual antlrcpp::Any visitParenthesized_expression(XiasParser::Parenthesized_expressionContext *context) = 0;

    virtual antlrcpp::Any visitMember_access(XiasParser::Member_accessContext *context) = 0;

    virtual antlrcpp::Any visitInvocation_expression(XiasParser::Invocation_expressionContext *context) = 0;

    virtual antlrcpp::Any visitElement_access(XiasParser::Element_accessContext *context) = 0;

    virtual antlrcpp::Any visitThis_access(XiasParser::This_accessContext *context) = 0;

    virtual antlrcpp::Any visitBase_access(XiasParser::Base_accessContext *context) = 0;

    virtual antlrcpp::Any visitPost_increment_expression(XiasParser::Post_increment_expressionContext *context) = 0;

    virtual antlrcpp::Any visitPost_decrement_expression(XiasParser::Post_decrement_expressionContext *context) = 0;

    virtual antlrcpp::Any visitObject_creation_expression(XiasParser::Object_creation_expressionContext *context) = 0;

    virtual antlrcpp::Any visitObject_or_collection_initializer(XiasParser::Object_or_collection_initializerContext *context) = 0;

    virtual antlrcpp::Any visitObject_initializer(XiasParser::Object_initializerContext *context) = 0;

    virtual antlrcpp::Any visitMember_initializer_list(XiasParser::Member_initializer_listContext *context) = 0;

    virtual antlrcpp::Any visitMember_initializer(XiasParser::Member_initializerContext *context) = 0;

    virtual antlrcpp::Any visitInitializer_value(XiasParser::Initializer_valueContext *context) = 0;

    virtual antlrcpp::Any visitCollection_initializer(XiasParser::Collection_initializerContext *context) = 0;

    virtual antlrcpp::Any visitElement_initializer_list(XiasParser::Element_initializer_listContext *context) = 0;

    virtual antlrcpp::Any visitElement_initializer(XiasParser::Element_initializerContext *context) = 0;

    virtual antlrcpp::Any visitExpression_list(XiasParser::Expression_listContext *context) = 0;

    virtual antlrcpp::Any visitTypeof_expression(XiasParser::Typeof_expressionContext *context) = 0;

    virtual antlrcpp::Any visitUnbound_type_name(XiasParser::Unbound_type_nameContext *context) = 0;

    virtual antlrcpp::Any visitGeneric_dimension_specifier(XiasParser::Generic_dimension_specifierContext *context) = 0;

    virtual antlrcpp::Any visitDefault_value_expression(XiasParser::Default_value_expressionContext *context) = 0;

    virtual antlrcpp::Any visitArrayCreationWithExpressionSize(XiasParser::ArrayCreationWithExpressionSizeContext *context) = 0;

    virtual antlrcpp::Any visitArrayCreationWithInitializer(XiasParser::ArrayCreationWithInitializerContext *context) = 0;

    virtual antlrcpp::Any visitUnary_expression(XiasParser::Unary_expressionContext *context) = 0;

    virtual antlrcpp::Any visitUnary_plus_expression(XiasParser::Unary_plus_expressionContext *context) = 0;

    virtual antlrcpp::Any visitUnary_minus_expression(XiasParser::Unary_minus_expressionContext *context) = 0;

    virtual antlrcpp::Any visitUnary_bang_expression(XiasParser::Unary_bang_expressionContext *context) = 0;

    virtual antlrcpp::Any visitUnary_tilde_expression(XiasParser::Unary_tilde_expressionContext *context) = 0;

    virtual antlrcpp::Any visitPre_increment_expression(XiasParser::Pre_increment_expressionContext *context) = 0;

    virtual antlrcpp::Any visitPre_decrement_expression(XiasParser::Pre_decrement_expressionContext *context) = 0;

    virtual antlrcpp::Any visitCast_expression(XiasParser::Cast_expressionContext *context) = 0;

    virtual antlrcpp::Any visitMultiplicative_expression(XiasParser::Multiplicative_expressionContext *context) = 0;

    virtual antlrcpp::Any visitAdditive_expression(XiasParser::Additive_expressionContext *context) = 0;

    virtual antlrcpp::Any visitShift_expression(XiasParser::Shift_expressionContext *context) = 0;

    virtual antlrcpp::Any visitRelational_expression(XiasParser::Relational_expressionContext *context) = 0;

    virtual antlrcpp::Any visitEquality_expression(XiasParser::Equality_expressionContext *context) = 0;

    virtual antlrcpp::Any visitAnd_expression(XiasParser::And_expressionContext *context) = 0;

    virtual antlrcpp::Any visitExclusive_or_expression(XiasParser::Exclusive_or_expressionContext *context) = 0;

    virtual antlrcpp::Any visitInclusive_or_expression(XiasParser::Inclusive_or_expressionContext *context) = 0;

    virtual antlrcpp::Any visitConditional_and_expression(XiasParser::Conditional_and_expressionContext *context) = 0;

    virtual antlrcpp::Any visitConditional_or_expression(XiasParser::Conditional_or_expressionContext *context) = 0;

    virtual antlrcpp::Any visitNull_coalescing_expression(XiasParser::Null_coalescing_expressionContext *context) = 0;

    virtual antlrcpp::Any visitConditional_expression(XiasParser::Conditional_expressionContext *context) = 0;

    virtual antlrcpp::Any visitAssignment(XiasParser::AssignmentContext *context) = 0;

    virtual antlrcpp::Any visitAssignment_operator(XiasParser::Assignment_operatorContext *context) = 0;

    virtual antlrcpp::Any visitExpression(XiasParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitNon_assignment_expression(XiasParser::Non_assignment_expressionContext *context) = 0;

    virtual antlrcpp::Any visitConstant_expression(XiasParser::Constant_expressionContext *context) = 0;

    virtual antlrcpp::Any visitBoolean_expression(XiasParser::Boolean_expressionContext *context) = 0;

    virtual antlrcpp::Any visitLiteral(XiasParser::LiteralContext *context) = 0;

    virtual antlrcpp::Any visitBoolean_literal(XiasParser::Boolean_literalContext *context) = 0;

    virtual antlrcpp::Any visitString_literal(XiasParser::String_literalContext *context) = 0;

    virtual antlrcpp::Any visitArray_initializer(XiasParser::Array_initializerContext *context) = 0;

    virtual antlrcpp::Any visitVariable_initializer_list(XiasParser::Variable_initializer_listContext *context) = 0;

    virtual antlrcpp::Any visitRight_shift(XiasParser::Right_shiftContext *context) = 0;

    virtual antlrcpp::Any visitRight_shift_assignment(XiasParser::Right_shift_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier(XiasParser::IdentifierContext *context) = 0;

    virtual antlrcpp::Any visitAll_modifier(XiasParser::All_modifierContext *context) = 0;


};

