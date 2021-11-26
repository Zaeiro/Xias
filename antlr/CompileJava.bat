@echo off
echo Generating...
call antlr4 -Xexact-output-dir -o gen XiasLexer.g4
call antlr4 -Xexact-output-dir -o gen XiasParser.g4
cd gen
javac XiasLexer*.java
javac XiasParser*.java
echo Done
echo Run with 'grun Xias compilation_unit'
cmd /k
@echo on