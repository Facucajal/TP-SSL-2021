
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
#line 1 "bison.y"

#include "funciones.h"

#define YYDEBUG 1

int yylex(void);
int yyerror(const char *s);
extern FILE* yyin;
extern int yylineno;
int analisisCorrecto = 1;
int flag_error=0;
int contador=0;
char tipo[30];
char esVariable[30];
char nombre[30];




NODOVARIABLES* listavariables = NULL;
NODOFUNCIONES* listafunciones = NULL;
NODONORECONOCIDO* listaNoReconocido=NULL;
NODOSENTENCIAS* listaSentencias=NULL;
NODOTIPOS* listaParaVerificarSiEsNombreDeFuncion = NULL;



/* Line 189 of yacc.c  */
#line 101 "bison.tab.c"

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
     CONSTANTE_OCTAL = 258,
     CONSTANTE_HEXADECIMAL = 259,
     CONSTANTE_CARACTER = 260,
     IDENTIFICADOR = 261,
     PUNTERO_FLECHA = 262,
     MAS_MAS = 263,
     ELIPSIS = 264,
     UNION = 265,
     ENUM = 266,
     VOLATILE = 267,
     CONST = 268,
     UNSIGNED = 269,
     SIGNED = 270,
     TYPEDEF = 271,
     EXTERN = 272,
     STATIC = 273,
     REGISTER = 274,
     AUTO = 275,
     INCLUDE = 276,
     DOUBLE = 277,
     SHORT = 278,
     LONG = 279,
     VOID = 280,
     FLOAT = 281,
     INT = 282,
     CHAR = 283,
     CONSTANTE_DECIMAL = 284,
     DO = 285,
     FOR = 286,
     SWITCH = 287,
     CONTINUE = 288,
     RETURN = 289,
     CASE = 290,
     DEFAULT = 291,
     SIZEOF = 292,
     MENOS_MENOS = 293,
     STRUCT = 294,
     DEFINE = 295,
     IF = 296,
     WHILE = 297,
     LITERAL_CADENA = 298,
     DISTINTO = 299,
     BREAK = 300,
     ELSE = 301,
     MAYOR_IGUAL = 302,
     MENOR_IGUAL = 303,
     IGUAL_IGUAL = 304,
     AND_LOGICO = 305,
     OR_LOGICO = 306,
     MAS_IGUAL = 307,
     MENOS_IGUAL = 308,
     POR_IGUAL = 309,
     DIVISION_IGUAL = 310,
     NO_RECONOCIDO = 311,
     MODULO_IGUAL = 312,
     CORRIMIENTO_A_IZQUIERDA_IGUAL = 313,
     CORRIMIENTO_A_DERECHA_IGUAL = 314,
     Y_IGUAL = 315,
     POTENCIA_IGUAL = 316,
     O_IGUAL = 317,
     CORRIMIENTO_A_DERECHA = 318,
     CORRIMIENTO_A_IZQUIERDA = 319,
     GOTO = 320,
     CONSTANTE_REAL = 321
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 29 "bison.y"

   char cadena[30];
   int entero;
   float real;
   char cadena2[30];
   struct info{
       char cadena[30];
       int linea;
   }INFO;



/* Line 214 of yacc.c  */
#line 216 "bison.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 228 "bison.tab.c"

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
#define YYFINAL  65
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2021

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  92
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  231
/* YYNRULES -- Number of states.  */
#define YYNSTATES  389

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   321

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    90,     2,     2,     2,    88,    85,     2,
      77,    78,    69,    67,    74,    68,    91,    70,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    76,    71,
      86,    75,    87,    82,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    79,     2,    80,    84,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    81,     2,     2,     2,
       2,     2,     2,    72,    83,    73,    89,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    11,    13,    16,    18,    20,
      23,    25,    27,    32,    36,    40,    43,    47,    50,    52,
      55,    58,    60,    63,    65,    68,    70,    72,    74,    76,
      78,    80,    82,    84,    86,    88,    90,    92,    94,    96,
      98,   100,   102,   104,   106,   108,   114,   119,   122,   124,
     126,   128,   131,   133,   137,   139,   143,   147,   150,   152,
     155,   157,   159,   163,   165,   169,   172,   178,   183,   186,
     188,   192,   194,   198,   201,   203,   205,   209,   214,   218,
     223,   228,   232,   235,   239,   242,   244,   246,   249,   251,
     255,   257,   261,   264,   267,   269,   271,   275,   277,   281,
     286,   288,   292,   295,   297,   299,   302,   304,   308,   313,
     317,   321,   324,   329,   333,   337,   340,   342,   344,   346,
     348,   350,   352,   354,   358,   363,   367,   370,   372,   377,
     381,   385,   388,   390,   393,   399,   407,   413,   419,   427,
     437,   446,   455,   463,   472,   480,   488,   495,   499,   502,
     505,   509,   512,   514,   518,   520,   524,   526,   528,   530,
     532,   534,   536,   538,   540,   542,   544,   546,   548,   554,
     556,   558,   562,   564,   568,   570,   574,   576,   580,   582,
     586,   588,   592,   596,   598,   602,   606,   610,   614,   616,
     620,   624,   626,   630,   634,   636,   640,   644,   648,   650,
     655,   657,   660,   663,   666,   669,   674,   676,   678,   680,
     682,   684,   686,   688,   693,   698,   702,   706,   710,   713,
     716,   718,   720,   722,   726,   728,   732,   734,   736,   738,
     740,   742
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      93,     0,    -1,    -1,    21,    93,    -1,    40,   156,    93,
      -1,    94,    -1,     1,    94,    -1,    95,    -1,    56,    -1,
      94,    95,    -1,    96,    -1,    97,    -1,    99,   115,    98,
     132,    -1,   115,    98,   132,    -1,    99,   115,   132,    -1,
     115,   132,    -1,    99,   106,    71,    -1,    99,    71,    -1,
      97,    -1,    98,    97,    -1,   100,    99,    -1,   100,    -1,
     101,    99,    -1,   101,    -1,   102,    99,    -1,   102,    -1,
      20,    -1,    19,    -1,    18,    -1,    17,    -1,    16,    -1,
      27,    -1,    28,    -1,    26,    -1,    22,    -1,    23,    -1,
      25,    -1,    24,    -1,    15,    -1,    14,    -1,   103,    -1,
     112,    -1,   128,    -1,    13,    -1,    12,    -1,   104,     6,
      72,   105,    73,    -1,   104,    72,   105,    73,    -1,   104,
       6,    -1,    39,    -1,    10,    -1,   108,    -1,   105,   108,
      -1,   107,    -1,   106,    74,   107,    -1,   115,    -1,   115,
      75,   123,    -1,   109,   110,    71,    -1,   101,   109,    -1,
     101,    -1,   102,   109,    -1,   102,    -1,   111,    -1,   110,
      74,   111,    -1,   115,    -1,   115,    76,   141,    -1,    76,
     141,    -1,    11,     6,    72,   113,    73,    -1,    11,    72,
     113,    73,    -1,    11,     6,    -1,   114,    -1,   113,    74,
     114,    -1,     6,    -1,     6,    75,   141,    -1,   117,   116,
      -1,   116,    -1,     6,    -1,    77,   115,    78,    -1,     6,
      79,   141,    80,    -1,     6,    79,    80,    -1,     6,    77,
     119,    78,    -1,     6,    77,   122,    78,    -1,     6,    77,
      78,    -1,    69,   118,    -1,    69,   117,   118,    -1,    69,
     117,    -1,    69,    -1,   102,    -1,   118,   102,    -1,   120,
      -1,   120,    74,     9,    -1,   121,    -1,   120,    74,   121,
      -1,    99,   115,    -1,    99,   126,    -1,    99,    -1,     6,
      -1,   122,    74,     6,    -1,   138,    -1,    72,   124,    73,
      -1,    72,   124,    74,    73,    -1,   123,    -1,   124,    74,
     123,    -1,   109,   126,    -1,   109,    -1,   117,    -1,   117,
     127,    -1,   127,    -1,    77,   126,    78,    -1,   127,    79,
     141,    80,    -1,    79,   141,    80,    -1,   127,    79,    80,
      -1,    79,    80,    -1,   127,    77,   119,    78,    -1,    77,
     119,    78,    -1,   127,    77,    78,    -1,    77,    78,    -1,
      81,    -1,   130,    -1,   131,    -1,   132,    -1,   134,    -1,
     135,    -1,   136,    -1,     6,    76,   129,    -1,    35,   141,
      76,   129,    -1,    36,    76,   129,    -1,   137,    71,    -1,
      71,    -1,    72,    98,   133,    73,    -1,    72,   133,    73,
      -1,    72,    98,    73,    -1,    72,    73,    -1,   129,    -1,
     133,   129,    -1,    41,    77,   137,    78,   129,    -1,    41,
      77,   137,    78,   129,    46,   129,    -1,    32,    77,   137,
      78,   129,    -1,    42,    77,   137,    78,   129,    -1,    30,
     129,    42,    77,   137,    78,    71,    -1,    31,    77,   137,
      71,   137,    71,   137,    78,   129,    -1,    31,    77,   137,
      71,   137,    71,    78,   129,    -1,    31,    77,   137,    71,
      71,   137,    78,   129,    -1,    31,    77,   137,    71,    71,
      78,   129,    -1,    31,    77,    71,   137,    71,   137,    78,
     129,    -1,    31,    77,    71,   137,    71,    78,   129,    -1,
      31,    77,    71,    71,   137,    78,   129,    -1,    31,    77,
      71,    71,    78,   129,    -1,    65,     6,    71,    -1,    33,
      71,    -1,    45,    71,    -1,    34,   137,    71,    -1,    34,
      71,    -1,   138,    -1,   137,    74,   138,    -1,   140,    -1,
     153,   139,   138,    -1,    54,    -1,    55,    -1,    52,    -1,
      53,    -1,    57,    -1,    58,    -1,    59,    -1,    60,    -1,
      61,    -1,    62,    -1,    75,    -1,   142,    -1,   142,    82,
     137,    76,   140,    -1,   140,    -1,   143,    -1,   142,    51,
     143,    -1,   144,    -1,   143,    50,   144,    -1,   145,    -1,
     144,    83,   145,    -1,   146,    -1,   145,    84,   146,    -1,
     147,    -1,   146,    85,   147,    -1,   148,    -1,   147,    49,
     148,    -1,   147,    44,   148,    -1,   149,    -1,   148,    86,
     149,    -1,   148,    87,   149,    -1,   148,    48,   149,    -1,
     148,    47,   149,    -1,   150,    -1,   149,    64,   150,    -1,
     149,    63,   150,    -1,   151,    -1,   150,    67,   151,    -1,
     150,    68,   151,    -1,   152,    -1,   151,    69,   152,    -1,
     151,    70,   152,    -1,   151,    88,   152,    -1,   153,    -1,
      77,   125,    78,   152,    -1,   155,    -1,    38,   153,    -1,
       8,   153,    -1,   154,   152,    -1,    37,   153,    -1,    37,
      77,   125,    78,    -1,    85,    -1,    69,    -1,    67,    -1,
      68,    -1,    89,    -1,    90,    -1,   156,    -1,   155,    79,
     137,    80,    -1,   155,    77,   157,    78,    -1,   155,    77,
      78,    -1,   155,    91,     6,    -1,   155,     7,     6,    -1,
     155,    38,    -1,   155,     8,    -1,     6,    -1,   158,    -1,
      43,    -1,    77,   137,    78,    -1,   138,    -1,   157,    74,
     138,    -1,     3,    -1,     4,    -1,    29,    -1,     5,    -1,
      66,    -1,    11,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   106,   106,   107,   108,   109,   110,   112,   113,   114,
     116,   117,   119,   120,   121,   122,   124,   135,   137,   138,
     140,   141,   142,   143,   144,   145,   147,   148,   149,   150,
     151,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   166,   167,   169,   170,   171,   173,   174,
     176,   177,   179,   180,   182,   183,   185,   187,   188,   189,
     190,   192,   193,   195,   196,   197,   199,   200,   201,   203,
     204,   206,   207,   209,   210,   212,   213,   214,   215,   216,
     217,   218,   220,   221,   222,   223,   225,   226,   228,   229,
     231,   232,   234,   235,   236,   238,   239,   241,   242,   243,
     245,   246,   248,   249,   251,   252,   253,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   265,   267,   268,   269,
     270,   271,   272,   274,   275,   276,   278,   279,   281,   282,
     283,   284,   286,   287,   289,   290,   291,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   304,   305,   306,
     307,   308,   310,   311,   313,   314,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   328,   329,   331,
     333,   334,   336,   337,   339,   340,   342,   343,   345,   346,
     348,   349,   350,   352,   353,   354,   355,   356,   358,   359,
     360,   362,   363,   364,   366,   367,   368,   369,   371,   372,
     374,   375,   376,   377,   378,   379,   381,   382,   383,   384,
     385,   386,   388,   389,   390,   391,   392,   393,   394,   395,
     397,   398,   399,   400,   402,   403,   405,   406,   407,   408,
     409,   410
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONSTANTE_OCTAL",
  "CONSTANTE_HEXADECIMAL", "CONSTANTE_CARACTER", "IDENTIFICADOR",
  "PUNTERO_FLECHA", "MAS_MAS", "ELIPSIS", "UNION", "ENUM", "VOLATILE",
  "CONST", "UNSIGNED", "SIGNED", "TYPEDEF", "EXTERN", "STATIC", "REGISTER",
  "AUTO", "INCLUDE", "DOUBLE", "SHORT", "LONG", "VOID", "FLOAT", "INT",
  "CHAR", "CONSTANTE_DECIMAL", "DO", "FOR", "SWITCH", "CONTINUE", "RETURN",
  "CASE", "DEFAULT", "SIZEOF", "MENOS_MENOS", "STRUCT", "DEFINE", "IF",
  "WHILE", "LITERAL_CADENA", "DISTINTO", "BREAK", "ELSE", "MAYOR_IGUAL",
  "MENOR_IGUAL", "IGUAL_IGUAL", "AND_LOGICO", "OR_LOGICO", "MAS_IGUAL",
  "MENOS_IGUAL", "POR_IGUAL", "DIVISION_IGUAL", "NO_RECONOCIDO",
  "MODULO_IGUAL", "CORRIMIENTO_A_IZQUIERDA_IGUAL",
  "CORRIMIENTO_A_DERECHA_IGUAL", "Y_IGUAL", "POTENCIA_IGUAL", "O_IGUAL",
  "CORRIMIENTO_A_DERECHA", "CORRIMIENTO_A_IZQUIERDA", "GOTO",
  "CONSTANTE_REAL", "'+'", "'-'", "'*'", "'/'", "';'", "'{'", "'}'", "','",
  "'='", "':'", "'('", "')'", "'['", "']'", "'t'", "'?'", "'|'", "'^'",
  "'&'", "'<'", "'>'", "'%'", "'~'", "'!'", "'.'", "$accept",
  "unidad_de_programa", "unidad_de_traduccion", "declaracion_externa",
  "definicion_de_funcion", "declaracion", "lista_de_declaracion",
  "especificadores_de_declaracion",
  "especificador_categoria_almacenamiento", "especificador_de_tipo",
  "calificador_de_tipo", "especificador_estructura_o_union",
  "estructura_o_union", "lista_declaraciones_struct",
  "lista_declaradores_init", "declarador_init", "declaracion_struct",
  "lista_calificador_especificador", "lista_declaradores_struct",
  "declarador_struct", "especificador_enum", "lista_de_enumerador",
  "enumerador", "declarador", "declarador_directo", "apuntador",
  "lista_calificadores_de_tipo", "lista_tipos_de_parametro",
  "lista_de_parametros", "declaracion_de_parametro",
  "lista_de_identificadores", "inicializador", "lista_de_inicializadores",
  "nombre_de_tipo", "declarador_abstracto", "declarador_abstracto_directo",
  "nombre_typedef", "sentencia", "sentencia_etiquetada",
  "sentencia_expresion", "sentencia_compuesta", "lista_de_sentencias",
  "sentencia_de_seleccion", "sentencia_de_iteracion", "sentencia_de_salto",
  "expresion", "expresion_de_asignacion", "operador_de_asignacion",
  "expresion_condicional", "expresion_constante", "expresion_logica_or",
  "expresion_logica_and", "expresion_or_inclusivo",
  "expresion_or_exclusivo", "expresion_and", "expresion_de_igualdad",
  "expresion_relacional", "expresion_de_corrimiento", "expresion_aditiva",
  "expresion_multiplicativa", "expresion_cast", "expresion_unaria",
  "operador_unario", "expresion_posfija", "expresion_primaria",
  "lista_expresiones_argumento", "constante", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,    43,    45,    42,
      47,    59,   123,   125,    44,    61,    58,    40,    41,    91,
      93,   116,    63,   124,    94,    38,    60,    62,    37,   126,
      33,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    92,    93,    93,    93,    93,    93,    94,    94,    94,
      95,    95,    96,    96,    96,    96,    97,    97,    98,    98,
      99,    99,    99,    99,    99,    99,   100,   100,   100,   100,
     100,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   102,   102,   103,   103,   103,   104,   104,
     105,   105,   106,   106,   107,   107,   108,   109,   109,   109,
     109,   110,   110,   111,   111,   111,   112,   112,   112,   113,
     113,   114,   114,   115,   115,   116,   116,   116,   116,   116,
     116,   116,   117,   117,   117,   117,   118,   118,   119,   119,
     120,   120,   121,   121,   121,   122,   122,   123,   123,   123,
     124,   124,   125,   125,   126,   126,   126,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   128,   129,   129,   129,
     129,   129,   129,   130,   130,   130,   131,   131,   132,   132,
     132,   132,   133,   133,   134,   134,   134,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   136,   136,   136,
     136,   136,   137,   137,   138,   138,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   140,   140,   141,
     142,   142,   143,   143,   144,   144,   145,   145,   146,   146,
     147,   147,   147,   148,   148,   148,   148,   148,   149,   149,
     149,   150,   150,   150,   151,   151,   151,   151,   152,   152,
     153,   153,   153,   153,   153,   153,   154,   154,   154,   154,
     154,   154,   155,   155,   155,   155,   155,   155,   155,   155,
     156,   156,   156,   156,   157,   157,   158,   158,   158,   158,
     158,   158
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     3,     1,     2,     1,     1,     2,
       1,     1,     4,     3,     3,     2,     3,     2,     1,     2,
       2,     1,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     4,     2,     1,     1,
       1,     2,     1,     3,     1,     3,     3,     2,     1,     2,
       1,     1,     3,     1,     3,     2,     5,     4,     2,     1,
       3,     1,     3,     2,     1,     1,     3,     4,     3,     4,
       4,     3,     2,     3,     2,     1,     1,     2,     1,     3,
       1,     3,     2,     2,     1,     1,     3,     1,     3,     4,
       1,     3,     2,     1,     1,     2,     1,     3,     4,     3,
       3,     2,     4,     3,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     3,     2,     1,     4,     3,
       3,     2,     1,     2,     5,     7,     5,     5,     7,     9,
       8,     8,     7,     8,     7,     7,     6,     3,     2,     2,
       3,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     1,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     4,
       1,     2,     2,     2,     2,     4,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     3,     3,     3,     2,     2,
       1,     1,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    75,    49,     0,    44,    43,    39,    38,    30,
      29,    28,    27,    26,     0,    34,    35,    37,    36,    33,
      31,    32,    48,     0,     8,    85,     0,   116,     0,     5,
       7,    10,    11,     0,    21,    23,    25,    40,     0,    41,
       0,    74,     0,    42,     6,     0,     0,    68,     0,     3,
     226,   227,   229,   220,   231,   228,   222,   230,     0,     0,
     221,    86,    84,    82,     0,     1,     9,    17,     0,    52,
      54,    20,    22,    24,    47,     0,     0,    18,     0,     0,
      15,    73,    95,    81,    94,     0,    88,    90,     0,     0,
       0,     0,   208,   209,   207,     0,    78,   206,   210,   211,
     169,     0,   167,   170,   172,   174,   176,   178,   180,   183,
     188,   191,   194,   198,     0,   200,   212,     0,    71,     0,
      69,     0,   152,   154,   198,     4,    83,    87,    76,    16,
       0,     0,     0,    14,     0,    58,    60,     0,    50,     0,
     220,   231,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   127,   131,     0,   132,   117,   118,   119,
       0,   120,   121,   122,     0,    19,    13,    54,     0,     0,
      92,   104,    93,   106,    79,     0,     0,    80,   202,     0,
     204,   201,   103,     0,    77,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   203,     0,   219,   218,     0,     0,
       0,     0,     0,    67,     0,     0,   223,   158,   159,   156,
     157,   160,   161,   162,   163,   164,   165,   166,     0,    53,
       0,    55,    97,    12,     0,    57,    59,    46,    51,     0,
       0,    61,    63,     0,     0,     0,     0,   148,   151,     0,
       0,     0,     0,     0,   149,     0,   130,     0,   129,   133,
     126,   115,     0,     0,   111,     0,   105,     0,     0,    89,
      91,    96,     0,     0,   104,   102,     0,   171,     0,   173,
     175,   177,   179,   182,   181,   187,   186,   184,   185,   190,
     189,   192,   193,   195,   196,   197,   217,   215,   224,     0,
       0,   216,    66,    72,    70,   153,   155,   100,     0,    45,
      65,    56,     0,     0,   123,     0,     0,     0,     0,   150,
       0,   125,     0,     0,   147,   128,   113,   107,   109,   114,
       0,   110,     0,   205,   199,     0,     0,   214,   213,    98,
       0,    62,    64,     0,     0,     0,     0,     0,   124,     0,
       0,   112,   108,   168,   225,    99,   101,     0,     0,     0,
       0,     0,     0,   136,   134,   137,     0,   146,     0,     0,
       0,     0,     0,     0,     0,   138,   145,   144,     0,   142,
       0,     0,     0,   135,   143,   141,   140,     0,   139
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    28,    29,    30,    31,    32,    78,    33,    34,    35,
      36,    37,    38,   137,    68,    69,   138,   139,   240,   241,
      39,   119,   120,    40,    41,    42,    63,   262,    86,    87,
      88,   231,   308,   183,   263,   173,    43,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   122,   228,   123,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   124,   114,   115,   116,   299,    60
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -218
static const yytype_int16 yypact[] =
{
    1544,  1616,   -30,  -218,    26,  -218,  -218,  -218,  -218,  -218,
    -218,  -218,  -218,  -218,  1544,  -218,  -218,  -218,  -218,  -218,
    -218,  -218,  -218,   203,  -218,     5,     8,  -218,    22,  1664,
    -218,  -218,  -218,   185,  1880,  1880,  1880,  -218,    39,  -218,
    1808,  -218,    14,  -218,  1664,   532,   804,   -24,    60,  -218,
    -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  1373,  1544,
    -218,  -218,    23,    23,    36,  -218,  -218,  -218,     1,  -218,
    1767,  -218,  -218,  -218,   114,  1940,   321,  -218,  1808,   185,
    -218,  -218,  -218,  -218,    20,   119,    18,  -218,    65,  1448,
    1463,  1448,  -218,  -218,  -218,   497,  -218,  -218,  -218,  -218,
    -218,   125,   -32,   160,   137,   147,   183,   -11,   153,    -3,
     209,   -45,  -218,  -218,  1373,   227,  -218,    60,   214,    59,
    -218,    67,  -218,  -218,   316,  -218,    23,  -218,  -218,  -218,
       8,   819,  1808,  -218,  1940,  1940,  1940,  1899,  -218,    25,
     207,    26,   714,   218,   224,   234,   894,  1373,   231,   233,
     235,   240,   307,  -218,  -218,   409,  -218,  -218,  -218,  -218,
     564,  -218,  -218,  -218,    53,  -218,  -218,   239,  1579,   909,
    -218,    58,  -218,   142,  -218,  1695,   310,  -218,  -218,   497,
    -218,  -218,   -10,   241,  -218,  1373,  1373,  1373,  1373,  1373,
    1373,  1373,  1373,  1373,  1373,  1373,  1373,  1373,  1373,  1373,
    1373,  1373,  1373,  1373,  -218,   311,  -218,  -218,   997,  1373,
     314,   208,  1373,  -218,    60,  1373,  -218,  -218,  -218,  -218,
    -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  1373,  -218,
     819,  -218,  -218,  -218,  1918,  -218,  -218,  -218,  -218,  1373,
     102,  -218,   245,   714,   280,  1012,  1373,  -218,  -218,   104,
     247,   714,  1373,  1373,  -218,   257,  -218,   639,  -218,  -218,
    -218,  -218,   252,   283,  -218,   285,   142,  1839,  1087,  -218,
    -218,  -218,   289,  1736,   159,  -218,  1373,   160,     4,   137,
     147,   183,   -11,   153,   153,    -3,    -3,    -3,    -3,   209,
     209,   -45,   -45,  -218,  -218,  -218,  -218,  -218,  -218,    68,
     -64,  -218,  -218,  -218,  -218,  -218,  -218,  -218,   220,  -218,
    -218,  -218,    25,  1373,  -218,   295,  1102,   156,    70,  -218,
     714,  -218,   115,   124,  -218,  -218,  -218,  -218,  -218,  -218,
     301,  -218,   300,  -218,  -218,  1373,  1373,  -218,  -218,  -218,
     729,  -218,  -218,  1373,  1177,   178,  1192,   714,  -218,   714,
     714,  -218,  -218,  -218,  -218,  -218,  -218,   138,   714,   139,
    1267,  1282,   190,  -218,   335,  -218,   312,  -218,   714,   714,
     144,   714,   177,  1358,   714,  -218,  -218,  -218,   714,  -218,
     714,   714,   189,  -218,  -218,  -218,  -218,   714,  -218
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -218,     9,   381,     0,  -218,   -36,    -5,    17,  -218,   108,
      45,  -218,  -218,   250,  -218,   255,  -128,   -54,  -218,    83,
    -218,   279,   186,   -21,   -40,     2,   337,   -44,  -218,   222,
    -218,  -217,  -218,   225,   -69,  -164,  -218,  -121,  -218,  -218,
       6,   246,  -218,  -218,  -218,   -58,  -125,  -218,   -43,  -139,
    -218,   223,   216,   217,   229,   219,   105,    78,   101,   109,
     -86,   -35,  -218,  -218,   384,  -218,  -218
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -3
static const yytype_int16 yytable[] =
{
     121,    85,    81,   100,    77,    64,   232,   266,   250,   238,
     215,   113,    70,   307,     2,   172,   338,     5,     6,   185,
       2,   244,    65,    49,   201,   202,     2,    62,   204,    66,
     265,     2,    47,   191,    77,     5,     6,   121,   192,   259,
      77,   182,   165,   203,    66,    74,    80,    45,   117,    46,
     186,    71,    72,    73,   178,   180,   181,    79,   167,    25,
     197,   198,    84,   170,     2,   132,   118,   273,   125,   169,
      61,   155,   129,   303,    25,   130,   133,    25,   215,   113,
     335,   235,   236,   298,   166,    26,   171,    79,   249,    25,
     305,    26,   175,    79,    25,    79,   165,   168,    48,   169,
     310,   239,    26,   306,   100,   232,   238,    61,   127,   167,
     266,    75,   113,   275,   128,   293,   294,   295,   242,   165,
     136,   121,   314,   356,   260,   182,   100,   215,   278,   332,
     321,    81,   213,   214,   113,   168,   259,   169,   233,   176,
     136,   215,   336,   177,   215,   216,   337,    64,   347,    79,
     113,   300,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   100,
     171,   127,    79,   311,   342,   319,   312,   113,   215,   136,
     136,   136,   136,   135,   274,    84,   134,   317,   318,   215,
     334,     2,    84,   349,   322,   323,   100,   174,   215,   348,
     193,   194,   350,   135,   113,   184,    50,    51,    52,    53,
     187,   354,   215,   215,    54,   232,   366,   368,   215,   267,
     188,   268,   378,   330,   136,   100,   363,   346,   364,   365,
     215,   189,    55,   113,   205,   206,   273,   367,   169,   195,
     196,   113,   135,   135,   135,   135,    56,   376,   377,   360,
     379,   215,   215,   383,    25,   380,    67,   384,   345,   385,
     386,   373,    26,   215,   215,   207,   388,   387,   190,    57,
     100,   285,   286,   287,   288,   274,   199,   200,   113,   136,
      58,   302,   214,   243,    84,   357,   359,   135,   362,   212,
      84,   242,   353,   339,   340,   245,   283,   284,   289,   290,
     113,   246,   370,   372,   208,   247,   209,   251,   291,   292,
     252,   254,   253,   255,   131,   382,   271,   296,   210,   276,
     301,   313,   315,   320,    50,    51,    52,   140,   324,    89,
     326,     3,   141,     5,     6,     7,     8,     9,    10,    11,
      12,    13,   135,    15,    16,    17,    18,    19,    20,    21,
      55,   142,   143,   144,   145,   146,   147,   148,    90,    91,
      22,   327,   149,   150,    56,   328,   151,   333,   217,   218,
     219,   220,   343,   221,   222,   223,   224,   225,   226,   351,
     352,   374,    44,   375,   234,   229,   152,    57,    92,    93,
      94,   227,   153,    76,   154,   341,   211,   270,    95,   126,
     304,   257,    27,   279,   272,   280,    97,    59,   277,   282,
      98,    99,    50,    51,    52,   140,     0,    89,   281,     3,
     141,     5,     6,     7,     8,     9,    10,    11,    12,    13,
       0,    15,    16,    17,    18,    19,    20,    21,    55,   142,
     143,   144,   145,   146,   147,   148,    90,    91,    22,     0,
     149,   150,    56,     0,   151,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   152,    57,    92,    93,    94,     0,
     153,    76,   256,     0,     0,     0,    95,     0,     0,     0,
      27,     0,     0,     0,    97,     0,     0,     0,    98,    99,
      50,    51,    52,    53,     0,    89,     0,     3,   141,     5,
       6,     7,     8,     0,     0,     0,     0,     0,     0,    15,
      16,    17,    18,    19,    20,    21,    55,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    22,     0,    82,     0,
      56,     0,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,     0,    15,    16,    17,    18,    19,    20,
      21,     0,     0,    57,    92,    93,    94,    50,    51,    52,
     140,    22,    89,     0,    95,    54,     0,     0,    27,     0,
       0,     0,    97,     0,     0,     0,    98,    99,     0,     0,
       0,     0,     0,    55,   142,   143,   144,   145,   146,   147,
     148,    90,    91,     0,     0,   149,   150,    56,     0,   151,
      83,     0,     0,    27,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   152,
      57,    92,    93,    94,     0,   153,    76,   258,     0,     0,
       0,    95,    50,    51,    52,   140,     0,    89,     0,    97,
      54,     0,     0,    98,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,   142,
     143,   144,   145,   146,   147,   148,    90,    91,     0,     0,
     149,   150,    56,     0,   151,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   152,    57,    92,    93,    94,     0,
     153,    76,   325,     0,     0,     0,    95,    50,    51,    52,
     140,     0,    89,     0,    97,    54,     0,     0,    98,    99,
       0,     0,    50,    51,    52,    53,     0,    89,     0,     0,
      54,     0,     0,    55,   142,   143,   144,   145,   146,   147,
     148,    90,    91,     0,     0,   149,   150,    56,    55,   151,
       0,     0,     0,     0,     0,     0,    90,    91,     0,     0,
       0,     0,    56,     0,     0,     0,     0,     0,     0,   152,
      57,    92,    93,    94,     0,   153,    76,     0,     0,     0,
       0,    95,     0,     0,     0,    57,    92,    93,    94,    97,
       0,   230,   355,    98,    99,     0,    95,    50,    51,    52,
      53,     0,    89,     0,    97,    54,     0,     0,    98,    99,
       0,     0,    50,    51,    52,    53,     0,    89,     0,     0,
      54,     0,     0,    55,     0,     0,     0,     0,     0,     0,
       0,    90,    91,     0,     0,     0,     0,    56,    55,     0,
       0,     0,     0,     0,     0,     0,    90,    91,     0,     0,
       0,     0,    56,     0,     0,     0,     0,     0,     0,     0,
      57,    92,    93,    94,     0,     0,     0,     0,     0,     0,
       0,    95,     0,     0,    96,    57,    92,    93,    94,    97,
       0,   230,     0,    98,    99,     0,    95,    50,    51,    52,
      53,     0,    89,     0,    97,    54,     0,     0,    98,    99,
       0,     0,    50,    51,    52,    53,     0,    89,     0,     0,
      54,     0,     0,    55,     0,     0,     0,     0,     0,     0,
       0,    90,    91,     0,     0,     0,     0,    56,    55,     0,
       0,     0,     0,     0,     0,     0,    90,    91,     0,     0,
       0,     0,    56,     0,     0,     0,     0,     0,     0,     0,
      57,    92,    93,    94,     0,   248,     0,     0,     0,     0,
       0,    95,     0,     0,     0,    57,    92,    93,    94,    97,
       0,     0,     0,    98,    99,     0,    95,     0,     0,   264,
       0,     0,     0,     0,    97,     0,     0,     0,    98,    99,
      50,    51,    52,    53,     0,    89,     0,     0,    54,     0,
       0,     0,     0,     0,     0,    50,    51,    52,    53,     0,
      89,     0,     0,    54,     0,     0,    55,     0,     0,     0,
       0,     0,     0,     0,    90,    91,     0,     0,     0,     0,
      56,    55,     0,     0,     0,     0,     0,     0,     0,    90,
      91,     0,     0,     0,     0,    56,     0,     0,     0,     0,
       0,     0,     0,    57,    92,    93,    94,     0,     0,     0,
       0,     0,     0,     0,    95,   297,     0,     0,    57,    92,
      93,    94,    97,   316,     0,     0,    98,    99,     0,    95,
      50,    51,    52,    53,     0,    89,     0,    97,    54,     0,
       0,    98,    99,     0,     0,    50,    51,    52,    53,     0,
      89,     0,     0,    54,     0,     0,    55,     0,     0,     0,
       0,     0,     0,     0,    90,    91,     0,     0,     0,     0,
      56,    55,     0,     0,     0,     0,     0,     0,     0,    90,
      91,     0,     0,     0,     0,    56,     0,     0,     0,     0,
       0,     0,     0,    57,    92,    93,    94,     0,     0,     0,
       0,     0,     0,     0,    95,     0,     0,   331,    57,    92,
      93,    94,    97,   344,     0,     0,    98,    99,     0,    95,
      50,    51,    52,    53,     0,    89,     0,    97,    54,     0,
       0,    98,    99,     0,     0,    50,    51,    52,    53,     0,
      89,     0,     0,    54,     0,     0,    55,     0,     0,     0,
       0,     0,     0,     0,    90,    91,     0,     0,     0,     0,
      56,    55,     0,     0,     0,     0,     0,     0,     0,    90,
      91,     0,     0,     0,     0,    56,     0,     0,     0,     0,
       0,     0,     0,    57,    92,    93,    94,     0,     0,     0,
       0,     0,     0,     0,    95,   358,     0,     0,    57,    92,
      93,    94,    97,   361,     0,     0,    98,    99,     0,    95,
      50,    51,    52,    53,     0,    89,     0,    97,    54,     0,
       0,    98,    99,     0,     0,    50,    51,    52,    53,     0,
      89,     0,     0,    54,     0,     0,    55,     0,     0,     0,
       0,     0,     0,     0,    90,    91,     0,     0,     0,     0,
      56,    55,     0,     0,     0,     0,     0,     0,     0,    90,
      91,     0,     0,     0,     0,    56,     0,     0,     0,     0,
       0,     0,     0,    57,    92,    93,    94,     0,     0,     0,
       0,     0,     0,     0,    95,   369,     0,     0,    57,    92,
      93,    94,    97,     0,     0,     0,    98,    99,     0,    95,
     371,    50,    51,    52,    53,     0,    89,    97,     0,    54,
       0,    98,    99,     0,     0,     0,    50,    51,    52,    53,
       0,    89,     0,     0,    54,     0,     0,    55,     0,     0,
       0,     0,     0,     0,     0,    90,    91,     0,     0,     0,
       0,    56,    55,     0,     0,     0,     0,     0,     0,     0,
      90,    91,     0,     0,     0,     0,    56,     0,     0,     0,
       0,     0,     0,     0,    57,    92,    93,    94,     0,     0,
       0,     0,     0,     0,     0,    95,   381,     0,     0,    57,
      92,    93,    94,    97,     0,     0,     0,    98,    99,     0,
      95,    50,    51,    52,    53,     0,    89,     0,    97,    54,
       0,     0,    98,    99,     0,     0,    50,    51,    52,    53,
       0,    89,     0,     0,    54,     0,     0,    55,     0,     0,
       0,     0,     0,     0,     0,    90,    91,     0,     0,     0,
       0,    56,    55,     0,     0,     0,     0,     0,     0,     0,
      90,    91,     0,     0,     0,     0,    56,     0,     0,     0,
       0,     0,     0,     0,    57,    92,    93,    94,     0,     0,
       0,     0,     0,     0,     0,    58,     0,     0,     0,    57,
      92,    93,    94,    97,     0,     0,     0,    98,    99,     0,
     179,     0,     0,     0,    -2,     1,     0,     0,    97,     0,
       2,     0,    98,    99,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,    23,     2,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      24,    15,    16,    17,    18,    19,    20,    21,     0,     0,
       0,     0,     0,    25,     0,     0,     0,     0,    22,     0,
       0,    26,     2,     0,     0,    27,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,     0,    15,    16,
      17,    18,    19,    20,    21,     0,     0,     0,    25,     0,
       0,     0,     0,     0,     0,    22,   168,   261,   169,     0,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     0,    24,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    25,    15,    16,    17,    18,
      19,    20,    21,    26,     0,     0,     0,    27,     0,     0,
       0,     0,     0,    22,   269,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,     0,    15,    16,    17,
      18,    19,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    25,    22,     0,     0,     0,     0,     0,
       0,    26,     0,     0,     0,    27,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,     0,    15,    16,
      17,    18,    19,    20,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,    27,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,     0,    15,
      16,    17,    18,    19,    20,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    25,    22,     0,     0,     0,
       0,     0,     0,   273,   261,   169,     0,    27,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     0,
      15,    16,    17,    18,    19,    20,    21,     0,     0,    76,
       0,     0,   131,     0,     0,     0,     0,    22,    27,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
       0,    15,    16,    17,    18,    19,    20,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    22,     0,
      76,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,     0,    15,    16,    17,    18,    19,    20,    21,     3,
       4,     5,     6,     7,     8,     0,     0,   329,     0,    22,
      27,    15,    16,    17,    18,    19,    20,    21,     3,     4,
       5,     6,     7,     8,     0,     0,     0,     0,    22,     0,
      15,    16,    17,    18,    19,    20,    21,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     0,    22,     0,     0,
       0,    27,    15,    16,    17,    18,    19,    20,    21,     0,
       0,     0,   237,     0,     0,     0,     0,     0,     0,    22,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   309,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27
};

static const yytype_int16 yycheck[] =
{
      58,    45,    42,    46,    40,    26,   131,   171,   147,   137,
      74,    46,    33,   230,     6,    84,    80,    12,    13,    51,
       6,   142,     0,    14,    69,    70,     6,    25,   114,    29,
     169,     6,     6,    44,    70,    12,    13,    95,    49,   160,
      76,    95,    78,    88,    44,     6,    40,    77,    72,    79,
      82,    34,    35,    36,    89,    90,    91,    40,    79,    69,
      63,    64,    45,    84,     6,    70,     6,    77,    59,    79,
      25,    76,    71,   212,    69,    74,    70,    69,    74,   114,
      76,   135,   136,   208,    78,    77,    84,    70,   146,    69,
     215,    77,    74,    76,    69,    78,   132,    77,    72,    79,
     239,    76,    77,   228,   147,   230,   234,    62,    63,   130,
     274,    72,   147,   182,    78,   201,   202,   203,   139,   155,
      75,   179,   243,   340,    71,   179,   169,    74,   186,   268,
     251,   171,    73,    74,   169,    77,   257,    79,   132,    74,
      95,    74,    74,    78,    74,    78,    78,   168,    78,   132,
     185,   209,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   212,
     168,   126,   155,    71,   313,    71,    74,   212,    74,   134,
     135,   136,   137,    75,   182,   168,    72,   245,   246,    74,
     276,     6,   175,    78,   252,   253,   239,    78,    74,   320,
      47,    48,    78,    95,   239,    80,     3,     4,     5,     6,
      50,   336,    74,    74,    11,   340,    78,    78,    74,    77,
      83,    79,    78,   267,   179,   268,   347,    71,   349,   350,
      74,    84,    29,   268,     7,     8,    77,   358,    79,    86,
      87,   276,   134,   135,   136,   137,    43,   368,   369,    71,
     371,    74,    74,   374,    69,    78,    71,   378,   316,   380,
     381,    71,    77,    74,    74,    38,   387,    78,    85,    66,
     313,   193,   194,   195,   196,   273,    67,    68,   313,   234,
      77,    73,    74,    76,   267,   343,   344,   179,   346,    75,
     273,   312,   335,    73,    74,    77,   191,   192,   197,   198,
     335,    77,   360,   361,    77,    71,    79,    76,   199,   200,
      77,    71,    77,     6,    75,   373,     6,     6,    91,    78,
       6,    76,    42,    76,     3,     4,     5,     6,    71,     8,
      78,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,   234,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    78,    41,    42,    43,    80,    45,    78,    52,    53,
      54,    55,    77,    57,    58,    59,    60,    61,    62,    78,
      80,    46,     1,    71,   134,   130,    65,    66,    67,    68,
      69,    75,    71,    72,    73,   312,   117,   175,    77,    62,
     214,   155,    81,   187,   179,   188,    85,    23,   185,   190,
      89,    90,     3,     4,     5,     6,    -1,     8,   189,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      41,    42,    43,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    66,    67,    68,    69,    -1,
      71,    72,    73,    -1,    -1,    -1,    77,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    85,    -1,    -1,    -1,    89,    90,
       3,     4,     5,     6,    -1,     8,    -1,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    39,    -1,     6,    -1,
      43,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    66,    67,    68,    69,     3,     4,     5,
       6,    39,     8,    -1,    77,    11,    -1,    -1,    81,    -1,
      -1,    -1,    85,    -1,    -1,    -1,    89,    90,    -1,    -1,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    41,    42,    43,    -1,    45,
      78,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    -1,    -1,
      -1,    77,     3,     4,     5,     6,    -1,     8,    -1,    85,
      11,    -1,    -1,    89,    90,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      41,    42,    43,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    66,    67,    68,    69,    -1,
      71,    72,    73,    -1,    -1,    -1,    77,     3,     4,     5,
       6,    -1,     8,    -1,    85,    11,    -1,    -1,    89,    90,
      -1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      11,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    41,    42,    43,    29,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    67,    68,    69,    -1,    71,    72,    -1,    -1,    -1,
      -1,    77,    -1,    -1,    -1,    66,    67,    68,    69,    85,
      -1,    72,    73,    89,    90,    -1,    77,     3,     4,     5,
       6,    -1,     8,    -1,    85,    11,    -1,    -1,    89,    90,
      -1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      11,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    -1,    -1,    -1,    -1,    43,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    -1,    -1,    80,    66,    67,    68,    69,    85,
      -1,    72,    -1,    89,    90,    -1,    77,     3,     4,     5,
       6,    -1,     8,    -1,    85,    11,    -1,    -1,    89,    90,
      -1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      11,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    -1,    -1,    -1,    -1,    43,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    67,    68,    69,    -1,    71,    -1,    -1,    -1,    -1,
      -1,    77,    -1,    -1,    -1,    66,    67,    68,    69,    85,
      -1,    -1,    -1,    89,    90,    -1,    77,    -1,    -1,    80,
      -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    89,    90,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    11,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    11,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,
      43,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    78,    -1,    -1,    66,    67,
      68,    69,    85,    71,    -1,    -1,    89,    90,    -1,    77,
       3,     4,     5,     6,    -1,     8,    -1,    85,    11,    -1,
      -1,    89,    90,    -1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    11,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,
      43,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    -1,    -1,    80,    66,    67,
      68,    69,    85,    71,    -1,    -1,    89,    90,    -1,    77,
       3,     4,     5,     6,    -1,     8,    -1,    85,    11,    -1,
      -1,    89,    90,    -1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    11,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,
      43,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    78,    -1,    -1,    66,    67,
      68,    69,    85,    71,    -1,    -1,    89,    90,    -1,    77,
       3,     4,     5,     6,    -1,     8,    -1,    85,    11,    -1,
      -1,    89,    90,    -1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    11,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,
      43,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    78,    -1,    -1,    66,    67,
      68,    69,    85,    -1,    -1,    -1,    89,    90,    -1,    77,
      78,     3,     4,     5,     6,    -1,     8,    85,    -1,    11,
      -1,    89,    90,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    11,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,
      -1,    43,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    -1,    -1,    66,
      67,    68,    69,    85,    -1,    -1,    -1,    89,    90,    -1,
      77,     3,     4,     5,     6,    -1,     8,    -1,    85,    11,
      -1,    -1,    89,    90,    -1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    11,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,
      -1,    43,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    66,
      67,    68,    69,    85,    -1,    -1,    -1,    89,    90,    -1,
      77,    -1,    -1,    -1,     0,     1,    -1,    -1,    85,    -1,
       6,    -1,    89,    90,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,     6,    -1,    -1,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      56,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    39,    -1,
      -1,    77,     6,    -1,    -1,    81,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    77,    78,    79,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    56,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    69,    22,    23,    24,    25,
      26,    27,    28,    77,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    39,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    -1,    -1,    -1,    81,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    81,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    78,    79,    -1,    81,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    28,    -1,    -1,    72,
      -1,    -1,    75,    -1,    -1,    -1,    -1,    39,    81,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    28,    10,
      11,    12,    13,    14,    15,    -1,    -1,    78,    -1,    39,
      81,    22,    23,    24,    25,    26,    27,    28,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    39,    -1,
      22,    23,    24,    25,    26,    27,    28,    -1,    -1,    -1,
      10,    11,    12,    13,    14,    15,    -1,    39,    -1,    -1,
      -1,    81,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     6,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    39,    40,    56,    69,    77,    81,    93,    94,
      95,    96,    97,    99,   100,   101,   102,   103,   104,   112,
     115,   116,   117,   128,    94,    77,    79,     6,    72,    93,
       3,     4,     5,     6,    11,    29,    43,    66,    77,   156,
     158,   102,   117,   118,   115,     0,    95,    71,   106,   107,
     115,    99,    99,    99,     6,    72,    72,    97,    98,    99,
     132,   116,     6,    78,    99,   119,   120,   121,   122,     8,
      37,    38,    67,    68,    69,    77,    80,    85,    89,    90,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,    72,     6,   113,
     114,   137,   138,   140,   153,    93,   118,   102,    78,    71,
      74,    75,    98,   132,    72,   101,   102,   105,   108,   109,
       6,    11,    30,    31,    32,    33,    34,    35,    36,    41,
      42,    45,    65,    71,    73,    98,   129,   130,   131,   132,
     133,   134,   135,   136,   137,    97,   132,   115,    77,    79,
     115,   117,   126,   127,    78,    74,    74,    78,   153,    77,
     153,   153,   109,   125,    80,    51,    82,    50,    83,    84,
      85,    44,    49,    47,    48,    86,    87,    63,    64,    67,
      68,    69,    70,    88,   152,     7,     8,    38,    77,    79,
      91,   113,    75,    73,    74,    74,    78,    52,    53,    54,
      55,    57,    58,    59,    60,    61,    62,    75,   139,   107,
      72,   123,   138,   132,   105,   109,   109,    73,   108,    76,
     110,   111,   115,    76,   129,    77,    77,    71,    71,   137,
     141,    76,    77,    77,    71,     6,    73,   133,    73,   129,
      71,    78,   119,   126,    80,   141,   127,    77,    79,     9,
     121,     6,   125,    77,   117,   126,    78,   143,   137,   144,
     145,   146,   147,   148,   148,   149,   149,   149,   149,   150,
     150,   151,   151,   152,   152,   152,     6,    78,   138,   157,
     137,     6,    73,   141,   114,   138,   138,   123,   124,    73,
     141,    71,    74,    76,   129,    42,    71,   137,   137,    71,
      76,   129,   137,   137,    71,    73,    78,    78,    80,    78,
     119,    80,   141,    78,   152,    76,    74,    78,    80,    73,
      74,   111,   141,    77,    71,   137,    71,    78,   129,    78,
      78,    78,    80,   140,   138,    73,   123,   137,    78,   137,
      71,    71,   137,   129,   129,   129,    78,   129,    78,    78,
     137,    78,   137,    71,    46,    71,   129,   129,    78,   129,
      78,    78,   137,   129,   129,   129,   129,    78,   129
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
        case 6:

/* Line 1455 of yacc.c  */
#line 110 "bison.y"
    { yyerrok;;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 113 "bison.y"
    {insertarEnListaNoReconocido(&listaNoReconocido,(yyvsp[(1) - (1)].cadena),(yyvsp[(1) - (1)].INFO.linea));;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 119 "bison.y"
    {insertarEnListaFunciones(&listafunciones,(yyvsp[(2) - (4)].cadena),(yyvsp[(1) - (4)].cadena),(yyvsp[(1) - (4)].INFO.linea));;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 121 "bison.y"
    {insertarEnListaFunciones(&listafunciones,(yyvsp[(2) - (3)].cadena),(yyvsp[(1) - (3)].cadena),(yyvsp[(1) - (3)].INFO.linea));;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 124 "bison.y"
    { 
 if (strcmp(esVariable,"Variable")==0)
 {
 insertarEnListaVariables(&listavariables,nombre,tipo,(yyvsp[(1) - (3)].INFO.linea));
} 
else if (strcmp(esVariable,"Funcion")==0)
{
    insertarEnListaFunciones(&listafunciones,nombre,tipo,(yyvsp[(1) - (3)].INFO.linea));
}
 ;;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 153 "bison.y"
    {if(esElTipoDeLaFuncion(&listaParaVerificarSiEsNombreDeFuncion, (yyvsp[(1) - (1)].INFO.cadena), (yyvsp[(1) - (1)].INFO.linea))==1){strcpy(tipo,(yyvsp[(1) - (1)].INFO.cadena));};;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 154 "bison.y"
    {if(esElTipoDeLaFuncion(&listaParaVerificarSiEsNombreDeFuncion, (yyvsp[(1) - (1)].INFO.cadena), (yyvsp[(1) - (1)].INFO.linea))==1){strcpy(tipo,(yyvsp[(1) - (1)].INFO.cadena));};;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 155 "bison.y"
    {if(esElTipoDeLaFuncion(&listaParaVerificarSiEsNombreDeFuncion, (yyvsp[(1) - (1)].INFO.cadena), (yyvsp[(1) - (1)].INFO.linea))==1){strcpy(tipo,(yyvsp[(1) - (1)].INFO.cadena));};;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 156 "bison.y"
    {if(esElTipoDeLaFuncion(&listaParaVerificarSiEsNombreDeFuncion, (yyvsp[(1) - (1)].INFO.cadena), (yyvsp[(1) - (1)].INFO.linea))==1){strcpy(tipo,(yyvsp[(1) - (1)].INFO.cadena));};;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 157 "bison.y"
    {if(esElTipoDeLaFuncion(&listaParaVerificarSiEsNombreDeFuncion, (yyvsp[(1) - (1)].INFO.cadena), (yyvsp[(1) - (1)].INFO.linea))==1){strcpy(tipo,(yyvsp[(1) - (1)].INFO.cadena));};;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 158 "bison.y"
    {if(esElTipoDeLaFuncion(&listaParaVerificarSiEsNombreDeFuncion, (yyvsp[(1) - (1)].INFO.cadena), (yyvsp[(1) - (1)].INFO.linea))==1){strcpy(tipo,(yyvsp[(1) - (1)].INFO.cadena));};;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 159 "bison.y"
    {if(esElTipoDeLaFuncion(&listaParaVerificarSiEsNombreDeFuncion, (yyvsp[(1) - (1)].INFO.cadena), (yyvsp[(1) - (1)].INFO.linea))==1){strcpy(tipo,(yyvsp[(1) - (1)].INFO.cadena));};;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 160 "bison.y"
    {if(esElTipoDeLaFuncion(&listaParaVerificarSiEsNombreDeFuncion, (yyvsp[(1) - (1)].INFO.cadena), (yyvsp[(1) - (1)].INFO.linea))==1){strcpy(tipo,(yyvsp[(1) - (1)].INFO.cadena));};;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 161 "bison.y"
    {if(esElTipoDeLaFuncion(&listaParaVerificarSiEsNombreDeFuncion, (yyvsp[(1) - (1)].INFO.cadena), (yyvsp[(1) - (1)].INFO.linea))==1){strcpy(tipo,(yyvsp[(1) - (1)].INFO.cadena));};;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 173 "bison.y"
    {strcpy(esVariable,"Variable");strcpy(tipo,(yyvsp[(1) - (1)].INFO.cadena));;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 174 "bison.y"
    {strcpy(esVariable,"Variable");strcpy(tipo,(yyvsp[(1) - (1)].INFO.cadena));;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 212 "bison.y"
    {strcpy(esVariable,"Variable");strcpy(nombre,(yyvsp[(1) - (1)].INFO.cadena));;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 214 "bison.y"
    {strcpy(esVariable,"Variable");strcpy(nombre,(yyvsp[(1) - (4)].INFO.cadena));;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 215 "bison.y"
    {strcpy(esVariable,"Variable");strcpy(nombre,(yyvsp[(1) - (3)].INFO.cadena));;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 216 "bison.y"
    {strcpy(esVariable,"Funcion");strcpy(nombre,(yyvsp[(1) - (4)].INFO.cadena));;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 217 "bison.y"
    {strcpy(esVariable,"Funcion");strcpy(nombre,(yyvsp[(1) - (4)].INFO.cadena));;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 218 "bison.y"
    {strcpy(esVariable,"Funcion");strcpy(nombre,(yyvsp[(1) - (3)].INFO.cadena));;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 289 "bison.y"
    {insertarEnListaSentencias(&listaSentencias,(yyvsp[(1) - (5)].cadena),(yyvsp[(1) - (5)].INFO.linea));;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 290 "bison.y"
    {insertarEnListaSentencias(&listaSentencias,(yyvsp[(1) - (7)].cadena),(yyvsp[(1) - (7)].INFO.linea));;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 291 "bison.y"
    {insertarEnListaSentencias(&listaSentencias,(yyvsp[(1) - (5)].cadena),(yyvsp[(1) - (5)].INFO.linea));;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 293 "bison.y"
    {insertarEnListaSentencias(&listaSentencias,(yyvsp[(1) - (5)].cadena),(yyvsp[(1) - (5)].INFO.linea));;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 294 "bison.y"
    {insertarEnListaSentencias(&listaSentencias,(yyvsp[(1) - (7)].cadena),(yyvsp[(1) - (7)].INFO.linea));;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 295 "bison.y"
    {insertarEnListaSentencias(&listaSentencias,(yyvsp[(1) - (9)].cadena),(yyvsp[(1) - (9)].INFO.linea));;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 296 "bison.y"
    {insertarEnListaSentencias(&listaSentencias,(yyvsp[(1) - (8)].cadena),(yyvsp[(1) - (8)].INFO.linea));;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 297 "bison.y"
    {insertarEnListaSentencias(&listaSentencias,(yyvsp[(1) - (8)].cadena),(yyvsp[(1) - (8)].INFO.linea));;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 298 "bison.y"
    {insertarEnListaSentencias(&listaSentencias,(yyvsp[(1) - (7)].cadena),(yyvsp[(1) - (7)].INFO.linea));;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 299 "bison.y"
    {insertarEnListaSentencias(&listaSentencias,(yyvsp[(1) - (8)].cadena),(yyvsp[(1) - (8)].INFO.linea));;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 300 "bison.y"
    {insertarEnListaSentencias(&listaSentencias,(yyvsp[(1) - (7)].cadena),(yyvsp[(1) - (7)].INFO.linea));;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 301 "bison.y"
    {insertarEnListaSentencias(&listaSentencias,(yyvsp[(1) - (7)].cadena),(yyvsp[(1) - (7)].INFO.linea));;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 302 "bison.y"
    {insertarEnListaSentencias(&listaSentencias,(yyvsp[(1) - (6)].cadena),(yyvsp[(1) - (6)].INFO.linea));;}
    break;



/* Line 1455 of yacc.c  */
#line 2410 "bison.tab.c"
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
#line 414 "bison.y"



int main (int argc, char *argv[])
{
        FILE* reporte = fopen("reporte.txt","w+");
        yyin=fopen(argv[1],"r");
        yyparse();
        imprimirListaEnArchivo(reporte,listavariables,listaNoReconocido,listafunciones,listaSentencias);
        fclose(reporte);
        fclose(yyin);

        if(analisisCorrecto)
        printf("\nAnalisis finalizado correctamente\n");

        return 0;
}

int yyerror(const char *msg){
        printf("\nFallo el analisis en la linea: %d %s\n",yylineno,msg);
        analisisCorrecto=0;
        return 0;
}



void insertarEnListaVariables(NODOVARIABLES** lista, char *nombre,char*tipo, int linea)
{
 
     NODOVARIABLES *ptr = *lista;
     NODOVARIABLES *nuevo = (NODOVARIABLES *)malloc(sizeof(NODOVARIABLES));

    nuevo->nombre = strdup(nombre);
    nuevo->linea = linea;
    nuevo->tipo = strdup(tipo);

    if (*lista == NULL )
    {
        nuevo->sig = *lista;
        *lista = nuevo;
    }
    else
    {   
        
        while (ptr->sig != NULL )
        {
            ptr = ptr->sig;
        }

        nuevo->sig = ptr->sig;
        ptr->sig = nuevo;
    }
}


void insertarEnListaFunciones(NODOFUNCIONES** lista, char *nombre,char*tipo, int linea)
{
 
     NODOFUNCIONES *ptr = *lista;
     NODOFUNCIONES *nuevo = (NODOFUNCIONES *)malloc(sizeof(NODOFUNCIONES));

    nuevo->nombre = strdup(nombre);
    nuevo->linea = linea;
    nuevo->tipo = strdup(tipo);

    if (*lista == NULL )
    {
        nuevo->sig = *lista;
        *lista = nuevo;
    }
    else
    {   
        
        while (ptr->sig != NULL )
        {
            ptr = ptr->sig;
        }

        nuevo->sig = ptr->sig;
        ptr->sig = nuevo;
    }
}


void insertarEnListaSentencias(NODOSENTENCIAS** lista, char *tipoSentencia,int linea)
{
 
     NODOSENTENCIAS *ptr = *lista;
     NODOSENTENCIAS *nuevo = (NODOSENTENCIAS *)malloc(sizeof(NODOSENTENCIAS));

    nuevo->tipoSentencia = strdup(tipoSentencia);
    nuevo->linea = linea;

    if (*lista == NULL )
    {
        nuevo->sig = *lista;
        *lista = nuevo;
    }
    else
    {   
        
        while (ptr->sig != NULL )
        {
            ptr = ptr->sig;
        }

        nuevo->sig = ptr->sig;
        ptr->sig = nuevo;
    }
}



void insertarEnListaNoReconocido(NODONORECONOCIDO **lista, char *texto, int linea)
{
	NODONORECONOCIDO* actual=*lista;
	NODONORECONOCIDO* nuevo=(NODONORECONOCIDO*) malloc(sizeof(NODONORECONOCIDO));
	
	nuevo->texto=strdup(texto);
    nuevo->linea = linea;
	
    if(*lista==NULL)
	{
		nuevo->sig=*lista;
		*lista=nuevo;
	}
	
	else
	{
		while(actual->sig!=NULL)
		{
			actual=actual->sig;
		}
			
		nuevo->sig= actual->sig;
		actual->sig=nuevo;
	}
	
}


void insertarEnListaEstructurasNoValidas(NODOESTRUCTURASNOVALIDAS** lista, char *estructura,int linea)
{
 
     NODOESTRUCTURASNOVALIDAS *ptr = *lista;
     NODOESTRUCTURASNOVALIDAS *nuevo = (NODOESTRUCTURASNOVALIDAS *)malloc(sizeof(NODOESTRUCTURASNOVALIDAS));

    nuevo->estructura = strdup(estructura);
    nuevo->linea = linea;

    if (*lista == NULL )
    {
        nuevo->sig = *lista;
        *lista = nuevo;
    }
    else
    {   
        
        while (ptr->sig != NULL )
        {
            ptr = ptr->sig;
        }

        nuevo->sig = ptr->sig;
        ptr->sig = nuevo;
    }
}

////////////////////IMPRIMIR LISTAS EN EL ARCHIVO////////////////////
void imprimirListaEnArchivo(FILE* archivo,NODOVARIABLES* listavariables,NODONORECONOCIDO *listaNoReconocido,NODOFUNCIONES* listafunciones,NODOSENTENCIAS* listaSentencias)
{
    
	fprintf(archivo,"\n________________________________________________________________________________________\n\n");
	
    //Imprimo Lista de Variables
    fprintf(archivo,"Listado de Variables:\n\n");
    while(listavariables!=NULL)
	{
        NODOVARIABLES *ptr=listavariables;
        listavariables=listavariables->sig;
        fprintf(archivo,"Linea: %i  ", ptr->linea);
        if(ptr->linea < 10) //Para alinear la lista
	    {
		    fprintf(archivo," ");
        }
		fprintf(archivo,"Identificador: %s",ptr->nombre);
        for(int i=0;i<(10-strlen(ptr->nombre));i++) //Para alinear la lista
	    {
		    fprintf(archivo," ");
        }
        fprintf(archivo,";  Tipo: %s  \n",ptr->tipo);
		free(ptr);
	}
    
    fprintf(archivo,"________________________________________________________________________________________\n\n");

    fprintf(archivo,"Listado de Funciones:\n\n");
    while(listafunciones!=NULL)
	{
        NODOFUNCIONES *ptr=listafunciones;
        listafunciones=listafunciones->sig;
        fprintf(archivo,"Linea: %i  ", ptr->linea);
		fprintf(archivo,"Funcion: %s",ptr->nombre);
        for(int i=0;i<(15-strlen(ptr->nombre));i++) //Para alinear la lista
	    {
		    fprintf(archivo," ");
        }
        fprintf(archivo,";  Tipo: %s\n",ptr->tipo);
		free(ptr);
	}
    
    fprintf(archivo,"________________________________________________________________________________________\n\n");

    fprintf(archivo,"Listado de secuencias que no pertenecen a ninguna categoria lexica:\n\n");
    fprintf(archivo,"Nro. de linea\t\tCadena/Caracter\n");
    while(listaNoReconocido!=NULL)
	{
        NODONORECONOCIDO *ptr=listaNoReconocido;
        listaNoReconocido=listaNoReconocido->sig;
		fprintf(archivo,"\t%i\t\t\t\t      %s\n",ptr->linea,ptr->texto);
		free(ptr);
	}

    fprintf(archivo,"________________________________________________________________________________________\n\n");

    fprintf(archivo,"Listado de Sentencias:\n\n");
    while(listaSentencias!=NULL)
	{
        NODOSENTENCIAS *ptr=listaSentencias;
        listaSentencias=listaSentencias->sig;
        fprintf(archivo,"Linea: %i  ", ptr->linea);
		fprintf(archivo,"Sentencia: %s \n",ptr->tipoSentencia);
		free(ptr);
	}

}


int esElTipoDeLaFuncion(NODOTIPOS **lista, char *tipoEntrante, int lineaEntrante)
{
  NODOTIPOS *ptr = *lista;
  NODOTIPOS *nuevo = (NODOTIPOS *)malloc(sizeof(NODOTIPOS));

    nuevo->linea = lineaEntrante;
    nuevo->tipo = strdup(tipoEntrante);

    if (*lista == NULL )
    {
        nuevo->sig = *lista;
        *lista = nuevo;
        return 1;
    }
    else
    {   
        while (  (ptr->linea!=lineaEntrante) && ptr->sig != NULL)    
        {
            
            ptr = ptr->sig;
        }
        if(ptr->linea==lineaEntrante){ //si es el primer tipo que se encuentra en esa linea, es porque es el tipo de la funcion
          nuevo->sig = *lista;
         *lista = nuevo;
           return 0;
           
        } 

        if(ptr->sig==NULL){ //si es el primer tipo que se encuentra en esa linea, es porque es el tipo de la funcion
          nuevo->sig = *lista;
         *lista = nuevo;
           return 1;
           
        } 
        

    
    }
}



