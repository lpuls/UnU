/********
 * function : lex tool
 * author : xp
 * 2016-5-18
 ********/
%{
#include "../PARSE/parse.hpp"

#include <iostream>
using namespace std;

#define LOG 
// cout << "\e[32m" << yytext << "\e[0m" << endl;
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
    yylval.Int = atoi(yytext);
    return Integer;
}
{FLOAT} {
    LOG;
    yylval.Double = atof(yytext);
    return Float;
}
{TOKEN} {
    LOG;
    yylval.String = yytext;
    return Token;
}
{ASSIGN} {
LOG;
    yylval.String = yytext;
    return Assign;
}
{ADD} {
    LOG;
    yylval.String = yytext;
    return Add;
} 
{LESS} {
    LOG;
    yylval.String = yytext;
    return Less;
} 
{MULTIPLY} {
    LOG;
    yylval.String = yytext;
    return Multiply;
} 
{EXCEPT} {
    LOG;
    yylval.String = yytext;
    return Except;
}
{MODULO} {
    LOG;
    yylval.String = yytext;
    return Modulo;
}
{BOOL_OPERATOR} {
    LOG;
    yylval.String = yytext;
    return BoolOPerator;
}
{SPACE} {
}
{END} {
    LOG;
    yylval.String = yytext;
    return End;
}
%%

int yywrap() 
{
    return 1;
}

bool yyInit(int args, char *argc[])
{
    if (args > 1)
    {
        cout << "\e[32m" << args << "\e[0m" << endl;
        yyin = fopen(argc[1], "r");
        return true;
    }
    return false;
}