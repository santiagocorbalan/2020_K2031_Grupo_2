%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Funciones.c"

int yylex();

FILE* yyin;

int yywrap(){
        return(1);
}

void yyerror (char const *s) {          //Con yyerror se detecta el error sintáctico 
   fprintf (stderr, "%s\n", s);
} 

char* tipo;
Tabla *aux;
Tabla *aux2;

%}

%union{
    int entero; 
    float real;
    char caracter;
    char* cadena;

struct yylval_struct
  {
      int tipo;
      int valor_entero;
      float valor_real;
      char valor_caracter;
  } mystruct;
}

%token <cadena> TIPO_DE_DATO 
%token <cadena> VOID
%token <cadena> IDENTIFICADOR     
%token <cadena> LITERAL_CADENA    
%token <mystruct> CONSTANTE_ENTERA
%token <mystruct> CONSTANTE_REAL   
%token <caracter> CONSTANTE_CARACTER 

%token SWITCH
%token DO
%token WHILE
%token IF
%token ELSE
%token FOR
%token BREAK
%token CONTINUE
%token RETURN
%token error // agrego token error

%type <mystruct> expresion
%type <mystruct> declaracionDefinicionFuncion

%% 

input:    /* vacio */
        | input line
;

line:   '\n'
        | expresion           '\n'                 
        | sentencia           '\n'                 
        | declaracion         '\n'  
        | invocacionDeFuncion '\n'       
;

sentencia:       sentenciaExpresion                                                       
                | sentenciaCompuesta                                                       
                | sentenciaDeSeleccion                                     
                | sentenciaDeIteracion           
                | sentenciaDeSalto 
;

sentenciaExpresion:     opExpresion ';'                                  
;

opExpresion:    /* vacio */                                                                        { printf("Se encontro una sentencia vacia\n"); }
                | expresion                                                                        { printf("Se encontro una sentencia con una expresion\n"); }    
;

sentenciaCompuesta:     '{' opListaDeclaraciones opListaDeSentencias '}'
;

opListaDeclaraciones: /* vacio */                   
                | listaDeclaraciones                                                               { printf("Se encontro una sentencia compuesta con una lista de declaraciones\n"); }
;

listaDeclaraciones: declaracion                           
                | listaDeclaraciones declaracion  
;

opListaDeSentencias:       /* vacio */
                         | listaDeSentencias                                                      { printf("Se encontro una sentencia compuesta con una lista de sentencias\n"); }
;

listaDeSentencias: sentencia
                     | listaDeSentencias sentencia	

;

sentenciaDeSeleccion:     IF '(' expresion ')' sentencia                                          { printf("Se encontro una sentencia IF\n"); } 
                        | IF '(' expresion ')' sentencia ELSE sentencia                           { printf("Se encontro una sentencia IF y ELSE\n"); }   
                        | IF error expresion                                                      { agregarError("Error Sintactico: Despues del IF se espera un '('\n"); }
                        | IF '(' expresion error sentencia                                        { agregarError("Error Sintactico: falta ')' en la sentencia IF\n"); }
                        | SWITCH '(' expresion ')' sentencia                                      { printf("Se encontro una sentencia SWITCH\n"); }   
                        | SWITCH error expresion                                                  { agregarError("Error Sintactico: Despues del SWITCH se espera un '('\n"); }
                        | SWITCH '(' expresion error sentencia                                    { agregarError("Error Sintactico: falta ')' en la sentencia SWITCH\n"); }                          
;
 
sentenciaDeIteracion:     WHILE '(' expresion ')' sentencia                                       { printf("Se encontro la sentencia WHILE\n"); }   
                        | WHILE error expresion                                                   { agregarError("Error Sintactico: Despues del WHILE se espera un '('\n"); }
                        | WHILE '(' expresion error sentencia                                     { agregarError("Error Sintactico: falta ')' en la sentencia WHILE\n"); }
                        | DO sentencia WHILE '(' expresion ')' ';'                                { printf("Se encontro una sentencia DO\n"); }   
                        | FOR '(' opExpresion ';' opExpresion ';' opExpresion ')' sentencia       { printf("Se encontro una sentencia FOR\n"); }  
                        | FOR error opExpresion                                                   { agregarError("Error Sintactico: Despues del FOR se espera un '('\n"); }
                        | FOR '(' opExpresion ';' opExpresion ';' opExpresion error sentencia     { agregarError("Error Sintactico: falta ')' en la sentencia FOR\n"); }
;


sentenciaDeSalto:  CONTINUE ';'                                                                   { printf("Se encontro la sentencia CONTINUE\n"); }
                  | BREAK ';'                                                                     { printf("Se encontro la sentencia BREAK\n"); }
                  | RETURN opExpresion ';'                                                        { printf("Se encontro la sentencia RETURN\n"); }  
            
;  

declaracion: TIPO_DE_DATO                                                                         { tipo = $<cadena>1; } declaraciones
             | TIPO_DE_DATO '*'                                                                   { tipo = concatenar($<cadena>1, "*"); } declaraciones                  
             | VOID                                                                               { tipo = "void"; } declaracionDefinicionFuncion  
;

declaracionDefinicionFuncion: IDENTIFICADOR parametrosCuerpoFuncion { 
                                                                        aux=buscarSimbolo($<cadena>1); 
                                                                        if (aux) 
                                                                                agregarError("Error Semantico : el identificador ya esta declarado");  
                                                                        else 
                                                                                aux2 = agregoSimbolo2($<cadena>1 , tipo, 2);   
                                                                                aux->tiposParametros = listaParametrosAux; 
                                                                                listaParametrosAux = NULL; 
                                                                }
                              | error parametrosCuerpoFuncion { agregarError("Error Sintactico : nombre de la funcion incorrecto"); }
;

declaraciones:  declaracionDefinicionFuncion          
                | declaracionVariables ';'                      
;

declaracionVariables:  listaVariables 
;

listaVariables:   unaVariableSimple                          
                | unaVariableSimple ',' listaVariables 
;

unaVariableSimple: IDENTIFICADOR 
                                {
                                        aux=buscarSimbolo($<cadena>1); 
                                        if (aux) 
                                                agregarError("Error Semantico: la variable ya esta declarada\n"); 
                                        else 
                                        {
                                                aux = agregoSimbolo2($<cadena>1, tipo, 1);

                                                        if (strcmp(aux-> tipo, "int") == 0) {
                                                                aux->value.valEnt = 0;
                                                        
                                                        } else if (strcmp(aux -> tipo, "float") == 0) {
                                                                aux->value.valReal = 0.0;

                                                        } else if (strcmp(aux -> tipo, "char") == 0) {
                                                                aux->value.valChar = '\0';

                                                        } else if (strcmp(aux -> tipo, "char*") == 0){
                                                                aux->value.valString = NULL;
                                                        }
                                                        
                                        }
                                                                                                            
                                }

                | IDENTIFICADOR '=' IDENTIFICADOR         
                        {
                                aux=buscarSimbolo($<cadena>1); 
                                if (aux) 
                                        agregarError("Error Semantico : la variable ya esta declarada\n"); 
                                else 
                                {
                                        aux2=buscarSimbolo($<cadena>3); 
                                        if(aux2 && (strcmp(tipo, aux2->tipo) == 0)) { 
                                                aux = agregoSimbolo2($<cadena>1 , tipo, 1); 

                                                if (strcmp(aux-> tipo, "int") == 0) {
                                                        aux2->value.valEnt = $<entero>3;

                                                } else if (strcmp(aux -> tipo, "float") == 0) {
                                                        aux2->value.valReal = $<real>3;

                                                } else if (strcmp(aux -> tipo, "char") == 0){
                                                        aux2->value.valChar = $<caracter>3;

                                                } else if (strcmp(aux -> tipo, "char*") == 0) {
                                                        aux2->value.valString = $<cadena>3;
                                                }
                                        }            
                                                                                                                                                                   
                                        if (aux2 == NULL)
                                                agregarError("Error Semantico : la variable no esta declarada\n");

                                        if (aux2 && (strcmp(tipo, aux2->tipo) != 0))
                                                agregarError("Error Semantico : las variables son de distinto tipo\n");
                                }
                        }
                  
                | IDENTIFICADOR '=' CONSTANTE_ENTERA    { 
                                                                aux = buscarSimbolo($<cadena>1); 
                                                                if (aux) 
                                                                        agregarError("Error Semantico : la variable ya esta declarada "); 
                                                                        else {
                                                                                if(strcmp(tipo,"int") == 0){ 
                                                                                        aux = agregoSimbolo2($<cadena>1 , tipo, 1);  
                                                                                        aux->value.valEnt = $<mystruct>3.valor_entero;}
                                                                                else
                                                                                        agregarError("Error Semantico : son de distinto tipo"); 
                                                                        }
                                                        }

                | IDENTIFICADOR '=' CONSTANTE_CARACTER  {
                                                                aux=buscarSimbolo($<cadena>1); 
                                                                if (aux) 
                                                                        agregarError("Error Semantico : la variable ya esta declarada "); 
                                                                else {
                                                                        if (strcmp(tipo, "char") == 0) {
                                                                                aux = agregoSimbolo2($<cadena>1 , tipo, 1);  
                                                                                aux->value.valChar = $<caracter>3; 
                                                                        }
                                                                        else 
                                                                                agregarError("Error Semantico : son de distinto tipo");
                                                                }
                                                        }
                     
                | IDENTIFICADOR '=' CONSTANTE_REAL     { 
                                                                aux=buscarSimbolo($<cadena>1); 
                                                                if (aux) 
                                                                        agregarError("Error Semantico : la variable ya esta declarada "); 
                                                                else
                                                                        if (strcmp(tipo, "double") == 0){ // si borro "0" me toma el if
                                                                                aux = agregoSimbolo2($<cadena>1 , tipo, 1);  
                                                                                aux->value.valReal = $<mystruct>3.valor_real;} 
                                                                        else{
                                                                                agregarError("Error Semantico : son de distinto tipo "); }
                                                        }

                | IDENTIFICADOR '=' LITERAL_CADENA      {
                                                                aux=buscarSimbolo($<cadena>1); 
                                                                if (aux) 
                                                                        agregarError("Error Semantico : la variable ya esta declarada "); 
                                                                else 
                                                                        if (strcmp(tipo, "char*") == 0){
                                                                                aux = agregoSimbolo2($<cadena>1 , tipo, 1);  
                                                                                aux->value.valString = $<cadena>3;}  
                                                                        else 
                                                                                agregarError("Error Semantico : son de distinto tipo ");
                                                        }


                | IDENTIFICADOR '=' error               { agregarError("Error Sintactico : se inicializo con un valor incorrecto"); }
                | error '='                             { agregarError("Error Sintactico : identificador incorrecto"); }
;

             
parametrosCuerpoFuncion: '(' listaParametros ')' sentenciaCompuesta    
                        | '(' listaParametros ')' ';'                    
;

listaParametros: /* vacio */  {agregoParametro("void");} 
                | parametros
                | parametros ',' listaParametros 
;

parametros:     TIPO_DE_DATO IDENTIFICADOR              { agregoParametro($<cadena>1); } 
                | TIPO_DE_DATO '*' IDENTIFICADOR        { agregoParametro(concatenar($<cadena>1, "*")); } 
                | error IDENTIFICADOR                   { agregarError("ERROR SINTACTICO : falta tipo de dato del parametro"); }
                | error '*' IDENTIFICADOR               { agregarError("ERROR SINTACTICO : falta tipo de dato del puntero parametro"); }
                | TIPO_DE_DATO error                    { agregarError("ERROR SINTACTICO : falta identificador en parametro"); }
                | TIPO_DE_DATO '*' error                { agregarError("ERROR SINTACTICO : falta identificador del puntero parametro"); }
;

expresion:      CONSTANTE_ENTERA                        { $<mystruct>$.tipo = $<mystruct>1.tipo;  $<mystruct>$.valor_entero = $<mystruct>1.valor_entero;}
                | CONSTANTE_REAL                        { $<mystruct>$.tipo = $<mystruct>1.tipo;  $<mystruct>$.valor_real = $<mystruct>1.valor_real;}
                | IDENTIFICADOR       { 
                                        aux=buscarSimbolo($<cadena>1); 
                                        if (aux) {  
                                                if (strcmp(aux->tipo, "int") == 0) {
                                                        $<mystruct>$.valor_entero = aux->value.valEnt; 
                                                        $<mystruct>$.tipo = 1;
                                                        }

                                                else if (strcmp(aux-> tipo,"float") == 0){
                                                        $<mystruct>$.valor_real = aux->value.valReal;  // cambio valor_float por valor_real
                                                        $<mystruct>$.tipo = 2;
                                                }
                                        } 
                                        else 
                                        { 
                                                agregarError("La variable no esta declarada\n");  
                                        } 
                                }

	        | expresion '+' expresion { 
                                                if($<mystruct>1.tipo == $<mystruct>3.tipo) { 
        
                                                        if ($<mystruct>1.tipo == 1) { 
                                                                $<mystruct>$.valor_entero=$<mystruct>1.valor_entero + $<mystruct>3.valor_entero; 
                                                        } else {
                                                                $<mystruct>$.valor_real = $<mystruct>1.valor_real + $<mystruct>3.valor_real; 
                                                        }
                                                } else { 
                                                        agregarError("Los operandos son de distinto tipo \n"); 
                                                }
        
                                        }

	  		//| expresion '-' expresion      { $$ = $1 - $3;}
	  		//| expresion '*' expresion      { $$ = $1 * $3;}
                        //| expresion '/' expresion      { $$ = $1 / $3;}
                        //| expresion '^' expresion      { $$ = pow ($1, $3);}
                        //| '(' expresion ')'            { $$ = $2;}
;

invocacionDeFuncion:  IDENTIFICADOR '(' listaArgumentos ')'     {
                                                                aux = buscarSimbolo($<cadena>1);   
                                                                if (aux) { 
                                                                        if(aux -> variableOfuncion == 1){
                                                                                agregarError ("Error semantico : El IDENTIFICADOR esta declarado como variable");} 
                                                                        else if (compararParametros(aux->tiposParametros, listaParametrosAux) == 1){
                                                                                agregarError ("Error semantico : cantidad o tipos de parametros incorrectos");} 
                                                                } 
                                                                else {
                                                                        agregarError ("Error semantico : No esta declarada la funcion"); 
                                                                }
                                                                listaParametrosAux = NULL;
                                                                }
                     | IDENTIFICADOR error listaArgumentos ')' {agregarError("Error Sintactico : falta '(' en la invocacion de la funcion"); }
                     | IDENTIFICADOR '(' listaArgumentos error {agregarError("Error Sintactico : falta ')' en la invocacion de la funcion"); }
;

listaArgumentos: argumento                           
                | argumento ',' listaArgumentos      
;

argumento: /* vacio */ {agregoArgumento("void");}
        | IDENTIFICADOR        {        
                                        aux=buscarSimbolo($<cadena>1);    
                                        if (aux) 
                                                agregoArgumento(aux->tipo); 
                                        else 
                                                agregarError("Error Semantico : la variable no esta declarada\n");
                                }
        | LITERAL_CADENA      { agregoArgumento("char*"); }
        | CONSTANTE_ENTERA    { agregoArgumento("int"); } 
        | CONSTANTE_CARACTER  { agregoArgumento("char"); }
        | CONSTANTE_REAL      { agregoArgumento("real"); }
;

%%

Tabla *listaSimbolos;

int main(){
        yyin = fopen("docDePrueba.c","r");
        printf("\n");
        yyparse();

        mostrarSimbolos(listaSimbolos);
        mostrarErrores(listaErrores);
}