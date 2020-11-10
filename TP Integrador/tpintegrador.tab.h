
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TIPO_DATO = 258,
     IDENTIFICADOR = 259,
     LITERAL_CADENA = 260,
     CONSTANTE_DECIMAL = 261,
     CONSTANTE_OCTAL = 262,
     CONSTANTE_HEXADECIMAL = 263,
     CONSTANTE_REAL = 264,
     CONSTANTE_CARACTER = 265,
     OPER_ADITIVO = 266,
     OPER_MULTIPLICATIVO = 267,
     OPER_RELACIONAL = 268,
     OPER_UNARIO = 269,
     OPER_IGUALDAD = 270,
     OPER_ASIGNACION = 271,
     OPER_INCREMENTO = 272,
     OPER_SIZEOF = 273,
     AND = 274,
     OR = 275,
     IF = 276,
     SWITCH = 277,
     ELSE = 278,
     FOR = 279,
     WHILE = 280,
     DO = 281,
     RETURN = 282
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 19 "tpintegrador.y"

char cadena[100];
int entero;
float real;



/* Line 1676 of yacc.c  */
#line 87 "tpintegrador.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


