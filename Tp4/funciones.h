
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef struct nodovariables
{
    int linea;
    char* nombre;
    char* tipo;
    struct nodovariables* sig;
}NODOVARIABLES;

typedef struct nodofunciones
{
    int linea;
    char* nombre;
    char* tipo;
    struct nodofunciones* sig;
}NODOFUNCIONES;

typedef struct nodonosentencias
{
    char* tipoSentencia;
    int linea;
    struct nodonosentencias* sig;
}NODOSENTENCIAS;

typedef struct nodonoreconocido
{
    char* texto;
    int linea;
    struct nodonoreconocido* sig;
}NODONORECONOCIDO;

typedef struct nodoestructurasnovalidas
{
    char* estructura;
    int linea;
    struct nodoestructurasnovalidas* sig;
}NODOESTRUCTURASNOVALIDAS;


typedef struct nodotipos
{
    int linea;
    char* tipo;
    struct nodotipos* sig;
}NODOTIPOS;

void insertarEnListaVariables(NODOVARIABLES** lista, char *nombre,char*tipo, int linea);

void insertarEnListaFunciones(NODOFUNCIONES** lista, char *nombre,char*tipo, int linea);

void insertarEnListaSentencias(NODOSENTENCIAS** lista, char *tipoSentencia,int linea);

void insertarEnListaNoReconocido(NODONORECONOCIDO **lista, char *texto, int linea);

void insertarEnListaEstructurasNoValidas(NODOESTRUCTURASNOVALIDAS** lista, char *estructura,int linea);
int esElTipoDeLaFuncion(NODOTIPOS **lista, char *tipoEntrante, int lineaEntrante);


void imprimirListaEnArchivo(FILE* archivo,NODOVARIABLES* listavariables,NODONORECONOCIDO *listaNoReconocido,NODOFUNCIONES* listafunciones,NODOSENTENCIAS* listaSentencias);

