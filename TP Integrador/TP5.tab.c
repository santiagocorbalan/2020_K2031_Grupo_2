/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "TP5.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Funciones.c"

int yylex();

FILE* yyin;

int yywrap(){
        return(1);
}

void yyerror (char const *s) {          //Con yyerror se detecta el error sintáctico 
   fprintf (stderr, "%s\n", s);
} 

char* tipo;
Tabla *aux;
Tabla *aux2;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 27 "TP5.y"
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
/* Line 193 of yacc.c.  */
#line 173 "TP5.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 186 "TP5.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   199

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNRULES -- Number of states.  */
#define YYNSTATES  158

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   273

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      19,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      23,    24,    25,    28,    26,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    20,
       2,    27,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    21,     2,    22,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    12,    15,    18,    21,
      23,    25,    27,    29,    31,    34,    35,    37,    42,    43,
      45,    47,    50,    51,    53,    55,    58,    64,    72,    76,
      82,    88,    92,    98,   104,   108,   114,   122,   132,   136,
     146,   149,   152,   156,   157,   161,   162,   167,   168,   172,
     175,   178,   180,   183,   185,   187,   191,   193,   197,   201,
     205,   209,   213,   217,   220,   225,   230,   231,   233,   237,
     240,   244,   247,   251,   254,   258,   260,   262,   264,   268,
     273,   278,   283,   285,   289,   290,   292,   294,   296,   298
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      30,     0,    -1,    -1,    30,    31,    -1,    19,    -1,    55,
      19,    -1,    32,    19,    -1,    43,    19,    -1,    56,    19,
      -1,    33,    -1,    35,    -1,    40,    -1,    41,    -1,    42,
      -1,    34,    20,    -1,    -1,    55,    -1,    21,    36,    38,
      22,    -1,    -1,    37,    -1,    43,    -1,    37,    43,    -1,
      -1,    39,    -1,    32,    -1,    39,    32,    -1,    13,    23,
      55,    24,    32,    -1,    13,    23,    55,    24,    32,    14,
      32,    -1,    13,     1,    55,    -1,    13,    23,    55,     1,
      32,    -1,    10,    23,    55,    24,    32,    -1,    10,     1,
      55,    -1,    10,    23,    55,     1,    32,    -1,    12,    23,
      55,    24,    32,    -1,    12,     1,    55,    -1,    12,    23,
      55,     1,    32,    -1,    11,    32,    12,    23,    55,    24,
      20,    -1,    15,    23,    34,    20,    34,    20,    34,    24,
      32,    -1,    15,     1,    34,    -1,    15,    23,    34,    20,
      34,    20,    34,     1,    32,    -1,    17,    20,    -1,    16,
      20,    -1,    18,    34,    20,    -1,    -1,     3,    44,    48,
      -1,    -1,     3,    25,    45,    48,    -1,    -1,     4,    46,
      47,    -1,     5,    52,    -1,     1,    52,    -1,    47,    -1,
      49,    20,    -1,    50,    -1,    51,    -1,    51,    26,    50,
      -1,     5,    -1,     5,    27,     5,    -1,     5,    27,     7,
      -1,     5,    27,     9,    -1,     5,    27,     8,    -1,     5,
      27,     6,    -1,     5,    27,     1,    -1,     1,    27,    -1,
      23,    53,    24,    35,    -1,    23,    53,    24,    20,    -1,
      -1,    54,    -1,    54,    26,    53,    -1,     3,     5,    -1,
       3,    25,     5,    -1,     1,     5,    -1,     1,    25,     5,
      -1,     3,     1,    -1,     3,    25,     1,    -1,     7,    -1,
       8,    -1,     5,    -1,    55,    28,    55,    -1,     5,    23,
      57,    24,    -1,     5,     1,    57,    24,    -1,     5,    23,
      57,     1,    -1,    58,    -1,    58,    26,    57,    -1,    -1,
       5,    -1,     6,    -1,     7,    -1,     9,    -1,     8,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    66,    66,    67,    70,    71,    72,    73,    74,    77,
      78,    79,    80,    81,    84,    87,    88,    91,    94,    95,
      98,    99,   102,   103,   106,   107,   111,   112,   113,   114,
     115,   116,   117,   120,   121,   122,   123,   124,   125,   126,
     130,   131,   132,   136,   136,   137,   137,   138,   138,   141,
     150,   153,   154,   157,   160,   161,   164,   190,   223,   236,
     250,   262,   275,   276,   280,   281,   284,   285,   286,   289,
     290,   291,   292,   293,   294,   297,   298,   299,   318,   339,
     352,   353,   356,   357,   360,   361,   368,   369,   370,   371
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TIPO_DE_DATO", "VOID", "IDENTIFICADOR",
  "LITERAL_CADENA", "CONSTANTE_ENTERA", "CONSTANTE_REAL",
  "CONSTANTE_CARACTER", "SWITCH", "DO", "WHILE", "IF", "ELSE", "FOR",
  "BREAK", "CONTINUE", "RETURN", "'\\n'", "';'", "'{'", "'}'", "'('",
  "')'", "'*'", "','", "'='", "'+'", "$accept", "input", "line",
  "sentencia", "sentenciaExpresion", "opExpresion", "sentenciaCompuesta",
  "opListaDeclaraciones", "listaDeclaraciones", "opListaDeSentencias",
  "listaDeSentencias", "sentenciaDeSeleccion", "sentenciaDeIteracion",
  "sentenciaDeSalto", "declaracion", "@1", "@2", "@3",
  "declaracionDefinicionFuncion", "declaraciones", "declaracionVariables",
  "listaVariables", "unaVariableSimple", "parametrosCuerpoFuncion",
  "listaParametros", "parametros", "expresion", "invocacionDeFuncion",
  "listaArgumentos", "argumento", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,    10,
      59,   123,   125,    40,    41,    42,    44,    61,    43
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    29,    30,    30,    31,    31,    31,    31,    31,    32,
      32,    32,    32,    32,    33,    34,    34,    35,    36,    36,
      37,    37,    38,    38,    39,    39,    40,    40,    40,    40,
      40,    40,    40,    41,    41,    41,    41,    41,    41,    41,
      42,    42,    42,    44,    43,    45,    43,    46,    43,    47,
      47,    48,    48,    49,    50,    50,    51,    51,    51,    51,
      51,    51,    51,    51,    52,    52,    53,    53,    53,    54,
      54,    54,    54,    54,    54,    55,    55,    55,    55,    56,
      56,    56,    57,    57,    58,    58,    58,    58,    58,    58
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     2,     0,     1,     4,     0,     1,
       1,     2,     0,     1,     1,     2,     5,     7,     3,     5,
       5,     3,     5,     5,     3,     5,     7,     9,     3,     9,
       2,     2,     3,     0,     3,     0,     4,     0,     3,     2,
       2,     1,     2,     1,     1,     3,     1,     3,     3,     3,
       3,     3,     3,     2,     4,     4,     0,     1,     3,     2,
       3,     2,     3,     2,     3,     1,     1,     1,     3,     4,
       4,     4,     1,     3,     0,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,    15,     1,    43,    47,     0,    75,    76,     0,    15,
       0,     0,     0,     0,     0,    15,     4,    18,     3,     0,
       9,     0,    10,    11,    12,    13,     0,    16,     0,    45,
       0,     0,    84,    84,     0,     0,    77,     0,    16,     0,
       0,     0,     0,    15,    15,    41,    40,     0,    15,    19,
      20,     6,    14,     7,     5,     0,     8,     0,     0,    56,
      51,    44,     0,    53,    54,     0,     0,    48,    85,    86,
      87,    89,    88,     0,    82,     0,    31,     0,     0,    34,
       0,    28,     0,    38,     0,    42,    24,     0,    15,    21,
      78,    46,     0,    63,    50,     0,    49,    52,     0,    80,
      84,    81,    79,    15,    15,     0,    15,    15,    15,    15,
      15,    17,    25,     0,     0,     0,    67,    62,    57,    61,
      58,    60,    59,     0,    56,    55,    83,    32,    30,     0,
      35,    33,    29,    26,     0,    71,     0,    73,    69,     0,
       0,     0,     0,    15,    15,    72,    74,    70,    65,    64,
      68,    36,    27,     0,    15,    15,    39,    37
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    18,    19,    20,    21,    22,    48,    49,    87,
      88,    23,    24,    25,    26,    30,    57,    31,    60,    61,
      62,    63,    64,    94,   115,   116,    38,    28,    73,    74
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -53
static const yytype_int16 yypact[] =
{
     -53,   104,   -53,     0,   -53,     3,   -53,   -53,     5,   178,
      26,    52,    53,    57,    67,    83,   -53,    89,   -53,    45,
     -53,    81,   -53,   -53,   -53,   -53,    86,   -10,    91,   -53,
      12,    14,    75,    75,    83,    83,   -53,    60,    58,    83,
      83,    83,    83,    83,    83,   -53,   -53,    82,   142,    89,
     -53,   -53,   -53,   -53,   -53,    83,   -53,    12,    -7,    42,
     -53,   -53,    93,   -53,    77,    95,    95,   -53,   -53,   -53,
     -53,   -53,   -53,   100,   101,     9,    58,    10,   103,    58,
      20,    58,    23,   -53,   108,   -53,   -53,   107,   160,   -53,
      58,   -53,    49,   -53,   -53,    54,   -53,   -53,    66,   -53,
      75,   -53,   -53,   178,   178,    83,   178,   178,   178,   178,
      83,   -53,   -53,    41,     7,   109,   105,   -53,   -53,   -53,
     -53,   -53,   -53,   110,   111,   -53,   -53,   -53,   -53,    50,
     -53,   -53,   -53,   118,   115,   -53,   131,   -53,   -53,    84,
      37,    49,   119,   178,    83,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,    44,   178,   178,   -53,   -53
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -53,   -53,   -53,    -9,   -53,   -14,     2,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,   -12,   -53,   -53,   -53,   112,    87,
     -53,    43,   -53,   -52,    -1,   -53,     1,   -53,   -30,   -53
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -78
static const yytype_int16 yytable[] =
{
      37,    47,    27,    75,    32,    50,    34,    96,   137,    54,
     101,   103,   138,    58,    96,    65,    92,    59,    55,    66,
      93,   106,   -77,   -77,   108,    29,    33,    39,    35,    83,
      84,   -77,   139,   102,   104,    76,    77,    89,    55,    86,
      79,    80,    81,    82,   107,   154,   135,   109,    55,    40,
     113,    55,   114,    41,    43,   117,    90,   148,    17,   118,
     119,   120,   121,   122,    51,    92,   136,   123,   155,    95,
     126,   124,    78,   -66,   142,    42,    44,    45,    55,   112,
      68,    69,    70,    71,    72,   146,    55,    46,    36,   147,
       6,     7,     3,     4,   127,   128,   134,   130,   131,   132,
     133,    52,    85,    98,     2,    53,   129,     3,     4,     5,
      56,     6,     7,    97,     8,     9,    10,    11,    92,    12,
      13,    14,    15,    16,    99,    17,   105,   100,   110,   111,
     153,   141,   143,   140,   152,   144,   145,    93,    95,   151,
     150,   125,   149,    67,    91,   156,   157,    36,     0,     6,
       7,     0,     8,     9,    10,    11,     0,    12,    13,    14,
      15,     0,     0,    17,   -22,    36,     0,     6,     7,     0,
       8,     9,    10,    11,     0,    12,    13,    14,    15,     0,
       0,    17,   -23,    36,     0,     6,     7,     0,     8,     9,
      10,    11,     0,    12,    13,    14,    15,     0,     0,    17
};

static const yytype_int16 yycheck[] =
{
       9,    15,     1,    33,     1,    17,     1,    59,     1,    19,
       1,     1,     5,     1,    66,     1,    23,     5,    28,     5,
      27,     1,    19,    20,     1,    25,    23,     1,    23,    43,
      44,    28,    25,    24,    24,    34,    35,    49,    28,    48,
      39,    40,    41,    42,    24,     1,     5,    24,    28,    23,
       1,    28,     3,     1,     1,     1,    55,    20,    21,     5,
       6,     7,     8,     9,    19,    23,    25,     1,    24,    27,
     100,     5,    12,    24,    24,    23,    23,    20,    28,    88,
       5,     6,     7,     8,     9,     1,    28,    20,     5,     5,
       7,     8,     3,     4,   103,   104,   110,   106,   107,   108,
     109,    20,    20,    26,     0,    19,   105,     3,     4,     5,
      19,     7,     8,    20,    10,    11,    12,    13,    23,    15,
      16,    17,    18,    19,    24,    21,    23,    26,    20,    22,
     144,    26,    14,    24,   143,    20,     5,    27,    27,    20,
     141,    98,   140,    31,    57,   154,   155,     5,    -1,     7,
       8,    -1,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    -1,    -1,    21,    22,     5,    -1,     7,     8,    -1,
      10,    11,    12,    13,    -1,    15,    16,    17,    18,    -1,
      -1,    21,    22,     5,    -1,     7,     8,    -1,    10,    11,
      12,    13,    -1,    15,    16,    17,    18,    -1,    -1,    21
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,     0,     3,     4,     5,     7,     8,    10,    11,
      12,    13,    15,    16,    17,    18,    19,    21,    31,    32,
      33,    34,    35,    40,    41,    42,    43,    55,    56,    25,
      44,    46,     1,    23,     1,    23,     5,    32,    55,     1,
      23,     1,    23,     1,    23,    20,    20,    34,    36,    37,
      43,    19,    20,    19,    19,    28,    19,    45,     1,     5,
      47,    48,    49,    50,    51,     1,     5,    47,     5,     6,
       7,     8,     9,    57,    58,    57,    55,    55,    12,    55,
      55,    55,    55,    34,    34,    20,    32,    38,    39,    43,
      55,    48,    23,    27,    52,    27,    52,    20,    26,    24,
      26,     1,    24,     1,    24,    23,     1,    24,     1,    24,
      20,    22,    32,     1,     3,    53,    54,     1,     5,     6,
       7,     8,     9,     1,     5,    50,    57,    32,    32,    55,
      32,    32,    32,    32,    34,     5,    25,     1,     5,    25,
      24,    26,    24,    14,    20,     5,     1,     5,    20,    35,
      53,    20,    32,    34,     1,    24,    32,    32
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 15:
#line 87 "TP5.y"
    {printf("Se encontro una sentencia vacia\n");;}
    break;

  case 16:
#line 88 "TP5.y"
    {printf("Se encontro una sentencia con una expresion\n");;}
    break;

  case 19:
#line 95 "TP5.y"
    {printf("Se encontro una sentencia compuesta con una lista de declaraciones\n");;}
    break;

  case 23:
#line 103 "TP5.y"
    {printf("Se encontro una sentencia compuesta con una lista de sentencias\n");;}
    break;

  case 26:
#line 111 "TP5.y"
    {printf("Se encontro una sentencia IF\n");;}
    break;

  case 27:
#line 112 "TP5.y"
    {printf("Se encontro una sentencia IF y ELSE\n");;}
    break;

  case 28:
#line 113 "TP5.y"
    {agregarError("Error Sintactico: Despues del IF se espera un '('\n"); ;}
    break;

  case 29:
#line 114 "TP5.y"
    {agregarError("Error Sintactico: falta ')' en la sentencia IF\n"); ;}
    break;

  case 30:
#line 115 "TP5.y"
    {printf("Se encontro una sentencia SWITCH\n");;}
    break;

  case 31:
#line 116 "TP5.y"
    {agregarError("Error Sintactico: Despues del SWITCH se espera un '('\n"); ;}
    break;

  case 32:
#line 117 "TP5.y"
    {agregarError("Error Sintactico: falta ')' en la sentencia SWITCH\n"); ;}
    break;

  case 33:
#line 120 "TP5.y"
    {printf("Se encontro la sentencia WHILE\n");;}
    break;

  case 34:
#line 121 "TP5.y"
    {agregarError("Error Sintactico: Despues del WHILE se espera un '('\n"); ;}
    break;

  case 35:
#line 122 "TP5.y"
    {agregarError("Error Sintactico: falta ')' en la sentencia WHILE\n"); ;}
    break;

  case 36:
#line 123 "TP5.y"
    {printf("Se encontro una sentencia DO\n");;}
    break;

  case 37:
#line 124 "TP5.y"
    {printf("Se encontro una sentencia FOR\n");;}
    break;

  case 38:
#line 125 "TP5.y"
    {agregarError("Error Sintactico: Despues del FOR se espera un '('\n"); ;}
    break;

  case 39:
#line 126 "TP5.y"
    {agregarError("Error Sintactico: falta ')' en la sentencia FOR\n"); ;}
    break;

  case 40:
#line 130 "TP5.y"
    {printf("Se encontro la sentencia CONTINUE\n");;}
    break;

  case 41:
#line 131 "TP5.y"
    {printf("Se encontro la sentencia BREAK\n");;}
    break;

  case 42:
#line 132 "TP5.y"
    {printf("Se encontro la sentencia RETURN\n");;}
    break;

  case 43:
#line 136 "TP5.y"
    {tipo = (yyvsp[(1) - (1)].cadena); ;}
    break;

  case 45:
#line 137 "TP5.y"
    {tipo = concatenar((yyvsp[(1) - (2)].cadena), "*"); ;}
    break;

  case 47:
#line 138 "TP5.y"
    {tipo = "void"; ;}
    break;

  case 49:
#line 141 "TP5.y"
    { 
                                                                        aux=buscarSimbolo((yyvsp[(1) - (2)].cadena)); 
                                                                        if (aux) 
                                                                                agregarError("Error Semantico : el identificador ya esta declarado");  
                                                                        else 
                                                                                aux2 = agregoSimbolo2((yyvsp[(1) - (2)].cadena) , tipo, 2);   
                                                                                aux->tiposParametros = listaParametrosAux; 
                                                                                listaParametrosAux = NULL; 
                                                                ;}
    break;

  case 50:
#line 150 "TP5.y"
    { agregarError("Error Sintactico : nombre de la funcion incorrecto"); ;}
    break;

  case 56:
#line 165 "TP5.y"
    {
                                        aux=buscarSimbolo((yyvsp[(1) - (1)].cadena)); 
                                        if (aux) 
                                                agregarError("Error Semantico: la variable ya esta declarada\n"); 
                                        else 
                                        {
                                                aux = agregoSimbolo2((yyvsp[(1) - (1)].cadena), tipo, 1);

                                                        if (strcmp(aux-> tipo, "int") == 0) {
                                                                aux->value.valEnt = 0;
                                                        
                                                        } else if (strcmp(aux -> tipo, "float") == 0) {
                                                                aux->value.valReal = 0.0;

                                                        } else if (strcmp(aux -> tipo, "char") == 0) {
                                                                aux->value.valChar = '\0';

                                                        } else if (strcmp(aux -> tipo, "char*") == 0){
                                                                aux->value.valString = NULL;
                                                        }
                                                        
                                        }
                                                                                                            
                                ;}
    break;

  case 57:
#line 191 "TP5.y"
    {
                                aux=buscarSimbolo((yyvsp[(1) - (3)].cadena)); 
                                if (aux) 
                                        agregarError("Error Semantico : la variable ya esta declarada\n"); 
                                else 
                                {
                                        aux2=buscarSimbolo((yyvsp[(3) - (3)].cadena)); 
                                        if(aux2 && (strcmp(tipo, aux2->tipo) == 0)) { 
                                                aux = agregoSimbolo2((yyvsp[(1) - (3)].cadena) , tipo, 1); 

                                                if (strcmp(aux-> tipo, "int") == 0) {
                                                        aux2->value.valEnt = (yyvsp[(3) - (3)].entero);

                                                } else if (strcmp(aux -> tipo, "float") == 0) {
                                                        aux2->value.valReal = (yyvsp[(3) - (3)].real);

                                                } else if (strcmp(aux -> tipo, "char") == 0){
                                                        aux2->value.valChar = (yyvsp[(3) - (3)].caracter);

                                                } else if (strcmp(aux -> tipo, "char*") == 0) {
                                                        aux2->value.valString = (yyvsp[(3) - (3)].cadena);
                                                }
                                        }            
                                                                                                                                                                   
                                        if (aux2 == NULL)
                                                agregarError("Error Semantico : la variable no esta declarada\n");

                                        if (aux2 && (strcmp(tipo, aux2->tipo) != 0))
                                                agregarError("Error Semantico : las variables son de distinto tipo\n");
                                }
                        ;}
    break;

  case 58:
#line 223 "TP5.y"
    { 
                                                                aux = buscarSimbolo((yyvsp[(1) - (3)].cadena)); 
                                                                if (aux) 
                                                                        agregarError("Error Semantico : la variable ya esta declarada "); 
                                                                        else {
                                                                                if(strcmp(tipo,"int") == 0){ 
                                                                                        aux = agregoSimbolo2((yyvsp[(1) - (3)].cadena) , tipo, 1);  
                                                                                        aux->value.valEnt = (yyvsp[(3) - (3)].mystruct).valor_entero;}
                                                                                else
                                                                                        agregarError("Error Semantico : son de distinto tipo"); 
                                                                        }
                                                        ;}
    break;

  case 59:
#line 236 "TP5.y"
    {
                                                                aux=buscarSimbolo((yyvsp[(1) - (3)].cadena)); 
                                                                if (aux) 
                                                                        agregarError("Error Semantico : la variable ya esta declarada "); 
                                                                else {
                                                                        if (strcmp(tipo, "char") == 0) {
                                                                                aux = agregoSimbolo2((yyvsp[(1) - (3)].cadena) , tipo, 1);  
                                                                                aux->value.valChar = (yyvsp[(3) - (3)].caracter); 
                                                                        }
                                                                        else 
                                                                                agregarError("Error Semantico : son de distinto tipo");
                                                                }
                                                        ;}
    break;

  case 60:
#line 250 "TP5.y"
    { 
                                                                aux=buscarSimbolo((yyvsp[(1) - (3)].cadena)); 
                                                                if (aux) 
                                                                        agregarError("Error Semantico : la variable ya esta declarada "); 
                                                                else
                                                                        if (strcmp(tipo, "double") == 0){ // si borro "0" me toma el if
                                                                                aux = agregoSimbolo2((yyvsp[(1) - (3)].cadena) , tipo, 1);  
                                                                                aux->value.valReal = (yyvsp[(3) - (3)].mystruct).valor_real;} 
                                                                        else{
                                                                                agregarError("Error Semantico : son de distinto tipo "); }
                                                        ;}
    break;

  case 61:
#line 262 "TP5.y"
    {
                                                                aux=buscarSimbolo((yyvsp[(1) - (3)].cadena)); 
                                                                if (aux) 
                                                                        agregarError("Error Semantico : la variable ya esta declarada "); 
                                                                else 
                                                                        if (strcmp(tipo, "char*") == 0){
                                                                                aux = agregoSimbolo2((yyvsp[(1) - (3)].cadena) , tipo, 1);  
                                                                                aux->value.valString = (yyvsp[(3) - (3)].cadena);}  
                                                                        else 
                                                                                agregarError("Error Semantico : son de distinto tipo ");
                                                        ;}
    break;

  case 62:
#line 275 "TP5.y"
    { agregarError("Error Sintactico : se inicializo con un valor incorrecto"); ;}
    break;

  case 63:
#line 276 "TP5.y"
    { agregarError("Error Sintactico : identificador incorrecto"); ;}
    break;

  case 66:
#line 284 "TP5.y"
    {agregoParametro("void");;}
    break;

  case 69:
#line 289 "TP5.y"
    { agregoParametro((yyvsp[(1) - (2)].cadena)); ;}
    break;

  case 70:
#line 290 "TP5.y"
    { agregoParametro(concatenar((yyvsp[(1) - (3)].cadena), "*")); ;}
    break;

  case 71:
#line 291 "TP5.y"
    { agregarError("ERROR SINTACTICO : falta tipo de dato del parametro"); ;}
    break;

  case 72:
#line 292 "TP5.y"
    { agregarError("ERROR SINTACTICO : falta tipo de dato del puntero parametro"); ;}
    break;

  case 73:
#line 293 "TP5.y"
    { agregarError("ERROR SINTACTICO : falta identificador en parametro"); ;}
    break;

  case 74:
#line 294 "TP5.y"
    { agregarError("ERROR SINTACTICO : falta identificador del puntero parametro"); ;}
    break;

  case 75:
#line 297 "TP5.y"
    { (yyval.mystruct).tipo = (yyvsp[(1) - (1)].mystruct).tipo;  (yyval.mystruct).valor_entero = (yyvsp[(1) - (1)].mystruct).valor_entero;;}
    break;

  case 76:
#line 298 "TP5.y"
    { (yyval.mystruct).tipo = (yyvsp[(1) - (1)].mystruct).tipo;  (yyval.mystruct).valor_real = (yyvsp[(1) - (1)].mystruct).valor_real;;}
    break;

  case 77:
#line 299 "TP5.y"
    { 
                                        aux=buscarSimbolo((yyvsp[(1) - (1)].cadena)); 
                                        if (aux) {  
                                                if (strcmp(aux->tipo, "int") == 0) {
                                                        (yyval.mystruct).valor_entero = aux->value.valEnt; 
                                                        (yyval.mystruct).tipo = 1;
                                                        }

                                                else if (strcmp(aux-> tipo,"float") == 0){
                                                        (yyval.mystruct).valor_real = aux->value.valReal;  // cambio valor_float por valor_real
                                                        (yyval.mystruct).tipo = 2;
                                                }
                                        } 
                                        else 
                                        { 
                                                agregarError("La variable no esta declarada\n");  
                                        } 
                                ;}
    break;

  case 78:
#line 318 "TP5.y"
    { 
                                                if((yyvsp[(1) - (3)].mystruct).tipo == (yyvsp[(3) - (3)].mystruct).tipo) { 
        
                                                        if ((yyvsp[(1) - (3)].mystruct).tipo == 1) { 
                                                                (yyval.mystruct).valor_entero=(yyvsp[(1) - (3)].mystruct).valor_entero + (yyvsp[(3) - (3)].mystruct).valor_entero; 
                                                        } else {
                                                                (yyval.mystruct).valor_real = (yyvsp[(1) - (3)].mystruct).valor_real + (yyvsp[(3) - (3)].mystruct).valor_real; 
                                                        }
                                                } else { 
                                                        agregarError("Los operandos son de distinto tipo \n"); 
                                                }
        
                                        ;}
    break;

  case 79:
#line 339 "TP5.y"
    {
                                                                aux = buscarSimbolo((yyvsp[(1) - (4)].cadena));   
                                                                if (aux) { 
                                                                        if(aux -> variableOfuncion == 1){
                                                                                agregarError ("Error semantico : El IDENTIFICADOR esta declarado como variable");} 
                                                                        else if (compararParametros(aux->tiposParametros, listaParametrosAux) == 1){
                                                                                agregarError ("Error semantico : cantidad o tipos de parametros incorrectos");} 
                                                                } 
                                                                else {
                                                                        agregarError ("Error semantico : No esta declarada la funcion"); 
                                                                }
                                                                listaParametrosAux = NULL;
                                                                ;}
    break;

  case 80:
#line 352 "TP5.y"
    {agregarError("Error Sintactico : falta '(' en la invocacion de la funcion"); ;}
    break;

  case 81:
#line 353 "TP5.y"
    {agregarError("Error Sintactico : falta ')' en la invocacion de la funcion"); ;}
    break;

  case 84:
#line 360 "TP5.y"
    {agregoArgumento("void");;}
    break;

  case 85:
#line 361 "TP5.y"
    {        
                                        aux=buscarSimbolo((yyvsp[(1) - (1)].cadena));    
                                        if (aux) 
                                                agregoArgumento(aux->tipo); 
                                        else 
                                                agregarError("Error Semantico : la variable no esta declarada\n");
                                ;}
    break;

  case 86:
#line 368 "TP5.y"
    { agregoArgumento("char*"); ;}
    break;

  case 87:
#line 369 "TP5.y"
    { agregoArgumento("int"); ;}
    break;

  case 88:
#line 370 "TP5.y"
    { agregoArgumento("char"); ;}
    break;

  case 89:
#line 371 "TP5.y"
    { agregoArgumento("real"); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1949 "TP5.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 374 "TP5.y"


Tabla *listaSimbolos;

int main(){
        yyin = fopen("docDePrueba.c","r");
        printf("\n");
        yyparse();

        mostrarSimbolos(listaSimbolos);
        mostrarErrores(listaErrores);
}
