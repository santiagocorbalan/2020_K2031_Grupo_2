
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
#include "Funciones.c"

void yyerror (char const *s) {          //Con yyerror se detecta el error sintáctico 
   fprintf (stderr, "%s\n", s);
}  

FILE* yyin;

int yylex();

int yywrap(){
    return(1);
}

Tabla *aux;
char* tipo;



/* Line 189 of yacc.c  */
#line 100 "TP5.tab.c"

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
     CONSTANTE_DECIMAL = 258,
     CONSTANTE_OCTAL = 259,
     CONSTANTE_HEXADECIMAL = 260,
     CONSTANTE_REAL = 261,
     CONSTANTE_CARACTER = 262,
     LITERAL_CADENA = 263,
     TIPO_DATO = 264,
     IDENTIFICADOR = 265,
     SWITCH = 266,
     BREAK = 267,
     CONTINUE = 268,
     WHILE = 269,
     IF = 270,
     ELSE = 271,
     FOR = 272,
     RETURN = 273,
     DO = 274,
     NEG = 275
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 27 "TP5.y"


char* cadena;
int entero;
float real;
char caracter;

 struct yylval_struct
  {
      int tipo;
      int valor_entero;
      float valor_real;
      char valor_caracter;
  } mystruct;




/* Line 214 of yacc.c  */
#line 175 "TP5.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
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
#define YYLAST   331

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNRULES -- Number of states.  */
#define YYNSTATES  173

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   275

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      20,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      27,    28,    23,    21,    32,    22,     2,    24,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    29,
       2,    33,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    26,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,    31,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    25
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    12,    15,    18,    21,
      23,    25,    27,    29,    31,    32,    37,    41,    45,    49,
      52,    56,    60,    62,    64,    66,    68,    70,    73,    74,
      76,    81,    82,    84,    86,    89,    90,    92,    94,    97,
     103,   111,   115,   121,   127,   131,   137,   143,   148,   154,
     162,   172,   177,   187,   190,   193,   197,   199,   201,   203,
     204,   209,   211,   215,   217,   221,   225,   229,   233,   237,
     240,   241,   242,   251,   253,   255,   259,   262,   266,   269,
     273,   276,   280,   285,   290,   295,   300,   302,   306,   307,
     309,   311,   313,   315
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      35,     0,    -1,    -1,    35,    36,    -1,    20,    -1,    37,
      20,    -1,    39,    20,    -1,    50,    20,    -1,    60,    20,
      -1,     7,    -1,     3,    -1,     5,    -1,     4,    -1,     6,
      -1,    -1,    37,    21,    37,    38,    -1,    37,    22,    37,
      -1,    37,    23,    37,    -1,    37,    24,    37,    -1,    22,
      37,    -1,    37,    26,    37,    -1,    27,    37,    28,    -1,
      40,    -1,    42,    -1,    47,    -1,    48,    -1,    49,    -1,
      41,    29,    -1,    -1,    37,    -1,    30,    43,    45,    31,
      -1,    -1,    44,    -1,    50,    -1,    44,    50,    -1,    -1,
      46,    -1,    39,    -1,    46,    39,    -1,    15,    27,    37,
      28,    39,    -1,    15,    27,    37,    28,    39,    16,    39,
      -1,    15,     1,    37,    -1,    15,    27,    37,     1,    39,
      -1,    11,    27,    37,    28,    39,    -1,    11,     1,    37,
      -1,    11,    27,    37,     1,    39,    -1,    14,    27,    37,
      28,    39,    -1,    14,     1,    37,    28,    -1,    14,    27,
      37,     1,    39,    -1,    19,    39,    14,    27,    37,    28,
      29,    -1,    17,    27,    41,    29,    41,    29,    41,    28,
      39,    -1,    17,     1,    41,    29,    -1,    17,    27,    41,
      29,    41,    29,    41,     1,    39,    -1,    13,    29,    -1,
      12,    29,    -1,    18,    41,    29,    -1,    51,    -1,    55,
      -1,    63,    -1,    -1,     9,    52,    53,    29,    -1,    54,
      -1,    54,    32,    53,    -1,    10,    -1,    10,    33,    10,
      -1,    10,    33,     3,    -1,    10,    33,     7,    -1,    10,
      33,     6,    -1,    10,    33,     1,    -1,     1,    33,    -1,
      -1,    -1,     9,    56,    10,    57,    27,    58,    28,    29,
      -1,     1,    -1,    59,    -1,    59,    32,    58,    -1,     9,
      10,    -1,     9,    23,    10,    -1,     1,    10,    -1,     1,
      23,    10,    -1,     9,     1,    -1,     9,    23,     1,    -1,
      10,    27,    61,    28,    -1,    10,     1,    61,    28,    -1,
      10,    27,     1,    28,    -1,    10,    27,    61,     1,    -1,
      62,    -1,    62,    32,    61,    -1,    -1,    10,    -1,     8,
      -1,     3,    -1,     7,    -1,     9,    10,    27,     9,    10,
      28,    42,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    66,    66,    67,    71,    72,    73,    74,    75,    82,
      83,    84,    85,    86,    87,    87,   109,   110,   111,   112,
     113,   114,   120,   121,   122,   123,   124,   128,   132,   133,
     136,   140,   141,   144,   145,   149,   150,   153,   154,   159,
     160,   161,   162,   163,   164,   165,   168,   169,   170,   171,
     172,   173,   174,   179,   180,   181,   187,   188,   189,   193,
     193,   196,   197,   200,   201,   203,   204,   205,   206,   207,
     210,   210,   210,   211,   214,   215,   218,   219,   220,   221,
     222,   223,   226,   228,   229,   230,   233,   234,   237,   238,
     239,   240,   241,   243
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONSTANTE_DECIMAL", "CONSTANTE_OCTAL",
  "CONSTANTE_HEXADECIMAL", "CONSTANTE_REAL", "CONSTANTE_CARACTER",
  "LITERAL_CADENA", "TIPO_DATO", "IDENTIFICADOR", "SWITCH", "BREAK",
  "CONTINUE", "WHILE", "IF", "ELSE", "FOR", "RETURN", "DO", "'\\n'", "'+'",
  "'-'", "'*'", "'/'", "NEG", "'^'", "'('", "')'", "';'", "'{'", "'}'",
  "','", "'='", "$accept", "input", "line", "exp", "$@1", "sentencia",
  "sentenciaExpresion", "opExpresion", "sentenciaCompuesta",
  "opListaDeclaraciones", "listaDeclaraciones", "opListaDeSentencias",
  "listaDeSentencias", "sentenciaDeSeleccion", "sentenciaDeIteracion",
  "sentenciaDeSalto", "declaracion", "declaracionVariablesSimples", "$@2",
  "listaVariablesSimples", "unaVariableSimple", "declaracionFunciones",
  "@3", "$@4", "listaParametro", "parametro", "invocacionDeFuncion",
  "listaArgumentos", "argumento", "definicionFunciones", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      10,    43,    45,    42,    47,   275,    94,    40,    41,    59,
     123,   125,    44,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    35,    35,    36,    36,    36,    36,    36,    37,
      37,    37,    37,    37,    38,    37,    37,    37,    37,    37,
      37,    37,    39,    39,    39,    39,    39,    40,    41,    41,
      42,    43,    43,    44,    44,    45,    45,    46,    46,    47,
      47,    47,    47,    47,    47,    47,    48,    48,    48,    48,
      48,    48,    48,    49,    49,    49,    50,    50,    50,    52,
      51,    53,    53,    54,    54,    54,    54,    54,    54,    54,
      56,    57,    55,    55,    58,    58,    59,    59,    59,    59,
      59,    59,    60,    60,    60,    60,    61,    61,    62,    62,
      62,    62,    62,    63
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     0,     4,     3,     3,     3,     2,
       3,     3,     1,     1,     1,     1,     1,     2,     0,     1,
       4,     0,     1,     1,     2,     0,     1,     1,     2,     5,
       7,     3,     5,     5,     3,     5,     5,     4,     5,     7,
       9,     4,     9,     2,     2,     3,     1,     1,     1,     0,
       4,     1,     3,     1,     3,     3,     3,     3,     3,     2,
       0,     0,     8,     1,     1,     3,     2,     3,     2,     3,
       2,     3,     4,     4,     4,     4,     1,     3,     0,     1,
       1,     1,     1,     7
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    73,    10,    12,    11,    13,     9,    59,
       0,     0,     0,     0,     0,     0,     0,    28,    28,     4,
       0,     0,     0,     3,    29,     0,    22,     0,    23,    24,
      25,    26,     0,    56,    57,     0,    58,     0,     0,     0,
      88,     0,     0,     0,    54,    53,     0,     0,     0,     0,
      28,    28,    29,     0,     0,    19,     0,    28,     0,    33,
       5,     0,     0,     0,     0,     0,     6,    27,     7,     8,
       0,     0,    63,     0,    61,    71,    91,    92,    90,    89,
       0,    86,     0,     0,    44,     0,     0,     0,    41,     0,
       0,     0,    55,     0,    21,    37,     0,    28,    34,    14,
      16,    17,    18,    20,     0,    69,     0,    60,     0,     0,
      83,    88,    84,    85,    82,    28,    28,    47,    28,    28,
      28,    28,    51,    28,     0,    30,    38,    15,     0,    68,
      65,    67,    66,    64,    62,     0,    87,    45,    43,    48,
      46,    42,    39,     0,     0,     0,     0,     0,     0,    74,
      28,    28,     0,    93,    78,     0,    80,    76,     0,     0,
       0,    40,     0,    49,    79,    81,    77,    72,    75,    28,
      28,    52,    50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    23,    52,   127,    25,    26,    27,    28,    57,
      58,    96,    97,    29,    30,    31,    32,    33,    38,    73,
      74,    34,    39,   109,   148,   149,    35,    80,    81,    36
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -39
static const yytype_int16 yypact[] =
{
     -39,   109,   -39,   -39,   -39,   -39,   -39,   -39,   -39,    -3,
      13,    15,   -12,   -11,    18,    19,    29,    64,   270,   -39,
      64,    64,   152,   -39,   305,    38,   -39,    -1,   -39,   -39,
     -39,   -39,    41,   -39,   -39,    52,   -39,    24,   107,    65,
     140,     5,    64,    64,   -39,   -39,    64,    64,    64,    64,
      64,    64,   154,    45,    62,   154,   280,   212,   183,   -39,
     -39,    64,    64,    64,    64,    64,   -39,   -39,   -39,   -39,
      68,    55,    56,    49,    72,   -39,   -39,   -39,   -39,   -39,
      66,    73,   102,     8,   154,     3,   288,    31,   154,    59,
      82,   105,   -39,   113,   -39,   -39,   110,   241,   -39,   154,
     154,   154,   154,   154,   134,   -39,    89,   -39,   107,   119,
     -39,   140,   -39,   -39,   -39,   270,   270,   -39,   270,   270,
     270,   270,   -39,    64,    64,   -39,   -39,   -39,   121,   -39,
     -39,   -39,   -39,   -39,   -39,   136,   -39,   -39,   -39,   -39,
     -39,   -39,   138,   131,   296,   142,     0,    83,   145,   130,
     270,    64,   139,   -39,   -39,   175,   -39,   -39,   132,   162,
     136,   -39,    10,   -39,   -39,   -39,   -39,   -39,   -39,   270,
     270,   -39,   -39
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -39,   -39,   -39,     1,   -39,   -18,   -39,   -16,    48,   -39,
     -39,   -39,   -39,   -39,   -39,   -39,   -17,   -39,   -39,    91,
     -39,   -39,   -39,   -39,    43,   -39,   -39,   -38,   -39,   -39
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -89
static const yytype_int16 yytable[] =
{
      54,    53,    24,    83,   115,    59,    82,    37,    76,   113,
     154,   169,    77,    78,    40,    79,    42,    44,    45,    46,
      48,    55,    56,   155,    61,    62,    63,    64,    67,    65,
      50,   116,   118,   -88,    90,    91,   114,   -88,   170,    95,
      41,    98,    43,    84,    85,    47,    49,    86,    87,    88,
      89,    70,    61,    62,    63,    64,    51,    65,    66,   119,
     120,    68,    99,   100,   101,   102,   103,     4,     5,     6,
       7,     8,    69,   136,    92,    75,    93,   104,   107,   126,
      61,    62,    63,    64,   156,    65,    20,   121,   105,   106,
     129,    21,   130,   157,   110,   131,   132,   137,   138,   133,
     139,   140,   141,   142,   108,   111,   158,   143,    71,     2,
       3,   122,     4,     5,     6,     7,     8,    72,     9,    10,
      11,    12,    13,    14,    15,   144,    16,    17,    18,    19,
     112,    20,   161,   165,   123,   162,    21,   146,   -28,    22,
     124,   125,   166,    76,   128,   147,   135,    77,    78,   145,
      79,   171,   172,     3,   150,   -31,   -31,   -31,   -31,   -31,
     151,     9,   160,   -31,   -31,   -31,   -31,   -31,   163,   -31,
     -31,   -31,    22,   159,   -31,    61,    62,    63,    64,   -31,
      65,   -31,   -31,   -31,     3,   164,   -32,   -32,   -32,   -32,
     -32,   167,     9,   153,   -32,   -32,   -32,   -32,   -32,   134,
     -32,   -32,   -32,   168,     0,   -32,     0,     0,     0,     0,
     -32,     0,   -32,   -32,   -32,     4,     5,     6,     7,     8,
       0,     0,     0,    11,    12,    13,    14,    15,     0,    16,
      17,    18,     0,     0,    20,     0,     0,     0,     0,    21,
       0,     0,    22,   -35,     4,     5,     6,     7,     8,     0,
       0,     0,    11,    12,    13,    14,    15,     0,    16,    17,
      18,     0,     0,    20,     0,     0,     0,     0,    21,     0,
       0,    22,   -36,     4,     5,     6,     7,     8,     0,     0,
       0,    11,    12,    13,    14,    15,     0,    16,    17,    18,
       0,     0,    20,     0,     0,     0,     0,    21,     0,     0,
      22,    61,    62,    63,    64,     0,    65,     0,    94,    61,
      62,    63,    64,     0,    65,     0,   117,    61,    62,    63,
      64,     0,    65,     0,   152,    60,    61,    62,    63,    64,
       0,    65
};

static const yytype_int16 yycheck[] =
{
      18,    17,     1,    41,     1,    22,     1,    10,     3,     1,
      10,     1,     7,     8,     1,    10,     1,    29,    29,     1,
       1,    20,    21,    23,    21,    22,    23,    24,    29,    26,
       1,    28,     1,    28,    50,    51,    28,    32,    28,    57,
      27,    58,    27,    42,    43,    27,    27,    46,    47,    48,
      49,    27,    21,    22,    23,    24,    27,    26,    20,    28,
       1,    20,    61,    62,    63,    64,    65,     3,     4,     5,
       6,     7,    20,   111,    29,    10,    14,     9,    29,    97,
      21,    22,    23,    24,     1,    26,    22,    28,    33,    33,
       1,    27,     3,    10,    28,     6,     7,   115,   116,    10,
     118,   119,   120,   121,    32,    32,    23,   123,     1,     0,
       1,    29,     3,     4,     5,     6,     7,    10,     9,    10,
      11,    12,    13,    14,    15,   124,    17,    18,    19,    20,
      28,    22,   150,     1,    29,   151,    27,     1,    29,    30,
      27,    31,    10,     3,    10,     9,    27,     7,     8,    28,
      10,   169,   170,     1,    16,     3,     4,     5,     6,     7,
      29,     9,    32,    11,    12,    13,    14,    15,    29,    17,
      18,    19,    30,    28,    22,    21,    22,    23,    24,    27,
      26,    29,    30,    31,     1,    10,     3,     4,     5,     6,
       7,    29,     9,   145,    11,    12,    13,    14,    15,   108,
      17,    18,    19,   160,    -1,    22,    -1,    -1,    -1,    -1,
      27,    -1,    29,    30,    31,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    11,    12,    13,    14,    15,    -1,    17,
      18,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    30,    31,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    11,    12,    13,    14,    15,    -1,    17,    18,
      19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    27,    -1,
      -1,    30,    31,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    11,    12,    13,    14,    15,    -1,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      30,    21,    22,    23,    24,    -1,    26,    -1,    28,    21,
      22,    23,    24,    -1,    26,    -1,    28,    21,    22,    23,
      24,    -1,    26,    -1,    28,    20,    21,    22,    23,    24,
      -1,    26
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    35,     0,     1,     3,     4,     5,     6,     7,     9,
      10,    11,    12,    13,    14,    15,    17,    18,    19,    20,
      22,    27,    30,    36,    37,    39,    40,    41,    42,    47,
      48,    49,    50,    51,    55,    60,    63,    10,    52,    56,
       1,    27,     1,    27,    29,    29,     1,    27,     1,    27,
       1,    27,    37,    41,    39,    37,    37,    43,    44,    50,
      20,    21,    22,    23,    24,    26,    20,    29,    20,    20,
      27,     1,    10,    53,    54,    10,     3,     7,     8,    10,
      61,    62,     1,    61,    37,    37,    37,    37,    37,    37,
      41,    41,    29,    14,    28,    39,    45,    46,    50,    37,
      37,    37,    37,    37,     9,    33,    33,    29,    32,    57,
      28,    32,    28,     1,    28,     1,    28,    28,     1,    28,
       1,    28,    29,    29,    27,    31,    39,    38,    10,     1,
       3,     6,     7,    10,    53,    27,    61,    39,    39,    39,
      39,    39,    39,    41,    37,    28,     1,     9,    58,    59,
      16,    29,    28,    42,    10,    23,     1,    10,    23,    28,
      32,    39,    41,    29,    10,     1,    10,    29,    58,     1,
      28,    39,    39
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
        case 9:

/* Line 1455 of yacc.c  */
#line 82 "TP5.y"
    {(yyval.mystruct).tipo = (yyvsp[(1) - (1)].mystruct).tipo; (yyval.mystruct).valor_caracter = (yyvsp[(1) - (1)].mystruct).valor_caracter;;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 83 "TP5.y"
    {(yyval.mystruct).tipo = (yyvsp[(1) - (1)].mystruct).tipo; (yyval.mystruct).valor_entero=(yyvsp[(1) - (1)].mystruct).valor_entero;;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 84 "TP5.y"
    {(yyval.mystruct).tipo = (yyvsp[(1) - (1)].mystruct).tipo; (yyval.mystruct).valor_entero=(yyvsp[(1) - (1)].mystruct).valor_entero;;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 85 "TP5.y"
    {(yyval.mystruct).tipo = (yyvsp[(1) - (1)].mystruct).tipo; (yyval.mystruct).valor_entero=(yyvsp[(1) - (1)].mystruct).valor_entero;;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 86 "TP5.y"
    {(yyval.mystruct).tipo = (yyvsp[(1) - (1)].mystruct).tipo; (yyval.mystruct).valor_real=(yyvsp[(1) - (1)].mystruct).valor_real;;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 87 "TP5.y"
    {if((yyvsp[(1) - (3)].mystruct).tipo == (yyvsp[(3) - (3)].mystruct).tipo);}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 89 "TP5.y"
    { 
        if((yyvsp[(1) - (4)].mystruct).tipo == 1) {  // Si es de tipo entero
          (yyval.mystruct).valor_entero = (yyvsp[(1) - (4)].mystruct).valor_entero + (yyvsp[(3) - (4)].mystruct).valor_entero;
        }
        
        if{ ((yyvsp[(1) - (4)].mystruct).tipo == 2) // Si es de tipo real
           (yyval.mystruct).valor_real = (yyvsp[(1) - (4)].mystruct).valor_real + (yyvsp[(3) - (4)].mystruct).valor_real;
        }

        if {  ((yyvsp[(1) - (4)].mystruct).tipo == 3) // Si es de tipo caracter
                (yyval.mystruct).valor_caracter = (yyvsp[(1) - (4)].mystruct).valor_caracter + (yyvsp[(3) - (4)].mystruct).valor_caracter;
              }
    else
    {
        printf("Los operandos son de distinto tipo \n"); // Error semántico
    }

;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 109 "TP5.y"
    { (yyval.entero) = (yyvsp[(1) - (3)].entero) - (yyvsp[(3) - (3)].entero);                    	;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 110 "TP5.y"
    { (yyval.entero) = (yyvsp[(1) - (3)].entero) * (yyvsp[(3) - (3)].entero);                    	;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 111 "TP5.y"
    { (yyval.entero) = (yyvsp[(1) - (3)].entero) / (yyvsp[(3) - (3)].entero);                    	;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 112 "TP5.y"
    { (yyval.entero) = -(yyvsp[(2) - (2)].entero);                        	;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 113 "TP5.y"
    { (yyval.entero) = pow ((yyvsp[(1) - (3)].entero), (yyvsp[(3) - (3)].entero));               	;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 114 "TP5.y"
    { (yyval.entero) = (yyvsp[(2) - (3)].entero);                         	;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 132 "TP5.y"
    {printf("Se encontro una sentencia vacia\n");;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 133 "TP5.y"
    {printf("Se encontro una sentencia con una expresion\n");;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 141 "TP5.y"
    {printf("Se encontro una sentencia compuesta con una lista de declaraciones\n");;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 150 "TP5.y"
    {printf("Se encontro una sentencia compuesta con una lista de sentencias\n");;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 159 "TP5.y"
    {printf("Se encontro una sentencia IF");;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 160 "TP5.y"
    {printf("Se encontro una sentencia IF y ELSE\n");;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 161 "TP5.y"
    {agregarError("Error Sintactico: falta '(' en la sentencia IF"); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 162 "TP5.y"
    {agregarError("Error Sintactico: falta ')' en la sentencia IF"); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 163 "TP5.y"
    {printf("Se encontro una sentencia SWITCH\n");;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 164 "TP5.y"
    {agregarError("Error Sintactico: falta '(' en la sentencia SWITCH "); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 165 "TP5.y"
    {agregarError("Error Sintactico: falta ')' en la sentencia SWITCH "); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 168 "TP5.y"
    {printf("Se encontro la sentencia WHILE\n");;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 169 "TP5.y"
    {agregarError("Error Sintactico: falta '(' en la sentencia WHILE "); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 170 "TP5.y"
    {agregarError("Error Sintactico: falta ')' en la sentencia WHILE "); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 171 "TP5.y"
    {printf("Se encontro una sentencia DO\n");;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 172 "TP5.y"
    {printf("Se encontro una sentencia FOR\n");;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 173 "TP5.y"
    {agregarError("Error Sintactico: falta '(' en la sentencia FOR "); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 174 "TP5.y"
    {agregarError("Error Sintactico: falta ')' en la sentencia FOR "); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 179 "TP5.y"
    {printf("Se encontro la sentencia CONTINUE\n");;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 180 "TP5.y"
    {printf("Se encontro la sentencia BREAK\n");;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 181 "TP5.y"
    {printf("Se encontro la sentencia RETURN\n");;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 193 "TP5.y"
    {tipo=(yyvsp[(1) - (1)].cadena);;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 200 "TP5.y"
    {aux = buscarSimbolo((yyvsp[(1) - (1)].cadena)); if (aux) agregarError("Error Semantico : la variable ya esta declarada "); else agregarsimbolo((yyvsp[(1) - (1)].cadena),tipo);;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 201 "TP5.y"
    {aux=buscarSimbolo((yyvsp[(1) - (3)].cadena)); if (aux) agregarError("Error Semantico : la variable ya esta declarada "); declararVariableConElIgual((yyvsp[(1) - (3)].cadena),tipo,(yyvsp[(3) - (3)].cadena));;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 203 "TP5.y"
    {aux=buscarSimbolo((yyvsp[(1) - (3)].cadena)); if (aux) agregarError("Error Semantico : la variable ya esta declarada "); else declararVariable((yyvsp[(1) - (3)].strval),tipo,(yyvsp[(3) - (3)].entero));;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 204 "TP5.y"
    {aux=buscarSimbolo((yyvsp[(1) - (3)].cadena)); if (aux) agregarError("Error Semantico : la variable ya esta declarada "); else declararVariable((yyvsp[(1) - (3)].strval),tipo,(yyvsp[(3) - (3)].caracter));;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 205 "TP5.y"
    {aux=buscarSimbolo((yyvsp[(1) - (3)].cadena)); if (aux) agregarError("Error Semantico : la variable ya esta declarada "); else declararVariable((yyvsp[(1) - (3)].strval),tipo,(yyvsp[(3) - (3)].real));;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 206 "TP5.y"
    {agregarError("Error Sintactico : se inicializo con un valor incorrecto");;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 207 "TP5.y"
    {agregarError("Error Sintactico : identificador incorrecto");;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 210 "TP5.y"
    {tipo = (yyvsp[(1) - (1)].cadena); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 210 "TP5.y"
    {id = (yyvsp[(2) - (3)].cadena);;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 210 "TP5.y"
    {aux=buscarSimbolo((yyvsp[(2) - (8)].cadena)); if (aux) agregarError("Error Semantico : el identificador ya esta declarado");  else declararFuncion(id, tipo); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 211 "TP5.y"
    { agregarError("Error Sintactico : identificador incorrecto  en declaracion de funcion"); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 218 "TP5.y"
    {aux=buscarEnListaFunciones(id); if(aux) agregoParametros(aux->lista_parametros,(yyvsp[(1) - (2)].cadena));}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 219 "TP5.y"
    {aux=buscarEnListaFunciones(id); if(aux) agregoParametros(aux->lista_parametros,strcat((yyvsp[(1) - (3)].cadena),"*")) ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 220 "TP5.y"
    {agregarError("Error sintactico : falta tipo de dato del parametro");}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 221 "TP5.y"
    {agregarError("Error sintactico : falta tipo de dato del puntero parametro");}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 222 "TP5.y"
    {agregarError("Error sintactico : falta indentificador del parametro");}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 223 "TP5.y"
    {agregarError("Error sintactico : falta identificador del puntero del  parametro");}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 226 "TP5.y"
    {aux=buscarEnListaFuciones((yyvsp[(1) - (4)].cadena)); if (aux) verificarParametros(aux->lista_parametros) else listaArgumentosTemporal = NULL;;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 228 "TP5.y"
    {agregarError("Error Sintactico : falta '(' en la invocacion de la funcion"); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 229 "TP5.y"
    {agregarError("Error Sintactico : argumentos no validos");;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 230 "TP5.y"
    {agregarError("Error Sintactico : falta ')' en la invocacion de la funcion"); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 238 "TP5.y"
    {aux=buscarSimbolo((yyvsp[(1) - (1)].cadena)); if (aux) agregarArgumento(aux->tipo); else agregarError("Error Semantico : la variable %s no esta declarada \n",(yyvsp[(1) - (1)].cadena));;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 239 "TP5.y"
    {agregoArgumento("char*");;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 240 "TP5.y"
    {agregoArgumento("int");;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 241 "TP5.y"
    {agregoArgumento("char");;}
    break;



/* Line 1455 of yacc.c  */
#line 2006 "TP5.tab.c"
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
#line 247 "TP5.y"



int main(){
/*         #ifdef BISON_DEBUG
        yydebug = 1;
        #endif */
        yyin = fopen("docDePrueba.c","r");
        printf("\n");
        yyparse();
        
}
