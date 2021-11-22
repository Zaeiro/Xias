// Generated from c:\dev\Xias\antlr\XiasParser.g4 by ANTLR 4.8
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class XiasParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		WHITESPACES=1, SINGLE_LINE_DOC_COMMENT=2, DELIMITED_DOC_COMMENT=3, SINGLE_LINE_COMMENT=4, 
		DELIMITED_COMMENT=5, ABSTRACT=6, AS=7, BASE=8, BOOL=9, BREAK=10, CASE=11, 
		CATCH=12, CHAR=13, CLASS=14, CONST=15, CONTINUE=16, DEFAULT=17, DO=18, 
		DOUBLE=19, ELSE=20, ENUM=21, EXPLICIT=22, FALSE=23, FINALLY=24, FLOAT=25, 
		FOR=26, FOREACH=27, GET=28, GOTO=29, IF=30, IMPLICIT=31, IN=32, INT=33, 
		INTERFACE=34, INTERNAL=35, NAMEOF=36, NAMESPACE=37, NEW=38, NULL_=39, 
		OBJECT=40, OPERATOR=41, OUT=42, OVERRIDE=43, PARAMS=44, PRIVATE=45, PROTECTED=46, 
		PUBLIC=47, READONLY=48, REF=49, RETURN=50, SEALED=51, SET=52, SIZEOF=53, 
		STATIC=54, STRING=55, SWITCH=56, THIS=57, THROW=58, TRUE=59, TRY=60, TYPEOF=61, 
		UINT=62, USING=63, VAR=64, VIRTUAL=65, VOID=66, WHEN=67, WHERE=68, WHILE=69, 
		IDENTIFIER=70, LITERAL_ACCESS=71, INTEGER_LITERAL=72, HEX_INTEGER_LITERAL=73, 
		REAL_LITERAL=74, CHARACTER_LITERAL=75, REGULAR_STRING=76, VERBATIUM_STRING=77, 
		OPEN_BRACE=78, CLOSE_BRACE=79, OPEN_BRACKET=80, CLOSE_BRACKET=81, OPEN_PARENS=82, 
		CLOSE_PARENS=83, DOT=84, COMMA=85, COLON=86, SEMICOLON=87, PLUS=88, MINUS=89, 
		STAR=90, DIV=91, PERCENT=92, AMP=93, BITWISE_OR=94, CARET=95, BANG=96, 
		TILDE=97, ASSIGNMENT=98, LT=99, GT=100, INTERR=101, DOUBLE_COLON=102, 
		OP_COALESCING=103, OP_INC=104, OP_DEC=105, OP_AND=106, OP_OR=107, OP_PTR=108, 
		OP_EQ=109, OP_NE=110, OP_LE=111, OP_GE=112, OP_ADD_ASSIGNMENT=113, OP_SUB_ASSIGNMENT=114, 
		OP_MULT_ASSIGNMENT=115, OP_DIV_ASSIGNMENT=116, OP_MOD_ASSIGNMENT=117, 
		OP_AND_ASSIGNMENT=118, OP_OR_ASSIGNMENT=119, OP_XOR_ASSIGNMENT=120, OP_LEFT_SHIFT=121, 
		OP_LEFT_SHIFT_ASSIGNMENT=122, OP_COALESCING_ASSIGNMENT=123, QUOTE=124, 
		DOUBLE_QUOTE=125, BACK_SLASH=126, DOUBLE_BACK_SLASH=127, SHARP=128;
	public static final int
		RULE_compilation_unit = 0, RULE_namespace_or_type_name = 1, RULE_type_ = 2, 
		RULE_base_type = 3, RULE_simple_type = 4, RULE_numeric_type = 5, RULE_integral_type = 6, 
		RULE_floating_point_type = 7, RULE_class_type = 8, RULE_type_argument_list = 9, 
		RULE_argument_list = 10, RULE_argument = 11, RULE_expression = 12, RULE_non_assignment_expression = 13, 
		RULE_assignment = 14, RULE_assignment_operator = 15, RULE_conditional_expression = 16, 
		RULE_null_coalescing_expression = 17, RULE_conditional_or_expression = 18, 
		RULE_conditional_and_expression = 19, RULE_inclusive_or_expression = 20, 
		RULE_exclusive_or_expression = 21, RULE_and_expression = 22, RULE_equality_expression = 23, 
		RULE_relational_expression = 24, RULE_shift_expression = 25, RULE_additive_expression = 26, 
		RULE_multiplicative_expression = 27, RULE_switch_expression = 28, RULE_switch_expression_arms = 29, 
		RULE_switch_expression_arm = 30, RULE_unary_expression = 31, RULE_primary_expression = 32, 
		RULE_primary_expression_start = 33, RULE_throwable_expression = 34, RULE_throw_expression = 35, 
		RULE_member_access = 36, RULE_bracket_expression = 37, RULE_indexer_argument = 38, 
		RULE_predefined_type = 39, RULE_expression_list = 40, RULE_object_or_collection_initializer = 41, 
		RULE_object_initializer = 42, RULE_member_initializer_list = 43, RULE_member_initializer = 44, 
		RULE_initializer_value = 45, RULE_collection_initializer = 46, RULE_element_initializer = 47, 
		RULE_anonymous_object_initializer = 48, RULE_member_declarator_list = 49, 
		RULE_member_declarator = 50, RULE_unbound_type_name = 51, RULE_generic_dimension_specifier = 52, 
		RULE_isType = 53, RULE_isTypePatternArms = 54, RULE_isTypePatternArm = 55, 
		RULE_where_clause = 56, RULE_statement = 57, RULE_declarationStatement = 58, 
		RULE_labeled_Statement = 59, RULE_embedded_statement = 60, RULE_simple_embedded_statement = 61, 
		RULE_block = 62, RULE_local_variable_declaration = 63, RULE_local_variable_type = 64, 
		RULE_local_variable_declarator = 65, RULE_local_variable_initializer = 66, 
		RULE_local_constant_declaration = 67, RULE_if_body = 68, RULE_switch_section = 69, 
		RULE_switch_label = 70, RULE_case_guard = 71, RULE_statement_list = 72, 
		RULE_for_initializer = 73, RULE_for_iterator = 74, RULE_catch_clauses = 75, 
		RULE_specific_catch_clause = 76, RULE_general_catch_clause = 77, RULE_exception_filter = 78, 
		RULE_finally_clause = 79, RULE_resource_acquisition = 80, RULE_namespace_declaration = 81, 
		RULE_qualified_identifier = 82, RULE_namespace_body = 83, RULE_using_directives = 84, 
		RULE_using_directive = 85, RULE_namespace_member_declarations = 86, RULE_namespace_member_declaration = 87, 
		RULE_type_declaration = 88, RULE_qualified_alias_member = 89, RULE_type_parameter_list = 90, 
		RULE_type_parameter = 91, RULE_class_base = 92, RULE_interface_type_list = 93, 
		RULE_type_parameter_constraints_clauses = 94, RULE_type_parameter_constraints_clause = 95, 
		RULE_type_parameter_constraints = 96, RULE_primary_constraint = 97, RULE_secondary_constraints = 98, 
		RULE_constructor_constraint = 99, RULE_class_body = 100, RULE_class_member_declarations = 101, 
		RULE_class_member_declaration = 102, RULE_all_member_modifiers = 103, 
		RULE_all_member_modifier = 104, RULE_common_member_declaration = 105, 
		RULE_typed_member_declaration = 106, RULE_constant_declarators = 107, 
		RULE_constant_declarator = 108, RULE_variable_declarators = 109, RULE_variable_declarator = 110, 
		RULE_variable_initializer = 111, RULE_return_type = 112, RULE_member_name = 113, 
		RULE_method_body = 114, RULE_formal_parameter_list = 115, RULE_fixed_parameters = 116, 
		RULE_fixed_parameter = 117, RULE_parameter_modifier = 118, RULE_parameter_array = 119, 
		RULE_accessor_declarations = 120, RULE_get_accessor_declaration = 121, 
		RULE_set_accessor_declaration = 122, RULE_accessor_modifier = 123, RULE_accessor_body = 124, 
		RULE_overloadable_operator = 125, RULE_conversion_operator_declarator = 126, 
		RULE_constructor_initializer = 127, RULE_body = 128, RULE_array_type = 129, 
		RULE_rank_specifier = 130, RULE_array_initializer = 131, RULE_variant_type_parameter_list = 132, 
		RULE_variant_type_parameter = 133, RULE_variance_annotation = 134, RULE_interface_base = 135, 
		RULE_interface_body = 136, RULE_interface_member_declaration = 137, RULE_interface_accessors = 138, 
		RULE_enum_base = 139, RULE_enum_body = 140, RULE_enum_member_declaration = 141, 
		RULE_right_arrow = 142, RULE_right_shift = 143, RULE_right_shift_assignment = 144, 
		RULE_literal = 145, RULE_boolean_literal = 146, RULE_string_literal = 147, 
		RULE_keyword = 148, RULE_class_definition = 149, RULE_interface_definition = 150, 
		RULE_enum_definition = 151, RULE_field_declaration = 152, RULE_property_declaration = 153, 
		RULE_constant_declaration = 154, RULE_indexer_declaration = 155, RULE_destructor_definition = 156, 
		RULE_constructor_declaration = 157, RULE_method_declaration = 158, RULE_method_member_name = 159, 
		RULE_operator_declaration = 160, RULE_arg_declaration = 161, RULE_method_invocation = 162, 
		RULE_object_creation_expression = 163, RULE_identifier = 164;
	private static String[] makeRuleNames() {
		return new String[] {
			"compilation_unit", "namespace_or_type_name", "type_", "base_type", "simple_type", 
			"numeric_type", "integral_type", "floating_point_type", "class_type", 
			"type_argument_list", "argument_list", "argument", "expression", "non_assignment_expression", 
			"assignment", "assignment_operator", "conditional_expression", "null_coalescing_expression", 
			"conditional_or_expression", "conditional_and_expression", "inclusive_or_expression", 
			"exclusive_or_expression", "and_expression", "equality_expression", "relational_expression", 
			"shift_expression", "additive_expression", "multiplicative_expression", 
			"switch_expression", "switch_expression_arms", "switch_expression_arm", 
			"unary_expression", "primary_expression", "primary_expression_start", 
			"throwable_expression", "throw_expression", "member_access", "bracket_expression", 
			"indexer_argument", "predefined_type", "expression_list", "object_or_collection_initializer", 
			"object_initializer", "member_initializer_list", "member_initializer", 
			"initializer_value", "collection_initializer", "element_initializer", 
			"anonymous_object_initializer", "member_declarator_list", "member_declarator", 
			"unbound_type_name", "generic_dimension_specifier", "isType", "isTypePatternArms", 
			"isTypePatternArm", "where_clause", "statement", "declarationStatement", 
			"labeled_Statement", "embedded_statement", "simple_embedded_statement", 
			"block", "local_variable_declaration", "local_variable_type", "local_variable_declarator", 
			"local_variable_initializer", "local_constant_declaration", "if_body", 
			"switch_section", "switch_label", "case_guard", "statement_list", "for_initializer", 
			"for_iterator", "catch_clauses", "specific_catch_clause", "general_catch_clause", 
			"exception_filter", "finally_clause", "resource_acquisition", "namespace_declaration", 
			"qualified_identifier", "namespace_body", "using_directives", "using_directive", 
			"namespace_member_declarations", "namespace_member_declaration", "type_declaration", 
			"qualified_alias_member", "type_parameter_list", "type_parameter", "class_base", 
			"interface_type_list", "type_parameter_constraints_clauses", "type_parameter_constraints_clause", 
			"type_parameter_constraints", "primary_constraint", "secondary_constraints", 
			"constructor_constraint", "class_body", "class_member_declarations", 
			"class_member_declaration", "all_member_modifiers", "all_member_modifier", 
			"common_member_declaration", "typed_member_declaration", "constant_declarators", 
			"constant_declarator", "variable_declarators", "variable_declarator", 
			"variable_initializer", "return_type", "member_name", "method_body", 
			"formal_parameter_list", "fixed_parameters", "fixed_parameter", "parameter_modifier", 
			"parameter_array", "accessor_declarations", "get_accessor_declaration", 
			"set_accessor_declaration", "accessor_modifier", "accessor_body", "overloadable_operator", 
			"conversion_operator_declarator", "constructor_initializer", "body", 
			"array_type", "rank_specifier", "array_initializer", "variant_type_parameter_list", 
			"variant_type_parameter", "variance_annotation", "interface_base", "interface_body", 
			"interface_member_declaration", "interface_accessors", "enum_base", "enum_body", 
			"enum_member_declaration", "right_arrow", "right_shift", "right_shift_assignment", 
			"literal", "boolean_literal", "string_literal", "keyword", "class_definition", 
			"interface_definition", "enum_definition", "field_declaration", "property_declaration", 
			"constant_declaration", "indexer_declaration", "destructor_definition", 
			"constructor_declaration", "method_declaration", "method_member_name", 
			"operator_declaration", "arg_declaration", "method_invocation", "object_creation_expression", 
			"identifier"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, null, null, null, "'abstract'", "'as'", "'base'", "'bool'", 
			"'break'", "'case'", "'catch'", "'char'", "'class'", "'const'", "'continue'", 
			"'default'", "'do'", "'double'", "'else'", "'enum'", "'explicit'", "'false'", 
			"'finally'", "'float'", "'for'", "'foreach'", "'get'", "'goto'", "'if'", 
			"'implicit'", "'in'", "'int'", "'interface'", "'internal'", "'nameof'", 
			"'namespace'", "'new'", "'null'", "'object'", "'operator'", "'out'", 
			"'override'", "'params'", "'private'", "'protected'", "'public'", "'readonly'", 
			"'ref'", "'return'", "'sealed'", "'set'", "'sizeof'", "'static'", "'string'", 
			"'switch'", "'this'", "'throw'", "'true'", "'try'", "'typeof'", "'uint'", 
			"'using'", "'var'", "'virtual'", "'void'", "'when'", "'where'", "'while'", 
			null, null, null, null, null, null, null, null, "'{'", "'}'", "'['", 
			"']'", "'('", "')'", "'.'", "','", "':'", "';'", "'+'", "'-'", "'*'", 
			"'/'", "'%'", "'&'", "'|'", "'^'", "'!'", "'~'", "'='", "'<'", "'>'", 
			"'?'", "'::'", "'??'", "'++'", "'--'", "'&&'", "'||'", "'->'", "'=='", 
			"'!='", "'<='", "'>='", "'+='", "'-='", "'*='", "'/='", "'%='", "'&='", 
			"'|='", "'^='", "'<<'", "'<<='", "'??='", "'''", "'\"'", "'\\'", "'\\\\'", 
			"'#'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "WHITESPACES", "SINGLE_LINE_DOC_COMMENT", "DELIMITED_DOC_COMMENT", 
			"SINGLE_LINE_COMMENT", "DELIMITED_COMMENT", "ABSTRACT", "AS", "BASE", 
			"BOOL", "BREAK", "CASE", "CATCH", "CHAR", "CLASS", "CONST", "CONTINUE", 
			"DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM", "EXPLICIT", "FALSE", "FINALLY", 
			"FLOAT", "FOR", "FOREACH", "GET", "GOTO", "IF", "IMPLICIT", "IN", "INT", 
			"INTERFACE", "INTERNAL", "NAMEOF", "NAMESPACE", "NEW", "NULL_", "OBJECT", 
			"OPERATOR", "OUT", "OVERRIDE", "PARAMS", "PRIVATE", "PROTECTED", "PUBLIC", 
			"READONLY", "REF", "RETURN", "SEALED", "SET", "SIZEOF", "STATIC", "STRING", 
			"SWITCH", "THIS", "THROW", "TRUE", "TRY", "TYPEOF", "UINT", "USING", 
			"VAR", "VIRTUAL", "VOID", "WHEN", "WHERE", "WHILE", "IDENTIFIER", "LITERAL_ACCESS", 
			"INTEGER_LITERAL", "HEX_INTEGER_LITERAL", "REAL_LITERAL", "CHARACTER_LITERAL", 
			"REGULAR_STRING", "VERBATIUM_STRING", "OPEN_BRACE", "CLOSE_BRACE", "OPEN_BRACKET", 
			"CLOSE_BRACKET", "OPEN_PARENS", "CLOSE_PARENS", "DOT", "COMMA", "COLON", 
			"SEMICOLON", "PLUS", "MINUS", "STAR", "DIV", "PERCENT", "AMP", "BITWISE_OR", 
			"CARET", "BANG", "TILDE", "ASSIGNMENT", "LT", "GT", "INTERR", "DOUBLE_COLON", 
			"OP_COALESCING", "OP_INC", "OP_DEC", "OP_AND", "OP_OR", "OP_PTR", "OP_EQ", 
			"OP_NE", "OP_LE", "OP_GE", "OP_ADD_ASSIGNMENT", "OP_SUB_ASSIGNMENT", 
			"OP_MULT_ASSIGNMENT", "OP_DIV_ASSIGNMENT", "OP_MOD_ASSIGNMENT", "OP_AND_ASSIGNMENT", 
			"OP_OR_ASSIGNMENT", "OP_XOR_ASSIGNMENT", "OP_LEFT_SHIFT", "OP_LEFT_SHIFT_ASSIGNMENT", 
			"OP_COALESCING_ASSIGNMENT", "QUOTE", "DOUBLE_QUOTE", "BACK_SLASH", "DOUBLE_BACK_SLASH", 
			"SHARP"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "XiasParser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public XiasParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class Compilation_unitContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(XiasParser.EOF, 0); }
		public Using_directivesContext using_directives() {
			return getRuleContext(Using_directivesContext.class,0);
		}
		public Namespace_member_declarationsContext namespace_member_declarations() {
			return getRuleContext(Namespace_member_declarationsContext.class,0);
		}
		public Compilation_unitContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_compilation_unit; }
	}

	public final Compilation_unitContext compilation_unit() throws RecognitionException {
		Compilation_unitContext _localctx = new Compilation_unitContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_compilation_unit);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(331);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==USING) {
				{
				setState(330);
				using_directives();
				}
			}

			setState(334);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (((((_la - 6)) & ~0x3f) == 0 && ((1L << (_la - 6)) & ((1L << (ABSTRACT - 6)) | (1L << (CLASS - 6)) | (1L << (ENUM - 6)) | (1L << (INTERFACE - 6)) | (1L << (INTERNAL - 6)) | (1L << (NAMESPACE - 6)) | (1L << (NEW - 6)) | (1L << (OVERRIDE - 6)) | (1L << (PRIVATE - 6)) | (1L << (PROTECTED - 6)) | (1L << (PUBLIC - 6)) | (1L << (READONLY - 6)) | (1L << (SEALED - 6)) | (1L << (STATIC - 6)) | (1L << (VIRTUAL - 6)))) != 0)) {
				{
				setState(333);
				namespace_member_declarations();
				}
			}

			setState(336);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Namespace_or_type_nameContext extends ParserRuleContext {
		public List<IdentifierContext> identifier() {
			return getRuleContexts(IdentifierContext.class);
		}
		public IdentifierContext identifier(int i) {
			return getRuleContext(IdentifierContext.class,i);
		}
		public Qualified_alias_memberContext qualified_alias_member() {
			return getRuleContext(Qualified_alias_memberContext.class,0);
		}
		public List<TerminalNode> DOT() { return getTokens(XiasParser.DOT); }
		public TerminalNode DOT(int i) {
			return getToken(XiasParser.DOT, i);
		}
		public List<Type_argument_listContext> type_argument_list() {
			return getRuleContexts(Type_argument_listContext.class);
		}
		public Type_argument_listContext type_argument_list(int i) {
			return getRuleContext(Type_argument_listContext.class,i);
		}
		public Namespace_or_type_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_namespace_or_type_name; }
	}

	public final Namespace_or_type_nameContext namespace_or_type_name() throws RecognitionException {
		Namespace_or_type_nameContext _localctx = new Namespace_or_type_nameContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_namespace_or_type_name);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(343);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
			case 1:
				{
				setState(338);
				identifier();
				setState(340);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
				case 1:
					{
					setState(339);
					type_argument_list();
					}
					break;
				}
				}
				break;
			case 2:
				{
				setState(342);
				qualified_alias_member();
				}
				break;
			}
			setState(352);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,5,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(345);
					match(DOT);
					setState(346);
					identifier();
					setState(348);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
					case 1:
						{
						setState(347);
						type_argument_list();
						}
						break;
					}
					}
					} 
				}
				setState(354);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,5,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Type_Context extends ParserRuleContext {
		public Base_typeContext base_type() {
			return getRuleContext(Base_typeContext.class,0);
		}
		public List<Rank_specifierContext> rank_specifier() {
			return getRuleContexts(Rank_specifierContext.class);
		}
		public Rank_specifierContext rank_specifier(int i) {
			return getRuleContext(Rank_specifierContext.class,i);
		}
		public Type_Context(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type_; }
	}

	public final Type_Context type_() throws RecognitionException {
		Type_Context _localctx = new Type_Context(_ctx, getState());
		enterRule(_localctx, 4, RULE_type_);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(355);
			base_type();
			setState(359);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(356);
					rank_specifier();
					}
					} 
				}
				setState(361);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Base_typeContext extends ParserRuleContext {
		public Simple_typeContext simple_type() {
			return getRuleContext(Simple_typeContext.class,0);
		}
		public Class_typeContext class_type() {
			return getRuleContext(Class_typeContext.class,0);
		}
		public TerminalNode VOID() { return getToken(XiasParser.VOID, 0); }
		public TerminalNode STAR() { return getToken(XiasParser.STAR, 0); }
		public Base_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_base_type; }
	}

	public final Base_typeContext base_type() throws RecognitionException {
		Base_typeContext _localctx = new Base_typeContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_base_type);
		try {
			setState(366);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case BOOL:
			case CHAR:
			case DOUBLE:
			case FLOAT:
			case INT:
			case UINT:
				enterOuterAlt(_localctx, 1);
				{
				setState(362);
				simple_type();
				}
				break;
			case GET:
			case NAMEOF:
			case OBJECT:
			case SET:
			case STRING:
			case VAR:
			case WHEN:
			case WHERE:
			case IDENTIFIER:
				enterOuterAlt(_localctx, 2);
				{
				setState(363);
				class_type();
				}
				break;
			case VOID:
				enterOuterAlt(_localctx, 3);
				{
				setState(364);
				match(VOID);
				setState(365);
				match(STAR);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Simple_typeContext extends ParserRuleContext {
		public Numeric_typeContext numeric_type() {
			return getRuleContext(Numeric_typeContext.class,0);
		}
		public TerminalNode BOOL() { return getToken(XiasParser.BOOL, 0); }
		public Simple_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simple_type; }
	}

	public final Simple_typeContext simple_type() throws RecognitionException {
		Simple_typeContext _localctx = new Simple_typeContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_simple_type);
		try {
			setState(370);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case CHAR:
			case DOUBLE:
			case FLOAT:
			case INT:
			case UINT:
				enterOuterAlt(_localctx, 1);
				{
				setState(368);
				numeric_type();
				}
				break;
			case BOOL:
				enterOuterAlt(_localctx, 2);
				{
				setState(369);
				match(BOOL);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Numeric_typeContext extends ParserRuleContext {
		public Integral_typeContext integral_type() {
			return getRuleContext(Integral_typeContext.class,0);
		}
		public Floating_point_typeContext floating_point_type() {
			return getRuleContext(Floating_point_typeContext.class,0);
		}
		public Numeric_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_numeric_type; }
	}

	public final Numeric_typeContext numeric_type() throws RecognitionException {
		Numeric_typeContext _localctx = new Numeric_typeContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_numeric_type);
		try {
			setState(374);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case CHAR:
			case INT:
			case UINT:
				enterOuterAlt(_localctx, 1);
				{
				setState(372);
				integral_type();
				}
				break;
			case DOUBLE:
			case FLOAT:
				enterOuterAlt(_localctx, 2);
				{
				setState(373);
				floating_point_type();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Integral_typeContext extends ParserRuleContext {
		public TerminalNode INT() { return getToken(XiasParser.INT, 0); }
		public TerminalNode UINT() { return getToken(XiasParser.UINT, 0); }
		public TerminalNode CHAR() { return getToken(XiasParser.CHAR, 0); }
		public Integral_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_integral_type; }
	}

	public final Integral_typeContext integral_type() throws RecognitionException {
		Integral_typeContext _localctx = new Integral_typeContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_integral_type);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(376);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << CHAR) | (1L << INT) | (1L << UINT))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Floating_point_typeContext extends ParserRuleContext {
		public TerminalNode FLOAT() { return getToken(XiasParser.FLOAT, 0); }
		public TerminalNode DOUBLE() { return getToken(XiasParser.DOUBLE, 0); }
		public Floating_point_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_floating_point_type; }
	}

	public final Floating_point_typeContext floating_point_type() throws RecognitionException {
		Floating_point_typeContext _localctx = new Floating_point_typeContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_floating_point_type);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(378);
			_la = _input.LA(1);
			if ( !(_la==DOUBLE || _la==FLOAT) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Class_typeContext extends ParserRuleContext {
		public Namespace_or_type_nameContext namespace_or_type_name() {
			return getRuleContext(Namespace_or_type_nameContext.class,0);
		}
		public TerminalNode OBJECT() { return getToken(XiasParser.OBJECT, 0); }
		public TerminalNode STRING() { return getToken(XiasParser.STRING, 0); }
		public Class_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_class_type; }
	}

	public final Class_typeContext class_type() throws RecognitionException {
		Class_typeContext _localctx = new Class_typeContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_class_type);
		try {
			setState(383);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case GET:
			case NAMEOF:
			case SET:
			case VAR:
			case WHEN:
			case WHERE:
			case IDENTIFIER:
				enterOuterAlt(_localctx, 1);
				{
				setState(380);
				namespace_or_type_name();
				}
				break;
			case OBJECT:
				enterOuterAlt(_localctx, 2);
				{
				setState(381);
				match(OBJECT);
				}
				break;
			case STRING:
				enterOuterAlt(_localctx, 3);
				{
				setState(382);
				match(STRING);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Type_argument_listContext extends ParserRuleContext {
		public TerminalNode LT() { return getToken(XiasParser.LT, 0); }
		public List<Type_Context> type_() {
			return getRuleContexts(Type_Context.class);
		}
		public Type_Context type_(int i) {
			return getRuleContext(Type_Context.class,i);
		}
		public TerminalNode GT() { return getToken(XiasParser.GT, 0); }
		public List<TerminalNode> COMMA() { return getTokens(XiasParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(XiasParser.COMMA, i);
		}
		public Type_argument_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type_argument_list; }
	}

	public final Type_argument_listContext type_argument_list() throws RecognitionException {
		Type_argument_listContext _localctx = new Type_argument_listContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_type_argument_list);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(385);
			match(LT);
			setState(386);
			type_();
			setState(391);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(387);
				match(COMMA);
				setState(388);
				type_();
				}
				}
				setState(393);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(394);
			match(GT);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Argument_listContext extends ParserRuleContext {
		public List<ArgumentContext> argument() {
			return getRuleContexts(ArgumentContext.class);
		}
		public ArgumentContext argument(int i) {
			return getRuleContext(ArgumentContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(XiasParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(XiasParser.COMMA, i);
		}
		public Argument_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_argument_list; }
	}

	public final Argument_listContext argument_list() throws RecognitionException {
		Argument_listContext _localctx = new Argument_listContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_argument_list);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(396);
			argument();
			setState(401);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(397);
				match(COMMA);
				setState(398);
				argument();
				}
				}
				setState(403);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ArgumentContext extends ParserRuleContext {
		public Token refout;
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode COLON() { return getToken(XiasParser.COLON, 0); }
		public TerminalNode VAR() { return getToken(XiasParser.VAR, 0); }
		public Type_Context type_() {
			return getRuleContext(Type_Context.class,0);
		}
		public TerminalNode REF() { return getToken(XiasParser.REF, 0); }
		public TerminalNode OUT() { return getToken(XiasParser.OUT, 0); }
		public TerminalNode IN() { return getToken(XiasParser.IN, 0); }
		public ArgumentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_argument; }
	}

	public final ArgumentContext argument() throws RecognitionException {
		ArgumentContext _localctx = new ArgumentContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_argument);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(407);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
			case 1:
				{
				setState(404);
				identifier();
				setState(405);
				match(COLON);
				}
				break;
			}
			setState(410);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
			case 1:
				{
				setState(409);
				((ArgumentContext)_localctx).refout = _input.LT(1);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << IN) | (1L << OUT) | (1L << REF))) != 0)) ) {
					((ArgumentContext)_localctx).refout = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				}
				break;
			}
			setState(414);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
			case 1:
				{
				setState(412);
				match(VAR);
				}
				break;
			case 2:
				{
				setState(413);
				type_();
				}
				break;
			}
			setState(416);
			expression();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExpressionContext extends ParserRuleContext {
		public AssignmentContext assignment() {
			return getRuleContext(AssignmentContext.class,0);
		}
		public Non_assignment_expressionContext non_assignment_expression() {
			return getRuleContext(Non_assignment_expressionContext.class,0);
		}
		public TerminalNode REF() { return getToken(XiasParser.REF, 0); }
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
	}

	public final ExpressionContext expression() throws RecognitionException {
		ExpressionContext _localctx = new ExpressionContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_expression);
		try {
			setState(422);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,16,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(418);
				assignment();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(419);
				non_assignment_expression();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(420);
				match(REF);
				setState(421);
				non_assignment_expression();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Non_assignment_expressionContext extends ParserRuleContext {
		public Conditional_expressionContext conditional_expression() {
			return getRuleContext(Conditional_expressionContext.class,0);
		}
		public Non_assignment_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_non_assignment_expression; }
	}

	public final Non_assignment_expressionContext non_assignment_expression() throws RecognitionException {
		Non_assignment_expressionContext _localctx = new Non_assignment_expressionContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_non_assignment_expression);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(424);
			conditional_expression();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AssignmentContext extends ParserRuleContext {
		public Unary_expressionContext unary_expression() {
			return getRuleContext(Unary_expressionContext.class,0);
		}
		public Assignment_operatorContext assignment_operator() {
			return getRuleContext(Assignment_operatorContext.class,0);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode OP_COALESCING_ASSIGNMENT() { return getToken(XiasParser.OP_COALESCING_ASSIGNMENT, 0); }
		public Throwable_expressionContext throwable_expression() {
			return getRuleContext(Throwable_expressionContext.class,0);
		}
		public AssignmentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assignment; }
	}

	public final AssignmentContext assignment() throws RecognitionException {
		AssignmentContext _localctx = new AssignmentContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_assignment);
		try {
			setState(434);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(426);
				unary_expression();
				setState(427);
				assignment_operator();
				setState(428);
				expression();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(430);
				unary_expression();
				setState(431);
				match(OP_COALESCING_ASSIGNMENT);
				setState(432);
				throwable_expression();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Assignment_operatorContext extends ParserRuleContext {
		public TerminalNode ASSIGNMENT() { return getToken(XiasParser.ASSIGNMENT, 0); }
		public TerminalNode OP_ADD_ASSIGNMENT() { return getToken(XiasParser.OP_ADD_ASSIGNMENT, 0); }
		public TerminalNode OP_SUB_ASSIGNMENT() { return getToken(XiasParser.OP_SUB_ASSIGNMENT, 0); }
		public TerminalNode OP_MULT_ASSIGNMENT() { return getToken(XiasParser.OP_MULT_ASSIGNMENT, 0); }
		public TerminalNode OP_DIV_ASSIGNMENT() { return getToken(XiasParser.OP_DIV_ASSIGNMENT, 0); }
		public TerminalNode OP_MOD_ASSIGNMENT() { return getToken(XiasParser.OP_MOD_ASSIGNMENT, 0); }
		public TerminalNode OP_AND_ASSIGNMENT() { return getToken(XiasParser.OP_AND_ASSIGNMENT, 0); }
		public TerminalNode OP_OR_ASSIGNMENT() { return getToken(XiasParser.OP_OR_ASSIGNMENT, 0); }
		public TerminalNode OP_XOR_ASSIGNMENT() { return getToken(XiasParser.OP_XOR_ASSIGNMENT, 0); }
		public TerminalNode OP_LEFT_SHIFT_ASSIGNMENT() { return getToken(XiasParser.OP_LEFT_SHIFT_ASSIGNMENT, 0); }
		public Right_shift_assignmentContext right_shift_assignment() {
			return getRuleContext(Right_shift_assignmentContext.class,0);
		}
		public Assignment_operatorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assignment_operator; }
	}

	public final Assignment_operatorContext assignment_operator() throws RecognitionException {
		Assignment_operatorContext _localctx = new Assignment_operatorContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_assignment_operator);
		try {
			setState(447);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case ASSIGNMENT:
				enterOuterAlt(_localctx, 1);
				{
				setState(436);
				match(ASSIGNMENT);
				}
				break;
			case OP_ADD_ASSIGNMENT:
				enterOuterAlt(_localctx, 2);
				{
				setState(437);
				match(OP_ADD_ASSIGNMENT);
				}
				break;
			case OP_SUB_ASSIGNMENT:
				enterOuterAlt(_localctx, 3);
				{
				setState(438);
				match(OP_SUB_ASSIGNMENT);
				}
				break;
			case OP_MULT_ASSIGNMENT:
				enterOuterAlt(_localctx, 4);
				{
				setState(439);
				match(OP_MULT_ASSIGNMENT);
				}
				break;
			case OP_DIV_ASSIGNMENT:
				enterOuterAlt(_localctx, 5);
				{
				setState(440);
				match(OP_DIV_ASSIGNMENT);
				}
				break;
			case OP_MOD_ASSIGNMENT:
				enterOuterAlt(_localctx, 6);
				{
				setState(441);
				match(OP_MOD_ASSIGNMENT);
				}
				break;
			case OP_AND_ASSIGNMENT:
				enterOuterAlt(_localctx, 7);
				{
				setState(442);
				match(OP_AND_ASSIGNMENT);
				}
				break;
			case OP_OR_ASSIGNMENT:
				enterOuterAlt(_localctx, 8);
				{
				setState(443);
				match(OP_OR_ASSIGNMENT);
				}
				break;
			case OP_XOR_ASSIGNMENT:
				enterOuterAlt(_localctx, 9);
				{
				setState(444);
				match(OP_XOR_ASSIGNMENT);
				}
				break;
			case OP_LEFT_SHIFT_ASSIGNMENT:
				enterOuterAlt(_localctx, 10);
				{
				setState(445);
				match(OP_LEFT_SHIFT_ASSIGNMENT);
				}
				break;
			case GT:
				enterOuterAlt(_localctx, 11);
				{
				setState(446);
				right_shift_assignment();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Conditional_expressionContext extends ParserRuleContext {
		public Null_coalescing_expressionContext null_coalescing_expression() {
			return getRuleContext(Null_coalescing_expressionContext.class,0);
		}
		public TerminalNode INTERR() { return getToken(XiasParser.INTERR, 0); }
		public List<Throwable_expressionContext> throwable_expression() {
			return getRuleContexts(Throwable_expressionContext.class);
		}
		public Throwable_expressionContext throwable_expression(int i) {
			return getRuleContext(Throwable_expressionContext.class,i);
		}
		public TerminalNode COLON() { return getToken(XiasParser.COLON, 0); }
		public Conditional_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_conditional_expression; }
	}

	public final Conditional_expressionContext conditional_expression() throws RecognitionException {
		Conditional_expressionContext _localctx = new Conditional_expressionContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_conditional_expression);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(449);
			null_coalescing_expression();
			setState(455);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,19,_ctx) ) {
			case 1:
				{
				setState(450);
				match(INTERR);
				setState(451);
				throwable_expression();
				setState(452);
				match(COLON);
				setState(453);
				throwable_expression();
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Null_coalescing_expressionContext extends ParserRuleContext {
		public Conditional_or_expressionContext conditional_or_expression() {
			return getRuleContext(Conditional_or_expressionContext.class,0);
		}
		public TerminalNode OP_COALESCING() { return getToken(XiasParser.OP_COALESCING, 0); }
		public Null_coalescing_expressionContext null_coalescing_expression() {
			return getRuleContext(Null_coalescing_expressionContext.class,0);
		}
		public Throw_expressionContext throw_expression() {
			return getRuleContext(Throw_expressionContext.class,0);
		}
		public Null_coalescing_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_null_coalescing_expression; }
	}

	public final Null_coalescing_expressionContext null_coalescing_expression() throws RecognitionException {
		Null_coalescing_expressionContext _localctx = new Null_coalescing_expressionContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_null_coalescing_expression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(457);
			conditional_or_expression();
			setState(463);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==OP_COALESCING) {
				{
				setState(458);
				match(OP_COALESCING);
				setState(461);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case BASE:
				case BOOL:
				case CHAR:
				case DEFAULT:
				case DOUBLE:
				case FALSE:
				case FLOAT:
				case GET:
				case INT:
				case NAMEOF:
				case NEW:
				case NULL_:
				case OBJECT:
				case SET:
				case SIZEOF:
				case STRING:
				case THIS:
				case TRUE:
				case TYPEOF:
				case UINT:
				case VAR:
				case WHEN:
				case WHERE:
				case IDENTIFIER:
				case LITERAL_ACCESS:
				case INTEGER_LITERAL:
				case HEX_INTEGER_LITERAL:
				case REAL_LITERAL:
				case CHARACTER_LITERAL:
				case REGULAR_STRING:
				case VERBATIUM_STRING:
				case OPEN_PARENS:
				case PLUS:
				case MINUS:
				case STAR:
				case BANG:
				case TILDE:
				case OP_INC:
				case OP_DEC:
					{
					setState(459);
					null_coalescing_expression();
					}
					break;
				case THROW:
					{
					setState(460);
					throw_expression();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Conditional_or_expressionContext extends ParserRuleContext {
		public List<Conditional_and_expressionContext> conditional_and_expression() {
			return getRuleContexts(Conditional_and_expressionContext.class);
		}
		public Conditional_and_expressionContext conditional_and_expression(int i) {
			return getRuleContext(Conditional_and_expressionContext.class,i);
		}
		public List<TerminalNode> OP_OR() { return getTokens(XiasParser.OP_OR); }
		public TerminalNode OP_OR(int i) {
			return getToken(XiasParser.OP_OR, i);
		}
		public Conditional_or_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_conditional_or_expression; }
	}

	public final Conditional_or_expressionContext conditional_or_expression() throws RecognitionException {
		Conditional_or_expressionContext _localctx = new Conditional_or_expressionContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_conditional_or_expression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(465);
			conditional_and_expression();
			setState(470);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==OP_OR) {
				{
				{
				setState(466);
				match(OP_OR);
				setState(467);
				conditional_and_expression();
				}
				}
				setState(472);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Conditional_and_expressionContext extends ParserRuleContext {
		public List<Inclusive_or_expressionContext> inclusive_or_expression() {
			return getRuleContexts(Inclusive_or_expressionContext.class);
		}
		public Inclusive_or_expressionContext inclusive_or_expression(int i) {
			return getRuleContext(Inclusive_or_expressionContext.class,i);
		}
		public List<TerminalNode> OP_AND() { return getTokens(XiasParser.OP_AND); }
		public TerminalNode OP_AND(int i) {
			return getToken(XiasParser.OP_AND, i);
		}
		public Conditional_and_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_conditional_and_expression; }
	}

	public final Conditional_and_expressionContext conditional_and_expression() throws RecognitionException {
		Conditional_and_expressionContext _localctx = new Conditional_and_expressionContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_conditional_and_expression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(473);
			inclusive_or_expression();
			setState(478);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==OP_AND) {
				{
				{
				setState(474);
				match(OP_AND);
				setState(475);
				inclusive_or_expression();
				}
				}
				setState(480);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Inclusive_or_expressionContext extends ParserRuleContext {
		public List<Exclusive_or_expressionContext> exclusive_or_expression() {
			return getRuleContexts(Exclusive_or_expressionContext.class);
		}
		public Exclusive_or_expressionContext exclusive_or_expression(int i) {
			return getRuleContext(Exclusive_or_expressionContext.class,i);
		}
		public List<TerminalNode> BITWISE_OR() { return getTokens(XiasParser.BITWISE_OR); }
		public TerminalNode BITWISE_OR(int i) {
			return getToken(XiasParser.BITWISE_OR, i);
		}
		public Inclusive_or_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_inclusive_or_expression; }
	}

	public final Inclusive_or_expressionContext inclusive_or_expression() throws RecognitionException {
		Inclusive_or_expressionContext _localctx = new Inclusive_or_expressionContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_inclusive_or_expression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(481);
			exclusive_or_expression();
			setState(486);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==BITWISE_OR) {
				{
				{
				setState(482);
				match(BITWISE_OR);
				setState(483);
				exclusive_or_expression();
				}
				}
				setState(488);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Exclusive_or_expressionContext extends ParserRuleContext {
		public List<And_expressionContext> and_expression() {
			return getRuleContexts(And_expressionContext.class);
		}
		public And_expressionContext and_expression(int i) {
			return getRuleContext(And_expressionContext.class,i);
		}
		public List<TerminalNode> CARET() { return getTokens(XiasParser.CARET); }
		public TerminalNode CARET(int i) {
			return getToken(XiasParser.CARET, i);
		}
		public Exclusive_or_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_exclusive_or_expression; }
	}

	public final Exclusive_or_expressionContext exclusive_or_expression() throws RecognitionException {
		Exclusive_or_expressionContext _localctx = new Exclusive_or_expressionContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_exclusive_or_expression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(489);
			and_expression();
			setState(494);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==CARET) {
				{
				{
				setState(490);
				match(CARET);
				setState(491);
				and_expression();
				}
				}
				setState(496);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class And_expressionContext extends ParserRuleContext {
		public List<Equality_expressionContext> equality_expression() {
			return getRuleContexts(Equality_expressionContext.class);
		}
		public Equality_expressionContext equality_expression(int i) {
			return getRuleContext(Equality_expressionContext.class,i);
		}
		public List<TerminalNode> AMP() { return getTokens(XiasParser.AMP); }
		public TerminalNode AMP(int i) {
			return getToken(XiasParser.AMP, i);
		}
		public And_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_and_expression; }
	}

	public final And_expressionContext and_expression() throws RecognitionException {
		And_expressionContext _localctx = new And_expressionContext(_ctx, getState());
		enterRule(_localctx, 44, RULE_and_expression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(497);
			equality_expression();
			setState(502);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==AMP) {
				{
				{
				setState(498);
				match(AMP);
				setState(499);
				equality_expression();
				}
				}
				setState(504);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Equality_expressionContext extends ParserRuleContext {
		public List<Relational_expressionContext> relational_expression() {
			return getRuleContexts(Relational_expressionContext.class);
		}
		public Relational_expressionContext relational_expression(int i) {
			return getRuleContext(Relational_expressionContext.class,i);
		}
		public List<TerminalNode> OP_EQ() { return getTokens(XiasParser.OP_EQ); }
		public TerminalNode OP_EQ(int i) {
			return getToken(XiasParser.OP_EQ, i);
		}
		public List<TerminalNode> OP_NE() { return getTokens(XiasParser.OP_NE); }
		public TerminalNode OP_NE(int i) {
			return getToken(XiasParser.OP_NE, i);
		}
		public Equality_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_equality_expression; }
	}

	public final Equality_expressionContext equality_expression() throws RecognitionException {
		Equality_expressionContext _localctx = new Equality_expressionContext(_ctx, getState());
		enterRule(_localctx, 46, RULE_equality_expression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(505);
			relational_expression();
			setState(510);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==OP_EQ || _la==OP_NE) {
				{
				{
				setState(506);
				_la = _input.LA(1);
				if ( !(_la==OP_EQ || _la==OP_NE) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(507);
				relational_expression();
				}
				}
				setState(512);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Relational_expressionContext extends ParserRuleContext {
		public List<Shift_expressionContext> shift_expression() {
			return getRuleContexts(Shift_expressionContext.class);
		}
		public Shift_expressionContext shift_expression(int i) {
			return getRuleContext(Shift_expressionContext.class,i);
		}
		public List<TerminalNode> AS() { return getTokens(XiasParser.AS); }
		public TerminalNode AS(int i) {
			return getToken(XiasParser.AS, i);
		}
		public List<Type_Context> type_() {
			return getRuleContexts(Type_Context.class);
		}
		public Type_Context type_(int i) {
			return getRuleContext(Type_Context.class,i);
		}
		public List<TerminalNode> LT() { return getTokens(XiasParser.LT); }
		public TerminalNode LT(int i) {
			return getToken(XiasParser.LT, i);
		}
		public List<TerminalNode> GT() { return getTokens(XiasParser.GT); }
		public TerminalNode GT(int i) {
			return getToken(XiasParser.GT, i);
		}
		public List<TerminalNode> OP_LE() { return getTokens(XiasParser.OP_LE); }
		public TerminalNode OP_LE(int i) {
			return getToken(XiasParser.OP_LE, i);
		}
		public List<TerminalNode> OP_GE() { return getTokens(XiasParser.OP_GE); }
		public TerminalNode OP_GE(int i) {
			return getToken(XiasParser.OP_GE, i);
		}
		public Relational_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_relational_expression; }
	}

	public final Relational_expressionContext relational_expression() throws RecognitionException {
		Relational_expressionContext _localctx = new Relational_expressionContext(_ctx, getState());
		enterRule(_localctx, 48, RULE_relational_expression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(513);
			shift_expression();
			setState(520);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==AS || ((((_la - 99)) & ~0x3f) == 0 && ((1L << (_la - 99)) & ((1L << (LT - 99)) | (1L << (GT - 99)) | (1L << (OP_LE - 99)) | (1L << (OP_GE - 99)))) != 0)) {
				{
				setState(518);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case LT:
				case GT:
				case OP_LE:
				case OP_GE:
					{
					setState(514);
					_la = _input.LA(1);
					if ( !(((((_la - 99)) & ~0x3f) == 0 && ((1L << (_la - 99)) & ((1L << (LT - 99)) | (1L << (GT - 99)) | (1L << (OP_LE - 99)) | (1L << (OP_GE - 99)))) != 0)) ) {
					_errHandler.recoverInline(this);
					}
					else {
						if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
						_errHandler.reportMatch(this);
						consume();
					}
					setState(515);
					shift_expression();
					}
					break;
				case AS:
					{
					setState(516);
					match(AS);
					setState(517);
					type_();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				setState(522);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Shift_expressionContext extends ParserRuleContext {
		public List<Additive_expressionContext> additive_expression() {
			return getRuleContexts(Additive_expressionContext.class);
		}
		public Additive_expressionContext additive_expression(int i) {
			return getRuleContext(Additive_expressionContext.class,i);
		}
		public List<TerminalNode> OP_LEFT_SHIFT() { return getTokens(XiasParser.OP_LEFT_SHIFT); }
		public TerminalNode OP_LEFT_SHIFT(int i) {
			return getToken(XiasParser.OP_LEFT_SHIFT, i);
		}
		public List<Right_shiftContext> right_shift() {
			return getRuleContexts(Right_shiftContext.class);
		}
		public Right_shiftContext right_shift(int i) {
			return getRuleContext(Right_shiftContext.class,i);
		}
		public Shift_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_shift_expression; }
	}

	public final Shift_expressionContext shift_expression() throws RecognitionException {
		Shift_expressionContext _localctx = new Shift_expressionContext(_ctx, getState());
		enterRule(_localctx, 50, RULE_shift_expression);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(523);
			additive_expression();
			setState(531);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,31,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(526);
					_errHandler.sync(this);
					switch (_input.LA(1)) {
					case OP_LEFT_SHIFT:
						{
						setState(524);
						match(OP_LEFT_SHIFT);
						}
						break;
					case GT:
						{
						setState(525);
						right_shift();
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(528);
					additive_expression();
					}
					} 
				}
				setState(533);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,31,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Additive_expressionContext extends ParserRuleContext {
		public List<Multiplicative_expressionContext> multiplicative_expression() {
			return getRuleContexts(Multiplicative_expressionContext.class);
		}
		public Multiplicative_expressionContext multiplicative_expression(int i) {
			return getRuleContext(Multiplicative_expressionContext.class,i);
		}
		public List<TerminalNode> PLUS() { return getTokens(XiasParser.PLUS); }
		public TerminalNode PLUS(int i) {
			return getToken(XiasParser.PLUS, i);
		}
		public List<TerminalNode> MINUS() { return getTokens(XiasParser.MINUS); }
		public TerminalNode MINUS(int i) {
			return getToken(XiasParser.MINUS, i);
		}
		public Additive_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_additive_expression; }
	}

	public final Additive_expressionContext additive_expression() throws RecognitionException {
		Additive_expressionContext _localctx = new Additive_expressionContext(_ctx, getState());
		enterRule(_localctx, 52, RULE_additive_expression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(534);
			multiplicative_expression();
			setState(539);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==PLUS || _la==MINUS) {
				{
				{
				setState(535);
				_la = _input.LA(1);
				if ( !(_la==PLUS || _la==MINUS) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(536);
				multiplicative_expression();
				}
				}
				setState(541);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Multiplicative_expressionContext extends ParserRuleContext {
		public List<Switch_expressionContext> switch_expression() {
			return getRuleContexts(Switch_expressionContext.class);
		}
		public Switch_expressionContext switch_expression(int i) {
			return getRuleContext(Switch_expressionContext.class,i);
		}
		public List<TerminalNode> STAR() { return getTokens(XiasParser.STAR); }
		public TerminalNode STAR(int i) {
			return getToken(XiasParser.STAR, i);
		}
		public List<TerminalNode> DIV() { return getTokens(XiasParser.DIV); }
		public TerminalNode DIV(int i) {
			return getToken(XiasParser.DIV, i);
		}
		public List<TerminalNode> PERCENT() { return getTokens(XiasParser.PERCENT); }
		public TerminalNode PERCENT(int i) {
			return getToken(XiasParser.PERCENT, i);
		}
		public Multiplicative_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_multiplicative_expression; }
	}

	public final Multiplicative_expressionContext multiplicative_expression() throws RecognitionException {
		Multiplicative_expressionContext _localctx = new Multiplicative_expressionContext(_ctx, getState());
		enterRule(_localctx, 54, RULE_multiplicative_expression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(542);
			switch_expression();
			setState(547);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (((((_la - 90)) & ~0x3f) == 0 && ((1L << (_la - 90)) & ((1L << (STAR - 90)) | (1L << (DIV - 90)) | (1L << (PERCENT - 90)))) != 0)) {
				{
				{
				setState(543);
				_la = _input.LA(1);
				if ( !(((((_la - 90)) & ~0x3f) == 0 && ((1L << (_la - 90)) & ((1L << (STAR - 90)) | (1L << (DIV - 90)) | (1L << (PERCENT - 90)))) != 0)) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(544);
				switch_expression();
				}
				}
				setState(549);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Switch_expressionContext extends ParserRuleContext {
		public Unary_expressionContext unary_expression() {
			return getRuleContext(Unary_expressionContext.class,0);
		}
		public TerminalNode SWITCH() { return getToken(XiasParser.SWITCH, 0); }
		public TerminalNode OPEN_BRACE() { return getToken(XiasParser.OPEN_BRACE, 0); }
		public TerminalNode CLOSE_BRACE() { return getToken(XiasParser.CLOSE_BRACE, 0); }
		public Switch_expression_armsContext switch_expression_arms() {
			return getRuleContext(Switch_expression_armsContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(XiasParser.COMMA, 0); }
		public Switch_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_switch_expression; }
	}

	public final Switch_expressionContext switch_expression() throws RecognitionException {
		Switch_expressionContext _localctx = new Switch_expressionContext(_ctx, getState());
		enterRule(_localctx, 56, RULE_switch_expression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(550);
			unary_expression();
			setState(560);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==SWITCH) {
				{
				setState(551);
				match(SWITCH);
				setState(552);
				match(OPEN_BRACE);
				setState(557);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << BASE) | (1L << BOOL) | (1L << CHAR) | (1L << DEFAULT) | (1L << DOUBLE) | (1L << FALSE) | (1L << FLOAT) | (1L << GET) | (1L << INT) | (1L << NAMEOF) | (1L << NEW) | (1L << NULL_) | (1L << OBJECT) | (1L << REF) | (1L << SET) | (1L << SIZEOF) | (1L << STRING) | (1L << THIS) | (1L << TRUE) | (1L << TYPEOF) | (1L << UINT))) != 0) || ((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & ((1L << (VAR - 64)) | (1L << (WHEN - 64)) | (1L << (WHERE - 64)) | (1L << (IDENTIFIER - 64)) | (1L << (LITERAL_ACCESS - 64)) | (1L << (INTEGER_LITERAL - 64)) | (1L << (HEX_INTEGER_LITERAL - 64)) | (1L << (REAL_LITERAL - 64)) | (1L << (CHARACTER_LITERAL - 64)) | (1L << (REGULAR_STRING - 64)) | (1L << (VERBATIUM_STRING - 64)) | (1L << (OPEN_PARENS - 64)) | (1L << (PLUS - 64)) | (1L << (MINUS - 64)) | (1L << (STAR - 64)) | (1L << (BANG - 64)) | (1L << (TILDE - 64)) | (1L << (OP_INC - 64)) | (1L << (OP_DEC - 64)))) != 0)) {
					{
					setState(553);
					switch_expression_arms();
					setState(555);
					_errHandler.sync(this);
					_la = _input.LA(1);
					if (_la==COMMA) {
						{
						setState(554);
						match(COMMA);
						}
					}

					}
				}

				setState(559);
				match(CLOSE_BRACE);
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Switch_expression_armsContext extends ParserRuleContext {
		public List<Switch_expression_armContext> switch_expression_arm() {
			return getRuleContexts(Switch_expression_armContext.class);
		}
		public Switch_expression_armContext switch_expression_arm(int i) {
			return getRuleContext(Switch_expression_armContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(XiasParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(XiasParser.COMMA, i);
		}
		public Switch_expression_armsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_switch_expression_arms; }
	}

	public final Switch_expression_armsContext switch_expression_arms() throws RecognitionException {
		Switch_expression_armsContext _localctx = new Switch_expression_armsContext(_ctx, getState());
		enterRule(_localctx, 58, RULE_switch_expression_arms);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(562);
			switch_expression_arm();
			setState(567);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,37,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(563);
					match(COMMA);
					setState(564);
					switch_expression_arm();
					}
					} 
				}
				setState(569);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,37,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Switch_expression_armContext extends ParserRuleContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Right_arrowContext right_arrow() {
			return getRuleContext(Right_arrowContext.class,0);
		}
		public Throwable_expressionContext throwable_expression() {
			return getRuleContext(Throwable_expressionContext.class,0);
		}
		public Case_guardContext case_guard() {
			return getRuleContext(Case_guardContext.class,0);
		}
		public Switch_expression_armContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_switch_expression_arm; }
	}

	public final Switch_expression_armContext switch_expression_arm() throws RecognitionException {
		Switch_expression_armContext _localctx = new Switch_expression_armContext(_ctx, getState());
		enterRule(_localctx, 60, RULE_switch_expression_arm);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(570);
			expression();
			setState(572);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WHEN) {
				{
				setState(571);
				case_guard();
				}
			}

			setState(574);
			right_arrow();
			setState(575);
			throwable_expression();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Unary_expressionContext extends ParserRuleContext {
		public Primary_expressionContext primary_expression() {
			return getRuleContext(Primary_expressionContext.class,0);
		}
		public TerminalNode PLUS() { return getToken(XiasParser.PLUS, 0); }
		public Unary_expressionContext unary_expression() {
			return getRuleContext(Unary_expressionContext.class,0);
		}
		public TerminalNode MINUS() { return getToken(XiasParser.MINUS, 0); }
		public TerminalNode BANG() { return getToken(XiasParser.BANG, 0); }
		public TerminalNode TILDE() { return getToken(XiasParser.TILDE, 0); }
		public TerminalNode OP_INC() { return getToken(XiasParser.OP_INC, 0); }
		public TerminalNode OP_DEC() { return getToken(XiasParser.OP_DEC, 0); }
		public TerminalNode OPEN_PARENS() { return getToken(XiasParser.OPEN_PARENS, 0); }
		public Type_Context type_() {
			return getRuleContext(Type_Context.class,0);
		}
		public TerminalNode CLOSE_PARENS() { return getToken(XiasParser.CLOSE_PARENS, 0); }
		public TerminalNode STAR() { return getToken(XiasParser.STAR, 0); }
		public Unary_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unary_expression; }
	}

	public final Unary_expressionContext unary_expression() throws RecognitionException {
		Unary_expressionContext _localctx = new Unary_expressionContext(_ctx, getState());
		enterRule(_localctx, 62, RULE_unary_expression);
		try {
			setState(597);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,39,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(577);
				primary_expression();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(578);
				match(PLUS);
				setState(579);
				unary_expression();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(580);
				match(MINUS);
				setState(581);
				unary_expression();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(582);
				match(BANG);
				setState(583);
				unary_expression();
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(584);
				match(TILDE);
				setState(585);
				unary_expression();
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(586);
				match(OP_INC);
				setState(587);
				unary_expression();
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(588);
				match(OP_DEC);
				setState(589);
				unary_expression();
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(590);
				match(OPEN_PARENS);
				setState(591);
				type_();
				setState(592);
				match(CLOSE_PARENS);
				setState(593);
				unary_expression();
				}
				break;
			case 9:
				enterOuterAlt(_localctx, 9);
				{
				setState(595);
				match(STAR);
				setState(596);
				unary_expression();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Primary_expressionContext extends ParserRuleContext {
		public Primary_expression_startContext pe;
		public Primary_expression_startContext primary_expression_start() {
			return getRuleContext(Primary_expression_startContext.class,0);
		}
		public List<TerminalNode> BANG() { return getTokens(XiasParser.BANG); }
		public TerminalNode BANG(int i) {
			return getToken(XiasParser.BANG, i);
		}
		public List<Bracket_expressionContext> bracket_expression() {
			return getRuleContexts(Bracket_expressionContext.class);
		}
		public Bracket_expressionContext bracket_expression(int i) {
			return getRuleContext(Bracket_expressionContext.class,i);
		}
		public List<Member_accessContext> member_access() {
			return getRuleContexts(Member_accessContext.class);
		}
		public Member_accessContext member_access(int i) {
			return getRuleContext(Member_accessContext.class,i);
		}
		public List<Method_invocationContext> method_invocation() {
			return getRuleContexts(Method_invocationContext.class);
		}
		public Method_invocationContext method_invocation(int i) {
			return getRuleContext(Method_invocationContext.class,i);
		}
		public List<TerminalNode> OP_INC() { return getTokens(XiasParser.OP_INC); }
		public TerminalNode OP_INC(int i) {
			return getToken(XiasParser.OP_INC, i);
		}
		public List<TerminalNode> OP_DEC() { return getTokens(XiasParser.OP_DEC); }
		public TerminalNode OP_DEC(int i) {
			return getToken(XiasParser.OP_DEC, i);
		}
		public Primary_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_primary_expression; }
	}

	public final Primary_expressionContext primary_expression() throws RecognitionException {
		Primary_expressionContext _localctx = new Primary_expressionContext(_ctx, getState());
		enterRule(_localctx, 64, RULE_primary_expression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(599);
			((Primary_expressionContext)_localctx).pe = primary_expression_start();
			setState(601);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,40,_ctx) ) {
			case 1:
				{
				setState(600);
				match(BANG);
				}
				break;
			}
			setState(606);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==OPEN_BRACKET) {
				{
				{
				setState(603);
				bracket_expression();
				}
				}
				setState(608);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(610);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==BANG) {
				{
				setState(609);
				match(BANG);
				}
			}

			setState(632);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (((((_la - 82)) & ~0x3f) == 0 && ((1L << (_la - 82)) & ((1L << (OPEN_PARENS - 82)) | (1L << (DOT - 82)) | (1L << (OP_INC - 82)) | (1L << (OP_DEC - 82)))) != 0)) {
				{
				{
				{
				setState(616);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case DOT:
					{
					setState(612);
					member_access();
					}
					break;
				case OPEN_PARENS:
					{
					setState(613);
					method_invocation();
					}
					break;
				case OP_INC:
					{
					setState(614);
					match(OP_INC);
					}
					break;
				case OP_DEC:
					{
					setState(615);
					match(OP_DEC);
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(619);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,44,_ctx) ) {
				case 1:
					{
					setState(618);
					match(BANG);
					}
					break;
				}
				}
				setState(624);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==OPEN_BRACKET) {
					{
					{
					setState(621);
					bracket_expression();
					}
					}
					setState(626);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(628);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==BANG) {
					{
					setState(627);
					match(BANG);
					}
				}

				}
				}
				setState(634);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Primary_expression_startContext extends ParserRuleContext {
		public Primary_expression_startContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_primary_expression_start; }
	 
		public Primary_expression_startContext() { }
		public void copyFrom(Primary_expression_startContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class ThisReferenceExpressionContext extends Primary_expression_startContext {
		public TerminalNode THIS() { return getToken(XiasParser.THIS, 0); }
		public ThisReferenceExpressionContext(Primary_expression_startContext ctx) { copyFrom(ctx); }
	}
	public static class ObjectCreationExpressionContext extends Primary_expression_startContext {
		public TerminalNode NEW() { return getToken(XiasParser.NEW, 0); }
		public Type_Context type_() {
			return getRuleContext(Type_Context.class,0);
		}
		public Anonymous_object_initializerContext anonymous_object_initializer() {
			return getRuleContext(Anonymous_object_initializerContext.class,0);
		}
		public List<Rank_specifierContext> rank_specifier() {
			return getRuleContexts(Rank_specifierContext.class);
		}
		public Rank_specifierContext rank_specifier(int i) {
			return getRuleContext(Rank_specifierContext.class,i);
		}
		public Array_initializerContext array_initializer() {
			return getRuleContext(Array_initializerContext.class,0);
		}
		public Object_creation_expressionContext object_creation_expression() {
			return getRuleContext(Object_creation_expressionContext.class,0);
		}
		public Object_or_collection_initializerContext object_or_collection_initializer() {
			return getRuleContext(Object_or_collection_initializerContext.class,0);
		}
		public TerminalNode OPEN_BRACKET() { return getToken(XiasParser.OPEN_BRACKET, 0); }
		public Expression_listContext expression_list() {
			return getRuleContext(Expression_listContext.class,0);
		}
		public TerminalNode CLOSE_BRACKET() { return getToken(XiasParser.CLOSE_BRACKET, 0); }
		public ObjectCreationExpressionContext(Primary_expression_startContext ctx) { copyFrom(ctx); }
	}
	public static class TypeofExpressionContext extends Primary_expression_startContext {
		public TerminalNode TYPEOF() { return getToken(XiasParser.TYPEOF, 0); }
		public TerminalNode OPEN_PARENS() { return getToken(XiasParser.OPEN_PARENS, 0); }
		public TerminalNode CLOSE_PARENS() { return getToken(XiasParser.CLOSE_PARENS, 0); }
		public Unbound_type_nameContext unbound_type_name() {
			return getRuleContext(Unbound_type_nameContext.class,0);
		}
		public Type_Context type_() {
			return getRuleContext(Type_Context.class,0);
		}
		public TerminalNode VOID() { return getToken(XiasParser.VOID, 0); }
		public TypeofExpressionContext(Primary_expression_startContext ctx) { copyFrom(ctx); }
	}
	public static class LiteralAccessExpressionContext extends Primary_expression_startContext {
		public TerminalNode LITERAL_ACCESS() { return getToken(XiasParser.LITERAL_ACCESS, 0); }
		public LiteralAccessExpressionContext(Primary_expression_startContext ctx) { copyFrom(ctx); }
	}
	public static class DefaultValueExpressionContext extends Primary_expression_startContext {
		public TerminalNode DEFAULT() { return getToken(XiasParser.DEFAULT, 0); }
		public TerminalNode OPEN_PARENS() { return getToken(XiasParser.OPEN_PARENS, 0); }
		public Type_Context type_() {
			return getRuleContext(Type_Context.class,0);
		}
		public TerminalNode CLOSE_PARENS() { return getToken(XiasParser.CLOSE_PARENS, 0); }
		public DefaultValueExpressionContext(Primary_expression_startContext ctx) { copyFrom(ctx); }
	}
	public static class SimpleNameExpressionContext extends Primary_expression_startContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public Type_argument_listContext type_argument_list() {
			return getRuleContext(Type_argument_listContext.class,0);
		}
		public SimpleNameExpressionContext(Primary_expression_startContext ctx) { copyFrom(ctx); }
	}
	public static class MemberAccessExpressionContext extends Primary_expression_startContext {
		public Predefined_typeContext predefined_type() {
			return getRuleContext(Predefined_typeContext.class,0);
		}
		public Qualified_alias_memberContext qualified_alias_member() {
			return getRuleContext(Qualified_alias_memberContext.class,0);
		}
		public MemberAccessExpressionContext(Primary_expression_startContext ctx) { copyFrom(ctx); }
	}
	public static class LiteralExpressionContext extends Primary_expression_startContext {
		public LiteralContext literal() {
			return getRuleContext(LiteralContext.class,0);
		}
		public LiteralExpressionContext(Primary_expression_startContext ctx) { copyFrom(ctx); }
	}
	public static class BaseAccessExpressionContext extends Primary_expression_startContext {
		public TerminalNode BASE() { return getToken(XiasParser.BASE, 0); }
		public TerminalNode DOT() { return getToken(XiasParser.DOT, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode OPEN_BRACKET() { return getToken(XiasParser.OPEN_BRACKET, 0); }
		public Expression_listContext expression_list() {
			return getRuleContext(Expression_listContext.class,0);
		}
		public TerminalNode CLOSE_BRACKET() { return getToken(XiasParser.CLOSE_BRACKET, 0); }
		public Type_argument_listContext type_argument_list() {
			return getRuleContext(Type_argument_listContext.class,0);
		}
		public BaseAccessExpressionContext(Primary_expression_startContext ctx) { copyFrom(ctx); }
	}
	public static class SizeofExpressionContext extends Primary_expression_startContext {
		public TerminalNode SIZEOF() { return getToken(XiasParser.SIZEOF, 0); }
		public TerminalNode OPEN_PARENS() { return getToken(XiasParser.OPEN_PARENS, 0); }
		public Type_Context type_() {
			return getRuleContext(Type_Context.class,0);
		}
		public TerminalNode CLOSE_PARENS() { return getToken(XiasParser.CLOSE_PARENS, 0); }
		public SizeofExpressionContext(Primary_expression_startContext ctx) { copyFrom(ctx); }
	}
	public static class ParenthesisExpressionsContext extends Primary_expression_startContext {
		public TerminalNode OPEN_PARENS() { return getToken(XiasParser.OPEN_PARENS, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode CLOSE_PARENS() { return getToken(XiasParser.CLOSE_PARENS, 0); }
		public ParenthesisExpressionsContext(Primary_expression_startContext ctx) { copyFrom(ctx); }
	}
	public static class NameofExpressionContext extends Primary_expression_startContext {
		public TerminalNode NAMEOF() { return getToken(XiasParser.NAMEOF, 0); }
		public TerminalNode OPEN_PARENS() { return getToken(XiasParser.OPEN_PARENS, 0); }
		public List<IdentifierContext> identifier() {
			return getRuleContexts(IdentifierContext.class);
		}
		public IdentifierContext identifier(int i) {
			return getRuleContext(IdentifierContext.class,i);
		}
		public TerminalNode CLOSE_PARENS() { return getToken(XiasParser.CLOSE_PARENS, 0); }
		public List<TerminalNode> DOT() { return getTokens(XiasParser.DOT); }
		public TerminalNode DOT(int i) {
			return getToken(XiasParser.DOT, i);
		}
		public NameofExpressionContext(Primary_expression_startContext ctx) { copyFrom(ctx); }
	}

	public final Primary_expression_startContext primary_expression_start() throws RecognitionException {
		Primary_expression_startContext _localctx = new Primary_expression_startContext(_ctx, getState());
		enterRule(_localctx, 66, RULE_primary_expression_start);
		int _la;
		try {
			int _alt;
			setState(724);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,59,_ctx) ) {
			case 1:
				_localctx = new LiteralExpressionContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(635);
				literal();
				}
				break;
			case 2:
				_localctx = new SimpleNameExpressionContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(636);
				identifier();
				setState(638);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,48,_ctx) ) {
				case 1:
					{
					setState(637);
					type_argument_list();
					}
					break;
				}
				}
				break;
			case 3:
				_localctx = new ParenthesisExpressionsContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(640);
				match(OPEN_PARENS);
				setState(641);
				expression();
				setState(642);
				match(CLOSE_PARENS);
				}
				break;
			case 4:
				_localctx = new MemberAccessExpressionContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(644);
				predefined_type();
				}
				break;
			case 5:
				_localctx = new MemberAccessExpressionContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(645);
				qualified_alias_member();
				}
				break;
			case 6:
				_localctx = new LiteralAccessExpressionContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(646);
				match(LITERAL_ACCESS);
				}
				break;
			case 7:
				_localctx = new ThisReferenceExpressionContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(647);
				match(THIS);
				}
				break;
			case 8:
				_localctx = new BaseAccessExpressionContext(_localctx);
				enterOuterAlt(_localctx, 8);
				{
				setState(648);
				match(BASE);
				setState(658);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case DOT:
					{
					setState(649);
					match(DOT);
					setState(650);
					identifier();
					setState(652);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,49,_ctx) ) {
					case 1:
						{
						setState(651);
						type_argument_list();
						}
						break;
					}
					}
					break;
				case OPEN_BRACKET:
					{
					setState(654);
					match(OPEN_BRACKET);
					setState(655);
					expression_list();
					setState(656);
					match(CLOSE_BRACKET);
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				break;
			case 9:
				_localctx = new ObjectCreationExpressionContext(_localctx);
				enterOuterAlt(_localctx, 9);
				{
				setState(660);
				match(NEW);
				setState(689);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case BOOL:
				case CHAR:
				case DOUBLE:
				case FLOAT:
				case GET:
				case INT:
				case NAMEOF:
				case OBJECT:
				case SET:
				case STRING:
				case UINT:
				case VAR:
				case VOID:
				case WHEN:
				case WHERE:
				case IDENTIFIER:
					{
					setState(661);
					type_();
					setState(683);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,54,_ctx) ) {
					case 1:
						{
						setState(662);
						object_creation_expression();
						}
						break;
					case 2:
						{
						setState(663);
						object_or_collection_initializer();
						}
						break;
					case 3:
						{
						setState(664);
						match(OPEN_BRACKET);
						setState(665);
						expression_list();
						setState(666);
						match(CLOSE_BRACKET);
						setState(670);
						_errHandler.sync(this);
						_alt = getInterpreter().adaptivePredict(_input,51,_ctx);
						while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
							if ( _alt==1 ) {
								{
								{
								setState(667);
								rank_specifier();
								}
								} 
							}
							setState(672);
							_errHandler.sync(this);
							_alt = getInterpreter().adaptivePredict(_input,51,_ctx);
						}
						setState(674);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if (_la==OPEN_BRACE) {
							{
							setState(673);
							array_initializer();
							}
						}

						}
						break;
					case 4:
						{
						setState(677); 
						_errHandler.sync(this);
						_la = _input.LA(1);
						do {
							{
							{
							setState(676);
							rank_specifier();
							}
							}
							setState(679); 
							_errHandler.sync(this);
							_la = _input.LA(1);
						} while ( _la==OPEN_BRACKET );
						setState(681);
						array_initializer();
						}
						break;
					}
					}
					break;
				case OPEN_BRACE:
					{
					setState(685);
					anonymous_object_initializer();
					}
					break;
				case OPEN_BRACKET:
					{
					setState(686);
					rank_specifier();
					setState(687);
					array_initializer();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				break;
			case 10:
				_localctx = new TypeofExpressionContext(_localctx);
				enterOuterAlt(_localctx, 10);
				{
				setState(691);
				match(TYPEOF);
				setState(692);
				match(OPEN_PARENS);
				setState(696);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,56,_ctx) ) {
				case 1:
					{
					setState(693);
					unbound_type_name();
					}
					break;
				case 2:
					{
					setState(694);
					type_();
					}
					break;
				case 3:
					{
					setState(695);
					match(VOID);
					}
					break;
				}
				setState(698);
				match(CLOSE_PARENS);
				}
				break;
			case 11:
				_localctx = new DefaultValueExpressionContext(_localctx);
				enterOuterAlt(_localctx, 11);
				{
				setState(699);
				match(DEFAULT);
				setState(704);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,57,_ctx) ) {
				case 1:
					{
					setState(700);
					match(OPEN_PARENS);
					setState(701);
					type_();
					setState(702);
					match(CLOSE_PARENS);
					}
					break;
				}
				}
				break;
			case 12:
				_localctx = new SizeofExpressionContext(_localctx);
				enterOuterAlt(_localctx, 12);
				{
				setState(706);
				match(SIZEOF);
				setState(707);
				match(OPEN_PARENS);
				setState(708);
				type_();
				setState(709);
				match(CLOSE_PARENS);
				}
				break;
			case 13:
				_localctx = new NameofExpressionContext(_localctx);
				enterOuterAlt(_localctx, 13);
				{
				setState(711);
				match(NAMEOF);
				setState(712);
				match(OPEN_PARENS);
				setState(718);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,58,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(713);
						identifier();
						setState(714);
						match(DOT);
						}
						} 
					}
					setState(720);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,58,_ctx);
				}
				setState(721);
				identifier();
				setState(722);
				match(CLOSE_PARENS);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Throwable_expressionContext extends ParserRuleContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Throw_expressionContext throw_expression() {
			return getRuleContext(Throw_expressionContext.class,0);
		}
		public Throwable_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_throwable_expression; }
	}

	public final Throwable_expressionContext throwable_expression() throws RecognitionException {
		Throwable_expressionContext _localctx = new Throwable_expressionContext(_ctx, getState());
		enterRule(_localctx, 68, RULE_throwable_expression);
		try {
			setState(728);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case BASE:
			case BOOL:
			case CHAR:
			case DEFAULT:
			case DOUBLE:
			case FALSE:
			case FLOAT:
			case GET:
			case INT:
			case NAMEOF:
			case NEW:
			case NULL_:
			case OBJECT:
			case REF:
			case SET:
			case SIZEOF:
			case STRING:
			case THIS:
			case TRUE:
			case TYPEOF:
			case UINT:
			case VAR:
			case WHEN:
			case WHERE:
			case IDENTIFIER:
			case LITERAL_ACCESS:
			case INTEGER_LITERAL:
			case HEX_INTEGER_LITERAL:
			case REAL_LITERAL:
			case CHARACTER_LITERAL:
			case REGULAR_STRING:
			case VERBATIUM_STRING:
			case OPEN_PARENS:
			case PLUS:
			case MINUS:
			case STAR:
			case BANG:
			case TILDE:
			case OP_INC:
			case OP_DEC:
				enterOuterAlt(_localctx, 1);
				{
				setState(726);
				expression();
				}
				break;
			case THROW:
				enterOuterAlt(_localctx, 2);
				{
				setState(727);
				throw_expression();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Throw_expressionContext extends ParserRuleContext {
		public TerminalNode THROW() { return getToken(XiasParser.THROW, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Throw_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_throw_expression; }
	}

	public final Throw_expressionContext throw_expression() throws RecognitionException {
		Throw_expressionContext _localctx = new Throw_expressionContext(_ctx, getState());
		enterRule(_localctx, 70, RULE_throw_expression);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(730);
			match(THROW);
			setState(731);
			expression();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Member_accessContext extends ParserRuleContext {
		public TerminalNode DOT() { return getToken(XiasParser.DOT, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public Type_argument_listContext type_argument_list() {
			return getRuleContext(Type_argument_listContext.class,0);
		}
		public Member_accessContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_member_access; }
	}

	public final Member_accessContext member_access() throws RecognitionException {
		Member_accessContext _localctx = new Member_accessContext(_ctx, getState());
		enterRule(_localctx, 72, RULE_member_access);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(733);
			match(DOT);
			setState(734);
			identifier();
			setState(736);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,61,_ctx) ) {
			case 1:
				{
				setState(735);
				type_argument_list();
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Bracket_expressionContext extends ParserRuleContext {
		public TerminalNode OPEN_BRACKET() { return getToken(XiasParser.OPEN_BRACKET, 0); }
		public List<Indexer_argumentContext> indexer_argument() {
			return getRuleContexts(Indexer_argumentContext.class);
		}
		public Indexer_argumentContext indexer_argument(int i) {
			return getRuleContext(Indexer_argumentContext.class,i);
		}
		public TerminalNode CLOSE_BRACKET() { return getToken(XiasParser.CLOSE_BRACKET, 0); }
		public List<TerminalNode> COMMA() { return getTokens(XiasParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(XiasParser.COMMA, i);
		}
		public Bracket_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_bracket_expression; }
	}

	public final Bracket_expressionContext bracket_expression() throws RecognitionException {
		Bracket_expressionContext _localctx = new Bracket_expressionContext(_ctx, getState());
		enterRule(_localctx, 74, RULE_bracket_expression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(738);
			match(OPEN_BRACKET);
			setState(739);
			indexer_argument();
			setState(744);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(740);
				match(COMMA);
				setState(741);
				indexer_argument();
				}
				}
				setState(746);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(747);
			match(CLOSE_BRACKET);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Indexer_argumentContext extends ParserRuleContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode COLON() { return getToken(XiasParser.COLON, 0); }
		public Indexer_argumentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_indexer_argument; }
	}

	public final Indexer_argumentContext indexer_argument() throws RecognitionException {
		Indexer_argumentContext _localctx = new Indexer_argumentContext(_ctx, getState());
		enterRule(_localctx, 76, RULE_indexer_argument);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(752);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,63,_ctx) ) {
			case 1:
				{
				setState(749);
				identifier();
				setState(750);
				match(COLON);
				}
				break;
			}
			setState(754);
			expression();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Predefined_typeContext extends ParserRuleContext {
		public TerminalNode BOOL() { return getToken(XiasParser.BOOL, 0); }
		public TerminalNode CHAR() { return getToken(XiasParser.CHAR, 0); }
		public TerminalNode DOUBLE() { return getToken(XiasParser.DOUBLE, 0); }
		public TerminalNode FLOAT() { return getToken(XiasParser.FLOAT, 0); }
		public TerminalNode INT() { return getToken(XiasParser.INT, 0); }
		public TerminalNode OBJECT() { return getToken(XiasParser.OBJECT, 0); }
		public TerminalNode STRING() { return getToken(XiasParser.STRING, 0); }
		public TerminalNode UINT() { return getToken(XiasParser.UINT, 0); }
		public Predefined_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_predefined_type; }
	}

	public final Predefined_typeContext predefined_type() throws RecognitionException {
		Predefined_typeContext _localctx = new Predefined_typeContext(_ctx, getState());
		enterRule(_localctx, 78, RULE_predefined_type);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(756);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << BOOL) | (1L << CHAR) | (1L << DOUBLE) | (1L << FLOAT) | (1L << INT) | (1L << OBJECT) | (1L << STRING) | (1L << UINT))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Expression_listContext extends ParserRuleContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(XiasParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(XiasParser.COMMA, i);
		}
		public Expression_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression_list; }
	}

	public final Expression_listContext expression_list() throws RecognitionException {
		Expression_listContext _localctx = new Expression_listContext(_ctx, getState());
		enterRule(_localctx, 80, RULE_expression_list);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(758);
			expression();
			setState(763);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(759);
				match(COMMA);
				setState(760);
				expression();
				}
				}
				setState(765);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Object_or_collection_initializerContext extends ParserRuleContext {
		public Object_initializerContext object_initializer() {
			return getRuleContext(Object_initializerContext.class,0);
		}
		public Collection_initializerContext collection_initializer() {
			return getRuleContext(Collection_initializerContext.class,0);
		}
		public Object_or_collection_initializerContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_object_or_collection_initializer; }
	}

	public final Object_or_collection_initializerContext object_or_collection_initializer() throws RecognitionException {
		Object_or_collection_initializerContext _localctx = new Object_or_collection_initializerContext(_ctx, getState());
		enterRule(_localctx, 82, RULE_object_or_collection_initializer);
		try {
			setState(768);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,65,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(766);
				object_initializer();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(767);
				collection_initializer();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Object_initializerContext extends ParserRuleContext {
		public TerminalNode OPEN_BRACE() { return getToken(XiasParser.OPEN_BRACE, 0); }
		public TerminalNode CLOSE_BRACE() { return getToken(XiasParser.CLOSE_BRACE, 0); }
		public Member_initializer_listContext member_initializer_list() {
			return getRuleContext(Member_initializer_listContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(XiasParser.COMMA, 0); }
		public Object_initializerContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_object_initializer; }
	}

	public final Object_initializerContext object_initializer() throws RecognitionException {
		Object_initializerContext _localctx = new Object_initializerContext(_ctx, getState());
		enterRule(_localctx, 84, RULE_object_initializer);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(770);
			match(OPEN_BRACE);
			setState(775);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (((((_la - 28)) & ~0x3f) == 0 && ((1L << (_la - 28)) & ((1L << (GET - 28)) | (1L << (NAMEOF - 28)) | (1L << (SET - 28)) | (1L << (VAR - 28)) | (1L << (WHEN - 28)) | (1L << (WHERE - 28)) | (1L << (IDENTIFIER - 28)) | (1L << (OPEN_BRACKET - 28)))) != 0)) {
				{
				setState(771);
				member_initializer_list();
				setState(773);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==COMMA) {
					{
					setState(772);
					match(COMMA);
					}
				}

				}
			}

			setState(777);
			match(CLOSE_BRACE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Member_initializer_listContext extends ParserRuleContext {
		public List<Member_initializerContext> member_initializer() {
			return getRuleContexts(Member_initializerContext.class);
		}
		public Member_initializerContext member_initializer(int i) {
			return getRuleContext(Member_initializerContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(XiasParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(XiasParser.COMMA, i);
		}
		public Member_initializer_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_member_initializer_list; }
	}

	public final Member_initializer_listContext member_initializer_list() throws RecognitionException {
		Member_initializer_listContext _localctx = new Member_initializer_listContext(_ctx, getState());
		enterRule(_localctx, 86, RULE_member_initializer_list);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(779);
			member_initializer();
			setState(784);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,68,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(780);
					match(COMMA);
					setState(781);
					member_initializer();
					}
					} 
				}
				setState(786);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,68,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Member_initializerContext extends ParserRuleContext {
		public TerminalNode ASSIGNMENT() { return getToken(XiasParser.ASSIGNMENT, 0); }
		public Initializer_valueContext initializer_value() {
			return getRuleContext(Initializer_valueContext.class,0);
		}
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode OPEN_BRACKET() { return getToken(XiasParser.OPEN_BRACKET, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode CLOSE_BRACKET() { return getToken(XiasParser.CLOSE_BRACKET, 0); }
		public Member_initializerContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_member_initializer; }
	}

	public final Member_initializerContext member_initializer() throws RecognitionException {
		Member_initializerContext _localctx = new Member_initializerContext(_ctx, getState());
		enterRule(_localctx, 88, RULE_member_initializer);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(792);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case GET:
			case NAMEOF:
			case SET:
			case VAR:
			case WHEN:
			case WHERE:
			case IDENTIFIER:
				{
				setState(787);
				identifier();
				}
				break;
			case OPEN_BRACKET:
				{
				setState(788);
				match(OPEN_BRACKET);
				setState(789);
				expression();
				setState(790);
				match(CLOSE_BRACKET);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(794);
			match(ASSIGNMENT);
			setState(795);
			initializer_value();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Initializer_valueContext extends ParserRuleContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Object_or_collection_initializerContext object_or_collection_initializer() {
			return getRuleContext(Object_or_collection_initializerContext.class,0);
		}
		public Initializer_valueContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_initializer_value; }
	}

	public final Initializer_valueContext initializer_value() throws RecognitionException {
		Initializer_valueContext _localctx = new Initializer_valueContext(_ctx, getState());
		enterRule(_localctx, 90, RULE_initializer_value);
		try {
			setState(799);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case BASE:
			case BOOL:
			case CHAR:
			case DEFAULT:
			case DOUBLE:
			case FALSE:
			case FLOAT:
			case GET:
			case INT:
			case NAMEOF:
			case NEW:
			case NULL_:
			case OBJECT:
			case REF:
			case SET:
			case SIZEOF:
			case STRING:
			case THIS:
			case TRUE:
			case TYPEOF:
			case UINT:
			case VAR:
			case WHEN:
			case WHERE:
			case IDENTIFIER:
			case LITERAL_ACCESS:
			case INTEGER_LITERAL:
			case HEX_INTEGER_LITERAL:
			case REAL_LITERAL:
			case CHARACTER_LITERAL:
			case REGULAR_STRING:
			case VERBATIUM_STRING:
			case OPEN_PARENS:
			case PLUS:
			case MINUS:
			case STAR:
			case BANG:
			case TILDE:
			case OP_INC:
			case OP_DEC:
				enterOuterAlt(_localctx, 1);
				{
				setState(797);
				expression();
				}
				break;
			case OPEN_BRACE:
				enterOuterAlt(_localctx, 2);
				{
				setState(798);
				object_or_collection_initializer();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Collection_initializerContext extends ParserRuleContext {
		public TerminalNode OPEN_BRACE() { return getToken(XiasParser.OPEN_BRACE, 0); }
		public List<Element_initializerContext> element_initializer() {
			return getRuleContexts(Element_initializerContext.class);
		}
		public Element_initializerContext element_initializer(int i) {
			return getRuleContext(Element_initializerContext.class,i);
		}
		public TerminalNode CLOSE_BRACE() { return getToken(XiasParser.CLOSE_BRACE, 0); }
		public List<TerminalNode> COMMA() { return getTokens(XiasParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(XiasParser.COMMA, i);
		}
		public Collection_initializerContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_collection_initializer; }
	}

	public final Collection_initializerContext collection_initializer() throws RecognitionException {
		Collection_initializerContext _localctx = new Collection_initializerContext(_ctx, getState());
		enterRule(_localctx, 92, RULE_collection_initializer);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(801);
			match(OPEN_BRACE);
			setState(802);
			element_initializer();
			setState(807);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,71,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(803);
					match(COMMA);
					setState(804);
					element_initializer();
					}
					} 
				}
				setState(809);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,71,_ctx);
			}
			setState(811);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==COMMA) {
				{
				setState(810);
				match(COMMA);
				}
			}

			setState(813);
			match(CLOSE_BRACE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Element_initializerContext extends ParserRuleContext {
		public Non_assignment_expressionContext non_assignment_expression() {
			return getRuleContext(Non_assignment_expressionContext.class,0);
		}
		public TerminalNode OPEN_BRACE() { return getToken(XiasParser.OPEN_BRACE, 0); }
		public Expression_listContext expression_list() {
			return getRuleContext(Expression_listContext.class,0);
		}
		public TerminalNode CLOSE_BRACE() { return getToken(XiasParser.CLOSE_BRACE, 0); }
		public Element_initializerContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_element_initializer; }
	}

	public final Element_initializerContext element_initializer() throws RecognitionException {
		Element_initializerContext _localctx = new Element_initializerContext(_ctx, getState());
		enterRule(_localctx, 94, RULE_element_initializer);
		try {
			setState(820);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case BASE:
			case BOOL:
			case CHAR:
			case DEFAULT:
			case DOUBLE:
			case FALSE:
			case FLOAT:
			case GET:
			case INT:
			case NAMEOF:
			case NEW:
			case NULL_:
			case OBJECT:
			case SET:
			case SIZEOF:
			case STRING:
			case THIS:
			case TRUE:
			case TYPEOF:
			case UINT:
			case VAR:
			case WHEN:
			case WHERE:
			case IDENTIFIER:
			case LITERAL_ACCESS:
			case INTEGER_LITERAL:
			case HEX_INTEGER_LITERAL:
			case REAL_LITERAL:
			case CHARACTER_LITERAL:
			case REGULAR_STRING:
			case VERBATIUM_STRING:
			case OPEN_PARENS:
			case PLUS:
			case MINUS:
			case STAR:
			case BANG:
			case TILDE:
			case OP_INC:
			case OP_DEC:
				enterOuterAlt(_localctx, 1);
				{
				setState(815);
				non_assignment_expression();
				}
				break;
			case OPEN_BRACE:
				enterOuterAlt(_localctx, 2);
				{
				setState(816);
				match(OPEN_BRACE);
				setState(817);
				expression_list();
				setState(818);
				match(CLOSE_BRACE);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Anonymous_object_initializerContext extends ParserRuleContext {
		public TerminalNode OPEN_BRACE() { return getToken(XiasParser.OPEN_BRACE, 0); }
		public TerminalNode CLOSE_BRACE() { return getToken(XiasParser.CLOSE_BRACE, 0); }
		public Member_declarator_listContext member_declarator_list() {
			return getRuleContext(Member_declarator_listContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(XiasParser.COMMA, 0); }
		public Anonymous_object_initializerContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_anonymous_object_initializer; }
	}

	public final Anonymous_object_initializerContext anonymous_object_initializer() throws RecognitionException {
		Anonymous_object_initializerContext _localctx = new Anonymous_object_initializerContext(_ctx, getState());
		enterRule(_localctx, 96, RULE_anonymous_object_initializer);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(822);
			match(OPEN_BRACE);
			setState(827);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << BASE) | (1L << BOOL) | (1L << CHAR) | (1L << DEFAULT) | (1L << DOUBLE) | (1L << FALSE) | (1L << FLOAT) | (1L << GET) | (1L << INT) | (1L << NAMEOF) | (1L << NEW) | (1L << NULL_) | (1L << OBJECT) | (1L << SET) | (1L << SIZEOF) | (1L << STRING) | (1L << THIS) | (1L << TRUE) | (1L << TYPEOF) | (1L << UINT))) != 0) || ((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & ((1L << (VAR - 64)) | (1L << (WHEN - 64)) | (1L << (WHERE - 64)) | (1L << (IDENTIFIER - 64)) | (1L << (LITERAL_ACCESS - 64)) | (1L << (INTEGER_LITERAL - 64)) | (1L << (HEX_INTEGER_LITERAL - 64)) | (1L << (REAL_LITERAL - 64)) | (1L << (CHARACTER_LITERAL - 64)) | (1L << (REGULAR_STRING - 64)) | (1L << (VERBATIUM_STRING - 64)) | (1L << (OPEN_PARENS - 64)))) != 0)) {
				{
				setState(823);
				member_declarator_list();
				setState(825);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==COMMA) {
					{
					setState(824);
					match(COMMA);
					}
				}

				}
			}

			setState(829);
			match(CLOSE_BRACE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Member_declarator_listContext extends ParserRuleContext {
		public List<Member_declaratorContext> member_declarator() {
			return getRuleContexts(Member_declaratorContext.class);
		}
		public Member_declaratorContext member_declarator(int i) {
			return getRuleContext(Member_declaratorContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(XiasParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(XiasParser.COMMA, i);
		}
		public Member_declarator_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_member_declarator_list; }
	}

	public final Member_declarator_listContext member_declarator_list() throws RecognitionException {
		Member_declarator_listContext _localctx = new Member_declarator_listContext(_ctx, getState());
		enterRule(_localctx, 98, RULE_member_declarator_list);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(831);
			member_declarator();
			setState(836);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,76,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(832);
					match(COMMA);
					setState(833);
					member_declarator();
					}
					} 
				}
				setState(838);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,76,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Member_declaratorContext extends ParserRuleContext {
		public Primary_expressionContext primary_expression() {
			return getRuleContext(Primary_expressionContext.class,0);
		}
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode ASSIGNMENT() { return getToken(XiasParser.ASSIGNMENT, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Member_declaratorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_member_declarator; }
	}

	public final Member_declaratorContext member_declarator() throws RecognitionException {
		Member_declaratorContext _localctx = new Member_declaratorContext(_ctx, getState());
		enterRule(_localctx, 100, RULE_member_declarator);
		try {
			setState(844);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,77,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(839);
				primary_expression();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(840);
				identifier();
				setState(841);
				match(ASSIGNMENT);
				setState(842);
				expression();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Unbound_type_nameContext extends ParserRuleContext {
		public List<IdentifierContext> identifier() {
			return getRuleContexts(IdentifierContext.class);
		}
		public IdentifierContext identifier(int i) {
			return getRuleContext(IdentifierContext.class,i);
		}
		public TerminalNode DOUBLE_COLON() { return getToken(XiasParser.DOUBLE_COLON, 0); }
		public List<TerminalNode> DOT() { return getTokens(XiasParser.DOT); }
		public TerminalNode DOT(int i) {
			return getToken(XiasParser.DOT, i);
		}
		public List<Generic_dimension_specifierContext> generic_dimension_specifier() {
			return getRuleContexts(Generic_dimension_specifierContext.class);
		}
		public Generic_dimension_specifierContext generic_dimension_specifier(int i) {
			return getRuleContext(Generic_dimension_specifierContext.class,i);
		}
		public Unbound_type_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unbound_type_name; }
	}

	public final Unbound_type_nameContext unbound_type_name() throws RecognitionException {
		Unbound_type_nameContext _localctx = new Unbound_type_nameContext(_ctx, getState());
		enterRule(_localctx, 102, RULE_unbound_type_name);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(846);
			identifier();
			setState(855);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case CLOSE_PARENS:
			case DOT:
			case LT:
				{
				setState(848);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==LT) {
					{
					setState(847);
					generic_dimension_specifier();
					}
				}

				}
				break;
			case DOUBLE_COLON:
				{
				setState(850);
				match(DOUBLE_COLON);
				setState(851);
				identifier();
				setState(853);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==LT) {
					{
					setState(852);
					generic_dimension_specifier();
					}
				}

				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(864);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==DOT) {
				{
				{
				setState(857);
				match(DOT);
				setState(858);
				identifier();
				setState(860);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==LT) {
					{
					setState(859);
					generic_dimension_specifier();
					}
				}

				}
				}
				setState(866);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Generic_dimension_specifierContext extends ParserRuleContext {
		public TerminalNode LT() { return getToken(XiasParser.LT, 0); }
		public TerminalNode GT() { return getToken(XiasParser.GT, 0); }
		public List<TerminalNode> COMMA() { return getTokens(XiasParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(XiasParser.COMMA, i);
		}
		public Generic_dimension_specifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_generic_dimension_specifier; }
	}

	public final Generic_dimension_specifierContext generic_dimension_specifier() throws RecognitionException {
		Generic_dimension_specifierContext _localctx = new Generic_dimension_specifierContext(_ctx, getState());
		enterRule(_localctx, 104, RULE_generic_dimension_specifier);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(867);
			match(LT);
			setState(871);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(868);
				match(COMMA);
				}
				}
				setState(873);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(874);
			match(GT);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IsTypeContext extends ParserRuleContext {
		public Base_typeContext base_type() {
			return getRuleContext(Base_typeContext.class,0);
		}
		public List<Rank_specifierContext> rank_specifier() {
			return getRuleContexts(Rank_specifierContext.class);
		}
		public Rank_specifierContext rank_specifier(int i) {
			return getRuleContext(Rank_specifierContext.class,i);
		}
		public List<TerminalNode> STAR() { return getTokens(XiasParser.STAR); }
		public TerminalNode STAR(int i) {
			return getToken(XiasParser.STAR, i);
		}
		public IsTypePatternArmsContext isTypePatternArms() {
			return getRuleContext(IsTypePatternArmsContext.class,0);
		}
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public IsTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_isType; }
	}

	public final IsTypeContext isType() throws RecognitionException {
		IsTypeContext _localctx = new IsTypeContext(_ctx, getState());
		enterRule(_localctx, 106, RULE_isType);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(876);
			base_type();
			setState(881);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==OPEN_BRACKET || _la==STAR) {
				{
				setState(879);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case OPEN_BRACKET:
					{
					setState(877);
					rank_specifier();
					}
					break;
				case STAR:
					{
					setState(878);
					match(STAR);
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				setState(883);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(885);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==OPEN_BRACE) {
				{
				setState(884);
				isTypePatternArms();
				}
			}

			setState(888);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (((((_la - 28)) & ~0x3f) == 0 && ((1L << (_la - 28)) & ((1L << (GET - 28)) | (1L << (NAMEOF - 28)) | (1L << (SET - 28)) | (1L << (VAR - 28)) | (1L << (WHEN - 28)) | (1L << (WHERE - 28)) | (1L << (IDENTIFIER - 28)))) != 0)) {
				{
				setState(887);
				identifier();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IsTypePatternArmsContext extends ParserRuleContext {
		public TerminalNode OPEN_BRACE() { return getToken(XiasParser.OPEN_BRACE, 0); }
		public List<IsTypePatternArmContext> isTypePatternArm() {
			return getRuleContexts(IsTypePatternArmContext.class);
		}
		public IsTypePatternArmContext isTypePatternArm(int i) {
			return getRuleContext(IsTypePatternArmContext.class,i);
		}
		public TerminalNode CLOSE_BRACE() { return getToken(XiasParser.CLOSE_BRACE, 0); }
		public List<TerminalNode> COMMA() { return getTokens(XiasParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(XiasParser.COMMA, i);
		}
		public IsTypePatternArmsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_isTypePatternArms; }
	}

	public final IsTypePatternArmsContext isTypePatternArms() throws RecognitionException {
		IsTypePatternArmsContext _localctx = new IsTypePatternArmsContext(_ctx, getState());
		enterRule(_localctx, 108, RULE_isTypePatternArms);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(890);
			match(OPEN_BRACE);
			setState(891);
			isTypePatternArm();
			setState(896);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(892);
				match(COMMA);
				setState(893);
				isTypePatternArm();
				}
				}
				setState(898);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(899);
			match(CLOSE_BRACE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IsTypePatternArmContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode COLON() { return getToken(XiasParser.COLON, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public IsTypePatternArmContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_isTypePatternArm; }
	}

	public final IsTypePatternArmContext isTypePatternArm() throws RecognitionException {
		IsTypePatternArmContext _localctx = new IsTypePatternArmContext(_ctx, getState());
		enterRule(_localctx, 110, RULE_isTypePatternArm);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(901);
			identifier();
			setState(902);
			match(COLON);
			setState(903);
			expression();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Where_clauseContext extends ParserRuleContext {
		public TerminalNode WHERE() { return getToken(XiasParser.WHERE, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Where_clauseContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_where_clause; }
	}

	public final Where_clauseContext where_clause() throws RecognitionException {
		Where_clauseContext _localctx = new Where_clauseContext(_ctx, getState());
		enterRule(_localctx, 112, RULE_where_clause);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(905);
			match(WHERE);
			setState(906);
			expression();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StatementContext extends ParserRuleContext {
		public Labeled_StatementContext labeled_Statement() {
			return getRuleContext(Labeled_StatementContext.class,0);
		}
		public DeclarationStatementContext declarationStatement() {
			return getRuleContext(DeclarationStatementContext.class,0);
		}
		public Embedded_statementContext embedded_statement() {
			return getRuleContext(Embedded_statementContext.class,0);
		}
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 114, RULE_statement);
		try {
			setState(911);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,89,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(908);
				labeled_Statement();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(909);
				declarationStatement();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(910);
				embedded_statement();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DeclarationStatementContext extends ParserRuleContext {
		public Local_variable_declarationContext local_variable_declaration() {
			return getRuleContext(Local_variable_declarationContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(XiasParser.SEMICOLON, 0); }
		public Local_constant_declarationContext local_constant_declaration() {
			return getRuleContext(Local_constant_declarationContext.class,0);
		}
		public DeclarationStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declarationStatement; }
	}

	public final DeclarationStatementContext declarationStatement() throws RecognitionException {
		DeclarationStatementContext _localctx = new DeclarationStatementContext(_ctx, getState());
		enterRule(_localctx, 116, RULE_declarationStatement);
		try {
			setState(919);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case BOOL:
			case CHAR:
			case DOUBLE:
			case FLOAT:
			case GET:
			case INT:
			case NAMEOF:
			case OBJECT:
			case REF:
			case SET:
			case STRING:
			case UINT:
			case USING:
			case VAR:
			case VOID:
			case WHEN:
			case WHERE:
			case IDENTIFIER:
				enterOuterAlt(_localctx, 1);
				{
				setState(913);
				local_variable_declaration();
				setState(914);
				match(SEMICOLON);
				}
				break;
			case CONST:
				enterOuterAlt(_localctx, 2);
				{
				setState(916);
				local_constant_declaration();
				setState(917);
				match(SEMICOLON);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Labeled_StatementContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode COLON() { return getToken(XiasParser.COLON, 0); }
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public Labeled_StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_labeled_Statement; }
	}

	public final Labeled_StatementContext labeled_Statement() throws RecognitionException {
		Labeled_StatementContext _localctx = new Labeled_StatementContext(_ctx, getState());
		enterRule(_localctx, 118, RULE_labeled_Statement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(921);
			identifier();
			setState(922);
			match(COLON);
			setState(923);
			statement();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Embedded_statementContext extends ParserRuleContext {
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public Simple_embedded_statementContext simple_embedded_statement() {
			return getRuleContext(Simple_embedded_statementContext.class,0);
		}
		public Embedded_statementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_embedded_statement; }
	}

	public final Embedded_statementContext embedded_statement() throws RecognitionException {
		Embedded_statementContext _localctx = new Embedded_statementContext(_ctx, getState());
		enterRule(_localctx, 120, RULE_embedded_statement);
		try {
			setState(927);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case OPEN_BRACE:
				enterOuterAlt(_localctx, 1);
				{
				setState(925);
				block();
				}
				break;
			case BASE:
			case BOOL:
			case BREAK:
			case CHAR:
			case CONTINUE:
			case DEFAULT:
			case DO:
			case DOUBLE:
			case FALSE:
			case FLOAT:
			case FOR:
			case FOREACH:
			case GET:
			case GOTO:
			case IF:
			case INT:
			case NAMEOF:
			case NEW:
			case NULL_:
			case OBJECT:
			case REF:
			case RETURN:
			case SET:
			case SIZEOF:
			case STRING:
			case SWITCH:
			case THIS:
			case THROW:
			case TRUE:
			case TRY:
			case TYPEOF:
			case UINT:
			case USING:
			case VAR:
			case WHEN:
			case WHERE:
			case WHILE:
			case IDENTIFIER:
			case LITERAL_ACCESS:
			case INTEGER_LITERAL:
			case HEX_INTEGER_LITERAL:
			case REAL_LITERAL:
			case CHARACTER_LITERAL:
			case REGULAR_STRING:
			case VERBATIUM_STRING:
			case OPEN_PARENS:
			case SEMICOLON:
			case PLUS:
			case MINUS:
			case STAR:
			case BANG:
			case TILDE:
			case OP_INC:
			case OP_DEC:
				enterOuterAlt(_localctx, 2);
				{
				setState(926);
				simple_embedded_statement();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Simple_embedded_statementContext extends ParserRuleContext {
		public Simple_embedded_statementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simple_embedded_statement; }
	 
		public Simple_embedded_statementContext() { }
		public void copyFrom(Simple_embedded_statementContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class TryStatementContext extends Simple_embedded_statementContext {
		public TerminalNode TRY() { return getToken(XiasParser.TRY, 0); }
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public Catch_clausesContext catch_clauses() {
			return getRuleContext(Catch_clausesContext.class,0);
		}
		public Finally_clauseContext finally_clause() {
			return getRuleContext(Finally_clauseContext.class,0);
		}
		public TryStatementContext(Simple_embedded_statementContext ctx) { copyFrom(ctx); }
	}
	public static class ThrowStatementContext extends Simple_embedded_statementContext {
		public TerminalNode THROW() { return getToken(XiasParser.THROW, 0); }
		public TerminalNode SEMICOLON() { return getToken(XiasParser.SEMICOLON, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public ThrowStatementContext(Simple_embedded_statementContext ctx) { copyFrom(ctx); }
	}
	public static class TheEmptyStatementContext extends Simple_embedded_statementContext {
		public TerminalNode SEMICOLON() { return getToken(XiasParser.SEMICOLON, 0); }
		public TheEmptyStatementContext(Simple_embedded_statementContext ctx) { copyFrom(ctx); }
	}
	public static class ForStatementContext extends Simple_embedded_statementContext {
		public TerminalNode FOR() { return getToken(XiasParser.FOR, 0); }
		public TerminalNode OPEN_PARENS() { return getToken(XiasParser.OPEN_PARENS, 0); }
		public List<TerminalNode> SEMICOLON() { return getTokens(XiasParser.SEMICOLON); }
		public TerminalNode SEMICOLON(int i) {
			return getToken(XiasParser.SEMICOLON, i);
		}
		public TerminalNode CLOSE_PARENS() { return getToken(XiasParser.CLOSE_PARENS, 0); }
		public Embedded_statementContext embedded_statement() {
			return getRuleContext(Embedded_statementContext.class,0);
		}
		public For_initializerContext for_initializer() {
			return getRuleContext(For_initializerContext.class,0);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public For_iteratorContext for_iterator() {
			return getRuleContext(For_iteratorContext.class,0);
		}
		public ForStatementContext(Simple_embedded_statementContext ctx) { copyFrom(ctx); }
	}
	public static class BreakStatementContext extends Simple_embedded_statementContext {
		public TerminalNode BREAK() { return getToken(XiasParser.BREAK, 0); }
		public TerminalNode SEMICOLON() { return getToken(XiasParser.SEMICOLON, 0); }
		public BreakStatementContext(Simple_embedded_statementContext ctx) { copyFrom(ctx); }
	}
	public static class IfStatementContext extends Simple_embedded_statementContext {
		public TerminalNode IF() { return getToken(XiasParser.IF, 0); }
		public TerminalNode OPEN_PARENS() { return getToken(XiasParser.OPEN_PARENS, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode CLOSE_PARENS() { return getToken(XiasParser.CLOSE_PARENS, 0); }
		public List<If_bodyContext> if_body() {
			return getRuleContexts(If_bodyContext.class);
		}
		public If_bodyContext if_body(int i) {
			return getRuleContext(If_bodyContext.class,i);
		}
		public TerminalNode ELSE() { return getToken(XiasParser.ELSE, 0); }
		public IfStatementContext(Simple_embedded_statementContext ctx) { copyFrom(ctx); }
	}
	public static class ReturnStatementContext extends Simple_embedded_statementContext {
		public TerminalNode RETURN() { return getToken(XiasParser.RETURN, 0); }
		public TerminalNode SEMICOLON() { return getToken(XiasParser.SEMICOLON, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public ReturnStatementContext(Simple_embedded_statementContext ctx) { copyFrom(ctx); }
	}
	public static class GotoStatementContext extends Simple_embedded_statementContext {
		public TerminalNode GOTO() { return getToken(XiasParser.GOTO, 0); }
		public TerminalNode SEMICOLON() { return getToken(XiasParser.SEMICOLON, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode CASE() { return getToken(XiasParser.CASE, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode DEFAULT() { return getToken(XiasParser.DEFAULT, 0); }
		public GotoStatementContext(Simple_embedded_statementContext ctx) { copyFrom(ctx); }
	}
	public static class SwitchStatementContext extends Simple_embedded_statementContext {
		public TerminalNode SWITCH() { return getToken(XiasParser.SWITCH, 0); }
		public TerminalNode OPEN_PARENS() { return getToken(XiasParser.OPEN_PARENS, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode CLOSE_PARENS() { return getToken(XiasParser.CLOSE_PARENS, 0); }
		public TerminalNode OPEN_BRACE() { return getToken(XiasParser.OPEN_BRACE, 0); }
		public TerminalNode CLOSE_BRACE() { return getToken(XiasParser.CLOSE_BRACE, 0); }
		public List<Switch_sectionContext> switch_section() {
			return getRuleContexts(Switch_sectionContext.class);
		}
		public Switch_sectionContext switch_section(int i) {
			return getRuleContext(Switch_sectionContext.class,i);
		}
		public SwitchStatementContext(Simple_embedded_statementContext ctx) { copyFrom(ctx); }
	}
	public static class WhileStatementContext extends Simple_embedded_statementContext {
		public TerminalNode WHILE() { return getToken(XiasParser.WHILE, 0); }
		public TerminalNode OPEN_PARENS() { return getToken(XiasParser.OPEN_PARENS, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode CLOSE_PARENS() { return getToken(XiasParser.CLOSE_PARENS, 0); }
		public Embedded_statementContext embedded_statement() {
			return getRuleContext(Embedded_statementContext.class,0);
		}
		public WhileStatementContext(Simple_embedded_statementContext ctx) { copyFrom(ctx); }
	}
	public static class DoStatementContext extends Simple_embedded_statementContext {
		public TerminalNode DO() { return getToken(XiasParser.DO, 0); }
		public Embedded_statementContext embedded_statement() {
			return getRuleContext(Embedded_statementContext.class,0);
		}
		public TerminalNode WHILE() { return getToken(XiasParser.WHILE, 0); }
		public TerminalNode OPEN_PARENS() { return getToken(XiasParser.OPEN_PARENS, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode CLOSE_PARENS() { return getToken(XiasParser.CLOSE_PARENS, 0); }
		public TerminalNode SEMICOLON() { return getToken(XiasParser.SEMICOLON, 0); }
		public DoStatementContext(Simple_embedded_statementContext ctx) { copyFrom(ctx); }
	}
	public static class ForeachStatementContext extends Simple_embedded_statementContext {
		public TerminalNode FOREACH() { return getToken(XiasParser.FOREACH, 0); }
		public TerminalNode OPEN_PARENS() { return getToken(XiasParser.OPEN_PARENS, 0); }
		public Local_variable_typeContext local_variable_type() {
			return getRuleContext(Local_variable_typeContext.class,0);
		}
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode IN() { return getToken(XiasParser.IN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode CLOSE_PARENS() { return getToken(XiasParser.CLOSE_PARENS, 0); }
		public Embedded_statementContext embedded_statement() {
			return getRuleContext(Embedded_statementContext.class,0);
		}
		public ForeachStatementContext(Simple_embedded_statementContext ctx) { copyFrom(ctx); }
	}
	public static class ExpressionStatementContext extends Simple_embedded_statementContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(XiasParser.SEMICOLON, 0); }
		public ExpressionStatementContext(Simple_embedded_statementContext ctx) { copyFrom(ctx); }
	}
	public static class ContinueStatementContext extends Simple_embedded_statementContext {
		public TerminalNode CONTINUE() { return getToken(XiasParser.CONTINUE, 0); }
		public TerminalNode SEMICOLON() { return getToken(XiasParser.SEMICOLON, 0); }
		public ContinueStatementContext(Simple_embedded_statementContext ctx) { copyFrom(ctx); }
	}
	public static class UsingStatementContext extends Simple_embedded_statementContext {
		public TerminalNode USING() { return getToken(XiasParser.USING, 0); }
		public TerminalNode OPEN_PARENS() { return getToken(XiasParser.OPEN_PARENS, 0); }
		public Resource_acquisitionContext resource_acquisition() {
			return getRuleContext(Resource_acquisitionContext.class,0);
		}
		public TerminalNode CLOSE_PARENS() { return getToken(XiasParser.CLOSE_PARENS, 0); }
		public Embedded_statementContext embedded_statement() {
			return getRuleContext(Embedded_statementContext.class,0);
		}
		public UsingStatementContext(Simple_embedded_statementContext ctx) { copyFrom(ctx); }
	}

	public final Simple_embedded_statementContext simple_embedded_statement() throws RecognitionException {
		Simple_embedded_statementContext _localctx = new Simple_embedded_statementContext(_ctx, getState());
		enterRule(_localctx, 122, RULE_simple_embedded_statement);
		int _la;
		try {
			setState(1030);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case SEMICOLON:
				_localctx = new TheEmptyStatementContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(929);
				match(SEMICOLON);
				}
				break;
			case BASE:
			case BOOL:
			case CHAR:
			case DEFAULT:
			case DOUBLE:
			case FALSE:
			case FLOAT:
			case GET:
			case INT:
			case NAMEOF:
			case NEW:
			case NULL_:
			case OBJECT:
			case REF:
			case SET:
			case SIZEOF:
			case STRING:
			case THIS:
			case TRUE:
			case TYPEOF:
			case UINT:
			case VAR:
			case WHEN:
			case WHERE:
			case IDENTIFIER:
			case LITERAL_ACCESS:
			case INTEGER_LITERAL:
			case HEX_INTEGER_LITERAL:
			case REAL_LITERAL:
			case CHARACTER_LITERAL:
			case REGULAR_STRING:
			case VERBATIUM_STRING:
			case OPEN_PARENS:
			case PLUS:
			case MINUS:
			case STAR:
			case BANG:
			case TILDE:
			case OP_INC:
			case OP_DEC:
				_localctx = new ExpressionStatementContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(930);
				expression();
				setState(931);
				match(SEMICOLON);
				}
				break;
			case IF:
				_localctx = new IfStatementContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(933);
				match(IF);
				setState(934);
				match(OPEN_PARENS);
				setState(935);
				expression();
				setState(936);
				match(CLOSE_PARENS);
				setState(937);
				if_body();
				setState(940);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,92,_ctx) ) {
				case 1:
					{
					setState(938);
					match(ELSE);
					setState(939);
					if_body();
					}
					break;
				}
				}
				break;
			case SWITCH:
				_localctx = new SwitchStatementContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(942);
				match(SWITCH);
				setState(943);
				match(OPEN_PARENS);
				setState(944);
				expression();
				setState(945);
				match(CLOSE_PARENS);
				setState(946);
				match(OPEN_BRACE);
				setState(950);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==CASE || _la==DEFAULT) {
					{
					{
					setState(947);
					switch_section();
					}
					}
					setState(952);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(953);
				match(CLOSE_BRACE);
				}
				break;
			case WHILE:
				_localctx = new WhileStatementContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(955);
				match(WHILE);
				setState(956);
				match(OPEN_PARENS);
				setState(957);
				expression();
				setState(958);
				match(CLOSE_PARENS);
				setState(959);
				embedded_statement();
				}
				break;
			case DO:
				_localctx = new DoStatementContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(961);
				match(DO);
				setState(962);
				embedded_statement();
				setState(963);
				match(WHILE);
				setState(964);
				match(OPEN_PARENS);
				setState(965);
				expression();
				setState(966);
				match(CLOSE_PARENS);
				setState(967);
				match(SEMICOLON);
				}
				break;
			case FOR:
				_localctx = new ForStatementContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(969);
				match(FOR);
				setState(970);
				match(OPEN_PARENS);
				setState(972);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << BASE) | (1L << BOOL) | (1L << CHAR) | (1L << DEFAULT) | (1L << DOUBLE) | (1L << FALSE) | (1L << FLOAT) | (1L << GET) | (1L << INT) | (1L << NAMEOF) | (1L << NEW) | (1L << NULL_) | (1L << OBJECT) | (1L << REF) | (1L << SET) | (1L << SIZEOF) | (1L << STRING) | (1L << THIS) | (1L << TRUE) | (1L << TYPEOF) | (1L << UINT) | (1L << USING))) != 0) || ((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & ((1L << (VAR - 64)) | (1L << (VOID - 64)) | (1L << (WHEN - 64)) | (1L << (WHERE - 64)) | (1L << (IDENTIFIER - 64)) | (1L << (LITERAL_ACCESS - 64)) | (1L << (INTEGER_LITERAL - 64)) | (1L << (HEX_INTEGER_LITERAL - 64)) | (1L << (REAL_LITERAL - 64)) | (1L << (CHARACTER_LITERAL - 64)) | (1L << (REGULAR_STRING - 64)) | (1L << (VERBATIUM_STRING - 64)) | (1L << (OPEN_PARENS - 64)) | (1L << (PLUS - 64)) | (1L << (MINUS - 64)) | (1L << (STAR - 64)) | (1L << (BANG - 64)) | (1L << (TILDE - 64)) | (1L << (OP_INC - 64)) | (1L << (OP_DEC - 64)))) != 0)) {
					{
					setState(971);
					for_initializer();
					}
				}

				setState(974);
				match(SEMICOLON);
				setState(976);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << BASE) | (1L << BOOL) | (1L << CHAR) | (1L << DEFAULT) | (1L << DOUBLE) | (1L << FALSE) | (1L << FLOAT) | (1L << GET) | (1L << INT) | (1L << NAMEOF) | (1L << NEW) | (1L << NULL_) | (1L << OBJECT) | (1L << REF) | (1L << SET) | (1L << SIZEOF) | (1L << STRING) | (1L << THIS) | (1L << TRUE) | (1L << TYPEOF) | (1L << UINT))) != 0) || ((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & ((1L << (VAR - 64)) | (1L << (WHEN - 64)) | (1L << (WHERE - 64)) | (1L << (IDENTIFIER - 64)) | (1L << (LITERAL_ACCESS - 64)) | (1L << (INTEGER_LITERAL - 64)) | (1L << (HEX_INTEGER_LITERAL - 64)) | (1L << (REAL_LITERAL - 64)) | (1L << (CHARACTER_LITERAL - 64)) | (1L << (REGULAR_STRING - 64)) | (1L << (VERBATIUM_STRING - 64)) | (1L << (OPEN_PARENS - 64)) | (1L << (PLUS - 64)) | (1L << (MINUS - 64)) | (1L << (STAR - 64)) | (1L << (BANG - 64)) | (1L << (TILDE - 64)) | (1L << (OP_INC - 64)) | (1L << (OP_DEC - 64)))) != 0)) {
					{
					setState(975);
					expression();
					}
				}

				setState(978);
				match(SEMICOLON);
				setState(980);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << BASE) | (1L << BOOL) | (1L << CHAR) | (1L << DEFAULT) | (1L << DOUBLE) | (1L << FALSE) | (1L << FLOAT) | (1L << GET) | (1L << INT) | (1L << NAMEOF) | (1L << NEW) | (1L << NULL_) | (1L << OBJECT) | (1L << REF) | (1L << SET) | (1L << SIZEOF) | (1L << STRING) | (1L << THIS) | (1L << TRUE) | (1L << TYPEOF) | (1L << UINT))) != 0) || ((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & ((1L << (VAR - 64)) | (1L << (WHEN - 64)) | (1L << (WHERE - 64)) | (1L << (IDENTIFIER - 64)) | (1L << (LITERAL_ACCESS - 64)) | (1L << (INTEGER_LITERAL - 64)) | (1L << (HEX_INTEGER_LITERAL - 64)) | (1L << (REAL_LITERAL - 64)) | (1L << (CHARACTER_LITERAL - 64)) | (1L << (REGULAR_STRING - 64)) | (1L << (VERBATIUM_STRING - 64)) | (1L << (OPEN_PARENS - 64)) | (1L << (PLUS - 64)) | (1L << (MINUS - 64)) | (1L << (STAR - 64)) | (1L << (BANG - 64)) | (1L << (TILDE - 64)) | (1L << (OP_INC - 64)) | (1L << (OP_DEC - 64)))) != 0)) {
					{
					setState(979);
					for_iterator();
					}
				}

				setState(982);
				match(CLOSE_PARENS);
				setState(983);
				embedded_statement();
				}
				break;
			case FOREACH:
				_localctx = new ForeachStatementContext(_localctx);
				enterOuterAlt(_localctx, 8);
				{
				setState(984);
				match(FOREACH);
				setState(985);
				match(OPEN_PARENS);
				setState(986);
				local_variable_type();
				setState(987);
				identifier();
				setState(988);
				match(IN);
				setState(989);
				expression();
				setState(990);
				match(CLOSE_PARENS);
				setState(991);
				embedded_statement();
				}
				break;
			case BREAK:
				_localctx = new BreakStatementContext(_localctx);
				enterOuterAlt(_localctx, 9);
				{
				setState(993);
				match(BREAK);
				setState(994);
				match(SEMICOLON);
				}
				break;
			case CONTINUE:
				_localctx = new ContinueStatementContext(_localctx);
				enterOuterAlt(_localctx, 10);
				{
				setState(995);
				match(CONTINUE);
				setState(996);
				match(SEMICOLON);
				}
				break;
			case GOTO:
				_localctx = new GotoStatementContext(_localctx);
				enterOuterAlt(_localctx, 11);
				{
				setState(997);
				match(GOTO);
				setState(1002);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case GET:
				case NAMEOF:
				case SET:
				case VAR:
				case WHEN:
				case WHERE:
				case IDENTIFIER:
					{
					setState(998);
					identifier();
					}
					break;
				case CASE:
					{
					setState(999);
					match(CASE);
					setState(1000);
					expression();
					}
					break;
				case DEFAULT:
					{
					setState(1001);
					match(DEFAULT);
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(1004);
				match(SEMICOLON);
				}
				break;
			case RETURN:
				_localctx = new ReturnStatementContext(_localctx);
				enterOuterAlt(_localctx, 12);
				{
				setState(1005);
				match(RETURN);
				setState(1007);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << BASE) | (1L << BOOL) | (1L << CHAR) | (1L << DEFAULT) | (1L << DOUBLE) | (1L << FALSE) | (1L << FLOAT) | (1L << GET) | (1L << INT) | (1L << NAMEOF) | (1L << NEW) | (1L << NULL_) | (1L << OBJECT) | (1L << REF) | (1L << SET) | (1L << SIZEOF) | (1L << STRING) | (1L << THIS) | (1L << TRUE) | (1L << TYPEOF) | (1L << UINT))) != 0) || ((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & ((1L << (VAR - 64)) | (1L << (WHEN - 64)) | (1L << (WHERE - 64)) | (1L << (IDENTIFIER - 64)) | (1L << (LITERAL_ACCESS - 64)) | (1L << (INTEGER_LITERAL - 64)) | (1L << (HEX_INTEGER_LITERAL - 64)) | (1L << (REAL_LITERAL - 64)) | (1L << (CHARACTER_LITERAL - 64)) | (1L << (REGULAR_STRING - 64)) | (1L << (VERBATIUM_STRING - 64)) | (1L << (OPEN_PARENS - 64)) | (1L << (PLUS - 64)) | (1L << (MINUS - 64)) | (1L << (STAR - 64)) | (1L << (BANG - 64)) | (1L << (TILDE - 64)) | (1L << (OP_INC - 64)) | (1L << (OP_DEC - 64)))) != 0)) {
					{
					setState(1006);
					expression();
					}
				}

				setState(1009);
				match(SEMICOLON);
				}
				break;
			case THROW:
				_localctx = new ThrowStatementContext(_localctx);
				enterOuterAlt(_localctx, 13);
				{
				setState(1010);
				match(THROW);
				setState(1012);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << BASE) | (1L << BOOL) | (1L << CHAR) | (1L << DEFAULT) | (1L << DOUBLE) | (1L << FALSE) | (1L << FLOAT) | (1L << GET) | (1L << INT) | (1L << NAMEOF) | (1L << NEW) | (1L << NULL_) | (1L << OBJECT) | (1L << REF) | (1L << SET) | (1L << SIZEOF) | (1L << STRING) | (1L << THIS) | (1L << TRUE) | (1L << TYPEOF) | (1L << UINT))) != 0) || ((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & ((1L << (VAR - 64)) | (1L << (WHEN - 64)) | (1L << (WHERE - 64)) | (1L << (IDENTIFIER - 64)) | (1L << (LITERAL_ACCESS - 64)) | (1L << (INTEGER_LITERAL - 64)) | (1L << (HEX_INTEGER_LITERAL - 64)) | (1L << (REAL_LITERAL - 64)) | (1L << (CHARACTER_LITERAL - 64)) | (1L << (REGULAR_STRING - 64)) | (1L << (VERBATIUM_STRING - 64)) | (1L << (OPEN_PARENS - 64)) | (1L << (PLUS - 64)) | (1L << (MINUS - 64)) | (1L << (STAR - 64)) | (1L << (BANG - 64)) | (1L << (TILDE - 64)) | (1L << (OP_INC - 64)) | (1L << (OP_DEC - 64)))) != 0)) {
					{
					setState(1011);
					expression();
					}
				}

				setState(1014);
				match(SEMICOLON);
				}
				break;
			case TRY:
				_localctx = new TryStatementContext(_localctx);
				enterOuterAlt(_localctx, 14);
				{
				setState(1015);
				match(TRY);
				setState(1016);
				block();
				setState(1022);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case CATCH:
					{
					setState(1017);
					catch_clauses();
					setState(1019);
					_errHandler.sync(this);
					_la = _input.LA(1);
					if (_la==FINALLY) {
						{
						setState(1018);
						finally_clause();
						}
					}

					}
					break;
				case FINALLY:
					{
					setState(1021);
					finally_clause();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				break;
			case USING:
				_localctx = new UsingStatementContext(_localctx);
				enterOuterAlt(_localctx, 15);
				{
				setState(1024);
				match(USING);
				setState(1025);
				match(OPEN_PARENS);
				setState(1026);
				resource_acquisition();
				setState(1027);
				match(CLOSE_PARENS);
				setState(1028);
				embedded_statement();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BlockContext extends ParserRuleContext {
		public TerminalNode OPEN_BRACE() { return getToken(XiasParser.OPEN_BRACE, 0); }
		public TerminalNode CLOSE_BRACE() { return getToken(XiasParser.CLOSE_BRACE, 0); }
		public Statement_listContext statement_list() {
			return getRuleContext(Statement_listContext.class,0);
		}
		public BlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_block; }
	}

	public final BlockContext block() throws RecognitionException {
		BlockContext _localctx = new BlockContext(_ctx, getState());
		enterRule(_localctx, 124, RULE_block);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1032);
			match(OPEN_BRACE);
			setState(1034);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << BASE) | (1L << BOOL) | (1L << BREAK) | (1L << CHAR) | (1L << CONST) | (1L << CONTINUE) | (1L << DEFAULT) | (1L << DO) | (1L << DOUBLE) | (1L << FALSE) | (1L << FLOAT) | (1L << FOR) | (1L << FOREACH) | (1L << GET) | (1L << GOTO) | (1L << IF) | (1L << INT) | (1L << NAMEOF) | (1L << NEW) | (1L << NULL_) | (1L << OBJECT) | (1L << REF) | (1L << RETURN) | (1L << SET) | (1L << SIZEOF) | (1L << STRING) | (1L << SWITCH) | (1L << THIS) | (1L << THROW) | (1L << TRUE) | (1L << TRY) | (1L << TYPEOF) | (1L << UINT) | (1L << USING))) != 0) || ((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & ((1L << (VAR - 64)) | (1L << (VOID - 64)) | (1L << (WHEN - 64)) | (1L << (WHERE - 64)) | (1L << (WHILE - 64)) | (1L << (IDENTIFIER - 64)) | (1L << (LITERAL_ACCESS - 64)) | (1L << (INTEGER_LITERAL - 64)) | (1L << (HEX_INTEGER_LITERAL - 64)) | (1L << (REAL_LITERAL - 64)) | (1L << (CHARACTER_LITERAL - 64)) | (1L << (REGULAR_STRING - 64)) | (1L << (VERBATIUM_STRING - 64)) | (1L << (OPEN_BRACE - 64)) | (1L << (OPEN_PARENS - 64)) | (1L << (SEMICOLON - 64)) | (1L << (PLUS - 64)) | (1L << (MINUS - 64)) | (1L << (STAR - 64)) | (1L << (BANG - 64)) | (1L << (TILDE - 64)) | (1L << (OP_INC - 64)) | (1L << (OP_DEC - 64)))) != 0)) {
				{
				setState(1033);
				statement_list();
				}
			}

			setState(1036);
			match(CLOSE_BRACE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Local_variable_declarationContext extends ParserRuleContext {
		public Local_variable_typeContext local_variable_type() {
			return getRuleContext(Local_variable_typeContext.class,0);
		}
		public List<Local_variable_declaratorContext> local_variable_declarator() {
			return getRuleContexts(Local_variable_declaratorContext.class);
		}
		public Local_variable_declaratorContext local_variable_declarator(int i) {
			return getRuleContext(Local_variable_declaratorContext.class,i);
		}
		public TerminalNode USING() { return getToken(XiasParser.USING, 0); }
		public TerminalNode REF() { return getToken(XiasParser.REF, 0); }
		public TerminalNode READONLY() { return getToken(XiasParser.READONLY, 0); }
		public List<TerminalNode> COMMA() { return getTokens(XiasParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(XiasParser.COMMA, i);
		}
		public Local_variable_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_local_variable_declaration; }
	}

	public final Local_variable_declarationContext local_variable_declaration() throws RecognitionException {
		Local_variable_declarationContext _localctx = new Local_variable_declarationContext(_ctx, getState());
		enterRule(_localctx, 126, RULE_local_variable_declaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1042);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,104,_ctx) ) {
			case 1:
				{
				setState(1038);
				match(USING);
				}
				break;
			case 2:
				{
				setState(1039);
				match(REF);
				}
				break;
			case 3:
				{
				setState(1040);
				match(REF);
				setState(1041);
				match(READONLY);
				}
				break;
			}
			setState(1044);
			local_variable_type();
			setState(1045);
			local_variable_declarator();
			setState(1050);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(1046);
				match(COMMA);
				setState(1047);
				local_variable_declarator();
				}
				}
				setState(1052);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Local_variable_typeContext extends ParserRuleContext {
		public TerminalNode VAR() { return getToken(XiasParser.VAR, 0); }
		public Type_Context type_() {
			return getRuleContext(Type_Context.class,0);
		}
		public Local_variable_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_local_variable_type; }
	}

	public final Local_variable_typeContext local_variable_type() throws RecognitionException {
		Local_variable_typeContext _localctx = new Local_variable_typeContext(_ctx, getState());
		enterRule(_localctx, 128, RULE_local_variable_type);
		try {
			setState(1055);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,106,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(1053);
				match(VAR);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(1054);
				type_();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Local_variable_declaratorContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode ASSIGNMENT() { return getToken(XiasParser.ASSIGNMENT, 0); }
		public Local_variable_initializerContext local_variable_initializer() {
			return getRuleContext(Local_variable_initializerContext.class,0);
		}
		public TerminalNode REF() { return getToken(XiasParser.REF, 0); }
		public Local_variable_declaratorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_local_variable_declarator; }
	}

	public final Local_variable_declaratorContext local_variable_declarator() throws RecognitionException {
		Local_variable_declaratorContext _localctx = new Local_variable_declaratorContext(_ctx, getState());
		enterRule(_localctx, 130, RULE_local_variable_declarator);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1057);
			identifier();
			setState(1063);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==ASSIGNMENT) {
				{
				setState(1058);
				match(ASSIGNMENT);
				setState(1060);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,107,_ctx) ) {
				case 1:
					{
					setState(1059);
					match(REF);
					}
					break;
				}
				setState(1062);
				local_variable_initializer();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Local_variable_initializerContext extends ParserRuleContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Array_initializerContext array_initializer() {
			return getRuleContext(Array_initializerContext.class,0);
		}
		public Local_variable_initializerContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_local_variable_initializer; }
	}

	public final Local_variable_initializerContext local_variable_initializer() throws RecognitionException {
		Local_variable_initializerContext _localctx = new Local_variable_initializerContext(_ctx, getState());
		enterRule(_localctx, 132, RULE_local_variable_initializer);
		try {
			setState(1067);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case BASE:
			case BOOL:
			case CHAR:
			case DEFAULT:
			case DOUBLE:
			case FALSE:
			case FLOAT:
			case GET:
			case INT:
			case NAMEOF:
			case NEW:
			case NULL_:
			case OBJECT:
			case REF:
			case SET:
			case SIZEOF:
			case STRING:
			case THIS:
			case TRUE:
			case TYPEOF:
			case UINT:
			case VAR:
			case WHEN:
			case WHERE:
			case IDENTIFIER:
			case LITERAL_ACCESS:
			case INTEGER_LITERAL:
			case HEX_INTEGER_LITERAL:
			case REAL_LITERAL:
			case CHARACTER_LITERAL:
			case REGULAR_STRING:
			case VERBATIUM_STRING:
			case OPEN_PARENS:
			case PLUS:
			case MINUS:
			case STAR:
			case BANG:
			case TILDE:
			case OP_INC:
			case OP_DEC:
				enterOuterAlt(_localctx, 1);
				{
				setState(1065);
				expression();
				}
				break;
			case OPEN_BRACE:
				enterOuterAlt(_localctx, 2);
				{
				setState(1066);
				array_initializer();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Local_constant_declarationContext extends ParserRuleContext {
		public TerminalNode CONST() { return getToken(XiasParser.CONST, 0); }
		public Type_Context type_() {
			return getRuleContext(Type_Context.class,0);
		}
		public Constant_declaratorsContext constant_declarators() {
			return getRuleContext(Constant_declaratorsContext.class,0);
		}
		public Local_constant_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_local_constant_declaration; }
	}

	public final Local_constant_declarationContext local_constant_declaration() throws RecognitionException {
		Local_constant_declarationContext _localctx = new Local_constant_declarationContext(_ctx, getState());
		enterRule(_localctx, 134, RULE_local_constant_declaration);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1069);
			match(CONST);
			setState(1070);
			type_();
			setState(1071);
			constant_declarators();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class If_bodyContext extends ParserRuleContext {
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public Simple_embedded_statementContext simple_embedded_statement() {
			return getRuleContext(Simple_embedded_statementContext.class,0);
		}
		public If_bodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_if_body; }
	}

	public final If_bodyContext if_body() throws RecognitionException {
		If_bodyContext _localctx = new If_bodyContext(_ctx, getState());
		enterRule(_localctx, 136, RULE_if_body);
		try {
			setState(1075);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case OPEN_BRACE:
				enterOuterAlt(_localctx, 1);
				{
				setState(1073);
				block();
				}
				break;
			case BASE:
			case BOOL:
			case BREAK:
			case CHAR:
			case CONTINUE:
			case DEFAULT:
			case DO:
			case DOUBLE:
			case FALSE:
			case FLOAT:
			case FOR:
			case FOREACH:
			case GET:
			case GOTO:
			case IF:
			case INT:
			case NAMEOF:
			case NEW:
			case NULL_:
			case OBJECT:
			case REF:
			case RETURN:
			case SET:
			case SIZEOF:
			case STRING:
			case SWITCH:
			case THIS:
			case THROW:
			case TRUE:
			case TRY:
			case TYPEOF:
			case UINT:
			case USING:
			case VAR:
			case WHEN:
			case WHERE:
			case WHILE:
			case IDENTIFIER:
			case LITERAL_ACCESS:
			case INTEGER_LITERAL:
			case HEX_INTEGER_LITERAL:
			case REAL_LITERAL:
			case CHARACTER_LITERAL:
			case REGULAR_STRING:
			case VERBATIUM_STRING:
			case OPEN_PARENS:
			case SEMICOLON:
			case PLUS:
			case MINUS:
			case STAR:
			case BANG:
			case TILDE:
			case OP_INC:
			case OP_DEC:
				enterOuterAlt(_localctx, 2);
				{
				setState(1074);
				simple_embedded_statement();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Switch_sectionContext extends ParserRuleContext {
		public Statement_listContext statement_list() {
			return getRuleContext(Statement_listContext.class,0);
		}
		public List<Switch_labelContext> switch_label() {
			return getRuleContexts(Switch_labelContext.class);
		}
		public Switch_labelContext switch_label(int i) {
			return getRuleContext(Switch_labelContext.class,i);
		}
		public Switch_sectionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_switch_section; }
	}

	public final Switch_sectionContext switch_section() throws RecognitionException {
		Switch_sectionContext _localctx = new Switch_sectionContext(_ctx, getState());
		enterRule(_localctx, 138, RULE_switch_section);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(1078); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(1077);
					switch_label();
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(1080); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,111,_ctx);
			} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
			setState(1082);
			statement_list();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Switch_labelContext extends ParserRuleContext {
		public TerminalNode CASE() { return getToken(XiasParser.CASE, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode COLON() { return getToken(XiasParser.COLON, 0); }
		public Case_guardContext case_guard() {
			return getRuleContext(Case_guardContext.class,0);
		}
		public TerminalNode DEFAULT() { return getToken(XiasParser.DEFAULT, 0); }
		public Switch_labelContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_switch_label; }
	}

	public final Switch_labelContext switch_label() throws RecognitionException {
		Switch_labelContext _localctx = new Switch_labelContext(_ctx, getState());
		enterRule(_localctx, 140, RULE_switch_label);
		int _la;
		try {
			setState(1093);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case CASE:
				enterOuterAlt(_localctx, 1);
				{
				setState(1084);
				match(CASE);
				setState(1085);
				expression();
				setState(1087);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==WHEN) {
					{
					setState(1086);
					case_guard();
					}
				}

				setState(1089);
				match(COLON);
				}
				break;
			case DEFAULT:
				enterOuterAlt(_localctx, 2);
				{
				setState(1091);
				match(DEFAULT);
				setState(1092);
				match(COLON);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Case_guardContext extends ParserRuleContext {
		public TerminalNode WHEN() { return getToken(XiasParser.WHEN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Case_guardContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_case_guard; }
	}

	public final Case_guardContext case_guard() throws RecognitionException {
		Case_guardContext _localctx = new Case_guardContext(_ctx, getState());
		enterRule(_localctx, 142, RULE_case_guard);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1095);
			match(WHEN);
			setState(1096);
			expression();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Statement_listContext extends ParserRuleContext {
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public Statement_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement_list; }
	}

	public final Statement_listContext statement_list() throws RecognitionException {
		Statement_listContext _localctx = new Statement_listContext(_ctx, getState());
		enterRule(_localctx, 144, RULE_statement_list);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(1099); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(1098);
					statement();
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(1101); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,114,_ctx);
			} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class For_initializerContext extends ParserRuleContext {
		public Local_variable_declarationContext local_variable_declaration() {
			return getRuleContext(Local_variable_declarationContext.class,0);
		}
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(XiasParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(XiasParser.COMMA, i);
		}
		public For_initializerContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_for_initializer; }
	}

	public final For_initializerContext for_initializer() throws RecognitionException {
		For_initializerContext _localctx = new For_initializerContext(_ctx, getState());
		enterRule(_localctx, 146, RULE_for_initializer);
		int _la;
		try {
			setState(1112);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,116,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(1103);
				local_variable_declaration();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(1104);
				expression();
				setState(1109);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMMA) {
					{
					{
					setState(1105);
					match(COMMA);
					setState(1106);
					expression();
					}
					}
					setState(1111);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class For_iteratorContext extends ParserRuleContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(XiasParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(XiasParser.COMMA, i);
		}
		public For_iteratorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_for_iterator; }
	}

	public final For_iteratorContext for_iterator() throws RecognitionException {
		For_iteratorContext _localctx = new For_iteratorContext(_ctx, getState());
		enterRule(_localctx, 148, RULE_for_iterator);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1114);
			expression();
			setState(1119);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(1115);
				match(COMMA);
				setState(1116);
				expression();
				}
				}
				setState(1121);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Catch_clausesContext extends ParserRuleContext {
		public List<Specific_catch_clauseContext> specific_catch_clause() {
			return getRuleContexts(Specific_catch_clauseContext.class);
		}
		public Specific_catch_clauseContext specific_catch_clause(int i) {
			return getRuleContext(Specific_catch_clauseContext.class,i);
		}
		public General_catch_clauseContext general_catch_clause() {
			return getRuleContext(General_catch_clauseContext.class,0);
		}
		public Catch_clausesContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_catch_clauses; }
	}

	public final Catch_clausesContext catch_clauses() throws RecognitionException {
		Catch_clausesContext _localctx = new Catch_clausesContext(_ctx, getState());
		enterRule(_localctx, 150, RULE_catch_clauses);
		int _la;
		try {
			int _alt;
			setState(1133);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,120,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(1122);
				specific_catch_clause();
				setState(1126);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,118,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(1123);
						specific_catch_clause();
						}
						} 
					}
					setState(1128);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,118,_ctx);
				}
				setState(1130);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==CATCH) {
					{
					setState(1129);
					general_catch_clause();
					}
				}

				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(1132);
				general_catch_clause();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Specific_catch_clauseContext extends ParserRuleContext {
		public TerminalNode CATCH() { return getToken(XiasParser.CATCH, 0); }
		public TerminalNode OPEN_PARENS() { return getToken(XiasParser.OPEN_PARENS, 0); }
		public Class_typeContext class_type() {
			return getRuleContext(Class_typeContext.class,0);
		}
		public TerminalNode CLOSE_PARENS() { return getToken(XiasParser.CLOSE_PARENS, 0); }
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public Exception_filterContext exception_filter() {
			return getRuleContext(Exception_filterContext.class,0);
		}
		public Specific_catch_clauseContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_specific_catch_clause; }
	}

	public final Specific_catch_clauseContext specific_catch_clause() throws RecognitionException {
		Specific_catch_clauseContext _localctx = new Specific_catch_clauseContext(_ctx, getState());
		enterRule(_localctx, 152, RULE_specific_catch_clause);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1135);
			match(CATCH);
			setState(1136);
			match(OPEN_PARENS);
			setState(1137);
			class_type();
			setState(1139);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (((((_la - 28)) & ~0x3f) == 0 && ((1L << (_la - 28)) & ((1L << (GET - 28)) | (1L << (NAMEOF - 28)) | (1L << (SET - 28)) | (1L << (VAR - 28)) | (1L << (WHEN - 28)) | (1L << (WHERE - 28)) | (1L << (IDENTIFIER - 28)))) != 0)) {
				{
				setState(1138);
				identifier();
				}
			}

			setState(1141);
			match(CLOSE_PARENS);
			setState(1143);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WHEN) {
				{
				setState(1142);
				exception_filter();
				}
			}

			setState(1145);
			block();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class General_catch_clauseContext extends ParserRuleContext {
		public TerminalNode CATCH() { return getToken(XiasParser.CATCH, 0); }
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public Exception_filterContext exception_filter() {
			return getRuleContext(Exception_filterContext.class,0);
		}
		public General_catch_clauseContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_general_catch_clause; }
	}

	public final General_catch_clauseContext general_catch_clause() throws RecognitionException {
		General_catch_clauseContext _localctx = new General_catch_clauseContext(_ctx, getState());
		enterRule(_localctx, 154, RULE_general_catch_clause);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1147);
			match(CATCH);
			setState(1149);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WHEN) {
				{
				setState(1148);
				exception_filter();
				}
			}

			setState(1151);
			block();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Exception_filterContext extends ParserRuleContext {
		public TerminalNode WHEN() { return getToken(XiasParser.WHEN, 0); }
		public TerminalNode OPEN_PARENS() { return getToken(XiasParser.OPEN_PARENS, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode CLOSE_PARENS() { return getToken(XiasParser.CLOSE_PARENS, 0); }
		public Exception_filterContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_exception_filter; }
	}

	public final Exception_filterContext exception_filter() throws RecognitionException {
		Exception_filterContext _localctx = new Exception_filterContext(_ctx, getState());
		enterRule(_localctx, 156, RULE_exception_filter);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1153);
			match(WHEN);
			setState(1154);
			match(OPEN_PARENS);
			setState(1155);
			expression();
			setState(1156);
			match(CLOSE_PARENS);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Finally_clauseContext extends ParserRuleContext {
		public TerminalNode FINALLY() { return getToken(XiasParser.FINALLY, 0); }
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public Finally_clauseContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_finally_clause; }
	}

	public final Finally_clauseContext finally_clause() throws RecognitionException {
		Finally_clauseContext _localctx = new Finally_clauseContext(_ctx, getState());
		enterRule(_localctx, 158, RULE_finally_clause);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1158);
			match(FINALLY);
			setState(1159);
			block();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Resource_acquisitionContext extends ParserRuleContext {
		public Local_variable_declarationContext local_variable_declaration() {
			return getRuleContext(Local_variable_declarationContext.class,0);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Resource_acquisitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_resource_acquisition; }
	}

	public final Resource_acquisitionContext resource_acquisition() throws RecognitionException {
		Resource_acquisitionContext _localctx = new Resource_acquisitionContext(_ctx, getState());
		enterRule(_localctx, 160, RULE_resource_acquisition);
		try {
			setState(1163);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,124,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(1161);
				local_variable_declaration();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(1162);
				expression();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Namespace_declarationContext extends ParserRuleContext {
		public Qualified_identifierContext qi;
		public TerminalNode NAMESPACE() { return getToken(XiasParser.NAMESPACE, 0); }
		public Namespace_bodyContext namespace_body() {
			return getRuleContext(Namespace_bodyContext.class,0);
		}
		public Qualified_identifierContext qualified_identifier() {
			return getRuleContext(Qualified_identifierContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(XiasParser.SEMICOLON, 0); }
		public Namespace_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_namespace_declaration; }
	}

	public final Namespace_declarationContext namespace_declaration() throws RecognitionException {
		Namespace_declarationContext _localctx = new Namespace_declarationContext(_ctx, getState());
		enterRule(_localctx, 162, RULE_namespace_declaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1165);
			match(NAMESPACE);
			setState(1166);
			((Namespace_declarationContext)_localctx).qi = qualified_identifier();
			setState(1167);
			namespace_body();
			setState(1169);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==SEMICOLON) {
				{
				setState(1168);
				match(SEMICOLON);
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Qualified_identifierContext extends ParserRuleContext {
		public List<IdentifierContext> identifier() {
			return getRuleContexts(IdentifierContext.class);
		}
		public IdentifierContext identifier(int i) {
			return getRuleContext(IdentifierContext.class,i);
		}
		public List<TerminalNode> DOT() { return getTokens(XiasParser.DOT); }
		public TerminalNode DOT(int i) {
			return getToken(XiasParser.DOT, i);
		}
		public Qualified_identifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_qualified_identifier; }
	}

	public final Qualified_identifierContext qualified_identifier() throws RecognitionException {
		Qualified_identifierContext _localctx = new Qualified_identifierContext(_ctx, getState());
		enterRule(_localctx, 164, RULE_qualified_identifier);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1171);
			identifier();
			setState(1176);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==DOT) {
				{
				{
				setState(1172);
				match(DOT);
				setState(1173);
				identifier();
				}
				}
				setState(1178);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Namespace_bodyContext extends ParserRuleContext {
		public TerminalNode OPEN_BRACE() { return getToken(XiasParser.OPEN_BRACE, 0); }
		public TerminalNode CLOSE_BRACE() { return getToken(XiasParser.CLOSE_BRACE, 0); }
		public Using_directivesContext using_directives() {
			return getRuleContext(Using_directivesContext.class,0);
		}
		public Namespace_member_declarationsContext namespace_member_declarations() {
			return getRuleContext(Namespace_member_declarationsContext.class,0);
		}
		public Namespace_bodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_namespace_body; }
	}

	public final Namespace_bodyContext namespace_body() throws RecognitionException {
		Namespace_bodyContext _localctx = new Namespace_bodyContext(_ctx, getState());
		enterRule(_localctx, 166, RULE_namespace_body);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1179);
			match(OPEN_BRACE);
			setState(1181);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==USING) {
				{
				setState(1180);
				using_directives();
				}
			}

			setState(1184);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (((((_la - 6)) & ~0x3f) == 0 && ((1L << (_la - 6)) & ((1L << (ABSTRACT - 6)) | (1L << (CLASS - 6)) | (1L << (ENUM - 6)) | (1L << (INTERFACE - 6)) | (1L << (INTERNAL - 6)) | (1L << (NAMESPACE - 6)) | (1L << (NEW - 6)) | (1L << (OVERRIDE - 6)) | (1L << (PRIVATE - 6)) | (1L << (PROTECTED - 6)) | (1L << (PUBLIC - 6)) | (1L << (READONLY - 6)) | (1L << (SEALED - 6)) | (1L << (STATIC - 6)) | (1L << (VIRTUAL - 6)))) != 0)) {
				{
				setState(1183);
				namespace_member_declarations();
				}
			}

			setState(1186);
			match(CLOSE_BRACE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Using_directivesContext extends ParserRuleContext {
		public List<Using_directiveContext> using_directive() {
			return getRuleContexts(Using_directiveContext.class);
		}
		public Using_directiveContext using_directive(int i) {
			return getRuleContext(Using_directiveContext.class,i);
		}
		public Using_directivesContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_using_directives; }
	}

	public final Using_directivesContext using_directives() throws RecognitionException {
		Using_directivesContext _localctx = new Using_directivesContext(_ctx, getState());
		enterRule(_localctx, 168, RULE_using_directives);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1189); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(1188);
				using_directive();
				}
				}
				setState(1191); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==USING );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Using_directiveContext extends ParserRuleContext {
		public Using_directiveContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_using_directive; }
	 
		public Using_directiveContext() { }
		public void copyFrom(Using_directiveContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class UsingAliasDirectiveContext extends Using_directiveContext {
		public TerminalNode USING() { return getToken(XiasParser.USING, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode ASSIGNMENT() { return getToken(XiasParser.ASSIGNMENT, 0); }
		public Namespace_or_type_nameContext namespace_or_type_name() {
			return getRuleContext(Namespace_or_type_nameContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(XiasParser.SEMICOLON, 0); }
		public UsingAliasDirectiveContext(Using_directiveContext ctx) { copyFrom(ctx); }
	}
	public static class UsingNamespaceDirectiveContext extends Using_directiveContext {
		public TerminalNode USING() { return getToken(XiasParser.USING, 0); }
		public Namespace_or_type_nameContext namespace_or_type_name() {
			return getRuleContext(Namespace_or_type_nameContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(XiasParser.SEMICOLON, 0); }
		public UsingNamespaceDirectiveContext(Using_directiveContext ctx) { copyFrom(ctx); }
	}
	public static class UsingStaticDirectiveContext extends Using_directiveContext {
		public TerminalNode USING() { return getToken(XiasParser.USING, 0); }
		public TerminalNode STATIC() { return getToken(XiasParser.STATIC, 0); }
		public Namespace_or_type_nameContext namespace_or_type_name() {
			return getRuleContext(Namespace_or_type_nameContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(XiasParser.SEMICOLON, 0); }
		public UsingStaticDirectiveContext(Using_directiveContext ctx) { copyFrom(ctx); }
	}

	public final Using_directiveContext using_directive() throws RecognitionException {
		Using_directiveContext _localctx = new Using_directiveContext(_ctx, getState());
		enterRule(_localctx, 170, RULE_using_directive);
		try {
			setState(1208);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,130,_ctx) ) {
			case 1:
				_localctx = new UsingAliasDirectiveContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(1193);
				match(USING);
				setState(1194);
				identifier();
				setState(1195);
				match(ASSIGNMENT);
				setState(1196);
				namespace_or_type_name();
				setState(1197);
				match(SEMICOLON);
				}
				break;
			case 2:
				_localctx = new UsingNamespaceDirectiveContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(1199);
				match(USING);
				setState(1200);
				namespace_or_type_name();
				setState(1201);
				match(SEMICOLON);
				}
				break;
			case 3:
				_localctx = new UsingStaticDirectiveContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(1203);
				match(USING);
				setState(1204);
				match(STATIC);
				setState(1205);
				namespace_or_type_name();
				setState(1206);
				match(SEMICOLON);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Namespace_member_declarationsContext extends ParserRuleContext {
		public List<Namespace_member_declarationContext> namespace_member_declaration() {
			return getRuleContexts(Namespace_member_declarationContext.class);
		}
		public Namespace_member_declarationContext namespace_member_declaration(int i) {
			return getRuleContext(Namespace_member_declarationContext.class,i);
		}
		public Namespace_member_declarationsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_namespace_member_declarations; }
	}

	public final Namespace_member_declarationsContext namespace_member_declarations() throws RecognitionException {
		Namespace_member_declarationsContext _localctx = new Namespace_member_declarationsContext(_ctx, getState());
		enterRule(_localctx, 172, RULE_namespace_member_declarations);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1211); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(1210);
				namespace_member_declaration();
				}
				}
				setState(1213); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( ((((_la - 6)) & ~0x3f) == 0 && ((1L << (_la - 6)) & ((1L << (ABSTRACT - 6)) | (1L << (CLASS - 6)) | (1L << (ENUM - 6)) | (1L << (INTERFACE - 6)) | (1L << (INTERNAL - 6)) | (1L << (NAMESPACE - 6)) | (1L << (NEW - 6)) | (1L << (OVERRIDE - 6)) | (1L << (PRIVATE - 6)) | (1L << (PROTECTED - 6)) | (1L << (PUBLIC - 6)) | (1L << (READONLY - 6)) | (1L << (SEALED - 6)) | (1L << (STATIC - 6)) | (1L << (VIRTUAL - 6)))) != 0) );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Namespace_member_declarationContext extends ParserRuleContext {
		public Namespace_declarationContext namespace_declaration() {
			return getRuleContext(Namespace_declarationContext.class,0);
		}
		public Type_declarationContext type_declaration() {
			return getRuleContext(Type_declarationContext.class,0);
		}
		public Namespace_member_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_namespace_member_declaration; }
	}

	public final Namespace_member_declarationContext namespace_member_declaration() throws RecognitionException {
		Namespace_member_declarationContext _localctx = new Namespace_member_declarationContext(_ctx, getState());
		enterRule(_localctx, 174, RULE_namespace_member_declaration);
		try {
			setState(1217);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case NAMESPACE:
				enterOuterAlt(_localctx, 1);
				{
				setState(1215);
				namespace_declaration();
				}
				break;
			case ABSTRACT:
			case CLASS:
			case ENUM:
			case INTERFACE:
			case INTERNAL:
			case NEW:
			case OVERRIDE:
			case PRIVATE:
			case PROTECTED:
			case PUBLIC:
			case READONLY:
			case SEALED:
			case STATIC:
			case VIRTUAL:
				enterOuterAlt(_localctx, 2);
				{
				setState(1216);
				type_declaration();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Type_declarationContext extends ParserRuleContext {
		public Class_definitionContext class_definition() {
			return getRuleContext(Class_definitionContext.class,0);
		}
		public Interface_definitionContext interface_definition() {
			return getRuleContext(Interface_definitionContext.class,0);
		}
		public Enum_definitionContext enum_definition() {
			return getRuleContext(Enum_definitionContext.class,0);
		}
		public All_member_modifiersContext all_member_modifiers() {
			return getRuleContext(All_member_modifiersContext.class,0);
		}
		public Type_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type_declaration; }
	}

	public final Type_declarationContext type_declaration() throws RecognitionException {
		Type_declarationContext _localctx = new Type_declarationContext(_ctx, getState());
		enterRule(_localctx, 176, RULE_type_declaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1220);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (((((_la - 6)) & ~0x3f) == 0 && ((1L << (_la - 6)) & ((1L << (ABSTRACT - 6)) | (1L << (INTERNAL - 6)) | (1L << (NEW - 6)) | (1L << (OVERRIDE - 6)) | (1L << (PRIVATE - 6)) | (1L << (PROTECTED - 6)) | (1L << (PUBLIC - 6)) | (1L << (READONLY - 6)) | (1L << (SEALED - 6)) | (1L << (STATIC - 6)) | (1L << (VIRTUAL - 6)))) != 0)) {
				{
				setState(1219);
				all_member_modifiers();
				}
			}

			setState(1225);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case CLASS:
				{
				setState(1222);
				class_definition();
				}
				break;
			case INTERFACE:
				{
				setState(1223);
				interface_definition();
				}
				break;
			case ENUM:
				{
				setState(1224);
				enum_definition();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Qualified_alias_memberContext extends ParserRuleContext {
		public List<IdentifierContext> identifier() {
			return getRuleContexts(IdentifierContext.class);
		}
		public IdentifierContext identifier(int i) {
			return getRuleContext(IdentifierContext.class,i);
		}
		public TerminalNode DOUBLE_COLON() { return getToken(XiasParser.DOUBLE_COLON, 0); }
		public Type_argument_listContext type_argument_list() {
			return getRuleContext(Type_argument_listContext.class,0);
		}
		public Qualified_alias_memberContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_qualified_alias_member; }
	}

	public final Qualified_alias_memberContext qualified_alias_member() throws RecognitionException {
		Qualified_alias_memberContext _localctx = new Qualified_alias_memberContext(_ctx, getState());
		enterRule(_localctx, 178, RULE_qualified_alias_member);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1227);
			identifier();
			setState(1228);
			match(DOUBLE_COLON);
			setState(1229);
			identifier();
			setState(1231);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,135,_ctx) ) {
			case 1:
				{
				setState(1230);
				type_argument_list();
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Type_parameter_listContext extends ParserRuleContext {
		public TerminalNode LT() { return getToken(XiasParser.LT, 0); }
		public List<Type_parameterContext> type_parameter() {
			return getRuleContexts(Type_parameterContext.class);
		}
		public Type_parameterContext type_parameter(int i) {
			return getRuleContext(Type_parameterContext.class,i);
		}
		public TerminalNode GT() { return getToken(XiasParser.GT, 0); }
		public List<TerminalNode> COMMA() { return getTokens(XiasParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(XiasParser.COMMA, i);
		}
		public Type_parameter_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type_parameter_list; }
	}

	public final Type_parameter_listContext type_parameter_list() throws RecognitionException {
		Type_parameter_listContext _localctx = new Type_parameter_listContext(_ctx, getState());
		enterRule(_localctx, 180, RULE_type_parameter_list);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1233);
			match(LT);
			setState(1234);
			type_parameter();
			setState(1239);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(1235);
				match(COMMA);
				setState(1236);
				type_parameter();
				}
				}
				setState(1241);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(1242);
			match(GT);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Type_parameterContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public Type_parameterContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type_parameter; }
	}

	public final Type_parameterContext type_parameter() throws RecognitionException {
		Type_parameterContext _localctx = new Type_parameterContext(_ctx, getState());
		enterRule(_localctx, 182, RULE_type_parameter);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1244);
			identifier();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Class_baseContext extends ParserRuleContext {
		public TerminalNode COLON() { return getToken(XiasParser.COLON, 0); }
		public Class_typeContext class_type() {
			return getRuleContext(Class_typeContext.class,0);
		}
		public List<TerminalNode> COMMA() { return getTokens(XiasParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(XiasParser.COMMA, i);
		}
		public List<Namespace_or_type_nameContext> namespace_or_type_name() {
			return getRuleContexts(Namespace_or_type_nameContext.class);
		}
		public Namespace_or_type_nameContext namespace_or_type_name(int i) {
			return getRuleContext(Namespace_or_type_nameContext.class,i);
		}
		public Class_baseContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_class_base; }
	}

	public final Class_baseContext class_base() throws RecognitionException {
		Class_baseContext _localctx = new Class_baseContext(_ctx, getState());
		enterRule(_localctx, 184, RULE_class_base);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1246);
			match(COLON);
			setState(1247);
			class_type();
			setState(1252);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(1248);
				match(COMMA);
				setState(1249);
				namespace_or_type_name();
				}
				}
				setState(1254);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Interface_type_listContext extends ParserRuleContext {
		public List<Namespace_or_type_nameContext> namespace_or_type_name() {
			return getRuleContexts(Namespace_or_type_nameContext.class);
		}
		public Namespace_or_type_nameContext namespace_or_type_name(int i) {
			return getRuleContext(Namespace_or_type_nameContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(XiasParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(XiasParser.COMMA, i);
		}
		public Interface_type_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_interface_type_list; }
	}

	public final Interface_type_listContext interface_type_list() throws RecognitionException {
		Interface_type_listContext _localctx = new Interface_type_listContext(_ctx, getState());
		enterRule(_localctx, 186, RULE_interface_type_list);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1255);
			namespace_or_type_name();
			setState(1260);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(1256);
				match(COMMA);
				setState(1257);
				namespace_or_type_name();
				}
				}
				setState(1262);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Type_parameter_constraints_clausesContext extends ParserRuleContext {
		public List<Type_parameter_constraints_clauseContext> type_parameter_constraints_clause() {
			return getRuleContexts(Type_parameter_constraints_clauseContext.class);
		}
		public Type_parameter_constraints_clauseContext type_parameter_constraints_clause(int i) {
			return getRuleContext(Type_parameter_constraints_clauseContext.class,i);
		}
		public Type_parameter_constraints_clausesContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type_parameter_constraints_clauses; }
	}

	public final Type_parameter_constraints_clausesContext type_parameter_constraints_clauses() throws RecognitionException {
		Type_parameter_constraints_clausesContext _localctx = new Type_parameter_constraints_clausesContext(_ctx, getState());
		enterRule(_localctx, 188, RULE_type_parameter_constraints_clauses);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1264); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(1263);
				type_parameter_constraints_clause();
				}
				}
				setState(1266); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==WHERE );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Type_parameter_constraints_clauseContext extends ParserRuleContext {
		public TerminalNode WHERE() { return getToken(XiasParser.WHERE, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode COLON() { return getToken(XiasParser.COLON, 0); }
		public Type_parameter_constraintsContext type_parameter_constraints() {
			return getRuleContext(Type_parameter_constraintsContext.class,0);
		}
		public Type_parameter_constraints_clauseContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type_parameter_constraints_clause; }
	}

	public final Type_parameter_constraints_clauseContext type_parameter_constraints_clause() throws RecognitionException {
		Type_parameter_constraints_clauseContext _localctx = new Type_parameter_constraints_clauseContext(_ctx, getState());
		enterRule(_localctx, 190, RULE_type_parameter_constraints_clause);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1268);
			match(WHERE);
			setState(1269);
			identifier();
			setState(1270);
			match(COLON);
			setState(1271);
			type_parameter_constraints();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Type_parameter_constraintsContext extends ParserRuleContext {
		public Constructor_constraintContext constructor_constraint() {
			return getRuleContext(Constructor_constraintContext.class,0);
		}
		public Primary_constraintContext primary_constraint() {
			return getRuleContext(Primary_constraintContext.class,0);
		}
		public List<TerminalNode> COMMA() { return getTokens(XiasParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(XiasParser.COMMA, i);
		}
		public Secondary_constraintsContext secondary_constraints() {
			return getRuleContext(Secondary_constraintsContext.class,0);
		}
		public Type_parameter_constraintsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type_parameter_constraints; }
	}

	public final Type_parameter_constraintsContext type_parameter_constraints() throws RecognitionException {
		Type_parameter_constraintsContext _localctx = new Type_parameter_constraintsContext(_ctx, getState());
		enterRule(_localctx, 192, RULE_type_parameter_constraints);
		int _la;
		try {
			setState(1283);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case NEW:
				enterOuterAlt(_localctx, 1);
				{
				setState(1273);
				constructor_constraint();
				}
				break;
			case CLASS:
			case GET:
			case NAMEOF:
			case OBJECT:
			case SET:
			case STRING:
			case VAR:
			case WHEN:
			case WHERE:
			case IDENTIFIER:
				enterOuterAlt(_localctx, 2);
				{
				setState(1274);
				primary_constraint();
				setState(1277);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,140,_ctx) ) {
				case 1:
					{
					setState(1275);
					match(COMMA);
					setState(1276);
					secondary_constraints();
					}
					break;
				}
				setState(1281);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==COMMA) {
					{
					setState(1279);
					match(COMMA);
					setState(1280);
					constructor_constraint();
					}
				}

				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Primary_constraintContext extends ParserRuleContext {
		public Class_typeContext class_type() {
			return getRuleContext(Class_typeContext.class,0);
		}
		public TerminalNode CLASS() { return getToken(XiasParser.CLASS, 0); }
		public Primary_constraintContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_primary_constraint; }
	}

	public final Primary_constraintContext primary_constraint() throws RecognitionException {
		Primary_constraintContext _localctx = new Primary_constraintContext(_ctx, getState());
		enterRule(_localctx, 194, RULE_primary_constraint);
		try {
			setState(1287);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case GET:
			case NAMEOF:
			case OBJECT:
			case SET:
			case STRING:
			case VAR:
			case WHEN:
			case WHERE:
			case IDENTIFIER:
				enterOuterAlt(_localctx, 1);
				{
				setState(1285);
				class_type();
				}
				break;
			case CLASS:
				enterOuterAlt(_localctx, 2);
				{
				setState(1286);
				match(CLASS);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Secondary_constraintsContext extends ParserRuleContext {
		public List<Namespace_or_type_nameContext> namespace_or_type_name() {
			return getRuleContexts(Namespace_or_type_nameContext.class);
		}
		public Namespace_or_type_nameContext namespace_or_type_name(int i) {
			return getRuleContext(Namespace_or_type_nameContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(XiasParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(XiasParser.COMMA, i);
		}
		public Secondary_constraintsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_secondary_constraints; }
	}

	public final Secondary_constraintsContext secondary_constraints() throws RecognitionException {
		Secondary_constraintsContext _localctx = new Secondary_constraintsContext(_ctx, getState());
		enterRule(_localctx, 196, RULE_secondary_constraints);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(1289);
			namespace_or_type_name();
			setState(1294);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,144,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(1290);
					match(COMMA);
					setState(1291);
					namespace_or_type_name();
					}
					} 
				}
				setState(1296);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,144,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Constructor_constraintContext extends ParserRuleContext {
		public TerminalNode NEW() { return getToken(XiasParser.NEW, 0); }
		public TerminalNode OPEN_PARENS() { return getToken(XiasParser.OPEN_PARENS, 0); }
		public TerminalNode CLOSE_PARENS() { return getToken(XiasParser.CLOSE_PARENS, 0); }
		public Constructor_constraintContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constructor_constraint; }
	}

	public final Constructor_constraintContext constructor_constraint() throws RecognitionException {
		Constructor_constraintContext _localctx = new Constructor_constraintContext(_ctx, getState());
		enterRule(_localctx, 198, RULE_constructor_constraint);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1297);
			match(NEW);
			setState(1298);
			match(OPEN_PARENS);
			setState(1299);
			match(CLOSE_PARENS);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Class_bodyContext extends ParserRuleContext {
		public TerminalNode OPEN_BRACE() { return getToken(XiasParser.OPEN_BRACE, 0); }
		public TerminalNode CLOSE_BRACE() { return getToken(XiasParser.CLOSE_BRACE, 0); }
		public Class_member_declarationsContext class_member_declarations() {
			return getRuleContext(Class_member_declarationsContext.class,0);
		}
		public Class_bodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_class_body; }
	}

	public final Class_bodyContext class_body() throws RecognitionException {
		Class_bodyContext _localctx = new Class_bodyContext(_ctx, getState());
		enterRule(_localctx, 200, RULE_class_body);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1301);
			match(OPEN_BRACE);
			setState(1303);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << ABSTRACT) | (1L << BOOL) | (1L << CHAR) | (1L << CLASS) | (1L << CONST) | (1L << DOUBLE) | (1L << ENUM) | (1L << EXPLICIT) | (1L << FLOAT) | (1L << GET) | (1L << IMPLICIT) | (1L << INT) | (1L << INTERFACE) | (1L << INTERNAL) | (1L << NAMEOF) | (1L << NEW) | (1L << OBJECT) | (1L << OVERRIDE) | (1L << PRIVATE) | (1L << PROTECTED) | (1L << PUBLIC) | (1L << READONLY) | (1L << REF) | (1L << SEALED) | (1L << SET) | (1L << STATIC) | (1L << STRING) | (1L << UINT))) != 0) || ((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & ((1L << (VAR - 64)) | (1L << (VIRTUAL - 64)) | (1L << (VOID - 64)) | (1L << (WHEN - 64)) | (1L << (WHERE - 64)) | (1L << (IDENTIFIER - 64)) | (1L << (TILDE - 64)))) != 0)) {
				{
				setState(1302);
				class_member_declarations();
				}
			}

			setState(1305);
			match(CLOSE_BRACE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Class_member_declarationsContext extends ParserRuleContext {
		public List<Class_member_declarationContext> class_member_declaration() {
			return getRuleContexts(Class_member_declarationContext.class);
		}
		public Class_member_declarationContext class_member_declaration(int i) {
			return getRuleContext(Class_member_declarationContext.class,i);
		}
		public Class_member_declarationsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_class_member_declarations; }
	}

	public final Class_member_declarationsContext class_member_declarations() throws RecognitionException {
		Class_member_declarationsContext _localctx = new Class_member_declarationsContext(_ctx, getState());
		enterRule(_localctx, 202, RULE_class_member_declarations);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1308); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(1307);
				class_member_declaration();
				}
				}
				setState(1310); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << ABSTRACT) | (1L << BOOL) | (1L << CHAR) | (1L << CLASS) | (1L << CONST) | (1L << DOUBLE) | (1L << ENUM) | (1L << EXPLICIT) | (1L << FLOAT) | (1L << GET) | (1L << IMPLICIT) | (1L << INT) | (1L << INTERFACE) | (1L << INTERNAL) | (1L << NAMEOF) | (1L << NEW) | (1L << OBJECT) | (1L << OVERRIDE) | (1L << PRIVATE) | (1L << PROTECTED) | (1L << PUBLIC) | (1L << READONLY) | (1L << REF) | (1L << SEALED) | (1L << SET) | (1L << STATIC) | (1L << STRING) | (1L << UINT))) != 0) || ((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & ((1L << (VAR - 64)) | (1L << (VIRTUAL - 64)) | (1L << (VOID - 64)) | (1L << (WHEN - 64)) | (1L << (WHERE - 64)) | (1L << (IDENTIFIER - 64)) | (1L << (TILDE - 64)))) != 0) );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Class_member_declarationContext extends ParserRuleContext {
		public Common_member_declarationContext common_member_declaration() {
			return getRuleContext(Common_member_declarationContext.class,0);
		}
		public Destructor_definitionContext destructor_definition() {
			return getRuleContext(Destructor_definitionContext.class,0);
		}
		public All_member_modifiersContext all_member_modifiers() {
			return getRuleContext(All_member_modifiersContext.class,0);
		}
		public Class_member_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_class_member_declaration; }
	}

	public final Class_member_declarationContext class_member_declaration() throws RecognitionException {
		Class_member_declarationContext _localctx = new Class_member_declarationContext(_ctx, getState());
		enterRule(_localctx, 204, RULE_class_member_declaration);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1313);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,147,_ctx) ) {
			case 1:
				{
				setState(1312);
				all_member_modifiers();
				}
				break;
			}
			setState(1317);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case BOOL:
			case CHAR:
			case CLASS:
			case CONST:
			case DOUBLE:
			case ENUM:
			case EXPLICIT:
			case FLOAT:
			case GET:
			case IMPLICIT:
			case INT:
			case INTERFACE:
			case NAMEOF:
			case OBJECT:
			case READONLY:
			case REF:
			case SET:
			case STRING:
			case UINT:
			case VAR:
			case VOID:
			case WHEN:
			case WHERE:
			case IDENTIFIER:
				{
				setState(1315);
				common_member_declaration();
				}
				break;
			case TILDE:
				{
				setState(1316);
				destructor_definition();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class All_member_modifiersContext extends ParserRuleContext {
		public List<All_member_modifierContext> all_member_modifier() {
			return getRuleContexts(All_member_modifierContext.class);
		}
		public All_member_modifierContext all_member_modifier(int i) {
			return getRuleContext(All_member_modifierContext.class,i);
		}
		public All_member_modifiersContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_all_member_modifiers; }
	}

	public final All_member_modifiersContext all_member_modifiers() throws RecognitionException {
		All_member_modifiersContext _localctx = new All_member_modifiersContext(_ctx, getState());
		enterRule(_localctx, 206, RULE_all_member_modifiers);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(1320); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(1319);
					all_member_modifier();
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(1322); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,149,_ctx);
			} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class All_member_modifierContext extends ParserRuleContext {
		public TerminalNode NEW() { return getToken(XiasParser.NEW, 0); }
		public TerminalNode PUBLIC() { return getToken(XiasParser.PUBLIC, 0); }
		public TerminalNode PROTECTED() { return getToken(XiasParser.PROTECTED, 0); }
		public TerminalNode INTERNAL() { return getToken(XiasParser.INTERNAL, 0); }
		public TerminalNode PRIVATE() { return getToken(XiasParser.PRIVATE, 0); }
		public TerminalNode READONLY() { return getToken(XiasParser.READONLY, 0); }
		public TerminalNode VIRTUAL() { return getToken(XiasParser.VIRTUAL, 0); }
		public TerminalNode SEALED() { return getToken(XiasParser.SEALED, 0); }
		public TerminalNode OVERRIDE() { return getToken(XiasParser.OVERRIDE, 0); }
		public TerminalNode ABSTRACT() { return getToken(XiasParser.ABSTRACT, 0); }
		public TerminalNode STATIC() { return getToken(XiasParser.STATIC, 0); }
		public All_member_modifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_all_member_modifier; }
	}

	public final All_member_modifierContext all_member_modifier() throws RecognitionException {
		All_member_modifierContext _localctx = new All_member_modifierContext(_ctx, getState());
		enterRule(_localctx, 208, RULE_all_member_modifier);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1324);
			_la = _input.LA(1);
			if ( !(((((_la - 6)) & ~0x3f) == 0 && ((1L << (_la - 6)) & ((1L << (ABSTRACT - 6)) | (1L << (INTERNAL - 6)) | (1L << (NEW - 6)) | (1L << (OVERRIDE - 6)) | (1L << (PRIVATE - 6)) | (1L << (PROTECTED - 6)) | (1L << (PUBLIC - 6)) | (1L << (READONLY - 6)) | (1L << (SEALED - 6)) | (1L << (STATIC - 6)) | (1L << (VIRTUAL - 6)))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Common_member_declarationContext extends ParserRuleContext {
		public Constant_declarationContext constant_declaration() {
			return getRuleContext(Constant_declarationContext.class,0);
		}
		public Typed_member_declarationContext typed_member_declaration() {
			return getRuleContext(Typed_member_declarationContext.class,0);
		}
		public Conversion_operator_declaratorContext conversion_operator_declarator() {
			return getRuleContext(Conversion_operator_declaratorContext.class,0);
		}
		public BodyContext body() {
			return getRuleContext(BodyContext.class,0);
		}
		public Right_arrowContext right_arrow() {
			return getRuleContext(Right_arrowContext.class,0);
		}
		public Throwable_expressionContext throwable_expression() {
			return getRuleContext(Throwable_expressionContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(XiasParser.SEMICOLON, 0); }
		public Constructor_declarationContext constructor_declaration() {
			return getRuleContext(Constructor_declarationContext.class,0);
		}
		public TerminalNode VOID() { return getToken(XiasParser.VOID, 0); }
		public Method_declarationContext method_declaration() {
			return getRuleContext(Method_declarationContext.class,0);
		}
		public Class_definitionContext class_definition() {
			return getRuleContext(Class_definitionContext.class,0);
		}
		public Interface_definitionContext interface_definition() {
			return getRuleContext(Interface_definitionContext.class,0);
		}
		public Enum_definitionContext enum_definition() {
			return getRuleContext(Enum_definitionContext.class,0);
		}
		public Common_member_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_common_member_declaration; }
	}

	public final Common_member_declarationContext common_member_declaration() throws RecognitionException {
		Common_member_declarationContext _localctx = new Common_member_declarationContext(_ctx, getState());
		enterRule(_localctx, 210, RULE_common_member_declaration);
		try {
			setState(1342);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,151,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(1326);
				constant_declaration();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(1327);
				typed_member_declaration();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(1328);
				conversion_operator_declarator();
				setState(1334);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case OPEN_BRACE:
				case SEMICOLON:
					{
					setState(1329);
					body();
					}
					break;
				case ASSIGNMENT:
					{
					setState(1330);
					right_arrow();
					setState(1331);
					throwable_expression();
					setState(1332);
					match(SEMICOLON);
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(1336);
				constructor_declaration();
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(1337);
				match(VOID);
				setState(1338);
				method_declaration();
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(1339);
				class_definition();
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(1340);
				interface_definition();
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(1341);
				enum_definition();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Typed_member_declarationContext extends ParserRuleContext {
		public Type_Context type_() {
			return getRuleContext(Type_Context.class,0);
		}
		public Namespace_or_type_nameContext namespace_or_type_name() {
			return getRuleContext(Namespace_or_type_nameContext.class,0);
		}
		public TerminalNode DOT() { return getToken(XiasParser.DOT, 0); }
		public Indexer_declarationContext indexer_declaration() {
			return getRuleContext(Indexer_declarationContext.class,0);
		}
		public Method_declarationContext method_declaration() {
			return getRuleContext(Method_declarationContext.class,0);
		}
		public Property_declarationContext property_declaration() {
			return getRuleContext(Property_declarationContext.class,0);
		}
		public Operator_declarationContext operator_declaration() {
			return getRuleContext(Operator_declarationContext.class,0);
		}
		public Field_declarationContext field_declaration() {
			return getRuleContext(Field_declarationContext.class,0);
		}
		public TerminalNode REF() { return getToken(XiasParser.REF, 0); }
		public TerminalNode READONLY() { return getToken(XiasParser.READONLY, 0); }
		public Typed_member_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typed_member_declaration; }
	}

	public final Typed_member_declarationContext typed_member_declaration() throws RecognitionException {
		Typed_member_declarationContext _localctx = new Typed_member_declarationContext(_ctx, getState());
		enterRule(_localctx, 212, RULE_typed_member_declaration);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1349);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,152,_ctx) ) {
			case 1:
				{
				setState(1344);
				match(REF);
				}
				break;
			case 2:
				{
				setState(1345);
				match(READONLY);
				setState(1346);
				match(REF);
				}
				break;
			case 3:
				{
				setState(1347);
				match(REF);
				setState(1348);
				match(READONLY);
				}
				break;
			}
			setState(1351);
			type_();
			setState(1361);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,153,_ctx) ) {
			case 1:
				{
				setState(1352);
				namespace_or_type_name();
				setState(1353);
				match(DOT);
				setState(1354);
				indexer_declaration();
				}
				break;
			case 2:
				{
				setState(1356);
				method_declaration();
				}
				break;
			case 3:
				{
				setState(1357);
				property_declaration();
				}
				break;
			case 4:
				{
				setState(1358);
				indexer_declaration();
				}
				break;
			case 5:
				{
				setState(1359);
				operator_declaration();
				}
				break;
			case 6:
				{
				setState(1360);
				field_declaration();
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Constant_declaratorsContext extends ParserRuleContext {
		public List<Constant_declaratorContext> constant_declarator() {
			return getRuleContexts(Constant_declaratorContext.class);
		}
		public Constant_declaratorContext constant_declarator(int i) {
			return getRuleContext(Constant_declaratorContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(XiasParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(XiasParser.COMMA, i);
		}
		public Constant_declaratorsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constant_declarators; }
	}

	public final Constant_declaratorsContext constant_declarators() throws RecognitionException {
		Constant_declaratorsContext _localctx = new Constant_declaratorsContext(_ctx, getState());
		enterRule(_localctx, 214, RULE_constant_declarators);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1363);
			constant_declarator();
			setState(1368);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(1364);
				match(COMMA);
				setState(1365);
				constant_declarator();
				}
				}
				setState(1370);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Constant_declaratorContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode ASSIGNMENT() { return getToken(XiasParser.ASSIGNMENT, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Constant_declaratorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constant_declarator; }
	}

	public final Constant_declaratorContext constant_declarator() throws RecognitionException {
		Constant_declaratorContext _localctx = new Constant_declaratorContext(_ctx, getState());
		enterRule(_localctx, 216, RULE_constant_declarator);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1371);
			identifier();
			setState(1372);
			match(ASSIGNMENT);
			setState(1373);
			expression();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Variable_declaratorsContext extends ParserRuleContext {
		public List<Variable_declaratorContext> variable_declarator() {
			return getRuleContexts(Variable_declaratorContext.class);
		}
		public Variable_declaratorContext variable_declarator(int i) {
			return getRuleContext(Variable_declaratorContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(XiasParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(XiasParser.COMMA, i);
		}
		public Variable_declaratorsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variable_declarators; }
	}

	public final Variable_declaratorsContext variable_declarators() throws RecognitionException {
		Variable_declaratorsContext _localctx = new Variable_declaratorsContext(_ctx, getState());
		enterRule(_localctx, 218, RULE_variable_declarators);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1375);
			variable_declarator();
			setState(1380);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(1376);
				match(COMMA);
				setState(1377);
				variable_declarator();
				}
				}
				setState(1382);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Variable_declaratorContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode ASSIGNMENT() { return getToken(XiasParser.ASSIGNMENT, 0); }
		public Variable_initializerContext variable_initializer() {
			return getRuleContext(Variable_initializerContext.class,0);
		}
		public Variable_declaratorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variable_declarator; }
	}

	public final Variable_declaratorContext variable_declarator() throws RecognitionException {
		Variable_declaratorContext _localctx = new Variable_declaratorContext(_ctx, getState());
		enterRule(_localctx, 220, RULE_variable_declarator);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1383);
			identifier();
			setState(1386);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==ASSIGNMENT) {
				{
				setState(1384);
				match(ASSIGNMENT);
				setState(1385);
				variable_initializer();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Variable_initializerContext extends ParserRuleContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Array_initializerContext array_initializer() {
			return getRuleContext(Array_initializerContext.class,0);
		}
		public Variable_initializerContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variable_initializer; }
	}

	public final Variable_initializerContext variable_initializer() throws RecognitionException {
		Variable_initializerContext _localctx = new Variable_initializerContext(_ctx, getState());
		enterRule(_localctx, 222, RULE_variable_initializer);
		try {
			setState(1390);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case BASE:
			case BOOL:
			case CHAR:
			case DEFAULT:
			case DOUBLE:
			case FALSE:
			case FLOAT:
			case GET:
			case INT:
			case NAMEOF:
			case NEW:
			case NULL_:
			case OBJECT:
			case REF:
			case SET:
			case SIZEOF:
			case STRING:
			case THIS:
			case TRUE:
			case TYPEOF:
			case UINT:
			case VAR:
			case WHEN:
			case WHERE:
			case IDENTIFIER:
			case LITERAL_ACCESS:
			case INTEGER_LITERAL:
			case HEX_INTEGER_LITERAL:
			case REAL_LITERAL:
			case CHARACTER_LITERAL:
			case REGULAR_STRING:
			case VERBATIUM_STRING:
			case OPEN_PARENS:
			case PLUS:
			case MINUS:
			case STAR:
			case BANG:
			case TILDE:
			case OP_INC:
			case OP_DEC:
				enterOuterAlt(_localctx, 1);
				{
				setState(1388);
				expression();
				}
				break;
			case OPEN_BRACE:
				enterOuterAlt(_localctx, 2);
				{
				setState(1389);
				array_initializer();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Return_typeContext extends ParserRuleContext {
		public Type_Context type_() {
			return getRuleContext(Type_Context.class,0);
		}
		public TerminalNode VOID() { return getToken(XiasParser.VOID, 0); }
		public Return_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_return_type; }
	}

	public final Return_typeContext return_type() throws RecognitionException {
		Return_typeContext _localctx = new Return_typeContext(_ctx, getState());
		enterRule(_localctx, 224, RULE_return_type);
		try {
			setState(1394);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,158,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(1392);
				type_();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(1393);
				match(VOID);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Member_nameContext extends ParserRuleContext {
		public Namespace_or_type_nameContext namespace_or_type_name() {
			return getRuleContext(Namespace_or_type_nameContext.class,0);
		}
		public Member_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_member_name; }
	}

	public final Member_nameContext member_name() throws RecognitionException {
		Member_nameContext _localctx = new Member_nameContext(_ctx, getState());
		enterRule(_localctx, 226, RULE_member_name);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1396);
			namespace_or_type_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Method_bodyContext extends ParserRuleContext {
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(XiasParser.SEMICOLON, 0); }
		public Method_bodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_method_body; }
	}

	public final Method_bodyContext method_body() throws RecognitionException {
		Method_bodyContext _localctx = new Method_bodyContext(_ctx, getState());
		enterRule(_localctx, 228, RULE_method_body);
		try {
			setState(1400);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case OPEN_BRACE:
				enterOuterAlt(_localctx, 1);
				{
				setState(1398);
				block();
				}
				break;
			case SEMICOLON:
				enterOuterAlt(_localctx, 2);
				{
				setState(1399);
				match(SEMICOLON);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Formal_parameter_listContext extends ParserRuleContext {
		public Parameter_arrayContext parameter_array() {
			return getRuleContext(Parameter_arrayContext.class,0);
		}
		public Fixed_parametersContext fixed_parameters() {
			return getRuleContext(Fixed_parametersContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(XiasParser.COMMA, 0); }
		public Formal_parameter_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_formal_parameter_list; }
	}

	public final Formal_parameter_listContext formal_parameter_list() throws RecognitionException {
		Formal_parameter_listContext _localctx = new Formal_parameter_listContext(_ctx, getState());
		enterRule(_localctx, 230, RULE_formal_parameter_list);
		int _la;
		try {
			setState(1408);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case PARAMS:
				enterOuterAlt(_localctx, 1);
				{
				setState(1402);
				parameter_array();
				}
				break;
			case BOOL:
			case CHAR:
			case DOUBLE:
			case FLOAT:
			case GET:
			case IN:
			case INT:
			case NAMEOF:
			case OBJECT:
			case OUT:
			case REF:
			case SET:
			case STRING:
			case THIS:
			case UINT:
			case VAR:
			case VOID:
			case WHEN:
			case WHERE:
			case IDENTIFIER:
				enterOuterAlt(_localctx, 2);
				{
				setState(1403);
				fixed_parameters();
				setState(1406);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==COMMA) {
					{
					setState(1404);
					match(COMMA);
					setState(1405);
					parameter_array();
					}
				}

				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Fixed_parametersContext extends ParserRuleContext {
		public List<Fixed_parameterContext> fixed_parameter() {
			return getRuleContexts(Fixed_parameterContext.class);
		}
		public Fixed_parameterContext fixed_parameter(int i) {
			return getRuleContext(Fixed_parameterContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(XiasParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(XiasParser.COMMA, i);
		}
		public Fixed_parametersContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_fixed_parameters; }
	}

	public final Fixed_parametersContext fixed_parameters() throws RecognitionException {
		Fixed_parametersContext _localctx = new Fixed_parametersContext(_ctx, getState());
		enterRule(_localctx, 232, RULE_fixed_parameters);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(1410);
			fixed_parameter();
			setState(1415);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,162,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(1411);
					match(COMMA);
					setState(1412);
					fixed_parameter();
					}
					} 
				}
				setState(1417);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,162,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Fixed_parameterContext extends ParserRuleContext {
		public Arg_declarationContext arg_declaration() {
			return getRuleContext(Arg_declarationContext.class,0);
		}
		public Parameter_modifierContext parameter_modifier() {
			return getRuleContext(Parameter_modifierContext.class,0);
		}
		public Fixed_parameterContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_fixed_parameter; }
	}

	public final Fixed_parameterContext fixed_parameter() throws RecognitionException {
		Fixed_parameterContext _localctx = new Fixed_parameterContext(_ctx, getState());
		enterRule(_localctx, 234, RULE_fixed_parameter);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1419);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << IN) | (1L << OUT) | (1L << REF) | (1L << THIS))) != 0)) {
				{
				setState(1418);
				parameter_modifier();
				}
			}

			setState(1421);
			arg_declaration();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Parameter_modifierContext extends ParserRuleContext {
		public TerminalNode REF() { return getToken(XiasParser.REF, 0); }
		public TerminalNode OUT() { return getToken(XiasParser.OUT, 0); }
		public TerminalNode IN() { return getToken(XiasParser.IN, 0); }
		public TerminalNode THIS() { return getToken(XiasParser.THIS, 0); }
		public Parameter_modifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameter_modifier; }
	}

	public final Parameter_modifierContext parameter_modifier() throws RecognitionException {
		Parameter_modifierContext _localctx = new Parameter_modifierContext(_ctx, getState());
		enterRule(_localctx, 236, RULE_parameter_modifier);
		try {
			setState(1431);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,164,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(1423);
				match(REF);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(1424);
				match(OUT);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(1425);
				match(IN);
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(1426);
				match(REF);
				setState(1427);
				match(THIS);
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(1428);
				match(IN);
				setState(1429);
				match(THIS);
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(1430);
				match(THIS);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Parameter_arrayContext extends ParserRuleContext {
		public TerminalNode PARAMS() { return getToken(XiasParser.PARAMS, 0); }
		public Array_typeContext array_type() {
			return getRuleContext(Array_typeContext.class,0);
		}
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public Parameter_arrayContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameter_array; }
	}

	public final Parameter_arrayContext parameter_array() throws RecognitionException {
		Parameter_arrayContext _localctx = new Parameter_arrayContext(_ctx, getState());
		enterRule(_localctx, 238, RULE_parameter_array);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1433);
			match(PARAMS);
			setState(1434);
			array_type();
			setState(1435);
			identifier();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Accessor_declarationsContext extends ParserRuleContext {
		public Accessor_modifierContext mods;
		public TerminalNode GET() { return getToken(XiasParser.GET, 0); }
		public Accessor_bodyContext accessor_body() {
			return getRuleContext(Accessor_bodyContext.class,0);
		}
		public TerminalNode SET() { return getToken(XiasParser.SET, 0); }
		public Accessor_modifierContext accessor_modifier() {
			return getRuleContext(Accessor_modifierContext.class,0);
		}
		public Set_accessor_declarationContext set_accessor_declaration() {
			return getRuleContext(Set_accessor_declarationContext.class,0);
		}
		public Get_accessor_declarationContext get_accessor_declaration() {
			return getRuleContext(Get_accessor_declarationContext.class,0);
		}
		public Accessor_declarationsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_accessor_declarations; }
	}

	public final Accessor_declarationsContext accessor_declarations() throws RecognitionException {
		Accessor_declarationsContext _localctx = new Accessor_declarationsContext(_ctx, getState());
		enterRule(_localctx, 240, RULE_accessor_declarations);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1438);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << INTERNAL) | (1L << PRIVATE) | (1L << PROTECTED))) != 0)) {
				{
				setState(1437);
				((Accessor_declarationsContext)_localctx).mods = accessor_modifier();
				}
			}

			setState(1450);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case GET:
				{
				setState(1440);
				match(GET);
				setState(1441);
				accessor_body();
				setState(1443);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << INTERNAL) | (1L << PRIVATE) | (1L << PROTECTED) | (1L << SET))) != 0)) {
					{
					setState(1442);
					set_accessor_declaration();
					}
				}

				}
				break;
			case SET:
				{
				setState(1445);
				match(SET);
				setState(1446);
				accessor_body();
				setState(1448);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << GET) | (1L << INTERNAL) | (1L << PRIVATE) | (1L << PROTECTED))) != 0)) {
					{
					setState(1447);
					get_accessor_declaration();
					}
				}

				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Get_accessor_declarationContext extends ParserRuleContext {
		public TerminalNode GET() { return getToken(XiasParser.GET, 0); }
		public Accessor_bodyContext accessor_body() {
			return getRuleContext(Accessor_bodyContext.class,0);
		}
		public Accessor_modifierContext accessor_modifier() {
			return getRuleContext(Accessor_modifierContext.class,0);
		}
		public Get_accessor_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_get_accessor_declaration; }
	}

	public final Get_accessor_declarationContext get_accessor_declaration() throws RecognitionException {
		Get_accessor_declarationContext _localctx = new Get_accessor_declarationContext(_ctx, getState());
		enterRule(_localctx, 242, RULE_get_accessor_declaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1453);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << INTERNAL) | (1L << PRIVATE) | (1L << PROTECTED))) != 0)) {
				{
				setState(1452);
				accessor_modifier();
				}
			}

			setState(1455);
			match(GET);
			setState(1456);
			accessor_body();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Set_accessor_declarationContext extends ParserRuleContext {
		public TerminalNode SET() { return getToken(XiasParser.SET, 0); }
		public Accessor_bodyContext accessor_body() {
			return getRuleContext(Accessor_bodyContext.class,0);
		}
		public Accessor_modifierContext accessor_modifier() {
			return getRuleContext(Accessor_modifierContext.class,0);
		}
		public Set_accessor_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_set_accessor_declaration; }
	}

	public final Set_accessor_declarationContext set_accessor_declaration() throws RecognitionException {
		Set_accessor_declarationContext _localctx = new Set_accessor_declarationContext(_ctx, getState());
		enterRule(_localctx, 244, RULE_set_accessor_declaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1459);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << INTERNAL) | (1L << PRIVATE) | (1L << PROTECTED))) != 0)) {
				{
				setState(1458);
				accessor_modifier();
				}
			}

			setState(1461);
			match(SET);
			setState(1462);
			accessor_body();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Accessor_modifierContext extends ParserRuleContext {
		public TerminalNode PROTECTED() { return getToken(XiasParser.PROTECTED, 0); }
		public TerminalNode INTERNAL() { return getToken(XiasParser.INTERNAL, 0); }
		public TerminalNode PRIVATE() { return getToken(XiasParser.PRIVATE, 0); }
		public Accessor_modifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_accessor_modifier; }
	}

	public final Accessor_modifierContext accessor_modifier() throws RecognitionException {
		Accessor_modifierContext _localctx = new Accessor_modifierContext(_ctx, getState());
		enterRule(_localctx, 246, RULE_accessor_modifier);
		try {
			setState(1471);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,171,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(1464);
				match(PROTECTED);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(1465);
				match(INTERNAL);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(1466);
				match(PRIVATE);
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(1467);
				match(PROTECTED);
				setState(1468);
				match(INTERNAL);
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(1469);
				match(INTERNAL);
				setState(1470);
				match(PROTECTED);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Accessor_bodyContext extends ParserRuleContext {
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(XiasParser.SEMICOLON, 0); }
		public Accessor_bodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_accessor_body; }
	}

	public final Accessor_bodyContext accessor_body() throws RecognitionException {
		Accessor_bodyContext _localctx = new Accessor_bodyContext(_ctx, getState());
		enterRule(_localctx, 248, RULE_accessor_body);
		try {
			setState(1475);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case OPEN_BRACE:
				enterOuterAlt(_localctx, 1);
				{
				setState(1473);
				block();
				}
				break;
			case SEMICOLON:
				enterOuterAlt(_localctx, 2);
				{
				setState(1474);
				match(SEMICOLON);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Overloadable_operatorContext extends ParserRuleContext {
		public TerminalNode PLUS() { return getToken(XiasParser.PLUS, 0); }
		public TerminalNode MINUS() { return getToken(XiasParser.MINUS, 0); }
		public TerminalNode BANG() { return getToken(XiasParser.BANG, 0); }
		public TerminalNode TILDE() { return getToken(XiasParser.TILDE, 0); }
		public TerminalNode OP_INC() { return getToken(XiasParser.OP_INC, 0); }
		public TerminalNode OP_DEC() { return getToken(XiasParser.OP_DEC, 0); }
		public TerminalNode TRUE() { return getToken(XiasParser.TRUE, 0); }
		public TerminalNode FALSE() { return getToken(XiasParser.FALSE, 0); }
		public TerminalNode STAR() { return getToken(XiasParser.STAR, 0); }
		public TerminalNode DIV() { return getToken(XiasParser.DIV, 0); }
		public TerminalNode PERCENT() { return getToken(XiasParser.PERCENT, 0); }
		public TerminalNode AMP() { return getToken(XiasParser.AMP, 0); }
		public TerminalNode BITWISE_OR() { return getToken(XiasParser.BITWISE_OR, 0); }
		public TerminalNode CARET() { return getToken(XiasParser.CARET, 0); }
		public TerminalNode OP_LEFT_SHIFT() { return getToken(XiasParser.OP_LEFT_SHIFT, 0); }
		public Right_shiftContext right_shift() {
			return getRuleContext(Right_shiftContext.class,0);
		}
		public TerminalNode OP_EQ() { return getToken(XiasParser.OP_EQ, 0); }
		public TerminalNode OP_NE() { return getToken(XiasParser.OP_NE, 0); }
		public TerminalNode GT() { return getToken(XiasParser.GT, 0); }
		public TerminalNode LT() { return getToken(XiasParser.LT, 0); }
		public TerminalNode OP_GE() { return getToken(XiasParser.OP_GE, 0); }
		public TerminalNode OP_LE() { return getToken(XiasParser.OP_LE, 0); }
		public Overloadable_operatorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_overloadable_operator; }
	}

	public final Overloadable_operatorContext overloadable_operator() throws RecognitionException {
		Overloadable_operatorContext _localctx = new Overloadable_operatorContext(_ctx, getState());
		enterRule(_localctx, 250, RULE_overloadable_operator);
		try {
			setState(1499);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,173,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(1477);
				match(PLUS);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(1478);
				match(MINUS);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(1479);
				match(BANG);
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(1480);
				match(TILDE);
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(1481);
				match(OP_INC);
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(1482);
				match(OP_DEC);
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(1483);
				match(TRUE);
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(1484);
				match(FALSE);
				}
				break;
			case 9:
				enterOuterAlt(_localctx, 9);
				{
				setState(1485);
				match(STAR);
				}
				break;
			case 10:
				enterOuterAlt(_localctx, 10);
				{
				setState(1486);
				match(DIV);
				}
				break;
			case 11:
				enterOuterAlt(_localctx, 11);
				{
				setState(1487);
				match(PERCENT);
				}
				break;
			case 12:
				enterOuterAlt(_localctx, 12);
				{
				setState(1488);
				match(AMP);
				}
				break;
			case 13:
				enterOuterAlt(_localctx, 13);
				{
				setState(1489);
				match(BITWISE_OR);
				}
				break;
			case 14:
				enterOuterAlt(_localctx, 14);
				{
				setState(1490);
				match(CARET);
				}
				break;
			case 15:
				enterOuterAlt(_localctx, 15);
				{
				setState(1491);
				match(OP_LEFT_SHIFT);
				}
				break;
			case 16:
				enterOuterAlt(_localctx, 16);
				{
				setState(1492);
				right_shift();
				}
				break;
			case 17:
				enterOuterAlt(_localctx, 17);
				{
				setState(1493);
				match(OP_EQ);
				}
				break;
			case 18:
				enterOuterAlt(_localctx, 18);
				{
				setState(1494);
				match(OP_NE);
				}
				break;
			case 19:
				enterOuterAlt(_localctx, 19);
				{
				setState(1495);
				match(GT);
				}
				break;
			case 20:
				enterOuterAlt(_localctx, 20);
				{
				setState(1496);
				match(LT);
				}
				break;
			case 21:
				enterOuterAlt(_localctx, 21);
				{
				setState(1497);
				match(OP_GE);
				}
				break;
			case 22:
				enterOuterAlt(_localctx, 22);
				{
				setState(1498);
				match(OP_LE);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Conversion_operator_declaratorContext extends ParserRuleContext {
		public TerminalNode OPERATOR() { return getToken(XiasParser.OPERATOR, 0); }
		public Type_Context type_() {
			return getRuleContext(Type_Context.class,0);
		}
		public TerminalNode OPEN_PARENS() { return getToken(XiasParser.OPEN_PARENS, 0); }
		public Arg_declarationContext arg_declaration() {
			return getRuleContext(Arg_declarationContext.class,0);
		}
		public TerminalNode CLOSE_PARENS() { return getToken(XiasParser.CLOSE_PARENS, 0); }
		public TerminalNode IMPLICIT() { return getToken(XiasParser.IMPLICIT, 0); }
		public TerminalNode EXPLICIT() { return getToken(XiasParser.EXPLICIT, 0); }
		public Conversion_operator_declaratorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_conversion_operator_declarator; }
	}

	public final Conversion_operator_declaratorContext conversion_operator_declarator() throws RecognitionException {
		Conversion_operator_declaratorContext _localctx = new Conversion_operator_declaratorContext(_ctx, getState());
		enterRule(_localctx, 252, RULE_conversion_operator_declarator);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1501);
			_la = _input.LA(1);
			if ( !(_la==EXPLICIT || _la==IMPLICIT) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			setState(1502);
			match(OPERATOR);
			setState(1503);
			type_();
			setState(1504);
			match(OPEN_PARENS);
			setState(1505);
			arg_declaration();
			setState(1506);
			match(CLOSE_PARENS);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Constructor_initializerContext extends ParserRuleContext {
		public TerminalNode COLON() { return getToken(XiasParser.COLON, 0); }
		public TerminalNode OPEN_PARENS() { return getToken(XiasParser.OPEN_PARENS, 0); }
		public TerminalNode CLOSE_PARENS() { return getToken(XiasParser.CLOSE_PARENS, 0); }
		public TerminalNode BASE() { return getToken(XiasParser.BASE, 0); }
		public TerminalNode THIS() { return getToken(XiasParser.THIS, 0); }
		public Argument_listContext argument_list() {
			return getRuleContext(Argument_listContext.class,0);
		}
		public Constructor_initializerContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constructor_initializer; }
	}

	public final Constructor_initializerContext constructor_initializer() throws RecognitionException {
		Constructor_initializerContext _localctx = new Constructor_initializerContext(_ctx, getState());
		enterRule(_localctx, 254, RULE_constructor_initializer);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1508);
			match(COLON);
			setState(1509);
			_la = _input.LA(1);
			if ( !(_la==BASE || _la==THIS) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			setState(1510);
			match(OPEN_PARENS);
			setState(1512);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << BASE) | (1L << BOOL) | (1L << CHAR) | (1L << DEFAULT) | (1L << DOUBLE) | (1L << FALSE) | (1L << FLOAT) | (1L << GET) | (1L << IN) | (1L << INT) | (1L << NAMEOF) | (1L << NEW) | (1L << NULL_) | (1L << OBJECT) | (1L << OUT) | (1L << REF) | (1L << SET) | (1L << SIZEOF) | (1L << STRING) | (1L << THIS) | (1L << TRUE) | (1L << TYPEOF) | (1L << UINT))) != 0) || ((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & ((1L << (VAR - 64)) | (1L << (VOID - 64)) | (1L << (WHEN - 64)) | (1L << (WHERE - 64)) | (1L << (IDENTIFIER - 64)) | (1L << (LITERAL_ACCESS - 64)) | (1L << (INTEGER_LITERAL - 64)) | (1L << (HEX_INTEGER_LITERAL - 64)) | (1L << (REAL_LITERAL - 64)) | (1L << (CHARACTER_LITERAL - 64)) | (1L << (REGULAR_STRING - 64)) | (1L << (VERBATIUM_STRING - 64)) | (1L << (OPEN_PARENS - 64)) | (1L << (PLUS - 64)) | (1L << (MINUS - 64)) | (1L << (STAR - 64)) | (1L << (BANG - 64)) | (1L << (TILDE - 64)) | (1L << (OP_INC - 64)) | (1L << (OP_DEC - 64)))) != 0)) {
				{
				setState(1511);
				argument_list();
				}
			}

			setState(1514);
			match(CLOSE_PARENS);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BodyContext extends ParserRuleContext {
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(XiasParser.SEMICOLON, 0); }
		public BodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_body; }
	}

	public final BodyContext body() throws RecognitionException {
		BodyContext _localctx = new BodyContext(_ctx, getState());
		enterRule(_localctx, 256, RULE_body);
		try {
			setState(1518);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case OPEN_BRACE:
				enterOuterAlt(_localctx, 1);
				{
				setState(1516);
				block();
				}
				break;
			case SEMICOLON:
				enterOuterAlt(_localctx, 2);
				{
				setState(1517);
				match(SEMICOLON);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Array_typeContext extends ParserRuleContext {
		public Base_typeContext base_type() {
			return getRuleContext(Base_typeContext.class,0);
		}
		public List<Rank_specifierContext> rank_specifier() {
			return getRuleContexts(Rank_specifierContext.class);
		}
		public Rank_specifierContext rank_specifier(int i) {
			return getRuleContext(Rank_specifierContext.class,i);
		}
		public List<TerminalNode> STAR() { return getTokens(XiasParser.STAR); }
		public TerminalNode STAR(int i) {
			return getToken(XiasParser.STAR, i);
		}
		public List<TerminalNode> INTERR() { return getTokens(XiasParser.INTERR); }
		public TerminalNode INTERR(int i) {
			return getToken(XiasParser.INTERR, i);
		}
		public Array_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_array_type; }
	}

	public final Array_typeContext array_type() throws RecognitionException {
		Array_typeContext _localctx = new Array_typeContext(_ctx, getState());
		enterRule(_localctx, 258, RULE_array_type);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1520);
			base_type();
			setState(1528); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(1524);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==STAR || _la==INTERR) {
					{
					{
					setState(1521);
					_la = _input.LA(1);
					if ( !(_la==STAR || _la==INTERR) ) {
					_errHandler.recoverInline(this);
					}
					else {
						if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
						_errHandler.reportMatch(this);
						consume();
					}
					}
					}
					setState(1526);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(1527);
				rank_specifier();
				}
				}
				setState(1530); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( ((((_la - 80)) & ~0x3f) == 0 && ((1L << (_la - 80)) & ((1L << (OPEN_BRACKET - 80)) | (1L << (STAR - 80)) | (1L << (INTERR - 80)))) != 0) );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Rank_specifierContext extends ParserRuleContext {
		public TerminalNode OPEN_BRACKET() { return getToken(XiasParser.OPEN_BRACKET, 0); }
		public TerminalNode CLOSE_BRACKET() { return getToken(XiasParser.CLOSE_BRACKET, 0); }
		public List<TerminalNode> COMMA() { return getTokens(XiasParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(XiasParser.COMMA, i);
		}
		public Rank_specifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_rank_specifier; }
	}

	public final Rank_specifierContext rank_specifier() throws RecognitionException {
		Rank_specifierContext _localctx = new Rank_specifierContext(_ctx, getState());
		enterRule(_localctx, 260, RULE_rank_specifier);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1532);
			match(OPEN_BRACKET);
			setState(1536);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(1533);
				match(COMMA);
				}
				}
				setState(1538);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(1539);
			match(CLOSE_BRACKET);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Array_initializerContext extends ParserRuleContext {
		public TerminalNode OPEN_BRACE() { return getToken(XiasParser.OPEN_BRACE, 0); }
		public TerminalNode CLOSE_BRACE() { return getToken(XiasParser.CLOSE_BRACE, 0); }
		public List<Variable_initializerContext> variable_initializer() {
			return getRuleContexts(Variable_initializerContext.class);
		}
		public Variable_initializerContext variable_initializer(int i) {
			return getRuleContext(Variable_initializerContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(XiasParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(XiasParser.COMMA, i);
		}
		public Array_initializerContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_array_initializer; }
	}

	public final Array_initializerContext array_initializer() throws RecognitionException {
		Array_initializerContext _localctx = new Array_initializerContext(_ctx, getState());
		enterRule(_localctx, 262, RULE_array_initializer);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(1541);
			match(OPEN_BRACE);
			setState(1553);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << BASE) | (1L << BOOL) | (1L << CHAR) | (1L << DEFAULT) | (1L << DOUBLE) | (1L << FALSE) | (1L << FLOAT) | (1L << GET) | (1L << INT) | (1L << NAMEOF) | (1L << NEW) | (1L << NULL_) | (1L << OBJECT) | (1L << REF) | (1L << SET) | (1L << SIZEOF) | (1L << STRING) | (1L << THIS) | (1L << TRUE) | (1L << TYPEOF) | (1L << UINT))) != 0) || ((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & ((1L << (VAR - 64)) | (1L << (WHEN - 64)) | (1L << (WHERE - 64)) | (1L << (IDENTIFIER - 64)) | (1L << (LITERAL_ACCESS - 64)) | (1L << (INTEGER_LITERAL - 64)) | (1L << (HEX_INTEGER_LITERAL - 64)) | (1L << (REAL_LITERAL - 64)) | (1L << (CHARACTER_LITERAL - 64)) | (1L << (REGULAR_STRING - 64)) | (1L << (VERBATIUM_STRING - 64)) | (1L << (OPEN_BRACE - 64)) | (1L << (OPEN_PARENS - 64)) | (1L << (PLUS - 64)) | (1L << (MINUS - 64)) | (1L << (STAR - 64)) | (1L << (BANG - 64)) | (1L << (TILDE - 64)) | (1L << (OP_INC - 64)) | (1L << (OP_DEC - 64)))) != 0)) {
				{
				setState(1542);
				variable_initializer();
				setState(1547);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,179,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(1543);
						match(COMMA);
						setState(1544);
						variable_initializer();
						}
						} 
					}
					setState(1549);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,179,_ctx);
				}
				setState(1551);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==COMMA) {
					{
					setState(1550);
					match(COMMA);
					}
				}

				}
			}

			setState(1555);
			match(CLOSE_BRACE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Variant_type_parameter_listContext extends ParserRuleContext {
		public TerminalNode LT() { return getToken(XiasParser.LT, 0); }
		public List<Variant_type_parameterContext> variant_type_parameter() {
			return getRuleContexts(Variant_type_parameterContext.class);
		}
		public Variant_type_parameterContext variant_type_parameter(int i) {
			return getRuleContext(Variant_type_parameterContext.class,i);
		}
		public TerminalNode GT() { return getToken(XiasParser.GT, 0); }
		public List<TerminalNode> COMMA() { return getTokens(XiasParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(XiasParser.COMMA, i);
		}
		public Variant_type_parameter_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variant_type_parameter_list; }
	}

	public final Variant_type_parameter_listContext variant_type_parameter_list() throws RecognitionException {
		Variant_type_parameter_listContext _localctx = new Variant_type_parameter_listContext(_ctx, getState());
		enterRule(_localctx, 264, RULE_variant_type_parameter_list);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1557);
			match(LT);
			setState(1558);
			variant_type_parameter();
			setState(1563);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(1559);
				match(COMMA);
				setState(1560);
				variant_type_parameter();
				}
				}
				setState(1565);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(1566);
			match(GT);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Variant_type_parameterContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public Variance_annotationContext variance_annotation() {
			return getRuleContext(Variance_annotationContext.class,0);
		}
		public Variant_type_parameterContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variant_type_parameter; }
	}

	public final Variant_type_parameterContext variant_type_parameter() throws RecognitionException {
		Variant_type_parameterContext _localctx = new Variant_type_parameterContext(_ctx, getState());
		enterRule(_localctx, 266, RULE_variant_type_parameter);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1569);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==IN || _la==OUT) {
				{
				setState(1568);
				variance_annotation();
				}
			}

			setState(1571);
			identifier();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Variance_annotationContext extends ParserRuleContext {
		public TerminalNode IN() { return getToken(XiasParser.IN, 0); }
		public TerminalNode OUT() { return getToken(XiasParser.OUT, 0); }
		public Variance_annotationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variance_annotation; }
	}

	public final Variance_annotationContext variance_annotation() throws RecognitionException {
		Variance_annotationContext _localctx = new Variance_annotationContext(_ctx, getState());
		enterRule(_localctx, 268, RULE_variance_annotation);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1573);
			_la = _input.LA(1);
			if ( !(_la==IN || _la==OUT) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Interface_baseContext extends ParserRuleContext {
		public TerminalNode COLON() { return getToken(XiasParser.COLON, 0); }
		public Interface_type_listContext interface_type_list() {
			return getRuleContext(Interface_type_listContext.class,0);
		}
		public Interface_baseContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_interface_base; }
	}

	public final Interface_baseContext interface_base() throws RecognitionException {
		Interface_baseContext _localctx = new Interface_baseContext(_ctx, getState());
		enterRule(_localctx, 270, RULE_interface_base);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1575);
			match(COLON);
			setState(1576);
			interface_type_list();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Interface_bodyContext extends ParserRuleContext {
		public TerminalNode OPEN_BRACE() { return getToken(XiasParser.OPEN_BRACE, 0); }
		public TerminalNode CLOSE_BRACE() { return getToken(XiasParser.CLOSE_BRACE, 0); }
		public List<Interface_member_declarationContext> interface_member_declaration() {
			return getRuleContexts(Interface_member_declarationContext.class);
		}
		public Interface_member_declarationContext interface_member_declaration(int i) {
			return getRuleContext(Interface_member_declarationContext.class,i);
		}
		public Interface_bodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_interface_body; }
	}

	public final Interface_bodyContext interface_body() throws RecognitionException {
		Interface_bodyContext _localctx = new Interface_bodyContext(_ctx, getState());
		enterRule(_localctx, 272, RULE_interface_body);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1578);
			match(OPEN_BRACE);
			setState(1582);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (((((_la - 9)) & ~0x3f) == 0 && ((1L << (_la - 9)) & ((1L << (BOOL - 9)) | (1L << (CHAR - 9)) | (1L << (DOUBLE - 9)) | (1L << (FLOAT - 9)) | (1L << (GET - 9)) | (1L << (INT - 9)) | (1L << (NAMEOF - 9)) | (1L << (NEW - 9)) | (1L << (OBJECT - 9)) | (1L << (READONLY - 9)) | (1L << (REF - 9)) | (1L << (SET - 9)) | (1L << (STRING - 9)) | (1L << (UINT - 9)) | (1L << (VAR - 9)) | (1L << (VOID - 9)) | (1L << (WHEN - 9)) | (1L << (WHERE - 9)) | (1L << (IDENTIFIER - 9)))) != 0)) {
				{
				{
				setState(1579);
				interface_member_declaration();
				}
				}
				setState(1584);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(1585);
			match(CLOSE_BRACE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Interface_member_declarationContext extends ParserRuleContext {
		public Type_Context type_() {
			return getRuleContext(Type_Context.class,0);
		}
		public TerminalNode VOID() { return getToken(XiasParser.VOID, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode OPEN_PARENS() { return getToken(XiasParser.OPEN_PARENS, 0); }
		public TerminalNode CLOSE_PARENS() { return getToken(XiasParser.CLOSE_PARENS, 0); }
		public TerminalNode SEMICOLON() { return getToken(XiasParser.SEMICOLON, 0); }
		public TerminalNode NEW() { return getToken(XiasParser.NEW, 0); }
		public TerminalNode OPEN_BRACE() { return getToken(XiasParser.OPEN_BRACE, 0); }
		public Interface_accessorsContext interface_accessors() {
			return getRuleContext(Interface_accessorsContext.class,0);
		}
		public TerminalNode CLOSE_BRACE() { return getToken(XiasParser.CLOSE_BRACE, 0); }
		public TerminalNode THIS() { return getToken(XiasParser.THIS, 0); }
		public TerminalNode OPEN_BRACKET() { return getToken(XiasParser.OPEN_BRACKET, 0); }
		public Formal_parameter_listContext formal_parameter_list() {
			return getRuleContext(Formal_parameter_listContext.class,0);
		}
		public TerminalNode CLOSE_BRACKET() { return getToken(XiasParser.CLOSE_BRACKET, 0); }
		public TerminalNode REF() { return getToken(XiasParser.REF, 0); }
		public TerminalNode READONLY() { return getToken(XiasParser.READONLY, 0); }
		public Type_parameter_listContext type_parameter_list() {
			return getRuleContext(Type_parameter_listContext.class,0);
		}
		public Type_parameter_constraints_clausesContext type_parameter_constraints_clauses() {
			return getRuleContext(Type_parameter_constraints_clausesContext.class,0);
		}
		public Interface_member_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_interface_member_declaration; }
	}

	public final Interface_member_declarationContext interface_member_declaration() throws RecognitionException {
		Interface_member_declarationContext _localctx = new Interface_member_declarationContext(_ctx, getState());
		enterRule(_localctx, 274, RULE_interface_member_declaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1588);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==NEW) {
				{
				setState(1587);
				match(NEW);
				}
			}

			setState(1642);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,194,_ctx) ) {
			case 1:
				{
				setState(1595);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,186,_ctx) ) {
				case 1:
					{
					setState(1590);
					match(REF);
					}
					break;
				case 2:
					{
					setState(1591);
					match(REF);
					setState(1592);
					match(READONLY);
					}
					break;
				case 3:
					{
					setState(1593);
					match(READONLY);
					setState(1594);
					match(REF);
					}
					break;
				}
				setState(1597);
				type_();
				setState(1625);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,190,_ctx) ) {
				case 1:
					{
					setState(1598);
					identifier();
					setState(1600);
					_errHandler.sync(this);
					_la = _input.LA(1);
					if (_la==LT) {
						{
						setState(1599);
						type_parameter_list();
						}
					}

					setState(1602);
					match(OPEN_PARENS);
					setState(1604);
					_errHandler.sync(this);
					_la = _input.LA(1);
					if (((((_la - 9)) & ~0x3f) == 0 && ((1L << (_la - 9)) & ((1L << (BOOL - 9)) | (1L << (CHAR - 9)) | (1L << (DOUBLE - 9)) | (1L << (FLOAT - 9)) | (1L << (GET - 9)) | (1L << (IN - 9)) | (1L << (INT - 9)) | (1L << (NAMEOF - 9)) | (1L << (OBJECT - 9)) | (1L << (OUT - 9)) | (1L << (PARAMS - 9)) | (1L << (REF - 9)) | (1L << (SET - 9)) | (1L << (STRING - 9)) | (1L << (THIS - 9)) | (1L << (UINT - 9)) | (1L << (VAR - 9)) | (1L << (VOID - 9)) | (1L << (WHEN - 9)) | (1L << (WHERE - 9)) | (1L << (IDENTIFIER - 9)))) != 0)) {
						{
						setState(1603);
						formal_parameter_list();
						}
					}

					setState(1606);
					match(CLOSE_PARENS);
					setState(1608);
					_errHandler.sync(this);
					_la = _input.LA(1);
					if (_la==WHERE) {
						{
						setState(1607);
						type_parameter_constraints_clauses();
						}
					}

					setState(1610);
					match(SEMICOLON);
					}
					break;
				case 2:
					{
					setState(1612);
					identifier();
					setState(1613);
					match(OPEN_BRACE);
					setState(1614);
					interface_accessors();
					setState(1615);
					match(CLOSE_BRACE);
					}
					break;
				case 3:
					{
					setState(1617);
					match(THIS);
					setState(1618);
					match(OPEN_BRACKET);
					setState(1619);
					formal_parameter_list();
					setState(1620);
					match(CLOSE_BRACKET);
					setState(1621);
					match(OPEN_BRACE);
					setState(1622);
					interface_accessors();
					setState(1623);
					match(CLOSE_BRACE);
					}
					break;
				}
				}
				break;
			case 2:
				{
				setState(1627);
				match(VOID);
				setState(1628);
				identifier();
				setState(1630);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==LT) {
					{
					setState(1629);
					type_parameter_list();
					}
				}

				setState(1632);
				match(OPEN_PARENS);
				setState(1634);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (((((_la - 9)) & ~0x3f) == 0 && ((1L << (_la - 9)) & ((1L << (BOOL - 9)) | (1L << (CHAR - 9)) | (1L << (DOUBLE - 9)) | (1L << (FLOAT - 9)) | (1L << (GET - 9)) | (1L << (IN - 9)) | (1L << (INT - 9)) | (1L << (NAMEOF - 9)) | (1L << (OBJECT - 9)) | (1L << (OUT - 9)) | (1L << (PARAMS - 9)) | (1L << (REF - 9)) | (1L << (SET - 9)) | (1L << (STRING - 9)) | (1L << (THIS - 9)) | (1L << (UINT - 9)) | (1L << (VAR - 9)) | (1L << (VOID - 9)) | (1L << (WHEN - 9)) | (1L << (WHERE - 9)) | (1L << (IDENTIFIER - 9)))) != 0)) {
					{
					setState(1633);
					formal_parameter_list();
					}
				}

				setState(1636);
				match(CLOSE_PARENS);
				setState(1638);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==WHERE) {
					{
					setState(1637);
					type_parameter_constraints_clauses();
					}
				}

				setState(1640);
				match(SEMICOLON);
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Interface_accessorsContext extends ParserRuleContext {
		public TerminalNode GET() { return getToken(XiasParser.GET, 0); }
		public List<TerminalNode> SEMICOLON() { return getTokens(XiasParser.SEMICOLON); }
		public TerminalNode SEMICOLON(int i) {
			return getToken(XiasParser.SEMICOLON, i);
		}
		public TerminalNode SET() { return getToken(XiasParser.SET, 0); }
		public Interface_accessorsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_interface_accessors; }
	}

	public final Interface_accessorsContext interface_accessors() throws RecognitionException {
		Interface_accessorsContext _localctx = new Interface_accessorsContext(_ctx, getState());
		enterRule(_localctx, 276, RULE_interface_accessors);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1656);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case GET:
				{
				setState(1644);
				match(GET);
				setState(1645);
				match(SEMICOLON);
				setState(1648);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==SET) {
					{
					setState(1646);
					match(SET);
					setState(1647);
					match(SEMICOLON);
					}
				}

				}
				break;
			case SET:
				{
				setState(1650);
				match(SET);
				setState(1651);
				match(SEMICOLON);
				setState(1654);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==GET) {
					{
					setState(1652);
					match(GET);
					setState(1653);
					match(SEMICOLON);
					}
				}

				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Enum_baseContext extends ParserRuleContext {
		public TerminalNode COLON() { return getToken(XiasParser.COLON, 0); }
		public Integral_typeContext integral_type() {
			return getRuleContext(Integral_typeContext.class,0);
		}
		public Enum_baseContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_enum_base; }
	}

	public final Enum_baseContext enum_base() throws RecognitionException {
		Enum_baseContext _localctx = new Enum_baseContext(_ctx, getState());
		enterRule(_localctx, 278, RULE_enum_base);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1658);
			match(COLON);
			setState(1659);
			integral_type();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Enum_bodyContext extends ParserRuleContext {
		public TerminalNode OPEN_BRACE() { return getToken(XiasParser.OPEN_BRACE, 0); }
		public TerminalNode CLOSE_BRACE() { return getToken(XiasParser.CLOSE_BRACE, 0); }
		public List<Enum_member_declarationContext> enum_member_declaration() {
			return getRuleContexts(Enum_member_declarationContext.class);
		}
		public Enum_member_declarationContext enum_member_declaration(int i) {
			return getRuleContext(Enum_member_declarationContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(XiasParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(XiasParser.COMMA, i);
		}
		public Enum_bodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_enum_body; }
	}

	public final Enum_bodyContext enum_body() throws RecognitionException {
		Enum_bodyContext _localctx = new Enum_bodyContext(_ctx, getState());
		enterRule(_localctx, 280, RULE_enum_body);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(1661);
			match(OPEN_BRACE);
			setState(1673);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (((((_la - 28)) & ~0x3f) == 0 && ((1L << (_la - 28)) & ((1L << (GET - 28)) | (1L << (NAMEOF - 28)) | (1L << (SET - 28)) | (1L << (VAR - 28)) | (1L << (WHEN - 28)) | (1L << (WHERE - 28)) | (1L << (IDENTIFIER - 28)))) != 0)) {
				{
				setState(1662);
				enum_member_declaration();
				setState(1667);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,198,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(1663);
						match(COMMA);
						setState(1664);
						enum_member_declaration();
						}
						} 
					}
					setState(1669);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,198,_ctx);
				}
				setState(1671);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==COMMA) {
					{
					setState(1670);
					match(COMMA);
					}
				}

				}
			}

			setState(1675);
			match(CLOSE_BRACE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Enum_member_declarationContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode ASSIGNMENT() { return getToken(XiasParser.ASSIGNMENT, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Enum_member_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_enum_member_declaration; }
	}

	public final Enum_member_declarationContext enum_member_declaration() throws RecognitionException {
		Enum_member_declarationContext _localctx = new Enum_member_declarationContext(_ctx, getState());
		enterRule(_localctx, 282, RULE_enum_member_declaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1677);
			identifier();
			setState(1680);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==ASSIGNMENT) {
				{
				setState(1678);
				match(ASSIGNMENT);
				setState(1679);
				expression();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Right_arrowContext extends ParserRuleContext {
		public Token first;
		public Token second;
		public TerminalNode ASSIGNMENT() { return getToken(XiasParser.ASSIGNMENT, 0); }
		public TerminalNode GT() { return getToken(XiasParser.GT, 0); }
		public Right_arrowContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_right_arrow; }
	}

	public final Right_arrowContext right_arrow() throws RecognitionException {
		Right_arrowContext _localctx = new Right_arrowContext(_ctx, getState());
		enterRule(_localctx, 284, RULE_right_arrow);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1682);
			((Right_arrowContext)_localctx).first = match(ASSIGNMENT);
			setState(1683);
			((Right_arrowContext)_localctx).second = match(GT);
			setState(1684);
			if (!((((Right_arrowContext)_localctx).first!=null?((Right_arrowContext)_localctx).first.getTokenIndex():0) + 1 == (((Right_arrowContext)_localctx).second!=null?((Right_arrowContext)_localctx).second.getTokenIndex():0))) throw new FailedPredicateException(this, "$first.index + 1 == $second.index");
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Right_shiftContext extends ParserRuleContext {
		public Token first;
		public Token second;
		public List<TerminalNode> GT() { return getTokens(XiasParser.GT); }
		public TerminalNode GT(int i) {
			return getToken(XiasParser.GT, i);
		}
		public Right_shiftContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_right_shift; }
	}

	public final Right_shiftContext right_shift() throws RecognitionException {
		Right_shiftContext _localctx = new Right_shiftContext(_ctx, getState());
		enterRule(_localctx, 286, RULE_right_shift);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1686);
			((Right_shiftContext)_localctx).first = match(GT);
			setState(1687);
			((Right_shiftContext)_localctx).second = match(GT);
			setState(1688);
			if (!((((Right_shiftContext)_localctx).first!=null?((Right_shiftContext)_localctx).first.getTokenIndex():0) + 1 == (((Right_shiftContext)_localctx).second!=null?((Right_shiftContext)_localctx).second.getTokenIndex():0))) throw new FailedPredicateException(this, "$first.index + 1 == $second.index");
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Right_shift_assignmentContext extends ParserRuleContext {
		public Token first;
		public Token second;
		public TerminalNode GT() { return getToken(XiasParser.GT, 0); }
		public TerminalNode OP_GE() { return getToken(XiasParser.OP_GE, 0); }
		public Right_shift_assignmentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_right_shift_assignment; }
	}

	public final Right_shift_assignmentContext right_shift_assignment() throws RecognitionException {
		Right_shift_assignmentContext _localctx = new Right_shift_assignmentContext(_ctx, getState());
		enterRule(_localctx, 288, RULE_right_shift_assignment);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1690);
			((Right_shift_assignmentContext)_localctx).first = match(GT);
			setState(1691);
			((Right_shift_assignmentContext)_localctx).second = match(OP_GE);
			setState(1692);
			if (!((((Right_shift_assignmentContext)_localctx).first!=null?((Right_shift_assignmentContext)_localctx).first.getTokenIndex():0) + 1 == (((Right_shift_assignmentContext)_localctx).second!=null?((Right_shift_assignmentContext)_localctx).second.getTokenIndex():0))) throw new FailedPredicateException(this, "$first.index + 1 == $second.index");
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LiteralContext extends ParserRuleContext {
		public Boolean_literalContext boolean_literal() {
			return getRuleContext(Boolean_literalContext.class,0);
		}
		public String_literalContext string_literal() {
			return getRuleContext(String_literalContext.class,0);
		}
		public TerminalNode INTEGER_LITERAL() { return getToken(XiasParser.INTEGER_LITERAL, 0); }
		public TerminalNode HEX_INTEGER_LITERAL() { return getToken(XiasParser.HEX_INTEGER_LITERAL, 0); }
		public TerminalNode REAL_LITERAL() { return getToken(XiasParser.REAL_LITERAL, 0); }
		public TerminalNode CHARACTER_LITERAL() { return getToken(XiasParser.CHARACTER_LITERAL, 0); }
		public TerminalNode NULL_() { return getToken(XiasParser.NULL_, 0); }
		public LiteralContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_literal; }
	}

	public final LiteralContext literal() throws RecognitionException {
		LiteralContext _localctx = new LiteralContext(_ctx, getState());
		enterRule(_localctx, 290, RULE_literal);
		try {
			setState(1701);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case FALSE:
			case TRUE:
				enterOuterAlt(_localctx, 1);
				{
				setState(1694);
				boolean_literal();
				}
				break;
			case REGULAR_STRING:
			case VERBATIUM_STRING:
				enterOuterAlt(_localctx, 2);
				{
				setState(1695);
				string_literal();
				}
				break;
			case INTEGER_LITERAL:
				enterOuterAlt(_localctx, 3);
				{
				setState(1696);
				match(INTEGER_LITERAL);
				}
				break;
			case HEX_INTEGER_LITERAL:
				enterOuterAlt(_localctx, 4);
				{
				setState(1697);
				match(HEX_INTEGER_LITERAL);
				}
				break;
			case REAL_LITERAL:
				enterOuterAlt(_localctx, 5);
				{
				setState(1698);
				match(REAL_LITERAL);
				}
				break;
			case CHARACTER_LITERAL:
				enterOuterAlt(_localctx, 6);
				{
				setState(1699);
				match(CHARACTER_LITERAL);
				}
				break;
			case NULL_:
				enterOuterAlt(_localctx, 7);
				{
				setState(1700);
				match(NULL_);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Boolean_literalContext extends ParserRuleContext {
		public TerminalNode TRUE() { return getToken(XiasParser.TRUE, 0); }
		public TerminalNode FALSE() { return getToken(XiasParser.FALSE, 0); }
		public Boolean_literalContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_boolean_literal; }
	}

	public final Boolean_literalContext boolean_literal() throws RecognitionException {
		Boolean_literalContext _localctx = new Boolean_literalContext(_ctx, getState());
		enterRule(_localctx, 292, RULE_boolean_literal);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1703);
			_la = _input.LA(1);
			if ( !(_la==FALSE || _la==TRUE) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class String_literalContext extends ParserRuleContext {
		public TerminalNode REGULAR_STRING() { return getToken(XiasParser.REGULAR_STRING, 0); }
		public TerminalNode VERBATIUM_STRING() { return getToken(XiasParser.VERBATIUM_STRING, 0); }
		public String_literalContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_string_literal; }
	}

	public final String_literalContext string_literal() throws RecognitionException {
		String_literalContext _localctx = new String_literalContext(_ctx, getState());
		enterRule(_localctx, 294, RULE_string_literal);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1705);
			_la = _input.LA(1);
			if ( !(_la==REGULAR_STRING || _la==VERBATIUM_STRING) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class KeywordContext extends ParserRuleContext {
		public TerminalNode ABSTRACT() { return getToken(XiasParser.ABSTRACT, 0); }
		public TerminalNode AS() { return getToken(XiasParser.AS, 0); }
		public TerminalNode BASE() { return getToken(XiasParser.BASE, 0); }
		public TerminalNode BOOL() { return getToken(XiasParser.BOOL, 0); }
		public TerminalNode BREAK() { return getToken(XiasParser.BREAK, 0); }
		public TerminalNode CASE() { return getToken(XiasParser.CASE, 0); }
		public TerminalNode CATCH() { return getToken(XiasParser.CATCH, 0); }
		public TerminalNode CHAR() { return getToken(XiasParser.CHAR, 0); }
		public TerminalNode CLASS() { return getToken(XiasParser.CLASS, 0); }
		public TerminalNode CONST() { return getToken(XiasParser.CONST, 0); }
		public TerminalNode CONTINUE() { return getToken(XiasParser.CONTINUE, 0); }
		public TerminalNode DEFAULT() { return getToken(XiasParser.DEFAULT, 0); }
		public TerminalNode DO() { return getToken(XiasParser.DO, 0); }
		public TerminalNode DOUBLE() { return getToken(XiasParser.DOUBLE, 0); }
		public TerminalNode ELSE() { return getToken(XiasParser.ELSE, 0); }
		public TerminalNode ENUM() { return getToken(XiasParser.ENUM, 0); }
		public TerminalNode EXPLICIT() { return getToken(XiasParser.EXPLICIT, 0); }
		public TerminalNode FALSE() { return getToken(XiasParser.FALSE, 0); }
		public TerminalNode FINALLY() { return getToken(XiasParser.FINALLY, 0); }
		public TerminalNode FLOAT() { return getToken(XiasParser.FLOAT, 0); }
		public TerminalNode FOR() { return getToken(XiasParser.FOR, 0); }
		public TerminalNode FOREACH() { return getToken(XiasParser.FOREACH, 0); }
		public TerminalNode GET() { return getToken(XiasParser.GET, 0); }
		public TerminalNode GOTO() { return getToken(XiasParser.GOTO, 0); }
		public TerminalNode IF() { return getToken(XiasParser.IF, 0); }
		public TerminalNode IMPLICIT() { return getToken(XiasParser.IMPLICIT, 0); }
		public TerminalNode IN() { return getToken(XiasParser.IN, 0); }
		public TerminalNode INT() { return getToken(XiasParser.INT, 0); }
		public TerminalNode INTERFACE() { return getToken(XiasParser.INTERFACE, 0); }
		public TerminalNode INTERNAL() { return getToken(XiasParser.INTERNAL, 0); }
		public TerminalNode NAMEOF() { return getToken(XiasParser.NAMEOF, 0); }
		public TerminalNode NAMESPACE() { return getToken(XiasParser.NAMESPACE, 0); }
		public TerminalNode NEW() { return getToken(XiasParser.NEW, 0); }
		public TerminalNode NULL_() { return getToken(XiasParser.NULL_, 0); }
		public TerminalNode OBJECT() { return getToken(XiasParser.OBJECT, 0); }
		public TerminalNode OPERATOR() { return getToken(XiasParser.OPERATOR, 0); }
		public TerminalNode OUT() { return getToken(XiasParser.OUT, 0); }
		public TerminalNode OVERRIDE() { return getToken(XiasParser.OVERRIDE, 0); }
		public TerminalNode PARAMS() { return getToken(XiasParser.PARAMS, 0); }
		public TerminalNode PRIVATE() { return getToken(XiasParser.PRIVATE, 0); }
		public TerminalNode PROTECTED() { return getToken(XiasParser.PROTECTED, 0); }
		public TerminalNode PUBLIC() { return getToken(XiasParser.PUBLIC, 0); }
		public TerminalNode READONLY() { return getToken(XiasParser.READONLY, 0); }
		public TerminalNode REF() { return getToken(XiasParser.REF, 0); }
		public TerminalNode RETURN() { return getToken(XiasParser.RETURN, 0); }
		public TerminalNode SEALED() { return getToken(XiasParser.SEALED, 0); }
		public TerminalNode SET() { return getToken(XiasParser.SET, 0); }
		public TerminalNode SIZEOF() { return getToken(XiasParser.SIZEOF, 0); }
		public TerminalNode STATIC() { return getToken(XiasParser.STATIC, 0); }
		public TerminalNode STRING() { return getToken(XiasParser.STRING, 0); }
		public TerminalNode SWITCH() { return getToken(XiasParser.SWITCH, 0); }
		public TerminalNode THIS() { return getToken(XiasParser.THIS, 0); }
		public TerminalNode THROW() { return getToken(XiasParser.THROW, 0); }
		public TerminalNode TRUE() { return getToken(XiasParser.TRUE, 0); }
		public TerminalNode TRY() { return getToken(XiasParser.TRY, 0); }
		public TerminalNode TYPEOF() { return getToken(XiasParser.TYPEOF, 0); }
		public TerminalNode UINT() { return getToken(XiasParser.UINT, 0); }
		public TerminalNode USING() { return getToken(XiasParser.USING, 0); }
		public TerminalNode VAR() { return getToken(XiasParser.VAR, 0); }
		public TerminalNode VIRTUAL() { return getToken(XiasParser.VIRTUAL, 0); }
		public TerminalNode VOID() { return getToken(XiasParser.VOID, 0); }
		public TerminalNode WHEN() { return getToken(XiasParser.WHEN, 0); }
		public TerminalNode WHERE() { return getToken(XiasParser.WHERE, 0); }
		public TerminalNode WHILE() { return getToken(XiasParser.WHILE, 0); }
		public KeywordContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_keyword; }
	}

	public final KeywordContext keyword() throws RecognitionException {
		KeywordContext _localctx = new KeywordContext(_ctx, getState());
		enterRule(_localctx, 296, RULE_keyword);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1707);
			_la = _input.LA(1);
			if ( !(((((_la - 6)) & ~0x3f) == 0 && ((1L << (_la - 6)) & ((1L << (ABSTRACT - 6)) | (1L << (AS - 6)) | (1L << (BASE - 6)) | (1L << (BOOL - 6)) | (1L << (BREAK - 6)) | (1L << (CASE - 6)) | (1L << (CATCH - 6)) | (1L << (CHAR - 6)) | (1L << (CLASS - 6)) | (1L << (CONST - 6)) | (1L << (CONTINUE - 6)) | (1L << (DEFAULT - 6)) | (1L << (DO - 6)) | (1L << (DOUBLE - 6)) | (1L << (ELSE - 6)) | (1L << (ENUM - 6)) | (1L << (EXPLICIT - 6)) | (1L << (FALSE - 6)) | (1L << (FINALLY - 6)) | (1L << (FLOAT - 6)) | (1L << (FOR - 6)) | (1L << (FOREACH - 6)) | (1L << (GET - 6)) | (1L << (GOTO - 6)) | (1L << (IF - 6)) | (1L << (IMPLICIT - 6)) | (1L << (IN - 6)) | (1L << (INT - 6)) | (1L << (INTERFACE - 6)) | (1L << (INTERNAL - 6)) | (1L << (NAMEOF - 6)) | (1L << (NAMESPACE - 6)) | (1L << (NEW - 6)) | (1L << (NULL_ - 6)) | (1L << (OBJECT - 6)) | (1L << (OPERATOR - 6)) | (1L << (OUT - 6)) | (1L << (OVERRIDE - 6)) | (1L << (PARAMS - 6)) | (1L << (PRIVATE - 6)) | (1L << (PROTECTED - 6)) | (1L << (PUBLIC - 6)) | (1L << (READONLY - 6)) | (1L << (REF - 6)) | (1L << (RETURN - 6)) | (1L << (SEALED - 6)) | (1L << (SET - 6)) | (1L << (SIZEOF - 6)) | (1L << (STATIC - 6)) | (1L << (STRING - 6)) | (1L << (SWITCH - 6)) | (1L << (THIS - 6)) | (1L << (THROW - 6)) | (1L << (TRUE - 6)) | (1L << (TRY - 6)) | (1L << (TYPEOF - 6)) | (1L << (UINT - 6)) | (1L << (USING - 6)) | (1L << (VAR - 6)) | (1L << (VIRTUAL - 6)) | (1L << (VOID - 6)) | (1L << (WHEN - 6)) | (1L << (WHERE - 6)) | (1L << (WHILE - 6)))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Class_definitionContext extends ParserRuleContext {
		public TerminalNode CLASS() { return getToken(XiasParser.CLASS, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public Class_bodyContext class_body() {
			return getRuleContext(Class_bodyContext.class,0);
		}
		public Type_parameter_listContext type_parameter_list() {
			return getRuleContext(Type_parameter_listContext.class,0);
		}
		public Class_baseContext class_base() {
			return getRuleContext(Class_baseContext.class,0);
		}
		public Type_parameter_constraints_clausesContext type_parameter_constraints_clauses() {
			return getRuleContext(Type_parameter_constraints_clausesContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(XiasParser.SEMICOLON, 0); }
		public Class_definitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_class_definition; }
	}

	public final Class_definitionContext class_definition() throws RecognitionException {
		Class_definitionContext _localctx = new Class_definitionContext(_ctx, getState());
		enterRule(_localctx, 298, RULE_class_definition);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1709);
			match(CLASS);
			setState(1710);
			identifier();
			setState(1712);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LT) {
				{
				setState(1711);
				type_parameter_list();
				}
			}

			setState(1715);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==COLON) {
				{
				setState(1714);
				class_base();
				}
			}

			setState(1718);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WHERE) {
				{
				setState(1717);
				type_parameter_constraints_clauses();
				}
			}

			setState(1720);
			class_body();
			setState(1722);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==SEMICOLON) {
				{
				setState(1721);
				match(SEMICOLON);
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Interface_definitionContext extends ParserRuleContext {
		public TerminalNode INTERFACE() { return getToken(XiasParser.INTERFACE, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public Class_bodyContext class_body() {
			return getRuleContext(Class_bodyContext.class,0);
		}
		public Variant_type_parameter_listContext variant_type_parameter_list() {
			return getRuleContext(Variant_type_parameter_listContext.class,0);
		}
		public Interface_baseContext interface_base() {
			return getRuleContext(Interface_baseContext.class,0);
		}
		public Type_parameter_constraints_clausesContext type_parameter_constraints_clauses() {
			return getRuleContext(Type_parameter_constraints_clausesContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(XiasParser.SEMICOLON, 0); }
		public Interface_definitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_interface_definition; }
	}

	public final Interface_definitionContext interface_definition() throws RecognitionException {
		Interface_definitionContext _localctx = new Interface_definitionContext(_ctx, getState());
		enterRule(_localctx, 300, RULE_interface_definition);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1724);
			match(INTERFACE);
			setState(1725);
			identifier();
			setState(1727);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LT) {
				{
				setState(1726);
				variant_type_parameter_list();
				}
			}

			setState(1730);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==COLON) {
				{
				setState(1729);
				interface_base();
				}
			}

			setState(1733);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WHERE) {
				{
				setState(1732);
				type_parameter_constraints_clauses();
				}
			}

			setState(1735);
			class_body();
			setState(1737);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==SEMICOLON) {
				{
				setState(1736);
				match(SEMICOLON);
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Enum_definitionContext extends ParserRuleContext {
		public TerminalNode ENUM() { return getToken(XiasParser.ENUM, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public Enum_bodyContext enum_body() {
			return getRuleContext(Enum_bodyContext.class,0);
		}
		public Enum_baseContext enum_base() {
			return getRuleContext(Enum_baseContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(XiasParser.SEMICOLON, 0); }
		public Enum_definitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_enum_definition; }
	}

	public final Enum_definitionContext enum_definition() throws RecognitionException {
		Enum_definitionContext _localctx = new Enum_definitionContext(_ctx, getState());
		enterRule(_localctx, 302, RULE_enum_definition);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1739);
			match(ENUM);
			setState(1740);
			identifier();
			setState(1742);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==COLON) {
				{
				setState(1741);
				enum_base();
				}
			}

			setState(1744);
			enum_body();
			setState(1746);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==SEMICOLON) {
				{
				setState(1745);
				match(SEMICOLON);
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Field_declarationContext extends ParserRuleContext {
		public Variable_declaratorsContext variable_declarators() {
			return getRuleContext(Variable_declaratorsContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(XiasParser.SEMICOLON, 0); }
		public Field_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_field_declaration; }
	}

	public final Field_declarationContext field_declaration() throws RecognitionException {
		Field_declarationContext _localctx = new Field_declarationContext(_ctx, getState());
		enterRule(_localctx, 304, RULE_field_declaration);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1748);
			variable_declarators();
			setState(1749);
			match(SEMICOLON);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Property_declarationContext extends ParserRuleContext {
		public Member_nameContext member_name() {
			return getRuleContext(Member_nameContext.class,0);
		}
		public TerminalNode OPEN_BRACE() { return getToken(XiasParser.OPEN_BRACE, 0); }
		public Accessor_declarationsContext accessor_declarations() {
			return getRuleContext(Accessor_declarationsContext.class,0);
		}
		public TerminalNode CLOSE_BRACE() { return getToken(XiasParser.CLOSE_BRACE, 0); }
		public Right_arrowContext right_arrow() {
			return getRuleContext(Right_arrowContext.class,0);
		}
		public Throwable_expressionContext throwable_expression() {
			return getRuleContext(Throwable_expressionContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(XiasParser.SEMICOLON, 0); }
		public TerminalNode ASSIGNMENT() { return getToken(XiasParser.ASSIGNMENT, 0); }
		public Variable_initializerContext variable_initializer() {
			return getRuleContext(Variable_initializerContext.class,0);
		}
		public Property_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_property_declaration; }
	}

	public final Property_declarationContext property_declaration() throws RecognitionException {
		Property_declarationContext _localctx = new Property_declarationContext(_ctx, getState());
		enterRule(_localctx, 306, RULE_property_declaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1751);
			member_name();
			setState(1765);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case OPEN_BRACE:
				{
				setState(1752);
				match(OPEN_BRACE);
				setState(1753);
				accessor_declarations();
				setState(1754);
				match(CLOSE_BRACE);
				setState(1759);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==ASSIGNMENT) {
					{
					setState(1755);
					match(ASSIGNMENT);
					setState(1756);
					variable_initializer();
					setState(1757);
					match(SEMICOLON);
					}
				}

				}
				break;
			case ASSIGNMENT:
				{
				setState(1761);
				right_arrow();
				setState(1762);
				throwable_expression();
				setState(1763);
				match(SEMICOLON);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Constant_declarationContext extends ParserRuleContext {
		public TerminalNode CONST() { return getToken(XiasParser.CONST, 0); }
		public Type_Context type_() {
			return getRuleContext(Type_Context.class,0);
		}
		public Constant_declaratorsContext constant_declarators() {
			return getRuleContext(Constant_declaratorsContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(XiasParser.SEMICOLON, 0); }
		public Constant_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constant_declaration; }
	}

	public final Constant_declarationContext constant_declaration() throws RecognitionException {
		Constant_declarationContext _localctx = new Constant_declarationContext(_ctx, getState());
		enterRule(_localctx, 308, RULE_constant_declaration);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1767);
			match(CONST);
			setState(1768);
			type_();
			setState(1769);
			constant_declarators();
			setState(1770);
			match(SEMICOLON);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Indexer_declarationContext extends ParserRuleContext {
		public TerminalNode THIS() { return getToken(XiasParser.THIS, 0); }
		public TerminalNode OPEN_BRACKET() { return getToken(XiasParser.OPEN_BRACKET, 0); }
		public Formal_parameter_listContext formal_parameter_list() {
			return getRuleContext(Formal_parameter_listContext.class,0);
		}
		public TerminalNode CLOSE_BRACKET() { return getToken(XiasParser.CLOSE_BRACKET, 0); }
		public TerminalNode OPEN_BRACE() { return getToken(XiasParser.OPEN_BRACE, 0); }
		public Accessor_declarationsContext accessor_declarations() {
			return getRuleContext(Accessor_declarationsContext.class,0);
		}
		public TerminalNode CLOSE_BRACE() { return getToken(XiasParser.CLOSE_BRACE, 0); }
		public Right_arrowContext right_arrow() {
			return getRuleContext(Right_arrowContext.class,0);
		}
		public Throwable_expressionContext throwable_expression() {
			return getRuleContext(Throwable_expressionContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(XiasParser.SEMICOLON, 0); }
		public Indexer_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_indexer_declaration; }
	}

	public final Indexer_declarationContext indexer_declaration() throws RecognitionException {
		Indexer_declarationContext _localctx = new Indexer_declarationContext(_ctx, getState());
		enterRule(_localctx, 310, RULE_indexer_declaration);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1772);
			match(THIS);
			setState(1773);
			match(OPEN_BRACKET);
			setState(1774);
			formal_parameter_list();
			setState(1775);
			match(CLOSE_BRACKET);
			setState(1784);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case OPEN_BRACE:
				{
				setState(1776);
				match(OPEN_BRACE);
				setState(1777);
				accessor_declarations();
				setState(1778);
				match(CLOSE_BRACE);
				}
				break;
			case ASSIGNMENT:
				{
				setState(1780);
				right_arrow();
				setState(1781);
				throwable_expression();
				setState(1782);
				match(SEMICOLON);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Destructor_definitionContext extends ParserRuleContext {
		public TerminalNode TILDE() { return getToken(XiasParser.TILDE, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode OPEN_PARENS() { return getToken(XiasParser.OPEN_PARENS, 0); }
		public TerminalNode CLOSE_PARENS() { return getToken(XiasParser.CLOSE_PARENS, 0); }
		public BodyContext body() {
			return getRuleContext(BodyContext.class,0);
		}
		public Destructor_definitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_destructor_definition; }
	}

	public final Destructor_definitionContext destructor_definition() throws RecognitionException {
		Destructor_definitionContext _localctx = new Destructor_definitionContext(_ctx, getState());
		enterRule(_localctx, 312, RULE_destructor_definition);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1786);
			match(TILDE);
			setState(1787);
			identifier();
			setState(1788);
			match(OPEN_PARENS);
			setState(1789);
			match(CLOSE_PARENS);
			setState(1790);
			body();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Constructor_declarationContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode OPEN_PARENS() { return getToken(XiasParser.OPEN_PARENS, 0); }
		public TerminalNode CLOSE_PARENS() { return getToken(XiasParser.CLOSE_PARENS, 0); }
		public BodyContext body() {
			return getRuleContext(BodyContext.class,0);
		}
		public Formal_parameter_listContext formal_parameter_list() {
			return getRuleContext(Formal_parameter_listContext.class,0);
		}
		public Constructor_initializerContext constructor_initializer() {
			return getRuleContext(Constructor_initializerContext.class,0);
		}
		public Constructor_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constructor_declaration; }
	}

	public final Constructor_declarationContext constructor_declaration() throws RecognitionException {
		Constructor_declarationContext _localctx = new Constructor_declarationContext(_ctx, getState());
		enterRule(_localctx, 314, RULE_constructor_declaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1792);
			identifier();
			setState(1793);
			match(OPEN_PARENS);
			setState(1795);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (((((_la - 9)) & ~0x3f) == 0 && ((1L << (_la - 9)) & ((1L << (BOOL - 9)) | (1L << (CHAR - 9)) | (1L << (DOUBLE - 9)) | (1L << (FLOAT - 9)) | (1L << (GET - 9)) | (1L << (IN - 9)) | (1L << (INT - 9)) | (1L << (NAMEOF - 9)) | (1L << (OBJECT - 9)) | (1L << (OUT - 9)) | (1L << (PARAMS - 9)) | (1L << (REF - 9)) | (1L << (SET - 9)) | (1L << (STRING - 9)) | (1L << (THIS - 9)) | (1L << (UINT - 9)) | (1L << (VAR - 9)) | (1L << (VOID - 9)) | (1L << (WHEN - 9)) | (1L << (WHERE - 9)) | (1L << (IDENTIFIER - 9)))) != 0)) {
				{
				setState(1794);
				formal_parameter_list();
				}
			}

			setState(1797);
			match(CLOSE_PARENS);
			setState(1799);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==COLON) {
				{
				setState(1798);
				constructor_initializer();
				}
			}

			setState(1801);
			body();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Method_declarationContext extends ParserRuleContext {
		public Method_member_nameContext method_member_name() {
			return getRuleContext(Method_member_nameContext.class,0);
		}
		public TerminalNode OPEN_PARENS() { return getToken(XiasParser.OPEN_PARENS, 0); }
		public TerminalNode CLOSE_PARENS() { return getToken(XiasParser.CLOSE_PARENS, 0); }
		public Method_bodyContext method_body() {
			return getRuleContext(Method_bodyContext.class,0);
		}
		public Right_arrowContext right_arrow() {
			return getRuleContext(Right_arrowContext.class,0);
		}
		public Throwable_expressionContext throwable_expression() {
			return getRuleContext(Throwable_expressionContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(XiasParser.SEMICOLON, 0); }
		public Type_parameter_listContext type_parameter_list() {
			return getRuleContext(Type_parameter_listContext.class,0);
		}
		public Formal_parameter_listContext formal_parameter_list() {
			return getRuleContext(Formal_parameter_listContext.class,0);
		}
		public Type_parameter_constraints_clausesContext type_parameter_constraints_clauses() {
			return getRuleContext(Type_parameter_constraints_clausesContext.class,0);
		}
		public Method_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_method_declaration; }
	}

	public final Method_declarationContext method_declaration() throws RecognitionException {
		Method_declarationContext _localctx = new Method_declarationContext(_ctx, getState());
		enterRule(_localctx, 316, RULE_method_declaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1803);
			method_member_name();
			setState(1805);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LT) {
				{
				setState(1804);
				type_parameter_list();
				}
			}

			setState(1807);
			match(OPEN_PARENS);
			setState(1809);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (((((_la - 9)) & ~0x3f) == 0 && ((1L << (_la - 9)) & ((1L << (BOOL - 9)) | (1L << (CHAR - 9)) | (1L << (DOUBLE - 9)) | (1L << (FLOAT - 9)) | (1L << (GET - 9)) | (1L << (IN - 9)) | (1L << (INT - 9)) | (1L << (NAMEOF - 9)) | (1L << (OBJECT - 9)) | (1L << (OUT - 9)) | (1L << (PARAMS - 9)) | (1L << (REF - 9)) | (1L << (SET - 9)) | (1L << (STRING - 9)) | (1L << (THIS - 9)) | (1L << (UINT - 9)) | (1L << (VAR - 9)) | (1L << (VOID - 9)) | (1L << (WHEN - 9)) | (1L << (WHERE - 9)) | (1L << (IDENTIFIER - 9)))) != 0)) {
				{
				setState(1808);
				formal_parameter_list();
				}
			}

			setState(1811);
			match(CLOSE_PARENS);
			setState(1813);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WHERE) {
				{
				setState(1812);
				type_parameter_constraints_clauses();
				}
			}

			setState(1820);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case OPEN_BRACE:
			case SEMICOLON:
				{
				setState(1815);
				method_body();
				}
				break;
			case ASSIGNMENT:
				{
				setState(1816);
				right_arrow();
				setState(1817);
				throwable_expression();
				setState(1818);
				match(SEMICOLON);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Method_member_nameContext extends ParserRuleContext {
		public List<IdentifierContext> identifier() {
			return getRuleContexts(IdentifierContext.class);
		}
		public IdentifierContext identifier(int i) {
			return getRuleContext(IdentifierContext.class,i);
		}
		public TerminalNode DOUBLE_COLON() { return getToken(XiasParser.DOUBLE_COLON, 0); }
		public List<TerminalNode> DOT() { return getTokens(XiasParser.DOT); }
		public TerminalNode DOT(int i) {
			return getToken(XiasParser.DOT, i);
		}
		public List<Type_argument_listContext> type_argument_list() {
			return getRuleContexts(Type_argument_listContext.class);
		}
		public Type_argument_listContext type_argument_list(int i) {
			return getRuleContext(Type_argument_listContext.class,i);
		}
		public Method_member_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_method_member_name; }
	}

	public final Method_member_nameContext method_member_name() throws RecognitionException {
		Method_member_nameContext _localctx = new Method_member_nameContext(_ctx, getState());
		enterRule(_localctx, 318, RULE_method_member_name);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(1827);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,222,_ctx) ) {
			case 1:
				{
				setState(1822);
				identifier();
				}
				break;
			case 2:
				{
				setState(1823);
				identifier();
				setState(1824);
				match(DOUBLE_COLON);
				setState(1825);
				identifier();
				}
				break;
			}
			setState(1836);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,224,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(1830);
					_errHandler.sync(this);
					_la = _input.LA(1);
					if (_la==LT) {
						{
						setState(1829);
						type_argument_list();
						}
					}

					setState(1832);
					match(DOT);
					setState(1833);
					identifier();
					}
					} 
				}
				setState(1838);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,224,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Operator_declarationContext extends ParserRuleContext {
		public TerminalNode OPERATOR() { return getToken(XiasParser.OPERATOR, 0); }
		public Overloadable_operatorContext overloadable_operator() {
			return getRuleContext(Overloadable_operatorContext.class,0);
		}
		public TerminalNode OPEN_PARENS() { return getToken(XiasParser.OPEN_PARENS, 0); }
		public List<Arg_declarationContext> arg_declaration() {
			return getRuleContexts(Arg_declarationContext.class);
		}
		public Arg_declarationContext arg_declaration(int i) {
			return getRuleContext(Arg_declarationContext.class,i);
		}
		public TerminalNode CLOSE_PARENS() { return getToken(XiasParser.CLOSE_PARENS, 0); }
		public BodyContext body() {
			return getRuleContext(BodyContext.class,0);
		}
		public Right_arrowContext right_arrow() {
			return getRuleContext(Right_arrowContext.class,0);
		}
		public Throwable_expressionContext throwable_expression() {
			return getRuleContext(Throwable_expressionContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(XiasParser.SEMICOLON, 0); }
		public List<TerminalNode> IN() { return getTokens(XiasParser.IN); }
		public TerminalNode IN(int i) {
			return getToken(XiasParser.IN, i);
		}
		public TerminalNode COMMA() { return getToken(XiasParser.COMMA, 0); }
		public Operator_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_operator_declaration; }
	}

	public final Operator_declarationContext operator_declaration() throws RecognitionException {
		Operator_declarationContext _localctx = new Operator_declarationContext(_ctx, getState());
		enterRule(_localctx, 320, RULE_operator_declaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1839);
			match(OPERATOR);
			setState(1840);
			overloadable_operator();
			setState(1841);
			match(OPEN_PARENS);
			setState(1843);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==IN) {
				{
				setState(1842);
				match(IN);
				}
			}

			setState(1845);
			arg_declaration();
			setState(1851);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==COMMA) {
				{
				setState(1846);
				match(COMMA);
				setState(1848);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==IN) {
					{
					setState(1847);
					match(IN);
					}
				}

				setState(1850);
				arg_declaration();
				}
			}

			setState(1853);
			match(CLOSE_PARENS);
			setState(1859);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case OPEN_BRACE:
			case SEMICOLON:
				{
				setState(1854);
				body();
				}
				break;
			case ASSIGNMENT:
				{
				setState(1855);
				right_arrow();
				setState(1856);
				throwable_expression();
				setState(1857);
				match(SEMICOLON);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Arg_declarationContext extends ParserRuleContext {
		public Type_Context type_() {
			return getRuleContext(Type_Context.class,0);
		}
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode ASSIGNMENT() { return getToken(XiasParser.ASSIGNMENT, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Arg_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arg_declaration; }
	}

	public final Arg_declarationContext arg_declaration() throws RecognitionException {
		Arg_declarationContext _localctx = new Arg_declarationContext(_ctx, getState());
		enterRule(_localctx, 322, RULE_arg_declaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1861);
			type_();
			setState(1862);
			identifier();
			setState(1865);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==ASSIGNMENT) {
				{
				setState(1863);
				match(ASSIGNMENT);
				setState(1864);
				expression();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Method_invocationContext extends ParserRuleContext {
		public TerminalNode OPEN_PARENS() { return getToken(XiasParser.OPEN_PARENS, 0); }
		public TerminalNode CLOSE_PARENS() { return getToken(XiasParser.CLOSE_PARENS, 0); }
		public Argument_listContext argument_list() {
			return getRuleContext(Argument_listContext.class,0);
		}
		public Method_invocationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_method_invocation; }
	}

	public final Method_invocationContext method_invocation() throws RecognitionException {
		Method_invocationContext _localctx = new Method_invocationContext(_ctx, getState());
		enterRule(_localctx, 324, RULE_method_invocation);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1867);
			match(OPEN_PARENS);
			setState(1869);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << BASE) | (1L << BOOL) | (1L << CHAR) | (1L << DEFAULT) | (1L << DOUBLE) | (1L << FALSE) | (1L << FLOAT) | (1L << GET) | (1L << IN) | (1L << INT) | (1L << NAMEOF) | (1L << NEW) | (1L << NULL_) | (1L << OBJECT) | (1L << OUT) | (1L << REF) | (1L << SET) | (1L << SIZEOF) | (1L << STRING) | (1L << THIS) | (1L << TRUE) | (1L << TYPEOF) | (1L << UINT))) != 0) || ((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & ((1L << (VAR - 64)) | (1L << (VOID - 64)) | (1L << (WHEN - 64)) | (1L << (WHERE - 64)) | (1L << (IDENTIFIER - 64)) | (1L << (LITERAL_ACCESS - 64)) | (1L << (INTEGER_LITERAL - 64)) | (1L << (HEX_INTEGER_LITERAL - 64)) | (1L << (REAL_LITERAL - 64)) | (1L << (CHARACTER_LITERAL - 64)) | (1L << (REGULAR_STRING - 64)) | (1L << (VERBATIUM_STRING - 64)) | (1L << (OPEN_PARENS - 64)) | (1L << (PLUS - 64)) | (1L << (MINUS - 64)) | (1L << (STAR - 64)) | (1L << (BANG - 64)) | (1L << (TILDE - 64)) | (1L << (OP_INC - 64)) | (1L << (OP_DEC - 64)))) != 0)) {
				{
				setState(1868);
				argument_list();
				}
			}

			setState(1871);
			match(CLOSE_PARENS);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Object_creation_expressionContext extends ParserRuleContext {
		public TerminalNode OPEN_PARENS() { return getToken(XiasParser.OPEN_PARENS, 0); }
		public TerminalNode CLOSE_PARENS() { return getToken(XiasParser.CLOSE_PARENS, 0); }
		public Argument_listContext argument_list() {
			return getRuleContext(Argument_listContext.class,0);
		}
		public Object_or_collection_initializerContext object_or_collection_initializer() {
			return getRuleContext(Object_or_collection_initializerContext.class,0);
		}
		public Object_creation_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_object_creation_expression; }
	}

	public final Object_creation_expressionContext object_creation_expression() throws RecognitionException {
		Object_creation_expressionContext _localctx = new Object_creation_expressionContext(_ctx, getState());
		enterRule(_localctx, 326, RULE_object_creation_expression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1873);
			match(OPEN_PARENS);
			setState(1875);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << BASE) | (1L << BOOL) | (1L << CHAR) | (1L << DEFAULT) | (1L << DOUBLE) | (1L << FALSE) | (1L << FLOAT) | (1L << GET) | (1L << IN) | (1L << INT) | (1L << NAMEOF) | (1L << NEW) | (1L << NULL_) | (1L << OBJECT) | (1L << OUT) | (1L << REF) | (1L << SET) | (1L << SIZEOF) | (1L << STRING) | (1L << THIS) | (1L << TRUE) | (1L << TYPEOF) | (1L << UINT))) != 0) || ((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & ((1L << (VAR - 64)) | (1L << (VOID - 64)) | (1L << (WHEN - 64)) | (1L << (WHERE - 64)) | (1L << (IDENTIFIER - 64)) | (1L << (LITERAL_ACCESS - 64)) | (1L << (INTEGER_LITERAL - 64)) | (1L << (HEX_INTEGER_LITERAL - 64)) | (1L << (REAL_LITERAL - 64)) | (1L << (CHARACTER_LITERAL - 64)) | (1L << (REGULAR_STRING - 64)) | (1L << (VERBATIUM_STRING - 64)) | (1L << (OPEN_PARENS - 64)) | (1L << (PLUS - 64)) | (1L << (MINUS - 64)) | (1L << (STAR - 64)) | (1L << (BANG - 64)) | (1L << (TILDE - 64)) | (1L << (OP_INC - 64)) | (1L << (OP_DEC - 64)))) != 0)) {
				{
				setState(1874);
				argument_list();
				}
			}

			setState(1877);
			match(CLOSE_PARENS);
			setState(1879);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==OPEN_BRACE) {
				{
				setState(1878);
				object_or_collection_initializer();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IdentifierContext extends ParserRuleContext {
		public TerminalNode IDENTIFIER() { return getToken(XiasParser.IDENTIFIER, 0); }
		public TerminalNode GET() { return getToken(XiasParser.GET, 0); }
		public TerminalNode NAMEOF() { return getToken(XiasParser.NAMEOF, 0); }
		public TerminalNode SET() { return getToken(XiasParser.SET, 0); }
		public TerminalNode VAR() { return getToken(XiasParser.VAR, 0); }
		public TerminalNode WHEN() { return getToken(XiasParser.WHEN, 0); }
		public TerminalNode WHERE() { return getToken(XiasParser.WHERE, 0); }
		public IdentifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_identifier; }
	}

	public final IdentifierContext identifier() throws RecognitionException {
		IdentifierContext _localctx = new IdentifierContext(_ctx, getState());
		enterRule(_localctx, 328, RULE_identifier);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1881);
			_la = _input.LA(1);
			if ( !(((((_la - 28)) & ~0x3f) == 0 && ((1L << (_la - 28)) & ((1L << (GET - 28)) | (1L << (NAMEOF - 28)) | (1L << (SET - 28)) | (1L << (VAR - 28)) | (1L << (WHEN - 28)) | (1L << (WHERE - 28)) | (1L << (IDENTIFIER - 28)))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 142:
			return right_arrow_sempred((Right_arrowContext)_localctx, predIndex);
		case 143:
			return right_shift_sempred((Right_shiftContext)_localctx, predIndex);
		case 144:
			return right_shift_assignment_sempred((Right_shift_assignmentContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean right_arrow_sempred(Right_arrowContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return (((Right_arrowContext)_localctx).first!=null?((Right_arrowContext)_localctx).first.getTokenIndex():0) + 1 == (((Right_arrowContext)_localctx).second!=null?((Right_arrowContext)_localctx).second.getTokenIndex():0);
		}
		return true;
	}
	private boolean right_shift_sempred(Right_shiftContext _localctx, int predIndex) {
		switch (predIndex) {
		case 1:
			return (((Right_shiftContext)_localctx).first!=null?((Right_shiftContext)_localctx).first.getTokenIndex():0) + 1 == (((Right_shiftContext)_localctx).second!=null?((Right_shiftContext)_localctx).second.getTokenIndex():0);
		}
		return true;
	}
	private boolean right_shift_assignment_sempred(Right_shift_assignmentContext _localctx, int predIndex) {
		switch (predIndex) {
		case 2:
			return (((Right_shift_assignmentContext)_localctx).first!=null?((Right_shift_assignmentContext)_localctx).first.getTokenIndex():0) + 1 == (((Right_shift_assignmentContext)_localctx).second!=null?((Right_shift_assignmentContext)_localctx).second.getTokenIndex():0);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\u0082\u075e\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t+\4"+
		",\t,\4-\t-\4.\t.\4/\t/\4\60\t\60\4\61\t\61\4\62\t\62\4\63\t\63\4\64\t"+
		"\64\4\65\t\65\4\66\t\66\4\67\t\67\48\t8\49\t9\4:\t:\4;\t;\4<\t<\4=\t="+
		"\4>\t>\4?\t?\4@\t@\4A\tA\4B\tB\4C\tC\4D\tD\4E\tE\4F\tF\4G\tG\4H\tH\4I"+
		"\tI\4J\tJ\4K\tK\4L\tL\4M\tM\4N\tN\4O\tO\4P\tP\4Q\tQ\4R\tR\4S\tS\4T\tT"+
		"\4U\tU\4V\tV\4W\tW\4X\tX\4Y\tY\4Z\tZ\4[\t[\4\\\t\\\4]\t]\4^\t^\4_\t_\4"+
		"`\t`\4a\ta\4b\tb\4c\tc\4d\td\4e\te\4f\tf\4g\tg\4h\th\4i\ti\4j\tj\4k\t"+
		"k\4l\tl\4m\tm\4n\tn\4o\to\4p\tp\4q\tq\4r\tr\4s\ts\4t\tt\4u\tu\4v\tv\4"+
		"w\tw\4x\tx\4y\ty\4z\tz\4{\t{\4|\t|\4}\t}\4~\t~\4\177\t\177\4\u0080\t\u0080"+
		"\4\u0081\t\u0081\4\u0082\t\u0082\4\u0083\t\u0083\4\u0084\t\u0084\4\u0085"+
		"\t\u0085\4\u0086\t\u0086\4\u0087\t\u0087\4\u0088\t\u0088\4\u0089\t\u0089"+
		"\4\u008a\t\u008a\4\u008b\t\u008b\4\u008c\t\u008c\4\u008d\t\u008d\4\u008e"+
		"\t\u008e\4\u008f\t\u008f\4\u0090\t\u0090\4\u0091\t\u0091\4\u0092\t\u0092"+
		"\4\u0093\t\u0093\4\u0094\t\u0094\4\u0095\t\u0095\4\u0096\t\u0096\4\u0097"+
		"\t\u0097\4\u0098\t\u0098\4\u0099\t\u0099\4\u009a\t\u009a\4\u009b\t\u009b"+
		"\4\u009c\t\u009c\4\u009d\t\u009d\4\u009e\t\u009e\4\u009f\t\u009f\4\u00a0"+
		"\t\u00a0\4\u00a1\t\u00a1\4\u00a2\t\u00a2\4\u00a3\t\u00a3\4\u00a4\t\u00a4"+
		"\4\u00a5\t\u00a5\4\u00a6\t\u00a6\3\2\5\2\u014e\n\2\3\2\5\2\u0151\n\2\3"+
		"\2\3\2\3\3\3\3\5\3\u0157\n\3\3\3\5\3\u015a\n\3\3\3\3\3\3\3\5\3\u015f\n"+
		"\3\7\3\u0161\n\3\f\3\16\3\u0164\13\3\3\4\3\4\7\4\u0168\n\4\f\4\16\4\u016b"+
		"\13\4\3\5\3\5\3\5\3\5\5\5\u0171\n\5\3\6\3\6\5\6\u0175\n\6\3\7\3\7\5\7"+
		"\u0179\n\7\3\b\3\b\3\t\3\t\3\n\3\n\3\n\5\n\u0182\n\n\3\13\3\13\3\13\3"+
		"\13\7\13\u0188\n\13\f\13\16\13\u018b\13\13\3\13\3\13\3\f\3\f\3\f\7\f\u0192"+
		"\n\f\f\f\16\f\u0195\13\f\3\r\3\r\3\r\5\r\u019a\n\r\3\r\5\r\u019d\n\r\3"+
		"\r\3\r\5\r\u01a1\n\r\3\r\3\r\3\16\3\16\3\16\3\16\5\16\u01a9\n\16\3\17"+
		"\3\17\3\20\3\20\3\20\3\20\3\20\3\20\3\20\3\20\5\20\u01b5\n\20\3\21\3\21"+
		"\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\5\21\u01c2\n\21\3\22\3\22"+
		"\3\22\3\22\3\22\3\22\5\22\u01ca\n\22\3\23\3\23\3\23\3\23\5\23\u01d0\n"+
		"\23\5\23\u01d2\n\23\3\24\3\24\3\24\7\24\u01d7\n\24\f\24\16\24\u01da\13"+
		"\24\3\25\3\25\3\25\7\25\u01df\n\25\f\25\16\25\u01e2\13\25\3\26\3\26\3"+
		"\26\7\26\u01e7\n\26\f\26\16\26\u01ea\13\26\3\27\3\27\3\27\7\27\u01ef\n"+
		"\27\f\27\16\27\u01f2\13\27\3\30\3\30\3\30\7\30\u01f7\n\30\f\30\16\30\u01fa"+
		"\13\30\3\31\3\31\3\31\7\31\u01ff\n\31\f\31\16\31\u0202\13\31\3\32\3\32"+
		"\3\32\3\32\3\32\7\32\u0209\n\32\f\32\16\32\u020c\13\32\3\33\3\33\3\33"+
		"\5\33\u0211\n\33\3\33\7\33\u0214\n\33\f\33\16\33\u0217\13\33\3\34\3\34"+
		"\3\34\7\34\u021c\n\34\f\34\16\34\u021f\13\34\3\35\3\35\3\35\7\35\u0224"+
		"\n\35\f\35\16\35\u0227\13\35\3\36\3\36\3\36\3\36\3\36\5\36\u022e\n\36"+
		"\5\36\u0230\n\36\3\36\5\36\u0233\n\36\3\37\3\37\3\37\7\37\u0238\n\37\f"+
		"\37\16\37\u023b\13\37\3 \3 \5 \u023f\n \3 \3 \3 \3!\3!\3!\3!\3!\3!\3!"+
		"\3!\3!\3!\3!\3!\3!\3!\3!\3!\3!\3!\3!\3!\5!\u0258\n!\3\"\3\"\5\"\u025c"+
		"\n\"\3\"\7\"\u025f\n\"\f\"\16\"\u0262\13\"\3\"\5\"\u0265\n\"\3\"\3\"\3"+
		"\"\3\"\5\"\u026b\n\"\3\"\5\"\u026e\n\"\3\"\7\"\u0271\n\"\f\"\16\"\u0274"+
		"\13\"\3\"\5\"\u0277\n\"\7\"\u0279\n\"\f\"\16\"\u027c\13\"\3#\3#\3#\5#"+
		"\u0281\n#\3#\3#\3#\3#\3#\3#\3#\3#\3#\3#\3#\3#\5#\u028f\n#\3#\3#\3#\3#"+
		"\5#\u0295\n#\3#\3#\3#\3#\3#\3#\3#\3#\7#\u029f\n#\f#\16#\u02a2\13#\3#\5"+
		"#\u02a5\n#\3#\6#\u02a8\n#\r#\16#\u02a9\3#\3#\5#\u02ae\n#\3#\3#\3#\3#\5"+
		"#\u02b4\n#\3#\3#\3#\3#\3#\5#\u02bb\n#\3#\3#\3#\3#\3#\3#\5#\u02c3\n#\3"+
		"#\3#\3#\3#\3#\3#\3#\3#\3#\3#\7#\u02cf\n#\f#\16#\u02d2\13#\3#\3#\3#\5#"+
		"\u02d7\n#\3$\3$\5$\u02db\n$\3%\3%\3%\3&\3&\3&\5&\u02e3\n&\3\'\3\'\3\'"+
		"\3\'\7\'\u02e9\n\'\f\'\16\'\u02ec\13\'\3\'\3\'\3(\3(\3(\5(\u02f3\n(\3"+
		"(\3(\3)\3)\3*\3*\3*\7*\u02fc\n*\f*\16*\u02ff\13*\3+\3+\5+\u0303\n+\3,"+
		"\3,\3,\5,\u0308\n,\5,\u030a\n,\3,\3,\3-\3-\3-\7-\u0311\n-\f-\16-\u0314"+
		"\13-\3.\3.\3.\3.\3.\5.\u031b\n.\3.\3.\3.\3/\3/\5/\u0322\n/\3\60\3\60\3"+
		"\60\3\60\7\60\u0328\n\60\f\60\16\60\u032b\13\60\3\60\5\60\u032e\n\60\3"+
		"\60\3\60\3\61\3\61\3\61\3\61\3\61\5\61\u0337\n\61\3\62\3\62\3\62\5\62"+
		"\u033c\n\62\5\62\u033e\n\62\3\62\3\62\3\63\3\63\3\63\7\63\u0345\n\63\f"+
		"\63\16\63\u0348\13\63\3\64\3\64\3\64\3\64\3\64\5\64\u034f\n\64\3\65\3"+
		"\65\5\65\u0353\n\65\3\65\3\65\3\65\5\65\u0358\n\65\5\65\u035a\n\65\3\65"+
		"\3\65\3\65\5\65\u035f\n\65\7\65\u0361\n\65\f\65\16\65\u0364\13\65\3\66"+
		"\3\66\7\66\u0368\n\66\f\66\16\66\u036b\13\66\3\66\3\66\3\67\3\67\3\67"+
		"\7\67\u0372\n\67\f\67\16\67\u0375\13\67\3\67\5\67\u0378\n\67\3\67\5\67"+
		"\u037b\n\67\38\38\38\38\78\u0381\n8\f8\168\u0384\138\38\38\39\39\39\3"+
		"9\3:\3:\3:\3;\3;\3;\5;\u0392\n;\3<\3<\3<\3<\3<\3<\5<\u039a\n<\3=\3=\3"+
		"=\3=\3>\3>\5>\u03a2\n>\3?\3?\3?\3?\3?\3?\3?\3?\3?\3?\3?\5?\u03af\n?\3"+
		"?\3?\3?\3?\3?\3?\7?\u03b7\n?\f?\16?\u03ba\13?\3?\3?\3?\3?\3?\3?\3?\3?"+
		"\3?\3?\3?\3?\3?\3?\3?\3?\3?\3?\3?\5?\u03cf\n?\3?\3?\5?\u03d3\n?\3?\3?"+
		"\5?\u03d7\n?\3?\3?\3?\3?\3?\3?\3?\3?\3?\3?\3?\3?\3?\3?\3?\3?\3?\3?\3?"+
		"\3?\5?\u03ed\n?\3?\3?\3?\5?\u03f2\n?\3?\3?\3?\5?\u03f7\n?\3?\3?\3?\3?"+
		"\3?\5?\u03fe\n?\3?\5?\u0401\n?\3?\3?\3?\3?\3?\3?\5?\u0409\n?\3@\3@\5@"+
		"\u040d\n@\3@\3@\3A\3A\3A\3A\5A\u0415\nA\3A\3A\3A\3A\7A\u041b\nA\fA\16"+
		"A\u041e\13A\3B\3B\5B\u0422\nB\3C\3C\3C\5C\u0427\nC\3C\5C\u042a\nC\3D\3"+
		"D\5D\u042e\nD\3E\3E\3E\3E\3F\3F\5F\u0436\nF\3G\6G\u0439\nG\rG\16G\u043a"+
		"\3G\3G\3H\3H\3H\5H\u0442\nH\3H\3H\3H\3H\5H\u0448\nH\3I\3I\3I\3J\6J\u044e"+
		"\nJ\rJ\16J\u044f\3K\3K\3K\3K\7K\u0456\nK\fK\16K\u0459\13K\5K\u045b\nK"+
		"\3L\3L\3L\7L\u0460\nL\fL\16L\u0463\13L\3M\3M\7M\u0467\nM\fM\16M\u046a"+
		"\13M\3M\5M\u046d\nM\3M\5M\u0470\nM\3N\3N\3N\3N\5N\u0476\nN\3N\3N\5N\u047a"+
		"\nN\3N\3N\3O\3O\5O\u0480\nO\3O\3O\3P\3P\3P\3P\3P\3Q\3Q\3Q\3R\3R\5R\u048e"+
		"\nR\3S\3S\3S\3S\5S\u0494\nS\3T\3T\3T\7T\u0499\nT\fT\16T\u049c\13T\3U\3"+
		"U\5U\u04a0\nU\3U\5U\u04a3\nU\3U\3U\3V\6V\u04a8\nV\rV\16V\u04a9\3W\3W\3"+
		"W\3W\3W\3W\3W\3W\3W\3W\3W\3W\3W\3W\3W\5W\u04bb\nW\3X\6X\u04be\nX\rX\16"+
		"X\u04bf\3Y\3Y\5Y\u04c4\nY\3Z\5Z\u04c7\nZ\3Z\3Z\3Z\5Z\u04cc\nZ\3[\3[\3"+
		"[\3[\5[\u04d2\n[\3\\\3\\\3\\\3\\\7\\\u04d8\n\\\f\\\16\\\u04db\13\\\3\\"+
		"\3\\\3]\3]\3^\3^\3^\3^\7^\u04e5\n^\f^\16^\u04e8\13^\3_\3_\3_\7_\u04ed"+
		"\n_\f_\16_\u04f0\13_\3`\6`\u04f3\n`\r`\16`\u04f4\3a\3a\3a\3a\3a\3b\3b"+
		"\3b\3b\5b\u0500\nb\3b\3b\5b\u0504\nb\5b\u0506\nb\3c\3c\5c\u050a\nc\3d"+
		"\3d\3d\7d\u050f\nd\fd\16d\u0512\13d\3e\3e\3e\3e\3f\3f\5f\u051a\nf\3f\3"+
		"f\3g\6g\u051f\ng\rg\16g\u0520\3h\5h\u0524\nh\3h\3h\5h\u0528\nh\3i\6i\u052b"+
		"\ni\ri\16i\u052c\3j\3j\3k\3k\3k\3k\3k\3k\3k\3k\5k\u0539\nk\3k\3k\3k\3"+
		"k\3k\3k\5k\u0541\nk\3l\3l\3l\3l\3l\5l\u0548\nl\3l\3l\3l\3l\3l\3l\3l\3"+
		"l\3l\3l\5l\u0554\nl\3m\3m\3m\7m\u0559\nm\fm\16m\u055c\13m\3n\3n\3n\3n"+
		"\3o\3o\3o\7o\u0565\no\fo\16o\u0568\13o\3p\3p\3p\5p\u056d\np\3q\3q\5q\u0571"+
		"\nq\3r\3r\5r\u0575\nr\3s\3s\3t\3t\5t\u057b\nt\3u\3u\3u\3u\5u\u0581\nu"+
		"\5u\u0583\nu\3v\3v\3v\7v\u0588\nv\fv\16v\u058b\13v\3w\5w\u058e\nw\3w\3"+
		"w\3x\3x\3x\3x\3x\3x\3x\3x\5x\u059a\nx\3y\3y\3y\3y\3z\5z\u05a1\nz\3z\3"+
		"z\3z\5z\u05a6\nz\3z\3z\3z\5z\u05ab\nz\5z\u05ad\nz\3{\5{\u05b0\n{\3{\3"+
		"{\3{\3|\5|\u05b6\n|\3|\3|\3|\3}\3}\3}\3}\3}\3}\3}\5}\u05c2\n}\3~\3~\5"+
		"~\u05c6\n~\3\177\3\177\3\177\3\177\3\177\3\177\3\177\3\177\3\177\3\177"+
		"\3\177\3\177\3\177\3\177\3\177\3\177\3\177\3\177\3\177\3\177\3\177\3\177"+
		"\5\177\u05de\n\177\3\u0080\3\u0080\3\u0080\3\u0080\3\u0080\3\u0080\3\u0080"+
		"\3\u0081\3\u0081\3\u0081\3\u0081\5\u0081\u05eb\n\u0081\3\u0081\3\u0081"+
		"\3\u0082\3\u0082\5\u0082\u05f1\n\u0082\3\u0083\3\u0083\7\u0083\u05f5\n"+
		"\u0083\f\u0083\16\u0083\u05f8\13\u0083\3\u0083\6\u0083\u05fb\n\u0083\r"+
		"\u0083\16\u0083\u05fc\3\u0084\3\u0084\7\u0084\u0601\n\u0084\f\u0084\16"+
		"\u0084\u0604\13\u0084\3\u0084\3\u0084\3\u0085\3\u0085\3\u0085\3\u0085"+
		"\7\u0085\u060c\n\u0085\f\u0085\16\u0085\u060f\13\u0085\3\u0085\5\u0085"+
		"\u0612\n\u0085\5\u0085\u0614\n\u0085\3\u0085\3\u0085\3\u0086\3\u0086\3"+
		"\u0086\3\u0086\7\u0086\u061c\n\u0086\f\u0086\16\u0086\u061f\13\u0086\3"+
		"\u0086\3\u0086\3\u0087\5\u0087\u0624\n\u0087\3\u0087\3\u0087\3\u0088\3"+
		"\u0088\3\u0089\3\u0089\3\u0089\3\u008a\3\u008a\7\u008a\u062f\n\u008a\f"+
		"\u008a\16\u008a\u0632\13\u008a\3\u008a\3\u008a\3\u008b\5\u008b\u0637\n"+
		"\u008b\3\u008b\3\u008b\3\u008b\3\u008b\3\u008b\5\u008b\u063e\n\u008b\3"+
		"\u008b\3\u008b\3\u008b\5\u008b\u0643\n\u008b\3\u008b\3\u008b\5\u008b\u0647"+
		"\n\u008b\3\u008b\3\u008b\5\u008b\u064b\n\u008b\3\u008b\3\u008b\3\u008b"+
		"\3\u008b\3\u008b\3\u008b\3\u008b\3\u008b\3\u008b\3\u008b\3\u008b\3\u008b"+
		"\3\u008b\3\u008b\3\u008b\5\u008b\u065c\n\u008b\3\u008b\3\u008b\3\u008b"+
		"\5\u008b\u0661\n\u008b\3\u008b\3\u008b\5\u008b\u0665\n\u008b\3\u008b\3"+
		"\u008b\5\u008b\u0669\n\u008b\3\u008b\3\u008b\5\u008b\u066d\n\u008b\3\u008c"+
		"\3\u008c\3\u008c\3\u008c\5\u008c\u0673\n\u008c\3\u008c\3\u008c\3\u008c"+
		"\3\u008c\5\u008c\u0679\n\u008c\5\u008c\u067b\n\u008c\3\u008d\3\u008d\3"+
		"\u008d\3\u008e\3\u008e\3\u008e\3\u008e\7\u008e\u0684\n\u008e\f\u008e\16"+
		"\u008e\u0687\13\u008e\3\u008e\5\u008e\u068a\n\u008e\5\u008e\u068c\n\u008e"+
		"\3\u008e\3\u008e\3\u008f\3\u008f\3\u008f\5\u008f\u0693\n\u008f\3\u0090"+
		"\3\u0090\3\u0090\3\u0090\3\u0091\3\u0091\3\u0091\3\u0091\3\u0092\3\u0092"+
		"\3\u0092\3\u0092\3\u0093\3\u0093\3\u0093\3\u0093\3\u0093\3\u0093\3\u0093"+
		"\5\u0093\u06a8\n\u0093\3\u0094\3\u0094\3\u0095\3\u0095\3\u0096\3\u0096"+
		"\3\u0097\3\u0097\3\u0097\5\u0097\u06b3\n\u0097\3\u0097\5\u0097\u06b6\n"+
		"\u0097\3\u0097\5\u0097\u06b9\n\u0097\3\u0097\3\u0097\5\u0097\u06bd\n\u0097"+
		"\3\u0098\3\u0098\3\u0098\5\u0098\u06c2\n\u0098\3\u0098\5\u0098\u06c5\n"+
		"\u0098\3\u0098\5\u0098\u06c8\n\u0098\3\u0098\3\u0098\5\u0098\u06cc\n\u0098"+
		"\3\u0099\3\u0099\3\u0099\5\u0099\u06d1\n\u0099\3\u0099\3\u0099\5\u0099"+
		"\u06d5\n\u0099\3\u009a\3\u009a\3\u009a\3\u009b\3\u009b\3\u009b\3\u009b"+
		"\3\u009b\3\u009b\3\u009b\3\u009b\5\u009b\u06e2\n\u009b\3\u009b\3\u009b"+
		"\3\u009b\3\u009b\5\u009b\u06e8\n\u009b\3\u009c\3\u009c\3\u009c\3\u009c"+
		"\3\u009c\3\u009d\3\u009d\3\u009d\3\u009d\3\u009d\3\u009d\3\u009d\3\u009d"+
		"\3\u009d\3\u009d\3\u009d\3\u009d\5\u009d\u06fb\n\u009d\3\u009e\3\u009e"+
		"\3\u009e\3\u009e\3\u009e\3\u009e\3\u009f\3\u009f\3\u009f\5\u009f\u0706"+
		"\n\u009f\3\u009f\3\u009f\5\u009f\u070a\n\u009f\3\u009f\3\u009f\3\u00a0"+
		"\3\u00a0\5\u00a0\u0710\n\u00a0\3\u00a0\3\u00a0\5\u00a0\u0714\n\u00a0\3"+
		"\u00a0\3\u00a0\5\u00a0\u0718\n\u00a0\3\u00a0\3\u00a0\3\u00a0\3\u00a0\3"+
		"\u00a0\5\u00a0\u071f\n\u00a0\3\u00a1\3\u00a1\3\u00a1\3\u00a1\3\u00a1\5"+
		"\u00a1\u0726\n\u00a1\3\u00a1\5\u00a1\u0729\n\u00a1\3\u00a1\3\u00a1\7\u00a1"+
		"\u072d\n\u00a1\f\u00a1\16\u00a1\u0730\13\u00a1\3\u00a2\3\u00a2\3\u00a2"+
		"\3\u00a2\5\u00a2\u0736\n\u00a2\3\u00a2\3\u00a2\3\u00a2\5\u00a2\u073b\n"+
		"\u00a2\3\u00a2\5\u00a2\u073e\n\u00a2\3\u00a2\3\u00a2\3\u00a2\3\u00a2\3"+
		"\u00a2\3\u00a2\5\u00a2\u0746\n\u00a2\3\u00a3\3\u00a3\3\u00a3\3\u00a3\5"+
		"\u00a3\u074c\n\u00a3\3\u00a4\3\u00a4\5\u00a4\u0750\n\u00a4\3\u00a4\3\u00a4"+
		"\3\u00a5\3\u00a5\5\u00a5\u0756\n\u00a5\3\u00a5\3\u00a5\5\u00a5\u075a\n"+
		"\u00a5\3\u00a6\3\u00a6\3\u00a6\2\2\u00a7\2\4\6\b\n\f\16\20\22\24\26\30"+
		"\32\34\36 \"$&(*,.\60\62\64\668:<>@BDFHJLNPRTVXZ\\^`bdfhjlnprtvxz|~\u0080"+
		"\u0082\u0084\u0086\u0088\u008a\u008c\u008e\u0090\u0092\u0094\u0096\u0098"+
		"\u009a\u009c\u009e\u00a0\u00a2\u00a4\u00a6\u00a8\u00aa\u00ac\u00ae\u00b0"+
		"\u00b2\u00b4\u00b6\u00b8\u00ba\u00bc\u00be\u00c0\u00c2\u00c4\u00c6\u00c8"+
		"\u00ca\u00cc\u00ce\u00d0\u00d2\u00d4\u00d6\u00d8\u00da\u00dc\u00de\u00e0"+
		"\u00e2\u00e4\u00e6\u00e8\u00ea\u00ec\u00ee\u00f0\u00f2\u00f4\u00f6\u00f8"+
		"\u00fa\u00fc\u00fe\u0100\u0102\u0104\u0106\u0108\u010a\u010c\u010e\u0110"+
		"\u0112\u0114\u0116\u0118\u011a\u011c\u011e\u0120\u0122\u0124\u0126\u0128"+
		"\u012a\u012c\u012e\u0130\u0132\u0134\u0136\u0138\u013a\u013c\u013e\u0140"+
		"\u0142\u0144\u0146\u0148\u014a\2\23\5\2\17\17##@@\4\2\25\25\33\33\5\2"+
		"\"\",,\63\63\3\2op\4\2efqr\3\2Z[\3\2\\^\n\2\13\13\17\17\25\25\33\33##"+
		"**99@@\n\2\b\b%%((--/\62\65\6588CC\4\2\30\30!!\4\2\n\n;;\4\2\\\\gg\4\2"+
		"\"\",,\4\2\31\31==\3\2NO\3\2\bG\b\2\36\36&&\66\66BBEFHH\2\u0808\2\u014d"+
		"\3\2\2\2\4\u0159\3\2\2\2\6\u0165\3\2\2\2\b\u0170\3\2\2\2\n\u0174\3\2\2"+
		"\2\f\u0178\3\2\2\2\16\u017a\3\2\2\2\20\u017c\3\2\2\2\22\u0181\3\2\2\2"+
		"\24\u0183\3\2\2\2\26\u018e\3\2\2\2\30\u0199\3\2\2\2\32\u01a8\3\2\2\2\34"+
		"\u01aa\3\2\2\2\36\u01b4\3\2\2\2 \u01c1\3\2\2\2\"\u01c3\3\2\2\2$\u01cb"+
		"\3\2\2\2&\u01d3\3\2\2\2(\u01db\3\2\2\2*\u01e3\3\2\2\2,\u01eb\3\2\2\2."+
		"\u01f3\3\2\2\2\60\u01fb\3\2\2\2\62\u0203\3\2\2\2\64\u020d\3\2\2\2\66\u0218"+
		"\3\2\2\28\u0220\3\2\2\2:\u0228\3\2\2\2<\u0234\3\2\2\2>\u023c\3\2\2\2@"+
		"\u0257\3\2\2\2B\u0259\3\2\2\2D\u02d6\3\2\2\2F\u02da\3\2\2\2H\u02dc\3\2"+
		"\2\2J\u02df\3\2\2\2L\u02e4\3\2\2\2N\u02f2\3\2\2\2P\u02f6\3\2\2\2R\u02f8"+
		"\3\2\2\2T\u0302\3\2\2\2V\u0304\3\2\2\2X\u030d\3\2\2\2Z\u031a\3\2\2\2\\"+
		"\u0321\3\2\2\2^\u0323\3\2\2\2`\u0336\3\2\2\2b\u0338\3\2\2\2d\u0341\3\2"+
		"\2\2f\u034e\3\2\2\2h\u0350\3\2\2\2j\u0365\3\2\2\2l\u036e\3\2\2\2n\u037c"+
		"\3\2\2\2p\u0387\3\2\2\2r\u038b\3\2\2\2t\u0391\3\2\2\2v\u0399\3\2\2\2x"+
		"\u039b\3\2\2\2z\u03a1\3\2\2\2|\u0408\3\2\2\2~\u040a\3\2\2\2\u0080\u0414"+
		"\3\2\2\2\u0082\u0421\3\2\2\2\u0084\u0423\3\2\2\2\u0086\u042d\3\2\2\2\u0088"+
		"\u042f\3\2\2\2\u008a\u0435\3\2\2\2\u008c\u0438\3\2\2\2\u008e\u0447\3\2"+
		"\2\2\u0090\u0449\3\2\2\2\u0092\u044d\3\2\2\2\u0094\u045a\3\2\2\2\u0096"+
		"\u045c\3\2\2\2\u0098\u046f\3\2\2\2\u009a\u0471\3\2\2\2\u009c\u047d\3\2"+
		"\2\2\u009e\u0483\3\2\2\2\u00a0\u0488\3\2\2\2\u00a2\u048d\3\2\2\2\u00a4"+
		"\u048f\3\2\2\2\u00a6\u0495\3\2\2\2\u00a8\u049d\3\2\2\2\u00aa\u04a7\3\2"+
		"\2\2\u00ac\u04ba\3\2\2\2\u00ae\u04bd\3\2\2\2\u00b0\u04c3\3\2\2\2\u00b2"+
		"\u04c6\3\2\2\2\u00b4\u04cd\3\2\2\2\u00b6\u04d3\3\2\2\2\u00b8\u04de\3\2"+
		"\2\2\u00ba\u04e0\3\2\2\2\u00bc\u04e9\3\2\2\2\u00be\u04f2\3\2\2\2\u00c0"+
		"\u04f6\3\2\2\2\u00c2\u0505\3\2\2\2\u00c4\u0509\3\2\2\2\u00c6\u050b\3\2"+
		"\2\2\u00c8\u0513\3\2\2\2\u00ca\u0517\3\2\2\2\u00cc\u051e\3\2\2\2\u00ce"+
		"\u0523\3\2\2\2\u00d0\u052a\3\2\2\2\u00d2\u052e\3\2\2\2\u00d4\u0540\3\2"+
		"\2\2\u00d6\u0547\3\2\2\2\u00d8\u0555\3\2\2\2\u00da\u055d\3\2\2\2\u00dc"+
		"\u0561\3\2\2\2\u00de\u0569\3\2\2\2\u00e0\u0570\3\2\2\2\u00e2\u0574\3\2"+
		"\2\2\u00e4\u0576\3\2\2\2\u00e6\u057a\3\2\2\2\u00e8\u0582\3\2\2\2\u00ea"+
		"\u0584\3\2\2\2\u00ec\u058d\3\2\2\2\u00ee\u0599\3\2\2\2\u00f0\u059b\3\2"+
		"\2\2\u00f2\u05a0\3\2\2\2\u00f4\u05af\3\2\2\2\u00f6\u05b5\3\2\2\2\u00f8"+
		"\u05c1\3\2\2\2\u00fa\u05c5\3\2\2\2\u00fc\u05dd\3\2\2\2\u00fe\u05df\3\2"+
		"\2\2\u0100\u05e6\3\2\2\2\u0102\u05f0\3\2\2\2\u0104\u05f2\3\2\2\2\u0106"+
		"\u05fe\3\2\2\2\u0108\u0607\3\2\2\2\u010a\u0617\3\2\2\2\u010c\u0623\3\2"+
		"\2\2\u010e\u0627\3\2\2\2\u0110\u0629\3\2\2\2\u0112\u062c\3\2\2\2\u0114"+
		"\u0636\3\2\2\2\u0116\u067a\3\2\2\2\u0118\u067c\3\2\2\2\u011a\u067f\3\2"+
		"\2\2\u011c\u068f\3\2\2\2\u011e\u0694\3\2\2\2\u0120\u0698\3\2\2\2\u0122"+
		"\u069c\3\2\2\2\u0124\u06a7\3\2\2\2\u0126\u06a9\3\2\2\2\u0128\u06ab\3\2"+
		"\2\2\u012a\u06ad\3\2\2\2\u012c\u06af\3\2\2\2\u012e\u06be\3\2\2\2\u0130"+
		"\u06cd\3\2\2\2\u0132\u06d6\3\2\2\2\u0134\u06d9\3\2\2\2\u0136\u06e9\3\2"+
		"\2\2\u0138\u06ee\3\2\2\2\u013a\u06fc\3\2\2\2\u013c\u0702\3\2\2\2\u013e"+
		"\u070d\3\2\2\2\u0140\u0725\3\2\2\2\u0142\u0731\3\2\2\2\u0144\u0747\3\2"+
		"\2\2\u0146\u074d\3\2\2\2\u0148\u0753\3\2\2\2\u014a\u075b\3\2\2\2\u014c"+
		"\u014e\5\u00aaV\2\u014d\u014c\3\2\2\2\u014d\u014e\3\2\2\2\u014e\u0150"+
		"\3\2\2\2\u014f\u0151\5\u00aeX\2\u0150\u014f\3\2\2\2\u0150\u0151\3\2\2"+
		"\2\u0151\u0152\3\2\2\2\u0152\u0153\7\2\2\3\u0153\3\3\2\2\2\u0154\u0156"+
		"\5\u014a\u00a6\2\u0155\u0157\5\24\13\2\u0156\u0155\3\2\2\2\u0156\u0157"+
		"\3\2\2\2\u0157\u015a\3\2\2\2\u0158\u015a\5\u00b4[\2\u0159\u0154\3\2\2"+
		"\2\u0159\u0158\3\2\2\2\u015a\u0162\3\2\2\2\u015b\u015c\7V\2\2\u015c\u015e"+
		"\5\u014a\u00a6\2\u015d\u015f\5\24\13\2\u015e\u015d\3\2\2\2\u015e\u015f"+
		"\3\2\2\2\u015f\u0161\3\2\2\2\u0160\u015b\3\2\2\2\u0161\u0164\3\2\2\2\u0162"+
		"\u0160\3\2\2\2\u0162\u0163\3\2\2\2\u0163\5\3\2\2\2\u0164\u0162\3\2\2\2"+
		"\u0165\u0169\5\b\5\2\u0166\u0168\5\u0106\u0084\2\u0167\u0166\3\2\2\2\u0168"+
		"\u016b\3\2\2\2\u0169\u0167\3\2\2\2\u0169\u016a\3\2\2\2\u016a\7\3\2\2\2"+
		"\u016b\u0169\3\2\2\2\u016c\u0171\5\n\6\2\u016d\u0171\5\22\n\2\u016e\u016f"+
		"\7D\2\2\u016f\u0171\7\\\2\2\u0170\u016c\3\2\2\2\u0170\u016d\3\2\2\2\u0170"+
		"\u016e\3\2\2\2\u0171\t\3\2\2\2\u0172\u0175\5\f\7\2\u0173\u0175\7\13\2"+
		"\2\u0174\u0172\3\2\2\2\u0174\u0173\3\2\2\2\u0175\13\3\2\2\2\u0176\u0179"+
		"\5\16\b\2\u0177\u0179\5\20\t\2\u0178\u0176\3\2\2\2\u0178\u0177\3\2\2\2"+
		"\u0179\r\3\2\2\2\u017a\u017b\t\2\2\2\u017b\17\3\2\2\2\u017c\u017d\t\3"+
		"\2\2\u017d\21\3\2\2\2\u017e\u0182\5\4\3\2\u017f\u0182\7*\2\2\u0180\u0182"+
		"\79\2\2\u0181\u017e\3\2\2\2\u0181\u017f\3\2\2\2\u0181\u0180\3\2\2\2\u0182"+
		"\23\3\2\2\2\u0183\u0184\7e\2\2\u0184\u0189\5\6\4\2\u0185\u0186\7W\2\2"+
		"\u0186\u0188\5\6\4\2\u0187\u0185\3\2\2\2\u0188\u018b\3\2\2\2\u0189\u0187"+
		"\3\2\2\2\u0189\u018a\3\2\2\2\u018a\u018c\3\2\2\2\u018b\u0189\3\2\2\2\u018c"+
		"\u018d\7f\2\2\u018d\25\3\2\2\2\u018e\u0193\5\30\r\2\u018f\u0190\7W\2\2"+
		"\u0190\u0192\5\30\r\2\u0191\u018f\3\2\2\2\u0192\u0195\3\2\2\2\u0193\u0191"+
		"\3\2\2\2\u0193\u0194\3\2\2\2\u0194\27\3\2\2\2\u0195\u0193\3\2\2\2\u0196"+
		"\u0197\5\u014a\u00a6\2\u0197\u0198\7X\2\2\u0198\u019a\3\2\2\2\u0199\u0196"+
		"\3\2\2\2\u0199\u019a\3\2\2\2\u019a\u019c\3\2\2\2\u019b\u019d\t\4\2\2\u019c"+
		"\u019b\3\2\2\2\u019c\u019d\3\2\2\2\u019d\u01a0\3\2\2\2\u019e\u01a1\7B"+
		"\2\2\u019f\u01a1\5\6\4\2\u01a0\u019e\3\2\2\2\u01a0\u019f\3\2\2\2\u01a0"+
		"\u01a1\3\2\2\2\u01a1\u01a2\3\2\2\2\u01a2\u01a3\5\32\16\2\u01a3\31\3\2"+
		"\2\2\u01a4\u01a9\5\36\20\2\u01a5\u01a9\5\34\17\2\u01a6\u01a7\7\63\2\2"+
		"\u01a7\u01a9\5\34\17\2\u01a8\u01a4\3\2\2\2\u01a8\u01a5\3\2\2\2\u01a8\u01a6"+
		"\3\2\2\2\u01a9\33\3\2\2\2\u01aa\u01ab\5\"\22\2\u01ab\35\3\2\2\2\u01ac"+
		"\u01ad\5@!\2\u01ad\u01ae\5 \21\2\u01ae\u01af\5\32\16\2\u01af\u01b5\3\2"+
		"\2\2\u01b0\u01b1\5@!\2\u01b1\u01b2\7}\2\2\u01b2\u01b3\5F$\2\u01b3\u01b5"+
		"\3\2\2\2\u01b4\u01ac\3\2\2\2\u01b4\u01b0\3\2\2\2\u01b5\37\3\2\2\2\u01b6"+
		"\u01c2\7d\2\2\u01b7\u01c2\7s\2\2\u01b8\u01c2\7t\2\2\u01b9\u01c2\7u\2\2"+
		"\u01ba\u01c2\7v\2\2\u01bb\u01c2\7w\2\2\u01bc\u01c2\7x\2\2\u01bd\u01c2"+
		"\7y\2\2\u01be\u01c2\7z\2\2\u01bf\u01c2\7|\2\2\u01c0\u01c2\5\u0122\u0092"+
		"\2\u01c1\u01b6\3\2\2\2\u01c1\u01b7\3\2\2\2\u01c1\u01b8\3\2\2\2\u01c1\u01b9"+
		"\3\2\2\2\u01c1\u01ba\3\2\2\2\u01c1\u01bb\3\2\2\2\u01c1\u01bc\3\2\2\2\u01c1"+
		"\u01bd\3\2\2\2\u01c1\u01be\3\2\2\2\u01c1\u01bf\3\2\2\2\u01c1\u01c0\3\2"+
		"\2\2\u01c2!\3\2\2\2\u01c3\u01c9\5$\23\2\u01c4\u01c5\7g\2\2\u01c5\u01c6"+
		"\5F$\2\u01c6\u01c7\7X\2\2\u01c7\u01c8\5F$\2\u01c8\u01ca\3\2\2\2\u01c9"+
		"\u01c4\3\2\2\2\u01c9\u01ca\3\2\2\2\u01ca#\3\2\2\2\u01cb\u01d1\5&\24\2"+
		"\u01cc\u01cf\7i\2\2\u01cd\u01d0\5$\23\2\u01ce\u01d0\5H%\2\u01cf\u01cd"+
		"\3\2\2\2\u01cf\u01ce\3\2\2\2\u01d0\u01d2\3\2\2\2\u01d1\u01cc\3\2\2\2\u01d1"+
		"\u01d2\3\2\2\2\u01d2%\3\2\2\2\u01d3\u01d8\5(\25\2\u01d4\u01d5\7m\2\2\u01d5"+
		"\u01d7\5(\25\2\u01d6\u01d4\3\2\2\2\u01d7\u01da\3\2\2\2\u01d8\u01d6\3\2"+
		"\2\2\u01d8\u01d9\3\2\2\2\u01d9\'\3\2\2\2\u01da\u01d8\3\2\2\2\u01db\u01e0"+
		"\5*\26\2\u01dc\u01dd\7l\2\2\u01dd\u01df\5*\26\2\u01de\u01dc\3\2\2\2\u01df"+
		"\u01e2\3\2\2\2\u01e0\u01de\3\2\2\2\u01e0\u01e1\3\2\2\2\u01e1)\3\2\2\2"+
		"\u01e2\u01e0\3\2\2\2\u01e3\u01e8\5,\27\2\u01e4\u01e5\7`\2\2\u01e5\u01e7"+
		"\5,\27\2\u01e6\u01e4\3\2\2\2\u01e7\u01ea\3\2\2\2\u01e8\u01e6\3\2\2\2\u01e8"+
		"\u01e9\3\2\2\2\u01e9+\3\2\2\2\u01ea\u01e8\3\2\2\2\u01eb\u01f0\5.\30\2"+
		"\u01ec\u01ed\7a\2\2\u01ed\u01ef\5.\30\2\u01ee\u01ec\3\2\2\2\u01ef\u01f2"+
		"\3\2\2\2\u01f0\u01ee\3\2\2\2\u01f0\u01f1\3\2\2\2\u01f1-\3\2\2\2\u01f2"+
		"\u01f0\3\2\2\2\u01f3\u01f8\5\60\31\2\u01f4\u01f5\7_\2\2\u01f5\u01f7\5"+
		"\60\31\2\u01f6\u01f4\3\2\2\2\u01f7\u01fa\3\2\2\2\u01f8\u01f6\3\2\2\2\u01f8"+
		"\u01f9\3\2\2\2\u01f9/\3\2\2\2\u01fa\u01f8\3\2\2\2\u01fb\u0200\5\62\32"+
		"\2\u01fc\u01fd\t\5\2\2\u01fd\u01ff\5\62\32\2\u01fe\u01fc\3\2\2\2\u01ff"+
		"\u0202\3\2\2\2\u0200\u01fe\3\2\2\2\u0200\u0201\3\2\2\2\u0201\61\3\2\2"+
		"\2\u0202\u0200\3\2\2\2\u0203\u020a\5\64\33\2\u0204\u0205\t\6\2\2\u0205"+
		"\u0209\5\64\33\2\u0206\u0207\7\t\2\2\u0207\u0209\5\6\4\2\u0208\u0204\3"+
		"\2\2\2\u0208\u0206\3\2\2\2\u0209\u020c\3\2\2\2\u020a\u0208\3\2\2\2\u020a"+
		"\u020b\3\2\2\2\u020b\63\3\2\2\2\u020c\u020a\3\2\2\2\u020d\u0215\5\66\34"+
		"\2\u020e\u0211\7{\2\2\u020f\u0211\5\u0120\u0091\2\u0210\u020e\3\2\2\2"+
		"\u0210\u020f\3\2\2\2\u0211\u0212\3\2\2\2\u0212\u0214\5\66\34\2\u0213\u0210"+
		"\3\2\2\2\u0214\u0217\3\2\2\2\u0215\u0213\3\2\2\2\u0215\u0216\3\2\2\2\u0216"+
		"\65\3\2\2\2\u0217\u0215\3\2\2\2\u0218\u021d\58\35\2\u0219\u021a\t\7\2"+
		"\2\u021a\u021c\58\35\2\u021b\u0219\3\2\2\2\u021c\u021f\3\2\2\2\u021d\u021b"+
		"\3\2\2\2\u021d\u021e\3\2\2\2\u021e\67\3\2\2\2\u021f\u021d\3\2\2\2\u0220"+
		"\u0225\5:\36\2\u0221\u0222\t\b\2\2\u0222\u0224\5:\36\2\u0223\u0221\3\2"+
		"\2\2\u0224\u0227\3\2\2\2\u0225\u0223\3\2\2\2\u0225\u0226\3\2\2\2\u0226"+
		"9\3\2\2\2\u0227\u0225\3\2\2\2\u0228\u0232\5@!\2\u0229\u022a\7:\2\2\u022a"+
		"\u022f\7P\2\2\u022b\u022d\5<\37\2\u022c\u022e\7W\2\2\u022d\u022c\3\2\2"+
		"\2\u022d\u022e\3\2\2\2\u022e\u0230\3\2\2\2\u022f\u022b\3\2\2\2\u022f\u0230"+
		"\3\2\2\2\u0230\u0231\3\2\2\2\u0231\u0233\7Q\2\2\u0232\u0229\3\2\2\2\u0232"+
		"\u0233\3\2\2\2\u0233;\3\2\2\2\u0234\u0239\5> \2\u0235\u0236\7W\2\2\u0236"+
		"\u0238\5> \2\u0237\u0235\3\2\2\2\u0238\u023b\3\2\2\2\u0239\u0237\3\2\2"+
		"\2\u0239\u023a\3\2\2\2\u023a=\3\2\2\2\u023b\u0239\3\2\2\2\u023c\u023e"+
		"\5\32\16\2\u023d\u023f\5\u0090I\2\u023e\u023d\3\2\2\2\u023e\u023f\3\2"+
		"\2\2\u023f\u0240\3\2\2\2\u0240\u0241\5\u011e\u0090\2\u0241\u0242\5F$\2"+
		"\u0242?\3\2\2\2\u0243\u0258\5B\"\2\u0244\u0245\7Z\2\2\u0245\u0258\5@!"+
		"\2\u0246\u0247\7[\2\2\u0247\u0258\5@!\2\u0248\u0249\7b\2\2\u0249\u0258"+
		"\5@!\2\u024a\u024b\7c\2\2\u024b\u0258\5@!\2\u024c\u024d\7j\2\2\u024d\u0258"+
		"\5@!\2\u024e\u024f\7k\2\2\u024f\u0258\5@!\2\u0250\u0251\7T\2\2\u0251\u0252"+
		"\5\6\4\2\u0252\u0253\7U\2\2\u0253\u0254\5@!\2\u0254\u0258\3\2\2\2\u0255"+
		"\u0256\7\\\2\2\u0256\u0258\5@!\2\u0257\u0243\3\2\2\2\u0257\u0244\3\2\2"+
		"\2\u0257\u0246\3\2\2\2\u0257\u0248\3\2\2\2\u0257\u024a\3\2\2\2\u0257\u024c"+
		"\3\2\2\2\u0257\u024e\3\2\2\2\u0257\u0250\3\2\2\2\u0257\u0255\3\2\2\2\u0258"+
		"A\3\2\2\2\u0259\u025b\5D#\2\u025a\u025c\7b\2\2\u025b\u025a\3\2\2\2\u025b"+
		"\u025c\3\2\2\2\u025c\u0260\3\2\2\2\u025d\u025f\5L\'\2\u025e\u025d\3\2"+
		"\2\2\u025f\u0262\3\2\2\2\u0260\u025e\3\2\2\2\u0260\u0261\3\2\2\2\u0261"+
		"\u0264\3\2\2\2\u0262\u0260\3\2\2\2\u0263\u0265\7b\2\2\u0264\u0263\3\2"+
		"\2\2\u0264\u0265\3\2\2\2\u0265\u027a\3\2\2\2\u0266\u026b\5J&\2\u0267\u026b"+
		"\5\u0146\u00a4\2\u0268\u026b\7j\2\2\u0269\u026b\7k\2\2\u026a\u0266\3\2"+
		"\2\2\u026a\u0267\3\2\2\2\u026a\u0268\3\2\2\2\u026a\u0269\3\2\2\2\u026b"+
		"\u026d\3\2\2\2\u026c\u026e\7b\2\2\u026d\u026c\3\2\2\2\u026d\u026e\3\2"+
		"\2\2\u026e\u0272\3\2\2\2\u026f\u0271\5L\'\2\u0270\u026f\3\2\2\2\u0271"+
		"\u0274\3\2\2\2\u0272\u0270\3\2\2\2\u0272\u0273\3\2\2\2\u0273\u0276\3\2"+
		"\2\2\u0274\u0272\3\2\2\2\u0275\u0277\7b\2\2\u0276\u0275\3\2\2\2\u0276"+
		"\u0277\3\2\2\2\u0277\u0279\3\2\2\2\u0278\u026a\3\2\2\2\u0279\u027c\3\2"+
		"\2\2\u027a\u0278\3\2\2\2\u027a\u027b\3\2\2\2\u027bC\3\2\2\2\u027c\u027a"+
		"\3\2\2\2\u027d\u02d7\5\u0124\u0093\2\u027e\u0280\5\u014a\u00a6\2\u027f"+
		"\u0281\5\24\13\2\u0280\u027f\3\2\2\2\u0280\u0281\3\2\2\2\u0281\u02d7\3"+
		"\2\2\2\u0282\u0283\7T\2\2\u0283\u0284\5\32\16\2\u0284\u0285\7U\2\2\u0285"+
		"\u02d7\3\2\2\2\u0286\u02d7\5P)\2\u0287\u02d7\5\u00b4[\2\u0288\u02d7\7"+
		"I\2\2\u0289\u02d7\7;\2\2\u028a\u0294\7\n\2\2\u028b\u028c\7V\2\2\u028c"+
		"\u028e\5\u014a\u00a6\2\u028d\u028f\5\24\13\2\u028e\u028d\3\2\2\2\u028e"+
		"\u028f\3\2\2\2\u028f\u0295\3\2\2\2\u0290\u0291\7R\2\2\u0291\u0292\5R*"+
		"\2\u0292\u0293\7S\2\2\u0293\u0295\3\2\2\2\u0294\u028b\3\2\2\2\u0294\u0290"+
		"\3\2\2\2\u0295\u02d7\3\2\2\2\u0296\u02b3\7(\2\2\u0297\u02ad\5\6\4\2\u0298"+
		"\u02ae\5\u0148\u00a5\2\u0299\u02ae\5T+\2\u029a\u029b\7R\2\2\u029b\u029c"+
		"\5R*\2\u029c\u02a0\7S\2\2\u029d\u029f\5\u0106\u0084\2\u029e\u029d\3\2"+
		"\2\2\u029f\u02a2\3\2\2\2\u02a0\u029e\3\2\2\2\u02a0\u02a1\3\2\2\2\u02a1"+
		"\u02a4\3\2\2\2\u02a2\u02a0\3\2\2\2\u02a3\u02a5\5\u0108\u0085\2\u02a4\u02a3"+
		"\3\2\2\2\u02a4\u02a5\3\2\2\2\u02a5\u02ae\3\2\2\2\u02a6\u02a8\5\u0106\u0084"+
		"\2\u02a7\u02a6\3\2\2\2\u02a8\u02a9\3\2\2\2\u02a9\u02a7\3\2\2\2\u02a9\u02aa"+
		"\3\2\2\2\u02aa\u02ab\3\2\2\2\u02ab\u02ac\5\u0108\u0085\2\u02ac\u02ae\3"+
		"\2\2\2\u02ad\u0298\3\2\2\2\u02ad\u0299\3\2\2\2\u02ad\u029a\3\2\2\2\u02ad"+
		"\u02a7\3\2\2\2\u02ae\u02b4\3\2\2\2\u02af\u02b4\5b\62\2\u02b0\u02b1\5\u0106"+
		"\u0084\2\u02b1\u02b2\5\u0108\u0085\2\u02b2\u02b4\3\2\2\2\u02b3\u0297\3"+
		"\2\2\2\u02b3\u02af\3\2\2\2\u02b3\u02b0\3\2\2\2\u02b4\u02d7\3\2\2\2\u02b5"+
		"\u02b6\7?\2\2\u02b6\u02ba\7T\2\2\u02b7\u02bb\5h\65\2\u02b8\u02bb\5\6\4"+
		"\2\u02b9\u02bb\7D\2\2\u02ba\u02b7\3\2\2\2\u02ba\u02b8\3\2\2\2\u02ba\u02b9"+
		"\3\2\2\2\u02bb\u02bc\3\2\2\2\u02bc\u02d7\7U\2\2\u02bd\u02c2\7\23\2\2\u02be"+
		"\u02bf\7T\2\2\u02bf\u02c0\5\6\4\2\u02c0\u02c1\7U\2\2\u02c1\u02c3\3\2\2"+
		"\2\u02c2\u02be\3\2\2\2\u02c2\u02c3\3\2\2\2\u02c3\u02d7\3\2\2\2\u02c4\u02c5"+
		"\7\67\2\2\u02c5\u02c6\7T\2\2\u02c6\u02c7\5\6\4\2\u02c7\u02c8\7U\2\2\u02c8"+
		"\u02d7\3\2\2\2\u02c9\u02ca\7&\2\2\u02ca\u02d0\7T\2\2\u02cb\u02cc\5\u014a"+
		"\u00a6\2\u02cc\u02cd\7V\2\2\u02cd\u02cf\3\2\2\2\u02ce\u02cb\3\2\2\2\u02cf"+
		"\u02d2\3\2\2\2\u02d0\u02ce\3\2\2\2\u02d0\u02d1\3\2\2\2\u02d1\u02d3\3\2"+
		"\2\2\u02d2\u02d0\3\2\2\2\u02d3\u02d4\5\u014a\u00a6\2\u02d4\u02d5\7U\2"+
		"\2\u02d5\u02d7\3\2\2\2\u02d6\u027d\3\2\2\2\u02d6\u027e\3\2\2\2\u02d6\u0282"+
		"\3\2\2\2\u02d6\u0286\3\2\2\2\u02d6\u0287\3\2\2\2\u02d6\u0288\3\2\2\2\u02d6"+
		"\u0289\3\2\2\2\u02d6\u028a\3\2\2\2\u02d6\u0296\3\2\2\2\u02d6\u02b5\3\2"+
		"\2\2\u02d6\u02bd\3\2\2\2\u02d6\u02c4\3\2\2\2\u02d6\u02c9\3\2\2\2\u02d7"+
		"E\3\2\2\2\u02d8\u02db\5\32\16\2\u02d9\u02db\5H%\2\u02da\u02d8\3\2\2\2"+
		"\u02da\u02d9\3\2\2\2\u02dbG\3\2\2\2\u02dc\u02dd\7<\2\2\u02dd\u02de\5\32"+
		"\16\2\u02deI\3\2\2\2\u02df\u02e0\7V\2\2\u02e0\u02e2\5\u014a\u00a6\2\u02e1"+
		"\u02e3\5\24\13\2\u02e2\u02e1\3\2\2\2\u02e2\u02e3\3\2\2\2\u02e3K\3\2\2"+
		"\2\u02e4\u02e5\7R\2\2\u02e5\u02ea\5N(\2\u02e6\u02e7\7W\2\2\u02e7\u02e9"+
		"\5N(\2\u02e8\u02e6\3\2\2\2\u02e9\u02ec\3\2\2\2\u02ea\u02e8\3\2\2\2\u02ea"+
		"\u02eb\3\2\2\2\u02eb\u02ed\3\2\2\2\u02ec\u02ea\3\2\2\2\u02ed\u02ee\7S"+
		"\2\2\u02eeM\3\2\2\2\u02ef\u02f0\5\u014a\u00a6\2\u02f0\u02f1\7X\2\2\u02f1"+
		"\u02f3\3\2\2\2\u02f2\u02ef\3\2\2\2\u02f2\u02f3\3\2\2\2\u02f3\u02f4\3\2"+
		"\2\2\u02f4\u02f5\5\32\16\2\u02f5O\3\2\2\2\u02f6\u02f7\t\t\2\2\u02f7Q\3"+
		"\2\2\2\u02f8\u02fd\5\32\16\2\u02f9\u02fa\7W\2\2\u02fa\u02fc\5\32\16\2"+
		"\u02fb\u02f9\3\2\2\2\u02fc\u02ff\3\2\2\2\u02fd\u02fb\3\2\2\2\u02fd\u02fe"+
		"\3\2\2\2\u02feS\3\2\2\2\u02ff\u02fd\3\2\2\2\u0300\u0303\5V,\2\u0301\u0303"+
		"\5^\60\2\u0302\u0300\3\2\2\2\u0302\u0301\3\2\2\2\u0303U\3\2\2\2\u0304"+
		"\u0309\7P\2\2\u0305\u0307\5X-\2\u0306\u0308\7W\2\2\u0307\u0306\3\2\2\2"+
		"\u0307\u0308\3\2\2\2\u0308\u030a\3\2\2\2\u0309\u0305\3\2\2\2\u0309\u030a"+
		"\3\2\2\2\u030a\u030b\3\2\2\2\u030b\u030c\7Q\2\2\u030cW\3\2\2\2\u030d\u0312"+
		"\5Z.\2\u030e\u030f\7W\2\2\u030f\u0311\5Z.\2\u0310\u030e\3\2\2\2\u0311"+
		"\u0314\3\2\2\2\u0312\u0310\3\2\2\2\u0312\u0313\3\2\2\2\u0313Y\3\2\2\2"+
		"\u0314\u0312\3\2\2\2\u0315\u031b\5\u014a\u00a6\2\u0316\u0317\7R\2\2\u0317"+
		"\u0318\5\32\16\2\u0318\u0319\7S\2\2\u0319\u031b\3\2\2\2\u031a\u0315\3"+
		"\2\2\2\u031a\u0316\3\2\2\2\u031b\u031c\3\2\2\2\u031c\u031d\7d\2\2\u031d"+
		"\u031e\5\\/\2\u031e[\3\2\2\2\u031f\u0322\5\32\16\2\u0320\u0322\5T+\2\u0321"+
		"\u031f\3\2\2\2\u0321\u0320\3\2\2\2\u0322]\3\2\2\2\u0323\u0324\7P\2\2\u0324"+
		"\u0329\5`\61\2\u0325\u0326\7W\2\2\u0326\u0328\5`\61\2\u0327\u0325\3\2"+
		"\2\2\u0328\u032b\3\2\2\2\u0329\u0327\3\2\2\2\u0329\u032a\3\2\2\2\u032a"+
		"\u032d\3\2\2\2\u032b\u0329\3\2\2\2\u032c\u032e\7W\2\2\u032d\u032c\3\2"+
		"\2\2\u032d\u032e\3\2\2\2\u032e\u032f\3\2\2\2\u032f\u0330\7Q\2\2\u0330"+
		"_\3\2\2\2\u0331\u0337\5\34\17\2\u0332\u0333\7P\2\2\u0333\u0334\5R*\2\u0334"+
		"\u0335\7Q\2\2\u0335\u0337\3\2\2\2\u0336\u0331\3\2\2\2\u0336\u0332\3\2"+
		"\2\2\u0337a\3\2\2\2\u0338\u033d\7P\2\2\u0339\u033b\5d\63\2\u033a\u033c"+
		"\7W\2\2\u033b\u033a\3\2\2\2\u033b\u033c\3\2\2\2\u033c\u033e\3\2\2\2\u033d"+
		"\u0339\3\2\2\2\u033d\u033e\3\2\2\2\u033e\u033f\3\2\2\2\u033f\u0340\7Q"+
		"\2\2\u0340c\3\2\2\2\u0341\u0346\5f\64\2\u0342\u0343\7W\2\2\u0343\u0345"+
		"\5f\64\2\u0344\u0342\3\2\2\2\u0345\u0348\3\2\2\2\u0346\u0344\3\2\2\2\u0346"+
		"\u0347\3\2\2\2\u0347e\3\2\2\2\u0348\u0346\3\2\2\2\u0349\u034f\5B\"\2\u034a"+
		"\u034b\5\u014a\u00a6\2\u034b\u034c\7d\2\2\u034c\u034d\5\32\16\2\u034d"+
		"\u034f\3\2\2\2\u034e\u0349\3\2\2\2\u034e\u034a\3\2\2\2\u034fg\3\2\2\2"+
		"\u0350\u0359\5\u014a\u00a6\2\u0351\u0353\5j\66\2\u0352\u0351\3\2\2\2\u0352"+
		"\u0353\3\2\2\2\u0353\u035a\3\2\2\2\u0354\u0355\7h\2\2\u0355\u0357\5\u014a"+
		"\u00a6\2\u0356\u0358\5j\66\2\u0357\u0356\3\2\2\2\u0357\u0358\3\2\2\2\u0358"+
		"\u035a\3\2\2\2\u0359\u0352\3\2\2\2\u0359\u0354\3\2\2\2\u035a\u0362\3\2"+
		"\2\2\u035b\u035c\7V\2\2\u035c\u035e\5\u014a\u00a6\2\u035d\u035f\5j\66"+
		"\2\u035e\u035d\3\2\2\2\u035e\u035f\3\2\2\2\u035f\u0361\3\2\2\2\u0360\u035b"+
		"\3\2\2\2\u0361\u0364\3\2\2\2\u0362\u0360\3\2\2\2\u0362\u0363\3\2\2\2\u0363"+
		"i\3\2\2\2\u0364\u0362\3\2\2\2\u0365\u0369\7e\2\2\u0366\u0368\7W\2\2\u0367"+
		"\u0366\3\2\2\2\u0368\u036b\3\2\2\2\u0369\u0367\3\2\2\2\u0369\u036a\3\2"+
		"\2\2\u036a\u036c\3\2\2\2\u036b\u0369\3\2\2\2\u036c\u036d\7f\2\2\u036d"+
		"k\3\2\2\2\u036e\u0373\5\b\5\2\u036f\u0372\5\u0106\u0084\2\u0370\u0372"+
		"\7\\\2\2\u0371\u036f\3\2\2\2\u0371\u0370\3\2\2\2\u0372\u0375\3\2\2\2\u0373"+
		"\u0371\3\2\2\2\u0373\u0374\3\2\2\2\u0374\u0377\3\2\2\2\u0375\u0373\3\2"+
		"\2\2\u0376\u0378\5n8\2\u0377\u0376\3\2\2\2\u0377\u0378\3\2\2\2\u0378\u037a"+
		"\3\2\2\2\u0379\u037b\5\u014a\u00a6\2\u037a\u0379\3\2\2\2\u037a\u037b\3"+
		"\2\2\2\u037bm\3\2\2\2\u037c\u037d\7P\2\2\u037d\u0382\5p9\2\u037e\u037f"+
		"\7W\2\2\u037f\u0381\5p9\2\u0380\u037e\3\2\2\2\u0381\u0384\3\2\2\2\u0382"+
		"\u0380\3\2\2\2\u0382\u0383\3\2\2\2\u0383\u0385\3\2\2\2\u0384\u0382\3\2"+
		"\2\2\u0385\u0386\7Q\2\2\u0386o\3\2\2\2\u0387\u0388\5\u014a\u00a6\2\u0388"+
		"\u0389\7X\2\2\u0389\u038a\5\32\16\2\u038aq\3\2\2\2\u038b\u038c\7F\2\2"+
		"\u038c\u038d\5\32\16\2\u038ds\3\2\2\2\u038e\u0392\5x=\2\u038f\u0392\5"+
		"v<\2\u0390\u0392\5z>\2\u0391\u038e\3\2\2\2\u0391\u038f\3\2\2\2\u0391\u0390"+
		"\3\2\2\2\u0392u\3\2\2\2\u0393\u0394\5\u0080A\2\u0394\u0395\7Y\2\2\u0395"+
		"\u039a\3\2\2\2\u0396\u0397\5\u0088E\2\u0397\u0398\7Y\2\2\u0398\u039a\3"+
		"\2\2\2\u0399\u0393\3\2\2\2\u0399\u0396\3\2\2\2\u039aw\3\2\2\2\u039b\u039c"+
		"\5\u014a\u00a6\2\u039c\u039d\7X\2\2\u039d\u039e\5t;\2\u039ey\3\2\2\2\u039f"+
		"\u03a2\5~@\2\u03a0\u03a2\5|?\2\u03a1\u039f\3\2\2\2\u03a1\u03a0\3\2\2\2"+
		"\u03a2{\3\2\2\2\u03a3\u0409\7Y\2\2\u03a4\u03a5\5\32\16\2\u03a5\u03a6\7"+
		"Y\2\2\u03a6\u0409\3\2\2\2\u03a7\u03a8\7 \2\2\u03a8\u03a9\7T\2\2\u03a9"+
		"\u03aa\5\32\16\2\u03aa\u03ab\7U\2\2\u03ab\u03ae\5\u008aF\2\u03ac\u03ad"+
		"\7\26\2\2\u03ad\u03af\5\u008aF\2\u03ae\u03ac\3\2\2\2\u03ae\u03af\3\2\2"+
		"\2\u03af\u0409\3\2\2\2\u03b0\u03b1\7:\2\2\u03b1\u03b2\7T\2\2\u03b2\u03b3"+
		"\5\32\16\2\u03b3\u03b4\7U\2\2\u03b4\u03b8\7P\2\2\u03b5\u03b7\5\u008cG"+
		"\2\u03b6\u03b5\3\2\2\2\u03b7\u03ba\3\2\2\2\u03b8\u03b6\3\2\2\2\u03b8\u03b9"+
		"\3\2\2\2\u03b9\u03bb\3\2\2\2\u03ba\u03b8\3\2\2\2\u03bb\u03bc\7Q\2\2\u03bc"+
		"\u0409\3\2\2\2\u03bd\u03be\7G\2\2\u03be\u03bf\7T\2\2\u03bf\u03c0\5\32"+
		"\16\2\u03c0\u03c1\7U\2\2\u03c1\u03c2\5z>\2\u03c2\u0409\3\2\2\2\u03c3\u03c4"+
		"\7\24\2\2\u03c4\u03c5\5z>\2\u03c5\u03c6\7G\2\2\u03c6\u03c7\7T\2\2\u03c7"+
		"\u03c8\5\32\16\2\u03c8\u03c9\7U\2\2\u03c9\u03ca\7Y\2\2\u03ca\u0409\3\2"+
		"\2\2\u03cb\u03cc\7\34\2\2\u03cc\u03ce\7T\2\2\u03cd\u03cf\5\u0094K\2\u03ce"+
		"\u03cd\3\2\2\2\u03ce\u03cf\3\2\2\2\u03cf\u03d0\3\2\2\2\u03d0\u03d2\7Y"+
		"\2\2\u03d1\u03d3\5\32\16\2\u03d2\u03d1\3\2\2\2\u03d2\u03d3\3\2\2\2\u03d3"+
		"\u03d4\3\2\2\2\u03d4\u03d6\7Y\2\2\u03d5\u03d7\5\u0096L\2\u03d6\u03d5\3"+
		"\2\2\2\u03d6\u03d7\3\2\2\2\u03d7\u03d8\3\2\2\2\u03d8\u03d9\7U\2\2\u03d9"+
		"\u0409\5z>\2\u03da\u03db\7\35\2\2\u03db\u03dc\7T\2\2\u03dc\u03dd\5\u0082"+
		"B\2\u03dd\u03de\5\u014a\u00a6\2\u03de\u03df\7\"\2\2\u03df\u03e0\5\32\16"+
		"\2\u03e0\u03e1\7U\2\2\u03e1\u03e2\5z>\2\u03e2\u0409\3\2\2\2\u03e3\u03e4"+
		"\7\f\2\2\u03e4\u0409\7Y\2\2\u03e5\u03e6\7\22\2\2\u03e6\u0409\7Y\2\2\u03e7"+
		"\u03ec\7\37\2\2\u03e8\u03ed\5\u014a\u00a6\2\u03e9\u03ea\7\r\2\2\u03ea"+
		"\u03ed\5\32\16\2\u03eb\u03ed\7\23\2\2\u03ec\u03e8\3\2\2\2\u03ec\u03e9"+
		"\3\2\2\2\u03ec\u03eb\3\2\2\2\u03ed\u03ee\3\2\2\2\u03ee\u0409\7Y\2\2\u03ef"+
		"\u03f1\7\64\2\2\u03f0\u03f2\5\32\16\2\u03f1\u03f0\3\2\2\2\u03f1\u03f2"+
		"\3\2\2\2\u03f2\u03f3\3\2\2\2\u03f3\u0409\7Y\2\2\u03f4\u03f6\7<\2\2\u03f5"+
		"\u03f7\5\32\16\2\u03f6\u03f5\3\2\2\2\u03f6\u03f7\3\2\2\2\u03f7\u03f8\3"+
		"\2\2\2\u03f8\u0409\7Y\2\2\u03f9\u03fa\7>\2\2\u03fa\u0400\5~@\2\u03fb\u03fd"+
		"\5\u0098M\2\u03fc\u03fe\5\u00a0Q\2\u03fd\u03fc\3\2\2\2\u03fd\u03fe\3\2"+
		"\2\2\u03fe\u0401\3\2\2\2\u03ff\u0401\5\u00a0Q\2\u0400\u03fb\3\2\2\2\u0400"+
		"\u03ff\3\2\2\2\u0401\u0409\3\2\2\2\u0402\u0403\7A\2\2\u0403\u0404\7T\2"+
		"\2\u0404\u0405\5\u00a2R\2\u0405\u0406\7U\2\2\u0406\u0407\5z>\2\u0407\u0409"+
		"\3\2\2\2\u0408\u03a3\3\2\2\2\u0408\u03a4\3\2\2\2\u0408\u03a7\3\2\2\2\u0408"+
		"\u03b0\3\2\2\2\u0408\u03bd\3\2\2\2\u0408\u03c3\3\2\2\2\u0408\u03cb\3\2"+
		"\2\2\u0408\u03da\3\2\2\2\u0408\u03e3\3\2\2\2\u0408\u03e5\3\2\2\2\u0408"+
		"\u03e7\3\2\2\2\u0408\u03ef\3\2\2\2\u0408\u03f4\3\2\2\2\u0408\u03f9\3\2"+
		"\2\2\u0408\u0402\3\2\2\2\u0409}\3\2\2\2\u040a\u040c\7P\2\2\u040b\u040d"+
		"\5\u0092J\2\u040c\u040b\3\2\2\2\u040c\u040d\3\2\2\2\u040d\u040e\3\2\2"+
		"\2\u040e\u040f\7Q\2\2\u040f\177\3\2\2\2\u0410\u0415\7A\2\2\u0411\u0415"+
		"\7\63\2\2\u0412\u0413\7\63\2\2\u0413\u0415\7\62\2\2\u0414\u0410\3\2\2"+
		"\2\u0414\u0411\3\2\2\2\u0414\u0412\3\2\2\2\u0414\u0415\3\2\2\2\u0415\u0416"+
		"\3\2\2\2\u0416\u0417\5\u0082B\2\u0417\u041c\5\u0084C\2\u0418\u0419\7W"+
		"\2\2\u0419\u041b\5\u0084C\2\u041a\u0418\3\2\2\2\u041b\u041e\3\2\2\2\u041c"+
		"\u041a\3\2\2\2\u041c\u041d\3\2\2\2\u041d\u0081\3\2\2\2\u041e\u041c\3\2"+
		"\2\2\u041f\u0422\7B\2\2\u0420\u0422\5\6\4\2\u0421\u041f\3\2\2\2\u0421"+
		"\u0420\3\2\2\2\u0422\u0083\3\2\2\2\u0423\u0429\5\u014a\u00a6\2\u0424\u0426"+
		"\7d\2\2\u0425\u0427\7\63\2\2\u0426\u0425\3\2\2\2\u0426\u0427\3\2\2\2\u0427"+
		"\u0428\3\2\2\2\u0428\u042a\5\u0086D\2\u0429\u0424\3\2\2\2\u0429\u042a"+
		"\3\2\2\2\u042a\u0085\3\2\2\2\u042b\u042e\5\32\16\2\u042c\u042e\5\u0108"+
		"\u0085\2\u042d\u042b\3\2\2\2\u042d\u042c\3\2\2\2\u042e\u0087\3\2\2\2\u042f"+
		"\u0430\7\21\2\2\u0430\u0431\5\6\4\2\u0431\u0432\5\u00d8m\2\u0432\u0089"+
		"\3\2\2\2\u0433\u0436\5~@\2\u0434\u0436\5|?\2\u0435\u0433\3\2\2\2\u0435"+
		"\u0434\3\2\2\2\u0436\u008b\3\2\2\2\u0437\u0439\5\u008eH\2\u0438\u0437"+
		"\3\2\2\2\u0439\u043a\3\2\2\2\u043a\u0438\3\2\2\2\u043a\u043b\3\2\2\2\u043b"+
		"\u043c\3\2\2\2\u043c\u043d\5\u0092J\2\u043d\u008d\3\2\2\2\u043e\u043f"+
		"\7\r\2\2\u043f\u0441\5\32\16\2\u0440\u0442\5\u0090I\2\u0441\u0440\3\2"+
		"\2\2\u0441\u0442\3\2\2\2\u0442\u0443\3\2\2\2\u0443\u0444\7X\2\2\u0444"+
		"\u0448\3\2\2\2\u0445\u0446\7\23\2\2\u0446\u0448\7X\2\2\u0447\u043e\3\2"+
		"\2\2\u0447\u0445\3\2\2\2\u0448\u008f\3\2\2\2\u0449\u044a\7E\2\2\u044a"+
		"\u044b\5\32\16\2\u044b\u0091\3\2\2\2\u044c\u044e\5t;\2\u044d\u044c\3\2"+
		"\2\2\u044e\u044f\3\2\2\2\u044f\u044d\3\2\2\2\u044f\u0450\3\2\2\2\u0450"+
		"\u0093\3\2\2\2\u0451\u045b\5\u0080A\2\u0452\u0457\5\32\16\2\u0453\u0454"+
		"\7W\2\2\u0454\u0456\5\32\16\2\u0455\u0453\3\2\2\2\u0456\u0459\3\2\2\2"+
		"\u0457\u0455\3\2\2\2\u0457\u0458\3\2\2\2\u0458\u045b\3\2\2\2\u0459\u0457"+
		"\3\2\2\2\u045a\u0451\3\2\2\2\u045a\u0452\3\2\2\2\u045b\u0095\3\2\2\2\u045c"+
		"\u0461\5\32\16\2\u045d\u045e\7W\2\2\u045e\u0460\5\32\16\2\u045f\u045d"+
		"\3\2\2\2\u0460\u0463\3\2\2\2\u0461\u045f\3\2\2\2\u0461\u0462\3\2\2\2\u0462"+
		"\u0097\3\2\2\2\u0463\u0461\3\2\2\2\u0464\u0468\5\u009aN\2\u0465\u0467"+
		"\5\u009aN\2\u0466\u0465\3\2\2\2\u0467\u046a\3\2\2\2\u0468\u0466\3\2\2"+
		"\2\u0468\u0469\3\2\2\2\u0469\u046c\3\2\2\2\u046a\u0468\3\2\2\2\u046b\u046d"+
		"\5\u009cO\2\u046c\u046b\3\2\2\2\u046c\u046d\3\2\2\2\u046d\u0470\3\2\2"+
		"\2\u046e\u0470\5\u009cO\2\u046f\u0464\3\2\2\2\u046f\u046e\3\2\2\2\u0470"+
		"\u0099\3\2\2\2\u0471\u0472\7\16\2\2\u0472\u0473\7T\2\2\u0473\u0475\5\22"+
		"\n\2\u0474\u0476\5\u014a\u00a6\2\u0475\u0474\3\2\2\2\u0475\u0476\3\2\2"+
		"\2\u0476\u0477\3\2\2\2\u0477\u0479\7U\2\2\u0478\u047a\5\u009eP\2\u0479"+
		"\u0478\3\2\2\2\u0479\u047a\3\2\2\2\u047a\u047b\3\2\2\2\u047b\u047c\5~"+
		"@\2\u047c\u009b\3\2\2\2\u047d\u047f\7\16\2\2\u047e\u0480\5\u009eP\2\u047f"+
		"\u047e\3\2\2\2\u047f\u0480\3\2\2\2\u0480\u0481\3\2\2\2\u0481\u0482\5~"+
		"@\2\u0482\u009d\3\2\2\2\u0483\u0484\7E\2\2\u0484\u0485\7T\2\2\u0485\u0486"+
		"\5\32\16\2\u0486\u0487\7U\2\2\u0487\u009f\3\2\2\2\u0488\u0489\7\32\2\2"+
		"\u0489\u048a\5~@\2\u048a\u00a1\3\2\2\2\u048b\u048e\5\u0080A\2\u048c\u048e"+
		"\5\32\16\2\u048d\u048b\3\2\2\2\u048d\u048c\3\2\2\2\u048e\u00a3\3\2\2\2"+
		"\u048f\u0490\7\'\2\2\u0490\u0491\5\u00a6T\2\u0491\u0493\5\u00a8U\2\u0492"+
		"\u0494\7Y\2\2\u0493\u0492\3\2\2\2\u0493\u0494\3\2\2\2\u0494\u00a5\3\2"+
		"\2\2\u0495\u049a\5\u014a\u00a6\2\u0496\u0497\7V\2\2\u0497\u0499\5\u014a"+
		"\u00a6\2\u0498\u0496\3\2\2\2\u0499\u049c\3\2\2\2\u049a\u0498\3\2\2\2\u049a"+
		"\u049b\3\2\2\2\u049b\u00a7\3\2\2\2\u049c\u049a\3\2\2\2\u049d\u049f\7P"+
		"\2\2\u049e\u04a0\5\u00aaV\2\u049f\u049e\3\2\2\2\u049f\u04a0\3\2\2\2\u04a0"+
		"\u04a2\3\2\2\2\u04a1\u04a3\5\u00aeX\2\u04a2\u04a1\3\2\2\2\u04a2\u04a3"+
		"\3\2\2\2\u04a3\u04a4\3\2\2\2\u04a4\u04a5\7Q\2\2\u04a5\u00a9\3\2\2\2\u04a6"+
		"\u04a8\5\u00acW\2\u04a7\u04a6\3\2\2\2\u04a8\u04a9\3\2\2\2\u04a9\u04a7"+
		"\3\2\2\2\u04a9\u04aa\3\2\2\2\u04aa\u00ab\3\2\2\2\u04ab\u04ac\7A\2\2\u04ac"+
		"\u04ad\5\u014a\u00a6\2\u04ad\u04ae\7d\2\2\u04ae\u04af\5\4\3\2\u04af\u04b0"+
		"\7Y\2\2\u04b0\u04bb\3\2\2\2\u04b1\u04b2\7A\2\2\u04b2\u04b3\5\4\3\2\u04b3"+
		"\u04b4\7Y\2\2\u04b4\u04bb\3\2\2\2\u04b5\u04b6\7A\2\2\u04b6\u04b7\78\2"+
		"\2\u04b7\u04b8\5\4\3\2\u04b8\u04b9\7Y\2\2\u04b9\u04bb\3\2\2\2\u04ba\u04ab"+
		"\3\2\2\2\u04ba\u04b1\3\2\2\2\u04ba\u04b5\3\2\2\2\u04bb\u00ad\3\2\2\2\u04bc"+
		"\u04be\5\u00b0Y\2\u04bd\u04bc\3\2\2\2\u04be\u04bf\3\2\2\2\u04bf\u04bd"+
		"\3\2\2\2\u04bf\u04c0\3\2\2\2\u04c0\u00af\3\2\2\2\u04c1\u04c4\5\u00a4S"+
		"\2\u04c2\u04c4\5\u00b2Z\2\u04c3\u04c1\3\2\2\2\u04c3\u04c2\3\2\2\2\u04c4"+
		"\u00b1\3\2\2\2\u04c5\u04c7\5\u00d0i\2\u04c6\u04c5\3\2\2\2\u04c6\u04c7"+
		"\3\2\2\2\u04c7\u04cb\3\2\2\2\u04c8\u04cc\5\u012c\u0097\2\u04c9\u04cc\5"+
		"\u012e\u0098\2\u04ca\u04cc\5\u0130\u0099\2\u04cb\u04c8\3\2\2\2\u04cb\u04c9"+
		"\3\2\2\2\u04cb\u04ca\3\2\2\2\u04cc\u00b3\3\2\2\2\u04cd\u04ce\5\u014a\u00a6"+
		"\2\u04ce\u04cf\7h\2\2\u04cf\u04d1\5\u014a\u00a6\2\u04d0\u04d2\5\24\13"+
		"\2\u04d1\u04d0\3\2\2\2\u04d1\u04d2\3\2\2\2\u04d2\u00b5\3\2\2\2\u04d3\u04d4"+
		"\7e\2\2\u04d4\u04d9\5\u00b8]\2\u04d5\u04d6\7W\2\2\u04d6\u04d8\5\u00b8"+
		"]\2\u04d7\u04d5\3\2\2\2\u04d8\u04db\3\2\2\2\u04d9\u04d7\3\2\2\2\u04d9"+
		"\u04da\3\2\2\2\u04da\u04dc\3\2\2\2\u04db\u04d9\3\2\2\2\u04dc\u04dd\7f"+
		"\2\2\u04dd\u00b7\3\2\2\2\u04de\u04df\5\u014a\u00a6\2\u04df\u00b9\3\2\2"+
		"\2\u04e0\u04e1\7X\2\2\u04e1\u04e6\5\22\n\2\u04e2\u04e3\7W\2\2\u04e3\u04e5"+
		"\5\4\3\2\u04e4\u04e2\3\2\2\2\u04e5\u04e8\3\2\2\2\u04e6\u04e4\3\2\2\2\u04e6"+
		"\u04e7\3\2\2\2\u04e7\u00bb\3\2\2\2\u04e8\u04e6\3\2\2\2\u04e9\u04ee\5\4"+
		"\3\2\u04ea\u04eb\7W\2\2\u04eb\u04ed\5\4\3\2\u04ec\u04ea\3\2\2\2\u04ed"+
		"\u04f0\3\2\2\2\u04ee\u04ec\3\2\2\2\u04ee\u04ef\3\2\2\2\u04ef\u00bd\3\2"+
		"\2\2\u04f0\u04ee\3\2\2\2\u04f1\u04f3\5\u00c0a\2\u04f2\u04f1\3\2\2\2\u04f3"+
		"\u04f4\3\2\2\2\u04f4\u04f2\3\2\2\2\u04f4\u04f5\3\2\2\2\u04f5\u00bf\3\2"+
		"\2\2\u04f6\u04f7\7F\2\2\u04f7\u04f8\5\u014a\u00a6\2\u04f8\u04f9\7X\2\2"+
		"\u04f9\u04fa\5\u00c2b\2\u04fa\u00c1\3\2\2\2\u04fb\u0506\5\u00c8e\2\u04fc"+
		"\u04ff\5\u00c4c\2\u04fd\u04fe\7W\2\2\u04fe\u0500\5\u00c6d\2\u04ff\u04fd"+
		"\3\2\2\2\u04ff\u0500\3\2\2\2\u0500\u0503\3\2\2\2\u0501\u0502\7W\2\2\u0502"+
		"\u0504\5\u00c8e\2\u0503\u0501\3\2\2\2\u0503\u0504\3\2\2\2\u0504\u0506"+
		"\3\2\2\2\u0505\u04fb\3\2\2\2\u0505\u04fc\3\2\2\2\u0506\u00c3\3\2\2\2\u0507"+
		"\u050a\5\22\n\2\u0508\u050a\7\20\2\2\u0509\u0507\3\2\2\2\u0509\u0508\3"+
		"\2\2\2\u050a\u00c5\3\2\2\2\u050b\u0510\5\4\3\2\u050c\u050d\7W\2\2\u050d"+
		"\u050f\5\4\3\2\u050e\u050c\3\2\2\2\u050f\u0512\3\2\2\2\u0510\u050e\3\2"+
		"\2\2\u0510\u0511\3\2\2\2\u0511\u00c7\3\2\2\2\u0512\u0510\3\2\2\2\u0513"+
		"\u0514\7(\2\2\u0514\u0515\7T\2\2\u0515\u0516\7U\2\2\u0516\u00c9\3\2\2"+
		"\2\u0517\u0519\7P\2\2\u0518\u051a\5\u00ccg\2\u0519\u0518\3\2\2\2\u0519"+
		"\u051a\3\2\2\2\u051a\u051b\3\2\2\2\u051b\u051c\7Q\2\2\u051c\u00cb\3\2"+
		"\2\2\u051d\u051f\5\u00ceh\2\u051e\u051d\3\2\2\2\u051f\u0520\3\2\2\2\u0520"+
		"\u051e\3\2\2\2\u0520\u0521\3\2\2\2\u0521\u00cd\3\2\2\2\u0522\u0524\5\u00d0"+
		"i\2\u0523\u0522\3\2\2\2\u0523\u0524\3\2\2\2\u0524\u0527\3\2\2\2\u0525"+
		"\u0528\5\u00d4k\2\u0526\u0528\5\u013a\u009e\2\u0527\u0525\3\2\2\2\u0527"+
		"\u0526\3\2\2\2\u0528\u00cf\3\2\2\2\u0529\u052b\5\u00d2j\2\u052a\u0529"+
		"\3\2\2\2\u052b\u052c\3\2\2\2\u052c\u052a\3\2\2\2\u052c\u052d\3\2\2\2\u052d"+
		"\u00d1\3\2\2\2\u052e\u052f\t\n\2\2\u052f\u00d3\3\2\2\2\u0530\u0541\5\u0136"+
		"\u009c\2\u0531\u0541\5\u00d6l\2\u0532\u0538\5\u00fe\u0080\2\u0533\u0539"+
		"\5\u0102\u0082\2\u0534\u0535\5\u011e\u0090\2\u0535\u0536\5F$\2\u0536\u0537"+
		"\7Y\2\2\u0537\u0539\3\2\2\2\u0538\u0533\3\2\2\2\u0538\u0534\3\2\2\2\u0539"+
		"\u0541\3\2\2\2\u053a\u0541\5\u013c\u009f\2\u053b\u053c\7D\2\2\u053c\u0541"+
		"\5\u013e\u00a0\2\u053d\u0541\5\u012c\u0097\2\u053e\u0541\5\u012e\u0098"+
		"\2\u053f\u0541\5\u0130\u0099\2\u0540\u0530\3\2\2\2\u0540\u0531\3\2\2\2"+
		"\u0540\u0532\3\2\2\2\u0540\u053a\3\2\2\2\u0540\u053b\3\2\2\2\u0540\u053d"+
		"\3\2\2\2\u0540\u053e\3\2\2\2\u0540\u053f\3\2\2\2\u0541\u00d5\3\2\2\2\u0542"+
		"\u0548\7\63\2\2\u0543\u0544\7\62\2\2\u0544\u0548\7\63\2\2\u0545\u0546"+
		"\7\63\2\2\u0546\u0548\7\62\2\2\u0547\u0542\3\2\2\2\u0547\u0543\3\2\2\2"+
		"\u0547\u0545\3\2\2\2\u0547\u0548\3\2\2\2\u0548\u0549\3\2\2\2\u0549\u0553"+
		"\5\6\4\2\u054a\u054b\5\4\3\2\u054b\u054c\7V\2\2\u054c\u054d\5\u0138\u009d"+
		"\2\u054d\u0554\3\2\2\2\u054e\u0554\5\u013e\u00a0\2\u054f\u0554\5\u0134"+
		"\u009b\2\u0550\u0554\5\u0138\u009d\2\u0551\u0554\5\u0142\u00a2\2\u0552"+
		"\u0554\5\u0132\u009a\2\u0553\u054a\3\2\2\2\u0553\u054e\3\2\2\2\u0553\u054f"+
		"\3\2\2\2\u0553\u0550\3\2\2\2\u0553\u0551\3\2\2\2\u0553\u0552\3\2\2\2\u0554"+
		"\u00d7\3\2\2\2\u0555\u055a\5\u00dan\2\u0556\u0557\7W\2\2\u0557\u0559\5"+
		"\u00dan\2\u0558\u0556\3\2\2\2\u0559\u055c\3\2\2\2\u055a\u0558\3\2\2\2"+
		"\u055a\u055b\3\2\2\2\u055b\u00d9\3\2\2\2\u055c\u055a\3\2\2\2\u055d\u055e"+
		"\5\u014a\u00a6\2\u055e\u055f\7d\2\2\u055f\u0560\5\32\16\2\u0560\u00db"+
		"\3\2\2\2\u0561\u0566\5\u00dep\2\u0562\u0563\7W\2\2\u0563\u0565\5\u00de"+
		"p\2\u0564\u0562\3\2\2\2\u0565\u0568\3\2\2\2\u0566\u0564\3\2\2\2\u0566"+
		"\u0567\3\2\2\2\u0567\u00dd\3\2\2\2\u0568\u0566\3\2\2\2\u0569\u056c\5\u014a"+
		"\u00a6\2\u056a\u056b\7d\2\2\u056b\u056d\5\u00e0q\2\u056c\u056a\3\2\2\2"+
		"\u056c\u056d\3\2\2\2\u056d\u00df\3\2\2\2\u056e\u0571\5\32\16\2\u056f\u0571"+
		"\5\u0108\u0085\2\u0570\u056e\3\2\2\2\u0570\u056f\3\2\2\2\u0571\u00e1\3"+
		"\2\2\2\u0572\u0575\5\6\4\2\u0573\u0575\7D\2\2\u0574\u0572\3\2\2\2\u0574"+
		"\u0573\3\2\2\2\u0575\u00e3\3\2\2\2\u0576\u0577\5\4\3\2\u0577\u00e5\3\2"+
		"\2\2\u0578\u057b\5~@\2\u0579\u057b\7Y\2\2\u057a\u0578\3\2\2\2\u057a\u0579"+
		"\3\2\2\2\u057b\u00e7\3\2\2\2\u057c\u0583\5\u00f0y\2\u057d\u0580\5\u00ea"+
		"v\2\u057e\u057f\7W\2\2\u057f\u0581\5\u00f0y\2\u0580\u057e\3\2\2\2\u0580"+
		"\u0581\3\2\2\2\u0581\u0583\3\2\2\2\u0582\u057c\3\2\2\2\u0582\u057d\3\2"+
		"\2\2\u0583\u00e9\3\2\2\2\u0584\u0589\5\u00ecw\2\u0585\u0586\7W\2\2\u0586"+
		"\u0588\5\u00ecw\2\u0587\u0585\3\2\2\2\u0588\u058b\3\2\2\2\u0589\u0587"+
		"\3\2\2\2\u0589\u058a\3\2\2\2\u058a\u00eb\3\2\2\2\u058b\u0589\3\2\2\2\u058c"+
		"\u058e\5\u00eex\2\u058d\u058c\3\2\2\2\u058d\u058e\3\2\2\2\u058e\u058f"+
		"\3\2\2\2\u058f\u0590\5\u0144\u00a3\2\u0590\u00ed\3\2\2\2\u0591\u059a\7"+
		"\63\2\2\u0592\u059a\7,\2\2\u0593\u059a\7\"\2\2\u0594\u0595\7\63\2\2\u0595"+
		"\u059a\7;\2\2\u0596\u0597\7\"\2\2\u0597\u059a\7;\2\2\u0598\u059a\7;\2"+
		"\2\u0599\u0591\3\2\2\2\u0599\u0592\3\2\2\2\u0599\u0593\3\2\2\2\u0599\u0594"+
		"\3\2\2\2\u0599\u0596\3\2\2\2\u0599\u0598\3\2\2\2\u059a\u00ef\3\2\2\2\u059b"+
		"\u059c\7.\2\2\u059c\u059d\5\u0104\u0083\2\u059d\u059e\5\u014a\u00a6\2"+
		"\u059e\u00f1\3\2\2\2\u059f\u05a1\5\u00f8}\2\u05a0\u059f\3\2\2\2\u05a0"+
		"\u05a1\3\2\2\2\u05a1\u05ac\3\2\2\2\u05a2\u05a3\7\36\2\2\u05a3\u05a5\5"+
		"\u00fa~\2\u05a4\u05a6\5\u00f6|\2\u05a5\u05a4\3\2\2\2\u05a5\u05a6\3\2\2"+
		"\2\u05a6\u05ad\3\2\2\2\u05a7\u05a8\7\66\2\2\u05a8\u05aa\5\u00fa~\2\u05a9"+
		"\u05ab\5\u00f4{\2\u05aa\u05a9\3\2\2\2\u05aa\u05ab\3\2\2\2\u05ab\u05ad"+
		"\3\2\2\2\u05ac\u05a2\3\2\2\2\u05ac\u05a7\3\2\2\2\u05ad\u00f3\3\2\2\2\u05ae"+
		"\u05b0\5\u00f8}\2\u05af\u05ae\3\2\2\2\u05af\u05b0\3\2\2\2\u05b0\u05b1"+
		"\3\2\2\2\u05b1\u05b2\7\36\2\2\u05b2\u05b3\5\u00fa~\2\u05b3\u00f5\3\2\2"+
		"\2\u05b4\u05b6\5\u00f8}\2\u05b5\u05b4\3\2\2\2\u05b5\u05b6\3\2\2\2\u05b6"+
		"\u05b7\3\2\2\2\u05b7\u05b8\7\66\2\2\u05b8\u05b9\5\u00fa~\2\u05b9\u00f7"+
		"\3\2\2\2\u05ba\u05c2\7\60\2\2\u05bb\u05c2\7%\2\2\u05bc\u05c2\7/\2\2\u05bd"+
		"\u05be\7\60\2\2\u05be\u05c2\7%\2\2\u05bf\u05c0\7%\2\2\u05c0\u05c2\7\60"+
		"\2\2\u05c1\u05ba\3\2\2\2\u05c1\u05bb\3\2\2\2\u05c1\u05bc\3\2\2\2\u05c1"+
		"\u05bd\3\2\2\2\u05c1\u05bf\3\2\2\2\u05c2\u00f9\3\2\2\2\u05c3\u05c6\5~"+
		"@\2\u05c4\u05c6\7Y\2\2\u05c5\u05c3\3\2\2\2\u05c5\u05c4\3\2\2\2\u05c6\u00fb"+
		"\3\2\2\2\u05c7\u05de\7Z\2\2\u05c8\u05de\7[\2\2\u05c9\u05de\7b\2\2\u05ca"+
		"\u05de\7c\2\2\u05cb\u05de\7j\2\2\u05cc\u05de\7k\2\2\u05cd\u05de\7=\2\2"+
		"\u05ce\u05de\7\31\2\2\u05cf\u05de\7\\\2\2\u05d0\u05de\7]\2\2\u05d1\u05de"+
		"\7^\2\2\u05d2\u05de\7_\2\2\u05d3\u05de\7`\2\2\u05d4\u05de\7a\2\2\u05d5"+
		"\u05de\7{\2\2\u05d6\u05de\5\u0120\u0091\2\u05d7\u05de\7o\2\2\u05d8\u05de"+
		"\7p\2\2\u05d9\u05de\7f\2\2\u05da\u05de\7e\2\2\u05db\u05de\7r\2\2\u05dc"+
		"\u05de\7q\2\2\u05dd\u05c7\3\2\2\2\u05dd\u05c8\3\2\2\2\u05dd\u05c9\3\2"+
		"\2\2\u05dd\u05ca\3\2\2\2\u05dd\u05cb\3\2\2\2\u05dd\u05cc\3\2\2\2\u05dd"+
		"\u05cd\3\2\2\2\u05dd\u05ce\3\2\2\2\u05dd\u05cf\3\2\2\2\u05dd\u05d0\3\2"+
		"\2\2\u05dd\u05d1\3\2\2\2\u05dd\u05d2\3\2\2\2\u05dd\u05d3\3\2\2\2\u05dd"+
		"\u05d4\3\2\2\2\u05dd\u05d5\3\2\2\2\u05dd\u05d6\3\2\2\2\u05dd\u05d7\3\2"+
		"\2\2\u05dd\u05d8\3\2\2\2\u05dd\u05d9\3\2\2\2\u05dd\u05da\3\2\2\2\u05dd"+
		"\u05db\3\2\2\2\u05dd\u05dc\3\2\2\2\u05de\u00fd\3\2\2\2\u05df\u05e0\t\13"+
		"\2\2\u05e0\u05e1\7+\2\2\u05e1\u05e2\5\6\4\2\u05e2\u05e3\7T\2\2\u05e3\u05e4"+
		"\5\u0144\u00a3\2\u05e4\u05e5\7U\2\2\u05e5\u00ff\3\2\2\2\u05e6\u05e7\7"+
		"X\2\2\u05e7\u05e8\t\f\2\2\u05e8\u05ea\7T\2\2\u05e9\u05eb\5\26\f\2\u05ea"+
		"\u05e9\3\2\2\2\u05ea\u05eb\3\2\2\2\u05eb\u05ec\3\2\2\2\u05ec\u05ed\7U"+
		"\2\2\u05ed\u0101\3\2\2\2\u05ee\u05f1\5~@\2\u05ef\u05f1\7Y\2\2\u05f0\u05ee"+
		"\3\2\2\2\u05f0\u05ef\3\2\2\2\u05f1\u0103\3\2\2\2\u05f2\u05fa\5\b\5\2\u05f3"+
		"\u05f5\t\r\2\2\u05f4\u05f3\3\2\2\2\u05f5\u05f8\3\2\2\2\u05f6\u05f4\3\2"+
		"\2\2\u05f6\u05f7\3\2\2\2\u05f7\u05f9\3\2\2\2\u05f8\u05f6\3\2\2\2\u05f9"+
		"\u05fb\5\u0106\u0084\2\u05fa\u05f6\3\2\2\2\u05fb\u05fc\3\2\2\2\u05fc\u05fa"+
		"\3\2\2\2\u05fc\u05fd\3\2\2\2\u05fd\u0105\3\2\2\2\u05fe\u0602\7R\2\2\u05ff"+
		"\u0601\7W\2\2\u0600\u05ff\3\2\2\2\u0601\u0604\3\2\2\2\u0602\u0600\3\2"+
		"\2\2\u0602\u0603\3\2\2\2\u0603\u0605\3\2\2\2\u0604\u0602\3\2\2\2\u0605"+
		"\u0606\7S\2\2\u0606\u0107\3\2\2\2\u0607\u0613\7P\2\2\u0608\u060d\5\u00e0"+
		"q\2\u0609\u060a\7W\2\2\u060a\u060c\5\u00e0q\2\u060b\u0609\3\2\2\2\u060c"+
		"\u060f\3\2\2\2\u060d\u060b\3\2\2\2\u060d\u060e\3\2\2\2\u060e\u0611\3\2"+
		"\2\2\u060f\u060d\3\2\2\2\u0610\u0612\7W\2\2\u0611\u0610\3\2\2\2\u0611"+
		"\u0612\3\2\2\2\u0612\u0614\3\2\2\2\u0613\u0608\3\2\2\2\u0613\u0614\3\2"+
		"\2\2\u0614\u0615\3\2\2\2\u0615\u0616\7Q\2\2\u0616\u0109\3\2\2\2\u0617"+
		"\u0618\7e\2\2\u0618\u061d\5\u010c\u0087\2\u0619\u061a\7W\2\2\u061a\u061c"+
		"\5\u010c\u0087\2\u061b\u0619\3\2\2\2\u061c\u061f\3\2\2\2\u061d\u061b\3"+
		"\2\2\2\u061d\u061e\3\2\2\2\u061e\u0620\3\2\2\2\u061f\u061d\3\2\2\2\u0620"+
		"\u0621\7f\2\2\u0621\u010b\3\2\2\2\u0622\u0624\5\u010e\u0088\2\u0623\u0622"+
		"\3\2\2\2\u0623\u0624\3\2\2\2\u0624\u0625\3\2\2\2\u0625\u0626\5\u014a\u00a6"+
		"\2\u0626\u010d\3\2\2\2\u0627\u0628\t\16\2\2\u0628\u010f\3\2\2\2\u0629"+
		"\u062a\7X\2\2\u062a\u062b\5\u00bc_\2\u062b\u0111\3\2\2\2\u062c\u0630\7"+
		"P\2\2\u062d\u062f\5\u0114\u008b\2\u062e\u062d\3\2\2\2\u062f\u0632\3\2"+
		"\2\2\u0630\u062e\3\2\2\2\u0630\u0631\3\2\2\2\u0631\u0633\3\2\2\2\u0632"+
		"\u0630\3\2\2\2\u0633\u0634\7Q\2\2\u0634\u0113\3\2\2\2\u0635\u0637\7(\2"+
		"\2\u0636\u0635\3\2\2\2\u0636\u0637\3\2\2\2\u0637\u066c\3\2\2\2\u0638\u063e"+
		"\7\63\2\2\u0639\u063a\7\63\2\2\u063a\u063e\7\62\2\2\u063b\u063c\7\62\2"+
		"\2\u063c\u063e\7\63\2\2\u063d\u0638\3\2\2\2\u063d\u0639\3\2\2\2\u063d"+
		"\u063b\3\2\2\2\u063d\u063e\3\2\2\2\u063e\u063f\3\2\2\2\u063f\u065b\5\6"+
		"\4\2\u0640\u0642\5\u014a\u00a6\2\u0641\u0643\5\u00b6\\\2\u0642\u0641\3"+
		"\2\2\2\u0642\u0643\3\2\2\2\u0643\u0644\3\2\2\2\u0644\u0646\7T\2\2\u0645"+
		"\u0647\5\u00e8u\2\u0646\u0645\3\2\2\2\u0646\u0647\3\2\2\2\u0647\u0648"+
		"\3\2\2\2\u0648\u064a\7U\2\2\u0649\u064b\5\u00be`\2\u064a\u0649\3\2\2\2"+
		"\u064a\u064b\3\2\2\2\u064b\u064c\3\2\2\2\u064c\u064d\7Y\2\2\u064d\u065c"+
		"\3\2\2\2\u064e\u064f\5\u014a\u00a6\2\u064f\u0650\7P\2\2\u0650\u0651\5"+
		"\u0116\u008c\2\u0651\u0652\7Q\2\2\u0652\u065c\3\2\2\2\u0653\u0654\7;\2"+
		"\2\u0654\u0655\7R\2\2\u0655\u0656\5\u00e8u\2\u0656\u0657\7S\2\2\u0657"+
		"\u0658\7P\2\2\u0658\u0659\5\u0116\u008c\2\u0659\u065a\7Q\2\2\u065a\u065c"+
		"\3\2\2\2\u065b\u0640\3\2\2\2\u065b\u064e\3\2\2\2\u065b\u0653\3\2\2\2\u065c"+
		"\u066d\3\2\2\2\u065d\u065e\7D\2\2\u065e\u0660\5\u014a\u00a6\2\u065f\u0661"+
		"\5\u00b6\\\2\u0660\u065f\3\2\2\2\u0660\u0661\3\2\2\2\u0661\u0662\3\2\2"+
		"\2\u0662\u0664\7T\2\2\u0663\u0665\5\u00e8u\2\u0664\u0663\3\2\2\2\u0664"+
		"\u0665\3\2\2\2\u0665\u0666\3\2\2\2\u0666\u0668\7U\2\2\u0667\u0669\5\u00be"+
		"`\2\u0668\u0667\3\2\2\2\u0668\u0669\3\2\2\2\u0669\u066a\3\2\2\2\u066a"+
		"\u066b\7Y\2\2\u066b\u066d\3\2\2\2\u066c\u063d\3\2\2\2\u066c\u065d\3\2"+
		"\2\2\u066d\u0115\3\2\2\2\u066e\u066f\7\36\2\2\u066f\u0672\7Y\2\2\u0670"+
		"\u0671\7\66\2\2\u0671\u0673\7Y\2\2\u0672\u0670\3\2\2\2\u0672\u0673\3\2"+
		"\2\2\u0673\u067b\3\2\2\2\u0674\u0675\7\66\2\2\u0675\u0678\7Y\2\2\u0676"+
		"\u0677\7\36\2\2\u0677\u0679\7Y\2\2\u0678\u0676\3\2\2\2\u0678\u0679\3\2"+
		"\2\2\u0679\u067b\3\2\2\2\u067a\u066e\3\2\2\2\u067a\u0674\3\2\2\2\u067b"+
		"\u0117\3\2\2\2\u067c\u067d\7X\2\2\u067d\u067e\5\16\b\2\u067e\u0119\3\2"+
		"\2\2\u067f\u068b\7P\2\2\u0680\u0685\5\u011c\u008f\2\u0681\u0682\7W\2\2"+
		"\u0682\u0684\5\u011c\u008f\2\u0683\u0681\3\2\2\2\u0684\u0687\3\2\2\2\u0685"+
		"\u0683\3\2\2\2\u0685\u0686\3\2\2\2\u0686\u0689\3\2\2\2\u0687\u0685\3\2"+
		"\2\2\u0688\u068a\7W\2\2\u0689\u0688\3\2\2\2\u0689\u068a\3\2\2\2\u068a"+
		"\u068c\3\2\2\2\u068b\u0680\3\2\2\2\u068b\u068c\3\2\2\2\u068c\u068d\3\2"+
		"\2\2\u068d\u068e\7Q\2\2\u068e\u011b\3\2\2\2\u068f\u0692\5\u014a\u00a6"+
		"\2\u0690\u0691\7d\2\2\u0691\u0693\5\32\16\2\u0692\u0690\3\2\2\2\u0692"+
		"\u0693\3\2\2\2\u0693\u011d\3\2\2\2\u0694\u0695\7d\2\2\u0695\u0696\7f\2"+
		"\2\u0696\u0697\6\u0090\2\3\u0697\u011f\3\2\2\2\u0698\u0699\7f\2\2\u0699"+
		"\u069a\7f\2\2\u069a\u069b\6\u0091\3\3\u069b\u0121\3\2\2\2\u069c\u069d"+
		"\7f\2\2\u069d\u069e\7r\2\2\u069e\u069f\6\u0092\4\3\u069f\u0123\3\2\2\2"+
		"\u06a0\u06a8\5\u0126\u0094\2\u06a1\u06a8\5\u0128\u0095\2\u06a2\u06a8\7"+
		"J\2\2\u06a3\u06a8\7K\2\2\u06a4\u06a8\7L\2\2\u06a5\u06a8\7M\2\2\u06a6\u06a8"+
		"\7)\2\2\u06a7\u06a0\3\2\2\2\u06a7\u06a1\3\2\2\2\u06a7\u06a2\3\2\2\2\u06a7"+
		"\u06a3\3\2\2\2\u06a7\u06a4\3\2\2\2\u06a7\u06a5\3\2\2\2\u06a7\u06a6\3\2"+
		"\2\2\u06a8\u0125\3\2\2\2\u06a9\u06aa\t\17\2\2\u06aa\u0127\3\2\2\2\u06ab"+
		"\u06ac\t\20\2\2\u06ac\u0129\3\2\2\2\u06ad\u06ae\t\21\2\2\u06ae\u012b\3"+
		"\2\2\2\u06af\u06b0\7\20\2\2\u06b0\u06b2\5\u014a\u00a6\2\u06b1\u06b3\5"+
		"\u00b6\\\2\u06b2\u06b1\3\2\2\2\u06b2\u06b3\3\2\2\2\u06b3\u06b5\3\2\2\2"+
		"\u06b4\u06b6\5\u00ba^\2\u06b5\u06b4\3\2\2\2\u06b5\u06b6\3\2\2\2\u06b6"+
		"\u06b8\3\2\2\2\u06b7\u06b9\5\u00be`\2\u06b8\u06b7\3\2\2\2\u06b8\u06b9"+
		"\3\2\2\2\u06b9\u06ba\3\2\2\2\u06ba\u06bc\5\u00caf\2\u06bb\u06bd\7Y\2\2"+
		"\u06bc\u06bb\3\2\2\2\u06bc\u06bd\3\2\2\2\u06bd\u012d\3\2\2\2\u06be\u06bf"+
		"\7$\2\2\u06bf\u06c1\5\u014a\u00a6\2\u06c0\u06c2\5\u010a\u0086\2\u06c1"+
		"\u06c0\3\2\2\2\u06c1\u06c2\3\2\2\2\u06c2\u06c4\3\2\2\2\u06c3\u06c5\5\u0110"+
		"\u0089\2\u06c4\u06c3\3\2\2\2\u06c4\u06c5\3\2\2\2\u06c5\u06c7\3\2\2\2\u06c6"+
		"\u06c8\5\u00be`\2\u06c7\u06c6\3\2\2\2\u06c7\u06c8\3\2\2\2\u06c8\u06c9"+
		"\3\2\2\2\u06c9\u06cb\5\u00caf\2\u06ca\u06cc\7Y\2\2\u06cb\u06ca\3\2\2\2"+
		"\u06cb\u06cc\3\2\2\2\u06cc\u012f\3\2\2\2\u06cd\u06ce\7\27\2\2\u06ce\u06d0"+
		"\5\u014a\u00a6\2\u06cf\u06d1\5\u0118\u008d\2\u06d0\u06cf\3\2\2\2\u06d0"+
		"\u06d1\3\2\2\2\u06d1\u06d2\3\2\2\2\u06d2\u06d4\5\u011a\u008e\2\u06d3\u06d5"+
		"\7Y\2\2\u06d4\u06d3\3\2\2\2\u06d4\u06d5\3\2\2\2\u06d5\u0131\3\2\2\2\u06d6"+
		"\u06d7\5\u00dco\2\u06d7\u06d8\7Y\2\2\u06d8\u0133\3\2\2\2\u06d9\u06e7\5"+
		"\u00e4s\2\u06da\u06db\7P\2\2\u06db\u06dc\5\u00f2z\2\u06dc\u06e1\7Q\2\2"+
		"\u06dd\u06de\7d\2\2\u06de\u06df\5\u00e0q\2\u06df\u06e0\7Y\2\2\u06e0\u06e2"+
		"\3\2\2\2\u06e1\u06dd\3\2\2\2\u06e1\u06e2\3\2\2\2\u06e2\u06e8\3\2\2\2\u06e3"+
		"\u06e4\5\u011e\u0090\2\u06e4\u06e5\5F$\2\u06e5\u06e6\7Y\2\2\u06e6\u06e8"+
		"\3\2\2\2\u06e7\u06da\3\2\2\2\u06e7\u06e3\3\2\2\2\u06e8\u0135\3\2\2\2\u06e9"+
		"\u06ea\7\21\2\2\u06ea\u06eb\5\6\4\2\u06eb\u06ec\5\u00d8m\2\u06ec\u06ed"+
		"\7Y\2\2\u06ed\u0137\3\2\2\2\u06ee\u06ef\7;\2\2\u06ef\u06f0\7R\2\2\u06f0"+
		"\u06f1\5\u00e8u\2\u06f1\u06fa\7S\2\2\u06f2\u06f3\7P\2\2\u06f3\u06f4\5"+
		"\u00f2z\2\u06f4\u06f5\7Q\2\2\u06f5\u06fb\3\2\2\2\u06f6\u06f7\5\u011e\u0090"+
		"\2\u06f7\u06f8\5F$\2\u06f8\u06f9\7Y\2\2\u06f9\u06fb\3\2\2\2\u06fa\u06f2"+
		"\3\2\2\2\u06fa\u06f6\3\2\2\2\u06fb\u0139\3\2\2\2\u06fc\u06fd\7c\2\2\u06fd"+
		"\u06fe\5\u014a\u00a6\2\u06fe\u06ff\7T\2\2\u06ff\u0700\7U\2\2\u0700\u0701"+
		"\5\u0102\u0082\2\u0701\u013b\3\2\2\2\u0702\u0703\5\u014a\u00a6\2\u0703"+
		"\u0705\7T\2\2\u0704\u0706\5\u00e8u\2\u0705\u0704\3\2\2\2\u0705\u0706\3"+
		"\2\2\2\u0706\u0707\3\2\2\2\u0707\u0709\7U\2\2\u0708\u070a\5\u0100\u0081"+
		"\2\u0709\u0708\3\2\2\2\u0709\u070a\3\2\2\2\u070a\u070b\3\2\2\2\u070b\u070c"+
		"\5\u0102\u0082\2\u070c\u013d\3\2\2\2\u070d\u070f\5\u0140\u00a1\2\u070e"+
		"\u0710\5\u00b6\\\2\u070f\u070e\3\2\2\2\u070f\u0710\3\2\2\2\u0710\u0711"+
		"\3\2\2\2\u0711\u0713\7T\2\2\u0712\u0714\5\u00e8u\2\u0713\u0712\3\2\2\2"+
		"\u0713\u0714\3\2\2\2\u0714\u0715\3\2\2\2\u0715\u0717\7U\2\2\u0716\u0718"+
		"\5\u00be`\2\u0717\u0716\3\2\2\2\u0717\u0718\3\2\2\2\u0718\u071e\3\2\2"+
		"\2\u0719\u071f\5\u00e6t\2\u071a\u071b\5\u011e\u0090\2\u071b\u071c\5F$"+
		"\2\u071c\u071d\7Y\2\2\u071d\u071f\3\2\2\2\u071e\u0719\3\2\2\2\u071e\u071a"+
		"\3\2\2\2\u071f\u013f\3\2\2\2\u0720\u0726\5\u014a\u00a6\2\u0721\u0722\5"+
		"\u014a\u00a6\2\u0722\u0723\7h\2\2\u0723\u0724\5\u014a\u00a6\2\u0724\u0726"+
		"\3\2\2\2\u0725\u0720\3\2\2\2\u0725\u0721\3\2\2\2\u0726\u072e\3\2\2\2\u0727"+
		"\u0729\5\24\13\2\u0728\u0727\3\2\2\2\u0728\u0729\3\2\2\2\u0729\u072a\3"+
		"\2\2\2\u072a\u072b\7V\2\2\u072b\u072d\5\u014a\u00a6\2\u072c\u0728\3\2"+
		"\2\2\u072d\u0730\3\2\2\2\u072e\u072c\3\2\2\2\u072e\u072f\3\2\2\2\u072f"+
		"\u0141\3\2\2\2\u0730\u072e\3\2\2\2\u0731\u0732\7+\2\2\u0732\u0733\5\u00fc"+
		"\177\2\u0733\u0735\7T\2\2\u0734\u0736\7\"\2\2\u0735\u0734\3\2\2\2\u0735"+
		"\u0736\3\2\2\2\u0736\u0737\3\2\2\2\u0737\u073d\5\u0144\u00a3\2\u0738\u073a"+
		"\7W\2\2\u0739\u073b\7\"\2\2\u073a\u0739\3\2\2\2\u073a\u073b\3\2\2\2\u073b"+
		"\u073c\3\2\2\2\u073c\u073e\5\u0144\u00a3\2\u073d\u0738\3\2\2\2\u073d\u073e"+
		"\3\2\2\2\u073e\u073f\3\2\2\2\u073f\u0745\7U\2\2\u0740\u0746\5\u0102\u0082"+
		"\2\u0741\u0742\5\u011e\u0090\2\u0742\u0743\5F$\2\u0743\u0744\7Y\2\2\u0744"+
		"\u0746\3\2\2\2\u0745\u0740\3\2\2\2\u0745\u0741\3\2\2\2\u0746\u0143\3\2"+
		"\2\2\u0747\u0748\5\6\4\2\u0748\u074b\5\u014a\u00a6\2\u0749\u074a\7d\2"+
		"\2\u074a\u074c\5\32\16\2\u074b\u0749\3\2\2\2\u074b\u074c\3\2\2\2\u074c"+
		"\u0145\3\2\2\2\u074d\u074f\7T\2\2\u074e\u0750\5\26\f\2\u074f\u074e\3\2"+
		"\2\2\u074f\u0750\3\2\2\2\u0750\u0751\3\2\2\2\u0751\u0752\7U\2\2\u0752"+
		"\u0147\3\2\2\2\u0753\u0755\7T\2\2\u0754\u0756\5\26\f\2\u0755\u0754\3\2"+
		"\2\2\u0755\u0756\3\2\2\2\u0756\u0757\3\2\2\2\u0757\u0759\7U\2\2\u0758"+
		"\u075a\5T+\2\u0759\u0758\3\2\2\2\u0759\u075a\3\2\2\2\u075a\u0149\3\2\2"+
		"\2\u075b\u075c\t\22\2\2\u075c\u014b\3\2\2\2\u00eb\u014d\u0150\u0156\u0159"+
		"\u015e\u0162\u0169\u0170\u0174\u0178\u0181\u0189\u0193\u0199\u019c\u01a0"+
		"\u01a8\u01b4\u01c1\u01c9\u01cf\u01d1\u01d8\u01e0\u01e8\u01f0\u01f8\u0200"+
		"\u0208\u020a\u0210\u0215\u021d\u0225\u022d\u022f\u0232\u0239\u023e\u0257"+
		"\u025b\u0260\u0264\u026a\u026d\u0272\u0276\u027a\u0280\u028e\u0294\u02a0"+
		"\u02a4\u02a9\u02ad\u02b3\u02ba\u02c2\u02d0\u02d6\u02da\u02e2\u02ea\u02f2"+
		"\u02fd\u0302\u0307\u0309\u0312\u031a\u0321\u0329\u032d\u0336\u033b\u033d"+
		"\u0346\u034e\u0352\u0357\u0359\u035e\u0362\u0369\u0371\u0373\u0377\u037a"+
		"\u0382\u0391\u0399\u03a1\u03ae\u03b8\u03ce\u03d2\u03d6\u03ec\u03f1\u03f6"+
		"\u03fd\u0400\u0408\u040c\u0414\u041c\u0421\u0426\u0429\u042d\u0435\u043a"+
		"\u0441\u0447\u044f\u0457\u045a\u0461\u0468\u046c\u046f\u0475\u0479\u047f"+
		"\u048d\u0493\u049a\u049f\u04a2\u04a9\u04ba\u04bf\u04c3\u04c6\u04cb\u04d1"+
		"\u04d9\u04e6\u04ee\u04f4\u04ff\u0503\u0505\u0509\u0510\u0519\u0520\u0523"+
		"\u0527\u052c\u0538\u0540\u0547\u0553\u055a\u0566\u056c\u0570\u0574\u057a"+
		"\u0580\u0582\u0589\u058d\u0599\u05a0\u05a5\u05aa\u05ac\u05af\u05b5\u05c1"+
		"\u05c5\u05dd\u05ea\u05f0\u05f6\u05fc\u0602\u060d\u0611\u0613\u061d\u0623"+
		"\u0630\u0636\u063d\u0642\u0646\u064a\u065b\u0660\u0664\u0668\u066c\u0672"+
		"\u0678\u067a\u0685\u0689\u068b\u0692\u06a7\u06b2\u06b5\u06b8\u06bc\u06c1"+
		"\u06c4\u06c7\u06cb\u06d0\u06d4\u06e1\u06e7\u06fa\u0705\u0709\u070f\u0713"+
		"\u0717\u071e\u0725\u0728\u072e\u0735\u073a\u073d\u0745\u074b\u074f\u0755"+
		"\u0759";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}