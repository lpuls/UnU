#ifndef __AST_EXP__
#define __AST_EXP__

#include "ASTNode.hpp"

namespace UnUCompiler
{
    class ASTExp : public ASTNode
    {
        private:
        public:
            /*
             * function: constructor
             * params: None
             * return: None
             */
            ASTExp(); 
        
            /*
             * function: destructor
             * params: None
             * return: None
             */
            ~ASTExp();  
            
            /*
             * function: call back the check function of node
             * params: None
             * return: None
             */
            int check(); 
            
            /*
             * function: print the tree
             * params: Node
             * return: None
             */
            virtual void showTree();
    };
}

#endif