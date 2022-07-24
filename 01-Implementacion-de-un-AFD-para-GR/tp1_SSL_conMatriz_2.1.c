#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <stdio.h>

int columnaQuePertenece(char caracter){
	if(caracter =='0'){ // Con este if, en funcion del caracter, le voy a asignar su columna correspondiente
        	return 0;
        }
        else if(caracter =='1' || caracter == '2' ||caracter == '3' ||caracter == '4' ||caracter == '5' ||caracter == '6' ||caracter == '7'){
        	return 1;
        }
        else if(caracter=='8' || caracter == '9'){
           	return 2;
       	}
        else if(caracter== 'a' ||caracter == 'A' ||caracter == 'b' ||caracter == 'B' ||caracter =='c' ||caracter == 'C'||caracter == 'd' ||caracter == 'D' ||caracter == 'e' ||caracter == 'E' ||caracter == 'f' ||caracter == 'F'){
        	return 3;
        }
        else if(caracter =='x' || caracter == 'X'){
        	return 4;
        }
	 // si no pertenece a ningun toma error directamente
	return 5; // pertenece a la columna [Error]
}

int recorrerMatriz(char cadena[],int matriz[7][6]){
	int cont_cadena,fila,columna;
	char caracter;
  	fila=0;
  	for(cont_cadena=0;cont_cadena<strlen(cadena);cont_cadena++){
    	caracter= cadena[cont_cadena];
		columna=columnaQuePertenece(caracter);	
			
    	if(matriz[fila][columna] == 6) //Si cae en estado de error
		{
			return 6;
		}
		else
		{
			fila=matriz[fila][columna];  // Se dirige al estado actual
    	}	

  	}
  	
  	return fila;

	
}


void definirTipo(char cadena[], int matriz[7][6], FILE* salida){

	int estadoFinal= recorrerMatriz (cadena,matriz);

	//Determina que tipo es dependiendo su estado final
	switch(estadoFinal){
		case 1:
    		printf("\n %s OCTAL", cadena);
    		fputs(cadena,salida);
    		fputs("		OCTAL \n",salida);
    		break;
    	case 2:
    		printf("\n %s DECIMAL", cadena);
    		fputs(cadena,salida);
    		fputs("		DECIMAL \n",salida);
			break;
    	case 3:
    		printf("\n %s NO PERTENECE ", cadena);
    		fputs(cadena,salida);
    		fputs("		NO PERTENECE \n",salida);
    		break;
    	case 4:
    		printf("\n %s HEXADECIMAL", cadena);
    		fputs(cadena,salida);
    		fputs("		HEXADECIMAL \n",salida);
    		break;
    	case 5:
    		printf("\n %s OCTAL", cadena);
    		fputs(cadena,salida);
    		fputs("		OCTAL \n",salida);
    		break;
    	case 6:
    		printf("\n %s NO PERTENECE", cadena);
    		fputs(cadena,salida);
    		fputs("		NO PERTENECE \n",salida);
    		break;
    	default:
    		printf("\n %s NO PERTENECE .... algo malo paso :c", cadena);
    		fputs(cadena,salida);
    		fputs("		NO PERTENECE \n",salida);
    	break;
	}


}





int main()
	{
    int matriz [7][6] = {
    //   0  [1-7] [8,9] [a-f] [xX] [error]
        {1,  2,   2,    6,    6,   6},    // q0 inicial
        {5,  5,   6,    6,    3,   6},    // q1 final de OCTAL con 0
        {2,  2,   2,    6,    6,   6},    // q2 final de DECIMAL
        {4,  4,   4,    4,    6,   6},    // q3
        {4,  4,   4,    4,    6,   6},    // q4 final de HEXADECIMAL
        {5,  5,   6,    6,    6,   6},    // q5 final de OCTAL
        {6,  6,   6,    6,    6,   6}     // q6 estado de ERROR
    };
    
    char cadena[100];
    char* centinela=",";

    FILE* entrada_config; //se crea archivo de entrada
  entrada_config=fopen("entrada_config.txt", "wt");
  fputs("0xFF,127,0159,0xaBb1,0Xx,0,010,09,127A,120,0x",entrada_config);
  fclose(entrada_config);

  // LEE EL ARCHIVO ENTRADA Y LA DIVIDE EN SUBCADENAS POR CENTINELA
  FILE* entrada;
  entrada=fopen("entrada_config.txt","rt");
  fscanf(entrada,"%s",cadena);
  fclose(entrada);

  printf("%s  \n",cadena); // muestra la cadena recivida
  FILE* salida; // crear archivo de salida
  salida=fopen("salida.txt", "wt");


  char* token = strtok(cadena,centinela); // se guarda la primer cadena a verificar si es lexicamente correcto
  
	if(token!=NULL){
		while(token!=NULL){
			definirTipo(token,matriz,salida);
			token=strtok(NULL,centinela);
		}
	}










    fclose(salida);
	return 0;
}


