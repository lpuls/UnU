OBJ=parse.o lex.o 
OTHER=ASTNode.o ASTBody.o ASTExp.o ASTValue.o ASTInteger.o ASTOperator.o FileReader.o TypeConversion.o Toolsets.o ToolLog.o

main: $(OBJ)
	g++ $(OBJ) $(OTHER) -o main
parse.o:
	g++ -std=c++11 -c PARSE/parse.cpp  
lex.o:
	g++ -std=c++11 -c LEX/lex.cpp
clean:
	rm -rf main $(OBJ)
