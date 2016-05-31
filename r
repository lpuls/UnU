#! /bin/bash
flex -o LEX/lex.cpp LEX/lex.l
bison -d -o PARSE/parse.cpp PARSE/parse.y 
make clean
make
./main $1

#FileReader.o:
#	g++ -std=c++11 -c Tools/FileReader/FileReader.cpp
#TypeConversion.o:
#	g++ -std=c++11 -c Tools/TypeConversion/TypeConversion.cpp
#Toolsets.o:
#	g++ -std=c++11 -c Tools/Toolsets.cpp
#ToolLog.o:
#	g++ -std=c++11 -c Tools/Log/ToolLog.cpp
#ASTNode.o:
#	g++ -std=c++11 -c AST/ASTNode.cpp
#ASTBody.o:
#	g++ -std=c++11 -c AST/ASTNode.cpp
#ASTExp.o:
#	g++ -std=c++11 -c AST/ASTNode.cpp
#ASTValue.o:
#	g++ -std=c++11 -c AST/ASTNode.cpp
#ASTInteger.o:
#	g++ -std=c++11 -c AST/ASTNode.cpp
#ASTOperator.o:
#	g++ -std=c++11 -c AST/ASTNode.cpp