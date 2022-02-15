#pragma once

#include "XiasParser.h"
#include "antlr/DefaultErrorStrategy.h"
#include "antlr4-runtime.h"

class XiasErrorHandler : public antlr4::DefaultErrorStrategy
{
public:
	virtual void reportError(antlr4::Parser* recognizer, const antlr4::RecognitionException& e) override;
};
