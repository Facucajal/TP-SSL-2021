
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
char nombreDeFuncion[30];
char tipo[30];
char tipoFuncion[30];
char tipoVariableFuncion[30];
char nombreVariableFuncion[30];
char esVariable[30];
char nombre[30];
int estoyDerivandoParametrosDeLaFuncion=0;
char nombreDeFuncionInvocada[30];
int estoyDerivandoIdentificadoresInvocados=0;




NODOVARIABLES* listavariables = NULL;
NODOVARIABLES* listaDobleDeclaracion = NULL;
NODOFUNCIONES* listafunciones = NULL;
NODONORECONOCIDO* listaNoReconocido=NULL;
NODOSENTENCIAS* listaSentencias=NULL;
NODOTIPOS* listaParaVerificarSiEsNombreDeFuncion = NULL;
NODOFUNCIONES* listaFuncionesYParametros = NULL;
NODOVARIABLES* listaerrordetipos = NULL;
NODONODECLARADOS* listaNoDeclarados = NULL;
NODOPARAMETROS* listaParametros = NULL;
NODOERRORDETIPOSDEFUNCION* listaErroresSemanticosDeTipos=NULL;
NODOERRORFALTADETIPOS* listaErroresSemanticosDeCantidadDeTipos=NULL;
NODOSOBRADETIPOS* listaErroresSemanticosDeSobraDeTipos=NULL;
NODOERRORESSINTACTICOS* listaErroresSintacticos=NULL;


/* Line 189 of yacc.c  */
#line 116 "bison.tab.c"

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
#line 44 "bison.y"

   char cadena[30];
   int entero;
   float real;
   char cadena2[30];
   struct info{
       char cadena[30];
       int linea;
   }INFO;



/* Line 214 of yacc.c  */
#line 231 "bison.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 243 "bison.tab.c"

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
#define YYLAST   1998

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  92
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  70
/* YYNRULES -- Number of rules.  */
#define YYNRULES  235
/* YYNRULES -- Number of states.  */
#define YYNSTATES  392

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
      22,    25,    27,    29,    34,    38,    42,    45,    49,    52,
      54,    57,    60,    62,    65,    67,    70,    72,    74,    76,
      78,    80,    82,    84,    86,    88,    90,    92,    94,    96,
      98,   100,   102,   104,   106,   108,   110,   116,   121,   124,
     126,   128,   130,   133,   135,   139,   141,   145,   149,   152,
     154,   157,   159,   161,   165,   167,   171,   174,   180,   185,
     188,   190,   194,   196,   200,   203,   205,   207,   211,   216,
     220,   221,   227,   228,   234,   238,   241,   245,   248,   250,
     252,   255,   257,   261,   263,   267,   270,   273,   275,   277,
     278,   283,   285,   289,   294,   296,   300,   303,   305,   307,
     310,   312,   316,   321,   325,   329,   332,   337,   341,   345,
     348,   350,   352,   354,   356,   358,   360,   362,   366,   371,
     375,   378,   380,   385,   389,   393,   396,   398,   401,   407,
     415,   421,   427,   435,   445,   454,   463,   471,   480,   488,
     496,   503,   507,   510,   513,   517,   520,   522,   526,   528,
     532,   534,   536,   538,   540,   542,   544,   546,   548,   550,
     552,   554,   556,   562,   564,   566,   570,   572,   576,   578,
     582,   584,   588,   590,   594,   596,   600,   604,   606,   610,
     614,   618,   622,   624,   628,   632,   634,   638,   642,   644,
     648,   652,   656,   658,   663,   665,   668,   671,   674,   677,
     682,   684,   686,   688,   690,   692,   694,   696,   701,   706,
     710,   714,   718,   721,   724,   726,   728,   730,   734,   736,
     740,   742,   744,   746,   748,   750
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      93,     0,    -1,    -1,    21,    93,    -1,    40,   159,    93,
      -1,    94,    -1,     1,    94,    -1,     1,    -1,    95,    -1,
      56,    -1,    94,    95,    -1,    96,    -1,    97,    -1,    99,
     115,    98,   135,    -1,   115,    98,   135,    -1,    99,   115,
     135,    -1,   115,   135,    -1,    99,   106,    71,    -1,    99,
      71,    -1,    97,    -1,    98,    97,    -1,   100,    99,    -1,
     100,    -1,   101,    99,    -1,   101,    -1,   102,    99,    -1,
     102,    -1,    20,    -1,    19,    -1,    18,    -1,    17,    -1,
      16,    -1,    27,    -1,    28,    -1,    26,    -1,    22,    -1,
      23,    -1,    25,    -1,    24,    -1,    15,    -1,    14,    -1,
     103,    -1,   112,    -1,   131,    -1,    13,    -1,    12,    -1,
     104,     6,    72,   105,    73,    -1,   104,    72,   105,    73,
      -1,   104,     6,    -1,    39,    -1,    10,    -1,   108,    -1,
     105,   108,    -1,   107,    -1,   106,    74,   107,    -1,   115,
      -1,   115,    75,   126,    -1,   109,   110,    71,    -1,   101,
     109,    -1,   101,    -1,   102,   109,    -1,   102,    -1,   111,
      -1,   110,    74,   111,    -1,   115,    -1,   115,    76,   144,
      -1,    76,   144,    -1,    11,     6,    72,   113,    73,    -1,
      11,    72,   113,    73,    -1,    11,     6,    -1,   114,    -1,
     113,    74,   114,    -1,     6,    -1,     6,    75,   144,    -1,
     119,   116,    -1,   116,    -1,     6,    -1,    77,   115,    78,
      -1,     6,    79,   144,    80,    -1,     6,    79,    80,    -1,
      -1,     6,    77,   117,   121,    78,    -1,    -1,     6,    77,
     118,   124,    78,    -1,     6,    77,    78,    -1,    69,   120,
      -1,    69,   119,   120,    -1,    69,   119,    -1,    69,    -1,
     102,    -1,   120,   102,    -1,   122,    -1,   122,    74,     9,
      -1,   123,    -1,   122,    74,   123,    -1,    99,   115,    -1,
      99,   129,    -1,    99,    -1,     6,    -1,    -1,     6,   125,
      74,   124,    -1,   141,    -1,    72,   127,    73,    -1,    72,
     127,    74,    73,    -1,   126,    -1,   127,    74,   126,    -1,
     109,   129,    -1,   109,    -1,   119,    -1,   119,   130,    -1,
     130,    -1,    77,   129,    78,    -1,   130,    79,   144,    80,
      -1,    79,   144,    80,    -1,   130,    79,    80,    -1,    79,
      80,    -1,   130,    77,   121,    78,    -1,    77,   121,    78,
      -1,   130,    77,    78,    -1,    77,    78,    -1,    81,    -1,
     133,    -1,   134,    -1,   135,    -1,   137,    -1,   138,    -1,
     139,    -1,     6,    76,   132,    -1,    35,   144,    76,   132,
      -1,    36,    76,   132,    -1,   140,    71,    -1,    71,    -1,
      72,    98,   136,    73,    -1,    72,   136,    73,    -1,    72,
      98,    73,    -1,    72,    73,    -1,   132,    -1,   136,   132,
      -1,    41,    77,   140,    78,   132,    -1,    41,    77,   140,
      78,   132,    46,   132,    -1,    32,    77,   140,    78,   132,
      -1,    42,    77,   140,    78,   132,    -1,    30,   132,    42,
      77,   140,    78,    71,    -1,    31,    77,   140,    71,   140,
      71,   140,    78,   132,    -1,    31,    77,   140,    71,   140,
      71,    78,   132,    -1,    31,    77,   140,    71,    71,   140,
      78,   132,    -1,    31,    77,   140,    71,    71,    78,   132,
      -1,    31,    77,    71,   140,    71,   140,    78,   132,    -1,
      31,    77,    71,   140,    71,    78,   132,    -1,    31,    77,
      71,    71,   140,    78,   132,    -1,    31,    77,    71,    71,
      78,   132,    -1,    65,     6,    71,    -1,    33,    71,    -1,
      45,    71,    -1,    34,   140,    71,    -1,    34,    71,    -1,
     141,    -1,   140,    74,   141,    -1,   143,    -1,   156,   142,
     141,    -1,    54,    -1,    55,    -1,    52,    -1,    53,    -1,
      57,    -1,    58,    -1,    59,    -1,    60,    -1,    61,    -1,
      62,    -1,    75,    -1,   145,    -1,   145,    82,   140,    76,
     143,    -1,   143,    -1,   146,    -1,   145,    51,   146,    -1,
     147,    -1,   146,    50,   147,    -1,   148,    -1,   147,    83,
     148,    -1,   149,    -1,   148,    84,   149,    -1,   150,    -1,
     149,    85,   150,    -1,   151,    -1,   150,    49,   151,    -1,
     150,    44,   151,    -1,   152,    -1,   151,    86,   152,    -1,
     151,    87,   152,    -1,   151,    48,   152,    -1,   151,    47,
     152,    -1,   153,    -1,   152,    64,   153,    -1,   152,    63,
     153,    -1,   154,    -1,   153,    67,   154,    -1,   153,    68,
     154,    -1,   155,    -1,   154,    69,   155,    -1,   154,    70,
     155,    -1,   154,    88,   155,    -1,   156,    -1,    77,   128,
      78,   155,    -1,   158,    -1,    38,   156,    -1,     8,   156,
      -1,   157,   155,    -1,    37,   156,    -1,    37,    77,   128,
      78,    -1,    85,    -1,    69,    -1,    67,    -1,    68,    -1,
      89,    -1,    90,    -1,   159,    -1,   158,    79,   140,    80,
      -1,   158,    77,   160,    78,    -1,   158,    77,    78,    -1,
     158,    91,     6,    -1,   158,     7,     6,    -1,   158,    38,
      -1,   158,     8,    -1,     6,    -1,   161,    -1,    43,    -1,
      77,   140,    78,    -1,   141,    -1,   160,    74,   141,    -1,
       3,    -1,     4,    -1,    29,    -1,     5,    -1,    66,    -1,
      11,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   121,   121,   122,   123,   124,   125,   126,   128,   129,
     130,   132,   133,   135,   136,   137,   138,   140,   142,   144,
     145,   147,   148,   149,   150,   151,   152,   154,   155,   156,
     157,   158,   160,   168,   175,   182,   189,   196,   203,   210,
     217,   224,   225,   226,   228,   229,   231,   232,   233,   235,
     242,   250,   251,   253,   254,   256,   257,   259,   261,   262,
     263,   264,   266,   267,   269,   270,   271,   273,   274,   275,
     277,   278,   280,   281,   283,   284,   286,   295,   296,   297,
     298,   298,   302,   302,   305,   308,   309,   310,   311,   313,
     314,   316,   317,   319,   320,   322,   323,   324,   326,   334,
     334,   339,   340,   341,   343,   344,   346,   347,   349,   350,
     351,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     363,   365,   366,   367,   368,   369,   370,   372,   373,   374,
     376,   377,   379,   380,   381,   382,   384,   385,   387,   388,
     389,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   402,   403,   404,   405,   406,   408,   409,   411,   412,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   426,   427,   429,   431,   432,   434,   435,   437,   438,
     440,   441,   443,   444,   446,   447,   448,   450,   451,   452,
     453,   454,   456,   457,   458,   460,   461,   481,   483,   484,
     485,   486,   488,   489,   491,   492,   493,   494,   499,   500,
     502,   503,   504,   505,   506,   507,   509,   510,   511,   512,
     513,   514,   515,   516,   518,   519,   520,   521,   523,   524,
     526,   527,   528,   529,   530,   531
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
  "enumerador", "declarador", "declarador_directo", "$@1", "$@2",
  "apuntador", "lista_calificadores_de_tipo", "lista_tipos_de_parametro",
  "lista_de_parametros", "declaracion_de_parametro",
  "lista_de_identificadores", "$@3", "inicializador",
  "lista_de_inicializadores", "nombre_de_tipo", "declarador_abstracto",
  "declarador_abstracto_directo", "nombre_typedef", "sentencia",
  "sentencia_etiquetada", "sentencia_expresion", "sentencia_compuesta",
  "lista_de_sentencias", "sentencia_de_seleccion",
  "sentencia_de_iteracion", "sentencia_de_salto", "expresion",
  "expresion_de_asignacion", "operador_de_asignacion",
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
       0,    92,    93,    93,    93,    93,    93,    93,    94,    94,
      94,    95,    95,    96,    96,    96,    96,    97,    97,    98,
      98,    99,    99,    99,    99,    99,    99,   100,   100,   100,
     100,   100,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   102,   102,   103,   103,   103,   104,
     104,   105,   105,   106,   106,   107,   107,   108,   109,   109,
     109,   109,   110,   110,   111,   111,   111,   112,   112,   112,
     113,   113,   114,   114,   115,   115,   116,   116,   116,   116,
     117,   116,   118,   116,   116,   119,   119,   119,   119,   120,
     120,   121,   121,   122,   122,   123,   123,   123,   124,   125,
     124,   126,   126,   126,   127,   127,   128,   128,   129,   129,
     129,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     131,   132,   132,   132,   132,   132,   132,   133,   133,   133,
     134,   134,   135,   135,   135,   135,   136,   136,   137,   137,
     137,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   139,   139,   139,   139,   139,   140,   140,   141,   141,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   143,   143,   144,   145,   145,   146,   146,   147,   147,
     148,   148,   149,   149,   150,   150,   150,   151,   151,   151,
     151,   151,   152,   152,   152,   153,   153,   153,   154,   154,
     154,   154,   155,   155,   156,   156,   156,   156,   156,   156,
     157,   157,   157,   157,   157,   157,   158,   158,   158,   158,
     158,   158,   158,   158,   159,   159,   159,   159,   160,   160,
     161,   161,   161,   161,   161,   161
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     3,     1,     2,     1,     1,     1,
       2,     1,     1,     4,     3,     3,     2,     3,     2,     1,
       2,     2,     1,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     4,     2,     1,
       1,     1,     2,     1,     3,     1,     3,     3,     2,     1,
       2,     1,     1,     3,     1,     3,     2,     5,     4,     2,
       1,     3,     1,     3,     2,     1,     1,     3,     4,     3,
       0,     5,     0,     5,     3,     2,     3,     2,     1,     1,
       2,     1,     3,     1,     3,     2,     2,     1,     1,     0,
       4,     1,     3,     4,     1,     3,     2,     1,     1,     2,
       1,     3,     4,     3,     3,     2,     4,     3,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     3,     4,     3,
       2,     1,     4,     3,     3,     2,     1,     2,     5,     7,
       5,     5,     7,     9,     8,     8,     7,     8,     7,     7,
       6,     3,     2,     2,     3,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     1,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     4,     1,     2,     2,     2,     2,     4,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     3,
       3,     3,     2,     2,     1,     1,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     7,    76,    50,     0,    45,    44,    40,    39,    31,
      30,    29,    28,    27,     0,    35,    36,    38,    37,    34,
      32,    33,    49,     0,     9,    88,     0,   120,     0,     5,
       8,    11,    12,     0,    22,    24,    26,    41,     0,    42,
       0,    75,     0,    43,     6,    80,     0,    69,     0,     3,
     230,   231,   233,   224,   235,   232,   226,   234,     0,     0,
     225,    89,    87,    85,     0,     1,    10,    18,     0,    53,
      55,    21,    23,    25,    48,     0,     0,    19,     0,     0,
      16,    74,    84,     0,     0,     0,     0,     0,   212,   213,
     211,     0,    79,   210,   214,   215,   173,     0,   171,   174,
     176,   178,   180,   182,   184,   187,   192,   195,   198,   202,
       0,   204,   216,     0,    72,     0,    70,     0,   156,   158,
     202,     4,    86,    90,    77,    17,     0,     0,     0,    15,
       0,    59,    61,     0,    51,     0,   224,   235,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   131,
     135,     0,   136,   121,   122,   123,     0,   124,   125,   126,
       0,    20,    14,    55,    97,     0,    91,    93,    98,     0,
     206,     0,   208,   205,   107,     0,    78,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   207,     0,   223,   222,
       0,     0,     0,     0,     0,    68,     0,     0,   227,   162,
     163,   160,   161,   164,   165,   166,   167,   168,   169,   170,
       0,    54,     0,    56,   101,    13,     0,    58,    60,    47,
      52,     0,     0,    62,    64,     0,     0,     0,     0,   152,
     155,     0,     0,     0,     0,     0,   153,     0,   134,     0,
     133,   137,   130,     0,     0,    95,   108,    96,   110,    81,
       0,     0,    83,     0,     0,   108,   106,     0,   175,     0,
     177,   179,   181,   183,   186,   185,   191,   190,   188,   189,
     194,   193,   196,   197,   199,   200,   201,   221,   219,   228,
       0,     0,   220,    67,    73,    71,   157,   159,   104,     0,
      46,    66,    57,     0,     0,   127,     0,     0,     0,     0,
     154,     0,   129,     0,     0,   151,   132,   119,     0,     0,
     115,     0,   109,     0,     0,    92,    94,     0,   209,   203,
       0,     0,   218,   217,   102,     0,    63,    65,     0,     0,
       0,     0,     0,   128,     0,     0,   117,   111,   113,   118,
       0,   114,     0,   100,   172,   229,   103,   105,     0,     0,
       0,     0,     0,     0,   140,   138,   141,   116,   112,     0,
     150,     0,     0,     0,     0,     0,     0,     0,   142,   149,
     148,     0,   146,     0,     0,     0,   139,   147,   145,   144,
       0,   143
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    28,    29,    30,    31,    32,    78,    33,    34,    35,
      36,    37,    38,   133,    68,    69,   134,   135,   232,   233,
      39,   115,   116,    40,    41,    83,    84,    42,    63,   318,
     166,   167,   169,   261,   223,   299,   175,   319,   258,    43,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   118,
     220,   119,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   120,   110,   111,   112,   290,    60
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -212
static const yytype_int16 yypact[] =
{
    1566,  1638,    65,  -212,     7,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,  -212,  -212,  1566,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,  -212,   186,  -212,     3,    13,  -212,    44,  1686,
    -212,  -212,  -212,    69,  1868,  1868,  1868,  -212,    36,  -212,
    1795,  -212,    28,  -212,  1686,    11,   812,   -36,    43,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  1395,  1566,
    -212,  -212,   164,   164,   -26,  -212,  -212,  -212,    -5,  -212,
    1765,  -212,  -212,  -212,     5,   299,   329,  -212,  1795,    69,
    -212,  -212,  -212,  1868,    74,  1470,  1485,  1470,  -212,  -212,
    -212,   505,  -212,  -212,  -212,  -212,  -212,    14,   -22,    72,
      29,    46,    42,    52,   -16,   215,   217,   -30,  -212,  -212,
    1395,    91,  -212,    43,    94,   221,  -212,   -56,  -212,  -212,
     324,  -212,   164,  -212,  -212,  -212,    13,   827,  1795,  -212,
     299,   299,   299,  1887,  -212,   189,   138,     7,   722,   170,
     177,   148,   902,  1395,   160,   205,   209,   153,   256,  -212,
    -212,   417,  -212,  -212,  -212,  -212,   572,  -212,  -212,  -212,
     142,  -212,  -212,   213,    56,   230,   241,  -212,   245,   258,
    -212,   505,  -212,  -212,    62,   272,  -212,  1395,  1395,  1395,
    1395,  1395,  1395,  1395,  1395,  1395,  1395,  1395,  1395,  1395,
    1395,  1395,  1395,  1395,  1395,  1395,  -212,   285,  -212,  -212,
     917,  1395,   367,   223,  1395,  -212,    43,  1395,  -212,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
    1395,  -212,   827,  -212,  -212,  -212,  1917,  -212,  -212,  -212,
    -212,  1395,   159,  -212,   311,   722,   333,   993,  1395,  -212,
    -212,   163,   312,   722,  1395,  1395,  -212,   318,  -212,   647,
    -212,  -212,  -212,  1601,  1008,  -212,    57,  -212,   106,  -212,
     540,   316,  -212,   313,  1717,   197,  -212,  1395,    72,   201,
      29,    46,    42,    52,   -16,   -16,   215,   215,   215,   215,
     217,   217,   -30,   -30,  -212,  -212,  -212,  -212,  -212,  -212,
      97,    41,  -212,  -212,  -212,  -212,  -212,  -212,  -212,   226,
    -212,  -212,  -212,   189,  1395,  -212,   315,  1096,   169,   110,
    -212,   722,  -212,   122,   124,  -212,  -212,  -212,   325,   326,
    -212,   327,   106,  1838,  1111,  -212,  -212,    74,  -212,  -212,
    1395,  1395,  -212,  -212,  -212,   737,  -212,  -212,  1395,  1199,
     171,  1214,   722,  -212,   722,   722,  -212,  -212,  -212,  -212,
     330,  -212,   331,  -212,  -212,  -212,  -212,  -212,   127,   722,
     129,  1289,  1304,   185,  -212,   347,  -212,  -212,  -212,   334,
    -212,   722,   722,   130,   722,   132,  1380,   722,  -212,  -212,
    -212,   722,  -212,   722,   722,   147,  -212,  -212,  -212,  -212,
     722,  -212
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -212,     6,   408,    32,  -212,   -19,   -29,   -33,  -212,   -45,
     198,  -212,  -212,   282,  -212,   287,  -123,   -64,  -212,   112,
    -212,   303,   211,     2,   -38,  -212,  -212,     0,   364,   -77,
    -212,   178,   134,  -212,  -211,  -212,   286,  -126,  -182,  -212,
    -133,  -212,  -212,   -14,   314,  -212,  -212,  -212,   -58,  -103,
    -212,   -37,  -131,  -212,   289,   284,   288,   283,   290,   118,
      83,   117,   125,  -102,   -32,  -212,  -212,   444,  -212,  -212
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -100
static const yytype_int16 yytable[] =
{
     117,    71,    72,    73,    81,   236,   165,    79,   196,    96,
     230,   298,   242,    47,   109,     5,     6,   -82,   207,     2,
      49,    77,   208,   251,   224,    62,    80,   174,    64,   177,
     131,   185,   186,   117,     2,    70,   113,    79,   257,   193,
     194,   128,    74,    79,    65,    79,   131,   151,   266,   114,
     164,    77,   124,   170,   172,   173,   129,    77,   195,   161,
     178,    66,     2,     2,   162,   121,   125,   227,   228,   126,
     187,   188,    25,   294,   322,     2,    66,   130,   109,    48,
     168,   163,    25,   322,   241,   131,   131,   131,   131,    82,
      26,   284,   285,   286,   176,    79,   183,   289,   197,   198,
     301,   184,   305,   230,   296,    26,    96,   174,    75,   161,
     312,   109,   180,   117,   225,   207,   251,   297,    79,   224,
     269,   333,   179,   321,   357,    25,   131,   182,   163,   199,
     181,    25,   161,   253,   253,   254,   254,   234,    25,   264,
      67,   254,    45,   291,    46,   109,    26,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   256,   329,   255,    96,   200,   204,
     201,   331,   109,   337,   265,   332,     5,     6,   343,   308,
     309,   131,   202,   323,   207,   324,   313,   314,   342,    50,
      51,    52,    53,   352,    96,     2,   207,    54,   207,   109,
     344,   207,   345,   207,   207,   369,   207,   371,   381,   364,
     383,   365,   366,   252,   235,    55,   207,    96,    81,   239,
     164,   207,   109,    61,   246,   390,   370,   164,   355,    56,
     302,   164,   224,   303,   310,   109,   243,   207,   379,   380,
     341,   382,   361,   207,   386,   207,   350,   237,   387,   340,
     388,   389,    57,   256,   238,    64,   376,   391,    25,   207,
      61,   123,   247,    58,   265,   231,    26,    96,   276,   277,
     278,   279,   109,   132,   264,   207,   254,   330,   189,   190,
     358,   360,   244,   363,   191,   192,   245,    96,   127,   132,
     164,   287,   109,   354,   205,   206,   293,   206,   109,   334,
     335,   274,   275,   373,   375,   234,   280,   281,   259,     3,
       4,     5,     6,     7,     8,   260,   282,   283,   385,   -99,
     123,    15,    16,    17,    18,    19,    20,    21,   132,   132,
     132,   132,    50,    51,    52,   136,   262,    85,    22,     3,
     137,     5,     6,     7,     8,     9,    10,    11,    12,    13,
     267,    15,    16,    17,    18,    19,    20,    21,    55,   138,
     139,   140,   141,   142,   143,   144,    86,    87,    22,   132,
     145,   146,    56,   292,   147,   306,   209,   210,   211,   212,
      27,   213,   214,   215,   216,   217,   218,   304,   311,   315,
     327,   328,   338,   377,   148,    57,    88,    89,    90,   219,
     149,    76,   150,   346,   347,   378,    91,   348,   367,    44,
      27,   368,   226,   221,    93,   336,   203,   295,    94,    95,
      50,    51,    52,   136,   132,    85,   122,     3,   137,     5,
       6,     7,     8,     9,    10,    11,    12,    13,   326,    15,
      16,    17,    18,    19,    20,    21,    55,   138,   139,   140,
     141,   142,   143,   144,    86,    87,    22,   263,   145,   146,
      56,   353,   147,   270,   272,   249,   268,    59,   271,     0,
       0,     0,   273,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   148,    57,    88,    89,    90,     0,   149,    76,
     248,     0,     0,     0,    91,     0,     0,     0,    27,     0,
       0,     0,    93,     0,     0,     0,    94,    95,    50,    51,
      52,    53,     0,    85,     0,     3,   137,     5,     6,     7,
       8,     0,     0,     0,     0,     0,     0,    15,    16,    17,
      18,    19,    20,    21,    55,     0,     0,     0,     0,     0,
       0,     0,    86,    87,    22,     0,     0,     0,    56,   325,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,     0,    15,    16,    17,    18,    19,    20,    21,     0,
       0,    57,    88,    89,    90,    50,    51,    52,   136,    22,
      85,     0,    91,    54,     0,     0,    27,     0,     0,     0,
      93,     0,     0,     0,    94,    95,     0,     0,     0,     0,
       0,    55,   138,   139,   140,   141,   142,   143,   144,    86,
      87,     0,     0,   145,   146,    56,     0,   147,     0,     0,
       0,    27,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   148,    57,    88,
      89,    90,     0,   149,    76,   250,     0,     0,     0,    91,
      50,    51,    52,   136,     0,    85,     0,    93,    54,     0,
       0,    94,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    55,   138,   139,   140,
     141,   142,   143,   144,    86,    87,     0,     0,   145,   146,
      56,     0,   147,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   148,    57,    88,    89,    90,     0,   149,    76,
     316,     0,     0,     0,    91,    50,    51,    52,   136,     0,
      85,     0,    93,    54,     0,     0,    94,    95,     0,     0,
      50,    51,    52,    53,     0,    85,     0,     0,    54,     0,
       0,    55,   138,   139,   140,   141,   142,   143,   144,    86,
      87,     0,     0,   145,   146,    56,    55,   147,     0,     0,
       0,     0,     0,     0,    86,    87,     0,     0,     0,     0,
      56,     0,     0,     0,     0,     0,     0,   148,    57,    88,
      89,    90,     0,   149,    76,     0,     0,     0,     0,    91,
       0,     0,     0,    57,    88,    89,    90,    93,     0,   222,
     356,    94,    95,     0,    91,    50,    51,    52,    53,     0,
      85,     0,    93,    54,     0,     0,    94,    95,     0,     0,
      50,    51,    52,    53,     0,    85,     0,     0,    54,     0,
       0,    55,     0,     0,     0,     0,     0,     0,     0,    86,
      87,     0,     0,     0,     0,    56,    55,     0,     0,     0,
       0,     0,     0,     0,    86,    87,     0,     0,     0,     0,
      56,     0,     0,     0,     0,     0,     0,     0,    57,    88,
      89,    90,     0,     0,     0,     0,     0,     0,     0,    91,
       0,     0,    92,    57,    88,    89,    90,    93,     0,   222,
       0,    94,    95,     0,    91,    50,    51,    52,    53,     0,
      85,     0,    93,    54,     0,     0,    94,    95,     0,     0,
      50,    51,    52,    53,     0,    85,     0,     0,    54,     0,
       0,    55,     0,     0,     0,     0,     0,     0,     0,    86,
      87,     0,     0,     0,     0,    56,    55,     0,     0,     0,
       0,     0,     0,     0,    86,    87,     0,     0,     0,     0,
      56,     0,     0,     0,     0,     0,     0,     0,    57,    88,
      89,    90,     0,   240,     0,     0,     0,     0,     0,    91,
       0,     0,     0,    57,    88,    89,    90,    93,     0,     0,
       0,    94,    95,     0,    91,   288,    50,    51,    52,    53,
       0,    85,    93,     0,    54,     0,    94,    95,     0,     0,
       0,    50,    51,    52,    53,     0,    85,     0,     0,    54,
       0,     0,    55,     0,     0,     0,     0,     0,     0,     0,
      86,    87,     0,     0,     0,     0,    56,    55,     0,     0,
       0,     0,     0,     0,     0,    86,    87,     0,     0,     0,
       0,    56,     0,     0,     0,     0,     0,     0,     0,    57,
      88,    89,    90,     0,   307,     0,     0,     0,     0,     0,
      91,     0,     0,     0,    57,    88,    89,    90,    93,     0,
       0,     0,    94,    95,     0,    91,     0,     0,   320,     0,
       0,     0,     0,    93,     0,     0,     0,    94,    95,    50,
      51,    52,    53,     0,    85,     0,     0,    54,     0,     0,
       0,     0,     0,     0,    50,    51,    52,    53,     0,    85,
       0,     0,    54,     0,     0,    55,     0,     0,     0,     0,
       0,     0,     0,    86,    87,     0,     0,     0,     0,    56,
      55,     0,     0,     0,     0,     0,     0,     0,    86,    87,
       0,     0,     0,     0,    56,     0,     0,     0,     0,     0,
       0,     0,    57,    88,    89,    90,     0,   339,     0,     0,
       0,     0,     0,    91,     0,     0,     0,    57,    88,    89,
      90,    93,     0,     0,     0,    94,    95,     0,    91,     0,
       0,   351,     0,     0,     0,     0,    93,     0,     0,     0,
      94,    95,    50,    51,    52,    53,     0,    85,     0,     0,
      54,     0,     0,     0,     0,     0,     0,    50,    51,    52,
      53,     0,    85,     0,     0,    54,     0,     0,    55,     0,
       0,     0,     0,     0,     0,     0,    86,    87,     0,     0,
       0,     0,    56,    55,     0,     0,     0,     0,     0,     0,
       0,    86,    87,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,     0,     0,    57,    88,    89,    90,     0,
       0,     0,     0,     0,     0,     0,    91,   359,     0,     0,
      57,    88,    89,    90,    93,   362,     0,     0,    94,    95,
       0,    91,    50,    51,    52,    53,     0,    85,     0,    93,
      54,     0,     0,    94,    95,     0,     0,    50,    51,    52,
      53,     0,    85,     0,     0,    54,     0,     0,    55,     0,
       0,     0,     0,     0,     0,     0,    86,    87,     0,     0,
       0,     0,    56,    55,     0,     0,     0,     0,     0,     0,
       0,    86,    87,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,     0,     0,    57,    88,    89,    90,     0,
       0,     0,     0,     0,     0,     0,    91,   372,     0,     0,
      57,    88,    89,    90,    93,     0,     0,     0,    94,    95,
       0,    91,   374,    50,    51,    52,    53,     0,    85,    93,
       0,    54,     0,    94,    95,     0,     0,     0,    50,    51,
      52,    53,     0,    85,     0,     0,    54,     0,     0,    55,
       0,     0,     0,     0,     0,     0,     0,    86,    87,     0,
       0,     0,     0,    56,    55,     0,     0,     0,     0,     0,
       0,     0,    86,    87,     0,     0,     0,     0,    56,     0,
       0,     0,     0,     0,     0,     0,    57,    88,    89,    90,
       0,     0,     0,     0,     0,     0,     0,    91,   384,     0,
       0,    57,    88,    89,    90,    93,     0,     0,     0,    94,
      95,     0,    91,    50,    51,    52,    53,     0,    85,     0,
      93,    54,     0,     0,    94,    95,     0,     0,    50,    51,
      52,    53,     0,    85,     0,     0,    54,     0,     0,    55,
       0,     0,     0,     0,     0,     0,     0,    86,    87,     0,
       0,     0,     0,    56,    55,     0,     0,     0,     0,     0,
       0,     0,    86,    87,     0,     0,     0,     0,    56,     0,
       0,     0,     0,     0,     0,     0,    57,    88,    89,    90,
       0,     0,     0,     0,     0,     0,     0,    58,     0,     0,
       0,    57,    88,    89,    90,    93,     0,     0,     0,    94,
      95,     0,   171,     0,     0,     0,    -2,     1,     0,     0,
      93,     0,     2,     0,    94,    95,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,    23,     2,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    24,    15,    16,    17,    18,    19,    20,    21,
       0,     0,     0,     0,     0,    25,     0,     0,     0,     0,
      22,     0,     0,    26,     2,     0,     0,    27,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     0,
      15,    16,    17,    18,    19,    20,    21,     0,     0,     0,
      25,     0,     0,     0,     0,     0,     0,    22,   253,   317,
     254,     0,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     0,    24,     0,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    25,    15,    16,
      17,    18,    19,    20,    21,    26,     0,     0,     0,    27,
       0,     0,     0,     0,     0,    22,     0,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,     0,    15,
      16,    17,    18,    19,    20,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    25,    22,     0,     0,     0,
       0,     0,     0,    26,     0,     0,     0,    27,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    25,    15,    16,    17,
      18,    19,    20,    21,   264,   317,   254,     0,    27,     0,
       0,     0,     0,     0,    22,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,     0,    15,    16,    17,
      18,    19,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,     0,     0,    76,     0,     0,
     127,     0,     0,     0,     0,     0,    27,     0,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     0,
      15,    16,    17,    18,    19,    20,    21,    76,     0,     0,
       0,     0,     0,     0,     0,     0,    27,    22,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     0,
      15,    16,    17,    18,    19,    20,    21,     3,     4,     5,
       6,     7,     8,     0,     0,     0,     0,    22,     0,    15,
      16,    17,    18,    19,    20,    21,   349,     0,     0,    27,
       0,     0,     0,     0,     0,     0,    22,     3,     4,     5,
       6,     7,     8,     0,     0,     0,     0,     0,     0,    15,
      16,    17,    18,    19,    20,    21,     0,     0,     0,    27,
       0,     0,     0,     0,     0,     0,    22,     0,     0,     0,
     229,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     300,     0,     0,     0,     0,     0,     0,     0,    27
};

static const yytype_int16 yycheck[] =
{
      58,    34,    35,    36,    42,   138,    83,    40,   110,    46,
     133,   222,   143,     6,    46,    12,    13,     6,    74,     6,
      14,    40,    78,   156,   127,    25,    40,    91,    26,    51,
      75,    47,    48,    91,     6,    33,    72,    70,   164,    69,
      70,    70,     6,    76,     0,    78,    91,    76,   174,     6,
      83,    70,    78,    85,    86,    87,    70,    76,    88,    78,
      82,    29,     6,     6,    78,    59,    71,   131,   132,    74,
      86,    87,    69,   204,   256,     6,    44,    72,   110,    72,
       6,    79,    69,   265,   142,   130,   131,   132,   133,    78,
      77,   193,   194,   195,    80,   128,    44,   200,     7,     8,
     231,    49,   235,   226,   207,    77,   143,   171,    72,   128,
     243,   143,    83,   171,   128,    74,   249,   220,   151,   222,
     178,    80,    50,   254,   335,    69,   171,    85,   126,    38,
      84,    69,   151,    77,    77,    79,    79,   135,    69,    77,
      71,    79,    77,   201,    79,   177,    77,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   164,   267,   164,   204,    77,    75,
      79,    74,   204,   304,   174,    78,    12,    13,   311,   237,
     238,   226,    91,    77,    74,    79,   244,   245,    78,     3,
       4,     5,     6,   324,   231,     6,    74,    11,    74,   231,
      78,    74,    78,    74,    74,    78,    74,    78,    78,   342,
      78,   344,   345,    71,    76,    29,    74,   254,   256,    71,
     253,    74,   254,    25,    71,    78,   359,   260,   331,    43,
      71,   264,   335,    74,    71,   267,    76,    74,   371,   372,
      71,   374,    71,    74,   377,    74,   323,    77,   381,   307,
     383,   384,    66,   253,    77,   253,    71,   390,    69,    74,
      62,    63,     6,    77,   264,    76,    77,   304,   185,   186,
     187,   188,   304,    75,    77,    74,    79,    76,    63,    64,
     338,   339,    77,   341,    67,    68,    77,   324,    75,    91,
     323,     6,   324,   330,    73,    74,    73,    74,   330,    73,
      74,   183,   184,   361,   362,   303,   189,   190,    78,    10,
      11,    12,    13,    14,    15,    74,   191,   192,   376,    74,
     122,    22,    23,    24,    25,    26,    27,    28,   130,   131,
     132,   133,     3,     4,     5,     6,    78,     8,    39,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      78,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,   171,
      41,    42,    43,     6,    45,    42,    52,    53,    54,    55,
      81,    57,    58,    59,    60,    61,    62,    76,    76,    71,
      74,    78,    77,    46,    65,    66,    67,    68,    69,    75,
      71,    72,    73,    78,    78,    71,    77,    80,    78,     1,
      81,    80,   130,   126,    85,   303,   113,   206,    89,    90,
       3,     4,     5,     6,   226,     8,    62,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,   260,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,   171,    41,    42,
      43,   327,    45,   179,   181,   151,   177,    23,   180,    -1,
      -1,    -1,   182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    -1,    -1,    -1,    77,    -1,    -1,    -1,    81,    -1,
      -1,    -1,    85,    -1,    -1,    -1,    89,    90,     3,     4,
       5,     6,    -1,     8,    -1,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    -1,    -1,    -1,    43,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    66,    67,    68,    69,     3,     4,     5,     6,    39,
       8,    -1,    77,    11,    -1,    -1,    81,    -1,    -1,    -1,
      85,    -1,    -1,    -1,    89,    90,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    41,    42,    43,    -1,    45,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    -1,    -1,    -1,    77,
       3,     4,     5,     6,    -1,     8,    -1,    85,    11,    -1,
      -1,    89,    90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    41,    42,
      43,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    -1,    -1,    -1,    77,     3,     4,     5,     6,    -1,
       8,    -1,    85,    11,    -1,    -1,    89,    90,    -1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    11,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    41,    42,    43,    29,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,
      68,    69,    -1,    71,    72,    -1,    -1,    -1,    -1,    77,
      -1,    -1,    -1,    66,    67,    68,    69,    85,    -1,    72,
      73,    89,    90,    -1,    77,     3,     4,     5,     6,    -1,
       8,    -1,    85,    11,    -1,    -1,    89,    90,    -1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    11,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    -1,    -1,    -1,    -1,    43,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      -1,    -1,    80,    66,    67,    68,    69,    85,    -1,    72,
      -1,    89,    90,    -1,    77,     3,     4,     5,     6,    -1,
       8,    -1,    85,    11,    -1,    -1,    89,    90,    -1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    11,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    -1,    -1,    -1,    -1,    43,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,
      68,    69,    -1,    71,    -1,    -1,    -1,    -1,    -1,    77,
      -1,    -1,    -1,    66,    67,    68,    69,    85,    -1,    -1,
      -1,    89,    90,    -1,    77,    78,     3,     4,     5,     6,
      -1,     8,    85,    -1,    11,    -1,    89,    90,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    11,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    -1,    -1,    -1,    -1,    43,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      67,    68,    69,    -1,    71,    -1,    -1,    -1,    -1,    -1,
      77,    -1,    -1,    -1,    66,    67,    68,    69,    85,    -1,
      -1,    -1,    89,    90,    -1,    77,    -1,    -1,    80,    -1,
      -1,    -1,    -1,    85,    -1,    -1,    -1,    89,    90,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    11,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,    43,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    67,    68,    69,    -1,    71,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    -1,    -1,    66,    67,    68,
      69,    85,    -1,    -1,    -1,    89,    90,    -1,    77,    -1,
      -1,    80,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,
      89,    90,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    11,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    43,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    -1,    -1,    -1,    -1,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    -1,    -1,
      66,    67,    68,    69,    85,    71,    -1,    -1,    89,    90,
      -1,    77,     3,     4,     5,     6,    -1,     8,    -1,    85,
      11,    -1,    -1,    89,    90,    -1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    11,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    43,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    -1,    -1,    -1,    -1,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    -1,    -1,
      66,    67,    68,    69,    85,    -1,    -1,    -1,    89,    90,
      -1,    77,    78,     3,     4,     5,     6,    -1,     8,    85,
      -1,    11,    -1,    89,    90,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    11,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,
      -1,    -1,    -1,    43,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    -1,
      -1,    66,    67,    68,    69,    85,    -1,    -1,    -1,    89,
      90,    -1,    77,     3,     4,     5,     6,    -1,     8,    -1,
      85,    11,    -1,    -1,    89,    90,    -1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    11,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,
      -1,    -1,    -1,    43,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,
      -1,    66,    67,    68,    69,    85,    -1,    -1,    -1,    89,
      90,    -1,    77,    -1,    -1,    -1,     0,     1,    -1,    -1,
      85,    -1,     6,    -1,    89,    90,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,     6,    -1,    -1,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    56,    22,    23,    24,    25,    26,    27,    28,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,
      39,    -1,    -1,    77,     6,    -1,    -1,    81,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    28,    -1,    -1,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    39,    77,    78,
      79,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,    -1,    56,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    69,    22,    23,
      24,    25,    26,    27,    28,    77,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    69,    22,    23,    24,
      25,    26,    27,    28,    77,    78,    79,    -1,    81,    -1,
      -1,    -1,    -1,    -1,    39,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    -1,    72,    -1,    -1,
      75,    -1,    -1,    -1,    -1,    -1,    81,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    28,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    39,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    28,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    39,    -1,    22,
      23,    24,    25,    26,    27,    28,    78,    -1,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     6,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    39,    40,    56,    69,    77,    81,    93,    94,
      95,    96,    97,    99,   100,   101,   102,   103,   104,   112,
     115,   116,   119,   131,    94,    77,    79,     6,    72,    93,
       3,     4,     5,     6,    11,    29,    43,    66,    77,   159,
     161,   102,   119,   120,   115,     0,    95,    71,   106,   107,
     115,    99,    99,    99,     6,    72,    72,    97,    98,    99,
     135,   116,    78,   117,   118,     8,    37,    38,    67,    68,
      69,    77,    80,    85,    89,    90,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,    72,     6,   113,   114,   140,   141,   143,
     156,    93,   120,   102,    78,    71,    74,    75,    98,   135,
      72,   101,   102,   105,   108,   109,     6,    11,    30,    31,
      32,    33,    34,    35,    36,    41,    42,    45,    65,    71,
      73,    98,   132,   133,   134,   135,   136,   137,   138,   139,
     140,    97,   135,   115,    99,   121,   122,   123,     6,   124,
     156,    77,   156,   156,   109,   128,    80,    51,    82,    50,
      83,    84,    85,    44,    49,    47,    48,    86,    87,    63,
      64,    67,    68,    69,    70,    88,   155,     7,     8,    38,
      77,    79,    91,   113,    75,    73,    74,    74,    78,    52,
      53,    54,    55,    57,    58,    59,    60,    61,    62,    75,
     142,   107,    72,   126,   141,   135,   105,   109,   109,    73,
     108,    76,   110,   111,   115,    76,   132,    77,    77,    71,
      71,   140,   144,    76,    77,    77,    71,     6,    73,   136,
      73,   132,    71,    77,    79,   115,   119,   129,   130,    78,
      74,   125,    78,   128,    77,   119,   129,    78,   146,   140,
     147,   148,   149,   150,   151,   151,   152,   152,   152,   152,
     153,   153,   154,   154,   155,   155,   155,     6,    78,   141,
     160,   140,     6,    73,   144,   114,   141,   141,   126,   127,
      73,   144,    71,    74,    76,   132,    42,    71,   140,   140,
      71,    76,   132,   140,   140,    71,    73,    78,   121,   129,
      80,   144,   130,    77,    79,     9,   123,    74,    78,   155,
      76,    74,    78,    80,    73,    74,   111,   144,    77,    71,
     140,    71,    78,   132,    78,    78,    78,    78,    80,    78,
     121,    80,   144,   124,   143,   141,    73,   126,   140,    78,
     140,    71,    71,   140,   132,   132,   132,    78,    80,    78,
     132,    78,    78,   140,    78,   140,    71,    46,    71,   132,
     132,    78,   132,    78,    78,   140,   132,   132,   132,   132,
      78,   132
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
#line 125 "bison.y"
    { yyerrok;;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 126 "bison.y"
    {insertarErrorSintactico(&listaErroresSintacticos,yylineno);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 129 "bison.y"
    {insertarEnListaNoReconocido(&listaNoReconocido,(yyvsp[(1) - (1)].cadena),(yyvsp[(1) - (1)].INFO.linea));;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 137 "bison.y"
    {/*insertarEnListaFunciones(&listafunciones,$<cadena>2,$<cadena>1,$<INFO.linea>1);/* tengo que veri*/;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 161 "bison.y"
    {if(estoyDerivandoParametrosDeLaFuncion==1){
    strcpy(tipoVariableFuncion,(yyvsp[(1) - (1)].INFO.cadena));
}else{
     strcpy(tipo,(yyvsp[(1) - (1)].INFO.cadena));
}

;;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 168 "bison.y"
    {if(estoyDerivandoParametrosDeLaFuncion==1){
    strcpy(tipoVariableFuncion,(yyvsp[(1) - (1)].INFO.cadena));
}else{
     strcpy(tipo,(yyvsp[(1) - (1)].INFO.cadena));
}

;;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 175 "bison.y"
    {if(estoyDerivandoParametrosDeLaFuncion==1){
    strcpy(tipoVariableFuncion,(yyvsp[(1) - (1)].INFO.cadena));
}else{
     strcpy(tipo,(yyvsp[(1) - (1)].INFO.cadena));
}

;;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 182 "bison.y"
    {if(estoyDerivandoParametrosDeLaFuncion==1){
    strcpy(tipoVariableFuncion,(yyvsp[(1) - (1)].INFO.cadena));
}else{
     strcpy(tipo,(yyvsp[(1) - (1)].INFO.cadena));
}

;;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 189 "bison.y"
    {if(estoyDerivandoParametrosDeLaFuncion==1){
    strcpy(tipoVariableFuncion,(yyvsp[(1) - (1)].INFO.cadena));
}else{
     strcpy(tipo,(yyvsp[(1) - (1)].INFO.cadena));
}

;;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 196 "bison.y"
    {if(estoyDerivandoParametrosDeLaFuncion==1){
    strcpy(tipoVariableFuncion,(yyvsp[(1) - (1)].INFO.cadena));
}else{
     strcpy(tipo,(yyvsp[(1) - (1)].INFO.cadena));
}

;;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 203 "bison.y"
    {if(estoyDerivandoParametrosDeLaFuncion==1){
    strcpy(tipoVariableFuncion,(yyvsp[(1) - (1)].INFO.cadena));
}else{
     strcpy(tipo,(yyvsp[(1) - (1)].INFO.cadena));
}

;;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 210 "bison.y"
    {if(estoyDerivandoParametrosDeLaFuncion==1){
    strcpy(tipoVariableFuncion,(yyvsp[(1) - (1)].INFO.cadena));
}else{
     strcpy(tipo,(yyvsp[(1) - (1)].INFO.cadena));
}

;;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 217 "bison.y"
    {if(estoyDerivandoParametrosDeLaFuncion==1){
    strcpy(tipoVariableFuncion,(yyvsp[(1) - (1)].INFO.cadena));
}else{
     strcpy(tipo,(yyvsp[(1) - (1)].INFO.cadena));
}

;;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 235 "bison.y"
    {if(estoyDerivandoParametrosDeLaFuncion==1){
    strcpy(tipoVariableFuncion,(yyvsp[(1) - (1)].INFO.cadena));
}else{
     strcpy(tipo,(yyvsp[(1) - (1)].INFO.cadena));
}

;;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 242 "bison.y"
    {if(estoyDerivandoParametrosDeLaFuncion==1){
    strcpy(tipoVariableFuncion,(yyvsp[(1) - (1)].INFO.cadena));
}else{
     strcpy(tipo,(yyvsp[(1) - (1)].INFO.cadena));
}

;;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 283 "bison.y"
    {esPuntero(&listavariables);;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 287 "bison.y"
    {if(estoyDerivandoParametrosDeLaFuncion==1){
    //printf("variable de la f: %s",$<INFO.cadena>1);
    agregarVariableALaFuncion(nombreDeFuncion,tipoVariableFuncion,(yyvsp[(1) - (1)].INFO.cadena),&listafunciones);
    //agregarVariableALaFuncion(nombreDeFuncion,tipoVariableFuncion,$<INFO.cadena>1;&listafunciones);
}else{
     insertarEnListaVariables(&listavariables,(yyvsp[(1) - (1)].INFO.cadena),tipo,(yyvsp[(1) - (1)].INFO.linea),&listaDobleDeclaracion);
}
;;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 296 "bison.y"
    {insertarEnListaVariables(&listavariables,(yyvsp[(1) - (4)].INFO.cadena),tipo,(yyvsp[(1) - (4)].INFO.linea),&listaDobleDeclaracion); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 297 "bison.y"
    {insertarEnListaVariables(&listavariables,(yyvsp[(1) - (3)].INFO.cadena),tipo,(yyvsp[(1) - (3)].INFO.linea),&listaDobleDeclaracion); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 298 "bison.y"
    {estoyDerivandoParametrosDeLaFuncion=1;
                      strcpy(nombreDeFuncion,(yyvsp[(1) - (2)].INFO.cadena));
                      insertarEnListaFunciones(&listafunciones,(yyvsp[(1) - (2)].INFO.cadena),tipo,(yyvsp[(1) - (2)].INFO.linea));
                      ;;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 301 "bison.y"
    {estoyDerivandoParametrosDeLaFuncion=0;;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 302 "bison.y"
    {strcpy(nombreDeFuncionInvocada,(yyvsp[(1) - (2)].INFO.cadena));estoyDerivandoIdentificadoresInvocados=1;;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 302 "bison.y"
    {estoyDerivandoIdentificadoresInvocados=0;
                verificarFuncionInvocada(&listafunciones,nombreDeFuncionInvocada,&listaParametros,&listavariables);
                ;;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 326 "bison.y"
    { if(estoyDerivandoIdentificadoresInvocados==1){
insertarIdentificadoresInvocados(&listaParametros,(yyvsp[(1) - (1)].INFO.cadena));

}
    
    /*if (verificarFuncionInvocada(&listafunciones,nombreDeFuncionInvocada,&listaParametros,&listavariables)==1){
    printf("no coinciden los tipos de parametros de la funcion \n");
}*/;;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 334 "bison.y"
    { if(estoyDerivandoIdentificadoresInvocados==1){
insertarIdentificadoresInvocados(&listaParametros,(yyvsp[(1) - (1)].INFO.cadena));

};;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 387 "bison.y"
    {insertarEnListaSentencias(&listaSentencias,(yyvsp[(1) - (5)].cadena),(yyvsp[(1) - (5)].INFO.linea));;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 388 "bison.y"
    {insertarEnListaSentencias(&listaSentencias,(yyvsp[(1) - (7)].cadena),(yyvsp[(1) - (7)].INFO.linea));;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 389 "bison.y"
    {insertarEnListaSentencias(&listaSentencias,(yyvsp[(1) - (5)].cadena),(yyvsp[(1) - (5)].INFO.linea));;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 391 "bison.y"
    {insertarEnListaSentencias(&listaSentencias,(yyvsp[(1) - (5)].cadena),(yyvsp[(1) - (5)].INFO.linea));;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 392 "bison.y"
    {insertarEnListaSentencias(&listaSentencias,(yyvsp[(1) - (7)].cadena),(yyvsp[(1) - (7)].INFO.linea));;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 393 "bison.y"
    {insertarEnListaSentencias(&listaSentencias,(yyvsp[(1) - (9)].cadena),(yyvsp[(1) - (9)].INFO.linea));;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 394 "bison.y"
    {insertarEnListaSentencias(&listaSentencias,(yyvsp[(1) - (8)].cadena),(yyvsp[(1) - (8)].INFO.linea));;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 395 "bison.y"
    {insertarEnListaSentencias(&listaSentencias,(yyvsp[(1) - (8)].cadena),(yyvsp[(1) - (8)].INFO.linea));;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 396 "bison.y"
    {insertarEnListaSentencias(&listaSentencias,(yyvsp[(1) - (7)].cadena),(yyvsp[(1) - (7)].INFO.linea));;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 397 "bison.y"
    {insertarEnListaSentencias(&listaSentencias,(yyvsp[(1) - (8)].cadena),(yyvsp[(1) - (8)].INFO.linea));;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 398 "bison.y"
    {insertarEnListaSentencias(&listaSentencias,(yyvsp[(1) - (7)].cadena),(yyvsp[(1) - (7)].INFO.linea));;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 399 "bison.y"
    {insertarEnListaSentencias(&listaSentencias,(yyvsp[(1) - (7)].cadena),(yyvsp[(1) - (7)].INFO.linea));;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 400 "bison.y"
    {insertarEnListaSentencias(&listaSentencias,(yyvsp[(1) - (6)].cadena),(yyvsp[(1) - (6)].INFO.linea));;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 461 "bison.y"
    {
                                if(esTipoCorrecto(&listavariables,(yyvsp[(1) - (3)].INFO.cadena))==0){ // Si la función retorna 0, no es un tipo operable
                                    insertarEnListaErrorDeTipos(&listaerrordetipos,(yyvsp[(1) - (3)].INFO.cadena),tipoDeDato(&listavariables,(yyvsp[(1) - (3)].INFO.cadena)),(yyvsp[(1) - (3)].INFO.linea));
                                } 
                                
                                else if(esTipoCorrecto(&listavariables,(yyvsp[(1) - (3)].INFO.cadena))==2){ // Si la función retorna 2, no esta declarada
                                    insertarEnListaNoDeclarados(&listaNoDeclarados,(yyvsp[(1) - (3)].INFO.cadena),(yyvsp[(1) - (3)].INFO.linea));
                                }

                                //Para la segunda variable
                                if(esTipoCorrecto(&listavariables,(yyvsp[(3) - (3)].INFO.cadena))==0){ // Si la función retorna 0, no es un tipo operable
                                    insertarEnListaErrorDeTipos(&listaerrordetipos,(yyvsp[(3) - (3)].INFO.cadena),tipoDeDato(&listavariables,(yyvsp[(3) - (3)].INFO.cadena)),(yyvsp[(3) - (3)].INFO.linea));
                                } 
                                
                                else if(esTipoCorrecto(&listavariables,(yyvsp[(3) - (3)].INFO.cadena))==2){ // Si la función retorna 2, no esta declarada
                                    insertarEnListaNoDeclarados(&listaNoDeclarados,(yyvsp[(3) - (3)].INFO.cadena),(yyvsp[(3) - (3)].INFO.linea));
                                }
                                
                            ;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 494 "bison.y"
    {
                    if(strcmp((yyvsp[(2) - (2)].cadena),yylval.cadena) == 0) {
                        printf("No se puede realizar una operacion binaria con strings");
                    }
                ;;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 518 "bison.y"
    {/*printf("se encontro un id : %s\n",$<INFO.cadena>1)/* aca hay que poner la funcion de validar tipo de datos*/;;}
    break;



/* Line 1455 of yacc.c  */
#line 2567 "bison.tab.c"
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
#line 535 "bison.y"



int main (int argc, char *argv[])
{
        FILE* reporte = fopen("reporte.txt","w+");
        yyin=fopen(argv[1],"r");
        yyparse();
        imprimirListaEnArchivo(reporte,listavariables,listaNoReconocido,listafunciones,listaSentencias,listaDobleDeclaracion,listaerrordetipos,listaNoDeclarados);
        fclose(reporte);
        fclose(yyin);

        if(analisisCorrecto)
        printf("\nAnalisis finalizado correctamente\n");

        return 0;
}

int yyerror(const char *msg){
        //printf("\nFallo el analisis en la linea: %d %s\n",yylineno,msg);
        analisisCorrecto=0;
        return 0;
}





void insertarEnListaVariables(NODOVARIABLES** lista, char *nombre,char*tipo, int linea,NODOVARIABLES** listaDobleDeclaracion)
{
 
     NODOVARIABLES *ptr = *lista;
     NODOVARIABLES *nuevo = (NODOVARIABLES *)malloc(sizeof(NODOVARIABLES));
     NODOVARIABLES *aux = *lista;

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
        
        while (aux != NULL )
        {
            if(strcmp(aux->nombre,nombre)==0)
            {
                //Doble declaracion
                insertarEnListaDobleDeclaracion(nombre,linea,listaDobleDeclaracion);
                break;
            }


            aux = aux->sig;
        }


        while (ptr->sig != NULL )
        {
   
            ptr = ptr->sig;
        }

        nuevo->sig = ptr->sig;
        ptr->sig = nuevo;
    }
}

void insertarEnListaDobleDeclaracion(char *nombre, int linea,NODOVARIABLES** listaDobleDeclaracion) {
    NODOVARIABLES *ptr = *listaDobleDeclaracion;
     NODOVARIABLES *nuevo = (NODOVARIABLES *)malloc(sizeof(NODOVARIABLES));

    nuevo->nombre = strdup(nombre);
    nuevo->linea = linea;

    if (*listaDobleDeclaracion == NULL )
    {
        nuevo->sig = *listaDobleDeclaracion;
        *listaDobleDeclaracion = nuevo;
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
    nuevo->cantidad = 0;
    nuevo->variable = NULL;

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

int estaEnListaFunciones(NODOFUNCIONES** lista, char *nombre)
{
     NODOFUNCIONES *aux = *lista;
    while (aux != NULL)
    {
        if (strcmp(aux->nombre, nombre) == 0)
        {
            return 1;
        }
        aux = aux->sig;
    }
    return 0;
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
void imprimirListaEnArchivo(FILE* archivo,NODOVARIABLES* listavariables,NODONORECONOCIDO *listaNoReconocido,NODOFUNCIONES* listafunciones,NODOSENTENCIAS* listaSentencias,NODOVARIABLES* listaDobleDeclaracion,NODOVARIABLES* listaerrordetipos, NODONODECLARADOS* listaNoDeclarados)
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
        fprintf(archivo,"\nLinea: %i    ", ptr->linea);
        if(ptr->linea < 10) //Para alinear la lista
	    {
		    fprintf(archivo," ");
        }
		fprintf(archivo,"Funcion: %s",ptr->nombre);
        for(int i=0;i<(15-strlen(ptr->nombre));i++) //Para alinear la lista
	    {
		    fprintf(archivo," ");
        }
        fprintf(archivo,"Tipo: %s",ptr->tipo);
        for(int i=0;i<(15-strlen(ptr->tipo));i++) //Para alinear la lista
	    {
		    fprintf(archivo," ");
        }
        fprintf(archivo,"Cantidad de parametros: %i\n",ptr->cantidad);

        fprintf(archivo,"Parametros:\n");

        while(ptr->variable != NULL){
            NODOVARIABLES *aux = ptr->variable;
            ptr->variable = ptr->variable->sig;

            fprintf(archivo,"Nombre: %s     ",aux->nombre);
            for(int i=0;i<(15-strlen(aux->nombre));i++) //Para alinear la lista
	        {
		        fprintf(archivo," ");
            }
            fprintf(archivo,"Tipo: %s \n",aux->tipo);
            free(aux);

        }


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
        fprintf(archivo,"Linea: %i\t\t\t\t", ptr->linea);
		fprintf(archivo,"Sentencia: %s \n",ptr->tipoSentencia);
		free(ptr);
	}

    fprintf(archivo,"\n________________________________________________________________________________________\n\n");
	
    //ERRORES SEMANTICOS
    fprintf(archivo,"-------------------------------------Errores Semanticos-------------------------------------\n\n");

    //Doble declaracion de variables
    fprintf(archivo,"Doble declaracion de variable:\n\n");    
    while(listaDobleDeclaracion!=NULL)
	{
        NODOVARIABLES *ptr=listaDobleDeclaracion;
        listaDobleDeclaracion=listaDobleDeclaracion->sig;
        fprintf(archivo,"Nombre: %s", ptr->nombre);
        for(int i=0;i<(15-strlen(ptr->nombre));i++) //Para alinear la lista
	    {
		    fprintf(archivo," ");
        }
		fprintf(archivo,"Linea: %i \n",ptr->linea);
		free(ptr);
	}

     fprintf(archivo,"\n________________________________________________________________________________________\n\n");

    //Error de tipos
    fprintf(archivo,"Error de tipos:\n\n");    
     while(listaerrordetipos!=NULL)
	{
        NODOVARIABLES *ptr=listaerrordetipos;
        listaerrordetipos=listaerrordetipos->sig;
        fprintf(archivo,"Linea: %i      ",ptr->linea);
        /*for(int i=0;i<(15-strlen(ptr->variable1));i++) //Para alinear la lista
	    {
		    fprintf(archivo," ");
        }*/
        fprintf(archivo,"El identificador %s de tipo %s no es operable\n", ptr->nombre,ptr->tipo);
		free(ptr);
	}

     fprintf(archivo,"\n________________________________________________________________________________________\n\n");

    //Imprimo Lista de Identificadores No Declarados
    fprintf(archivo,"Listado de Identificadores No Declarados:\n\n");
    while(listaNoDeclarados!=NULL)
	{
        NODONODECLARADOS *ptr=listaNoDeclarados;
        listaNoDeclarados=listaNoDeclarados->sig;
        fprintf(archivo,"Linea: %i  ", ptr->linea);
        if(ptr->linea < 10) //Para alinear la lista
	    {
		    fprintf(archivo," ");
        }
		fprintf(archivo,"Identificador: %s\n",ptr->nombre);

		free(ptr);
	}

    fprintf(archivo,"\n________________________________________________________________________________________\n\n");

    fprintf(archivo,"Listado de errores de tipos en funciones:\n\n");
    while(listaErroresSemanticosDeTipos!=NULL)
	{
        NODOERRORDETIPOSDEFUNCION *ptr=listaErroresSemanticosDeTipos;
        listaErroresSemanticosDeTipos=listaErroresSemanticosDeTipos->sig;
        //fprintf(archivo,"Linea: %i  ", ptr->linea);
        /*if(ptr->linea < 10) //Para alinear la lista
	    {
		    fprintf(archivo," ");
        }*/
		fprintf(archivo,"En la funcion \"%s\", se esperaba un identificador de tipo %s pero se encontro al identificador %s de tipo  %s \n",ptr->nombreFuncion,ptr->tipoParametroEsperado,ptr->nombreIdentificador,ptr->tipoIdentificador);

		free(ptr);
	}

    fprintf(archivo,"\n________________________________________________________________________________________\n\n");

    fprintf(archivo,"Listado de errores de falta de parametros en funciones:\n\n");

    while(listaErroresSemanticosDeCantidadDeTipos!=NULL)
	{
        NODOERRORFALTADETIPOS *ptr=listaErroresSemanticosDeCantidadDeTipos;
        listaErroresSemanticosDeCantidadDeTipos=listaErroresSemanticosDeCantidadDeTipos->sig;


		fprintf(archivo,"en la funcion %s se esperaban %d  identificadores, pero se econtraron solo %d \n",ptr->nombreFuncion,ptr->cantidadVariablesDeclaradas,ptr->cantIdentificadoresInvocados);
        
		free(ptr);
	}


     fprintf(archivo,"\n________________________________________________________________________________________\n\n");

    fprintf(archivo,"Listado de errores de sobra de parametros en funciones:\n\n");

    while(listaErroresSemanticosDeSobraDeTipos!=NULL)
	{
        NODOSOBRADETIPOS *ptr=listaErroresSemanticosDeSobraDeTipos;
        listaErroresSemanticosDeSobraDeTipos=listaErroresSemanticosDeSobraDeTipos->sig;

		fprintf(archivo,"en la funcion %s solo se esperaban %d  identificadores, pero se econtraron con %d \n",ptr->nombreFuncion,ptr->cantidadVariablesDeclaradas,ptr->cantIdentificadoresInvocados);
        
		free(ptr);
	}


    //ERRORES SINTACTICOS
    fprintf(archivo,"\n-------------------------------------Errores Sintacticos-------------------------------------\n\n");
    fprintf(archivo,"Hubo errores sintacticos en las lineas: ");
    while(listaErroresSintacticos!=NULL)
	{
        NODOERRORESSINTACTICOS *ptr=listaErroresSintacticos;
        listaErroresSintacticos=listaErroresSintacticos->sig;
        fprintf(archivo,"%i, ",ptr->linea);
        ptr=ptr->sig;
        
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

int esTipoDeDatoValido(NODOVARIABLES** listaVariables,char *identificador){

 NODOVARIABLES *ptr = *listaVariables;
 while (ptr!=NULL){
    if(strcmp(ptr->nombre,identificador)==0){
        if(strcmp(ptr->tipo,"int")==0){
            return 1;
        }
        if(strcmp(ptr->tipo,"float")==0){
            return 1;
        }
        if(strcmp(ptr->tipo,"double")==0){
            return 1;
        }
        if(strcmp(ptr->tipo,"long")==0){
            return 1;
        }
        if(strcmp(ptr->tipo,"short")==0){
            return 1;
        }
     
        if(strcmp(ptr->tipo,"char")==0){
            return 1;
        }
        else{
         return 0;
        }
    }
     ptr=ptr->sig;
 }
}
void inicializarNodoVariablesVacio(NODOVARIABLES* nuevo)
{
    /* 
    int linea;
    char* nombre;
    char* tipo;
    */
	
	nuevo->linea=0;
	nuevo->nombre=strdup(" ");
    nuevo->tipo=strdup(" ");
}

NODOVARIABLES* pedirMemoriaEInicializarNodoVariables()
{	
	NODOVARIABLES* nuevoNodo=(NODOVARIABLES*) malloc(sizeof(NODOVARIABLES));
	inicializarNodoVariablesVacio(nuevoNodo);

	return nuevoNodo;
}

void agregarNuevoNodoVariablesAlFinal(NODOVARIABLES** nodo,NODOVARIABLES* nuevoNodo)
{
	nuevoNodo->sig=NULL;


	if(*nodo==NULL)
	{
		*nodo=nuevoNodo;
	}
	else
	{
		NODOVARIABLES* t=*nodo;
		while(t->sig!=NULL)
		{
			t=t->sig;
		}
		t->sig=nuevoNodo;

	}
}


void insertarEnListaParametros(NODOVARIABLES** lista, char *identificador,char*tipo)
{
     //NODOVARIABLES* nuevoNodo = pedirMemoriaEInicializarNodoVariables();
    NODOVARIABLES *ptr = *lista;
    NODOVARIABLES* nuevoNodo=(NODOVARIABLES *) malloc(sizeof(NODOVARIABLES));

    nuevoNodo->nombre=strdup(identificador);
    nuevoNodo->tipo=strdup(tipo);
  

    if (*lista == NULL )
    {
        nuevoNodo->sig = *lista;
        *lista = nuevoNodo;
    }
    else
    {   
        while (ptr->sig != NULL )
        {
            ptr = ptr->sig;
        }

        nuevoNodo->sig = ptr->sig;
        ptr->sig = nuevoNodo;
    }
	
	 //agregarNuevoNodoVariablesAlFinal(lista,nuevoNodo);
}



void agregarVariableALaFuncion(char* nombre,char* tipo,char* identificador,NODOFUNCIONES** lista) {

        NODOFUNCIONES *aux = *lista;
        if(strcmp(aux->nombre,nombre)==0){
            insertarEnListaParametros(&aux->variable,identificador,tipo);
            aux->cantidad ++;
            return ; 
        }
        while (strcmp(aux->nombre,nombre)!=0) {
            aux = aux->sig; 
        }
         if(strcmp(aux->nombre,nombre)==0)
            {
                insertarEnListaParametros(&aux->variable,identificador,tipo);
                aux->cantidad ++;
            }
        
    
}

char* buscarTipoId(char* nombre,NODOVARIABLES**  variables) {
    NODOVARIABLES *aux = *variables;
    while(aux != NULL) {
        if(strcmp(nombre,aux->nombre)==0) {
            return aux->tipo;
        }
        aux = aux->sig;
    }
    return "error";
}

//DEVUELVE 1 SI LOS TIPOS DE DATOS VERIFICAN, SI NO DEVUELVE 0
void compararParametros(NODOVARIABLES**  parametrosDeLaFuncion,NODOPARAMETROS** parametrosInvocados,NODOVARIABLES**  variables, char* nombreFuncion) {
     NODOVARIABLES* auxP1 = pedirMemoriaEInicializarNodoVariables();
    auxP1 = *parametrosDeLaFuncion;
    NODOPARAMETROS *auxP2 = *parametrosInvocados;
      int parametrosInvocadosTotales;


   parametrosInvocadosTotales= cantidadDeParametrosInvocados(auxP2);
    int cantidadDeVariablesDeclaradas;
    cantidadDeVariablesDeclaradas= cantidadDeParametros(auxP1);
   // aca es donde rompe
     //printf("el nombre es %s \n",auxP1->nombre );
   if(cantidadDeVariablesDeclaradas > parametrosInvocadosTotales ) {
        insertarListaErrorSemanticoFaltaDeTipos(&listaErroresSemanticosDeCantidadDeTipos,nombreFuncion, cantidadDeVariablesDeclaradas,parametrosInvocadosTotales);
        
    }
        if(cantidadDeVariablesDeclaradas < parametrosInvocadosTotales ) {
        insertarListaErrorSemanticoSobraDeTipos(&listaErroresSemanticosDeSobraDeTipos,nombreFuncion, cantidadDeVariablesDeclaradas,parametrosInvocadosTotales);
       
    }

    if(cantidadDeVariablesDeclaradas == parametrosInvocadosTotales) {
        while(auxP1!=NULL) {
            //Los parametros no son del tipo que corresponde
            char* tipoParametro = strdup(buscarTipoId(auxP2->nombre,variables));
            if(strcmp(auxP1->tipo,tipoParametro)!=0){
               
                insertarListaErrorSemanticoDeTiposDeFuncion(&listaErroresSemanticosDeTipos,nombreFuncion,auxP2->nombre,tipoParametro, auxP1->tipo);
                 // error semantico el tipo del identificador invocado, no coincide con el tipo de la funcion declarada
            }
            auxP1 = auxP1->sig;
            auxP2 = auxP2->sig;
        }
    }
    /*}*/
   
    return ; // esta todo ok
}


//DEVUELVE 1 SI LOS TIPOS DE DATOS VERIFICAN, SI NO DEVUELVE 0
void verificarFuncionInvocada(NODOFUNCIONES** lista,char* nombreFuncion,NODOPARAMETROS** parametros,NODOVARIABLES**  variables) {
    NODOFUNCIONES *aux = *lista;
    char* tipoDeDatoParametro;
    char* tipoDeDatoIdentificador;
    int resultado = 0;
 

    if(strcmp(aux->nombre,nombreFuncion)==0){
        NODOVARIABLES *auxPar1=aux->variable;
        compararParametros(&auxPar1,parametros,variables,nombreFuncion);
        resultado= resultado+1;
    }
    while (strcmp(aux->nombre,nombreFuncion)!=0) {
        aux = aux->sig; 
    }
    if(strcmp(aux->nombre,nombreFuncion)==0 && resultado==0)
    {
        NODOVARIABLES *auxPar1=aux->variable;
        compararParametros(&auxPar1,parametros,variables,nombreFuncion);
    }

    //Dejo lista para parametros en NULL
    *parametros = NULL;

    return ;
}


//int verificarTipoDeDato()

char* tipoDeDato(NODOVARIABLES** lista, char* identificador){
   
   int i=0;
   NODOVARIABLES *ptr=listavariables;
   char* tipo ;

   while(ptr != NULL){

       if(strcmp(identificador,ptr->nombre)==0){
           tipo = ptr->tipo;
           break;
       }
       else{

        ptr = ptr->sig;
       }
   }

   if(ptr == NULL){
       tipo = "error";
   }

   return tipo;
}

int esTipoCorrecto(NODOVARIABLES** lista, char* identificador){

    char * tipo = tipoDeDato(lista,identificador);


    if(strcmp(tipo,"int")==0){
        return 1;
    }
    if(strcmp(tipo,"char")==0){
        return 1;
    }
    if(strcmp(tipo,"double")==0){
        return 1;
    }
    if(strcmp(tipo,"float")==0){
        return 1;
    }
    if(strcmp(tipo,"long")==0){
        return 1;
    }
    if(strcmp(tipo,"short")==0){
        return 1;
    }

    if(strcmp(tipo,"error")==0){
        return 2; // no se encuentra declarado
    }

    return 0; // no es operable
}

void insertarEnListaErrorDeTipos(NODOVARIABLES** lista, char *nombre,char*tipo,int linea)
{
 
     NODOVARIABLES *ptr = *lista;
     NODOVARIABLES *nuevo = (NODOVARIABLES *)malloc(sizeof(NODOVARIABLES));

    nuevo->nombre = strdup(nombre);
    nuevo->tipo = strdup(tipo);
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



void insertarEnListaNoDeclarados(NODONODECLARADOS**lista, char* nombre,int linea)
{
 
     NODONODECLARADOS *ptr = *lista;
     NODONODECLARADOS *nuevo = (NODONODECLARADOS *)malloc(sizeof(NODONODECLARADOS));

    nuevo->nombre = strdup(nombre);
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


void esPuntero(NODOVARIABLES** lista){
    NODOVARIABLES *ptr = *lista;
    
    while (ptr->sig != NULL )
        {
            ptr = ptr->sig;
        }

    strcat(ptr->tipo,"*");

}
void inicializarNodoVariablesVacioParametro(NODOPARAMETROS* nuevo)
{
    nuevo->nombre=strdup(" ");
     nuevo->sig=NULL;
	nuevo->longitud=0;
   
}

NODOPARAMETROS* pedirMemoriaEInicializarNodoParametros()
{	
	NODOPARAMETROS* nuevoNodo=(NODOPARAMETROS*) malloc(sizeof(NODOPARAMETROS));
	inicializarNodoVariablesVacioParametro(nuevoNodo);

	return nuevoNodo;
}

void insertarIdentificadoresInvocados(NODOPARAMETROS** lista,char* identificador){
    
    NODOPARAMETROS *actual = *lista;
    NODOPARAMETROS *nuevo = (NODOPARAMETROS *)malloc(sizeof(NODOPARAMETROS));
    nuevo->nombre = strdup(identificador);
    int contador=1;


    if (*lista == NULL)
    {
        nuevo->sig = *lista;
        *lista = nuevo;
        nuevo->longitud = 1;
        //printf("la longitud actual de identificador %s es: %d \n",nuevo->nombre,nuevo->longitud);
   

    }
    else
    {
        contador=2;
        while (actual->sig != NULL)
        {
            contador=contador+1;
            actual = actual->sig;
        }
        
        nuevo->longitud= contador;
        nuevo->sig = actual->sig;
        actual->sig = nuevo;
       //  printf("la longitud actual de identificador %s es: %d \n",nuevo->nombre,nuevo->longitud);
    }
}

int cantidadDeParametros(NODOVARIABLES *lista){
     NODOVARIABLES *aux = lista;
     int contador=1;
      while (aux->sig != NULL)
    {
        aux=aux->sig;
        contador=contador+1;
    }
    return contador;
}

int cantidadDeParametrosInvocados(NODOPARAMETROS*lista){
         NODOPARAMETROS *aux = lista;
     int contador=1;
      while (aux->sig != NULL)
    {
        aux=aux->sig;
        contador=contador+1;
    }
    return contador;
}

void insertarListaErrorSemanticoDeTiposDeFuncion(NODOERRORDETIPOSDEFUNCION** lista,char * nombreFuncion,char* nombreIdentificador,char* tipoidentificador, char* tipoParametroEsperado){
    NODOERRORDETIPOSDEFUNCION *actual = *lista;
    NODOERRORDETIPOSDEFUNCION *nuevo = (NODOERRORDETIPOSDEFUNCION *)malloc(sizeof(NODOERRORDETIPOSDEFUNCION));
    nuevo->nombreFuncion = strdup(nombreFuncion);
    nuevo->nombreIdentificador = strdup(nombreIdentificador);
    nuevo->tipoIdentificador = strdup(tipoidentificador);
    nuevo->tipoParametroEsperado = strdup(tipoParametroEsperado);

 if (*lista == NULL)
    {
        nuevo->sig = *lista;
        *lista = nuevo;
   
   

    }
    else
    {
      
        while (actual->sig != NULL)
        {
         
            actual = actual->sig;
        }
        
       
        nuevo->sig = actual->sig;
        actual->sig = nuevo;
     
    }
}




void insertarListaErrorSemanticoFaltaDeTipos(NODOERRORFALTADETIPOS** lista,char* nombreFuncion,int cantidadDeVariablesDeclaradas, int parametrosInvocadosTotales){

     NODOERRORFALTADETIPOS *actual = *lista;
    NODOERRORFALTADETIPOS *nuevo = (NODOERRORFALTADETIPOS *)malloc(sizeof(NODOERRORFALTADETIPOS));
    nuevo->nombreFuncion = strdup(nombreFuncion);
    nuevo->cantidadVariablesDeclaradas= cantidadDeVariablesDeclaradas;
    nuevo->cantIdentificadoresInvocados= parametrosInvocadosTotales;

    //printf("en la funcion %s se esperaban %d  identificadores, pero se econtraron solo %d \n",nombreFuncion,cantidadDeVariablesDeclaradas,parametrosInvocadosTotales);
     if (*lista == NULL)
    {
        nuevo->sig = *lista;
        *lista = nuevo;
    }
    else
    {
        while (actual->sig != NULL)
        {
         
            actual = actual->sig;
        }
        
       
        nuevo->sig = actual->sig;
        actual->sig = nuevo;
     
    }

}


void insertarListaErrorSemanticoSobraDeTipos(NODOSOBRADETIPOS** lista,char* nombreFuncion,int cantidadDeVariablesDeclaradas,int parametrosInvocadosTotales){
    
    NODOSOBRADETIPOS *actual = *lista;
    NODOSOBRADETIPOS *nuevo = (NODOSOBRADETIPOS *)malloc(sizeof(NODOSOBRADETIPOS));
    nuevo->nombreFuncion = strdup(nombreFuncion);
    nuevo->cantidadVariablesDeclaradas= cantidadDeVariablesDeclaradas;
    nuevo->cantIdentificadoresInvocados= parametrosInvocadosTotales;

    //printf("en la funcion %s solo se esperaban %d  identificadores, pero se econtraron con %d \n",nombreFuncion,cantidadDeVariablesDeclaradas,parametrosInvocadosTotales);
     if (*lista == NULL)
    {
        
        nuevo->sig = *lista;
        *lista = nuevo;
    }
    else
    {
      
        while (actual->sig != NULL)
        {
         
            actual = actual->sig;
        }
        
       
        nuevo->sig = actual->sig;
        actual->sig = nuevo;
     
    }
}

void insertarErrorSintactico(NODOERRORESSINTACTICOS** lista,int linea){
    NODOERRORESSINTACTICOS *actual = *lista;
    NODOERRORESSINTACTICOS *nuevo = (NODOERRORESSINTACTICOS *)malloc(sizeof(NODOERRORESSINTACTICOS));
    nuevo->linea = linea;

     if (*lista == NULL)
    {
        
        nuevo->sig = *lista;
        *lista = nuevo;
    }
    else
    {
      
        while (actual->sig != NULL)
        {
         
            actual = actual->sig;
        }
        
       
        nuevo->sig = actual->sig;
        actual->sig = nuevo;
     
    }
}
