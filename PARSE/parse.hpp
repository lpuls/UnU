/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSE_PARSE_HPP_INCLUDED
# define YY_YY_PARSE_PARSE_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 35 "PARSE/parse.y" /* yacc.c:1909  */

#include "../AST/ASTNode.hpp"
#include "../AST/ASTBody.hpp"
#include "../AST/ASTInteger.hpp"
#include "../AST/ASTExp.hpp"
#include "../AST/ASTOperator.hpp"
#include "../AST/ASTValue.hpp"

using namespace std;
using namespace UnUCompiler;


#line 57 "PARSE/parse.hpp" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    Integer = 258,
    Float = 259,
    Token = 260,
    Assign = 261,
    Add = 262,
    Less = 263,
    Multiply = 264,
    Except = 265,
    Modulo = 266,
    BoolOPerator = 267,
    End = 268
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 48 "PARSE/parse.y" /* yacc.c:1909  */

    ASTNode *node;
    ASTOperator *operatorNode;
    ASTExp *expNode;
    ASTValue *valueNode;
    ASTBody *bodyNode;
    long long int Int;
    char *String;
    double Double;

#line 94 "PARSE/parse.hpp" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSE_PARSE_HPP_INCLUDED  */
