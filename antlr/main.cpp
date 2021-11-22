#include <iostream>
#include "antlr4-runtime.h"
#include "XiasLexer.h"
#include "XiasParser.h"
#include "XiasVisitor.h"

using namespace std;
using namespace antlr4;

int main(int argc, const char* argv[])
{
    std::ifstream stream;
    stream.open("sample.x");
    
    ANTLRInputStream input(stream);
    XiasLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    XiasParser parser(&tokens);
    XiasParser::Compilation_unitContext* tree = parser.compilation_unit();

    auto usingDirs = tree->using_directives();
    auto dirs = usingDirs->using_directive();
    auto first = dirs[0];
    auto text = first->getText();
    std::cout << text;

    XiasVisitor visitor;
    auto visit = visitor.visitUnit(tree);

    return 0;
}