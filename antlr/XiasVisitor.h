#include "antlr4-runtime.h"
#include "XiasParserBaseVisitor.h"

#include <string>

class  XiasVisitor : XiasParserBaseVisitor {
public:    
    antlrcpp::Any visitUnit(XiasParser::Compilation_unitContext* ctx);
};
