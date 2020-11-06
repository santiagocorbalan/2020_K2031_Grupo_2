%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int yylex();

FILE* yyin;

int yywrap(){
	return(1);
}

void yyerror (char* a) {}
int linea = 1;

%}

%union {
char cadena[50];
int entero;
float real;
}

%token <cadena> TIPODATO
%token <cadena> IDENTIFICADOR
%token <cadena> LITERALCADENA
%token <entero> CONSTANTEDECIMAL
%token <entero> CONSTANTEOCTAL
%token <entero> CONSTANTEHEXADECIMAL
%token <real>   CONSTANTEREAL
%token <entero> CONSTANTECARACTER
%token <cadena> INCREMENTO
%token <cadena> DECREMENTO
%token <cadena> AND
%token <cadena> OR
%token <cadena> IF
%token <cadena> SWITCH
%token <cadena> ELSE
%token <cadena> FOR
%token <cadena> WHILE
%token <cadena> DO
%token <cadena> RETURN

%token <cadena> OPER_SIZEOF

%type <cadena> unaVariableSimple
%type <cadena> error

%%

input:  /* vacio */
        | input line
;

line:   declaracion '\n'        {linea++;}
        | sentencia '\n'        {linea++;}
        | definicionFunciones '\n'  {linea++;}
        | error '\n'            {printf("\nSe detecto un error sintactico en la linea %i.", linea); linea++;}     
;

/* Expresiones */

expresion:      expAsignacion
;

expAsignacion:  expCondicional
                | expUnaria OPER_ASIGNACION expAsignacion
;

expCondicional: expOr
                | expOr '?' expresion ':' expCondicional
;

expOr:  expAnd
        | expOr OR expAnd
;

expAnd: expIgualdad
        | expAnd AND expIgualdad
;

expIgualdad:    expRelacional
                | expIgualdad OPER_IGUALDAD expRelacional
;

expRelacional:  expAditiva
                | expRelacional OPER_RELACIONAL expAditiva
;

expAditiva:     expMultiplicativa
                | expAditiva OPER_ADITIVO expMultiplicativa
;

expMultiplicativa:      expUnaria
                        | expMultiplicativa OPER_MULTIPLICATIVO expUnaria
;

expUnaria:      expPostfijo
                | OPER_INCREMENTO expUnaria
                | OPER_UNARIO expUnaria
                | OPER_SIZEOF '(' TIPO_DATO ')'
;

expPostfijo:    expPrimaria
                | expPostfijo '[' expresion ']'
                | expPostfijo '(' opcionListaArgumentos ')'
;

opcionListaArgumentos:  /* vacio*/
                        | expAsignacion
                        | opcionListaArgumentos ',' expAsignacion
;

expPrimaria:    IDENTIFICADOR
                | constante
                | LITERAL_CADENA
                | '(' expresion ')'
;

/* Declaracion y definiciones */

declaracion:    declaracionVariablesSimples
                | declaracionFunciones
                
;

declaracionVariablesSimples:    TIPO_DATO listaVariablesSimples ';' {printf(" de tipo %s.", $<cadena>1);}
;

listaVariablesSimples:  unaVariableSimple       {printf("\nSe declara la variable %s", $<cadena>1);}
                        | listaVariablesSimples ',' unaVariableSimple {printf(", y la variable %s", $<cadena>3);}
;

unaVariableSimple:      IDENTIFICADOR opcionInicializacion      {strcpy($<cadena>$, $<cadena>1);}
;

opcionInicializacion:   /* vacio */
                        | OPER_ASIGNACION expCondicional
;



declaracionFunciones:   TIPO_DATO IDENTIFICADOR '(' opcionArgumentosConTipo ')' ';' {printf("\nSe declara la funcion %s de tipo %s.", $<cadena>2, $<cadena>1);}
;

opcionArgumentosConTipo:        /* vacio */ 
                                | TIPO_DATO opcionReferencia IDENTIFICADOR 
                                | TIPO_DATO opcionReferencia IDENTIFICADOR ',' argumentosConTipo 
;

argumentosConTipo:      TIPO_DATO opcionReferencia IDENTIFICADOR 
                        | TIPO_DATO opcionReferencia IDENTIFICADOR ',' argumentosConTipo 
;

opcionReferencia:       /* vacio */
                        | '&'
;

definicionFunciones:    TIPO_DATO IDENTIFICADOR '(' opcionArgumentosConTipo ')' ';' {printf("\nSe define la funcion %s de tipo %s.", $<cadena>2, $<cadena>1);}

;

/* Sentencias */

sentencia:      sentenciaCompuesta
                | sentenciaExpresion
                | sentenciaSeleccion
                | sentenciaIteracion
                | sentenciaSalto
                
;

sentenciaCompuesta:     '{' opcionListaDeclaraciones opcionListaSentencias '}'  {printf("\nSe encontro una sentencia compuesta y otras sentencias.")}
;

opcionListaDeclaraciones:       /* vacio */
                                | declaracion                           
                                | opcionListaDeclaraciones declaracion  
;

listaSentencias:        sentencia                       
                        | listaSentencias sentencia     
;

opcionListaSentencias:  /* vacio*/
                        | sentencia                     
                        | listaSentencias sentencia     
;

sentenciaExpresion:     ';'                     {printf("\nSe encontro una sentencia vacia.");}
                        | expresion ';'         {printf("\nSe encontro una sentencia expresion.");}
;

sentenciaSeleccion:     IF '(' expresion ')' sentencia                  {printf("\nSe encontro una sentencia de seleccion (if).");}
                        | IF '(' expresion ')' sentencia ELSE sentencia {printf("\nSe encontro una sentencia de seleccion (if y else).");}
                        | SWITCH '(' expresion ')' sentencia            {printf("\nSe encontro una sentencia de seleccion (switch).");}
;

sentenciaIteracion:     WHILE '(' expresion ')' sentencia                                               {printf("\nSe encontro una sentencia de iteracion while.");}
                        | DO sentencia WHILE '(' expresion ')' ';'                                      {printf("\nSe encontro una sentencia de iteracion do while.");}
                        | FOR '(' opcionExpresion ';' opcionExpresion ';' opcionExpresion ')' sentencia {printf("\nSe encontro una sentencia de iteracion for.");}
;

sentenciaSalto: RETURN opcionExpresion ';'      {printf("\nSe encontro una sentencia de salto.");}
;

opcionExpresion:        /* vacio */
                        | expresion
;

constante:      CONSTANTE_DECIMAL             
                | CONSTANTE_OCTAL               
                | CONSTANTE_HEXADECIMAL       
                | CONSTANTE_REAL                 
                | CONSTANTE_CARACTER                         
;

%%

int main ()
{
        yyin = fopen("docDePrueba.c", "r");
        yyparse ();
}