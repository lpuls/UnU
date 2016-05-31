#! /bin/bash
rm -r ../O/ASTNode.o ../O/ASTBody.o ../O/ASTExp.o ../O/ASTValue.o ../O/ASTInteger.o ../O/ASTOperator.o
g++ -std=c++11 -c ASTNode.cpp -o ../ASTNode.o
g++ -std=c++11 -c ASTBody.cpp -o ../ASTBody.o
g++ -std=c++11 -c ASTExp.cpp -o ../ASTExp.o
g++ -std=c++11 -c ASTValue.cpp -o ../ASTValue.o
g++ -std=c++11 -c ASTInteger.cpp -o ../ASTInteger.o
g++ -std=c++11 -c ASTOperator.cpp -o ../ASTOperator.o