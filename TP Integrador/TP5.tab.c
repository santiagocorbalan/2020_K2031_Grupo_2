
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "TP5.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "TP5.h"
#include "TP5.c"
#define YYDEBUG 1

extern int yylineno;

char* tipo;

void yyerror (char const *s) {          
//   fprintf (stderr, "%s\n", s);
}  

FILE* yyin;

int yylex();

int yywrap(){
    return(1);
}

symrec *aux;



/* Line 189 of yacc.c  */
#line 105 "TP5.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TIPO_DE_DATO = 258,
     CONSTANTE_CARACTER = 259,
     IDENTIFICADOR = 260,
     LITERAL_CADENA = 261,
     TKN_VOID = 262,
     CONSTANTE_ENTERA = 263,
     CONSTANTE_REAL = 264,
     BREAK = 265,
     CONTINUE = 266,
     RETURN = 267,
     FOR = 268,
     DO = 269,
     WHILE = 270,
     SWITCH = 271,
     IF = 272,
     ELSE = 273
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 33 "TP5.y"

    struct yylval_struct
      {
      int tipo;
      int valor_entero;
      float valor_real;
      } mystruct;

          char* cadena;
         char caracter;
          int entero;
          float real;




/* Line 214 of yacc.c  */
#line 176 "TP5.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 188 "TP5.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   177

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNRULES -- Number of states.  */
#define YYNSTATES  149

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   273

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      25,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      23,    24,    21,    19,    29,    20,     2,    22,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    26,
       2,    30,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,    28,     2,     2,     2,     2,
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
      23,    25,    27,    29,    31,    33,    36,    37,    39,    44,
      45,    47,    49,    52,    53,    55,    57,    60,    66,    74,
      80,    86,    94,   104,   107,   110,   114,   115,   119,   120,
     125,   126,   130,   132,   135,   137,   139,   143,   145,   149,
     153,   157,   161,   165,   169,   172,   175,   178,   183,   184,
     186,   190,   193,   197,   200,   204,   207,   211,   216,   221,
     226,   228,   232,   233,   235,   237,   239,   241,   243,   245,
     249,   253,   257,   261
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      32,     0,    -1,    -1,    32,    33,    -1,    25,    -1,    45,
      25,    -1,    34,    25,    -1,    57,    25,    -1,     1,    25,
      -1,    35,    -1,    37,    -1,    43,    -1,    42,    -1,    44,
      -1,    26,    -1,    60,    26,    -1,    -1,    60,    -1,    27,
      38,    40,    28,    -1,    -1,    39,    -1,    45,    -1,    39,
      45,    -1,    -1,    41,    -1,    34,    -1,    41,    34,    -1,
      17,    23,    60,    24,    34,    -1,    17,    23,    60,    24,
      34,    18,    34,    -1,    16,    23,    60,    24,    34,    -1,
      15,    23,    60,    24,    34,    -1,    14,    34,    15,    23,
      60,    24,    26,    -1,    13,    23,    36,    26,    36,    26,
      36,    24,    34,    -1,    11,    26,    -1,    10,    26,    -1,
      12,    36,    26,    -1,    -1,     3,    46,    49,    -1,    -1,
       3,    21,    47,    49,    -1,    -1,     7,    48,    53,    -1,
      53,    -1,    50,    26,    -1,    51,    -1,    52,    -1,    52,
      29,    51,    -1,     5,    -1,     5,    30,     5,    -1,     5,
      30,     4,    -1,     5,    30,     8,    -1,     5,    30,     9,
      -1,     5,    30,     6,    -1,     5,    30,     1,    -1,     1,
      30,    -1,     5,    54,    -1,     1,    54,    -1,    23,    55,
      24,    26,    -1,    -1,    56,    -1,    56,    29,    55,    -1,
       3,     5,    -1,     3,    21,     5,    -1,     1,     5,    -1,
       1,    21,     5,    -1,     3,     1,    -1,     3,    21,     1,
      -1,     5,    23,    58,    24,    -1,     5,     1,    58,    24,
      -1,     5,    23,    58,     1,    -1,    59,    -1,    59,    29,
      58,    -1,    -1,     5,    -1,     6,    -1,     8,    -1,     4,
      -1,     8,    -1,     9,    -1,    60,    19,    60,    -1,    60,
      20,    60,    -1,    60,    21,    60,    -1,    60,    22,    60,
      -1,    23,    60,    24,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    77,    77,    78,    81,    82,    83,    84,    85,    88,
      89,    90,    91,    92,    95,    96,    99,   100,   103,   106,
     107,   110,   111,   114,   115,   118,   119,   123,   124,   125,
     129,   130,   131,   135,   136,   137,   141,   141,   142,   142,
     143,   143,   146,   147,   150,   153,   154,   158,   166,   214,
     230,   248,   264,   284,   285,   288,   301,   304,   307,   308,
     309,   313,   314,   315,   316,   317,   318,   321,   346,   347,
     350,   351,   354,   355,   362,   363,   364,   368,   370,   373,
     386,   399,   412,   414
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TIPO_DE_DATO", "CONSTANTE_CARACTER",
  "IDENTIFICADOR", "LITERAL_CADENA", "TKN_VOID", "CONSTANTE_ENTERA",
  "CONSTANTE_REAL", "BREAK", "CONTINUE", "RETURN", "FOR", "DO", "WHILE",
  "SWITCH", "IF", "ELSE", "'+'", "'-'", "'*'", "'/'", "'('", "')'",
  "'\\n'", "';'", "'{'", "'}'", "','", "'='", "$accept", "input", "line",
  "sentencia", "sentenciaExpresion", "opExpresion", "sentenciaCompuesta",
  "opListaDeclaraciones", "listaDeclaraciones", "opListaDeSentencias",
  "listaDeSentencias", "sentenciaDeSeleccion", "sentenciaDeIteracion",
  "sentenciaDeSalto", "declaracion", "$@1", "$@2", "$@3", "declaraciones",
  "declaracionVariables", "listaVariables", "unaVariableSimple",
  "declaracionDefinicionFuncion", "parametrosCuerpoFuncion",
  "listaParametros", "parametros", "invocacionDeFuncion",
  "listaArgumentos", "argumento", "expresion", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,    43,
      45,    42,    47,    40,    41,    10,    59,   123,   125,    44,
      61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    31,    32,    32,    33,    33,    33,    33,    33,    34,
      34,    34,    34,    34,    35,    35,    36,    36,    37,    38,
      38,    39,    39,    40,    40,    41,    41,    42,    42,    42,
      43,    43,    43,    44,    44,    44,    46,    45,    47,    45,
      48,    45,    49,    49,    50,    51,    51,    52,    52,    52,
      52,    52,    52,    52,    52,    53,    53,    54,    55,    55,
      55,    56,    56,    56,    56,    56,    56,    57,    57,    57,
      58,    58,    59,    59,    59,    59,    59,    60,    60,    60,
      60,    60,    60,    60
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     2,     0,     1,     4,     0,
       1,     1,     2,     0,     1,     1,     2,     5,     7,     5,
       5,     7,     9,     2,     2,     3,     0,     3,     0,     4,
       0,     3,     1,     2,     1,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     4,     0,     1,
       3,     2,     3,     2,     3,     2,     3,     4,     4,     4,
       1,     3,     0,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,    36,     0,    40,    77,    78,     0,
       0,    16,     0,     0,     0,     0,     0,     0,     4,    14,
      19,     3,     0,     9,    10,    12,    11,    13,     0,     0,
       0,     8,    38,     0,    72,    72,     0,    34,    33,     0,
      17,    16,     0,     0,     0,     0,     0,    23,    20,    21,
       6,     5,     7,     0,     0,     0,     0,    15,     0,     0,
      47,    37,     0,    44,    45,    42,    76,    73,    74,    75,
       0,    70,     0,     0,     0,    41,    35,     0,     0,     0,
       0,     0,    83,    25,     0,    24,    22,    79,    80,    81,
      82,    39,     0,    54,    56,     0,    55,    43,     0,    68,
      72,    69,    67,    16,     0,     0,     0,     0,    18,    26,
       0,     0,     0,    59,    53,    49,    48,    52,    50,    51,
       0,    47,    46,    71,     0,     0,    30,    29,    27,    63,
       0,    65,    61,     0,     0,     0,    16,     0,     0,    64,
      66,    62,    57,    60,     0,    31,    28,     0,    32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    21,    22,    23,    39,    24,    47,    48,    84,
      85,    25,    26,    27,    28,    33,    58,    36,    61,    62,
      63,    64,    65,    94,   112,   113,    29,    70,    71,    30
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -49
static const yytype_int16 yypact[] =
{
     -49,   104,   -49,    -6,    22,     7,   -49,   -49,   -49,    15,
      45,    16,    68,    42,    85,    87,   119,    16,   -49,   -49,
      20,   -49,    58,   -49,   -49,   -49,   -49,   -49,    64,   123,
      41,   -49,   -49,     9,   118,   118,    39,   -49,   -49,   115,
     125,    16,   134,    16,    16,    16,    54,    42,    20,   -49,
     -49,   -49,   -49,    16,    16,    16,    16,   -49,     9,    19,
      47,   -49,   124,   -49,   122,   -49,   -49,   -49,   -49,   -49,
     128,   126,     5,   130,   130,   -49,   -49,   131,   133,    60,
      66,    79,   -49,   -49,   132,    42,   -49,   111,   111,   -49,
     -49,   -49,     4,   -49,   -49,    12,   -49,   -49,   101,   -49,
     118,   -49,   -49,    16,    16,    42,    42,    42,   -49,   -49,
      17,    10,   135,   129,   -49,   -49,   -49,   -49,   -49,   -49,
     136,   137,   -49,   -49,   139,   116,   -49,   -49,   143,   -49,
     149,   -49,   -49,   138,   142,     4,    16,   144,    42,   -49,
     -49,   -49,   -49,   -49,   140,   -49,   -49,    42,   -49
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -49,   -49,   -49,   -13,   -49,   -39,   -49,   -49,   -49,   -49,
     -49,   -49,   -49,   -49,   -16,   -49,   -49,   -49,   105,   -49,
      71,   -49,   141,   -48,    27,   -49,   -49,   -34,   -49,    -8
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -59
static const yytype_int16 yytable[] =
{
      42,    72,    77,    40,    49,   110,   101,   111,    34,    46,
      59,   131,    96,   114,    60,   132,   115,   116,   117,    31,
     118,   119,   129,     4,     7,     8,    96,     6,   -58,   102,
      35,   133,    86,    40,    83,    79,    80,    81,   130,    17,
      73,    37,    92,    32,    74,    87,    88,    89,    90,    93,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      53,    54,    55,    56,   124,    17,   123,    57,    19,    20,
      92,    38,   109,    53,    54,    55,    56,    95,    82,    53,
      54,    55,    56,    50,   105,    53,    54,    55,    56,    51,
     106,    41,   126,   127,   128,    40,   125,   144,    53,    54,
      55,    56,   120,   107,     2,     3,   121,     4,    43,     5,
      44,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    66,    67,    68,   146,    69,    17,    40,    18,
      19,    20,    55,    56,   148,    53,    54,    55,    56,   140,
     137,    76,    45,   141,    53,    54,    55,    56,    52,    78,
      97,    98,    99,    92,   139,   100,   104,   103,   135,   134,
     108,   138,   143,    91,   147,   136,    93,    95,   142,   122,
     145,     0,     0,     0,     0,     0,     0,    75
};

static const yytype_int16 yycheck[] =
{
      13,    35,    41,    11,    20,     1,     1,     3,     1,    17,
       1,     1,    60,     1,     5,     5,     4,     5,     6,    25,
       8,     9,     5,     3,     8,     9,    74,     7,    24,    24,
      23,    21,    48,    41,    47,    43,    44,    45,    21,    23,
       1,    26,    23,    21,     5,    53,    54,    55,    56,    30,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      19,    20,    21,    22,   103,    23,   100,    26,    26,    27,
      23,    26,    85,    19,    20,    21,    22,    30,    24,    19,
      20,    21,    22,    25,    24,    19,    20,    21,    22,    25,
      24,    23,   105,   106,   107,   103,   104,   136,    19,    20,
      21,    22,     1,    24,     0,     1,     5,     3,    23,     5,
      23,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     4,     5,     6,   138,     8,    23,   136,    25,
      26,    27,    21,    22,   147,    19,    20,    21,    22,     1,
      24,    26,    23,     5,    19,    20,    21,    22,    25,    15,
      26,    29,    24,    23,     5,    29,    23,    26,    29,    24,
      28,    18,   135,    58,    24,    26,    30,    30,    26,    98,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,     0,     1,     3,     5,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    23,    25,    26,
      27,    33,    34,    35,    37,    42,    43,    44,    45,    57,
      60,    25,    21,    46,     1,    23,    48,    26,    26,    36,
      60,    23,    34,    23,    23,    23,    60,    38,    39,    45,
      25,    25,    25,    19,    20,    21,    22,    26,    47,     1,
       5,    49,    50,    51,    52,    53,     4,     5,     6,     8,
      58,    59,    58,     1,     5,    53,    26,    36,    15,    60,
      60,    60,    24,    34,    40,    41,    45,    60,    60,    60,
      60,    49,    23,    30,    54,    30,    54,    26,    29,    24,
      29,     1,    24,    26,    23,    24,    24,    24,    28,    34,
       1,     3,    55,    56,     1,     4,     5,     6,     8,     9,
       1,     5,    51,    58,    36,    60,    34,    34,    34,     5,
      21,     1,     5,    21,    24,    29,    26,    24,    18,     5,
       1,     5,    26,    55,    36,    26,    34,    24,    34
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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
        case 5:

/* Line 1455 of yacc.c  */
#line 82 "TP5.y"
    {yylineno++; ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 83 "TP5.y"
    {yylineno++; ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 84 "TP5.y"
    {yylineno++; ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 85 "TP5.y"
    { agregarErrorSintactico("\nSe detecto un error sintactico en la linea",yylineno);yylineno++;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 99 "TP5.y"
    { printf("Se encontro una sentencia vacia\n"); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 107 "TP5.y"
    { printf("Se encontro una sentencia compuesta con una lista de declaraciones\n"); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 115 "TP5.y"
    { printf("Se encontro una sentencia compuesta con una lista de sentencias\n"); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 123 "TP5.y"
    { printf("Se encontro una sentencia IF\n"); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 124 "TP5.y"
    { printf("Se encontro una sentencia IF ELSE\n"); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 125 "TP5.y"
    { printf("Se encontro una sentencia SWITCH\n"); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 129 "TP5.y"
    { printf("Se encontro la sentencia WHILE\n"); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 130 "TP5.y"
    { printf("Se encontro una sentencia DO\n");   ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 131 "TP5.y"
    { printf("Se encontro una sentencia FOR\n");  ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 135 "TP5.y"
    { printf("Se encontro la sentencia CONTINUE\n"); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 136 "TP5.y"
    { printf("Se encontro la sentencia BREAK\n");    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 137 "TP5.y"
    { printf("Se encontro la sentencia RETURN\n");   ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 141 "TP5.y"
    { tipo = (yyvsp[(1) - (1)].cadena);             ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 142 "TP5.y"
    { tipo = strcat((yyvsp[(1) - (2)].cadena),"*"); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 143 "TP5.y"
    { tipo = "void";                 ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 159 "TP5.y"
    {
                        aux = buscoSimbolo((yyvsp[(1) - (1)].cadena)); 
                        if (aux) agregarErrorSemantico("ERROR: La variable ya fue declarada.",yylineno); 
                        else 
                        declararVariable1((yyvsp[(1) - (1)].cadena),tipo);
                ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 167 "TP5.y"
    {
                        aux = buscoSimbolo((yyvsp[(1) - (3)].cadena)); 
                        if (aux) 
                        agregarErrorSemantico("ERROR: La variable ya fue declarada.",yylineno);
                        else  
                        {
                                symrec *aux2 = buscoSimbolo((yyvsp[(3) - (3)].cadena)); 
                                if (aux2 && (strcmp(tipo, aux2->tipo) == 0)) { 

                                        aux = agregoSimbolo((yyvsp[(1) - (3)].cadena) , tipo, 1); 

                                        if (strcmp("int", aux->tipo) == 0)  {
                                                aux->value.valEnt = aux2->value.valEnt; 
                                                printf("\nSe declara la variable %s de tipo %s con valor %i\n\n",aux->nombre,aux->tipo, aux->value.valEnt);    
                                        }
                                        
                                        if (strcmp("float", aux->tipo) == 0)  {
                                                aux->value.valReal = aux2->value.valReal; 
                                                printf("\nSe declara la variable %s de tipo %s con valor %f\n\n",aux->nombre,aux->tipo, aux->value.valReal);
                                        }

                                        if (strcmp("char", aux->tipo) == 0)  {
                                                aux->value.valChar = aux2->value.valChar;
                                                printf("\nSe declara la variable %s de tipo %s con valor %c\n\n",aux->nombre,aux->tipo, aux->value.valChar);
                                        }
                                        
                                        if (strcmp("char*", aux->tipo) == 0)  {
                                                aux->value.valString = aux2->value.valString;
                                                printf("\nSe declara la variable %s de tipo %s con valor %s\n\n",aux->nombre,aux->tipo, aux->value.valString);
                                        }
                                                       

                                }   

                                        
                                if (aux2 && (strcmp(tipo, aux2->tipo) != 0))
                                        agregarErrorSemantico("ERROR: Las variables son de distinto tipo.",yylineno);

                                if (aux2 == NULL) 
                                        agregarErrorSemantico("ERROR : La variable que se encuentra a la derecha de la asignación NO está declarada.",yylineno);

                                                                                                                    
                                       
                        }
                ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 215 "TP5.y"
    {
                        aux = buscoSimbolo((yyvsp[(1) - (3)].cadena)); 
                        if (aux) 
                                agregarErrorSemantico("ERROR : La variable ya fue declarada.", yylineno); 
                        else {
                                if (strcmp(tipo, "char") == 0) {
                                        aux = agregoSimbolo(strdup((yyvsp[(1) - (3)].cadena)), tipo, 1);  
                                        aux->value.valChar = (yyvsp[(3) - (3)].caracter); 
                                        printf("\nSe declara la variable %s de tipo %s con valor %c\n\n",aux->nombre,aux->tipo, aux->value.valChar);
                                }
                                else 
                                agregarErrorSemantico("ERROR : No coincide el tipo de la variable con el asignado.",yylineno);
                        }
                ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 231 "TP5.y"
    {
                        aux = buscoSimbolo((yyvsp[(1) - (3)].cadena)); 
                        if (aux) 
                        agregarErrorSemantico("Error : La variable ya fue declarada.",yylineno); 
                        else  {
                                                                                
                                if (strcmp(tipo,"int") == 0)  {
                                        aux = agregoSimbolo(strdup((yyvsp[(1) - (3)].cadena)) , tipo, 1);  
                                        aux->value.valEnt = (yyvsp[(3) - (3)].mystruct).valor_entero; 
                                        printf("\nSe declara la variable %s de tipo %s con valor %i\n\n",aux->nombre,aux->tipo, aux->value.valEnt);
                                } 
                                else 
                                        agregarErrorSemantico("Error : No coincide el tipo de la variable con el asignado.",yylineno);
                                                                        
                        }
                ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 249 "TP5.y"
    { 
                        aux = buscoSimbolo((yyvsp[(1) - (3)].cadena)); 
                        if (aux) 
                                agregarErrorSemantico("Error  : La variable ya fue declarada.",yylineno); 
                        else {
                                if (strcmp(tipo, "float") == 0) {
                                        aux = agregoSimbolo((yyvsp[(1) - (3)].cadena) , tipo, 1);  
                                        aux->value.valReal = (yyvsp[(3) - (3)].mystruct).valor_real; 
                                        printf("\nSe declara la variable %s de tipo %s con valor %f\n\n",aux->nombre,aux->tipo, aux->value.valReal);
                                } 
                                else 
                                        agregarErrorSemantico("Error : No coincide el tipo de la variable con el asignado.",yylineno);
                        }
                ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 265 "TP5.y"
    {
                        aux = buscoSimbolo((yyvsp[(1) - (3)].cadena)); 
                        if (aux) 
                                agregarErrorSemantico("Error : La variable ya fue declarada.",yylineno);
                        else {
                                if (strcmp(tipo, "char*") == 0) {
                                        aux = agregoSimbolo(strdup((yyvsp[(1) - (3)].cadena)) , tipo, 1);  
                                        aux->value.valString = (yyvsp[(3) - (3)].cadena); 
                                        printf("\nSe declara la variable %s de tipo %s con valor %s\n\n",aux->nombre,aux->tipo, aux->value.valString);
                                } 
                                else 
                                        agregarErrorSemantico("Error : No coincide el tipo de la variable con el asignado.",yylineno);
                        }


                ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 284 "TP5.y"
    { agregarErrorSintactico("Error :  Falta el valor asignado.",yylineno); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 285 "TP5.y"
    { agregarErrorSintactico("Error : Identificador incorrecto.",yylineno); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 289 "TP5.y"
    { 
                                                                        aux = buscoSimbolo((yyvsp[(1) - (2)].cadena)); 
                                                                        if (aux)  
                                                                        agregarErrorSemantico("Error: el identificador ya esta declarado",yylineno); 
                                                                        else {
                                                                                aux=agregoSimbolo((yyvsp[(1) - (2)].cadena), tipo, 2);   
                                                                                aux->tiposParametros = listaParametrosAux; 
                                                                        }
                                                                        listaParametrosAux = NULL; 
                                                                ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 301 "TP5.y"
    {  agregarErrorSemantico("Error: nombre de la funcion incorrecto",yylineno);;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 307 "TP5.y"
    { agregoParametro("void");;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 313 "TP5.y"
    { agregoParametro((yyvsp[(1) - (2)].cadena));;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 314 "TP5.y"
    { agregoParametro(strcat(tipo,"*"));;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 315 "TP5.y"
    { agregarErrorSemantico("ERROR : Falta el tipo de dato del parametro.",yylineno);;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 316 "TP5.y"
    { agregarErrorSemantico("ERROR : Falta el tipo de dato del puntero parametro.",yylineno);;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 317 "TP5.y"
    { agregarErrorSemantico("ERROR : Falta el identificador en el parametro.",yylineno);;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 318 "TP5.y"
    { agregarErrorSemantico("ERROR : Falta el identificador del puntero del parametro.",yylineno);;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 322 "TP5.y"
    {
                                                                aux = buscoSimbolo((yyvsp[(1) - (4)].cadena));  
                                                                if (aux) { 
                                                                        if(aux->type == 1){
                                                                                agregarErrorSemantico("Error: El IDENTIFICADOR esta declarado como variable.",yylineno);} 
                     
                                                                        if (compararParametros(aux->tiposParametros, listaParametrosAux) == 1){
                                                                                agregarErrorSemantico("Error: La cantidad o tipos de parametros son incorrectos.",yylineno);} 
                        
                                                                        if (compararParametros(aux->tiposParametros, listaParametrosAux) == 0){
                                                                                agregarErrorSemantico("\nCantidad y tipos de parametros correctos",yylineno);} 

                                                                } 
                                                                else {
                                                                        agregarErrorSemantico("Error: No está declarada la función.",yylineno); 
                                                                }
                                                                
                                                                listaParametrosAux = NULL;
                         
                                                                ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 346 "TP5.y"
    { agregarErrorSintactico("ERROR : falta '(' en la invocacion de la función.",yylineno); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 347 "TP5.y"
    { agregarErrorSintactico("ERROR : falta ')' en la invocacion de la función.",yylineno); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 354 "TP5.y"
    { agregoArgumento("void"); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 355 "TP5.y"
    {        
                                        aux = buscoSimbolo((yyvsp[(1) - (1)].cadena));    
                                        if (aux) 
                                                agregoArgumento(aux->tipo); 
                                        else 
                                                agregarErrorSemantico("ERROR : La variable no está declarada.",yylineno);
                                        ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 362 "TP5.y"
    { agregoArgumento("char*"); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 363 "TP5.y"
    { agregoArgumento("int");   ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 364 "TP5.y"
    { agregoArgumento("char");  ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 368 "TP5.y"
    {(yyval.mystruct).tipo=(yyvsp[(1) - (1)].mystruct).tipo;
                                            (yyval.mystruct).valor_entero=(yyvsp[(1) - (1)].mystruct).valor_entero;;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 370 "TP5.y"
    {(yyval.mystruct).tipo=(yyvsp[(1) - (1)].mystruct).tipo;
                                            (yyval.mystruct).valor_real=(yyvsp[(1) - (1)].mystruct).valor_real;;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 374 "TP5.y"
    { 
                                                        if ((yyvsp[(1) - (3)].mystruct).tipo == (yyvsp[(3) - (3)].mystruct).tipo)  { // Verifico que los tipos de constantes sean iguales

                                                        if((yyvsp[(1) - (3)].mystruct).tipo == 1)  { (yyval.mystruct).valor_entero=(yyvsp[(1) - (3)].mystruct).valor_entero+(yyvsp[(3) - (3)].mystruct).valor_entero; } // si son enteros , sumo las expresiones y asigno el valor.
        
                                                        else { (yyval.mystruct).valor_real=(yyvsp[(1) - (3)].mystruct).valor_real+(yyvsp[(3) - (3)].mystruct).valor_real; } // si son constantes reales , sumo las expresiones y asigno el valor.
                                                        }
        
                                                        else { agregarErrorSemantico("Los operandos son de distinto tipo, no se puede realizar la operación.",yylineno); }
        
                                                ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 387 "TP5.y"
    { 
                                                        if ((yyvsp[(1) - (3)].mystruct).tipo == (yyvsp[(3) - (3)].mystruct).tipo) { 
       
                                                        if ((yyvsp[(1) - (3)].mystruct).tipo == 1) { (yyval.mystruct).valor_entero=(yyvsp[(1) - (3)].mystruct).valor_entero+(yyvsp[(3) - (3)].mystruct).valor_entero; }
        
                                                        else { (yyval.mystruct).valor_real=(yyvsp[(1) - (3)].mystruct).valor_real+(yyvsp[(3) - (3)].mystruct).valor_real; }
                                                        }
        
                                                        else { agregarErrorSemantico("Los operandos son de distinto tipo, no se puede realizar la operación.",yylineno);}
        
                                                ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 400 "TP5.y"
    { 
                                                        if((yyvsp[(1) - (3)].mystruct).tipo == (yyvsp[(3) - (3)].mystruct).tipo)  { 

                                                        if((yyvsp[(1) - (3)].mystruct).tipo == 1) { (yyval.mystruct).valor_entero=(yyvsp[(1) - (3)].mystruct).valor_entero+(yyvsp[(3) - (3)].mystruct).valor_entero; }
        
                                                        else  { (yyval.mystruct).valor_real=(yyvsp[(1) - (3)].mystruct).valor_real+(yyvsp[(3) - (3)].mystruct).valor_real; }

                                                        }
        
                                                        else  { agregarErrorSemantico("Los operandos son de distinto tipo, no se puede realizar la operación.",yylineno); }
        
                                                ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 414 "TP5.y"
    { (yyval.mystruct).valor_entero = (yyvsp[(2) - (3)].mystruct).valor_entero ; ;}
    break;



/* Line 1455 of yacc.c  */
#line 2041 "TP5.tab.c"
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
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
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



/* Line 1675 of yacc.c  */
#line 419 "TP5.y"


// Puntero que apunta a la tabla de símbolos
symrec *sym_table;

int main(){
        #ifdef BISON_DEBUG
        yydebug = 1;
        #endif

        yyin = fopen("archivo.c","r");
        printf("\n");
        yyparse();
        
        mostrarListaVariables();
        mostrarListaFunciones();
        mostrarErrorSintactico();
        mostrarErrorSemantico();
}
