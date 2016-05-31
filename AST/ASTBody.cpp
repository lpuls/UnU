#include <iostream>

#include "ASTBody.hpp"
#include "ASTError.hpp"

using namespace UnUCompiler;

ASTBody::ASTBody()
{
    
}

ASTBody::~ASTBody()
{
    for(auto item : this->__children)
    {
        if (item) 
        {
            delete(item);
            item = nullptr;    
        }
    }
    this->__children.clear();
}

int ASTBody::check()
{
    return Normal;
}

void ASTBody::insertChild(ASTNode * child)
{
    this->__children.push_back(child);
}

void ASTBody::showTree()
{
    std::cout << "Body { \n";
    for(auto item : this->__children)
    {
        item->showTree();
    }
    std::cout << "} \n";
}