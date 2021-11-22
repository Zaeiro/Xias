#pragma once

#include "compilation_unit.h"
#include "types.h"

#include <string>

namespace Xias {

	class Vm;

	class Compiler
	{
	public:
		static std::string Compile(Vm* vm, const Expression& expression, x_method method);
		static void Compile(Vm* vm, const Statement& statement, x_method method);
	private:
		static void FindProperty();
	};

}
