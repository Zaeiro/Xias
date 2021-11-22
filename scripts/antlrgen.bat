@echo off
echo Generating lexer...
call antlr4 -Dlanguage=Cpp -DcontextSuperClass=antlr4::RuleContextWithAltNum -no-listener -visitor -Xexact-output-dir -o ..\Xias\src\antlrgen ..\antlr\XiasLexer.g4
timeout /t 1 /nobreak > NUL
echo Done
echo Generating parser...
call antlr4 -Dlanguage=Cpp -DcontextSuperClass=antlr4::RuleContextWithAltNum -no-listener -visitor -Xexact-output-dir -o ..\Xias\src\antlrgen ..\antlr\XiasParser.g4
timeout /t 1 /nobreak > NUL
echo Done
PAUSE