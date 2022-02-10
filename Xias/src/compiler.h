#pragma once

#include "compilation_unit.h"
#include "types.h"
#include "compilation_unit.h"

#include <string>

namespace Xias {

	class Vm;

	struct OverloadResolution
	{
		Type Return;
		std::string GivenSignature;
		std::vector<Type> OriginalParameters;
		std::vector<x_method> CastMethods;
		std::vector<Type> FinalParameters;
	};

	struct StackElementInfo
	{
		int ScopeDepth = 0;
		std::string Name;
		Type ElementType;
	};

	class Compiler
	{
	public:
		Compiler();
		Compiler(Vm* vm);
		std::vector<CompilationMessage> Compile(x_class xclass, x_method method, Statement& statement);
	private:
		void StaticCheck(Statement& statement);
		void Walk(Statement& statement);
		ExpressionResult& Walk(Expression& expression);
		ExpressionResult& WalkPrimary(std::vector<Expression>& expressions);
		void CreateDAG(Statement& statement);
		//std::string Compilea(Vm* vm, const Expression& expression, x_method method);
		//void Compilea(Vm* vm, const Statement& statement, x_method method);
	private:
		//void FindProperty(std::vector<CompilationMessage>& messages);
		void AddMessage(x_ulong errorID, std::vector<std::string> params);
		std::string CreateName(const Type& type);
		Type CreateType(const std::string& type);
		x_method FindMethod(std::string name, Type& left, Type& right);
		//OverloadResolution ResolveOverload(const std::string& methodName, std::vector<Type> givenTypes);
		OverloadResolution ResolveOverload(const std::string& methodName, std::vector<Type> givenTypes);
		bool MemberAccessible(const std::string& containingClass, Member& member);
		void ObliterateScope();
	public:
		x_class containingClass = nullptr;
		x_class doubleClass = nullptr;
		x_class floatClass = nullptr;
		x_class intClass = nullptr;
		x_class uintClass = nullptr;
		x_class boolClass = nullptr;
		x_class objectClass = nullptr;
		x_class stringClass = nullptr;
	private:
		std::vector<CompilationMessage>* messages;
		x_ulong line, column;
		Vm* vm = nullptr;
		std::vector<StackElementInfo> stack;
		int currentScopeDepth = 0;
	};

	class CompilationPass
	{
	public:
		CompilationPass(Vm* xvm);

		virtual void SetClass(ClassInfo& cInfo, x_class xClass);
	private:
		Vm* XVM = nullptr;
		ClassInfo* m_CInfo = nullptr;
		x_class m_XClass = nullptr;
	};

}
