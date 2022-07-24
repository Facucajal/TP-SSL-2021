%option noyywrap
%option yylineno

%{
//#include <stdio.h>
#include "funciones.h"
NODO* listaIdentificador=NULL;
NODOPALABRARESERVADA* listaPR=NULL;
NODOCADENA* listaCadena=NULL;
NODOENTERO* listaOctal=NULL;
NODOENTERO* listaHexa=NULL;
NODOENTERO* listaDecimal=NULL;
NODOREAL* listaReal=NULL;
NODOCARACTER* listaCaracter=NULL;
NODO* listaOpOCaPuntuacion=NULL;
NODOCOMENTARIO* listaComentario=NULL;
NODONORECONOCIDO* listaNoReconocido=NULL;
%}

ESPACIO_EN_BLANCO (" ")+
TABULACION (\t)+

DIGITO_DECIMAL [0-9]
DIGITO_OCTAL [0-7]
DIGITO_HEXADECIMAL [a-fA-F0-9]

SUFIJO_REAL f|F|l|L
SECUENCIA_DIGITOS {DIGITO_DECIMAL}+
SIGNO +|-
PARTE_EXPONENTE [Ee]{SIGNO}?{SECUENCIA_DIGITOS}
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

%%

 //{CONSTANTE_REAL} {insertarEnListaReal(&listaReal,yytext);} //Real (NO FUNCIONA)
{CONSTANTE_DECIMAL}                 {insertarEnListaDecimal(&listaDecimal,yytext,yyleng);} //Entera decimal
{CONSTANTE_OCTAL}                   {insertarEnListaOctal(&listaOctal,yytext,yyleng);} //Entera octal
{CONSTANTE_HEXADECIMAL}             {insertarEnListaHexadecimal(&listaHexa,yytext,yyleng);} //Entera hexadecimal
{CONSTANTE_REAL}                    {insertarEnListaReal(&listaReal,yytext);}
{CONSTANTE_CARACTER}                {insertarEnListaCaracter(&listaCaracter,yytext);} //Caracter
{LITERAL_CADENA}                    {insertarEnListaCadena(&listaCadena, yytext, yyleng);} //Literal cadena
{TIPO_DE_DATO}                      {insertarEnListaPR(&listaPR,yytext);}
{ESTRUCTURA_DE_CONTROL}             {insertarEnListaPR(&listaPR,yytext);} //Estructuras de control
{OTRAS_PALABRAS_RESERVADAS}         {insertarEnListaPR(&listaPR,yytext);} //Otros
{IDENTIFICADOR}                     {insertarEnListaIdentificador(&listaIdentificador,yytext);} //Identificadores
{OPERADOR_O_CARACTER_DE_PUNTUACION} {insertarEnListaOpOCaPuntuacion(&listaOpOCaPuntuacion,yytext);} //Caracteres de puntuacion/Operadores
{ESPACIO_EN_BLANCO}|{TABULACION}    {;} //Ignora los espacios en blanco y las tabulaciones
{COMENTARIO_SIMPLE}                 {insertarEnListaComentario(&listaComentario,yytext,"Una linea");}
{COMENTARIO_UNA_LINEA}              {insertarEnListaComentario(&listaComentario,yytext,"Una linea");}
{COMENTARIO_MULTIPLES_LINEAS}       {insertarEnListaComentario(&listaComentario,yytext,"Multiples lineas");}
.                                   {insertarEnListaNoReconocido(&listaNoReconocido,yytext,yylineno);}

%%
int main()
{
    /*abro archivo de reporte  donde escribo las listas*/
    FILE* reporte = fopen("reporte.txt","w+");

    yyin=fopen("archivo.c","r+");
    yylex();

    /*imprimo listas*/
    imprimirListaEnArchivo(reporte,listaIdentificador,listaCadena,listaPR,listaOctal,listaHexa,listaDecimal,listaReal,listaCaracter,listaOpOCaPuntuacion,listaComentario,listaNoReconocido);

    /*Cierro archivo reporte*/
    fclose(reporte);
    fclose(yyin);

    return 0;
}