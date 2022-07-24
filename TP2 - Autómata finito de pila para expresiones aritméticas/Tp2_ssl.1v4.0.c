#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

#define N 100

#define q0 0
#define q1 1
#define q2 2
#define q3 3
#define __ '_'


typedef struct nodo
{
	char info;
	struct nodo* sig;
}Nodo;


typedef struct transicion
{
	int estadoActual;
	char caracterDeEntradaLeido;
	char cimaDePila;
	char simbolosAAgregarEnLaPila[3];
	int siguienteEstado;
}TRANSICION;

void iniciarPila(Nodo** p);

void push(Nodo** p,char c);

void pop(Nodo** p);

char cimaDePila (Nodo* p);

void mostrarPila(Nodo* p);

int pilaVacia(Nodo* p);

void evaluar(TRANSICION* transicion);

void imprimirTransicion(TRANSICION transicion);

int respondioSI(char* respuesta);




TRANSICION matriz[7][5]={ //si leo '0'   			si leo n='1-9'        si leo o='+-*/'        	si leo ' ('          		 si leo ')'
                    {{__,'_','_',"__",__},		{q0,'n','$',"$",q1},  	{__,'_','_',"__",__},	{q0,'(','R',"R$",q0},	{__,'_','_',"__",__}},    //(q0,$)
					{{q1,'0','$',"$",q1},		{q1,'n','$',"$",q1},  	{q1,'o','$',"$",q0},	{__,'(','_',"__",__},	{__,'_','_',"__",__}},    // (q1,$)+
					{{__,'_','_',"__",__},		{q0,'n','R',"R",q1},  	{__,'_','_',"__",__},   {q0,'(','$',"RR",q0},	{__,'_','_',"__",__}},    // (q0,R)
					{{q1,'0','R',"R",q1},		{q1,'n','R',"R",q1},  	{q1,'o','R',"R",q0},	{__,'_','_',"__",__},	{q1,')','R',"EP",q2}},    // (q1,R)
					{{__,'_','_',"__",__},		{__,'_','_',"__",__},	{q0,'o','R',"R",q0},	{__,'_','_',"__",__},	{q2,')','R',"EP",q2}},    // (q2,R)
					{{__,'_','_',"__",__},		{__,'_','_',"__",__},  	{q2,'o','$',"$",q0},	{__,'_','_',"__",__},	{__,')','_',"__",__}},    // (q2,$)+
                    {{q3,'_','_',"__",q3},      {q3,'_','_',"__",q3},  	{q3,'_','_',"__",q3},  	{q3,'_','_',"__",q3},   {q3,'_','_',"__",q3}}     // Rechazo
                    };




int main()
{
	char respuesta[]="SI";
	int i=0,j=0,c;
	char* cadenaSinEspacios=(char*) malloc(N);
	Nodo* p= NULL;
	TRANSICION transicion;
	
	while(respondioSI(respuesta))
	{
		char* cadenaSinEspacios=(char*) malloc(N);
	

		//Inicializo la Pila con $
		iniciarPila(&p);
	
	
		//Pido al usuario que ingrese una cadena
		printf("\n Ingrese una expresion aritmetica: ");
	
		//NO GUARDO LOS ESPACIOS EN BLANCO
		for(i=0;(c=getc(stdin)) != '\n';)
		{
			if(c!=32)//32 es espacio en blanco en tabla ascii
			{
				cadenaSinEspacios[i]=c;
				i++;
			}
		}
	
		cadenaSinEspacios[i] = '\0'; //tope termina con el caracter especial
		
		printf("\n CADENA LEIDA SIN ESPACIOS : %s\n",cadenaSinEspacios );
		
	
		//INICIALIZO TRANSICION
		transicion.estadoActual=q0;
		transicion.caracterDeEntradaLeido = cadenaSinEspacios[0];
		transicion.cimaDePila = cimaDePila(p);
		strcpy(transicion.simbolosAAgregarEnLaPila,"__"); // agrego contenido a la cadena vacia
		transicion.siguienteEstado=__;
	
		//Evaluo caracter a caracter
		for(j=0;j<strlen(cadenaSinEspacios);)
		{
			evaluar(&transicion);  // evalua caracter a caracter la cadena
			printf("\nTRANSICION\n");
			imprimirTransicion(transicion);
	
			pop(&p);//HAGO POP DEL ELEMENTO EN LA CIMA DE LA PILA
	

			//Pregunta si la longitud de simbolosAAgregar es igual a...
			if(strcmp(transicion.simbolosAAgregarEnLaPila,"$")==0 || strcmp(transicion.simbolosAAgregarEnLaPila,"R")==0 ) //Agrego solamente "$" o "R"
			{
	        	push(&p,transicion.simbolosAAgregarEnLaPila[0]);
	        }
	        
	        if((strcmp(transicion.simbolosAAgregarEnLaPila,"R$")==0) ||  strcmp(transicion.simbolosAAgregarEnLaPila,"RR")==0)//Agrego solamente "R$" o "RR"
			{
	            push(&p,transicion.simbolosAAgregarEnLaPila[1]);
	            push(&p,transicion.simbolosAAgregarEnLaPila[0]);
	        }
	
	
			//IMPRIMO PILA
			printf("\t PILA:\n");
			mostrarPila(p);
	
			j++;//LEO EL SIGUIENTE CARACTER
	
	        transicion.estadoActual=transicion.siguienteEstado;
			transicion.cimaDePila=cimaDePila(p);
			transicion.caracterDeEntradaLeido=cadenaSinEspacios[j];
			//Sigue analizando a partir de los resultados de evaluar
		}
	
	
	
		//quito el simbolo $
		pop(&p);
	
		if((transicion.estadoActual==q3) ||  (transicion.estadoActual==q0))
		{
			printf("\n ERROR , LA CADENA ES RECHAZADA POR NO QUEDAR EN ESTADO FINAL");
		}
	
		//si la pila esta vacia, al final la cadena es ACEPTADA
		else if(pilaVacia(p))
			printf("\n FINALMENTE, LA PILA QUEDA VACIA. \n Por lo tanto, la cadena \"%s\" es ACEPTADA por el AFP. \n",cadenaSinEspacios);
		//La cadena es rechazada por tener elementos en la pila
		else
			printf("\n ERROR , LA CADENA ES RECHAZADA POR QUE HAY ELEMENTOS EN LA PILA");
			
		printf("\n\nQuiere ingresar otra cadena para analizar?\n\nEscriba SI si quiere continuar o NO para finalizar: ");
		scanf("%s",&respuesta);
		
		if(respondioSI(respuesta))
		{
			
			p=NULL;
			
			fflush(stdin);//borra el buffer de entrada
		}
	
		free(cadenaSinEspacios);
	}

	return 0;
}



void iniciarPila(Nodo** p) //INICIA LA PILA CON $
{
	(*p) = (Nodo*) malloc(sizeof(Nodo));
	(*p) -> info = '$';
	(*p) -> sig = NULL;
}


void push(Nodo** p,char c) //FUNCION PARA PUSHEAR CUANDO LEE '('
{
	Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));

	nuevo -> info = c;
	nuevo -> sig = (*p);
	(*p) = nuevo;
}

void pop(Nodo** p) //FUNCION PARA HACER POP CUANDO LEE ')'
{
	if((*p)!=NULL)
	{
		Nodo* aux = *p;
		(*p) = (*p) -> sig;
		free(aux);
	}
}

char cimaDePila(Nodo* p) //TE DEVUELVE EL VALOR EN LA CIMA DE LA PILA
{
	if(p!=NULL)
	{
		return p->info;
	}
}

void mostrarPila(Nodo* p) //MUESTRA EL CONTENIDO DE LA PILA
{
	int i;
	Nodo* aux = p;

	for(i=0;aux!=NULL;i++)
	{
		printf("\t\t\t\t\t|%c|\n",aux -> info);
		aux=aux->sig;
	}

	printf("\t\t\t\t\t---");

}

int pilaVacia(Nodo* p) //PREGUNTA SI LA PILA ESTA VACIA
{
	return p==NULL? 1 : 0;
}


void evaluar(TRANSICION* transicion)
{
	int columna,fila;

	//Columna 0

	if((*transicion).caracterDeEntradaLeido == '0')
	{
		columna=0;

		if((*transicion).estadoActual==q1 && (*transicion).cimaDePila=='$')
					fila=1;

		else if((*transicion).estadoActual==q1 && (*transicion).cimaDePila=='R')
					fila=3;
		else{
				fila=6;
			}
	}


	//Columna 1

	else if(	(*transicion).caracterDeEntradaLeido >= '1' && (*transicion).caracterDeEntradaLeido <= '9')
	{

			columna=1;

			if((*transicion).estadoActual==q0 && (*transicion).cimaDePila=='$')
			{

					fila=0;
			}

			else if((*transicion).estadoActual==q1 && (*transicion).cimaDePila=='$')
			{

					fila=1;
			}

			else if((*transicion).estadoActual==q0 && (*transicion).cimaDePila=='R')
			{

					fila=2;
			}

			else if((*transicion).estadoActual==q1 && (*transicion).cimaDePila=='R')
			{

					fila=3;
			}

			else{
				fila=6;
			}
	}


	//Columna 2

	else if(	(*transicion).caracterDeEntradaLeido == '+' ||
		(*transicion).caracterDeEntradaLeido == '-' ||
		(*transicion).caracterDeEntradaLeido == '*' ||
		(*transicion).caracterDeEntradaLeido == '/')
	{

		columna=2;

		if((*transicion).estadoActual==q1 && (*transicion).cimaDePila=='$')
					fila=1;

		else if((*transicion).estadoActual==q1 && (*transicion).cimaDePila=='R')
					fila=3;

		else if((*transicion).estadoActual==q2 && (*transicion).cimaDePila=='R')
					fila=4;

		else if((*transicion).estadoActual==q2 && (*transicion).cimaDePila=='$')
					fila=5;

		else{
			fila=6;
		}
	}

	//COLUMNA 3
	else if((*transicion).caracterDeEntradaLeido == '(')
	{
		columna=3;

		if((*transicion).estadoActual==q0 && (*transicion).cimaDePila=='$')
					fila=0;

		else if((*transicion).estadoActual==q0 && (*transicion).cimaDePila=='R')
					fila=2;

		else{
			fila=6;
		}
	}


	//COLUMNA 4
	else if((*transicion).caracterDeEntradaLeido == ')')
	{
		columna=4;

		if((*transicion).estadoActual==q1 && (*transicion).cimaDePila=='R')
					fila=3;

		else if((*transicion).estadoActual==q2 && (*transicion).cimaDePila=='R')
					fila=4;

		else{
			fila=6;
		}
	}
	
	else
	{
		printf("\n\nCaracter no pertenece al alfabeto\n");
		
		columna=0;
		fila=6;
	}



	strcpy((*transicion).simbolosAAgregarEnLaPila,matriz[fila][columna].simbolosAAgregarEnLaPila),
	(*transicion).siguienteEstado=matriz[fila][columna].siguienteEstado;

}



void imprimirTransicion(TRANSICION transicion)
{
	//setConsoleOutputCP(65001);

	if(transicion.estadoActual == q0)
		printf("d( q0 , ");

	else if(transicion.estadoActual == q1)
		printf("d( q1 , ");

	else if(transicion.estadoActual == q2)
		printf("d( q2 , ");

	else if(transicion.estadoActual == q3)
		printf("d( q3 , ");


	printf(" \'%c\' ,",transicion.caracterDeEntradaLeido);
	printf(" %c )->",transicion.cimaDePila);

	if(transicion.siguienteEstado==q0)
		printf("(q0 ,");

	else if(transicion.siguienteEstado==q1)
		printf("(q1 ,");

	else if(transicion.siguienteEstado==q2)
		printf("(q2 ,");

	else if(transicion.siguienteEstado==q3)
		printf("(q3 ,");

	if(strcmp(transicion.simbolosAAgregarEnLaPila,"EP")==0)
		printf(" e)");

	else
		printf(" %s )",transicion.simbolosAAgregarEnLaPila);
}

int respondioSI(char* respuesta)
{
	//devuelve un 1 si la respuesta es SI y 0 si no es Si
	
	return (respuesta[0] == 'S' && respuesta[1] == 'I')? 1:0;
}
