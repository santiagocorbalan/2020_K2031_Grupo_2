%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "Funciones.c"

int yylex();

FILE* yyin;

int yywrap(){
        return(1);
}

void yyerror (char const *s) {          //Con yyerror se detecta el error sintáctico 
   fprintf (stderr, "%s\n", s);
} 

char* tipo = NULL;
Tabla *aux = NULL;
Tabla *aux2 = NULL;
//Tabla *listaSimbolos = NULL;

%}

%union {
    int entero; 
    float real;
    char caracter;
    char cadena[100];

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
        | error '\n'        
;

sentencia:       sentenciaExpresion                                                       
                | sentenciaCompuesta                                                       
                | sentenciaDeSeleccion                                     
                | sentenciaDeIteracion           
                | sentenciaDeSalto 
;

sentenciaExpresion:     opExpresion ';'                                  
;

opExpresion:    
                /* vacio */                                                                        { printf("1 pase por aca \n"); printf("Se encontro una sentencia vacia\n"); }
                | expresion                                                                        { printf("2 pase por aca \n"); printf("Se encontro una sentencia con una expresion\n"); }    
;

sentenciaCompuesta:     '{' opListaDeclaraciones opListaDeSentencias '}'
;

opListaDeclaraciones: 
                /* vacio */                   
                | listaDeclaraciones                                                               { printf("3 pase por aca \n"); printf("Se encontro una sentencia compuesta con una lista de declaraciones\n"); }
;

listaDeclaraciones: 
                declaracion                           
                | listaDeclaraciones declaracion  
;

opListaDeSentencias:       /* vacio */
                         | listaDeSentencias                                                      { printf("4 pase por aca \n");printf("Se encontro una sentencia compuesta con una lista de sentencias\n"); }
;

listaDeSentencias: sentencia
                     | listaDeSentencias sentencia	

;

sentenciaDeSeleccion:     IF '(' expresion ')' sentencia                                          { printf("5 pase por aca");printf("Se encontro una sentencia IF \n"); } 
                        | IF '(' expresion ')' sentencia ELSE sentencia                           { printf("6 pase por aca");printf("Se encontro una sentencia IF y ELSE \n"); }   
                        | IF error expresion                                                      { printf("7 pase por aca");agregarError("Error Sintactico: Despues del IF se espera un '('\n"); }
                        | IF '(' expresion error sentencia                                        { printf("8 pase por aca");agregarError("Error Sintactico: falta ')' en la sentencia IF\n"); }
                        | SWITCH '(' expresion ')' sentencia                                      { printf("9 pase por aca");printf("Se encontro una sentencia SWITCH \n"); }   
                        | SWITCH error expresion                                                  { printf("10 pase por aca");agregarError("Error Sintactico: Despues del SWITCH se espera un '('\n"); }
                        | SWITCH '(' expresion error sentencia                                    { printf("11 pase por aca");agregarError("Error Sintactico: falta ')' en la sentencia SWITCH\n"); }                          
;
 
sentenciaDeIteracion:     WHILE '(' expresion ')' sentencia                                       { printf("12 pase por aca");printf("Se encontro la sentencia WHILE\n"); }   
                        | WHILE error expresion                                                   { printf("13 pase por aca");agregarError("Error Sintactico: Despues del WHILE se espera un '('\n"); }
                        | WHILE '(' expresion error sentencia                                     { printf("14 pase por aca");agregarError("Error Sintactico: falta ')' en la sentencia WHILE\n"); }
                        | DO sentencia WHILE '(' expresion ')' ';'                                { printf("15 pase por aca");printf("Se encontro una sentencia DO\n"); }   
                        | FOR '(' opExpresion ';' opExpresion ';' opExpresion ')' sentencia       { printf("16 pase por aca");printf("Se encontro una sentencia FOR\n"); }  
                        | FOR error opExpresion                                                   { printf("17 pase por aca");agregarError("Error Sintactico: Despues del FOR se espera un '('\n"); }
                        | FOR '(' opExpresion ';' opExpresion ';' opExpresion error sentencia     { printf("18 pase por aca");agregarError("Error Sintactico: falta ')' en la sentencia FOR\n"); }
;


sentenciaDeSalto:  CONTINUE ';'                                                                   { printf("19 pase por aca");printf("Se encontro la sentencia CONTINUE\n"); }
                  | BREAK ';'                                                                     { printf("20 pase por aca");printf("Se encontro la sentencia BREAK\n"); }
                  | RETURN opExpresion ';'                                                        { printf("21 pase por aca");printf("Se encontro la sentencia RETURN\n"); }  
;  

declaracion:  
               TIPO_DE_DATO declaraciones              { printf("22 pase por aca \n");tipo = $<cadena>1;} 
             | TIPO_DE_DATO '*' declaraciones          { printf("23 pase por aca \n");tipo = concatenar($<cadena>1, "*");}                   
             | VOID declaracionDefinicionFuncion       { printf("24 pase por aca \n");tipo = "void";}   
;

declaraciones:  declaracionDefinicionFuncion          
                | declaracionVariables ';'                      
;


declaracionDefinicionFuncion: IDENTIFICADOR parametrosCuerpoFuncion { 
                                                                        printf("25 pase por aca \n");
                                                                        aux = buscarSimbolo($<cadena>1); 
                                                                        if (aux) 
                                                                                agregarError("Error Semantico : el identificador ya esta declarado");  
                                                                        else {
                                                                                aux2 = agregoSimbolo2($<cadena>1 , tipo, 2);   
                                                                                aux->tiposParametros = listaParametrosAux; 
                                                                                listaParametrosAux = NULL; 
                                                                        }
                                                                }
                              | error parametrosCuerpoFuncion { agregarError("Error Sintactico : nombre de la funcion incorrecto"); }
;

declaracionVariables:  listaVariables 
;

listaVariables:   unaVariableSimple                          
                | unaVariableSimple ',' listaVariables 
;

unaVariableSimple: IDENTIFICADOR 
                                {
                                        printf("26 pase por aca \n");
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
                                printf("27 pase por aca");
                                aux=buscarSimbolo($<cadena>1); 
                                if (aux) {
                                        agregarError("Error Semantico : la variable ya esta declarada\n"); 
                                } 
                                else 
                                {
                                        aux2 = buscarSimbolo($<cadena>3); 
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
                                                        printf("28 pase por aca");
                                                                //aux = buscarSimbolo($<cadena>1); 
                                                                //if (aux) 
                                                                //        agregarError("Error Semantico : la variable ya esta declarada "); 
                                                                //else {
                                                                                if(strcmp(tipo,"int") == 0){ 
                                                                                        aux = agregoSimbolo2($<cadena>1 , tipo, 1);  
                                                                                        aux->value.valEnt = $<mystruct>3.valor_entero;}
                                                                                else
                                                                                        agregarError("Error Semantico : son de distinto tipo"); 
                                                                 //       }
                                                        }

                | IDENTIFICADOR '=' CONSTANTE_CARACTER  {
                                                                printf("29 pase por aca");
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
                        printf("30 pase por aca");       
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
                        printf("31 pase por aca");
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

listaParametros: /* vacio */  { printf("31 pase por aca");agregoParametro("void"); } 
                | parametros
                | parametros ',' listaParametros 
;

parametros:     
                TIPO_DE_DATO IDENTIFICADOR              { printf("33 pase por aca");agregoParametro($<cadena>1); } 
                | TIPO_DE_DATO '*' IDENTIFICADOR        { printf("34 pase por aca");agregoParametro(concatenar($<cadena>1, "*")); } 
                | error IDENTIFICADOR                   { agregarError("ERROR SINTACTICO : falta tipo de dato del parametro"); }
                | error '*' IDENTIFICADOR               { agregarError("ERROR SINTACTICO : falta tipo de dato del puntero parametro"); }
                | TIPO_DE_DATO error                    { agregarError("ERROR SINTACTICO : falta identificador en parametro"); }
                | TIPO_DE_DATO '*' error                { agregarError("ERROR SINTACTICO : falta identificador del puntero parametro"); }
;

expresion:      
                CONSTANTE_ENTERA                        { printf("constante entera exp pase por aca");$<mystruct>$.tipo = $<mystruct>1.tipo;  $<mystruct>$.valor_entero = $<mystruct>1.valor_entero;}
                | CONSTANTE_REAL                        {printf("constante real exp pase por aca"); $<mystruct>$.tipo = $<mystruct>1.tipo;  $<mystruct>$.valor_real = $<mystruct>1.valor_real;}
                | IDENTIFICADOR       { 
                        printf("35 pase por aca");
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
                        printf("36 pase por aca");
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
        printf("37 pase por aca");
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

argumento: /* vacio */ { printf("38 pase por aca");
        agregoArgumento("void"); }
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


int main(){
        yyin = fopen("docDePrueba.c","r");
        printf("\n");
        yyparse();
        printf("main pase por aca");
        mostrarSimbolos(listaSimbolos);
        mostrarErrores(listaErrores);
}