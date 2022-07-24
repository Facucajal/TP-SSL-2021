
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef struct nodoparametros
{
    char* nombre;
    struct nodoparametros* sig;
    int longitud;
}NODOPARAMETROS;

typedef struct nodovariables
{
    int linea;
    char* nombre;
    char* tipo;
    struct nodovariables* sig;
    int longitud;   //Solo se suma cuando son parametros
}NODOVARIABLES;


typedef struct nodofunciones
{
    int linea;
    char* nombre;
    char* tipo;
    int cantidad;
    struct nodovariables* variable;
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


typedef struct nodeclarados
{
    int linea;
    char* nombre;
    struct nodeclarados* sig;
}NODONODECLARADOS;

typedef struct erroresSemanticosDeTipos
{
    char* nombreFuncion;
    char* nombreIdentificador;
    char* tipoIdentificador;
    char* tipoParametroEsperado;
    struct erroresSemanticosDeTipos* sig;
}NODOERRORDETIPOSDEFUNCION;

typedef struct erroresSemanticosDeFaltaDeTipos
{
     char* nombreFuncion;
     int cantidadVariablesDeclaradas;
     int cantIdentificadoresInvocados;
         struct erroresSemanticosDeFaltaDeTipos* sig;
}NODOERRORFALTADETIPOS;

typedef struct erroresSemanticosDeSobraDeTipos
{
     char* nombreFuncion;
     int cantidadVariablesDeclaradas;
     int cantIdentificadoresInvocados;
     struct erroresSemanticosDeSobraDeTipos* sig;
}NODOSOBRADETIPOS;

typedef struct nodoErroresSintacticos
{
     int linea;
     struct nodoErroresSintacticos* sig;
}NODOERRORESSINTACTICOS;




void inicializarNodoVariablesVacio(NODOVARIABLES* nuevo);

NODOVARIABLES* pedirMemoriaEInicializarNodoVariables();

void agregarNuevoNodoVariablesAlFinal(NODOVARIABLES** nodo,NODOVARIABLES* nuevoNodo);

void insertarEnListaVariables(NODOVARIABLES** lista, char *nombre,char*tipo, int linea,NODOVARIABLES** listaDobleDefinicion);

void insertarEnListaDobleDeclaracion(char *nombre, int linea,NODOVARIABLES** listaDobleDeclaracion);

void insertarEnListaFunciones(NODOFUNCIONES** lista, char *nombre,char*tipo, int linea);

void insertarEnListaSentencias(NODOSENTENCIAS** lista, char *tipoSentencia,int linea);

void insertarEnListaNoReconocido(NODONORECONOCIDO **lista, char *texto, int linea);

void insertarEnListaEstructurasNoValidas(NODOESTRUCTURASNOVALIDAS** lista, char *estructura,int linea);
int esElTipoDeLaFuncion(NODOTIPOS **lista, char *tipoEntrante, int lineaEntrante);


void imprimirListaEnArchivo(FILE* archivo,NODOVARIABLES* listavariables,NODONORECONOCIDO *listaNoReconocido,NODOFUNCIONES* listafunciones,NODOSENTENCIAS* listaSentencias,NODOVARIABLES* listaDobleDeclaracion,NODOVARIABLES* listaerrordetipos, NODONODECLARADOS* listaNoDeclarados);

int esTipoDeDatoValido(NODOVARIABLES** listavariables,char *identificador);

void insertarEnListaParametros(NODOVARIABLES** lista, char *identificador,char*tipo);
void insertarFuncionConParametro(char* nombre,char* tipo,char* identificador,NODOFUNCIONES** lista);
void agregarVariableALaFuncion(char* nombre,char* tipo,char* identificador,NODOFUNCIONES** lista);

//int verificarFuncionInvocada(NODOFUNCIONES** lista,char* nombreFuncion,char* identificador,NODOVARIABLES**  variables);
int estaEnListaFunciones(NODOFUNCIONES** lista, char *nombre);

char* tipoDeDato(NODOVARIABLES** lista, char* identificador);
int esTipoCorrecto(NODOVARIABLES** lista, char* identificador);

void insertarEnListaErrorDeTipos(NODOVARIABLES** lista, char *nombre,char*tipo,int linea);

void insertarEnListaNoDeclarados(NODONODECLARADOS**lista, char* nombre, int linea);

void esPuntero(NODOVARIABLES** lista);

char* buscarTipoId(char* nombre,NODOVARIABLES**  variables);
void compararParametros(NODOVARIABLES**  parametros1,NODOPARAMETROS** parametros2,NODOVARIABLES**  variables,char* nombreFuncion);
void verificarFuncionInvocada(NODOFUNCIONES** lista,char* nombreFuncion,NODOPARAMETROS** parametros,NODOVARIABLES**  variables);
void insertarIdentificadoresInvocados(NODOPARAMETROS** lista,char* identificador);

NODOPARAMETROS* pedirMemoriaEInicializarNodoParametros();
void inicializarNodoVariablesVacioParametro(NODOPARAMETROS* nuevo);

int cantidadDeParametros(NODOVARIABLES *lista);


int cantidadDeParametrosInvocados(NODOPARAMETROS*lista);


void insertarListaErrorSemanticoDeTiposDeFuncion(NODOERRORDETIPOSDEFUNCION** listaErroresSemanticosDeTipos,char * nombreFuncion,char* nombreIdentificador,char* tipoidentificador, char*tipoParametroEsperado);

void insertarListaErrorSemanticoFaltaDeTipos(NODOERRORFALTADETIPOS** lista,char* nombreFuncion,int cantidadDeVariablesDeclaradas, int parametrosInvocadosTotales);


void insertarListaErrorSemanticoSobraDeTipos(NODOSOBRADETIPOS** lista,char* nombreFuncion,int cantidadDeVariablesDeclaradas, int parametrosInvocadosTotales);

void insertarErrorSintactico(NODOERRORESSINTACTICOS** lista,int linea);