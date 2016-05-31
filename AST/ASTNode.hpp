#ifndef __AST_NODE__
#define __AST_NODE__

namespace UnUCompiler
{
    class ASTNode
    {
        public:
            /*
             * function: constructor
             * params: None
             * return: None
             */
            ASTNode(); 
        
            /*
             * function: destructor
             * params: None
             * return: None
             */
            ~ASTNode(); 
            
            /*
             * function: call back the check function of node
             * params: ASVisitor, visitor, the visitor install
             * return: None
             */
            virtual int check();
            
            /*
             * function: print the tree
             * params: Node
             * return: None
             */
            virtual void showTree();
    };
}
#endif