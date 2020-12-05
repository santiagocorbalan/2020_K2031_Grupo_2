/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
     TIPO_DE_DATO = 258,
     VOID = 259,
     IDENTIFICADOR = 260,
     LITERAL_CADENA = 261,
     CONSTANTE_ENTERA = 262,
     CONSTANTE_REAL = 263,
     CONSTANTE_CARACTER = 264,
     SWITCH = 265,
     DO = 266,
     WHILE = 267,
     IF = 268,
     ELSE = 269,
     FOR = 270,
     BREAK = 271,
     CONTINUE = 272,
     RETURN = 273
   };
#endif
/* Tokens.  */
#define TIPO_DE_DATO 258
#define VOID 259
#define IDENTIFICADOR 260
#define LITERAL_CADENA 261
#define CONSTANTE_ENTERA 262
#define CONSTANTE_REAL 263
#define CONSTANTE_CARACTER 264
#define SWITCH 265
#define DO 266
#define WHILE 267
#define IF 268
#define ELSE 269
#define FOR 270
#define BREAK 271
#define CONTINUE 272
#define RETURN 273




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 29 "TP5.y"
{
    int entero; 
    float real;
    char caracter;
    char* cadena;

struct yylval_struct
  {
      int tipo;
      int valor_entero;
      float valor_real;
      char valor_caracter;
  } mystruct;
}
/* Line 1529 of yacc.c.  */
#line 100 "TP5.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

