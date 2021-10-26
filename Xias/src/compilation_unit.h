#pragma once

#include "XiasParser.h"

#include <vector>
#include <string>

namespace Xias {

	struct UsingInfo
	{
		std::string Using;
	};

	struct AliasInfo
	{
		std::string Name;
		std::string Using;
	};

	enum class AccessModifier
	{
		Public,
		Private,
		Protected,
		Internal,
		ProtectedInternal,
		PrivateProtected,
	};

	enum class Modifier
	{
		New,
		Static,
		Readonly,
		Virtual,
		Sealed,
		Override,
		Abstract,
	};

	struct Modifiers
	{
		AccessModifier m_Access;
		std::vector<Modifier> m_Modifiers;
	};

	// Consider keeping types like boolean_condition for type checking easyness
	struct Expression
	{
		enum
		{
			expression,
			expression_list,

			local_variable_initializer,
			variable_initializer,
			array_initializer,
			variable_initializer_list,

			conditional_expression,
			null_coalescing_expression,
			conditional_or_expression,
			conditional_and_expression,
			inclusive_or_expression,
			exclusive_or_expression,
			and_expression,
			equality_expression_EQ,
			equality_expression_NE,
			relational_expression_LT,
			relational_expression_GT,
			relational_expression_OP_LE,
			relational_expression_OP_GE,
			relational_expression_IS,
			relational_expression_AS,
			shift_expression_LEFT,
			shift_expression_RIGHT,
			additive_expression_PLUS,
			additive_expression_MINUS,
			multiplicative_expression_STAR,
			multiplicative_expression_DIV,
			multiplicative_expression_MOD,

			unary_plus_expression,
			unary_minus_expression,
			unary_bang_expression,
			unary_tilde_expression,
			pre_increment_expression,
			pre_decrement_expression,
			cast_expression,

			// primary_expression

			primary_no_array_creation_base,

			// primary_expression_start
			true_literal,
			false_literal,
			string_literal,
			verbatim_literal,
			integer_literal,
			unsigned_literal,
			float_literal,
			double_literal,
			null_literal,

			simple_name,
			parenthesized,
			this_access,
			base_access,
			object_creation,
			object_initializer,
			member_initializer,
			collection_initializer,
			element_initializer,
			typeof_expression,
			default_value,

			// primary_no_array_creation_expression
			member_access,
			predefined_type,
			qualified_alias_member,
			invocation_expression,
			element_access,
			post_increment_expression,
			post_decrement_expression,

			// array_creation_expression
			array_creation_with_expression_size,
			array_creation_with_initializer,
			rank_specifier,

			argument_list,

			type_argument_list,

			assignment,
			ADD_assignment,
			SUB_assignment,
			MULT_assignment,
			DIV_assignment,
			MOD_assignment,
			AND_assignment,
			OR_assignment,
			XOR_assignment,
			LEFT_SHIFT_assignment,
			RIGHT_SHIFT_assignment,
		} m_Type;

		std::vector<std::string> m_Data;

		std::vector<Expression> m_Children;
	};

	struct Statement
	{
		enum
		{
			block,
			statement_list,

			labeled_statement,

			local_variable_declaration,
			local_variable_declarator,

			local_constant_declaration,
			constant_declarator,

			// embedded_statement
			empty,
			statement_expression,
			statement_expression_list,

			if_statement,
			switch_statement,
			switch_section,
			switch_label,

			while_statement,
			do_statement,
			for_statement,
			for_initializer,
			for_condition,
			for_iterator,
			foreach_statement,

			break_statement,
			continue_statement,

			goto_label,
			goto_case,
			goto_default,

			return_statement,

			throw_statement,

			try_statement,
			catch_clause,
			finally_clause,

			exception_specifier,
			exception_filter,
		} m_Type;

		std::vector<std::string> m_Data;

		std::vector<Statement> m_Children;
		std::vector<Expression> m_Expressions;
	};

	struct FieldInfo
	{
		std::string m_Name;
		Modifiers m_Modifiers;

		Expression m_VariableInitializer;

		std::string m_Type;
	};

	struct AccessorInfo
	{
		Modifiers m_Modifiers;
		bool m_Present = false;
		Statement m_Body;
	};

	struct PropertyInfo
	{
		std::string m_Name;
		Modifiers m_Modifiers;

		AccessorInfo m_Set;
		AccessorInfo m_Get;

		Expression m_VariableInitializer;

		std::string m_Type;
	};

	struct ParameterInfo
	{
		std::string m_Name;

		Expression m_Default;

		std::string m_Type;
	};

	struct MethodInfo
	{
		std::string m_Name;
		Modifiers m_Modifiers;

		std::vector<ParameterInfo> m_Parameters;

		Statement m_Body;

		std::string m_Type;
	};

	struct ConstructorInitializerInfo
	{
		enum
		{
			None,
			Base,
			This,
		} m_Type;

		Expression m_Arguments;
	};

	struct ConstructorInfo
	{
		Modifiers m_Modifiers;

		std::vector<ParameterInfo> m_Parameters;

		Statement m_Body;
	};

	struct ClassInfo
	{
		std::string_view m_Name;
		std::string m_QualifiedName;
		Modifiers m_Modifiers;

		std::vector<FieldInfo> m_Fields;
		std::vector<PropertyInfo> m_Properties;
		std::vector<MethodInfo> m_Methods;

		std::vector<ConstructorInfo> m_Constructors;

		std::vector<std::string> m_Parents;
	};

	struct NamespaceInfo
	{
		std::string m_Name;
		std::unordered_map<std::string, NamespaceInfo> m_Namespaces;

		std::vector<std::string> m_Classes;
	};

	struct CompilationUnit
	{
		std::vector<UsingInfo> m_Usings;
		NamespaceInfo m_GlobalNamespace;

		std::vector<ClassInfo> m_Classes;
	};

}
