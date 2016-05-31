#ifndef __AST_OPERATOR__
#define __AST_OPERATOR__

#include <string>

#include "ASTExp.hpp"
#include "../Tools/Tools.hpp"

namespace UnUCompiler
{
    class ASTOperator : public ASTExp
    {
        private:
            /*
             * description: store the child node
             * type: std::string
             */
            DEFINE_PROTECTED(std::string, _operator, Operator);
            
            /*
             * description: left value
             * type: ASTExp*
             */
            DEFINE_PROTECTED(ASTExp*, _left, Left);
            
            /*
             * description: right value
             * type: ASTExp*
             */
            DEFINE_PROTECTED(ASTExp*, _right, Right);
            
        public:
            /*
             * function: constructor
             * params: None
             * return: None
             */
            ASTOperator();
                    
            /*
             * function: destructor
             * params: None
             * return: None
             */
            ~ASTOperator();
    
            /*
             * function: call back the check function of node
             * params: ASVisitor, visitor, the visitor install
             * return: None
             */
            int check();
            
            /*
             * function: printe the struct of ast
             * params: None
             * return: None
             */
            void showTree();
            
        
    };
    
}

#endif