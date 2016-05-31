#include "ASTValue.hpp"
#include "ASTError.hpp"

using namespace UnUCompiler;

ASTValue::ASTValue()
{
    this->_value = new ASTValueUnion();
}

ASTValue::~ASTValue()
{
    
}

int ASTValue::check()
{
    return Normal;
}

void ASTValue::showTree()
{
    
}