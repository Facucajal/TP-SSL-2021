
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

/* Line 1676 of yacc.c  */
#line 44 "bison.y"

   char cadena[30];
   int entero;
   float real;
   char cadena2[30];
   struct info{
       char cadena[30];
       int linea;
   }INFO;



/* Line 1676 of yacc.c  */
#line 131 "bison.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


