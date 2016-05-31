#ifndef __AST_BODY__
#define __AST_BODY__

#include <vector>

#include "ASTNode.hpp"

namespace UnUCompiler
{
    class ASTBody : public ASTNode
    {
        private:
            /*
             * description: store the child node
             * type: std::vector<ASTNode*>
             */
            std::vector<ASTNode*> __children;
        public:
            /*
             * function: constructor
             * params: None
             * return: None
             */
            ASTBody(); 
        
            /*
             * function: destructor
             * params: None
             * return: None
             */
            ~ASTBody();  
            
            /*
             * function: call back the check function of node
             * params: None
             * return: None
             */
            int check();
            
            /*
             * function: insert a child into __children
             * params: ASTNode*, child, the child will be insert into __children
             * return: None
             */          
            void insertChild(ASTNode * child);
            
            /*
             * function: print the tree
             * params: Node
             * return: None
             */
             void showTree();   
    };
}

#endif