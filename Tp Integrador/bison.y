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
char nombreDeFuncion[30];
char tipo[30];
char tipoFuncion[30];
char tipoVariableFuncion[30];
char nombreVariableFuncion[30];
char esVariable[30];
char nombre[30];
int estoyDerivandoParametrosDeLaFuncion=0;
char nombreDeFuncionInvocada[30];
int estoyDerivandoIdentificadoresInvocados=0;




NODOVARIABLES* listavariables = NULL;
NODOVARIABLES* listaDobleDeclaracion = NULL;
NODOFUNCIONES* listafunciones = NULL;
NODONORECONOCIDO* listaNoReconocido=NULL;
NODOSENTENCIAS* listaSentencias=NULL;
NODOTIPOS* listaParaVerificarSiEsNombreDeFuncion = NULL;
NODOFUNCIONES* listaFuncionesYParametros = NULL;
NODOVARIABLES* listaerrordetipos = NULL;
NODONODECLARADOS* listaNoDeclarados = NULL;
NODOPARAMETROS* listaParametros = NULL;
NODOERRORDETIPOSDEFUNCION* listaErroresSemanticosDeTipos=NULL;
NODOERRORFALTADETIPOS* listaErroresSemanticosDeCantidadDeTipos=NULL;
NODOSOBRADETIPOS* listaErroresSemanticosDeSobraDeTipos=NULL;
NODOERRORESSINTACTICOS* listaErroresSintacticos=NULL;
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
                  | error {insertarErrorSintactico(&listaErroresSintacticos,yylineno);}
                  ;
unidad_de_traduccion: declaracion_externa
                | NO_RECONOCIDO {insertarEnListaNoReconocido(&listaNoReconocido,$1,$<INFO.linea>1);}                                                                           
                | unidad_de_traduccion  declaracion_externa                                                             
                ;
declaracion_externa: definicion_de_funcion                                         
                | declaracion                                         
                ;
definicion_de_funcion: especificadores_de_declaracion declarador lista_de_declaracion sentencia_compuesta                                    
                | declarador lista_de_declaracion sentencia_compuesta                                       
                | especificadores_de_declaracion declarador sentencia_compuesta    {/*insertarEnListaFunciones(&listafunciones,$<cadena>2,$<cadena>1,$<INFO.linea>1);/* tengo que veri*/}                                          
                | declarador sentencia_compuesta    //se define una f previamente declarado                                                         
                ;
declaracion: especificadores_de_declaracion lista_declaradores_init ';'    
                                                  
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
especificador_de_tipo: INT
{if(estoyDerivandoParametrosDeLaFuncion==1){
    strcpy(tipoVariableFuncion,$<INFO.cadena>1);
}else{
     strcpy(tipo,$<INFO.cadena>1);
}

;}                      
                     |CHAR   {if(estoyDerivandoParametrosDeLaFuncion==1){
    strcpy(tipoVariableFuncion,$<INFO.cadena>1);
}else{
     strcpy(tipo,$<INFO.cadena>1);
}

;}                            
                     |FLOAT     {if(estoyDerivandoParametrosDeLaFuncion==1){
    strcpy(tipoVariableFuncion,$<INFO.cadena>1);
}else{
     strcpy(tipo,$<INFO.cadena>1);
}

;}                             
                     |DOUBLE     {if(estoyDerivandoParametrosDeLaFuncion==1){
    strcpy(tipoVariableFuncion,$<INFO.cadena>1);
}else{
     strcpy(tipo,$<INFO.cadena>1);
}

;}                                    
                     |SHORT      {if(estoyDerivandoParametrosDeLaFuncion==1){
    strcpy(tipoVariableFuncion,$<INFO.cadena>1);
}else{
     strcpy(tipo,$<INFO.cadena>1);
}

;}                                  
                     |VOID        {if(estoyDerivandoParametrosDeLaFuncion==1){
    strcpy(tipoVariableFuncion,$<INFO.cadena>1);
}else{
     strcpy(tipo,$<INFO.cadena>1);
}

;}                              
                     |LONG         {if(estoyDerivandoParametrosDeLaFuncion==1){
    strcpy(tipoVariableFuncion,$<INFO.cadena>1);
}else{
     strcpy(tipo,$<INFO.cadena>1);
}

;}                         
                     |SIGNED          {if(estoyDerivandoParametrosDeLaFuncion==1){
    strcpy(tipoVariableFuncion,$<INFO.cadena>1);
}else{
     strcpy(tipo,$<INFO.cadena>1);
}

;}                            
                     |UNSIGNED         {if(estoyDerivandoParametrosDeLaFuncion==1){
    strcpy(tipoVariableFuncion,$<INFO.cadena>1);
}else{
     strcpy(tipo,$<INFO.cadena>1);
}

;}                                                                    
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
estructura_o_union: STRUCT          {if(estoyDerivandoParametrosDeLaFuncion==1){
    strcpy(tipoVariableFuncion,$<INFO.cadena>1);
}else{
     strcpy(tipo,$<INFO.cadena>1);
}

;}                                
                  | UNION             {if(estoyDerivandoParametrosDeLaFuncion==1){
    strcpy(tipoVariableFuncion,$<INFO.cadena>1);
}else{
     strcpy(tipo,$<INFO.cadena>1);
}

;}                              
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
declarador: apuntador declarador_directo  {esPuntero(&listavariables);}                 
            | declarador_directo                 
            ;
declarador_directo: IDENTIFICADOR
{if(estoyDerivandoParametrosDeLaFuncion==1){
    //printf("variable de la f: %s",$<INFO.cadena>1);
    agregarVariableALaFuncion(nombreDeFuncion,tipoVariableFuncion,$<INFO.cadena>1,&listafunciones);
    //agregarVariableALaFuncion(nombreDeFuncion,tipoVariableFuncion,$<INFO.cadena>1;&listafunciones);
}else{
     insertarEnListaVariables(&listavariables,$<INFO.cadena>1,tipo,$<INFO.linea>1,&listaDobleDeclaracion);
}
;}                                                                  
            | '(' declarador ')'                                                                      
                  | IDENTIFICADOR  '[' expresion_constante  ']'           {insertarEnListaVariables(&listavariables,$<INFO.cadena>1,tipo,$<INFO.linea>1,&listaDobleDeclaracion); }                                               
                  | IDENTIFICADOR  '['  ']'                                  {insertarEnListaVariables(&listavariables,$<INFO.cadena>1,tipo,$<INFO.linea>1,&listaDobleDeclaracion); }
                  | IDENTIFICADOR   '('  {estoyDerivandoParametrosDeLaFuncion=1;
                      strcpy(nombreDeFuncion,$<INFO.cadena>1);
                      insertarEnListaFunciones(&listafunciones,$<INFO.cadena>1,tipo,$<INFO.linea>1);
                      ;} lista_tipos_de_parametro ')'     {estoyDerivandoParametrosDeLaFuncion=0;}                                                    
                  | IDENTIFICADOR  '('{strcpy(nombreDeFuncionInvocada,$<INFO.cadena>1);estoyDerivandoIdentificadoresInvocados=1;} lista_de_identificadores ')'    {estoyDerivandoIdentificadoresInvocados=0;
                verificarFuncionInvocada(&listafunciones,nombreDeFuncionInvocada,&listaParametros,&listavariables);
                ;}                                                              
                  | IDENTIFICADOR  '('  ')'                                                  
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
lista_de_identificadores:  IDENTIFICADOR   { if(estoyDerivandoIdentificadoresInvocados==1){
insertarIdentificadoresInvocados(&listaParametros,$<INFO.cadena>1);

}
    
    /*if (verificarFuncionInvocada(&listafunciones,nombreDeFuncionInvocada,&listaParametros,&listavariables)==1){
    printf("no coinciden los tipos de parametros de la funcion \n");
}*/;}                       
        | IDENTIFICADOR  { if(estoyDerivandoIdentificadoresInvocados==1){
insertarIdentificadoresInvocados(&listaParametros,$<INFO.cadena>1);

};} ','   lista_de_identificadores
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
                            | expresion_aditiva '+' expresion_multiplicativa  {
                                if(esTipoCorrecto(&listavariables,$<INFO.cadena>1)==0){ // Si la función retorna 0, no es un tipo operable
                                    insertarEnListaErrorDeTipos(&listaerrordetipos,$<INFO.cadena>1,tipoDeDato(&listavariables,$<INFO.cadena>1),$<INFO.linea>1);
                                } 
                                
                                else if(esTipoCorrecto(&listavariables,$<INFO.cadena>1)==2){ // Si la función retorna 2, no esta declarada
                                    insertarEnListaNoDeclarados(&listaNoDeclarados,$<INFO.cadena>1,$<INFO.linea>1);
                                }

                                //Para la segunda variable
                                if(esTipoCorrecto(&listavariables,$<INFO.cadena>3)==0){ // Si la función retorna 0, no es un tipo operable
                                    insertarEnListaErrorDeTipos(&listaerrordetipos,$<INFO.cadena>3,tipoDeDato(&listavariables,$<INFO.cadena>3),$<INFO.linea>3);
                                } 
                                
                                else if(esTipoCorrecto(&listavariables,$<INFO.cadena>3)==2){ // Si la función retorna 2, no esta declarada
                                    insertarEnListaNoDeclarados(&listaNoDeclarados,$<INFO.cadena>3,$<INFO.linea>3);
                                }
                                
                            }

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
                | operador_unario  expresion_cast {
                    if(strcmp($<cadena>2,yylval.cadena) == 0) {
                        printf("No se puede realizar una operacion binaria con strings");
                    }
                ;}                                  
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
expresion_primaria: IDENTIFICADOR   {/*printf("se encontro un id : %s\n",$<INFO.cadena>1)/* aca hay que poner la funcion de validar tipo de datos*/;}                                     
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
        imprimirListaEnArchivo(reporte,listavariables,listaNoReconocido,listafunciones,listaSentencias,listaDobleDeclaracion,listaerrordetipos,listaNoDeclarados);
        fclose(reporte);
        fclose(yyin);

        if(analisisCorrecto)
        printf("\nAnalisis finalizado correctamente\n");

        return 0;
}

int yyerror(const char *msg){
        //printf("\nFallo el analisis en la linea: %d %s\n",yylineno,msg);
        analisisCorrecto=0;
        return 0;
}





void insertarEnListaVariables(NODOVARIABLES** lista, char *nombre,char*tipo, int linea,NODOVARIABLES** listaDobleDeclaracion)
{
 
     NODOVARIABLES *ptr = *lista;
     NODOVARIABLES *nuevo = (NODOVARIABLES *)malloc(sizeof(NODOVARIABLES));
     NODOVARIABLES *aux = *lista;

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
        
        while (aux != NULL )
        {
            if(strcmp(aux->nombre,nombre)==0)
            {
                //Doble declaracion
                insertarEnListaDobleDeclaracion(nombre,linea,listaDobleDeclaracion);
                break;
            }


            aux = aux->sig;
        }


        while (ptr->sig != NULL )
        {
   
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
    nuevo->cantidad = 0;
    nuevo->variable = NULL;

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

int estaEnListaFunciones(NODOFUNCIONES** lista, char *nombre)
{
     NODOFUNCIONES *aux = *lista;
    while (aux != NULL)
    {
        if (strcmp(aux->nombre, nombre) == 0)
        {
            return 1;
        }
        aux = aux->sig;
    }
    return 0;
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
void imprimirListaEnArchivo(FILE* archivo,NODOVARIABLES* listavariables,NODONORECONOCIDO *listaNoReconocido,NODOFUNCIONES* listafunciones,NODOSENTENCIAS* listaSentencias,NODOVARIABLES* listaDobleDeclaracion,NODOVARIABLES* listaerrordetipos, NODONODECLARADOS* listaNoDeclarados)
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
        fprintf(archivo,"\nLinea: %i    ", ptr->linea);
        if(ptr->linea < 10) //Para alinear la lista
	    {
		    fprintf(archivo," ");
        }
		fprintf(archivo,"Funcion: %s",ptr->nombre);
        for(int i=0;i<(15-strlen(ptr->nombre));i++) //Para alinear la lista
	    {
		    fprintf(archivo," ");
        }
        fprintf(archivo,"Tipo: %s",ptr->tipo);
        for(int i=0;i<(15-strlen(ptr->tipo));i++) //Para alinear la lista
	    {
		    fprintf(archivo," ");
        }
        fprintf(archivo,"Cantidad de parametros: %i\n",ptr->cantidad);

        fprintf(archivo,"Parametros:\n");

        while(ptr->variable != NULL){
            NODOVARIABLES *aux = ptr->variable;
            ptr->variable = ptr->variable->sig;

            fprintf(archivo,"Nombre: %s     ",aux->nombre);
            for(int i=0;i<(15-strlen(aux->nombre));i++) //Para alinear la lista
	        {
		        fprintf(archivo," ");
            }
            fprintf(archivo,"Tipo: %s \n",aux->tipo);
            free(aux);

        }


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
        fprintf(archivo,"Linea: %i\t\t\t\t", ptr->linea);
		fprintf(archivo,"Sentencia: %s \n",ptr->tipoSentencia);
		free(ptr);
	}

    fprintf(archivo,"\n________________________________________________________________________________________\n\n");
	
    //ERRORES SEMANTICOS
    fprintf(archivo,"-------------------------------------Errores Semanticos-------------------------------------\n\n");

    //Doble declaracion de variables
    fprintf(archivo,"Doble declaracion de variable:\n\n");    
    while(listaDobleDeclaracion!=NULL)
	{
        NODOVARIABLES *ptr=listaDobleDeclaracion;
        listaDobleDeclaracion=listaDobleDeclaracion->sig;
        fprintf(archivo,"Nombre: %s", ptr->nombre);
        for(int i=0;i<(15-strlen(ptr->nombre));i++) //Para alinear la lista
	    {
		    fprintf(archivo," ");
        }
		fprintf(archivo,"Linea: %i \n",ptr->linea);
		free(ptr);
	}

     fprintf(archivo,"\n________________________________________________________________________________________\n\n");

    //Error de tipos
    fprintf(archivo,"Error de tipos:\n\n");    
     while(listaerrordetipos!=NULL)
	{
        NODOVARIABLES *ptr=listaerrordetipos;
        listaerrordetipos=listaerrordetipos->sig;
        fprintf(archivo,"Linea: %i      ",ptr->linea);
        /*for(int i=0;i<(15-strlen(ptr->variable1));i++) //Para alinear la lista
	    {
		    fprintf(archivo," ");
        }*/
        fprintf(archivo,"El identificador %s de tipo %s no es operable\n", ptr->nombre,ptr->tipo);
		free(ptr);
	}

     fprintf(archivo,"\n________________________________________________________________________________________\n\n");

    //Imprimo Lista de Identificadores No Declarados
    fprintf(archivo,"Listado de Identificadores No Declarados:\n\n");
    while(listaNoDeclarados!=NULL)
	{
        NODONODECLARADOS *ptr=listaNoDeclarados;
        listaNoDeclarados=listaNoDeclarados->sig;
        fprintf(archivo,"Linea: %i  ", ptr->linea);
        if(ptr->linea < 10) //Para alinear la lista
	    {
		    fprintf(archivo," ");
        }
		fprintf(archivo,"Identificador: %s\n",ptr->nombre);

		free(ptr);
	}

    fprintf(archivo,"\n________________________________________________________________________________________\n\n");

    fprintf(archivo,"Listado de errores de tipos en funciones:\n\n");
    while(listaErroresSemanticosDeTipos!=NULL)
	{
        NODOERRORDETIPOSDEFUNCION *ptr=listaErroresSemanticosDeTipos;
        listaErroresSemanticosDeTipos=listaErroresSemanticosDeTipos->sig;
        //fprintf(archivo,"Linea: %i  ", ptr->linea);
        /*if(ptr->linea < 10) //Para alinear la lista
	    {
		    fprintf(archivo," ");
        }*/
		fprintf(archivo,"En la funcion \"%s\", se esperaba un identificador de tipo %s pero se encontro al identificador %s de tipo  %s \n",ptr->nombreFuncion,ptr->tipoParametroEsperado,ptr->nombreIdentificador,ptr->tipoIdentificador);

		free(ptr);
	}

    fprintf(archivo,"\n________________________________________________________________________________________\n\n");

    fprintf(archivo,"Listado de errores de falta de parametros en funciones:\n\n");

    while(listaErroresSemanticosDeCantidadDeTipos!=NULL)
	{
        NODOERRORFALTADETIPOS *ptr=listaErroresSemanticosDeCantidadDeTipos;
        listaErroresSemanticosDeCantidadDeTipos=listaErroresSemanticosDeCantidadDeTipos->sig;


		fprintf(archivo,"en la funcion %s se esperaban %d  identificadores, pero se econtraron solo %d \n",ptr->nombreFuncion,ptr->cantidadVariablesDeclaradas,ptr->cantIdentificadoresInvocados);
        
		free(ptr);
	}


     fprintf(archivo,"\n________________________________________________________________________________________\n\n");

    fprintf(archivo,"Listado de errores de sobra de parametros en funciones:\n\n");

    while(listaErroresSemanticosDeSobraDeTipos!=NULL)
	{
        NODOSOBRADETIPOS *ptr=listaErroresSemanticosDeSobraDeTipos;
        listaErroresSemanticosDeSobraDeTipos=listaErroresSemanticosDeSobraDeTipos->sig;

		fprintf(archivo,"en la funcion %s solo se esperaban %d  identificadores, pero se econtraron con %d \n",ptr->nombreFuncion,ptr->cantidadVariablesDeclaradas,ptr->cantIdentificadoresInvocados);
        
		free(ptr);
	}


    //ERRORES SINTACTICOS
    fprintf(archivo,"\n-------------------------------------Errores Sintacticos-------------------------------------\n\n");
    fprintf(archivo,"Hubo errores sintacticos en las lineas: ");
    while(listaErroresSintacticos!=NULL)
	{
        NODOERRORESSINTACTICOS *ptr=listaErroresSintacticos;
        listaErroresSintacticos=listaErroresSintacticos->sig;
        fprintf(archivo,"%i, ",ptr->linea);
        ptr=ptr->sig;
        
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

int esTipoDeDatoValido(NODOVARIABLES** listaVariables,char *identificador){

 NODOVARIABLES *ptr = *listaVariables;
 while (ptr!=NULL){
    if(strcmp(ptr->nombre,identificador)==0){
        if(strcmp(ptr->tipo,"int")==0){
            return 1;
        }
        if(strcmp(ptr->tipo,"float")==0){
            return 1;
        }
        if(strcmp(ptr->tipo,"double")==0){
            return 1;
        }
        if(strcmp(ptr->tipo,"long")==0){
            return 1;
        }
        if(strcmp(ptr->tipo,"short")==0){
            return 1;
        }
     
        if(strcmp(ptr->tipo,"char")==0){
            return 1;
        }
        else{
         return 0;
        }
    }
     ptr=ptr->sig;
 }
}
void inicializarNodoVariablesVacio(NODOVARIABLES* nuevo)
{
    /* 
    int linea;
    char* nombre;
    char* tipo;
    */
	
	nuevo->linea=0;
	nuevo->nombre=strdup(" ");
    nuevo->tipo=strdup(" ");
}

NODOVARIABLES* pedirMemoriaEInicializarNodoVariables()
{	
	NODOVARIABLES* nuevoNodo=(NODOVARIABLES*) malloc(sizeof(NODOVARIABLES));
	inicializarNodoVariablesVacio(nuevoNodo);

	return nuevoNodo;
}

void agregarNuevoNodoVariablesAlFinal(NODOVARIABLES** nodo,NODOVARIABLES* nuevoNodo)
{
	nuevoNodo->sig=NULL;


	if(*nodo==NULL)
	{
		*nodo=nuevoNodo;
	}
	else
	{
		NODOVARIABLES* t=*nodo;
		while(t->sig!=NULL)
		{
			t=t->sig;
		}
		t->sig=nuevoNodo;

	}
}


void insertarEnListaParametros(NODOVARIABLES** lista, char *identificador,char*tipo)
{
     //NODOVARIABLES* nuevoNodo = pedirMemoriaEInicializarNodoVariables();
    NODOVARIABLES *ptr = *lista;
    NODOVARIABLES* nuevoNodo=(NODOVARIABLES *) malloc(sizeof(NODOVARIABLES));

    nuevoNodo->nombre=strdup(identificador);
    nuevoNodo->tipo=strdup(tipo);
  

    if (*lista == NULL )
    {
        nuevoNodo->sig = *lista;
        *lista = nuevoNodo;
    }
    else
    {   
        while (ptr->sig != NULL )
        {
            ptr = ptr->sig;
        }

        nuevoNodo->sig = ptr->sig;
        ptr->sig = nuevoNodo;
    }
	
	 //agregarNuevoNodoVariablesAlFinal(lista,nuevoNodo);
}



void agregarVariableALaFuncion(char* nombre,char* tipo,char* identificador,NODOFUNCIONES** lista) {

        NODOFUNCIONES *aux = *lista;
        if(strcmp(aux->nombre,nombre)==0){
            insertarEnListaParametros(&aux->variable,identificador,tipo);
            aux->cantidad ++;
            return ; 
        }
        while (strcmp(aux->nombre,nombre)!=0) {
            aux = aux->sig; 
        }
         if(strcmp(aux->nombre,nombre)==0)
            {
                insertarEnListaParametros(&aux->variable,identificador,tipo);
                aux->cantidad ++;
            }
        
    
}

char* buscarTipoId(char* nombre,NODOVARIABLES**  variables) {
    NODOVARIABLES *aux = *variables;
    while(aux != NULL) {
        if(strcmp(nombre,aux->nombre)==0) {
            return aux->tipo;
        }
        aux = aux->sig;
    }
    return "error";
}

//DEVUELVE 1 SI LOS TIPOS DE DATOS VERIFICAN, SI NO DEVUELVE 0
void compararParametros(NODOVARIABLES**  parametrosDeLaFuncion,NODOPARAMETROS** parametrosInvocados,NODOVARIABLES**  variables, char* nombreFuncion) {
     NODOVARIABLES* auxP1 = pedirMemoriaEInicializarNodoVariables();
    auxP1 = *parametrosDeLaFuncion;
    NODOPARAMETROS *auxP2 = *parametrosInvocados;
      int parametrosInvocadosTotales;


   parametrosInvocadosTotales= cantidadDeParametrosInvocados(auxP2);
    int cantidadDeVariablesDeclaradas;
    cantidadDeVariablesDeclaradas= cantidadDeParametros(auxP1);
   // aca es donde rompe
     //printf("el nombre es %s \n",auxP1->nombre );
   if(cantidadDeVariablesDeclaradas > parametrosInvocadosTotales ) {
        insertarListaErrorSemanticoFaltaDeTipos(&listaErroresSemanticosDeCantidadDeTipos,nombreFuncion, cantidadDeVariablesDeclaradas,parametrosInvocadosTotales);
        
    }
        if(cantidadDeVariablesDeclaradas < parametrosInvocadosTotales ) {
        insertarListaErrorSemanticoSobraDeTipos(&listaErroresSemanticosDeSobraDeTipos,nombreFuncion, cantidadDeVariablesDeclaradas,parametrosInvocadosTotales);
       
    }

    if(cantidadDeVariablesDeclaradas == parametrosInvocadosTotales) {
        while(auxP1!=NULL) {
            //Los parametros no son del tipo que corresponde
            char* tipoParametro = strdup(buscarTipoId(auxP2->nombre,variables));
            if(strcmp(auxP1->tipo,tipoParametro)!=0){
               
                insertarListaErrorSemanticoDeTiposDeFuncion(&listaErroresSemanticosDeTipos,nombreFuncion,auxP2->nombre,tipoParametro, auxP1->tipo);
                 // error semantico el tipo del identificador invocado, no coincide con el tipo de la funcion declarada
            }
            auxP1 = auxP1->sig;
            auxP2 = auxP2->sig;
        }
    }
    /*}*/
   
    return ; // esta todo ok
}


//DEVUELVE 1 SI LOS TIPOS DE DATOS VERIFICAN, SI NO DEVUELVE 0
void verificarFuncionInvocada(NODOFUNCIONES** lista,char* nombreFuncion,NODOPARAMETROS** parametros,NODOVARIABLES**  variables) {
    NODOFUNCIONES *aux = *lista;
    char* tipoDeDatoParametro;
    char* tipoDeDatoIdentificador;
    int resultado = 0;
 

    if(strcmp(aux->nombre,nombreFuncion)==0){
        NODOVARIABLES *auxPar1=aux->variable;
        compararParametros(&auxPar1,parametros,variables,nombreFuncion);
        resultado= resultado+1;
    }
    while (strcmp(aux->nombre,nombreFuncion)!=0) {
        aux = aux->sig; 
    }
    if(strcmp(aux->nombre,nombreFuncion)==0 && resultado==0)
    {
        NODOVARIABLES *auxPar1=aux->variable;
        compararParametros(&auxPar1,parametros,variables,nombreFuncion);
    }

    //Dejo lista para parametros en NULL
    *parametros = NULL;

    return ;
}


//int verificarTipoDeDato()

char* tipoDeDato(NODOVARIABLES** lista, char* identificador){
   
   int i=0;
   NODOVARIABLES *ptr=listavariables;
   char* tipo ;

   while(ptr != NULL){

       if(strcmp(identificador,ptr->nombre)==0){
           tipo = ptr->tipo;
           break;
       }
       else{

        ptr = ptr->sig;
       }
   }

   if(ptr == NULL){
       tipo = "error";
   }

   return tipo;
}

int esTipoCorrecto(NODOVARIABLES** lista, char* identificador){

    char * tipo = tipoDeDato(lista,identificador);


    if(strcmp(tipo,"int")==0){
        return 1;
    }
    if(strcmp(tipo,"char")==0){
        return 1;
    }
    if(strcmp(tipo,"double")==0){
        return 1;
    }
    if(strcmp(tipo,"float")==0){
        return 1;
    }
    if(strcmp(tipo,"long")==0){
        return 1;
    }
    if(strcmp(tipo,"short")==0){
        return 1;
    }

    if(strcmp(tipo,"error")==0){
        return 2; // no se encuentra declarado
    }

    return 0; // no es operable
}

void insertarEnListaErrorDeTipos(NODOVARIABLES** lista, char *nombre,char*tipo,int linea)
{
 
     NODOVARIABLES *ptr = *lista;
     NODOVARIABLES *nuevo = (NODOVARIABLES *)malloc(sizeof(NODOVARIABLES));

    nuevo->nombre = strdup(nombre);
    nuevo->tipo = strdup(tipo);
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



void insertarEnListaNoDeclarados(NODONODECLARADOS**lista, char* nombre,int linea)
{
 
     NODONODECLARADOS *ptr = *lista;
     NODONODECLARADOS *nuevo = (NODONODECLARADOS *)malloc(sizeof(NODONODECLARADOS));

    nuevo->nombre = strdup(nombre);
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


void esPuntero(NODOVARIABLES** lista){
    NODOVARIABLES *ptr = *lista;
    
    while (ptr->sig != NULL )
        {
            ptr = ptr->sig;
        }

    strcat(ptr->tipo,"*");

}
void inicializarNodoVariablesVacioParametro(NODOPARAMETROS* nuevo)
{
    nuevo->nombre=strdup(" ");
     nuevo->sig=NULL;
	nuevo->longitud=0;
   
}

NODOPARAMETROS* pedirMemoriaEInicializarNodoParametros()
{	
	NODOPARAMETROS* nuevoNodo=(NODOPARAMETROS*) malloc(sizeof(NODOPARAMETROS));
	inicializarNodoVariablesVacioParametro(nuevoNodo);

	return nuevoNodo;
}

void insertarIdentificadoresInvocados(NODOPARAMETROS** lista,char* identificador){
    
    NODOPARAMETROS *actual = *lista;
    NODOPARAMETROS *nuevo = (NODOPARAMETROS *)malloc(sizeof(NODOPARAMETROS));
    nuevo->nombre = strdup(identificador);
    int contador=1;


    if (*lista == NULL)
    {
        nuevo->sig = *lista;
        *lista = nuevo;
        nuevo->longitud = 1;
        //printf("la longitud actual de identificador %s es: %d \n",nuevo->nombre,nuevo->longitud);
   

    }
    else
    {
        contador=2;
        while (actual->sig != NULL)
        {
            contador=contador+1;
            actual = actual->sig;
        }
        
        nuevo->longitud= contador;
        nuevo->sig = actual->sig;
        actual->sig = nuevo;
       //  printf("la longitud actual de identificador %s es: %d \n",nuevo->nombre,nuevo->longitud);
    }
}

int cantidadDeParametros(NODOVARIABLES *lista){
     NODOVARIABLES *aux = lista;
     int contador=1;
      while (aux->sig != NULL)
    {
        aux=aux->sig;
        contador=contador+1;
    }
    return contador;
}

int cantidadDeParametrosInvocados(NODOPARAMETROS*lista){
         NODOPARAMETROS *aux = lista;
     int contador=1;
      while (aux->sig != NULL)
    {
        aux=aux->sig;
        contador=contador+1;
    }
    return contador;
}

void insertarListaErrorSemanticoDeTiposDeFuncion(NODOERRORDETIPOSDEFUNCION** lista,char * nombreFuncion,char* nombreIdentificador,char* tipoidentificador, char* tipoParametroEsperado){
    NODOERRORDETIPOSDEFUNCION *actual = *lista;
    NODOERRORDETIPOSDEFUNCION *nuevo = (NODOERRORDETIPOSDEFUNCION *)malloc(sizeof(NODOERRORDETIPOSDEFUNCION));
    nuevo->nombreFuncion = strdup(nombreFuncion);
    nuevo->nombreIdentificador = strdup(nombreIdentificador);
    nuevo->tipoIdentificador = strdup(tipoidentificador);
    nuevo->tipoParametroEsperado = strdup(tipoParametroEsperado);

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




void insertarListaErrorSemanticoFaltaDeTipos(NODOERRORFALTADETIPOS** lista,char* nombreFuncion,int cantidadDeVariablesDeclaradas, int parametrosInvocadosTotales){

     NODOERRORFALTADETIPOS *actual = *lista;
    NODOERRORFALTADETIPOS *nuevo = (NODOERRORFALTADETIPOS *)malloc(sizeof(NODOERRORFALTADETIPOS));
    nuevo->nombreFuncion = strdup(nombreFuncion);
    nuevo->cantidadVariablesDeclaradas= cantidadDeVariablesDeclaradas;
    nuevo->cantIdentificadoresInvocados= parametrosInvocadosTotales;

    //printf("en la funcion %s se esperaban %d  identificadores, pero se econtraron solo %d \n",nombreFuncion,cantidadDeVariablesDeclaradas,parametrosInvocadosTotales);
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


void insertarListaErrorSemanticoSobraDeTipos(NODOSOBRADETIPOS** lista,char* nombreFuncion,int cantidadDeVariablesDeclaradas,int parametrosInvocadosTotales){
    
    NODOSOBRADETIPOS *actual = *lista;
    NODOSOBRADETIPOS *nuevo = (NODOSOBRADETIPOS *)malloc(sizeof(NODOSOBRADETIPOS));
    nuevo->nombreFuncion = strdup(nombreFuncion);
    nuevo->cantidadVariablesDeclaradas= cantidadDeVariablesDeclaradas;
    nuevo->cantIdentificadoresInvocados= parametrosInvocadosTotales;

    //printf("en la funcion %s solo se esperaban %d  identificadores, pero se econtraron con %d \n",nombreFuncion,cantidadDeVariablesDeclaradas,parametrosInvocadosTotales);
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

void insertarErrorSintactico(NODOERRORESSINTACTICOS** lista,int linea){
    NODOERRORESSINTACTICOS *actual = *lista;
    NODOERRORESSINTACTICOS *nuevo = (NODOERRORESSINTACTICOS *)malloc(sizeof(NODOERRORESSINTACTICOS));
    nuevo->linea = linea;

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