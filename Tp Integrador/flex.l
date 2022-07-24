%option yylineno

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bison.tab.h"
#include "funciones.h"


extern FILE* yyin;
%}

ESPACIO_EN_BLANCO (" ")+
TABULACION (\t)+

DIGITO_DECIMAL [0-9]
DIGITO_OCTAL [0-7]
DIGITO_HEXADECIMAL [a-fA-F0-9]

SUFIJO_REAL f|F|l|L
SECUENCIA_DIGITOS {DIGITO_DECIMAL}+
/*SIGNO +|-*/
/*PARTE_EXPONENTE [Ee]{SIGNO}?{SECUENCIA_DIGITOS}*/
CONSTANTE_FRACCION {SECUENCIA_DIGITOS}?\.{SECUENCIA_DIGITOS}|{SECUENCIA_DIGITOS}\.
CONSTANTE_REAL      {CONSTANTE_FRACCION}(PARTE_EXPONENTE)?{SUFIJO_REAL}? 

SECUENCIA_DE_ESCAPE_HEXADECIMAL \\x{DIGITO_HEXADECIMAL}{1,2}
SECUENCIA_DE_ESCAPE_OCTAL \\{DIGITO_OCTAL}{1,3}
SECUENCIA_DE_ESCAPE_SIMPLE \\(\'|\"|\?|\\|a|b|f|n|r|t|v)
SECUENCIA_DE_ESCAPE {SECUENCIA_DE_ESCAPE_SIMPLE}|{SECUENCIA_DE_ESCAPE_OCTAL}|{SECUENCIA_DE_ESCAPE_HEXADECIMAL}
CUALQUIER_CARACTER_EXCEPTO_COMILLAS_O_BARRA_INVERTIDA [^"\\]
CARACTERES {CUALQUIER_CARACTER_EXCEPTO_COMILLAS_O_BARRA_INVERTIDA}|{SECUENCIA_DE_ESCAPE}
SECUENCIA_CARACTERES {CARACTERES}+

NO_DIGITO [_a-zA-Z]

OPERADOR_O_CARACTER_DE_PUNTUACION "["|"]"|"("|")"|"{"|"}"|"."|"->"|"++"|"--"|"&"|"*"|"+"|"-"|"~"|"!"|"/"|"%"|"<<"|">>"|"<"|">"|"<="|">="|"=="|"!="|"^"|"|"|"&&"|"||"|"="|"*="|"/="|"%="|"+="|"-="|"<<="|">>="|"&="|"^="|"|="|"?"|":"|";"|"..."|","|"#"|"##"

TIPO_DE_DATO char|double|float|int|long|short|void

ESTRUCTURA_DE_CONTROL else|for|if|switch|while|do

OTRAS_PALABRAS_RESERVADAS auto|break|case|const|continue|default|enum|extern|goto|register|return|signed|sizeof|static|struct|typedef|union|void|volatile

CONSTANTE_DECIMAL       [1-9]{DIGITO_DECIMAL}*
CONSTANTE_OCTAL         0{DIGITO_OCTAL}+
CONSTANTE_HEXADECIMAL   0[xX]{DIGITO_HEXADECIMAL}+

LITERAL_CADENA      \"{SECUENCIA_CARACTERES}\"
IDENTIFICADOR       {NO_DIGITO}({NO_DIGITO}|{DIGITO_DECIMAL})*

CONSTANTE_CARACTER  \'{CARACTERES}\'

COMENTARIO_SIMPLE               \/\/.*
COMENTARIO_UNA_LINEA            \/\*.*\*\/  
COMENTARIO_MULTIPLES_LINEAS     \/\*\n*.*\n*\*\/ 

SUFIJO_UNSIGNED u|U
SUFIJO_LONG l|L
SUFIJO_ENTERO {SUFIJO_UNSIGNED}|{SUFIJO_LONG}|{SUFIJO_UNSIGNED}{SUFIJO_LONG}|{SUFIJO_LONG}{SUFIJO_UNSIGNED}

%%
"#include<stdio.h>"                 {return INCLUDE;}
"#define"[ ]+{IDENTIFICADOR}         {return DEFINE;}
"auto"                              {return AUTO;}
"do"                                {strcpy(yylval.INFO.cadena,yytext);yylval.INFO.linea = yylineno;return DO;}
"for"                               {strcpy(yylval.INFO.cadena,yytext);yylval.INFO.linea = yylineno;return FOR;}
"char"                               {strcpy(yylval.INFO.cadena,yytext);;yylval.INFO.linea = yylineno;return CHAR;}
"double"                               {strcpy(yylval.INFO.cadena,yytext);yylval.INFO.linea = yylineno;return DOUBLE;}
"float"                               {strcpy(yylval.INFO.cadena,yytext);yylval.INFO.linea = yylineno;return FLOAT;}
"int"                               {strcpy(yylval.INFO.cadena,yytext);yylval.INFO.linea = yylineno;return INT;}
"long"                               {strcpy(yylval.INFO.cadena,yytext);yylval.INFO.linea = yylineno;return LONG;}
"short"                               {strcpy(yylval.INFO.cadena,yytext);yylval.INFO.linea = yylineno;return SHORT;}
"void"                               {strcpy(yylval.INFO.cadena,yytext);yylval.INFO.linea = yylineno;return VOID;}
"register"                          {return REGISTER;}
"continue"                          {return CONTINUE;}
"static"                            {return STATIC;}
"goto"                              {return GOTO;}
"extern"                            {return EXTERN;}
"typedef"                           {return TYPEDEF;}
"signed"                            {return SIGNED;}
"unsigned"                          {return UNSIGNED;}
"const"                             {return CONST;}
"volatile"                          {return VOLATILE;}
"enum"                              {return ENUM;}
"case"                              {return CASE;}
"default"                           {return DEFAULT;}
"if"                                {strcpy(yylval.INFO.cadena,yytext);yylval.INFO.linea = yylineno;return IF;}
"switch"                            {strcpy(yylval.INFO.cadena,yytext);yylval.INFO.linea = yylineno;return SWITCH;}        
"else"                              {strcpy(yylval.INFO.cadena,yytext);yylval.INFO.linea = yylineno;return ELSE;}
"while"                             {strcpy(yylval.INFO.cadena,yytext);yylval.INFO.linea = yylineno;return WHILE;}
"struct"                            {return STRUCT;}
"union"                             {return UNION;}
"return"                            {return RETURN;}
"sizeof"                            {return SIZEOF;}
"break"                             {return BREAK;}
"..."                               {return ELIPSIS;}
"=="                                {return IGUAL_IGUAL;}
"!="                                {return DISTINTO;}
"<="                                {return MENOR_IGUAL;}
">="                                {return MAYOR_IGUAL;}
"<<="                               {return CORRIMIENTO_A_IZQUIERDA_IGUAL;}
">>="                               {return CORRIMIENTO_A_DERECHA;}
"&="                                {return Y_IGUAL;}
"%="                                {return MODULO_IGUAL;}
"^="                                {return POTENCIA_IGUAL;}
"<<"                                {return CORRIMIENTO_A_IZQUIERDA;}
">>"                                {return CORRIMIENTO_A_DERECHA;}
"|="                                {return O_IGUAL;}
"++"                                {return MAS_MAS;}
"--"                                {return MENOS_MENOS;}
";"|"="|","|"{"|"}"|"("|")"|"["|"]"|"*"|"+"|"-"|"/"|"?"|":"|"&"|"|"|"^"|"!"|"~"|"%"|"<"|">" {return yytext[0];}
"+="                                {return MAS_IGUAL;}
"*="                                {return	POR_IGUAL;}
"/="                                {return	DIVISION_IGUAL;}
"-="                                {return MENOS_IGUAL;}
"&&"                                {return AND_LOGICO;}
"||"                                {return OR_LOGICO;}
"->"                                {return PUNTERO_FLECHA;}

0[0-7]*{SUFIJO_ENTERO}?             {yylval.entero=strtol(yytext,NULL,8); return CONSTANTE_OCTAL;}
{IDENTIFICADOR}                     {strcpy(yylval.cadena,yytext); return IDENTIFICADOR;}
{CONSTANTE_HEXADECIMAL}             {return CONSTANTE_HEXADECIMAL;}
{CONSTANTE_DECIMAL}                 {yylval.entero=atoi(yytext); return CONSTANTE_DECIMAL;}
{CONSTANTE_CARACTER}                {return CONSTANTE_CARACTER;}
{LITERAL_CADENA}                    {strcpy(yylval.cadena,yytext); return LITERAL_CADENA;}
[\t\n]                              {;}

{CONSTANTE_REAL}                    {yylval.real=atoi(yytext);return CONSTANTE_REAL;}
{LITERAL_CADENA}                    {;} 
{TIPO_DE_DATO}                      {;}
{ESTRUCTURA_DE_CONTROL}             {;}
{OTRAS_PALABRAS_RESERVADAS}         {;}
{OPERADOR_O_CARACTER_DE_PUNTUACION} {;} 
{ESPACIO_EN_BLANCO}|{TABULACION}    {;}
{COMENTARIO_SIMPLE}                 {;}
{COMENTARIO_UNA_LINEA}              {;}
{COMENTARIO_MULTIPLES_LINEAS}       {;}
.                                   {strcpy(yylval.INFO.cadena,yytext);yylval.INFO.linea = yylineno;return NO_RECONOCIDO;}

%%

int yywrap(void) {
    return 1;
}

