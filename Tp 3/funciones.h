#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


//Estructura nodo para guardar cada token
typedef struct nodo
{
    float cantidad;
    char* texto;
    struct nodo* sig;
}NODO;

typedef struct nodoCadena
{
    int longitud;
    char* texto;
    struct nodoCadena* sig;
}NODOCADENA;

typedef struct nodoPalabraReservada
{
    char* texto;
    struct nodoPalabraReservada* sig;
}NODOPALABRARESERVADA;


typedef struct nodoEntero
{
    char* valor;
    unsigned long long valorDecimal;
    struct nodoEntero* sig;
}NODOENTERO;

typedef struct nodoReal
{
    char* valor;
    double mantisa;
    double entera;
    struct nodoReal* sig;
}NODOREAL;

typedef struct nodoCaracter
{
    char* caracter;
    struct nodoCaracter* sig;
}NODOCARACTER;

typedef struct nodonoreconocido
{
    char* texto;
    int numeroDeLinea;
    struct nodonoreconocido* sig;
}NODONORECONOCIDO;

typedef struct nodocomentario
{
    char* texto;
    char* tipo;
    struct nodocomentario* sig;
}NODOCOMENTARIO;

//Devuelve el NODO o NULL si no lo encuentra
NODO* buscarEnLista(NODO* lislistaIdentificadorta,char* texto);
int compararCadenas(char palabra[],char palabra2[]);
//Insertar un nodo al final de la lista si este no esta
void insertarEnListaIdentificador(NODO** lista, char* texto);

void insertarEnListaCadena(NODOCADENA **lista, char *texto, int longitud);

void insertarEnListaPR(NODOPALABRARESERVADA** lista, char* texto);

void insertarEnListaOctal(NODOENTERO** lista, char *num,int longitud);

void insertarEnListaHexadecimal(NODOENTERO** lista, char *num,int longitud);

void insertarEnListaDecimal(NODOENTERO** lista, char *num,int longitud);

void insertarEnListaReal(NODOREAL **lista, char *num);

void insertarEnListaCaracter(NODOCARACTER **lista, char* caracter);

void insertarEnListaOpOCaPuntuacion(NODO** lista, char* texto);

void insertarEnListaComentario(NODOCOMENTARIO **lista, char *texto, char* tipo);

void insertarEnListaNoReconocido(NODONORECONOCIDO **lista, char *texto, int numeroDeLinea);



/*
void mostrarLista(NODO* listaIdentificador);
void mostrarListaCadena(NODOCADENA* lista);
void eliminarPrimeroListaPR(NODOPALABRARESERVADA* listaPR);
void mostrarListaOctal(NODOENTERO *lista);
void mostrarListaHexadecimal(NODOENTERO *lista);
void mostrarListaDecimal(NODOENTERO *lista);
void mostrarListaReal(NODOREAL *lista);
void mostrarListaCaracter(NODOCARACTER *lista);
void mostrarListaOpOCaPuntuacion(NODO *lista);
void mostrarListaComentario(NODOCOMENTARIO *lista);
void mostrarListaNoReconocido(NODONORECONOCIDO *lista);
*/

void imprimirListaEnArchivo(FILE* archivo,NODO* listaIdentificador,NODOCADENA* listaCadena,NODOPALABRARESERVADA* listaPR, NODOENTERO* listaOctal, NODOENTERO* listaHexa, NODOENTERO* listaDecimal, NODOREAL* listaReal, NODOCARACTER* listaCaracter, NODO* listaOpOCaPuntuacion, NODOCOMENTARIO* listaComentario, NODONORECONOCIDO* listaNoReconocido);
