%{
#include "funciones.h"

#define YYDEBUG 1

int yylex(void);
int yyerror(const char *s);
extern FILE* yyin;
extern int yylineno;
int analisisCorrecto = 1;
int flag_error=0;
int contador=0;
char tipo[30];
char esVariable[30];
char nombre[30];




NODOVARIABLES* listavariables = NULL;
NODOFUNCIONES* listafunciones = NULL;
NODONORECONOCIDO* listaNoReconocido=NULL;
NODOSENTENCIAS* listaSentencias=NULL;
NODOTIPOS* listaParaVerificarSiEsNombreDeFuncion = NULL;

%}


%union {
   char cadena[30];
   int entero;
   float real;
   char cadena2[30];
   struct info{
       char cadena[30];
       int linea;
   }INFO;
}

%token <entero> CONSTANTE_OCTAL CONSTANTE_HEXADECIMAL CONSTANTE_CARACTER
%token <cadena> IDENTIFICADOR PUNTERO_FLECHA MAS_MAS ELIPSIS UNION ENUM VOLATILE CONST UNSIGNED SIGNED TYPEDEF EXTERN STATIC REGISTER AUTO INCLUDE DOUBLE SHORT LONG VOID FLOAT INT CHAR
%token <entero> CONSTANTE_DECIMAL
//%token <cadena> TIPO_DE_DATO
%token <cadena> DO
%token <cadena> FOR
%token <cadena> SWITCH
%token <cadena> CONTINUE
%token <cadena> RETURN
%token <cadena> CASE
%token <cadena> DEFAULT
%token <cadena> SIZEOF
%token <cadena> MENOS_MENOS
%token <cadena> STRUCT
%token <cadena> DEFINE
%token <cadena> IF
%token <cadena> WHILE
%token <cadena> LITERAL_CADENA
%token <cadena> DISTINTO
%token <cadena> BREAK
%token <cadena> ELSE
%token <cadena> MAYOR_IGUAL
%token <cadena> MENOR_IGUAL
%token <cadena> IGUAL_IGUAL
%token <cadena> AND_LOGICO
%token <cadena> OR_LOGICO
%token <cadena> MAS_IGUAL
%token <cadena> MENOS_IGUAL
%token <cadena> POR_IGUAL
%token <cadena> DIVISION_IGUAL
%token <cadena> NO_RECONOCIDO
%token <cadena> MODULO_IGUAL                
%token <cadena> CORRIMIENTO_A_IZQUIERDA_IGUAL                               
%token <cadena> CORRIMIENTO_A_DERECHA_IGUAL                          
%token <cadena> Y_IGUAL                                       
%token <cadena> POTENCIA_IGUAL                                           
%token <cadena> O_IGUAL
%token <cadena> CORRIMIENTO_A_DERECHA                                           
%token <cadena> CORRIMIENTO_A_IZQUIERDA    
%token <cadena> GOTO                               
%token <real> CONSTANTE_REAL

%start unidad_de_programa

//%token AUTO REGISTER STATIC EXTERN TYPEDEF 
//%token SIGNED UNSIGNED
//%token CONST VOLATILE STRUCT UNION ENUM DEFINE IF WHILE

//%token MAS_MAS IGUAL_IGUAL DISTINTO MENOR_IGUAL MAYOR_IGUAL
///%token MENOS_IGUAL MAS_IGUAL ELIPSIS ELSE INCLUDE AND OR FLECHA HEXA  CONS_CARACTER CADENA BREAK




%left '+' '-'
%left '*' '/'


%nonassoc ELSE




%%/* A continuacion las reglas gramaticales y las acciones */


unidad_de_programa: /* vacio */
                  | INCLUDE  unidad_de_programa                                                     
                  | DEFINE  expresion_primaria   unidad_de_programa                                           
                  | unidad_de_traduccion                            
                  | error unidad_de_traduccion { yyerrok;}
                  ;
unidad_de_traduccion: declaracion_externa
                | NO_RECONOCIDO {insertarEnListaNoReconocido(&listaNoReconocido,$1,$<INFO.linea>1);}                                                                           
                | unidad_de_traduccion  declaracion_externa                                                             
                ;
declaracion_externa: definicion_de_funcion                                         
                | declaracion                                         
                ;
definicion_de_funcion: especificadores_de_declaracion declarador lista_de_declaracion sentencia_compuesta  {insertarEnListaFunciones(&listafunciones,$<cadena>2,$<cadena>1,$<INFO.linea>1);}                                           
                | declarador lista_de_declaracion sentencia_compuesta                                       
                | especificadores_de_declaracion declarador sentencia_compuesta                            {insertarEnListaFunciones(&listafunciones,$<cadena>2,$<cadena>1,$<INFO.linea>1);}                          
                | declarador sentencia_compuesta                                                             
                ;
declaracion: especificadores_de_declaracion lista_declaradores_init ';'{ 
 if (strcmp(esVariable,"Variable")==0)
 {
 insertarEnListaVariables(&listavariables,nombre,tipo,$<INFO.linea>1);
} 
else if (strcmp(esVariable,"Funcion")==0)
{
    insertarEnListaFunciones(&listafunciones,nombre,tipo,$<INFO.linea>1);
}
 ;}       
                                                  
           | especificadores_de_declaracion ';'                                          
           ;
lista_de_declaracion:declaracion                                   
                    | lista_de_declaracion declaracion                                    
                    ;
especificadores_de_declaracion: especificador_categoria_almacenamiento especificadores_de_declaracion                                        
          | especificador_categoria_almacenamiento                                        
          | especificador_de_tipo especificadores_de_declaracion                                                                    
          | especificador_de_tipo                                                                               
          | calificador_de_tipo especificadores_de_declaracion                                         
          | calificador_de_tipo 
          ;
especificador_categoria_almacenamiento: AUTO 
                                      |REGISTER
                                      |STATIC 
                                      |EXTERN 
                                      |TYPEDEF 
                                      ;
especificador_de_tipo: INT    {if(esElTipoDeLaFuncion(&listaParaVerificarSiEsNombreDeFuncion, $<INFO.cadena>1, $<INFO.linea>1)==1){strcpy(tipo,$<INFO.cadena>1);};}                      
                     |CHAR    {if(esElTipoDeLaFuncion(&listaParaVerificarSiEsNombreDeFuncion, $<INFO.cadena>1, $<INFO.linea>1)==1){strcpy(tipo,$<INFO.cadena>1);};}                          
                     |FLOAT      {if(esElTipoDeLaFuncion(&listaParaVerificarSiEsNombreDeFuncion, $<INFO.cadena>1, $<INFO.linea>1)==1){strcpy(tipo,$<INFO.cadena>1);};}                           
                     |DOUBLE     {if(esElTipoDeLaFuncion(&listaParaVerificarSiEsNombreDeFuncion, $<INFO.cadena>1, $<INFO.linea>1)==1){strcpy(tipo,$<INFO.cadena>1);};}                                 
                     |SHORT      {if(esElTipoDeLaFuncion(&listaParaVerificarSiEsNombreDeFuncion, $<INFO.cadena>1, $<INFO.linea>1)==1){strcpy(tipo,$<INFO.cadena>1);};}                              
                     |VOID         {if(esElTipoDeLaFuncion(&listaParaVerificarSiEsNombreDeFuncion, $<INFO.cadena>1, $<INFO.linea>1)==1){strcpy(tipo,$<INFO.cadena>1);};}                          
                     |LONG          {if(esElTipoDeLaFuncion(&listaParaVerificarSiEsNombreDeFuncion, $<INFO.cadena>1, $<INFO.linea>1)==1){strcpy(tipo,$<INFO.cadena>1);};}                     
                     |SIGNED          {if(esElTipoDeLaFuncion(&listaParaVerificarSiEsNombreDeFuncion, $<INFO.cadena>1, $<INFO.linea>1)==1){strcpy(tipo,$<INFO.cadena>1);};}                        
                     |UNSIGNED         {if(esElTipoDeLaFuncion(&listaParaVerificarSiEsNombreDeFuncion, $<INFO.cadena>1, $<INFO.linea>1)==1){strcpy(tipo,$<INFO.cadena>1);};}                                                                  
                     |especificador_estructura_o_union                                      
                     |especificador_enum                                    
                     |nombre_typedef                                   
                     ;
calificador_de_tipo: CONST                                        
                   | VOLATILE                                           
                   ;
especificador_estructura_o_union: estructura_o_union IDENTIFICADOR '{' lista_declaraciones_struct '}'                                    
                                | estructura_o_union '{' lista_declaraciones_struct '}'                                         
                                | estructura_o_union IDENTIFICADOR                                         
                                ;
estructura_o_union: STRUCT          {strcpy(esVariable,"Variable");strcpy(tipo,$<INFO.cadena>1);}                                 
                  | UNION             {strcpy(esVariable,"Variable");strcpy(tipo,$<INFO.cadena>1);}                              
                  ;
lista_declaraciones_struct: declaracion_struct                  
                          | lista_declaraciones_struct declaracion_struct                                         
                          ;
lista_declaradores_init: declarador_init                                     
                       | lista_declaradores_init ',' declarador_init                                      
                       ;
declarador_init: declarador                                      
                | declarador '=' inicializador                                     
                ;
declaracion_struct: lista_calificador_especificador lista_declaradores_struct ';'                  
                    ;
lista_calificador_especificador: especificador_de_tipo lista_calificador_especificador                 
                                | especificador_de_tipo                 
                                | calificador_de_tipo lista_calificador_especificador                  
                                | calificador_de_tipo                  
                                ;
lista_declaradores_struct: declarador_struct                 
                         | lista_declaradores_struct ',' declarador_struct                 
                         ;
declarador_struct: declarador                  
                  | declarador ':' expresion_constante                  
                  | ':' expresion_constante                  
                  ;
especificador_enum: ENUM IDENTIFICADOR '{' lista_de_enumerador '}'                                      
                  | ENUM '{' lista_de_enumerador '}'                  
                  | ENUM IDENTIFICADOR                                     
                  ;
lista_de_enumerador: enumerador                  
                     | lista_de_enumerador ',' enumerador                  
                     ;
enumerador: IDENTIFICADOR                                     
            | IDENTIFICADOR '=' expresion_constante                                        
            ;
declarador: apuntador declarador_directo                 
            | declarador_directo                 
            ;
declarador_directo: IDENTIFICADOR            {strcpy(esVariable,"Variable");strcpy(nombre,$<INFO.cadena>1);}                                                                  
                  | '(' declarador ')'                                                                      
                  | IDENTIFICADOR  '[' expresion_constante  ']'       {strcpy(esVariable,"Variable");strcpy(nombre,$<INFO.cadena>1);}                                                      
                  | IDENTIFICADOR  '['  ']'                            {strcpy(esVariable,"Variable");strcpy(nombre,$<INFO.cadena>1);}       
                  | IDENTIFICADOR  '(' lista_tipos_de_parametro ')'    {strcpy(esVariable,"Funcion");strcpy(nombre,$<INFO.cadena>1);}                                                      
                  | IDENTIFICADOR  '(' lista_de_identificadores ')'     {strcpy(esVariable,"Funcion");strcpy(nombre,$<INFO.cadena>1);}                                                               
                  | IDENTIFICADOR  '('  ')'                        {strcpy(esVariable,"Funcion");strcpy(nombre,$<INFO.cadena>1);}                           
                  ;
apuntador: '*' lista_calificadores_de_tipo 
         | '*' apuntador lista_calificadores_de_tipo 
         | '*' apuntador
         | '*' 
         ;
lista_calificadores_de_tipo: calificador_de_tipo                                      
                           | lista_calificadores_de_tipo calificador_de_tipo                        
                           ;
lista_tipos_de_parametro:  lista_de_parametros                                    
                          | lista_de_parametros ',' ELIPSIS                                     
                          ;
lista_de_parametros: declaracion_de_parametro                                      
                    | lista_de_parametros ',' declaracion_de_parametro                                     
                    ;
declaracion_de_parametro:  especificadores_de_declaracion declarador                                      
           | especificadores_de_declaracion declarador_abstracto                                      
           | especificadores_de_declaracion                                        
           ;
lista_de_identificadores:  IDENTIFICADOR                           
        | lista_de_identificadores ',' IDENTIFICADOR                                     
        ;
inicializador: expresion_de_asignacion                                       
             | '{' lista_de_inicializadores'}'                                   
             | '{' lista_de_inicializadores',' '}'                                      
             ;
lista_de_inicializadores: inicializador                                       
                   | lista_de_inicializadores',' inicializador                                       
                   ;
nombre_de_tipo: lista_calificador_especificador declarador_abstracto                                  
              | lista_calificador_especificador                                    
              ;
declarador_abstracto: apuntador                                        
                    | apuntador declarador_abstracto_directo                                          
                    | declarador_abstracto_directo                                     
                    ;
declarador_abstracto_directo:'(' declarador_abstracto ')'                                       
                  | declarador_abstracto_directo '[' expresion_constante ']'                                 
                  | '[' expresion_constante ']'
                  | declarador_abstracto_directo '[' ']'
                  | '[' ']'
                  | declarador_abstracto_directo '(' lista_tipos_de_parametro ')'
                  | '(' lista_tipos_de_parametro ')'
                  | declarador_abstracto_directo '(' ')'
                  | '(' ')'
                  ;
nombre_typedef: 't'
              ;
sentencia: sentencia_etiquetada                                             
         | sentencia_expresion                                          
         | sentencia_compuesta                                      
         | sentencia_de_seleccion                                     
         | sentencia_de_iteracion 
         | sentencia_de_salto 
         ;
sentencia_etiquetada: IDENTIFICADOR ':' sentencia                                        
                    | CASE expresion_constante  ':' sentencia                  
                    | DEFAULT ':' sentencia                  
                    ;
sentencia_expresion: expresion ';'                                     
                   | ';'                                  
                   ;
sentencia_compuesta: '{' lista_de_declaracion lista_de_sentencias  '}'                  
                   | '{' lista_de_sentencias  '}'                                                                           
                   | '{' lista_de_declaracion   '}'                                                                                 
                   | '{' '}'                                                                                
                   ;
lista_de_sentencias: sentencia                                                                                          
                | lista_de_sentencias  sentencia                                                                                
                ;
sentencia_de_seleccion: IF '(' expresion ')' sentencia             {insertarEnListaSentencias(&listaSentencias,$<cadena>1,$<INFO.linea>1);}                         
                   | IF '(' expresion ')' sentencia ELSE sentencia   {insertarEnListaSentencias(&listaSentencias,$<cadena>1,$<INFO.linea>1);}               
                   | SWITCH '(' expresion ')' sentencia                {insertarEnListaSentencias(&listaSentencias,$<cadena>1,$<INFO.linea>1);}                       
                   ;
sentencia_de_iteracion: WHILE '(' expresion ')' sentencia            {insertarEnListaSentencias(&listaSentencias,$<cadena>1,$<INFO.linea>1);}                          
                   | DO sentencia WHILE '(' expresion ')' ';'                        {insertarEnListaSentencias(&listaSentencias,$<cadena>1,$<INFO.linea>1);}                
                   | FOR '(' expresion ';' expresion ';' expresion ')' sentencia            {insertarEnListaSentencias(&listaSentencias,$<cadena>1,$<INFO.linea>1);}        
                   | FOR '(' expresion ';' expresion ';'    ')' sentencia                  {insertarEnListaSentencias(&listaSentencias,$<cadena>1,$<INFO.linea>1);}                       
                   | FOR '(' expresion ';' ';' expresion ')' sentencia                  {insertarEnListaSentencias(&listaSentencias,$<cadena>1,$<INFO.linea>1);}                    
                   | FOR '(' expresion ';' ';' ')' sentencia                         {insertarEnListaSentencias(&listaSentencias,$<cadena>1,$<INFO.linea>1);}           
                   | FOR '(' ';' expresion ';' expresion ')' sentencia               {insertarEnListaSentencias(&listaSentencias,$<cadena>1,$<INFO.linea>1);}                         
                   | FOR '(' ';' expresion ';' ')' sentencia                        {insertarEnListaSentencias(&listaSentencias,$<cadena>1,$<INFO.linea>1);}                
                   | FOR '(' ';' ';' expresion ')' sentencia                         {insertarEnListaSentencias(&listaSentencias,$<cadena>1,$<INFO.linea>1);}             
                   | FOR '(' ';' ';' ')' sentencia                                   {insertarEnListaSentencias(&listaSentencias,$<cadena>1,$<INFO.linea>1);}  
                   ;
sentencia_de_salto: GOTO IDENTIFICADOR ';'                                 
                  | CONTINUE ';'                                  
                  | BREAK ';'                                       
                  | RETURN expresion ';'                                     
                  | RETURN ';'                                       
                  ;
expresion: expresion_de_asignacion                                       
         | expresion ',' expresion_de_asignacion                                       
         ;
expresion_de_asignacion: expresion_condicional                                   
                       | expresion_unaria operador_de_asignacion expresion_de_asignacion                 
                       ;
operador_de_asignacion:    POR_IGUAL                           
                           |DIVISION_IGUAL                                    
                           |MAS_IGUAL                                       
                           |MENOS_IGUAL                                         
                           |MODULO_IGUAL                                      
                           |CORRIMIENTO_A_IZQUIERDA_IGUAL                                      
                           |CORRIMIENTO_A_DERECHA_IGUAL                                          
                           |Y_IGUAL                                       
                           |POTENCIA_IGUAL                                           
                           |O_IGUAL                                        
                           | '='                                         
                           ;
expresion_condicional: expresion_logica_or                                    
                     | expresion_logica_or '?' expresion ':' expresion_condicional                                        
                     ;  
expresion_constante: expresion_condicional                                       
                   ;
expresion_logica_or: expresion_logica_and                                  
                   | expresion_logica_or OR_LOGICO expresion_logica_and                 
                   ;
expresion_logica_and: expresion_or_inclusivo                                         
                    | expresion_logica_and AND_LOGICO expresion_or_inclusivo                                    
                    ;
expresion_or_inclusivo: expresion_or_exclusivo                                        
                      | expresion_or_inclusivo '|' expresion_or_exclusivo                                   
                      ;
expresion_or_exclusivo: expresion_and                                  
                      | expresion_or_exclusivo '^' expresion_and                                      
                      ;
expresion_and: expresion_de_igualdad                                       
             | expresion_and '&' expresion_de_igualdad                                       
             ;
expresion_de_igualdad: expresion_relacional                                        
                     | expresion_de_igualdad IGUAL_IGUAL expresion_relacional                  
                     | expresion_de_igualdad DISTINTO expresion_relacional                                        
                     ;
expresion_relacional: expresion_de_corrimiento                                     
                    | expresion_relacional '<' expresion_de_corrimiento                                        
                    | expresion_relacional '>' expresion_de_corrimiento                                       
                    | expresion_relacional MENOR_IGUAL expresion_de_corrimiento                                        
                    | expresion_relacional MAYOR_IGUAL expresion_de_corrimiento                                    
                    ;
expresion_de_corrimiento: expresion_aditiva                                     
                        | expresion_de_corrimiento CORRIMIENTO_A_IZQUIERDA expresion_aditiva                                        
                        | expresion_de_corrimiento CORRIMIENTO_A_DERECHA expresion_aditiva                                       
                        ;
expresion_aditiva: expresion_multiplicativa                                      
                            | expresion_aditiva '+' expresion_multiplicativa                                      
                            | expresion_aditiva '-' expresion_multiplicativa                                      
                            ;
expresion_multiplicativa: expresion_cast                                      
                        | expresion_multiplicativa '*' expresion_cast                                       
                        | expresion_multiplicativa '/' expresion_cast                                        
                        | expresion_multiplicativa '%' expresion_cast                                         
                        ;
expresion_cast: expresion_unaria                                     
              | '(' nombre_de_tipo ')' expresion_cast                                     
              ;
expresion_unaria: expresion_posfija                                       
                | MENOS_MENOS  expresion_unaria                                
                | MAS_MAS expresion_unaria                                 
                | operador_unario  expresion_cast                                      
                | SIZEOF expresion_unaria                                     
                | SIZEOF '(' nombre_de_tipo ')'                                       
                ;
operador_unario: '&'                                       
               | '*'                                      
               | '+'                                   
               | '-'                                      
               | '~'                                   
               | '!'                                                    
               ;
expresion_posfija: expresion_primaria                                           
                 | expresion_posfija '[' expresion ']'
                 | expresion_posfija '(' lista_expresiones_argumento ')' 
                 | expresion_posfija '(' ')' 
                 | expresion_posfija '.' IDENTIFICADOR 
                 | expresion_posfija PUNTERO_FLECHA IDENTIFICADOR 
                 | expresion_posfija MENOS_MENOS 
                 | expresion_posfija MAS_MAS 
                 ;
expresion_primaria: IDENTIFICADOR                                       
                  | constante                                           
                  | LITERAL_CADENA                                      
                  | '(' expresion')'
                  ;
lista_expresiones_argumento: expresion_de_asignacion 
                           | lista_expresiones_argumento ',' expresion_de_asignacion 
                           ;
constante: CONSTANTE_OCTAL 
         | CONSTANTE_HEXADECIMAL  
         | CONSTANTE_DECIMAL                                            
         | CONSTANTE_CARACTER  
         | CONSTANTE_REAL 
         | ENUM 
         ;


%%


int main (int argc, char *argv[])
{
        FILE* reporte = fopen("reporte.txt","w+");
        yyin=fopen(argv[1],"r");
        yyparse();
        imprimirListaEnArchivo(reporte,listavariables,listaNoReconocido,listafunciones,listaSentencias);
        fclose(reporte);
        fclose(yyin);

        if(analisisCorrecto)
        printf("\nAnalisis finalizado correctamente\n");

        return 0;
}

int yyerror(const char *msg){
        printf("\nFallo el analisis en la linea: %d %s\n",yylineno,msg);
        analisisCorrecto=0;
        return 0;
}



void insertarEnListaVariables(NODOVARIABLES** lista, char *nombre,char*tipo, int linea)
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
void imprimirListaEnArchivo(FILE* archivo,NODOVARIABLES* listavariables,NODONORECONOCIDO *listaNoReconocido,NODOFUNCIONES* listafunciones,NODOSENTENCIAS* listaSentencias)
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


int esElTipoDeLaFuncion(NODOTIPOS **lista, char *tipoEntrante, int lineaEntrante)
{
  NODOTIPOS *ptr = *lista;
  NODOTIPOS *nuevo = (NODOTIPOS *)malloc(sizeof(NODOTIPOS));

    nuevo->linea = lineaEntrante;
    nuevo->tipo = strdup(tipoEntrante);

    if (*lista == NULL )
    {
        nuevo->sig = *lista;
        *lista = nuevo;
        return 1;
    }
    else
    {   
        while (  (ptr->linea!=lineaEntrante) && ptr->sig != NULL)    
        {
            
            ptr = ptr->sig;
        }
        if(ptr->linea==lineaEntrante){ //si es el primer tipo que se encuentra en esa linea, es porque es el tipo de la funcion
          nuevo->sig = *lista;
         *lista = nuevo;
           return 0;
           
        } 

        if(ptr->sig==NULL){ //si es el primer tipo que se encuentra en esa linea, es porque es el tipo de la funcion
          nuevo->sig = *lista;
         *lista = nuevo;
           return 1;
           
        } 
        

    
    }
}


