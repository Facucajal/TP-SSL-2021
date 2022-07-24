#include "funciones.h"
/*
void insertarEnListaVariables(NODOVARIABLES** lista, char *nombre,char*tipo, int linea,NODOVARIABLES** listaDobleDeclaracion)
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
            if(strcmp(ptr->nombre,nombre)==0)
            {
                //Doble declaracion
                insertarEnListaDobleDeclaracion(nombre,linea,listaDobleDeclaracion);
            }
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
void imprimirListaEnArchivo(FILE* archivo,NODOVARIABLES* listavariables,NODONORECONOCIDO *listaNoReconocido,NODOFUNCIONES* listafunciones,NODOSENTENCIAS* listaSentencias,NODOVARIABLES* listaDobleDeclaracion)
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

*/