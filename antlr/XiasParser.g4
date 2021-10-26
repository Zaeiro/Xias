parser grammar XiasParser;

options { tokenVocab=XiasLexer; }

// Entry point

compilation_unit
	: using_directive* namespace_member_declaration* EOF
	;

// Usings
using_directive
	: USING identifier ASSIGNMENT namespace_or_type_name SEMICOLON     #usingAliasDirective
	| USING namespace_or_type_name SEMICOLON                           #usingNamespaceDirective
	// C# 6: https://msdn.microsoft.com/en-us/library/ms228593.aspx
	| USING STATIC namespace_or_type_name SEMICOLON                    #usingStaticDirective
	;

// Namespace members
namespace_member_declaration
	: namespace_declaration
	| type_declaration
	;

// Namespaces
namespace_declaration
	: NAMESPACE qi=qualified_identifier namespace_body SEMICOLON?
	;

qualified_identifier
	: identifier ( DOT identifier )*
	;

namespace_body
	: OPEN_BRACE using_directive* namespace_member_declaration* CLOSE_BRACE
	;

qualified_alias_member
    : identifier DOUBLE_COLON identifier type_argument_list?
    ;

// Types
type_declaration
	: class_declaration
	| interface_declaration
	//| enum_definition
	;

type_parameter_list
	: LT type_parameter (COMMA type_parameter)* GT
	;

type_argument_list 
	: LT type_ ( COMMA type_)* GT
	;

type_parameter
	: identifier
	;

type_parameter_constraints_clause
	: WHERE identifier COLON type_parameter_constraints
	;

type_parameter_constraints
	: class_type constructor_constraint?
	;

constructor_constraint
	: NEW OPEN_PARENS CLOSE_PARENS
	;

basic_modifier
	: NEW
	| PUBLIC
	| PROTECTED
	| INTERNAL
	| PRIVATE
	;

// Type types
type_
    : value_type
    | reference_type
    | type_parameter
	;

namespace_name
    : namespace_or_type_name
    ;

type_name
    : namespace_or_type_name
    ;

namespace_or_type_name
    : identifier type_argument_list?
    | namespace_or_type_name DOT identifier type_argument_list?
    | qualified_alias_member
    ;

value_type
    : struct_type
    | enum_type
    ;

struct_type
    : type_name
    | simple_type
    ;

base_type
	: simple_type
	| class_type
	| VOID STAR
	;

simple_type 
	: numeric_type
	| BOOL
	;

numeric_type 
	: integral_type
	| floating_point_type
	;

integral_type 
	: INT
	| UINT
	| CHAR
	;

floating_point_type 
	: FLOAT
	| DOUBLE
	;

enum_type
    : type_name
    ;

reference_type
    : class_type
    | interface_type
    | array_type
    ;

class_type
    : type_name
    | OBJECT
    | STRING
    ;

interface_type
    : type_name
    ;

array_type
    : non_array_type rank_specifier+
    ;

non_array_type
    : class_type
    | interface_type
    | value_type
    | type_parameter
    ;

rank_specifier
    : OPEN_BRACKET dim_separator* CLOSE_BRACKET
    ;

dim_separator
    : COMMA
    ;

predefined_type
	: BOOL | CHAR | DOUBLE | FLOAT | INT
	| OBJECT | STRING | UINT
	;

// Classes
class_declaration
	: all_modifier* CLASS identifier type_parameter_list? class_base?
      type_parameter_constraints_clause* class_body SEMICOLON?
	;

// class_modifier
// 	: NEW
// 	| PUBLIC
// 	| PROTECTED
// 	| INTERNAL
// 	| PRIVATE
// 	| ABSTRACT
// 	| SEALED
// 	| STATIC
// 	;

class_base
    : COLON class_type
    | COLON interface_type_list
    | COLON class_type COMMA interface_type_list
    ;

interface_type_list
    : interface_type (COMMA interface_type)*
    ;

class_body
	: OPEN_BRACE class_member_declaration* CLOSE_BRACE
	;

class_member_declaration
	: constant_declaration
	| field_declaration
    | method_declaration
    | property_declaration
    | indexer_declaration
    | operator_declaration
    | constructor_declaration
    | static_constructor_declaration
    | destructor_declaration
    | type_declaration
	;

// constant_declaration
constant_declaration
	: basic_modifier* CONST type_ constant_declarators SEMICOLON
	;
// End constant_declaration

// field_declaration
field_declaration
	: all_modifier* type_ variable_declarators SEMICOLON
	;

// field_modifier
// 	: NEW
// 	| PUBLIC
// 	| PROTECTED
// 	| INTERNAL
// 	| PRIVATE
// 	| STATIC
// 	| READONLY
// 	;

variable_declarators
	: variable_declarator (COMMA variable_declarator)*
	;

variable_declarator
	: identifier (ASSIGNMENT variable_initializer)?
	;

variable_initializer
	: expression
	| array_initializer
	;
// End field_declaration

// method_declaration
method_declaration
    : method_header method_body
    ;

method_header
    : all_modifier* return_type member_name type_parameter_list?
      OPEN_PARENS formal_parameter_list? CLOSE_PARENS type_parameter_constraints_clause*
    ;

// method_modifier
// 	: NEW
// 	| PUBLIC
// 	| PROTECTED
// 	| INTERNAL
// 	| PRIVATE
// 	| STATIC
// 	| VIRTUAL
// 	| SEALED
// 	| OVERRIDE
// 	| ABSTRACT
// 	;

return_type
    : type_
    | VOID
    ;

member_name
    : identifier
    | interface_type DOT identifier
    ;

formal_parameter_list
    : fixed_parameters
    ;

fixed_parameters
    : fixed_parameter (COMMA fixed_parameter)*
    ;

fixed_parameter
    : parameter_modifier? type_ identifier default_argument?
    ;

default_argument
    : ASSIGNMENT expression
    ;

parameter_modifier
    : THIS
    ;

method_body
    : block
    | SEMICOLON
    ;
// End method_declaration

// property_declaration
property_declaration
    : all_modifier* type_ member_name property_body
    ;

// property_modifier
// 	: NEW
// 	| PUBLIC
// 	| PROTECTED
// 	| INTERNAL
// 	| PRIVATE
// 	| STATIC
// 	| VIRTUAL
// 	| SEALED
// 	| OVERRIDE
// 	| ABSTRACT
// 	;

property_body
    : OPEN_BRACE accessor_declarations CLOSE_BRACE property_initializer?
    //| '=>' expression ';'
    ;

accessor_declarations
    : get_accessor_declaration set_accessor_declaration?
    | set_accessor_declaration get_accessor_declaration?
    ;

get_accessor_declaration
    : accessor_modifier? GET accessor_body
    ;

set_accessor_declaration
    : accessor_modifier? SET accessor_body
    ;

accessor_modifier
    : PROTECTED
    | INTERNAL
    | PRIVATE
    | PROTECTED INTERNAL
    | INTERNAL PROTECTED
    ;

accessor_body
    : block
    | SEMICOLON
    ;

property_initializer
    : ASSIGNMENT variable_initializer SEMICOLON
    ;
// End property_declaration

// indexer_declaration
indexer_declaration
    : indexer_modifier* indexer_declarator indexer_body
    ;

indexer_modifier
    : NEW
	| PUBLIC
	| PROTECTED
	| INTERNAL
	| PRIVATE
    | STATIC
    | VIRTUAL
    | SEALED
    | OVERRIDE
    | ABSTRACT
    ;

indexer_declarator
    : type_ THIS OPEN_BRACKET formal_parameter_list CLOSE_BRACKET
    | type_ interface_type DOT THIS OPEN_BRACKET formal_parameter_list CLOSE_BRACKET
    ;

indexer_body
    : OPEN_BRACE accessor_declarations CLOSE_BRACE
    //| '=>' expression ';'
    ;
// End indexer_declaration

// operator_declaration
operator_declaration
    : operator_modifier+ operator_declarator operator_body
    ;

operator_modifier
    : PUBLIC
    | STATIC
    ;

operator_declarator
    : unary_operator_declarator
    | binary_operator_declarator
    | conversion_operator_declarator
    ;

unary_operator_declarator
    : type_ OPERATOR overloadable_unary_operator OPEN_PARENS type_ identifier CLOSE_PARENS
    ;

overloadable_unary_operator
    : PLUS
    | MINUS
    | BANG
    | TILDE
    | OP_INC
    | OP_DEC
    | TRUE
    | FALSE
    ;

binary_operator_declarator
    : type_ OPERATOR overloadable_binary_operator OPEN_PARENS type_ identifier
    COMMA type_ identifier CLOSE_PARENS
    ;

overloadable_binary_operator
    : PLUS
    | MINUS
    | STAR
	| DIV
	| PERCENT
	| AMP
	| BITWISE_OR
	| CARET
	| OP_LEFT_SHIFT
	| right_shift
	| OP_EQ
	| OP_NE
	| GT
	| LT
	| OP_GE
	| OP_LE
    ;

conversion_operator_declarator
    : IMPLICIT OPERATOR type_ OPEN_PARENS type_ identifier CLOSE_PARENS
    | EXPLICIT OPERATOR type_ OPEN_PARENS type_ identifier CLOSE_PARENS
    ;

operator_body
    : block
    //| '=>' expression ';'
    | SEMICOLON
    ;
// End operator_declaration

// constructor_declaration
constructor_declaration
    : constructor_modifier* constructor_declarator constructor_body
    ;

constructor_modifier
    : PUBLIC
    | PROTECTED
    | INTERNAL
    | PRIVATE
    ;

constructor_declarator
    : identifier OPEN_PARENS formal_parameter_list? CLOSE_PARENS constructor_initializer?
    ;

constructor_initializer
    : COLON BASE OPEN_PARENS argument_list? CLOSE_PARENS
    | COLON THIS OPEN_PARENS argument_list? CLOSE_PARENS
    ;

constructor_body
    : block
    | SEMICOLON
    ;
// End constructor_declaration

// static_constructor_declaration
static_constructor_declaration
    : static_constructor_modifiers identifier OPEN_PARENS CLOSE_PARENS static_constructor_body
    ;

static_constructor_modifiers
    : STATIC
    ;

static_constructor_body
    : block
    | SEMICOLON
    ;
// End static_constructor_declaration

// destructor_declaration
destructor_declaration
    : TILDE identifier OPEN_PARENS CLOSE_PARENS destructor_body
    ;

destructor_body
    : block
    | SEMICOLON
    ;
// End destructor_declaration

// Interfaces
interface_declaration
    : basic_modifier* INTERFACE
      identifier variant_type_parameter_list? interface_base?
      type_parameter_constraints_clause* interface_body SEMICOLON?
    ;

variant_type_parameter_list
    : LT variant_type_parameters GT
    ;

variant_type_parameters
    : variance_annotation? type_parameter
    | variant_type_parameters COMMA variance_annotation? type_parameter
    ;

variance_annotation
    : IN
    | OUT
    ;

interface_base
    : COLON interface_type_list
    ;

interface_body
    : OPEN_BRACE interface_member_declaration* CLOSE_BRACE
    ;

interface_member_declaration
    : interface_method_declaration
    | interface_property_declaration
    | interface_indexer_declaration
    ;

interface_method_declaration
    : NEW? return_type identifier type_parameter_list OPEN_PARENS
    formal_parameter_list? CLOSE_PARENS type_parameter_constraints_clause* SEMICOLON
    ;

interface_property_declaration
    : NEW? type_ identifier OPEN_BRACE interface_accessors CLOSE_BRACE
    ;

interface_accessors
    : GET SEMICOLON
    | SET SEMICOLON
    | GET SEMICOLON SET SEMICOLON
    | SET SEMICOLON GET SEMICOLON
    ;

interface_indexer_declaration
    : NEW? type_ THIS OPEN_BRACKET formal_parameter_list CLOSE_BRACKET
    OPEN_BRACE interface_accessors CLOSE_BRACE
    ;

// Enums

// Statements
block
	: OPEN_BRACE statement_list? CLOSE_BRACE
	;

statement_list
    : statement+
    ;

statement
	: labeled_statement
	| declaration_statement
	| embedded_statement
	;

labeled_statement
	: identifier COLON statement
	;


declaration_statement
	: local_variable_declaration SEMICOLON
	| local_constant_declaration SEMICOLON
	;

local_variable_declaration
    : local_variable_type local_variable_declarators
    ;

local_variable_type
    : type_
    | VAR
    ;

local_variable_declarators
    : local_variable_declarator (COMMA local_variable_declarator)*
    ;

local_variable_declarator
    : identifier
    | identifier ASSIGNMENT local_variable_initializer
    ;

local_variable_initializer
    : expression
    | array_initializer
    ;

local_constant_declaration
    : CONST type_ constant_declarators
    ;

constant_declarators
    : constant_declarator (COMMA constant_declarator)*
    ;

constant_declarator
    : identifier ASSIGNMENT constant_expression
    ;


embedded_statement
    : block
    | empty_statement
    | expression_statement
    | selection_statement
    | iteration_statement
    | jump_statement
    | try_statement
    //| using_statement
    ;

empty_statement
    : SEMICOLON
    ;


expression_statement
    : statement_expression SEMICOLON
    ;

statement_expression
    : invocation_expression
    | object_creation_expression
    | assignment
    | post_increment_expression
    | post_decrement_expression
    | pre_increment_expression
    | pre_decrement_expression
    ;


selection_statement
    : if_statement
    | switch_statement
    ;

if_statement
    : IF OPEN_PARENS expression CLOSE_PARENS embedded_statement
    | IF OPEN_PARENS expression CLOSE_PARENS embedded_statement ELSE embedded_statement
    ;

switch_statement
    : SWITCH OPEN_PARENS expression CLOSE_PARENS switch_block
    ;

switch_block
    : OPEN_BRACE switch_section* CLOSE_BRACE
    ;

switch_section
    : switch_label+ statement_list
    ;

switch_label
    : CASE constant_expression COLON
    | DEFAULT COLON
    ;


iteration_statement
    : while_statement
    | do_statement
    | for_statement
    | foreach_statement
    ;

while_statement
    : WHILE OPEN_PARENS boolean_expression CLOSE_PARENS embedded_statement
    ;

do_statement
    : DO embedded_statement WHILE OPEN_PARENS boolean_expression CLOSE_PARENS SEMICOLON
    ;

for_statement
    : FOR OPEN_PARENS for_initializer SEMICOLON for_condition
      SEMICOLON for_iterator CLOSE_PARENS embedded_statement
    ;

for_initializer
    : local_variable_declaration?
    | statement_expression_list?
    ;

for_condition
    : boolean_expression?
    ;

for_iterator
    : statement_expression_list?
    ;

statement_expression_list
    : statement_expression (COMMA statement_expression)*
    ;

foreach_statement
    : FOREACH OPEN_PARENS local_variable_type identifier IN expression
      CLOSE_PARENS embedded_statement
    ;


jump_statement
    : break_statement
    | continue_statement
    | goto_statement
    | return_statement
    | throw_statement
    ;

break_statement
    : BREAK SEMICOLON
    ;

continue_statement
    : CONTINUE SEMICOLON
    ;

goto_statement
    : GOTO identifier SEMICOLON
    | GOTO CASE constant_expression SEMICOLON
    | GOTO DEFAULT SEMICOLON
    ;

return_statement
    : RETURN expression? SEMICOLON
    ;

throw_statement
    : THROW expression? SEMICOLON
    ;


try_statement
    : TRY block catch_clause+
    | TRY block finally_clause
    | TRY block catch_clause+ finally_clause
    ;

catch_clause
    : CATCH exception_specifier? exception_filter? block
    ;

exception_specifier
    : OPEN_PARENS type_ identifier? CLOSE_PARENS
    ;

exception_filter
    : WHEN OPEN_PARENS expression CLOSE_PARENS
    ;

finally_clause
    : FINALLY block
    ;
// End embedded_statement


// Expressions
argument_list
    : expression (COMMA expression)*
    ;

primary_expression
    : primary_no_array_creation_expression_base
    | array_creation_expression
    ;

primary_no_array_creation_expression_base
    : primary_expression_start primary_no_array_creation_expression?
    ;

primary_expression_start
    : literal
    | simple_name
    | parenthesized_expression
    | this_access
    | base_access
    | object_creation_expression
    | typeof_expression
    | default_value_expression
    ;

primary_no_array_creation_expression
    : member_access
    | invocation_expression
    | element_access
    | post_increment_expression
    | post_decrement_expression
    ;

simple_name
    : identifier type_argument_list?
    ;


parenthesized_expression
    : OPEN_PARENS expression CLOSE_PARENS
    ;


member_access
    : primary_expression DOT identifier type_argument_list?
    | predefined_type DOT identifier type_argument_list?
    | qualified_alias_member DOT identifier
    ;


invocation_expression
    : primary_expression OPEN_PARENS argument_list? CLOSE_PARENS
    ;


element_access
    : primary_no_array_creation_expression_base OPEN_BRACKET expression_list CLOSE_BRACKET
    ;


this_access
    : THIS
    ;


base_access
    : BASE DOT identifier
    | BASE OPEN_BRACKET expression_list CLOSE_BRACKET
    ;


post_increment_expression
    : primary_expression OP_INC
    ;

post_decrement_expression
    : primary_expression OP_DEC
    ;


object_creation_expression
    : NEW type_ OPEN_PARENS argument_list? CLOSE_PARENS object_or_collection_initializer?
    | NEW type_ object_or_collection_initializer
    ;

object_or_collection_initializer
    : object_initializer
    | collection_initializer
    ;

object_initializer
    : OPEN_BRACE member_initializer_list? CLOSE_BRACE
    | OPEN_BRACE member_initializer_list COMMA CLOSE_BRACE
    ;

member_initializer_list
    : member_initializer (COMMA member_initializer)*
    ;

member_initializer
    : identifier ASSIGNMENT initializer_value
    ;

initializer_value
    : expression
    | object_or_collection_initializer
    ;

collection_initializer
    : OPEN_BRACE element_initializer_list CLOSE_BRACE
    | OPEN_BRACE element_initializer_list COMMA CLOSE_BRACE
    ;

element_initializer_list
    : element_initializer (COMMA element_initializer)*
    ;

element_initializer
    : non_assignment_expression
    | OPEN_BRACE expression_list CLOSE_BRACE
    ;

expression_list
    : expression (COMMA expression)*
    ;

typeof_expression
    : TYPEOF OPEN_PARENS type_ CLOSE_PARENS
    | TYPEOF OPEN_PARENS unbound_type_name CLOSE_PARENS
    | TYPEOF OPEN_PARENS VOID CLOSE_PARENS
    ;

unbound_type_name
    : identifier generic_dimension_specifier?
    | identifier DOUBLE_COLON identifier generic_dimension_specifier?
    | unbound_type_name DOT identifier generic_dimension_specifier?
    ;

generic_dimension_specifier
    : LT COMMA* GT
    ;

default_value_expression
    : DEFAULT OPEN_PARENS type_ CLOSE_PARENS
    ;
//End primary_no_array_creation_expression

array_creation_expression
    : NEW non_array_type OPEN_BRACKET expression_list CLOSE_BRACKET
      rank_specifier* array_initializer? #arrayCreationWithExpressionSize
    | NEW array_type array_initializer #arrayCreationWithInitializer
    ;

unary_expression
    : primary_expression
    | unary_plus_expression
    | unary_minus_expression
    | unary_bang_expression
    | unary_tilde_expression
    | pre_increment_expression
    | pre_decrement_expression
    | cast_expression
    ;

unary_plus_expression
    : PLUS unary_expression
    ;

unary_minus_expression
    : MINUS unary_expression
    ;

unary_bang_expression
    : BANG unary_expression
    ;

unary_tilde_expression
    : TILDE unary_expression
    ;

pre_increment_expression
    : OP_INC unary_expression
    ;

pre_decrement_expression
    : OP_DEC unary_expression
    ;

cast_expression
    : OPEN_PARENS type_ CLOSE_PARENS unary_expression
    ;
// End unary_expression

// Operators
multiplicative_expression
    : unary_expression
    | multiplicative_expression STAR unary_expression
    | multiplicative_expression DIV unary_expression
    | multiplicative_expression PERCENT unary_expression
    ;

additive_expression
    : multiplicative_expression
    | additive_expression PLUS multiplicative_expression
    | additive_expression MINUS multiplicative_expression
    ;

shift_expression
    : additive_expression
    | shift_expression OP_LEFT_SHIFT additive_expression
    | shift_expression right_shift additive_expression
    ;

relational_expression
    : shift_expression
    | relational_expression LT shift_expression
    | relational_expression GT shift_expression
    | relational_expression OP_LE shift_expression
    | relational_expression OP_GE shift_expression
    | relational_expression IS type_
    | relational_expression AS type_
    ;

equality_expression
    : relational_expression
    | equality_expression OP_EQ relational_expression
    | equality_expression OP_NE relational_expression
    ;

and_expression
    : equality_expression
    | and_expression AMP equality_expression
    ;

exclusive_or_expression
    : and_expression
    | exclusive_or_expression CARET and_expression
    ;

inclusive_or_expression
    : exclusive_or_expression
    | inclusive_or_expression BITWISE_OR exclusive_or_expression
    ;

conditional_and_expression
    : inclusive_or_expression
    | conditional_and_expression OP_AND inclusive_or_expression
    ;

conditional_or_expression
    : conditional_and_expression
    | conditional_or_expression OP_OR conditional_and_expression
    ;

null_coalescing_expression
    : conditional_or_expression
    | conditional_or_expression OP_COALESCING null_coalescing_expression
    ;

conditional_expression
    : null_coalescing_expression
    | null_coalescing_expression INTERR expression COLON expression
    ;

assignment
    : unary_expression assignment_operator expression
    ;

assignment_operator
    : ASSIGNMENT
    | OP_ADD_ASSIGNMENT
    | OP_SUB_ASSIGNMENT
    | OP_MULT_ASSIGNMENT
    | OP_DIV_ASSIGNMENT
    | OP_MOD_ASSIGNMENT
    | OP_AND_ASSIGNMENT
    | OP_OR_ASSIGNMENT
    | OP_XOR_ASSIGNMENT
    | OP_LEFT_SHIFT_ASSIGNMENT
    | right_shift_assignment
    ;

expression
    : non_assignment_expression
    | assignment
    ;

non_assignment_expression
    : conditional_expression
    ;

constant_expression
    : expression
    ;

boolean_expression
    : expression
    ;

// Literals
literal
	: boolean_literal
	| string_literal
	| INTEGER_LITERAL
	| UNSIGNED_LITERAL
	| HEX_INTEGER_LITERAL
	| FLOAT_LITERAL
	| DOUBLE_LITERAL
	| CHARACTER_LITERAL
	| NULL_
	;

boolean_literal
	: TRUE
	| FALSE
	;

string_literal
	: REGULAR_STRING
	| VERBATIUM_STRING
	;

// Arrays
array_initializer
    : OPEN_BRACE variable_initializer_list? CLOSE_BRACE
    | OPEN_BRACE variable_initializer_list COMMA CLOSE_BRACE
    ;

variable_initializer_list
    : variable_initializer (COMMA variable_initializer)*
    ;

// Miscellaneous
right_shift
	: first=GT second=GT {$first.index + 1 == $second.index}? // Nothing between the tokens?
	;

right_shift_assignment
	: first=GT second=OP_GE {$first.index + 1 == $second.index}? // Nothing between the tokens?
	;

identifier
    : IDENTIFIER
    ;

all_modifier
    : NEW
	| PUBLIC
	| PROTECTED
	| PRIVATE
	| STATIC
    | VIRTUAL
	| SEALED
    | OVERRIDE
    | ABSTRACT
	| READONLY
    | EXTERN
    ;
