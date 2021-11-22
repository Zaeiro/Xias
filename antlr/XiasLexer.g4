lexer grammar XiasLexer;

channels { COMMENTS_CHANNEL }

WHITESPACES
    : (Whitespace | NewLine)+ -> channel(HIDDEN)
    ;

fragment NewLineCharacter
    : ('\r'? '\n' | '\r')
    ;

fragment NewLine
    : NewLineCharacter
    ;

fragment Whitespace
    : ' '
    | '\t'
    | '\f'
    ;

// Comments

SINGLE_LINE_DOC_COMMENT 
    : '///' Input_character* -> channel(COMMENTS_CHANNEL)
    ;

DELIMITED_DOC_COMMENT 
    : '/**' Delimited_comment_section* Asterisks '/' -> channel(COMMENTS_CHANNEL)
    ;

SINGLE_LINE_COMMENT 
    : '//' Input_character* -> channel(COMMENTS_CHANNEL)
    ;

fragment Input_characters
    : Input_character+
    ;

fragment Input_character 
    : ~[\n\r]
    ;

DELIMITED_COMMENT 
    : '/*' Delimited_comment_section* Asterisks '/' -> channel(COMMENTS_CHANNEL)
    ;

fragment Delimited_comment_section 
    : '/'
    | Asterisks? Not_slash_or_asterisk
    ;

fragment Asterisks 
    : '*'+
    ;

fragment Not_slash_or_asterisk 
    : ~( '/' | '*' )
    ;

// Keywords

ABSTRACT : 'abstract';
AS : 'as';
IS : 'is';
BASE : 'base';
BOOL : 'bool';
BREAK : 'break';
CASE : 'case';
CATCH : 'catch';
CHAR : 'char';
CLASS : 'class';
CONST : 'const';
CONTINUE : 'continue';
DEFAULT : 'default';
DO : 'do';
DOUBLE : 'double';
ELSE : 'else';
ENUM : 'enum';
EXTERN : 'extern';
EXPLICIT : 'explicit';
FALSE : 'false';
FINALLY : 'finally';
FLOAT : 'float';
FOR : 'for';
FOREACH : 'foreach';
GET : 'get';
GOTO : 'goto';
IF : 'if';
IMPLICIT : 'implicit';
IN : 'in';
INT : 'int';
INTERFACE : 'interface';
INTERNAL : 'internal';
NAMEOF : 'nameof';
NAMESPACE : 'namespace';
NEW : 'new';
NULL_ : 'null';
OBJECT : 'object';
OPERATOR : 'operator';
OUT : 'out';
OVERRIDE : 'override';
PARAMS : 'params';
PRIVATE : 'private';
PROTECTED : 'protected';
PUBLIC : 'public';
READONLY : 'readonly';
REF : 'ref';
RETURN : 'return';
SEALED : 'sealed';
SET : 'set';
SIZEOF : 'sizeof';
STATIC : 'static';
STRING : 'string';
SWITCH : 'switch';
THIS : 'this';
THROW : 'throw';
TRUE : 'true';
TRY : 'try';
TYPEOF : 'typeof';
UINT : 'uint';
USING : 'using';
VAR : 'var';
VIRTUAL : 'virtual';
VOID : 'void';
WHEN : 'when';
WHERE : 'where';
WHILE : 'while';

IDENTIFIER
    : Identifier_start_character Identifier_part_character*
    ;

fragment Identifier_start_character
    : Letter_character
    | '_'
    ;

fragment Identifier_part_character 
  : Letter_character
  | Decimal_digit_character
  | '_'
  ;

fragment Decimal_digit_character 
  : DECIMAL_DIGIT
  ;

fragment Letter_character 
  : UPPERCASE_LETTER
  | LOWERCASE_LETTER
  ;

// Literals

LITERAL_ACCESS
    : [0-9] ('_'* [0-9])* Integer_type_suffix? '.' IDENTIFIER
    ;

INTEGER_LITERAL
    : [0-9] ('_'* [0-9])*
    ;

UNSIGNED_LITERAL
    : [0-9] ('_'* [0-9])* [Uu]
    ;

HEX_INTEGER_LITERAL
    : '0' [xX] ('_'* Hex_digit)+ Integer_type_suffix?
    ;

fragment Integer_type_suffix 
    : 'U'
    | 'u'
    ;

fragment Hex_digit
    : [0-9]
    | [A-F]
    | [a-f]
    ;

FLOAT_LITERAL
    : ([0-9] ('_'* [0-9])*)? '.' [0-9] ('_'* [0-9])* Exponent_part? [Ff]?
    | [0-9] ('_'* [0-9])* ([Ff] | Exponent_part [Ff]?)
    ;

DOUBLE_LITERAL
    : ([0-9] ('_'* [0-9])*)? '.' [0-9] ('_'* [0-9])* Exponent_part? [Dd]?
    | [0-9] ('_'* [0-9])* ([Dd] | Exponent_part [Dd]?)
    ;

fragment Exponent_part
    : [eE] ('+' | '-')? [0-9] ('_'* [0-9])*
    ;

CHARACTER_LITERAL 
    : '\'' (~['\\\r\n] | Simple_escape_sequence) '\''
    ;

fragment Simple_escape_sequence 
    : '\\\''
    | '\\"'
    | DOUBLE_BACK_SLASH
    | '\\0'
    | '\\a'
    | '\\b'
    | '\\f'
    | '\\n'
    | '\\r'
    | '\\t'
    | '\\v'
    ;

REGULAR_STRING
    : '"'  (~["\\\r\n] | Simple_escape_sequence)* '"'
    ;

VERBATIUM_STRING
    : '@"' (~'"' | '""')* '"'
    ;

// Operators And Punctuators

OPEN_BRACE : '{';
CLOSE_BRACE : '}';
OPEN_BRACKET : '[';
CLOSE_BRACKET : ']';
OPEN_PARENS : '(';
CLOSE_PARENS : ')';
DOT : '.';
COMMA : ',';
COLON : ':';
SEMICOLON : ';';
PLUS : '+';
MINUS : '-';
STAR : '*';
DIV : '/';
PERCENT : '%';
AMP : '&';
BITWISE_OR : '|';
CARET : '^';
BANG : '!';
TILDE : '~';
ASSIGNMENT : '=';
LT : '<';
GT : '>';
INTERR : '?';
DOUBLE_COLON : '::';
OP_COALESCING : '??';
OP_INC : '++';
OP_DEC : '--';
OP_AND : '&&';
OP_OR : '||';
OP_PTR : '->';
OP_EQ : '==';
OP_NE : '!=';
OP_LE : '<=';
OP_GE : '>=';
OP_ADD_ASSIGNMENT : '+=';
OP_SUB_ASSIGNMENT : '-=';
OP_MULT_ASSIGNMENT : '*=';
OP_DIV_ASSIGNMENT : '/=';
OP_MOD_ASSIGNMENT : '%=';
OP_AND_ASSIGNMENT : '&=';
OP_OR_ASSIGNMENT : '|=';
OP_XOR_ASSIGNMENT : '^=';
OP_LEFT_SHIFT : '<<';
OP_LEFT_SHIFT_ASSIGNMENT : '<<=';
OP_COALESCING_ASSIGNMENT: '??=';

QUOTE :             '\'';
DOUBLE_QUOTE :      '"';
BACK_SLASH :        '\\';
DOUBLE_BACK_SLASH : '\\\\';
SHARP :             '#';

fragment UPPERCASE_LETTER
    : [A-Z]
    ;

fragment LOWERCASE_LETTER
    : [a-z]
    ;

fragment DECIMAL_DIGIT
    : [0-9]
    ;