#include <iostream>

#include "ASTToken.hpp"
#include "ASTError.hpp"

using namespace UnuCompiler;

ASTToken::ASTToken()
{
    
}

ASTToken::~ASTToken()
{
    
}

int ASTToken::check()
{
    return Normal;
}

void ASTToken::showTree()
{
    std::cout << "Token : " << this->_value->Token << std::endl;
}