%{
#include <stack>
#include <string>
#include <iostream>
#include <typeinfo>
#include <fstream>

#include "../AST/ASTBody.hpp" 

using namespace std;
using namespace UnUCompiler;

int yylex();
bool yyInit(int args, char *argc[]);
int yyerror(const char *);

// the stack to store code block
std::stack<ASTBody*> blocks;

#define LOG(var) cout << "\e[32m" << var << "\e[0m" << endl;
%}

%token <Int> Integer
%token <Double> Float
%token <String> Token
%token <String> Assign
%token <String> Add
%token <String> Less
%token <String> Multiply
%token <String> Except
%token <String> Modulo
%token <String> BoolOPerator
%token <String> End

%code requires {
#include "../AST/ASTNode.hpp"
#include "../AST/ASTBody.hpp"
#include "../AST/ASTInteger.hpp"
#include "../AST/ASTExp.hpp"
#include "../AST/ASTOperator.hpp"
#include "../AST/ASTValue.hpp"

using namespace std;
using namespace UnUCompiler;

}

%union {
    ASTNode *node;
    ASTOperator *operatorNode;
    ASTExp *expNode;
    ASTValue *valueNode;
    ASTBody *bodyNode;
    long long int Int;
    char *String;
    double Double;
}

%left BoolOPerator
%left Add Less
%left Multiply Except Modulo

%type <bodyNode> codes
%type <node> code 
%type <expNode> exp 
%type <valueNode> value
%type <operatorNode> valueOperator

%%

codes : codes code { 
        LOG("Codes");
        $$ = new ASTBody(); 
        blocks.push($$); 
        $$->insertChild($2);
    }
      | { LOG("Empty Codes"); }
      ;

code : exp End { 
        LOG("Exp");
        $$ = $2;
    }
     | token Assign exp { 
         
     }
     | { LOG("Nil") }
     ;
     
exp : exp valueOperator {
        LOG("Value Operator");
        auto valueOperator = $2;
        valueOperator->setLeft($1);
        $$ = valueOperator;
    }
    | value { $$ = $1; }
    ;

value : Integer { 
        LOG("Integer"); 
        auto value = new ASTInteger();  
        value->setValue($1);
        $$ = value; 
    }
    | Float { 
        LOG("Float"); 
        auto value = new ASTInteger();  
        value->setValue($1);              
        $$ = value;
    }
    | Token { 
        LOG("Token"); 
        // auto value = new ASTInteger();  
        // value->setValue($1);   
        // $$ = value;
    }
    ;
    
valueOperator : Multiply exp { 
        LOG("Multiply"); 
        auto operatorType = new ASTOperator();
        operatorType->setOperator($1);
        operatorType->setRight($2);      
        $$ = operatorType; 
    }
    | Except exp { 
        LOG("Except"); 
        auto operatorType = new ASTOperator();
        operatorType->setOperator($1);
        operatorType->setRight($2);              
        $$ = operatorType; 
    }
    | Modulo exp { 
        LOG("Modulo"); 
        auto operatorType = new ASTOperator();
        operatorType->setOperator($1);
        operatorType->setRight($2);          
        $$ = operatorType;
    }
    | Add exp { 
        LOG("Add");         
        auto operatorType = new ASTOperator();
        operatorType->setOperator("+");
        operatorType->setRight($2);    
        $$ = operatorType; 
    }
    | Less exp { 
        LOG("Less"); 
        auto operatorType = new ASTOperator();
        operatorType->setOperator($1);
        operatorType->setRight($2);                    
        $$ = operatorType;
    }
    ;

%%

int yyerror(const char *emsage)
{
    cout << "Parse Error, The Message is >>> \e[32m " << emsage << "\e[0m" << endl;
    exit(0);
}

bool showBlock()
{
    bool result = false;
    if (blocks.size() == 1)
    {
        auto body = blocks.top();
        body->showTree();
        result = true;
    }
    while (!blocks.empty())
    {
        auto top = blocks.top();
        delete(top);
        top = nullptr;
        blocks.pop();
    }
    return result;
}

int main(int args, char *argc[])
{
    cout << "\e[12m" << "Welcom UnU" << endl;
    if (yyInit(args, argc)) 
    {
        yyparse();
        showBlock();
    }
    else 
    { 
        while (true) 
        { 
            yyparse();
            showBlock();
        } 
    }
    cout << "\e[0m" << endl;
}