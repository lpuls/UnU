#ifndef __AST_VALUE__
#define __AST_VALUE__

#include <string>

#include "ASTExp.hpp"

namespace UnUCompiler
{
    union ASTValueUnion
    {
        double Float;
        std::string Token;
        std::string String;
        long long int Integer;
        ASTValueUnion() {}
    };
    
    class ASTValue : public ASTExp
    {
        protected:
            /*
             * description: the data value
             * type: ASTValueUnion
             */
            ASTValueUnion *_value;
            
        public:
            /*
             * function: constructor
             * params: None
             * return: None
             */
            ASTValue(); 
        
            /*
             * function: destructor
             * params: None
             * return: None
             */
            ~ASTValue();  
            
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

