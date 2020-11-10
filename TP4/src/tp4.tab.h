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
/* Tokens.  */
#define TIPO_DATO 258
#define IDENTIFICADOR 259
#define LITERAL_CADENA 260
#define CONSTANTE_DECIMAL 261
#define CONSTANTE_OCTAL 262
#define CONSTANTE_HEXADECIMAL 263
#define CONSTANTE_REAL 264
#define CONSTANTE_CARACTER 265
#define OPER_ADITIVO 266
#define OPER_MULTIPLICATIVO 267
#define OPER_RELACIONAL 268
#define OPER_UNARIO 269
#define OPER_IGUALDAD 270
#define OPER_ASIGNACION 271
#define OPER_INCREMENTO 272
#define OPER_SIZEOF 273
#define AND 274
#define OR 275
#define IF 276
#define SWITCH 277
#define ELSE 278
#define FOR 279
#define WHILE 280
#define DO 281
#define RETURN 282




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 19 "tp4.y"
{
char cadena[100];
int entero;
float real;
}
/* Line 1529 of yacc.c.  */
#line 109 "tp4.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

