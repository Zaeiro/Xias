#pragma once

#include "types.h"
#include "instructions.h"

#include <vector>

namespace Xias {

	struct Bytecode
	{
		std::vector<Xias::OpType> Code;
		std::vector<Xias::Value> Constants;
	};

}
