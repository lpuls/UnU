/********
 * function : lex tool
 * author : xp
 * 2016-5-18
 ********/
%{

#include <iostream>
using namespace std;

#define LOG cout << "\e[32m" << yytext << "\e[0m" << endl;
%}


INTEGER [1-9][0-9]*|[0]
FLOAT [0-9]*[.][0-9]+([eE][+-]?[0-9]*|[0])?f?
TOKEN [a-zA-Z]*
ASSIGN [=]
ADD [+]
LESS [-]
MULTIPLY [*]
EXCEPT [/]
MODULO [%]
BOOL_OPERATOR [>]|[<]|[>=]|[<=]|[==]
SPACE [ \t\n]
END [;]

%%
{INTEGER} {
    LOG;
}
{FLOAT} {
    LOG;
}
{TOKEN} {
    LOG;
}
{ASSIGN} {
LOG;
}
{ADD} {
    LOG;
} 
{LESS} {
    LOG;
} 
{MULTIPLY} {
    LOG;
} 
{EXCEPT} {
    LOG;
}
{MODULO} {
    LOG;
}
{BOOL_OPERATOR} {
    LOG;
}
{SPACE} {
}
{END} {
    LOG;
}
%%

int yywrap() 
{
    return 1;
}

int main()
{
    yylex();
    return 0;
}