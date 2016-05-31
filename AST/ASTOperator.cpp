#include <iostream>

#include "ASTOperator.hpp"
#include "ASTError.hpp"

using namespace UnUCompiler;

ASTOperator::ASTOperator()
{
    this->_operator = "";
    this->_left = nullptr;
    this->_right = nullptr;
}

ASTOperator::~ASTOperator()
{
    if (this->_left && this->_right) 
    {
        delete(this->_left);
        this->_left = nullptr;
        delete(this->_right);
        this->_right = nullptr; 
    }
}

int ASTOperator::check()
{
    // TODO check the types of two operator value are the same  
    return Normal;
}

void ASTOperator::showTree()
{
    if (this->_left) { this->_left->showTree(); }
    std::cout << "Operator : " << this->_operator << std::endl;
    if (this->_right) { this->_right->showTree(); }
}