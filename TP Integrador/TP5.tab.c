
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
#include "Funciones.c"

int yylex();

FILE* yyin;

int yywrap(){
	return(1);
}

void yyerror (char const *s) {          //Con yyerror se detecta el error sintáctico 
   fprintf (stderr, "%s\n", s);
} 

//Parametro* listaParametrosAux = NULL;
char* tipo;
Tabla *aux;
Tabla *aux2;
Tabla *aux3;



/* Line 189 of yacc.c  */
#line 102 "TP5.tab.c"

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



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 29 "TP5.y"

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



/* Line 214 of yacc.c  */
#line 173 "TP5.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 185 "TP5.tab.c"

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
#define YYLAST   238

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNRULES -- Number of states.  */
#define YYNSTATES  169

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
      23,    24,    25,    28,    26,    29,     2,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    20,
       2,    27,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    31,     2,     2,     2,     2,     2,
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
     272,   276,   280,   284,   288,   293,   298,   303,   305,   309,
     310,   312,   314,   316,   318
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      33,     0,    -1,    -1,    33,    34,    -1,    19,    -1,    58,
      19,    -1,    35,    19,    -1,    46,    19,    -1,    59,    19,
      -1,    36,    -1,    38,    -1,    43,    -1,    44,    -1,    45,
      -1,    37,    20,    -1,    -1,    58,    -1,    21,    39,    41,
      22,    -1,    -1,    40,    -1,    46,    -1,    40,    46,    -1,
      -1,    42,    -1,    35,    -1,    42,    35,    -1,    13,    23,
      58,    24,    35,    -1,    13,    23,    58,    24,    35,    14,
      35,    -1,    13,     1,    58,    -1,    13,    23,    58,     1,
      35,    -1,    10,    23,    58,    24,    35,    -1,    10,     1,
      58,    -1,    10,    23,    58,     1,    35,    -1,    12,    23,
      58,    24,    35,    -1,    12,     1,    58,    -1,    12,    23,
      58,     1,    35,    -1,    11,    35,    12,    23,    58,    24,
      20,    -1,    15,    23,    37,    20,    37,    20,    37,    24,
      35,    -1,    15,     1,    37,    -1,    15,    23,    37,    20,
      37,    20,    37,     1,    35,    -1,    17,    20,    -1,    16,
      20,    -1,    18,    37,    20,    -1,    -1,     3,    47,    51,
      -1,    -1,     3,    25,    48,    51,    -1,    -1,     4,    49,
      50,    -1,     5,    55,    -1,     1,    55,    -1,    50,    -1,
      52,    20,    -1,    53,    -1,    54,    -1,    54,    26,    53,
      -1,     5,    -1,     5,    27,     5,    -1,     5,    27,     7,
      -1,     5,    27,     9,    -1,     5,    27,     8,    -1,     5,
      27,     6,    -1,     5,    27,     1,    -1,     1,    27,    -1,
      23,    56,    24,    38,    -1,    23,    56,    24,    20,    -1,
      -1,    57,    -1,    57,    26,    56,    -1,     3,     5,    -1,
       3,    25,     5,    -1,     1,     5,    -1,     1,    25,     5,
      -1,     3,     1,    -1,     3,    25,     1,    -1,     7,    -1,
       8,    -1,     5,    -1,    58,    28,    58,    -1,    58,    29,
      58,    -1,    58,    25,    58,    -1,    58,    30,    58,    -1,
      58,    31,    58,    -1,    23,    58,    24,    -1,     5,    23,
      60,    24,    -1,     5,     1,    60,    24,    -1,     5,    23,
      60,     1,    -1,    61,    -1,    61,    26,    60,    -1,    -1,
       5,    -1,     6,    -1,     7,    -1,     9,    -1,     8,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    71,    71,    72,    75,    76,    77,    78,    79,    82,
      83,    84,    85,    86,    89,    92,    93,    96,   100,   101,
     104,   105,   108,   109,   112,   113,   117,   118,   119,   120,
     121,   122,   123,   126,   127,   128,   129,   130,   131,   132,
     136,   137,   138,   142,   142,   143,   143,   144,   144,   147,
     156,   159,   160,   163,   166,   167,   170,   199,   239,   252,
     266,   278,   291,   293,   297,   298,   301,   302,   303,   306,
     307,   308,   309,   310,   311,   314,   315,   316,   334,   350,
     351,   352,   353,   354,   357,   371,   372,   375,   376,   379,
     380,   387,   388,   389,   390
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
  "')'", "'*'", "','", "'='", "'+'", "'-'", "'/'", "'^'", "$accept",
  "input", "line", "sentencia", "sentenciaExpresion", "opExpresion",
  "sentenciaCompuesta", "opListaDeclaraciones", "listaDeclaraciones",
  "opListaDeSentencias", "listaDeSentencias", "sentenciaDeSeleccion",
  "sentenciaDeIteracion", "sentenciaDeSalto", "declaracion", "$@1", "$@2",
  "$@3", "declaracionDefinicionFuncion", "declaraciones",
  "declaracionVariables", "listaVariables", "unaVariableSimple",
  "parametrosCuerpoFuncion", "listaParametros", "parametros", "expresion",
  "invocacionDeFuncion", "listaArgumentos", "argumento", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,    10,
      59,   123,   125,    40,    41,    42,    44,    61,    43,    45,
      47,    94
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    32,    33,    33,    34,    34,    34,    34,    34,    35,
      35,    35,    35,    35,    36,    37,    37,    38,    39,    39,
      40,    40,    41,    41,    42,    42,    43,    43,    43,    43,
      43,    43,    43,    44,    44,    44,    44,    44,    44,    44,
      45,    45,    45,    47,    46,    48,    46,    49,    46,    50,
      50,    51,    51,    52,    53,    53,    54,    54,    54,    54,
      54,    54,    54,    54,    55,    55,    56,    56,    56,    57,
      57,    57,    57,    57,    57,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    59,    59,    59,    60,    60,    61,
      61,    61,    61,    61,    61
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
       3,     2,     3,     2,     3,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     4,     4,     4,     1,     3,     0,
       1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,    15,     1,    43,    47,     0,    75,    76,     0,    15,
       0,     0,     0,     0,     0,    15,     4,    18,     0,     3,
       0,     9,     0,    10,    11,    12,    13,     0,    16,     0,
      45,     0,     0,    89,    89,     0,     0,    77,     0,    16,
       0,     0,     0,     0,    15,    15,    41,    40,     0,    15,
      19,    20,     0,     6,    14,     7,     5,     0,     0,     0,
       0,     0,     8,     0,     0,    56,    51,    44,     0,    53,
      54,     0,     0,    48,    90,    91,    92,    94,    93,     0,
      87,     0,    31,     0,     0,    34,     0,    28,     0,    38,
       0,    42,    24,     0,    15,    21,    83,    80,    78,    79,
      81,    82,    46,     0,    63,    50,     0,    49,    52,     0,
      85,    89,    86,    84,    15,    15,     0,    15,    15,    15,
      15,    15,    17,    25,     0,     0,     0,    67,    62,    57,
      61,    58,    60,    59,     0,    56,    55,    88,    32,    30,
       0,    35,    33,    29,    26,     0,    71,     0,    73,    69,
       0,     0,     0,     0,    15,    15,    72,    74,    70,    65,
      64,    68,    36,    27,     0,    15,    15,    39,    37
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    19,    20,    21,    22,    23,    49,    50,    93,
      94,    24,    25,    26,    27,    31,    63,    32,    66,    67,
      68,    69,    70,   105,   126,   127,    39,    29,    79,    80
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -59
static const yytype_int16 yypact[] =
{
     -59,   115,   -59,   -10,   -59,    26,   -59,   -59,    11,   191,
      12,    16,    25,    -2,    30,    59,   -59,   100,    59,   -59,
       6,   -59,    32,   -59,   -59,   -59,   -59,    49,   118,    70,
     -59,    64,    78,   145,   145,    59,    59,   -59,    66,   207,
      59,    59,    59,    59,    59,    59,   -59,   -59,    77,   153,
     100,   -59,   192,   -59,   -59,   -59,   -59,    59,    59,    59,
      59,    59,   -59,    64,    61,    89,   -59,   -59,    94,   -59,
      55,    90,    90,   -59,   -59,   -59,   -59,   -59,   -59,    97,
      98,     5,   207,    46,   106,   207,    62,   207,    71,   -59,
     120,   -59,   -59,   122,   172,   -59,   -59,   207,   207,   207,
     207,   207,   -59,     8,   -59,   -59,    15,   -59,   -59,    93,
     -59,   145,   -59,   -59,   191,   191,    59,   191,   191,   191,
     191,    59,   -59,   -59,    48,     3,   131,   116,   -59,   -59,
     -59,   -59,   -59,   -59,   132,   135,   -59,   -59,   -59,   -59,
     200,   -59,   -59,   -59,   164,   147,   -59,   176,   -59,   -59,
     134,   152,     8,   166,   191,    59,   -59,   -59,   -59,   -59,
     -59,   -59,   -59,   -59,     9,   191,   191,   -59,   -59
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -59,   -59,   -59,    -9,   -59,   -14,    40,   -59,   -59,   -59,
     -59,   -59,   -59,   -59,   -12,   -59,   -59,   -59,   160,   137,
     -59,    88,   -59,   -58,    53,   -59,     1,   -59,   -31,   -59
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -78
static const yytype_int16 yytable[] =
{
      38,    48,    28,    81,   148,    51,   112,   107,   149,   124,
     165,   125,    35,    40,   107,    30,   128,    42,    46,    52,
     129,   130,   131,   132,   133,    53,    44,    33,   150,   113,
      89,    90,   -66,   166,    36,    41,    82,    83,    95,    43,
      92,    85,    86,    87,    88,   -77,   -77,   114,    45,    34,
      47,   -77,    54,   146,   -77,   -77,   -77,   -77,    97,    98,
      99,   100,   101,   117,    37,    64,     6,     7,    55,    65,
     115,    57,   119,   147,    58,    59,    60,    61,    84,    71,
     137,   109,    18,    72,   103,   123,   118,    57,   104,    62,
      58,    59,    60,    61,   134,   120,    57,    91,   135,    58,
      59,    60,    61,     3,     4,   138,   139,   145,   141,   142,
     143,   144,   103,   103,   108,     2,   106,   140,     3,     4,
       5,   110,     6,     7,   111,     8,     9,    10,    11,   116,
      12,    13,    14,    15,    16,   157,    17,    56,    18,   158,
     121,   164,   152,    57,   122,   163,    58,    59,    60,    61,
      74,    75,    76,    77,    78,   151,   167,   168,    37,   104,
       6,     7,   106,     8,     9,    10,    11,   155,    12,    13,
      14,    15,   159,    17,    17,   -22,    18,    37,   154,     6,
       7,   156,     8,     9,    10,    11,   162,    12,    13,    14,
      15,   160,    73,    17,   -23,    18,    37,   136,     6,     7,
     102,     8,     9,    10,    11,   161,    12,    13,    14,    15,
       0,     0,    17,     0,    18,     0,    96,    57,     0,     0,
      58,    59,    60,    61,   153,    57,     0,     0,    58,    59,
      60,    61,    57,     0,     0,    58,    59,    60,    61
};

static const yytype_int16 yycheck[] =
{
       9,    15,     1,    34,     1,    17,     1,    65,     5,     1,
       1,     3,     1,     1,    72,    25,     1,     1,    20,    18,
       5,     6,     7,     8,     9,    19,     1,     1,    25,    24,
      44,    45,    24,    24,    23,    23,    35,    36,    50,    23,
      49,    40,    41,    42,    43,    19,    20,     1,    23,    23,
      20,    25,    20,     5,    28,    29,    30,    31,    57,    58,
      59,    60,    61,     1,     5,     1,     7,     8,    19,     5,
      24,    25,     1,    25,    28,    29,    30,    31,    12,     1,
     111,    26,    23,     5,    23,    94,    24,    25,    27,    19,
      28,    29,    30,    31,     1,    24,    25,    20,     5,    28,
      29,    30,    31,     3,     4,   114,   115,   121,   117,   118,
     119,   120,    23,    23,    20,     0,    27,   116,     3,     4,
       5,    24,     7,     8,    26,    10,    11,    12,    13,    23,
      15,    16,    17,    18,    19,     1,    21,    19,    23,     5,
      20,   155,    26,    25,    22,   154,    28,    29,    30,    31,
       5,     6,     7,     8,     9,    24,   165,   166,     5,    27,
       7,     8,    27,    10,    11,    12,    13,    20,    15,    16,
      17,    18,    20,    21,    21,    22,    23,     5,    14,     7,
       8,     5,    10,    11,    12,    13,    20,    15,    16,    17,
      18,   151,    32,    21,    22,    23,     5,   109,     7,     8,
      63,    10,    11,    12,    13,   152,    15,    16,    17,    18,
      -1,    -1,    21,    -1,    23,    -1,    24,    25,    -1,    -1,
      28,    29,    30,    31,    24,    25,    -1,    -1,    28,    29,
      30,    31,    25,    -1,    -1,    28,    29,    30,    31
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    33,     0,     3,     4,     5,     7,     8,    10,    11,
      12,    13,    15,    16,    17,    18,    19,    21,    23,    34,
      35,    36,    37,    38,    43,    44,    45,    46,    58,    59,
      25,    47,    49,     1,    23,     1,    23,     5,    35,    58,
       1,    23,     1,    23,     1,    23,    20,    20,    37,    39,
      40,    46,    58,    19,    20,    19,    19,    25,    28,    29,
      30,    31,    19,    48,     1,     5,    50,    51,    52,    53,
      54,     1,     5,    50,     5,     6,     7,     8,     9,    60,
      61,    60,    58,    58,    12,    58,    58,    58,    58,    37,
      37,    20,    35,    41,    42,    46,    24,    58,    58,    58,
      58,    58,    51,    23,    27,    55,    27,    55,    20,    26,
      24,    26,     1,    24,     1,    24,    23,     1,    24,     1,
      24,    20,    22,    35,     1,     3,    56,    57,     1,     5,
       6,     7,     8,     9,     1,     5,    53,    60,    35,    35,
      58,    35,    35,    35,    35,    37,     5,    25,     1,     5,
      25,    24,    26,    24,    14,    20,     5,     1,     5,    20,
      38,    56,    20,    35,    37,     1,    24,    35,    35
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
        case 15:

/* Line 1455 of yacc.c  */
#line 92 "TP5.y"
    {printf("Se encontro una sentencia vacia\n");;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 93 "TP5.y"
    {printf("Se encontro una sentencia con una expresion\n");;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 101 "TP5.y"
    {printf("Se encontro una sentencia compuesta con una lista de declaraciones\n");;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 109 "TP5.y"
    {printf("Se encontro una sentencia compuesta con una lista de sentencias\n");;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 117 "TP5.y"
    {printf("Se encontro una sentencia IF\n");;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 118 "TP5.y"
    {printf("Se encontro una sentencia IF y ELSE\n");;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 119 "TP5.y"
    {agregarError("Error Sintactico: Despues del IF se espera un '('\n"); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 120 "TP5.y"
    {agregarError("Error Sintactico: falta ')' en la sentencia IF\n"); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 121 "TP5.y"
    {printf("Se encontro una sentencia SWITCH\n");;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 122 "TP5.y"
    {agregarError("Error Sintactico: Despues del SWITCH se espera un '('\n"); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 123 "TP5.y"
    {agregarError("Error Sintactico: falta ')' en la sentencia SWITCH\n"); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 126 "TP5.y"
    {printf("Se encontro la sentencia WHILE\n");;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 127 "TP5.y"
    {agregarError("Error Sintactico: Despues del WHILE se espera un '('\n"); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 128 "TP5.y"
    {agregarError("Error Sintactico: falta ')' en la sentencia WHILE\n"); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 129 "TP5.y"
    {printf("Se encontro una sentencia DO\n");;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 130 "TP5.y"
    {printf("Se encontro una sentencia FOR\n");;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 131 "TP5.y"
    {agregarError("Error Sintactico: Despues del FOR se espera un '('\n"); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 132 "TP5.y"
    {agregarError("Error Sintactico: falta ')' en la sentencia FOR\n"); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 136 "TP5.y"
    {printf("Se encontro la sentencia CONTINUE\n");;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 137 "TP5.y"
    {printf("Se encontro la sentencia BREAK\n");;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 138 "TP5.y"
    {printf("Se encontro la sentencia RETURN\n");;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 142 "TP5.y"
    { tipo = (yyvsp[(1) - (1)].cadena); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 143 "TP5.y"
    { tipo = strcat((yyvsp[(1) - (2)].cadena),"*"); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 144 "TP5.y"
    { tipo = "void"; ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 147 "TP5.y"
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

/* Line 1455 of yacc.c  */
#line 156 "TP5.y"
    { agregarError("Error Sintactico : nombre de la funcion incorrecto"); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 171 "TP5.y"
    {
                                        aux=buscarSimbolo((yyvsp[(1) - (1)].cadena)); 
                                        if (aux) 
                                                agregarError("Error Semantico: la variable ya esta declarada\n"); 
                                        else 
                                        {
                                                aux2 = agregoSimbolo2( (yyvsp[(1) - (1)].cadena) , tipo, 1);

                                                        if (aux2-> tipo == "int") {
                                                                aux2->value.valEnt = 0;
                                                        
                                                        } else if (aux2 -> tipo == "float"){
                                                                aux2->value.valReal = 0.0;

                                                        } else if (aux2 -> tipo == "char") {
                                                                aux2->value.valChar = '\0';

                                                        }
                                                
                                                        else if (aux2 -> tipo == "char*"){
                                                                aux2->value.valString = NULL;

                                                        }
                                                        
                                        }
                                                                                                            
                                ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 200 "TP5.y"
    {
                                aux=buscarSimbolo((yyvsp[(1) - (3)].cadena)); 
                                if (aux) 
                                        agregarError("Error Semantico : la variable ya esta declarada\n"); 
                                else 
                                {
                                        aux2=buscarSimbolo((yyvsp[(3) - (3)].cadena)); 
                                        if(aux2 && (strcmp(tipo, aux2->tipo) == 0)) { 
                                                aux3 = agregoSimbolo2((yyvsp[(1) - (3)].cadena) , tipo, 1); 

                                                if (aux3->tipo == "int") {
                                                        aux2->value.valEnt = (yyvsp[(3) - (3)].entero);
                                                }

                                                else if (aux3 -> tipo == "float"){
                                                        aux2->value.valReal = (yyvsp[(3) - (3)].real);

                                                }

                                                else if (aux3 -> tipo == "char"){
                                                        aux2->value.valChar = (yyvsp[(3) - (3)].caracter);


                                                }
                                                else if (aux3 -> tipo == "char*"){
                                                        aux2->value.valString = (yyvsp[(3) - (3)].cadena);

                                                }            
                                                                                                                                                                                 
                                        if (aux2 == NULL)
                                                agregarError("Error Semantico : la variable no esta declarada\n");

                                        if (aux2 && (strcmp(tipo, aux2->tipo) != 0))
                                                agregarError("Error Semantico : las variables son de distinto tipo\n");
                                                                                                                    
                                        }
                                }
                        ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 239 "TP5.y"
    { 
                                                                aux=buscarSimbolo((yyvsp[(1) - (3)].cadena)); 
                                                                if (aux) 
                                                                        agregarError("Error Semantico : la variable ya esta declarada "); 
                                                                        else {
                                                                                if(strcmp(tipo,"int") == 0){ 
                                                                                        aux2 = agregoSimbolo2((yyvsp[(1) - (3)].cadena) , tipo, 1);  
                                                                                        aux2->value.valEnt = (yyvsp[(3) - (3)].mystruct).valor_entero;}
                                                                                else
                                                                                        agregarError("Error Semantico : son de distinto tipo"); 
                                                                        }
                                                        ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 252 "TP5.y"
    {
                                                                aux=buscarSimbolo((yyvsp[(1) - (3)].cadena)); 
                                                                if (aux) 
                                                                        agregarError("Error Semantico : la variable ya esta declarada "); 
                                                                else {
                                                                        if (strcmp(tipo, "char") == 0) {
                                                                                aux2 = agregoSimbolo2((yyvsp[(1) - (3)].cadena) , tipo, 1);  
                                                                                aux2->value.valChar = (yyvsp[(3) - (3)].caracter); 
                                                                        }
                                                                        else 
                                                                                agregarError("Error Semantico : son de distinto tipo");
                                                                }
                                                        ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 266 "TP5.y"
    { 
                                                                aux=buscarSimbolo((yyvsp[(1) - (3)].cadena)); 
                                                                if (aux) 
                                                                        agregarError("Error Semantico : la variable ya esta declarada "); 
                                                                else
                                                                        if (strcmp(tipo, "double") == 0){ // si borro "0" me toma el if
                                                                                aux2 = agregoSimbolo2((yyvsp[(1) - (3)].cadena) , tipo, 1);  
                                                                                aux2->value.valReal = (yyvsp[(3) - (3)].mystruct).valor_real;} 
                                                                        else{
                                                                                agregarError("Error Semantico : son de distinto tipo "); }
                                                        ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 278 "TP5.y"
    {
                                                                aux=buscarSimbolo((yyvsp[(1) - (3)].cadena)); 
                                                                if (aux) 
                                                                        agregarError("Error Semantico : la variable ya esta declarada "); 
                                                                else 
                                                                        if (strcmp(tipo, "char*") == 0){
                                                                                aux2 = agregoSimbolo2((yyvsp[(1) - (3)].cadena) , tipo, 1);  
                                                                                aux2->value.valString = (yyvsp[(3) - (3)].cadena);}  
                                                                        else 
                                                                                agregarError("Error Semantico : son de distinto tipo ");
                                                        ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 291 "TP5.y"
    { agregarError("Error Sintactico : se inicializo con un valor incorrecto"); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 293 "TP5.y"
    { agregarError("Error Sintactico : identificador incorrecto"); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 301 "TP5.y"
    {agregoParametro("void");;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 306 "TP5.y"
    { agregoParametro((yyvsp[(1) - (2)].cadena));;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 307 "TP5.y"
    { agregoParametro(strcat((yyvsp[(1) - (3)].cadena),"*"));;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 308 "TP5.y"
    { agregarError("ERROR SINTACTICO : falta tipo de dato del parametro"); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 309 "TP5.y"
    { agregarError("ERROR SINTACTICO : falta tipo de dato del puntero parametro"); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 310 "TP5.y"
    { agregarError("ERROR SINTACTICO : falta identificador en parametro"); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 311 "TP5.y"
    { agregarError("ERROR SINTACTICO : falta identificador del puntero parametro"); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 314 "TP5.y"
    { (yyval.mystruct).tipo = (yyvsp[(1) - (1)].mystruct).tipo;  (yyval.mystruct).valor_entero = (yyvsp[(1) - (1)].mystruct).valor_entero;;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 315 "TP5.y"
    { (yyval.mystruct).tipo = (yyvsp[(1) - (1)].mystruct).tipo;  (yyval.mystruct).valor_real = (yyvsp[(1) - (1)].mystruct).valor_real;;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 316 "TP5.y"
    { 
                                        aux=buscarSimbolo((yyvsp[(1) - (1)].cadena)); 
                                        if (aux) {  
                                                if (aux->tipo == "int") {
                                                        (yyval.mystruct).valor_entero = aux->value.valEnt; 
                                                        (yyval.mystruct).tipo = 1;
                                                        }

                                                else if (aux-> tipo == "float"){
                                                        (yyval.mystruct).valor_float = aux->value.valReal; 
                                                        (yyval.mystruct).tipo = 2;
                                                }
                                        } 
                                        else 
                                        { 
                                                agregarError("La variable no esta declarada\n");  } 
                                        ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 334 "TP5.y"
    { 
                                                if((yyvsp[(1) - (3)].mystruct).tipo == (yyvsp[(3) - (3)].mystruct).tipo) { 
        
                                                        if((yyvsp[(1) - (3)].mystruct).tipo==1) { 
                                                                (yyval.mystruct).valor_entero=(yyvsp[(1) - (3)].mystruct).valor_entero+(yyvsp[(3) - (3)].mystruct).valor_entero; 
                                                        }
                                                        else
                                                        {
                                                        (yyval.mystruct).valor_real=(yyvsp[(1) - (3)].mystruct).valor_real+(yyvsp[(3) - (3)].mystruct).valor_real; }
                                                }
                                                else 
                                                { 
                                                        agregarError("Los operandos son de distinto tipo \n"); }
        
                                        ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 350 "TP5.y"
    { (yyval.mystruct) = (yyvsp[(1) - (3)].mystruct) - (yyvsp[(3) - (3)].mystruct);        ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 351 "TP5.y"
    { (yyval.mystruct) = (yyvsp[(1) - (3)].mystruct) * (yyvsp[(3) - (3)].mystruct);        ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 352 "TP5.y"
    { (yyval.mystruct) = (yyvsp[(1) - (3)].mystruct) / (yyvsp[(3) - (3)].mystruct);        ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 353 "TP5.y"
    { (yyval.mystruct) = pow ((yyvsp[(1) - (3)].mystruct), (yyvsp[(3) - (3)].mystruct));   ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 354 "TP5.y"
    { (yyval.mystruct) = (yyvsp[(2) - (3)].mystruct);             ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 357 "TP5.y"
    {
                                                                aux=buscarSimbolo((yyvsp[(1) - (4)].cadena));   
                                                                if (aux) { 
                                                                        if(aux -> variableOfuncion == 1){
                                                                                agregarError ("Error semantico : El IDENTIFICADOR esta declarado como variable");} 
                                                                        else if (compararParametros(aux->tiposParametros, listaParametrosAux) == 1){
                                                                                agregarError ("Error semantico : cantidad o tipos de parametros incorrectos");} 
                                                                } 
                                                                else 
                                                                {
                                                                        agregarError ("Error semantico : No esta declarada la funcion"); 
                                                                }
                                                                listaParametrosAux = NULL;
                                                                ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 371 "TP5.y"
    {agregarError("Error Sintactico : falta '(' en la invocacion de la funcion"); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 372 "TP5.y"
    {agregarError("Error Sintactico : falta ')' en la invocacion de la funcion"); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 379 "TP5.y"
    {agregoArgumento("void");;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 380 "TP5.y"
    {        
                                        aux=buscarSimbolo((yyvsp[(1) - (1)].cadena));    
                                        if (aux) 
                                                agregoArgumento(aux->tipo); 
                                        else 
                                                agregarError("Error Semantico : la variable no esta declarada\n");
                                ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 387 "TP5.y"
    { agregoArgumento("char*"); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 388 "TP5.y"
    { agregoArgumento("int"); ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 389 "TP5.y"
    { agregoArgumento("char"); ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 390 "TP5.y"
    { agregoArgumento("real"); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2119 "TP5.tab.c"
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
#line 393 "TP5.y"


Tabla *listaSimbolos;

int main(){

        yyin = fopen("","r");
        printf("\n");
        yyparse();
        mostrarSimbolos(listaSimbolos);
        mostrarErrores(listaErrores);
        
}
