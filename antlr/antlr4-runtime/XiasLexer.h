
// Generated from c:\dev\Xias\antlr\XiasLexer.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  XiasLexer : public antlr4::Lexer {
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
    COMMENTS_CHANNEL = 2
  };

  XiasLexer(antlr4::CharStream *input);
  ~XiasLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

