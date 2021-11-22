
// Generated from ..\antlr\XiasParser.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  XiasParser : public antlr4::Parser {
public:
  enum {
    WHITESPACES = 1, SINGLE_LINE_DOC_COMMENT = 2, DELIMITED_DOC_COMMENT = 3, 
    SINGLE_LINE_COMMENT = 4, DELIMITED_COMMENT = 5, ABSTRACT = 6, AS = 7, 
    IS = 8, BASE = 9, BOOL = 10, BREAK = 11, CASE = 12, CATCH = 13, CHAR = 14, 
    CLASS = 15, CONST = 16, CONTINUE = 17, DEFAULT = 18, DO = 19, DOUBLE = 20, 
    ELSE = 21, ENUM = 22, EXTERN = 23, EXPLICIT = 24, FALSE = 25, FINALLY = 26, 
    FLOAT = 27, FOR = 28, FOREACH = 29, GET = 30, GOTO = 31, IF = 32, IMPLICIT = 33, 
    IN = 34, INT = 35, INTERFACE = 36, INTERNAL = 37, NAMEOF = 38, NAMESPACE = 39, 
    NEW = 40, NULL_ = 41, OBJECT = 42, OPERATOR = 43, OUT = 44, OVERRIDE = 45, 
    PARAMS = 46, PRIVATE = 47, PROTECTED = 48, PUBLIC = 49, READONLY = 50, 
    REF = 51, RETURN = 52, SEALED = 53, SET = 54, SIZEOF = 55, STATIC = 56, 
    STRING = 57, SWITCH = 58, THIS = 59, THROW = 60, TRUE = 61, TRY = 62, 
    TYPEOF = 63, UINT = 64, USING = 65, VAR = 66, VIRTUAL = 67, VOID = 68, 
    WHEN = 69, WHERE = 70, WHILE = 71, IDENTIFIER = 72, LITERAL_ACCESS = 73, 
    INTEGER_LITERAL = 74, UNSIGNED_LITERAL = 75, HEX_INTEGER_LITERAL = 76, 
    FLOAT_LITERAL = 77, DOUBLE_LITERAL = 78, CHARACTER_LITERAL = 79, REGULAR_STRING = 80, 
    VERBATIUM_STRING = 81, OPEN_BRACE = 82, CLOSE_BRACE = 83, OPEN_BRACKET = 84, 
    CLOSE_BRACKET = 85, OPEN_PARENS = 86, CLOSE_PARENS = 87, DOT = 88, COMMA = 89, 
    COLON = 90, SEMICOLON = 91, PLUS = 92, MINUS = 93, STAR = 94, DIV = 95, 
    PERCENT = 96, AMP = 97, BITWISE_OR = 98, CARET = 99, BANG = 100, TILDE = 101, 
    ASSIGNMENT = 102, LT = 103, GT = 104, INTERR = 105, DOUBLE_COLON = 106, 
    OP_COALESCING = 107, OP_INC = 108, OP_DEC = 109, OP_AND = 110, OP_OR = 111, 
    OP_PTR = 112, OP_EQ = 113, OP_NE = 114, OP_LE = 115, OP_GE = 116, OP_ADD_ASSIGNMENT = 117, 
    OP_SUB_ASSIGNMENT = 118, OP_MULT_ASSIGNMENT = 119, OP_DIV_ASSIGNMENT = 120, 
    OP_MOD_ASSIGNMENT = 121, OP_AND_ASSIGNMENT = 122, OP_OR_ASSIGNMENT = 123, 
    OP_XOR_ASSIGNMENT = 124, OP_LEFT_SHIFT = 125, OP_LEFT_SHIFT_ASSIGNMENT = 126, 
    OP_COALESCING_ASSIGNMENT = 127, QUOTE = 128, DOUBLE_QUOTE = 129, BACK_SLASH = 130, 
    DOUBLE_BACK_SLASH = 131, SHARP = 132
  };

  enum {
    RuleCompilation_unit = 0, RuleUsing_directive = 1, RuleNamespace_member_declaration = 2, 
    RuleNamespace_declaration = 3, RuleQualified_identifier = 4, RuleNamespace_body = 5, 
    RuleQualified_alias_member = 6, RuleType_declaration = 7, RuleType_parameter_list = 8, 
    RuleType_argument_list = 9, RuleType_parameter = 10, RuleType_parameter_constraints_clause = 11, 
    RuleType_parameter_constraints = 12, RuleConstructor_constraint = 13, 
    RuleBasic_modifier = 14, RuleType_ = 15, RuleNamespace_name = 16, RuleType_name = 17, 
    RuleNamespace_or_type_name = 18, RuleValue_type = 19, RuleStruct_type = 20, 
    RuleBase_type = 21, RuleSimple_type = 22, RuleNumeric_type = 23, RuleIntegral_type = 24, 
    RuleFloating_point_type = 25, RuleEnum_type = 26, RuleReference_type = 27, 
    RuleClass_type = 28, RuleInterface_type = 29, RuleArray_type = 30, RuleNon_array_type = 31, 
    RuleRank_specifier = 32, RuleDim_separator = 33, RulePredefined_type = 34, 
    RuleClass_declaration = 35, RuleClass_base = 36, RuleInterface_type_list = 37, 
    RuleClass_body = 38, RuleClass_member_declaration = 39, RuleConstant_declaration = 40, 
    RuleField_declaration = 41, RuleVariable_declarators = 42, RuleVariable_declarator = 43, 
    RuleVariable_initializer = 44, RuleMethod_declaration = 45, RuleMethod_header = 46, 
    RuleReturn_type = 47, RuleMember_name = 48, RuleFormal_parameter_list = 49, 
    RuleFixed_parameters = 50, RuleFixed_parameter = 51, RuleDefault_argument = 52, 
    RuleParameter_modifier = 53, RuleMethod_body = 54, RuleProperty_declaration = 55, 
    RuleProperty_body = 56, RuleAccessor_declarations = 57, RuleGet_accessor_declaration = 58, 
    RuleSet_accessor_declaration = 59, RuleAccessor_modifier = 60, RuleAccessor_body = 61, 
    RuleProperty_initializer = 62, RuleIndexer_declaration = 63, RuleIndexer_modifier = 64, 
    RuleIndexer_declarator = 65, RuleIndexer_body = 66, RuleOperator_declaration = 67, 
    RuleOperator_modifier = 68, RuleOperator_declarator = 69, RuleUnary_operator_declarator = 70, 
    RuleOverloadable_unary_operator = 71, RuleBinary_operator_declarator = 72, 
    RuleOverloadable_binary_operator = 73, RuleConversion_operator_declarator = 74, 
    RuleOperator_body = 75, RuleConstructor_declaration = 76, RuleConstructor_modifier = 77, 
    RuleConstructor_declarator = 78, RuleConstructor_initializer = 79, RuleConstructor_body = 80, 
    RuleStatic_constructor_declaration = 81, RuleStatic_constructor_modifiers = 82, 
    RuleStatic_constructor_body = 83, RuleDestructor_declaration = 84, RuleDestructor_body = 85, 
    RuleInterface_declaration = 86, RuleVariant_type_parameter_list = 87, 
    RuleVariant_type_parameters = 88, RuleVariance_annotation = 89, RuleInterface_base = 90, 
    RuleInterface_body = 91, RuleInterface_member_declaration = 92, RuleInterface_method_declaration = 93, 
    RuleInterface_property_declaration = 94, RuleInterface_accessors = 95, 
    RuleInterface_indexer_declaration = 96, RuleBlock = 97, RuleStatement_list = 98, 
    RuleStatement = 99, RuleLabeled_statement = 100, RuleDeclaration_statement = 101, 
    RuleLocal_variable_declaration = 102, RuleLocal_variable_type = 103, 
    RuleLocal_variable_declarators = 104, RuleLocal_variable_declarator = 105, 
    RuleLocal_variable_initializer = 106, RuleLocal_constant_declaration = 107, 
    RuleConstant_declarators = 108, RuleConstant_declarator = 109, RuleEmbedded_statement = 110, 
    RuleEmpty_statement = 111, RuleExpression_statement = 112, RuleStatement_expression = 113, 
    RuleSelection_statement = 114, RuleIf_statement = 115, RuleSwitch_statement = 116, 
    RuleSwitch_block = 117, RuleSwitch_section = 118, RuleSwitch_label = 119, 
    RuleIteration_statement = 120, RuleWhile_statement = 121, RuleDo_statement = 122, 
    RuleFor_statement = 123, RuleFor_initializer = 124, RuleFor_condition = 125, 
    RuleFor_iterator = 126, RuleStatement_expression_list = 127, RuleForeach_statement = 128, 
    RuleJump_statement = 129, RuleBreak_statement = 130, RuleContinue_statement = 131, 
    RuleGoto_statement = 132, RuleReturn_statement = 133, RuleThrow_statement = 134, 
    RuleTry_statement = 135, RuleCatch_clause = 136, RuleException_specifier = 137, 
    RuleException_filter = 138, RuleFinally_clause = 139, RuleArgument_list = 140, 
    RulePrimary_expression = 141, RulePrimary_no_array_creation_expression_base = 142, 
    RulePrimary_expression_start = 143, RulePrimary_no_array_creation_expression = 144, 
    RuleSimple_name = 145, RuleParenthesized_expression = 146, RuleMember_access = 147, 
    RuleInvocation_expression = 148, RuleElement_access = 149, RuleThis_access = 150, 
    RuleBase_access = 151, RulePost_increment_expression = 152, RulePost_decrement_expression = 153, 
    RuleObject_creation_expression = 154, RuleObject_or_collection_initializer = 155, 
    RuleObject_initializer = 156, RuleMember_initializer_list = 157, RuleMember_initializer = 158, 
    RuleInitializer_value = 159, RuleCollection_initializer = 160, RuleElement_initializer_list = 161, 
    RuleElement_initializer = 162, RuleExpression_list = 163, RuleTypeof_expression = 164, 
    RuleUnbound_type_name = 165, RuleGeneric_dimension_specifier = 166, 
    RuleDefault_value_expression = 167, RuleArray_creation_expression = 168, 
    RuleUnary_expression = 169, RuleUnary_plus_expression = 170, RuleUnary_minus_expression = 171, 
    RuleUnary_bang_expression = 172, RuleUnary_tilde_expression = 173, RulePre_increment_expression = 174, 
    RulePre_decrement_expression = 175, RuleCast_expression = 176, RuleMultiplicative_expression = 177, 
    RuleAdditive_expression = 178, RuleShift_expression = 179, RuleRelational_expression = 180, 
    RuleEquality_expression = 181, RuleAnd_expression = 182, RuleExclusive_or_expression = 183, 
    RuleInclusive_or_expression = 184, RuleConditional_and_expression = 185, 
    RuleConditional_or_expression = 186, RuleNull_coalescing_expression = 187, 
    RuleConditional_expression = 188, RuleAssignment = 189, RuleAssignment_operator = 190, 
    RuleExpression = 191, RuleNon_assignment_expression = 192, RuleConstant_expression = 193, 
    RuleBoolean_expression = 194, RuleLiteral = 195, RuleBoolean_literal = 196, 
    RuleString_literal = 197, RuleArray_initializer = 198, RuleVariable_initializer_list = 199, 
    RuleRight_shift = 200, RuleRight_shift_assignment = 201, RuleIdentifier = 202, 
    RuleAll_modifier = 203
  };

  explicit XiasParser(antlr4::TokenStream *input);
  ~XiasParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class Compilation_unitContext;
  class Using_directiveContext;
  class Namespace_member_declarationContext;
  class Namespace_declarationContext;
  class Qualified_identifierContext;
  class Namespace_bodyContext;
  class Qualified_alias_memberContext;
  class Type_declarationContext;
  class Type_parameter_listContext;
  class Type_argument_listContext;
  class Type_parameterContext;
  class Type_parameter_constraints_clauseContext;
  class Type_parameter_constraintsContext;
  class Constructor_constraintContext;
  class Basic_modifierContext;
  class Type_Context;
  class Namespace_nameContext;
  class Type_nameContext;
  class Namespace_or_type_nameContext;
  class Value_typeContext;
  class Struct_typeContext;
  class Base_typeContext;
  class Simple_typeContext;
  class Numeric_typeContext;
  class Integral_typeContext;
  class Floating_point_typeContext;
  class Enum_typeContext;
  class Reference_typeContext;
  class Class_typeContext;
  class Interface_typeContext;
  class Array_typeContext;
  class Non_array_typeContext;
  class Rank_specifierContext;
  class Dim_separatorContext;
  class Predefined_typeContext;
  class Class_declarationContext;
  class Class_baseContext;
  class Interface_type_listContext;
  class Class_bodyContext;
  class Class_member_declarationContext;
  class Constant_declarationContext;
  class Field_declarationContext;
  class Variable_declaratorsContext;
  class Variable_declaratorContext;
  class Variable_initializerContext;
  class Method_declarationContext;
  class Method_headerContext;
  class Return_typeContext;
  class Member_nameContext;
  class Formal_parameter_listContext;
  class Fixed_parametersContext;
  class Fixed_parameterContext;
  class Default_argumentContext;
  class Parameter_modifierContext;
  class Method_bodyContext;
  class Property_declarationContext;
  class Property_bodyContext;
  class Accessor_declarationsContext;
  class Get_accessor_declarationContext;
  class Set_accessor_declarationContext;
  class Accessor_modifierContext;
  class Accessor_bodyContext;
  class Property_initializerContext;
  class Indexer_declarationContext;
  class Indexer_modifierContext;
  class Indexer_declaratorContext;
  class Indexer_bodyContext;
  class Operator_declarationContext;
  class Operator_modifierContext;
  class Operator_declaratorContext;
  class Unary_operator_declaratorContext;
  class Overloadable_unary_operatorContext;
  class Binary_operator_declaratorContext;
  class Overloadable_binary_operatorContext;
  class Conversion_operator_declaratorContext;
  class Operator_bodyContext;
  class Constructor_declarationContext;
  class Constructor_modifierContext;
  class Constructor_declaratorContext;
  class Constructor_initializerContext;
  class Constructor_bodyContext;
  class Static_constructor_declarationContext;
  class Static_constructor_modifiersContext;
  class Static_constructor_bodyContext;
  class Destructor_declarationContext;
  class Destructor_bodyContext;
  class Interface_declarationContext;
  class Variant_type_parameter_listContext;
  class Variant_type_parametersContext;
  class Variance_annotationContext;
  class Interface_baseContext;
  class Interface_bodyContext;
  class Interface_member_declarationContext;
  class Interface_method_declarationContext;
  class Interface_property_declarationContext;
  class Interface_accessorsContext;
  class Interface_indexer_declarationContext;
  class BlockContext;
  class Statement_listContext;
  class StatementContext;
  class Labeled_statementContext;
  class Declaration_statementContext;
  class Local_variable_declarationContext;
  class Local_variable_typeContext;
  class Local_variable_declaratorsContext;
  class Local_variable_declaratorContext;
  class Local_variable_initializerContext;
  class Local_constant_declarationContext;
  class Constant_declaratorsContext;
  class Constant_declaratorContext;
  class Embedded_statementContext;
  class Empty_statementContext;
  class Expression_statementContext;
  class Statement_expressionContext;
  class Selection_statementContext;
  class If_statementContext;
  class Switch_statementContext;
  class Switch_blockContext;
  class Switch_sectionContext;
  class Switch_labelContext;
  class Iteration_statementContext;
  class While_statementContext;
  class Do_statementContext;
  class For_statementContext;
  class For_initializerContext;
  class For_conditionContext;
  class For_iteratorContext;
  class Statement_expression_listContext;
  class Foreach_statementContext;
  class Jump_statementContext;
  class Break_statementContext;
  class Continue_statementContext;
  class Goto_statementContext;
  class Return_statementContext;
  class Throw_statementContext;
  class Try_statementContext;
  class Catch_clauseContext;
  class Exception_specifierContext;
  class Exception_filterContext;
  class Finally_clauseContext;
  class Argument_listContext;
  class Primary_expressionContext;
  class Primary_no_array_creation_expression_baseContext;
  class Primary_expression_startContext;
  class Primary_no_array_creation_expressionContext;
  class Simple_nameContext;
  class Parenthesized_expressionContext;
  class Member_accessContext;
  class Invocation_expressionContext;
  class Element_accessContext;
  class This_accessContext;
  class Base_accessContext;
  class Post_increment_expressionContext;
  class Post_decrement_expressionContext;
  class Object_creation_expressionContext;
  class Object_or_collection_initializerContext;
  class Object_initializerContext;
  class Member_initializer_listContext;
  class Member_initializerContext;
  class Initializer_valueContext;
  class Collection_initializerContext;
  class Element_initializer_listContext;
  class Element_initializerContext;
  class Expression_listContext;
  class Typeof_expressionContext;
  class Unbound_type_nameContext;
  class Generic_dimension_specifierContext;
  class Default_value_expressionContext;
  class Array_creation_expressionContext;
  class Unary_expressionContext;
  class Unary_plus_expressionContext;
  class Unary_minus_expressionContext;
  class Unary_bang_expressionContext;
  class Unary_tilde_expressionContext;
  class Pre_increment_expressionContext;
  class Pre_decrement_expressionContext;
  class Cast_expressionContext;
  class Multiplicative_expressionContext;
  class Additive_expressionContext;
  class Shift_expressionContext;
  class Relational_expressionContext;
  class Equality_expressionContext;
  class And_expressionContext;
  class Exclusive_or_expressionContext;
  class Inclusive_or_expressionContext;
  class Conditional_and_expressionContext;
  class Conditional_or_expressionContext;
  class Null_coalescing_expressionContext;
  class Conditional_expressionContext;
  class AssignmentContext;
  class Assignment_operatorContext;
  class ExpressionContext;
  class Non_assignment_expressionContext;
  class Constant_expressionContext;
  class Boolean_expressionContext;
  class LiteralContext;
  class Boolean_literalContext;
  class String_literalContext;
  class Array_initializerContext;
  class Variable_initializer_listContext;
  class Right_shiftContext;
  class Right_shift_assignmentContext;
  class IdentifierContext;
  class All_modifierContext; 

  class  Compilation_unitContext : public antlr4::RuleContextWithAltNum {
  public:
    Compilation_unitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<Using_directiveContext *> using_directive();
    Using_directiveContext* using_directive(size_t i);
    std::vector<Namespace_member_declarationContext *> namespace_member_declaration();
    Namespace_member_declarationContext* namespace_member_declaration(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Compilation_unitContext* compilation_unit();

  class  Using_directiveContext : public antlr4::RuleContextWithAltNum {
  public:
    Using_directiveContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Using_directiveContext() = default;
    void copyFrom(Using_directiveContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  UsingAliasDirectiveContext : public Using_directiveContext {
  public:
    UsingAliasDirectiveContext(Using_directiveContext *ctx);

    antlr4::tree::TerminalNode *USING();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *ASSIGNMENT();
    Namespace_or_type_nameContext *namespace_or_type_name();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UsingNamespaceDirectiveContext : public Using_directiveContext {
  public:
    UsingNamespaceDirectiveContext(Using_directiveContext *ctx);

    antlr4::tree::TerminalNode *USING();
    Namespace_or_type_nameContext *namespace_or_type_name();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UsingStaticDirectiveContext : public Using_directiveContext {
  public:
    UsingStaticDirectiveContext(Using_directiveContext *ctx);

    antlr4::tree::TerminalNode *USING();
    antlr4::tree::TerminalNode *STATIC();
    Namespace_or_type_nameContext *namespace_or_type_name();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Using_directiveContext* using_directive();

  class  Namespace_member_declarationContext : public antlr4::RuleContextWithAltNum {
  public:
    Namespace_member_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Namespace_declarationContext *namespace_declaration();
    Type_declarationContext *type_declaration();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Namespace_member_declarationContext* namespace_member_declaration();

  class  Namespace_declarationContext : public antlr4::RuleContextWithAltNum {
  public:
    XiasParser::Qualified_identifierContext *qi = nullptr;
    Namespace_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAMESPACE();
    Namespace_bodyContext *namespace_body();
    Qualified_identifierContext *qualified_identifier();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Namespace_declarationContext* namespace_declaration();

  class  Qualified_identifierContext : public antlr4::RuleContextWithAltNum {
  public:
    Qualified_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Qualified_identifierContext* qualified_identifier();

  class  Namespace_bodyContext : public antlr4::RuleContextWithAltNum {
  public:
    Namespace_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPEN_BRACE();
    antlr4::tree::TerminalNode *CLOSE_BRACE();
    std::vector<Using_directiveContext *> using_directive();
    Using_directiveContext* using_directive(size_t i);
    std::vector<Namespace_member_declarationContext *> namespace_member_declaration();
    Namespace_member_declarationContext* namespace_member_declaration(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Namespace_bodyContext* namespace_body();

  class  Qualified_alias_memberContext : public antlr4::RuleContextWithAltNum {
  public:
    Qualified_alias_memberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);
    antlr4::tree::TerminalNode *DOUBLE_COLON();
    Type_argument_listContext *type_argument_list();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Qualified_alias_memberContext* qualified_alias_member();

  class  Type_declarationContext : public antlr4::RuleContextWithAltNum {
  public:
    Type_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Class_declarationContext *class_declaration();
    Interface_declarationContext *interface_declaration();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_declarationContext* type_declaration();

  class  Type_parameter_listContext : public antlr4::RuleContextWithAltNum {
  public:
    Type_parameter_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LT();
    std::vector<Type_parameterContext *> type_parameter();
    Type_parameterContext* type_parameter(size_t i);
    antlr4::tree::TerminalNode *GT();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_parameter_listContext* type_parameter_list();

  class  Type_argument_listContext : public antlr4::RuleContextWithAltNum {
  public:
    Type_argument_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LT();
    std::vector<Type_Context *> type_();
    Type_Context* type_(size_t i);
    antlr4::tree::TerminalNode *GT();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_argument_listContext* type_argument_list();

  class  Type_parameterContext : public antlr4::RuleContextWithAltNum {
  public:
    Type_parameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_parameterContext* type_parameter();

  class  Type_parameter_constraints_clauseContext : public antlr4::RuleContextWithAltNum {
  public:
    Type_parameter_constraints_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHERE();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *COLON();
    Type_parameter_constraintsContext *type_parameter_constraints();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_parameter_constraints_clauseContext* type_parameter_constraints_clause();

  class  Type_parameter_constraintsContext : public antlr4::RuleContextWithAltNum {
  public:
    Type_parameter_constraintsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Class_typeContext *class_type();
    Constructor_constraintContext *constructor_constraint();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_parameter_constraintsContext* type_parameter_constraints();

  class  Constructor_constraintContext : public antlr4::RuleContextWithAltNum {
  public:
    Constructor_constraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NEW();
    antlr4::tree::TerminalNode *OPEN_PARENS();
    antlr4::tree::TerminalNode *CLOSE_PARENS();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constructor_constraintContext* constructor_constraint();

  class  Basic_modifierContext : public antlr4::RuleContextWithAltNum {
  public:
    Basic_modifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NEW();
    antlr4::tree::TerminalNode *PUBLIC();
    antlr4::tree::TerminalNode *PROTECTED();
    antlr4::tree::TerminalNode *INTERNAL();
    antlr4::tree::TerminalNode *PRIVATE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Basic_modifierContext* basic_modifier();

  class  Type_Context : public antlr4::RuleContextWithAltNum {
  public:
    Type_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Value_typeContext *value_type();
    Reference_typeContext *reference_type();
    Type_parameterContext *type_parameter();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_Context* type_();

  class  Namespace_nameContext : public antlr4::RuleContextWithAltNum {
  public:
    Namespace_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Namespace_or_type_nameContext *namespace_or_type_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Namespace_nameContext* namespace_name();

  class  Type_nameContext : public antlr4::RuleContextWithAltNum {
  public:
    Type_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Namespace_or_type_nameContext *namespace_or_type_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_nameContext* type_name();

  class  Namespace_or_type_nameContext : public antlr4::RuleContextWithAltNum {
  public:
    Namespace_or_type_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    Type_argument_listContext *type_argument_list();
    Qualified_alias_memberContext *qualified_alias_member();
    Namespace_or_type_nameContext *namespace_or_type_name();
    antlr4::tree::TerminalNode *DOT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Namespace_or_type_nameContext* namespace_or_type_name();
  Namespace_or_type_nameContext* namespace_or_type_name(int precedence);
  class  Value_typeContext : public antlr4::RuleContextWithAltNum {
  public:
    Value_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Struct_typeContext *struct_type();
    Enum_typeContext *enum_type();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Value_typeContext* value_type();

  class  Struct_typeContext : public antlr4::RuleContextWithAltNum {
  public:
    Struct_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_nameContext *type_name();
    Simple_typeContext *simple_type();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Struct_typeContext* struct_type();

  class  Base_typeContext : public antlr4::RuleContextWithAltNum {
  public:
    Base_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Simple_typeContext *simple_type();
    Class_typeContext *class_type();
    antlr4::tree::TerminalNode *VOID();
    antlr4::tree::TerminalNode *STAR();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Base_typeContext* base_type();

  class  Simple_typeContext : public antlr4::RuleContextWithAltNum {
  public:
    Simple_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Numeric_typeContext *numeric_type();
    antlr4::tree::TerminalNode *BOOL();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Simple_typeContext* simple_type();

  class  Numeric_typeContext : public antlr4::RuleContextWithAltNum {
  public:
    Numeric_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Integral_typeContext *integral_type();
    Floating_point_typeContext *floating_point_type();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Numeric_typeContext* numeric_type();

  class  Integral_typeContext : public antlr4::RuleContextWithAltNum {
  public:
    Integral_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *UINT();
    antlr4::tree::TerminalNode *CHAR();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Integral_typeContext* integral_type();

  class  Floating_point_typeContext : public antlr4::RuleContextWithAltNum {
  public:
    Floating_point_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *DOUBLE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Floating_point_typeContext* floating_point_type();

  class  Enum_typeContext : public antlr4::RuleContextWithAltNum {
  public:
    Enum_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_nameContext *type_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Enum_typeContext* enum_type();

  class  Reference_typeContext : public antlr4::RuleContextWithAltNum {
  public:
    Reference_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Class_typeContext *class_type();
    Interface_typeContext *interface_type();
    Array_typeContext *array_type();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Reference_typeContext* reference_type();

  class  Class_typeContext : public antlr4::RuleContextWithAltNum {
  public:
    Class_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_nameContext *type_name();
    antlr4::tree::TerminalNode *OBJECT();
    antlr4::tree::TerminalNode *STRING();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_typeContext* class_type();

  class  Interface_typeContext : public antlr4::RuleContextWithAltNum {
  public:
    Interface_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_nameContext *type_name();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Interface_typeContext* interface_type();

  class  Array_typeContext : public antlr4::RuleContextWithAltNum {
  public:
    Array_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Non_array_typeContext *non_array_type();
    std::vector<Rank_specifierContext *> rank_specifier();
    Rank_specifierContext* rank_specifier(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Array_typeContext* array_type();

  class  Non_array_typeContext : public antlr4::RuleContextWithAltNum {
  public:
    Non_array_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Class_typeContext *class_type();
    Interface_typeContext *interface_type();
    Value_typeContext *value_type();
    Type_parameterContext *type_parameter();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Non_array_typeContext* non_array_type();

  class  Rank_specifierContext : public antlr4::RuleContextWithAltNum {
  public:
    Rank_specifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPEN_BRACKET();
    antlr4::tree::TerminalNode *CLOSE_BRACKET();
    std::vector<Dim_separatorContext *> dim_separator();
    Dim_separatorContext* dim_separator(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Rank_specifierContext* rank_specifier();

  class  Dim_separatorContext : public antlr4::RuleContextWithAltNum {
  public:
    Dim_separatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Dim_separatorContext* dim_separator();

  class  Predefined_typeContext : public antlr4::RuleContextWithAltNum {
  public:
    Predefined_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BOOL();
    antlr4::tree::TerminalNode *CHAR();
    antlr4::tree::TerminalNode *DOUBLE();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *OBJECT();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *UINT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Predefined_typeContext* predefined_type();

  class  Class_declarationContext : public antlr4::RuleContextWithAltNum {
  public:
    Class_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CLASS();
    IdentifierContext *identifier();
    Class_bodyContext *class_body();
    std::vector<All_modifierContext *> all_modifier();
    All_modifierContext* all_modifier(size_t i);
    Type_parameter_listContext *type_parameter_list();
    Class_baseContext *class_base();
    std::vector<Type_parameter_constraints_clauseContext *> type_parameter_constraints_clause();
    Type_parameter_constraints_clauseContext* type_parameter_constraints_clause(size_t i);
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_declarationContext* class_declaration();

  class  Class_baseContext : public antlr4::RuleContextWithAltNum {
  public:
    Class_baseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COLON();
    Class_typeContext *class_type();
    Interface_type_listContext *interface_type_list();
    antlr4::tree::TerminalNode *COMMA();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_baseContext* class_base();

  class  Interface_type_listContext : public antlr4::RuleContextWithAltNum {
  public:
    Interface_type_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Interface_typeContext *> interface_type();
    Interface_typeContext* interface_type(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Interface_type_listContext* interface_type_list();

  class  Class_bodyContext : public antlr4::RuleContextWithAltNum {
  public:
    Class_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPEN_BRACE();
    antlr4::tree::TerminalNode *CLOSE_BRACE();
    std::vector<Class_member_declarationContext *> class_member_declaration();
    Class_member_declarationContext* class_member_declaration(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_bodyContext* class_body();

  class  Class_member_declarationContext : public antlr4::RuleContextWithAltNum {
  public:
    Class_member_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Constant_declarationContext *constant_declaration();
    Field_declarationContext *field_declaration();
    Method_declarationContext *method_declaration();
    Property_declarationContext *property_declaration();
    Indexer_declarationContext *indexer_declaration();
    Operator_declarationContext *operator_declaration();
    Constructor_declarationContext *constructor_declaration();
    Static_constructor_declarationContext *static_constructor_declaration();
    Destructor_declarationContext *destructor_declaration();
    Type_declarationContext *type_declaration();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_member_declarationContext* class_member_declaration();

  class  Constant_declarationContext : public antlr4::RuleContextWithAltNum {
  public:
    Constant_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONST();
    Type_Context *type_();
    Constant_declaratorsContext *constant_declarators();
    antlr4::tree::TerminalNode *SEMICOLON();
    std::vector<Basic_modifierContext *> basic_modifier();
    Basic_modifierContext* basic_modifier(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constant_declarationContext* constant_declaration();

  class  Field_declarationContext : public antlr4::RuleContextWithAltNum {
  public:
    Field_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_Context *type_();
    Variable_declaratorsContext *variable_declarators();
    antlr4::tree::TerminalNode *SEMICOLON();
    std::vector<All_modifierContext *> all_modifier();
    All_modifierContext* all_modifier(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Field_declarationContext* field_declaration();

  class  Variable_declaratorsContext : public antlr4::RuleContextWithAltNum {
  public:
    Variable_declaratorsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Variable_declaratorContext *> variable_declarator();
    Variable_declaratorContext* variable_declarator(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variable_declaratorsContext* variable_declarators();

  class  Variable_declaratorContext : public antlr4::RuleContextWithAltNum {
  public:
    Variable_declaratorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *ASSIGNMENT();
    Variable_initializerContext *variable_initializer();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variable_declaratorContext* variable_declarator();

  class  Variable_initializerContext : public antlr4::RuleContextWithAltNum {
  public:
    Variable_initializerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    Array_initializerContext *array_initializer();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variable_initializerContext* variable_initializer();

  class  Method_declarationContext : public antlr4::RuleContextWithAltNum {
  public:
    Method_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Method_headerContext *method_header();
    Method_bodyContext *method_body();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Method_declarationContext* method_declaration();

  class  Method_headerContext : public antlr4::RuleContextWithAltNum {
  public:
    Method_headerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Return_typeContext *return_type();
    Member_nameContext *member_name();
    antlr4::tree::TerminalNode *OPEN_PARENS();
    antlr4::tree::TerminalNode *CLOSE_PARENS();
    std::vector<All_modifierContext *> all_modifier();
    All_modifierContext* all_modifier(size_t i);
    Type_parameter_listContext *type_parameter_list();
    Formal_parameter_listContext *formal_parameter_list();
    std::vector<Type_parameter_constraints_clauseContext *> type_parameter_constraints_clause();
    Type_parameter_constraints_clauseContext* type_parameter_constraints_clause(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Method_headerContext* method_header();

  class  Return_typeContext : public antlr4::RuleContextWithAltNum {
  public:
    Return_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_Context *type_();
    antlr4::tree::TerminalNode *VOID();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Return_typeContext* return_type();

  class  Member_nameContext : public antlr4::RuleContextWithAltNum {
  public:
    Member_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    Interface_typeContext *interface_type();
    antlr4::tree::TerminalNode *DOT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Member_nameContext* member_name();

  class  Formal_parameter_listContext : public antlr4::RuleContextWithAltNum {
  public:
    Formal_parameter_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Fixed_parametersContext *fixed_parameters();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Formal_parameter_listContext* formal_parameter_list();

  class  Fixed_parametersContext : public antlr4::RuleContextWithAltNum {
  public:
    Fixed_parametersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Fixed_parameterContext *> fixed_parameter();
    Fixed_parameterContext* fixed_parameter(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Fixed_parametersContext* fixed_parameters();

  class  Fixed_parameterContext : public antlr4::RuleContextWithAltNum {
  public:
    Fixed_parameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_Context *type_();
    IdentifierContext *identifier();
    Parameter_modifierContext *parameter_modifier();
    Default_argumentContext *default_argument();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Fixed_parameterContext* fixed_parameter();

  class  Default_argumentContext : public antlr4::RuleContextWithAltNum {
  public:
    Default_argumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ASSIGNMENT();
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Default_argumentContext* default_argument();

  class  Parameter_modifierContext : public antlr4::RuleContextWithAltNum {
  public:
    Parameter_modifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *THIS();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Parameter_modifierContext* parameter_modifier();

  class  Method_bodyContext : public antlr4::RuleContextWithAltNum {
  public:
    Method_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Method_bodyContext* method_body();

  class  Property_declarationContext : public antlr4::RuleContextWithAltNum {
  public:
    Property_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_Context *type_();
    Member_nameContext *member_name();
    Property_bodyContext *property_body();
    std::vector<All_modifierContext *> all_modifier();
    All_modifierContext* all_modifier(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Property_declarationContext* property_declaration();

  class  Property_bodyContext : public antlr4::RuleContextWithAltNum {
  public:
    Property_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPEN_BRACE();
    Accessor_declarationsContext *accessor_declarations();
    antlr4::tree::TerminalNode *CLOSE_BRACE();
    Property_initializerContext *property_initializer();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Property_bodyContext* property_body();

  class  Accessor_declarationsContext : public antlr4::RuleContextWithAltNum {
  public:
    Accessor_declarationsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Get_accessor_declarationContext *get_accessor_declaration();
    Set_accessor_declarationContext *set_accessor_declaration();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Accessor_declarationsContext* accessor_declarations();

  class  Get_accessor_declarationContext : public antlr4::RuleContextWithAltNum {
  public:
    Get_accessor_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GET();
    Accessor_bodyContext *accessor_body();
    Accessor_modifierContext *accessor_modifier();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Get_accessor_declarationContext* get_accessor_declaration();

  class  Set_accessor_declarationContext : public antlr4::RuleContextWithAltNum {
  public:
    Set_accessor_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SET();
    Accessor_bodyContext *accessor_body();
    Accessor_modifierContext *accessor_modifier();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Set_accessor_declarationContext* set_accessor_declaration();

  class  Accessor_modifierContext : public antlr4::RuleContextWithAltNum {
  public:
    Accessor_modifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PROTECTED();
    antlr4::tree::TerminalNode *INTERNAL();
    antlr4::tree::TerminalNode *PRIVATE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Accessor_modifierContext* accessor_modifier();

  class  Accessor_bodyContext : public antlr4::RuleContextWithAltNum {
  public:
    Accessor_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Accessor_bodyContext* accessor_body();

  class  Property_initializerContext : public antlr4::RuleContextWithAltNum {
  public:
    Property_initializerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ASSIGNMENT();
    Variable_initializerContext *variable_initializer();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Property_initializerContext* property_initializer();

  class  Indexer_declarationContext : public antlr4::RuleContextWithAltNum {
  public:
    Indexer_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Indexer_declaratorContext *indexer_declarator();
    Indexer_bodyContext *indexer_body();
    std::vector<Indexer_modifierContext *> indexer_modifier();
    Indexer_modifierContext* indexer_modifier(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Indexer_declarationContext* indexer_declaration();

  class  Indexer_modifierContext : public antlr4::RuleContextWithAltNum {
  public:
    Indexer_modifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NEW();
    antlr4::tree::TerminalNode *PUBLIC();
    antlr4::tree::TerminalNode *PROTECTED();
    antlr4::tree::TerminalNode *INTERNAL();
    antlr4::tree::TerminalNode *PRIVATE();
    antlr4::tree::TerminalNode *STATIC();
    antlr4::tree::TerminalNode *VIRTUAL();
    antlr4::tree::TerminalNode *SEALED();
    antlr4::tree::TerminalNode *OVERRIDE();
    antlr4::tree::TerminalNode *ABSTRACT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Indexer_modifierContext* indexer_modifier();

  class  Indexer_declaratorContext : public antlr4::RuleContextWithAltNum {
  public:
    Indexer_declaratorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_Context *type_();
    antlr4::tree::TerminalNode *THIS();
    antlr4::tree::TerminalNode *OPEN_BRACKET();
    Formal_parameter_listContext *formal_parameter_list();
    antlr4::tree::TerminalNode *CLOSE_BRACKET();
    Interface_typeContext *interface_type();
    antlr4::tree::TerminalNode *DOT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Indexer_declaratorContext* indexer_declarator();

  class  Indexer_bodyContext : public antlr4::RuleContextWithAltNum {
  public:
    Indexer_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPEN_BRACE();
    Accessor_declarationsContext *accessor_declarations();
    antlr4::tree::TerminalNode *CLOSE_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Indexer_bodyContext* indexer_body();

  class  Operator_declarationContext : public antlr4::RuleContextWithAltNum {
  public:
    Operator_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Operator_declaratorContext *operator_declarator();
    Operator_bodyContext *operator_body();
    std::vector<Operator_modifierContext *> operator_modifier();
    Operator_modifierContext* operator_modifier(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Operator_declarationContext* operator_declaration();

  class  Operator_modifierContext : public antlr4::RuleContextWithAltNum {
  public:
    Operator_modifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PUBLIC();
    antlr4::tree::TerminalNode *STATIC();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Operator_modifierContext* operator_modifier();

  class  Operator_declaratorContext : public antlr4::RuleContextWithAltNum {
  public:
    Operator_declaratorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Unary_operator_declaratorContext *unary_operator_declarator();
    Binary_operator_declaratorContext *binary_operator_declarator();
    Conversion_operator_declaratorContext *conversion_operator_declarator();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Operator_declaratorContext* operator_declarator();

  class  Unary_operator_declaratorContext : public antlr4::RuleContextWithAltNum {
  public:
    Unary_operator_declaratorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Type_Context *> type_();
    Type_Context* type_(size_t i);
    antlr4::tree::TerminalNode *OPERATOR();
    Overloadable_unary_operatorContext *overloadable_unary_operator();
    antlr4::tree::TerminalNode *OPEN_PARENS();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *CLOSE_PARENS();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Unary_operator_declaratorContext* unary_operator_declarator();

  class  Overloadable_unary_operatorContext : public antlr4::RuleContextWithAltNum {
  public:
    Overloadable_unary_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *BANG();
    antlr4::tree::TerminalNode *TILDE();
    antlr4::tree::TerminalNode *OP_INC();
    antlr4::tree::TerminalNode *OP_DEC();
    antlr4::tree::TerminalNode *TRUE();
    antlr4::tree::TerminalNode *FALSE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Overloadable_unary_operatorContext* overloadable_unary_operator();

  class  Binary_operator_declaratorContext : public antlr4::RuleContextWithAltNum {
  public:
    Binary_operator_declaratorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Type_Context *> type_();
    Type_Context* type_(size_t i);
    antlr4::tree::TerminalNode *OPERATOR();
    Overloadable_binary_operatorContext *overloadable_binary_operator();
    antlr4::tree::TerminalNode *OPEN_PARENS();
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *CLOSE_PARENS();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Binary_operator_declaratorContext* binary_operator_declarator();

  class  Overloadable_binary_operatorContext : public antlr4::RuleContextWithAltNum {
  public:
    Overloadable_binary_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *STAR();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *PERCENT();
    antlr4::tree::TerminalNode *AMP();
    antlr4::tree::TerminalNode *BITWISE_OR();
    antlr4::tree::TerminalNode *CARET();
    antlr4::tree::TerminalNode *OP_LEFT_SHIFT();
    Right_shiftContext *right_shift();
    antlr4::tree::TerminalNode *OP_EQ();
    antlr4::tree::TerminalNode *OP_NE();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *OP_GE();
    antlr4::tree::TerminalNode *OP_LE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Overloadable_binary_operatorContext* overloadable_binary_operator();

  class  Conversion_operator_declaratorContext : public antlr4::RuleContextWithAltNum {
  public:
    Conversion_operator_declaratorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IMPLICIT();
    antlr4::tree::TerminalNode *OPERATOR();
    std::vector<Type_Context *> type_();
    Type_Context* type_(size_t i);
    antlr4::tree::TerminalNode *OPEN_PARENS();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *CLOSE_PARENS();
    antlr4::tree::TerminalNode *EXPLICIT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Conversion_operator_declaratorContext* conversion_operator_declarator();

  class  Operator_bodyContext : public antlr4::RuleContextWithAltNum {
  public:
    Operator_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Operator_bodyContext* operator_body();

  class  Constructor_declarationContext : public antlr4::RuleContextWithAltNum {
  public:
    Constructor_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Constructor_declaratorContext *constructor_declarator();
    Constructor_bodyContext *constructor_body();
    std::vector<Constructor_modifierContext *> constructor_modifier();
    Constructor_modifierContext* constructor_modifier(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constructor_declarationContext* constructor_declaration();

  class  Constructor_modifierContext : public antlr4::RuleContextWithAltNum {
  public:
    Constructor_modifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PUBLIC();
    antlr4::tree::TerminalNode *PROTECTED();
    antlr4::tree::TerminalNode *INTERNAL();
    antlr4::tree::TerminalNode *PRIVATE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constructor_modifierContext* constructor_modifier();

  class  Constructor_declaratorContext : public antlr4::RuleContextWithAltNum {
  public:
    Constructor_declaratorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *OPEN_PARENS();
    antlr4::tree::TerminalNode *CLOSE_PARENS();
    Formal_parameter_listContext *formal_parameter_list();
    Constructor_initializerContext *constructor_initializer();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constructor_declaratorContext* constructor_declarator();

  class  Constructor_initializerContext : public antlr4::RuleContextWithAltNum {
  public:
    Constructor_initializerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *BASE();
    antlr4::tree::TerminalNode *OPEN_PARENS();
    antlr4::tree::TerminalNode *CLOSE_PARENS();
    Argument_listContext *argument_list();
    antlr4::tree::TerminalNode *THIS();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constructor_initializerContext* constructor_initializer();

  class  Constructor_bodyContext : public antlr4::RuleContextWithAltNum {
  public:
    Constructor_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constructor_bodyContext* constructor_body();

  class  Static_constructor_declarationContext : public antlr4::RuleContextWithAltNum {
  public:
    Static_constructor_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Static_constructor_modifiersContext *static_constructor_modifiers();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *OPEN_PARENS();
    antlr4::tree::TerminalNode *CLOSE_PARENS();
    Static_constructor_bodyContext *static_constructor_body();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Static_constructor_declarationContext* static_constructor_declaration();

  class  Static_constructor_modifiersContext : public antlr4::RuleContextWithAltNum {
  public:
    Static_constructor_modifiersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STATIC();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Static_constructor_modifiersContext* static_constructor_modifiers();

  class  Static_constructor_bodyContext : public antlr4::RuleContextWithAltNum {
  public:
    Static_constructor_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Static_constructor_bodyContext* static_constructor_body();

  class  Destructor_declarationContext : public antlr4::RuleContextWithAltNum {
  public:
    Destructor_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TILDE();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *OPEN_PARENS();
    antlr4::tree::TerminalNode *CLOSE_PARENS();
    Destructor_bodyContext *destructor_body();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Destructor_declarationContext* destructor_declaration();

  class  Destructor_bodyContext : public antlr4::RuleContextWithAltNum {
  public:
    Destructor_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Destructor_bodyContext* destructor_body();

  class  Interface_declarationContext : public antlr4::RuleContextWithAltNum {
  public:
    Interface_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTERFACE();
    IdentifierContext *identifier();
    Interface_bodyContext *interface_body();
    std::vector<Basic_modifierContext *> basic_modifier();
    Basic_modifierContext* basic_modifier(size_t i);
    Variant_type_parameter_listContext *variant_type_parameter_list();
    Interface_baseContext *interface_base();
    std::vector<Type_parameter_constraints_clauseContext *> type_parameter_constraints_clause();
    Type_parameter_constraints_clauseContext* type_parameter_constraints_clause(size_t i);
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Interface_declarationContext* interface_declaration();

  class  Variant_type_parameter_listContext : public antlr4::RuleContextWithAltNum {
  public:
    Variant_type_parameter_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LT();
    Variant_type_parametersContext *variant_type_parameters();
    antlr4::tree::TerminalNode *GT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variant_type_parameter_listContext* variant_type_parameter_list();

  class  Variant_type_parametersContext : public antlr4::RuleContextWithAltNum {
  public:
    Variant_type_parametersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_parameterContext *type_parameter();
    Variance_annotationContext *variance_annotation();
    Variant_type_parametersContext *variant_type_parameters();
    antlr4::tree::TerminalNode *COMMA();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variant_type_parametersContext* variant_type_parameters();
  Variant_type_parametersContext* variant_type_parameters(int precedence);
  class  Variance_annotationContext : public antlr4::RuleContextWithAltNum {
  public:
    Variance_annotationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IN();
    antlr4::tree::TerminalNode *OUT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variance_annotationContext* variance_annotation();

  class  Interface_baseContext : public antlr4::RuleContextWithAltNum {
  public:
    Interface_baseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COLON();
    Interface_type_listContext *interface_type_list();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Interface_baseContext* interface_base();

  class  Interface_bodyContext : public antlr4::RuleContextWithAltNum {
  public:
    Interface_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPEN_BRACE();
    antlr4::tree::TerminalNode *CLOSE_BRACE();
    std::vector<Interface_member_declarationContext *> interface_member_declaration();
    Interface_member_declarationContext* interface_member_declaration(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Interface_bodyContext* interface_body();

  class  Interface_member_declarationContext : public antlr4::RuleContextWithAltNum {
  public:
    Interface_member_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Interface_method_declarationContext *interface_method_declaration();
    Interface_property_declarationContext *interface_property_declaration();
    Interface_indexer_declarationContext *interface_indexer_declaration();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Interface_member_declarationContext* interface_member_declaration();

  class  Interface_method_declarationContext : public antlr4::RuleContextWithAltNum {
  public:
    Interface_method_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Return_typeContext *return_type();
    IdentifierContext *identifier();
    Type_parameter_listContext *type_parameter_list();
    antlr4::tree::TerminalNode *OPEN_PARENS();
    antlr4::tree::TerminalNode *CLOSE_PARENS();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *NEW();
    Formal_parameter_listContext *formal_parameter_list();
    std::vector<Type_parameter_constraints_clauseContext *> type_parameter_constraints_clause();
    Type_parameter_constraints_clauseContext* type_parameter_constraints_clause(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Interface_method_declarationContext* interface_method_declaration();

  class  Interface_property_declarationContext : public antlr4::RuleContextWithAltNum {
  public:
    Interface_property_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_Context *type_();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *OPEN_BRACE();
    Interface_accessorsContext *interface_accessors();
    antlr4::tree::TerminalNode *CLOSE_BRACE();
    antlr4::tree::TerminalNode *NEW();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Interface_property_declarationContext* interface_property_declaration();

  class  Interface_accessorsContext : public antlr4::RuleContextWithAltNum {
  public:
    Interface_accessorsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GET();
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);
    antlr4::tree::TerminalNode *SET();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Interface_accessorsContext* interface_accessors();

  class  Interface_indexer_declarationContext : public antlr4::RuleContextWithAltNum {
  public:
    Interface_indexer_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_Context *type_();
    antlr4::tree::TerminalNode *THIS();
    antlr4::tree::TerminalNode *OPEN_BRACKET();
    Formal_parameter_listContext *formal_parameter_list();
    antlr4::tree::TerminalNode *CLOSE_BRACKET();
    antlr4::tree::TerminalNode *OPEN_BRACE();
    Interface_accessorsContext *interface_accessors();
    antlr4::tree::TerminalNode *CLOSE_BRACE();
    antlr4::tree::TerminalNode *NEW();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Interface_indexer_declarationContext* interface_indexer_declaration();

  class  BlockContext : public antlr4::RuleContextWithAltNum {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPEN_BRACE();
    antlr4::tree::TerminalNode *CLOSE_BRACE();
    Statement_listContext *statement_list();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  Statement_listContext : public antlr4::RuleContextWithAltNum {
  public:
    Statement_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Statement_listContext* statement_list();

  class  StatementContext : public antlr4::RuleContextWithAltNum {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Labeled_statementContext *labeled_statement();
    Declaration_statementContext *declaration_statement();
    Embedded_statementContext *embedded_statement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  Labeled_statementContext : public antlr4::RuleContextWithAltNum {
  public:
    Labeled_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *COLON();
    StatementContext *statement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Labeled_statementContext* labeled_statement();

  class  Declaration_statementContext : public antlr4::RuleContextWithAltNum {
  public:
    Declaration_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Local_variable_declarationContext *local_variable_declaration();
    antlr4::tree::TerminalNode *SEMICOLON();
    Local_constant_declarationContext *local_constant_declaration();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Declaration_statementContext* declaration_statement();

  class  Local_variable_declarationContext : public antlr4::RuleContextWithAltNum {
  public:
    Local_variable_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Local_variable_typeContext *local_variable_type();
    Local_variable_declaratorsContext *local_variable_declarators();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Local_variable_declarationContext* local_variable_declaration();

  class  Local_variable_typeContext : public antlr4::RuleContextWithAltNum {
  public:
    Local_variable_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_Context *type_();
    antlr4::tree::TerminalNode *VAR();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Local_variable_typeContext* local_variable_type();

  class  Local_variable_declaratorsContext : public antlr4::RuleContextWithAltNum {
  public:
    Local_variable_declaratorsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Local_variable_declaratorContext *> local_variable_declarator();
    Local_variable_declaratorContext* local_variable_declarator(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Local_variable_declaratorsContext* local_variable_declarators();

  class  Local_variable_declaratorContext : public antlr4::RuleContextWithAltNum {
  public:
    Local_variable_declaratorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *ASSIGNMENT();
    Local_variable_initializerContext *local_variable_initializer();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Local_variable_declaratorContext* local_variable_declarator();

  class  Local_variable_initializerContext : public antlr4::RuleContextWithAltNum {
  public:
    Local_variable_initializerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    Array_initializerContext *array_initializer();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Local_variable_initializerContext* local_variable_initializer();

  class  Local_constant_declarationContext : public antlr4::RuleContextWithAltNum {
  public:
    Local_constant_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONST();
    Type_Context *type_();
    Constant_declaratorsContext *constant_declarators();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Local_constant_declarationContext* local_constant_declaration();

  class  Constant_declaratorsContext : public antlr4::RuleContextWithAltNum {
  public:
    Constant_declaratorsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Constant_declaratorContext *> constant_declarator();
    Constant_declaratorContext* constant_declarator(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constant_declaratorsContext* constant_declarators();

  class  Constant_declaratorContext : public antlr4::RuleContextWithAltNum {
  public:
    Constant_declaratorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *ASSIGNMENT();
    Constant_expressionContext *constant_expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constant_declaratorContext* constant_declarator();

  class  Embedded_statementContext : public antlr4::RuleContextWithAltNum {
  public:
    Embedded_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();
    Empty_statementContext *empty_statement();
    Expression_statementContext *expression_statement();
    Selection_statementContext *selection_statement();
    Iteration_statementContext *iteration_statement();
    Jump_statementContext *jump_statement();
    Try_statementContext *try_statement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Embedded_statementContext* embedded_statement();

  class  Empty_statementContext : public antlr4::RuleContextWithAltNum {
  public:
    Empty_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Empty_statementContext* empty_statement();

  class  Expression_statementContext : public antlr4::RuleContextWithAltNum {
  public:
    Expression_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Statement_expressionContext *statement_expression();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expression_statementContext* expression_statement();

  class  Statement_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Statement_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Invocation_expressionContext *invocation_expression();
    Object_creation_expressionContext *object_creation_expression();
    AssignmentContext *assignment();
    Post_increment_expressionContext *post_increment_expression();
    Post_decrement_expressionContext *post_decrement_expression();
    Pre_increment_expressionContext *pre_increment_expression();
    Pre_decrement_expressionContext *pre_decrement_expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Statement_expressionContext* statement_expression();

  class  Selection_statementContext : public antlr4::RuleContextWithAltNum {
  public:
    Selection_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    If_statementContext *if_statement();
    Switch_statementContext *switch_statement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Selection_statementContext* selection_statement();

  class  If_statementContext : public antlr4::RuleContextWithAltNum {
  public:
    If_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *OPEN_PARENS();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *CLOSE_PARENS();
    std::vector<Embedded_statementContext *> embedded_statement();
    Embedded_statementContext* embedded_statement(size_t i);
    antlr4::tree::TerminalNode *ELSE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_statementContext* if_statement();

  class  Switch_statementContext : public antlr4::RuleContextWithAltNum {
  public:
    Switch_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SWITCH();
    antlr4::tree::TerminalNode *OPEN_PARENS();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *CLOSE_PARENS();
    Switch_blockContext *switch_block();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Switch_statementContext* switch_statement();

  class  Switch_blockContext : public antlr4::RuleContextWithAltNum {
  public:
    Switch_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPEN_BRACE();
    antlr4::tree::TerminalNode *CLOSE_BRACE();
    std::vector<Switch_sectionContext *> switch_section();
    Switch_sectionContext* switch_section(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Switch_blockContext* switch_block();

  class  Switch_sectionContext : public antlr4::RuleContextWithAltNum {
  public:
    Switch_sectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Statement_listContext *statement_list();
    std::vector<Switch_labelContext *> switch_label();
    Switch_labelContext* switch_label(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Switch_sectionContext* switch_section();

  class  Switch_labelContext : public antlr4::RuleContextWithAltNum {
  public:
    Switch_labelContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CASE();
    Constant_expressionContext *constant_expression();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *DEFAULT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Switch_labelContext* switch_label();

  class  Iteration_statementContext : public antlr4::RuleContextWithAltNum {
  public:
    Iteration_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    While_statementContext *while_statement();
    Do_statementContext *do_statement();
    For_statementContext *for_statement();
    Foreach_statementContext *foreach_statement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Iteration_statementContext* iteration_statement();

  class  While_statementContext : public antlr4::RuleContextWithAltNum {
  public:
    While_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *OPEN_PARENS();
    Boolean_expressionContext *boolean_expression();
    antlr4::tree::TerminalNode *CLOSE_PARENS();
    Embedded_statementContext *embedded_statement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  While_statementContext* while_statement();

  class  Do_statementContext : public antlr4::RuleContextWithAltNum {
  public:
    Do_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DO();
    Embedded_statementContext *embedded_statement();
    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *OPEN_PARENS();
    Boolean_expressionContext *boolean_expression();
    antlr4::tree::TerminalNode *CLOSE_PARENS();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Do_statementContext* do_statement();

  class  For_statementContext : public antlr4::RuleContextWithAltNum {
  public:
    For_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *OPEN_PARENS();
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);
    antlr4::tree::TerminalNode *CLOSE_PARENS();
    Embedded_statementContext *embedded_statement();
    For_initializerContext *for_initializer();
    For_conditionContext *for_condition();
    For_iteratorContext *for_iterator();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  For_statementContext* for_statement();

  class  For_initializerContext : public antlr4::RuleContextWithAltNum {
  public:
    For_initializerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Local_variable_declarationContext *local_variable_declaration();
    Statement_expression_listContext *statement_expression_list();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  For_initializerContext* for_initializer();

  class  For_conditionContext : public antlr4::RuleContextWithAltNum {
  public:
    For_conditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Boolean_expressionContext *boolean_expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  For_conditionContext* for_condition();

  class  For_iteratorContext : public antlr4::RuleContextWithAltNum {
  public:
    For_iteratorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Statement_expression_listContext *statement_expression_list();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  For_iteratorContext* for_iterator();

  class  Statement_expression_listContext : public antlr4::RuleContextWithAltNum {
  public:
    Statement_expression_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Statement_expressionContext *> statement_expression();
    Statement_expressionContext* statement_expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Statement_expression_listContext* statement_expression_list();

  class  Foreach_statementContext : public antlr4::RuleContextWithAltNum {
  public:
    Foreach_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOREACH();
    antlr4::tree::TerminalNode *OPEN_PARENS();
    Local_variable_typeContext *local_variable_type();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *IN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *CLOSE_PARENS();
    Embedded_statementContext *embedded_statement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Foreach_statementContext* foreach_statement();

  class  Jump_statementContext : public antlr4::RuleContextWithAltNum {
  public:
    Jump_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Break_statementContext *break_statement();
    Continue_statementContext *continue_statement();
    Goto_statementContext *goto_statement();
    Return_statementContext *return_statement();
    Throw_statementContext *throw_statement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Jump_statementContext* jump_statement();

  class  Break_statementContext : public antlr4::RuleContextWithAltNum {
  public:
    Break_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BREAK();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Break_statementContext* break_statement();

  class  Continue_statementContext : public antlr4::RuleContextWithAltNum {
  public:
    Continue_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONTINUE();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Continue_statementContext* continue_statement();

  class  Goto_statementContext : public antlr4::RuleContextWithAltNum {
  public:
    Goto_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GOTO();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *CASE();
    Constant_expressionContext *constant_expression();
    antlr4::tree::TerminalNode *DEFAULT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Goto_statementContext* goto_statement();

  class  Return_statementContext : public antlr4::RuleContextWithAltNum {
  public:
    Return_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RETURN();
    antlr4::tree::TerminalNode *SEMICOLON();
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Return_statementContext* return_statement();

  class  Throw_statementContext : public antlr4::RuleContextWithAltNum {
  public:
    Throw_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *THROW();
    antlr4::tree::TerminalNode *SEMICOLON();
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Throw_statementContext* throw_statement();

  class  Try_statementContext : public antlr4::RuleContextWithAltNum {
  public:
    Try_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRY();
    BlockContext *block();
    std::vector<Catch_clauseContext *> catch_clause();
    Catch_clauseContext* catch_clause(size_t i);
    Finally_clauseContext *finally_clause();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Try_statementContext* try_statement();

  class  Catch_clauseContext : public antlr4::RuleContextWithAltNum {
  public:
    Catch_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CATCH();
    BlockContext *block();
    Exception_specifierContext *exception_specifier();
    Exception_filterContext *exception_filter();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Catch_clauseContext* catch_clause();

  class  Exception_specifierContext : public antlr4::RuleContextWithAltNum {
  public:
    Exception_specifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPEN_PARENS();
    Type_Context *type_();
    antlr4::tree::TerminalNode *CLOSE_PARENS();
    IdentifierContext *identifier();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Exception_specifierContext* exception_specifier();

  class  Exception_filterContext : public antlr4::RuleContextWithAltNum {
  public:
    Exception_filterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHEN();
    antlr4::tree::TerminalNode *OPEN_PARENS();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *CLOSE_PARENS();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Exception_filterContext* exception_filter();

  class  Finally_clauseContext : public antlr4::RuleContextWithAltNum {
  public:
    Finally_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FINALLY();
    BlockContext *block();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Finally_clauseContext* finally_clause();

  class  Argument_listContext : public antlr4::RuleContextWithAltNum {
  public:
    Argument_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Argument_listContext* argument_list();

  class  Primary_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Primary_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Primary_no_array_creation_expression_baseContext *primary_no_array_creation_expression_base();
    Array_creation_expressionContext *array_creation_expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Primary_expressionContext* primary_expression();

  class  Primary_no_array_creation_expression_baseContext : public antlr4::RuleContextWithAltNum {
  public:
    Primary_no_array_creation_expression_baseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Primary_expression_startContext *primary_expression_start();
    Primary_no_array_creation_expressionContext *primary_no_array_creation_expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Primary_no_array_creation_expression_baseContext* primary_no_array_creation_expression_base();

  class  Primary_expression_startContext : public antlr4::RuleContextWithAltNum {
  public:
    Primary_expression_startContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LiteralContext *literal();
    Simple_nameContext *simple_name();
    Parenthesized_expressionContext *parenthesized_expression();
    This_accessContext *this_access();
    Base_accessContext *base_access();
    Object_creation_expressionContext *object_creation_expression();
    Typeof_expressionContext *typeof_expression();
    Default_value_expressionContext *default_value_expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Primary_expression_startContext* primary_expression_start();

  class  Primary_no_array_creation_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Primary_no_array_creation_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Member_accessContext *member_access();
    Invocation_expressionContext *invocation_expression();
    Element_accessContext *element_access();
    Post_increment_expressionContext *post_increment_expression();
    Post_decrement_expressionContext *post_decrement_expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Primary_no_array_creation_expressionContext* primary_no_array_creation_expression();

  class  Simple_nameContext : public antlr4::RuleContextWithAltNum {
  public:
    Simple_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    Type_argument_listContext *type_argument_list();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Simple_nameContext* simple_name();

  class  Parenthesized_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Parenthesized_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPEN_PARENS();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *CLOSE_PARENS();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Parenthesized_expressionContext* parenthesized_expression();

  class  Member_accessContext : public antlr4::RuleContextWithAltNum {
  public:
    Member_accessContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Primary_expressionContext *primary_expression();
    antlr4::tree::TerminalNode *DOT();
    IdentifierContext *identifier();
    Type_argument_listContext *type_argument_list();
    Predefined_typeContext *predefined_type();
    Qualified_alias_memberContext *qualified_alias_member();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Member_accessContext* member_access();

  class  Invocation_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Invocation_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Primary_expressionContext *primary_expression();
    antlr4::tree::TerminalNode *OPEN_PARENS();
    antlr4::tree::TerminalNode *CLOSE_PARENS();
    Argument_listContext *argument_list();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Invocation_expressionContext* invocation_expression();

  class  Element_accessContext : public antlr4::RuleContextWithAltNum {
  public:
    Element_accessContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Primary_no_array_creation_expression_baseContext *primary_no_array_creation_expression_base();
    antlr4::tree::TerminalNode *OPEN_BRACKET();
    Expression_listContext *expression_list();
    antlr4::tree::TerminalNode *CLOSE_BRACKET();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Element_accessContext* element_access();

  class  This_accessContext : public antlr4::RuleContextWithAltNum {
  public:
    This_accessContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *THIS();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  This_accessContext* this_access();

  class  Base_accessContext : public antlr4::RuleContextWithAltNum {
  public:
    Base_accessContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BASE();
    antlr4::tree::TerminalNode *DOT();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *OPEN_BRACKET();
    Expression_listContext *expression_list();
    antlr4::tree::TerminalNode *CLOSE_BRACKET();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Base_accessContext* base_access();

  class  Post_increment_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Post_increment_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Primary_expressionContext *primary_expression();
    antlr4::tree::TerminalNode *OP_INC();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Post_increment_expressionContext* post_increment_expression();

  class  Post_decrement_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Post_decrement_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Primary_expressionContext *primary_expression();
    antlr4::tree::TerminalNode *OP_DEC();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Post_decrement_expressionContext* post_decrement_expression();

  class  Object_creation_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Object_creation_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NEW();
    Type_Context *type_();
    antlr4::tree::TerminalNode *OPEN_PARENS();
    antlr4::tree::TerminalNode *CLOSE_PARENS();
    Argument_listContext *argument_list();
    Object_or_collection_initializerContext *object_or_collection_initializer();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Object_creation_expressionContext* object_creation_expression();

  class  Object_or_collection_initializerContext : public antlr4::RuleContextWithAltNum {
  public:
    Object_or_collection_initializerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Object_initializerContext *object_initializer();
    Collection_initializerContext *collection_initializer();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Object_or_collection_initializerContext* object_or_collection_initializer();

  class  Object_initializerContext : public antlr4::RuleContextWithAltNum {
  public:
    Object_initializerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPEN_BRACE();
    antlr4::tree::TerminalNode *CLOSE_BRACE();
    Member_initializer_listContext *member_initializer_list();
    antlr4::tree::TerminalNode *COMMA();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Object_initializerContext* object_initializer();

  class  Member_initializer_listContext : public antlr4::RuleContextWithAltNum {
  public:
    Member_initializer_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Member_initializerContext *> member_initializer();
    Member_initializerContext* member_initializer(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Member_initializer_listContext* member_initializer_list();

  class  Member_initializerContext : public antlr4::RuleContextWithAltNum {
  public:
    Member_initializerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *ASSIGNMENT();
    Initializer_valueContext *initializer_value();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Member_initializerContext* member_initializer();

  class  Initializer_valueContext : public antlr4::RuleContextWithAltNum {
  public:
    Initializer_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    Object_or_collection_initializerContext *object_or_collection_initializer();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Initializer_valueContext* initializer_value();

  class  Collection_initializerContext : public antlr4::RuleContextWithAltNum {
  public:
    Collection_initializerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPEN_BRACE();
    Element_initializer_listContext *element_initializer_list();
    antlr4::tree::TerminalNode *CLOSE_BRACE();
    antlr4::tree::TerminalNode *COMMA();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Collection_initializerContext* collection_initializer();

  class  Element_initializer_listContext : public antlr4::RuleContextWithAltNum {
  public:
    Element_initializer_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Element_initializerContext *> element_initializer();
    Element_initializerContext* element_initializer(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Element_initializer_listContext* element_initializer_list();

  class  Element_initializerContext : public antlr4::RuleContextWithAltNum {
  public:
    Element_initializerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Non_assignment_expressionContext *non_assignment_expression();
    antlr4::tree::TerminalNode *OPEN_BRACE();
    Expression_listContext *expression_list();
    antlr4::tree::TerminalNode *CLOSE_BRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Element_initializerContext* element_initializer();

  class  Expression_listContext : public antlr4::RuleContextWithAltNum {
  public:
    Expression_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expression_listContext* expression_list();

  class  Typeof_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Typeof_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPEOF();
    antlr4::tree::TerminalNode *OPEN_PARENS();
    Type_Context *type_();
    antlr4::tree::TerminalNode *CLOSE_PARENS();
    Unbound_type_nameContext *unbound_type_name();
    antlr4::tree::TerminalNode *VOID();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Typeof_expressionContext* typeof_expression();

  class  Unbound_type_nameContext : public antlr4::RuleContextWithAltNum {
  public:
    Unbound_type_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);
    Generic_dimension_specifierContext *generic_dimension_specifier();
    antlr4::tree::TerminalNode *DOUBLE_COLON();
    Unbound_type_nameContext *unbound_type_name();
    antlr4::tree::TerminalNode *DOT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Unbound_type_nameContext* unbound_type_name();
  Unbound_type_nameContext* unbound_type_name(int precedence);
  class  Generic_dimension_specifierContext : public antlr4::RuleContextWithAltNum {
  public:
    Generic_dimension_specifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *GT();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Generic_dimension_specifierContext* generic_dimension_specifier();

  class  Default_value_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Default_value_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEFAULT();
    antlr4::tree::TerminalNode *OPEN_PARENS();
    Type_Context *type_();
    antlr4::tree::TerminalNode *CLOSE_PARENS();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Default_value_expressionContext* default_value_expression();

  class  Array_creation_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Array_creation_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Array_creation_expressionContext() = default;
    void copyFrom(Array_creation_expressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ArrayCreationWithExpressionSizeContext : public Array_creation_expressionContext {
  public:
    ArrayCreationWithExpressionSizeContext(Array_creation_expressionContext *ctx);

    antlr4::tree::TerminalNode *NEW();
    Non_array_typeContext *non_array_type();
    antlr4::tree::TerminalNode *OPEN_BRACKET();
    Expression_listContext *expression_list();
    antlr4::tree::TerminalNode *CLOSE_BRACKET();
    std::vector<Rank_specifierContext *> rank_specifier();
    Rank_specifierContext* rank_specifier(size_t i);
    Array_initializerContext *array_initializer();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ArrayCreationWithInitializerContext : public Array_creation_expressionContext {
  public:
    ArrayCreationWithInitializerContext(Array_creation_expressionContext *ctx);

    antlr4::tree::TerminalNode *NEW();
    Array_typeContext *array_type();
    Array_initializerContext *array_initializer();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Array_creation_expressionContext* array_creation_expression();

  class  Unary_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Unary_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Primary_expressionContext *primary_expression();
    Unary_plus_expressionContext *unary_plus_expression();
    Unary_minus_expressionContext *unary_minus_expression();
    Unary_bang_expressionContext *unary_bang_expression();
    Unary_tilde_expressionContext *unary_tilde_expression();
    Pre_increment_expressionContext *pre_increment_expression();
    Pre_decrement_expressionContext *pre_decrement_expression();
    Cast_expressionContext *cast_expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Unary_expressionContext* unary_expression();

  class  Unary_plus_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Unary_plus_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PLUS();
    Unary_expressionContext *unary_expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Unary_plus_expressionContext* unary_plus_expression();

  class  Unary_minus_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Unary_minus_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MINUS();
    Unary_expressionContext *unary_expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Unary_minus_expressionContext* unary_minus_expression();

  class  Unary_bang_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Unary_bang_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BANG();
    Unary_expressionContext *unary_expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Unary_bang_expressionContext* unary_bang_expression();

  class  Unary_tilde_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Unary_tilde_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TILDE();
    Unary_expressionContext *unary_expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Unary_tilde_expressionContext* unary_tilde_expression();

  class  Pre_increment_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Pre_increment_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OP_INC();
    Unary_expressionContext *unary_expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Pre_increment_expressionContext* pre_increment_expression();

  class  Pre_decrement_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Pre_decrement_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OP_DEC();
    Unary_expressionContext *unary_expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Pre_decrement_expressionContext* pre_decrement_expression();

  class  Cast_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Cast_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPEN_PARENS();
    Type_Context *type_();
    antlr4::tree::TerminalNode *CLOSE_PARENS();
    Unary_expressionContext *unary_expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Cast_expressionContext* cast_expression();

  class  Multiplicative_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Multiplicative_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Unary_expressionContext *unary_expression();
    Multiplicative_expressionContext *multiplicative_expression();
    antlr4::tree::TerminalNode *STAR();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *PERCENT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Multiplicative_expressionContext* multiplicative_expression();
  Multiplicative_expressionContext* multiplicative_expression(int precedence);
  class  Additive_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Additive_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Multiplicative_expressionContext *multiplicative_expression();
    Additive_expressionContext *additive_expression();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Additive_expressionContext* additive_expression();
  Additive_expressionContext* additive_expression(int precedence);
  class  Shift_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Shift_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Additive_expressionContext *additive_expression();
    Shift_expressionContext *shift_expression();
    antlr4::tree::TerminalNode *OP_LEFT_SHIFT();
    Right_shiftContext *right_shift();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Shift_expressionContext* shift_expression();
  Shift_expressionContext* shift_expression(int precedence);
  class  Relational_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Relational_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Shift_expressionContext *shift_expression();
    Relational_expressionContext *relational_expression();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *OP_LE();
    antlr4::tree::TerminalNode *OP_GE();
    antlr4::tree::TerminalNode *IS();
    Type_Context *type_();
    antlr4::tree::TerminalNode *AS();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Relational_expressionContext* relational_expression();
  Relational_expressionContext* relational_expression(int precedence);
  class  Equality_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Equality_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Relational_expressionContext *relational_expression();
    Equality_expressionContext *equality_expression();
    antlr4::tree::TerminalNode *OP_EQ();
    antlr4::tree::TerminalNode *OP_NE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Equality_expressionContext* equality_expression();
  Equality_expressionContext* equality_expression(int precedence);
  class  And_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    And_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Equality_expressionContext *equality_expression();
    And_expressionContext *and_expression();
    antlr4::tree::TerminalNode *AMP();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  And_expressionContext* and_expression();
  And_expressionContext* and_expression(int precedence);
  class  Exclusive_or_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Exclusive_or_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    And_expressionContext *and_expression();
    Exclusive_or_expressionContext *exclusive_or_expression();
    antlr4::tree::TerminalNode *CARET();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Exclusive_or_expressionContext* exclusive_or_expression();
  Exclusive_or_expressionContext* exclusive_or_expression(int precedence);
  class  Inclusive_or_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Inclusive_or_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Exclusive_or_expressionContext *exclusive_or_expression();
    Inclusive_or_expressionContext *inclusive_or_expression();
    antlr4::tree::TerminalNode *BITWISE_OR();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Inclusive_or_expressionContext* inclusive_or_expression();
  Inclusive_or_expressionContext* inclusive_or_expression(int precedence);
  class  Conditional_and_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Conditional_and_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Inclusive_or_expressionContext *inclusive_or_expression();
    Conditional_and_expressionContext *conditional_and_expression();
    antlr4::tree::TerminalNode *OP_AND();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Conditional_and_expressionContext* conditional_and_expression();
  Conditional_and_expressionContext* conditional_and_expression(int precedence);
  class  Conditional_or_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Conditional_or_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Conditional_and_expressionContext *conditional_and_expression();
    Conditional_or_expressionContext *conditional_or_expression();
    antlr4::tree::TerminalNode *OP_OR();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Conditional_or_expressionContext* conditional_or_expression();
  Conditional_or_expressionContext* conditional_or_expression(int precedence);
  class  Null_coalescing_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Null_coalescing_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Conditional_or_expressionContext *conditional_or_expression();
    antlr4::tree::TerminalNode *OP_COALESCING();
    Null_coalescing_expressionContext *null_coalescing_expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Null_coalescing_expressionContext* null_coalescing_expression();

  class  Conditional_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Conditional_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Null_coalescing_expressionContext *null_coalescing_expression();
    antlr4::tree::TerminalNode *INTERR();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *COLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Conditional_expressionContext* conditional_expression();

  class  AssignmentContext : public antlr4::RuleContextWithAltNum {
  public:
    AssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Unary_expressionContext *unary_expression();
    Assignment_operatorContext *assignment_operator();
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentContext* assignment();

  class  Assignment_operatorContext : public antlr4::RuleContextWithAltNum {
  public:
    Assignment_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ASSIGNMENT();
    antlr4::tree::TerminalNode *OP_ADD_ASSIGNMENT();
    antlr4::tree::TerminalNode *OP_SUB_ASSIGNMENT();
    antlr4::tree::TerminalNode *OP_MULT_ASSIGNMENT();
    antlr4::tree::TerminalNode *OP_DIV_ASSIGNMENT();
    antlr4::tree::TerminalNode *OP_MOD_ASSIGNMENT();
    antlr4::tree::TerminalNode *OP_AND_ASSIGNMENT();
    antlr4::tree::TerminalNode *OP_OR_ASSIGNMENT();
    antlr4::tree::TerminalNode *OP_XOR_ASSIGNMENT();
    antlr4::tree::TerminalNode *OP_LEFT_SHIFT_ASSIGNMENT();
    Right_shift_assignmentContext *right_shift_assignment();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assignment_operatorContext* assignment_operator();

  class  ExpressionContext : public antlr4::RuleContextWithAltNum {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Non_assignment_expressionContext *non_assignment_expression();
    AssignmentContext *assignment();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();

  class  Non_assignment_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Non_assignment_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Conditional_expressionContext *conditional_expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Non_assignment_expressionContext* non_assignment_expression();

  class  Constant_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Constant_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constant_expressionContext* constant_expression();

  class  Boolean_expressionContext : public antlr4::RuleContextWithAltNum {
  public:
    Boolean_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Boolean_expressionContext* boolean_expression();

  class  LiteralContext : public antlr4::RuleContextWithAltNum {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Boolean_literalContext *boolean_literal();
    String_literalContext *string_literal();
    antlr4::tree::TerminalNode *INTEGER_LITERAL();
    antlr4::tree::TerminalNode *UNSIGNED_LITERAL();
    antlr4::tree::TerminalNode *HEX_INTEGER_LITERAL();
    antlr4::tree::TerminalNode *FLOAT_LITERAL();
    antlr4::tree::TerminalNode *DOUBLE_LITERAL();
    antlr4::tree::TerminalNode *CHARACTER_LITERAL();
    antlr4::tree::TerminalNode *NULL_();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LiteralContext* literal();

  class  Boolean_literalContext : public antlr4::RuleContextWithAltNum {
  public:
    Boolean_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRUE();
    antlr4::tree::TerminalNode *FALSE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Boolean_literalContext* boolean_literal();

  class  String_literalContext : public antlr4::RuleContextWithAltNum {
  public:
    String_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *REGULAR_STRING();
    antlr4::tree::TerminalNode *VERBATIUM_STRING();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  String_literalContext* string_literal();

  class  Array_initializerContext : public antlr4::RuleContextWithAltNum {
  public:
    Array_initializerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPEN_BRACE();
    antlr4::tree::TerminalNode *CLOSE_BRACE();
    Variable_initializer_listContext *variable_initializer_list();
    antlr4::tree::TerminalNode *COMMA();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Array_initializerContext* array_initializer();

  class  Variable_initializer_listContext : public antlr4::RuleContextWithAltNum {
  public:
    Variable_initializer_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Variable_initializerContext *> variable_initializer();
    Variable_initializerContext* variable_initializer(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variable_initializer_listContext* variable_initializer_list();

  class  Right_shiftContext : public antlr4::RuleContextWithAltNum {
  public:
    antlr4::Token *first = nullptr;
    antlr4::Token *second = nullptr;
    Right_shiftContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> GT();
    antlr4::tree::TerminalNode* GT(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Right_shiftContext* right_shift();

  class  Right_shift_assignmentContext : public antlr4::RuleContextWithAltNum {
  public:
    antlr4::Token *first = nullptr;
    antlr4::Token *second = nullptr;
    Right_shift_assignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *OP_GE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Right_shift_assignmentContext* right_shift_assignment();

  class  IdentifierContext : public antlr4::RuleContextWithAltNum {
  public:
    IdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdentifierContext* identifier();

  class  All_modifierContext : public antlr4::RuleContextWithAltNum {
  public:
    All_modifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NEW();
    antlr4::tree::TerminalNode *PUBLIC();
    antlr4::tree::TerminalNode *PROTECTED();
    antlr4::tree::TerminalNode *PRIVATE();
    antlr4::tree::TerminalNode *STATIC();
    antlr4::tree::TerminalNode *VIRTUAL();
    antlr4::tree::TerminalNode *SEALED();
    antlr4::tree::TerminalNode *OVERRIDE();
    antlr4::tree::TerminalNode *ABSTRACT();
    antlr4::tree::TerminalNode *READONLY();
    antlr4::tree::TerminalNode *EXTERN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  All_modifierContext* all_modifier();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool namespace_or_type_nameSempred(Namespace_or_type_nameContext *_localctx, size_t predicateIndex);
  bool variant_type_parametersSempred(Variant_type_parametersContext *_localctx, size_t predicateIndex);
  bool unbound_type_nameSempred(Unbound_type_nameContext *_localctx, size_t predicateIndex);
  bool multiplicative_expressionSempred(Multiplicative_expressionContext *_localctx, size_t predicateIndex);
  bool additive_expressionSempred(Additive_expressionContext *_localctx, size_t predicateIndex);
  bool shift_expressionSempred(Shift_expressionContext *_localctx, size_t predicateIndex);
  bool relational_expressionSempred(Relational_expressionContext *_localctx, size_t predicateIndex);
  bool equality_expressionSempred(Equality_expressionContext *_localctx, size_t predicateIndex);
  bool and_expressionSempred(And_expressionContext *_localctx, size_t predicateIndex);
  bool exclusive_or_expressionSempred(Exclusive_or_expressionContext *_localctx, size_t predicateIndex);
  bool inclusive_or_expressionSempred(Inclusive_or_expressionContext *_localctx, size_t predicateIndex);
  bool conditional_and_expressionSempred(Conditional_and_expressionContext *_localctx, size_t predicateIndex);
  bool conditional_or_expressionSempred(Conditional_or_expressionContext *_localctx, size_t predicateIndex);
  bool right_shiftSempred(Right_shiftContext *_localctx, size_t predicateIndex);
  bool right_shift_assignmentSempred(Right_shift_assignmentContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

