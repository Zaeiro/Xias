call antlr4 -o /gen XiasLexer.g4
call antlr4 -o /gen XiasParser.g4
cd C:\gen
javac XiasLexer*.java
javac XiasParser*.java
echo run with 'grun Xias compilation_unit'
cmd /k