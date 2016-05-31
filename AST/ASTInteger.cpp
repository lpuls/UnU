#include <iostream>

#include "ASTInteger.hpp"

using namespace UnUCompiler;

ASTInteger::ASTInteger ()
{
}
    
ASTInteger::~ASTInteger ()
{
}

void ASTInteger::setValue(long long int value)
{
    this->_value->Integer = value;
}

long long int ASTInteger::getValue()
{
    return this->_value->Integer;
}

void ASTInteger::showTree()
{
    std::cout << "Integer : " << this->_value->Integer << std::endl;
}