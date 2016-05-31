#ifndef __AST_INTEGER__
#define __AST_INTEGER__

#include "ASTValue.hpp"

namespace UnUCompiler
{
    class ASTInteger : public ASTValue
    {
    public:
        /*
         * function: constructor
         * params: None
         * return: None
         */
        ASTInteger ();
        
        /*
         * function: destructor
         * params: None
         * return: None
         */
        ~ASTInteger ();
        
        /*
         * function: set the value of _value
         * params: long long int, value, the value of _value
         * return: None
         */
        void setValue(long long int value);
        
        /*
         * function: get the value of _value
         * params: None
         * return: long long int
         */
        long long int getValue();
                    
        /*
         * function: print the tree
         * params: Node
         * return: None
         */
        void showTree();
    
    private:
        
    };
    
}

#endif