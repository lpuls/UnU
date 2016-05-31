#ifndef __AST_TOKEN__
#define __AST_TOKEN__

#include "ASTValue.hpp"

namespace UnuCompiler
{
    class ASTToken : public ASTValue
    {
    public:
        /*
         * function: constructor
         * params: None
         * return: None
         */
         ASTToken(); 
        
        /*
         * function: destructor
         * params: None
         * return: None
         */
         ~ASTToken();  
            
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
         void showTree(); 
    };
    
}

#endif