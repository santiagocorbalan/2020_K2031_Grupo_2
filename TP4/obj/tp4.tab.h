
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
     IDENTIFICADOR = 258,
     TIPO_DATO = 259,
     INCREMENTO = 260,
     DECREMENTO = 261,
     INCREMENTOASIGNACION = 262,
     DECREMENTOASIGNACION = 263,
     AND = 264,
     OR = 265,
     RELACIONALIGUAL = 266,
     RELACIONALDIFERENTE = 267,
     MAYORIGUAL = 268,
     MENORIGUAL = 269,
     ACCESOPUNTERO = 270,
     CONSTANTEDECIMAL = 271,
     CONSTANTEOCTAL = 272,
     CONSTANTEHEXADECIMAL = 273,
     CONSTANTEREAL = 274,
     CONSTANTECARACTER = 275,
     LITERALCADENA = 276,
     IF = 277,
     ELSE = 278,
     WHILE = 279,
     DO = 280,
     SWITCH = 281,
     FOR = 282,
     RETURN = 283
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 25 "../src/tp4.y"

    int enteroval;
    char* strval;
    double dobleval;



/* Line 1676 of yacc.c  */
#line 88 "tp4.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


