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
#include <ctype.h>
#include "Funciones.c"

int yylex();

FILE* yyin;

int yywrap(){
        return(1);
}

void yyerror (char const *s) {          //Con yyerror se detecta el error sintáctico 
   fprintf (stderr, "%s\n", s);
} 

char* tipo = NULL;
Tabla *aux = NULL;
Tabla *aux2 = NULL;
//Tabla *listaSimbolos = NULL;



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
#line 28 "TP5.y"
{
    int entero; 
    float real;
    char caracter;
    char cadena[100];

struct yylval_struct
  {
      int tipo;
      int valor_entero;
      float valor_real;
      char valor_caracter;
  } mystruct;
}
/* Line 193 of yacc.c.  */
#line 174 "TP5.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 187 "TP5.tab.c"

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
#define YYLAST   189

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNRULES -- Number of states.  */
#define YYNSTATES  157

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
      24,    26,    28,    30,    32,    34,    37,    38,    40,    45,
      46,    48,    50,    53,    54,    56,    58,    61,    67,    75,
      79,    85,    91,    95,   101,   107,   111,   117,   125,   135,
     139,   149,   152,   155,   159,   162,   166,   169,   171,   174,
     177,   180,   182,   184,   188,   190,   194,   198,   202,   206,
     210,   214,   217,   222,   227,   228,   230,   234,   237,   241,
     244,   248,   251,   255,   257,   259,   261,   265,   270,   275,
     280,   282,   286,   287,   289,   291,   293,   295
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      30,     0,    -1,    -1,    30,    31,    -1,    19,    -1,    52,
      19,    -1,    32,    19,    -1,    43,    19,    -1,    53,    19,
      -1,     1,    19,    -1,    33,    -1,    35,    -1,    40,    -1,
      41,    -1,    42,    -1,    34,    20,    -1,    -1,    52,    -1,
      21,    36,    38,    22,    -1,    -1,    37,    -1,    43,    -1,
      37,    43,    -1,    -1,    39,    -1,    32,    -1,    39,    32,
      -1,    13,    23,    52,    24,    32,    -1,    13,    23,    52,
      24,    32,    14,    32,    -1,    13,     1,    52,    -1,    13,
      23,    52,     1,    32,    -1,    10,    23,    52,    24,    32,
      -1,    10,     1,    52,    -1,    10,    23,    52,     1,    32,
      -1,    12,    23,    52,    24,    32,    -1,    12,     1,    52,
      -1,    12,    23,    52,     1,    32,    -1,    11,    32,    12,
      23,    52,    24,    20,    -1,    15,    23,    34,    20,    34,
      20,    34,    24,    32,    -1,    15,     1,    34,    -1,    15,
      23,    34,    20,    34,    20,    34,     1,    32,    -1,    17,
      20,    -1,    16,    20,    -1,    18,    34,    20,    -1,     3,
      44,    -1,     3,    25,    44,    -1,     4,    45,    -1,    45,
      -1,    46,    20,    -1,     5,    49,    -1,     1,    49,    -1,
      47,    -1,    48,    -1,    48,    26,    47,    -1,     5,    -1,
       5,    27,     5,    -1,     5,    27,     7,    -1,     5,    27,
       9,    -1,     5,    27,     8,    -1,     5,    27,     6,    -1,
       5,    27,     1,    -1,     1,    27,    -1,    23,    50,    24,
      35,    -1,    23,    50,    24,    20,    -1,    -1,    51,    -1,
      51,    26,    50,    -1,     3,     5,    -1,     3,    25,     5,
      -1,     1,     5,    -1,     1,    25,     5,    -1,     3,     1,
      -1,     3,    25,     1,    -1,     7,    -1,     8,    -1,     5,
      -1,    52,    28,    52,    -1,     5,    23,    54,    24,    -1,
       5,     1,    54,    24,    -1,     5,    23,    54,     1,    -1,
      55,    -1,    55,    26,    54,    -1,    -1,     5,    -1,     6,
      -1,     7,    -1,     9,    -1,     8,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    67,    67,    68,    71,    72,    73,    74,    75,    76,
      79,    80,    81,    82,    83,    86,    90,    91,    94,    97,
      99,   103,   104,   107,   108,   111,   112,   116,   117,   118,
     119,   120,   121,   122,   125,   126,   127,   128,   129,   130,
     131,   135,   136,   137,   141,   142,   143,   146,   147,   151,
     162,   165,   168,   169,   172,   183,   218,   232,   247,   260,
     274,   275,   279,   280,   283,   284,   285,   289,   290,   291,
     292,   293,   294,   298,   299,   300,   320,   342,   356,   357,
     360,   361,   364,   366,   373,   374,   375,   376
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
  "sentenciaDeSalto", "declaracion", "declaraciones",
  "declaracionDefinicionFuncion", "declaracionVariables", "listaVariables",
  "unaVariableSimple", "parametrosCuerpoFuncion", "listaParametros",
  "parametros", "expresion", "invocacionDeFuncion", "listaArgumentos",
  "argumento", 0
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
       0,    29,    30,    30,    31,    31,    31,    31,    31,    31,
      32,    32,    32,    32,    32,    33,    34,    34,    35,    36,
      36,    37,    37,    38,    38,    39,    39,    40,    40,    40,
      40,    40,    40,    40,    41,    41,    41,    41,    41,    41,
      41,    42,    42,    42,    43,    43,    43,    44,    44,    45,
      45,    46,    47,    47,    48,    48,    48,    48,    48,    48,
      48,    48,    49,    49,    50,    50,    50,    51,    51,    51,
      51,    51,    51,    52,    52,    52,    52,    53,    53,    53,
      54,    54,    55,    55,    55,    55,    55,    55
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     2,     0,     1,     4,     0,
       1,     1,     2,     0,     1,     1,     2,     5,     7,     3,
       5,     5,     3,     5,     5,     3,     5,     7,     9,     3,
       9,     2,     2,     3,     2,     3,     2,     1,     2,     2,
       2,     1,     1,     3,     1,     3,     3,     3,     3,     3,
       3,     2,     4,     4,     0,     1,     3,     2,     3,     2,
       3,     2,     3,     1,     1,     1,     3,     4,     4,     4,
       1,     3,     0,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,    73,    74,     0,
      16,     0,     0,     0,     0,     0,    16,     4,    19,     3,
       0,    10,     0,    11,    12,    13,    14,     0,    17,     0,
       9,     0,    54,     0,    44,    47,     0,    51,    52,     0,
       0,    46,    82,    82,     0,     0,    75,     0,    17,     0,
       0,     0,     0,    16,    16,    42,    41,     0,    16,    20,
      21,     6,    15,     7,     5,     0,     8,     0,    61,    50,
       0,    49,    45,    48,     0,    83,    84,    85,    87,    86,
       0,    80,     0,    32,     0,     0,    35,     0,    29,     0,
      39,     0,    43,    25,     0,    16,    22,    76,     0,     0,
       0,    65,    60,    55,    59,    56,    58,    57,     0,    54,
      53,    78,    82,    79,    77,    16,    16,     0,    16,    16,
      16,    16,    16,    18,    26,    69,     0,    71,    67,     0,
       0,     0,    81,    33,    31,     0,    36,    34,    30,    27,
       0,    70,    72,    68,    63,    62,    66,     0,    16,    16,
      37,    28,     0,    16,    16,    40,    38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    19,    20,    21,    22,    23,    58,    59,    94,
      95,    24,    25,    26,    27,    34,    35,    36,    37,    38,
      69,   100,   101,    48,    29,    80,    81
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -41
static const yytype_int16 yypact[] =
{
     -41,    79,   -41,    -5,    10,    24,     3,   -41,   -41,    26,
     158,    41,    53,    54,    55,    68,    52,   -41,     5,   -41,
      25,   -41,    73,   -41,   -41,   -41,   -41,    84,    37,    85,
     -41,    35,    51,   127,   -41,   -41,    92,   -41,    -2,    50,
      50,   -41,   175,   175,    52,    52,   -41,   101,    87,    52,
      52,    52,    52,    52,    52,   -41,   -41,   103,   109,     5,
     -41,   -41,   -41,   -41,   -41,    52,   -41,    16,   -41,   -41,
      62,   -41,   -41,   -41,   128,   -41,   -41,   -41,   -41,   -41,
     113,   115,    17,    87,     4,   119,    87,     6,    87,     9,
     -41,   126,   -41,   -41,   132,   140,   -41,    87,    56,    11,
     125,   133,   -41,   -41,   -41,   -41,   -41,   -41,   137,   145,
     -41,   -41,   175,   -41,   -41,   158,   158,    52,   158,   158,
     158,   158,    52,   -41,   -41,   -41,   155,   -41,   -41,   134,
      81,    16,   -41,   -41,   -41,   112,   -41,   -41,   -41,   153,
     157,   -41,   -41,   -41,   -41,   -41,   -41,   165,   158,    52,
     -41,   -41,    19,   158,   158,   -41,   -41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -41,   -41,   -41,   -10,   -41,   -15,    48,   -41,   -41,   -41,
     -41,   -41,   -41,   -41,   -12,   154,   181,   -41,   114,   -41,
     -19,    58,   -41,     1,   -41,   -40,   -41
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -76
static const yytype_int16 yytable[] =
{
      47,    57,    28,    82,    42,   115,    60,   118,     4,     5,
     120,    31,   127,    71,    30,    32,   128,    98,   113,    99,
     153,    71,   -75,   -75,    74,    39,    43,    44,   116,    40,
     119,   -75,    65,   121,    65,    33,   129,    65,    90,    91,
     -64,   114,    49,   154,    61,    83,    84,    96,    93,    45,
      86,    87,    88,    89,    51,    53,    64,    46,    67,     7,
       8,   125,    68,   102,    50,    65,    97,   103,   104,   105,
     106,   107,   132,    67,    67,    55,    52,    54,    70,     2,
       3,   126,     4,     5,     6,   124,     7,     8,    56,     9,
      10,    11,    12,    62,    13,    14,    15,    16,    17,   -16,
      18,   144,    18,    63,    66,   133,   134,   140,   136,   137,
     138,   139,    73,    85,    46,    65,     7,     8,   135,     9,
      10,    11,    12,    92,    13,    14,    15,    16,    31,   108,
      18,   -23,    32,   109,   152,   142,   147,   111,   151,   143,
      65,   112,   117,   155,   156,    46,   122,     7,     8,   130,
       9,    10,    11,    12,   123,    13,    14,    15,    16,   131,
     141,    18,   -24,    46,    68,     7,     8,   148,     9,    10,
      11,    12,    70,    13,    14,    15,    16,   149,   145,    18,
      75,    76,    77,    78,    79,   150,    41,    72,   110,   146
};

static const yytype_uint8 yycheck[] =
{
      10,    16,     1,    43,     1,     1,    18,     1,     3,     4,
       1,     1,     1,    32,    19,     5,     5,     1,     1,     3,
       1,    40,    19,    20,    26,     1,    23,     1,    24,     5,
      24,    28,    28,    24,    28,    25,    25,    28,    53,    54,
      24,    24,     1,    24,    19,    44,    45,    59,    58,    23,
      49,    50,    51,    52,     1,     1,    19,     5,    23,     7,
       8,     5,    27,     1,    23,    28,    65,     5,     6,     7,
       8,     9,   112,    23,    23,    20,    23,    23,    27,     0,
       1,    25,     3,     4,     5,    95,     7,     8,    20,    10,
      11,    12,    13,    20,    15,    16,    17,    18,    19,    20,
      21,    20,    21,    19,    19,   115,   116,   122,   118,   119,
     120,   121,    20,    12,     5,    28,     7,     8,   117,    10,
      11,    12,    13,    20,    15,    16,    17,    18,     1,     1,
      21,    22,     5,     5,   149,     1,    24,    24,   148,     5,
      28,    26,    23,   153,   154,     5,    20,     7,     8,    24,
      10,    11,    12,    13,    22,    15,    16,    17,    18,    26,
       5,    21,    22,     5,    27,     7,     8,    14,    10,    11,
      12,    13,    27,    15,    16,    17,    18,    20,   130,    21,
       5,     6,     7,     8,     9,    20,     5,    33,    74,   131
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,     0,     1,     3,     4,     5,     7,     8,    10,
      11,    12,    13,    15,    16,    17,    18,    19,    21,    31,
      32,    33,    34,    35,    40,    41,    42,    43,    52,    53,
      19,     1,     5,    25,    44,    45,    46,    47,    48,     1,
       5,    45,     1,    23,     1,    23,     5,    32,    52,     1,
      23,     1,    23,     1,    23,    20,    20,    34,    36,    37,
      43,    19,    20,    19,    19,    28,    19,    23,    27,    49,
      27,    49,    44,    20,    26,     5,     6,     7,     8,     9,
      54,    55,    54,    52,    52,    12,    52,    52,    52,    52,
      34,    34,    20,    32,    38,    39,    43,    52,     1,     3,
      50,    51,     1,     5,     6,     7,     8,     9,     1,     5,
      47,    24,    26,     1,    24,     1,    24,    23,     1,    24,
       1,    24,    20,    22,    32,     5,    25,     1,     5,    25,
      24,    26,    54,    32,    32,    52,    32,    32,    32,    32,
      34,     5,     1,     5,    20,    35,    50,    24,    14,    20,
      20,    32,    34,     1,    24,    32,    32
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
        case 16:
#line 90 "TP5.y"
    { printf("1 pase por aca \n"); printf("Se encontro una sentencia vacia\n"); ;}
    break;

  case 17:
#line 91 "TP5.y"
    { printf("2 pase por aca \n"); printf("Se encontro una sentencia con una expresion\n"); ;}
    break;

  case 20:
#line 99 "TP5.y"
    { printf("3 pase por aca \n"); printf("Se encontro una sentencia compuesta con una lista de declaraciones\n"); ;}
    break;

  case 24:
#line 108 "TP5.y"
    { printf("4 pase por aca \n");printf("Se encontro una sentencia compuesta con una lista de sentencias\n"); ;}
    break;

  case 27:
#line 116 "TP5.y"
    { printf("5 pase por aca");printf("Se encontro una sentencia IF \n"); ;}
    break;

  case 28:
#line 117 "TP5.y"
    { printf("6 pase por aca");printf("Se encontro una sentencia IF y ELSE \n"); ;}
    break;

  case 29:
#line 118 "TP5.y"
    { printf("7 pase por aca");agregarError("Error Sintactico: Despues del IF se espera un '('\n"); ;}
    break;

  case 30:
#line 119 "TP5.y"
    { printf("8 pase por aca");agregarError("Error Sintactico: falta ')' en la sentencia IF\n"); ;}
    break;

  case 31:
#line 120 "TP5.y"
    { printf("9 pase por aca");printf("Se encontro una sentencia SWITCH \n"); ;}
    break;

  case 32:
#line 121 "TP5.y"
    { printf("10 pase por aca");agregarError("Error Sintactico: Despues del SWITCH se espera un '('\n"); ;}
    break;

  case 33:
#line 122 "TP5.y"
    { printf("11 pase por aca");agregarError("Error Sintactico: falta ')' en la sentencia SWITCH\n"); ;}
    break;

  case 34:
#line 125 "TP5.y"
    { printf("12 pase por aca");printf("Se encontro la sentencia WHILE\n"); ;}
    break;

  case 35:
#line 126 "TP5.y"
    { printf("13 pase por aca");agregarError("Error Sintactico: Despues del WHILE se espera un '('\n"); ;}
    break;

  case 36:
#line 127 "TP5.y"
    { printf("14 pase por aca");agregarError("Error Sintactico: falta ')' en la sentencia WHILE\n"); ;}
    break;

  case 37:
#line 128 "TP5.y"
    { printf("15 pase por aca");printf("Se encontro una sentencia DO\n"); ;}
    break;

  case 38:
#line 129 "TP5.y"
    { printf("16 pase por aca");printf("Se encontro una sentencia FOR\n"); ;}
    break;

  case 39:
#line 130 "TP5.y"
    { printf("17 pase por aca");agregarError("Error Sintactico: Despues del FOR se espera un '('\n"); ;}
    break;

  case 40:
#line 131 "TP5.y"
    { printf("18 pase por aca");agregarError("Error Sintactico: falta ')' en la sentencia FOR\n"); ;}
    break;

  case 41:
#line 135 "TP5.y"
    { printf("19 pase por aca");printf("Se encontro la sentencia CONTINUE\n"); ;}
    break;

  case 42:
#line 136 "TP5.y"
    { printf("20 pase por aca");printf("Se encontro la sentencia BREAK\n"); ;}
    break;

  case 43:
#line 137 "TP5.y"
    { printf("21 pase por aca");printf("Se encontro la sentencia RETURN\n"); ;}
    break;

  case 44:
#line 141 "TP5.y"
    { printf("22 pase por aca \n");tipo = (yyvsp[(1) - (2)].cadena);;}
    break;

  case 45:
#line 142 "TP5.y"
    { printf("23 pase por aca \n");tipo = concatenar((yyvsp[(1) - (3)].cadena), "*");;}
    break;

  case 46:
#line 143 "TP5.y"
    { printf("24 pase por aca \n");tipo = "void";;}
    break;

  case 49:
#line 151 "TP5.y"
    { 
                                                                        printf("25 pase por aca \n");
                                                                        aux = buscarSimbolo((yyvsp[(1) - (2)].cadena)); 
                                                                        if (aux) 
                                                                                agregarError("Error Semantico : el identificador ya esta declarado");  
                                                                        else {
                                                                                aux2 = agregoSimbolo2((yyvsp[(1) - (2)].cadena) , tipo, 2);   
                                                                                aux->tiposParametros = listaParametrosAux; 
                                                                                listaParametrosAux = NULL; 
                                                                        }
                                                                ;}
    break;

  case 50:
#line 162 "TP5.y"
    { agregarError("Error Sintactico : nombre de la funcion incorrecto"); ;}
    break;

  case 54:
#line 173 "TP5.y"
    {
                                        printf("26 pase por aca \n");
                                        agregoSimbolo2((yyvsp[(1) - (1)].cadena) , tipo, 1);
                                        //aux = buscarSimbolo($<cadena>1); 
                                        //if (aux != NULL) 
                                        //        agregarError("Error Semantico: la variable ya esta declarada\n");
                                        //else
                                                                                                            
                                ;}
    break;

  case 55:
#line 184 "TP5.y"
    {
                                printf("27 pase por aca");
                                aux=buscarSimbolo((yyvsp[(1) - (3)].cadena)); 
                                if (aux) {
                                        agregarError("Error Semantico : la variable ya esta declarada\n"); 
                                } 
                                else 
                                {
                                        aux2 = buscarSimbolo((yyvsp[(3) - (3)].cadena)); 
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

  case 56:
#line 218 "TP5.y"
    { 
                                                        printf("28 pase por aca");
                                                                //aux = buscarSimbolo($<cadena>1); 
                                                                //if (aux) 
                                                                //        agregarError("Error Semantico : la variable ya esta declarada "); 
                                                                //else {
                                                                                if(strcmp(tipo,"int") == 0){ 
                                                                                        aux = agregoSimbolo2((yyvsp[(1) - (3)].cadena) , tipo, 1);  
                                                                                        aux->value.valEnt = (yyvsp[(3) - (3)].mystruct).valor_entero;}
                                                                                else
                                                                                        agregarError("Error Semantico : son de distinto tipo"); 
                                                                 //       }
                                                        ;}
    break;

  case 57:
#line 232 "TP5.y"
    {
                                                                printf("29 pase por aca");
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

  case 58:
#line 247 "TP5.y"
    { 
                        printf("30 pase por aca");       
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

  case 59:
#line 260 "TP5.y"
    {
                        printf("31 pase por aca");
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

  case 60:
#line 274 "TP5.y"
    { agregarError("Error Sintactico : se inicializo con un valor incorrecto"); ;}
    break;

  case 61:
#line 275 "TP5.y"
    { agregarError("Error Sintactico : identificador incorrecto"); ;}
    break;

  case 64:
#line 283 "TP5.y"
    { printf("31 pase por aca");agregoParametro("void"); ;}
    break;

  case 67:
#line 289 "TP5.y"
    { printf("33 pase por aca");agregoParametro((yyvsp[(1) - (2)].cadena)); ;}
    break;

  case 68:
#line 290 "TP5.y"
    { printf("34 pase por aca");agregoParametro(concatenar((yyvsp[(1) - (3)].cadena), "*")); ;}
    break;

  case 69:
#line 291 "TP5.y"
    { agregarError("ERROR SINTACTICO : falta tipo de dato del parametro"); ;}
    break;

  case 70:
#line 292 "TP5.y"
    { agregarError("ERROR SINTACTICO : falta tipo de dato del puntero parametro"); ;}
    break;

  case 71:
#line 293 "TP5.y"
    { agregarError("ERROR SINTACTICO : falta identificador en parametro"); ;}
    break;

  case 72:
#line 294 "TP5.y"
    { agregarError("ERROR SINTACTICO : falta identificador del puntero parametro"); ;}
    break;

  case 73:
#line 298 "TP5.y"
    { printf("constante entera exp pase por aca");(yyval.mystruct).tipo = (yyvsp[(1) - (1)].mystruct).tipo;  (yyval.mystruct).valor_entero = (yyvsp[(1) - (1)].mystruct).valor_entero;;}
    break;

  case 74:
#line 299 "TP5.y"
    {printf("constante real exp pase por aca"); (yyval.mystruct).tipo = (yyvsp[(1) - (1)].mystruct).tipo;  (yyval.mystruct).valor_real = (yyvsp[(1) - (1)].mystruct).valor_real;;}
    break;

  case 75:
#line 300 "TP5.y"
    { 
                        printf("35 pase por aca");
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

  case 76:
#line 320 "TP5.y"
    { 
                        printf("36 pase por aca");
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

  case 77:
#line 342 "TP5.y"
    {
        printf("37 pase por aca");
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

  case 78:
#line 356 "TP5.y"
    {agregarError("Error Sintactico : falta '(' en la invocacion de la funcion"); ;}
    break;

  case 79:
#line 357 "TP5.y"
    {agregarError("Error Sintactico : falta ')' en la invocacion de la funcion"); ;}
    break;

  case 82:
#line 364 "TP5.y"
    { printf("38 pase por aca");
        agregoArgumento("void"); ;}
    break;

  case 83:
#line 366 "TP5.y"
    {        
                                        aux=buscarSimbolo((yyvsp[(1) - (1)].cadena));    
                                        if (aux) 
                                                agregoArgumento(aux->tipo); 
                                        else 
                                                agregarError("Error Semantico : la variable no esta declarada\n");
                                ;}
    break;

  case 84:
#line 373 "TP5.y"
    { agregoArgumento("char*"); ;}
    break;

  case 85:
#line 374 "TP5.y"
    { agregoArgumento("int"); ;}
    break;

  case 86:
#line 375 "TP5.y"
    { agregoArgumento("char"); ;}
    break;

  case 87:
#line 376 "TP5.y"
    { agregoArgumento("real"); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1945 "TP5.tab.c"
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


#line 379 "TP5.y"



int main(){
        yyin = fopen("docDePrueba.c","r");
        printf("\n");
        yyparse();
        printf("main pase por aca");
        mostrarSimbolos(listaSimbolos);
        mostrarErrores(listaErrores);
}
