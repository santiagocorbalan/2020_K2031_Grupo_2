%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "TP5.h"
#include "TP5.c"
#define YYDEBUG 1

extern int yylineno;
char* tipo;

void yyerror (char const *s) { }  

FILE* yyin;

int yylex();

int yywrap(){
    return(1);
}

symrec *aux;

%}

%union
{
    struct yylval_struct
      {
      int tipo;
      int valor_entero;
      float valor_real;
      } mystruct;

        char* cadena;
        char caracter;
        int entero;
        float real;
}

%start input

%type <mystruct> expresion

%token <cadena>         TIPO_DE_DATO 
%token <caracter>       CONSTANTE_CARACTER 
%token <cadena>         IDENTIFICADOR     
%token <cadena>         LITERAL_CADENA
%token <cadena>         TKN_VOID
%token <mystruct>       CONSTANTE_ENTERA
%token <mystruct>       CONSTANTE_REAL

%token BREAK
%token CONTINUE
%token RETURN
%token FOR
%token DO
%token WHILE
%token SWITCH
%token IF
%token TKN_ELSE

%right '='
%left '+' '-'
%left '*' '/'
%left '(' ')'

%% 

input:    /* vacio */
        | input line
;

line:   '\n'
        | declaracion   
        | sentencia
        | invocacionDeFuncion  
;

sentencia:  sentenciaExpresion                                                       
        | sentenciaCompuesta                                                                                           
        | sentenciaDeIteracion   
        | sentenciaDeSeleccion        
        | sentenciaDeSalto 
;

sentenciaExpresion:    opExpresion ';'
                      | opExpresion  error      { agregarErrorSintactico("ERROR, Falta ';' al Final de la Linea",yylineno); }                             
;

opExpresion:            /* vacio */             { printf("Linea %i:  Se encontro una sentencia vacia\n\n",yylineno); }  
                        | expresion      
;

sentenciaCompuesta:     '{' opListaDeclaraciones opListaDeSentencias '}'                                        
;

opListaDeclaraciones:   /* vacio */                   
                        | listaDeclaraciones                                                    { printf("Linea %i:  Se encontro una sentencia compuesta con una lista de declaraciones\n\n",yylineno); }
;

listaDeclaraciones:     declaracion                           
                        | listaDeclaraciones declaracion  
;

opListaDeSentencias:    /* vacio */
                        | listaDeSentencias                                                     { printf("Linea %i:  Se encontro una sentencia compuesta con una lista de sentencias\n\n",yylineno);    }
;

listaDeSentencias:      sentencia
                        | listaDeSentencias sentencia	
;

sentenciaDeSeleccion:   IF '(' expresion ')' sentencia                                          { printf("Linea %i:  Se encontro una sentencia IF\n\n",yylineno);            }
                        | IF error expresion ')' sentencia                                      { agregarErrorSintactico("ERROR, Falta '(' en la sentencia IF",yylineno);    }
                        | IF '(' expresion error sentencia                                      { agregarErrorSintactico("ERROR, Falta ')' en la sentencia IF",yylineno);    }                       
                        | SWITCH '(' expresion ')' sentencia                                    { printf("Linea %i:  Se encontro una sentencia SWITCH\n\n",yylineno);        }                                       
;

sentenciaDeIteracion:   WHILE '(' expresion ')' sentencia                                       { printf("Linea %i:  Se encontro una sentencia WHILE\n\n",yylineno);         } 
                        | WHILE error expresion ')' sentencia                                   { agregarErrorSintactico("ERROR, Falta '(' en la sentencia WHILE",yylineno); }
                        | WHILE '(' expresion error sentencia                                   { agregarErrorSintactico("ERROR, Falta ')' en la sentencia WHILE",yylineno); }
                        | DO sentencia WHILE '(' expresion ')' ';'                              { printf("Linea %i:  Se encontro una sentencia DO\n\n",yylineno);            }    
                        | FOR '(' opExpresion ';' opExpresion ';' opExpresion ')' sentencia     { printf("Linea %i:  Se encontro una sentencia FOR\n\n",yylineno);           } 
                        | FOR error opExpresion ';' opExpresion ';' opExpresion ')' sentencia   { agregarErrorSintactico("ERROR, Falta '(' en la sentencia FOR", yylineno);  }
                        | FOR '(' opExpresion ';' opExpresion ';' opExpresion error sentencia   { agregarErrorSintactico("ERROR, Falta '(' en la sentencia FOR", yylineno);  }                       
;

sentenciaDeSalto:       CONTINUE ';'                                                            { printf("Linea %i:  Se encontro la sentencia CONTINUE\n\n",yylineno);       }
                        | CONTINUE error                                                         { agregarErrorSintactico("ERROR, Falta ';' al Final de la Linea",yylineno);  } 
                        | BREAK ';'                                                             { printf("Linea %i:  Se encontro la sentencia BREAK\n\n",yylineno);          }
                        | BREAK error                                                           { agregarErrorSintactico("ERROR, Falta ';' al Final de la Linea",yylineno);  } 
                        | RETURN opExpresion  ';'                                               { printf("Linea %i:  Se encontro la sentencia RETURN\n\n",yylineno);         }
                        | RETURN opExpresion error                                              { agregarErrorSintactico("ERROR, Falta ';' al Final de la Linea",yylineno);  } 
;

declaracion:            TIPO_DE_DATO            { tipo = $<cadena>1;} declaraciones
                        | TIPO_DE_DATO '*'      { tipo = strcat($<cadena>1,"*");}  declaraciones  
                        | TKN_VOID              { tipo = "void"; } declaracionDefinicionFuncion                    
;

declaraciones:          declaracionDefinicionFuncion          
                        | declaracionVariables ';'  
                        | declaracionVariables error                                            { agregarErrorSintactico("ERROR, Falta ';' al Final de la Linea",yylineno); }                    
;

declaracionVariables:   listaVariables 
;

listaVariables:         unaVariableSimple                          
                        | unaVariableSimple ',' listaVariables 
;

unaVariableSimple:      IDENTIFICADOR   
                                        {
                                                aux = buscoSimbolo($<cadena>1); 
                                                if (aux) 
                                                        agregarErrorSemantico("ERROR, Doble Declaracion De Variables",yylineno); 
                                                else 
                                                        declararVariable1($<cadena>1,tipo);
                                        } 

                        | IDENTIFICADOR '=' IDENTIFICADOR         
                                                                {
                                                                        aux = buscoSimbolo($<cadena>1); 
                                                                        if (aux) 
                                                                                agregarErrorSemantico("ERROR, Doble Declaracion De Variables", yylineno);
                                                                        else  {
                                                                                symrec *aux2=buscoSimbolo($<cadena>3); 
                                                        
                                                                                if (aux2 && (strcmp(tipo, aux2->tipo) == 0)) { 
                                                                                        aux = agregoSimbolo($<cadena>1 , tipo, 1); 

                                                                                        if (strcmp("int", aux->tipo) == 0) {
                                                                                                aux->value.valEnt = aux2->value.valEnt;  
                                                                                        }

                                                                                        if (strcmp("float", aux->tipo) == 0) {
                                                                                                aux->value.valReal = aux2->value.valReal; 
                                                                                        }

                                                                                        if (strcmp("char", aux->tipo) == 0) {
                                                                                                aux->value.valChar = aux2->value.valChar ;  
                                                                                        }       

                                                                                        if (strcmp("char*", aux->tipo) == 0) {
                                                                                                aux->value.valString = aux2->value.valString;  
                                                                                        } 
                                                                                }   
                                        
                                                                                if (aux2 && (strcmp(tipo, aux2->tipo) != 0))
                                                                                        agregarErrorSemantico("ERROR, Las Variables Son De Distinto Tipo",yylineno);

                                                                                if (aux2 == NULL) 
                                                                                        agregarErrorSemantico("ERROR, La Variable que esta a la Derecha de la Asignacion NO esta Declarada",yylineno);  
                                                                        } 
                                                                }
                                                            
                                        
                        | IDENTIFICADOR '=' CONSTANTE_CARACTER  
                                                                {
                                                                        aux = buscoSimbolo($<cadena>1); 
                                                                        if (aux) 
                                                                                agregarErrorSemantico("ERROR, Doble Declaracion De Variables", yylineno); 
                                                                        else {
                                                                                if (strcmp(tipo, "char") == 0) {
                                                                                        aux = agregoSimbolo(strdup($<cadena>1), tipo, 1);  
                                                                                        aux->value.valChar = $<caracter>3;   
                                                                                }
                                                                                else 
                                                                                        agregarErrorSemantico("ERROR, Son De Distinto Tipo",yylineno); 
                                                                        }  
                                                                }

                        | IDENTIFICADOR '=' CONSTANTE_ENTERA    
                                                                {
                                                                        aux = buscoSimbolo($<cadena>1); 
                                                                        if (aux) 
                                                                                agregarErrorSemantico("ERROR, Doble Declaracion De Variables",yylineno); 
                                                                        else  {
                                                                                if (strcmp(tipo,"int") == 0) {
                                                                                        aux = agregoSimbolo(strdup($<cadena>1) , tipo, 1);  
                                                                                        aux->value.valEnt = $<mystruct>3.valor_entero; 
                                                                                } 
                                                                                else 
                                                                                        agregarErrorSemantico("ERROR, Son De Distinto Tipo",yylineno); 
                                                                        } 
                                                                }
                        
                        | IDENTIFICADOR '=' CONSTANTE_REAL     
                                                                { 
                                                                        aux = buscoSimbolo($<cadena>1); 
                                                                        if (aux) 
                                                                                agregarErrorSemantico("ERROR, Doble Declaracion De Variables",yylineno); 
                                                                        else {
                                                                                if (strcmp(tipo, "float") == 0) {
                                                                                        aux = agregoSimbolo($<cadena>1 , tipo, 1);  
                                                                                        aux->value.valReal = $<mystruct>3.valor_real;  
                                                                                } 
                                                                                else 
                                                                                        agregarErrorSemantico("ERROR, Son De Distinto Tipo",yylineno);
                                                                        } 
                                                                }

                        | IDENTIFICADOR '=' LITERAL_CADENA      
                                                                {
                                                                        aux=buscoSimbolo($<cadena>1); 
                                                                        if (aux)  
                                                                                agregarErrorSemantico("ERROR, Doble Declaracion De Variables",yylineno);
                                                                        else {
                                                                                if (strcmp(tipo, "char*") == 0) {
                                                                                        aux = agregoSimbolo(strdup($<cadena>1) , tipo, 1);  
                                                                                        aux->value.valString = $<cadena>3; } 
                                                                                else 
                                                                                        agregarErrorSemantico("ERROR, Son De Distinto Tipo",yylineno);  
                                                                        } 
                                                                }

                             
                                                       
                        | IDENTIFICADOR '=' error               { agregarErrorSintactico("ERROR, Se intento Inicializar Con Un Valor Incorrecto",yylineno); }

                        | error '=' CONSTANTE_ENTERA            { agregarErrorSintactico("ERROR, Identificador Incorrecto de la Variable a Declarar con Inicializacion",yylineno);}
                             
;

declaracionDefinicionFuncion: IDENTIFICADOR parametrosFuncion 
                                                                { 
                                                                        aux = buscoSimbolo($<cadena>1); 
                                                                        if (aux)  
                                                                                agregarErrorSemantico("ERROR, El Identificador ya esta Declarado",yylineno); 
                                                                        else {
                                                                                aux=agregoSimbolo($<cadena>1 , tipo, 2);   
                                                                                aux->tiposParametros = listaParametrosAux;  
                                                                        }

                                                                        listaParametrosAux = NULL; 
                                                                }

                              | error parametrosFuncion { agregarErrorSintactico("ERROR, Nombre de la Funcion Incorrecto",yylineno); }
;
                    
parametrosFuncion:   '(' listaParametros ')' ';'    
;

listaParametros:         /* vacio */  { agregoParametro("void"); } 
                        | parametros
                        | parametros ',' listaParametros 
;
               
parametros:       TIPO_DE_DATO IDENTIFICADOR       { agregoParametro($<cadena>1); } 
                | TIPO_DE_DATO '*' IDENTIFICADOR   { agregoParametro(strcat(tipo,"*")); }
                | error IDENTIFICADOR              { agregarErrorSintactico("ERROR, Falta tipo de dato del parametro",yylineno); }
                | error '*' IDENTIFICADOR          { agregarErrorSintactico("ERROR, Falta tipo de dato del puntero parametro",yylineno); }
                | TIPO_DE_DATO error               { agregarErrorSintactico("ERROR, Falta identificador en parametro",yylineno); }
                | TIPO_DE_DATO '*' error           { agregarErrorSintactico("ERROR, Falta identificador del puntero parametro",yylineno); }

;

invocacionDeFuncion:  IDENTIFICADOR '(' listaArgumentos ')' ';'   
                                                                {
                                                                        aux = buscoSimbolo($<cadena>1);  
                                                                        if (aux) { 
                                                                                if (aux->type == 1) { 
                                                                                        agregarErrorSemantico("ERROR, El IDENTIFICADOR esta Declarado como Variable",yylineno); 
                                                                                }
                     
                                                                                if (compararParametros(aux->tiposParametros, listaParametrosAux) == 1) {
                                                                                        agregarErrorSemantico("ERROR, Se Invoco una Funcion con la Cantidad o Tipos de Parametros Incorrectos",yylineno); 
                                                                                } 
                        
                                                                                if (compararParametros(aux->tiposParametros, listaParametrosAux) == 0) {
                                                                                        printf ("Linea %i:  Se Invoco una Funcion con la Cantidad y Tipos De Parametros Correctos\n\n",yylineno);
                                                                                } 
                                                                        } 

                                                                        else { 
                                                                                agregarErrorSemantico("ERROR, No esta Declarada la Funcion",yylineno);  
                                                                        }
                                                                
                                                                        listaParametrosAux = NULL; 
                                                                }                                        
                                                                                                                 
                                                                                                                                                                                                       
                        | IDENTIFICADOR error listaArgumentos ')'       { agregarErrorSintactico("ERROR, Falta '(' en la Invocacion de la Funcion",yylineno); }
                        | IDENTIFICADOR '(' listaArgumentos error       { agregarErrorSintactico("ERROR, Falta ')' en la Invocacion de la Funcion",yylineno); }
;

listaArgumentos: argumento                           
                | argumento ',' listaArgumentos      
;

argumento: /* vacio */          { agregoArgumento("void"); }

                | IDENTIFICADOR        
                                {        
                                        aux = buscoSimbolo($<cadena>1);    
                                        if (aux) 
                                                agregoArgumento(aux->tipo); 
                                        else 
                                                agregarErrorSemantico("ERROR, La Variable NO esta Declarada",yylineno); 
                                }

                | LITERAL_CADENA      { agregoArgumento("char*"); }
                | CONSTANTE_ENTERA    { agregoArgumento("int");   } 
                | CONSTANTE_CARACTER  { agregoArgumento("char");  }
                | CONSTANTE_REAL      { agregoArgumento("real");  }
        
;

expresion:      CONSTANTE_ENTERA        { $<mystruct>$.tipo=$<mystruct>1.tipo;$<mystruct>$.valor_entero=$<mystruct>1.valor_entero; }
	  	| CONSTANTE_REAL        { $<mystruct>$.tipo=$<mystruct>1.tipo;$<mystruct>$.valor_real=$<mystruct>1.valor_real;     }

                | IDENTIFICADOR '=' expresion   
                                                { 
                                                        aux = buscoSimbolo($<cadena>1); 
                                                        if (aux) {  
                                                                if ((strcmp(aux->tipo,"int") == 0) && ($<mystruct>3.tipo == 1) ) {
                                                                        aux->value.valEnt = $<mystruct>3.valor_entero; 
                                                                        $<mystruct>$.valor_entero = $<mystruct>3.valor_entero;  
                                                                } 

                                                                else  if ((strcmp(aux->tipo,"float") == 0) && ($<mystruct>3.tipo == 2) ) {
                                                                        aux->value.valReal = $<mystruct>3.valor_real; 
                                                                        $<mystruct>$.valor_real = $<mystruct>3.valor_real;  
                                                                } 
                                                                
                                                                else      
                                                                        agregarErrorSemantico("ERROR, Son de Distinto Tipo",yylineno);    
                                                                }
        
                                                        else { 
                                                                agregarErrorSemantico("ERROR, La Variable NO esta Declarada",yylineno); 
                                                        } 
                                                }	


	  	| expresion '+' expresion 
                                                { 
                                                        if ($<mystruct>1.tipo == $<mystruct>3.tipo)  { 

                                                                if ($<mystruct>1.tipo==1)  {
                                                                        $<mystruct>$.valor_entero = $<mystruct>1.valor_entero + $<mystruct>3.valor_entero;
                                                                }
                                                                else  { 
                                                                        $<mystruct>$.valor_real = $<mystruct>1.valor_real + $<mystruct>3.valor_real;
                                                                } 
                                                        }
        
                                                        else { 
                                                                agregarErrorSemantico("ERROR, Los Operandos Son de Distinto Tipo, NO se Realizo la Operacion Completa",yylineno);
                                                        } 
                                                }


                | expresion '-' expresion 
                                                { 
                                                        if ($<mystruct>1.tipo == $<mystruct>3.tipo) { 
       
                                                                if($<mystruct>1.tipo==1) {
                                                                        $<mystruct>$.valor_entero = $<mystruct>1.valor_entero - $<mystruct>3.valor_entero; 
                                                                }
                                                                else {
                                                                        $<mystruct>$.valor_real = $<mystruct>1.valor_real - $<mystruct>3.valor_real;
                                                                }  
                                                        }
        
                                                        else { 
                                                                agregarErrorSemantico("ERROR, Los Operandos Son de Distinto Tipo, NO se Realizo la Operacion Completa",yylineno);
                                                        } 
                                                }

	  	| expresion '*' expresion 
                                                { 
                                                        if ($<mystruct>1.tipo == $<mystruct>3.tipo) { 

                                                                if ($<mystruct>1.tipo == 1) { 
                                                                        $<mystruct>$.valor_entero = $<mystruct>1.valor_entero * $<mystruct>3.valor_entero; 
                                                                }
                                                                else { 
                                                                        $<mystruct>$.valor_real = $<mystruct>1.valor_real * $<mystruct>3.valor_real; 
                                                                } 
                                                        }
        
                                                        else { 
                                                                agregarErrorSemantico("ERROR, Los Operandos Son de Distinto Tipo NO se Realizo la Operacion Completa",yylineno);
                                                        } 
                                                }

                | expresion '/' expresion
                | '(' expresion ')'             { $<mystruct>$.valor_entero = $<mystruct>2.valor_entero ; }                   
;

%%

symrec *sym_table;

int main(){
        #ifdef BISON_DEBUG
        yydebug = 1;
        #endif

        yyin = fopen("archivo.c","r");
        printf("\n\n");
        yyparse();
        
        mostrarListaVariables();
        mostrarListaFunciones();
        mostrarErrorSintactico();
        mostrarErrorSemantico();
}