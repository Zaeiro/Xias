
// Generated from ..\antlr\XiasParser.g4 by ANTLR 4.9.2


#include "XiasParserVisitor.h"

#include "XiasParser.h"


using namespace antlrcpp;
using namespace antlr4;

XiasParser::XiasParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

XiasParser::~XiasParser() {
  delete _interpreter;
}

std::string XiasParser::getGrammarFileName() const {
  return "XiasParser.g4";
}

const std::vector<std::string>& XiasParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& XiasParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- Compilation_unitContext ------------------------------------------------------------------

XiasParser::Compilation_unitContext::Compilation_unitContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Compilation_unitContext::EOF() {
  return getToken(XiasParser::EOF, 0);
}

std::vector<XiasParser::Using_directiveContext *> XiasParser::Compilation_unitContext::using_directive() {
  return getRuleContexts<XiasParser::Using_directiveContext>();
}

XiasParser::Using_directiveContext* XiasParser::Compilation_unitContext::using_directive(size_t i) {
  return getRuleContext<XiasParser::Using_directiveContext>(i);
}

std::vector<XiasParser::Namespace_member_declarationContext *> XiasParser::Compilation_unitContext::namespace_member_declaration() {
  return getRuleContexts<XiasParser::Namespace_member_declarationContext>();
}

XiasParser::Namespace_member_declarationContext* XiasParser::Compilation_unitContext::namespace_member_declaration(size_t i) {
  return getRuleContext<XiasParser::Namespace_member_declarationContext>(i);
}


size_t XiasParser::Compilation_unitContext::getRuleIndex() const {
  return XiasParser::RuleCompilation_unit;
}


antlrcpp::Any XiasParser::Compilation_unitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitCompilation_unit(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Compilation_unitContext* XiasParser::compilation_unit() {
  Compilation_unitContext *_localctx = _tracker.createInstance<Compilation_unitContext>(_ctx, getState());
  enterRule(_localctx, 0, XiasParser::RuleCompilation_unit);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(411);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == XiasParser::USING) {
      setState(408);
      using_directive();
      setState(413);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(417);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 6) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 6)) & ((1ULL << (XiasParser::ABSTRACT - 6))
      | (1ULL << (XiasParser::CLASS - 6))
      | (1ULL << (XiasParser::EXTERN - 6))
      | (1ULL << (XiasParser::INTERFACE - 6))
      | (1ULL << (XiasParser::INTERNAL - 6))
      | (1ULL << (XiasParser::NAMESPACE - 6))
      | (1ULL << (XiasParser::NEW - 6))
      | (1ULL << (XiasParser::OVERRIDE - 6))
      | (1ULL << (XiasParser::PRIVATE - 6))
      | (1ULL << (XiasParser::PROTECTED - 6))
      | (1ULL << (XiasParser::PUBLIC - 6))
      | (1ULL << (XiasParser::READONLY - 6))
      | (1ULL << (XiasParser::SEALED - 6))
      | (1ULL << (XiasParser::STATIC - 6))
      | (1ULL << (XiasParser::VIRTUAL - 6)))) != 0)) {
      setState(414);
      namespace_member_declaration();
      setState(419);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(420);
    match(XiasParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Using_directiveContext ------------------------------------------------------------------

XiasParser::Using_directiveContext::Using_directiveContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}


size_t XiasParser::Using_directiveContext::getRuleIndex() const {
  return XiasParser::RuleUsing_directive;
}

void XiasParser::Using_directiveContext::copyFrom(Using_directiveContext *ctx) {
  antlr4::RuleContextWithAltNum::copyFrom(ctx);
}

//----------------- UsingAliasDirectiveContext ------------------------------------------------------------------

tree::TerminalNode* XiasParser::UsingAliasDirectiveContext::USING() {
  return getToken(XiasParser::USING, 0);
}

XiasParser::IdentifierContext* XiasParser::UsingAliasDirectiveContext::identifier() {
  return getRuleContext<XiasParser::IdentifierContext>(0);
}

tree::TerminalNode* XiasParser::UsingAliasDirectiveContext::ASSIGNMENT() {
  return getToken(XiasParser::ASSIGNMENT, 0);
}

XiasParser::Namespace_or_type_nameContext* XiasParser::UsingAliasDirectiveContext::namespace_or_type_name() {
  return getRuleContext<XiasParser::Namespace_or_type_nameContext>(0);
}

tree::TerminalNode* XiasParser::UsingAliasDirectiveContext::SEMICOLON() {
  return getToken(XiasParser::SEMICOLON, 0);
}

XiasParser::UsingAliasDirectiveContext::UsingAliasDirectiveContext(Using_directiveContext *ctx) { copyFrom(ctx); }


antlrcpp::Any XiasParser::UsingAliasDirectiveContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitUsingAliasDirective(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UsingNamespaceDirectiveContext ------------------------------------------------------------------

tree::TerminalNode* XiasParser::UsingNamespaceDirectiveContext::USING() {
  return getToken(XiasParser::USING, 0);
}

XiasParser::Namespace_or_type_nameContext* XiasParser::UsingNamespaceDirectiveContext::namespace_or_type_name() {
  return getRuleContext<XiasParser::Namespace_or_type_nameContext>(0);
}

tree::TerminalNode* XiasParser::UsingNamespaceDirectiveContext::SEMICOLON() {
  return getToken(XiasParser::SEMICOLON, 0);
}

XiasParser::UsingNamespaceDirectiveContext::UsingNamespaceDirectiveContext(Using_directiveContext *ctx) { copyFrom(ctx); }


antlrcpp::Any XiasParser::UsingNamespaceDirectiveContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitUsingNamespaceDirective(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UsingStaticDirectiveContext ------------------------------------------------------------------

tree::TerminalNode* XiasParser::UsingStaticDirectiveContext::USING() {
  return getToken(XiasParser::USING, 0);
}

tree::TerminalNode* XiasParser::UsingStaticDirectiveContext::STATIC() {
  return getToken(XiasParser::STATIC, 0);
}

XiasParser::Namespace_or_type_nameContext* XiasParser::UsingStaticDirectiveContext::namespace_or_type_name() {
  return getRuleContext<XiasParser::Namespace_or_type_nameContext>(0);
}

tree::TerminalNode* XiasParser::UsingStaticDirectiveContext::SEMICOLON() {
  return getToken(XiasParser::SEMICOLON, 0);
}

XiasParser::UsingStaticDirectiveContext::UsingStaticDirectiveContext(Using_directiveContext *ctx) { copyFrom(ctx); }


antlrcpp::Any XiasParser::UsingStaticDirectiveContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitUsingStaticDirective(this);
  else
    return visitor->visitChildren(this);
}
XiasParser::Using_directiveContext* XiasParser::using_directive() {
  Using_directiveContext *_localctx = _tracker.createInstance<Using_directiveContext>(_ctx, getState());
  enterRule(_localctx, 2, XiasParser::RuleUsing_directive);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(437);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<Using_directiveContext *>(_tracker.createInstance<XiasParser::UsingAliasDirectiveContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(422);
      match(XiasParser::USING);
      setState(423);
      identifier();
      setState(424);
      match(XiasParser::ASSIGNMENT);
      setState(425);
      namespace_or_type_name(0);
      setState(426);
      match(XiasParser::SEMICOLON);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<Using_directiveContext *>(_tracker.createInstance<XiasParser::UsingNamespaceDirectiveContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(428);
      match(XiasParser::USING);
      setState(429);
      namespace_or_type_name(0);
      setState(430);
      match(XiasParser::SEMICOLON);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<Using_directiveContext *>(_tracker.createInstance<XiasParser::UsingStaticDirectiveContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(432);
      match(XiasParser::USING);
      setState(433);
      match(XiasParser::STATIC);
      setState(434);
      namespace_or_type_name(0);
      setState(435);
      match(XiasParser::SEMICOLON);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Namespace_member_declarationContext ------------------------------------------------------------------

XiasParser::Namespace_member_declarationContext::Namespace_member_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Namespace_declarationContext* XiasParser::Namespace_member_declarationContext::namespace_declaration() {
  return getRuleContext<XiasParser::Namespace_declarationContext>(0);
}

XiasParser::Type_declarationContext* XiasParser::Namespace_member_declarationContext::type_declaration() {
  return getRuleContext<XiasParser::Type_declarationContext>(0);
}


size_t XiasParser::Namespace_member_declarationContext::getRuleIndex() const {
  return XiasParser::RuleNamespace_member_declaration;
}


antlrcpp::Any XiasParser::Namespace_member_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitNamespace_member_declaration(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Namespace_member_declarationContext* XiasParser::namespace_member_declaration() {
  Namespace_member_declarationContext *_localctx = _tracker.createInstance<Namespace_member_declarationContext>(_ctx, getState());
  enterRule(_localctx, 4, XiasParser::RuleNamespace_member_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(441);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case XiasParser::NAMESPACE: {
        enterOuterAlt(_localctx, 1);
        setState(439);
        namespace_declaration();
        break;
      }

      case XiasParser::ABSTRACT:
      case XiasParser::CLASS:
      case XiasParser::EXTERN:
      case XiasParser::INTERFACE:
      case XiasParser::INTERNAL:
      case XiasParser::NEW:
      case XiasParser::OVERRIDE:
      case XiasParser::PRIVATE:
      case XiasParser::PROTECTED:
      case XiasParser::PUBLIC:
      case XiasParser::READONLY:
      case XiasParser::SEALED:
      case XiasParser::STATIC:
      case XiasParser::VIRTUAL: {
        enterOuterAlt(_localctx, 2);
        setState(440);
        type_declaration();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Namespace_declarationContext ------------------------------------------------------------------

XiasParser::Namespace_declarationContext::Namespace_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Namespace_declarationContext::NAMESPACE() {
  return getToken(XiasParser::NAMESPACE, 0);
}

XiasParser::Namespace_bodyContext* XiasParser::Namespace_declarationContext::namespace_body() {
  return getRuleContext<XiasParser::Namespace_bodyContext>(0);
}

XiasParser::Qualified_identifierContext* XiasParser::Namespace_declarationContext::qualified_identifier() {
  return getRuleContext<XiasParser::Qualified_identifierContext>(0);
}

tree::TerminalNode* XiasParser::Namespace_declarationContext::SEMICOLON() {
  return getToken(XiasParser::SEMICOLON, 0);
}


size_t XiasParser::Namespace_declarationContext::getRuleIndex() const {
  return XiasParser::RuleNamespace_declaration;
}


antlrcpp::Any XiasParser::Namespace_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitNamespace_declaration(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Namespace_declarationContext* XiasParser::namespace_declaration() {
  Namespace_declarationContext *_localctx = _tracker.createInstance<Namespace_declarationContext>(_ctx, getState());
  enterRule(_localctx, 6, XiasParser::RuleNamespace_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(443);
    match(XiasParser::NAMESPACE);
    setState(444);
    dynamic_cast<Namespace_declarationContext *>(_localctx)->qi = qualified_identifier();
    setState(445);
    namespace_body();
    setState(447);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == XiasParser::SEMICOLON) {
      setState(446);
      match(XiasParser::SEMICOLON);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Qualified_identifierContext ------------------------------------------------------------------

XiasParser::Qualified_identifierContext::Qualified_identifierContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

std::vector<XiasParser::IdentifierContext *> XiasParser::Qualified_identifierContext::identifier() {
  return getRuleContexts<XiasParser::IdentifierContext>();
}

XiasParser::IdentifierContext* XiasParser::Qualified_identifierContext::identifier(size_t i) {
  return getRuleContext<XiasParser::IdentifierContext>(i);
}

std::vector<tree::TerminalNode *> XiasParser::Qualified_identifierContext::DOT() {
  return getTokens(XiasParser::DOT);
}

tree::TerminalNode* XiasParser::Qualified_identifierContext::DOT(size_t i) {
  return getToken(XiasParser::DOT, i);
}


size_t XiasParser::Qualified_identifierContext::getRuleIndex() const {
  return XiasParser::RuleQualified_identifier;
}


antlrcpp::Any XiasParser::Qualified_identifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitQualified_identifier(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Qualified_identifierContext* XiasParser::qualified_identifier() {
  Qualified_identifierContext *_localctx = _tracker.createInstance<Qualified_identifierContext>(_ctx, getState());
  enterRule(_localctx, 8, XiasParser::RuleQualified_identifier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(449);
    identifier();
    setState(454);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == XiasParser::DOT) {
      setState(450);
      match(XiasParser::DOT);
      setState(451);
      identifier();
      setState(456);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Namespace_bodyContext ------------------------------------------------------------------

XiasParser::Namespace_bodyContext::Namespace_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Namespace_bodyContext::OPEN_BRACE() {
  return getToken(XiasParser::OPEN_BRACE, 0);
}

tree::TerminalNode* XiasParser::Namespace_bodyContext::CLOSE_BRACE() {
  return getToken(XiasParser::CLOSE_BRACE, 0);
}

std::vector<XiasParser::Using_directiveContext *> XiasParser::Namespace_bodyContext::using_directive() {
  return getRuleContexts<XiasParser::Using_directiveContext>();
}

XiasParser::Using_directiveContext* XiasParser::Namespace_bodyContext::using_directive(size_t i) {
  return getRuleContext<XiasParser::Using_directiveContext>(i);
}

std::vector<XiasParser::Namespace_member_declarationContext *> XiasParser::Namespace_bodyContext::namespace_member_declaration() {
  return getRuleContexts<XiasParser::Namespace_member_declarationContext>();
}

XiasParser::Namespace_member_declarationContext* XiasParser::Namespace_bodyContext::namespace_member_declaration(size_t i) {
  return getRuleContext<XiasParser::Namespace_member_declarationContext>(i);
}


size_t XiasParser::Namespace_bodyContext::getRuleIndex() const {
  return XiasParser::RuleNamespace_body;
}


antlrcpp::Any XiasParser::Namespace_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitNamespace_body(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Namespace_bodyContext* XiasParser::namespace_body() {
  Namespace_bodyContext *_localctx = _tracker.createInstance<Namespace_bodyContext>(_ctx, getState());
  enterRule(_localctx, 10, XiasParser::RuleNamespace_body);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(457);
    match(XiasParser::OPEN_BRACE);
    setState(461);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == XiasParser::USING) {
      setState(458);
      using_directive();
      setState(463);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(467);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 6) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 6)) & ((1ULL << (XiasParser::ABSTRACT - 6))
      | (1ULL << (XiasParser::CLASS - 6))
      | (1ULL << (XiasParser::EXTERN - 6))
      | (1ULL << (XiasParser::INTERFACE - 6))
      | (1ULL << (XiasParser::INTERNAL - 6))
      | (1ULL << (XiasParser::NAMESPACE - 6))
      | (1ULL << (XiasParser::NEW - 6))
      | (1ULL << (XiasParser::OVERRIDE - 6))
      | (1ULL << (XiasParser::PRIVATE - 6))
      | (1ULL << (XiasParser::PROTECTED - 6))
      | (1ULL << (XiasParser::PUBLIC - 6))
      | (1ULL << (XiasParser::READONLY - 6))
      | (1ULL << (XiasParser::SEALED - 6))
      | (1ULL << (XiasParser::STATIC - 6))
      | (1ULL << (XiasParser::VIRTUAL - 6)))) != 0)) {
      setState(464);
      namespace_member_declaration();
      setState(469);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(470);
    match(XiasParser::CLOSE_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Qualified_alias_memberContext ------------------------------------------------------------------

XiasParser::Qualified_alias_memberContext::Qualified_alias_memberContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

std::vector<XiasParser::IdentifierContext *> XiasParser::Qualified_alias_memberContext::identifier() {
  return getRuleContexts<XiasParser::IdentifierContext>();
}

XiasParser::IdentifierContext* XiasParser::Qualified_alias_memberContext::identifier(size_t i) {
  return getRuleContext<XiasParser::IdentifierContext>(i);
}

tree::TerminalNode* XiasParser::Qualified_alias_memberContext::DOUBLE_COLON() {
  return getToken(XiasParser::DOUBLE_COLON, 0);
}

XiasParser::Type_argument_listContext* XiasParser::Qualified_alias_memberContext::type_argument_list() {
  return getRuleContext<XiasParser::Type_argument_listContext>(0);
}


size_t XiasParser::Qualified_alias_memberContext::getRuleIndex() const {
  return XiasParser::RuleQualified_alias_member;
}


antlrcpp::Any XiasParser::Qualified_alias_memberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitQualified_alias_member(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Qualified_alias_memberContext* XiasParser::qualified_alias_member() {
  Qualified_alias_memberContext *_localctx = _tracker.createInstance<Qualified_alias_memberContext>(_ctx, getState());
  enterRule(_localctx, 12, XiasParser::RuleQualified_alias_member);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(472);
    identifier();
    setState(473);
    match(XiasParser::DOUBLE_COLON);
    setState(474);
    identifier();
    setState(476);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      setState(475);
      type_argument_list();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_declarationContext ------------------------------------------------------------------

XiasParser::Type_declarationContext::Type_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Class_declarationContext* XiasParser::Type_declarationContext::class_declaration() {
  return getRuleContext<XiasParser::Class_declarationContext>(0);
}

XiasParser::Interface_declarationContext* XiasParser::Type_declarationContext::interface_declaration() {
  return getRuleContext<XiasParser::Interface_declarationContext>(0);
}


size_t XiasParser::Type_declarationContext::getRuleIndex() const {
  return XiasParser::RuleType_declaration;
}


antlrcpp::Any XiasParser::Type_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitType_declaration(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Type_declarationContext* XiasParser::type_declaration() {
  Type_declarationContext *_localctx = _tracker.createInstance<Type_declarationContext>(_ctx, getState());
  enterRule(_localctx, 14, XiasParser::RuleType_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(480);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(478);
      class_declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(479);
      interface_declaration();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_parameter_listContext ------------------------------------------------------------------

XiasParser::Type_parameter_listContext::Type_parameter_listContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Type_parameter_listContext::LT() {
  return getToken(XiasParser::LT, 0);
}

std::vector<XiasParser::Type_parameterContext *> XiasParser::Type_parameter_listContext::type_parameter() {
  return getRuleContexts<XiasParser::Type_parameterContext>();
}

XiasParser::Type_parameterContext* XiasParser::Type_parameter_listContext::type_parameter(size_t i) {
  return getRuleContext<XiasParser::Type_parameterContext>(i);
}

tree::TerminalNode* XiasParser::Type_parameter_listContext::GT() {
  return getToken(XiasParser::GT, 0);
}

std::vector<tree::TerminalNode *> XiasParser::Type_parameter_listContext::COMMA() {
  return getTokens(XiasParser::COMMA);
}

tree::TerminalNode* XiasParser::Type_parameter_listContext::COMMA(size_t i) {
  return getToken(XiasParser::COMMA, i);
}


size_t XiasParser::Type_parameter_listContext::getRuleIndex() const {
  return XiasParser::RuleType_parameter_list;
}


antlrcpp::Any XiasParser::Type_parameter_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitType_parameter_list(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Type_parameter_listContext* XiasParser::type_parameter_list() {
  Type_parameter_listContext *_localctx = _tracker.createInstance<Type_parameter_listContext>(_ctx, getState());
  enterRule(_localctx, 16, XiasParser::RuleType_parameter_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(482);
    match(XiasParser::LT);
    setState(483);
    type_parameter();
    setState(488);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == XiasParser::COMMA) {
      setState(484);
      match(XiasParser::COMMA);
      setState(485);
      type_parameter();
      setState(490);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(491);
    match(XiasParser::GT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_argument_listContext ------------------------------------------------------------------

XiasParser::Type_argument_listContext::Type_argument_listContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Type_argument_listContext::LT() {
  return getToken(XiasParser::LT, 0);
}

std::vector<XiasParser::Type_Context *> XiasParser::Type_argument_listContext::type_() {
  return getRuleContexts<XiasParser::Type_Context>();
}

XiasParser::Type_Context* XiasParser::Type_argument_listContext::type_(size_t i) {
  return getRuleContext<XiasParser::Type_Context>(i);
}

tree::TerminalNode* XiasParser::Type_argument_listContext::GT() {
  return getToken(XiasParser::GT, 0);
}

std::vector<tree::TerminalNode *> XiasParser::Type_argument_listContext::COMMA() {
  return getTokens(XiasParser::COMMA);
}

tree::TerminalNode* XiasParser::Type_argument_listContext::COMMA(size_t i) {
  return getToken(XiasParser::COMMA, i);
}


size_t XiasParser::Type_argument_listContext::getRuleIndex() const {
  return XiasParser::RuleType_argument_list;
}


antlrcpp::Any XiasParser::Type_argument_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitType_argument_list(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Type_argument_listContext* XiasParser::type_argument_list() {
  Type_argument_listContext *_localctx = _tracker.createInstance<Type_argument_listContext>(_ctx, getState());
  enterRule(_localctx, 18, XiasParser::RuleType_argument_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(493);
    match(XiasParser::LT);
    setState(494);
    type_();
    setState(499);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == XiasParser::COMMA) {
      setState(495);
      match(XiasParser::COMMA);
      setState(496);
      type_();
      setState(501);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(502);
    match(XiasParser::GT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_parameterContext ------------------------------------------------------------------

XiasParser::Type_parameterContext::Type_parameterContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::IdentifierContext* XiasParser::Type_parameterContext::identifier() {
  return getRuleContext<XiasParser::IdentifierContext>(0);
}


size_t XiasParser::Type_parameterContext::getRuleIndex() const {
  return XiasParser::RuleType_parameter;
}


antlrcpp::Any XiasParser::Type_parameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitType_parameter(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Type_parameterContext* XiasParser::type_parameter() {
  Type_parameterContext *_localctx = _tracker.createInstance<Type_parameterContext>(_ctx, getState());
  enterRule(_localctx, 20, XiasParser::RuleType_parameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(504);
    identifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_parameter_constraints_clauseContext ------------------------------------------------------------------

XiasParser::Type_parameter_constraints_clauseContext::Type_parameter_constraints_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Type_parameter_constraints_clauseContext::WHERE() {
  return getToken(XiasParser::WHERE, 0);
}

XiasParser::IdentifierContext* XiasParser::Type_parameter_constraints_clauseContext::identifier() {
  return getRuleContext<XiasParser::IdentifierContext>(0);
}

tree::TerminalNode* XiasParser::Type_parameter_constraints_clauseContext::COLON() {
  return getToken(XiasParser::COLON, 0);
}

XiasParser::Type_parameter_constraintsContext* XiasParser::Type_parameter_constraints_clauseContext::type_parameter_constraints() {
  return getRuleContext<XiasParser::Type_parameter_constraintsContext>(0);
}


size_t XiasParser::Type_parameter_constraints_clauseContext::getRuleIndex() const {
  return XiasParser::RuleType_parameter_constraints_clause;
}


antlrcpp::Any XiasParser::Type_parameter_constraints_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitType_parameter_constraints_clause(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Type_parameter_constraints_clauseContext* XiasParser::type_parameter_constraints_clause() {
  Type_parameter_constraints_clauseContext *_localctx = _tracker.createInstance<Type_parameter_constraints_clauseContext>(_ctx, getState());
  enterRule(_localctx, 22, XiasParser::RuleType_parameter_constraints_clause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(506);
    match(XiasParser::WHERE);
    setState(507);
    identifier();
    setState(508);
    match(XiasParser::COLON);
    setState(509);
    type_parameter_constraints();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_parameter_constraintsContext ------------------------------------------------------------------

XiasParser::Type_parameter_constraintsContext::Type_parameter_constraintsContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Class_typeContext* XiasParser::Type_parameter_constraintsContext::class_type() {
  return getRuleContext<XiasParser::Class_typeContext>(0);
}

XiasParser::Constructor_constraintContext* XiasParser::Type_parameter_constraintsContext::constructor_constraint() {
  return getRuleContext<XiasParser::Constructor_constraintContext>(0);
}


size_t XiasParser::Type_parameter_constraintsContext::getRuleIndex() const {
  return XiasParser::RuleType_parameter_constraints;
}


antlrcpp::Any XiasParser::Type_parameter_constraintsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitType_parameter_constraints(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Type_parameter_constraintsContext* XiasParser::type_parameter_constraints() {
  Type_parameter_constraintsContext *_localctx = _tracker.createInstance<Type_parameter_constraintsContext>(_ctx, getState());
  enterRule(_localctx, 24, XiasParser::RuleType_parameter_constraints);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(511);
    class_type();
    setState(513);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == XiasParser::NEW) {
      setState(512);
      constructor_constraint();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Constructor_constraintContext ------------------------------------------------------------------

XiasParser::Constructor_constraintContext::Constructor_constraintContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Constructor_constraintContext::NEW() {
  return getToken(XiasParser::NEW, 0);
}

tree::TerminalNode* XiasParser::Constructor_constraintContext::OPEN_PARENS() {
  return getToken(XiasParser::OPEN_PARENS, 0);
}

tree::TerminalNode* XiasParser::Constructor_constraintContext::CLOSE_PARENS() {
  return getToken(XiasParser::CLOSE_PARENS, 0);
}


size_t XiasParser::Constructor_constraintContext::getRuleIndex() const {
  return XiasParser::RuleConstructor_constraint;
}


antlrcpp::Any XiasParser::Constructor_constraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitConstructor_constraint(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Constructor_constraintContext* XiasParser::constructor_constraint() {
  Constructor_constraintContext *_localctx = _tracker.createInstance<Constructor_constraintContext>(_ctx, getState());
  enterRule(_localctx, 26, XiasParser::RuleConstructor_constraint);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(515);
    match(XiasParser::NEW);
    setState(516);
    match(XiasParser::OPEN_PARENS);
    setState(517);
    match(XiasParser::CLOSE_PARENS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Basic_modifierContext ------------------------------------------------------------------

XiasParser::Basic_modifierContext::Basic_modifierContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Basic_modifierContext::NEW() {
  return getToken(XiasParser::NEW, 0);
}

tree::TerminalNode* XiasParser::Basic_modifierContext::PUBLIC() {
  return getToken(XiasParser::PUBLIC, 0);
}

tree::TerminalNode* XiasParser::Basic_modifierContext::PROTECTED() {
  return getToken(XiasParser::PROTECTED, 0);
}

tree::TerminalNode* XiasParser::Basic_modifierContext::INTERNAL() {
  return getToken(XiasParser::INTERNAL, 0);
}

tree::TerminalNode* XiasParser::Basic_modifierContext::PRIVATE() {
  return getToken(XiasParser::PRIVATE, 0);
}


size_t XiasParser::Basic_modifierContext::getRuleIndex() const {
  return XiasParser::RuleBasic_modifier;
}


antlrcpp::Any XiasParser::Basic_modifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitBasic_modifier(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Basic_modifierContext* XiasParser::basic_modifier() {
  Basic_modifierContext *_localctx = _tracker.createInstance<Basic_modifierContext>(_ctx, getState());
  enterRule(_localctx, 28, XiasParser::RuleBasic_modifier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(519);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << XiasParser::INTERNAL)
      | (1ULL << XiasParser::NEW)
      | (1ULL << XiasParser::PRIVATE)
      | (1ULL << XiasParser::PROTECTED)
      | (1ULL << XiasParser::PUBLIC))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_Context ------------------------------------------------------------------

XiasParser::Type_Context::Type_Context(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Value_typeContext* XiasParser::Type_Context::value_type() {
  return getRuleContext<XiasParser::Value_typeContext>(0);
}

XiasParser::Reference_typeContext* XiasParser::Type_Context::reference_type() {
  return getRuleContext<XiasParser::Reference_typeContext>(0);
}

XiasParser::Type_parameterContext* XiasParser::Type_Context::type_parameter() {
  return getRuleContext<XiasParser::Type_parameterContext>(0);
}


size_t XiasParser::Type_Context::getRuleIndex() const {
  return XiasParser::RuleType_;
}


antlrcpp::Any XiasParser::Type_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitType_(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Type_Context* XiasParser::type_() {
  Type_Context *_localctx = _tracker.createInstance<Type_Context>(_ctx, getState());
  enterRule(_localctx, 30, XiasParser::RuleType_);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(524);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(521);
      value_type();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(522);
      reference_type();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(523);
      type_parameter();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Namespace_nameContext ------------------------------------------------------------------

XiasParser::Namespace_nameContext::Namespace_nameContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Namespace_or_type_nameContext* XiasParser::Namespace_nameContext::namespace_or_type_name() {
  return getRuleContext<XiasParser::Namespace_or_type_nameContext>(0);
}


size_t XiasParser::Namespace_nameContext::getRuleIndex() const {
  return XiasParser::RuleNamespace_name;
}


antlrcpp::Any XiasParser::Namespace_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitNamespace_name(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Namespace_nameContext* XiasParser::namespace_name() {
  Namespace_nameContext *_localctx = _tracker.createInstance<Namespace_nameContext>(_ctx, getState());
  enterRule(_localctx, 32, XiasParser::RuleNamespace_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(526);
    namespace_or_type_name(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_nameContext ------------------------------------------------------------------

XiasParser::Type_nameContext::Type_nameContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Namespace_or_type_nameContext* XiasParser::Type_nameContext::namespace_or_type_name() {
  return getRuleContext<XiasParser::Namespace_or_type_nameContext>(0);
}


size_t XiasParser::Type_nameContext::getRuleIndex() const {
  return XiasParser::RuleType_name;
}


antlrcpp::Any XiasParser::Type_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitType_name(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Type_nameContext* XiasParser::type_name() {
  Type_nameContext *_localctx = _tracker.createInstance<Type_nameContext>(_ctx, getState());
  enterRule(_localctx, 34, XiasParser::RuleType_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(528);
    namespace_or_type_name(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Namespace_or_type_nameContext ------------------------------------------------------------------

XiasParser::Namespace_or_type_nameContext::Namespace_or_type_nameContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::IdentifierContext* XiasParser::Namespace_or_type_nameContext::identifier() {
  return getRuleContext<XiasParser::IdentifierContext>(0);
}

XiasParser::Type_argument_listContext* XiasParser::Namespace_or_type_nameContext::type_argument_list() {
  return getRuleContext<XiasParser::Type_argument_listContext>(0);
}

XiasParser::Qualified_alias_memberContext* XiasParser::Namespace_or_type_nameContext::qualified_alias_member() {
  return getRuleContext<XiasParser::Qualified_alias_memberContext>(0);
}

XiasParser::Namespace_or_type_nameContext* XiasParser::Namespace_or_type_nameContext::namespace_or_type_name() {
  return getRuleContext<XiasParser::Namespace_or_type_nameContext>(0);
}

tree::TerminalNode* XiasParser::Namespace_or_type_nameContext::DOT() {
  return getToken(XiasParser::DOT, 0);
}


size_t XiasParser::Namespace_or_type_nameContext::getRuleIndex() const {
  return XiasParser::RuleNamespace_or_type_name;
}


antlrcpp::Any XiasParser::Namespace_or_type_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitNamespace_or_type_name(this);
  else
    return visitor->visitChildren(this);
}


XiasParser::Namespace_or_type_nameContext* XiasParser::namespace_or_type_name() {
   return namespace_or_type_name(0);
}

XiasParser::Namespace_or_type_nameContext* XiasParser::namespace_or_type_name(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  XiasParser::Namespace_or_type_nameContext *_localctx = _tracker.createInstance<Namespace_or_type_nameContext>(_ctx, parentState);
  XiasParser::Namespace_or_type_nameContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, XiasParser::RuleNamespace_or_type_name, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(536);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      setState(531);
      identifier();
      setState(533);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
      case 1: {
        setState(532);
        type_argument_list();
        break;
      }

      default:
        break;
      }
      break;
    }

    case 2: {
      setState(535);
      qualified_alias_member();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(546);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Namespace_or_type_nameContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleNamespace_or_type_name);
        setState(538);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(539);
        match(XiasParser::DOT);
        setState(540);
        identifier();
        setState(542);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
        case 1: {
          setState(541);
          type_argument_list();
          break;
        }

        default:
          break;
        } 
      }
      setState(548);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Value_typeContext ------------------------------------------------------------------

XiasParser::Value_typeContext::Value_typeContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Struct_typeContext* XiasParser::Value_typeContext::struct_type() {
  return getRuleContext<XiasParser::Struct_typeContext>(0);
}

XiasParser::Enum_typeContext* XiasParser::Value_typeContext::enum_type() {
  return getRuleContext<XiasParser::Enum_typeContext>(0);
}


size_t XiasParser::Value_typeContext::getRuleIndex() const {
  return XiasParser::RuleValue_type;
}


antlrcpp::Any XiasParser::Value_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitValue_type(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Value_typeContext* XiasParser::value_type() {
  Value_typeContext *_localctx = _tracker.createInstance<Value_typeContext>(_ctx, getState());
  enterRule(_localctx, 38, XiasParser::RuleValue_type);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(551);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(549);
      struct_type();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(550);
      enum_type();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Struct_typeContext ------------------------------------------------------------------

XiasParser::Struct_typeContext::Struct_typeContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Type_nameContext* XiasParser::Struct_typeContext::type_name() {
  return getRuleContext<XiasParser::Type_nameContext>(0);
}

XiasParser::Simple_typeContext* XiasParser::Struct_typeContext::simple_type() {
  return getRuleContext<XiasParser::Simple_typeContext>(0);
}


size_t XiasParser::Struct_typeContext::getRuleIndex() const {
  return XiasParser::RuleStruct_type;
}


antlrcpp::Any XiasParser::Struct_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitStruct_type(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Struct_typeContext* XiasParser::struct_type() {
  Struct_typeContext *_localctx = _tracker.createInstance<Struct_typeContext>(_ctx, getState());
  enterRule(_localctx, 40, XiasParser::RuleStruct_type);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(555);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case XiasParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(553);
        type_name();
        break;
      }

      case XiasParser::BOOL:
      case XiasParser::CHAR:
      case XiasParser::DOUBLE:
      case XiasParser::FLOAT:
      case XiasParser::INT:
      case XiasParser::UINT: {
        enterOuterAlt(_localctx, 2);
        setState(554);
        simple_type();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Base_typeContext ------------------------------------------------------------------

XiasParser::Base_typeContext::Base_typeContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Simple_typeContext* XiasParser::Base_typeContext::simple_type() {
  return getRuleContext<XiasParser::Simple_typeContext>(0);
}

XiasParser::Class_typeContext* XiasParser::Base_typeContext::class_type() {
  return getRuleContext<XiasParser::Class_typeContext>(0);
}

tree::TerminalNode* XiasParser::Base_typeContext::VOID() {
  return getToken(XiasParser::VOID, 0);
}

tree::TerminalNode* XiasParser::Base_typeContext::STAR() {
  return getToken(XiasParser::STAR, 0);
}


size_t XiasParser::Base_typeContext::getRuleIndex() const {
  return XiasParser::RuleBase_type;
}


antlrcpp::Any XiasParser::Base_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitBase_type(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Base_typeContext* XiasParser::base_type() {
  Base_typeContext *_localctx = _tracker.createInstance<Base_typeContext>(_ctx, getState());
  enterRule(_localctx, 42, XiasParser::RuleBase_type);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(561);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case XiasParser::BOOL:
      case XiasParser::CHAR:
      case XiasParser::DOUBLE:
      case XiasParser::FLOAT:
      case XiasParser::INT:
      case XiasParser::UINT: {
        enterOuterAlt(_localctx, 1);
        setState(557);
        simple_type();
        break;
      }

      case XiasParser::OBJECT:
      case XiasParser::STRING:
      case XiasParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(558);
        class_type();
        break;
      }

      case XiasParser::VOID: {
        enterOuterAlt(_localctx, 3);
        setState(559);
        match(XiasParser::VOID);
        setState(560);
        match(XiasParser::STAR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_typeContext ------------------------------------------------------------------

XiasParser::Simple_typeContext::Simple_typeContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Numeric_typeContext* XiasParser::Simple_typeContext::numeric_type() {
  return getRuleContext<XiasParser::Numeric_typeContext>(0);
}

tree::TerminalNode* XiasParser::Simple_typeContext::BOOL() {
  return getToken(XiasParser::BOOL, 0);
}


size_t XiasParser::Simple_typeContext::getRuleIndex() const {
  return XiasParser::RuleSimple_type;
}


antlrcpp::Any XiasParser::Simple_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitSimple_type(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Simple_typeContext* XiasParser::simple_type() {
  Simple_typeContext *_localctx = _tracker.createInstance<Simple_typeContext>(_ctx, getState());
  enterRule(_localctx, 44, XiasParser::RuleSimple_type);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(565);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case XiasParser::CHAR:
      case XiasParser::DOUBLE:
      case XiasParser::FLOAT:
      case XiasParser::INT:
      case XiasParser::UINT: {
        enterOuterAlt(_localctx, 1);
        setState(563);
        numeric_type();
        break;
      }

      case XiasParser::BOOL: {
        enterOuterAlt(_localctx, 2);
        setState(564);
        match(XiasParser::BOOL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Numeric_typeContext ------------------------------------------------------------------

XiasParser::Numeric_typeContext::Numeric_typeContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Integral_typeContext* XiasParser::Numeric_typeContext::integral_type() {
  return getRuleContext<XiasParser::Integral_typeContext>(0);
}

XiasParser::Floating_point_typeContext* XiasParser::Numeric_typeContext::floating_point_type() {
  return getRuleContext<XiasParser::Floating_point_typeContext>(0);
}


size_t XiasParser::Numeric_typeContext::getRuleIndex() const {
  return XiasParser::RuleNumeric_type;
}


antlrcpp::Any XiasParser::Numeric_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitNumeric_type(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Numeric_typeContext* XiasParser::numeric_type() {
  Numeric_typeContext *_localctx = _tracker.createInstance<Numeric_typeContext>(_ctx, getState());
  enterRule(_localctx, 46, XiasParser::RuleNumeric_type);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(569);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case XiasParser::CHAR:
      case XiasParser::INT:
      case XiasParser::UINT: {
        enterOuterAlt(_localctx, 1);
        setState(567);
        integral_type();
        break;
      }

      case XiasParser::DOUBLE:
      case XiasParser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(568);
        floating_point_type();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Integral_typeContext ------------------------------------------------------------------

XiasParser::Integral_typeContext::Integral_typeContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Integral_typeContext::INT() {
  return getToken(XiasParser::INT, 0);
}

tree::TerminalNode* XiasParser::Integral_typeContext::UINT() {
  return getToken(XiasParser::UINT, 0);
}

tree::TerminalNode* XiasParser::Integral_typeContext::CHAR() {
  return getToken(XiasParser::CHAR, 0);
}


size_t XiasParser::Integral_typeContext::getRuleIndex() const {
  return XiasParser::RuleIntegral_type;
}


antlrcpp::Any XiasParser::Integral_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitIntegral_type(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Integral_typeContext* XiasParser::integral_type() {
  Integral_typeContext *_localctx = _tracker.createInstance<Integral_typeContext>(_ctx, getState());
  enterRule(_localctx, 48, XiasParser::RuleIntegral_type);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(571);
    _la = _input->LA(1);
    if (!(((((_la - 14) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 14)) & ((1ULL << (XiasParser::CHAR - 14))
      | (1ULL << (XiasParser::INT - 14))
      | (1ULL << (XiasParser::UINT - 14)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Floating_point_typeContext ------------------------------------------------------------------

XiasParser::Floating_point_typeContext::Floating_point_typeContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Floating_point_typeContext::FLOAT() {
  return getToken(XiasParser::FLOAT, 0);
}

tree::TerminalNode* XiasParser::Floating_point_typeContext::DOUBLE() {
  return getToken(XiasParser::DOUBLE, 0);
}


size_t XiasParser::Floating_point_typeContext::getRuleIndex() const {
  return XiasParser::RuleFloating_point_type;
}


antlrcpp::Any XiasParser::Floating_point_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitFloating_point_type(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Floating_point_typeContext* XiasParser::floating_point_type() {
  Floating_point_typeContext *_localctx = _tracker.createInstance<Floating_point_typeContext>(_ctx, getState());
  enterRule(_localctx, 50, XiasParser::RuleFloating_point_type);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(573);
    _la = _input->LA(1);
    if (!(_la == XiasParser::DOUBLE

    || _la == XiasParser::FLOAT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Enum_typeContext ------------------------------------------------------------------

XiasParser::Enum_typeContext::Enum_typeContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Type_nameContext* XiasParser::Enum_typeContext::type_name() {
  return getRuleContext<XiasParser::Type_nameContext>(0);
}


size_t XiasParser::Enum_typeContext::getRuleIndex() const {
  return XiasParser::RuleEnum_type;
}


antlrcpp::Any XiasParser::Enum_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitEnum_type(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Enum_typeContext* XiasParser::enum_type() {
  Enum_typeContext *_localctx = _tracker.createInstance<Enum_typeContext>(_ctx, getState());
  enterRule(_localctx, 52, XiasParser::RuleEnum_type);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(575);
    type_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Reference_typeContext ------------------------------------------------------------------

XiasParser::Reference_typeContext::Reference_typeContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Class_typeContext* XiasParser::Reference_typeContext::class_type() {
  return getRuleContext<XiasParser::Class_typeContext>(0);
}

XiasParser::Interface_typeContext* XiasParser::Reference_typeContext::interface_type() {
  return getRuleContext<XiasParser::Interface_typeContext>(0);
}

XiasParser::Array_typeContext* XiasParser::Reference_typeContext::array_type() {
  return getRuleContext<XiasParser::Array_typeContext>(0);
}


size_t XiasParser::Reference_typeContext::getRuleIndex() const {
  return XiasParser::RuleReference_type;
}


antlrcpp::Any XiasParser::Reference_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitReference_type(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Reference_typeContext* XiasParser::reference_type() {
  Reference_typeContext *_localctx = _tracker.createInstance<Reference_typeContext>(_ctx, getState());
  enterRule(_localctx, 54, XiasParser::RuleReference_type);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(580);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(577);
      class_type();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(578);
      interface_type();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(579);
      array_type();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_typeContext ------------------------------------------------------------------

XiasParser::Class_typeContext::Class_typeContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Type_nameContext* XiasParser::Class_typeContext::type_name() {
  return getRuleContext<XiasParser::Type_nameContext>(0);
}

tree::TerminalNode* XiasParser::Class_typeContext::OBJECT() {
  return getToken(XiasParser::OBJECT, 0);
}

tree::TerminalNode* XiasParser::Class_typeContext::STRING() {
  return getToken(XiasParser::STRING, 0);
}


size_t XiasParser::Class_typeContext::getRuleIndex() const {
  return XiasParser::RuleClass_type;
}


antlrcpp::Any XiasParser::Class_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitClass_type(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Class_typeContext* XiasParser::class_type() {
  Class_typeContext *_localctx = _tracker.createInstance<Class_typeContext>(_ctx, getState());
  enterRule(_localctx, 56, XiasParser::RuleClass_type);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(585);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case XiasParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(582);
        type_name();
        break;
      }

      case XiasParser::OBJECT: {
        enterOuterAlt(_localctx, 2);
        setState(583);
        match(XiasParser::OBJECT);
        break;
      }

      case XiasParser::STRING: {
        enterOuterAlt(_localctx, 3);
        setState(584);
        match(XiasParser::STRING);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_typeContext ------------------------------------------------------------------

XiasParser::Interface_typeContext::Interface_typeContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Type_nameContext* XiasParser::Interface_typeContext::type_name() {
  return getRuleContext<XiasParser::Type_nameContext>(0);
}


size_t XiasParser::Interface_typeContext::getRuleIndex() const {
  return XiasParser::RuleInterface_type;
}


antlrcpp::Any XiasParser::Interface_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitInterface_type(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Interface_typeContext* XiasParser::interface_type() {
  Interface_typeContext *_localctx = _tracker.createInstance<Interface_typeContext>(_ctx, getState());
  enterRule(_localctx, 58, XiasParser::RuleInterface_type);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(587);
    type_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Array_typeContext ------------------------------------------------------------------

XiasParser::Array_typeContext::Array_typeContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Non_array_typeContext* XiasParser::Array_typeContext::non_array_type() {
  return getRuleContext<XiasParser::Non_array_typeContext>(0);
}

std::vector<XiasParser::Rank_specifierContext *> XiasParser::Array_typeContext::rank_specifier() {
  return getRuleContexts<XiasParser::Rank_specifierContext>();
}

XiasParser::Rank_specifierContext* XiasParser::Array_typeContext::rank_specifier(size_t i) {
  return getRuleContext<XiasParser::Rank_specifierContext>(i);
}


size_t XiasParser::Array_typeContext::getRuleIndex() const {
  return XiasParser::RuleArray_type;
}


antlrcpp::Any XiasParser::Array_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitArray_type(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Array_typeContext* XiasParser::array_type() {
  Array_typeContext *_localctx = _tracker.createInstance<Array_typeContext>(_ctx, getState());
  enterRule(_localctx, 60, XiasParser::RuleArray_type);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(589);
    non_array_type();
    setState(591); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(590);
              rank_specifier();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(593); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Non_array_typeContext ------------------------------------------------------------------

XiasParser::Non_array_typeContext::Non_array_typeContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Class_typeContext* XiasParser::Non_array_typeContext::class_type() {
  return getRuleContext<XiasParser::Class_typeContext>(0);
}

XiasParser::Interface_typeContext* XiasParser::Non_array_typeContext::interface_type() {
  return getRuleContext<XiasParser::Interface_typeContext>(0);
}

XiasParser::Value_typeContext* XiasParser::Non_array_typeContext::value_type() {
  return getRuleContext<XiasParser::Value_typeContext>(0);
}

XiasParser::Type_parameterContext* XiasParser::Non_array_typeContext::type_parameter() {
  return getRuleContext<XiasParser::Type_parameterContext>(0);
}


size_t XiasParser::Non_array_typeContext::getRuleIndex() const {
  return XiasParser::RuleNon_array_type;
}


antlrcpp::Any XiasParser::Non_array_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitNon_array_type(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Non_array_typeContext* XiasParser::non_array_type() {
  Non_array_typeContext *_localctx = _tracker.createInstance<Non_array_typeContext>(_ctx, getState());
  enterRule(_localctx, 62, XiasParser::RuleNon_array_type);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(599);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(595);
      class_type();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(596);
      interface_type();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(597);
      value_type();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(598);
      type_parameter();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rank_specifierContext ------------------------------------------------------------------

XiasParser::Rank_specifierContext::Rank_specifierContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Rank_specifierContext::OPEN_BRACKET() {
  return getToken(XiasParser::OPEN_BRACKET, 0);
}

tree::TerminalNode* XiasParser::Rank_specifierContext::CLOSE_BRACKET() {
  return getToken(XiasParser::CLOSE_BRACKET, 0);
}

std::vector<XiasParser::Dim_separatorContext *> XiasParser::Rank_specifierContext::dim_separator() {
  return getRuleContexts<XiasParser::Dim_separatorContext>();
}

XiasParser::Dim_separatorContext* XiasParser::Rank_specifierContext::dim_separator(size_t i) {
  return getRuleContext<XiasParser::Dim_separatorContext>(i);
}


size_t XiasParser::Rank_specifierContext::getRuleIndex() const {
  return XiasParser::RuleRank_specifier;
}


antlrcpp::Any XiasParser::Rank_specifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitRank_specifier(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Rank_specifierContext* XiasParser::rank_specifier() {
  Rank_specifierContext *_localctx = _tracker.createInstance<Rank_specifierContext>(_ctx, getState());
  enterRule(_localctx, 64, XiasParser::RuleRank_specifier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(601);
    match(XiasParser::OPEN_BRACKET);
    setState(605);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == XiasParser::COMMA) {
      setState(602);
      dim_separator();
      setState(607);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(608);
    match(XiasParser::CLOSE_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Dim_separatorContext ------------------------------------------------------------------

XiasParser::Dim_separatorContext::Dim_separatorContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Dim_separatorContext::COMMA() {
  return getToken(XiasParser::COMMA, 0);
}


size_t XiasParser::Dim_separatorContext::getRuleIndex() const {
  return XiasParser::RuleDim_separator;
}


antlrcpp::Any XiasParser::Dim_separatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitDim_separator(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Dim_separatorContext* XiasParser::dim_separator() {
  Dim_separatorContext *_localctx = _tracker.createInstance<Dim_separatorContext>(_ctx, getState());
  enterRule(_localctx, 66, XiasParser::RuleDim_separator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(610);
    match(XiasParser::COMMA);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Predefined_typeContext ------------------------------------------------------------------

XiasParser::Predefined_typeContext::Predefined_typeContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Predefined_typeContext::BOOL() {
  return getToken(XiasParser::BOOL, 0);
}

tree::TerminalNode* XiasParser::Predefined_typeContext::CHAR() {
  return getToken(XiasParser::CHAR, 0);
}

tree::TerminalNode* XiasParser::Predefined_typeContext::DOUBLE() {
  return getToken(XiasParser::DOUBLE, 0);
}

tree::TerminalNode* XiasParser::Predefined_typeContext::FLOAT() {
  return getToken(XiasParser::FLOAT, 0);
}

tree::TerminalNode* XiasParser::Predefined_typeContext::INT() {
  return getToken(XiasParser::INT, 0);
}

tree::TerminalNode* XiasParser::Predefined_typeContext::OBJECT() {
  return getToken(XiasParser::OBJECT, 0);
}

tree::TerminalNode* XiasParser::Predefined_typeContext::STRING() {
  return getToken(XiasParser::STRING, 0);
}

tree::TerminalNode* XiasParser::Predefined_typeContext::UINT() {
  return getToken(XiasParser::UINT, 0);
}


size_t XiasParser::Predefined_typeContext::getRuleIndex() const {
  return XiasParser::RulePredefined_type;
}


antlrcpp::Any XiasParser::Predefined_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitPredefined_type(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Predefined_typeContext* XiasParser::predefined_type() {
  Predefined_typeContext *_localctx = _tracker.createInstance<Predefined_typeContext>(_ctx, getState());
  enterRule(_localctx, 68, XiasParser::RulePredefined_type);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(612);
    _la = _input->LA(1);
    if (!(((((_la - 10) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 10)) & ((1ULL << (XiasParser::BOOL - 10))
      | (1ULL << (XiasParser::CHAR - 10))
      | (1ULL << (XiasParser::DOUBLE - 10))
      | (1ULL << (XiasParser::FLOAT - 10))
      | (1ULL << (XiasParser::INT - 10))
      | (1ULL << (XiasParser::OBJECT - 10))
      | (1ULL << (XiasParser::STRING - 10))
      | (1ULL << (XiasParser::UINT - 10)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_declarationContext ------------------------------------------------------------------

XiasParser::Class_declarationContext::Class_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Class_declarationContext::CLASS() {
  return getToken(XiasParser::CLASS, 0);
}

XiasParser::IdentifierContext* XiasParser::Class_declarationContext::identifier() {
  return getRuleContext<XiasParser::IdentifierContext>(0);
}

XiasParser::Class_bodyContext* XiasParser::Class_declarationContext::class_body() {
  return getRuleContext<XiasParser::Class_bodyContext>(0);
}

std::vector<XiasParser::All_modifierContext *> XiasParser::Class_declarationContext::all_modifier() {
  return getRuleContexts<XiasParser::All_modifierContext>();
}

XiasParser::All_modifierContext* XiasParser::Class_declarationContext::all_modifier(size_t i) {
  return getRuleContext<XiasParser::All_modifierContext>(i);
}

XiasParser::Type_parameter_listContext* XiasParser::Class_declarationContext::type_parameter_list() {
  return getRuleContext<XiasParser::Type_parameter_listContext>(0);
}

XiasParser::Class_baseContext* XiasParser::Class_declarationContext::class_base() {
  return getRuleContext<XiasParser::Class_baseContext>(0);
}

std::vector<XiasParser::Type_parameter_constraints_clauseContext *> XiasParser::Class_declarationContext::type_parameter_constraints_clause() {
  return getRuleContexts<XiasParser::Type_parameter_constraints_clauseContext>();
}

XiasParser::Type_parameter_constraints_clauseContext* XiasParser::Class_declarationContext::type_parameter_constraints_clause(size_t i) {
  return getRuleContext<XiasParser::Type_parameter_constraints_clauseContext>(i);
}

tree::TerminalNode* XiasParser::Class_declarationContext::SEMICOLON() {
  return getToken(XiasParser::SEMICOLON, 0);
}


size_t XiasParser::Class_declarationContext::getRuleIndex() const {
  return XiasParser::RuleClass_declaration;
}


antlrcpp::Any XiasParser::Class_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitClass_declaration(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Class_declarationContext* XiasParser::class_declaration() {
  Class_declarationContext *_localctx = _tracker.createInstance<Class_declarationContext>(_ctx, getState());
  enterRule(_localctx, 70, XiasParser::RuleClass_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(617);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 6) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 6)) & ((1ULL << (XiasParser::ABSTRACT - 6))
      | (1ULL << (XiasParser::EXTERN - 6))
      | (1ULL << (XiasParser::NEW - 6))
      | (1ULL << (XiasParser::OVERRIDE - 6))
      | (1ULL << (XiasParser::PRIVATE - 6))
      | (1ULL << (XiasParser::PROTECTED - 6))
      | (1ULL << (XiasParser::PUBLIC - 6))
      | (1ULL << (XiasParser::READONLY - 6))
      | (1ULL << (XiasParser::SEALED - 6))
      | (1ULL << (XiasParser::STATIC - 6))
      | (1ULL << (XiasParser::VIRTUAL - 6)))) != 0)) {
      setState(614);
      all_modifier();
      setState(619);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(620);
    match(XiasParser::CLASS);
    setState(621);
    identifier();
    setState(623);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == XiasParser::LT) {
      setState(622);
      type_parameter_list();
    }
    setState(626);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == XiasParser::COLON) {
      setState(625);
      class_base();
    }
    setState(631);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == XiasParser::WHERE) {
      setState(628);
      type_parameter_constraints_clause();
      setState(633);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(634);
    class_body();
    setState(636);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == XiasParser::SEMICOLON) {
      setState(635);
      match(XiasParser::SEMICOLON);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_baseContext ------------------------------------------------------------------

XiasParser::Class_baseContext::Class_baseContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Class_baseContext::COLON() {
  return getToken(XiasParser::COLON, 0);
}

XiasParser::Class_typeContext* XiasParser::Class_baseContext::class_type() {
  return getRuleContext<XiasParser::Class_typeContext>(0);
}

XiasParser::Interface_type_listContext* XiasParser::Class_baseContext::interface_type_list() {
  return getRuleContext<XiasParser::Interface_type_listContext>(0);
}

tree::TerminalNode* XiasParser::Class_baseContext::COMMA() {
  return getToken(XiasParser::COMMA, 0);
}


size_t XiasParser::Class_baseContext::getRuleIndex() const {
  return XiasParser::RuleClass_base;
}


antlrcpp::Any XiasParser::Class_baseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitClass_base(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Class_baseContext* XiasParser::class_base() {
  Class_baseContext *_localctx = _tracker.createInstance<Class_baseContext>(_ctx, getState());
  enterRule(_localctx, 72, XiasParser::RuleClass_base);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(647);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(638);
      match(XiasParser::COLON);
      setState(639);
      class_type();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(640);
      match(XiasParser::COLON);
      setState(641);
      interface_type_list();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(642);
      match(XiasParser::COLON);
      setState(643);
      class_type();
      setState(644);
      match(XiasParser::COMMA);
      setState(645);
      interface_type_list();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_type_listContext ------------------------------------------------------------------

XiasParser::Interface_type_listContext::Interface_type_listContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

std::vector<XiasParser::Interface_typeContext *> XiasParser::Interface_type_listContext::interface_type() {
  return getRuleContexts<XiasParser::Interface_typeContext>();
}

XiasParser::Interface_typeContext* XiasParser::Interface_type_listContext::interface_type(size_t i) {
  return getRuleContext<XiasParser::Interface_typeContext>(i);
}

std::vector<tree::TerminalNode *> XiasParser::Interface_type_listContext::COMMA() {
  return getTokens(XiasParser::COMMA);
}

tree::TerminalNode* XiasParser::Interface_type_listContext::COMMA(size_t i) {
  return getToken(XiasParser::COMMA, i);
}


size_t XiasParser::Interface_type_listContext::getRuleIndex() const {
  return XiasParser::RuleInterface_type_list;
}


antlrcpp::Any XiasParser::Interface_type_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitInterface_type_list(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Interface_type_listContext* XiasParser::interface_type_list() {
  Interface_type_listContext *_localctx = _tracker.createInstance<Interface_type_listContext>(_ctx, getState());
  enterRule(_localctx, 74, XiasParser::RuleInterface_type_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(649);
    interface_type();
    setState(654);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == XiasParser::COMMA) {
      setState(650);
      match(XiasParser::COMMA);
      setState(651);
      interface_type();
      setState(656);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_bodyContext ------------------------------------------------------------------

XiasParser::Class_bodyContext::Class_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Class_bodyContext::OPEN_BRACE() {
  return getToken(XiasParser::OPEN_BRACE, 0);
}

tree::TerminalNode* XiasParser::Class_bodyContext::CLOSE_BRACE() {
  return getToken(XiasParser::CLOSE_BRACE, 0);
}

std::vector<XiasParser::Class_member_declarationContext *> XiasParser::Class_bodyContext::class_member_declaration() {
  return getRuleContexts<XiasParser::Class_member_declarationContext>();
}

XiasParser::Class_member_declarationContext* XiasParser::Class_bodyContext::class_member_declaration(size_t i) {
  return getRuleContext<XiasParser::Class_member_declarationContext>(i);
}


size_t XiasParser::Class_bodyContext::getRuleIndex() const {
  return XiasParser::RuleClass_body;
}


antlrcpp::Any XiasParser::Class_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitClass_body(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Class_bodyContext* XiasParser::class_body() {
  Class_bodyContext *_localctx = _tracker.createInstance<Class_bodyContext>(_ctx, getState());
  enterRule(_localctx, 76, XiasParser::RuleClass_body);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(657);
    match(XiasParser::OPEN_BRACE);
    setState(661);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << XiasParser::ABSTRACT)
      | (1ULL << XiasParser::BOOL)
      | (1ULL << XiasParser::CHAR)
      | (1ULL << XiasParser::CLASS)
      | (1ULL << XiasParser::CONST)
      | (1ULL << XiasParser::DOUBLE)
      | (1ULL << XiasParser::EXTERN)
      | (1ULL << XiasParser::FLOAT)
      | (1ULL << XiasParser::INT)
      | (1ULL << XiasParser::INTERFACE)
      | (1ULL << XiasParser::INTERNAL)
      | (1ULL << XiasParser::NEW)
      | (1ULL << XiasParser::OBJECT)
      | (1ULL << XiasParser::OVERRIDE)
      | (1ULL << XiasParser::PRIVATE)
      | (1ULL << XiasParser::PROTECTED)
      | (1ULL << XiasParser::PUBLIC)
      | (1ULL << XiasParser::READONLY)
      | (1ULL << XiasParser::SEALED)
      | (1ULL << XiasParser::STATIC)
      | (1ULL << XiasParser::STRING))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (XiasParser::UINT - 64))
      | (1ULL << (XiasParser::VIRTUAL - 64))
      | (1ULL << (XiasParser::VOID - 64))
      | (1ULL << (XiasParser::IDENTIFIER - 64))
      | (1ULL << (XiasParser::TILDE - 64)))) != 0)) {
      setState(658);
      class_member_declaration();
      setState(663);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(664);
    match(XiasParser::CLOSE_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_member_declarationContext ------------------------------------------------------------------

XiasParser::Class_member_declarationContext::Class_member_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Constant_declarationContext* XiasParser::Class_member_declarationContext::constant_declaration() {
  return getRuleContext<XiasParser::Constant_declarationContext>(0);
}

XiasParser::Field_declarationContext* XiasParser::Class_member_declarationContext::field_declaration() {
  return getRuleContext<XiasParser::Field_declarationContext>(0);
}

XiasParser::Method_declarationContext* XiasParser::Class_member_declarationContext::method_declaration() {
  return getRuleContext<XiasParser::Method_declarationContext>(0);
}

XiasParser::Property_declarationContext* XiasParser::Class_member_declarationContext::property_declaration() {
  return getRuleContext<XiasParser::Property_declarationContext>(0);
}

XiasParser::Indexer_declarationContext* XiasParser::Class_member_declarationContext::indexer_declaration() {
  return getRuleContext<XiasParser::Indexer_declarationContext>(0);
}

XiasParser::Operator_declarationContext* XiasParser::Class_member_declarationContext::operator_declaration() {
  return getRuleContext<XiasParser::Operator_declarationContext>(0);
}

XiasParser::Constructor_declarationContext* XiasParser::Class_member_declarationContext::constructor_declaration() {
  return getRuleContext<XiasParser::Constructor_declarationContext>(0);
}

XiasParser::Static_constructor_declarationContext* XiasParser::Class_member_declarationContext::static_constructor_declaration() {
  return getRuleContext<XiasParser::Static_constructor_declarationContext>(0);
}

XiasParser::Destructor_declarationContext* XiasParser::Class_member_declarationContext::destructor_declaration() {
  return getRuleContext<XiasParser::Destructor_declarationContext>(0);
}

XiasParser::Type_declarationContext* XiasParser::Class_member_declarationContext::type_declaration() {
  return getRuleContext<XiasParser::Type_declarationContext>(0);
}


size_t XiasParser::Class_member_declarationContext::getRuleIndex() const {
  return XiasParser::RuleClass_member_declaration;
}


antlrcpp::Any XiasParser::Class_member_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitClass_member_declaration(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Class_member_declarationContext* XiasParser::class_member_declaration() {
  Class_member_declarationContext *_localctx = _tracker.createInstance<Class_member_declarationContext>(_ctx, getState());
  enterRule(_localctx, 78, XiasParser::RuleClass_member_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(676);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(666);
      constant_declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(667);
      field_declaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(668);
      method_declaration();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(669);
      property_declaration();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(670);
      indexer_declaration();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(671);
      operator_declaration();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(672);
      constructor_declaration();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(673);
      static_constructor_declaration();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(674);
      destructor_declaration();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(675);
      type_declaration();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Constant_declarationContext ------------------------------------------------------------------

XiasParser::Constant_declarationContext::Constant_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Constant_declarationContext::CONST() {
  return getToken(XiasParser::CONST, 0);
}

XiasParser::Type_Context* XiasParser::Constant_declarationContext::type_() {
  return getRuleContext<XiasParser::Type_Context>(0);
}

XiasParser::Constant_declaratorsContext* XiasParser::Constant_declarationContext::constant_declarators() {
  return getRuleContext<XiasParser::Constant_declaratorsContext>(0);
}

tree::TerminalNode* XiasParser::Constant_declarationContext::SEMICOLON() {
  return getToken(XiasParser::SEMICOLON, 0);
}

std::vector<XiasParser::Basic_modifierContext *> XiasParser::Constant_declarationContext::basic_modifier() {
  return getRuleContexts<XiasParser::Basic_modifierContext>();
}

XiasParser::Basic_modifierContext* XiasParser::Constant_declarationContext::basic_modifier(size_t i) {
  return getRuleContext<XiasParser::Basic_modifierContext>(i);
}


size_t XiasParser::Constant_declarationContext::getRuleIndex() const {
  return XiasParser::RuleConstant_declaration;
}


antlrcpp::Any XiasParser::Constant_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitConstant_declaration(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Constant_declarationContext* XiasParser::constant_declaration() {
  Constant_declarationContext *_localctx = _tracker.createInstance<Constant_declarationContext>(_ctx, getState());
  enterRule(_localctx, 80, XiasParser::RuleConstant_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(681);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << XiasParser::INTERNAL)
      | (1ULL << XiasParser::NEW)
      | (1ULL << XiasParser::PRIVATE)
      | (1ULL << XiasParser::PROTECTED)
      | (1ULL << XiasParser::PUBLIC))) != 0)) {
      setState(678);
      basic_modifier();
      setState(683);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(684);
    match(XiasParser::CONST);
    setState(685);
    type_();
    setState(686);
    constant_declarators();
    setState(687);
    match(XiasParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Field_declarationContext ------------------------------------------------------------------

XiasParser::Field_declarationContext::Field_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Type_Context* XiasParser::Field_declarationContext::type_() {
  return getRuleContext<XiasParser::Type_Context>(0);
}

XiasParser::Variable_declaratorsContext* XiasParser::Field_declarationContext::variable_declarators() {
  return getRuleContext<XiasParser::Variable_declaratorsContext>(0);
}

tree::TerminalNode* XiasParser::Field_declarationContext::SEMICOLON() {
  return getToken(XiasParser::SEMICOLON, 0);
}

std::vector<XiasParser::All_modifierContext *> XiasParser::Field_declarationContext::all_modifier() {
  return getRuleContexts<XiasParser::All_modifierContext>();
}

XiasParser::All_modifierContext* XiasParser::Field_declarationContext::all_modifier(size_t i) {
  return getRuleContext<XiasParser::All_modifierContext>(i);
}


size_t XiasParser::Field_declarationContext::getRuleIndex() const {
  return XiasParser::RuleField_declaration;
}


antlrcpp::Any XiasParser::Field_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitField_declaration(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Field_declarationContext* XiasParser::field_declaration() {
  Field_declarationContext *_localctx = _tracker.createInstance<Field_declarationContext>(_ctx, getState());
  enterRule(_localctx, 82, XiasParser::RuleField_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(692);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 6) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 6)) & ((1ULL << (XiasParser::ABSTRACT - 6))
      | (1ULL << (XiasParser::EXTERN - 6))
      | (1ULL << (XiasParser::NEW - 6))
      | (1ULL << (XiasParser::OVERRIDE - 6))
      | (1ULL << (XiasParser::PRIVATE - 6))
      | (1ULL << (XiasParser::PROTECTED - 6))
      | (1ULL << (XiasParser::PUBLIC - 6))
      | (1ULL << (XiasParser::READONLY - 6))
      | (1ULL << (XiasParser::SEALED - 6))
      | (1ULL << (XiasParser::STATIC - 6))
      | (1ULL << (XiasParser::VIRTUAL - 6)))) != 0)) {
      setState(689);
      all_modifier();
      setState(694);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(695);
    type_();
    setState(696);
    variable_declarators();
    setState(697);
    match(XiasParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_declaratorsContext ------------------------------------------------------------------

XiasParser::Variable_declaratorsContext::Variable_declaratorsContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

std::vector<XiasParser::Variable_declaratorContext *> XiasParser::Variable_declaratorsContext::variable_declarator() {
  return getRuleContexts<XiasParser::Variable_declaratorContext>();
}

XiasParser::Variable_declaratorContext* XiasParser::Variable_declaratorsContext::variable_declarator(size_t i) {
  return getRuleContext<XiasParser::Variable_declaratorContext>(i);
}

std::vector<tree::TerminalNode *> XiasParser::Variable_declaratorsContext::COMMA() {
  return getTokens(XiasParser::COMMA);
}

tree::TerminalNode* XiasParser::Variable_declaratorsContext::COMMA(size_t i) {
  return getToken(XiasParser::COMMA, i);
}


size_t XiasParser::Variable_declaratorsContext::getRuleIndex() const {
  return XiasParser::RuleVariable_declarators;
}


antlrcpp::Any XiasParser::Variable_declaratorsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitVariable_declarators(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Variable_declaratorsContext* XiasParser::variable_declarators() {
  Variable_declaratorsContext *_localctx = _tracker.createInstance<Variable_declaratorsContext>(_ctx, getState());
  enterRule(_localctx, 84, XiasParser::RuleVariable_declarators);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(699);
    variable_declarator();
    setState(704);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == XiasParser::COMMA) {
      setState(700);
      match(XiasParser::COMMA);
      setState(701);
      variable_declarator();
      setState(706);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_declaratorContext ------------------------------------------------------------------

XiasParser::Variable_declaratorContext::Variable_declaratorContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::IdentifierContext* XiasParser::Variable_declaratorContext::identifier() {
  return getRuleContext<XiasParser::IdentifierContext>(0);
}

tree::TerminalNode* XiasParser::Variable_declaratorContext::ASSIGNMENT() {
  return getToken(XiasParser::ASSIGNMENT, 0);
}

XiasParser::Variable_initializerContext* XiasParser::Variable_declaratorContext::variable_initializer() {
  return getRuleContext<XiasParser::Variable_initializerContext>(0);
}


size_t XiasParser::Variable_declaratorContext::getRuleIndex() const {
  return XiasParser::RuleVariable_declarator;
}


antlrcpp::Any XiasParser::Variable_declaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitVariable_declarator(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Variable_declaratorContext* XiasParser::variable_declarator() {
  Variable_declaratorContext *_localctx = _tracker.createInstance<Variable_declaratorContext>(_ctx, getState());
  enterRule(_localctx, 86, XiasParser::RuleVariable_declarator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(707);
    identifier();
    setState(710);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == XiasParser::ASSIGNMENT) {
      setState(708);
      match(XiasParser::ASSIGNMENT);
      setState(709);
      variable_initializer();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_initializerContext ------------------------------------------------------------------

XiasParser::Variable_initializerContext::Variable_initializerContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::ExpressionContext* XiasParser::Variable_initializerContext::expression() {
  return getRuleContext<XiasParser::ExpressionContext>(0);
}

XiasParser::Array_initializerContext* XiasParser::Variable_initializerContext::array_initializer() {
  return getRuleContext<XiasParser::Array_initializerContext>(0);
}


size_t XiasParser::Variable_initializerContext::getRuleIndex() const {
  return XiasParser::RuleVariable_initializer;
}


antlrcpp::Any XiasParser::Variable_initializerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitVariable_initializer(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Variable_initializerContext* XiasParser::variable_initializer() {
  Variable_initializerContext *_localctx = _tracker.createInstance<Variable_initializerContext>(_ctx, getState());
  enterRule(_localctx, 88, XiasParser::RuleVariable_initializer);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(714);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case XiasParser::BASE:
      case XiasParser::DEFAULT:
      case XiasParser::FALSE:
      case XiasParser::NEW:
      case XiasParser::NULL_:
      case XiasParser::THIS:
      case XiasParser::TRUE:
      case XiasParser::TYPEOF:
      case XiasParser::IDENTIFIER:
      case XiasParser::INTEGER_LITERAL:
      case XiasParser::UNSIGNED_LITERAL:
      case XiasParser::HEX_INTEGER_LITERAL:
      case XiasParser::FLOAT_LITERAL:
      case XiasParser::DOUBLE_LITERAL:
      case XiasParser::CHARACTER_LITERAL:
      case XiasParser::REGULAR_STRING:
      case XiasParser::VERBATIUM_STRING:
      case XiasParser::OPEN_PARENS:
      case XiasParser::PLUS:
      case XiasParser::MINUS:
      case XiasParser::BANG:
      case XiasParser::TILDE:
      case XiasParser::OP_INC:
      case XiasParser::OP_DEC: {
        enterOuterAlt(_localctx, 1);
        setState(712);
        expression();
        break;
      }

      case XiasParser::OPEN_BRACE: {
        enterOuterAlt(_localctx, 2);
        setState(713);
        array_initializer();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Method_declarationContext ------------------------------------------------------------------

XiasParser::Method_declarationContext::Method_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Method_headerContext* XiasParser::Method_declarationContext::method_header() {
  return getRuleContext<XiasParser::Method_headerContext>(0);
}

XiasParser::Method_bodyContext* XiasParser::Method_declarationContext::method_body() {
  return getRuleContext<XiasParser::Method_bodyContext>(0);
}


size_t XiasParser::Method_declarationContext::getRuleIndex() const {
  return XiasParser::RuleMethod_declaration;
}


antlrcpp::Any XiasParser::Method_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitMethod_declaration(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Method_declarationContext* XiasParser::method_declaration() {
  Method_declarationContext *_localctx = _tracker.createInstance<Method_declarationContext>(_ctx, getState());
  enterRule(_localctx, 90, XiasParser::RuleMethod_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(716);
    method_header();
    setState(717);
    method_body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Method_headerContext ------------------------------------------------------------------

XiasParser::Method_headerContext::Method_headerContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Return_typeContext* XiasParser::Method_headerContext::return_type() {
  return getRuleContext<XiasParser::Return_typeContext>(0);
}

XiasParser::Member_nameContext* XiasParser::Method_headerContext::member_name() {
  return getRuleContext<XiasParser::Member_nameContext>(0);
}

tree::TerminalNode* XiasParser::Method_headerContext::OPEN_PARENS() {
  return getToken(XiasParser::OPEN_PARENS, 0);
}

tree::TerminalNode* XiasParser::Method_headerContext::CLOSE_PARENS() {
  return getToken(XiasParser::CLOSE_PARENS, 0);
}

std::vector<XiasParser::All_modifierContext *> XiasParser::Method_headerContext::all_modifier() {
  return getRuleContexts<XiasParser::All_modifierContext>();
}

XiasParser::All_modifierContext* XiasParser::Method_headerContext::all_modifier(size_t i) {
  return getRuleContext<XiasParser::All_modifierContext>(i);
}

XiasParser::Type_parameter_listContext* XiasParser::Method_headerContext::type_parameter_list() {
  return getRuleContext<XiasParser::Type_parameter_listContext>(0);
}

XiasParser::Formal_parameter_listContext* XiasParser::Method_headerContext::formal_parameter_list() {
  return getRuleContext<XiasParser::Formal_parameter_listContext>(0);
}

std::vector<XiasParser::Type_parameter_constraints_clauseContext *> XiasParser::Method_headerContext::type_parameter_constraints_clause() {
  return getRuleContexts<XiasParser::Type_parameter_constraints_clauseContext>();
}

XiasParser::Type_parameter_constraints_clauseContext* XiasParser::Method_headerContext::type_parameter_constraints_clause(size_t i) {
  return getRuleContext<XiasParser::Type_parameter_constraints_clauseContext>(i);
}


size_t XiasParser::Method_headerContext::getRuleIndex() const {
  return XiasParser::RuleMethod_header;
}


antlrcpp::Any XiasParser::Method_headerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitMethod_header(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Method_headerContext* XiasParser::method_header() {
  Method_headerContext *_localctx = _tracker.createInstance<Method_headerContext>(_ctx, getState());
  enterRule(_localctx, 92, XiasParser::RuleMethod_header);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(722);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 6) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 6)) & ((1ULL << (XiasParser::ABSTRACT - 6))
      | (1ULL << (XiasParser::EXTERN - 6))
      | (1ULL << (XiasParser::NEW - 6))
      | (1ULL << (XiasParser::OVERRIDE - 6))
      | (1ULL << (XiasParser::PRIVATE - 6))
      | (1ULL << (XiasParser::PROTECTED - 6))
      | (1ULL << (XiasParser::PUBLIC - 6))
      | (1ULL << (XiasParser::READONLY - 6))
      | (1ULL << (XiasParser::SEALED - 6))
      | (1ULL << (XiasParser::STATIC - 6))
      | (1ULL << (XiasParser::VIRTUAL - 6)))) != 0)) {
      setState(719);
      all_modifier();
      setState(724);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(725);
    return_type();
    setState(726);
    member_name();
    setState(728);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == XiasParser::LT) {
      setState(727);
      type_parameter_list();
    }
    setState(730);
    match(XiasParser::OPEN_PARENS);
    setState(732);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 10) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 10)) & ((1ULL << (XiasParser::BOOL - 10))
      | (1ULL << (XiasParser::CHAR - 10))
      | (1ULL << (XiasParser::DOUBLE - 10))
      | (1ULL << (XiasParser::FLOAT - 10))
      | (1ULL << (XiasParser::INT - 10))
      | (1ULL << (XiasParser::OBJECT - 10))
      | (1ULL << (XiasParser::STRING - 10))
      | (1ULL << (XiasParser::THIS - 10))
      | (1ULL << (XiasParser::UINT - 10))
      | (1ULL << (XiasParser::IDENTIFIER - 10)))) != 0)) {
      setState(731);
      formal_parameter_list();
    }
    setState(734);
    match(XiasParser::CLOSE_PARENS);
    setState(738);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == XiasParser::WHERE) {
      setState(735);
      type_parameter_constraints_clause();
      setState(740);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Return_typeContext ------------------------------------------------------------------

XiasParser::Return_typeContext::Return_typeContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Type_Context* XiasParser::Return_typeContext::type_() {
  return getRuleContext<XiasParser::Type_Context>(0);
}

tree::TerminalNode* XiasParser::Return_typeContext::VOID() {
  return getToken(XiasParser::VOID, 0);
}


size_t XiasParser::Return_typeContext::getRuleIndex() const {
  return XiasParser::RuleReturn_type;
}


antlrcpp::Any XiasParser::Return_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitReturn_type(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Return_typeContext* XiasParser::return_type() {
  Return_typeContext *_localctx = _tracker.createInstance<Return_typeContext>(_ctx, getState());
  enterRule(_localctx, 94, XiasParser::RuleReturn_type);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(743);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case XiasParser::BOOL:
      case XiasParser::CHAR:
      case XiasParser::DOUBLE:
      case XiasParser::FLOAT:
      case XiasParser::INT:
      case XiasParser::OBJECT:
      case XiasParser::STRING:
      case XiasParser::UINT:
      case XiasParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(741);
        type_();
        break;
      }

      case XiasParser::VOID: {
        enterOuterAlt(_localctx, 2);
        setState(742);
        match(XiasParser::VOID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Member_nameContext ------------------------------------------------------------------

XiasParser::Member_nameContext::Member_nameContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::IdentifierContext* XiasParser::Member_nameContext::identifier() {
  return getRuleContext<XiasParser::IdentifierContext>(0);
}

XiasParser::Interface_typeContext* XiasParser::Member_nameContext::interface_type() {
  return getRuleContext<XiasParser::Interface_typeContext>(0);
}

tree::TerminalNode* XiasParser::Member_nameContext::DOT() {
  return getToken(XiasParser::DOT, 0);
}


size_t XiasParser::Member_nameContext::getRuleIndex() const {
  return XiasParser::RuleMember_name;
}


antlrcpp::Any XiasParser::Member_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitMember_name(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Member_nameContext* XiasParser::member_name() {
  Member_nameContext *_localctx = _tracker.createInstance<Member_nameContext>(_ctx, getState());
  enterRule(_localctx, 96, XiasParser::RuleMember_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(750);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(745);
      identifier();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(746);
      interface_type();
      setState(747);
      match(XiasParser::DOT);
      setState(748);
      identifier();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Formal_parameter_listContext ------------------------------------------------------------------

XiasParser::Formal_parameter_listContext::Formal_parameter_listContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Fixed_parametersContext* XiasParser::Formal_parameter_listContext::fixed_parameters() {
  return getRuleContext<XiasParser::Fixed_parametersContext>(0);
}


size_t XiasParser::Formal_parameter_listContext::getRuleIndex() const {
  return XiasParser::RuleFormal_parameter_list;
}


antlrcpp::Any XiasParser::Formal_parameter_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitFormal_parameter_list(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Formal_parameter_listContext* XiasParser::formal_parameter_list() {
  Formal_parameter_listContext *_localctx = _tracker.createInstance<Formal_parameter_listContext>(_ctx, getState());
  enterRule(_localctx, 98, XiasParser::RuleFormal_parameter_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(752);
    fixed_parameters();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Fixed_parametersContext ------------------------------------------------------------------

XiasParser::Fixed_parametersContext::Fixed_parametersContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

std::vector<XiasParser::Fixed_parameterContext *> XiasParser::Fixed_parametersContext::fixed_parameter() {
  return getRuleContexts<XiasParser::Fixed_parameterContext>();
}

XiasParser::Fixed_parameterContext* XiasParser::Fixed_parametersContext::fixed_parameter(size_t i) {
  return getRuleContext<XiasParser::Fixed_parameterContext>(i);
}

std::vector<tree::TerminalNode *> XiasParser::Fixed_parametersContext::COMMA() {
  return getTokens(XiasParser::COMMA);
}

tree::TerminalNode* XiasParser::Fixed_parametersContext::COMMA(size_t i) {
  return getToken(XiasParser::COMMA, i);
}


size_t XiasParser::Fixed_parametersContext::getRuleIndex() const {
  return XiasParser::RuleFixed_parameters;
}


antlrcpp::Any XiasParser::Fixed_parametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitFixed_parameters(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Fixed_parametersContext* XiasParser::fixed_parameters() {
  Fixed_parametersContext *_localctx = _tracker.createInstance<Fixed_parametersContext>(_ctx, getState());
  enterRule(_localctx, 100, XiasParser::RuleFixed_parameters);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(754);
    fixed_parameter();
    setState(759);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == XiasParser::COMMA) {
      setState(755);
      match(XiasParser::COMMA);
      setState(756);
      fixed_parameter();
      setState(761);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Fixed_parameterContext ------------------------------------------------------------------

XiasParser::Fixed_parameterContext::Fixed_parameterContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Type_Context* XiasParser::Fixed_parameterContext::type_() {
  return getRuleContext<XiasParser::Type_Context>(0);
}

XiasParser::IdentifierContext* XiasParser::Fixed_parameterContext::identifier() {
  return getRuleContext<XiasParser::IdentifierContext>(0);
}

XiasParser::Parameter_modifierContext* XiasParser::Fixed_parameterContext::parameter_modifier() {
  return getRuleContext<XiasParser::Parameter_modifierContext>(0);
}

XiasParser::Default_argumentContext* XiasParser::Fixed_parameterContext::default_argument() {
  return getRuleContext<XiasParser::Default_argumentContext>(0);
}


size_t XiasParser::Fixed_parameterContext::getRuleIndex() const {
  return XiasParser::RuleFixed_parameter;
}


antlrcpp::Any XiasParser::Fixed_parameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitFixed_parameter(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Fixed_parameterContext* XiasParser::fixed_parameter() {
  Fixed_parameterContext *_localctx = _tracker.createInstance<Fixed_parameterContext>(_ctx, getState());
  enterRule(_localctx, 102, XiasParser::RuleFixed_parameter);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(763);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == XiasParser::THIS) {
      setState(762);
      parameter_modifier();
    }
    setState(765);
    type_();
    setState(766);
    identifier();
    setState(768);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == XiasParser::ASSIGNMENT) {
      setState(767);
      default_argument();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Default_argumentContext ------------------------------------------------------------------

XiasParser::Default_argumentContext::Default_argumentContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Default_argumentContext::ASSIGNMENT() {
  return getToken(XiasParser::ASSIGNMENT, 0);
}

XiasParser::ExpressionContext* XiasParser::Default_argumentContext::expression() {
  return getRuleContext<XiasParser::ExpressionContext>(0);
}


size_t XiasParser::Default_argumentContext::getRuleIndex() const {
  return XiasParser::RuleDefault_argument;
}


antlrcpp::Any XiasParser::Default_argumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitDefault_argument(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Default_argumentContext* XiasParser::default_argument() {
  Default_argumentContext *_localctx = _tracker.createInstance<Default_argumentContext>(_ctx, getState());
  enterRule(_localctx, 104, XiasParser::RuleDefault_argument);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(770);
    match(XiasParser::ASSIGNMENT);
    setState(771);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_modifierContext ------------------------------------------------------------------

XiasParser::Parameter_modifierContext::Parameter_modifierContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Parameter_modifierContext::THIS() {
  return getToken(XiasParser::THIS, 0);
}


size_t XiasParser::Parameter_modifierContext::getRuleIndex() const {
  return XiasParser::RuleParameter_modifier;
}


antlrcpp::Any XiasParser::Parameter_modifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitParameter_modifier(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Parameter_modifierContext* XiasParser::parameter_modifier() {
  Parameter_modifierContext *_localctx = _tracker.createInstance<Parameter_modifierContext>(_ctx, getState());
  enterRule(_localctx, 106, XiasParser::RuleParameter_modifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(773);
    match(XiasParser::THIS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Method_bodyContext ------------------------------------------------------------------

XiasParser::Method_bodyContext::Method_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::BlockContext* XiasParser::Method_bodyContext::block() {
  return getRuleContext<XiasParser::BlockContext>(0);
}

tree::TerminalNode* XiasParser::Method_bodyContext::SEMICOLON() {
  return getToken(XiasParser::SEMICOLON, 0);
}


size_t XiasParser::Method_bodyContext::getRuleIndex() const {
  return XiasParser::RuleMethod_body;
}


antlrcpp::Any XiasParser::Method_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitMethod_body(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Method_bodyContext* XiasParser::method_body() {
  Method_bodyContext *_localctx = _tracker.createInstance<Method_bodyContext>(_ctx, getState());
  enterRule(_localctx, 108, XiasParser::RuleMethod_body);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(777);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case XiasParser::OPEN_BRACE: {
        enterOuterAlt(_localctx, 1);
        setState(775);
        block();
        break;
      }

      case XiasParser::SEMICOLON: {
        enterOuterAlt(_localctx, 2);
        setState(776);
        match(XiasParser::SEMICOLON);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Property_declarationContext ------------------------------------------------------------------

XiasParser::Property_declarationContext::Property_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Type_Context* XiasParser::Property_declarationContext::type_() {
  return getRuleContext<XiasParser::Type_Context>(0);
}

XiasParser::Member_nameContext* XiasParser::Property_declarationContext::member_name() {
  return getRuleContext<XiasParser::Member_nameContext>(0);
}

XiasParser::Property_bodyContext* XiasParser::Property_declarationContext::property_body() {
  return getRuleContext<XiasParser::Property_bodyContext>(0);
}

std::vector<XiasParser::All_modifierContext *> XiasParser::Property_declarationContext::all_modifier() {
  return getRuleContexts<XiasParser::All_modifierContext>();
}

XiasParser::All_modifierContext* XiasParser::Property_declarationContext::all_modifier(size_t i) {
  return getRuleContext<XiasParser::All_modifierContext>(i);
}


size_t XiasParser::Property_declarationContext::getRuleIndex() const {
  return XiasParser::RuleProperty_declaration;
}


antlrcpp::Any XiasParser::Property_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitProperty_declaration(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Property_declarationContext* XiasParser::property_declaration() {
  Property_declarationContext *_localctx = _tracker.createInstance<Property_declarationContext>(_ctx, getState());
  enterRule(_localctx, 110, XiasParser::RuleProperty_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(782);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 6) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 6)) & ((1ULL << (XiasParser::ABSTRACT - 6))
      | (1ULL << (XiasParser::EXTERN - 6))
      | (1ULL << (XiasParser::NEW - 6))
      | (1ULL << (XiasParser::OVERRIDE - 6))
      | (1ULL << (XiasParser::PRIVATE - 6))
      | (1ULL << (XiasParser::PROTECTED - 6))
      | (1ULL << (XiasParser::PUBLIC - 6))
      | (1ULL << (XiasParser::READONLY - 6))
      | (1ULL << (XiasParser::SEALED - 6))
      | (1ULL << (XiasParser::STATIC - 6))
      | (1ULL << (XiasParser::VIRTUAL - 6)))) != 0)) {
      setState(779);
      all_modifier();
      setState(784);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(785);
    type_();
    setState(786);
    member_name();
    setState(787);
    property_body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Property_bodyContext ------------------------------------------------------------------

XiasParser::Property_bodyContext::Property_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Property_bodyContext::OPEN_BRACE() {
  return getToken(XiasParser::OPEN_BRACE, 0);
}

XiasParser::Accessor_declarationsContext* XiasParser::Property_bodyContext::accessor_declarations() {
  return getRuleContext<XiasParser::Accessor_declarationsContext>(0);
}

tree::TerminalNode* XiasParser::Property_bodyContext::CLOSE_BRACE() {
  return getToken(XiasParser::CLOSE_BRACE, 0);
}

XiasParser::Property_initializerContext* XiasParser::Property_bodyContext::property_initializer() {
  return getRuleContext<XiasParser::Property_initializerContext>(0);
}


size_t XiasParser::Property_bodyContext::getRuleIndex() const {
  return XiasParser::RuleProperty_body;
}


antlrcpp::Any XiasParser::Property_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitProperty_body(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Property_bodyContext* XiasParser::property_body() {
  Property_bodyContext *_localctx = _tracker.createInstance<Property_bodyContext>(_ctx, getState());
  enterRule(_localctx, 112, XiasParser::RuleProperty_body);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(789);
    match(XiasParser::OPEN_BRACE);
    setState(790);
    accessor_declarations();
    setState(791);
    match(XiasParser::CLOSE_BRACE);
    setState(793);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == XiasParser::ASSIGNMENT) {
      setState(792);
      property_initializer();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Accessor_declarationsContext ------------------------------------------------------------------

XiasParser::Accessor_declarationsContext::Accessor_declarationsContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Get_accessor_declarationContext* XiasParser::Accessor_declarationsContext::get_accessor_declaration() {
  return getRuleContext<XiasParser::Get_accessor_declarationContext>(0);
}

XiasParser::Set_accessor_declarationContext* XiasParser::Accessor_declarationsContext::set_accessor_declaration() {
  return getRuleContext<XiasParser::Set_accessor_declarationContext>(0);
}


size_t XiasParser::Accessor_declarationsContext::getRuleIndex() const {
  return XiasParser::RuleAccessor_declarations;
}


antlrcpp::Any XiasParser::Accessor_declarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitAccessor_declarations(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Accessor_declarationsContext* XiasParser::accessor_declarations() {
  Accessor_declarationsContext *_localctx = _tracker.createInstance<Accessor_declarationsContext>(_ctx, getState());
  enterRule(_localctx, 114, XiasParser::RuleAccessor_declarations);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(803);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(795);
      get_accessor_declaration();
      setState(797);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << XiasParser::INTERNAL)
        | (1ULL << XiasParser::PRIVATE)
        | (1ULL << XiasParser::PROTECTED)
        | (1ULL << XiasParser::SET))) != 0)) {
        setState(796);
        set_accessor_declaration();
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(799);
      set_accessor_declaration();
      setState(801);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << XiasParser::GET)
        | (1ULL << XiasParser::INTERNAL)
        | (1ULL << XiasParser::PRIVATE)
        | (1ULL << XiasParser::PROTECTED))) != 0)) {
        setState(800);
        get_accessor_declaration();
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Get_accessor_declarationContext ------------------------------------------------------------------

XiasParser::Get_accessor_declarationContext::Get_accessor_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Get_accessor_declarationContext::GET() {
  return getToken(XiasParser::GET, 0);
}

XiasParser::Accessor_bodyContext* XiasParser::Get_accessor_declarationContext::accessor_body() {
  return getRuleContext<XiasParser::Accessor_bodyContext>(0);
}

XiasParser::Accessor_modifierContext* XiasParser::Get_accessor_declarationContext::accessor_modifier() {
  return getRuleContext<XiasParser::Accessor_modifierContext>(0);
}


size_t XiasParser::Get_accessor_declarationContext::getRuleIndex() const {
  return XiasParser::RuleGet_accessor_declaration;
}


antlrcpp::Any XiasParser::Get_accessor_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitGet_accessor_declaration(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Get_accessor_declarationContext* XiasParser::get_accessor_declaration() {
  Get_accessor_declarationContext *_localctx = _tracker.createInstance<Get_accessor_declarationContext>(_ctx, getState());
  enterRule(_localctx, 116, XiasParser::RuleGet_accessor_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(806);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << XiasParser::INTERNAL)
      | (1ULL << XiasParser::PRIVATE)
      | (1ULL << XiasParser::PROTECTED))) != 0)) {
      setState(805);
      accessor_modifier();
    }
    setState(808);
    match(XiasParser::GET);
    setState(809);
    accessor_body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Set_accessor_declarationContext ------------------------------------------------------------------

XiasParser::Set_accessor_declarationContext::Set_accessor_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Set_accessor_declarationContext::SET() {
  return getToken(XiasParser::SET, 0);
}

XiasParser::Accessor_bodyContext* XiasParser::Set_accessor_declarationContext::accessor_body() {
  return getRuleContext<XiasParser::Accessor_bodyContext>(0);
}

XiasParser::Accessor_modifierContext* XiasParser::Set_accessor_declarationContext::accessor_modifier() {
  return getRuleContext<XiasParser::Accessor_modifierContext>(0);
}


size_t XiasParser::Set_accessor_declarationContext::getRuleIndex() const {
  return XiasParser::RuleSet_accessor_declaration;
}


antlrcpp::Any XiasParser::Set_accessor_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitSet_accessor_declaration(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Set_accessor_declarationContext* XiasParser::set_accessor_declaration() {
  Set_accessor_declarationContext *_localctx = _tracker.createInstance<Set_accessor_declarationContext>(_ctx, getState());
  enterRule(_localctx, 118, XiasParser::RuleSet_accessor_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(812);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << XiasParser::INTERNAL)
      | (1ULL << XiasParser::PRIVATE)
      | (1ULL << XiasParser::PROTECTED))) != 0)) {
      setState(811);
      accessor_modifier();
    }
    setState(814);
    match(XiasParser::SET);
    setState(815);
    accessor_body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Accessor_modifierContext ------------------------------------------------------------------

XiasParser::Accessor_modifierContext::Accessor_modifierContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Accessor_modifierContext::PROTECTED() {
  return getToken(XiasParser::PROTECTED, 0);
}

tree::TerminalNode* XiasParser::Accessor_modifierContext::INTERNAL() {
  return getToken(XiasParser::INTERNAL, 0);
}

tree::TerminalNode* XiasParser::Accessor_modifierContext::PRIVATE() {
  return getToken(XiasParser::PRIVATE, 0);
}


size_t XiasParser::Accessor_modifierContext::getRuleIndex() const {
  return XiasParser::RuleAccessor_modifier;
}


antlrcpp::Any XiasParser::Accessor_modifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitAccessor_modifier(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Accessor_modifierContext* XiasParser::accessor_modifier() {
  Accessor_modifierContext *_localctx = _tracker.createInstance<Accessor_modifierContext>(_ctx, getState());
  enterRule(_localctx, 120, XiasParser::RuleAccessor_modifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(824);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(817);
      match(XiasParser::PROTECTED);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(818);
      match(XiasParser::INTERNAL);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(819);
      match(XiasParser::PRIVATE);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(820);
      match(XiasParser::PROTECTED);
      setState(821);
      match(XiasParser::INTERNAL);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(822);
      match(XiasParser::INTERNAL);
      setState(823);
      match(XiasParser::PROTECTED);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Accessor_bodyContext ------------------------------------------------------------------

XiasParser::Accessor_bodyContext::Accessor_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::BlockContext* XiasParser::Accessor_bodyContext::block() {
  return getRuleContext<XiasParser::BlockContext>(0);
}

tree::TerminalNode* XiasParser::Accessor_bodyContext::SEMICOLON() {
  return getToken(XiasParser::SEMICOLON, 0);
}


size_t XiasParser::Accessor_bodyContext::getRuleIndex() const {
  return XiasParser::RuleAccessor_body;
}


antlrcpp::Any XiasParser::Accessor_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitAccessor_body(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Accessor_bodyContext* XiasParser::accessor_body() {
  Accessor_bodyContext *_localctx = _tracker.createInstance<Accessor_bodyContext>(_ctx, getState());
  enterRule(_localctx, 122, XiasParser::RuleAccessor_body);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(828);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case XiasParser::OPEN_BRACE: {
        enterOuterAlt(_localctx, 1);
        setState(826);
        block();
        break;
      }

      case XiasParser::SEMICOLON: {
        enterOuterAlt(_localctx, 2);
        setState(827);
        match(XiasParser::SEMICOLON);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Property_initializerContext ------------------------------------------------------------------

XiasParser::Property_initializerContext::Property_initializerContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Property_initializerContext::ASSIGNMENT() {
  return getToken(XiasParser::ASSIGNMENT, 0);
}

XiasParser::Variable_initializerContext* XiasParser::Property_initializerContext::variable_initializer() {
  return getRuleContext<XiasParser::Variable_initializerContext>(0);
}

tree::TerminalNode* XiasParser::Property_initializerContext::SEMICOLON() {
  return getToken(XiasParser::SEMICOLON, 0);
}


size_t XiasParser::Property_initializerContext::getRuleIndex() const {
  return XiasParser::RuleProperty_initializer;
}


antlrcpp::Any XiasParser::Property_initializerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitProperty_initializer(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Property_initializerContext* XiasParser::property_initializer() {
  Property_initializerContext *_localctx = _tracker.createInstance<Property_initializerContext>(_ctx, getState());
  enterRule(_localctx, 124, XiasParser::RuleProperty_initializer);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(830);
    match(XiasParser::ASSIGNMENT);
    setState(831);
    variable_initializer();
    setState(832);
    match(XiasParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Indexer_declarationContext ------------------------------------------------------------------

XiasParser::Indexer_declarationContext::Indexer_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Indexer_declaratorContext* XiasParser::Indexer_declarationContext::indexer_declarator() {
  return getRuleContext<XiasParser::Indexer_declaratorContext>(0);
}

XiasParser::Indexer_bodyContext* XiasParser::Indexer_declarationContext::indexer_body() {
  return getRuleContext<XiasParser::Indexer_bodyContext>(0);
}

std::vector<XiasParser::Indexer_modifierContext *> XiasParser::Indexer_declarationContext::indexer_modifier() {
  return getRuleContexts<XiasParser::Indexer_modifierContext>();
}

XiasParser::Indexer_modifierContext* XiasParser::Indexer_declarationContext::indexer_modifier(size_t i) {
  return getRuleContext<XiasParser::Indexer_modifierContext>(i);
}


size_t XiasParser::Indexer_declarationContext::getRuleIndex() const {
  return XiasParser::RuleIndexer_declaration;
}


antlrcpp::Any XiasParser::Indexer_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitIndexer_declaration(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Indexer_declarationContext* XiasParser::indexer_declaration() {
  Indexer_declarationContext *_localctx = _tracker.createInstance<Indexer_declarationContext>(_ctx, getState());
  enterRule(_localctx, 126, XiasParser::RuleIndexer_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(837);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 6) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 6)) & ((1ULL << (XiasParser::ABSTRACT - 6))
      | (1ULL << (XiasParser::INTERNAL - 6))
      | (1ULL << (XiasParser::NEW - 6))
      | (1ULL << (XiasParser::OVERRIDE - 6))
      | (1ULL << (XiasParser::PRIVATE - 6))
      | (1ULL << (XiasParser::PROTECTED - 6))
      | (1ULL << (XiasParser::PUBLIC - 6))
      | (1ULL << (XiasParser::SEALED - 6))
      | (1ULL << (XiasParser::STATIC - 6))
      | (1ULL << (XiasParser::VIRTUAL - 6)))) != 0)) {
      setState(834);
      indexer_modifier();
      setState(839);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(840);
    indexer_declarator();
    setState(841);
    indexer_body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Indexer_modifierContext ------------------------------------------------------------------

XiasParser::Indexer_modifierContext::Indexer_modifierContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Indexer_modifierContext::NEW() {
  return getToken(XiasParser::NEW, 0);
}

tree::TerminalNode* XiasParser::Indexer_modifierContext::PUBLIC() {
  return getToken(XiasParser::PUBLIC, 0);
}

tree::TerminalNode* XiasParser::Indexer_modifierContext::PROTECTED() {
  return getToken(XiasParser::PROTECTED, 0);
}

tree::TerminalNode* XiasParser::Indexer_modifierContext::INTERNAL() {
  return getToken(XiasParser::INTERNAL, 0);
}

tree::TerminalNode* XiasParser::Indexer_modifierContext::PRIVATE() {
  return getToken(XiasParser::PRIVATE, 0);
}

tree::TerminalNode* XiasParser::Indexer_modifierContext::STATIC() {
  return getToken(XiasParser::STATIC, 0);
}

tree::TerminalNode* XiasParser::Indexer_modifierContext::VIRTUAL() {
  return getToken(XiasParser::VIRTUAL, 0);
}

tree::TerminalNode* XiasParser::Indexer_modifierContext::SEALED() {
  return getToken(XiasParser::SEALED, 0);
}

tree::TerminalNode* XiasParser::Indexer_modifierContext::OVERRIDE() {
  return getToken(XiasParser::OVERRIDE, 0);
}

tree::TerminalNode* XiasParser::Indexer_modifierContext::ABSTRACT() {
  return getToken(XiasParser::ABSTRACT, 0);
}


size_t XiasParser::Indexer_modifierContext::getRuleIndex() const {
  return XiasParser::RuleIndexer_modifier;
}


antlrcpp::Any XiasParser::Indexer_modifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitIndexer_modifier(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Indexer_modifierContext* XiasParser::indexer_modifier() {
  Indexer_modifierContext *_localctx = _tracker.createInstance<Indexer_modifierContext>(_ctx, getState());
  enterRule(_localctx, 128, XiasParser::RuleIndexer_modifier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(843);
    _la = _input->LA(1);
    if (!(((((_la - 6) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 6)) & ((1ULL << (XiasParser::ABSTRACT - 6))
      | (1ULL << (XiasParser::INTERNAL - 6))
      | (1ULL << (XiasParser::NEW - 6))
      | (1ULL << (XiasParser::OVERRIDE - 6))
      | (1ULL << (XiasParser::PRIVATE - 6))
      | (1ULL << (XiasParser::PROTECTED - 6))
      | (1ULL << (XiasParser::PUBLIC - 6))
      | (1ULL << (XiasParser::SEALED - 6))
      | (1ULL << (XiasParser::STATIC - 6))
      | (1ULL << (XiasParser::VIRTUAL - 6)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Indexer_declaratorContext ------------------------------------------------------------------

XiasParser::Indexer_declaratorContext::Indexer_declaratorContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Type_Context* XiasParser::Indexer_declaratorContext::type_() {
  return getRuleContext<XiasParser::Type_Context>(0);
}

tree::TerminalNode* XiasParser::Indexer_declaratorContext::THIS() {
  return getToken(XiasParser::THIS, 0);
}

tree::TerminalNode* XiasParser::Indexer_declaratorContext::OPEN_BRACKET() {
  return getToken(XiasParser::OPEN_BRACKET, 0);
}

XiasParser::Formal_parameter_listContext* XiasParser::Indexer_declaratorContext::formal_parameter_list() {
  return getRuleContext<XiasParser::Formal_parameter_listContext>(0);
}

tree::TerminalNode* XiasParser::Indexer_declaratorContext::CLOSE_BRACKET() {
  return getToken(XiasParser::CLOSE_BRACKET, 0);
}

XiasParser::Interface_typeContext* XiasParser::Indexer_declaratorContext::interface_type() {
  return getRuleContext<XiasParser::Interface_typeContext>(0);
}

tree::TerminalNode* XiasParser::Indexer_declaratorContext::DOT() {
  return getToken(XiasParser::DOT, 0);
}


size_t XiasParser::Indexer_declaratorContext::getRuleIndex() const {
  return XiasParser::RuleIndexer_declarator;
}


antlrcpp::Any XiasParser::Indexer_declaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitIndexer_declarator(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Indexer_declaratorContext* XiasParser::indexer_declarator() {
  Indexer_declaratorContext *_localctx = _tracker.createInstance<Indexer_declaratorContext>(_ctx, getState());
  enterRule(_localctx, 130, XiasParser::RuleIndexer_declarator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(859);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(845);
      type_();
      setState(846);
      match(XiasParser::THIS);
      setState(847);
      match(XiasParser::OPEN_BRACKET);
      setState(848);
      formal_parameter_list();
      setState(849);
      match(XiasParser::CLOSE_BRACKET);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(851);
      type_();
      setState(852);
      interface_type();
      setState(853);
      match(XiasParser::DOT);
      setState(854);
      match(XiasParser::THIS);
      setState(855);
      match(XiasParser::OPEN_BRACKET);
      setState(856);
      formal_parameter_list();
      setState(857);
      match(XiasParser::CLOSE_BRACKET);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Indexer_bodyContext ------------------------------------------------------------------

XiasParser::Indexer_bodyContext::Indexer_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Indexer_bodyContext::OPEN_BRACE() {
  return getToken(XiasParser::OPEN_BRACE, 0);
}

XiasParser::Accessor_declarationsContext* XiasParser::Indexer_bodyContext::accessor_declarations() {
  return getRuleContext<XiasParser::Accessor_declarationsContext>(0);
}

tree::TerminalNode* XiasParser::Indexer_bodyContext::CLOSE_BRACE() {
  return getToken(XiasParser::CLOSE_BRACE, 0);
}


size_t XiasParser::Indexer_bodyContext::getRuleIndex() const {
  return XiasParser::RuleIndexer_body;
}


antlrcpp::Any XiasParser::Indexer_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitIndexer_body(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Indexer_bodyContext* XiasParser::indexer_body() {
  Indexer_bodyContext *_localctx = _tracker.createInstance<Indexer_bodyContext>(_ctx, getState());
  enterRule(_localctx, 132, XiasParser::RuleIndexer_body);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(861);
    match(XiasParser::OPEN_BRACE);
    setState(862);
    accessor_declarations();
    setState(863);
    match(XiasParser::CLOSE_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Operator_declarationContext ------------------------------------------------------------------

XiasParser::Operator_declarationContext::Operator_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Operator_declaratorContext* XiasParser::Operator_declarationContext::operator_declarator() {
  return getRuleContext<XiasParser::Operator_declaratorContext>(0);
}

XiasParser::Operator_bodyContext* XiasParser::Operator_declarationContext::operator_body() {
  return getRuleContext<XiasParser::Operator_bodyContext>(0);
}

std::vector<XiasParser::Operator_modifierContext *> XiasParser::Operator_declarationContext::operator_modifier() {
  return getRuleContexts<XiasParser::Operator_modifierContext>();
}

XiasParser::Operator_modifierContext* XiasParser::Operator_declarationContext::operator_modifier(size_t i) {
  return getRuleContext<XiasParser::Operator_modifierContext>(i);
}


size_t XiasParser::Operator_declarationContext::getRuleIndex() const {
  return XiasParser::RuleOperator_declaration;
}


antlrcpp::Any XiasParser::Operator_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitOperator_declaration(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Operator_declarationContext* XiasParser::operator_declaration() {
  Operator_declarationContext *_localctx = _tracker.createInstance<Operator_declarationContext>(_ctx, getState());
  enterRule(_localctx, 134, XiasParser::RuleOperator_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(866); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(865);
      operator_modifier();
      setState(868); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == XiasParser::PUBLIC

    || _la == XiasParser::STATIC);
    setState(870);
    operator_declarator();
    setState(871);
    operator_body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Operator_modifierContext ------------------------------------------------------------------

XiasParser::Operator_modifierContext::Operator_modifierContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Operator_modifierContext::PUBLIC() {
  return getToken(XiasParser::PUBLIC, 0);
}

tree::TerminalNode* XiasParser::Operator_modifierContext::STATIC() {
  return getToken(XiasParser::STATIC, 0);
}


size_t XiasParser::Operator_modifierContext::getRuleIndex() const {
  return XiasParser::RuleOperator_modifier;
}


antlrcpp::Any XiasParser::Operator_modifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitOperator_modifier(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Operator_modifierContext* XiasParser::operator_modifier() {
  Operator_modifierContext *_localctx = _tracker.createInstance<Operator_modifierContext>(_ctx, getState());
  enterRule(_localctx, 136, XiasParser::RuleOperator_modifier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(873);
    _la = _input->LA(1);
    if (!(_la == XiasParser::PUBLIC

    || _la == XiasParser::STATIC)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Operator_declaratorContext ------------------------------------------------------------------

XiasParser::Operator_declaratorContext::Operator_declaratorContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Unary_operator_declaratorContext* XiasParser::Operator_declaratorContext::unary_operator_declarator() {
  return getRuleContext<XiasParser::Unary_operator_declaratorContext>(0);
}

XiasParser::Binary_operator_declaratorContext* XiasParser::Operator_declaratorContext::binary_operator_declarator() {
  return getRuleContext<XiasParser::Binary_operator_declaratorContext>(0);
}

XiasParser::Conversion_operator_declaratorContext* XiasParser::Operator_declaratorContext::conversion_operator_declarator() {
  return getRuleContext<XiasParser::Conversion_operator_declaratorContext>(0);
}


size_t XiasParser::Operator_declaratorContext::getRuleIndex() const {
  return XiasParser::RuleOperator_declarator;
}


antlrcpp::Any XiasParser::Operator_declaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitOperator_declarator(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Operator_declaratorContext* XiasParser::operator_declarator() {
  Operator_declaratorContext *_localctx = _tracker.createInstance<Operator_declaratorContext>(_ctx, getState());
  enterRule(_localctx, 138, XiasParser::RuleOperator_declarator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(878);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 64, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(875);
      unary_operator_declarator();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(876);
      binary_operator_declarator();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(877);
      conversion_operator_declarator();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unary_operator_declaratorContext ------------------------------------------------------------------

XiasParser::Unary_operator_declaratorContext::Unary_operator_declaratorContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

std::vector<XiasParser::Type_Context *> XiasParser::Unary_operator_declaratorContext::type_() {
  return getRuleContexts<XiasParser::Type_Context>();
}

XiasParser::Type_Context* XiasParser::Unary_operator_declaratorContext::type_(size_t i) {
  return getRuleContext<XiasParser::Type_Context>(i);
}

tree::TerminalNode* XiasParser::Unary_operator_declaratorContext::OPERATOR() {
  return getToken(XiasParser::OPERATOR, 0);
}

XiasParser::Overloadable_unary_operatorContext* XiasParser::Unary_operator_declaratorContext::overloadable_unary_operator() {
  return getRuleContext<XiasParser::Overloadable_unary_operatorContext>(0);
}

tree::TerminalNode* XiasParser::Unary_operator_declaratorContext::OPEN_PARENS() {
  return getToken(XiasParser::OPEN_PARENS, 0);
}

XiasParser::IdentifierContext* XiasParser::Unary_operator_declaratorContext::identifier() {
  return getRuleContext<XiasParser::IdentifierContext>(0);
}

tree::TerminalNode* XiasParser::Unary_operator_declaratorContext::CLOSE_PARENS() {
  return getToken(XiasParser::CLOSE_PARENS, 0);
}


size_t XiasParser::Unary_operator_declaratorContext::getRuleIndex() const {
  return XiasParser::RuleUnary_operator_declarator;
}


antlrcpp::Any XiasParser::Unary_operator_declaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitUnary_operator_declarator(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Unary_operator_declaratorContext* XiasParser::unary_operator_declarator() {
  Unary_operator_declaratorContext *_localctx = _tracker.createInstance<Unary_operator_declaratorContext>(_ctx, getState());
  enterRule(_localctx, 140, XiasParser::RuleUnary_operator_declarator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(880);
    type_();
    setState(881);
    match(XiasParser::OPERATOR);
    setState(882);
    overloadable_unary_operator();
    setState(883);
    match(XiasParser::OPEN_PARENS);
    setState(884);
    type_();
    setState(885);
    identifier();
    setState(886);
    match(XiasParser::CLOSE_PARENS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Overloadable_unary_operatorContext ------------------------------------------------------------------

XiasParser::Overloadable_unary_operatorContext::Overloadable_unary_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Overloadable_unary_operatorContext::PLUS() {
  return getToken(XiasParser::PLUS, 0);
}

tree::TerminalNode* XiasParser::Overloadable_unary_operatorContext::MINUS() {
  return getToken(XiasParser::MINUS, 0);
}

tree::TerminalNode* XiasParser::Overloadable_unary_operatorContext::BANG() {
  return getToken(XiasParser::BANG, 0);
}

tree::TerminalNode* XiasParser::Overloadable_unary_operatorContext::TILDE() {
  return getToken(XiasParser::TILDE, 0);
}

tree::TerminalNode* XiasParser::Overloadable_unary_operatorContext::OP_INC() {
  return getToken(XiasParser::OP_INC, 0);
}

tree::TerminalNode* XiasParser::Overloadable_unary_operatorContext::OP_DEC() {
  return getToken(XiasParser::OP_DEC, 0);
}

tree::TerminalNode* XiasParser::Overloadable_unary_operatorContext::TRUE() {
  return getToken(XiasParser::TRUE, 0);
}

tree::TerminalNode* XiasParser::Overloadable_unary_operatorContext::FALSE() {
  return getToken(XiasParser::FALSE, 0);
}


size_t XiasParser::Overloadable_unary_operatorContext::getRuleIndex() const {
  return XiasParser::RuleOverloadable_unary_operator;
}


antlrcpp::Any XiasParser::Overloadable_unary_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitOverloadable_unary_operator(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Overloadable_unary_operatorContext* XiasParser::overloadable_unary_operator() {
  Overloadable_unary_operatorContext *_localctx = _tracker.createInstance<Overloadable_unary_operatorContext>(_ctx, getState());
  enterRule(_localctx, 142, XiasParser::RuleOverloadable_unary_operator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(888);
    _la = _input->LA(1);
    if (!(_la == XiasParser::FALSE

    || _la == XiasParser::TRUE || ((((_la - 92) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 92)) & ((1ULL << (XiasParser::PLUS - 92))
      | (1ULL << (XiasParser::MINUS - 92))
      | (1ULL << (XiasParser::BANG - 92))
      | (1ULL << (XiasParser::TILDE - 92))
      | (1ULL << (XiasParser::OP_INC - 92))
      | (1ULL << (XiasParser::OP_DEC - 92)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binary_operator_declaratorContext ------------------------------------------------------------------

XiasParser::Binary_operator_declaratorContext::Binary_operator_declaratorContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

std::vector<XiasParser::Type_Context *> XiasParser::Binary_operator_declaratorContext::type_() {
  return getRuleContexts<XiasParser::Type_Context>();
}

XiasParser::Type_Context* XiasParser::Binary_operator_declaratorContext::type_(size_t i) {
  return getRuleContext<XiasParser::Type_Context>(i);
}

tree::TerminalNode* XiasParser::Binary_operator_declaratorContext::OPERATOR() {
  return getToken(XiasParser::OPERATOR, 0);
}

XiasParser::Overloadable_binary_operatorContext* XiasParser::Binary_operator_declaratorContext::overloadable_binary_operator() {
  return getRuleContext<XiasParser::Overloadable_binary_operatorContext>(0);
}

tree::TerminalNode* XiasParser::Binary_operator_declaratorContext::OPEN_PARENS() {
  return getToken(XiasParser::OPEN_PARENS, 0);
}

std::vector<XiasParser::IdentifierContext *> XiasParser::Binary_operator_declaratorContext::identifier() {
  return getRuleContexts<XiasParser::IdentifierContext>();
}

XiasParser::IdentifierContext* XiasParser::Binary_operator_declaratorContext::identifier(size_t i) {
  return getRuleContext<XiasParser::IdentifierContext>(i);
}

tree::TerminalNode* XiasParser::Binary_operator_declaratorContext::COMMA() {
  return getToken(XiasParser::COMMA, 0);
}

tree::TerminalNode* XiasParser::Binary_operator_declaratorContext::CLOSE_PARENS() {
  return getToken(XiasParser::CLOSE_PARENS, 0);
}


size_t XiasParser::Binary_operator_declaratorContext::getRuleIndex() const {
  return XiasParser::RuleBinary_operator_declarator;
}


antlrcpp::Any XiasParser::Binary_operator_declaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitBinary_operator_declarator(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Binary_operator_declaratorContext* XiasParser::binary_operator_declarator() {
  Binary_operator_declaratorContext *_localctx = _tracker.createInstance<Binary_operator_declaratorContext>(_ctx, getState());
  enterRule(_localctx, 144, XiasParser::RuleBinary_operator_declarator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(890);
    type_();
    setState(891);
    match(XiasParser::OPERATOR);
    setState(892);
    overloadable_binary_operator();
    setState(893);
    match(XiasParser::OPEN_PARENS);
    setState(894);
    type_();
    setState(895);
    identifier();
    setState(896);
    match(XiasParser::COMMA);
    setState(897);
    type_();
    setState(898);
    identifier();
    setState(899);
    match(XiasParser::CLOSE_PARENS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Overloadable_binary_operatorContext ------------------------------------------------------------------

XiasParser::Overloadable_binary_operatorContext::Overloadable_binary_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Overloadable_binary_operatorContext::PLUS() {
  return getToken(XiasParser::PLUS, 0);
}

tree::TerminalNode* XiasParser::Overloadable_binary_operatorContext::MINUS() {
  return getToken(XiasParser::MINUS, 0);
}

tree::TerminalNode* XiasParser::Overloadable_binary_operatorContext::STAR() {
  return getToken(XiasParser::STAR, 0);
}

tree::TerminalNode* XiasParser::Overloadable_binary_operatorContext::DIV() {
  return getToken(XiasParser::DIV, 0);
}

tree::TerminalNode* XiasParser::Overloadable_binary_operatorContext::PERCENT() {
  return getToken(XiasParser::PERCENT, 0);
}

tree::TerminalNode* XiasParser::Overloadable_binary_operatorContext::AMP() {
  return getToken(XiasParser::AMP, 0);
}

tree::TerminalNode* XiasParser::Overloadable_binary_operatorContext::BITWISE_OR() {
  return getToken(XiasParser::BITWISE_OR, 0);
}

tree::TerminalNode* XiasParser::Overloadable_binary_operatorContext::CARET() {
  return getToken(XiasParser::CARET, 0);
}

tree::TerminalNode* XiasParser::Overloadable_binary_operatorContext::OP_LEFT_SHIFT() {
  return getToken(XiasParser::OP_LEFT_SHIFT, 0);
}

XiasParser::Right_shiftContext* XiasParser::Overloadable_binary_operatorContext::right_shift() {
  return getRuleContext<XiasParser::Right_shiftContext>(0);
}

tree::TerminalNode* XiasParser::Overloadable_binary_operatorContext::OP_EQ() {
  return getToken(XiasParser::OP_EQ, 0);
}

tree::TerminalNode* XiasParser::Overloadable_binary_operatorContext::OP_NE() {
  return getToken(XiasParser::OP_NE, 0);
}

tree::TerminalNode* XiasParser::Overloadable_binary_operatorContext::GT() {
  return getToken(XiasParser::GT, 0);
}

tree::TerminalNode* XiasParser::Overloadable_binary_operatorContext::LT() {
  return getToken(XiasParser::LT, 0);
}

tree::TerminalNode* XiasParser::Overloadable_binary_operatorContext::OP_GE() {
  return getToken(XiasParser::OP_GE, 0);
}

tree::TerminalNode* XiasParser::Overloadable_binary_operatorContext::OP_LE() {
  return getToken(XiasParser::OP_LE, 0);
}


size_t XiasParser::Overloadable_binary_operatorContext::getRuleIndex() const {
  return XiasParser::RuleOverloadable_binary_operator;
}


antlrcpp::Any XiasParser::Overloadable_binary_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitOverloadable_binary_operator(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Overloadable_binary_operatorContext* XiasParser::overloadable_binary_operator() {
  Overloadable_binary_operatorContext *_localctx = _tracker.createInstance<Overloadable_binary_operatorContext>(_ctx, getState());
  enterRule(_localctx, 146, XiasParser::RuleOverloadable_binary_operator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(917);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(901);
      match(XiasParser::PLUS);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(902);
      match(XiasParser::MINUS);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(903);
      match(XiasParser::STAR);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(904);
      match(XiasParser::DIV);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(905);
      match(XiasParser::PERCENT);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(906);
      match(XiasParser::AMP);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(907);
      match(XiasParser::BITWISE_OR);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(908);
      match(XiasParser::CARET);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(909);
      match(XiasParser::OP_LEFT_SHIFT);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(910);
      right_shift();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(911);
      match(XiasParser::OP_EQ);
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(912);
      match(XiasParser::OP_NE);
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(913);
      match(XiasParser::GT);
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(914);
      match(XiasParser::LT);
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(915);
      match(XiasParser::OP_GE);
      break;
    }

    case 16: {
      enterOuterAlt(_localctx, 16);
      setState(916);
      match(XiasParser::OP_LE);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Conversion_operator_declaratorContext ------------------------------------------------------------------

XiasParser::Conversion_operator_declaratorContext::Conversion_operator_declaratorContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Conversion_operator_declaratorContext::IMPLICIT() {
  return getToken(XiasParser::IMPLICIT, 0);
}

tree::TerminalNode* XiasParser::Conversion_operator_declaratorContext::OPERATOR() {
  return getToken(XiasParser::OPERATOR, 0);
}

std::vector<XiasParser::Type_Context *> XiasParser::Conversion_operator_declaratorContext::type_() {
  return getRuleContexts<XiasParser::Type_Context>();
}

XiasParser::Type_Context* XiasParser::Conversion_operator_declaratorContext::type_(size_t i) {
  return getRuleContext<XiasParser::Type_Context>(i);
}

tree::TerminalNode* XiasParser::Conversion_operator_declaratorContext::OPEN_PARENS() {
  return getToken(XiasParser::OPEN_PARENS, 0);
}

XiasParser::IdentifierContext* XiasParser::Conversion_operator_declaratorContext::identifier() {
  return getRuleContext<XiasParser::IdentifierContext>(0);
}

tree::TerminalNode* XiasParser::Conversion_operator_declaratorContext::CLOSE_PARENS() {
  return getToken(XiasParser::CLOSE_PARENS, 0);
}

tree::TerminalNode* XiasParser::Conversion_operator_declaratorContext::EXPLICIT() {
  return getToken(XiasParser::EXPLICIT, 0);
}


size_t XiasParser::Conversion_operator_declaratorContext::getRuleIndex() const {
  return XiasParser::RuleConversion_operator_declarator;
}


antlrcpp::Any XiasParser::Conversion_operator_declaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitConversion_operator_declarator(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Conversion_operator_declaratorContext* XiasParser::conversion_operator_declarator() {
  Conversion_operator_declaratorContext *_localctx = _tracker.createInstance<Conversion_operator_declaratorContext>(_ctx, getState());
  enterRule(_localctx, 148, XiasParser::RuleConversion_operator_declarator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(935);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case XiasParser::IMPLICIT: {
        enterOuterAlt(_localctx, 1);
        setState(919);
        match(XiasParser::IMPLICIT);
        setState(920);
        match(XiasParser::OPERATOR);
        setState(921);
        type_();
        setState(922);
        match(XiasParser::OPEN_PARENS);
        setState(923);
        type_();
        setState(924);
        identifier();
        setState(925);
        match(XiasParser::CLOSE_PARENS);
        break;
      }

      case XiasParser::EXPLICIT: {
        enterOuterAlt(_localctx, 2);
        setState(927);
        match(XiasParser::EXPLICIT);
        setState(928);
        match(XiasParser::OPERATOR);
        setState(929);
        type_();
        setState(930);
        match(XiasParser::OPEN_PARENS);
        setState(931);
        type_();
        setState(932);
        identifier();
        setState(933);
        match(XiasParser::CLOSE_PARENS);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Operator_bodyContext ------------------------------------------------------------------

XiasParser::Operator_bodyContext::Operator_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::BlockContext* XiasParser::Operator_bodyContext::block() {
  return getRuleContext<XiasParser::BlockContext>(0);
}

tree::TerminalNode* XiasParser::Operator_bodyContext::SEMICOLON() {
  return getToken(XiasParser::SEMICOLON, 0);
}


size_t XiasParser::Operator_bodyContext::getRuleIndex() const {
  return XiasParser::RuleOperator_body;
}


antlrcpp::Any XiasParser::Operator_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitOperator_body(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Operator_bodyContext* XiasParser::operator_body() {
  Operator_bodyContext *_localctx = _tracker.createInstance<Operator_bodyContext>(_ctx, getState());
  enterRule(_localctx, 150, XiasParser::RuleOperator_body);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(939);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case XiasParser::OPEN_BRACE: {
        enterOuterAlt(_localctx, 1);
        setState(937);
        block();
        break;
      }

      case XiasParser::SEMICOLON: {
        enterOuterAlt(_localctx, 2);
        setState(938);
        match(XiasParser::SEMICOLON);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Constructor_declarationContext ------------------------------------------------------------------

XiasParser::Constructor_declarationContext::Constructor_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Constructor_declaratorContext* XiasParser::Constructor_declarationContext::constructor_declarator() {
  return getRuleContext<XiasParser::Constructor_declaratorContext>(0);
}

XiasParser::Constructor_bodyContext* XiasParser::Constructor_declarationContext::constructor_body() {
  return getRuleContext<XiasParser::Constructor_bodyContext>(0);
}

std::vector<XiasParser::Constructor_modifierContext *> XiasParser::Constructor_declarationContext::constructor_modifier() {
  return getRuleContexts<XiasParser::Constructor_modifierContext>();
}

XiasParser::Constructor_modifierContext* XiasParser::Constructor_declarationContext::constructor_modifier(size_t i) {
  return getRuleContext<XiasParser::Constructor_modifierContext>(i);
}


size_t XiasParser::Constructor_declarationContext::getRuleIndex() const {
  return XiasParser::RuleConstructor_declaration;
}


antlrcpp::Any XiasParser::Constructor_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitConstructor_declaration(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Constructor_declarationContext* XiasParser::constructor_declaration() {
  Constructor_declarationContext *_localctx = _tracker.createInstance<Constructor_declarationContext>(_ctx, getState());
  enterRule(_localctx, 152, XiasParser::RuleConstructor_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(944);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << XiasParser::INTERNAL)
      | (1ULL << XiasParser::PRIVATE)
      | (1ULL << XiasParser::PROTECTED)
      | (1ULL << XiasParser::PUBLIC))) != 0)) {
      setState(941);
      constructor_modifier();
      setState(946);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(947);
    constructor_declarator();
    setState(948);
    constructor_body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Constructor_modifierContext ------------------------------------------------------------------

XiasParser::Constructor_modifierContext::Constructor_modifierContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Constructor_modifierContext::PUBLIC() {
  return getToken(XiasParser::PUBLIC, 0);
}

tree::TerminalNode* XiasParser::Constructor_modifierContext::PROTECTED() {
  return getToken(XiasParser::PROTECTED, 0);
}

tree::TerminalNode* XiasParser::Constructor_modifierContext::INTERNAL() {
  return getToken(XiasParser::INTERNAL, 0);
}

tree::TerminalNode* XiasParser::Constructor_modifierContext::PRIVATE() {
  return getToken(XiasParser::PRIVATE, 0);
}


size_t XiasParser::Constructor_modifierContext::getRuleIndex() const {
  return XiasParser::RuleConstructor_modifier;
}


antlrcpp::Any XiasParser::Constructor_modifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitConstructor_modifier(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Constructor_modifierContext* XiasParser::constructor_modifier() {
  Constructor_modifierContext *_localctx = _tracker.createInstance<Constructor_modifierContext>(_ctx, getState());
  enterRule(_localctx, 154, XiasParser::RuleConstructor_modifier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(950);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << XiasParser::INTERNAL)
      | (1ULL << XiasParser::PRIVATE)
      | (1ULL << XiasParser::PROTECTED)
      | (1ULL << XiasParser::PUBLIC))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Constructor_declaratorContext ------------------------------------------------------------------

XiasParser::Constructor_declaratorContext::Constructor_declaratorContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::IdentifierContext* XiasParser::Constructor_declaratorContext::identifier() {
  return getRuleContext<XiasParser::IdentifierContext>(0);
}

tree::TerminalNode* XiasParser::Constructor_declaratorContext::OPEN_PARENS() {
  return getToken(XiasParser::OPEN_PARENS, 0);
}

tree::TerminalNode* XiasParser::Constructor_declaratorContext::CLOSE_PARENS() {
  return getToken(XiasParser::CLOSE_PARENS, 0);
}

XiasParser::Formal_parameter_listContext* XiasParser::Constructor_declaratorContext::formal_parameter_list() {
  return getRuleContext<XiasParser::Formal_parameter_listContext>(0);
}

XiasParser::Constructor_initializerContext* XiasParser::Constructor_declaratorContext::constructor_initializer() {
  return getRuleContext<XiasParser::Constructor_initializerContext>(0);
}


size_t XiasParser::Constructor_declaratorContext::getRuleIndex() const {
  return XiasParser::RuleConstructor_declarator;
}


antlrcpp::Any XiasParser::Constructor_declaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitConstructor_declarator(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Constructor_declaratorContext* XiasParser::constructor_declarator() {
  Constructor_declaratorContext *_localctx = _tracker.createInstance<Constructor_declaratorContext>(_ctx, getState());
  enterRule(_localctx, 156, XiasParser::RuleConstructor_declarator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(952);
    identifier();
    setState(953);
    match(XiasParser::OPEN_PARENS);
    setState(955);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 10) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 10)) & ((1ULL << (XiasParser::BOOL - 10))
      | (1ULL << (XiasParser::CHAR - 10))
      | (1ULL << (XiasParser::DOUBLE - 10))
      | (1ULL << (XiasParser::FLOAT - 10))
      | (1ULL << (XiasParser::INT - 10))
      | (1ULL << (XiasParser::OBJECT - 10))
      | (1ULL << (XiasParser::STRING - 10))
      | (1ULL << (XiasParser::THIS - 10))
      | (1ULL << (XiasParser::UINT - 10))
      | (1ULL << (XiasParser::IDENTIFIER - 10)))) != 0)) {
      setState(954);
      formal_parameter_list();
    }
    setState(957);
    match(XiasParser::CLOSE_PARENS);
    setState(959);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == XiasParser::COLON) {
      setState(958);
      constructor_initializer();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Constructor_initializerContext ------------------------------------------------------------------

XiasParser::Constructor_initializerContext::Constructor_initializerContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Constructor_initializerContext::COLON() {
  return getToken(XiasParser::COLON, 0);
}

tree::TerminalNode* XiasParser::Constructor_initializerContext::BASE() {
  return getToken(XiasParser::BASE, 0);
}

tree::TerminalNode* XiasParser::Constructor_initializerContext::OPEN_PARENS() {
  return getToken(XiasParser::OPEN_PARENS, 0);
}

tree::TerminalNode* XiasParser::Constructor_initializerContext::CLOSE_PARENS() {
  return getToken(XiasParser::CLOSE_PARENS, 0);
}

XiasParser::Argument_listContext* XiasParser::Constructor_initializerContext::argument_list() {
  return getRuleContext<XiasParser::Argument_listContext>(0);
}

tree::TerminalNode* XiasParser::Constructor_initializerContext::THIS() {
  return getToken(XiasParser::THIS, 0);
}


size_t XiasParser::Constructor_initializerContext::getRuleIndex() const {
  return XiasParser::RuleConstructor_initializer;
}


antlrcpp::Any XiasParser::Constructor_initializerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitConstructor_initializer(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Constructor_initializerContext* XiasParser::constructor_initializer() {
  Constructor_initializerContext *_localctx = _tracker.createInstance<Constructor_initializerContext>(_ctx, getState());
  enterRule(_localctx, 158, XiasParser::RuleConstructor_initializer);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(975);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(961);
      match(XiasParser::COLON);
      setState(962);
      match(XiasParser::BASE);
      setState(963);
      match(XiasParser::OPEN_PARENS);
      setState(965);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << XiasParser::BASE)
        | (1ULL << XiasParser::DEFAULT)
        | (1ULL << XiasParser::FALSE)
        | (1ULL << XiasParser::NEW)
        | (1ULL << XiasParser::NULL_)
        | (1ULL << XiasParser::THIS)
        | (1ULL << XiasParser::TRUE)
        | (1ULL << XiasParser::TYPEOF))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 72)) & ((1ULL << (XiasParser::IDENTIFIER - 72))
        | (1ULL << (XiasParser::INTEGER_LITERAL - 72))
        | (1ULL << (XiasParser::UNSIGNED_LITERAL - 72))
        | (1ULL << (XiasParser::HEX_INTEGER_LITERAL - 72))
        | (1ULL << (XiasParser::FLOAT_LITERAL - 72))
        | (1ULL << (XiasParser::DOUBLE_LITERAL - 72))
        | (1ULL << (XiasParser::CHARACTER_LITERAL - 72))
        | (1ULL << (XiasParser::REGULAR_STRING - 72))
        | (1ULL << (XiasParser::VERBATIUM_STRING - 72))
        | (1ULL << (XiasParser::OPEN_PARENS - 72))
        | (1ULL << (XiasParser::PLUS - 72))
        | (1ULL << (XiasParser::MINUS - 72))
        | (1ULL << (XiasParser::BANG - 72))
        | (1ULL << (XiasParser::TILDE - 72))
        | (1ULL << (XiasParser::OP_INC - 72))
        | (1ULL << (XiasParser::OP_DEC - 72)))) != 0)) {
        setState(964);
        argument_list();
      }
      setState(967);
      match(XiasParser::CLOSE_PARENS);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(968);
      match(XiasParser::COLON);
      setState(969);
      match(XiasParser::THIS);
      setState(970);
      match(XiasParser::OPEN_PARENS);
      setState(972);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << XiasParser::BASE)
        | (1ULL << XiasParser::DEFAULT)
        | (1ULL << XiasParser::FALSE)
        | (1ULL << XiasParser::NEW)
        | (1ULL << XiasParser::NULL_)
        | (1ULL << XiasParser::THIS)
        | (1ULL << XiasParser::TRUE)
        | (1ULL << XiasParser::TYPEOF))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 72)) & ((1ULL << (XiasParser::IDENTIFIER - 72))
        | (1ULL << (XiasParser::INTEGER_LITERAL - 72))
        | (1ULL << (XiasParser::UNSIGNED_LITERAL - 72))
        | (1ULL << (XiasParser::HEX_INTEGER_LITERAL - 72))
        | (1ULL << (XiasParser::FLOAT_LITERAL - 72))
        | (1ULL << (XiasParser::DOUBLE_LITERAL - 72))
        | (1ULL << (XiasParser::CHARACTER_LITERAL - 72))
        | (1ULL << (XiasParser::REGULAR_STRING - 72))
        | (1ULL << (XiasParser::VERBATIUM_STRING - 72))
        | (1ULL << (XiasParser::OPEN_PARENS - 72))
        | (1ULL << (XiasParser::PLUS - 72))
        | (1ULL << (XiasParser::MINUS - 72))
        | (1ULL << (XiasParser::BANG - 72))
        | (1ULL << (XiasParser::TILDE - 72))
        | (1ULL << (XiasParser::OP_INC - 72))
        | (1ULL << (XiasParser::OP_DEC - 72)))) != 0)) {
        setState(971);
        argument_list();
      }
      setState(974);
      match(XiasParser::CLOSE_PARENS);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Constructor_bodyContext ------------------------------------------------------------------

XiasParser::Constructor_bodyContext::Constructor_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::BlockContext* XiasParser::Constructor_bodyContext::block() {
  return getRuleContext<XiasParser::BlockContext>(0);
}

tree::TerminalNode* XiasParser::Constructor_bodyContext::SEMICOLON() {
  return getToken(XiasParser::SEMICOLON, 0);
}


size_t XiasParser::Constructor_bodyContext::getRuleIndex() const {
  return XiasParser::RuleConstructor_body;
}


antlrcpp::Any XiasParser::Constructor_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitConstructor_body(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Constructor_bodyContext* XiasParser::constructor_body() {
  Constructor_bodyContext *_localctx = _tracker.createInstance<Constructor_bodyContext>(_ctx, getState());
  enterRule(_localctx, 160, XiasParser::RuleConstructor_body);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(979);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case XiasParser::OPEN_BRACE: {
        enterOuterAlt(_localctx, 1);
        setState(977);
        block();
        break;
      }

      case XiasParser::SEMICOLON: {
        enterOuterAlt(_localctx, 2);
        setState(978);
        match(XiasParser::SEMICOLON);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Static_constructor_declarationContext ------------------------------------------------------------------

XiasParser::Static_constructor_declarationContext::Static_constructor_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Static_constructor_modifiersContext* XiasParser::Static_constructor_declarationContext::static_constructor_modifiers() {
  return getRuleContext<XiasParser::Static_constructor_modifiersContext>(0);
}

XiasParser::IdentifierContext* XiasParser::Static_constructor_declarationContext::identifier() {
  return getRuleContext<XiasParser::IdentifierContext>(0);
}

tree::TerminalNode* XiasParser::Static_constructor_declarationContext::OPEN_PARENS() {
  return getToken(XiasParser::OPEN_PARENS, 0);
}

tree::TerminalNode* XiasParser::Static_constructor_declarationContext::CLOSE_PARENS() {
  return getToken(XiasParser::CLOSE_PARENS, 0);
}

XiasParser::Static_constructor_bodyContext* XiasParser::Static_constructor_declarationContext::static_constructor_body() {
  return getRuleContext<XiasParser::Static_constructor_bodyContext>(0);
}


size_t XiasParser::Static_constructor_declarationContext::getRuleIndex() const {
  return XiasParser::RuleStatic_constructor_declaration;
}


antlrcpp::Any XiasParser::Static_constructor_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitStatic_constructor_declaration(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Static_constructor_declarationContext* XiasParser::static_constructor_declaration() {
  Static_constructor_declarationContext *_localctx = _tracker.createInstance<Static_constructor_declarationContext>(_ctx, getState());
  enterRule(_localctx, 162, XiasParser::RuleStatic_constructor_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(981);
    static_constructor_modifiers();
    setState(982);
    identifier();
    setState(983);
    match(XiasParser::OPEN_PARENS);
    setState(984);
    match(XiasParser::CLOSE_PARENS);
    setState(985);
    static_constructor_body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Static_constructor_modifiersContext ------------------------------------------------------------------

XiasParser::Static_constructor_modifiersContext::Static_constructor_modifiersContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Static_constructor_modifiersContext::STATIC() {
  return getToken(XiasParser::STATIC, 0);
}


size_t XiasParser::Static_constructor_modifiersContext::getRuleIndex() const {
  return XiasParser::RuleStatic_constructor_modifiers;
}


antlrcpp::Any XiasParser::Static_constructor_modifiersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitStatic_constructor_modifiers(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Static_constructor_modifiersContext* XiasParser::static_constructor_modifiers() {
  Static_constructor_modifiersContext *_localctx = _tracker.createInstance<Static_constructor_modifiersContext>(_ctx, getState());
  enterRule(_localctx, 164, XiasParser::RuleStatic_constructor_modifiers);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(987);
    match(XiasParser::STATIC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Static_constructor_bodyContext ------------------------------------------------------------------

XiasParser::Static_constructor_bodyContext::Static_constructor_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::BlockContext* XiasParser::Static_constructor_bodyContext::block() {
  return getRuleContext<XiasParser::BlockContext>(0);
}

tree::TerminalNode* XiasParser::Static_constructor_bodyContext::SEMICOLON() {
  return getToken(XiasParser::SEMICOLON, 0);
}


size_t XiasParser::Static_constructor_bodyContext::getRuleIndex() const {
  return XiasParser::RuleStatic_constructor_body;
}


antlrcpp::Any XiasParser::Static_constructor_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitStatic_constructor_body(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Static_constructor_bodyContext* XiasParser::static_constructor_body() {
  Static_constructor_bodyContext *_localctx = _tracker.createInstance<Static_constructor_bodyContext>(_ctx, getState());
  enterRule(_localctx, 166, XiasParser::RuleStatic_constructor_body);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(991);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case XiasParser::OPEN_BRACE: {
        enterOuterAlt(_localctx, 1);
        setState(989);
        block();
        break;
      }

      case XiasParser::SEMICOLON: {
        enterOuterAlt(_localctx, 2);
        setState(990);
        match(XiasParser::SEMICOLON);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Destructor_declarationContext ------------------------------------------------------------------

XiasParser::Destructor_declarationContext::Destructor_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Destructor_declarationContext::TILDE() {
  return getToken(XiasParser::TILDE, 0);
}

XiasParser::IdentifierContext* XiasParser::Destructor_declarationContext::identifier() {
  return getRuleContext<XiasParser::IdentifierContext>(0);
}

tree::TerminalNode* XiasParser::Destructor_declarationContext::OPEN_PARENS() {
  return getToken(XiasParser::OPEN_PARENS, 0);
}

tree::TerminalNode* XiasParser::Destructor_declarationContext::CLOSE_PARENS() {
  return getToken(XiasParser::CLOSE_PARENS, 0);
}

XiasParser::Destructor_bodyContext* XiasParser::Destructor_declarationContext::destructor_body() {
  return getRuleContext<XiasParser::Destructor_bodyContext>(0);
}


size_t XiasParser::Destructor_declarationContext::getRuleIndex() const {
  return XiasParser::RuleDestructor_declaration;
}


antlrcpp::Any XiasParser::Destructor_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitDestructor_declaration(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Destructor_declarationContext* XiasParser::destructor_declaration() {
  Destructor_declarationContext *_localctx = _tracker.createInstance<Destructor_declarationContext>(_ctx, getState());
  enterRule(_localctx, 168, XiasParser::RuleDestructor_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(993);
    match(XiasParser::TILDE);
    setState(994);
    identifier();
    setState(995);
    match(XiasParser::OPEN_PARENS);
    setState(996);
    match(XiasParser::CLOSE_PARENS);
    setState(997);
    destructor_body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Destructor_bodyContext ------------------------------------------------------------------

XiasParser::Destructor_bodyContext::Destructor_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::BlockContext* XiasParser::Destructor_bodyContext::block() {
  return getRuleContext<XiasParser::BlockContext>(0);
}

tree::TerminalNode* XiasParser::Destructor_bodyContext::SEMICOLON() {
  return getToken(XiasParser::SEMICOLON, 0);
}


size_t XiasParser::Destructor_bodyContext::getRuleIndex() const {
  return XiasParser::RuleDestructor_body;
}


antlrcpp::Any XiasParser::Destructor_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitDestructor_body(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Destructor_bodyContext* XiasParser::destructor_body() {
  Destructor_bodyContext *_localctx = _tracker.createInstance<Destructor_bodyContext>(_ctx, getState());
  enterRule(_localctx, 170, XiasParser::RuleDestructor_body);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1001);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case XiasParser::OPEN_BRACE: {
        enterOuterAlt(_localctx, 1);
        setState(999);
        block();
        break;
      }

      case XiasParser::SEMICOLON: {
        enterOuterAlt(_localctx, 2);
        setState(1000);
        match(XiasParser::SEMICOLON);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_declarationContext ------------------------------------------------------------------

XiasParser::Interface_declarationContext::Interface_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Interface_declarationContext::INTERFACE() {
  return getToken(XiasParser::INTERFACE, 0);
}

XiasParser::IdentifierContext* XiasParser::Interface_declarationContext::identifier() {
  return getRuleContext<XiasParser::IdentifierContext>(0);
}

XiasParser::Interface_bodyContext* XiasParser::Interface_declarationContext::interface_body() {
  return getRuleContext<XiasParser::Interface_bodyContext>(0);
}

std::vector<XiasParser::Basic_modifierContext *> XiasParser::Interface_declarationContext::basic_modifier() {
  return getRuleContexts<XiasParser::Basic_modifierContext>();
}

XiasParser::Basic_modifierContext* XiasParser::Interface_declarationContext::basic_modifier(size_t i) {
  return getRuleContext<XiasParser::Basic_modifierContext>(i);
}

XiasParser::Variant_type_parameter_listContext* XiasParser::Interface_declarationContext::variant_type_parameter_list() {
  return getRuleContext<XiasParser::Variant_type_parameter_listContext>(0);
}

XiasParser::Interface_baseContext* XiasParser::Interface_declarationContext::interface_base() {
  return getRuleContext<XiasParser::Interface_baseContext>(0);
}

std::vector<XiasParser::Type_parameter_constraints_clauseContext *> XiasParser::Interface_declarationContext::type_parameter_constraints_clause() {
  return getRuleContexts<XiasParser::Type_parameter_constraints_clauseContext>();
}

XiasParser::Type_parameter_constraints_clauseContext* XiasParser::Interface_declarationContext::type_parameter_constraints_clause(size_t i) {
  return getRuleContext<XiasParser::Type_parameter_constraints_clauseContext>(i);
}

tree::TerminalNode* XiasParser::Interface_declarationContext::SEMICOLON() {
  return getToken(XiasParser::SEMICOLON, 0);
}


size_t XiasParser::Interface_declarationContext::getRuleIndex() const {
  return XiasParser::RuleInterface_declaration;
}


antlrcpp::Any XiasParser::Interface_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitInterface_declaration(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Interface_declarationContext* XiasParser::interface_declaration() {
  Interface_declarationContext *_localctx = _tracker.createInstance<Interface_declarationContext>(_ctx, getState());
  enterRule(_localctx, 172, XiasParser::RuleInterface_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1006);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << XiasParser::INTERNAL)
      | (1ULL << XiasParser::NEW)
      | (1ULL << XiasParser::PRIVATE)
      | (1ULL << XiasParser::PROTECTED)
      | (1ULL << XiasParser::PUBLIC))) != 0)) {
      setState(1003);
      basic_modifier();
      setState(1008);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1009);
    match(XiasParser::INTERFACE);
    setState(1010);
    identifier();
    setState(1012);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == XiasParser::LT) {
      setState(1011);
      variant_type_parameter_list();
    }
    setState(1015);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == XiasParser::COLON) {
      setState(1014);
      interface_base();
    }
    setState(1020);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == XiasParser::WHERE) {
      setState(1017);
      type_parameter_constraints_clause();
      setState(1022);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1023);
    interface_body();
    setState(1025);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == XiasParser::SEMICOLON) {
      setState(1024);
      match(XiasParser::SEMICOLON);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variant_type_parameter_listContext ------------------------------------------------------------------

XiasParser::Variant_type_parameter_listContext::Variant_type_parameter_listContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Variant_type_parameter_listContext::LT() {
  return getToken(XiasParser::LT, 0);
}

XiasParser::Variant_type_parametersContext* XiasParser::Variant_type_parameter_listContext::variant_type_parameters() {
  return getRuleContext<XiasParser::Variant_type_parametersContext>(0);
}

tree::TerminalNode* XiasParser::Variant_type_parameter_listContext::GT() {
  return getToken(XiasParser::GT, 0);
}


size_t XiasParser::Variant_type_parameter_listContext::getRuleIndex() const {
  return XiasParser::RuleVariant_type_parameter_list;
}


antlrcpp::Any XiasParser::Variant_type_parameter_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitVariant_type_parameter_list(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Variant_type_parameter_listContext* XiasParser::variant_type_parameter_list() {
  Variant_type_parameter_listContext *_localctx = _tracker.createInstance<Variant_type_parameter_listContext>(_ctx, getState());
  enterRule(_localctx, 174, XiasParser::RuleVariant_type_parameter_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1027);
    match(XiasParser::LT);
    setState(1028);
    variant_type_parameters(0);
    setState(1029);
    match(XiasParser::GT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variant_type_parametersContext ------------------------------------------------------------------

XiasParser::Variant_type_parametersContext::Variant_type_parametersContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Type_parameterContext* XiasParser::Variant_type_parametersContext::type_parameter() {
  return getRuleContext<XiasParser::Type_parameterContext>(0);
}

XiasParser::Variance_annotationContext* XiasParser::Variant_type_parametersContext::variance_annotation() {
  return getRuleContext<XiasParser::Variance_annotationContext>(0);
}

XiasParser::Variant_type_parametersContext* XiasParser::Variant_type_parametersContext::variant_type_parameters() {
  return getRuleContext<XiasParser::Variant_type_parametersContext>(0);
}

tree::TerminalNode* XiasParser::Variant_type_parametersContext::COMMA() {
  return getToken(XiasParser::COMMA, 0);
}


size_t XiasParser::Variant_type_parametersContext::getRuleIndex() const {
  return XiasParser::RuleVariant_type_parameters;
}


antlrcpp::Any XiasParser::Variant_type_parametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitVariant_type_parameters(this);
  else
    return visitor->visitChildren(this);
}


XiasParser::Variant_type_parametersContext* XiasParser::variant_type_parameters() {
   return variant_type_parameters(0);
}

XiasParser::Variant_type_parametersContext* XiasParser::variant_type_parameters(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  XiasParser::Variant_type_parametersContext *_localctx = _tracker.createInstance<Variant_type_parametersContext>(_ctx, parentState);
  XiasParser::Variant_type_parametersContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 176;
  enterRecursionRule(_localctx, 176, XiasParser::RuleVariant_type_parameters, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1033);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == XiasParser::IN

    || _la == XiasParser::OUT) {
      setState(1032);
      variance_annotation();
    }
    setState(1035);
    type_parameter();
    _ctx->stop = _input->LT(-1);
    setState(1045);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 84, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Variant_type_parametersContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleVariant_type_parameters);
        setState(1037);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1038);
        match(XiasParser::COMMA);
        setState(1040);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == XiasParser::IN

        || _la == XiasParser::OUT) {
          setState(1039);
          variance_annotation();
        }
        setState(1042);
        type_parameter(); 
      }
      setState(1047);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 84, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Variance_annotationContext ------------------------------------------------------------------

XiasParser::Variance_annotationContext::Variance_annotationContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Variance_annotationContext::IN() {
  return getToken(XiasParser::IN, 0);
}

tree::TerminalNode* XiasParser::Variance_annotationContext::OUT() {
  return getToken(XiasParser::OUT, 0);
}


size_t XiasParser::Variance_annotationContext::getRuleIndex() const {
  return XiasParser::RuleVariance_annotation;
}


antlrcpp::Any XiasParser::Variance_annotationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitVariance_annotation(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Variance_annotationContext* XiasParser::variance_annotation() {
  Variance_annotationContext *_localctx = _tracker.createInstance<Variance_annotationContext>(_ctx, getState());
  enterRule(_localctx, 178, XiasParser::RuleVariance_annotation);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1048);
    _la = _input->LA(1);
    if (!(_la == XiasParser::IN

    || _la == XiasParser::OUT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_baseContext ------------------------------------------------------------------

XiasParser::Interface_baseContext::Interface_baseContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Interface_baseContext::COLON() {
  return getToken(XiasParser::COLON, 0);
}

XiasParser::Interface_type_listContext* XiasParser::Interface_baseContext::interface_type_list() {
  return getRuleContext<XiasParser::Interface_type_listContext>(0);
}


size_t XiasParser::Interface_baseContext::getRuleIndex() const {
  return XiasParser::RuleInterface_base;
}


antlrcpp::Any XiasParser::Interface_baseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitInterface_base(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Interface_baseContext* XiasParser::interface_base() {
  Interface_baseContext *_localctx = _tracker.createInstance<Interface_baseContext>(_ctx, getState());
  enterRule(_localctx, 180, XiasParser::RuleInterface_base);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1050);
    match(XiasParser::COLON);
    setState(1051);
    interface_type_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_bodyContext ------------------------------------------------------------------

XiasParser::Interface_bodyContext::Interface_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Interface_bodyContext::OPEN_BRACE() {
  return getToken(XiasParser::OPEN_BRACE, 0);
}

tree::TerminalNode* XiasParser::Interface_bodyContext::CLOSE_BRACE() {
  return getToken(XiasParser::CLOSE_BRACE, 0);
}

std::vector<XiasParser::Interface_member_declarationContext *> XiasParser::Interface_bodyContext::interface_member_declaration() {
  return getRuleContexts<XiasParser::Interface_member_declarationContext>();
}

XiasParser::Interface_member_declarationContext* XiasParser::Interface_bodyContext::interface_member_declaration(size_t i) {
  return getRuleContext<XiasParser::Interface_member_declarationContext>(i);
}


size_t XiasParser::Interface_bodyContext::getRuleIndex() const {
  return XiasParser::RuleInterface_body;
}


antlrcpp::Any XiasParser::Interface_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitInterface_body(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Interface_bodyContext* XiasParser::interface_body() {
  Interface_bodyContext *_localctx = _tracker.createInstance<Interface_bodyContext>(_ctx, getState());
  enterRule(_localctx, 182, XiasParser::RuleInterface_body);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1053);
    match(XiasParser::OPEN_BRACE);
    setState(1057);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 10) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 10)) & ((1ULL << (XiasParser::BOOL - 10))
      | (1ULL << (XiasParser::CHAR - 10))
      | (1ULL << (XiasParser::DOUBLE - 10))
      | (1ULL << (XiasParser::FLOAT - 10))
      | (1ULL << (XiasParser::INT - 10))
      | (1ULL << (XiasParser::NEW - 10))
      | (1ULL << (XiasParser::OBJECT - 10))
      | (1ULL << (XiasParser::STRING - 10))
      | (1ULL << (XiasParser::UINT - 10))
      | (1ULL << (XiasParser::VOID - 10))
      | (1ULL << (XiasParser::IDENTIFIER - 10)))) != 0)) {
      setState(1054);
      interface_member_declaration();
      setState(1059);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1060);
    match(XiasParser::CLOSE_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_member_declarationContext ------------------------------------------------------------------

XiasParser::Interface_member_declarationContext::Interface_member_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Interface_method_declarationContext* XiasParser::Interface_member_declarationContext::interface_method_declaration() {
  return getRuleContext<XiasParser::Interface_method_declarationContext>(0);
}

XiasParser::Interface_property_declarationContext* XiasParser::Interface_member_declarationContext::interface_property_declaration() {
  return getRuleContext<XiasParser::Interface_property_declarationContext>(0);
}

XiasParser::Interface_indexer_declarationContext* XiasParser::Interface_member_declarationContext::interface_indexer_declaration() {
  return getRuleContext<XiasParser::Interface_indexer_declarationContext>(0);
}


size_t XiasParser::Interface_member_declarationContext::getRuleIndex() const {
  return XiasParser::RuleInterface_member_declaration;
}


antlrcpp::Any XiasParser::Interface_member_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitInterface_member_declaration(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Interface_member_declarationContext* XiasParser::interface_member_declaration() {
  Interface_member_declarationContext *_localctx = _tracker.createInstance<Interface_member_declarationContext>(_ctx, getState());
  enterRule(_localctx, 184, XiasParser::RuleInterface_member_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1065);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 86, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1062);
      interface_method_declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1063);
      interface_property_declaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1064);
      interface_indexer_declaration();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_method_declarationContext ------------------------------------------------------------------

XiasParser::Interface_method_declarationContext::Interface_method_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Return_typeContext* XiasParser::Interface_method_declarationContext::return_type() {
  return getRuleContext<XiasParser::Return_typeContext>(0);
}

XiasParser::IdentifierContext* XiasParser::Interface_method_declarationContext::identifier() {
  return getRuleContext<XiasParser::IdentifierContext>(0);
}

XiasParser::Type_parameter_listContext* XiasParser::Interface_method_declarationContext::type_parameter_list() {
  return getRuleContext<XiasParser::Type_parameter_listContext>(0);
}

tree::TerminalNode* XiasParser::Interface_method_declarationContext::OPEN_PARENS() {
  return getToken(XiasParser::OPEN_PARENS, 0);
}

tree::TerminalNode* XiasParser::Interface_method_declarationContext::CLOSE_PARENS() {
  return getToken(XiasParser::CLOSE_PARENS, 0);
}

tree::TerminalNode* XiasParser::Interface_method_declarationContext::SEMICOLON() {
  return getToken(XiasParser::SEMICOLON, 0);
}

tree::TerminalNode* XiasParser::Interface_method_declarationContext::NEW() {
  return getToken(XiasParser::NEW, 0);
}

XiasParser::Formal_parameter_listContext* XiasParser::Interface_method_declarationContext::formal_parameter_list() {
  return getRuleContext<XiasParser::Formal_parameter_listContext>(0);
}

std::vector<XiasParser::Type_parameter_constraints_clauseContext *> XiasParser::Interface_method_declarationContext::type_parameter_constraints_clause() {
  return getRuleContexts<XiasParser::Type_parameter_constraints_clauseContext>();
}

XiasParser::Type_parameter_constraints_clauseContext* XiasParser::Interface_method_declarationContext::type_parameter_constraints_clause(size_t i) {
  return getRuleContext<XiasParser::Type_parameter_constraints_clauseContext>(i);
}


size_t XiasParser::Interface_method_declarationContext::getRuleIndex() const {
  return XiasParser::RuleInterface_method_declaration;
}


antlrcpp::Any XiasParser::Interface_method_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitInterface_method_declaration(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Interface_method_declarationContext* XiasParser::interface_method_declaration() {
  Interface_method_declarationContext *_localctx = _tracker.createInstance<Interface_method_declarationContext>(_ctx, getState());
  enterRule(_localctx, 186, XiasParser::RuleInterface_method_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1068);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == XiasParser::NEW) {
      setState(1067);
      match(XiasParser::NEW);
    }
    setState(1070);
    return_type();
    setState(1071);
    identifier();
    setState(1072);
    type_parameter_list();
    setState(1073);
    match(XiasParser::OPEN_PARENS);
    setState(1075);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 10) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 10)) & ((1ULL << (XiasParser::BOOL - 10))
      | (1ULL << (XiasParser::CHAR - 10))
      | (1ULL << (XiasParser::DOUBLE - 10))
      | (1ULL << (XiasParser::FLOAT - 10))
      | (1ULL << (XiasParser::INT - 10))
      | (1ULL << (XiasParser::OBJECT - 10))
      | (1ULL << (XiasParser::STRING - 10))
      | (1ULL << (XiasParser::THIS - 10))
      | (1ULL << (XiasParser::UINT - 10))
      | (1ULL << (XiasParser::IDENTIFIER - 10)))) != 0)) {
      setState(1074);
      formal_parameter_list();
    }
    setState(1077);
    match(XiasParser::CLOSE_PARENS);
    setState(1081);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == XiasParser::WHERE) {
      setState(1078);
      type_parameter_constraints_clause();
      setState(1083);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1084);
    match(XiasParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_property_declarationContext ------------------------------------------------------------------

XiasParser::Interface_property_declarationContext::Interface_property_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Type_Context* XiasParser::Interface_property_declarationContext::type_() {
  return getRuleContext<XiasParser::Type_Context>(0);
}

XiasParser::IdentifierContext* XiasParser::Interface_property_declarationContext::identifier() {
  return getRuleContext<XiasParser::IdentifierContext>(0);
}

tree::TerminalNode* XiasParser::Interface_property_declarationContext::OPEN_BRACE() {
  return getToken(XiasParser::OPEN_BRACE, 0);
}

XiasParser::Interface_accessorsContext* XiasParser::Interface_property_declarationContext::interface_accessors() {
  return getRuleContext<XiasParser::Interface_accessorsContext>(0);
}

tree::TerminalNode* XiasParser::Interface_property_declarationContext::CLOSE_BRACE() {
  return getToken(XiasParser::CLOSE_BRACE, 0);
}

tree::TerminalNode* XiasParser::Interface_property_declarationContext::NEW() {
  return getToken(XiasParser::NEW, 0);
}


size_t XiasParser::Interface_property_declarationContext::getRuleIndex() const {
  return XiasParser::RuleInterface_property_declaration;
}


antlrcpp::Any XiasParser::Interface_property_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitInterface_property_declaration(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Interface_property_declarationContext* XiasParser::interface_property_declaration() {
  Interface_property_declarationContext *_localctx = _tracker.createInstance<Interface_property_declarationContext>(_ctx, getState());
  enterRule(_localctx, 188, XiasParser::RuleInterface_property_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1087);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == XiasParser::NEW) {
      setState(1086);
      match(XiasParser::NEW);
    }
    setState(1089);
    type_();
    setState(1090);
    identifier();
    setState(1091);
    match(XiasParser::OPEN_BRACE);
    setState(1092);
    interface_accessors();
    setState(1093);
    match(XiasParser::CLOSE_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_accessorsContext ------------------------------------------------------------------

XiasParser::Interface_accessorsContext::Interface_accessorsContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Interface_accessorsContext::GET() {
  return getToken(XiasParser::GET, 0);
}

std::vector<tree::TerminalNode *> XiasParser::Interface_accessorsContext::SEMICOLON() {
  return getTokens(XiasParser::SEMICOLON);
}

tree::TerminalNode* XiasParser::Interface_accessorsContext::SEMICOLON(size_t i) {
  return getToken(XiasParser::SEMICOLON, i);
}

tree::TerminalNode* XiasParser::Interface_accessorsContext::SET() {
  return getToken(XiasParser::SET, 0);
}


size_t XiasParser::Interface_accessorsContext::getRuleIndex() const {
  return XiasParser::RuleInterface_accessors;
}


antlrcpp::Any XiasParser::Interface_accessorsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitInterface_accessors(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Interface_accessorsContext* XiasParser::interface_accessors() {
  Interface_accessorsContext *_localctx = _tracker.createInstance<Interface_accessorsContext>(_ctx, getState());
  enterRule(_localctx, 190, XiasParser::RuleInterface_accessors);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1107);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 91, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1095);
      match(XiasParser::GET);
      setState(1096);
      match(XiasParser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1097);
      match(XiasParser::SET);
      setState(1098);
      match(XiasParser::SEMICOLON);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1099);
      match(XiasParser::GET);
      setState(1100);
      match(XiasParser::SEMICOLON);
      setState(1101);
      match(XiasParser::SET);
      setState(1102);
      match(XiasParser::SEMICOLON);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1103);
      match(XiasParser::SET);
      setState(1104);
      match(XiasParser::SEMICOLON);
      setState(1105);
      match(XiasParser::GET);
      setState(1106);
      match(XiasParser::SEMICOLON);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_indexer_declarationContext ------------------------------------------------------------------

XiasParser::Interface_indexer_declarationContext::Interface_indexer_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Type_Context* XiasParser::Interface_indexer_declarationContext::type_() {
  return getRuleContext<XiasParser::Type_Context>(0);
}

tree::TerminalNode* XiasParser::Interface_indexer_declarationContext::THIS() {
  return getToken(XiasParser::THIS, 0);
}

tree::TerminalNode* XiasParser::Interface_indexer_declarationContext::OPEN_BRACKET() {
  return getToken(XiasParser::OPEN_BRACKET, 0);
}

XiasParser::Formal_parameter_listContext* XiasParser::Interface_indexer_declarationContext::formal_parameter_list() {
  return getRuleContext<XiasParser::Formal_parameter_listContext>(0);
}

tree::TerminalNode* XiasParser::Interface_indexer_declarationContext::CLOSE_BRACKET() {
  return getToken(XiasParser::CLOSE_BRACKET, 0);
}

tree::TerminalNode* XiasParser::Interface_indexer_declarationContext::OPEN_BRACE() {
  return getToken(XiasParser::OPEN_BRACE, 0);
}

XiasParser::Interface_accessorsContext* XiasParser::Interface_indexer_declarationContext::interface_accessors() {
  return getRuleContext<XiasParser::Interface_accessorsContext>(0);
}

tree::TerminalNode* XiasParser::Interface_indexer_declarationContext::CLOSE_BRACE() {
  return getToken(XiasParser::CLOSE_BRACE, 0);
}

tree::TerminalNode* XiasParser::Interface_indexer_declarationContext::NEW() {
  return getToken(XiasParser::NEW, 0);
}


size_t XiasParser::Interface_indexer_declarationContext::getRuleIndex() const {
  return XiasParser::RuleInterface_indexer_declaration;
}


antlrcpp::Any XiasParser::Interface_indexer_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitInterface_indexer_declaration(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Interface_indexer_declarationContext* XiasParser::interface_indexer_declaration() {
  Interface_indexer_declarationContext *_localctx = _tracker.createInstance<Interface_indexer_declarationContext>(_ctx, getState());
  enterRule(_localctx, 192, XiasParser::RuleInterface_indexer_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1110);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == XiasParser::NEW) {
      setState(1109);
      match(XiasParser::NEW);
    }
    setState(1112);
    type_();
    setState(1113);
    match(XiasParser::THIS);
    setState(1114);
    match(XiasParser::OPEN_BRACKET);
    setState(1115);
    formal_parameter_list();
    setState(1116);
    match(XiasParser::CLOSE_BRACKET);
    setState(1117);
    match(XiasParser::OPEN_BRACE);
    setState(1118);
    interface_accessors();
    setState(1119);
    match(XiasParser::CLOSE_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

XiasParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::BlockContext::OPEN_BRACE() {
  return getToken(XiasParser::OPEN_BRACE, 0);
}

tree::TerminalNode* XiasParser::BlockContext::CLOSE_BRACE() {
  return getToken(XiasParser::CLOSE_BRACE, 0);
}

XiasParser::Statement_listContext* XiasParser::BlockContext::statement_list() {
  return getRuleContext<XiasParser::Statement_listContext>(0);
}


size_t XiasParser::BlockContext::getRuleIndex() const {
  return XiasParser::RuleBlock;
}


antlrcpp::Any XiasParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::BlockContext* XiasParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 194, XiasParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1121);
    match(XiasParser::OPEN_BRACE);
    setState(1123);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << XiasParser::BASE)
      | (1ULL << XiasParser::BOOL)
      | (1ULL << XiasParser::BREAK)
      | (1ULL << XiasParser::CHAR)
      | (1ULL << XiasParser::CONST)
      | (1ULL << XiasParser::CONTINUE)
      | (1ULL << XiasParser::DEFAULT)
      | (1ULL << XiasParser::DO)
      | (1ULL << XiasParser::DOUBLE)
      | (1ULL << XiasParser::FALSE)
      | (1ULL << XiasParser::FLOAT)
      | (1ULL << XiasParser::FOR)
      | (1ULL << XiasParser::FOREACH)
      | (1ULL << XiasParser::GOTO)
      | (1ULL << XiasParser::IF)
      | (1ULL << XiasParser::INT)
      | (1ULL << XiasParser::NEW)
      | (1ULL << XiasParser::NULL_)
      | (1ULL << XiasParser::OBJECT)
      | (1ULL << XiasParser::RETURN)
      | (1ULL << XiasParser::STRING)
      | (1ULL << XiasParser::SWITCH)
      | (1ULL << XiasParser::THIS)
      | (1ULL << XiasParser::THROW)
      | (1ULL << XiasParser::TRUE)
      | (1ULL << XiasParser::TRY)
      | (1ULL << XiasParser::TYPEOF))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (XiasParser::UINT - 64))
      | (1ULL << (XiasParser::VAR - 64))
      | (1ULL << (XiasParser::WHILE - 64))
      | (1ULL << (XiasParser::IDENTIFIER - 64))
      | (1ULL << (XiasParser::INTEGER_LITERAL - 64))
      | (1ULL << (XiasParser::UNSIGNED_LITERAL - 64))
      | (1ULL << (XiasParser::HEX_INTEGER_LITERAL - 64))
      | (1ULL << (XiasParser::FLOAT_LITERAL - 64))
      | (1ULL << (XiasParser::DOUBLE_LITERAL - 64))
      | (1ULL << (XiasParser::CHARACTER_LITERAL - 64))
      | (1ULL << (XiasParser::REGULAR_STRING - 64))
      | (1ULL << (XiasParser::VERBATIUM_STRING - 64))
      | (1ULL << (XiasParser::OPEN_BRACE - 64))
      | (1ULL << (XiasParser::OPEN_PARENS - 64))
      | (1ULL << (XiasParser::SEMICOLON - 64))
      | (1ULL << (XiasParser::PLUS - 64))
      | (1ULL << (XiasParser::MINUS - 64))
      | (1ULL << (XiasParser::BANG - 64))
      | (1ULL << (XiasParser::TILDE - 64))
      | (1ULL << (XiasParser::OP_INC - 64))
      | (1ULL << (XiasParser::OP_DEC - 64)))) != 0)) {
      setState(1122);
      statement_list();
    }
    setState(1125);
    match(XiasParser::CLOSE_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Statement_listContext ------------------------------------------------------------------

XiasParser::Statement_listContext::Statement_listContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

std::vector<XiasParser::StatementContext *> XiasParser::Statement_listContext::statement() {
  return getRuleContexts<XiasParser::StatementContext>();
}

XiasParser::StatementContext* XiasParser::Statement_listContext::statement(size_t i) {
  return getRuleContext<XiasParser::StatementContext>(i);
}


size_t XiasParser::Statement_listContext::getRuleIndex() const {
  return XiasParser::RuleStatement_list;
}


antlrcpp::Any XiasParser::Statement_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitStatement_list(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Statement_listContext* XiasParser::statement_list() {
  Statement_listContext *_localctx = _tracker.createInstance<Statement_listContext>(_ctx, getState());
  enterRule(_localctx, 196, XiasParser::RuleStatement_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1128); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(1127);
              statement();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(1130); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 94, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

XiasParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Labeled_statementContext* XiasParser::StatementContext::labeled_statement() {
  return getRuleContext<XiasParser::Labeled_statementContext>(0);
}

XiasParser::Declaration_statementContext* XiasParser::StatementContext::declaration_statement() {
  return getRuleContext<XiasParser::Declaration_statementContext>(0);
}

XiasParser::Embedded_statementContext* XiasParser::StatementContext::embedded_statement() {
  return getRuleContext<XiasParser::Embedded_statementContext>(0);
}


size_t XiasParser::StatementContext::getRuleIndex() const {
  return XiasParser::RuleStatement;
}


antlrcpp::Any XiasParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::StatementContext* XiasParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 198, XiasParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1135);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 95, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1132);
      labeled_statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1133);
      declaration_statement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1134);
      embedded_statement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Labeled_statementContext ------------------------------------------------------------------

XiasParser::Labeled_statementContext::Labeled_statementContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::IdentifierContext* XiasParser::Labeled_statementContext::identifier() {
  return getRuleContext<XiasParser::IdentifierContext>(0);
}

tree::TerminalNode* XiasParser::Labeled_statementContext::COLON() {
  return getToken(XiasParser::COLON, 0);
}

XiasParser::StatementContext* XiasParser::Labeled_statementContext::statement() {
  return getRuleContext<XiasParser::StatementContext>(0);
}


size_t XiasParser::Labeled_statementContext::getRuleIndex() const {
  return XiasParser::RuleLabeled_statement;
}


antlrcpp::Any XiasParser::Labeled_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitLabeled_statement(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Labeled_statementContext* XiasParser::labeled_statement() {
  Labeled_statementContext *_localctx = _tracker.createInstance<Labeled_statementContext>(_ctx, getState());
  enterRule(_localctx, 200, XiasParser::RuleLabeled_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1137);
    identifier();
    setState(1138);
    match(XiasParser::COLON);
    setState(1139);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declaration_statementContext ------------------------------------------------------------------

XiasParser::Declaration_statementContext::Declaration_statementContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Local_variable_declarationContext* XiasParser::Declaration_statementContext::local_variable_declaration() {
  return getRuleContext<XiasParser::Local_variable_declarationContext>(0);
}

tree::TerminalNode* XiasParser::Declaration_statementContext::SEMICOLON() {
  return getToken(XiasParser::SEMICOLON, 0);
}

XiasParser::Local_constant_declarationContext* XiasParser::Declaration_statementContext::local_constant_declaration() {
  return getRuleContext<XiasParser::Local_constant_declarationContext>(0);
}


size_t XiasParser::Declaration_statementContext::getRuleIndex() const {
  return XiasParser::RuleDeclaration_statement;
}


antlrcpp::Any XiasParser::Declaration_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitDeclaration_statement(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Declaration_statementContext* XiasParser::declaration_statement() {
  Declaration_statementContext *_localctx = _tracker.createInstance<Declaration_statementContext>(_ctx, getState());
  enterRule(_localctx, 202, XiasParser::RuleDeclaration_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1147);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case XiasParser::BOOL:
      case XiasParser::CHAR:
      case XiasParser::DOUBLE:
      case XiasParser::FLOAT:
      case XiasParser::INT:
      case XiasParser::OBJECT:
      case XiasParser::STRING:
      case XiasParser::UINT:
      case XiasParser::VAR:
      case XiasParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(1141);
        local_variable_declaration();
        setState(1142);
        match(XiasParser::SEMICOLON);
        break;
      }

      case XiasParser::CONST: {
        enterOuterAlt(_localctx, 2);
        setState(1144);
        local_constant_declaration();
        setState(1145);
        match(XiasParser::SEMICOLON);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Local_variable_declarationContext ------------------------------------------------------------------

XiasParser::Local_variable_declarationContext::Local_variable_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Local_variable_typeContext* XiasParser::Local_variable_declarationContext::local_variable_type() {
  return getRuleContext<XiasParser::Local_variable_typeContext>(0);
}

XiasParser::Local_variable_declaratorsContext* XiasParser::Local_variable_declarationContext::local_variable_declarators() {
  return getRuleContext<XiasParser::Local_variable_declaratorsContext>(0);
}


size_t XiasParser::Local_variable_declarationContext::getRuleIndex() const {
  return XiasParser::RuleLocal_variable_declaration;
}


antlrcpp::Any XiasParser::Local_variable_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitLocal_variable_declaration(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Local_variable_declarationContext* XiasParser::local_variable_declaration() {
  Local_variable_declarationContext *_localctx = _tracker.createInstance<Local_variable_declarationContext>(_ctx, getState());
  enterRule(_localctx, 204, XiasParser::RuleLocal_variable_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1149);
    local_variable_type();
    setState(1150);
    local_variable_declarators();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Local_variable_typeContext ------------------------------------------------------------------

XiasParser::Local_variable_typeContext::Local_variable_typeContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Type_Context* XiasParser::Local_variable_typeContext::type_() {
  return getRuleContext<XiasParser::Type_Context>(0);
}

tree::TerminalNode* XiasParser::Local_variable_typeContext::VAR() {
  return getToken(XiasParser::VAR, 0);
}


size_t XiasParser::Local_variable_typeContext::getRuleIndex() const {
  return XiasParser::RuleLocal_variable_type;
}


antlrcpp::Any XiasParser::Local_variable_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitLocal_variable_type(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Local_variable_typeContext* XiasParser::local_variable_type() {
  Local_variable_typeContext *_localctx = _tracker.createInstance<Local_variable_typeContext>(_ctx, getState());
  enterRule(_localctx, 206, XiasParser::RuleLocal_variable_type);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1154);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case XiasParser::BOOL:
      case XiasParser::CHAR:
      case XiasParser::DOUBLE:
      case XiasParser::FLOAT:
      case XiasParser::INT:
      case XiasParser::OBJECT:
      case XiasParser::STRING:
      case XiasParser::UINT:
      case XiasParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(1152);
        type_();
        break;
      }

      case XiasParser::VAR: {
        enterOuterAlt(_localctx, 2);
        setState(1153);
        match(XiasParser::VAR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Local_variable_declaratorsContext ------------------------------------------------------------------

XiasParser::Local_variable_declaratorsContext::Local_variable_declaratorsContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

std::vector<XiasParser::Local_variable_declaratorContext *> XiasParser::Local_variable_declaratorsContext::local_variable_declarator() {
  return getRuleContexts<XiasParser::Local_variable_declaratorContext>();
}

XiasParser::Local_variable_declaratorContext* XiasParser::Local_variable_declaratorsContext::local_variable_declarator(size_t i) {
  return getRuleContext<XiasParser::Local_variable_declaratorContext>(i);
}

std::vector<tree::TerminalNode *> XiasParser::Local_variable_declaratorsContext::COMMA() {
  return getTokens(XiasParser::COMMA);
}

tree::TerminalNode* XiasParser::Local_variable_declaratorsContext::COMMA(size_t i) {
  return getToken(XiasParser::COMMA, i);
}


size_t XiasParser::Local_variable_declaratorsContext::getRuleIndex() const {
  return XiasParser::RuleLocal_variable_declarators;
}


antlrcpp::Any XiasParser::Local_variable_declaratorsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitLocal_variable_declarators(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Local_variable_declaratorsContext* XiasParser::local_variable_declarators() {
  Local_variable_declaratorsContext *_localctx = _tracker.createInstance<Local_variable_declaratorsContext>(_ctx, getState());
  enterRule(_localctx, 208, XiasParser::RuleLocal_variable_declarators);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1156);
    local_variable_declarator();
    setState(1161);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == XiasParser::COMMA) {
      setState(1157);
      match(XiasParser::COMMA);
      setState(1158);
      local_variable_declarator();
      setState(1163);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Local_variable_declaratorContext ------------------------------------------------------------------

XiasParser::Local_variable_declaratorContext::Local_variable_declaratorContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::IdentifierContext* XiasParser::Local_variable_declaratorContext::identifier() {
  return getRuleContext<XiasParser::IdentifierContext>(0);
}

tree::TerminalNode* XiasParser::Local_variable_declaratorContext::ASSIGNMENT() {
  return getToken(XiasParser::ASSIGNMENT, 0);
}

XiasParser::Local_variable_initializerContext* XiasParser::Local_variable_declaratorContext::local_variable_initializer() {
  return getRuleContext<XiasParser::Local_variable_initializerContext>(0);
}


size_t XiasParser::Local_variable_declaratorContext::getRuleIndex() const {
  return XiasParser::RuleLocal_variable_declarator;
}


antlrcpp::Any XiasParser::Local_variable_declaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitLocal_variable_declarator(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Local_variable_declaratorContext* XiasParser::local_variable_declarator() {
  Local_variable_declaratorContext *_localctx = _tracker.createInstance<Local_variable_declaratorContext>(_ctx, getState());
  enterRule(_localctx, 210, XiasParser::RuleLocal_variable_declarator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1169);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 99, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1164);
      identifier();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1165);
      identifier();
      setState(1166);
      match(XiasParser::ASSIGNMENT);
      setState(1167);
      local_variable_initializer();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Local_variable_initializerContext ------------------------------------------------------------------

XiasParser::Local_variable_initializerContext::Local_variable_initializerContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::ExpressionContext* XiasParser::Local_variable_initializerContext::expression() {
  return getRuleContext<XiasParser::ExpressionContext>(0);
}

XiasParser::Array_initializerContext* XiasParser::Local_variable_initializerContext::array_initializer() {
  return getRuleContext<XiasParser::Array_initializerContext>(0);
}


size_t XiasParser::Local_variable_initializerContext::getRuleIndex() const {
  return XiasParser::RuleLocal_variable_initializer;
}


antlrcpp::Any XiasParser::Local_variable_initializerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitLocal_variable_initializer(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Local_variable_initializerContext* XiasParser::local_variable_initializer() {
  Local_variable_initializerContext *_localctx = _tracker.createInstance<Local_variable_initializerContext>(_ctx, getState());
  enterRule(_localctx, 212, XiasParser::RuleLocal_variable_initializer);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1173);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case XiasParser::BASE:
      case XiasParser::DEFAULT:
      case XiasParser::FALSE:
      case XiasParser::NEW:
      case XiasParser::NULL_:
      case XiasParser::THIS:
      case XiasParser::TRUE:
      case XiasParser::TYPEOF:
      case XiasParser::IDENTIFIER:
      case XiasParser::INTEGER_LITERAL:
      case XiasParser::UNSIGNED_LITERAL:
      case XiasParser::HEX_INTEGER_LITERAL:
      case XiasParser::FLOAT_LITERAL:
      case XiasParser::DOUBLE_LITERAL:
      case XiasParser::CHARACTER_LITERAL:
      case XiasParser::REGULAR_STRING:
      case XiasParser::VERBATIUM_STRING:
      case XiasParser::OPEN_PARENS:
      case XiasParser::PLUS:
      case XiasParser::MINUS:
      case XiasParser::BANG:
      case XiasParser::TILDE:
      case XiasParser::OP_INC:
      case XiasParser::OP_DEC: {
        enterOuterAlt(_localctx, 1);
        setState(1171);
        expression();
        break;
      }

      case XiasParser::OPEN_BRACE: {
        enterOuterAlt(_localctx, 2);
        setState(1172);
        array_initializer();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Local_constant_declarationContext ------------------------------------------------------------------

XiasParser::Local_constant_declarationContext::Local_constant_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Local_constant_declarationContext::CONST() {
  return getToken(XiasParser::CONST, 0);
}

XiasParser::Type_Context* XiasParser::Local_constant_declarationContext::type_() {
  return getRuleContext<XiasParser::Type_Context>(0);
}

XiasParser::Constant_declaratorsContext* XiasParser::Local_constant_declarationContext::constant_declarators() {
  return getRuleContext<XiasParser::Constant_declaratorsContext>(0);
}


size_t XiasParser::Local_constant_declarationContext::getRuleIndex() const {
  return XiasParser::RuleLocal_constant_declaration;
}


antlrcpp::Any XiasParser::Local_constant_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitLocal_constant_declaration(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Local_constant_declarationContext* XiasParser::local_constant_declaration() {
  Local_constant_declarationContext *_localctx = _tracker.createInstance<Local_constant_declarationContext>(_ctx, getState());
  enterRule(_localctx, 214, XiasParser::RuleLocal_constant_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1175);
    match(XiasParser::CONST);
    setState(1176);
    type_();
    setState(1177);
    constant_declarators();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Constant_declaratorsContext ------------------------------------------------------------------

XiasParser::Constant_declaratorsContext::Constant_declaratorsContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

std::vector<XiasParser::Constant_declaratorContext *> XiasParser::Constant_declaratorsContext::constant_declarator() {
  return getRuleContexts<XiasParser::Constant_declaratorContext>();
}

XiasParser::Constant_declaratorContext* XiasParser::Constant_declaratorsContext::constant_declarator(size_t i) {
  return getRuleContext<XiasParser::Constant_declaratorContext>(i);
}

std::vector<tree::TerminalNode *> XiasParser::Constant_declaratorsContext::COMMA() {
  return getTokens(XiasParser::COMMA);
}

tree::TerminalNode* XiasParser::Constant_declaratorsContext::COMMA(size_t i) {
  return getToken(XiasParser::COMMA, i);
}


size_t XiasParser::Constant_declaratorsContext::getRuleIndex() const {
  return XiasParser::RuleConstant_declarators;
}


antlrcpp::Any XiasParser::Constant_declaratorsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitConstant_declarators(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Constant_declaratorsContext* XiasParser::constant_declarators() {
  Constant_declaratorsContext *_localctx = _tracker.createInstance<Constant_declaratorsContext>(_ctx, getState());
  enterRule(_localctx, 216, XiasParser::RuleConstant_declarators);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1179);
    constant_declarator();
    setState(1184);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == XiasParser::COMMA) {
      setState(1180);
      match(XiasParser::COMMA);
      setState(1181);
      constant_declarator();
      setState(1186);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Constant_declaratorContext ------------------------------------------------------------------

XiasParser::Constant_declaratorContext::Constant_declaratorContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::IdentifierContext* XiasParser::Constant_declaratorContext::identifier() {
  return getRuleContext<XiasParser::IdentifierContext>(0);
}

tree::TerminalNode* XiasParser::Constant_declaratorContext::ASSIGNMENT() {
  return getToken(XiasParser::ASSIGNMENT, 0);
}

XiasParser::Constant_expressionContext* XiasParser::Constant_declaratorContext::constant_expression() {
  return getRuleContext<XiasParser::Constant_expressionContext>(0);
}


size_t XiasParser::Constant_declaratorContext::getRuleIndex() const {
  return XiasParser::RuleConstant_declarator;
}


antlrcpp::Any XiasParser::Constant_declaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitConstant_declarator(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Constant_declaratorContext* XiasParser::constant_declarator() {
  Constant_declaratorContext *_localctx = _tracker.createInstance<Constant_declaratorContext>(_ctx, getState());
  enterRule(_localctx, 218, XiasParser::RuleConstant_declarator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1187);
    identifier();
    setState(1188);
    match(XiasParser::ASSIGNMENT);
    setState(1189);
    constant_expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Embedded_statementContext ------------------------------------------------------------------

XiasParser::Embedded_statementContext::Embedded_statementContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::BlockContext* XiasParser::Embedded_statementContext::block() {
  return getRuleContext<XiasParser::BlockContext>(0);
}

XiasParser::Empty_statementContext* XiasParser::Embedded_statementContext::empty_statement() {
  return getRuleContext<XiasParser::Empty_statementContext>(0);
}

XiasParser::Expression_statementContext* XiasParser::Embedded_statementContext::expression_statement() {
  return getRuleContext<XiasParser::Expression_statementContext>(0);
}

XiasParser::Selection_statementContext* XiasParser::Embedded_statementContext::selection_statement() {
  return getRuleContext<XiasParser::Selection_statementContext>(0);
}

XiasParser::Iteration_statementContext* XiasParser::Embedded_statementContext::iteration_statement() {
  return getRuleContext<XiasParser::Iteration_statementContext>(0);
}

XiasParser::Jump_statementContext* XiasParser::Embedded_statementContext::jump_statement() {
  return getRuleContext<XiasParser::Jump_statementContext>(0);
}

XiasParser::Try_statementContext* XiasParser::Embedded_statementContext::try_statement() {
  return getRuleContext<XiasParser::Try_statementContext>(0);
}


size_t XiasParser::Embedded_statementContext::getRuleIndex() const {
  return XiasParser::RuleEmbedded_statement;
}


antlrcpp::Any XiasParser::Embedded_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitEmbedded_statement(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Embedded_statementContext* XiasParser::embedded_statement() {
  Embedded_statementContext *_localctx = _tracker.createInstance<Embedded_statementContext>(_ctx, getState());
  enterRule(_localctx, 220, XiasParser::RuleEmbedded_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1198);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case XiasParser::OPEN_BRACE: {
        enterOuterAlt(_localctx, 1);
        setState(1191);
        block();
        break;
      }

      case XiasParser::SEMICOLON: {
        enterOuterAlt(_localctx, 2);
        setState(1192);
        empty_statement();
        break;
      }

      case XiasParser::BASE:
      case XiasParser::DEFAULT:
      case XiasParser::FALSE:
      case XiasParser::NEW:
      case XiasParser::NULL_:
      case XiasParser::THIS:
      case XiasParser::TRUE:
      case XiasParser::TYPEOF:
      case XiasParser::IDENTIFIER:
      case XiasParser::INTEGER_LITERAL:
      case XiasParser::UNSIGNED_LITERAL:
      case XiasParser::HEX_INTEGER_LITERAL:
      case XiasParser::FLOAT_LITERAL:
      case XiasParser::DOUBLE_LITERAL:
      case XiasParser::CHARACTER_LITERAL:
      case XiasParser::REGULAR_STRING:
      case XiasParser::VERBATIUM_STRING:
      case XiasParser::OPEN_PARENS:
      case XiasParser::PLUS:
      case XiasParser::MINUS:
      case XiasParser::BANG:
      case XiasParser::TILDE:
      case XiasParser::OP_INC:
      case XiasParser::OP_DEC: {
        enterOuterAlt(_localctx, 3);
        setState(1193);
        expression_statement();
        break;
      }

      case XiasParser::IF:
      case XiasParser::SWITCH: {
        enterOuterAlt(_localctx, 4);
        setState(1194);
        selection_statement();
        break;
      }

      case XiasParser::DO:
      case XiasParser::FOR:
      case XiasParser::FOREACH:
      case XiasParser::WHILE: {
        enterOuterAlt(_localctx, 5);
        setState(1195);
        iteration_statement();
        break;
      }

      case XiasParser::BREAK:
      case XiasParser::CONTINUE:
      case XiasParser::GOTO:
      case XiasParser::RETURN:
      case XiasParser::THROW: {
        enterOuterAlt(_localctx, 6);
        setState(1196);
        jump_statement();
        break;
      }

      case XiasParser::TRY: {
        enterOuterAlt(_localctx, 7);
        setState(1197);
        try_statement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Empty_statementContext ------------------------------------------------------------------

XiasParser::Empty_statementContext::Empty_statementContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Empty_statementContext::SEMICOLON() {
  return getToken(XiasParser::SEMICOLON, 0);
}


size_t XiasParser::Empty_statementContext::getRuleIndex() const {
  return XiasParser::RuleEmpty_statement;
}


antlrcpp::Any XiasParser::Empty_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitEmpty_statement(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Empty_statementContext* XiasParser::empty_statement() {
  Empty_statementContext *_localctx = _tracker.createInstance<Empty_statementContext>(_ctx, getState());
  enterRule(_localctx, 222, XiasParser::RuleEmpty_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1200);
    match(XiasParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_statementContext ------------------------------------------------------------------

XiasParser::Expression_statementContext::Expression_statementContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Statement_expressionContext* XiasParser::Expression_statementContext::statement_expression() {
  return getRuleContext<XiasParser::Statement_expressionContext>(0);
}

tree::TerminalNode* XiasParser::Expression_statementContext::SEMICOLON() {
  return getToken(XiasParser::SEMICOLON, 0);
}


size_t XiasParser::Expression_statementContext::getRuleIndex() const {
  return XiasParser::RuleExpression_statement;
}


antlrcpp::Any XiasParser::Expression_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitExpression_statement(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Expression_statementContext* XiasParser::expression_statement() {
  Expression_statementContext *_localctx = _tracker.createInstance<Expression_statementContext>(_ctx, getState());
  enterRule(_localctx, 224, XiasParser::RuleExpression_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1202);
    statement_expression();
    setState(1203);
    match(XiasParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Statement_expressionContext ------------------------------------------------------------------

XiasParser::Statement_expressionContext::Statement_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Invocation_expressionContext* XiasParser::Statement_expressionContext::invocation_expression() {
  return getRuleContext<XiasParser::Invocation_expressionContext>(0);
}

XiasParser::Object_creation_expressionContext* XiasParser::Statement_expressionContext::object_creation_expression() {
  return getRuleContext<XiasParser::Object_creation_expressionContext>(0);
}

XiasParser::AssignmentContext* XiasParser::Statement_expressionContext::assignment() {
  return getRuleContext<XiasParser::AssignmentContext>(0);
}

XiasParser::Post_increment_expressionContext* XiasParser::Statement_expressionContext::post_increment_expression() {
  return getRuleContext<XiasParser::Post_increment_expressionContext>(0);
}

XiasParser::Post_decrement_expressionContext* XiasParser::Statement_expressionContext::post_decrement_expression() {
  return getRuleContext<XiasParser::Post_decrement_expressionContext>(0);
}

XiasParser::Pre_increment_expressionContext* XiasParser::Statement_expressionContext::pre_increment_expression() {
  return getRuleContext<XiasParser::Pre_increment_expressionContext>(0);
}

XiasParser::Pre_decrement_expressionContext* XiasParser::Statement_expressionContext::pre_decrement_expression() {
  return getRuleContext<XiasParser::Pre_decrement_expressionContext>(0);
}


size_t XiasParser::Statement_expressionContext::getRuleIndex() const {
  return XiasParser::RuleStatement_expression;
}


antlrcpp::Any XiasParser::Statement_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitStatement_expression(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Statement_expressionContext* XiasParser::statement_expression() {
  Statement_expressionContext *_localctx = _tracker.createInstance<Statement_expressionContext>(_ctx, getState());
  enterRule(_localctx, 226, XiasParser::RuleStatement_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1212);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 103, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1205);
      invocation_expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1206);
      object_creation_expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1207);
      assignment();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1208);
      post_increment_expression();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(1209);
      post_decrement_expression();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(1210);
      pre_increment_expression();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(1211);
      pre_decrement_expression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Selection_statementContext ------------------------------------------------------------------

XiasParser::Selection_statementContext::Selection_statementContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::If_statementContext* XiasParser::Selection_statementContext::if_statement() {
  return getRuleContext<XiasParser::If_statementContext>(0);
}

XiasParser::Switch_statementContext* XiasParser::Selection_statementContext::switch_statement() {
  return getRuleContext<XiasParser::Switch_statementContext>(0);
}


size_t XiasParser::Selection_statementContext::getRuleIndex() const {
  return XiasParser::RuleSelection_statement;
}


antlrcpp::Any XiasParser::Selection_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitSelection_statement(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Selection_statementContext* XiasParser::selection_statement() {
  Selection_statementContext *_localctx = _tracker.createInstance<Selection_statementContext>(_ctx, getState());
  enterRule(_localctx, 228, XiasParser::RuleSelection_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1216);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case XiasParser::IF: {
        enterOuterAlt(_localctx, 1);
        setState(1214);
        if_statement();
        break;
      }

      case XiasParser::SWITCH: {
        enterOuterAlt(_localctx, 2);
        setState(1215);
        switch_statement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_statementContext ------------------------------------------------------------------

XiasParser::If_statementContext::If_statementContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::If_statementContext::IF() {
  return getToken(XiasParser::IF, 0);
}

tree::TerminalNode* XiasParser::If_statementContext::OPEN_PARENS() {
  return getToken(XiasParser::OPEN_PARENS, 0);
}

XiasParser::ExpressionContext* XiasParser::If_statementContext::expression() {
  return getRuleContext<XiasParser::ExpressionContext>(0);
}

tree::TerminalNode* XiasParser::If_statementContext::CLOSE_PARENS() {
  return getToken(XiasParser::CLOSE_PARENS, 0);
}

std::vector<XiasParser::Embedded_statementContext *> XiasParser::If_statementContext::embedded_statement() {
  return getRuleContexts<XiasParser::Embedded_statementContext>();
}

XiasParser::Embedded_statementContext* XiasParser::If_statementContext::embedded_statement(size_t i) {
  return getRuleContext<XiasParser::Embedded_statementContext>(i);
}

tree::TerminalNode* XiasParser::If_statementContext::ELSE() {
  return getToken(XiasParser::ELSE, 0);
}


size_t XiasParser::If_statementContext::getRuleIndex() const {
  return XiasParser::RuleIf_statement;
}


antlrcpp::Any XiasParser::If_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitIf_statement(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::If_statementContext* XiasParser::if_statement() {
  If_statementContext *_localctx = _tracker.createInstance<If_statementContext>(_ctx, getState());
  enterRule(_localctx, 230, XiasParser::RuleIf_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1232);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 105, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1218);
      match(XiasParser::IF);
      setState(1219);
      match(XiasParser::OPEN_PARENS);
      setState(1220);
      expression();
      setState(1221);
      match(XiasParser::CLOSE_PARENS);
      setState(1222);
      embedded_statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1224);
      match(XiasParser::IF);
      setState(1225);
      match(XiasParser::OPEN_PARENS);
      setState(1226);
      expression();
      setState(1227);
      match(XiasParser::CLOSE_PARENS);
      setState(1228);
      embedded_statement();
      setState(1229);
      match(XiasParser::ELSE);
      setState(1230);
      embedded_statement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Switch_statementContext ------------------------------------------------------------------

XiasParser::Switch_statementContext::Switch_statementContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Switch_statementContext::SWITCH() {
  return getToken(XiasParser::SWITCH, 0);
}

tree::TerminalNode* XiasParser::Switch_statementContext::OPEN_PARENS() {
  return getToken(XiasParser::OPEN_PARENS, 0);
}

XiasParser::ExpressionContext* XiasParser::Switch_statementContext::expression() {
  return getRuleContext<XiasParser::ExpressionContext>(0);
}

tree::TerminalNode* XiasParser::Switch_statementContext::CLOSE_PARENS() {
  return getToken(XiasParser::CLOSE_PARENS, 0);
}

XiasParser::Switch_blockContext* XiasParser::Switch_statementContext::switch_block() {
  return getRuleContext<XiasParser::Switch_blockContext>(0);
}


size_t XiasParser::Switch_statementContext::getRuleIndex() const {
  return XiasParser::RuleSwitch_statement;
}


antlrcpp::Any XiasParser::Switch_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitSwitch_statement(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Switch_statementContext* XiasParser::switch_statement() {
  Switch_statementContext *_localctx = _tracker.createInstance<Switch_statementContext>(_ctx, getState());
  enterRule(_localctx, 232, XiasParser::RuleSwitch_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1234);
    match(XiasParser::SWITCH);
    setState(1235);
    match(XiasParser::OPEN_PARENS);
    setState(1236);
    expression();
    setState(1237);
    match(XiasParser::CLOSE_PARENS);
    setState(1238);
    switch_block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Switch_blockContext ------------------------------------------------------------------

XiasParser::Switch_blockContext::Switch_blockContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Switch_blockContext::OPEN_BRACE() {
  return getToken(XiasParser::OPEN_BRACE, 0);
}

tree::TerminalNode* XiasParser::Switch_blockContext::CLOSE_BRACE() {
  return getToken(XiasParser::CLOSE_BRACE, 0);
}

std::vector<XiasParser::Switch_sectionContext *> XiasParser::Switch_blockContext::switch_section() {
  return getRuleContexts<XiasParser::Switch_sectionContext>();
}

XiasParser::Switch_sectionContext* XiasParser::Switch_blockContext::switch_section(size_t i) {
  return getRuleContext<XiasParser::Switch_sectionContext>(i);
}


size_t XiasParser::Switch_blockContext::getRuleIndex() const {
  return XiasParser::RuleSwitch_block;
}


antlrcpp::Any XiasParser::Switch_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitSwitch_block(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Switch_blockContext* XiasParser::switch_block() {
  Switch_blockContext *_localctx = _tracker.createInstance<Switch_blockContext>(_ctx, getState());
  enterRule(_localctx, 234, XiasParser::RuleSwitch_block);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1240);
    match(XiasParser::OPEN_BRACE);
    setState(1244);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == XiasParser::CASE

    || _la == XiasParser::DEFAULT) {
      setState(1241);
      switch_section();
      setState(1246);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1247);
    match(XiasParser::CLOSE_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Switch_sectionContext ------------------------------------------------------------------

XiasParser::Switch_sectionContext::Switch_sectionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Statement_listContext* XiasParser::Switch_sectionContext::statement_list() {
  return getRuleContext<XiasParser::Statement_listContext>(0);
}

std::vector<XiasParser::Switch_labelContext *> XiasParser::Switch_sectionContext::switch_label() {
  return getRuleContexts<XiasParser::Switch_labelContext>();
}

XiasParser::Switch_labelContext* XiasParser::Switch_sectionContext::switch_label(size_t i) {
  return getRuleContext<XiasParser::Switch_labelContext>(i);
}


size_t XiasParser::Switch_sectionContext::getRuleIndex() const {
  return XiasParser::RuleSwitch_section;
}


antlrcpp::Any XiasParser::Switch_sectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitSwitch_section(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Switch_sectionContext* XiasParser::switch_section() {
  Switch_sectionContext *_localctx = _tracker.createInstance<Switch_sectionContext>(_ctx, getState());
  enterRule(_localctx, 236, XiasParser::RuleSwitch_section);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1250); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(1249);
              switch_label();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(1252); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 107, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(1254);
    statement_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Switch_labelContext ------------------------------------------------------------------

XiasParser::Switch_labelContext::Switch_labelContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Switch_labelContext::CASE() {
  return getToken(XiasParser::CASE, 0);
}

XiasParser::Constant_expressionContext* XiasParser::Switch_labelContext::constant_expression() {
  return getRuleContext<XiasParser::Constant_expressionContext>(0);
}

tree::TerminalNode* XiasParser::Switch_labelContext::COLON() {
  return getToken(XiasParser::COLON, 0);
}

tree::TerminalNode* XiasParser::Switch_labelContext::DEFAULT() {
  return getToken(XiasParser::DEFAULT, 0);
}


size_t XiasParser::Switch_labelContext::getRuleIndex() const {
  return XiasParser::RuleSwitch_label;
}


antlrcpp::Any XiasParser::Switch_labelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitSwitch_label(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Switch_labelContext* XiasParser::switch_label() {
  Switch_labelContext *_localctx = _tracker.createInstance<Switch_labelContext>(_ctx, getState());
  enterRule(_localctx, 238, XiasParser::RuleSwitch_label);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1262);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case XiasParser::CASE: {
        enterOuterAlt(_localctx, 1);
        setState(1256);
        match(XiasParser::CASE);
        setState(1257);
        constant_expression();
        setState(1258);
        match(XiasParser::COLON);
        break;
      }

      case XiasParser::DEFAULT: {
        enterOuterAlt(_localctx, 2);
        setState(1260);
        match(XiasParser::DEFAULT);
        setState(1261);
        match(XiasParser::COLON);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Iteration_statementContext ------------------------------------------------------------------

XiasParser::Iteration_statementContext::Iteration_statementContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::While_statementContext* XiasParser::Iteration_statementContext::while_statement() {
  return getRuleContext<XiasParser::While_statementContext>(0);
}

XiasParser::Do_statementContext* XiasParser::Iteration_statementContext::do_statement() {
  return getRuleContext<XiasParser::Do_statementContext>(0);
}

XiasParser::For_statementContext* XiasParser::Iteration_statementContext::for_statement() {
  return getRuleContext<XiasParser::For_statementContext>(0);
}

XiasParser::Foreach_statementContext* XiasParser::Iteration_statementContext::foreach_statement() {
  return getRuleContext<XiasParser::Foreach_statementContext>(0);
}


size_t XiasParser::Iteration_statementContext::getRuleIndex() const {
  return XiasParser::RuleIteration_statement;
}


antlrcpp::Any XiasParser::Iteration_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitIteration_statement(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Iteration_statementContext* XiasParser::iteration_statement() {
  Iteration_statementContext *_localctx = _tracker.createInstance<Iteration_statementContext>(_ctx, getState());
  enterRule(_localctx, 240, XiasParser::RuleIteration_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1268);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case XiasParser::WHILE: {
        enterOuterAlt(_localctx, 1);
        setState(1264);
        while_statement();
        break;
      }

      case XiasParser::DO: {
        enterOuterAlt(_localctx, 2);
        setState(1265);
        do_statement();
        break;
      }

      case XiasParser::FOR: {
        enterOuterAlt(_localctx, 3);
        setState(1266);
        for_statement();
        break;
      }

      case XiasParser::FOREACH: {
        enterOuterAlt(_localctx, 4);
        setState(1267);
        foreach_statement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- While_statementContext ------------------------------------------------------------------

XiasParser::While_statementContext::While_statementContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::While_statementContext::WHILE() {
  return getToken(XiasParser::WHILE, 0);
}

tree::TerminalNode* XiasParser::While_statementContext::OPEN_PARENS() {
  return getToken(XiasParser::OPEN_PARENS, 0);
}

XiasParser::Boolean_expressionContext* XiasParser::While_statementContext::boolean_expression() {
  return getRuleContext<XiasParser::Boolean_expressionContext>(0);
}

tree::TerminalNode* XiasParser::While_statementContext::CLOSE_PARENS() {
  return getToken(XiasParser::CLOSE_PARENS, 0);
}

XiasParser::Embedded_statementContext* XiasParser::While_statementContext::embedded_statement() {
  return getRuleContext<XiasParser::Embedded_statementContext>(0);
}


size_t XiasParser::While_statementContext::getRuleIndex() const {
  return XiasParser::RuleWhile_statement;
}


antlrcpp::Any XiasParser::While_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitWhile_statement(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::While_statementContext* XiasParser::while_statement() {
  While_statementContext *_localctx = _tracker.createInstance<While_statementContext>(_ctx, getState());
  enterRule(_localctx, 242, XiasParser::RuleWhile_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1270);
    match(XiasParser::WHILE);
    setState(1271);
    match(XiasParser::OPEN_PARENS);
    setState(1272);
    boolean_expression();
    setState(1273);
    match(XiasParser::CLOSE_PARENS);
    setState(1274);
    embedded_statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Do_statementContext ------------------------------------------------------------------

XiasParser::Do_statementContext::Do_statementContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Do_statementContext::DO() {
  return getToken(XiasParser::DO, 0);
}

XiasParser::Embedded_statementContext* XiasParser::Do_statementContext::embedded_statement() {
  return getRuleContext<XiasParser::Embedded_statementContext>(0);
}

tree::TerminalNode* XiasParser::Do_statementContext::WHILE() {
  return getToken(XiasParser::WHILE, 0);
}

tree::TerminalNode* XiasParser::Do_statementContext::OPEN_PARENS() {
  return getToken(XiasParser::OPEN_PARENS, 0);
}

XiasParser::Boolean_expressionContext* XiasParser::Do_statementContext::boolean_expression() {
  return getRuleContext<XiasParser::Boolean_expressionContext>(0);
}

tree::TerminalNode* XiasParser::Do_statementContext::CLOSE_PARENS() {
  return getToken(XiasParser::CLOSE_PARENS, 0);
}

tree::TerminalNode* XiasParser::Do_statementContext::SEMICOLON() {
  return getToken(XiasParser::SEMICOLON, 0);
}


size_t XiasParser::Do_statementContext::getRuleIndex() const {
  return XiasParser::RuleDo_statement;
}


antlrcpp::Any XiasParser::Do_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitDo_statement(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Do_statementContext* XiasParser::do_statement() {
  Do_statementContext *_localctx = _tracker.createInstance<Do_statementContext>(_ctx, getState());
  enterRule(_localctx, 244, XiasParser::RuleDo_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1276);
    match(XiasParser::DO);
    setState(1277);
    embedded_statement();
    setState(1278);
    match(XiasParser::WHILE);
    setState(1279);
    match(XiasParser::OPEN_PARENS);
    setState(1280);
    boolean_expression();
    setState(1281);
    match(XiasParser::CLOSE_PARENS);
    setState(1282);
    match(XiasParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For_statementContext ------------------------------------------------------------------

XiasParser::For_statementContext::For_statementContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::For_statementContext::FOR() {
  return getToken(XiasParser::FOR, 0);
}

tree::TerminalNode* XiasParser::For_statementContext::OPEN_PARENS() {
  return getToken(XiasParser::OPEN_PARENS, 0);
}

std::vector<tree::TerminalNode *> XiasParser::For_statementContext::SEMICOLON() {
  return getTokens(XiasParser::SEMICOLON);
}

tree::TerminalNode* XiasParser::For_statementContext::SEMICOLON(size_t i) {
  return getToken(XiasParser::SEMICOLON, i);
}

tree::TerminalNode* XiasParser::For_statementContext::CLOSE_PARENS() {
  return getToken(XiasParser::CLOSE_PARENS, 0);
}

XiasParser::Embedded_statementContext* XiasParser::For_statementContext::embedded_statement() {
  return getRuleContext<XiasParser::Embedded_statementContext>(0);
}

XiasParser::For_initializerContext* XiasParser::For_statementContext::for_initializer() {
  return getRuleContext<XiasParser::For_initializerContext>(0);
}

XiasParser::For_conditionContext* XiasParser::For_statementContext::for_condition() {
  return getRuleContext<XiasParser::For_conditionContext>(0);
}

XiasParser::For_iteratorContext* XiasParser::For_statementContext::for_iterator() {
  return getRuleContext<XiasParser::For_iteratorContext>(0);
}


size_t XiasParser::For_statementContext::getRuleIndex() const {
  return XiasParser::RuleFor_statement;
}


antlrcpp::Any XiasParser::For_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitFor_statement(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::For_statementContext* XiasParser::for_statement() {
  For_statementContext *_localctx = _tracker.createInstance<For_statementContext>(_ctx, getState());
  enterRule(_localctx, 246, XiasParser::RuleFor_statement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1284);
    match(XiasParser::FOR);
    setState(1285);
    match(XiasParser::OPEN_PARENS);
    setState(1287);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << XiasParser::BASE)
      | (1ULL << XiasParser::BOOL)
      | (1ULL << XiasParser::CHAR)
      | (1ULL << XiasParser::DEFAULT)
      | (1ULL << XiasParser::DOUBLE)
      | (1ULL << XiasParser::FALSE)
      | (1ULL << XiasParser::FLOAT)
      | (1ULL << XiasParser::INT)
      | (1ULL << XiasParser::NEW)
      | (1ULL << XiasParser::NULL_)
      | (1ULL << XiasParser::OBJECT)
      | (1ULL << XiasParser::STRING)
      | (1ULL << XiasParser::THIS)
      | (1ULL << XiasParser::TRUE)
      | (1ULL << XiasParser::TYPEOF))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (XiasParser::UINT - 64))
      | (1ULL << (XiasParser::VAR - 64))
      | (1ULL << (XiasParser::IDENTIFIER - 64))
      | (1ULL << (XiasParser::INTEGER_LITERAL - 64))
      | (1ULL << (XiasParser::UNSIGNED_LITERAL - 64))
      | (1ULL << (XiasParser::HEX_INTEGER_LITERAL - 64))
      | (1ULL << (XiasParser::FLOAT_LITERAL - 64))
      | (1ULL << (XiasParser::DOUBLE_LITERAL - 64))
      | (1ULL << (XiasParser::CHARACTER_LITERAL - 64))
      | (1ULL << (XiasParser::REGULAR_STRING - 64))
      | (1ULL << (XiasParser::VERBATIUM_STRING - 64))
      | (1ULL << (XiasParser::OPEN_PARENS - 64))
      | (1ULL << (XiasParser::PLUS - 64))
      | (1ULL << (XiasParser::MINUS - 64))
      | (1ULL << (XiasParser::BANG - 64))
      | (1ULL << (XiasParser::TILDE - 64))
      | (1ULL << (XiasParser::OP_INC - 64))
      | (1ULL << (XiasParser::OP_DEC - 64)))) != 0)) {
      setState(1286);
      for_initializer();
    }
    setState(1289);
    match(XiasParser::SEMICOLON);
    setState(1291);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << XiasParser::BASE)
      | (1ULL << XiasParser::DEFAULT)
      | (1ULL << XiasParser::FALSE)
      | (1ULL << XiasParser::NEW)
      | (1ULL << XiasParser::NULL_)
      | (1ULL << XiasParser::THIS)
      | (1ULL << XiasParser::TRUE)
      | (1ULL << XiasParser::TYPEOF))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 72)) & ((1ULL << (XiasParser::IDENTIFIER - 72))
      | (1ULL << (XiasParser::INTEGER_LITERAL - 72))
      | (1ULL << (XiasParser::UNSIGNED_LITERAL - 72))
      | (1ULL << (XiasParser::HEX_INTEGER_LITERAL - 72))
      | (1ULL << (XiasParser::FLOAT_LITERAL - 72))
      | (1ULL << (XiasParser::DOUBLE_LITERAL - 72))
      | (1ULL << (XiasParser::CHARACTER_LITERAL - 72))
      | (1ULL << (XiasParser::REGULAR_STRING - 72))
      | (1ULL << (XiasParser::VERBATIUM_STRING - 72))
      | (1ULL << (XiasParser::OPEN_PARENS - 72))
      | (1ULL << (XiasParser::PLUS - 72))
      | (1ULL << (XiasParser::MINUS - 72))
      | (1ULL << (XiasParser::BANG - 72))
      | (1ULL << (XiasParser::TILDE - 72))
      | (1ULL << (XiasParser::OP_INC - 72))
      | (1ULL << (XiasParser::OP_DEC - 72)))) != 0)) {
      setState(1290);
      for_condition();
    }
    setState(1293);
    match(XiasParser::SEMICOLON);
    setState(1295);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << XiasParser::BASE)
      | (1ULL << XiasParser::DEFAULT)
      | (1ULL << XiasParser::FALSE)
      | (1ULL << XiasParser::NEW)
      | (1ULL << XiasParser::NULL_)
      | (1ULL << XiasParser::THIS)
      | (1ULL << XiasParser::TRUE)
      | (1ULL << XiasParser::TYPEOF))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 72)) & ((1ULL << (XiasParser::IDENTIFIER - 72))
      | (1ULL << (XiasParser::INTEGER_LITERAL - 72))
      | (1ULL << (XiasParser::UNSIGNED_LITERAL - 72))
      | (1ULL << (XiasParser::HEX_INTEGER_LITERAL - 72))
      | (1ULL << (XiasParser::FLOAT_LITERAL - 72))
      | (1ULL << (XiasParser::DOUBLE_LITERAL - 72))
      | (1ULL << (XiasParser::CHARACTER_LITERAL - 72))
      | (1ULL << (XiasParser::REGULAR_STRING - 72))
      | (1ULL << (XiasParser::VERBATIUM_STRING - 72))
      | (1ULL << (XiasParser::OPEN_PARENS - 72))
      | (1ULL << (XiasParser::PLUS - 72))
      | (1ULL << (XiasParser::MINUS - 72))
      | (1ULL << (XiasParser::BANG - 72))
      | (1ULL << (XiasParser::TILDE - 72))
      | (1ULL << (XiasParser::OP_INC - 72))
      | (1ULL << (XiasParser::OP_DEC - 72)))) != 0)) {
      setState(1294);
      for_iterator();
    }
    setState(1297);
    match(XiasParser::CLOSE_PARENS);
    setState(1298);
    embedded_statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For_initializerContext ------------------------------------------------------------------

XiasParser::For_initializerContext::For_initializerContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Local_variable_declarationContext* XiasParser::For_initializerContext::local_variable_declaration() {
  return getRuleContext<XiasParser::Local_variable_declarationContext>(0);
}

XiasParser::Statement_expression_listContext* XiasParser::For_initializerContext::statement_expression_list() {
  return getRuleContext<XiasParser::Statement_expression_listContext>(0);
}


size_t XiasParser::For_initializerContext::getRuleIndex() const {
  return XiasParser::RuleFor_initializer;
}


antlrcpp::Any XiasParser::For_initializerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitFor_initializer(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::For_initializerContext* XiasParser::for_initializer() {
  For_initializerContext *_localctx = _tracker.createInstance<For_initializerContext>(_ctx, getState());
  enterRule(_localctx, 248, XiasParser::RuleFor_initializer);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1302);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 113, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1300);
      local_variable_declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1301);
      statement_expression_list();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For_conditionContext ------------------------------------------------------------------

XiasParser::For_conditionContext::For_conditionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Boolean_expressionContext* XiasParser::For_conditionContext::boolean_expression() {
  return getRuleContext<XiasParser::Boolean_expressionContext>(0);
}


size_t XiasParser::For_conditionContext::getRuleIndex() const {
  return XiasParser::RuleFor_condition;
}


antlrcpp::Any XiasParser::For_conditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitFor_condition(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::For_conditionContext* XiasParser::for_condition() {
  For_conditionContext *_localctx = _tracker.createInstance<For_conditionContext>(_ctx, getState());
  enterRule(_localctx, 250, XiasParser::RuleFor_condition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1304);
    boolean_expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For_iteratorContext ------------------------------------------------------------------

XiasParser::For_iteratorContext::For_iteratorContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Statement_expression_listContext* XiasParser::For_iteratorContext::statement_expression_list() {
  return getRuleContext<XiasParser::Statement_expression_listContext>(0);
}


size_t XiasParser::For_iteratorContext::getRuleIndex() const {
  return XiasParser::RuleFor_iterator;
}


antlrcpp::Any XiasParser::For_iteratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitFor_iterator(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::For_iteratorContext* XiasParser::for_iterator() {
  For_iteratorContext *_localctx = _tracker.createInstance<For_iteratorContext>(_ctx, getState());
  enterRule(_localctx, 252, XiasParser::RuleFor_iterator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1306);
    statement_expression_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Statement_expression_listContext ------------------------------------------------------------------

XiasParser::Statement_expression_listContext::Statement_expression_listContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

std::vector<XiasParser::Statement_expressionContext *> XiasParser::Statement_expression_listContext::statement_expression() {
  return getRuleContexts<XiasParser::Statement_expressionContext>();
}

XiasParser::Statement_expressionContext* XiasParser::Statement_expression_listContext::statement_expression(size_t i) {
  return getRuleContext<XiasParser::Statement_expressionContext>(i);
}

std::vector<tree::TerminalNode *> XiasParser::Statement_expression_listContext::COMMA() {
  return getTokens(XiasParser::COMMA);
}

tree::TerminalNode* XiasParser::Statement_expression_listContext::COMMA(size_t i) {
  return getToken(XiasParser::COMMA, i);
}


size_t XiasParser::Statement_expression_listContext::getRuleIndex() const {
  return XiasParser::RuleStatement_expression_list;
}


antlrcpp::Any XiasParser::Statement_expression_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitStatement_expression_list(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Statement_expression_listContext* XiasParser::statement_expression_list() {
  Statement_expression_listContext *_localctx = _tracker.createInstance<Statement_expression_listContext>(_ctx, getState());
  enterRule(_localctx, 254, XiasParser::RuleStatement_expression_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1308);
    statement_expression();
    setState(1313);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == XiasParser::COMMA) {
      setState(1309);
      match(XiasParser::COMMA);
      setState(1310);
      statement_expression();
      setState(1315);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Foreach_statementContext ------------------------------------------------------------------

XiasParser::Foreach_statementContext::Foreach_statementContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Foreach_statementContext::FOREACH() {
  return getToken(XiasParser::FOREACH, 0);
}

tree::TerminalNode* XiasParser::Foreach_statementContext::OPEN_PARENS() {
  return getToken(XiasParser::OPEN_PARENS, 0);
}

XiasParser::Local_variable_typeContext* XiasParser::Foreach_statementContext::local_variable_type() {
  return getRuleContext<XiasParser::Local_variable_typeContext>(0);
}

XiasParser::IdentifierContext* XiasParser::Foreach_statementContext::identifier() {
  return getRuleContext<XiasParser::IdentifierContext>(0);
}

tree::TerminalNode* XiasParser::Foreach_statementContext::IN() {
  return getToken(XiasParser::IN, 0);
}

XiasParser::ExpressionContext* XiasParser::Foreach_statementContext::expression() {
  return getRuleContext<XiasParser::ExpressionContext>(0);
}

tree::TerminalNode* XiasParser::Foreach_statementContext::CLOSE_PARENS() {
  return getToken(XiasParser::CLOSE_PARENS, 0);
}

XiasParser::Embedded_statementContext* XiasParser::Foreach_statementContext::embedded_statement() {
  return getRuleContext<XiasParser::Embedded_statementContext>(0);
}


size_t XiasParser::Foreach_statementContext::getRuleIndex() const {
  return XiasParser::RuleForeach_statement;
}


antlrcpp::Any XiasParser::Foreach_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitForeach_statement(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Foreach_statementContext* XiasParser::foreach_statement() {
  Foreach_statementContext *_localctx = _tracker.createInstance<Foreach_statementContext>(_ctx, getState());
  enterRule(_localctx, 256, XiasParser::RuleForeach_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1316);
    match(XiasParser::FOREACH);
    setState(1317);
    match(XiasParser::OPEN_PARENS);
    setState(1318);
    local_variable_type();
    setState(1319);
    identifier();
    setState(1320);
    match(XiasParser::IN);
    setState(1321);
    expression();
    setState(1322);
    match(XiasParser::CLOSE_PARENS);
    setState(1323);
    embedded_statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Jump_statementContext ------------------------------------------------------------------

XiasParser::Jump_statementContext::Jump_statementContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Break_statementContext* XiasParser::Jump_statementContext::break_statement() {
  return getRuleContext<XiasParser::Break_statementContext>(0);
}

XiasParser::Continue_statementContext* XiasParser::Jump_statementContext::continue_statement() {
  return getRuleContext<XiasParser::Continue_statementContext>(0);
}

XiasParser::Goto_statementContext* XiasParser::Jump_statementContext::goto_statement() {
  return getRuleContext<XiasParser::Goto_statementContext>(0);
}

XiasParser::Return_statementContext* XiasParser::Jump_statementContext::return_statement() {
  return getRuleContext<XiasParser::Return_statementContext>(0);
}

XiasParser::Throw_statementContext* XiasParser::Jump_statementContext::throw_statement() {
  return getRuleContext<XiasParser::Throw_statementContext>(0);
}


size_t XiasParser::Jump_statementContext::getRuleIndex() const {
  return XiasParser::RuleJump_statement;
}


antlrcpp::Any XiasParser::Jump_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitJump_statement(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Jump_statementContext* XiasParser::jump_statement() {
  Jump_statementContext *_localctx = _tracker.createInstance<Jump_statementContext>(_ctx, getState());
  enterRule(_localctx, 258, XiasParser::RuleJump_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1330);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case XiasParser::BREAK: {
        enterOuterAlt(_localctx, 1);
        setState(1325);
        break_statement();
        break;
      }

      case XiasParser::CONTINUE: {
        enterOuterAlt(_localctx, 2);
        setState(1326);
        continue_statement();
        break;
      }

      case XiasParser::GOTO: {
        enterOuterAlt(_localctx, 3);
        setState(1327);
        goto_statement();
        break;
      }

      case XiasParser::RETURN: {
        enterOuterAlt(_localctx, 4);
        setState(1328);
        return_statement();
        break;
      }

      case XiasParser::THROW: {
        enterOuterAlt(_localctx, 5);
        setState(1329);
        throw_statement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Break_statementContext ------------------------------------------------------------------

XiasParser::Break_statementContext::Break_statementContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Break_statementContext::BREAK() {
  return getToken(XiasParser::BREAK, 0);
}

tree::TerminalNode* XiasParser::Break_statementContext::SEMICOLON() {
  return getToken(XiasParser::SEMICOLON, 0);
}


size_t XiasParser::Break_statementContext::getRuleIndex() const {
  return XiasParser::RuleBreak_statement;
}


antlrcpp::Any XiasParser::Break_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitBreak_statement(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Break_statementContext* XiasParser::break_statement() {
  Break_statementContext *_localctx = _tracker.createInstance<Break_statementContext>(_ctx, getState());
  enterRule(_localctx, 260, XiasParser::RuleBreak_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1332);
    match(XiasParser::BREAK);
    setState(1333);
    match(XiasParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Continue_statementContext ------------------------------------------------------------------

XiasParser::Continue_statementContext::Continue_statementContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Continue_statementContext::CONTINUE() {
  return getToken(XiasParser::CONTINUE, 0);
}

tree::TerminalNode* XiasParser::Continue_statementContext::SEMICOLON() {
  return getToken(XiasParser::SEMICOLON, 0);
}


size_t XiasParser::Continue_statementContext::getRuleIndex() const {
  return XiasParser::RuleContinue_statement;
}


antlrcpp::Any XiasParser::Continue_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitContinue_statement(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Continue_statementContext* XiasParser::continue_statement() {
  Continue_statementContext *_localctx = _tracker.createInstance<Continue_statementContext>(_ctx, getState());
  enterRule(_localctx, 262, XiasParser::RuleContinue_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1335);
    match(XiasParser::CONTINUE);
    setState(1336);
    match(XiasParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Goto_statementContext ------------------------------------------------------------------

XiasParser::Goto_statementContext::Goto_statementContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Goto_statementContext::GOTO() {
  return getToken(XiasParser::GOTO, 0);
}

XiasParser::IdentifierContext* XiasParser::Goto_statementContext::identifier() {
  return getRuleContext<XiasParser::IdentifierContext>(0);
}

tree::TerminalNode* XiasParser::Goto_statementContext::SEMICOLON() {
  return getToken(XiasParser::SEMICOLON, 0);
}

tree::TerminalNode* XiasParser::Goto_statementContext::CASE() {
  return getToken(XiasParser::CASE, 0);
}

XiasParser::Constant_expressionContext* XiasParser::Goto_statementContext::constant_expression() {
  return getRuleContext<XiasParser::Constant_expressionContext>(0);
}

tree::TerminalNode* XiasParser::Goto_statementContext::DEFAULT() {
  return getToken(XiasParser::DEFAULT, 0);
}


size_t XiasParser::Goto_statementContext::getRuleIndex() const {
  return XiasParser::RuleGoto_statement;
}


antlrcpp::Any XiasParser::Goto_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitGoto_statement(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Goto_statementContext* XiasParser::goto_statement() {
  Goto_statementContext *_localctx = _tracker.createInstance<Goto_statementContext>(_ctx, getState());
  enterRule(_localctx, 264, XiasParser::RuleGoto_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1350);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 116, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1338);
      match(XiasParser::GOTO);
      setState(1339);
      identifier();
      setState(1340);
      match(XiasParser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1342);
      match(XiasParser::GOTO);
      setState(1343);
      match(XiasParser::CASE);
      setState(1344);
      constant_expression();
      setState(1345);
      match(XiasParser::SEMICOLON);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1347);
      match(XiasParser::GOTO);
      setState(1348);
      match(XiasParser::DEFAULT);
      setState(1349);
      match(XiasParser::SEMICOLON);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Return_statementContext ------------------------------------------------------------------

XiasParser::Return_statementContext::Return_statementContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Return_statementContext::RETURN() {
  return getToken(XiasParser::RETURN, 0);
}

tree::TerminalNode* XiasParser::Return_statementContext::SEMICOLON() {
  return getToken(XiasParser::SEMICOLON, 0);
}

XiasParser::ExpressionContext* XiasParser::Return_statementContext::expression() {
  return getRuleContext<XiasParser::ExpressionContext>(0);
}


size_t XiasParser::Return_statementContext::getRuleIndex() const {
  return XiasParser::RuleReturn_statement;
}


antlrcpp::Any XiasParser::Return_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitReturn_statement(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Return_statementContext* XiasParser::return_statement() {
  Return_statementContext *_localctx = _tracker.createInstance<Return_statementContext>(_ctx, getState());
  enterRule(_localctx, 266, XiasParser::RuleReturn_statement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1352);
    match(XiasParser::RETURN);
    setState(1354);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << XiasParser::BASE)
      | (1ULL << XiasParser::DEFAULT)
      | (1ULL << XiasParser::FALSE)
      | (1ULL << XiasParser::NEW)
      | (1ULL << XiasParser::NULL_)
      | (1ULL << XiasParser::THIS)
      | (1ULL << XiasParser::TRUE)
      | (1ULL << XiasParser::TYPEOF))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 72)) & ((1ULL << (XiasParser::IDENTIFIER - 72))
      | (1ULL << (XiasParser::INTEGER_LITERAL - 72))
      | (1ULL << (XiasParser::UNSIGNED_LITERAL - 72))
      | (1ULL << (XiasParser::HEX_INTEGER_LITERAL - 72))
      | (1ULL << (XiasParser::FLOAT_LITERAL - 72))
      | (1ULL << (XiasParser::DOUBLE_LITERAL - 72))
      | (1ULL << (XiasParser::CHARACTER_LITERAL - 72))
      | (1ULL << (XiasParser::REGULAR_STRING - 72))
      | (1ULL << (XiasParser::VERBATIUM_STRING - 72))
      | (1ULL << (XiasParser::OPEN_PARENS - 72))
      | (1ULL << (XiasParser::PLUS - 72))
      | (1ULL << (XiasParser::MINUS - 72))
      | (1ULL << (XiasParser::BANG - 72))
      | (1ULL << (XiasParser::TILDE - 72))
      | (1ULL << (XiasParser::OP_INC - 72))
      | (1ULL << (XiasParser::OP_DEC - 72)))) != 0)) {
      setState(1353);
      expression();
    }
    setState(1356);
    match(XiasParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Throw_statementContext ------------------------------------------------------------------

XiasParser::Throw_statementContext::Throw_statementContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Throw_statementContext::THROW() {
  return getToken(XiasParser::THROW, 0);
}

tree::TerminalNode* XiasParser::Throw_statementContext::SEMICOLON() {
  return getToken(XiasParser::SEMICOLON, 0);
}

XiasParser::ExpressionContext* XiasParser::Throw_statementContext::expression() {
  return getRuleContext<XiasParser::ExpressionContext>(0);
}


size_t XiasParser::Throw_statementContext::getRuleIndex() const {
  return XiasParser::RuleThrow_statement;
}


antlrcpp::Any XiasParser::Throw_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitThrow_statement(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Throw_statementContext* XiasParser::throw_statement() {
  Throw_statementContext *_localctx = _tracker.createInstance<Throw_statementContext>(_ctx, getState());
  enterRule(_localctx, 268, XiasParser::RuleThrow_statement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1358);
    match(XiasParser::THROW);
    setState(1360);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << XiasParser::BASE)
      | (1ULL << XiasParser::DEFAULT)
      | (1ULL << XiasParser::FALSE)
      | (1ULL << XiasParser::NEW)
      | (1ULL << XiasParser::NULL_)
      | (1ULL << XiasParser::THIS)
      | (1ULL << XiasParser::TRUE)
      | (1ULL << XiasParser::TYPEOF))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 72)) & ((1ULL << (XiasParser::IDENTIFIER - 72))
      | (1ULL << (XiasParser::INTEGER_LITERAL - 72))
      | (1ULL << (XiasParser::UNSIGNED_LITERAL - 72))
      | (1ULL << (XiasParser::HEX_INTEGER_LITERAL - 72))
      | (1ULL << (XiasParser::FLOAT_LITERAL - 72))
      | (1ULL << (XiasParser::DOUBLE_LITERAL - 72))
      | (1ULL << (XiasParser::CHARACTER_LITERAL - 72))
      | (1ULL << (XiasParser::REGULAR_STRING - 72))
      | (1ULL << (XiasParser::VERBATIUM_STRING - 72))
      | (1ULL << (XiasParser::OPEN_PARENS - 72))
      | (1ULL << (XiasParser::PLUS - 72))
      | (1ULL << (XiasParser::MINUS - 72))
      | (1ULL << (XiasParser::BANG - 72))
      | (1ULL << (XiasParser::TILDE - 72))
      | (1ULL << (XiasParser::OP_INC - 72))
      | (1ULL << (XiasParser::OP_DEC - 72)))) != 0)) {
      setState(1359);
      expression();
    }
    setState(1362);
    match(XiasParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Try_statementContext ------------------------------------------------------------------

XiasParser::Try_statementContext::Try_statementContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Try_statementContext::TRY() {
  return getToken(XiasParser::TRY, 0);
}

XiasParser::BlockContext* XiasParser::Try_statementContext::block() {
  return getRuleContext<XiasParser::BlockContext>(0);
}

std::vector<XiasParser::Catch_clauseContext *> XiasParser::Try_statementContext::catch_clause() {
  return getRuleContexts<XiasParser::Catch_clauseContext>();
}

XiasParser::Catch_clauseContext* XiasParser::Try_statementContext::catch_clause(size_t i) {
  return getRuleContext<XiasParser::Catch_clauseContext>(i);
}

XiasParser::Finally_clauseContext* XiasParser::Try_statementContext::finally_clause() {
  return getRuleContext<XiasParser::Finally_clauseContext>(0);
}


size_t XiasParser::Try_statementContext::getRuleIndex() const {
  return XiasParser::RuleTry_statement;
}


antlrcpp::Any XiasParser::Try_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitTry_statement(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Try_statementContext* XiasParser::try_statement() {
  Try_statementContext *_localctx = _tracker.createInstance<Try_statementContext>(_ctx, getState());
  enterRule(_localctx, 270, XiasParser::RuleTry_statement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1384);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 121, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1364);
      match(XiasParser::TRY);
      setState(1365);
      block();
      setState(1367); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(1366);
        catch_clause();
        setState(1369); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == XiasParser::CATCH);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1371);
      match(XiasParser::TRY);
      setState(1372);
      block();
      setState(1373);
      finally_clause();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1375);
      match(XiasParser::TRY);
      setState(1376);
      block();
      setState(1378); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(1377);
        catch_clause();
        setState(1380); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == XiasParser::CATCH);
      setState(1382);
      finally_clause();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Catch_clauseContext ------------------------------------------------------------------

XiasParser::Catch_clauseContext::Catch_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Catch_clauseContext::CATCH() {
  return getToken(XiasParser::CATCH, 0);
}

XiasParser::BlockContext* XiasParser::Catch_clauseContext::block() {
  return getRuleContext<XiasParser::BlockContext>(0);
}

XiasParser::Exception_specifierContext* XiasParser::Catch_clauseContext::exception_specifier() {
  return getRuleContext<XiasParser::Exception_specifierContext>(0);
}

XiasParser::Exception_filterContext* XiasParser::Catch_clauseContext::exception_filter() {
  return getRuleContext<XiasParser::Exception_filterContext>(0);
}


size_t XiasParser::Catch_clauseContext::getRuleIndex() const {
  return XiasParser::RuleCatch_clause;
}


antlrcpp::Any XiasParser::Catch_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitCatch_clause(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Catch_clauseContext* XiasParser::catch_clause() {
  Catch_clauseContext *_localctx = _tracker.createInstance<Catch_clauseContext>(_ctx, getState());
  enterRule(_localctx, 272, XiasParser::RuleCatch_clause);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1386);
    match(XiasParser::CATCH);
    setState(1388);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == XiasParser::OPEN_PARENS) {
      setState(1387);
      exception_specifier();
    }
    setState(1391);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == XiasParser::WHEN) {
      setState(1390);
      exception_filter();
    }
    setState(1393);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Exception_specifierContext ------------------------------------------------------------------

XiasParser::Exception_specifierContext::Exception_specifierContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Exception_specifierContext::OPEN_PARENS() {
  return getToken(XiasParser::OPEN_PARENS, 0);
}

XiasParser::Type_Context* XiasParser::Exception_specifierContext::type_() {
  return getRuleContext<XiasParser::Type_Context>(0);
}

tree::TerminalNode* XiasParser::Exception_specifierContext::CLOSE_PARENS() {
  return getToken(XiasParser::CLOSE_PARENS, 0);
}

XiasParser::IdentifierContext* XiasParser::Exception_specifierContext::identifier() {
  return getRuleContext<XiasParser::IdentifierContext>(0);
}


size_t XiasParser::Exception_specifierContext::getRuleIndex() const {
  return XiasParser::RuleException_specifier;
}


antlrcpp::Any XiasParser::Exception_specifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitException_specifier(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Exception_specifierContext* XiasParser::exception_specifier() {
  Exception_specifierContext *_localctx = _tracker.createInstance<Exception_specifierContext>(_ctx, getState());
  enterRule(_localctx, 274, XiasParser::RuleException_specifier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1395);
    match(XiasParser::OPEN_PARENS);
    setState(1396);
    type_();
    setState(1398);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == XiasParser::IDENTIFIER) {
      setState(1397);
      identifier();
    }
    setState(1400);
    match(XiasParser::CLOSE_PARENS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Exception_filterContext ------------------------------------------------------------------

XiasParser::Exception_filterContext::Exception_filterContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Exception_filterContext::WHEN() {
  return getToken(XiasParser::WHEN, 0);
}

tree::TerminalNode* XiasParser::Exception_filterContext::OPEN_PARENS() {
  return getToken(XiasParser::OPEN_PARENS, 0);
}

XiasParser::ExpressionContext* XiasParser::Exception_filterContext::expression() {
  return getRuleContext<XiasParser::ExpressionContext>(0);
}

tree::TerminalNode* XiasParser::Exception_filterContext::CLOSE_PARENS() {
  return getToken(XiasParser::CLOSE_PARENS, 0);
}


size_t XiasParser::Exception_filterContext::getRuleIndex() const {
  return XiasParser::RuleException_filter;
}


antlrcpp::Any XiasParser::Exception_filterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitException_filter(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Exception_filterContext* XiasParser::exception_filter() {
  Exception_filterContext *_localctx = _tracker.createInstance<Exception_filterContext>(_ctx, getState());
  enterRule(_localctx, 276, XiasParser::RuleException_filter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1402);
    match(XiasParser::WHEN);
    setState(1403);
    match(XiasParser::OPEN_PARENS);
    setState(1404);
    expression();
    setState(1405);
    match(XiasParser::CLOSE_PARENS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Finally_clauseContext ------------------------------------------------------------------

XiasParser::Finally_clauseContext::Finally_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Finally_clauseContext::FINALLY() {
  return getToken(XiasParser::FINALLY, 0);
}

XiasParser::BlockContext* XiasParser::Finally_clauseContext::block() {
  return getRuleContext<XiasParser::BlockContext>(0);
}


size_t XiasParser::Finally_clauseContext::getRuleIndex() const {
  return XiasParser::RuleFinally_clause;
}


antlrcpp::Any XiasParser::Finally_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitFinally_clause(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Finally_clauseContext* XiasParser::finally_clause() {
  Finally_clauseContext *_localctx = _tracker.createInstance<Finally_clauseContext>(_ctx, getState());
  enterRule(_localctx, 278, XiasParser::RuleFinally_clause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1407);
    match(XiasParser::FINALLY);
    setState(1408);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Argument_listContext ------------------------------------------------------------------

XiasParser::Argument_listContext::Argument_listContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

std::vector<XiasParser::ExpressionContext *> XiasParser::Argument_listContext::expression() {
  return getRuleContexts<XiasParser::ExpressionContext>();
}

XiasParser::ExpressionContext* XiasParser::Argument_listContext::expression(size_t i) {
  return getRuleContext<XiasParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> XiasParser::Argument_listContext::COMMA() {
  return getTokens(XiasParser::COMMA);
}

tree::TerminalNode* XiasParser::Argument_listContext::COMMA(size_t i) {
  return getToken(XiasParser::COMMA, i);
}


size_t XiasParser::Argument_listContext::getRuleIndex() const {
  return XiasParser::RuleArgument_list;
}


antlrcpp::Any XiasParser::Argument_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitArgument_list(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Argument_listContext* XiasParser::argument_list() {
  Argument_listContext *_localctx = _tracker.createInstance<Argument_listContext>(_ctx, getState());
  enterRule(_localctx, 280, XiasParser::RuleArgument_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1410);
    expression();
    setState(1415);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == XiasParser::COMMA) {
      setState(1411);
      match(XiasParser::COMMA);
      setState(1412);
      expression();
      setState(1417);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Primary_expressionContext ------------------------------------------------------------------

XiasParser::Primary_expressionContext::Primary_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Primary_no_array_creation_expression_baseContext* XiasParser::Primary_expressionContext::primary_no_array_creation_expression_base() {
  return getRuleContext<XiasParser::Primary_no_array_creation_expression_baseContext>(0);
}

XiasParser::Array_creation_expressionContext* XiasParser::Primary_expressionContext::array_creation_expression() {
  return getRuleContext<XiasParser::Array_creation_expressionContext>(0);
}


size_t XiasParser::Primary_expressionContext::getRuleIndex() const {
  return XiasParser::RulePrimary_expression;
}


antlrcpp::Any XiasParser::Primary_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitPrimary_expression(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Primary_expressionContext* XiasParser::primary_expression() {
  Primary_expressionContext *_localctx = _tracker.createInstance<Primary_expressionContext>(_ctx, getState());
  enterRule(_localctx, 282, XiasParser::RulePrimary_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1420);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 126, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1418);
      primary_no_array_creation_expression_base();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1419);
      array_creation_expression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Primary_no_array_creation_expression_baseContext ------------------------------------------------------------------

XiasParser::Primary_no_array_creation_expression_baseContext::Primary_no_array_creation_expression_baseContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Primary_expression_startContext* XiasParser::Primary_no_array_creation_expression_baseContext::primary_expression_start() {
  return getRuleContext<XiasParser::Primary_expression_startContext>(0);
}

XiasParser::Primary_no_array_creation_expressionContext* XiasParser::Primary_no_array_creation_expression_baseContext::primary_no_array_creation_expression() {
  return getRuleContext<XiasParser::Primary_no_array_creation_expressionContext>(0);
}


size_t XiasParser::Primary_no_array_creation_expression_baseContext::getRuleIndex() const {
  return XiasParser::RulePrimary_no_array_creation_expression_base;
}


antlrcpp::Any XiasParser::Primary_no_array_creation_expression_baseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitPrimary_no_array_creation_expression_base(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Primary_no_array_creation_expression_baseContext* XiasParser::primary_no_array_creation_expression_base() {
  Primary_no_array_creation_expression_baseContext *_localctx = _tracker.createInstance<Primary_no_array_creation_expression_baseContext>(_ctx, getState());
  enterRule(_localctx, 284, XiasParser::RulePrimary_no_array_creation_expression_base);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1422);
    primary_expression_start();
    setState(1424);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 127, _ctx)) {
    case 1: {
      setState(1423);
      primary_no_array_creation_expression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Primary_expression_startContext ------------------------------------------------------------------

XiasParser::Primary_expression_startContext::Primary_expression_startContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::LiteralContext* XiasParser::Primary_expression_startContext::literal() {
  return getRuleContext<XiasParser::LiteralContext>(0);
}

XiasParser::Simple_nameContext* XiasParser::Primary_expression_startContext::simple_name() {
  return getRuleContext<XiasParser::Simple_nameContext>(0);
}

XiasParser::Parenthesized_expressionContext* XiasParser::Primary_expression_startContext::parenthesized_expression() {
  return getRuleContext<XiasParser::Parenthesized_expressionContext>(0);
}

XiasParser::This_accessContext* XiasParser::Primary_expression_startContext::this_access() {
  return getRuleContext<XiasParser::This_accessContext>(0);
}

XiasParser::Base_accessContext* XiasParser::Primary_expression_startContext::base_access() {
  return getRuleContext<XiasParser::Base_accessContext>(0);
}

XiasParser::Object_creation_expressionContext* XiasParser::Primary_expression_startContext::object_creation_expression() {
  return getRuleContext<XiasParser::Object_creation_expressionContext>(0);
}

XiasParser::Typeof_expressionContext* XiasParser::Primary_expression_startContext::typeof_expression() {
  return getRuleContext<XiasParser::Typeof_expressionContext>(0);
}

XiasParser::Default_value_expressionContext* XiasParser::Primary_expression_startContext::default_value_expression() {
  return getRuleContext<XiasParser::Default_value_expressionContext>(0);
}


size_t XiasParser::Primary_expression_startContext::getRuleIndex() const {
  return XiasParser::RulePrimary_expression_start;
}


antlrcpp::Any XiasParser::Primary_expression_startContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitPrimary_expression_start(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Primary_expression_startContext* XiasParser::primary_expression_start() {
  Primary_expression_startContext *_localctx = _tracker.createInstance<Primary_expression_startContext>(_ctx, getState());
  enterRule(_localctx, 286, XiasParser::RulePrimary_expression_start);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1434);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case XiasParser::FALSE:
      case XiasParser::NULL_:
      case XiasParser::TRUE:
      case XiasParser::INTEGER_LITERAL:
      case XiasParser::UNSIGNED_LITERAL:
      case XiasParser::HEX_INTEGER_LITERAL:
      case XiasParser::FLOAT_LITERAL:
      case XiasParser::DOUBLE_LITERAL:
      case XiasParser::CHARACTER_LITERAL:
      case XiasParser::REGULAR_STRING:
      case XiasParser::VERBATIUM_STRING: {
        enterOuterAlt(_localctx, 1);
        setState(1426);
        literal();
        break;
      }

      case XiasParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(1427);
        simple_name();
        break;
      }

      case XiasParser::OPEN_PARENS: {
        enterOuterAlt(_localctx, 3);
        setState(1428);
        parenthesized_expression();
        break;
      }

      case XiasParser::THIS: {
        enterOuterAlt(_localctx, 4);
        setState(1429);
        this_access();
        break;
      }

      case XiasParser::BASE: {
        enterOuterAlt(_localctx, 5);
        setState(1430);
        base_access();
        break;
      }

      case XiasParser::NEW: {
        enterOuterAlt(_localctx, 6);
        setState(1431);
        object_creation_expression();
        break;
      }

      case XiasParser::TYPEOF: {
        enterOuterAlt(_localctx, 7);
        setState(1432);
        typeof_expression();
        break;
      }

      case XiasParser::DEFAULT: {
        enterOuterAlt(_localctx, 8);
        setState(1433);
        default_value_expression();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Primary_no_array_creation_expressionContext ------------------------------------------------------------------

XiasParser::Primary_no_array_creation_expressionContext::Primary_no_array_creation_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Member_accessContext* XiasParser::Primary_no_array_creation_expressionContext::member_access() {
  return getRuleContext<XiasParser::Member_accessContext>(0);
}

XiasParser::Invocation_expressionContext* XiasParser::Primary_no_array_creation_expressionContext::invocation_expression() {
  return getRuleContext<XiasParser::Invocation_expressionContext>(0);
}

XiasParser::Element_accessContext* XiasParser::Primary_no_array_creation_expressionContext::element_access() {
  return getRuleContext<XiasParser::Element_accessContext>(0);
}

XiasParser::Post_increment_expressionContext* XiasParser::Primary_no_array_creation_expressionContext::post_increment_expression() {
  return getRuleContext<XiasParser::Post_increment_expressionContext>(0);
}

XiasParser::Post_decrement_expressionContext* XiasParser::Primary_no_array_creation_expressionContext::post_decrement_expression() {
  return getRuleContext<XiasParser::Post_decrement_expressionContext>(0);
}


size_t XiasParser::Primary_no_array_creation_expressionContext::getRuleIndex() const {
  return XiasParser::RulePrimary_no_array_creation_expression;
}


antlrcpp::Any XiasParser::Primary_no_array_creation_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitPrimary_no_array_creation_expression(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Primary_no_array_creation_expressionContext* XiasParser::primary_no_array_creation_expression() {
  Primary_no_array_creation_expressionContext *_localctx = _tracker.createInstance<Primary_no_array_creation_expressionContext>(_ctx, getState());
  enterRule(_localctx, 288, XiasParser::RulePrimary_no_array_creation_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1441);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 129, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1436);
      member_access();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1437);
      invocation_expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1438);
      element_access();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1439);
      post_increment_expression();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(1440);
      post_decrement_expression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_nameContext ------------------------------------------------------------------

XiasParser::Simple_nameContext::Simple_nameContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::IdentifierContext* XiasParser::Simple_nameContext::identifier() {
  return getRuleContext<XiasParser::IdentifierContext>(0);
}

XiasParser::Type_argument_listContext* XiasParser::Simple_nameContext::type_argument_list() {
  return getRuleContext<XiasParser::Type_argument_listContext>(0);
}


size_t XiasParser::Simple_nameContext::getRuleIndex() const {
  return XiasParser::RuleSimple_name;
}


antlrcpp::Any XiasParser::Simple_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitSimple_name(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Simple_nameContext* XiasParser::simple_name() {
  Simple_nameContext *_localctx = _tracker.createInstance<Simple_nameContext>(_ctx, getState());
  enterRule(_localctx, 290, XiasParser::RuleSimple_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1443);
    identifier();
    setState(1445);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 130, _ctx)) {
    case 1: {
      setState(1444);
      type_argument_list();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parenthesized_expressionContext ------------------------------------------------------------------

XiasParser::Parenthesized_expressionContext::Parenthesized_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Parenthesized_expressionContext::OPEN_PARENS() {
  return getToken(XiasParser::OPEN_PARENS, 0);
}

XiasParser::ExpressionContext* XiasParser::Parenthesized_expressionContext::expression() {
  return getRuleContext<XiasParser::ExpressionContext>(0);
}

tree::TerminalNode* XiasParser::Parenthesized_expressionContext::CLOSE_PARENS() {
  return getToken(XiasParser::CLOSE_PARENS, 0);
}


size_t XiasParser::Parenthesized_expressionContext::getRuleIndex() const {
  return XiasParser::RuleParenthesized_expression;
}


antlrcpp::Any XiasParser::Parenthesized_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitParenthesized_expression(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Parenthesized_expressionContext* XiasParser::parenthesized_expression() {
  Parenthesized_expressionContext *_localctx = _tracker.createInstance<Parenthesized_expressionContext>(_ctx, getState());
  enterRule(_localctx, 292, XiasParser::RuleParenthesized_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1447);
    match(XiasParser::OPEN_PARENS);
    setState(1448);
    expression();
    setState(1449);
    match(XiasParser::CLOSE_PARENS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Member_accessContext ------------------------------------------------------------------

XiasParser::Member_accessContext::Member_accessContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Primary_expressionContext* XiasParser::Member_accessContext::primary_expression() {
  return getRuleContext<XiasParser::Primary_expressionContext>(0);
}

tree::TerminalNode* XiasParser::Member_accessContext::DOT() {
  return getToken(XiasParser::DOT, 0);
}

XiasParser::IdentifierContext* XiasParser::Member_accessContext::identifier() {
  return getRuleContext<XiasParser::IdentifierContext>(0);
}

XiasParser::Type_argument_listContext* XiasParser::Member_accessContext::type_argument_list() {
  return getRuleContext<XiasParser::Type_argument_listContext>(0);
}

XiasParser::Predefined_typeContext* XiasParser::Member_accessContext::predefined_type() {
  return getRuleContext<XiasParser::Predefined_typeContext>(0);
}

XiasParser::Qualified_alias_memberContext* XiasParser::Member_accessContext::qualified_alias_member() {
  return getRuleContext<XiasParser::Qualified_alias_memberContext>(0);
}


size_t XiasParser::Member_accessContext::getRuleIndex() const {
  return XiasParser::RuleMember_access;
}


antlrcpp::Any XiasParser::Member_accessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitMember_access(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Member_accessContext* XiasParser::member_access() {
  Member_accessContext *_localctx = _tracker.createInstance<Member_accessContext>(_ctx, getState());
  enterRule(_localctx, 294, XiasParser::RuleMember_access);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1467);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 133, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1451);
      primary_expression();
      setState(1452);
      match(XiasParser::DOT);
      setState(1453);
      identifier();
      setState(1455);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 131, _ctx)) {
      case 1: {
        setState(1454);
        type_argument_list();
        break;
      }

      default:
        break;
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1457);
      predefined_type();
      setState(1458);
      match(XiasParser::DOT);
      setState(1459);
      identifier();
      setState(1461);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 132, _ctx)) {
      case 1: {
        setState(1460);
        type_argument_list();
        break;
      }

      default:
        break;
      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1463);
      qualified_alias_member();
      setState(1464);
      match(XiasParser::DOT);
      setState(1465);
      identifier();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Invocation_expressionContext ------------------------------------------------------------------

XiasParser::Invocation_expressionContext::Invocation_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Primary_expressionContext* XiasParser::Invocation_expressionContext::primary_expression() {
  return getRuleContext<XiasParser::Primary_expressionContext>(0);
}

tree::TerminalNode* XiasParser::Invocation_expressionContext::OPEN_PARENS() {
  return getToken(XiasParser::OPEN_PARENS, 0);
}

tree::TerminalNode* XiasParser::Invocation_expressionContext::CLOSE_PARENS() {
  return getToken(XiasParser::CLOSE_PARENS, 0);
}

XiasParser::Argument_listContext* XiasParser::Invocation_expressionContext::argument_list() {
  return getRuleContext<XiasParser::Argument_listContext>(0);
}


size_t XiasParser::Invocation_expressionContext::getRuleIndex() const {
  return XiasParser::RuleInvocation_expression;
}


antlrcpp::Any XiasParser::Invocation_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitInvocation_expression(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Invocation_expressionContext* XiasParser::invocation_expression() {
  Invocation_expressionContext *_localctx = _tracker.createInstance<Invocation_expressionContext>(_ctx, getState());
  enterRule(_localctx, 296, XiasParser::RuleInvocation_expression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1469);
    primary_expression();
    setState(1470);
    match(XiasParser::OPEN_PARENS);
    setState(1472);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << XiasParser::BASE)
      | (1ULL << XiasParser::DEFAULT)
      | (1ULL << XiasParser::FALSE)
      | (1ULL << XiasParser::NEW)
      | (1ULL << XiasParser::NULL_)
      | (1ULL << XiasParser::THIS)
      | (1ULL << XiasParser::TRUE)
      | (1ULL << XiasParser::TYPEOF))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 72)) & ((1ULL << (XiasParser::IDENTIFIER - 72))
      | (1ULL << (XiasParser::INTEGER_LITERAL - 72))
      | (1ULL << (XiasParser::UNSIGNED_LITERAL - 72))
      | (1ULL << (XiasParser::HEX_INTEGER_LITERAL - 72))
      | (1ULL << (XiasParser::FLOAT_LITERAL - 72))
      | (1ULL << (XiasParser::DOUBLE_LITERAL - 72))
      | (1ULL << (XiasParser::CHARACTER_LITERAL - 72))
      | (1ULL << (XiasParser::REGULAR_STRING - 72))
      | (1ULL << (XiasParser::VERBATIUM_STRING - 72))
      | (1ULL << (XiasParser::OPEN_PARENS - 72))
      | (1ULL << (XiasParser::PLUS - 72))
      | (1ULL << (XiasParser::MINUS - 72))
      | (1ULL << (XiasParser::BANG - 72))
      | (1ULL << (XiasParser::TILDE - 72))
      | (1ULL << (XiasParser::OP_INC - 72))
      | (1ULL << (XiasParser::OP_DEC - 72)))) != 0)) {
      setState(1471);
      argument_list();
    }
    setState(1474);
    match(XiasParser::CLOSE_PARENS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Element_accessContext ------------------------------------------------------------------

XiasParser::Element_accessContext::Element_accessContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Primary_no_array_creation_expression_baseContext* XiasParser::Element_accessContext::primary_no_array_creation_expression_base() {
  return getRuleContext<XiasParser::Primary_no_array_creation_expression_baseContext>(0);
}

tree::TerminalNode* XiasParser::Element_accessContext::OPEN_BRACKET() {
  return getToken(XiasParser::OPEN_BRACKET, 0);
}

XiasParser::Expression_listContext* XiasParser::Element_accessContext::expression_list() {
  return getRuleContext<XiasParser::Expression_listContext>(0);
}

tree::TerminalNode* XiasParser::Element_accessContext::CLOSE_BRACKET() {
  return getToken(XiasParser::CLOSE_BRACKET, 0);
}


size_t XiasParser::Element_accessContext::getRuleIndex() const {
  return XiasParser::RuleElement_access;
}


antlrcpp::Any XiasParser::Element_accessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitElement_access(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Element_accessContext* XiasParser::element_access() {
  Element_accessContext *_localctx = _tracker.createInstance<Element_accessContext>(_ctx, getState());
  enterRule(_localctx, 298, XiasParser::RuleElement_access);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1476);
    primary_no_array_creation_expression_base();
    setState(1477);
    match(XiasParser::OPEN_BRACKET);
    setState(1478);
    expression_list();
    setState(1479);
    match(XiasParser::CLOSE_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- This_accessContext ------------------------------------------------------------------

XiasParser::This_accessContext::This_accessContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::This_accessContext::THIS() {
  return getToken(XiasParser::THIS, 0);
}


size_t XiasParser::This_accessContext::getRuleIndex() const {
  return XiasParser::RuleThis_access;
}


antlrcpp::Any XiasParser::This_accessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitThis_access(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::This_accessContext* XiasParser::this_access() {
  This_accessContext *_localctx = _tracker.createInstance<This_accessContext>(_ctx, getState());
  enterRule(_localctx, 300, XiasParser::RuleThis_access);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1481);
    match(XiasParser::THIS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Base_accessContext ------------------------------------------------------------------

XiasParser::Base_accessContext::Base_accessContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Base_accessContext::BASE() {
  return getToken(XiasParser::BASE, 0);
}

tree::TerminalNode* XiasParser::Base_accessContext::DOT() {
  return getToken(XiasParser::DOT, 0);
}

XiasParser::IdentifierContext* XiasParser::Base_accessContext::identifier() {
  return getRuleContext<XiasParser::IdentifierContext>(0);
}

tree::TerminalNode* XiasParser::Base_accessContext::OPEN_BRACKET() {
  return getToken(XiasParser::OPEN_BRACKET, 0);
}

XiasParser::Expression_listContext* XiasParser::Base_accessContext::expression_list() {
  return getRuleContext<XiasParser::Expression_listContext>(0);
}

tree::TerminalNode* XiasParser::Base_accessContext::CLOSE_BRACKET() {
  return getToken(XiasParser::CLOSE_BRACKET, 0);
}


size_t XiasParser::Base_accessContext::getRuleIndex() const {
  return XiasParser::RuleBase_access;
}


antlrcpp::Any XiasParser::Base_accessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitBase_access(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Base_accessContext* XiasParser::base_access() {
  Base_accessContext *_localctx = _tracker.createInstance<Base_accessContext>(_ctx, getState());
  enterRule(_localctx, 302, XiasParser::RuleBase_access);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1491);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 135, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1483);
      match(XiasParser::BASE);
      setState(1484);
      match(XiasParser::DOT);
      setState(1485);
      identifier();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1486);
      match(XiasParser::BASE);
      setState(1487);
      match(XiasParser::OPEN_BRACKET);
      setState(1488);
      expression_list();
      setState(1489);
      match(XiasParser::CLOSE_BRACKET);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Post_increment_expressionContext ------------------------------------------------------------------

XiasParser::Post_increment_expressionContext::Post_increment_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Primary_expressionContext* XiasParser::Post_increment_expressionContext::primary_expression() {
  return getRuleContext<XiasParser::Primary_expressionContext>(0);
}

tree::TerminalNode* XiasParser::Post_increment_expressionContext::OP_INC() {
  return getToken(XiasParser::OP_INC, 0);
}


size_t XiasParser::Post_increment_expressionContext::getRuleIndex() const {
  return XiasParser::RulePost_increment_expression;
}


antlrcpp::Any XiasParser::Post_increment_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitPost_increment_expression(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Post_increment_expressionContext* XiasParser::post_increment_expression() {
  Post_increment_expressionContext *_localctx = _tracker.createInstance<Post_increment_expressionContext>(_ctx, getState());
  enterRule(_localctx, 304, XiasParser::RulePost_increment_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1493);
    primary_expression();
    setState(1494);
    match(XiasParser::OP_INC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Post_decrement_expressionContext ------------------------------------------------------------------

XiasParser::Post_decrement_expressionContext::Post_decrement_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Primary_expressionContext* XiasParser::Post_decrement_expressionContext::primary_expression() {
  return getRuleContext<XiasParser::Primary_expressionContext>(0);
}

tree::TerminalNode* XiasParser::Post_decrement_expressionContext::OP_DEC() {
  return getToken(XiasParser::OP_DEC, 0);
}


size_t XiasParser::Post_decrement_expressionContext::getRuleIndex() const {
  return XiasParser::RulePost_decrement_expression;
}


antlrcpp::Any XiasParser::Post_decrement_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitPost_decrement_expression(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Post_decrement_expressionContext* XiasParser::post_decrement_expression() {
  Post_decrement_expressionContext *_localctx = _tracker.createInstance<Post_decrement_expressionContext>(_ctx, getState());
  enterRule(_localctx, 306, XiasParser::RulePost_decrement_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1496);
    primary_expression();
    setState(1497);
    match(XiasParser::OP_DEC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Object_creation_expressionContext ------------------------------------------------------------------

XiasParser::Object_creation_expressionContext::Object_creation_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Object_creation_expressionContext::NEW() {
  return getToken(XiasParser::NEW, 0);
}

XiasParser::Type_Context* XiasParser::Object_creation_expressionContext::type_() {
  return getRuleContext<XiasParser::Type_Context>(0);
}

tree::TerminalNode* XiasParser::Object_creation_expressionContext::OPEN_PARENS() {
  return getToken(XiasParser::OPEN_PARENS, 0);
}

tree::TerminalNode* XiasParser::Object_creation_expressionContext::CLOSE_PARENS() {
  return getToken(XiasParser::CLOSE_PARENS, 0);
}

XiasParser::Argument_listContext* XiasParser::Object_creation_expressionContext::argument_list() {
  return getRuleContext<XiasParser::Argument_listContext>(0);
}

XiasParser::Object_or_collection_initializerContext* XiasParser::Object_creation_expressionContext::object_or_collection_initializer() {
  return getRuleContext<XiasParser::Object_or_collection_initializerContext>(0);
}


size_t XiasParser::Object_creation_expressionContext::getRuleIndex() const {
  return XiasParser::RuleObject_creation_expression;
}


antlrcpp::Any XiasParser::Object_creation_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitObject_creation_expression(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Object_creation_expressionContext* XiasParser::object_creation_expression() {
  Object_creation_expressionContext *_localctx = _tracker.createInstance<Object_creation_expressionContext>(_ctx, getState());
  enterRule(_localctx, 308, XiasParser::RuleObject_creation_expression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1513);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 138, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1499);
      match(XiasParser::NEW);
      setState(1500);
      type_();
      setState(1501);
      match(XiasParser::OPEN_PARENS);
      setState(1503);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << XiasParser::BASE)
        | (1ULL << XiasParser::DEFAULT)
        | (1ULL << XiasParser::FALSE)
        | (1ULL << XiasParser::NEW)
        | (1ULL << XiasParser::NULL_)
        | (1ULL << XiasParser::THIS)
        | (1ULL << XiasParser::TRUE)
        | (1ULL << XiasParser::TYPEOF))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 72)) & ((1ULL << (XiasParser::IDENTIFIER - 72))
        | (1ULL << (XiasParser::INTEGER_LITERAL - 72))
        | (1ULL << (XiasParser::UNSIGNED_LITERAL - 72))
        | (1ULL << (XiasParser::HEX_INTEGER_LITERAL - 72))
        | (1ULL << (XiasParser::FLOAT_LITERAL - 72))
        | (1ULL << (XiasParser::DOUBLE_LITERAL - 72))
        | (1ULL << (XiasParser::CHARACTER_LITERAL - 72))
        | (1ULL << (XiasParser::REGULAR_STRING - 72))
        | (1ULL << (XiasParser::VERBATIUM_STRING - 72))
        | (1ULL << (XiasParser::OPEN_PARENS - 72))
        | (1ULL << (XiasParser::PLUS - 72))
        | (1ULL << (XiasParser::MINUS - 72))
        | (1ULL << (XiasParser::BANG - 72))
        | (1ULL << (XiasParser::TILDE - 72))
        | (1ULL << (XiasParser::OP_INC - 72))
        | (1ULL << (XiasParser::OP_DEC - 72)))) != 0)) {
        setState(1502);
        argument_list();
      }
      setState(1505);
      match(XiasParser::CLOSE_PARENS);
      setState(1507);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 137, _ctx)) {
      case 1: {
        setState(1506);
        object_or_collection_initializer();
        break;
      }

      default:
        break;
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1509);
      match(XiasParser::NEW);
      setState(1510);
      type_();
      setState(1511);
      object_or_collection_initializer();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Object_or_collection_initializerContext ------------------------------------------------------------------

XiasParser::Object_or_collection_initializerContext::Object_or_collection_initializerContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Object_initializerContext* XiasParser::Object_or_collection_initializerContext::object_initializer() {
  return getRuleContext<XiasParser::Object_initializerContext>(0);
}

XiasParser::Collection_initializerContext* XiasParser::Object_or_collection_initializerContext::collection_initializer() {
  return getRuleContext<XiasParser::Collection_initializerContext>(0);
}


size_t XiasParser::Object_or_collection_initializerContext::getRuleIndex() const {
  return XiasParser::RuleObject_or_collection_initializer;
}


antlrcpp::Any XiasParser::Object_or_collection_initializerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitObject_or_collection_initializer(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Object_or_collection_initializerContext* XiasParser::object_or_collection_initializer() {
  Object_or_collection_initializerContext *_localctx = _tracker.createInstance<Object_or_collection_initializerContext>(_ctx, getState());
  enterRule(_localctx, 310, XiasParser::RuleObject_or_collection_initializer);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1517);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 139, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1515);
      object_initializer();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1516);
      collection_initializer();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Object_initializerContext ------------------------------------------------------------------

XiasParser::Object_initializerContext::Object_initializerContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Object_initializerContext::OPEN_BRACE() {
  return getToken(XiasParser::OPEN_BRACE, 0);
}

tree::TerminalNode* XiasParser::Object_initializerContext::CLOSE_BRACE() {
  return getToken(XiasParser::CLOSE_BRACE, 0);
}

XiasParser::Member_initializer_listContext* XiasParser::Object_initializerContext::member_initializer_list() {
  return getRuleContext<XiasParser::Member_initializer_listContext>(0);
}

tree::TerminalNode* XiasParser::Object_initializerContext::COMMA() {
  return getToken(XiasParser::COMMA, 0);
}


size_t XiasParser::Object_initializerContext::getRuleIndex() const {
  return XiasParser::RuleObject_initializer;
}


antlrcpp::Any XiasParser::Object_initializerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitObject_initializer(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Object_initializerContext* XiasParser::object_initializer() {
  Object_initializerContext *_localctx = _tracker.createInstance<Object_initializerContext>(_ctx, getState());
  enterRule(_localctx, 312, XiasParser::RuleObject_initializer);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1529);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 141, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1519);
      match(XiasParser::OPEN_BRACE);
      setState(1521);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == XiasParser::IDENTIFIER) {
        setState(1520);
        member_initializer_list();
      }
      setState(1523);
      match(XiasParser::CLOSE_BRACE);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1524);
      match(XiasParser::OPEN_BRACE);
      setState(1525);
      member_initializer_list();
      setState(1526);
      match(XiasParser::COMMA);
      setState(1527);
      match(XiasParser::CLOSE_BRACE);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Member_initializer_listContext ------------------------------------------------------------------

XiasParser::Member_initializer_listContext::Member_initializer_listContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

std::vector<XiasParser::Member_initializerContext *> XiasParser::Member_initializer_listContext::member_initializer() {
  return getRuleContexts<XiasParser::Member_initializerContext>();
}

XiasParser::Member_initializerContext* XiasParser::Member_initializer_listContext::member_initializer(size_t i) {
  return getRuleContext<XiasParser::Member_initializerContext>(i);
}

std::vector<tree::TerminalNode *> XiasParser::Member_initializer_listContext::COMMA() {
  return getTokens(XiasParser::COMMA);
}

tree::TerminalNode* XiasParser::Member_initializer_listContext::COMMA(size_t i) {
  return getToken(XiasParser::COMMA, i);
}


size_t XiasParser::Member_initializer_listContext::getRuleIndex() const {
  return XiasParser::RuleMember_initializer_list;
}


antlrcpp::Any XiasParser::Member_initializer_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitMember_initializer_list(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Member_initializer_listContext* XiasParser::member_initializer_list() {
  Member_initializer_listContext *_localctx = _tracker.createInstance<Member_initializer_listContext>(_ctx, getState());
  enterRule(_localctx, 314, XiasParser::RuleMember_initializer_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1531);
    member_initializer();
    setState(1536);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 142, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1532);
        match(XiasParser::COMMA);
        setState(1533);
        member_initializer(); 
      }
      setState(1538);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 142, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Member_initializerContext ------------------------------------------------------------------

XiasParser::Member_initializerContext::Member_initializerContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::IdentifierContext* XiasParser::Member_initializerContext::identifier() {
  return getRuleContext<XiasParser::IdentifierContext>(0);
}

tree::TerminalNode* XiasParser::Member_initializerContext::ASSIGNMENT() {
  return getToken(XiasParser::ASSIGNMENT, 0);
}

XiasParser::Initializer_valueContext* XiasParser::Member_initializerContext::initializer_value() {
  return getRuleContext<XiasParser::Initializer_valueContext>(0);
}


size_t XiasParser::Member_initializerContext::getRuleIndex() const {
  return XiasParser::RuleMember_initializer;
}


antlrcpp::Any XiasParser::Member_initializerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitMember_initializer(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Member_initializerContext* XiasParser::member_initializer() {
  Member_initializerContext *_localctx = _tracker.createInstance<Member_initializerContext>(_ctx, getState());
  enterRule(_localctx, 316, XiasParser::RuleMember_initializer);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1539);
    identifier();
    setState(1540);
    match(XiasParser::ASSIGNMENT);
    setState(1541);
    initializer_value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Initializer_valueContext ------------------------------------------------------------------

XiasParser::Initializer_valueContext::Initializer_valueContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::ExpressionContext* XiasParser::Initializer_valueContext::expression() {
  return getRuleContext<XiasParser::ExpressionContext>(0);
}

XiasParser::Object_or_collection_initializerContext* XiasParser::Initializer_valueContext::object_or_collection_initializer() {
  return getRuleContext<XiasParser::Object_or_collection_initializerContext>(0);
}


size_t XiasParser::Initializer_valueContext::getRuleIndex() const {
  return XiasParser::RuleInitializer_value;
}


antlrcpp::Any XiasParser::Initializer_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitInitializer_value(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Initializer_valueContext* XiasParser::initializer_value() {
  Initializer_valueContext *_localctx = _tracker.createInstance<Initializer_valueContext>(_ctx, getState());
  enterRule(_localctx, 318, XiasParser::RuleInitializer_value);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1545);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case XiasParser::BASE:
      case XiasParser::DEFAULT:
      case XiasParser::FALSE:
      case XiasParser::NEW:
      case XiasParser::NULL_:
      case XiasParser::THIS:
      case XiasParser::TRUE:
      case XiasParser::TYPEOF:
      case XiasParser::IDENTIFIER:
      case XiasParser::INTEGER_LITERAL:
      case XiasParser::UNSIGNED_LITERAL:
      case XiasParser::HEX_INTEGER_LITERAL:
      case XiasParser::FLOAT_LITERAL:
      case XiasParser::DOUBLE_LITERAL:
      case XiasParser::CHARACTER_LITERAL:
      case XiasParser::REGULAR_STRING:
      case XiasParser::VERBATIUM_STRING:
      case XiasParser::OPEN_PARENS:
      case XiasParser::PLUS:
      case XiasParser::MINUS:
      case XiasParser::BANG:
      case XiasParser::TILDE:
      case XiasParser::OP_INC:
      case XiasParser::OP_DEC: {
        enterOuterAlt(_localctx, 1);
        setState(1543);
        expression();
        break;
      }

      case XiasParser::OPEN_BRACE: {
        enterOuterAlt(_localctx, 2);
        setState(1544);
        object_or_collection_initializer();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Collection_initializerContext ------------------------------------------------------------------

XiasParser::Collection_initializerContext::Collection_initializerContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Collection_initializerContext::OPEN_BRACE() {
  return getToken(XiasParser::OPEN_BRACE, 0);
}

XiasParser::Element_initializer_listContext* XiasParser::Collection_initializerContext::element_initializer_list() {
  return getRuleContext<XiasParser::Element_initializer_listContext>(0);
}

tree::TerminalNode* XiasParser::Collection_initializerContext::CLOSE_BRACE() {
  return getToken(XiasParser::CLOSE_BRACE, 0);
}

tree::TerminalNode* XiasParser::Collection_initializerContext::COMMA() {
  return getToken(XiasParser::COMMA, 0);
}


size_t XiasParser::Collection_initializerContext::getRuleIndex() const {
  return XiasParser::RuleCollection_initializer;
}


antlrcpp::Any XiasParser::Collection_initializerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitCollection_initializer(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Collection_initializerContext* XiasParser::collection_initializer() {
  Collection_initializerContext *_localctx = _tracker.createInstance<Collection_initializerContext>(_ctx, getState());
  enterRule(_localctx, 320, XiasParser::RuleCollection_initializer);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1556);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 144, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1547);
      match(XiasParser::OPEN_BRACE);
      setState(1548);
      element_initializer_list();
      setState(1549);
      match(XiasParser::CLOSE_BRACE);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1551);
      match(XiasParser::OPEN_BRACE);
      setState(1552);
      element_initializer_list();
      setState(1553);
      match(XiasParser::COMMA);
      setState(1554);
      match(XiasParser::CLOSE_BRACE);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Element_initializer_listContext ------------------------------------------------------------------

XiasParser::Element_initializer_listContext::Element_initializer_listContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

std::vector<XiasParser::Element_initializerContext *> XiasParser::Element_initializer_listContext::element_initializer() {
  return getRuleContexts<XiasParser::Element_initializerContext>();
}

XiasParser::Element_initializerContext* XiasParser::Element_initializer_listContext::element_initializer(size_t i) {
  return getRuleContext<XiasParser::Element_initializerContext>(i);
}

std::vector<tree::TerminalNode *> XiasParser::Element_initializer_listContext::COMMA() {
  return getTokens(XiasParser::COMMA);
}

tree::TerminalNode* XiasParser::Element_initializer_listContext::COMMA(size_t i) {
  return getToken(XiasParser::COMMA, i);
}


size_t XiasParser::Element_initializer_listContext::getRuleIndex() const {
  return XiasParser::RuleElement_initializer_list;
}


antlrcpp::Any XiasParser::Element_initializer_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitElement_initializer_list(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Element_initializer_listContext* XiasParser::element_initializer_list() {
  Element_initializer_listContext *_localctx = _tracker.createInstance<Element_initializer_listContext>(_ctx, getState());
  enterRule(_localctx, 322, XiasParser::RuleElement_initializer_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1558);
    element_initializer();
    setState(1563);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 145, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1559);
        match(XiasParser::COMMA);
        setState(1560);
        element_initializer(); 
      }
      setState(1565);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 145, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Element_initializerContext ------------------------------------------------------------------

XiasParser::Element_initializerContext::Element_initializerContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Non_assignment_expressionContext* XiasParser::Element_initializerContext::non_assignment_expression() {
  return getRuleContext<XiasParser::Non_assignment_expressionContext>(0);
}

tree::TerminalNode* XiasParser::Element_initializerContext::OPEN_BRACE() {
  return getToken(XiasParser::OPEN_BRACE, 0);
}

XiasParser::Expression_listContext* XiasParser::Element_initializerContext::expression_list() {
  return getRuleContext<XiasParser::Expression_listContext>(0);
}

tree::TerminalNode* XiasParser::Element_initializerContext::CLOSE_BRACE() {
  return getToken(XiasParser::CLOSE_BRACE, 0);
}


size_t XiasParser::Element_initializerContext::getRuleIndex() const {
  return XiasParser::RuleElement_initializer;
}


antlrcpp::Any XiasParser::Element_initializerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitElement_initializer(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Element_initializerContext* XiasParser::element_initializer() {
  Element_initializerContext *_localctx = _tracker.createInstance<Element_initializerContext>(_ctx, getState());
  enterRule(_localctx, 324, XiasParser::RuleElement_initializer);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1571);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case XiasParser::BASE:
      case XiasParser::DEFAULT:
      case XiasParser::FALSE:
      case XiasParser::NEW:
      case XiasParser::NULL_:
      case XiasParser::THIS:
      case XiasParser::TRUE:
      case XiasParser::TYPEOF:
      case XiasParser::IDENTIFIER:
      case XiasParser::INTEGER_LITERAL:
      case XiasParser::UNSIGNED_LITERAL:
      case XiasParser::HEX_INTEGER_LITERAL:
      case XiasParser::FLOAT_LITERAL:
      case XiasParser::DOUBLE_LITERAL:
      case XiasParser::CHARACTER_LITERAL:
      case XiasParser::REGULAR_STRING:
      case XiasParser::VERBATIUM_STRING:
      case XiasParser::OPEN_PARENS:
      case XiasParser::PLUS:
      case XiasParser::MINUS:
      case XiasParser::BANG:
      case XiasParser::TILDE:
      case XiasParser::OP_INC:
      case XiasParser::OP_DEC: {
        enterOuterAlt(_localctx, 1);
        setState(1566);
        non_assignment_expression();
        break;
      }

      case XiasParser::OPEN_BRACE: {
        enterOuterAlt(_localctx, 2);
        setState(1567);
        match(XiasParser::OPEN_BRACE);
        setState(1568);
        expression_list();
        setState(1569);
        match(XiasParser::CLOSE_BRACE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_listContext ------------------------------------------------------------------

XiasParser::Expression_listContext::Expression_listContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

std::vector<XiasParser::ExpressionContext *> XiasParser::Expression_listContext::expression() {
  return getRuleContexts<XiasParser::ExpressionContext>();
}

XiasParser::ExpressionContext* XiasParser::Expression_listContext::expression(size_t i) {
  return getRuleContext<XiasParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> XiasParser::Expression_listContext::COMMA() {
  return getTokens(XiasParser::COMMA);
}

tree::TerminalNode* XiasParser::Expression_listContext::COMMA(size_t i) {
  return getToken(XiasParser::COMMA, i);
}


size_t XiasParser::Expression_listContext::getRuleIndex() const {
  return XiasParser::RuleExpression_list;
}


antlrcpp::Any XiasParser::Expression_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitExpression_list(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Expression_listContext* XiasParser::expression_list() {
  Expression_listContext *_localctx = _tracker.createInstance<Expression_listContext>(_ctx, getState());
  enterRule(_localctx, 326, XiasParser::RuleExpression_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1573);
    expression();
    setState(1578);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == XiasParser::COMMA) {
      setState(1574);
      match(XiasParser::COMMA);
      setState(1575);
      expression();
      setState(1580);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Typeof_expressionContext ------------------------------------------------------------------

XiasParser::Typeof_expressionContext::Typeof_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Typeof_expressionContext::TYPEOF() {
  return getToken(XiasParser::TYPEOF, 0);
}

tree::TerminalNode* XiasParser::Typeof_expressionContext::OPEN_PARENS() {
  return getToken(XiasParser::OPEN_PARENS, 0);
}

XiasParser::Type_Context* XiasParser::Typeof_expressionContext::type_() {
  return getRuleContext<XiasParser::Type_Context>(0);
}

tree::TerminalNode* XiasParser::Typeof_expressionContext::CLOSE_PARENS() {
  return getToken(XiasParser::CLOSE_PARENS, 0);
}

XiasParser::Unbound_type_nameContext* XiasParser::Typeof_expressionContext::unbound_type_name() {
  return getRuleContext<XiasParser::Unbound_type_nameContext>(0);
}

tree::TerminalNode* XiasParser::Typeof_expressionContext::VOID() {
  return getToken(XiasParser::VOID, 0);
}


size_t XiasParser::Typeof_expressionContext::getRuleIndex() const {
  return XiasParser::RuleTypeof_expression;
}


antlrcpp::Any XiasParser::Typeof_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitTypeof_expression(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Typeof_expressionContext* XiasParser::typeof_expression() {
  Typeof_expressionContext *_localctx = _tracker.createInstance<Typeof_expressionContext>(_ctx, getState());
  enterRule(_localctx, 328, XiasParser::RuleTypeof_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1595);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 148, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1581);
      match(XiasParser::TYPEOF);
      setState(1582);
      match(XiasParser::OPEN_PARENS);
      setState(1583);
      type_();
      setState(1584);
      match(XiasParser::CLOSE_PARENS);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1586);
      match(XiasParser::TYPEOF);
      setState(1587);
      match(XiasParser::OPEN_PARENS);
      setState(1588);
      unbound_type_name(0);
      setState(1589);
      match(XiasParser::CLOSE_PARENS);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1591);
      match(XiasParser::TYPEOF);
      setState(1592);
      match(XiasParser::OPEN_PARENS);
      setState(1593);
      match(XiasParser::VOID);
      setState(1594);
      match(XiasParser::CLOSE_PARENS);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unbound_type_nameContext ------------------------------------------------------------------

XiasParser::Unbound_type_nameContext::Unbound_type_nameContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

std::vector<XiasParser::IdentifierContext *> XiasParser::Unbound_type_nameContext::identifier() {
  return getRuleContexts<XiasParser::IdentifierContext>();
}

XiasParser::IdentifierContext* XiasParser::Unbound_type_nameContext::identifier(size_t i) {
  return getRuleContext<XiasParser::IdentifierContext>(i);
}

XiasParser::Generic_dimension_specifierContext* XiasParser::Unbound_type_nameContext::generic_dimension_specifier() {
  return getRuleContext<XiasParser::Generic_dimension_specifierContext>(0);
}

tree::TerminalNode* XiasParser::Unbound_type_nameContext::DOUBLE_COLON() {
  return getToken(XiasParser::DOUBLE_COLON, 0);
}

XiasParser::Unbound_type_nameContext* XiasParser::Unbound_type_nameContext::unbound_type_name() {
  return getRuleContext<XiasParser::Unbound_type_nameContext>(0);
}

tree::TerminalNode* XiasParser::Unbound_type_nameContext::DOT() {
  return getToken(XiasParser::DOT, 0);
}


size_t XiasParser::Unbound_type_nameContext::getRuleIndex() const {
  return XiasParser::RuleUnbound_type_name;
}


antlrcpp::Any XiasParser::Unbound_type_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitUnbound_type_name(this);
  else
    return visitor->visitChildren(this);
}


XiasParser::Unbound_type_nameContext* XiasParser::unbound_type_name() {
   return unbound_type_name(0);
}

XiasParser::Unbound_type_nameContext* XiasParser::unbound_type_name(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  XiasParser::Unbound_type_nameContext *_localctx = _tracker.createInstance<Unbound_type_nameContext>(_ctx, parentState);
  XiasParser::Unbound_type_nameContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 330;
  enterRecursionRule(_localctx, 330, XiasParser::RuleUnbound_type_name, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1608);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 151, _ctx)) {
    case 1: {
      setState(1598);
      identifier();
      setState(1600);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 149, _ctx)) {
      case 1: {
        setState(1599);
        generic_dimension_specifier();
        break;
      }

      default:
        break;
      }
      break;
    }

    case 2: {
      setState(1602);
      identifier();
      setState(1603);
      match(XiasParser::DOUBLE_COLON);
      setState(1604);
      identifier();
      setState(1606);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 150, _ctx)) {
      case 1: {
        setState(1605);
        generic_dimension_specifier();
        break;
      }

      default:
        break;
      }
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(1618);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 153, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Unbound_type_nameContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleUnbound_type_name);
        setState(1610);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1611);
        match(XiasParser::DOT);
        setState(1612);
        identifier();
        setState(1614);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 152, _ctx)) {
        case 1: {
          setState(1613);
          generic_dimension_specifier();
          break;
        }

        default:
          break;
        } 
      }
      setState(1620);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 153, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Generic_dimension_specifierContext ------------------------------------------------------------------

XiasParser::Generic_dimension_specifierContext::Generic_dimension_specifierContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Generic_dimension_specifierContext::LT() {
  return getToken(XiasParser::LT, 0);
}

tree::TerminalNode* XiasParser::Generic_dimension_specifierContext::GT() {
  return getToken(XiasParser::GT, 0);
}

std::vector<tree::TerminalNode *> XiasParser::Generic_dimension_specifierContext::COMMA() {
  return getTokens(XiasParser::COMMA);
}

tree::TerminalNode* XiasParser::Generic_dimension_specifierContext::COMMA(size_t i) {
  return getToken(XiasParser::COMMA, i);
}


size_t XiasParser::Generic_dimension_specifierContext::getRuleIndex() const {
  return XiasParser::RuleGeneric_dimension_specifier;
}


antlrcpp::Any XiasParser::Generic_dimension_specifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitGeneric_dimension_specifier(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Generic_dimension_specifierContext* XiasParser::generic_dimension_specifier() {
  Generic_dimension_specifierContext *_localctx = _tracker.createInstance<Generic_dimension_specifierContext>(_ctx, getState());
  enterRule(_localctx, 332, XiasParser::RuleGeneric_dimension_specifier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1621);
    match(XiasParser::LT);
    setState(1625);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == XiasParser::COMMA) {
      setState(1622);
      match(XiasParser::COMMA);
      setState(1627);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1628);
    match(XiasParser::GT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Default_value_expressionContext ------------------------------------------------------------------

XiasParser::Default_value_expressionContext::Default_value_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Default_value_expressionContext::DEFAULT() {
  return getToken(XiasParser::DEFAULT, 0);
}

tree::TerminalNode* XiasParser::Default_value_expressionContext::OPEN_PARENS() {
  return getToken(XiasParser::OPEN_PARENS, 0);
}

XiasParser::Type_Context* XiasParser::Default_value_expressionContext::type_() {
  return getRuleContext<XiasParser::Type_Context>(0);
}

tree::TerminalNode* XiasParser::Default_value_expressionContext::CLOSE_PARENS() {
  return getToken(XiasParser::CLOSE_PARENS, 0);
}


size_t XiasParser::Default_value_expressionContext::getRuleIndex() const {
  return XiasParser::RuleDefault_value_expression;
}


antlrcpp::Any XiasParser::Default_value_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitDefault_value_expression(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Default_value_expressionContext* XiasParser::default_value_expression() {
  Default_value_expressionContext *_localctx = _tracker.createInstance<Default_value_expressionContext>(_ctx, getState());
  enterRule(_localctx, 334, XiasParser::RuleDefault_value_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1630);
    match(XiasParser::DEFAULT);
    setState(1631);
    match(XiasParser::OPEN_PARENS);
    setState(1632);
    type_();
    setState(1633);
    match(XiasParser::CLOSE_PARENS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Array_creation_expressionContext ------------------------------------------------------------------

XiasParser::Array_creation_expressionContext::Array_creation_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}


size_t XiasParser::Array_creation_expressionContext::getRuleIndex() const {
  return XiasParser::RuleArray_creation_expression;
}

void XiasParser::Array_creation_expressionContext::copyFrom(Array_creation_expressionContext *ctx) {
  antlr4::RuleContextWithAltNum::copyFrom(ctx);
}

//----------------- ArrayCreationWithExpressionSizeContext ------------------------------------------------------------------

tree::TerminalNode* XiasParser::ArrayCreationWithExpressionSizeContext::NEW() {
  return getToken(XiasParser::NEW, 0);
}

XiasParser::Non_array_typeContext* XiasParser::ArrayCreationWithExpressionSizeContext::non_array_type() {
  return getRuleContext<XiasParser::Non_array_typeContext>(0);
}

tree::TerminalNode* XiasParser::ArrayCreationWithExpressionSizeContext::OPEN_BRACKET() {
  return getToken(XiasParser::OPEN_BRACKET, 0);
}

XiasParser::Expression_listContext* XiasParser::ArrayCreationWithExpressionSizeContext::expression_list() {
  return getRuleContext<XiasParser::Expression_listContext>(0);
}

tree::TerminalNode* XiasParser::ArrayCreationWithExpressionSizeContext::CLOSE_BRACKET() {
  return getToken(XiasParser::CLOSE_BRACKET, 0);
}

std::vector<XiasParser::Rank_specifierContext *> XiasParser::ArrayCreationWithExpressionSizeContext::rank_specifier() {
  return getRuleContexts<XiasParser::Rank_specifierContext>();
}

XiasParser::Rank_specifierContext* XiasParser::ArrayCreationWithExpressionSizeContext::rank_specifier(size_t i) {
  return getRuleContext<XiasParser::Rank_specifierContext>(i);
}

XiasParser::Array_initializerContext* XiasParser::ArrayCreationWithExpressionSizeContext::array_initializer() {
  return getRuleContext<XiasParser::Array_initializerContext>(0);
}

XiasParser::ArrayCreationWithExpressionSizeContext::ArrayCreationWithExpressionSizeContext(Array_creation_expressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any XiasParser::ArrayCreationWithExpressionSizeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitArrayCreationWithExpressionSize(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayCreationWithInitializerContext ------------------------------------------------------------------

tree::TerminalNode* XiasParser::ArrayCreationWithInitializerContext::NEW() {
  return getToken(XiasParser::NEW, 0);
}

XiasParser::Array_typeContext* XiasParser::ArrayCreationWithInitializerContext::array_type() {
  return getRuleContext<XiasParser::Array_typeContext>(0);
}

XiasParser::Array_initializerContext* XiasParser::ArrayCreationWithInitializerContext::array_initializer() {
  return getRuleContext<XiasParser::Array_initializerContext>(0);
}

XiasParser::ArrayCreationWithInitializerContext::ArrayCreationWithInitializerContext(Array_creation_expressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any XiasParser::ArrayCreationWithInitializerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitArrayCreationWithInitializer(this);
  else
    return visitor->visitChildren(this);
}
XiasParser::Array_creation_expressionContext* XiasParser::array_creation_expression() {
  Array_creation_expressionContext *_localctx = _tracker.createInstance<Array_creation_expressionContext>(_ctx, getState());
  enterRule(_localctx, 336, XiasParser::RuleArray_creation_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(1653);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 157, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<Array_creation_expressionContext *>(_tracker.createInstance<XiasParser::ArrayCreationWithExpressionSizeContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(1635);
      match(XiasParser::NEW);
      setState(1636);
      non_array_type();
      setState(1637);
      match(XiasParser::OPEN_BRACKET);
      setState(1638);
      expression_list();
      setState(1639);
      match(XiasParser::CLOSE_BRACKET);
      setState(1643);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 155, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(1640);
          rank_specifier(); 
        }
        setState(1645);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 155, _ctx);
      }
      setState(1647);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 156, _ctx)) {
      case 1: {
        setState(1646);
        array_initializer();
        break;
      }

      default:
        break;
      }
      break;
    }

    case 2: {
      _localctx = dynamic_cast<Array_creation_expressionContext *>(_tracker.createInstance<XiasParser::ArrayCreationWithInitializerContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(1649);
      match(XiasParser::NEW);
      setState(1650);
      array_type();
      setState(1651);
      array_initializer();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unary_expressionContext ------------------------------------------------------------------

XiasParser::Unary_expressionContext::Unary_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Primary_expressionContext* XiasParser::Unary_expressionContext::primary_expression() {
  return getRuleContext<XiasParser::Primary_expressionContext>(0);
}

XiasParser::Unary_plus_expressionContext* XiasParser::Unary_expressionContext::unary_plus_expression() {
  return getRuleContext<XiasParser::Unary_plus_expressionContext>(0);
}

XiasParser::Unary_minus_expressionContext* XiasParser::Unary_expressionContext::unary_minus_expression() {
  return getRuleContext<XiasParser::Unary_minus_expressionContext>(0);
}

XiasParser::Unary_bang_expressionContext* XiasParser::Unary_expressionContext::unary_bang_expression() {
  return getRuleContext<XiasParser::Unary_bang_expressionContext>(0);
}

XiasParser::Unary_tilde_expressionContext* XiasParser::Unary_expressionContext::unary_tilde_expression() {
  return getRuleContext<XiasParser::Unary_tilde_expressionContext>(0);
}

XiasParser::Pre_increment_expressionContext* XiasParser::Unary_expressionContext::pre_increment_expression() {
  return getRuleContext<XiasParser::Pre_increment_expressionContext>(0);
}

XiasParser::Pre_decrement_expressionContext* XiasParser::Unary_expressionContext::pre_decrement_expression() {
  return getRuleContext<XiasParser::Pre_decrement_expressionContext>(0);
}

XiasParser::Cast_expressionContext* XiasParser::Unary_expressionContext::cast_expression() {
  return getRuleContext<XiasParser::Cast_expressionContext>(0);
}


size_t XiasParser::Unary_expressionContext::getRuleIndex() const {
  return XiasParser::RuleUnary_expression;
}


antlrcpp::Any XiasParser::Unary_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitUnary_expression(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Unary_expressionContext* XiasParser::unary_expression() {
  Unary_expressionContext *_localctx = _tracker.createInstance<Unary_expressionContext>(_ctx, getState());
  enterRule(_localctx, 338, XiasParser::RuleUnary_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1663);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 158, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1655);
      primary_expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1656);
      unary_plus_expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1657);
      unary_minus_expression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1658);
      unary_bang_expression();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(1659);
      unary_tilde_expression();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(1660);
      pre_increment_expression();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(1661);
      pre_decrement_expression();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(1662);
      cast_expression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unary_plus_expressionContext ------------------------------------------------------------------

XiasParser::Unary_plus_expressionContext::Unary_plus_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Unary_plus_expressionContext::PLUS() {
  return getToken(XiasParser::PLUS, 0);
}

XiasParser::Unary_expressionContext* XiasParser::Unary_plus_expressionContext::unary_expression() {
  return getRuleContext<XiasParser::Unary_expressionContext>(0);
}


size_t XiasParser::Unary_plus_expressionContext::getRuleIndex() const {
  return XiasParser::RuleUnary_plus_expression;
}


antlrcpp::Any XiasParser::Unary_plus_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitUnary_plus_expression(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Unary_plus_expressionContext* XiasParser::unary_plus_expression() {
  Unary_plus_expressionContext *_localctx = _tracker.createInstance<Unary_plus_expressionContext>(_ctx, getState());
  enterRule(_localctx, 340, XiasParser::RuleUnary_plus_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1665);
    match(XiasParser::PLUS);
    setState(1666);
    unary_expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unary_minus_expressionContext ------------------------------------------------------------------

XiasParser::Unary_minus_expressionContext::Unary_minus_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Unary_minus_expressionContext::MINUS() {
  return getToken(XiasParser::MINUS, 0);
}

XiasParser::Unary_expressionContext* XiasParser::Unary_minus_expressionContext::unary_expression() {
  return getRuleContext<XiasParser::Unary_expressionContext>(0);
}


size_t XiasParser::Unary_minus_expressionContext::getRuleIndex() const {
  return XiasParser::RuleUnary_minus_expression;
}


antlrcpp::Any XiasParser::Unary_minus_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitUnary_minus_expression(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Unary_minus_expressionContext* XiasParser::unary_minus_expression() {
  Unary_minus_expressionContext *_localctx = _tracker.createInstance<Unary_minus_expressionContext>(_ctx, getState());
  enterRule(_localctx, 342, XiasParser::RuleUnary_minus_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1668);
    match(XiasParser::MINUS);
    setState(1669);
    unary_expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unary_bang_expressionContext ------------------------------------------------------------------

XiasParser::Unary_bang_expressionContext::Unary_bang_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Unary_bang_expressionContext::BANG() {
  return getToken(XiasParser::BANG, 0);
}

XiasParser::Unary_expressionContext* XiasParser::Unary_bang_expressionContext::unary_expression() {
  return getRuleContext<XiasParser::Unary_expressionContext>(0);
}


size_t XiasParser::Unary_bang_expressionContext::getRuleIndex() const {
  return XiasParser::RuleUnary_bang_expression;
}


antlrcpp::Any XiasParser::Unary_bang_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitUnary_bang_expression(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Unary_bang_expressionContext* XiasParser::unary_bang_expression() {
  Unary_bang_expressionContext *_localctx = _tracker.createInstance<Unary_bang_expressionContext>(_ctx, getState());
  enterRule(_localctx, 344, XiasParser::RuleUnary_bang_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1671);
    match(XiasParser::BANG);
    setState(1672);
    unary_expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unary_tilde_expressionContext ------------------------------------------------------------------

XiasParser::Unary_tilde_expressionContext::Unary_tilde_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Unary_tilde_expressionContext::TILDE() {
  return getToken(XiasParser::TILDE, 0);
}

XiasParser::Unary_expressionContext* XiasParser::Unary_tilde_expressionContext::unary_expression() {
  return getRuleContext<XiasParser::Unary_expressionContext>(0);
}


size_t XiasParser::Unary_tilde_expressionContext::getRuleIndex() const {
  return XiasParser::RuleUnary_tilde_expression;
}


antlrcpp::Any XiasParser::Unary_tilde_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitUnary_tilde_expression(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Unary_tilde_expressionContext* XiasParser::unary_tilde_expression() {
  Unary_tilde_expressionContext *_localctx = _tracker.createInstance<Unary_tilde_expressionContext>(_ctx, getState());
  enterRule(_localctx, 346, XiasParser::RuleUnary_tilde_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1674);
    match(XiasParser::TILDE);
    setState(1675);
    unary_expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Pre_increment_expressionContext ------------------------------------------------------------------

XiasParser::Pre_increment_expressionContext::Pre_increment_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Pre_increment_expressionContext::OP_INC() {
  return getToken(XiasParser::OP_INC, 0);
}

XiasParser::Unary_expressionContext* XiasParser::Pre_increment_expressionContext::unary_expression() {
  return getRuleContext<XiasParser::Unary_expressionContext>(0);
}


size_t XiasParser::Pre_increment_expressionContext::getRuleIndex() const {
  return XiasParser::RulePre_increment_expression;
}


antlrcpp::Any XiasParser::Pre_increment_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitPre_increment_expression(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Pre_increment_expressionContext* XiasParser::pre_increment_expression() {
  Pre_increment_expressionContext *_localctx = _tracker.createInstance<Pre_increment_expressionContext>(_ctx, getState());
  enterRule(_localctx, 348, XiasParser::RulePre_increment_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1677);
    match(XiasParser::OP_INC);
    setState(1678);
    unary_expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Pre_decrement_expressionContext ------------------------------------------------------------------

XiasParser::Pre_decrement_expressionContext::Pre_decrement_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Pre_decrement_expressionContext::OP_DEC() {
  return getToken(XiasParser::OP_DEC, 0);
}

XiasParser::Unary_expressionContext* XiasParser::Pre_decrement_expressionContext::unary_expression() {
  return getRuleContext<XiasParser::Unary_expressionContext>(0);
}


size_t XiasParser::Pre_decrement_expressionContext::getRuleIndex() const {
  return XiasParser::RulePre_decrement_expression;
}


antlrcpp::Any XiasParser::Pre_decrement_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitPre_decrement_expression(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Pre_decrement_expressionContext* XiasParser::pre_decrement_expression() {
  Pre_decrement_expressionContext *_localctx = _tracker.createInstance<Pre_decrement_expressionContext>(_ctx, getState());
  enterRule(_localctx, 350, XiasParser::RulePre_decrement_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1680);
    match(XiasParser::OP_DEC);
    setState(1681);
    unary_expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Cast_expressionContext ------------------------------------------------------------------

XiasParser::Cast_expressionContext::Cast_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Cast_expressionContext::OPEN_PARENS() {
  return getToken(XiasParser::OPEN_PARENS, 0);
}

XiasParser::Type_Context* XiasParser::Cast_expressionContext::type_() {
  return getRuleContext<XiasParser::Type_Context>(0);
}

tree::TerminalNode* XiasParser::Cast_expressionContext::CLOSE_PARENS() {
  return getToken(XiasParser::CLOSE_PARENS, 0);
}

XiasParser::Unary_expressionContext* XiasParser::Cast_expressionContext::unary_expression() {
  return getRuleContext<XiasParser::Unary_expressionContext>(0);
}


size_t XiasParser::Cast_expressionContext::getRuleIndex() const {
  return XiasParser::RuleCast_expression;
}


antlrcpp::Any XiasParser::Cast_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitCast_expression(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Cast_expressionContext* XiasParser::cast_expression() {
  Cast_expressionContext *_localctx = _tracker.createInstance<Cast_expressionContext>(_ctx, getState());
  enterRule(_localctx, 352, XiasParser::RuleCast_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1683);
    match(XiasParser::OPEN_PARENS);
    setState(1684);
    type_();
    setState(1685);
    match(XiasParser::CLOSE_PARENS);
    setState(1686);
    unary_expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Multiplicative_expressionContext ------------------------------------------------------------------

XiasParser::Multiplicative_expressionContext::Multiplicative_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Unary_expressionContext* XiasParser::Multiplicative_expressionContext::unary_expression() {
  return getRuleContext<XiasParser::Unary_expressionContext>(0);
}

XiasParser::Multiplicative_expressionContext* XiasParser::Multiplicative_expressionContext::multiplicative_expression() {
  return getRuleContext<XiasParser::Multiplicative_expressionContext>(0);
}

tree::TerminalNode* XiasParser::Multiplicative_expressionContext::STAR() {
  return getToken(XiasParser::STAR, 0);
}

tree::TerminalNode* XiasParser::Multiplicative_expressionContext::DIV() {
  return getToken(XiasParser::DIV, 0);
}

tree::TerminalNode* XiasParser::Multiplicative_expressionContext::PERCENT() {
  return getToken(XiasParser::PERCENT, 0);
}


size_t XiasParser::Multiplicative_expressionContext::getRuleIndex() const {
  return XiasParser::RuleMultiplicative_expression;
}


antlrcpp::Any XiasParser::Multiplicative_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitMultiplicative_expression(this);
  else
    return visitor->visitChildren(this);
}


XiasParser::Multiplicative_expressionContext* XiasParser::multiplicative_expression() {
   return multiplicative_expression(0);
}

XiasParser::Multiplicative_expressionContext* XiasParser::multiplicative_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  XiasParser::Multiplicative_expressionContext *_localctx = _tracker.createInstance<Multiplicative_expressionContext>(_ctx, parentState);
  XiasParser::Multiplicative_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 354;
  enterRecursionRule(_localctx, 354, XiasParser::RuleMultiplicative_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1689);
    unary_expression();
    _ctx->stop = _input->LT(-1);
    setState(1702);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 160, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(1700);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 159, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Multiplicative_expressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicative_expression);
          setState(1691);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(1692);
          match(XiasParser::STAR);
          setState(1693);
          unary_expression();
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Multiplicative_expressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicative_expression);
          setState(1694);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(1695);
          match(XiasParser::DIV);
          setState(1696);
          unary_expression();
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<Multiplicative_expressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicative_expression);
          setState(1697);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(1698);
          match(XiasParser::PERCENT);
          setState(1699);
          unary_expression();
          break;
        }

        default:
          break;
        } 
      }
      setState(1704);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 160, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Additive_expressionContext ------------------------------------------------------------------

XiasParser::Additive_expressionContext::Additive_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Multiplicative_expressionContext* XiasParser::Additive_expressionContext::multiplicative_expression() {
  return getRuleContext<XiasParser::Multiplicative_expressionContext>(0);
}

XiasParser::Additive_expressionContext* XiasParser::Additive_expressionContext::additive_expression() {
  return getRuleContext<XiasParser::Additive_expressionContext>(0);
}

tree::TerminalNode* XiasParser::Additive_expressionContext::PLUS() {
  return getToken(XiasParser::PLUS, 0);
}

tree::TerminalNode* XiasParser::Additive_expressionContext::MINUS() {
  return getToken(XiasParser::MINUS, 0);
}


size_t XiasParser::Additive_expressionContext::getRuleIndex() const {
  return XiasParser::RuleAdditive_expression;
}


antlrcpp::Any XiasParser::Additive_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitAdditive_expression(this);
  else
    return visitor->visitChildren(this);
}


XiasParser::Additive_expressionContext* XiasParser::additive_expression() {
   return additive_expression(0);
}

XiasParser::Additive_expressionContext* XiasParser::additive_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  XiasParser::Additive_expressionContext *_localctx = _tracker.createInstance<Additive_expressionContext>(_ctx, parentState);
  XiasParser::Additive_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 356;
  enterRecursionRule(_localctx, 356, XiasParser::RuleAdditive_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1706);
    multiplicative_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(1716);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 162, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(1714);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 161, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Additive_expressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleAdditive_expression);
          setState(1708);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(1709);
          match(XiasParser::PLUS);
          setState(1710);
          multiplicative_expression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Additive_expressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleAdditive_expression);
          setState(1711);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(1712);
          match(XiasParser::MINUS);
          setState(1713);
          multiplicative_expression(0);
          break;
        }

        default:
          break;
        } 
      }
      setState(1718);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 162, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Shift_expressionContext ------------------------------------------------------------------

XiasParser::Shift_expressionContext::Shift_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Additive_expressionContext* XiasParser::Shift_expressionContext::additive_expression() {
  return getRuleContext<XiasParser::Additive_expressionContext>(0);
}

XiasParser::Shift_expressionContext* XiasParser::Shift_expressionContext::shift_expression() {
  return getRuleContext<XiasParser::Shift_expressionContext>(0);
}

tree::TerminalNode* XiasParser::Shift_expressionContext::OP_LEFT_SHIFT() {
  return getToken(XiasParser::OP_LEFT_SHIFT, 0);
}

XiasParser::Right_shiftContext* XiasParser::Shift_expressionContext::right_shift() {
  return getRuleContext<XiasParser::Right_shiftContext>(0);
}


size_t XiasParser::Shift_expressionContext::getRuleIndex() const {
  return XiasParser::RuleShift_expression;
}


antlrcpp::Any XiasParser::Shift_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitShift_expression(this);
  else
    return visitor->visitChildren(this);
}


XiasParser::Shift_expressionContext* XiasParser::shift_expression() {
   return shift_expression(0);
}

XiasParser::Shift_expressionContext* XiasParser::shift_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  XiasParser::Shift_expressionContext *_localctx = _tracker.createInstance<Shift_expressionContext>(_ctx, parentState);
  XiasParser::Shift_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 358;
  enterRecursionRule(_localctx, 358, XiasParser::RuleShift_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1720);
    additive_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(1731);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 164, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(1729);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 163, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Shift_expressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleShift_expression);
          setState(1722);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(1723);
          match(XiasParser::OP_LEFT_SHIFT);
          setState(1724);
          additive_expression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Shift_expressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleShift_expression);
          setState(1725);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(1726);
          right_shift();
          setState(1727);
          additive_expression(0);
          break;
        }

        default:
          break;
        } 
      }
      setState(1733);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 164, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Relational_expressionContext ------------------------------------------------------------------

XiasParser::Relational_expressionContext::Relational_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Shift_expressionContext* XiasParser::Relational_expressionContext::shift_expression() {
  return getRuleContext<XiasParser::Shift_expressionContext>(0);
}

XiasParser::Relational_expressionContext* XiasParser::Relational_expressionContext::relational_expression() {
  return getRuleContext<XiasParser::Relational_expressionContext>(0);
}

tree::TerminalNode* XiasParser::Relational_expressionContext::LT() {
  return getToken(XiasParser::LT, 0);
}

tree::TerminalNode* XiasParser::Relational_expressionContext::GT() {
  return getToken(XiasParser::GT, 0);
}

tree::TerminalNode* XiasParser::Relational_expressionContext::OP_LE() {
  return getToken(XiasParser::OP_LE, 0);
}

tree::TerminalNode* XiasParser::Relational_expressionContext::OP_GE() {
  return getToken(XiasParser::OP_GE, 0);
}

tree::TerminalNode* XiasParser::Relational_expressionContext::IS() {
  return getToken(XiasParser::IS, 0);
}

XiasParser::Type_Context* XiasParser::Relational_expressionContext::type_() {
  return getRuleContext<XiasParser::Type_Context>(0);
}

tree::TerminalNode* XiasParser::Relational_expressionContext::AS() {
  return getToken(XiasParser::AS, 0);
}


size_t XiasParser::Relational_expressionContext::getRuleIndex() const {
  return XiasParser::RuleRelational_expression;
}


antlrcpp::Any XiasParser::Relational_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitRelational_expression(this);
  else
    return visitor->visitChildren(this);
}


XiasParser::Relational_expressionContext* XiasParser::relational_expression() {
   return relational_expression(0);
}

XiasParser::Relational_expressionContext* XiasParser::relational_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  XiasParser::Relational_expressionContext *_localctx = _tracker.createInstance<Relational_expressionContext>(_ctx, parentState);
  XiasParser::Relational_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 360;
  enterRecursionRule(_localctx, 360, XiasParser::RuleRelational_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1735);
    shift_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(1757);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 166, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(1755);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 165, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Relational_expressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelational_expression);
          setState(1737);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(1738);
          match(XiasParser::LT);
          setState(1739);
          shift_expression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Relational_expressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelational_expression);
          setState(1740);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(1741);
          match(XiasParser::GT);
          setState(1742);
          shift_expression(0);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<Relational_expressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelational_expression);
          setState(1743);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(1744);
          match(XiasParser::OP_LE);
          setState(1745);
          shift_expression(0);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<Relational_expressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelational_expression);
          setState(1746);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(1747);
          match(XiasParser::OP_GE);
          setState(1748);
          shift_expression(0);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<Relational_expressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelational_expression);
          setState(1749);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(1750);
          match(XiasParser::IS);
          setState(1751);
          type_();
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<Relational_expressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelational_expression);
          setState(1752);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(1753);
          match(XiasParser::AS);
          setState(1754);
          type_();
          break;
        }

        default:
          break;
        } 
      }
      setState(1759);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 166, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Equality_expressionContext ------------------------------------------------------------------

XiasParser::Equality_expressionContext::Equality_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Relational_expressionContext* XiasParser::Equality_expressionContext::relational_expression() {
  return getRuleContext<XiasParser::Relational_expressionContext>(0);
}

XiasParser::Equality_expressionContext* XiasParser::Equality_expressionContext::equality_expression() {
  return getRuleContext<XiasParser::Equality_expressionContext>(0);
}

tree::TerminalNode* XiasParser::Equality_expressionContext::OP_EQ() {
  return getToken(XiasParser::OP_EQ, 0);
}

tree::TerminalNode* XiasParser::Equality_expressionContext::OP_NE() {
  return getToken(XiasParser::OP_NE, 0);
}


size_t XiasParser::Equality_expressionContext::getRuleIndex() const {
  return XiasParser::RuleEquality_expression;
}


antlrcpp::Any XiasParser::Equality_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitEquality_expression(this);
  else
    return visitor->visitChildren(this);
}


XiasParser::Equality_expressionContext* XiasParser::equality_expression() {
   return equality_expression(0);
}

XiasParser::Equality_expressionContext* XiasParser::equality_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  XiasParser::Equality_expressionContext *_localctx = _tracker.createInstance<Equality_expressionContext>(_ctx, parentState);
  XiasParser::Equality_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 362;
  enterRecursionRule(_localctx, 362, XiasParser::RuleEquality_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1761);
    relational_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(1771);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 168, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(1769);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 167, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Equality_expressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleEquality_expression);
          setState(1763);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(1764);
          match(XiasParser::OP_EQ);
          setState(1765);
          relational_expression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Equality_expressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleEquality_expression);
          setState(1766);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(1767);
          match(XiasParser::OP_NE);
          setState(1768);
          relational_expression(0);
          break;
        }

        default:
          break;
        } 
      }
      setState(1773);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 168, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- And_expressionContext ------------------------------------------------------------------

XiasParser::And_expressionContext::And_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Equality_expressionContext* XiasParser::And_expressionContext::equality_expression() {
  return getRuleContext<XiasParser::Equality_expressionContext>(0);
}

XiasParser::And_expressionContext* XiasParser::And_expressionContext::and_expression() {
  return getRuleContext<XiasParser::And_expressionContext>(0);
}

tree::TerminalNode* XiasParser::And_expressionContext::AMP() {
  return getToken(XiasParser::AMP, 0);
}


size_t XiasParser::And_expressionContext::getRuleIndex() const {
  return XiasParser::RuleAnd_expression;
}


antlrcpp::Any XiasParser::And_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitAnd_expression(this);
  else
    return visitor->visitChildren(this);
}


XiasParser::And_expressionContext* XiasParser::and_expression() {
   return and_expression(0);
}

XiasParser::And_expressionContext* XiasParser::and_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  XiasParser::And_expressionContext *_localctx = _tracker.createInstance<And_expressionContext>(_ctx, parentState);
  XiasParser::And_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 364;
  enterRecursionRule(_localctx, 364, XiasParser::RuleAnd_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1775);
    equality_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(1782);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 169, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<And_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleAnd_expression);
        setState(1777);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1778);
        match(XiasParser::AMP);
        setState(1779);
        equality_expression(0); 
      }
      setState(1784);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 169, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Exclusive_or_expressionContext ------------------------------------------------------------------

XiasParser::Exclusive_or_expressionContext::Exclusive_or_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::And_expressionContext* XiasParser::Exclusive_or_expressionContext::and_expression() {
  return getRuleContext<XiasParser::And_expressionContext>(0);
}

XiasParser::Exclusive_or_expressionContext* XiasParser::Exclusive_or_expressionContext::exclusive_or_expression() {
  return getRuleContext<XiasParser::Exclusive_or_expressionContext>(0);
}

tree::TerminalNode* XiasParser::Exclusive_or_expressionContext::CARET() {
  return getToken(XiasParser::CARET, 0);
}


size_t XiasParser::Exclusive_or_expressionContext::getRuleIndex() const {
  return XiasParser::RuleExclusive_or_expression;
}


antlrcpp::Any XiasParser::Exclusive_or_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitExclusive_or_expression(this);
  else
    return visitor->visitChildren(this);
}


XiasParser::Exclusive_or_expressionContext* XiasParser::exclusive_or_expression() {
   return exclusive_or_expression(0);
}

XiasParser::Exclusive_or_expressionContext* XiasParser::exclusive_or_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  XiasParser::Exclusive_or_expressionContext *_localctx = _tracker.createInstance<Exclusive_or_expressionContext>(_ctx, parentState);
  XiasParser::Exclusive_or_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 366;
  enterRecursionRule(_localctx, 366, XiasParser::RuleExclusive_or_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1786);
    and_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(1793);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 170, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Exclusive_or_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExclusive_or_expression);
        setState(1788);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1789);
        match(XiasParser::CARET);
        setState(1790);
        and_expression(0); 
      }
      setState(1795);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 170, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Inclusive_or_expressionContext ------------------------------------------------------------------

XiasParser::Inclusive_or_expressionContext::Inclusive_or_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Exclusive_or_expressionContext* XiasParser::Inclusive_or_expressionContext::exclusive_or_expression() {
  return getRuleContext<XiasParser::Exclusive_or_expressionContext>(0);
}

XiasParser::Inclusive_or_expressionContext* XiasParser::Inclusive_or_expressionContext::inclusive_or_expression() {
  return getRuleContext<XiasParser::Inclusive_or_expressionContext>(0);
}

tree::TerminalNode* XiasParser::Inclusive_or_expressionContext::BITWISE_OR() {
  return getToken(XiasParser::BITWISE_OR, 0);
}


size_t XiasParser::Inclusive_or_expressionContext::getRuleIndex() const {
  return XiasParser::RuleInclusive_or_expression;
}


antlrcpp::Any XiasParser::Inclusive_or_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitInclusive_or_expression(this);
  else
    return visitor->visitChildren(this);
}


XiasParser::Inclusive_or_expressionContext* XiasParser::inclusive_or_expression() {
   return inclusive_or_expression(0);
}

XiasParser::Inclusive_or_expressionContext* XiasParser::inclusive_or_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  XiasParser::Inclusive_or_expressionContext *_localctx = _tracker.createInstance<Inclusive_or_expressionContext>(_ctx, parentState);
  XiasParser::Inclusive_or_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 368;
  enterRecursionRule(_localctx, 368, XiasParser::RuleInclusive_or_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1797);
    exclusive_or_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(1804);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 171, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Inclusive_or_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleInclusive_or_expression);
        setState(1799);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1800);
        match(XiasParser::BITWISE_OR);
        setState(1801);
        exclusive_or_expression(0); 
      }
      setState(1806);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 171, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Conditional_and_expressionContext ------------------------------------------------------------------

XiasParser::Conditional_and_expressionContext::Conditional_and_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Inclusive_or_expressionContext* XiasParser::Conditional_and_expressionContext::inclusive_or_expression() {
  return getRuleContext<XiasParser::Inclusive_or_expressionContext>(0);
}

XiasParser::Conditional_and_expressionContext* XiasParser::Conditional_and_expressionContext::conditional_and_expression() {
  return getRuleContext<XiasParser::Conditional_and_expressionContext>(0);
}

tree::TerminalNode* XiasParser::Conditional_and_expressionContext::OP_AND() {
  return getToken(XiasParser::OP_AND, 0);
}


size_t XiasParser::Conditional_and_expressionContext::getRuleIndex() const {
  return XiasParser::RuleConditional_and_expression;
}


antlrcpp::Any XiasParser::Conditional_and_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitConditional_and_expression(this);
  else
    return visitor->visitChildren(this);
}


XiasParser::Conditional_and_expressionContext* XiasParser::conditional_and_expression() {
   return conditional_and_expression(0);
}

XiasParser::Conditional_and_expressionContext* XiasParser::conditional_and_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  XiasParser::Conditional_and_expressionContext *_localctx = _tracker.createInstance<Conditional_and_expressionContext>(_ctx, parentState);
  XiasParser::Conditional_and_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 370;
  enterRecursionRule(_localctx, 370, XiasParser::RuleConditional_and_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1808);
    inclusive_or_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(1815);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 172, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Conditional_and_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleConditional_and_expression);
        setState(1810);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1811);
        match(XiasParser::OP_AND);
        setState(1812);
        inclusive_or_expression(0); 
      }
      setState(1817);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 172, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Conditional_or_expressionContext ------------------------------------------------------------------

XiasParser::Conditional_or_expressionContext::Conditional_or_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Conditional_and_expressionContext* XiasParser::Conditional_or_expressionContext::conditional_and_expression() {
  return getRuleContext<XiasParser::Conditional_and_expressionContext>(0);
}

XiasParser::Conditional_or_expressionContext* XiasParser::Conditional_or_expressionContext::conditional_or_expression() {
  return getRuleContext<XiasParser::Conditional_or_expressionContext>(0);
}

tree::TerminalNode* XiasParser::Conditional_or_expressionContext::OP_OR() {
  return getToken(XiasParser::OP_OR, 0);
}


size_t XiasParser::Conditional_or_expressionContext::getRuleIndex() const {
  return XiasParser::RuleConditional_or_expression;
}


antlrcpp::Any XiasParser::Conditional_or_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitConditional_or_expression(this);
  else
    return visitor->visitChildren(this);
}


XiasParser::Conditional_or_expressionContext* XiasParser::conditional_or_expression() {
   return conditional_or_expression(0);
}

XiasParser::Conditional_or_expressionContext* XiasParser::conditional_or_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  XiasParser::Conditional_or_expressionContext *_localctx = _tracker.createInstance<Conditional_or_expressionContext>(_ctx, parentState);
  XiasParser::Conditional_or_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 372;
  enterRecursionRule(_localctx, 372, XiasParser::RuleConditional_or_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1819);
    conditional_and_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(1826);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 173, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Conditional_or_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleConditional_or_expression);
        setState(1821);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1822);
        match(XiasParser::OP_OR);
        setState(1823);
        conditional_and_expression(0); 
      }
      setState(1828);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 173, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Null_coalescing_expressionContext ------------------------------------------------------------------

XiasParser::Null_coalescing_expressionContext::Null_coalescing_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Conditional_or_expressionContext* XiasParser::Null_coalescing_expressionContext::conditional_or_expression() {
  return getRuleContext<XiasParser::Conditional_or_expressionContext>(0);
}

tree::TerminalNode* XiasParser::Null_coalescing_expressionContext::OP_COALESCING() {
  return getToken(XiasParser::OP_COALESCING, 0);
}

XiasParser::Null_coalescing_expressionContext* XiasParser::Null_coalescing_expressionContext::null_coalescing_expression() {
  return getRuleContext<XiasParser::Null_coalescing_expressionContext>(0);
}


size_t XiasParser::Null_coalescing_expressionContext::getRuleIndex() const {
  return XiasParser::RuleNull_coalescing_expression;
}


antlrcpp::Any XiasParser::Null_coalescing_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitNull_coalescing_expression(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Null_coalescing_expressionContext* XiasParser::null_coalescing_expression() {
  Null_coalescing_expressionContext *_localctx = _tracker.createInstance<Null_coalescing_expressionContext>(_ctx, getState());
  enterRule(_localctx, 374, XiasParser::RuleNull_coalescing_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1834);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 174, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1829);
      conditional_or_expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1830);
      conditional_or_expression(0);
      setState(1831);
      match(XiasParser::OP_COALESCING);
      setState(1832);
      null_coalescing_expression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Conditional_expressionContext ------------------------------------------------------------------

XiasParser::Conditional_expressionContext::Conditional_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Null_coalescing_expressionContext* XiasParser::Conditional_expressionContext::null_coalescing_expression() {
  return getRuleContext<XiasParser::Null_coalescing_expressionContext>(0);
}

tree::TerminalNode* XiasParser::Conditional_expressionContext::INTERR() {
  return getToken(XiasParser::INTERR, 0);
}

std::vector<XiasParser::ExpressionContext *> XiasParser::Conditional_expressionContext::expression() {
  return getRuleContexts<XiasParser::ExpressionContext>();
}

XiasParser::ExpressionContext* XiasParser::Conditional_expressionContext::expression(size_t i) {
  return getRuleContext<XiasParser::ExpressionContext>(i);
}

tree::TerminalNode* XiasParser::Conditional_expressionContext::COLON() {
  return getToken(XiasParser::COLON, 0);
}


size_t XiasParser::Conditional_expressionContext::getRuleIndex() const {
  return XiasParser::RuleConditional_expression;
}


antlrcpp::Any XiasParser::Conditional_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitConditional_expression(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Conditional_expressionContext* XiasParser::conditional_expression() {
  Conditional_expressionContext *_localctx = _tracker.createInstance<Conditional_expressionContext>(_ctx, getState());
  enterRule(_localctx, 376, XiasParser::RuleConditional_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1843);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 175, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1836);
      null_coalescing_expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1837);
      null_coalescing_expression();
      setState(1838);
      match(XiasParser::INTERR);
      setState(1839);
      expression();
      setState(1840);
      match(XiasParser::COLON);
      setState(1841);
      expression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

XiasParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Unary_expressionContext* XiasParser::AssignmentContext::unary_expression() {
  return getRuleContext<XiasParser::Unary_expressionContext>(0);
}

XiasParser::Assignment_operatorContext* XiasParser::AssignmentContext::assignment_operator() {
  return getRuleContext<XiasParser::Assignment_operatorContext>(0);
}

XiasParser::ExpressionContext* XiasParser::AssignmentContext::expression() {
  return getRuleContext<XiasParser::ExpressionContext>(0);
}


size_t XiasParser::AssignmentContext::getRuleIndex() const {
  return XiasParser::RuleAssignment;
}


antlrcpp::Any XiasParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::AssignmentContext* XiasParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 378, XiasParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1845);
    unary_expression();
    setState(1846);
    assignment_operator();
    setState(1847);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Assignment_operatorContext ------------------------------------------------------------------

XiasParser::Assignment_operatorContext::Assignment_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Assignment_operatorContext::ASSIGNMENT() {
  return getToken(XiasParser::ASSIGNMENT, 0);
}

tree::TerminalNode* XiasParser::Assignment_operatorContext::OP_ADD_ASSIGNMENT() {
  return getToken(XiasParser::OP_ADD_ASSIGNMENT, 0);
}

tree::TerminalNode* XiasParser::Assignment_operatorContext::OP_SUB_ASSIGNMENT() {
  return getToken(XiasParser::OP_SUB_ASSIGNMENT, 0);
}

tree::TerminalNode* XiasParser::Assignment_operatorContext::OP_MULT_ASSIGNMENT() {
  return getToken(XiasParser::OP_MULT_ASSIGNMENT, 0);
}

tree::TerminalNode* XiasParser::Assignment_operatorContext::OP_DIV_ASSIGNMENT() {
  return getToken(XiasParser::OP_DIV_ASSIGNMENT, 0);
}

tree::TerminalNode* XiasParser::Assignment_operatorContext::OP_MOD_ASSIGNMENT() {
  return getToken(XiasParser::OP_MOD_ASSIGNMENT, 0);
}

tree::TerminalNode* XiasParser::Assignment_operatorContext::OP_AND_ASSIGNMENT() {
  return getToken(XiasParser::OP_AND_ASSIGNMENT, 0);
}

tree::TerminalNode* XiasParser::Assignment_operatorContext::OP_OR_ASSIGNMENT() {
  return getToken(XiasParser::OP_OR_ASSIGNMENT, 0);
}

tree::TerminalNode* XiasParser::Assignment_operatorContext::OP_XOR_ASSIGNMENT() {
  return getToken(XiasParser::OP_XOR_ASSIGNMENT, 0);
}

tree::TerminalNode* XiasParser::Assignment_operatorContext::OP_LEFT_SHIFT_ASSIGNMENT() {
  return getToken(XiasParser::OP_LEFT_SHIFT_ASSIGNMENT, 0);
}

XiasParser::Right_shift_assignmentContext* XiasParser::Assignment_operatorContext::right_shift_assignment() {
  return getRuleContext<XiasParser::Right_shift_assignmentContext>(0);
}


size_t XiasParser::Assignment_operatorContext::getRuleIndex() const {
  return XiasParser::RuleAssignment_operator;
}


antlrcpp::Any XiasParser::Assignment_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitAssignment_operator(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Assignment_operatorContext* XiasParser::assignment_operator() {
  Assignment_operatorContext *_localctx = _tracker.createInstance<Assignment_operatorContext>(_ctx, getState());
  enterRule(_localctx, 380, XiasParser::RuleAssignment_operator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1860);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case XiasParser::ASSIGNMENT: {
        enterOuterAlt(_localctx, 1);
        setState(1849);
        match(XiasParser::ASSIGNMENT);
        break;
      }

      case XiasParser::OP_ADD_ASSIGNMENT: {
        enterOuterAlt(_localctx, 2);
        setState(1850);
        match(XiasParser::OP_ADD_ASSIGNMENT);
        break;
      }

      case XiasParser::OP_SUB_ASSIGNMENT: {
        enterOuterAlt(_localctx, 3);
        setState(1851);
        match(XiasParser::OP_SUB_ASSIGNMENT);
        break;
      }

      case XiasParser::OP_MULT_ASSIGNMENT: {
        enterOuterAlt(_localctx, 4);
        setState(1852);
        match(XiasParser::OP_MULT_ASSIGNMENT);
        break;
      }

      case XiasParser::OP_DIV_ASSIGNMENT: {
        enterOuterAlt(_localctx, 5);
        setState(1853);
        match(XiasParser::OP_DIV_ASSIGNMENT);
        break;
      }

      case XiasParser::OP_MOD_ASSIGNMENT: {
        enterOuterAlt(_localctx, 6);
        setState(1854);
        match(XiasParser::OP_MOD_ASSIGNMENT);
        break;
      }

      case XiasParser::OP_AND_ASSIGNMENT: {
        enterOuterAlt(_localctx, 7);
        setState(1855);
        match(XiasParser::OP_AND_ASSIGNMENT);
        break;
      }

      case XiasParser::OP_OR_ASSIGNMENT: {
        enterOuterAlt(_localctx, 8);
        setState(1856);
        match(XiasParser::OP_OR_ASSIGNMENT);
        break;
      }

      case XiasParser::OP_XOR_ASSIGNMENT: {
        enterOuterAlt(_localctx, 9);
        setState(1857);
        match(XiasParser::OP_XOR_ASSIGNMENT);
        break;
      }

      case XiasParser::OP_LEFT_SHIFT_ASSIGNMENT: {
        enterOuterAlt(_localctx, 10);
        setState(1858);
        match(XiasParser::OP_LEFT_SHIFT_ASSIGNMENT);
        break;
      }

      case XiasParser::GT: {
        enterOuterAlt(_localctx, 11);
        setState(1859);
        right_shift_assignment();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

XiasParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Non_assignment_expressionContext* XiasParser::ExpressionContext::non_assignment_expression() {
  return getRuleContext<XiasParser::Non_assignment_expressionContext>(0);
}

XiasParser::AssignmentContext* XiasParser::ExpressionContext::assignment() {
  return getRuleContext<XiasParser::AssignmentContext>(0);
}


size_t XiasParser::ExpressionContext::getRuleIndex() const {
  return XiasParser::RuleExpression;
}


antlrcpp::Any XiasParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::ExpressionContext* XiasParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 382, XiasParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1864);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 177, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1862);
      non_assignment_expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1863);
      assignment();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Non_assignment_expressionContext ------------------------------------------------------------------

XiasParser::Non_assignment_expressionContext::Non_assignment_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Conditional_expressionContext* XiasParser::Non_assignment_expressionContext::conditional_expression() {
  return getRuleContext<XiasParser::Conditional_expressionContext>(0);
}


size_t XiasParser::Non_assignment_expressionContext::getRuleIndex() const {
  return XiasParser::RuleNon_assignment_expression;
}


antlrcpp::Any XiasParser::Non_assignment_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitNon_assignment_expression(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Non_assignment_expressionContext* XiasParser::non_assignment_expression() {
  Non_assignment_expressionContext *_localctx = _tracker.createInstance<Non_assignment_expressionContext>(_ctx, getState());
  enterRule(_localctx, 384, XiasParser::RuleNon_assignment_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1866);
    conditional_expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Constant_expressionContext ------------------------------------------------------------------

XiasParser::Constant_expressionContext::Constant_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::ExpressionContext* XiasParser::Constant_expressionContext::expression() {
  return getRuleContext<XiasParser::ExpressionContext>(0);
}


size_t XiasParser::Constant_expressionContext::getRuleIndex() const {
  return XiasParser::RuleConstant_expression;
}


antlrcpp::Any XiasParser::Constant_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitConstant_expression(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Constant_expressionContext* XiasParser::constant_expression() {
  Constant_expressionContext *_localctx = _tracker.createInstance<Constant_expressionContext>(_ctx, getState());
  enterRule(_localctx, 386, XiasParser::RuleConstant_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1868);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Boolean_expressionContext ------------------------------------------------------------------

XiasParser::Boolean_expressionContext::Boolean_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::ExpressionContext* XiasParser::Boolean_expressionContext::expression() {
  return getRuleContext<XiasParser::ExpressionContext>(0);
}


size_t XiasParser::Boolean_expressionContext::getRuleIndex() const {
  return XiasParser::RuleBoolean_expression;
}


antlrcpp::Any XiasParser::Boolean_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitBoolean_expression(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Boolean_expressionContext* XiasParser::boolean_expression() {
  Boolean_expressionContext *_localctx = _tracker.createInstance<Boolean_expressionContext>(_ctx, getState());
  enterRule(_localctx, 388, XiasParser::RuleBoolean_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1870);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

XiasParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

XiasParser::Boolean_literalContext* XiasParser::LiteralContext::boolean_literal() {
  return getRuleContext<XiasParser::Boolean_literalContext>(0);
}

XiasParser::String_literalContext* XiasParser::LiteralContext::string_literal() {
  return getRuleContext<XiasParser::String_literalContext>(0);
}

tree::TerminalNode* XiasParser::LiteralContext::INTEGER_LITERAL() {
  return getToken(XiasParser::INTEGER_LITERAL, 0);
}

tree::TerminalNode* XiasParser::LiteralContext::UNSIGNED_LITERAL() {
  return getToken(XiasParser::UNSIGNED_LITERAL, 0);
}

tree::TerminalNode* XiasParser::LiteralContext::HEX_INTEGER_LITERAL() {
  return getToken(XiasParser::HEX_INTEGER_LITERAL, 0);
}

tree::TerminalNode* XiasParser::LiteralContext::FLOAT_LITERAL() {
  return getToken(XiasParser::FLOAT_LITERAL, 0);
}

tree::TerminalNode* XiasParser::LiteralContext::DOUBLE_LITERAL() {
  return getToken(XiasParser::DOUBLE_LITERAL, 0);
}

tree::TerminalNode* XiasParser::LiteralContext::CHARACTER_LITERAL() {
  return getToken(XiasParser::CHARACTER_LITERAL, 0);
}

tree::TerminalNode* XiasParser::LiteralContext::NULL_() {
  return getToken(XiasParser::NULL_, 0);
}


size_t XiasParser::LiteralContext::getRuleIndex() const {
  return XiasParser::RuleLiteral;
}


antlrcpp::Any XiasParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::LiteralContext* XiasParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 390, XiasParser::RuleLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1881);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case XiasParser::FALSE:
      case XiasParser::TRUE: {
        enterOuterAlt(_localctx, 1);
        setState(1872);
        boolean_literal();
        break;
      }

      case XiasParser::REGULAR_STRING:
      case XiasParser::VERBATIUM_STRING: {
        enterOuterAlt(_localctx, 2);
        setState(1873);
        string_literal();
        break;
      }

      case XiasParser::INTEGER_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(1874);
        match(XiasParser::INTEGER_LITERAL);
        break;
      }

      case XiasParser::UNSIGNED_LITERAL: {
        enterOuterAlt(_localctx, 4);
        setState(1875);
        match(XiasParser::UNSIGNED_LITERAL);
        break;
      }

      case XiasParser::HEX_INTEGER_LITERAL: {
        enterOuterAlt(_localctx, 5);
        setState(1876);
        match(XiasParser::HEX_INTEGER_LITERAL);
        break;
      }

      case XiasParser::FLOAT_LITERAL: {
        enterOuterAlt(_localctx, 6);
        setState(1877);
        match(XiasParser::FLOAT_LITERAL);
        break;
      }

      case XiasParser::DOUBLE_LITERAL: {
        enterOuterAlt(_localctx, 7);
        setState(1878);
        match(XiasParser::DOUBLE_LITERAL);
        break;
      }

      case XiasParser::CHARACTER_LITERAL: {
        enterOuterAlt(_localctx, 8);
        setState(1879);
        match(XiasParser::CHARACTER_LITERAL);
        break;
      }

      case XiasParser::NULL_: {
        enterOuterAlt(_localctx, 9);
        setState(1880);
        match(XiasParser::NULL_);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Boolean_literalContext ------------------------------------------------------------------

XiasParser::Boolean_literalContext::Boolean_literalContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Boolean_literalContext::TRUE() {
  return getToken(XiasParser::TRUE, 0);
}

tree::TerminalNode* XiasParser::Boolean_literalContext::FALSE() {
  return getToken(XiasParser::FALSE, 0);
}


size_t XiasParser::Boolean_literalContext::getRuleIndex() const {
  return XiasParser::RuleBoolean_literal;
}


antlrcpp::Any XiasParser::Boolean_literalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitBoolean_literal(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Boolean_literalContext* XiasParser::boolean_literal() {
  Boolean_literalContext *_localctx = _tracker.createInstance<Boolean_literalContext>(_ctx, getState());
  enterRule(_localctx, 392, XiasParser::RuleBoolean_literal);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1883);
    _la = _input->LA(1);
    if (!(_la == XiasParser::FALSE

    || _la == XiasParser::TRUE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- String_literalContext ------------------------------------------------------------------

XiasParser::String_literalContext::String_literalContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::String_literalContext::REGULAR_STRING() {
  return getToken(XiasParser::REGULAR_STRING, 0);
}

tree::TerminalNode* XiasParser::String_literalContext::VERBATIUM_STRING() {
  return getToken(XiasParser::VERBATIUM_STRING, 0);
}


size_t XiasParser::String_literalContext::getRuleIndex() const {
  return XiasParser::RuleString_literal;
}


antlrcpp::Any XiasParser::String_literalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitString_literal(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::String_literalContext* XiasParser::string_literal() {
  String_literalContext *_localctx = _tracker.createInstance<String_literalContext>(_ctx, getState());
  enterRule(_localctx, 394, XiasParser::RuleString_literal);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1885);
    _la = _input->LA(1);
    if (!(_la == XiasParser::REGULAR_STRING

    || _la == XiasParser::VERBATIUM_STRING)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Array_initializerContext ------------------------------------------------------------------

XiasParser::Array_initializerContext::Array_initializerContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Array_initializerContext::OPEN_BRACE() {
  return getToken(XiasParser::OPEN_BRACE, 0);
}

tree::TerminalNode* XiasParser::Array_initializerContext::CLOSE_BRACE() {
  return getToken(XiasParser::CLOSE_BRACE, 0);
}

XiasParser::Variable_initializer_listContext* XiasParser::Array_initializerContext::variable_initializer_list() {
  return getRuleContext<XiasParser::Variable_initializer_listContext>(0);
}

tree::TerminalNode* XiasParser::Array_initializerContext::COMMA() {
  return getToken(XiasParser::COMMA, 0);
}


size_t XiasParser::Array_initializerContext::getRuleIndex() const {
  return XiasParser::RuleArray_initializer;
}


antlrcpp::Any XiasParser::Array_initializerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitArray_initializer(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Array_initializerContext* XiasParser::array_initializer() {
  Array_initializerContext *_localctx = _tracker.createInstance<Array_initializerContext>(_ctx, getState());
  enterRule(_localctx, 396, XiasParser::RuleArray_initializer);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1897);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 180, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1887);
      match(XiasParser::OPEN_BRACE);
      setState(1889);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << XiasParser::BASE)
        | (1ULL << XiasParser::DEFAULT)
        | (1ULL << XiasParser::FALSE)
        | (1ULL << XiasParser::NEW)
        | (1ULL << XiasParser::NULL_)
        | (1ULL << XiasParser::THIS)
        | (1ULL << XiasParser::TRUE)
        | (1ULL << XiasParser::TYPEOF))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 72)) & ((1ULL << (XiasParser::IDENTIFIER - 72))
        | (1ULL << (XiasParser::INTEGER_LITERAL - 72))
        | (1ULL << (XiasParser::UNSIGNED_LITERAL - 72))
        | (1ULL << (XiasParser::HEX_INTEGER_LITERAL - 72))
        | (1ULL << (XiasParser::FLOAT_LITERAL - 72))
        | (1ULL << (XiasParser::DOUBLE_LITERAL - 72))
        | (1ULL << (XiasParser::CHARACTER_LITERAL - 72))
        | (1ULL << (XiasParser::REGULAR_STRING - 72))
        | (1ULL << (XiasParser::VERBATIUM_STRING - 72))
        | (1ULL << (XiasParser::OPEN_BRACE - 72))
        | (1ULL << (XiasParser::OPEN_PARENS - 72))
        | (1ULL << (XiasParser::PLUS - 72))
        | (1ULL << (XiasParser::MINUS - 72))
        | (1ULL << (XiasParser::BANG - 72))
        | (1ULL << (XiasParser::TILDE - 72))
        | (1ULL << (XiasParser::OP_INC - 72))
        | (1ULL << (XiasParser::OP_DEC - 72)))) != 0)) {
        setState(1888);
        variable_initializer_list();
      }
      setState(1891);
      match(XiasParser::CLOSE_BRACE);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1892);
      match(XiasParser::OPEN_BRACE);
      setState(1893);
      variable_initializer_list();
      setState(1894);
      match(XiasParser::COMMA);
      setState(1895);
      match(XiasParser::CLOSE_BRACE);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_initializer_listContext ------------------------------------------------------------------

XiasParser::Variable_initializer_listContext::Variable_initializer_listContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

std::vector<XiasParser::Variable_initializerContext *> XiasParser::Variable_initializer_listContext::variable_initializer() {
  return getRuleContexts<XiasParser::Variable_initializerContext>();
}

XiasParser::Variable_initializerContext* XiasParser::Variable_initializer_listContext::variable_initializer(size_t i) {
  return getRuleContext<XiasParser::Variable_initializerContext>(i);
}

std::vector<tree::TerminalNode *> XiasParser::Variable_initializer_listContext::COMMA() {
  return getTokens(XiasParser::COMMA);
}

tree::TerminalNode* XiasParser::Variable_initializer_listContext::COMMA(size_t i) {
  return getToken(XiasParser::COMMA, i);
}


size_t XiasParser::Variable_initializer_listContext::getRuleIndex() const {
  return XiasParser::RuleVariable_initializer_list;
}


antlrcpp::Any XiasParser::Variable_initializer_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitVariable_initializer_list(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Variable_initializer_listContext* XiasParser::variable_initializer_list() {
  Variable_initializer_listContext *_localctx = _tracker.createInstance<Variable_initializer_listContext>(_ctx, getState());
  enterRule(_localctx, 398, XiasParser::RuleVariable_initializer_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1899);
    variable_initializer();
    setState(1904);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 181, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1900);
        match(XiasParser::COMMA);
        setState(1901);
        variable_initializer(); 
      }
      setState(1906);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 181, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Right_shiftContext ------------------------------------------------------------------

XiasParser::Right_shiftContext::Right_shiftContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

std::vector<tree::TerminalNode *> XiasParser::Right_shiftContext::GT() {
  return getTokens(XiasParser::GT);
}

tree::TerminalNode* XiasParser::Right_shiftContext::GT(size_t i) {
  return getToken(XiasParser::GT, i);
}


size_t XiasParser::Right_shiftContext::getRuleIndex() const {
  return XiasParser::RuleRight_shift;
}


antlrcpp::Any XiasParser::Right_shiftContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitRight_shift(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Right_shiftContext* XiasParser::right_shift() {
  Right_shiftContext *_localctx = _tracker.createInstance<Right_shiftContext>(_ctx, getState());
  enterRule(_localctx, 400, XiasParser::RuleRight_shift);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1907);
    dynamic_cast<Right_shiftContext *>(_localctx)->first = match(XiasParser::GT);
    setState(1908);
    dynamic_cast<Right_shiftContext *>(_localctx)->second = match(XiasParser::GT);
    setState(1909);

    if (!((dynamic_cast<Right_shiftContext *>(_localctx)->first != nullptr ? dynamic_cast<Right_shiftContext *>(_localctx)->first->getTokenIndex() : 0) + 1 == (dynamic_cast<Right_shiftContext *>(_localctx)->second != nullptr ? dynamic_cast<Right_shiftContext *>(_localctx)->second->getTokenIndex() : 0))) throw FailedPredicateException(this, "$first.index + 1 == $second.index");
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Right_shift_assignmentContext ------------------------------------------------------------------

XiasParser::Right_shift_assignmentContext::Right_shift_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::Right_shift_assignmentContext::GT() {
  return getToken(XiasParser::GT, 0);
}

tree::TerminalNode* XiasParser::Right_shift_assignmentContext::OP_GE() {
  return getToken(XiasParser::OP_GE, 0);
}


size_t XiasParser::Right_shift_assignmentContext::getRuleIndex() const {
  return XiasParser::RuleRight_shift_assignment;
}


antlrcpp::Any XiasParser::Right_shift_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitRight_shift_assignment(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::Right_shift_assignmentContext* XiasParser::right_shift_assignment() {
  Right_shift_assignmentContext *_localctx = _tracker.createInstance<Right_shift_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 402, XiasParser::RuleRight_shift_assignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1911);
    dynamic_cast<Right_shift_assignmentContext *>(_localctx)->first = match(XiasParser::GT);
    setState(1912);
    dynamic_cast<Right_shift_assignmentContext *>(_localctx)->second = match(XiasParser::OP_GE);
    setState(1913);

    if (!((dynamic_cast<Right_shift_assignmentContext *>(_localctx)->first != nullptr ? dynamic_cast<Right_shift_assignmentContext *>(_localctx)->first->getTokenIndex() : 0) + 1 == (dynamic_cast<Right_shift_assignmentContext *>(_localctx)->second != nullptr ? dynamic_cast<Right_shift_assignmentContext *>(_localctx)->second->getTokenIndex() : 0))) throw FailedPredicateException(this, "$first.index + 1 == $second.index");
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierContext ------------------------------------------------------------------

XiasParser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::IdentifierContext::IDENTIFIER() {
  return getToken(XiasParser::IDENTIFIER, 0);
}


size_t XiasParser::IdentifierContext::getRuleIndex() const {
  return XiasParser::RuleIdentifier;
}


antlrcpp::Any XiasParser::IdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitIdentifier(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::IdentifierContext* XiasParser::identifier() {
  IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
  enterRule(_localctx, 404, XiasParser::RuleIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1915);
    match(XiasParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- All_modifierContext ------------------------------------------------------------------

XiasParser::All_modifierContext::All_modifierContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::RuleContextWithAltNum(parent, invokingState) {
}

tree::TerminalNode* XiasParser::All_modifierContext::NEW() {
  return getToken(XiasParser::NEW, 0);
}

tree::TerminalNode* XiasParser::All_modifierContext::PUBLIC() {
  return getToken(XiasParser::PUBLIC, 0);
}

tree::TerminalNode* XiasParser::All_modifierContext::PROTECTED() {
  return getToken(XiasParser::PROTECTED, 0);
}

tree::TerminalNode* XiasParser::All_modifierContext::PRIVATE() {
  return getToken(XiasParser::PRIVATE, 0);
}

tree::TerminalNode* XiasParser::All_modifierContext::STATIC() {
  return getToken(XiasParser::STATIC, 0);
}

tree::TerminalNode* XiasParser::All_modifierContext::VIRTUAL() {
  return getToken(XiasParser::VIRTUAL, 0);
}

tree::TerminalNode* XiasParser::All_modifierContext::SEALED() {
  return getToken(XiasParser::SEALED, 0);
}

tree::TerminalNode* XiasParser::All_modifierContext::OVERRIDE() {
  return getToken(XiasParser::OVERRIDE, 0);
}

tree::TerminalNode* XiasParser::All_modifierContext::ABSTRACT() {
  return getToken(XiasParser::ABSTRACT, 0);
}

tree::TerminalNode* XiasParser::All_modifierContext::READONLY() {
  return getToken(XiasParser::READONLY, 0);
}

tree::TerminalNode* XiasParser::All_modifierContext::EXTERN() {
  return getToken(XiasParser::EXTERN, 0);
}


size_t XiasParser::All_modifierContext::getRuleIndex() const {
  return XiasParser::RuleAll_modifier;
}


antlrcpp::Any XiasParser::All_modifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<XiasParserVisitor*>(visitor))
    return parserVisitor->visitAll_modifier(this);
  else
    return visitor->visitChildren(this);
}

XiasParser::All_modifierContext* XiasParser::all_modifier() {
  All_modifierContext *_localctx = _tracker.createInstance<All_modifierContext>(_ctx, getState());
  enterRule(_localctx, 406, XiasParser::RuleAll_modifier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1917);
    _la = _input->LA(1);
    if (!(((((_la - 6) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 6)) & ((1ULL << (XiasParser::ABSTRACT - 6))
      | (1ULL << (XiasParser::EXTERN - 6))
      | (1ULL << (XiasParser::NEW - 6))
      | (1ULL << (XiasParser::OVERRIDE - 6))
      | (1ULL << (XiasParser::PRIVATE - 6))
      | (1ULL << (XiasParser::PROTECTED - 6))
      | (1ULL << (XiasParser::PUBLIC - 6))
      | (1ULL << (XiasParser::READONLY - 6))
      | (1ULL << (XiasParser::SEALED - 6))
      | (1ULL << (XiasParser::STATIC - 6))
      | (1ULL << (XiasParser::VIRTUAL - 6)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool XiasParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 18: return namespace_or_type_nameSempred(dynamic_cast<Namespace_or_type_nameContext *>(context), predicateIndex);
    case 88: return variant_type_parametersSempred(dynamic_cast<Variant_type_parametersContext *>(context), predicateIndex);
    case 165: return unbound_type_nameSempred(dynamic_cast<Unbound_type_nameContext *>(context), predicateIndex);
    case 177: return multiplicative_expressionSempred(dynamic_cast<Multiplicative_expressionContext *>(context), predicateIndex);
    case 178: return additive_expressionSempred(dynamic_cast<Additive_expressionContext *>(context), predicateIndex);
    case 179: return shift_expressionSempred(dynamic_cast<Shift_expressionContext *>(context), predicateIndex);
    case 180: return relational_expressionSempred(dynamic_cast<Relational_expressionContext *>(context), predicateIndex);
    case 181: return equality_expressionSempred(dynamic_cast<Equality_expressionContext *>(context), predicateIndex);
    case 182: return and_expressionSempred(dynamic_cast<And_expressionContext *>(context), predicateIndex);
    case 183: return exclusive_or_expressionSempred(dynamic_cast<Exclusive_or_expressionContext *>(context), predicateIndex);
    case 184: return inclusive_or_expressionSempred(dynamic_cast<Inclusive_or_expressionContext *>(context), predicateIndex);
    case 185: return conditional_and_expressionSempred(dynamic_cast<Conditional_and_expressionContext *>(context), predicateIndex);
    case 186: return conditional_or_expressionSempred(dynamic_cast<Conditional_or_expressionContext *>(context), predicateIndex);
    case 200: return right_shiftSempred(dynamic_cast<Right_shiftContext *>(context), predicateIndex);
    case 201: return right_shift_assignmentSempred(dynamic_cast<Right_shift_assignmentContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool XiasParser::namespace_or_type_nameSempred(Namespace_or_type_nameContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool XiasParser::variant_type_parametersSempred(Variant_type_parametersContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool XiasParser::unbound_type_nameSempred(Unbound_type_nameContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool XiasParser::multiplicative_expressionSempred(Multiplicative_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 3);
    case 4: return precpred(_ctx, 2);
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool XiasParser::additive_expressionSempred(Additive_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 2);
    case 7: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool XiasParser::shift_expressionSempred(Shift_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 8: return precpred(_ctx, 2);
    case 9: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool XiasParser::relational_expressionSempred(Relational_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 10: return precpred(_ctx, 6);
    case 11: return precpred(_ctx, 5);
    case 12: return precpred(_ctx, 4);
    case 13: return precpred(_ctx, 3);
    case 14: return precpred(_ctx, 2);
    case 15: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool XiasParser::equality_expressionSempred(Equality_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 16: return precpred(_ctx, 2);
    case 17: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool XiasParser::and_expressionSempred(And_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 18: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool XiasParser::exclusive_or_expressionSempred(Exclusive_or_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 19: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool XiasParser::inclusive_or_expressionSempred(Inclusive_or_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 20: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool XiasParser::conditional_and_expressionSempred(Conditional_and_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 21: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool XiasParser::conditional_or_expressionSempred(Conditional_or_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 22: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool XiasParser::right_shiftSempred(Right_shiftContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 23: return (dynamic_cast<Right_shiftContext *>(_localctx)->first != nullptr ? dynamic_cast<Right_shiftContext *>(_localctx)->first->getTokenIndex() : 0) + 1 == (dynamic_cast<Right_shiftContext *>(_localctx)->second != nullptr ? dynamic_cast<Right_shiftContext *>(_localctx)->second->getTokenIndex() : 0);

  default:
    break;
  }
  return true;
}

bool XiasParser::right_shift_assignmentSempred(Right_shift_assignmentContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 24: return (dynamic_cast<Right_shift_assignmentContext *>(_localctx)->first != nullptr ? dynamic_cast<Right_shift_assignmentContext *>(_localctx)->first->getTokenIndex() : 0) + 1 == (dynamic_cast<Right_shift_assignmentContext *>(_localctx)->second != nullptr ? dynamic_cast<Right_shift_assignmentContext *>(_localctx)->second->getTokenIndex() : 0);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> XiasParser::_decisionToDFA;
atn::PredictionContextCache XiasParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN XiasParser::_atn;
std::vector<uint16_t> XiasParser::_serializedATN;

std::vector<std::string> XiasParser::_ruleNames = {
  "compilation_unit", "using_directive", "namespace_member_declaration", 
  "namespace_declaration", "qualified_identifier", "namespace_body", "qualified_alias_member", 
  "type_declaration", "type_parameter_list", "type_argument_list", "type_parameter", 
  "type_parameter_constraints_clause", "type_parameter_constraints", "constructor_constraint", 
  "basic_modifier", "type_", "namespace_name", "type_name", "namespace_or_type_name", 
  "value_type", "struct_type", "base_type", "simple_type", "numeric_type", 
  "integral_type", "floating_point_type", "enum_type", "reference_type", 
  "class_type", "interface_type", "array_type", "non_array_type", "rank_specifier", 
  "dim_separator", "predefined_type", "class_declaration", "class_base", 
  "interface_type_list", "class_body", "class_member_declaration", "constant_declaration", 
  "field_declaration", "variable_declarators", "variable_declarator", "variable_initializer", 
  "method_declaration", "method_header", "return_type", "member_name", "formal_parameter_list", 
  "fixed_parameters", "fixed_parameter", "default_argument", "parameter_modifier", 
  "method_body", "property_declaration", "property_body", "accessor_declarations", 
  "get_accessor_declaration", "set_accessor_declaration", "accessor_modifier", 
  "accessor_body", "property_initializer", "indexer_declaration", "indexer_modifier", 
  "indexer_declarator", "indexer_body", "operator_declaration", "operator_modifier", 
  "operator_declarator", "unary_operator_declarator", "overloadable_unary_operator", 
  "binary_operator_declarator", "overloadable_binary_operator", "conversion_operator_declarator", 
  "operator_body", "constructor_declaration", "constructor_modifier", "constructor_declarator", 
  "constructor_initializer", "constructor_body", "static_constructor_declaration", 
  "static_constructor_modifiers", "static_constructor_body", "destructor_declaration", 
  "destructor_body", "interface_declaration", "variant_type_parameter_list", 
  "variant_type_parameters", "variance_annotation", "interface_base", "interface_body", 
  "interface_member_declaration", "interface_method_declaration", "interface_property_declaration", 
  "interface_accessors", "interface_indexer_declaration", "block", "statement_list", 
  "statement", "labeled_statement", "declaration_statement", "local_variable_declaration", 
  "local_variable_type", "local_variable_declarators", "local_variable_declarator", 
  "local_variable_initializer", "local_constant_declaration", "constant_declarators", 
  "constant_declarator", "embedded_statement", "empty_statement", "expression_statement", 
  "statement_expression", "selection_statement", "if_statement", "switch_statement", 
  "switch_block", "switch_section", "switch_label", "iteration_statement", 
  "while_statement", "do_statement", "for_statement", "for_initializer", 
  "for_condition", "for_iterator", "statement_expression_list", "foreach_statement", 
  "jump_statement", "break_statement", "continue_statement", "goto_statement", 
  "return_statement", "throw_statement", "try_statement", "catch_clause", 
  "exception_specifier", "exception_filter", "finally_clause", "argument_list", 
  "primary_expression", "primary_no_array_creation_expression_base", "primary_expression_start", 
  "primary_no_array_creation_expression", "simple_name", "parenthesized_expression", 
  "member_access", "invocation_expression", "element_access", "this_access", 
  "base_access", "post_increment_expression", "post_decrement_expression", 
  "object_creation_expression", "object_or_collection_initializer", "object_initializer", 
  "member_initializer_list", "member_initializer", "initializer_value", 
  "collection_initializer", "element_initializer_list", "element_initializer", 
  "expression_list", "typeof_expression", "unbound_type_name", "generic_dimension_specifier", 
  "default_value_expression", "array_creation_expression", "unary_expression", 
  "unary_plus_expression", "unary_minus_expression", "unary_bang_expression", 
  "unary_tilde_expression", "pre_increment_expression", "pre_decrement_expression", 
  "cast_expression", "multiplicative_expression", "additive_expression", 
  "shift_expression", "relational_expression", "equality_expression", "and_expression", 
  "exclusive_or_expression", "inclusive_or_expression", "conditional_and_expression", 
  "conditional_or_expression", "null_coalescing_expression", "conditional_expression", 
  "assignment", "assignment_operator", "expression", "non_assignment_expression", 
  "constant_expression", "boolean_expression", "literal", "boolean_literal", 
  "string_literal", "array_initializer", "variable_initializer_list", "right_shift", 
  "right_shift_assignment", "identifier", "all_modifier"
};

std::vector<std::string> XiasParser::_literalNames = {
  "", "", "", "", "", "", "'abstract'", "'as'", "'is'", "'base'", "'bool'", 
  "'break'", "'case'", "'catch'", "'char'", "'class'", "'const'", "'continue'", 
  "'default'", "'do'", "'double'", "'else'", "'enum'", "'extern'", "'explicit'", 
  "'false'", "'finally'", "'float'", "'for'", "'foreach'", "'get'", "'goto'", 
  "'if'", "'implicit'", "'in'", "'int'", "'interface'", "'internal'", "'nameof'", 
  "'namespace'", "'new'", "'null'", "'object'", "'operator'", "'out'", "'override'", 
  "'params'", "'private'", "'protected'", "'public'", "'readonly'", "'ref'", 
  "'return'", "'sealed'", "'set'", "'sizeof'", "'static'", "'string'", "'switch'", 
  "'this'", "'throw'", "'true'", "'try'", "'typeof'", "'uint'", "'using'", 
  "'var'", "'virtual'", "'void'", "'when'", "'where'", "'while'", "", "", 
  "", "", "", "", "", "", "", "", "'{'", "'}'", "'['", "']'", "'('", "')'", 
  "'.'", "','", "':'", "';'", "'+'", "'-'", "'*'", "'/'", "'%'", "'&'", 
  "'|'", "'^'", "'!'", "'~'", "'='", "'<'", "'>'", "'\u003F'", "'::'", "'\u003F\u003F'", 
  "'++'", "'--'", "'&&'", "'||'", "'->'", "'=='", "'!='", "'<='", "'>='", 
  "'+='", "'-='", "'*='", "'/='", "'%='", "'&='", "'|='", "'^='", "'<<'", 
  "'<<='", "'\u003F\u003F='", "'''", "'\"'", "'\\'", "'\\\\'", "'#'"
};

std::vector<std::string> XiasParser::_symbolicNames = {
  "", "WHITESPACES", "SINGLE_LINE_DOC_COMMENT", "DELIMITED_DOC_COMMENT", 
  "SINGLE_LINE_COMMENT", "DELIMITED_COMMENT", "ABSTRACT", "AS", "IS", "BASE", 
  "BOOL", "BREAK", "CASE", "CATCH", "CHAR", "CLASS", "CONST", "CONTINUE", 
  "DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM", "EXTERN", "EXPLICIT", "FALSE", 
  "FINALLY", "FLOAT", "FOR", "FOREACH", "GET", "GOTO", "IF", "IMPLICIT", 
  "IN", "INT", "INTERFACE", "INTERNAL", "NAMEOF", "NAMESPACE", "NEW", "NULL_", 
  "OBJECT", "OPERATOR", "OUT", "OVERRIDE", "PARAMS", "PRIVATE", "PROTECTED", 
  "PUBLIC", "READONLY", "REF", "RETURN", "SEALED", "SET", "SIZEOF", "STATIC", 
  "STRING", "SWITCH", "THIS", "THROW", "TRUE", "TRY", "TYPEOF", "UINT", 
  "USING", "VAR", "VIRTUAL", "VOID", "WHEN", "WHERE", "WHILE", "IDENTIFIER", 
  "LITERAL_ACCESS", "INTEGER_LITERAL", "UNSIGNED_LITERAL", "HEX_INTEGER_LITERAL", 
  "FLOAT_LITERAL", "DOUBLE_LITERAL", "CHARACTER_LITERAL", "REGULAR_STRING", 
  "VERBATIUM_STRING", "OPEN_BRACE", "CLOSE_BRACE", "OPEN_BRACKET", "CLOSE_BRACKET", 
  "OPEN_PARENS", "CLOSE_PARENS", "DOT", "COMMA", "COLON", "SEMICOLON", "PLUS", 
  "MINUS", "STAR", "DIV", "PERCENT", "AMP", "BITWISE_OR", "CARET", "BANG", 
  "TILDE", "ASSIGNMENT", "LT", "GT", "INTERR", "DOUBLE_COLON", "OP_COALESCING", 
  "OP_INC", "OP_DEC", "OP_AND", "OP_OR", "OP_PTR", "OP_EQ", "OP_NE", "OP_LE", 
  "OP_GE", "OP_ADD_ASSIGNMENT", "OP_SUB_ASSIGNMENT", "OP_MULT_ASSIGNMENT", 
  "OP_DIV_ASSIGNMENT", "OP_MOD_ASSIGNMENT", "OP_AND_ASSIGNMENT", "OP_OR_ASSIGNMENT", 
  "OP_XOR_ASSIGNMENT", "OP_LEFT_SHIFT", "OP_LEFT_SHIFT_ASSIGNMENT", "OP_COALESCING_ASSIGNMENT", 
  "QUOTE", "DOUBLE_QUOTE", "BACK_SLASH", "DOUBLE_BACK_SLASH", "SHARP"
};

dfa::Vocabulary XiasParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> XiasParser::_tokenNames;

XiasParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x86, 0x782, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 
       0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 
       0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 
       0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 0x1f, 0x9, 0x1f, 0x4, 0x20, 
       0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 0x9, 0x22, 0x4, 0x23, 
       0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 0x25, 0x4, 0x26, 
       0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 0x4, 0x29, 
       0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 0x2c, 
       0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
       0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 
       0x9, 0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 
       0x9, 0x35, 0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 
       0x9, 0x38, 0x4, 0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 
       0x9, 0x3b, 0x4, 0x3c, 0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 
       0x9, 0x3e, 0x4, 0x3f, 0x9, 0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 
       0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 
       0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 0x46, 0x9, 0x46, 0x4, 0x47, 
       0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 0x9, 0x49, 0x4, 0x4a, 
       0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 0x4c, 0x4, 0x4d, 
       0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 0x4, 0x50, 
       0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x4, 0x53, 
       0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x4, 0x55, 0x9, 0x55, 0x4, 0x56, 
       0x9, 0x56, 0x4, 0x57, 0x9, 0x57, 0x4, 0x58, 0x9, 0x58, 0x4, 0x59, 
       0x9, 0x59, 0x4, 0x5a, 0x9, 0x5a, 0x4, 0x5b, 0x9, 0x5b, 0x4, 0x5c, 
       0x9, 0x5c, 0x4, 0x5d, 0x9, 0x5d, 0x4, 0x5e, 0x9, 0x5e, 0x4, 0x5f, 
       0x9, 0x5f, 0x4, 0x60, 0x9, 0x60, 0x4, 0x61, 0x9, 0x61, 0x4, 0x62, 
       0x9, 0x62, 0x4, 0x63, 0x9, 0x63, 0x4, 0x64, 0x9, 0x64, 0x4, 0x65, 
       0x9, 0x65, 0x4, 0x66, 0x9, 0x66, 0x4, 0x67, 0x9, 0x67, 0x4, 0x68, 
       0x9, 0x68, 0x4, 0x69, 0x9, 0x69, 0x4, 0x6a, 0x9, 0x6a, 0x4, 0x6b, 
       0x9, 0x6b, 0x4, 0x6c, 0x9, 0x6c, 0x4, 0x6d, 0x9, 0x6d, 0x4, 0x6e, 
       0x9, 0x6e, 0x4, 0x6f, 0x9, 0x6f, 0x4, 0x70, 0x9, 0x70, 0x4, 0x71, 
       0x9, 0x71, 0x4, 0x72, 0x9, 0x72, 0x4, 0x73, 0x9, 0x73, 0x4, 0x74, 
       0x9, 0x74, 0x4, 0x75, 0x9, 0x75, 0x4, 0x76, 0x9, 0x76, 0x4, 0x77, 
       0x9, 0x77, 0x4, 0x78, 0x9, 0x78, 0x4, 0x79, 0x9, 0x79, 0x4, 0x7a, 
       0x9, 0x7a, 0x4, 0x7b, 0x9, 0x7b, 0x4, 0x7c, 0x9, 0x7c, 0x4, 0x7d, 
       0x9, 0x7d, 0x4, 0x7e, 0x9, 0x7e, 0x4, 0x7f, 0x9, 0x7f, 0x4, 0x80, 
       0x9, 0x80, 0x4, 0x81, 0x9, 0x81, 0x4, 0x82, 0x9, 0x82, 0x4, 0x83, 
       0x9, 0x83, 0x4, 0x84, 0x9, 0x84, 0x4, 0x85, 0x9, 0x85, 0x4, 0x86, 
       0x9, 0x86, 0x4, 0x87, 0x9, 0x87, 0x4, 0x88, 0x9, 0x88, 0x4, 0x89, 
       0x9, 0x89, 0x4, 0x8a, 0x9, 0x8a, 0x4, 0x8b, 0x9, 0x8b, 0x4, 0x8c, 
       0x9, 0x8c, 0x4, 0x8d, 0x9, 0x8d, 0x4, 0x8e, 0x9, 0x8e, 0x4, 0x8f, 
       0x9, 0x8f, 0x4, 0x90, 0x9, 0x90, 0x4, 0x91, 0x9, 0x91, 0x4, 0x92, 
       0x9, 0x92, 0x4, 0x93, 0x9, 0x93, 0x4, 0x94, 0x9, 0x94, 0x4, 0x95, 
       0x9, 0x95, 0x4, 0x96, 0x9, 0x96, 0x4, 0x97, 0x9, 0x97, 0x4, 0x98, 
       0x9, 0x98, 0x4, 0x99, 0x9, 0x99, 0x4, 0x9a, 0x9, 0x9a, 0x4, 0x9b, 
       0x9, 0x9b, 0x4, 0x9c, 0x9, 0x9c, 0x4, 0x9d, 0x9, 0x9d, 0x4, 0x9e, 
       0x9, 0x9e, 0x4, 0x9f, 0x9, 0x9f, 0x4, 0xa0, 0x9, 0xa0, 0x4, 0xa1, 
       0x9, 0xa1, 0x4, 0xa2, 0x9, 0xa2, 0x4, 0xa3, 0x9, 0xa3, 0x4, 0xa4, 
       0x9, 0xa4, 0x4, 0xa5, 0x9, 0xa5, 0x4, 0xa6, 0x9, 0xa6, 0x4, 0xa7, 
       0x9, 0xa7, 0x4, 0xa8, 0x9, 0xa8, 0x4, 0xa9, 0x9, 0xa9, 0x4, 0xaa, 
       0x9, 0xaa, 0x4, 0xab, 0x9, 0xab, 0x4, 0xac, 0x9, 0xac, 0x4, 0xad, 
       0x9, 0xad, 0x4, 0xae, 0x9, 0xae, 0x4, 0xaf, 0x9, 0xaf, 0x4, 0xb0, 
       0x9, 0xb0, 0x4, 0xb1, 0x9, 0xb1, 0x4, 0xb2, 0x9, 0xb2, 0x4, 0xb3, 
       0x9, 0xb3, 0x4, 0xb4, 0x9, 0xb4, 0x4, 0xb5, 0x9, 0xb5, 0x4, 0xb6, 
       0x9, 0xb6, 0x4, 0xb7, 0x9, 0xb7, 0x4, 0xb8, 0x9, 0xb8, 0x4, 0xb9, 
       0x9, 0xb9, 0x4, 0xba, 0x9, 0xba, 0x4, 0xbb, 0x9, 0xbb, 0x4, 0xbc, 
       0x9, 0xbc, 0x4, 0xbd, 0x9, 0xbd, 0x4, 0xbe, 0x9, 0xbe, 0x4, 0xbf, 
       0x9, 0xbf, 0x4, 0xc0, 0x9, 0xc0, 0x4, 0xc1, 0x9, 0xc1, 0x4, 0xc2, 
       0x9, 0xc2, 0x4, 0xc3, 0x9, 0xc3, 0x4, 0xc4, 0x9, 0xc4, 0x4, 0xc5, 
       0x9, 0xc5, 0x4, 0xc6, 0x9, 0xc6, 0x4, 0xc7, 0x9, 0xc7, 0x4, 0xc8, 
       0x9, 0xc8, 0x4, 0xc9, 0x9, 0xc9, 0x4, 0xca, 0x9, 0xca, 0x4, 0xcb, 
       0x9, 0xcb, 0x4, 0xcc, 0x9, 0xcc, 0x4, 0xcd, 0x9, 0xcd, 0x3, 0x2, 
       0x7, 0x2, 0x19c, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x19f, 0xb, 0x2, 0x3, 
       0x2, 0x7, 0x2, 0x1a2, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x1a5, 0xb, 0x2, 
       0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x1b8, 0xa, 0x3, 
       0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x1bc, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 
       0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x1c2, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 
       0x3, 0x6, 0x7, 0x6, 0x1c7, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x1ca, 0xb, 
       0x6, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x1ce, 0xa, 0x7, 0xc, 0x7, 0xe, 
       0x7, 0x1d1, 0xb, 0x7, 0x3, 0x7, 0x7, 0x7, 0x1d4, 0xa, 0x7, 0xc, 0x7, 
       0xe, 0x7, 0x1d7, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 
       0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x1df, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 
       0x5, 0x9, 0x1e3, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
       0x7, 0xa, 0x1e9, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x1ec, 0xb, 0xa, 0x3, 
       0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 
       0x1f4, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x1f7, 0xb, 0xb, 0x3, 0xb, 0x3, 
       0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
       0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x204, 0xa, 0xe, 0x3, 0xf, 
       0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 
       0x11, 0x3, 0x11, 0x5, 0x11, 0x20f, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 
       0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 
       0x218, 0xa, 0x14, 0x3, 0x14, 0x5, 0x14, 0x21b, 0xa, 0x14, 0x3, 0x14, 
       0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x221, 0xa, 0x14, 0x7, 
       0x14, 0x223, 0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 0x226, 0xb, 0x14, 0x3, 
       0x15, 0x3, 0x15, 0x5, 0x15, 0x22a, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 
       0x5, 0x16, 0x22e, 0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 
       0x17, 0x5, 0x17, 0x234, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 
       0x238, 0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x23c, 0xa, 0x19, 
       0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 
       0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x247, 0xa, 0x1d, 0x3, 
       0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x24c, 0xa, 0x1e, 0x3, 0x1f, 
       0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x6, 0x20, 0x252, 0xa, 0x20, 0xd, 
       0x20, 0xe, 0x20, 0x253, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
       0x5, 0x21, 0x25a, 0xa, 0x21, 0x3, 0x22, 0x3, 0x22, 0x7, 0x22, 0x25e, 
       0xa, 0x22, 0xc, 0x22, 0xe, 0x22, 0x261, 0xb, 0x22, 0x3, 0x22, 0x3, 
       0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 0x7, 
       0x25, 0x26a, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 0x26d, 0xb, 0x25, 0x3, 
       0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x272, 0xa, 0x25, 0x3, 0x25, 
       0x5, 0x25, 0x275, 0xa, 0x25, 0x3, 0x25, 0x7, 0x25, 0x278, 0xa, 0x25, 
       0xc, 0x25, 0xe, 0x25, 0x27b, 0xb, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 
       0x25, 0x27f, 0xa, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 
       0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 
       0x28a, 0xa, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x7, 0x27, 0x28f, 
       0xa, 0x27, 0xc, 0x27, 0xe, 0x27, 0x292, 0xb, 0x27, 0x3, 0x28, 0x3, 
       0x28, 0x7, 0x28, 0x296, 0xa, 0x28, 0xc, 0x28, 0xe, 0x28, 0x299, 0xb, 
       0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 
       0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 
       0x29, 0x5, 0x29, 0x2a7, 0xa, 0x29, 0x3, 0x2a, 0x7, 0x2a, 0x2aa, 0xa, 
       0x2a, 0xc, 0x2a, 0xe, 0x2a, 0x2ad, 0xb, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 
       0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x7, 0x2b, 0x2b5, 0xa, 
       0x2b, 0xc, 0x2b, 0xe, 0x2b, 0x2b8, 0xb, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
       0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x7, 0x2c, 
       0x2c1, 0xa, 0x2c, 0xc, 0x2c, 0xe, 0x2c, 0x2c4, 0xb, 0x2c, 0x3, 0x2d, 
       0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x2c9, 0xa, 0x2d, 0x3, 0x2e, 0x3, 
       0x2e, 0x5, 0x2e, 0x2cd, 0xa, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
       0x3, 0x30, 0x7, 0x30, 0x2d3, 0xa, 0x30, 0xc, 0x30, 0xe, 0x30, 0x2d6, 
       0xb, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 0x2db, 0xa, 
       0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 0x2df, 0xa, 0x30, 0x3, 0x30, 
       0x3, 0x30, 0x7, 0x30, 0x2e3, 0xa, 0x30, 0xc, 0x30, 0xe, 0x30, 0x2e6, 
       0xb, 0x30, 0x3, 0x31, 0x3, 0x31, 0x5, 0x31, 0x2ea, 0xa, 0x31, 0x3, 
       0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 0x2f1, 
       0xa, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 
       0x7, 0x34, 0x2f8, 0xa, 0x34, 0xc, 0x34, 0xe, 0x34, 0x2fb, 0xb, 0x34, 
       0x3, 0x35, 0x5, 0x35, 0x2fe, 0xa, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 
       0x35, 0x5, 0x35, 0x303, 0xa, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 
       0x3, 0x37, 0x3, 0x37, 0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x30c, 0xa, 
       0x38, 0x3, 0x39, 0x7, 0x39, 0x30f, 0xa, 0x39, 0xc, 0x39, 0xe, 0x39, 
       0x312, 0xb, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 
       0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x31c, 0xa, 0x3a, 
       0x3, 0x3b, 0x3, 0x3b, 0x5, 0x3b, 0x320, 0xa, 0x3b, 0x3, 0x3b, 0x3, 
       0x3b, 0x5, 0x3b, 0x324, 0xa, 0x3b, 0x5, 0x3b, 0x326, 0xa, 0x3b, 0x3, 
       0x3c, 0x5, 0x3c, 0x329, 0xa, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
       0x3, 0x3d, 0x5, 0x3d, 0x32f, 0xa, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 
       0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 
       0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x33b, 0xa, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 
       0x5, 0x3f, 0x33f, 0xa, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 
       0x40, 0x3, 0x41, 0x7, 0x41, 0x346, 0xa, 0x41, 0xc, 0x41, 0xe, 0x41, 
       0x349, 0xb, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x42, 0x3, 
       0x42, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 
       0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 
       0x43, 0x3, 0x43, 0x3, 0x43, 0x5, 0x43, 0x35e, 0xa, 0x43, 0x3, 0x44, 
       0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x45, 0x6, 0x45, 0x365, 0xa, 
       0x45, 0xd, 0x45, 0xe, 0x45, 0x366, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 
       0x3, 0x46, 0x3, 0x46, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x5, 0x47, 
       0x371, 0xa, 0x47, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 
       0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x49, 0x3, 0x49, 0x3, 
       0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 
       0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4b, 0x3, 
       0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 
       0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 
       0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x5, 0x4b, 0x398, 0xa, 0x4b, 0x3, 0x4c, 
       0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 
       0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 
       0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x5, 0x4c, 0x3aa, 0xa, 0x4c, 0x3, 
       0x4d, 0x3, 0x4d, 0x5, 0x4d, 0x3ae, 0xa, 0x4d, 0x3, 0x4e, 0x7, 0x4e, 
       0x3b1, 0xa, 0x4e, 0xc, 0x4e, 0xe, 0x4e, 0x3b4, 0xb, 0x4e, 0x3, 0x4e, 
       0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x50, 0x3, 0x50, 
       0x3, 0x50, 0x5, 0x50, 0x3be, 0xa, 0x50, 0x3, 0x50, 0x3, 0x50, 0x5, 
       0x50, 0x3c2, 0xa, 0x50, 0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 
       0x5, 0x51, 0x3c8, 0xa, 0x51, 0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x3, 
       0x51, 0x3, 0x51, 0x5, 0x51, 0x3cf, 0xa, 0x51, 0x3, 0x51, 0x5, 0x51, 
       0x3d2, 0xa, 0x51, 0x3, 0x52, 0x3, 0x52, 0x5, 0x52, 0x3d6, 0xa, 0x52, 
       0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 
       0x3, 0x54, 0x3, 0x54, 0x3, 0x55, 0x3, 0x55, 0x5, 0x55, 0x3e2, 0xa, 
       0x55, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 
       0x56, 0x3, 0x57, 0x3, 0x57, 0x5, 0x57, 0x3ec, 0xa, 0x57, 0x3, 0x58, 
       0x7, 0x58, 0x3ef, 0xa, 0x58, 0xc, 0x58, 0xe, 0x58, 0x3f2, 0xb, 0x58, 
       0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x5, 0x58, 0x3f7, 0xa, 0x58, 0x3, 
       0x58, 0x5, 0x58, 0x3fa, 0xa, 0x58, 0x3, 0x58, 0x7, 0x58, 0x3fd, 0xa, 
       0x58, 0xc, 0x58, 0xe, 0x58, 0x400, 0xb, 0x58, 0x3, 0x58, 0x3, 0x58, 
       0x5, 0x58, 0x404, 0xa, 0x58, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 
       0x59, 0x3, 0x5a, 0x3, 0x5a, 0x5, 0x5a, 0x40c, 0xa, 0x5a, 0x3, 0x5a, 
       0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x5, 0x5a, 0x413, 0xa, 
       0x5a, 0x3, 0x5a, 0x7, 0x5a, 0x416, 0xa, 0x5a, 0xc, 0x5a, 0xe, 0x5a, 
       0x419, 0xb, 0x5a, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5c, 0x3, 0x5c, 0x3, 
       0x5c, 0x3, 0x5d, 0x3, 0x5d, 0x7, 0x5d, 0x422, 0xa, 0x5d, 0xc, 0x5d, 
       0xe, 0x5d, 0x425, 0xb, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5e, 0x3, 
       0x5e, 0x3, 0x5e, 0x5, 0x5e, 0x42c, 0xa, 0x5e, 0x3, 0x5f, 0x5, 0x5f, 
       0x42f, 0xa, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x3, 
       0x5f, 0x5, 0x5f, 0x436, 0xa, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x7, 0x5f, 
       0x43a, 0xa, 0x5f, 0xc, 0x5f, 0xe, 0x5f, 0x43d, 0xb, 0x5f, 0x3, 0x5f, 
       0x3, 0x5f, 0x3, 0x60, 0x5, 0x60, 0x442, 0xa, 0x60, 0x3, 0x60, 0x3, 
       0x60, 0x3, 0x60, 0x3, 0x60, 0x3, 0x60, 0x3, 0x60, 0x3, 0x61, 0x3, 
       0x61, 0x3, 0x61, 0x3, 0x61, 0x3, 0x61, 0x3, 0x61, 0x3, 0x61, 0x3, 
       0x61, 0x3, 0x61, 0x3, 0x61, 0x3, 0x61, 0x3, 0x61, 0x5, 0x61, 0x456, 
       0xa, 0x61, 0x3, 0x62, 0x5, 0x62, 0x459, 0xa, 0x62, 0x3, 0x62, 0x3, 
       0x62, 0x3, 0x62, 0x3, 0x62, 0x3, 0x62, 0x3, 0x62, 0x3, 0x62, 0x3, 
       0x62, 0x3, 0x62, 0x3, 0x63, 0x3, 0x63, 0x5, 0x63, 0x466, 0xa, 0x63, 
       0x3, 0x63, 0x3, 0x63, 0x3, 0x64, 0x6, 0x64, 0x46b, 0xa, 0x64, 0xd, 
       0x64, 0xe, 0x64, 0x46c, 0x3, 0x65, 0x3, 0x65, 0x3, 0x65, 0x5, 0x65, 
       0x472, 0xa, 0x65, 0x3, 0x66, 0x3, 0x66, 0x3, 0x66, 0x3, 0x66, 0x3, 
       0x67, 0x3, 0x67, 0x3, 0x67, 0x3, 0x67, 0x3, 0x67, 0x3, 0x67, 0x5, 
       0x67, 0x47e, 0xa, 0x67, 0x3, 0x68, 0x3, 0x68, 0x3, 0x68, 0x3, 0x69, 
       0x3, 0x69, 0x5, 0x69, 0x485, 0xa, 0x69, 0x3, 0x6a, 0x3, 0x6a, 0x3, 
       0x6a, 0x7, 0x6a, 0x48a, 0xa, 0x6a, 0xc, 0x6a, 0xe, 0x6a, 0x48d, 0xb, 
       0x6a, 0x3, 0x6b, 0x3, 0x6b, 0x3, 0x6b, 0x3, 0x6b, 0x3, 0x6b, 0x5, 
       0x6b, 0x494, 0xa, 0x6b, 0x3, 0x6c, 0x3, 0x6c, 0x5, 0x6c, 0x498, 0xa, 
       0x6c, 0x3, 0x6d, 0x3, 0x6d, 0x3, 0x6d, 0x3, 0x6d, 0x3, 0x6e, 0x3, 
       0x6e, 0x3, 0x6e, 0x7, 0x6e, 0x4a1, 0xa, 0x6e, 0xc, 0x6e, 0xe, 0x6e, 
       0x4a4, 0xb, 0x6e, 0x3, 0x6f, 0x3, 0x6f, 0x3, 0x6f, 0x3, 0x6f, 0x3, 
       0x70, 0x3, 0x70, 0x3, 0x70, 0x3, 0x70, 0x3, 0x70, 0x3, 0x70, 0x3, 
       0x70, 0x5, 0x70, 0x4b1, 0xa, 0x70, 0x3, 0x71, 0x3, 0x71, 0x3, 0x72, 
       0x3, 0x72, 0x3, 0x72, 0x3, 0x73, 0x3, 0x73, 0x3, 0x73, 0x3, 0x73, 
       0x3, 0x73, 0x3, 0x73, 0x3, 0x73, 0x5, 0x73, 0x4bf, 0xa, 0x73, 0x3, 
       0x74, 0x3, 0x74, 0x5, 0x74, 0x4c3, 0xa, 0x74, 0x3, 0x75, 0x3, 0x75, 
       0x3, 0x75, 0x3, 0x75, 0x3, 0x75, 0x3, 0x75, 0x3, 0x75, 0x3, 0x75, 
       0x3, 0x75, 0x3, 0x75, 0x3, 0x75, 0x3, 0x75, 0x3, 0x75, 0x3, 0x75, 
       0x5, 0x75, 0x4d3, 0xa, 0x75, 0x3, 0x76, 0x3, 0x76, 0x3, 0x76, 0x3, 
       0x76, 0x3, 0x76, 0x3, 0x76, 0x3, 0x77, 0x3, 0x77, 0x7, 0x77, 0x4dd, 
       0xa, 0x77, 0xc, 0x77, 0xe, 0x77, 0x4e0, 0xb, 0x77, 0x3, 0x77, 0x3, 
       0x77, 0x3, 0x78, 0x6, 0x78, 0x4e5, 0xa, 0x78, 0xd, 0x78, 0xe, 0x78, 
       0x4e6, 0x3, 0x78, 0x3, 0x78, 0x3, 0x79, 0x3, 0x79, 0x3, 0x79, 0x3, 
       0x79, 0x3, 0x79, 0x3, 0x79, 0x5, 0x79, 0x4f1, 0xa, 0x79, 0x3, 0x7a, 
       0x3, 0x7a, 0x3, 0x7a, 0x3, 0x7a, 0x5, 0x7a, 0x4f7, 0xa, 0x7a, 0x3, 
       0x7b, 0x3, 0x7b, 0x3, 0x7b, 0x3, 0x7b, 0x3, 0x7b, 0x3, 0x7b, 0x3, 
       0x7c, 0x3, 0x7c, 0x3, 0x7c, 0x3, 0x7c, 0x3, 0x7c, 0x3, 0x7c, 0x3, 
       0x7c, 0x3, 0x7c, 0x3, 0x7d, 0x3, 0x7d, 0x3, 0x7d, 0x5, 0x7d, 0x50a, 
       0xa, 0x7d, 0x3, 0x7d, 0x3, 0x7d, 0x5, 0x7d, 0x50e, 0xa, 0x7d, 0x3, 
       0x7d, 0x3, 0x7d, 0x5, 0x7d, 0x512, 0xa, 0x7d, 0x3, 0x7d, 0x3, 0x7d, 
       0x3, 0x7d, 0x3, 0x7e, 0x3, 0x7e, 0x5, 0x7e, 0x519, 0xa, 0x7e, 0x3, 
       0x7f, 0x3, 0x7f, 0x3, 0x80, 0x3, 0x80, 0x3, 0x81, 0x3, 0x81, 0x3, 
       0x81, 0x7, 0x81, 0x522, 0xa, 0x81, 0xc, 0x81, 0xe, 0x81, 0x525, 0xb, 
       0x81, 0x3, 0x82, 0x3, 0x82, 0x3, 0x82, 0x3, 0x82, 0x3, 0x82, 0x3, 
       0x82, 0x3, 0x82, 0x3, 0x82, 0x3, 0x82, 0x3, 0x83, 0x3, 0x83, 0x3, 
       0x83, 0x3, 0x83, 0x3, 0x83, 0x5, 0x83, 0x535, 0xa, 0x83, 0x3, 0x84, 
       0x3, 0x84, 0x3, 0x84, 0x3, 0x85, 0x3, 0x85, 0x3, 0x85, 0x3, 0x86, 
       0x3, 0x86, 0x3, 0x86, 0x3, 0x86, 0x3, 0x86, 0x3, 0x86, 0x3, 0x86, 
       0x3, 0x86, 0x3, 0x86, 0x3, 0x86, 0x3, 0x86, 0x3, 0x86, 0x5, 0x86, 
       0x549, 0xa, 0x86, 0x3, 0x87, 0x3, 0x87, 0x5, 0x87, 0x54d, 0xa, 0x87, 
       0x3, 0x87, 0x3, 0x87, 0x3, 0x88, 0x3, 0x88, 0x5, 0x88, 0x553, 0xa, 
       0x88, 0x3, 0x88, 0x3, 0x88, 0x3, 0x89, 0x3, 0x89, 0x3, 0x89, 0x6, 
       0x89, 0x55a, 0xa, 0x89, 0xd, 0x89, 0xe, 0x89, 0x55b, 0x3, 0x89, 0x3, 
       0x89, 0x3, 0x89, 0x3, 0x89, 0x3, 0x89, 0x3, 0x89, 0x3, 0x89, 0x6, 
       0x89, 0x565, 0xa, 0x89, 0xd, 0x89, 0xe, 0x89, 0x566, 0x3, 0x89, 0x3, 
       0x89, 0x5, 0x89, 0x56b, 0xa, 0x89, 0x3, 0x8a, 0x3, 0x8a, 0x5, 0x8a, 
       0x56f, 0xa, 0x8a, 0x3, 0x8a, 0x5, 0x8a, 0x572, 0xa, 0x8a, 0x3, 0x8a, 
       0x3, 0x8a, 0x3, 0x8b, 0x3, 0x8b, 0x3, 0x8b, 0x5, 0x8b, 0x579, 0xa, 
       0x8b, 0x3, 0x8b, 0x3, 0x8b, 0x3, 0x8c, 0x3, 0x8c, 0x3, 0x8c, 0x3, 
       0x8c, 0x3, 0x8c, 0x3, 0x8d, 0x3, 0x8d, 0x3, 0x8d, 0x3, 0x8e, 0x3, 
       0x8e, 0x3, 0x8e, 0x7, 0x8e, 0x588, 0xa, 0x8e, 0xc, 0x8e, 0xe, 0x8e, 
       0x58b, 0xb, 0x8e, 0x3, 0x8f, 0x3, 0x8f, 0x5, 0x8f, 0x58f, 0xa, 0x8f, 
       0x3, 0x90, 0x3, 0x90, 0x5, 0x90, 0x593, 0xa, 0x90, 0x3, 0x91, 0x3, 
       0x91, 0x3, 0x91, 0x3, 0x91, 0x3, 0x91, 0x3, 0x91, 0x3, 0x91, 0x3, 
       0x91, 0x5, 0x91, 0x59d, 0xa, 0x91, 0x3, 0x92, 0x3, 0x92, 0x3, 0x92, 
       0x3, 0x92, 0x3, 0x92, 0x5, 0x92, 0x5a4, 0xa, 0x92, 0x3, 0x93, 0x3, 
       0x93, 0x5, 0x93, 0x5a8, 0xa, 0x93, 0x3, 0x94, 0x3, 0x94, 0x3, 0x94, 
       0x3, 0x94, 0x3, 0x95, 0x3, 0x95, 0x3, 0x95, 0x3, 0x95, 0x5, 0x95, 
       0x5b2, 0xa, 0x95, 0x3, 0x95, 0x3, 0x95, 0x3, 0x95, 0x3, 0x95, 0x5, 
       0x95, 0x5b8, 0xa, 0x95, 0x3, 0x95, 0x3, 0x95, 0x3, 0x95, 0x3, 0x95, 
       0x5, 0x95, 0x5be, 0xa, 0x95, 0x3, 0x96, 0x3, 0x96, 0x3, 0x96, 0x5, 
       0x96, 0x5c3, 0xa, 0x96, 0x3, 0x96, 0x3, 0x96, 0x3, 0x97, 0x3, 0x97, 
       0x3, 0x97, 0x3, 0x97, 0x3, 0x97, 0x3, 0x98, 0x3, 0x98, 0x3, 0x99, 
       0x3, 0x99, 0x3, 0x99, 0x3, 0x99, 0x3, 0x99, 0x3, 0x99, 0x3, 0x99, 
       0x3, 0x99, 0x5, 0x99, 0x5d6, 0xa, 0x99, 0x3, 0x9a, 0x3, 0x9a, 0x3, 
       0x9a, 0x3, 0x9b, 0x3, 0x9b, 0x3, 0x9b, 0x3, 0x9c, 0x3, 0x9c, 0x3, 
       0x9c, 0x3, 0x9c, 0x5, 0x9c, 0x5e2, 0xa, 0x9c, 0x3, 0x9c, 0x3, 0x9c, 
       0x5, 0x9c, 0x5e6, 0xa, 0x9c, 0x3, 0x9c, 0x3, 0x9c, 0x3, 0x9c, 0x3, 
       0x9c, 0x5, 0x9c, 0x5ec, 0xa, 0x9c, 0x3, 0x9d, 0x3, 0x9d, 0x5, 0x9d, 
       0x5f0, 0xa, 0x9d, 0x3, 0x9e, 0x3, 0x9e, 0x5, 0x9e, 0x5f4, 0xa, 0x9e, 
       0x3, 0x9e, 0x3, 0x9e, 0x3, 0x9e, 0x3, 0x9e, 0x3, 0x9e, 0x3, 0x9e, 
       0x5, 0x9e, 0x5fc, 0xa, 0x9e, 0x3, 0x9f, 0x3, 0x9f, 0x3, 0x9f, 0x7, 
       0x9f, 0x601, 0xa, 0x9f, 0xc, 0x9f, 0xe, 0x9f, 0x604, 0xb, 0x9f, 0x3, 
       0xa0, 0x3, 0xa0, 0x3, 0xa0, 0x3, 0xa0, 0x3, 0xa1, 0x3, 0xa1, 0x5, 
       0xa1, 0x60c, 0xa, 0xa1, 0x3, 0xa2, 0x3, 0xa2, 0x3, 0xa2, 0x3, 0xa2, 
       0x3, 0xa2, 0x3, 0xa2, 0x3, 0xa2, 0x3, 0xa2, 0x3, 0xa2, 0x5, 0xa2, 
       0x617, 0xa, 0xa2, 0x3, 0xa3, 0x3, 0xa3, 0x3, 0xa3, 0x7, 0xa3, 0x61c, 
       0xa, 0xa3, 0xc, 0xa3, 0xe, 0xa3, 0x61f, 0xb, 0xa3, 0x3, 0xa4, 0x3, 
       0xa4, 0x3, 0xa4, 0x3, 0xa4, 0x3, 0xa4, 0x5, 0xa4, 0x626, 0xa, 0xa4, 
       0x3, 0xa5, 0x3, 0xa5, 0x3, 0xa5, 0x7, 0xa5, 0x62b, 0xa, 0xa5, 0xc, 
       0xa5, 0xe, 0xa5, 0x62e, 0xb, 0xa5, 0x3, 0xa6, 0x3, 0xa6, 0x3, 0xa6, 
       0x3, 0xa6, 0x3, 0xa6, 0x3, 0xa6, 0x3, 0xa6, 0x3, 0xa6, 0x3, 0xa6, 
       0x3, 0xa6, 0x3, 0xa6, 0x3, 0xa6, 0x3, 0xa6, 0x3, 0xa6, 0x5, 0xa6, 
       0x63e, 0xa, 0xa6, 0x3, 0xa7, 0x3, 0xa7, 0x3, 0xa7, 0x5, 0xa7, 0x643, 
       0xa, 0xa7, 0x3, 0xa7, 0x3, 0xa7, 0x3, 0xa7, 0x3, 0xa7, 0x5, 0xa7, 
       0x649, 0xa, 0xa7, 0x5, 0xa7, 0x64b, 0xa, 0xa7, 0x3, 0xa7, 0x3, 0xa7, 
       0x3, 0xa7, 0x3, 0xa7, 0x5, 0xa7, 0x651, 0xa, 0xa7, 0x7, 0xa7, 0x653, 
       0xa, 0xa7, 0xc, 0xa7, 0xe, 0xa7, 0x656, 0xb, 0xa7, 0x3, 0xa8, 0x3, 
       0xa8, 0x7, 0xa8, 0x65a, 0xa, 0xa8, 0xc, 0xa8, 0xe, 0xa8, 0x65d, 0xb, 
       0xa8, 0x3, 0xa8, 0x3, 0xa8, 0x3, 0xa9, 0x3, 0xa9, 0x3, 0xa9, 0x3, 
       0xa9, 0x3, 0xa9, 0x3, 0xaa, 0x3, 0xaa, 0x3, 0xaa, 0x3, 0xaa, 0x3, 
       0xaa, 0x3, 0xaa, 0x7, 0xaa, 0x66c, 0xa, 0xaa, 0xc, 0xaa, 0xe, 0xaa, 
       0x66f, 0xb, 0xaa, 0x3, 0xaa, 0x5, 0xaa, 0x672, 0xa, 0xaa, 0x3, 0xaa, 
       0x3, 0xaa, 0x3, 0xaa, 0x3, 0xaa, 0x5, 0xaa, 0x678, 0xa, 0xaa, 0x3, 
       0xab, 0x3, 0xab, 0x3, 0xab, 0x3, 0xab, 0x3, 0xab, 0x3, 0xab, 0x3, 
       0xab, 0x3, 0xab, 0x5, 0xab, 0x682, 0xa, 0xab, 0x3, 0xac, 0x3, 0xac, 
       0x3, 0xac, 0x3, 0xad, 0x3, 0xad, 0x3, 0xad, 0x3, 0xae, 0x3, 0xae, 
       0x3, 0xae, 0x3, 0xaf, 0x3, 0xaf, 0x3, 0xaf, 0x3, 0xb0, 0x3, 0xb0, 
       0x3, 0xb0, 0x3, 0xb1, 0x3, 0xb1, 0x3, 0xb1, 0x3, 0xb2, 0x3, 0xb2, 
       0x3, 0xb2, 0x3, 0xb2, 0x3, 0xb2, 0x3, 0xb3, 0x3, 0xb3, 0x3, 0xb3, 
       0x3, 0xb3, 0x3, 0xb3, 0x3, 0xb3, 0x3, 0xb3, 0x3, 0xb3, 0x3, 0xb3, 
       0x3, 0xb3, 0x3, 0xb3, 0x3, 0xb3, 0x7, 0xb3, 0x6a7, 0xa, 0xb3, 0xc, 
       0xb3, 0xe, 0xb3, 0x6aa, 0xb, 0xb3, 0x3, 0xb4, 0x3, 0xb4, 0x3, 0xb4, 
       0x3, 0xb4, 0x3, 0xb4, 0x3, 0xb4, 0x3, 0xb4, 0x3, 0xb4, 0x3, 0xb4, 
       0x7, 0xb4, 0x6b5, 0xa, 0xb4, 0xc, 0xb4, 0xe, 0xb4, 0x6b8, 0xb, 0xb4, 
       0x3, 0xb5, 0x3, 0xb5, 0x3, 0xb5, 0x3, 0xb5, 0x3, 0xb5, 0x3, 0xb5, 
       0x3, 0xb5, 0x3, 0xb5, 0x3, 0xb5, 0x3, 0xb5, 0x7, 0xb5, 0x6c4, 0xa, 
       0xb5, 0xc, 0xb5, 0xe, 0xb5, 0x6c7, 0xb, 0xb5, 0x3, 0xb6, 0x3, 0xb6, 
       0x3, 0xb6, 0x3, 0xb6, 0x3, 0xb6, 0x3, 0xb6, 0x3, 0xb6, 0x3, 0xb6, 
       0x3, 0xb6, 0x3, 0xb6, 0x3, 0xb6, 0x3, 0xb6, 0x3, 0xb6, 0x3, 0xb6, 
       0x3, 0xb6, 0x3, 0xb6, 0x3, 0xb6, 0x3, 0xb6, 0x3, 0xb6, 0x3, 0xb6, 
       0x3, 0xb6, 0x7, 0xb6, 0x6de, 0xa, 0xb6, 0xc, 0xb6, 0xe, 0xb6, 0x6e1, 
       0xb, 0xb6, 0x3, 0xb7, 0x3, 0xb7, 0x3, 0xb7, 0x3, 0xb7, 0x3, 0xb7, 
       0x3, 0xb7, 0x3, 0xb7, 0x3, 0xb7, 0x3, 0xb7, 0x7, 0xb7, 0x6ec, 0xa, 
       0xb7, 0xc, 0xb7, 0xe, 0xb7, 0x6ef, 0xb, 0xb7, 0x3, 0xb8, 0x3, 0xb8, 
       0x3, 0xb8, 0x3, 0xb8, 0x3, 0xb8, 0x3, 0xb8, 0x7, 0xb8, 0x6f7, 0xa, 
       0xb8, 0xc, 0xb8, 0xe, 0xb8, 0x6fa, 0xb, 0xb8, 0x3, 0xb9, 0x3, 0xb9, 
       0x3, 0xb9, 0x3, 0xb9, 0x3, 0xb9, 0x3, 0xb9, 0x7, 0xb9, 0x702, 0xa, 
       0xb9, 0xc, 0xb9, 0xe, 0xb9, 0x705, 0xb, 0xb9, 0x3, 0xba, 0x3, 0xba, 
       0x3, 0xba, 0x3, 0xba, 0x3, 0xba, 0x3, 0xba, 0x7, 0xba, 0x70d, 0xa, 
       0xba, 0xc, 0xba, 0xe, 0xba, 0x710, 0xb, 0xba, 0x3, 0xbb, 0x3, 0xbb, 
       0x3, 0xbb, 0x3, 0xbb, 0x3, 0xbb, 0x3, 0xbb, 0x7, 0xbb, 0x718, 0xa, 
       0xbb, 0xc, 0xbb, 0xe, 0xbb, 0x71b, 0xb, 0xbb, 0x3, 0xbc, 0x3, 0xbc, 
       0x3, 0xbc, 0x3, 0xbc, 0x3, 0xbc, 0x3, 0xbc, 0x7, 0xbc, 0x723, 0xa, 
       0xbc, 0xc, 0xbc, 0xe, 0xbc, 0x726, 0xb, 0xbc, 0x3, 0xbd, 0x3, 0xbd, 
       0x3, 0xbd, 0x3, 0xbd, 0x3, 0xbd, 0x5, 0xbd, 0x72d, 0xa, 0xbd, 0x3, 
       0xbe, 0x3, 0xbe, 0x3, 0xbe, 0x3, 0xbe, 0x3, 0xbe, 0x3, 0xbe, 0x3, 
       0xbe, 0x5, 0xbe, 0x736, 0xa, 0xbe, 0x3, 0xbf, 0x3, 0xbf, 0x3, 0xbf, 
       0x3, 0xbf, 0x3, 0xc0, 0x3, 0xc0, 0x3, 0xc0, 0x3, 0xc0, 0x3, 0xc0, 
       0x3, 0xc0, 0x3, 0xc0, 0x3, 0xc0, 0x3, 0xc0, 0x3, 0xc0, 0x3, 0xc0, 
       0x5, 0xc0, 0x747, 0xa, 0xc0, 0x3, 0xc1, 0x3, 0xc1, 0x5, 0xc1, 0x74b, 
       0xa, 0xc1, 0x3, 0xc2, 0x3, 0xc2, 0x3, 0xc3, 0x3, 0xc3, 0x3, 0xc4, 
       0x3, 0xc4, 0x3, 0xc5, 0x3, 0xc5, 0x3, 0xc5, 0x3, 0xc5, 0x3, 0xc5, 
       0x3, 0xc5, 0x3, 0xc5, 0x3, 0xc5, 0x3, 0xc5, 0x5, 0xc5, 0x75c, 0xa, 
       0xc5, 0x3, 0xc6, 0x3, 0xc6, 0x3, 0xc7, 0x3, 0xc7, 0x3, 0xc8, 0x3, 
       0xc8, 0x5, 0xc8, 0x764, 0xa, 0xc8, 0x3, 0xc8, 0x3, 0xc8, 0x3, 0xc8, 
       0x3, 0xc8, 0x3, 0xc8, 0x3, 0xc8, 0x5, 0xc8, 0x76c, 0xa, 0xc8, 0x3, 
       0xc9, 0x3, 0xc9, 0x3, 0xc9, 0x7, 0xc9, 0x771, 0xa, 0xc9, 0xc, 0xc9, 
       0xe, 0xc9, 0x774, 0xb, 0xc9, 0x3, 0xca, 0x3, 0xca, 0x3, 0xca, 0x3, 
       0xca, 0x3, 0xcb, 0x3, 0xcb, 0x3, 0xcb, 0x3, 0xcb, 0x3, 0xcc, 0x3, 
       0xcc, 0x3, 0xcd, 0x3, 0xcd, 0x3, 0xcd, 0x2, 0xf, 0x26, 0xb2, 0x14c, 
       0x164, 0x166, 0x168, 0x16a, 0x16c, 0x16e, 0x170, 0x172, 0x174, 0x176, 
       0xce, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 
       0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 
       0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 
       0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 
       0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 
       0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 
       0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 
       0x9c, 0x9e, 0xa0, 0xa2, 0xa4, 0xa6, 0xa8, 0xaa, 0xac, 0xae, 0xb0, 
       0xb2, 0xb4, 0xb6, 0xb8, 0xba, 0xbc, 0xbe, 0xc0, 0xc2, 0xc4, 0xc6, 
       0xc8, 0xca, 0xcc, 0xce, 0xd0, 0xd2, 0xd4, 0xd6, 0xd8, 0xda, 0xdc, 
       0xde, 0xe0, 0xe2, 0xe4, 0xe6, 0xe8, 0xea, 0xec, 0xee, 0xf0, 0xf2, 
       0xf4, 0xf6, 0xf8, 0xfa, 0xfc, 0xfe, 0x100, 0x102, 0x104, 0x106, 0x108, 
       0x10a, 0x10c, 0x10e, 0x110, 0x112, 0x114, 0x116, 0x118, 0x11a, 0x11c, 
       0x11e, 0x120, 0x122, 0x124, 0x126, 0x128, 0x12a, 0x12c, 0x12e, 0x130, 
       0x132, 0x134, 0x136, 0x138, 0x13a, 0x13c, 0x13e, 0x140, 0x142, 0x144, 
       0x146, 0x148, 0x14a, 0x14c, 0x14e, 0x150, 0x152, 0x154, 0x156, 0x158, 
       0x15a, 0x15c, 0x15e, 0x160, 0x162, 0x164, 0x166, 0x168, 0x16a, 0x16c, 
       0x16e, 0x170, 0x172, 0x174, 0x176, 0x178, 0x17a, 0x17c, 0x17e, 0x180, 
       0x182, 0x184, 0x186, 0x188, 0x18a, 0x18c, 0x18e, 0x190, 0x192, 0x194, 
       0x196, 0x198, 0x2, 0xe, 0x5, 0x2, 0x27, 0x27, 0x2a, 0x2a, 0x31, 0x33, 
       0x5, 0x2, 0x10, 0x10, 0x25, 0x25, 0x42, 0x42, 0x4, 0x2, 0x16, 0x16, 
       0x1d, 0x1d, 0xa, 0x2, 0xc, 0xc, 0x10, 0x10, 0x16, 0x16, 0x1d, 0x1d, 
       0x25, 0x25, 0x2c, 0x2c, 0x3b, 0x3b, 0x42, 0x42, 0xa, 0x2, 0x8, 0x8, 
       0x27, 0x27, 0x2a, 0x2a, 0x2f, 0x2f, 0x31, 0x33, 0x37, 0x37, 0x3a, 
       0x3a, 0x45, 0x45, 0x4, 0x2, 0x33, 0x33, 0x3a, 0x3a, 0x7, 0x2, 0x1b, 
       0x1b, 0x3f, 0x3f, 0x5e, 0x5f, 0x66, 0x67, 0x6e, 0x6f, 0x4, 0x2, 0x27, 
       0x27, 0x31, 0x33, 0x4, 0x2, 0x24, 0x24, 0x2e, 0x2e, 0x4, 0x2, 0x1b, 
       0x1b, 0x3f, 0x3f, 0x3, 0x2, 0x52, 0x53, 0xa, 0x2, 0x8, 0x8, 0x19, 
       0x19, 0x2a, 0x2a, 0x2f, 0x2f, 0x31, 0x34, 0x37, 0x37, 0x3a, 0x3a, 
       0x45, 0x45, 0x2, 0x7c8, 0x2, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x4, 0x1b7, 
       0x3, 0x2, 0x2, 0x2, 0x6, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x8, 0x1bd, 0x3, 
       0x2, 0x2, 0x2, 0xa, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0xc, 0x1cb, 0x3, 0x2, 
       0x2, 0x2, 0xe, 0x1da, 0x3, 0x2, 0x2, 0x2, 0x10, 0x1e2, 0x3, 0x2, 
       0x2, 0x2, 0x12, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x14, 0x1ef, 0x3, 0x2, 
       0x2, 0x2, 0x16, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x18, 0x1fc, 0x3, 0x2, 
       0x2, 0x2, 0x1a, 0x201, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x205, 0x3, 0x2, 
       0x2, 0x2, 0x1e, 0x209, 0x3, 0x2, 0x2, 0x2, 0x20, 0x20e, 0x3, 0x2, 
       0x2, 0x2, 0x22, 0x210, 0x3, 0x2, 0x2, 0x2, 0x24, 0x212, 0x3, 0x2, 
       0x2, 0x2, 0x26, 0x21a, 0x3, 0x2, 0x2, 0x2, 0x28, 0x229, 0x3, 0x2, 
       0x2, 0x2, 0x2a, 0x22d, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x233, 0x3, 0x2, 
       0x2, 0x2, 0x2e, 0x237, 0x3, 0x2, 0x2, 0x2, 0x30, 0x23b, 0x3, 0x2, 
       0x2, 0x2, 0x32, 0x23d, 0x3, 0x2, 0x2, 0x2, 0x34, 0x23f, 0x3, 0x2, 
       0x2, 0x2, 0x36, 0x241, 0x3, 0x2, 0x2, 0x2, 0x38, 0x246, 0x3, 0x2, 
       0x2, 0x2, 0x3a, 0x24b, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x24d, 0x3, 0x2, 
       0x2, 0x2, 0x3e, 0x24f, 0x3, 0x2, 0x2, 0x2, 0x40, 0x259, 0x3, 0x2, 
       0x2, 0x2, 0x42, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x44, 0x264, 0x3, 0x2, 
       0x2, 0x2, 0x46, 0x266, 0x3, 0x2, 0x2, 0x2, 0x48, 0x26b, 0x3, 0x2, 
       0x2, 0x2, 0x4a, 0x289, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x28b, 0x3, 0x2, 
       0x2, 0x2, 0x4e, 0x293, 0x3, 0x2, 0x2, 0x2, 0x50, 0x2a6, 0x3, 0x2, 
       0x2, 0x2, 0x52, 0x2ab, 0x3, 0x2, 0x2, 0x2, 0x54, 0x2b6, 0x3, 0x2, 
       0x2, 0x2, 0x56, 0x2bd, 0x3, 0x2, 0x2, 0x2, 0x58, 0x2c5, 0x3, 0x2, 
       0x2, 0x2, 0x5a, 0x2cc, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x2ce, 0x3, 0x2, 
       0x2, 0x2, 0x5e, 0x2d4, 0x3, 0x2, 0x2, 0x2, 0x60, 0x2e9, 0x3, 0x2, 
       0x2, 0x2, 0x62, 0x2f0, 0x3, 0x2, 0x2, 0x2, 0x64, 0x2f2, 0x3, 0x2, 
       0x2, 0x2, 0x66, 0x2f4, 0x3, 0x2, 0x2, 0x2, 0x68, 0x2fd, 0x3, 0x2, 
       0x2, 0x2, 0x6a, 0x304, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x307, 0x3, 0x2, 
       0x2, 0x2, 0x6e, 0x30b, 0x3, 0x2, 0x2, 0x2, 0x70, 0x310, 0x3, 0x2, 
       0x2, 0x2, 0x72, 0x317, 0x3, 0x2, 0x2, 0x2, 0x74, 0x325, 0x3, 0x2, 
       0x2, 0x2, 0x76, 0x328, 0x3, 0x2, 0x2, 0x2, 0x78, 0x32e, 0x3, 0x2, 
       0x2, 0x2, 0x7a, 0x33a, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x33e, 0x3, 0x2, 
       0x2, 0x2, 0x7e, 0x340, 0x3, 0x2, 0x2, 0x2, 0x80, 0x347, 0x3, 0x2, 
       0x2, 0x2, 0x82, 0x34d, 0x3, 0x2, 0x2, 0x2, 0x84, 0x35d, 0x3, 0x2, 
       0x2, 0x2, 0x86, 0x35f, 0x3, 0x2, 0x2, 0x2, 0x88, 0x364, 0x3, 0x2, 
       0x2, 0x2, 0x8a, 0x36b, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x370, 0x3, 0x2, 
       0x2, 0x2, 0x8e, 0x372, 0x3, 0x2, 0x2, 0x2, 0x90, 0x37a, 0x3, 0x2, 
       0x2, 0x2, 0x92, 0x37c, 0x3, 0x2, 0x2, 0x2, 0x94, 0x397, 0x3, 0x2, 
       0x2, 0x2, 0x96, 0x3a9, 0x3, 0x2, 0x2, 0x2, 0x98, 0x3ad, 0x3, 0x2, 
       0x2, 0x2, 0x9a, 0x3b2, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x3b8, 0x3, 0x2, 
       0x2, 0x2, 0x9e, 0x3ba, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x3d1, 0x3, 0x2, 
       0x2, 0x2, 0xa2, 0x3d5, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x3d7, 0x3, 0x2, 
       0x2, 0x2, 0xa6, 0x3dd, 0x3, 0x2, 0x2, 0x2, 0xa8, 0x3e1, 0x3, 0x2, 
       0x2, 0x2, 0xaa, 0x3e3, 0x3, 0x2, 0x2, 0x2, 0xac, 0x3eb, 0x3, 0x2, 
       0x2, 0x2, 0xae, 0x3f0, 0x3, 0x2, 0x2, 0x2, 0xb0, 0x405, 0x3, 0x2, 
       0x2, 0x2, 0xb2, 0x409, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x41a, 0x3, 0x2, 
       0x2, 0x2, 0xb6, 0x41c, 0x3, 0x2, 0x2, 0x2, 0xb8, 0x41f, 0x3, 0x2, 
       0x2, 0x2, 0xba, 0x42b, 0x3, 0x2, 0x2, 0x2, 0xbc, 0x42e, 0x3, 0x2, 
       0x2, 0x2, 0xbe, 0x441, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x455, 0x3, 0x2, 
       0x2, 0x2, 0xc2, 0x458, 0x3, 0x2, 0x2, 0x2, 0xc4, 0x463, 0x3, 0x2, 
       0x2, 0x2, 0xc6, 0x46a, 0x3, 0x2, 0x2, 0x2, 0xc8, 0x471, 0x3, 0x2, 
       0x2, 0x2, 0xca, 0x473, 0x3, 0x2, 0x2, 0x2, 0xcc, 0x47d, 0x3, 0x2, 
       0x2, 0x2, 0xce, 0x47f, 0x3, 0x2, 0x2, 0x2, 0xd0, 0x484, 0x3, 0x2, 
       0x2, 0x2, 0xd2, 0x486, 0x3, 0x2, 0x2, 0x2, 0xd4, 0x493, 0x3, 0x2, 
       0x2, 0x2, 0xd6, 0x497, 0x3, 0x2, 0x2, 0x2, 0xd8, 0x499, 0x3, 0x2, 
       0x2, 0x2, 0xda, 0x49d, 0x3, 0x2, 0x2, 0x2, 0xdc, 0x4a5, 0x3, 0x2, 
       0x2, 0x2, 0xde, 0x4b0, 0x3, 0x2, 0x2, 0x2, 0xe0, 0x4b2, 0x3, 0x2, 
       0x2, 0x2, 0xe2, 0x4b4, 0x3, 0x2, 0x2, 0x2, 0xe4, 0x4be, 0x3, 0x2, 
       0x2, 0x2, 0xe6, 0x4c2, 0x3, 0x2, 0x2, 0x2, 0xe8, 0x4d2, 0x3, 0x2, 
       0x2, 0x2, 0xea, 0x4d4, 0x3, 0x2, 0x2, 0x2, 0xec, 0x4da, 0x3, 0x2, 
       0x2, 0x2, 0xee, 0x4e4, 0x3, 0x2, 0x2, 0x2, 0xf0, 0x4f0, 0x3, 0x2, 
       0x2, 0x2, 0xf2, 0x4f6, 0x3, 0x2, 0x2, 0x2, 0xf4, 0x4f8, 0x3, 0x2, 
       0x2, 0x2, 0xf6, 0x4fe, 0x3, 0x2, 0x2, 0x2, 0xf8, 0x506, 0x3, 0x2, 
       0x2, 0x2, 0xfa, 0x518, 0x3, 0x2, 0x2, 0x2, 0xfc, 0x51a, 0x3, 0x2, 
       0x2, 0x2, 0xfe, 0x51c, 0x3, 0x2, 0x2, 0x2, 0x100, 0x51e, 0x3, 0x2, 
       0x2, 0x2, 0x102, 0x526, 0x3, 0x2, 0x2, 0x2, 0x104, 0x534, 0x3, 0x2, 
       0x2, 0x2, 0x106, 0x536, 0x3, 0x2, 0x2, 0x2, 0x108, 0x539, 0x3, 0x2, 
       0x2, 0x2, 0x10a, 0x548, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x54a, 0x3, 0x2, 
       0x2, 0x2, 0x10e, 0x550, 0x3, 0x2, 0x2, 0x2, 0x110, 0x56a, 0x3, 0x2, 
       0x2, 0x2, 0x112, 0x56c, 0x3, 0x2, 0x2, 0x2, 0x114, 0x575, 0x3, 0x2, 
       0x2, 0x2, 0x116, 0x57c, 0x3, 0x2, 0x2, 0x2, 0x118, 0x581, 0x3, 0x2, 
       0x2, 0x2, 0x11a, 0x584, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x58e, 0x3, 0x2, 
       0x2, 0x2, 0x11e, 0x590, 0x3, 0x2, 0x2, 0x2, 0x120, 0x59c, 0x3, 0x2, 
       0x2, 0x2, 0x122, 0x5a3, 0x3, 0x2, 0x2, 0x2, 0x124, 0x5a5, 0x3, 0x2, 
       0x2, 0x2, 0x126, 0x5a9, 0x3, 0x2, 0x2, 0x2, 0x128, 0x5bd, 0x3, 0x2, 
       0x2, 0x2, 0x12a, 0x5bf, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x5c6, 0x3, 0x2, 
       0x2, 0x2, 0x12e, 0x5cb, 0x3, 0x2, 0x2, 0x2, 0x130, 0x5d5, 0x3, 0x2, 
       0x2, 0x2, 0x132, 0x5d7, 0x3, 0x2, 0x2, 0x2, 0x134, 0x5da, 0x3, 0x2, 
       0x2, 0x2, 0x136, 0x5eb, 0x3, 0x2, 0x2, 0x2, 0x138, 0x5ef, 0x3, 0x2, 
       0x2, 0x2, 0x13a, 0x5fb, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x5fd, 0x3, 0x2, 
       0x2, 0x2, 0x13e, 0x605, 0x3, 0x2, 0x2, 0x2, 0x140, 0x60b, 0x3, 0x2, 
       0x2, 0x2, 0x142, 0x616, 0x3, 0x2, 0x2, 0x2, 0x144, 0x618, 0x3, 0x2, 
       0x2, 0x2, 0x146, 0x625, 0x3, 0x2, 0x2, 0x2, 0x148, 0x627, 0x3, 0x2, 
       0x2, 0x2, 0x14a, 0x63d, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x64a, 0x3, 0x2, 
       0x2, 0x2, 0x14e, 0x657, 0x3, 0x2, 0x2, 0x2, 0x150, 0x660, 0x3, 0x2, 
       0x2, 0x2, 0x152, 0x677, 0x3, 0x2, 0x2, 0x2, 0x154, 0x681, 0x3, 0x2, 
       0x2, 0x2, 0x156, 0x683, 0x3, 0x2, 0x2, 0x2, 0x158, 0x686, 0x3, 0x2, 
       0x2, 0x2, 0x15a, 0x689, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x68c, 0x3, 0x2, 
       0x2, 0x2, 0x15e, 0x68f, 0x3, 0x2, 0x2, 0x2, 0x160, 0x692, 0x3, 0x2, 
       0x2, 0x2, 0x162, 0x695, 0x3, 0x2, 0x2, 0x2, 0x164, 0x69a, 0x3, 0x2, 
       0x2, 0x2, 0x166, 0x6ab, 0x3, 0x2, 0x2, 0x2, 0x168, 0x6b9, 0x3, 0x2, 
       0x2, 0x2, 0x16a, 0x6c8, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x6e2, 0x3, 0x2, 
       0x2, 0x2, 0x16e, 0x6f0, 0x3, 0x2, 0x2, 0x2, 0x170, 0x6fb, 0x3, 0x2, 
       0x2, 0x2, 0x172, 0x706, 0x3, 0x2, 0x2, 0x2, 0x174, 0x711, 0x3, 0x2, 
       0x2, 0x2, 0x176, 0x71c, 0x3, 0x2, 0x2, 0x2, 0x178, 0x72c, 0x3, 0x2, 
       0x2, 0x2, 0x17a, 0x735, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x737, 0x3, 0x2, 
       0x2, 0x2, 0x17e, 0x746, 0x3, 0x2, 0x2, 0x2, 0x180, 0x74a, 0x3, 0x2, 
       0x2, 0x2, 0x182, 0x74c, 0x3, 0x2, 0x2, 0x2, 0x184, 0x74e, 0x3, 0x2, 
       0x2, 0x2, 0x186, 0x750, 0x3, 0x2, 0x2, 0x2, 0x188, 0x75b, 0x3, 0x2, 
       0x2, 0x2, 0x18a, 0x75d, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x75f, 0x3, 0x2, 
       0x2, 0x2, 0x18e, 0x76b, 0x3, 0x2, 0x2, 0x2, 0x190, 0x76d, 0x3, 0x2, 
       0x2, 0x2, 0x192, 0x775, 0x3, 0x2, 0x2, 0x2, 0x194, 0x779, 0x3, 0x2, 
       0x2, 0x2, 0x196, 0x77d, 0x3, 0x2, 0x2, 0x2, 0x198, 0x77f, 0x3, 0x2, 
       0x2, 0x2, 0x19a, 0x19c, 0x5, 0x4, 0x3, 0x2, 0x19b, 0x19a, 0x3, 0x2, 
       0x2, 0x2, 0x19c, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x19b, 0x3, 0x2, 
       0x2, 0x2, 0x19d, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x1a3, 0x3, 0x2, 
       0x2, 0x2, 0x19f, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x1a2, 0x5, 0x6, 
       0x4, 0x2, 0x1a1, 0x1a0, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a5, 0x3, 0x2, 
       0x2, 0x2, 0x1a3, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1a4, 0x3, 0x2, 
       0x2, 0x2, 0x1a4, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1a5, 0x1a3, 0x3, 0x2, 
       0x2, 0x2, 0x1a6, 0x1a7, 0x7, 0x2, 0x2, 0x3, 0x1a7, 0x3, 0x3, 0x2, 
       0x2, 0x2, 0x1a8, 0x1a9, 0x7, 0x43, 0x2, 0x2, 0x1a9, 0x1aa, 0x5, 0x196, 
       0xcc, 0x2, 0x1aa, 0x1ab, 0x7, 0x68, 0x2, 0x2, 0x1ab, 0x1ac, 0x5, 
       0x26, 0x14, 0x2, 0x1ac, 0x1ad, 0x7, 0x5d, 0x2, 0x2, 0x1ad, 0x1b8, 
       0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1af, 0x7, 0x43, 0x2, 0x2, 0x1af, 0x1b0, 
       0x5, 0x26, 0x14, 0x2, 0x1b0, 0x1b1, 0x7, 0x5d, 0x2, 0x2, 0x1b1, 0x1b8, 
       0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b3, 0x7, 0x43, 0x2, 0x2, 0x1b3, 0x1b4, 
       0x7, 0x3a, 0x2, 0x2, 0x1b4, 0x1b5, 0x5, 0x26, 0x14, 0x2, 0x1b5, 0x1b6, 
       0x7, 0x5d, 0x2, 0x2, 0x1b6, 0x1b8, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1a8, 
       0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1b2, 
       0x3, 0x2, 0x2, 0x2, 0x1b8, 0x5, 0x3, 0x2, 0x2, 0x2, 0x1b9, 0x1bc, 
       0x5, 0x8, 0x5, 0x2, 0x1ba, 0x1bc, 0x5, 0x10, 0x9, 0x2, 0x1bb, 0x1b9, 
       0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1ba, 0x3, 0x2, 0x2, 0x2, 0x1bc, 0x7, 
       0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1be, 0x7, 0x29, 0x2, 0x2, 0x1be, 0x1bf, 
       0x5, 0xa, 0x6, 0x2, 0x1bf, 0x1c1, 0x5, 0xc, 0x7, 0x2, 0x1c0, 0x1c2, 
       0x7, 0x5d, 0x2, 0x2, 0x1c1, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1c2, 
       0x3, 0x2, 0x2, 0x2, 0x1c2, 0x9, 0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1c8, 
       0x5, 0x196, 0xcc, 0x2, 0x1c4, 0x1c5, 0x7, 0x5a, 0x2, 0x2, 0x1c5, 
       0x1c7, 0x5, 0x196, 0xcc, 0x2, 0x1c6, 0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1c7, 
       0x1ca, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1c6, 0x3, 0x2, 0x2, 0x2, 0x1c8, 
       0x1c9, 0x3, 0x2, 0x2, 0x2, 0x1c9, 0xb, 0x3, 0x2, 0x2, 0x2, 0x1ca, 
       0x1c8, 0x3, 0x2, 0x2, 0x2, 0x1cb, 0x1cf, 0x7, 0x54, 0x2, 0x2, 0x1cc, 
       0x1ce, 0x5, 0x4, 0x3, 0x2, 0x1cd, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x1ce, 
       0x1d1, 0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1cd, 0x3, 0x2, 0x2, 0x2, 0x1cf, 
       0x1d0, 0x3, 0x2, 0x2, 0x2, 0x1d0, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d1, 
       0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1d2, 0x1d4, 0x5, 0x6, 0x4, 0x2, 0x1d3, 
       0x1d2, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1d5, 
       0x1d3, 0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1d6, 
       0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d8, 
       0x1d9, 0x7, 0x55, 0x2, 0x2, 0x1d9, 0xd, 0x3, 0x2, 0x2, 0x2, 0x1da, 
       0x1db, 0x5, 0x196, 0xcc, 0x2, 0x1db, 0x1dc, 0x7, 0x6c, 0x2, 0x2, 
       0x1dc, 0x1de, 0x5, 0x196, 0xcc, 0x2, 0x1dd, 0x1df, 0x5, 0x14, 0xb, 
       0x2, 0x1de, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1de, 0x1df, 0x3, 0x2, 0x2, 
       0x2, 0x1df, 0xf, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x1e3, 0x5, 0x48, 0x25, 
       0x2, 0x1e1, 0x1e3, 0x5, 0xae, 0x58, 0x2, 0x1e2, 0x1e0, 0x3, 0x2, 
       0x2, 0x2, 0x1e2, 0x1e1, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x11, 0x3, 0x2, 
       0x2, 0x2, 0x1e4, 0x1e5, 0x7, 0x69, 0x2, 0x2, 0x1e5, 0x1ea, 0x5, 0x16, 
       0xc, 0x2, 0x1e6, 0x1e7, 0x7, 0x5b, 0x2, 0x2, 0x1e7, 0x1e9, 0x5, 0x16, 
       0xc, 0x2, 0x1e8, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e9, 0x1ec, 0x3, 0x2, 
       0x2, 0x2, 0x1ea, 0x1e8, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1eb, 0x3, 0x2, 
       0x2, 0x2, 0x1eb, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1ec, 0x1ea, 0x3, 0x2, 
       0x2, 0x2, 0x1ed, 0x1ee, 0x7, 0x6a, 0x2, 0x2, 0x1ee, 0x13, 0x3, 0x2, 
       0x2, 0x2, 0x1ef, 0x1f0, 0x7, 0x69, 0x2, 0x2, 0x1f0, 0x1f5, 0x5, 0x20, 
       0x11, 0x2, 0x1f1, 0x1f2, 0x7, 0x5b, 0x2, 0x2, 0x1f2, 0x1f4, 0x5, 
       0x20, 0x11, 0x2, 0x1f3, 0x1f1, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0x1f7, 
       0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f6, 
       0x3, 0x2, 0x2, 0x2, 0x1f6, 0x1f8, 0x3, 0x2, 0x2, 0x2, 0x1f7, 0x1f5, 
       0x3, 0x2, 0x2, 0x2, 0x1f8, 0x1f9, 0x7, 0x6a, 0x2, 0x2, 0x1f9, 0x15, 
       0x3, 0x2, 0x2, 0x2, 0x1fa, 0x1fb, 0x5, 0x196, 0xcc, 0x2, 0x1fb, 0x17, 
       0x3, 0x2, 0x2, 0x2, 0x1fc, 0x1fd, 0x7, 0x48, 0x2, 0x2, 0x1fd, 0x1fe, 
       0x5, 0x196, 0xcc, 0x2, 0x1fe, 0x1ff, 0x7, 0x5c, 0x2, 0x2, 0x1ff, 
       0x200, 0x5, 0x1a, 0xe, 0x2, 0x200, 0x19, 0x3, 0x2, 0x2, 0x2, 0x201, 
       0x203, 0x5, 0x3a, 0x1e, 0x2, 0x202, 0x204, 0x5, 0x1c, 0xf, 0x2, 0x203, 
       0x202, 0x3, 0x2, 0x2, 0x2, 0x203, 0x204, 0x3, 0x2, 0x2, 0x2, 0x204, 
       0x1b, 0x3, 0x2, 0x2, 0x2, 0x205, 0x206, 0x7, 0x2a, 0x2, 0x2, 0x206, 
       0x207, 0x7, 0x58, 0x2, 0x2, 0x207, 0x208, 0x7, 0x59, 0x2, 0x2, 0x208, 
       0x1d, 0x3, 0x2, 0x2, 0x2, 0x209, 0x20a, 0x9, 0x2, 0x2, 0x2, 0x20a, 
       0x1f, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x20f, 0x5, 0x28, 0x15, 0x2, 0x20c, 
       0x20f, 0x5, 0x38, 0x1d, 0x2, 0x20d, 0x20f, 0x5, 0x16, 0xc, 0x2, 0x20e, 
       0x20b, 0x3, 0x2, 0x2, 0x2, 0x20e, 0x20c, 0x3, 0x2, 0x2, 0x2, 0x20e, 
       0x20d, 0x3, 0x2, 0x2, 0x2, 0x20f, 0x21, 0x3, 0x2, 0x2, 0x2, 0x210, 
       0x211, 0x5, 0x26, 0x14, 0x2, 0x211, 0x23, 0x3, 0x2, 0x2, 0x2, 0x212, 
       0x213, 0x5, 0x26, 0x14, 0x2, 0x213, 0x25, 0x3, 0x2, 0x2, 0x2, 0x214, 
       0x215, 0x8, 0x14, 0x1, 0x2, 0x215, 0x217, 0x5, 0x196, 0xcc, 0x2, 
       0x216, 0x218, 0x5, 0x14, 0xb, 0x2, 0x217, 0x216, 0x3, 0x2, 0x2, 0x2, 
       0x217, 0x218, 0x3, 0x2, 0x2, 0x2, 0x218, 0x21b, 0x3, 0x2, 0x2, 0x2, 
       0x219, 0x21b, 0x5, 0xe, 0x8, 0x2, 0x21a, 0x214, 0x3, 0x2, 0x2, 0x2, 
       0x21a, 0x219, 0x3, 0x2, 0x2, 0x2, 0x21b, 0x224, 0x3, 0x2, 0x2, 0x2, 
       0x21c, 0x21d, 0xc, 0x4, 0x2, 0x2, 0x21d, 0x21e, 0x7, 0x5a, 0x2, 0x2, 
       0x21e, 0x220, 0x5, 0x196, 0xcc, 0x2, 0x21f, 0x221, 0x5, 0x14, 0xb, 
       0x2, 0x220, 0x21f, 0x3, 0x2, 0x2, 0x2, 0x220, 0x221, 0x3, 0x2, 0x2, 
       0x2, 0x221, 0x223, 0x3, 0x2, 0x2, 0x2, 0x222, 0x21c, 0x3, 0x2, 0x2, 
       0x2, 0x223, 0x226, 0x3, 0x2, 0x2, 0x2, 0x224, 0x222, 0x3, 0x2, 0x2, 
       0x2, 0x224, 0x225, 0x3, 0x2, 0x2, 0x2, 0x225, 0x27, 0x3, 0x2, 0x2, 
       0x2, 0x226, 0x224, 0x3, 0x2, 0x2, 0x2, 0x227, 0x22a, 0x5, 0x2a, 0x16, 
       0x2, 0x228, 0x22a, 0x5, 0x36, 0x1c, 0x2, 0x229, 0x227, 0x3, 0x2, 
       0x2, 0x2, 0x229, 0x228, 0x3, 0x2, 0x2, 0x2, 0x22a, 0x29, 0x3, 0x2, 
       0x2, 0x2, 0x22b, 0x22e, 0x5, 0x24, 0x13, 0x2, 0x22c, 0x22e, 0x5, 
       0x2e, 0x18, 0x2, 0x22d, 0x22b, 0x3, 0x2, 0x2, 0x2, 0x22d, 0x22c, 
       0x3, 0x2, 0x2, 0x2, 0x22e, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x22f, 0x234, 
       0x5, 0x2e, 0x18, 0x2, 0x230, 0x234, 0x5, 0x3a, 0x1e, 0x2, 0x231, 
       0x232, 0x7, 0x46, 0x2, 0x2, 0x232, 0x234, 0x7, 0x60, 0x2, 0x2, 0x233, 
       0x22f, 0x3, 0x2, 0x2, 0x2, 0x233, 0x230, 0x3, 0x2, 0x2, 0x2, 0x233, 
       0x231, 0x3, 0x2, 0x2, 0x2, 0x234, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x235, 
       0x238, 0x5, 0x30, 0x19, 0x2, 0x236, 0x238, 0x7, 0xc, 0x2, 0x2, 0x237, 
       0x235, 0x3, 0x2, 0x2, 0x2, 0x237, 0x236, 0x3, 0x2, 0x2, 0x2, 0x238, 
       0x2f, 0x3, 0x2, 0x2, 0x2, 0x239, 0x23c, 0x5, 0x32, 0x1a, 0x2, 0x23a, 
       0x23c, 0x5, 0x34, 0x1b, 0x2, 0x23b, 0x239, 0x3, 0x2, 0x2, 0x2, 0x23b, 
       0x23a, 0x3, 0x2, 0x2, 0x2, 0x23c, 0x31, 0x3, 0x2, 0x2, 0x2, 0x23d, 
       0x23e, 0x9, 0x3, 0x2, 0x2, 0x23e, 0x33, 0x3, 0x2, 0x2, 0x2, 0x23f, 
       0x240, 0x9, 0x4, 0x2, 0x2, 0x240, 0x35, 0x3, 0x2, 0x2, 0x2, 0x241, 
       0x242, 0x5, 0x24, 0x13, 0x2, 0x242, 0x37, 0x3, 0x2, 0x2, 0x2, 0x243, 
       0x247, 0x5, 0x3a, 0x1e, 0x2, 0x244, 0x247, 0x5, 0x3c, 0x1f, 0x2, 
       0x245, 0x247, 0x5, 0x3e, 0x20, 0x2, 0x246, 0x243, 0x3, 0x2, 0x2, 
       0x2, 0x246, 0x244, 0x3, 0x2, 0x2, 0x2, 0x246, 0x245, 0x3, 0x2, 0x2, 
       0x2, 0x247, 0x39, 0x3, 0x2, 0x2, 0x2, 0x248, 0x24c, 0x5, 0x24, 0x13, 
       0x2, 0x249, 0x24c, 0x7, 0x2c, 0x2, 0x2, 0x24a, 0x24c, 0x7, 0x3b, 
       0x2, 0x2, 0x24b, 0x248, 0x3, 0x2, 0x2, 0x2, 0x24b, 0x249, 0x3, 0x2, 
       0x2, 0x2, 0x24b, 0x24a, 0x3, 0x2, 0x2, 0x2, 0x24c, 0x3b, 0x3, 0x2, 
       0x2, 0x2, 0x24d, 0x24e, 0x5, 0x24, 0x13, 0x2, 0x24e, 0x3d, 0x3, 0x2, 
       0x2, 0x2, 0x24f, 0x251, 0x5, 0x40, 0x21, 0x2, 0x250, 0x252, 0x5, 
       0x42, 0x22, 0x2, 0x251, 0x250, 0x3, 0x2, 0x2, 0x2, 0x252, 0x253, 
       0x3, 0x2, 0x2, 0x2, 0x253, 0x251, 0x3, 0x2, 0x2, 0x2, 0x253, 0x254, 
       0x3, 0x2, 0x2, 0x2, 0x254, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x255, 0x25a, 
       0x5, 0x3a, 0x1e, 0x2, 0x256, 0x25a, 0x5, 0x3c, 0x1f, 0x2, 0x257, 
       0x25a, 0x5, 0x28, 0x15, 0x2, 0x258, 0x25a, 0x5, 0x16, 0xc, 0x2, 0x259, 
       0x255, 0x3, 0x2, 0x2, 0x2, 0x259, 0x256, 0x3, 0x2, 0x2, 0x2, 0x259, 
       0x257, 0x3, 0x2, 0x2, 0x2, 0x259, 0x258, 0x3, 0x2, 0x2, 0x2, 0x25a, 
       0x41, 0x3, 0x2, 0x2, 0x2, 0x25b, 0x25f, 0x7, 0x56, 0x2, 0x2, 0x25c, 
       0x25e, 0x5, 0x44, 0x23, 0x2, 0x25d, 0x25c, 0x3, 0x2, 0x2, 0x2, 0x25e, 
       0x261, 0x3, 0x2, 0x2, 0x2, 0x25f, 0x25d, 0x3, 0x2, 0x2, 0x2, 0x25f, 
       0x260, 0x3, 0x2, 0x2, 0x2, 0x260, 0x262, 0x3, 0x2, 0x2, 0x2, 0x261, 
       0x25f, 0x3, 0x2, 0x2, 0x2, 0x262, 0x263, 0x7, 0x57, 0x2, 0x2, 0x263, 
       0x43, 0x3, 0x2, 0x2, 0x2, 0x264, 0x265, 0x7, 0x5b, 0x2, 0x2, 0x265, 
       0x45, 0x3, 0x2, 0x2, 0x2, 0x266, 0x267, 0x9, 0x5, 0x2, 0x2, 0x267, 
       0x47, 0x3, 0x2, 0x2, 0x2, 0x268, 0x26a, 0x5, 0x198, 0xcd, 0x2, 0x269, 
       0x268, 0x3, 0x2, 0x2, 0x2, 0x26a, 0x26d, 0x3, 0x2, 0x2, 0x2, 0x26b, 
       0x269, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x26c, 0x3, 0x2, 0x2, 0x2, 0x26c, 
       0x26e, 0x3, 0x2, 0x2, 0x2, 0x26d, 0x26b, 0x3, 0x2, 0x2, 0x2, 0x26e, 
       0x26f, 0x7, 0x11, 0x2, 0x2, 0x26f, 0x271, 0x5, 0x196, 0xcc, 0x2, 
       0x270, 0x272, 0x5, 0x12, 0xa, 0x2, 0x271, 0x270, 0x3, 0x2, 0x2, 0x2, 
       0x271, 0x272, 0x3, 0x2, 0x2, 0x2, 0x272, 0x274, 0x3, 0x2, 0x2, 0x2, 
       0x273, 0x275, 0x5, 0x4a, 0x26, 0x2, 0x274, 0x273, 0x3, 0x2, 0x2, 
       0x2, 0x274, 0x275, 0x3, 0x2, 0x2, 0x2, 0x275, 0x279, 0x3, 0x2, 0x2, 
       0x2, 0x276, 0x278, 0x5, 0x18, 0xd, 0x2, 0x277, 0x276, 0x3, 0x2, 0x2, 
       0x2, 0x278, 0x27b, 0x3, 0x2, 0x2, 0x2, 0x279, 0x277, 0x3, 0x2, 0x2, 
       0x2, 0x279, 0x27a, 0x3, 0x2, 0x2, 0x2, 0x27a, 0x27c, 0x3, 0x2, 0x2, 
       0x2, 0x27b, 0x279, 0x3, 0x2, 0x2, 0x2, 0x27c, 0x27e, 0x5, 0x4e, 0x28, 
       0x2, 0x27d, 0x27f, 0x7, 0x5d, 0x2, 0x2, 0x27e, 0x27d, 0x3, 0x2, 0x2, 
       0x2, 0x27e, 0x27f, 0x3, 0x2, 0x2, 0x2, 0x27f, 0x49, 0x3, 0x2, 0x2, 
       0x2, 0x280, 0x281, 0x7, 0x5c, 0x2, 0x2, 0x281, 0x28a, 0x5, 0x3a, 
       0x1e, 0x2, 0x282, 0x283, 0x7, 0x5c, 0x2, 0x2, 0x283, 0x28a, 0x5, 
       0x4c, 0x27, 0x2, 0x284, 0x285, 0x7, 0x5c, 0x2, 0x2, 0x285, 0x286, 
       0x5, 0x3a, 0x1e, 0x2, 0x286, 0x287, 0x7, 0x5b, 0x2, 0x2, 0x287, 0x288, 
       0x5, 0x4c, 0x27, 0x2, 0x288, 0x28a, 0x3, 0x2, 0x2, 0x2, 0x289, 0x280, 
       0x3, 0x2, 0x2, 0x2, 0x289, 0x282, 0x3, 0x2, 0x2, 0x2, 0x289, 0x284, 
       0x3, 0x2, 0x2, 0x2, 0x28a, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x28b, 0x290, 
       0x5, 0x3c, 0x1f, 0x2, 0x28c, 0x28d, 0x7, 0x5b, 0x2, 0x2, 0x28d, 0x28f, 
       0x5, 0x3c, 0x1f, 0x2, 0x28e, 0x28c, 0x3, 0x2, 0x2, 0x2, 0x28f, 0x292, 
       0x3, 0x2, 0x2, 0x2, 0x290, 0x28e, 0x3, 0x2, 0x2, 0x2, 0x290, 0x291, 
       0x3, 0x2, 0x2, 0x2, 0x291, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x292, 0x290, 
       0x3, 0x2, 0x2, 0x2, 0x293, 0x297, 0x7, 0x54, 0x2, 0x2, 0x294, 0x296, 
       0x5, 0x50, 0x29, 0x2, 0x295, 0x294, 0x3, 0x2, 0x2, 0x2, 0x296, 0x299, 
       0x3, 0x2, 0x2, 0x2, 0x297, 0x295, 0x3, 0x2, 0x2, 0x2, 0x297, 0x298, 
       0x3, 0x2, 0x2, 0x2, 0x298, 0x29a, 0x3, 0x2, 0x2, 0x2, 0x299, 0x297, 
       0x3, 0x2, 0x2, 0x2, 0x29a, 0x29b, 0x7, 0x55, 0x2, 0x2, 0x29b, 0x4f, 
       0x3, 0x2, 0x2, 0x2, 0x29c, 0x2a7, 0x5, 0x52, 0x2a, 0x2, 0x29d, 0x2a7, 
       0x5, 0x54, 0x2b, 0x2, 0x29e, 0x2a7, 0x5, 0x5c, 0x2f, 0x2, 0x29f, 
       0x2a7, 0x5, 0x70, 0x39, 0x2, 0x2a0, 0x2a7, 0x5, 0x80, 0x41, 0x2, 
       0x2a1, 0x2a7, 0x5, 0x88, 0x45, 0x2, 0x2a2, 0x2a7, 0x5, 0x9a, 0x4e, 
       0x2, 0x2a3, 0x2a7, 0x5, 0xa4, 0x53, 0x2, 0x2a4, 0x2a7, 0x5, 0xaa, 
       0x56, 0x2, 0x2a5, 0x2a7, 0x5, 0x10, 0x9, 0x2, 0x2a6, 0x29c, 0x3, 
       0x2, 0x2, 0x2, 0x2a6, 0x29d, 0x3, 0x2, 0x2, 0x2, 0x2a6, 0x29e, 0x3, 
       0x2, 0x2, 0x2, 0x2a6, 0x29f, 0x3, 0x2, 0x2, 0x2, 0x2a6, 0x2a0, 0x3, 
       0x2, 0x2, 0x2, 0x2a6, 0x2a1, 0x3, 0x2, 0x2, 0x2, 0x2a6, 0x2a2, 0x3, 
       0x2, 0x2, 0x2, 0x2a6, 0x2a3, 0x3, 0x2, 0x2, 0x2, 0x2a6, 0x2a4, 0x3, 
       0x2, 0x2, 0x2, 0x2a6, 0x2a5, 0x3, 0x2, 0x2, 0x2, 0x2a7, 0x51, 0x3, 
       0x2, 0x2, 0x2, 0x2a8, 0x2aa, 0x5, 0x1e, 0x10, 0x2, 0x2a9, 0x2a8, 
       0x3, 0x2, 0x2, 0x2, 0x2aa, 0x2ad, 0x3, 0x2, 0x2, 0x2, 0x2ab, 0x2a9, 
       0x3, 0x2, 0x2, 0x2, 0x2ab, 0x2ac, 0x3, 0x2, 0x2, 0x2, 0x2ac, 0x2ae, 
       0x3, 0x2, 0x2, 0x2, 0x2ad, 0x2ab, 0x3, 0x2, 0x2, 0x2, 0x2ae, 0x2af, 
       0x7, 0x12, 0x2, 0x2, 0x2af, 0x2b0, 0x5, 0x20, 0x11, 0x2, 0x2b0, 0x2b1, 
       0x5, 0xda, 0x6e, 0x2, 0x2b1, 0x2b2, 0x7, 0x5d, 0x2, 0x2, 0x2b2, 0x53, 
       0x3, 0x2, 0x2, 0x2, 0x2b3, 0x2b5, 0x5, 0x198, 0xcd, 0x2, 0x2b4, 0x2b3, 
       0x3, 0x2, 0x2, 0x2, 0x2b5, 0x2b8, 0x3, 0x2, 0x2, 0x2, 0x2b6, 0x2b4, 
       0x3, 0x2, 0x2, 0x2, 0x2b6, 0x2b7, 0x3, 0x2, 0x2, 0x2, 0x2b7, 0x2b9, 
       0x3, 0x2, 0x2, 0x2, 0x2b8, 0x2b6, 0x3, 0x2, 0x2, 0x2, 0x2b9, 0x2ba, 
       0x5, 0x20, 0x11, 0x2, 0x2ba, 0x2bb, 0x5, 0x56, 0x2c, 0x2, 0x2bb, 
       0x2bc, 0x7, 0x5d, 0x2, 0x2, 0x2bc, 0x55, 0x3, 0x2, 0x2, 0x2, 0x2bd, 
       0x2c2, 0x5, 0x58, 0x2d, 0x2, 0x2be, 0x2bf, 0x7, 0x5b, 0x2, 0x2, 0x2bf, 
       0x2c1, 0x5, 0x58, 0x2d, 0x2, 0x2c0, 0x2be, 0x3, 0x2, 0x2, 0x2, 0x2c1, 
       0x2c4, 0x3, 0x2, 0x2, 0x2, 0x2c2, 0x2c0, 0x3, 0x2, 0x2, 0x2, 0x2c2, 
       0x2c3, 0x3, 0x2, 0x2, 0x2, 0x2c3, 0x57, 0x3, 0x2, 0x2, 0x2, 0x2c4, 
       0x2c2, 0x3, 0x2, 0x2, 0x2, 0x2c5, 0x2c8, 0x5, 0x196, 0xcc, 0x2, 0x2c6, 
       0x2c7, 0x7, 0x68, 0x2, 0x2, 0x2c7, 0x2c9, 0x5, 0x5a, 0x2e, 0x2, 0x2c8, 
       0x2c6, 0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2c9, 0x3, 0x2, 0x2, 0x2, 0x2c9, 
       0x59, 0x3, 0x2, 0x2, 0x2, 0x2ca, 0x2cd, 0x5, 0x180, 0xc1, 0x2, 0x2cb, 
       0x2cd, 0x5, 0x18e, 0xc8, 0x2, 0x2cc, 0x2ca, 0x3, 0x2, 0x2, 0x2, 0x2cc, 
       0x2cb, 0x3, 0x2, 0x2, 0x2, 0x2cd, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x2ce, 
       0x2cf, 0x5, 0x5e, 0x30, 0x2, 0x2cf, 0x2d0, 0x5, 0x6e, 0x38, 0x2, 
       0x2d0, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x2d1, 0x2d3, 0x5, 0x198, 0xcd, 
       0x2, 0x2d2, 0x2d1, 0x3, 0x2, 0x2, 0x2, 0x2d3, 0x2d6, 0x3, 0x2, 0x2, 
       0x2, 0x2d4, 0x2d2, 0x3, 0x2, 0x2, 0x2, 0x2d4, 0x2d5, 0x3, 0x2, 0x2, 
       0x2, 0x2d5, 0x2d7, 0x3, 0x2, 0x2, 0x2, 0x2d6, 0x2d4, 0x3, 0x2, 0x2, 
       0x2, 0x2d7, 0x2d8, 0x5, 0x60, 0x31, 0x2, 0x2d8, 0x2da, 0x5, 0x62, 
       0x32, 0x2, 0x2d9, 0x2db, 0x5, 0x12, 0xa, 0x2, 0x2da, 0x2d9, 0x3, 
       0x2, 0x2, 0x2, 0x2da, 0x2db, 0x3, 0x2, 0x2, 0x2, 0x2db, 0x2dc, 0x3, 
       0x2, 0x2, 0x2, 0x2dc, 0x2de, 0x7, 0x58, 0x2, 0x2, 0x2dd, 0x2df, 0x5, 
       0x64, 0x33, 0x2, 0x2de, 0x2dd, 0x3, 0x2, 0x2, 0x2, 0x2de, 0x2df, 
       0x3, 0x2, 0x2, 0x2, 0x2df, 0x2e0, 0x3, 0x2, 0x2, 0x2, 0x2e0, 0x2e4, 
       0x7, 0x59, 0x2, 0x2, 0x2e1, 0x2e3, 0x5, 0x18, 0xd, 0x2, 0x2e2, 0x2e1, 
       0x3, 0x2, 0x2, 0x2, 0x2e3, 0x2e6, 0x3, 0x2, 0x2, 0x2, 0x2e4, 0x2e2, 
       0x3, 0x2, 0x2, 0x2, 0x2e4, 0x2e5, 0x3, 0x2, 0x2, 0x2, 0x2e5, 0x5f, 
       0x3, 0x2, 0x2, 0x2, 0x2e6, 0x2e4, 0x3, 0x2, 0x2, 0x2, 0x2e7, 0x2ea, 
       0x5, 0x20, 0x11, 0x2, 0x2e8, 0x2ea, 0x7, 0x46, 0x2, 0x2, 0x2e9, 0x2e7, 
       0x3, 0x2, 0x2, 0x2, 0x2e9, 0x2e8, 0x3, 0x2, 0x2, 0x2, 0x2ea, 0x61, 
       0x3, 0x2, 0x2, 0x2, 0x2eb, 0x2f1, 0x5, 0x196, 0xcc, 0x2, 0x2ec, 0x2ed, 
       0x5, 0x3c, 0x1f, 0x2, 0x2ed, 0x2ee, 0x7, 0x5a, 0x2, 0x2, 0x2ee, 0x2ef, 
       0x5, 0x196, 0xcc, 0x2, 0x2ef, 0x2f1, 0x3, 0x2, 0x2, 0x2, 0x2f0, 0x2eb, 
       0x3, 0x2, 0x2, 0x2, 0x2f0, 0x2ec, 0x3, 0x2, 0x2, 0x2, 0x2f1, 0x63, 
       0x3, 0x2, 0x2, 0x2, 0x2f2, 0x2f3, 0x5, 0x66, 0x34, 0x2, 0x2f3, 0x65, 
       0x3, 0x2, 0x2, 0x2, 0x2f4, 0x2f9, 0x5, 0x68, 0x35, 0x2, 0x2f5, 0x2f6, 
       0x7, 0x5b, 0x2, 0x2, 0x2f6, 0x2f8, 0x5, 0x68, 0x35, 0x2, 0x2f7, 0x2f5, 
       0x3, 0x2, 0x2, 0x2, 0x2f8, 0x2fb, 0x3, 0x2, 0x2, 0x2, 0x2f9, 0x2f7, 
       0x3, 0x2, 0x2, 0x2, 0x2f9, 0x2fa, 0x3, 0x2, 0x2, 0x2, 0x2fa, 0x67, 
       0x3, 0x2, 0x2, 0x2, 0x2fb, 0x2f9, 0x3, 0x2, 0x2, 0x2, 0x2fc, 0x2fe, 
       0x5, 0x6c, 0x37, 0x2, 0x2fd, 0x2fc, 0x3, 0x2, 0x2, 0x2, 0x2fd, 0x2fe, 
       0x3, 0x2, 0x2, 0x2, 0x2fe, 0x2ff, 0x3, 0x2, 0x2, 0x2, 0x2ff, 0x300, 
       0x5, 0x20, 0x11, 0x2, 0x300, 0x302, 0x5, 0x196, 0xcc, 0x2, 0x301, 
       0x303, 0x5, 0x6a, 0x36, 0x2, 0x302, 0x301, 0x3, 0x2, 0x2, 0x2, 0x302, 
       0x303, 0x3, 0x2, 0x2, 0x2, 0x303, 0x69, 0x3, 0x2, 0x2, 0x2, 0x304, 
       0x305, 0x7, 0x68, 0x2, 0x2, 0x305, 0x306, 0x5, 0x180, 0xc1, 0x2, 
       0x306, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x307, 0x308, 0x7, 0x3d, 0x2, 0x2, 
       0x308, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x309, 0x30c, 0x5, 0xc4, 0x63, 0x2, 
       0x30a, 0x30c, 0x7, 0x5d, 0x2, 0x2, 0x30b, 0x309, 0x3, 0x2, 0x2, 0x2, 
       0x30b, 0x30a, 0x3, 0x2, 0x2, 0x2, 0x30c, 0x6f, 0x3, 0x2, 0x2, 0x2, 
       0x30d, 0x30f, 0x5, 0x198, 0xcd, 0x2, 0x30e, 0x30d, 0x3, 0x2, 0x2, 
       0x2, 0x30f, 0x312, 0x3, 0x2, 0x2, 0x2, 0x310, 0x30e, 0x3, 0x2, 0x2, 
       0x2, 0x310, 0x311, 0x3, 0x2, 0x2, 0x2, 0x311, 0x313, 0x3, 0x2, 0x2, 
       0x2, 0x312, 0x310, 0x3, 0x2, 0x2, 0x2, 0x313, 0x314, 0x5, 0x20, 0x11, 
       0x2, 0x314, 0x315, 0x5, 0x62, 0x32, 0x2, 0x315, 0x316, 0x5, 0x72, 
       0x3a, 0x2, 0x316, 0x71, 0x3, 0x2, 0x2, 0x2, 0x317, 0x318, 0x7, 0x54, 
       0x2, 0x2, 0x318, 0x319, 0x5, 0x74, 0x3b, 0x2, 0x319, 0x31b, 0x7, 
       0x55, 0x2, 0x2, 0x31a, 0x31c, 0x5, 0x7e, 0x40, 0x2, 0x31b, 0x31a, 
       0x3, 0x2, 0x2, 0x2, 0x31b, 0x31c, 0x3, 0x2, 0x2, 0x2, 0x31c, 0x73, 
       0x3, 0x2, 0x2, 0x2, 0x31d, 0x31f, 0x5, 0x76, 0x3c, 0x2, 0x31e, 0x320, 
       0x5, 0x78, 0x3d, 0x2, 0x31f, 0x31e, 0x3, 0x2, 0x2, 0x2, 0x31f, 0x320, 
       0x3, 0x2, 0x2, 0x2, 0x320, 0x326, 0x3, 0x2, 0x2, 0x2, 0x321, 0x323, 
       0x5, 0x78, 0x3d, 0x2, 0x322, 0x324, 0x5, 0x76, 0x3c, 0x2, 0x323, 
       0x322, 0x3, 0x2, 0x2, 0x2, 0x323, 0x324, 0x3, 0x2, 0x2, 0x2, 0x324, 
       0x326, 0x3, 0x2, 0x2, 0x2, 0x325, 0x31d, 0x3, 0x2, 0x2, 0x2, 0x325, 
       0x321, 0x3, 0x2, 0x2, 0x2, 0x326, 0x75, 0x3, 0x2, 0x2, 0x2, 0x327, 
       0x329, 0x5, 0x7a, 0x3e, 0x2, 0x328, 0x327, 0x3, 0x2, 0x2, 0x2, 0x328, 
       0x329, 0x3, 0x2, 0x2, 0x2, 0x329, 0x32a, 0x3, 0x2, 0x2, 0x2, 0x32a, 
       0x32b, 0x7, 0x20, 0x2, 0x2, 0x32b, 0x32c, 0x5, 0x7c, 0x3f, 0x2, 0x32c, 
       0x77, 0x3, 0x2, 0x2, 0x2, 0x32d, 0x32f, 0x5, 0x7a, 0x3e, 0x2, 0x32e, 
       0x32d, 0x3, 0x2, 0x2, 0x2, 0x32e, 0x32f, 0x3, 0x2, 0x2, 0x2, 0x32f, 
       0x330, 0x3, 0x2, 0x2, 0x2, 0x330, 0x331, 0x7, 0x38, 0x2, 0x2, 0x331, 
       0x332, 0x5, 0x7c, 0x3f, 0x2, 0x332, 0x79, 0x3, 0x2, 0x2, 0x2, 0x333, 
       0x33b, 0x7, 0x32, 0x2, 0x2, 0x334, 0x33b, 0x7, 0x27, 0x2, 0x2, 0x335, 
       0x33b, 0x7, 0x31, 0x2, 0x2, 0x336, 0x337, 0x7, 0x32, 0x2, 0x2, 0x337, 
       0x33b, 0x7, 0x27, 0x2, 0x2, 0x338, 0x339, 0x7, 0x27, 0x2, 0x2, 0x339, 
       0x33b, 0x7, 0x32, 0x2, 0x2, 0x33a, 0x333, 0x3, 0x2, 0x2, 0x2, 0x33a, 
       0x334, 0x3, 0x2, 0x2, 0x2, 0x33a, 0x335, 0x3, 0x2, 0x2, 0x2, 0x33a, 
       0x336, 0x3, 0x2, 0x2, 0x2, 0x33a, 0x338, 0x3, 0x2, 0x2, 0x2, 0x33b, 
       0x7b, 0x3, 0x2, 0x2, 0x2, 0x33c, 0x33f, 0x5, 0xc4, 0x63, 0x2, 0x33d, 
       0x33f, 0x7, 0x5d, 0x2, 0x2, 0x33e, 0x33c, 0x3, 0x2, 0x2, 0x2, 0x33e, 
       0x33d, 0x3, 0x2, 0x2, 0x2, 0x33f, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x340, 
       0x341, 0x7, 0x68, 0x2, 0x2, 0x341, 0x342, 0x5, 0x5a, 0x2e, 0x2, 0x342, 
       0x343, 0x7, 0x5d, 0x2, 0x2, 0x343, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x344, 
       0x346, 0x5, 0x82, 0x42, 0x2, 0x345, 0x344, 0x3, 0x2, 0x2, 0x2, 0x346, 
       0x349, 0x3, 0x2, 0x2, 0x2, 0x347, 0x345, 0x3, 0x2, 0x2, 0x2, 0x347, 
       0x348, 0x3, 0x2, 0x2, 0x2, 0x348, 0x34a, 0x3, 0x2, 0x2, 0x2, 0x349, 
       0x347, 0x3, 0x2, 0x2, 0x2, 0x34a, 0x34b, 0x5, 0x84, 0x43, 0x2, 0x34b, 
       0x34c, 0x5, 0x86, 0x44, 0x2, 0x34c, 0x81, 0x3, 0x2, 0x2, 0x2, 0x34d, 
       0x34e, 0x9, 0x6, 0x2, 0x2, 0x34e, 0x83, 0x3, 0x2, 0x2, 0x2, 0x34f, 
       0x350, 0x5, 0x20, 0x11, 0x2, 0x350, 0x351, 0x7, 0x3d, 0x2, 0x2, 0x351, 
       0x352, 0x7, 0x56, 0x2, 0x2, 0x352, 0x353, 0x5, 0x64, 0x33, 0x2, 0x353, 
       0x354, 0x7, 0x57, 0x2, 0x2, 0x354, 0x35e, 0x3, 0x2, 0x2, 0x2, 0x355, 
       0x356, 0x5, 0x20, 0x11, 0x2, 0x356, 0x357, 0x5, 0x3c, 0x1f, 0x2, 
       0x357, 0x358, 0x7, 0x5a, 0x2, 0x2, 0x358, 0x359, 0x7, 0x3d, 0x2, 
       0x2, 0x359, 0x35a, 0x7, 0x56, 0x2, 0x2, 0x35a, 0x35b, 0x5, 0x64, 
       0x33, 0x2, 0x35b, 0x35c, 0x7, 0x57, 0x2, 0x2, 0x35c, 0x35e, 0x3, 
       0x2, 0x2, 0x2, 0x35d, 0x34f, 0x3, 0x2, 0x2, 0x2, 0x35d, 0x355, 0x3, 
       0x2, 0x2, 0x2, 0x35e, 0x85, 0x3, 0x2, 0x2, 0x2, 0x35f, 0x360, 0x7, 
       0x54, 0x2, 0x2, 0x360, 0x361, 0x5, 0x74, 0x3b, 0x2, 0x361, 0x362, 
       0x7, 0x55, 0x2, 0x2, 0x362, 0x87, 0x3, 0x2, 0x2, 0x2, 0x363, 0x365, 
       0x5, 0x8a, 0x46, 0x2, 0x364, 0x363, 0x3, 0x2, 0x2, 0x2, 0x365, 0x366, 
       0x3, 0x2, 0x2, 0x2, 0x366, 0x364, 0x3, 0x2, 0x2, 0x2, 0x366, 0x367, 
       0x3, 0x2, 0x2, 0x2, 0x367, 0x368, 0x3, 0x2, 0x2, 0x2, 0x368, 0x369, 
       0x5, 0x8c, 0x47, 0x2, 0x369, 0x36a, 0x5, 0x98, 0x4d, 0x2, 0x36a, 
       0x89, 0x3, 0x2, 0x2, 0x2, 0x36b, 0x36c, 0x9, 0x7, 0x2, 0x2, 0x36c, 
       0x8b, 0x3, 0x2, 0x2, 0x2, 0x36d, 0x371, 0x5, 0x8e, 0x48, 0x2, 0x36e, 
       0x371, 0x5, 0x92, 0x4a, 0x2, 0x36f, 0x371, 0x5, 0x96, 0x4c, 0x2, 
       0x370, 0x36d, 0x3, 0x2, 0x2, 0x2, 0x370, 0x36e, 0x3, 0x2, 0x2, 0x2, 
       0x370, 0x36f, 0x3, 0x2, 0x2, 0x2, 0x371, 0x8d, 0x3, 0x2, 0x2, 0x2, 
       0x372, 0x373, 0x5, 0x20, 0x11, 0x2, 0x373, 0x374, 0x7, 0x2d, 0x2, 
       0x2, 0x374, 0x375, 0x5, 0x90, 0x49, 0x2, 0x375, 0x376, 0x7, 0x58, 
       0x2, 0x2, 0x376, 0x377, 0x5, 0x20, 0x11, 0x2, 0x377, 0x378, 0x5, 
       0x196, 0xcc, 0x2, 0x378, 0x379, 0x7, 0x59, 0x2, 0x2, 0x379, 0x8f, 
       0x3, 0x2, 0x2, 0x2, 0x37a, 0x37b, 0x9, 0x8, 0x2, 0x2, 0x37b, 0x91, 
       0x3, 0x2, 0x2, 0x2, 0x37c, 0x37d, 0x5, 0x20, 0x11, 0x2, 0x37d, 0x37e, 
       0x7, 0x2d, 0x2, 0x2, 0x37e, 0x37f, 0x5, 0x94, 0x4b, 0x2, 0x37f, 0x380, 
       0x7, 0x58, 0x2, 0x2, 0x380, 0x381, 0x5, 0x20, 0x11, 0x2, 0x381, 0x382, 
       0x5, 0x196, 0xcc, 0x2, 0x382, 0x383, 0x7, 0x5b, 0x2, 0x2, 0x383, 
       0x384, 0x5, 0x20, 0x11, 0x2, 0x384, 0x385, 0x5, 0x196, 0xcc, 0x2, 
       0x385, 0x386, 0x7, 0x59, 0x2, 0x2, 0x386, 0x93, 0x3, 0x2, 0x2, 0x2, 
       0x387, 0x398, 0x7, 0x5e, 0x2, 0x2, 0x388, 0x398, 0x7, 0x5f, 0x2, 
       0x2, 0x389, 0x398, 0x7, 0x60, 0x2, 0x2, 0x38a, 0x398, 0x7, 0x61, 
       0x2, 0x2, 0x38b, 0x398, 0x7, 0x62, 0x2, 0x2, 0x38c, 0x398, 0x7, 0x63, 
       0x2, 0x2, 0x38d, 0x398, 0x7, 0x64, 0x2, 0x2, 0x38e, 0x398, 0x7, 0x65, 
       0x2, 0x2, 0x38f, 0x398, 0x7, 0x7f, 0x2, 0x2, 0x390, 0x398, 0x5, 0x192, 
       0xca, 0x2, 0x391, 0x398, 0x7, 0x73, 0x2, 0x2, 0x392, 0x398, 0x7, 
       0x74, 0x2, 0x2, 0x393, 0x398, 0x7, 0x6a, 0x2, 0x2, 0x394, 0x398, 
       0x7, 0x69, 0x2, 0x2, 0x395, 0x398, 0x7, 0x76, 0x2, 0x2, 0x396, 0x398, 
       0x7, 0x75, 0x2, 0x2, 0x397, 0x387, 0x3, 0x2, 0x2, 0x2, 0x397, 0x388, 
       0x3, 0x2, 0x2, 0x2, 0x397, 0x389, 0x3, 0x2, 0x2, 0x2, 0x397, 0x38a, 
       0x3, 0x2, 0x2, 0x2, 0x397, 0x38b, 0x3, 0x2, 0x2, 0x2, 0x397, 0x38c, 
       0x3, 0x2, 0x2, 0x2, 0x397, 0x38d, 0x3, 0x2, 0x2, 0x2, 0x397, 0x38e, 
       0x3, 0x2, 0x2, 0x2, 0x397, 0x38f, 0x3, 0x2, 0x2, 0x2, 0x397, 0x390, 
       0x3, 0x2, 0x2, 0x2, 0x397, 0x391, 0x3, 0x2, 0x2, 0x2, 0x397, 0x392, 
       0x3, 0x2, 0x2, 0x2, 0x397, 0x393, 0x3, 0x2, 0x2, 0x2, 0x397, 0x394, 
       0x3, 0x2, 0x2, 0x2, 0x397, 0x395, 0x3, 0x2, 0x2, 0x2, 0x397, 0x396, 
       0x3, 0x2, 0x2, 0x2, 0x398, 0x95, 0x3, 0x2, 0x2, 0x2, 0x399, 0x39a, 
       0x7, 0x23, 0x2, 0x2, 0x39a, 0x39b, 0x7, 0x2d, 0x2, 0x2, 0x39b, 0x39c, 
       0x5, 0x20, 0x11, 0x2, 0x39c, 0x39d, 0x7, 0x58, 0x2, 0x2, 0x39d, 0x39e, 
       0x5, 0x20, 0x11, 0x2, 0x39e, 0x39f, 0x5, 0x196, 0xcc, 0x2, 0x39f, 
       0x3a0, 0x7, 0x59, 0x2, 0x2, 0x3a0, 0x3aa, 0x3, 0x2, 0x2, 0x2, 0x3a1, 
       0x3a2, 0x7, 0x1a, 0x2, 0x2, 0x3a2, 0x3a3, 0x7, 0x2d, 0x2, 0x2, 0x3a3, 
       0x3a4, 0x5, 0x20, 0x11, 0x2, 0x3a4, 0x3a5, 0x7, 0x58, 0x2, 0x2, 0x3a5, 
       0x3a6, 0x5, 0x20, 0x11, 0x2, 0x3a6, 0x3a7, 0x5, 0x196, 0xcc, 0x2, 
       0x3a7, 0x3a8, 0x7, 0x59, 0x2, 0x2, 0x3a8, 0x3aa, 0x3, 0x2, 0x2, 0x2, 
       0x3a9, 0x399, 0x3, 0x2, 0x2, 0x2, 0x3a9, 0x3a1, 0x3, 0x2, 0x2, 0x2, 
       0x3aa, 0x97, 0x3, 0x2, 0x2, 0x2, 0x3ab, 0x3ae, 0x5, 0xc4, 0x63, 0x2, 
       0x3ac, 0x3ae, 0x7, 0x5d, 0x2, 0x2, 0x3ad, 0x3ab, 0x3, 0x2, 0x2, 0x2, 
       0x3ad, 0x3ac, 0x3, 0x2, 0x2, 0x2, 0x3ae, 0x99, 0x3, 0x2, 0x2, 0x2, 
       0x3af, 0x3b1, 0x5, 0x9c, 0x4f, 0x2, 0x3b0, 0x3af, 0x3, 0x2, 0x2, 
       0x2, 0x3b1, 0x3b4, 0x3, 0x2, 0x2, 0x2, 0x3b2, 0x3b0, 0x3, 0x2, 0x2, 
       0x2, 0x3b2, 0x3b3, 0x3, 0x2, 0x2, 0x2, 0x3b3, 0x3b5, 0x3, 0x2, 0x2, 
       0x2, 0x3b4, 0x3b2, 0x3, 0x2, 0x2, 0x2, 0x3b5, 0x3b6, 0x5, 0x9e, 0x50, 
       0x2, 0x3b6, 0x3b7, 0x5, 0xa2, 0x52, 0x2, 0x3b7, 0x9b, 0x3, 0x2, 0x2, 
       0x2, 0x3b8, 0x3b9, 0x9, 0x9, 0x2, 0x2, 0x3b9, 0x9d, 0x3, 0x2, 0x2, 
       0x2, 0x3ba, 0x3bb, 0x5, 0x196, 0xcc, 0x2, 0x3bb, 0x3bd, 0x7, 0x58, 
       0x2, 0x2, 0x3bc, 0x3be, 0x5, 0x64, 0x33, 0x2, 0x3bd, 0x3bc, 0x3, 
       0x2, 0x2, 0x2, 0x3bd, 0x3be, 0x3, 0x2, 0x2, 0x2, 0x3be, 0x3bf, 0x3, 
       0x2, 0x2, 0x2, 0x3bf, 0x3c1, 0x7, 0x59, 0x2, 0x2, 0x3c0, 0x3c2, 0x5, 
       0xa0, 0x51, 0x2, 0x3c1, 0x3c0, 0x3, 0x2, 0x2, 0x2, 0x3c1, 0x3c2, 
       0x3, 0x2, 0x2, 0x2, 0x3c2, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x3c3, 0x3c4, 
       0x7, 0x5c, 0x2, 0x2, 0x3c4, 0x3c5, 0x7, 0xb, 0x2, 0x2, 0x3c5, 0x3c7, 
       0x7, 0x58, 0x2, 0x2, 0x3c6, 0x3c8, 0x5, 0x11a, 0x8e, 0x2, 0x3c7, 
       0x3c6, 0x3, 0x2, 0x2, 0x2, 0x3c7, 0x3c8, 0x3, 0x2, 0x2, 0x2, 0x3c8, 
       0x3c9, 0x3, 0x2, 0x2, 0x2, 0x3c9, 0x3d2, 0x7, 0x59, 0x2, 0x2, 0x3ca, 
       0x3cb, 0x7, 0x5c, 0x2, 0x2, 0x3cb, 0x3cc, 0x7, 0x3d, 0x2, 0x2, 0x3cc, 
       0x3ce, 0x7, 0x58, 0x2, 0x2, 0x3cd, 0x3cf, 0x5, 0x11a, 0x8e, 0x2, 
       0x3ce, 0x3cd, 0x3, 0x2, 0x2, 0x2, 0x3ce, 0x3cf, 0x3, 0x2, 0x2, 0x2, 
       0x3cf, 0x3d0, 0x3, 0x2, 0x2, 0x2, 0x3d0, 0x3d2, 0x7, 0x59, 0x2, 0x2, 
       0x3d1, 0x3c3, 0x3, 0x2, 0x2, 0x2, 0x3d1, 0x3ca, 0x3, 0x2, 0x2, 0x2, 
       0x3d2, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x3d3, 0x3d6, 0x5, 0xc4, 0x63, 0x2, 
       0x3d4, 0x3d6, 0x7, 0x5d, 0x2, 0x2, 0x3d5, 0x3d3, 0x3, 0x2, 0x2, 0x2, 
       0x3d5, 0x3d4, 0x3, 0x2, 0x2, 0x2, 0x3d6, 0xa3, 0x3, 0x2, 0x2, 0x2, 
       0x3d7, 0x3d8, 0x5, 0xa6, 0x54, 0x2, 0x3d8, 0x3d9, 0x5, 0x196, 0xcc, 
       0x2, 0x3d9, 0x3da, 0x7, 0x58, 0x2, 0x2, 0x3da, 0x3db, 0x7, 0x59, 
       0x2, 0x2, 0x3db, 0x3dc, 0x5, 0xa8, 0x55, 0x2, 0x3dc, 0xa5, 0x3, 0x2, 
       0x2, 0x2, 0x3dd, 0x3de, 0x7, 0x3a, 0x2, 0x2, 0x3de, 0xa7, 0x3, 0x2, 
       0x2, 0x2, 0x3df, 0x3e2, 0x5, 0xc4, 0x63, 0x2, 0x3e0, 0x3e2, 0x7, 
       0x5d, 0x2, 0x2, 0x3e1, 0x3df, 0x3, 0x2, 0x2, 0x2, 0x3e1, 0x3e0, 0x3, 
       0x2, 0x2, 0x2, 0x3e2, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x3e3, 0x3e4, 0x7, 
       0x67, 0x2, 0x2, 0x3e4, 0x3e5, 0x5, 0x196, 0xcc, 0x2, 0x3e5, 0x3e6, 
       0x7, 0x58, 0x2, 0x2, 0x3e6, 0x3e7, 0x7, 0x59, 0x2, 0x2, 0x3e7, 0x3e8, 
       0x5, 0xac, 0x57, 0x2, 0x3e8, 0xab, 0x3, 0x2, 0x2, 0x2, 0x3e9, 0x3ec, 
       0x5, 0xc4, 0x63, 0x2, 0x3ea, 0x3ec, 0x7, 0x5d, 0x2, 0x2, 0x3eb, 0x3e9, 
       0x3, 0x2, 0x2, 0x2, 0x3eb, 0x3ea, 0x3, 0x2, 0x2, 0x2, 0x3ec, 0xad, 
       0x3, 0x2, 0x2, 0x2, 0x3ed, 0x3ef, 0x5, 0x1e, 0x10, 0x2, 0x3ee, 0x3ed, 
       0x3, 0x2, 0x2, 0x2, 0x3ef, 0x3f2, 0x3, 0x2, 0x2, 0x2, 0x3f0, 0x3ee, 
       0x3, 0x2, 0x2, 0x2, 0x3f0, 0x3f1, 0x3, 0x2, 0x2, 0x2, 0x3f1, 0x3f3, 
       0x3, 0x2, 0x2, 0x2, 0x3f2, 0x3f0, 0x3, 0x2, 0x2, 0x2, 0x3f3, 0x3f4, 
       0x7, 0x26, 0x2, 0x2, 0x3f4, 0x3f6, 0x5, 0x196, 0xcc, 0x2, 0x3f5, 
       0x3f7, 0x5, 0xb0, 0x59, 0x2, 0x3f6, 0x3f5, 0x3, 0x2, 0x2, 0x2, 0x3f6, 
       0x3f7, 0x3, 0x2, 0x2, 0x2, 0x3f7, 0x3f9, 0x3, 0x2, 0x2, 0x2, 0x3f8, 
       0x3fa, 0x5, 0xb6, 0x5c, 0x2, 0x3f9, 0x3f8, 0x3, 0x2, 0x2, 0x2, 0x3f9, 
       0x3fa, 0x3, 0x2, 0x2, 0x2, 0x3fa, 0x3fe, 0x3, 0x2, 0x2, 0x2, 0x3fb, 
       0x3fd, 0x5, 0x18, 0xd, 0x2, 0x3fc, 0x3fb, 0x3, 0x2, 0x2, 0x2, 0x3fd, 
       0x400, 0x3, 0x2, 0x2, 0x2, 0x3fe, 0x3fc, 0x3, 0x2, 0x2, 0x2, 0x3fe, 
       0x3ff, 0x3, 0x2, 0x2, 0x2, 0x3ff, 0x401, 0x3, 0x2, 0x2, 0x2, 0x400, 
       0x3fe, 0x3, 0x2, 0x2, 0x2, 0x401, 0x403, 0x5, 0xb8, 0x5d, 0x2, 0x402, 
       0x404, 0x7, 0x5d, 0x2, 0x2, 0x403, 0x402, 0x3, 0x2, 0x2, 0x2, 0x403, 
       0x404, 0x3, 0x2, 0x2, 0x2, 0x404, 0xaf, 0x3, 0x2, 0x2, 0x2, 0x405, 
       0x406, 0x7, 0x69, 0x2, 0x2, 0x406, 0x407, 0x5, 0xb2, 0x5a, 0x2, 0x407, 
       0x408, 0x7, 0x6a, 0x2, 0x2, 0x408, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x409, 
       0x40b, 0x8, 0x5a, 0x1, 0x2, 0x40a, 0x40c, 0x5, 0xb4, 0x5b, 0x2, 0x40b, 
       0x40a, 0x3, 0x2, 0x2, 0x2, 0x40b, 0x40c, 0x3, 0x2, 0x2, 0x2, 0x40c, 
       0x40d, 0x3, 0x2, 0x2, 0x2, 0x40d, 0x40e, 0x5, 0x16, 0xc, 0x2, 0x40e, 
       0x417, 0x3, 0x2, 0x2, 0x2, 0x40f, 0x410, 0xc, 0x3, 0x2, 0x2, 0x410, 
       0x412, 0x7, 0x5b, 0x2, 0x2, 0x411, 0x413, 0x5, 0xb4, 0x5b, 0x2, 0x412, 
       0x411, 0x3, 0x2, 0x2, 0x2, 0x412, 0x413, 0x3, 0x2, 0x2, 0x2, 0x413, 
       0x414, 0x3, 0x2, 0x2, 0x2, 0x414, 0x416, 0x5, 0x16, 0xc, 0x2, 0x415, 
       0x40f, 0x3, 0x2, 0x2, 0x2, 0x416, 0x419, 0x3, 0x2, 0x2, 0x2, 0x417, 
       0x415, 0x3, 0x2, 0x2, 0x2, 0x417, 0x418, 0x3, 0x2, 0x2, 0x2, 0x418, 
       0xb3, 0x3, 0x2, 0x2, 0x2, 0x419, 0x417, 0x3, 0x2, 0x2, 0x2, 0x41a, 
       0x41b, 0x9, 0xa, 0x2, 0x2, 0x41b, 0xb5, 0x3, 0x2, 0x2, 0x2, 0x41c, 
       0x41d, 0x7, 0x5c, 0x2, 0x2, 0x41d, 0x41e, 0x5, 0x4c, 0x27, 0x2, 0x41e, 
       0xb7, 0x3, 0x2, 0x2, 0x2, 0x41f, 0x423, 0x7, 0x54, 0x2, 0x2, 0x420, 
       0x422, 0x5, 0xba, 0x5e, 0x2, 0x421, 0x420, 0x3, 0x2, 0x2, 0x2, 0x422, 
       0x425, 0x3, 0x2, 0x2, 0x2, 0x423, 0x421, 0x3, 0x2, 0x2, 0x2, 0x423, 
       0x424, 0x3, 0x2, 0x2, 0x2, 0x424, 0x426, 0x3, 0x2, 0x2, 0x2, 0x425, 
       0x423, 0x3, 0x2, 0x2, 0x2, 0x426, 0x427, 0x7, 0x55, 0x2, 0x2, 0x427, 
       0xb9, 0x3, 0x2, 0x2, 0x2, 0x428, 0x42c, 0x5, 0xbc, 0x5f, 0x2, 0x429, 
       0x42c, 0x5, 0xbe, 0x60, 0x2, 0x42a, 0x42c, 0x5, 0xc2, 0x62, 0x2, 
       0x42b, 0x428, 0x3, 0x2, 0x2, 0x2, 0x42b, 0x429, 0x3, 0x2, 0x2, 0x2, 
       0x42b, 0x42a, 0x3, 0x2, 0x2, 0x2, 0x42c, 0xbb, 0x3, 0x2, 0x2, 0x2, 
       0x42d, 0x42f, 0x7, 0x2a, 0x2, 0x2, 0x42e, 0x42d, 0x3, 0x2, 0x2, 0x2, 
       0x42e, 0x42f, 0x3, 0x2, 0x2, 0x2, 0x42f, 0x430, 0x3, 0x2, 0x2, 0x2, 
       0x430, 0x431, 0x5, 0x60, 0x31, 0x2, 0x431, 0x432, 0x5, 0x196, 0xcc, 
       0x2, 0x432, 0x433, 0x5, 0x12, 0xa, 0x2, 0x433, 0x435, 0x7, 0x58, 
       0x2, 0x2, 0x434, 0x436, 0x5, 0x64, 0x33, 0x2, 0x435, 0x434, 0x3, 
       0x2, 0x2, 0x2, 0x435, 0x436, 0x3, 0x2, 0x2, 0x2, 0x436, 0x437, 0x3, 
       0x2, 0x2, 0x2, 0x437, 0x43b, 0x7, 0x59, 0x2, 0x2, 0x438, 0x43a, 0x5, 
       0x18, 0xd, 0x2, 0x439, 0x438, 0x3, 0x2, 0x2, 0x2, 0x43a, 0x43d, 0x3, 
       0x2, 0x2, 0x2, 0x43b, 0x439, 0x3, 0x2, 0x2, 0x2, 0x43b, 0x43c, 0x3, 
       0x2, 0x2, 0x2, 0x43c, 0x43e, 0x3, 0x2, 0x2, 0x2, 0x43d, 0x43b, 0x3, 
       0x2, 0x2, 0x2, 0x43e, 0x43f, 0x7, 0x5d, 0x2, 0x2, 0x43f, 0xbd, 0x3, 
       0x2, 0x2, 0x2, 0x440, 0x442, 0x7, 0x2a, 0x2, 0x2, 0x441, 0x440, 0x3, 
       0x2, 0x2, 0x2, 0x441, 0x442, 0x3, 0x2, 0x2, 0x2, 0x442, 0x443, 0x3, 
       0x2, 0x2, 0x2, 0x443, 0x444, 0x5, 0x20, 0x11, 0x2, 0x444, 0x445, 
       0x5, 0x196, 0xcc, 0x2, 0x445, 0x446, 0x7, 0x54, 0x2, 0x2, 0x446, 
       0x447, 0x5, 0xc0, 0x61, 0x2, 0x447, 0x448, 0x7, 0x55, 0x2, 0x2, 0x448, 
       0xbf, 0x3, 0x2, 0x2, 0x2, 0x449, 0x44a, 0x7, 0x20, 0x2, 0x2, 0x44a, 
       0x456, 0x7, 0x5d, 0x2, 0x2, 0x44b, 0x44c, 0x7, 0x38, 0x2, 0x2, 0x44c, 
       0x456, 0x7, 0x5d, 0x2, 0x2, 0x44d, 0x44e, 0x7, 0x20, 0x2, 0x2, 0x44e, 
       0x44f, 0x7, 0x5d, 0x2, 0x2, 0x44f, 0x450, 0x7, 0x38, 0x2, 0x2, 0x450, 
       0x456, 0x7, 0x5d, 0x2, 0x2, 0x451, 0x452, 0x7, 0x38, 0x2, 0x2, 0x452, 
       0x453, 0x7, 0x5d, 0x2, 0x2, 0x453, 0x454, 0x7, 0x20, 0x2, 0x2, 0x454, 
       0x456, 0x7, 0x5d, 0x2, 0x2, 0x455, 0x449, 0x3, 0x2, 0x2, 0x2, 0x455, 
       0x44b, 0x3, 0x2, 0x2, 0x2, 0x455, 0x44d, 0x3, 0x2, 0x2, 0x2, 0x455, 
       0x451, 0x3, 0x2, 0x2, 0x2, 0x456, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x457, 
       0x459, 0x7, 0x2a, 0x2, 0x2, 0x458, 0x457, 0x3, 0x2, 0x2, 0x2, 0x458, 
       0x459, 0x3, 0x2, 0x2, 0x2, 0x459, 0x45a, 0x3, 0x2, 0x2, 0x2, 0x45a, 
       0x45b, 0x5, 0x20, 0x11, 0x2, 0x45b, 0x45c, 0x7, 0x3d, 0x2, 0x2, 0x45c, 
       0x45d, 0x7, 0x56, 0x2, 0x2, 0x45d, 0x45e, 0x5, 0x64, 0x33, 0x2, 0x45e, 
       0x45f, 0x7, 0x57, 0x2, 0x2, 0x45f, 0x460, 0x7, 0x54, 0x2, 0x2, 0x460, 
       0x461, 0x5, 0xc0, 0x61, 0x2, 0x461, 0x462, 0x7, 0x55, 0x2, 0x2, 0x462, 
       0xc3, 0x3, 0x2, 0x2, 0x2, 0x463, 0x465, 0x7, 0x54, 0x2, 0x2, 0x464, 
       0x466, 0x5, 0xc6, 0x64, 0x2, 0x465, 0x464, 0x3, 0x2, 0x2, 0x2, 0x465, 
       0x466, 0x3, 0x2, 0x2, 0x2, 0x466, 0x467, 0x3, 0x2, 0x2, 0x2, 0x467, 
       0x468, 0x7, 0x55, 0x2, 0x2, 0x468, 0xc5, 0x3, 0x2, 0x2, 0x2, 0x469, 
       0x46b, 0x5, 0xc8, 0x65, 0x2, 0x46a, 0x469, 0x3, 0x2, 0x2, 0x2, 0x46b, 
       0x46c, 0x3, 0x2, 0x2, 0x2, 0x46c, 0x46a, 0x3, 0x2, 0x2, 0x2, 0x46c, 
       0x46d, 0x3, 0x2, 0x2, 0x2, 0x46d, 0xc7, 0x3, 0x2, 0x2, 0x2, 0x46e, 
       0x472, 0x5, 0xca, 0x66, 0x2, 0x46f, 0x472, 0x5, 0xcc, 0x67, 0x2, 
       0x470, 0x472, 0x5, 0xde, 0x70, 0x2, 0x471, 0x46e, 0x3, 0x2, 0x2, 
       0x2, 0x471, 0x46f, 0x3, 0x2, 0x2, 0x2, 0x471, 0x470, 0x3, 0x2, 0x2, 
       0x2, 0x472, 0xc9, 0x3, 0x2, 0x2, 0x2, 0x473, 0x474, 0x5, 0x196, 0xcc, 
       0x2, 0x474, 0x475, 0x7, 0x5c, 0x2, 0x2, 0x475, 0x476, 0x5, 0xc8, 
       0x65, 0x2, 0x476, 0xcb, 0x3, 0x2, 0x2, 0x2, 0x477, 0x478, 0x5, 0xce, 
       0x68, 0x2, 0x478, 0x479, 0x7, 0x5d, 0x2, 0x2, 0x479, 0x47e, 0x3, 
       0x2, 0x2, 0x2, 0x47a, 0x47b, 0x5, 0xd8, 0x6d, 0x2, 0x47b, 0x47c, 
       0x7, 0x5d, 0x2, 0x2, 0x47c, 0x47e, 0x3, 0x2, 0x2, 0x2, 0x47d, 0x477, 
       0x3, 0x2, 0x2, 0x2, 0x47d, 0x47a, 0x3, 0x2, 0x2, 0x2, 0x47e, 0xcd, 
       0x3, 0x2, 0x2, 0x2, 0x47f, 0x480, 0x5, 0xd0, 0x69, 0x2, 0x480, 0x481, 
       0x5, 0xd2, 0x6a, 0x2, 0x481, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x482, 0x485, 
       0x5, 0x20, 0x11, 0x2, 0x483, 0x485, 0x7, 0x44, 0x2, 0x2, 0x484, 0x482, 
       0x3, 0x2, 0x2, 0x2, 0x484, 0x483, 0x3, 0x2, 0x2, 0x2, 0x485, 0xd1, 
       0x3, 0x2, 0x2, 0x2, 0x486, 0x48b, 0x5, 0xd4, 0x6b, 0x2, 0x487, 0x488, 
       0x7, 0x5b, 0x2, 0x2, 0x488, 0x48a, 0x5, 0xd4, 0x6b, 0x2, 0x489, 0x487, 
       0x3, 0x2, 0x2, 0x2, 0x48a, 0x48d, 0x3, 0x2, 0x2, 0x2, 0x48b, 0x489, 
       0x3, 0x2, 0x2, 0x2, 0x48b, 0x48c, 0x3, 0x2, 0x2, 0x2, 0x48c, 0xd3, 
       0x3, 0x2, 0x2, 0x2, 0x48d, 0x48b, 0x3, 0x2, 0x2, 0x2, 0x48e, 0x494, 
       0x5, 0x196, 0xcc, 0x2, 0x48f, 0x490, 0x5, 0x196, 0xcc, 0x2, 0x490, 
       0x491, 0x7, 0x68, 0x2, 0x2, 0x491, 0x492, 0x5, 0xd6, 0x6c, 0x2, 0x492, 
       0x494, 0x3, 0x2, 0x2, 0x2, 0x493, 0x48e, 0x3, 0x2, 0x2, 0x2, 0x493, 
       0x48f, 0x3, 0x2, 0x2, 0x2, 0x494, 0xd5, 0x3, 0x2, 0x2, 0x2, 0x495, 
       0x498, 0x5, 0x180, 0xc1, 0x2, 0x496, 0x498, 0x5, 0x18e, 0xc8, 0x2, 
       0x497, 0x495, 0x3, 0x2, 0x2, 0x2, 0x497, 0x496, 0x3, 0x2, 0x2, 0x2, 
       0x498, 0xd7, 0x3, 0x2, 0x2, 0x2, 0x499, 0x49a, 0x7, 0x12, 0x2, 0x2, 
       0x49a, 0x49b, 0x5, 0x20, 0x11, 0x2, 0x49b, 0x49c, 0x5, 0xda, 0x6e, 
       0x2, 0x49c, 0xd9, 0x3, 0x2, 0x2, 0x2, 0x49d, 0x4a2, 0x5, 0xdc, 0x6f, 
       0x2, 0x49e, 0x49f, 0x7, 0x5b, 0x2, 0x2, 0x49f, 0x4a1, 0x5, 0xdc, 
       0x6f, 0x2, 0x4a0, 0x49e, 0x3, 0x2, 0x2, 0x2, 0x4a1, 0x4a4, 0x3, 0x2, 
       0x2, 0x2, 0x4a2, 0x4a0, 0x3, 0x2, 0x2, 0x2, 0x4a2, 0x4a3, 0x3, 0x2, 
       0x2, 0x2, 0x4a3, 0xdb, 0x3, 0x2, 0x2, 0x2, 0x4a4, 0x4a2, 0x3, 0x2, 
       0x2, 0x2, 0x4a5, 0x4a6, 0x5, 0x196, 0xcc, 0x2, 0x4a6, 0x4a7, 0x7, 
       0x68, 0x2, 0x2, 0x4a7, 0x4a8, 0x5, 0x184, 0xc3, 0x2, 0x4a8, 0xdd, 
       0x3, 0x2, 0x2, 0x2, 0x4a9, 0x4b1, 0x5, 0xc4, 0x63, 0x2, 0x4aa, 0x4b1, 
       0x5, 0xe0, 0x71, 0x2, 0x4ab, 0x4b1, 0x5, 0xe2, 0x72, 0x2, 0x4ac, 
       0x4b1, 0x5, 0xe6, 0x74, 0x2, 0x4ad, 0x4b1, 0x5, 0xf2, 0x7a, 0x2, 
       0x4ae, 0x4b1, 0x5, 0x104, 0x83, 0x2, 0x4af, 0x4b1, 0x5, 0x110, 0x89, 
       0x2, 0x4b0, 0x4a9, 0x3, 0x2, 0x2, 0x2, 0x4b0, 0x4aa, 0x3, 0x2, 0x2, 
       0x2, 0x4b0, 0x4ab, 0x3, 0x2, 0x2, 0x2, 0x4b0, 0x4ac, 0x3, 0x2, 0x2, 
       0x2, 0x4b0, 0x4ad, 0x3, 0x2, 0x2, 0x2, 0x4b0, 0x4ae, 0x3, 0x2, 0x2, 
       0x2, 0x4b0, 0x4af, 0x3, 0x2, 0x2, 0x2, 0x4b1, 0xdf, 0x3, 0x2, 0x2, 
       0x2, 0x4b2, 0x4b3, 0x7, 0x5d, 0x2, 0x2, 0x4b3, 0xe1, 0x3, 0x2, 0x2, 
       0x2, 0x4b4, 0x4b5, 0x5, 0xe4, 0x73, 0x2, 0x4b5, 0x4b6, 0x7, 0x5d, 
       0x2, 0x2, 0x4b6, 0xe3, 0x3, 0x2, 0x2, 0x2, 0x4b7, 0x4bf, 0x5, 0x12a, 
       0x96, 0x2, 0x4b8, 0x4bf, 0x5, 0x136, 0x9c, 0x2, 0x4b9, 0x4bf, 0x5, 
       0x17c, 0xbf, 0x2, 0x4ba, 0x4bf, 0x5, 0x132, 0x9a, 0x2, 0x4bb, 0x4bf, 
       0x5, 0x134, 0x9b, 0x2, 0x4bc, 0x4bf, 0x5, 0x15e, 0xb0, 0x2, 0x4bd, 
       0x4bf, 0x5, 0x160, 0xb1, 0x2, 0x4be, 0x4b7, 0x3, 0x2, 0x2, 0x2, 0x4be, 
       0x4b8, 0x3, 0x2, 0x2, 0x2, 0x4be, 0x4b9, 0x3, 0x2, 0x2, 0x2, 0x4be, 
       0x4ba, 0x3, 0x2, 0x2, 0x2, 0x4be, 0x4bb, 0x3, 0x2, 0x2, 0x2, 0x4be, 
       0x4bc, 0x3, 0x2, 0x2, 0x2, 0x4be, 0x4bd, 0x3, 0x2, 0x2, 0x2, 0x4bf, 
       0xe5, 0x3, 0x2, 0x2, 0x2, 0x4c0, 0x4c3, 0x5, 0xe8, 0x75, 0x2, 0x4c1, 
       0x4c3, 0x5, 0xea, 0x76, 0x2, 0x4c2, 0x4c0, 0x3, 0x2, 0x2, 0x2, 0x4c2, 
       0x4c1, 0x3, 0x2, 0x2, 0x2, 0x4c3, 0xe7, 0x3, 0x2, 0x2, 0x2, 0x4c4, 
       0x4c5, 0x7, 0x22, 0x2, 0x2, 0x4c5, 0x4c6, 0x7, 0x58, 0x2, 0x2, 0x4c6, 
       0x4c7, 0x5, 0x180, 0xc1, 0x2, 0x4c7, 0x4c8, 0x7, 0x59, 0x2, 0x2, 
       0x4c8, 0x4c9, 0x5, 0xde, 0x70, 0x2, 0x4c9, 0x4d3, 0x3, 0x2, 0x2, 
       0x2, 0x4ca, 0x4cb, 0x7, 0x22, 0x2, 0x2, 0x4cb, 0x4cc, 0x7, 0x58, 
       0x2, 0x2, 0x4cc, 0x4cd, 0x5, 0x180, 0xc1, 0x2, 0x4cd, 0x4ce, 0x7, 
       0x59, 0x2, 0x2, 0x4ce, 0x4cf, 0x5, 0xde, 0x70, 0x2, 0x4cf, 0x4d0, 
       0x7, 0x17, 0x2, 0x2, 0x4d0, 0x4d1, 0x5, 0xde, 0x70, 0x2, 0x4d1, 0x4d3, 
       0x3, 0x2, 0x2, 0x2, 0x4d2, 0x4c4, 0x3, 0x2, 0x2, 0x2, 0x4d2, 0x4ca, 
       0x3, 0x2, 0x2, 0x2, 0x4d3, 0xe9, 0x3, 0x2, 0x2, 0x2, 0x4d4, 0x4d5, 
       0x7, 0x3c, 0x2, 0x2, 0x4d5, 0x4d6, 0x7, 0x58, 0x2, 0x2, 0x4d6, 0x4d7, 
       0x5, 0x180, 0xc1, 0x2, 0x4d7, 0x4d8, 0x7, 0x59, 0x2, 0x2, 0x4d8, 
       0x4d9, 0x5, 0xec, 0x77, 0x2, 0x4d9, 0xeb, 0x3, 0x2, 0x2, 0x2, 0x4da, 
       0x4de, 0x7, 0x54, 0x2, 0x2, 0x4db, 0x4dd, 0x5, 0xee, 0x78, 0x2, 0x4dc, 
       0x4db, 0x3, 0x2, 0x2, 0x2, 0x4dd, 0x4e0, 0x3, 0x2, 0x2, 0x2, 0x4de, 
       0x4dc, 0x3, 0x2, 0x2, 0x2, 0x4de, 0x4df, 0x3, 0x2, 0x2, 0x2, 0x4df, 
       0x4e1, 0x3, 0x2, 0x2, 0x2, 0x4e0, 0x4de, 0x3, 0x2, 0x2, 0x2, 0x4e1, 
       0x4e2, 0x7, 0x55, 0x2, 0x2, 0x4e2, 0xed, 0x3, 0x2, 0x2, 0x2, 0x4e3, 
       0x4e5, 0x5, 0xf0, 0x79, 0x2, 0x4e4, 0x4e3, 0x3, 0x2, 0x2, 0x2, 0x4e5, 
       0x4e6, 0x3, 0x2, 0x2, 0x2, 0x4e6, 0x4e4, 0x3, 0x2, 0x2, 0x2, 0x4e6, 
       0x4e7, 0x3, 0x2, 0x2, 0x2, 0x4e7, 0x4e8, 0x3, 0x2, 0x2, 0x2, 0x4e8, 
       0x4e9, 0x5, 0xc6, 0x64, 0x2, 0x4e9, 0xef, 0x3, 0x2, 0x2, 0x2, 0x4ea, 
       0x4eb, 0x7, 0xe, 0x2, 0x2, 0x4eb, 0x4ec, 0x5, 0x184, 0xc3, 0x2, 0x4ec, 
       0x4ed, 0x7, 0x5c, 0x2, 0x2, 0x4ed, 0x4f1, 0x3, 0x2, 0x2, 0x2, 0x4ee, 
       0x4ef, 0x7, 0x14, 0x2, 0x2, 0x4ef, 0x4f1, 0x7, 0x5c, 0x2, 0x2, 0x4f0, 
       0x4ea, 0x3, 0x2, 0x2, 0x2, 0x4f0, 0x4ee, 0x3, 0x2, 0x2, 0x2, 0x4f1, 
       0xf1, 0x3, 0x2, 0x2, 0x2, 0x4f2, 0x4f7, 0x5, 0xf4, 0x7b, 0x2, 0x4f3, 
       0x4f7, 0x5, 0xf6, 0x7c, 0x2, 0x4f4, 0x4f7, 0x5, 0xf8, 0x7d, 0x2, 
       0x4f5, 0x4f7, 0x5, 0x102, 0x82, 0x2, 0x4f6, 0x4f2, 0x3, 0x2, 0x2, 
       0x2, 0x4f6, 0x4f3, 0x3, 0x2, 0x2, 0x2, 0x4f6, 0x4f4, 0x3, 0x2, 0x2, 
       0x2, 0x4f6, 0x4f5, 0x3, 0x2, 0x2, 0x2, 0x4f7, 0xf3, 0x3, 0x2, 0x2, 
       0x2, 0x4f8, 0x4f9, 0x7, 0x49, 0x2, 0x2, 0x4f9, 0x4fa, 0x7, 0x58, 
       0x2, 0x2, 0x4fa, 0x4fb, 0x5, 0x186, 0xc4, 0x2, 0x4fb, 0x4fc, 0x7, 
       0x59, 0x2, 0x2, 0x4fc, 0x4fd, 0x5, 0xde, 0x70, 0x2, 0x4fd, 0xf5, 
       0x3, 0x2, 0x2, 0x2, 0x4fe, 0x4ff, 0x7, 0x15, 0x2, 0x2, 0x4ff, 0x500, 
       0x5, 0xde, 0x70, 0x2, 0x500, 0x501, 0x7, 0x49, 0x2, 0x2, 0x501, 0x502, 
       0x7, 0x58, 0x2, 0x2, 0x502, 0x503, 0x5, 0x186, 0xc4, 0x2, 0x503, 
       0x504, 0x7, 0x59, 0x2, 0x2, 0x504, 0x505, 0x7, 0x5d, 0x2, 0x2, 0x505, 
       0xf7, 0x3, 0x2, 0x2, 0x2, 0x506, 0x507, 0x7, 0x1e, 0x2, 0x2, 0x507, 
       0x509, 0x7, 0x58, 0x2, 0x2, 0x508, 0x50a, 0x5, 0xfa, 0x7e, 0x2, 0x509, 
       0x508, 0x3, 0x2, 0x2, 0x2, 0x509, 0x50a, 0x3, 0x2, 0x2, 0x2, 0x50a, 
       0x50b, 0x3, 0x2, 0x2, 0x2, 0x50b, 0x50d, 0x7, 0x5d, 0x2, 0x2, 0x50c, 
       0x50e, 0x5, 0xfc, 0x7f, 0x2, 0x50d, 0x50c, 0x3, 0x2, 0x2, 0x2, 0x50d, 
       0x50e, 0x3, 0x2, 0x2, 0x2, 0x50e, 0x50f, 0x3, 0x2, 0x2, 0x2, 0x50f, 
       0x511, 0x7, 0x5d, 0x2, 0x2, 0x510, 0x512, 0x5, 0xfe, 0x80, 0x2, 0x511, 
       0x510, 0x3, 0x2, 0x2, 0x2, 0x511, 0x512, 0x3, 0x2, 0x2, 0x2, 0x512, 
       0x513, 0x3, 0x2, 0x2, 0x2, 0x513, 0x514, 0x7, 0x59, 0x2, 0x2, 0x514, 
       0x515, 0x5, 0xde, 0x70, 0x2, 0x515, 0xf9, 0x3, 0x2, 0x2, 0x2, 0x516, 
       0x519, 0x5, 0xce, 0x68, 0x2, 0x517, 0x519, 0x5, 0x100, 0x81, 0x2, 
       0x518, 0x516, 0x3, 0x2, 0x2, 0x2, 0x518, 0x517, 0x3, 0x2, 0x2, 0x2, 
       0x519, 0xfb, 0x3, 0x2, 0x2, 0x2, 0x51a, 0x51b, 0x5, 0x186, 0xc4, 
       0x2, 0x51b, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x51c, 0x51d, 0x5, 0x100, 0x81, 
       0x2, 0x51d, 0xff, 0x3, 0x2, 0x2, 0x2, 0x51e, 0x523, 0x5, 0xe4, 0x73, 
       0x2, 0x51f, 0x520, 0x7, 0x5b, 0x2, 0x2, 0x520, 0x522, 0x5, 0xe4, 
       0x73, 0x2, 0x521, 0x51f, 0x3, 0x2, 0x2, 0x2, 0x522, 0x525, 0x3, 0x2, 
       0x2, 0x2, 0x523, 0x521, 0x3, 0x2, 0x2, 0x2, 0x523, 0x524, 0x3, 0x2, 
       0x2, 0x2, 0x524, 0x101, 0x3, 0x2, 0x2, 0x2, 0x525, 0x523, 0x3, 0x2, 
       0x2, 0x2, 0x526, 0x527, 0x7, 0x1f, 0x2, 0x2, 0x527, 0x528, 0x7, 0x58, 
       0x2, 0x2, 0x528, 0x529, 0x5, 0xd0, 0x69, 0x2, 0x529, 0x52a, 0x5, 
       0x196, 0xcc, 0x2, 0x52a, 0x52b, 0x7, 0x24, 0x2, 0x2, 0x52b, 0x52c, 
       0x5, 0x180, 0xc1, 0x2, 0x52c, 0x52d, 0x7, 0x59, 0x2, 0x2, 0x52d, 
       0x52e, 0x5, 0xde, 0x70, 0x2, 0x52e, 0x103, 0x3, 0x2, 0x2, 0x2, 0x52f, 
       0x535, 0x5, 0x106, 0x84, 0x2, 0x530, 0x535, 0x5, 0x108, 0x85, 0x2, 
       0x531, 0x535, 0x5, 0x10a, 0x86, 0x2, 0x532, 0x535, 0x5, 0x10c, 0x87, 
       0x2, 0x533, 0x535, 0x5, 0x10e, 0x88, 0x2, 0x534, 0x52f, 0x3, 0x2, 
       0x2, 0x2, 0x534, 0x530, 0x3, 0x2, 0x2, 0x2, 0x534, 0x531, 0x3, 0x2, 
       0x2, 0x2, 0x534, 0x532, 0x3, 0x2, 0x2, 0x2, 0x534, 0x533, 0x3, 0x2, 
       0x2, 0x2, 0x535, 0x105, 0x3, 0x2, 0x2, 0x2, 0x536, 0x537, 0x7, 0xd, 
       0x2, 0x2, 0x537, 0x538, 0x7, 0x5d, 0x2, 0x2, 0x538, 0x107, 0x3, 0x2, 
       0x2, 0x2, 0x539, 0x53a, 0x7, 0x13, 0x2, 0x2, 0x53a, 0x53b, 0x7, 0x5d, 
       0x2, 0x2, 0x53b, 0x109, 0x3, 0x2, 0x2, 0x2, 0x53c, 0x53d, 0x7, 0x21, 
       0x2, 0x2, 0x53d, 0x53e, 0x5, 0x196, 0xcc, 0x2, 0x53e, 0x53f, 0x7, 
       0x5d, 0x2, 0x2, 0x53f, 0x549, 0x3, 0x2, 0x2, 0x2, 0x540, 0x541, 0x7, 
       0x21, 0x2, 0x2, 0x541, 0x542, 0x7, 0xe, 0x2, 0x2, 0x542, 0x543, 0x5, 
       0x184, 0xc3, 0x2, 0x543, 0x544, 0x7, 0x5d, 0x2, 0x2, 0x544, 0x549, 
       0x3, 0x2, 0x2, 0x2, 0x545, 0x546, 0x7, 0x21, 0x2, 0x2, 0x546, 0x547, 
       0x7, 0x14, 0x2, 0x2, 0x547, 0x549, 0x7, 0x5d, 0x2, 0x2, 0x548, 0x53c, 
       0x3, 0x2, 0x2, 0x2, 0x548, 0x540, 0x3, 0x2, 0x2, 0x2, 0x548, 0x545, 
       0x3, 0x2, 0x2, 0x2, 0x549, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x54a, 0x54c, 
       0x7, 0x36, 0x2, 0x2, 0x54b, 0x54d, 0x5, 0x180, 0xc1, 0x2, 0x54c, 
       0x54b, 0x3, 0x2, 0x2, 0x2, 0x54c, 0x54d, 0x3, 0x2, 0x2, 0x2, 0x54d, 
       0x54e, 0x3, 0x2, 0x2, 0x2, 0x54e, 0x54f, 0x7, 0x5d, 0x2, 0x2, 0x54f, 
       0x10d, 0x3, 0x2, 0x2, 0x2, 0x550, 0x552, 0x7, 0x3e, 0x2, 0x2, 0x551, 
       0x553, 0x5, 0x180, 0xc1, 0x2, 0x552, 0x551, 0x3, 0x2, 0x2, 0x2, 0x552, 
       0x553, 0x3, 0x2, 0x2, 0x2, 0x553, 0x554, 0x3, 0x2, 0x2, 0x2, 0x554, 
       0x555, 0x7, 0x5d, 0x2, 0x2, 0x555, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x556, 
       0x557, 0x7, 0x40, 0x2, 0x2, 0x557, 0x559, 0x5, 0xc4, 0x63, 0x2, 0x558, 
       0x55a, 0x5, 0x112, 0x8a, 0x2, 0x559, 0x558, 0x3, 0x2, 0x2, 0x2, 0x55a, 
       0x55b, 0x3, 0x2, 0x2, 0x2, 0x55b, 0x559, 0x3, 0x2, 0x2, 0x2, 0x55b, 
       0x55c, 0x3, 0x2, 0x2, 0x2, 0x55c, 0x56b, 0x3, 0x2, 0x2, 0x2, 0x55d, 
       0x55e, 0x7, 0x40, 0x2, 0x2, 0x55e, 0x55f, 0x5, 0xc4, 0x63, 0x2, 0x55f, 
       0x560, 0x5, 0x118, 0x8d, 0x2, 0x560, 0x56b, 0x3, 0x2, 0x2, 0x2, 0x561, 
       0x562, 0x7, 0x40, 0x2, 0x2, 0x562, 0x564, 0x5, 0xc4, 0x63, 0x2, 0x563, 
       0x565, 0x5, 0x112, 0x8a, 0x2, 0x564, 0x563, 0x3, 0x2, 0x2, 0x2, 0x565, 
       0x566, 0x3, 0x2, 0x2, 0x2, 0x566, 0x564, 0x3, 0x2, 0x2, 0x2, 0x566, 
       0x567, 0x3, 0x2, 0x2, 0x2, 0x567, 0x568, 0x3, 0x2, 0x2, 0x2, 0x568, 
       0x569, 0x5, 0x118, 0x8d, 0x2, 0x569, 0x56b, 0x3, 0x2, 0x2, 0x2, 0x56a, 
       0x556, 0x3, 0x2, 0x2, 0x2, 0x56a, 0x55d, 0x3, 0x2, 0x2, 0x2, 0x56a, 
       0x561, 0x3, 0x2, 0x2, 0x2, 0x56b, 0x111, 0x3, 0x2, 0x2, 0x2, 0x56c, 
       0x56e, 0x7, 0xf, 0x2, 0x2, 0x56d, 0x56f, 0x5, 0x114, 0x8b, 0x2, 0x56e, 
       0x56d, 0x3, 0x2, 0x2, 0x2, 0x56e, 0x56f, 0x3, 0x2, 0x2, 0x2, 0x56f, 
       0x571, 0x3, 0x2, 0x2, 0x2, 0x570, 0x572, 0x5, 0x116, 0x8c, 0x2, 0x571, 
       0x570, 0x3, 0x2, 0x2, 0x2, 0x571, 0x572, 0x3, 0x2, 0x2, 0x2, 0x572, 
       0x573, 0x3, 0x2, 0x2, 0x2, 0x573, 0x574, 0x5, 0xc4, 0x63, 0x2, 0x574, 
       0x113, 0x3, 0x2, 0x2, 0x2, 0x575, 0x576, 0x7, 0x58, 0x2, 0x2, 0x576, 
       0x578, 0x5, 0x20, 0x11, 0x2, 0x577, 0x579, 0x5, 0x196, 0xcc, 0x2, 
       0x578, 0x577, 0x3, 0x2, 0x2, 0x2, 0x578, 0x579, 0x3, 0x2, 0x2, 0x2, 
       0x579, 0x57a, 0x3, 0x2, 0x2, 0x2, 0x57a, 0x57b, 0x7, 0x59, 0x2, 0x2, 
       0x57b, 0x115, 0x3, 0x2, 0x2, 0x2, 0x57c, 0x57d, 0x7, 0x47, 0x2, 0x2, 
       0x57d, 0x57e, 0x7, 0x58, 0x2, 0x2, 0x57e, 0x57f, 0x5, 0x180, 0xc1, 
       0x2, 0x57f, 0x580, 0x7, 0x59, 0x2, 0x2, 0x580, 0x117, 0x3, 0x2, 0x2, 
       0x2, 0x581, 0x582, 0x7, 0x1c, 0x2, 0x2, 0x582, 0x583, 0x5, 0xc4, 
       0x63, 0x2, 0x583, 0x119, 0x3, 0x2, 0x2, 0x2, 0x584, 0x589, 0x5, 0x180, 
       0xc1, 0x2, 0x585, 0x586, 0x7, 0x5b, 0x2, 0x2, 0x586, 0x588, 0x5, 
       0x180, 0xc1, 0x2, 0x587, 0x585, 0x3, 0x2, 0x2, 0x2, 0x588, 0x58b, 
       0x3, 0x2, 0x2, 0x2, 0x589, 0x587, 0x3, 0x2, 0x2, 0x2, 0x589, 0x58a, 
       0x3, 0x2, 0x2, 0x2, 0x58a, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x58b, 0x589, 
       0x3, 0x2, 0x2, 0x2, 0x58c, 0x58f, 0x5, 0x11e, 0x90, 0x2, 0x58d, 0x58f, 
       0x5, 0x152, 0xaa, 0x2, 0x58e, 0x58c, 0x3, 0x2, 0x2, 0x2, 0x58e, 0x58d, 
       0x3, 0x2, 0x2, 0x2, 0x58f, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x590, 0x592, 
       0x5, 0x120, 0x91, 0x2, 0x591, 0x593, 0x5, 0x122, 0x92, 0x2, 0x592, 
       0x591, 0x3, 0x2, 0x2, 0x2, 0x592, 0x593, 0x3, 0x2, 0x2, 0x2, 0x593, 
       0x11f, 0x3, 0x2, 0x2, 0x2, 0x594, 0x59d, 0x5, 0x188, 0xc5, 0x2, 0x595, 
       0x59d, 0x5, 0x124, 0x93, 0x2, 0x596, 0x59d, 0x5, 0x126, 0x94, 0x2, 
       0x597, 0x59d, 0x5, 0x12e, 0x98, 0x2, 0x598, 0x59d, 0x5, 0x130, 0x99, 
       0x2, 0x599, 0x59d, 0x5, 0x136, 0x9c, 0x2, 0x59a, 0x59d, 0x5, 0x14a, 
       0xa6, 0x2, 0x59b, 0x59d, 0x5, 0x150, 0xa9, 0x2, 0x59c, 0x594, 0x3, 
       0x2, 0x2, 0x2, 0x59c, 0x595, 0x3, 0x2, 0x2, 0x2, 0x59c, 0x596, 0x3, 
       0x2, 0x2, 0x2, 0x59c, 0x597, 0x3, 0x2, 0x2, 0x2, 0x59c, 0x598, 0x3, 
       0x2, 0x2, 0x2, 0x59c, 0x599, 0x3, 0x2, 0x2, 0x2, 0x59c, 0x59a, 0x3, 
       0x2, 0x2, 0x2, 0x59c, 0x59b, 0x3, 0x2, 0x2, 0x2, 0x59d, 0x121, 0x3, 
       0x2, 0x2, 0x2, 0x59e, 0x5a4, 0x5, 0x128, 0x95, 0x2, 0x59f, 0x5a4, 
       0x5, 0x12a, 0x96, 0x2, 0x5a0, 0x5a4, 0x5, 0x12c, 0x97, 0x2, 0x5a1, 
       0x5a4, 0x5, 0x132, 0x9a, 0x2, 0x5a2, 0x5a4, 0x5, 0x134, 0x9b, 0x2, 
       0x5a3, 0x59e, 0x3, 0x2, 0x2, 0x2, 0x5a3, 0x59f, 0x3, 0x2, 0x2, 0x2, 
       0x5a3, 0x5a0, 0x3, 0x2, 0x2, 0x2, 0x5a3, 0x5a1, 0x3, 0x2, 0x2, 0x2, 
       0x5a3, 0x5a2, 0x3, 0x2, 0x2, 0x2, 0x5a4, 0x123, 0x3, 0x2, 0x2, 0x2, 
       0x5a5, 0x5a7, 0x5, 0x196, 0xcc, 0x2, 0x5a6, 0x5a8, 0x5, 0x14, 0xb, 
       0x2, 0x5a7, 0x5a6, 0x3, 0x2, 0x2, 0x2, 0x5a7, 0x5a8, 0x3, 0x2, 0x2, 
       0x2, 0x5a8, 0x125, 0x3, 0x2, 0x2, 0x2, 0x5a9, 0x5aa, 0x7, 0x58, 0x2, 
       0x2, 0x5aa, 0x5ab, 0x5, 0x180, 0xc1, 0x2, 0x5ab, 0x5ac, 0x7, 0x59, 
       0x2, 0x2, 0x5ac, 0x127, 0x3, 0x2, 0x2, 0x2, 0x5ad, 0x5ae, 0x5, 0x11c, 
       0x8f, 0x2, 0x5ae, 0x5af, 0x7, 0x5a, 0x2, 0x2, 0x5af, 0x5b1, 0x5, 
       0x196, 0xcc, 0x2, 0x5b0, 0x5b2, 0x5, 0x14, 0xb, 0x2, 0x5b1, 0x5b0, 
       0x3, 0x2, 0x2, 0x2, 0x5b1, 0x5b2, 0x3, 0x2, 0x2, 0x2, 0x5b2, 0x5be, 
       0x3, 0x2, 0x2, 0x2, 0x5b3, 0x5b4, 0x5, 0x46, 0x24, 0x2, 0x5b4, 0x5b5, 
       0x7, 0x5a, 0x2, 0x2, 0x5b5, 0x5b7, 0x5, 0x196, 0xcc, 0x2, 0x5b6, 
       0x5b8, 0x5, 0x14, 0xb, 0x2, 0x5b7, 0x5b6, 0x3, 0x2, 0x2, 0x2, 0x5b7, 
       0x5b8, 0x3, 0x2, 0x2, 0x2, 0x5b8, 0x5be, 0x3, 0x2, 0x2, 0x2, 0x5b9, 
       0x5ba, 0x5, 0xe, 0x8, 0x2, 0x5ba, 0x5bb, 0x7, 0x5a, 0x2, 0x2, 0x5bb, 
       0x5bc, 0x5, 0x196, 0xcc, 0x2, 0x5bc, 0x5be, 0x3, 0x2, 0x2, 0x2, 0x5bd, 
       0x5ad, 0x3, 0x2, 0x2, 0x2, 0x5bd, 0x5b3, 0x3, 0x2, 0x2, 0x2, 0x5bd, 
       0x5b9, 0x3, 0x2, 0x2, 0x2, 0x5be, 0x129, 0x3, 0x2, 0x2, 0x2, 0x5bf, 
       0x5c0, 0x5, 0x11c, 0x8f, 0x2, 0x5c0, 0x5c2, 0x7, 0x58, 0x2, 0x2, 
       0x5c1, 0x5c3, 0x5, 0x11a, 0x8e, 0x2, 0x5c2, 0x5c1, 0x3, 0x2, 0x2, 
       0x2, 0x5c2, 0x5c3, 0x3, 0x2, 0x2, 0x2, 0x5c3, 0x5c4, 0x3, 0x2, 0x2, 
       0x2, 0x5c4, 0x5c5, 0x7, 0x59, 0x2, 0x2, 0x5c5, 0x12b, 0x3, 0x2, 0x2, 
       0x2, 0x5c6, 0x5c7, 0x5, 0x11e, 0x90, 0x2, 0x5c7, 0x5c8, 0x7, 0x56, 
       0x2, 0x2, 0x5c8, 0x5c9, 0x5, 0x148, 0xa5, 0x2, 0x5c9, 0x5ca, 0x7, 
       0x57, 0x2, 0x2, 0x5ca, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x5cb, 0x5cc, 0x7, 
       0x3d, 0x2, 0x2, 0x5cc, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x5cd, 0x5ce, 0x7, 
       0xb, 0x2, 0x2, 0x5ce, 0x5cf, 0x7, 0x5a, 0x2, 0x2, 0x5cf, 0x5d6, 0x5, 
       0x196, 0xcc, 0x2, 0x5d0, 0x5d1, 0x7, 0xb, 0x2, 0x2, 0x5d1, 0x5d2, 
       0x7, 0x56, 0x2, 0x2, 0x5d2, 0x5d3, 0x5, 0x148, 0xa5, 0x2, 0x5d3, 
       0x5d4, 0x7, 0x57, 0x2, 0x2, 0x5d4, 0x5d6, 0x3, 0x2, 0x2, 0x2, 0x5d5, 
       0x5cd, 0x3, 0x2, 0x2, 0x2, 0x5d5, 0x5d0, 0x3, 0x2, 0x2, 0x2, 0x5d6, 
       0x131, 0x3, 0x2, 0x2, 0x2, 0x5d7, 0x5d8, 0x5, 0x11c, 0x8f, 0x2, 0x5d8, 
       0x5d9, 0x7, 0x6e, 0x2, 0x2, 0x5d9, 0x133, 0x3, 0x2, 0x2, 0x2, 0x5da, 
       0x5db, 0x5, 0x11c, 0x8f, 0x2, 0x5db, 0x5dc, 0x7, 0x6f, 0x2, 0x2, 
       0x5dc, 0x135, 0x3, 0x2, 0x2, 0x2, 0x5dd, 0x5de, 0x7, 0x2a, 0x2, 0x2, 
       0x5de, 0x5df, 0x5, 0x20, 0x11, 0x2, 0x5df, 0x5e1, 0x7, 0x58, 0x2, 
       0x2, 0x5e0, 0x5e2, 0x5, 0x11a, 0x8e, 0x2, 0x5e1, 0x5e0, 0x3, 0x2, 
       0x2, 0x2, 0x5e1, 0x5e2, 0x3, 0x2, 0x2, 0x2, 0x5e2, 0x5e3, 0x3, 0x2, 
       0x2, 0x2, 0x5e3, 0x5e5, 0x7, 0x59, 0x2, 0x2, 0x5e4, 0x5e6, 0x5, 0x138, 
       0x9d, 0x2, 0x5e5, 0x5e4, 0x3, 0x2, 0x2, 0x2, 0x5e5, 0x5e6, 0x3, 0x2, 
       0x2, 0x2, 0x5e6, 0x5ec, 0x3, 0x2, 0x2, 0x2, 0x5e7, 0x5e8, 0x7, 0x2a, 
       0x2, 0x2, 0x5e8, 0x5e9, 0x5, 0x20, 0x11, 0x2, 0x5e9, 0x5ea, 0x5, 
       0x138, 0x9d, 0x2, 0x5ea, 0x5ec, 0x3, 0x2, 0x2, 0x2, 0x5eb, 0x5dd, 
       0x3, 0x2, 0x2, 0x2, 0x5eb, 0x5e7, 0x3, 0x2, 0x2, 0x2, 0x5ec, 0x137, 
       0x3, 0x2, 0x2, 0x2, 0x5ed, 0x5f0, 0x5, 0x13a, 0x9e, 0x2, 0x5ee, 0x5f0, 
       0x5, 0x142, 0xa2, 0x2, 0x5ef, 0x5ed, 0x3, 0x2, 0x2, 0x2, 0x5ef, 0x5ee, 
       0x3, 0x2, 0x2, 0x2, 0x5f0, 0x139, 0x3, 0x2, 0x2, 0x2, 0x5f1, 0x5f3, 
       0x7, 0x54, 0x2, 0x2, 0x5f2, 0x5f4, 0x5, 0x13c, 0x9f, 0x2, 0x5f3, 
       0x5f2, 0x3, 0x2, 0x2, 0x2, 0x5f3, 0x5f4, 0x3, 0x2, 0x2, 0x2, 0x5f4, 
       0x5f5, 0x3, 0x2, 0x2, 0x2, 0x5f5, 0x5fc, 0x7, 0x55, 0x2, 0x2, 0x5f6, 
       0x5f7, 0x7, 0x54, 0x2, 0x2, 0x5f7, 0x5f8, 0x5, 0x13c, 0x9f, 0x2, 
       0x5f8, 0x5f9, 0x7, 0x5b, 0x2, 0x2, 0x5f9, 0x5fa, 0x7, 0x55, 0x2, 
       0x2, 0x5fa, 0x5fc, 0x3, 0x2, 0x2, 0x2, 0x5fb, 0x5f1, 0x3, 0x2, 0x2, 
       0x2, 0x5fb, 0x5f6, 0x3, 0x2, 0x2, 0x2, 0x5fc, 0x13b, 0x3, 0x2, 0x2, 
       0x2, 0x5fd, 0x602, 0x5, 0x13e, 0xa0, 0x2, 0x5fe, 0x5ff, 0x7, 0x5b, 
       0x2, 0x2, 0x5ff, 0x601, 0x5, 0x13e, 0xa0, 0x2, 0x600, 0x5fe, 0x3, 
       0x2, 0x2, 0x2, 0x601, 0x604, 0x3, 0x2, 0x2, 0x2, 0x602, 0x600, 0x3, 
       0x2, 0x2, 0x2, 0x602, 0x603, 0x3, 0x2, 0x2, 0x2, 0x603, 0x13d, 0x3, 
       0x2, 0x2, 0x2, 0x604, 0x602, 0x3, 0x2, 0x2, 0x2, 0x605, 0x606, 0x5, 
       0x196, 0xcc, 0x2, 0x606, 0x607, 0x7, 0x68, 0x2, 0x2, 0x607, 0x608, 
       0x5, 0x140, 0xa1, 0x2, 0x608, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x609, 0x60c, 
       0x5, 0x180, 0xc1, 0x2, 0x60a, 0x60c, 0x5, 0x138, 0x9d, 0x2, 0x60b, 
       0x609, 0x3, 0x2, 0x2, 0x2, 0x60b, 0x60a, 0x3, 0x2, 0x2, 0x2, 0x60c, 
       0x141, 0x3, 0x2, 0x2, 0x2, 0x60d, 0x60e, 0x7, 0x54, 0x2, 0x2, 0x60e, 
       0x60f, 0x5, 0x144, 0xa3, 0x2, 0x60f, 0x610, 0x7, 0x55, 0x2, 0x2, 
       0x610, 0x617, 0x3, 0x2, 0x2, 0x2, 0x611, 0x612, 0x7, 0x54, 0x2, 0x2, 
       0x612, 0x613, 0x5, 0x144, 0xa3, 0x2, 0x613, 0x614, 0x7, 0x5b, 0x2, 
       0x2, 0x614, 0x615, 0x7, 0x55, 0x2, 0x2, 0x615, 0x617, 0x3, 0x2, 0x2, 
       0x2, 0x616, 0x60d, 0x3, 0x2, 0x2, 0x2, 0x616, 0x611, 0x3, 0x2, 0x2, 
       0x2, 0x617, 0x143, 0x3, 0x2, 0x2, 0x2, 0x618, 0x61d, 0x5, 0x146, 
       0xa4, 0x2, 0x619, 0x61a, 0x7, 0x5b, 0x2, 0x2, 0x61a, 0x61c, 0x5, 
       0x146, 0xa4, 0x2, 0x61b, 0x619, 0x3, 0x2, 0x2, 0x2, 0x61c, 0x61f, 
       0x3, 0x2, 0x2, 0x2, 0x61d, 0x61b, 0x3, 0x2, 0x2, 0x2, 0x61d, 0x61e, 
       0x3, 0x2, 0x2, 0x2, 0x61e, 0x145, 0x3, 0x2, 0x2, 0x2, 0x61f, 0x61d, 
       0x3, 0x2, 0x2, 0x2, 0x620, 0x626, 0x5, 0x182, 0xc2, 0x2, 0x621, 0x622, 
       0x7, 0x54, 0x2, 0x2, 0x622, 0x623, 0x5, 0x148, 0xa5, 0x2, 0x623, 
       0x624, 0x7, 0x55, 0x2, 0x2, 0x624, 0x626, 0x3, 0x2, 0x2, 0x2, 0x625, 
       0x620, 0x3, 0x2, 0x2, 0x2, 0x625, 0x621, 0x3, 0x2, 0x2, 0x2, 0x626, 
       0x147, 0x3, 0x2, 0x2, 0x2, 0x627, 0x62c, 0x5, 0x180, 0xc1, 0x2, 0x628, 
       0x629, 0x7, 0x5b, 0x2, 0x2, 0x629, 0x62b, 0x5, 0x180, 0xc1, 0x2, 
       0x62a, 0x628, 0x3, 0x2, 0x2, 0x2, 0x62b, 0x62e, 0x3, 0x2, 0x2, 0x2, 
       0x62c, 0x62a, 0x3, 0x2, 0x2, 0x2, 0x62c, 0x62d, 0x3, 0x2, 0x2, 0x2, 
       0x62d, 0x149, 0x3, 0x2, 0x2, 0x2, 0x62e, 0x62c, 0x3, 0x2, 0x2, 0x2, 
       0x62f, 0x630, 0x7, 0x41, 0x2, 0x2, 0x630, 0x631, 0x7, 0x58, 0x2, 
       0x2, 0x631, 0x632, 0x5, 0x20, 0x11, 0x2, 0x632, 0x633, 0x7, 0x59, 
       0x2, 0x2, 0x633, 0x63e, 0x3, 0x2, 0x2, 0x2, 0x634, 0x635, 0x7, 0x41, 
       0x2, 0x2, 0x635, 0x636, 0x7, 0x58, 0x2, 0x2, 0x636, 0x637, 0x5, 0x14c, 
       0xa7, 0x2, 0x637, 0x638, 0x7, 0x59, 0x2, 0x2, 0x638, 0x63e, 0x3, 
       0x2, 0x2, 0x2, 0x639, 0x63a, 0x7, 0x41, 0x2, 0x2, 0x63a, 0x63b, 0x7, 
       0x58, 0x2, 0x2, 0x63b, 0x63c, 0x7, 0x46, 0x2, 0x2, 0x63c, 0x63e, 
       0x7, 0x59, 0x2, 0x2, 0x63d, 0x62f, 0x3, 0x2, 0x2, 0x2, 0x63d, 0x634, 
       0x3, 0x2, 0x2, 0x2, 0x63d, 0x639, 0x3, 0x2, 0x2, 0x2, 0x63e, 0x14b, 
       0x3, 0x2, 0x2, 0x2, 0x63f, 0x640, 0x8, 0xa7, 0x1, 0x2, 0x640, 0x642, 
       0x5, 0x196, 0xcc, 0x2, 0x641, 0x643, 0x5, 0x14e, 0xa8, 0x2, 0x642, 
       0x641, 0x3, 0x2, 0x2, 0x2, 0x642, 0x643, 0x3, 0x2, 0x2, 0x2, 0x643, 
       0x64b, 0x3, 0x2, 0x2, 0x2, 0x644, 0x645, 0x5, 0x196, 0xcc, 0x2, 0x645, 
       0x646, 0x7, 0x6c, 0x2, 0x2, 0x646, 0x648, 0x5, 0x196, 0xcc, 0x2, 
       0x647, 0x649, 0x5, 0x14e, 0xa8, 0x2, 0x648, 0x647, 0x3, 0x2, 0x2, 
       0x2, 0x648, 0x649, 0x3, 0x2, 0x2, 0x2, 0x649, 0x64b, 0x3, 0x2, 0x2, 
       0x2, 0x64a, 0x63f, 0x3, 0x2, 0x2, 0x2, 0x64a, 0x644, 0x3, 0x2, 0x2, 
       0x2, 0x64b, 0x654, 0x3, 0x2, 0x2, 0x2, 0x64c, 0x64d, 0xc, 0x3, 0x2, 
       0x2, 0x64d, 0x64e, 0x7, 0x5a, 0x2, 0x2, 0x64e, 0x650, 0x5, 0x196, 
       0xcc, 0x2, 0x64f, 0x651, 0x5, 0x14e, 0xa8, 0x2, 0x650, 0x64f, 0x3, 
       0x2, 0x2, 0x2, 0x650, 0x651, 0x3, 0x2, 0x2, 0x2, 0x651, 0x653, 0x3, 
       0x2, 0x2, 0x2, 0x652, 0x64c, 0x3, 0x2, 0x2, 0x2, 0x653, 0x656, 0x3, 
       0x2, 0x2, 0x2, 0x654, 0x652, 0x3, 0x2, 0x2, 0x2, 0x654, 0x655, 0x3, 
       0x2, 0x2, 0x2, 0x655, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x656, 0x654, 0x3, 
       0x2, 0x2, 0x2, 0x657, 0x65b, 0x7, 0x69, 0x2, 0x2, 0x658, 0x65a, 0x7, 
       0x5b, 0x2, 0x2, 0x659, 0x658, 0x3, 0x2, 0x2, 0x2, 0x65a, 0x65d, 0x3, 
       0x2, 0x2, 0x2, 0x65b, 0x659, 0x3, 0x2, 0x2, 0x2, 0x65b, 0x65c, 0x3, 
       0x2, 0x2, 0x2, 0x65c, 0x65e, 0x3, 0x2, 0x2, 0x2, 0x65d, 0x65b, 0x3, 
       0x2, 0x2, 0x2, 0x65e, 0x65f, 0x7, 0x6a, 0x2, 0x2, 0x65f, 0x14f, 0x3, 
       0x2, 0x2, 0x2, 0x660, 0x661, 0x7, 0x14, 0x2, 0x2, 0x661, 0x662, 0x7, 
       0x58, 0x2, 0x2, 0x662, 0x663, 0x5, 0x20, 0x11, 0x2, 0x663, 0x664, 
       0x7, 0x59, 0x2, 0x2, 0x664, 0x151, 0x3, 0x2, 0x2, 0x2, 0x665, 0x666, 
       0x7, 0x2a, 0x2, 0x2, 0x666, 0x667, 0x5, 0x40, 0x21, 0x2, 0x667, 0x668, 
       0x7, 0x56, 0x2, 0x2, 0x668, 0x669, 0x5, 0x148, 0xa5, 0x2, 0x669, 
       0x66d, 0x7, 0x57, 0x2, 0x2, 0x66a, 0x66c, 0x5, 0x42, 0x22, 0x2, 0x66b, 
       0x66a, 0x3, 0x2, 0x2, 0x2, 0x66c, 0x66f, 0x3, 0x2, 0x2, 0x2, 0x66d, 
       0x66b, 0x3, 0x2, 0x2, 0x2, 0x66d, 0x66e, 0x3, 0x2, 0x2, 0x2, 0x66e, 
       0x671, 0x3, 0x2, 0x2, 0x2, 0x66f, 0x66d, 0x3, 0x2, 0x2, 0x2, 0x670, 
       0x672, 0x5, 0x18e, 0xc8, 0x2, 0x671, 0x670, 0x3, 0x2, 0x2, 0x2, 0x671, 
       0x672, 0x3, 0x2, 0x2, 0x2, 0x672, 0x678, 0x3, 0x2, 0x2, 0x2, 0x673, 
       0x674, 0x7, 0x2a, 0x2, 0x2, 0x674, 0x675, 0x5, 0x3e, 0x20, 0x2, 0x675, 
       0x676, 0x5, 0x18e, 0xc8, 0x2, 0x676, 0x678, 0x3, 0x2, 0x2, 0x2, 0x677, 
       0x665, 0x3, 0x2, 0x2, 0x2, 0x677, 0x673, 0x3, 0x2, 0x2, 0x2, 0x678, 
       0x153, 0x3, 0x2, 0x2, 0x2, 0x679, 0x682, 0x5, 0x11c, 0x8f, 0x2, 0x67a, 
       0x682, 0x5, 0x156, 0xac, 0x2, 0x67b, 0x682, 0x5, 0x158, 0xad, 0x2, 
       0x67c, 0x682, 0x5, 0x15a, 0xae, 0x2, 0x67d, 0x682, 0x5, 0x15c, 0xaf, 
       0x2, 0x67e, 0x682, 0x5, 0x15e, 0xb0, 0x2, 0x67f, 0x682, 0x5, 0x160, 
       0xb1, 0x2, 0x680, 0x682, 0x5, 0x162, 0xb2, 0x2, 0x681, 0x679, 0x3, 
       0x2, 0x2, 0x2, 0x681, 0x67a, 0x3, 0x2, 0x2, 0x2, 0x681, 0x67b, 0x3, 
       0x2, 0x2, 0x2, 0x681, 0x67c, 0x3, 0x2, 0x2, 0x2, 0x681, 0x67d, 0x3, 
       0x2, 0x2, 0x2, 0x681, 0x67e, 0x3, 0x2, 0x2, 0x2, 0x681, 0x67f, 0x3, 
       0x2, 0x2, 0x2, 0x681, 0x680, 0x3, 0x2, 0x2, 0x2, 0x682, 0x155, 0x3, 
       0x2, 0x2, 0x2, 0x683, 0x684, 0x7, 0x5e, 0x2, 0x2, 0x684, 0x685, 0x5, 
       0x154, 0xab, 0x2, 0x685, 0x157, 0x3, 0x2, 0x2, 0x2, 0x686, 0x687, 
       0x7, 0x5f, 0x2, 0x2, 0x687, 0x688, 0x5, 0x154, 0xab, 0x2, 0x688, 
       0x159, 0x3, 0x2, 0x2, 0x2, 0x689, 0x68a, 0x7, 0x66, 0x2, 0x2, 0x68a, 
       0x68b, 0x5, 0x154, 0xab, 0x2, 0x68b, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x68c, 
       0x68d, 0x7, 0x67, 0x2, 0x2, 0x68d, 0x68e, 0x5, 0x154, 0xab, 0x2, 
       0x68e, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x68f, 0x690, 0x7, 0x6e, 0x2, 0x2, 
       0x690, 0x691, 0x5, 0x154, 0xab, 0x2, 0x691, 0x15f, 0x3, 0x2, 0x2, 
       0x2, 0x692, 0x693, 0x7, 0x6f, 0x2, 0x2, 0x693, 0x694, 0x5, 0x154, 
       0xab, 0x2, 0x694, 0x161, 0x3, 0x2, 0x2, 0x2, 0x695, 0x696, 0x7, 0x58, 
       0x2, 0x2, 0x696, 0x697, 0x5, 0x20, 0x11, 0x2, 0x697, 0x698, 0x7, 
       0x59, 0x2, 0x2, 0x698, 0x699, 0x5, 0x154, 0xab, 0x2, 0x699, 0x163, 
       0x3, 0x2, 0x2, 0x2, 0x69a, 0x69b, 0x8, 0xb3, 0x1, 0x2, 0x69b, 0x69c, 
       0x5, 0x154, 0xab, 0x2, 0x69c, 0x6a8, 0x3, 0x2, 0x2, 0x2, 0x69d, 0x69e, 
       0xc, 0x5, 0x2, 0x2, 0x69e, 0x69f, 0x7, 0x60, 0x2, 0x2, 0x69f, 0x6a7, 
       0x5, 0x154, 0xab, 0x2, 0x6a0, 0x6a1, 0xc, 0x4, 0x2, 0x2, 0x6a1, 0x6a2, 
       0x7, 0x61, 0x2, 0x2, 0x6a2, 0x6a7, 0x5, 0x154, 0xab, 0x2, 0x6a3, 
       0x6a4, 0xc, 0x3, 0x2, 0x2, 0x6a4, 0x6a5, 0x7, 0x62, 0x2, 0x2, 0x6a5, 
       0x6a7, 0x5, 0x154, 0xab, 0x2, 0x6a6, 0x69d, 0x3, 0x2, 0x2, 0x2, 0x6a6, 
       0x6a0, 0x3, 0x2, 0x2, 0x2, 0x6a6, 0x6a3, 0x3, 0x2, 0x2, 0x2, 0x6a7, 
       0x6aa, 0x3, 0x2, 0x2, 0x2, 0x6a8, 0x6a6, 0x3, 0x2, 0x2, 0x2, 0x6a8, 
       0x6a9, 0x3, 0x2, 0x2, 0x2, 0x6a9, 0x165, 0x3, 0x2, 0x2, 0x2, 0x6aa, 
       0x6a8, 0x3, 0x2, 0x2, 0x2, 0x6ab, 0x6ac, 0x8, 0xb4, 0x1, 0x2, 0x6ac, 
       0x6ad, 0x5, 0x164, 0xb3, 0x2, 0x6ad, 0x6b6, 0x3, 0x2, 0x2, 0x2, 0x6ae, 
       0x6af, 0xc, 0x4, 0x2, 0x2, 0x6af, 0x6b0, 0x7, 0x5e, 0x2, 0x2, 0x6b0, 
       0x6b5, 0x5, 0x164, 0xb3, 0x2, 0x6b1, 0x6b2, 0xc, 0x3, 0x2, 0x2, 0x6b2, 
       0x6b3, 0x7, 0x5f, 0x2, 0x2, 0x6b3, 0x6b5, 0x5, 0x164, 0xb3, 0x2, 
       0x6b4, 0x6ae, 0x3, 0x2, 0x2, 0x2, 0x6b4, 0x6b1, 0x3, 0x2, 0x2, 0x2, 
       0x6b5, 0x6b8, 0x3, 0x2, 0x2, 0x2, 0x6b6, 0x6b4, 0x3, 0x2, 0x2, 0x2, 
       0x6b6, 0x6b7, 0x3, 0x2, 0x2, 0x2, 0x6b7, 0x167, 0x3, 0x2, 0x2, 0x2, 
       0x6b8, 0x6b6, 0x3, 0x2, 0x2, 0x2, 0x6b9, 0x6ba, 0x8, 0xb5, 0x1, 0x2, 
       0x6ba, 0x6bb, 0x5, 0x166, 0xb4, 0x2, 0x6bb, 0x6c5, 0x3, 0x2, 0x2, 
       0x2, 0x6bc, 0x6bd, 0xc, 0x4, 0x2, 0x2, 0x6bd, 0x6be, 0x7, 0x7f, 0x2, 
       0x2, 0x6be, 0x6c4, 0x5, 0x166, 0xb4, 0x2, 0x6bf, 0x6c0, 0xc, 0x3, 
       0x2, 0x2, 0x6c0, 0x6c1, 0x5, 0x192, 0xca, 0x2, 0x6c1, 0x6c2, 0x5, 
       0x166, 0xb4, 0x2, 0x6c2, 0x6c4, 0x3, 0x2, 0x2, 0x2, 0x6c3, 0x6bc, 
       0x3, 0x2, 0x2, 0x2, 0x6c3, 0x6bf, 0x3, 0x2, 0x2, 0x2, 0x6c4, 0x6c7, 
       0x3, 0x2, 0x2, 0x2, 0x6c5, 0x6c3, 0x3, 0x2, 0x2, 0x2, 0x6c5, 0x6c6, 
       0x3, 0x2, 0x2, 0x2, 0x6c6, 0x169, 0x3, 0x2, 0x2, 0x2, 0x6c7, 0x6c5, 
       0x3, 0x2, 0x2, 0x2, 0x6c8, 0x6c9, 0x8, 0xb6, 0x1, 0x2, 0x6c9, 0x6ca, 
       0x5, 0x168, 0xb5, 0x2, 0x6ca, 0x6df, 0x3, 0x2, 0x2, 0x2, 0x6cb, 0x6cc, 
       0xc, 0x8, 0x2, 0x2, 0x6cc, 0x6cd, 0x7, 0x69, 0x2, 0x2, 0x6cd, 0x6de, 
       0x5, 0x168, 0xb5, 0x2, 0x6ce, 0x6cf, 0xc, 0x7, 0x2, 0x2, 0x6cf, 0x6d0, 
       0x7, 0x6a, 0x2, 0x2, 0x6d0, 0x6de, 0x5, 0x168, 0xb5, 0x2, 0x6d1, 
       0x6d2, 0xc, 0x6, 0x2, 0x2, 0x6d2, 0x6d3, 0x7, 0x75, 0x2, 0x2, 0x6d3, 
       0x6de, 0x5, 0x168, 0xb5, 0x2, 0x6d4, 0x6d5, 0xc, 0x5, 0x2, 0x2, 0x6d5, 
       0x6d6, 0x7, 0x76, 0x2, 0x2, 0x6d6, 0x6de, 0x5, 0x168, 0xb5, 0x2, 
       0x6d7, 0x6d8, 0xc, 0x4, 0x2, 0x2, 0x6d8, 0x6d9, 0x7, 0xa, 0x2, 0x2, 
       0x6d9, 0x6de, 0x5, 0x20, 0x11, 0x2, 0x6da, 0x6db, 0xc, 0x3, 0x2, 
       0x2, 0x6db, 0x6dc, 0x7, 0x9, 0x2, 0x2, 0x6dc, 0x6de, 0x5, 0x20, 0x11, 
       0x2, 0x6dd, 0x6cb, 0x3, 0x2, 0x2, 0x2, 0x6dd, 0x6ce, 0x3, 0x2, 0x2, 
       0x2, 0x6dd, 0x6d1, 0x3, 0x2, 0x2, 0x2, 0x6dd, 0x6d4, 0x3, 0x2, 0x2, 
       0x2, 0x6dd, 0x6d7, 0x3, 0x2, 0x2, 0x2, 0x6dd, 0x6da, 0x3, 0x2, 0x2, 
       0x2, 0x6de, 0x6e1, 0x3, 0x2, 0x2, 0x2, 0x6df, 0x6dd, 0x3, 0x2, 0x2, 
       0x2, 0x6df, 0x6e0, 0x3, 0x2, 0x2, 0x2, 0x6e0, 0x16b, 0x3, 0x2, 0x2, 
       0x2, 0x6e1, 0x6df, 0x3, 0x2, 0x2, 0x2, 0x6e2, 0x6e3, 0x8, 0xb7, 0x1, 
       0x2, 0x6e3, 0x6e4, 0x5, 0x16a, 0xb6, 0x2, 0x6e4, 0x6ed, 0x3, 0x2, 
       0x2, 0x2, 0x6e5, 0x6e6, 0xc, 0x4, 0x2, 0x2, 0x6e6, 0x6e7, 0x7, 0x73, 
       0x2, 0x2, 0x6e7, 0x6ec, 0x5, 0x16a, 0xb6, 0x2, 0x6e8, 0x6e9, 0xc, 
       0x3, 0x2, 0x2, 0x6e9, 0x6ea, 0x7, 0x74, 0x2, 0x2, 0x6ea, 0x6ec, 0x5, 
       0x16a, 0xb6, 0x2, 0x6eb, 0x6e5, 0x3, 0x2, 0x2, 0x2, 0x6eb, 0x6e8, 
       0x3, 0x2, 0x2, 0x2, 0x6ec, 0x6ef, 0x3, 0x2, 0x2, 0x2, 0x6ed, 0x6eb, 
       0x3, 0x2, 0x2, 0x2, 0x6ed, 0x6ee, 0x3, 0x2, 0x2, 0x2, 0x6ee, 0x16d, 
       0x3, 0x2, 0x2, 0x2, 0x6ef, 0x6ed, 0x3, 0x2, 0x2, 0x2, 0x6f0, 0x6f1, 
       0x8, 0xb8, 0x1, 0x2, 0x6f1, 0x6f2, 0x5, 0x16c, 0xb7, 0x2, 0x6f2, 
       0x6f8, 0x3, 0x2, 0x2, 0x2, 0x6f3, 0x6f4, 0xc, 0x3, 0x2, 0x2, 0x6f4, 
       0x6f5, 0x7, 0x63, 0x2, 0x2, 0x6f5, 0x6f7, 0x5, 0x16c, 0xb7, 0x2, 
       0x6f6, 0x6f3, 0x3, 0x2, 0x2, 0x2, 0x6f7, 0x6fa, 0x3, 0x2, 0x2, 0x2, 
       0x6f8, 0x6f6, 0x3, 0x2, 0x2, 0x2, 0x6f8, 0x6f9, 0x3, 0x2, 0x2, 0x2, 
       0x6f9, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x6fa, 0x6f8, 0x3, 0x2, 0x2, 0x2, 
       0x6fb, 0x6fc, 0x8, 0xb9, 0x1, 0x2, 0x6fc, 0x6fd, 0x5, 0x16e, 0xb8, 
       0x2, 0x6fd, 0x703, 0x3, 0x2, 0x2, 0x2, 0x6fe, 0x6ff, 0xc, 0x3, 0x2, 
       0x2, 0x6ff, 0x700, 0x7, 0x65, 0x2, 0x2, 0x700, 0x702, 0x5, 0x16e, 
       0xb8, 0x2, 0x701, 0x6fe, 0x3, 0x2, 0x2, 0x2, 0x702, 0x705, 0x3, 0x2, 
       0x2, 0x2, 0x703, 0x701, 0x3, 0x2, 0x2, 0x2, 0x703, 0x704, 0x3, 0x2, 
       0x2, 0x2, 0x704, 0x171, 0x3, 0x2, 0x2, 0x2, 0x705, 0x703, 0x3, 0x2, 
       0x2, 0x2, 0x706, 0x707, 0x8, 0xba, 0x1, 0x2, 0x707, 0x708, 0x5, 0x170, 
       0xb9, 0x2, 0x708, 0x70e, 0x3, 0x2, 0x2, 0x2, 0x709, 0x70a, 0xc, 0x3, 
       0x2, 0x2, 0x70a, 0x70b, 0x7, 0x64, 0x2, 0x2, 0x70b, 0x70d, 0x5, 0x170, 
       0xb9, 0x2, 0x70c, 0x709, 0x3, 0x2, 0x2, 0x2, 0x70d, 0x710, 0x3, 0x2, 
       0x2, 0x2, 0x70e, 0x70c, 0x3, 0x2, 0x2, 0x2, 0x70e, 0x70f, 0x3, 0x2, 
       0x2, 0x2, 0x70f, 0x173, 0x3, 0x2, 0x2, 0x2, 0x710, 0x70e, 0x3, 0x2, 
       0x2, 0x2, 0x711, 0x712, 0x8, 0xbb, 0x1, 0x2, 0x712, 0x713, 0x5, 0x172, 
       0xba, 0x2, 0x713, 0x719, 0x3, 0x2, 0x2, 0x2, 0x714, 0x715, 0xc, 0x3, 
       0x2, 0x2, 0x715, 0x716, 0x7, 0x70, 0x2, 0x2, 0x716, 0x718, 0x5, 0x172, 
       0xba, 0x2, 0x717, 0x714, 0x3, 0x2, 0x2, 0x2, 0x718, 0x71b, 0x3, 0x2, 
       0x2, 0x2, 0x719, 0x717, 0x3, 0x2, 0x2, 0x2, 0x719, 0x71a, 0x3, 0x2, 
       0x2, 0x2, 0x71a, 0x175, 0x3, 0x2, 0x2, 0x2, 0x71b, 0x719, 0x3, 0x2, 
       0x2, 0x2, 0x71c, 0x71d, 0x8, 0xbc, 0x1, 0x2, 0x71d, 0x71e, 0x5, 0x174, 
       0xbb, 0x2, 0x71e, 0x724, 0x3, 0x2, 0x2, 0x2, 0x71f, 0x720, 0xc, 0x3, 
       0x2, 0x2, 0x720, 0x721, 0x7, 0x71, 0x2, 0x2, 0x721, 0x723, 0x5, 0x174, 
       0xbb, 0x2, 0x722, 0x71f, 0x3, 0x2, 0x2, 0x2, 0x723, 0x726, 0x3, 0x2, 
       0x2, 0x2, 0x724, 0x722, 0x3, 0x2, 0x2, 0x2, 0x724, 0x725, 0x3, 0x2, 
       0x2, 0x2, 0x725, 0x177, 0x3, 0x2, 0x2, 0x2, 0x726, 0x724, 0x3, 0x2, 
       0x2, 0x2, 0x727, 0x72d, 0x5, 0x176, 0xbc, 0x2, 0x728, 0x729, 0x5, 
       0x176, 0xbc, 0x2, 0x729, 0x72a, 0x7, 0x6d, 0x2, 0x2, 0x72a, 0x72b, 
       0x5, 0x178, 0xbd, 0x2, 0x72b, 0x72d, 0x3, 0x2, 0x2, 0x2, 0x72c, 0x727, 
       0x3, 0x2, 0x2, 0x2, 0x72c, 0x728, 0x3, 0x2, 0x2, 0x2, 0x72d, 0x179, 
       0x3, 0x2, 0x2, 0x2, 0x72e, 0x736, 0x5, 0x178, 0xbd, 0x2, 0x72f, 0x730, 
       0x5, 0x178, 0xbd, 0x2, 0x730, 0x731, 0x7, 0x6b, 0x2, 0x2, 0x731, 
       0x732, 0x5, 0x180, 0xc1, 0x2, 0x732, 0x733, 0x7, 0x5c, 0x2, 0x2, 
       0x733, 0x734, 0x5, 0x180, 0xc1, 0x2, 0x734, 0x736, 0x3, 0x2, 0x2, 
       0x2, 0x735, 0x72e, 0x3, 0x2, 0x2, 0x2, 0x735, 0x72f, 0x3, 0x2, 0x2, 
       0x2, 0x736, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x737, 0x738, 0x5, 0x154, 
       0xab, 0x2, 0x738, 0x739, 0x5, 0x17e, 0xc0, 0x2, 0x739, 0x73a, 0x5, 
       0x180, 0xc1, 0x2, 0x73a, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x73b, 0x747, 
       0x7, 0x68, 0x2, 0x2, 0x73c, 0x747, 0x7, 0x77, 0x2, 0x2, 0x73d, 0x747, 
       0x7, 0x78, 0x2, 0x2, 0x73e, 0x747, 0x7, 0x79, 0x2, 0x2, 0x73f, 0x747, 
       0x7, 0x7a, 0x2, 0x2, 0x740, 0x747, 0x7, 0x7b, 0x2, 0x2, 0x741, 0x747, 
       0x7, 0x7c, 0x2, 0x2, 0x742, 0x747, 0x7, 0x7d, 0x2, 0x2, 0x743, 0x747, 
       0x7, 0x7e, 0x2, 0x2, 0x744, 0x747, 0x7, 0x80, 0x2, 0x2, 0x745, 0x747, 
       0x5, 0x194, 0xcb, 0x2, 0x746, 0x73b, 0x3, 0x2, 0x2, 0x2, 0x746, 0x73c, 
       0x3, 0x2, 0x2, 0x2, 0x746, 0x73d, 0x3, 0x2, 0x2, 0x2, 0x746, 0x73e, 
       0x3, 0x2, 0x2, 0x2, 0x746, 0x73f, 0x3, 0x2, 0x2, 0x2, 0x746, 0x740, 
       0x3, 0x2, 0x2, 0x2, 0x746, 0x741, 0x3, 0x2, 0x2, 0x2, 0x746, 0x742, 
       0x3, 0x2, 0x2, 0x2, 0x746, 0x743, 0x3, 0x2, 0x2, 0x2, 0x746, 0x744, 
       0x3, 0x2, 0x2, 0x2, 0x746, 0x745, 0x3, 0x2, 0x2, 0x2, 0x747, 0x17f, 
       0x3, 0x2, 0x2, 0x2, 0x748, 0x74b, 0x5, 0x182, 0xc2, 0x2, 0x749, 0x74b, 
       0x5, 0x17c, 0xbf, 0x2, 0x74a, 0x748, 0x3, 0x2, 0x2, 0x2, 0x74a, 0x749, 
       0x3, 0x2, 0x2, 0x2, 0x74b, 0x181, 0x3, 0x2, 0x2, 0x2, 0x74c, 0x74d, 
       0x5, 0x17a, 0xbe, 0x2, 0x74d, 0x183, 0x3, 0x2, 0x2, 0x2, 0x74e, 0x74f, 
       0x5, 0x180, 0xc1, 0x2, 0x74f, 0x185, 0x3, 0x2, 0x2, 0x2, 0x750, 0x751, 
       0x5, 0x180, 0xc1, 0x2, 0x751, 0x187, 0x3, 0x2, 0x2, 0x2, 0x752, 0x75c, 
       0x5, 0x18a, 0xc6, 0x2, 0x753, 0x75c, 0x5, 0x18c, 0xc7, 0x2, 0x754, 
       0x75c, 0x7, 0x4c, 0x2, 0x2, 0x755, 0x75c, 0x7, 0x4d, 0x2, 0x2, 0x756, 
       0x75c, 0x7, 0x4e, 0x2, 0x2, 0x757, 0x75c, 0x7, 0x4f, 0x2, 0x2, 0x758, 
       0x75c, 0x7, 0x50, 0x2, 0x2, 0x759, 0x75c, 0x7, 0x51, 0x2, 0x2, 0x75a, 
       0x75c, 0x7, 0x2b, 0x2, 0x2, 0x75b, 0x752, 0x3, 0x2, 0x2, 0x2, 0x75b, 
       0x753, 0x3, 0x2, 0x2, 0x2, 0x75b, 0x754, 0x3, 0x2, 0x2, 0x2, 0x75b, 
       0x755, 0x3, 0x2, 0x2, 0x2, 0x75b, 0x756, 0x3, 0x2, 0x2, 0x2, 0x75b, 
       0x757, 0x3, 0x2, 0x2, 0x2, 0x75b, 0x758, 0x3, 0x2, 0x2, 0x2, 0x75b, 
       0x759, 0x3, 0x2, 0x2, 0x2, 0x75b, 0x75a, 0x3, 0x2, 0x2, 0x2, 0x75c, 
       0x189, 0x3, 0x2, 0x2, 0x2, 0x75d, 0x75e, 0x9, 0xb, 0x2, 0x2, 0x75e, 
       0x18b, 0x3, 0x2, 0x2, 0x2, 0x75f, 0x760, 0x9, 0xc, 0x2, 0x2, 0x760, 
       0x18d, 0x3, 0x2, 0x2, 0x2, 0x761, 0x763, 0x7, 0x54, 0x2, 0x2, 0x762, 
       0x764, 0x5, 0x190, 0xc9, 0x2, 0x763, 0x762, 0x3, 0x2, 0x2, 0x2, 0x763, 
       0x764, 0x3, 0x2, 0x2, 0x2, 0x764, 0x765, 0x3, 0x2, 0x2, 0x2, 0x765, 
       0x76c, 0x7, 0x55, 0x2, 0x2, 0x766, 0x767, 0x7, 0x54, 0x2, 0x2, 0x767, 
       0x768, 0x5, 0x190, 0xc9, 0x2, 0x768, 0x769, 0x7, 0x5b, 0x2, 0x2, 
       0x769, 0x76a, 0x7, 0x55, 0x2, 0x2, 0x76a, 0x76c, 0x3, 0x2, 0x2, 0x2, 
       0x76b, 0x761, 0x3, 0x2, 0x2, 0x2, 0x76b, 0x766, 0x3, 0x2, 0x2, 0x2, 
       0x76c, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x76d, 0x772, 0x5, 0x5a, 0x2e, 
       0x2, 0x76e, 0x76f, 0x7, 0x5b, 0x2, 0x2, 0x76f, 0x771, 0x5, 0x5a, 
       0x2e, 0x2, 0x770, 0x76e, 0x3, 0x2, 0x2, 0x2, 0x771, 0x774, 0x3, 0x2, 
       0x2, 0x2, 0x772, 0x770, 0x3, 0x2, 0x2, 0x2, 0x772, 0x773, 0x3, 0x2, 
       0x2, 0x2, 0x773, 0x191, 0x3, 0x2, 0x2, 0x2, 0x774, 0x772, 0x3, 0x2, 
       0x2, 0x2, 0x775, 0x776, 0x7, 0x6a, 0x2, 0x2, 0x776, 0x777, 0x7, 0x6a, 
       0x2, 0x2, 0x777, 0x778, 0x6, 0xca, 0x19, 0x3, 0x778, 0x193, 0x3, 
       0x2, 0x2, 0x2, 0x779, 0x77a, 0x7, 0x6a, 0x2, 0x2, 0x77a, 0x77b, 0x7, 
       0x76, 0x2, 0x2, 0x77b, 0x77c, 0x6, 0xcb, 0x1a, 0x3, 0x77c, 0x195, 
       0x3, 0x2, 0x2, 0x2, 0x77d, 0x77e, 0x7, 0x4a, 0x2, 0x2, 0x77e, 0x197, 
       0x3, 0x2, 0x2, 0x2, 0x77f, 0x780, 0x9, 0xd, 0x2, 0x2, 0x780, 0x199, 
       0x3, 0x2, 0x2, 0x2, 0xb8, 0x19d, 0x1a3, 0x1b7, 0x1bb, 0x1c1, 0x1c8, 
       0x1cf, 0x1d5, 0x1de, 0x1e2, 0x1ea, 0x1f5, 0x203, 0x20e, 0x217, 0x21a, 
       0x220, 0x224, 0x229, 0x22d, 0x233, 0x237, 0x23b, 0x246, 0x24b, 0x253, 
       0x259, 0x25f, 0x26b, 0x271, 0x274, 0x279, 0x27e, 0x289, 0x290, 0x297, 
       0x2a6, 0x2ab, 0x2b6, 0x2c2, 0x2c8, 0x2cc, 0x2d4, 0x2da, 0x2de, 0x2e4, 
       0x2e9, 0x2f0, 0x2f9, 0x2fd, 0x302, 0x30b, 0x310, 0x31b, 0x31f, 0x323, 
       0x325, 0x328, 0x32e, 0x33a, 0x33e, 0x347, 0x35d, 0x366, 0x370, 0x397, 
       0x3a9, 0x3ad, 0x3b2, 0x3bd, 0x3c1, 0x3c7, 0x3ce, 0x3d1, 0x3d5, 0x3e1, 
       0x3eb, 0x3f0, 0x3f6, 0x3f9, 0x3fe, 0x403, 0x40b, 0x412, 0x417, 0x423, 
       0x42b, 0x42e, 0x435, 0x43b, 0x441, 0x455, 0x458, 0x465, 0x46c, 0x471, 
       0x47d, 0x484, 0x48b, 0x493, 0x497, 0x4a2, 0x4b0, 0x4be, 0x4c2, 0x4d2, 
       0x4de, 0x4e6, 0x4f0, 0x4f6, 0x509, 0x50d, 0x511, 0x518, 0x523, 0x534, 
       0x548, 0x54c, 0x552, 0x55b, 0x566, 0x56a, 0x56e, 0x571, 0x578, 0x589, 
       0x58e, 0x592, 0x59c, 0x5a3, 0x5a7, 0x5b1, 0x5b7, 0x5bd, 0x5c2, 0x5d5, 
       0x5e1, 0x5e5, 0x5eb, 0x5ef, 0x5f3, 0x5fb, 0x602, 0x60b, 0x616, 0x61d, 
       0x625, 0x62c, 0x63d, 0x642, 0x648, 0x64a, 0x650, 0x654, 0x65b, 0x66d, 
       0x671, 0x677, 0x681, 0x6a6, 0x6a8, 0x6b4, 0x6b6, 0x6c3, 0x6c5, 0x6dd, 
       0x6df, 0x6eb, 0x6ed, 0x6f8, 0x703, 0x70e, 0x719, 0x724, 0x72c, 0x735, 
       0x746, 0x74a, 0x75b, 0x763, 0x76b, 0x772, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

XiasParser::Initializer XiasParser::_init;
