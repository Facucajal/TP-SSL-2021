#include "funciones.h"
#define BASE 8
#define BASE2 16

////////////////////LISTA IDENTIFICADOR////////////////////
//Devuelve el NODO o NULL si no lo encuentra
NODO *buscarEnLista(NODO *lista, char *texto)
{
    NODO *aux = lista;
    while (aux != NULL)
    {
        if (strcmp(aux->texto, texto) == 0)
        {
            return aux;
        }
        aux = aux->sig;
    }
    return aux;
}

int compararCadenas(char cadena1[],char cadena2[]){ //La primer cadena es mayor alfabeticamente
	int cont_cadena1;
	char caracterCadena1;
    int cont_cadena2;
	char caracterCadena2;
    int longitud1;
    int longitud2;

    longitud1 = strlen(cadena1);
    longitud2 = strlen(cadena2);

    char auxCadena1[longitud1];
    char auxCadena2[longitud2];

    strcpy(auxCadena1,cadena1);
    strcpy(auxCadena2,cadena2);
    strlwr(auxCadena1); // Convierte las cadenas en minusculas para compararlas sin inconvenientes
    strlwr(auxCadena2);

  	for(cont_cadena1=0,cont_cadena2=0;cont_cadena1<longitud1,cont_cadena2<longitud2;cont_cadena1++,cont_cadena2++)
      {
    	caracterCadena1= auxCadena1[cont_cadena1];
        caracterCadena2= auxCadena2[cont_cadena2];
			
    	if(caracterCadena1 < caracterCadena2) 
		{
			return 1; // si es positivo es porque es menor
		}
		if(caracterCadena1 > caracterCadena2)
		{
			return -1;  // si es negativo es porque es mayor
    	}	
  	}
  	return 0; // si es 0, es porque son iguales
}

//Insertar un nodo al final de la lista si este no esta
void insertarEnListaIdentificador(NODO **lista, char *texto)
{
    NODO *nodoAInsertar = buscarEnLista(*lista, texto);
    if (nodoAInsertar == NULL)
    {
        NODO *ptr = *lista;
        NODO *nuevo = (NODO *)malloc(sizeof(NODO));

        nuevo->texto = strdup(texto);
        nuevo->cantidad = 1;

        if (*lista == NULL || (compararCadenas(nuevo->texto,ptr->texto)>=0)) //si el nuevo es menor alfabeticamente
        {
            nuevo->sig = *lista;
            *lista = nuevo;
        }
        else
        {   
            NODO *ant = *lista;
            while (ptr != NULL && (compararCadenas(nuevo->texto,ptr->texto)<0)) //si el nuevo es mayor alfabeticamente
            {

            ant=ptr;
            ptr = ptr->sig;
            }

           ant->sig = nuevo;
           nuevo->sig = ptr;
        }
    }
    else
    {
        nodoAInsertar->cantidad = (nodoAInsertar->cantidad) + 1;
    }
}

////////////////////LISTA LITERAL CADENA////////////////////
void insertarEnListaCadena(NODOCADENA **lista, char *texto, int longitud)
{
    NODOCADENA *nuevo = (NODOCADENA *)malloc(sizeof(NODOCADENA));
    NODOCADENA *ptr = *lista;
    //nuevo->numeroDeLinea=numeroDeLinea;
    nuevo->texto = strdup(texto);
    //nuevo->longitudTexto=longTexto;
    nuevo->longitud = longitud;

    if (*lista == NULL || (nuevo->longitud <= (ptr->longitud)))
    {
        nuevo->sig = *lista;
        *lista = nuevo;
    }
    else
    {
        NODOCADENA *antp = *lista;
        while ((ptr!=NULL) && (nuevo->longitud > ptr->longitud ))
        {
            *antp=*ptr;
            ptr = ptr->sig;
        }

        antp->sig = nuevo;
        nuevo->sig = ptr;
    }
}

////////////////////LISTA PALABRA RESERVADA////////////////////
void insertarEnListaPR(NODOPALABRARESERVADA **lista, char *texto)
{
    NODOPALABRARESERVADA *actual = *lista;
    NODOPALABRARESERVADA *nuevo = (NODOPALABRARESERVADA *)malloc(sizeof(NODOPALABRARESERVADA));
    nuevo->texto = strdup(texto);

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

////////////////////LISTA CONSTANTE OCTAL////////////////////
unsigned long long octalADecimal(char *cadenaOctal, int longitud)
{
    unsigned long long decimal = 0;
    int potencia = 0;
    for (int i = longitud - 1; i >= 0; i--)
    {

        int valorActual = cadenaOctal[i] - '0';
        // Elevar 8 a la potencia que se va incrementando, y multiplicarla por el
        // valor
        unsigned long long elevado = pow(BASE, potencia) * valorActual;

        // Agregar al número
        decimal += elevado;
        // Avanzar en la potencia
        potencia++;
    }
    return decimal;
}

void insertarEnListaOctal(NODOENTERO **lista, char *num, int longitud)
{
    NODOENTERO *actual = *lista;
    NODOENTERO *nuevo = (NODOENTERO *)malloc(sizeof(NODOENTERO));
    nuevo->valor = strdup(num);
    nuevo->valorDecimal = octalADecimal(num, longitud);

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

////////////////////LISTA CONSTANTE HEXADECIMAL////////////////////
int caracterHexadecimalADecimal(char caracter)
{
    if (isdigit(caracter))
        return caracter - '0';
    return 10 + (toupper(caracter) - 'A');
}

unsigned long long hexadecimalADecimal(char *cadenaHexadecimal, int longitud)
{
    unsigned long long decimal = 0;
    int potencia = 0;
    for (int i = longitud - 1; i >= 0; i--)
    {
        // Obtener el decimal, por ejemplo para A es 10, para F 15 y para 9 es 9
        int valorActual = caracterHexadecimalADecimal(cadenaHexadecimal[i]);
        // Elevar 16 a la potencia que se va incrementando, y multiplicarla por el
        // valor
        unsigned long long elevado = pow(BASE2, potencia) * valorActual;

        // Agregar al número
        decimal += elevado;
        // Avanzar en la potencia
        potencia++;
    }
    return decimal;
}

void insertarEnListaHexadecimal(NODOENTERO **lista, char *num, int longitud)
{
    NODOENTERO *actual = *lista;
    NODOENTERO *nuevo = (NODOENTERO *)malloc(sizeof(NODOENTERO));
    nuevo->valor = strdup(num);
    nuevo->valorDecimal = hexadecimalADecimal(num, longitud);

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

////////////////////LISTA CONSTANTE DECIMAL////////////////////
void insertarEnListaDecimal(NODOENTERO **lista, char *num, int longitud)
{
    int decimal = atoi(num);
    NODOENTERO *actual = *lista;
    NODOENTERO *nuevo = (NODOENTERO *)malloc(sizeof(NODOENTERO));

    nuevo->valor = strdup(num);
    nuevo->valorDecimal = decimal;

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

////////////////////LISTA CONSTANTE REAL////////////////////
void insertarEnListaReal(NODOREAL **lista, char *num)
{
    int decimal = atoi(num);
    NODOREAL *actual = *lista;
    NODOREAL *nuevo = (NODOREAL *)malloc(sizeof(NODOREAL));

    float real=atof(num);
    double mantisa,parteEntera;
    mantisa=modf(real,&parteEntera);

    nuevo->valor = strdup(num);
    nuevo->mantisa=mantisa;
    nuevo->entera=parteEntera;

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

////////////////////LISTA CONSTANTE CARACTER////////////////////
void insertarEnListaCaracter(NODOCARACTER **lista, char* caracter)
{
    NODOCARACTER *actual = *lista;
    NODOCARACTER *nuevo = (NODOCARACTER *)malloc(sizeof(NODOCARACTER));

   nuevo->caracter=strdup(caracter);

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

////////////////////LISTA OPERADOR O CARACTER DE PUNTUACION////////////////////
void insertarEnListaOpOCaPuntuacion(NODO** lista, char* texto)
{   
    if(strcmp(texto,"(")==0 || strcmp(texto,")")==0)    
        {
            texto = "()";
        }
    else if(strcmp(texto,"[")==0 || strcmp(texto,"]")==0)
        {
            texto = "[]";
        }
    else if(strcmp(texto,"{")==0 || strcmp(texto,"}")==0)
        {
            texto = "{}";
        }
    NODO *nodoAInsertar = buscarEnLista(*lista, texto);
    if (nodoAInsertar == NULL)
    {   
        NODO* actual=*lista;
		NODO* nuevo=(NODO*) malloc(sizeof(NODO));

        if(strcmp(texto,"()")==0 || strcmp(texto,"[]")==0 || strcmp(texto,"{}")==0)
        {
            nuevo->texto = strdup(texto);
            nuevo->cantidad = 0.5;
        }
        else
        {
            nuevo->texto = strdup(texto);
            nuevo->cantidad = 1;
        }
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
    else
    {   
        if(strcmp(texto,"()")==0 || strcmp(texto,"[]")==0 || strcmp(texto,"{}")==0)
        {
            nodoAInsertar->cantidad = (nodoAInsertar->cantidad) + 0.5; // le sumo la mitad ya que entra dos veces cada vez que aparece
        }
        else{
            nodoAInsertar->cantidad = (nodoAInsertar->cantidad) + 1;
        }
    }
}

////////////////////LISTA COMENTARIO////////////////////
void insertarEnListaComentario(NODOCOMENTARIO **lista, char *texto, char* tipo)
{
    NODOCOMENTARIO* actual=*lista;
	NODOCOMENTARIO* nuevo=(NODOCOMENTARIO*) malloc(sizeof(NODOCOMENTARIO));
	
	nuevo->texto=strdup(texto);
	nuevo->tipo = tipo;

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

////////////////////LISTA CADENA O CARACTER NO RECONOCIDO////////////////////
void insertarEnListaNoReconocido(NODONORECONOCIDO **lista, char *texto, int numeroDeLinea)
{
	NODONORECONOCIDO* actual=*lista;
	NODONORECONOCIDO* nuevo=(NODONORECONOCIDO*) malloc(sizeof(NODONORECONOCIDO));
	
	nuevo->numeroDeLinea=numeroDeLinea;
	nuevo->texto=strdup(texto);
	
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









NODOENTERO *buscarEnListaEntero(NODOENTERO *lista, char *texto)
{
    NODOENTERO *aux = lista;
    while (aux != NULL)
    {
        if (strcmp(aux->valor, texto) == 0)
        {
            return aux;
        }
        aux = aux->sig;
    }
    return aux;
}


/*void mostrarLista(NODO *lista)
{
    printf("\nListado de Identificadores:\n");
    NODO *aux = lista;
    while (aux != NULL)
    {
        printf("Identificador: %s  ;  ", aux->texto);
        printf("Cantidad: %0.f \n", aux->cantidad);
        aux = aux->sig;
    }
}
void mostrarListaCadena(NODOCADENA *lista)
{
    printf("\nListado de literales cadena:\n");
    NODOCADENA *aux = lista;
    while (aux != NULL)
    {
        printf("Literal cadena: %s  ;  ", aux->texto);
        printf("Longitud: %i \n", (aux->longitud) - 2);
        aux = aux->sig;
    }
}
void eliminarPrimeroListaPR(NODOPALABRARESERVADA *lista)
{   
      printf("Listado de palabras reservadas:\n");

     while(lista!=NULL)
     {
        NODOPALABRARESERVADA *ptr=lista;
        lista=lista->sig;
        printf("Palabra Reservada: %s \n",ptr->texto);
        free(ptr);
    }   
}
void mostrarListaOctal(NODOENTERO *lista)
{
    printf("\nListado de enteros octales:\n");
    NODOENTERO *aux = lista;
    while (aux != NULL)
    {
        printf("Entero Octal: %s  ;  ", aux->valor);
        printf("Valor decimal: %llu \n", aux->valorDecimal);
        aux = aux->sig;
    }
}
void mostrarListaHexadecimal(NODOENTERO *lista)
{
    printf("\nListado de enteros hexadecimales:\n");
    NODOENTERO *aux = lista;
    while (aux != NULL)
    {
        printf("Entero Hexadecimal: %s  ;  ", aux->valor);
        printf("Valor decimal: %llu \n", aux->valorDecimal);
        aux = aux->sig;
    }
}
void mostrarListaDecimal(NODOENTERO *lista)
{
    printf("\nListado de enteros decimales:\n");
    NODOENTERO *aux = lista;
    int acumulador=0;
    while (aux != NULL)
    {
        printf("Entero Decimal: %s\n", aux->valor);
        acumulador = acumulador + aux->valorDecimal;
        aux = aux->sig;
    }
    printf("Total acumulado: %i\n", acumulador);
}
void mostrarListaReal(NODOREAL *lista)
{
    NODOREAL *aux = lista;
    printf("\nListado de numeros reales:\n");
    printf("Numero real\t   Parte Entera\t      Parte Mantisa\n");
    while (aux != NULL)
    {
        printf("   %s",aux->valor);
        printf("\t\t\t%.0f",aux->entera);
        printf("\t\t%.2f\n",aux->mantisa);
        aux = aux->sig;
    }
}
void mostrarListaCaracter(NODOCARACTER *lista)
{
    NODOCARACTER *aux = lista;
    int cantidad = 1;
    printf("\nListado de constantes caracteres:\n");

    printf("Orden\tConstante\n");
    while (aux != NULL)
    {
        printf("  %i.       %s\n",cantidad,aux->caracter);
        cantidad++;
        aux = aux->sig;
    }
}
void mostrarListaOpOCaPuntuacion(NODO *lista)
{
    printf("\nListado de Operadores o Caracteres de Puntuacion:\n");
    NODO *aux = lista;
    while (aux != NULL)
    {
        printf("Operador o caracter: %s  ;  ", aux->texto);
        printf("Cantidad: %0.f \n", aux->cantidad);
        aux = aux->sig;
    }
}
void mostrarListaComentario(NODOCOMENTARIO *lista)
{
    NODOCOMENTARIO *aux = lista;
    printf("\nListado de Comentarios:\n");
    printf("Tipo\t\t\tComentario\n");
    while (aux != NULL)
    {
        printf("%s\t\t%s\n",aux->tipo,aux->texto);
        aux = aux->sig;
    }
}
void mostrarListaNoReconocido(NODONORECONOCIDO *lista)
{
    NODONORECONOCIDO *aux = lista;
    printf("\nListado de Cadenas o Caracteres no Reconocidos:\n");
    printf("Nro. de linea\tCadena/Caracter\n");
    while (aux != NULL)
    {
        printf("    %i\t              %s\n",aux->numeroDeLinea,aux->texto);
        aux = aux->sig;
    }
}*/




////////////////////IMPRIMIR LISTAS EN EL ARCHIVO////////////////////
void imprimirListaEnArchivo(FILE* archivo,NODO* listaIdentificador,NODOCADENA* listaCadena,NODOPALABRARESERVADA* listaPR, NODOENTERO* listaOctal, NODOENTERO* listaHexa, NODOENTERO* listaDecimal, NODOREAL* listaReal, NODOCARACTER* listaCaracter, NODO* listaOpOCaPuntuacion, NODOCOMENTARIO* listaComentario, NODONORECONOCIDO* listaNoReconocido)
{
    
	fprintf(archivo,"\n________________________________________________________________________________________\n\n");
	
    //Imprimo Lista de Identificadores
    fprintf(archivo,"Listado de Identificadores:\n\n");
    while(listaIdentificador!=NULL)
	{
        NODO *ptr=listaIdentificador;
        listaIdentificador=listaIdentificador->sig;
		fprintf(archivo,"Identificador: %s  ;  ",ptr->texto);
        fprintf(archivo,"Cantidad: %0.f \n",ptr->cantidad);
		free(ptr);
	}
    fprintf(archivo,"________________________________________________________________________________________\n\n");


    //Imprimo Lista de Literal Cadena
    fprintf(archivo,"Listado de Literal Cadena:\n\n");
    while(listaCadena!=NULL)
	{
        NODOCADENA *ptr=listaCadena;
        listaCadena=listaCadena->sig;
		fprintf(archivo,"Literal cadena: %s  ;  ",ptr->texto);
        fprintf(archivo,"Longitud: %i \n", (ptr->longitud) - 2);
		free(ptr);
	}
    fprintf(archivo,"________________________________________________________________________________________\n\n");


    //Imprimo Lista de Palabras reservadas
    fprintf(archivo,"Listado de palabras reservadas:\n\n");
	while(listaPR!=NULL)
	{
        NODOPALABRARESERVADA *ptr=listaPR;
        listaPR=listaPR->sig;
		fprintf(archivo,"Palabra Reservada: %s\n",ptr->texto);
		free(ptr);
	}
    fprintf(archivo,"________________________________________________________________________________________\n\n");


    
    //Imprimo Lista de Constante Octal
    fprintf(archivo,"Listado de enteros octales:\n\n");
    while(listaOctal!=NULL)
	{
        NODOENTERO *ptr=listaOctal;
        listaOctal=listaOctal->sig;
		fprintf(archivo,"Entero Octal: %s  ;  ",ptr->valor);
        fprintf(archivo,"Valor decimal: %llu \n",ptr->valorDecimal);
		free(ptr);
	}
    fprintf(archivo,"________________________________________________________________________________________\n\n");

    //Imprimo Lista de Constante Hexadecimal
    fprintf(archivo,"Listado de enteros hexadecimales:\n\n");
    while(listaHexa!=NULL)
	{
        NODOENTERO *ptr=listaHexa;
        listaHexa=listaHexa->sig;
		fprintf(archivo,"Entero Hexadecimal: %s  ;  ",ptr->valor);
        fprintf(archivo,"Valor decimal: %llu \n",ptr->valorDecimal);
		free(ptr);
	}
    fprintf(archivo,"________________________________________________________________________________________\n\n");

    //Imprimo Lista de Constante Decimal
    fprintf(archivo,"Listado de enteros decimales:\n\n");
    int acumulador=0;
    while(listaDecimal!=NULL)
	{
        NODOENTERO *ptr=listaDecimal;
        listaDecimal=listaDecimal->sig;
		fprintf(archivo,"Entero Decimal: %s\n",ptr->valor);
        acumulador = acumulador + ptr->valorDecimal;
		free(ptr);
	}
    fprintf(archivo,"Total acumulado: %i\n",acumulador);
    fprintf(archivo,"________________________________________________________________________________________\n\n");


    //Imprimo Lista de Numeros Reales
    fprintf(archivo,"Listado de numeros reales:\n\n");
    fprintf(archivo,"Numero real\t   Parte Entera\t    Parte Mantisa\n");
    while(listaReal!=NULL)
	{
        NODOREAL *ptr=listaReal;
        listaReal=listaReal->sig;
		fprintf(archivo,"   %s",ptr->valor);
        fprintf(archivo,"\t\t\t\t\t\t\t%.0f",ptr->entera);
        fprintf(archivo,"\t\t\t\t%.2f\n",ptr->mantisa);
		free(ptr);
	}
    fprintf(archivo,"________________________________________________________________________________________\n\n");


    //Imprimo Lista de Constante Caracter
    fprintf(archivo,"Listado de constantes caracteres:\n\n");
fprintf(archivo,"Orden\t\tConstante\n");
    int orden = 1;
    while(listaCaracter!=NULL)
	{
        NODOCARACTER *ptr=listaCaracter;
        listaCaracter=listaCaracter->sig;
		fprintf(archivo,"  %i.       %s\n",orden,ptr->caracter);
        orden++;
		free(ptr);
	}
    fprintf(archivo,"________________________________________________________________________________________\n\n");


    //Imprimo Lista de Operador o Caracter de Puntuacion
    fprintf(archivo,"Listado de Operadores o Caracteres de Puntuacion:\n\n");
    while(listaOpOCaPuntuacion!=NULL)
	{
        NODO *ptr=listaOpOCaPuntuacion;
        listaOpOCaPuntuacion=listaOpOCaPuntuacion->sig;
		fprintf(archivo,"Operador o caracter: %s  ;  ", ptr->texto);
        fprintf(archivo,"Cantidad: %0.f \n", ptr->cantidad);
		free(ptr);
	}
    fprintf(archivo,"________________________________________________________________________________________\n\n");


    //Imprimo Lista de Comentarios
    fprintf(archivo,"Listado de Comentarios:\n\n");
    //fprintf(archivo,"Tipo\t\t\t\t\t\t\t\tComentario\n");
    while(listaComentario!=NULL)
	{
        NODOCOMENTARIO *ptr=listaComentario;
        listaComentario=listaComentario->sig;
		fprintf(archivo,"Comentario de %s:\n%s\n\n",ptr->tipo,ptr->texto);
		free(ptr);
	}
    fprintf(archivo,"________________________________________________________________________________________\n\n");


    //Imprimo Lista de Cadenas o Caracteres no reconocidos
    fprintf(archivo,"Listado de Cadenas o Caracteres no Reconocidos:\n\n");
    fprintf(archivo,"Nro. de linea\t\tCadena/Caracter\n");
    while(listaNoReconocido!=NULL)
	{
        NODONORECONOCIDO *ptr=listaNoReconocido;
        listaNoReconocido=listaNoReconocido->sig;
		fprintf(archivo,"    %i\t              %s\n",ptr->numeroDeLinea,ptr->texto);
		free(ptr);
	}
    fprintf(archivo,"________________________________________________________________________________________\n\n");
}

	/*Para Alinear tabla
	for(i=0;i<(longMaxima-strlen("TOKEN"));i++)
	{
		fprintf(archivo," ");
	}*/
	