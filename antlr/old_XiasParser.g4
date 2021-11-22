parser grammar XiasParser;

options { tokenVocab=XiasLexer; }

// entry point

compilation_unit
	: using_directives? namespace_member_declarations? EOF
	;

namespace_or_type_name 
	: (identifier type_argument_list? | qualified_alias_member) (DOT identifier type_argument_list?)*
	;

// Types

type_
	: base_type rank_specifier*
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

/** namespace_or_type_name, OBJECT, STRING */
class_type 
	: namespace_or_type_name
	| OBJECT
	| STRING
	;

type_argument_list 
	: LT type_ ( COMMA type_)* GT
	;

// Expressions
argument_list 
	: argument ( COMMA argument)*
	;

argument
	: (identifier COLON)? refout=(REF | OUT | IN)? (VAR | type_)? expression
	;

expression
	: assignment
	| non_assignment_expression
	| REF non_assignment_expression
	;

non_assignment_expression
	: conditional_expression
	;

assignment
	: unary_expression assignment_operator expression
	| unary_expression OP_COALESCING_ASSIGNMENT throwable_expression
	;

assignment_operator
	: ASSIGNMENT | OP_ADD_ASSIGNMENT | OP_SUB_ASSIGNMENT | OP_MULT_ASSIGNMENT | OP_DIV_ASSIGNMENT
	| OP_MOD_ASSIGNMENT | OP_AND_ASSIGNMENT | OP_OR_ASSIGNMENT | OP_XOR_ASSIGNMENT | OP_LEFT_SHIFT_ASSIGNMENT | right_shift_assignment
	;

conditional_expression
	: null_coalescing_expression (INTERR throwable_expression COLON throwable_expression)?
	;

null_coalescing_expression
	: conditional_or_expression (OP_COALESCING (null_coalescing_expression | throw_expression))?
	;

conditional_or_expression
	: conditional_and_expression (OP_OR conditional_and_expression)*
	;

conditional_and_expression
	: inclusive_or_expression (OP_AND inclusive_or_expression)*
	;

inclusive_or_expression
	: exclusive_or_expression (BITWISE_OR exclusive_or_expression)*
	;

exclusive_or_expression
	: and_expression (CARET and_expression)*
	;

and_expression
	: equality_expression (AMP equality_expression)*
	;

equality_expression
	: relational_expression ((OP_EQ | OP_NE) relational_expression)*
	;

relational_expression
	: shift_expression ((LT | GT | OP_LE | OP_GE) shift_expression | AS type_)*
	;

shift_expression
	: additive_expression ((OP_LEFT_SHIFT | right_shift) additive_expression)*
	;

additive_expression
	: multiplicative_expression ((PLUS | MINUS) multiplicative_expression)*
	;

multiplicative_expression
	: switch_expression ((STAR | DIV | PERCENT) switch_expression)*
	;

switch_expression
	: unary_expression (SWITCH OPEN_BRACE (switch_expression_arms COMMA?)? CLOSE_BRACE)?
	;

switch_expression_arms
	: switch_expression_arm (COMMA switch_expression_arm)*
	;

switch_expression_arm
	: expression case_guard? right_arrow throwable_expression
	;

// https://msdn.microsoft.com/library/6a71f45d(v=vs.110).aspx
unary_expression
	: primary_expression
	| PLUS unary_expression
	| MINUS unary_expression
	| BANG unary_expression
	| TILDE unary_expression
	| OP_INC unary_expression
	| OP_DEC unary_expression
	| OPEN_PARENS type_ CLOSE_PARENS unary_expression
	| STAR unary_expression
	;

primary_expression  // Null-conditional operators C# 6: https://msdn.microsoft.com/en-us/library/dn986595.aspx
	: pe=primary_expression_start BANG? bracket_expression* BANG?
	  (((member_access | method_invocation | OP_INC | OP_DEC) BANG?) bracket_expression* BANG?)*
	;

primary_expression_start
	: literal                                   #literalExpression
	| identifier type_argument_list?            #simpleNameExpression
	| OPEN_PARENS expression CLOSE_PARENS       #parenthesisExpressions
	| predefined_type                           #memberAccessExpression
	| qualified_alias_member                    #memberAccessExpression
	| LITERAL_ACCESS                            #literalAccessExpression
	| THIS                                      #thisReferenceExpression
	| BASE (DOT identifier type_argument_list? | OPEN_BRACKET expression_list CLOSE_BRACKET) #baseAccessExpression
	| NEW (type_ (object_creation_expression
	             | object_or_collection_initializer
	             | OPEN_BRACKET expression_list CLOSE_BRACKET rank_specifier* array_initializer?
	             | rank_specifier+ array_initializer)
	      | anonymous_object_initializer
	      | rank_specifier array_initializer)                       #objectCreationExpression
	| TYPEOF OPEN_PARENS (unbound_type_name | type_ | VOID) CLOSE_PARENS   #typeofExpression
	| DEFAULT (OPEN_PARENS type_ CLOSE_PARENS)?                     #defaultValueExpression
	| SIZEOF OPEN_PARENS type_ CLOSE_PARENS                          #sizeofExpression
	// C# 6: https://msdn.microsoft.com/en-us/library/dn986596.aspx
	| NAMEOF OPEN_PARENS (identifier DOT)* identifier CLOSE_PARENS  #nameofExpression
	;

throwable_expression
	: expression
	| throw_expression
	;

throw_expression
	: THROW expression
	;

member_access
	: DOT identifier type_argument_list?
	;

bracket_expression
	: OPEN_BRACKET indexer_argument ( COMMA indexer_argument)* CLOSE_BRACKET
	;

indexer_argument
	: (identifier COLON)? expression
	;

predefined_type
	: BOOL | CHAR | DOUBLE | FLOAT | INT
	| OBJECT | STRING | UINT
	;

expression_list
	: expression (COMMA expression)*
	;

object_or_collection_initializer
	: object_initializer
	| collection_initializer
	;

object_initializer
	: OPEN_BRACE (member_initializer_list COMMA?)? CLOSE_BRACE
	;

member_initializer_list
	: member_initializer (COMMA member_initializer)*
	;

member_initializer
	: (identifier | OPEN_BRACKET expression CLOSE_BRACKET) ASSIGNMENT initializer_value // C# 6
	;

initializer_value
	: expression
	| object_or_collection_initializer
	;

collection_initializer
	: OPEN_BRACE element_initializer (COMMA element_initializer)* COMMA? CLOSE_BRACE
	;

element_initializer
	: non_assignment_expression
	| OPEN_BRACE expression_list CLOSE_BRACE
	;

anonymous_object_initializer
	: OPEN_BRACE (member_declarator_list COMMA?)? CLOSE_BRACE
	;

member_declarator_list
	: member_declarator ( COMMA member_declarator)*
	;

member_declarator
	: primary_expression
	| identifier ASSIGNMENT expression
	;

unbound_type_name
	: identifier ( generic_dimension_specifier? | DOUBLE_COLON identifier generic_dimension_specifier?)
	  (DOT identifier generic_dimension_specifier?)*
	;

generic_dimension_specifier
	: LT COMMA* GT
	;

isType
	: base_type (rank_specifier | STAR)* isTypePatternArms? identifier?
	;

isTypePatternArms
	: OPEN_BRACE isTypePatternArm (COMMA isTypePatternArm)* CLOSE_BRACE
	;

isTypePatternArm
	: identifier COLON expression
	;

where_clause
	: WHERE expression
	;


// Statements

statement
	: labeled_Statement
	| declarationStatement
	| embedded_statement
	;

declarationStatement
	: local_variable_declaration SEMICOLON
	| local_constant_declaration SEMICOLON
	;

labeled_Statement
	: identifier COLON statement
	;

embedded_statement
	: block
	| simple_embedded_statement
	;

simple_embedded_statement
	: SEMICOLON                                                         #theEmptyStatement
	| expression SEMICOLON                                              #expressionStatement

	// selection statements
	| IF OPEN_PARENS expression CLOSE_PARENS if_body (ELSE if_body)?               #ifStatement
	| SWITCH OPEN_PARENS expression CLOSE_PARENS OPEN_BRACE switch_section* CLOSE_BRACE           #switchStatement

	// iteration statements
	| WHILE OPEN_PARENS expression CLOSE_PARENS embedded_statement                                        #whileStatement
	| DO embedded_statement WHILE OPEN_PARENS expression CLOSE_PARENS SEMICOLON                                 #doStatement
	| FOR OPEN_PARENS for_initializer? SEMICOLON expression? SEMICOLON for_iterator? CLOSE_PARENS embedded_statement  #forStatement
	| FOREACH OPEN_PARENS local_variable_type identifier IN expression CLOSE_PARENS embedded_statement    #foreachStatement

	// jump statements
	| BREAK SEMICOLON                                                   #breakStatement
	| CONTINUE SEMICOLON                                                #continueStatement
	| GOTO (identifier | CASE expression | DEFAULT) SEMICOLON           #gotoStatement
	| RETURN expression? SEMICOLON                                      #returnStatement
	| THROW expression? SEMICOLON                                       #throwStatement

	| TRY block (catch_clauses finally_clause? | finally_clause)  #tryStatement
	| USING OPEN_PARENS resource_acquisition CLOSE_PARENS embedded_statement       #usingStatement
	;

block
	: OPEN_BRACE statement_list? CLOSE_BRACE
	;

local_variable_declaration
	: (USING | REF | REF READONLY)? local_variable_type local_variable_declarator ( COMMA  local_variable_declarator)*
	;

local_variable_type 
	: VAR
	| type_
	;

local_variable_declarator
	: identifier (ASSIGNMENT REF? local_variable_initializer)?
	;

local_variable_initializer
	: expression
	| array_initializer
	;

local_constant_declaration
	: CONST type_ constant_declarators
	;

if_body
	: block
	| simple_embedded_statement
	;

switch_section
	: switch_label+ statement_list
	;

switch_label
	: CASE expression case_guard? COLON
	| DEFAULT COLON
	;

case_guard
	: WHEN expression
	;

statement_list
	: statement+
	;

for_initializer
	: local_variable_declaration
	| expression (COMMA  expression)*
	;

for_iterator
	: expression (COMMA  expression)*
	;

catch_clauses
	: specific_catch_clause (specific_catch_clause)* general_catch_clause?
	| general_catch_clause
	;

specific_catch_clause
	: CATCH OPEN_PARENS class_type identifier? CLOSE_PARENS exception_filter? block
	;

general_catch_clause
	: CATCH exception_filter? block
	;

exception_filter // C# 6
	: WHEN OPEN_PARENS expression CLOSE_PARENS
	;

finally_clause
	: FINALLY block
	;

resource_acquisition
	: local_variable_declaration
	| expression
	;

//B.2.6 Namespaces;
namespace_declaration
	: NAMESPACE qi=qualified_identifier namespace_body SEMICOLON?
	;

qualified_identifier
	: identifier ( DOT identifier )*
	;

namespace_body
	: OPEN_BRACE using_directives? namespace_member_declarations? CLOSE_BRACE
	;

using_directives
	: using_directive+
	;

using_directive
	: USING identifier ASSIGNMENT namespace_or_type_name SEMICOLON     #usingAliasDirective
	| USING namespace_or_type_name SEMICOLON                           #usingNamespaceDirective
	// C# 6: https://msdn.microsoft.com/en-us/library/ms228593.aspx
	| USING STATIC namespace_or_type_name SEMICOLON                    #usingStaticDirective
	;

namespace_member_declarations
	: namespace_member_declaration+
	;

namespace_member_declaration
	: namespace_declaration
	| type_declaration
	;

type_declaration
	: class_definition      #classDefinition
	| interface_definition  #interfaceDefinition
	| enum_definition       #enumDefinition
	;

qualified_alias_member
	: identifier DOUBLE_COLON identifier type_argument_list?
	;

//B.2.7 Classes;
type_parameter_list
	: LT type_parameter (COMMA type_parameter)* GT
	;

type_parameter
	: identifier
	;

class_base
	//: COLON class_type (COMMA namespace_or_type_name)*
	: COLON class_type
	;

interface_type_list
	: namespace_or_type_name (COMMA namespace_or_type_name)*
	;

type_parameter_constraints_clauses
	: type_parameter_constraints_clause+
	;

type_parameter_constraints_clause
	: WHERE identifier COLON type_parameter_constraints
	;

type_parameter_constraints
	: constructor_constraint
	| primary_constraint (COMMA secondary_constraints)? (COMMA constructor_constraint)?
	;

primary_constraint
	: class_type
	| CLASS
	;

// namespace_or_type_name includes identifier
secondary_constraints
	: namespace_or_type_name (COMMA namespace_or_type_name)*
	;

constructor_constraint
	: NEW OPEN_PARENS CLOSE_PARENS
	;

class_body
	: OPEN_BRACE class_member_declarations? CLOSE_BRACE
	;

class_member_declarations
	: class_member_declaration+
	;

class_member_declaration
	: all_member_modifiers? (common_member_declaration | destructor_definition)
	;

class_modifier
    : NEW
	| PUBLIC
	| PROTECTED
	| INTERNAL
	| PRIVATE
    | ABSTRACT
	| ABSTRACT
	| STATIC
    ;

// all_member_modifiers
// 	: all_member_modifier+
// 	;

// all_member_modifier
// 	: NEW
// 	| PUBLIC
// 	| PROTECTED
// 	| INTERNAL
// 	| PRIVATE
// 	| READONLY
// 	| VIRTUAL
// 	| SEALED
// 	| OVERRIDE
// 	| ABSTRACT
// 	| STATIC
// 	;

// represents the intersection of struct_member_declaration and class_member_declaration
common_member_declaration
	: constant_declaration
	| typed_member_declaration
	| conversion_operator_declarator (body | right_arrow throwable_expression SEMICOLON) // C# 6
	| constructor_declaration
	| VOID method_declaration
	| class_definition
	| interface_definition
	| enum_definition
	;

typed_member_declaration
	: (REF | READONLY REF | REF READONLY)? type_
	  ( namespace_or_type_name DOT indexer_declaration
	  | method_declaration
	  | property_declaration
	  | indexer_declaration
	  | operator_declaration
	  | field_declaration
	  )
	;

constant_declarators
	: constant_declarator (COMMA  constant_declarator)*
	;

constant_declarator
	: identifier ASSIGNMENT expression
	;

variable_declarators
	: variable_declarator (COMMA  variable_declarator)*
	;

variable_declarator
	: identifier (ASSIGNMENT variable_initializer)?
	;

variable_initializer
	: expression
	| array_initializer
	;

return_type
	: type_
	| VOID
	;

member_name
	: namespace_or_type_name
	;

method_body
	: block
	| SEMICOLON
	;

formal_parameter_list
	: parameter_array
	| fixed_parameters (COMMA parameter_array)?
	;

fixed_parameters
	: fixed_parameter ( COMMA fixed_parameter )*
	;

fixed_parameter
	: parameter_modifier? arg_declaration
	;

parameter_modifier
	: REF
	| OUT
	| IN
	| REF THIS
	| IN THIS
	| THIS
	;

parameter_array
	: PARAMS array_type identifier
	;

accessor_declarations
	: mods=accessor_modifier?
	  (GET accessor_body set_accessor_declaration? | SET accessor_body get_accessor_declaration?)
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

overloadable_operator
	: PLUS
	| MINUS
	| BANG
	| TILDE
	| OP_INC
	| OP_DEC
	| TRUE
	| FALSE
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
	: (IMPLICIT | EXPLICIT) OPERATOR type_ OPEN_PARENS arg_declaration CLOSE_PARENS
	;

constructor_initializer
	: COLON (BASE | THIS) OPEN_PARENS argument_list? CLOSE_PARENS
	;

body
	: block
	| SEMICOLON
	;

// Arrays
array_type
	: base_type ((STAR | INTERR)* rank_specifier)+
	;

rank_specifier
	: OPEN_BRACKET COMMA* CLOSE_BRACKET
	;

array_initializer
	: OPEN_BRACE (variable_initializer (COMMA  variable_initializer)* COMMA?)? CLOSE_BRACE
	;

// Interfaces
variant_type_parameter_list
	: LT variant_type_parameter (COMMA variant_type_parameter)* GT
	;

variant_type_parameter
	: variance_annotation? identifier
	;

variance_annotation
	: IN | OUT
	;

interface_base
	: COLON interface_type_list
	;

interface_body // ignored in csharp 8
	: OPEN_BRACE interface_member_declaration* CLOSE_BRACE
	;

interface_member_declaration
	: NEW?
	  ((REF | REF READONLY | READONLY REF)? type_
	    ( identifier type_parameter_list? OPEN_PARENS formal_parameter_list? CLOSE_PARENS type_parameter_constraints_clauses? SEMICOLON
	    | identifier OPEN_BRACE interface_accessors CLOSE_BRACE
	    | THIS OPEN_BRACKET formal_parameter_list CLOSE_BRACKET OPEN_BRACE interface_accessors CLOSE_BRACE)
	  | VOID identifier type_parameter_list? OPEN_PARENS formal_parameter_list? CLOSE_PARENS type_parameter_constraints_clauses? SEMICOLON)
	;

interface_accessors
	: (GET SEMICOLON (SET SEMICOLON)? | SET SEMICOLON (GET SEMICOLON)?)
	;

interface_modifier
	: NEW
	| PUBLIC
	| PROTECTED
	| INTERNAL
	| PRIVATE
	;

// Enums
enum_base
	: COLON integral_type
	;

enum_body
	: OPEN_BRACE (enum_member_declaration (COMMA  enum_member_declaration)* COMMA?)? CLOSE_BRACE
	;

enum_member_declaration
	: identifier (ASSIGNMENT expression)?
	;

enum_modifer
	: NEW
	| PUBLIC
	| PROTECTED
	| INTERNAL
	| PRIVATE
	;

right_arrow
	: first=ASSIGNMENT second=GT {$first.index + 1 == $second.index}? // Nothing between the tokens?
	;

right_shift
	: first=GT second=GT {$first.index + 1 == $second.index}? // Nothing between the tokens?
	;

right_shift_assignment
	: first=GT second=OP_GE {$first.index + 1 == $second.index}? // Nothing between the tokens?
	;

literal
	: boolean_literal
	| string_literal
	| INTEGER_LITERAL
	| HEX_INTEGER_LITERAL
	| REAL_LITERAL
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

// Keywords
keyword
    : ABSTRACT
    | AS
    | BASE
    | BOOL
    | BREAK
    | CASE
    | CATCH
    | CHAR
    | CLASS
    | CONST
    | CONTINUE
    | DEFAULT
    | DO
    | DOUBLE
    | ELSE
    | ENUM
    | EXPLICIT
    | FALSE
    | FINALLY
    | FLOAT
    | FOR
    | FOREACH
    | GET
    | GOTO
    | IF
    | IMPLICIT
    | IN
    | INT
    | INTERFACE
    | INTERNAL
    | NAMEOF
    | NAMESPACE
    | NEW
    | NULL_
    | OBJECT
    | OPERATOR
    | OUT
    | OVERRIDE
    | PARAMS
    | PRIVATE
    | PROTECTED
    | PUBLIC
    | READONLY
    | REF
    | RETURN
    | SEALED
    | SET
    | SIZEOF
    | STATIC
    | STRING
    | SWITCH
    | THIS
    | THROW
    | TRUE
    | TRY
    | TYPEOF
    | UINT
    | USING
    | VAR
    | VIRTUAL
    | VOID
    | WHEN
    | WHERE
    | WHILE
	;

// Miscellaneous rules

class_definition
	: class_modifier* CLASS identifier type_parameter_list? class_base? type_parameter_constraints_clauses?
	  class_body SEMICOLON?
	;

interface_definition
	: interface_modifier* INTERFACE identifier variant_type_parameter_list? interface_base?
	  type_parameter_constraints_clauses? class_body SEMICOLON?
	;

enum_definition
	: enum_modifier* ENUM identifier enum_base? enum_body SEMICOLON?
	;

field_declaration
	: variable_declarators SEMICOLON
	;

property_declaration // Property initializer & lambda in properties C# 6
	: member_name (OPEN_BRACE accessor_declarations CLOSE_BRACE (ASSIGNMENT variable_initializer SEMICOLON)? | right_arrow throwable_expression SEMICOLON)
	;

constant_declaration
	: CONST type_ constant_declarators SEMICOLON
	;

indexer_declaration // lamdas from C# 6
	: THIS OPEN_BRACKET formal_parameter_list CLOSE_BRACKET (OPEN_BRACE accessor_declarations CLOSE_BRACE | right_arrow throwable_expression SEMICOLON)
	;

destructor_definition
	: TILDE identifier OPEN_PARENS CLOSE_PARENS body
	;

constructor_declaration
	: identifier OPEN_PARENS formal_parameter_list? CLOSE_PARENS constructor_initializer? body
	;

method_declaration // lamdas from C# 6
	: method_member_name type_parameter_list? OPEN_PARENS formal_parameter_list? CLOSE_PARENS
	  type_parameter_constraints_clauses? method_body
	;

method_member_name
	: (identifier | identifier DOUBLE_COLON identifier) (type_argument_list? DOT identifier)*
	;

operator_declaration // lamdas form C# 6
	: OPERATOR overloadable_operator OPEN_PARENS IN? arg_declaration
	  (COMMA IN? arg_declaration)? CLOSE_PARENS (body | right_arrow throwable_expression SEMICOLON)
	;

arg_declaration
	: type_ identifier (ASSIGNMENT expression)?
	;

method_invocation
	: OPEN_PARENS argument_list? CLOSE_PARENS
	;

object_creation_expression
	: OPEN_PARENS argument_list? CLOSE_PARENS object_or_collection_initializer?
	;

identifier
	: IDENTIFIER
	| GET
	| NAMEOF
	| SET
	| VAR
	| WHEN
	| WHERE
	;