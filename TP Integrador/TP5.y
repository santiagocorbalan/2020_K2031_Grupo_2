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

void yyerror (char const *s) {          
//   fprintf (stderr, "%s\n", s);
}  

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

%token <cadena> TIPO_DE_DATO 
%token <caracter> CONSTANTE_CARACTER 
%token <cadena> IDENTIFICADOR     
%token <cadena> LITERAL_CADENA
%token <cadena> TKN_VOID
%token <entero> error
%token <mystruct> CONSTANTE_ENTERA
%token <mystruct> CONSTANTE_REAL
%token BREAK
%token CONTINUE
%token RETURN
%token FOR
%token DO
%token WHILE
%token SWITCH
%token IF
%token ELSE

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

sentencia:       sentenciaExpresion                                                       
                | sentenciaCompuesta                                                                                           
                | sentenciaDeIteracion   
                | sentenciaDeSeleccion        
                | sentenciaDeSalto 
;

sentenciaExpresion:    opExpresion ';'                                  
;

opExpresion: /* vacio */      {printf("Se encontro una sentencia vacia\n");}
             | expresion         

;

sentenciaCompuesta:     '{' opListaDeclaraciones opListaDeSentencias '}'
                      
;

opListaDeclaraciones: /* vacio */                   
                      | listaDeclaraciones          {printf("Se encontro una sentencia compuesta con una lista de declaraciones\n");}
;

listaDeclaraciones: declaracion                           
                | listaDeclaraciones declaracion  
;

opListaDeSentencias:       /* vacio */
                         | listaDeSentencias                {printf("Se encontro una sentencia compuesta con una lista de sentencias\n");}
;

listaDeSentencias: sentencia
                     | listaDeSentencias sentencia	

;

sentenciaDeSeleccion:     IF '(' expresion ')'  sentencia                                          {printf("Se encontro una sentencia IF\n");} 
                        | SWITCH '(' expresion ')' sentencia                                      {printf("Se encontro una sentencia SWITCH\n");}   
                                     
;

sentenciaDeIteracion:     WHILE '(' expresion ')' sentencia                                       {printf("Se encontro la sentencia WHILE\n");}   
                        | DO sentencia WHILE '(' expresion ')' ';'                                {printf("Se encontro una sentencia DO\n");}   
                        | FOR '(' opExpresion ';' opExpresion ';' opExpresion ')' sentencia       {printf("Se encontro una sentencia FOR\n");}  
                        
;

sentenciaDeSalto:  CONTINUE ';'                                                                  {printf("Se encontro la sentencia CONTINUE\n");}
                  | BREAK ';'                                                                    {printf("Se encontro la sentencia BREAK\n");}
                  | RETURN opExpresion ';'                                                       {printf("Se encontro la sentencia RETURN\n");} 
;

declaracion: 
                TIPO_DE_DATO          {tipo = $<cadena>1;} declaraciones 
                | TIPO_DE_DATO '*'      {tipo = strcat($<cadena>1,"*");}  declaraciones  
                | TKN_VOID                  {tipo = "void"; } declaracionDefinicionFuncion                    
;

declaraciones:  declaracionDefinicionFuncion          
                | declaracionVariables ';'                      
;

declaracionVariables:   listaVariables 
;

listaVariables:   unaVariableSimple                          
                      | unaVariableSimple ',' listaVariables 
;

unaVariableSimple: IDENTIFICADOR   {
                                       aux=buscoSimbolo($<cadena>1); if (aux) agregarErrorSemantico("ERROR: La Variable Ya Esta Declarada",yylineno); 
                                                            else declararVariable1($<cadena>1,tipo);} 
                 | IDENTIFICADOR '=' IDENTIFICADOR         {
                                        aux=buscoSimbolo($<cadena>1); if (aux) agregarErrorSemantico("ERROR: La Variable Ya Esta Declarada",yylineno);
                                                            else  {
                                        symrec *aux2=buscoSimbolo($<cadena>3); 
                                        if(aux2 && (strcmp(tipo, aux2->tipo) == 0)) { 

                                                aux = agregoSimbolo($<cadena>1 , tipo, 1); 

                                                if(strcmp("int", aux->tipo) == 0)  {
                                                    aux->value.valEnt = aux2->value.valEnt; 
                                                    printf("\nSe declara la variable %s de tipo %s con valor %i\n\n",aux->nombre,aux->tipo, aux->value.valEnt);    
                                                }
                                                 if(strcmp("float", aux->tipo) == 0)  {
                                                    aux->value.valReal = aux2->value.valReal; 
                                                    printf("\nSe declara la variable %s de tipo %s con valor %f\n\n",aux->nombre,aux->tipo, aux->value.valReal);
                                                }

                                                 if(strcmp("char", aux->tipo) == 0)  {
                                                    aux->value.valChar = aux2->value.valChar ;
                                                    printf("\nSe declara la variable %s de tipo %s con valor %c\n\n",aux->nombre,aux->tipo, aux->value.valChar);
                                                }
                                                 if(strcmp("char*", aux->tipo) == 0)  {
                                                    aux->value.valString = aux2->value.valString;
                                                    printf("\nSe declara la variable %s de tipo %s con valor %s\n\n",aux->nombre,aux->tipo, aux->value.valString);
                                                }
                                                       

                                                }   

                                        
                                        if (aux2 && (strcmp(tipo, aux2->tipo) != 0))
                                                agregarErrorSemantico("ERROR: Las Variables Son De Distinto Tipo",yylineno);

                                        if (aux2 == NULL) 
                                                agregarErrorSemantico("ERROR : La Variable que esta a la derecha de la asignacion NO Esta Declarada",yylineno);

                                                                                                                    
                                       
                                }
                        }
                                                            
                                        
                     | IDENTIFICADOR '=' CONSTANTE_CARACTER  {
                                                                aux=buscoSimbolo($<cadena>1); 
                                                                if (aux) 
                                                                        agregarErrorSemantico("ERROR : La Variable Ya Esta Declarada", yylineno); 
                                                                else {
                                                                        if (strcmp(tipo, "char") == 0) {
                                                                                aux = agregoSimbolo(strdup($<cadena>1), tipo, 1);  
                                                                                aux->value.valChar = $<caracter>3; 
                                                                                printf("\nSe declara la variable %s de tipo %s con valor %c\n\n",aux->nombre,aux->tipo, aux->value.valChar);
                                                                        }
                                                                        else 
                                                                                agregarErrorSemantico("ERROR : Son De Distinto Tipo",yylineno);
                                                                }
                                                        }

                       | IDENTIFICADOR '=' CONSTANTE_ENTERA    {
                                                                aux=buscoSimbolo($<cadena>1); 
                                                                if (aux) 
                                                                        agregarErrorSemantico("Error : la variable ya esta declarada ",yylineno); 
                                                                        else  {
                                                                                
                                                                                if (strcmp(tipo,"int") == 0)  {
                                                                                        aux = agregoSimbolo(strdup($<cadena>1) , tipo, 1) ;  
                                                                                        aux->value.valEnt = $<mystruct>3.valor_entero; 
                                                                                        printf("\nSe declara la variable %s de tipo %s con valor %i\n\n",aux->nombre,aux->tipo, aux->value.valEnt);
                                                                                        } 
                                                                                else 
                                                                                        agregarErrorSemantico("Error : son de distinto tipo",yylineno);
                                                                        
                                                                           }

                                                        }
                        
                       | IDENTIFICADOR '=' CONSTANTE_REAL     { 
                                                                aux=buscoSimbolo($<cadena>1); 
                                                                if (aux) 
                                                                        agregarErrorSemantico("Error  : la variable ya esta declarada ",yylineno); 
                                                                else 
                                                                        if (strcmp(tipo, "float") == 0) {
                                                                                aux=agregoSimbolo($<cadena>1 , tipo, 1);  
                                                                                aux->value.valReal = $<mystruct>3.valor_real; 
                                                                                 printf("\nSe declara la variable %s de tipo %s con valor %f\n\n",aux->nombre,aux->tipo, aux->value.valReal);
                                                                                        } 
                                                                        else 
                                                                                agregarErrorSemantico("Error : son de distinto tipo ",yylineno);
                                                        }
                           | IDENTIFICADOR '=' LITERAL_CADENA      {
                                                                aux=buscoSimbolo($<cadena>1); 
                                                                if (aux) 
                                                                        agregarErrorSemantico("Error : la variable ya esta declarada ",yylineno);
                                                                else {
                                                                        if (strcmp(tipo, "char*") == 0) {
                                                                                aux = agregoSimbolo(strdup($<cadena>1) , tipo, 1);  
                                                                                aux->value.valString = $<cadena>3; 
                                                                           printf("\nSe declara la variable %s de tipo %s con valor %s\n\n",aux->nombre,aux->tipo, aux->value.valString);
                                                                                        } 
                                                                        else 
                                                                                agregarErrorSemantico("Error : son de distinto tipo ",yylineno);
                                                        }


                                            }

                             
                                                       
                            | IDENTIFICADOR '=' error               { agregarErrorSemantico("Error  :  se inicializo con un valor incorrecto",yylineno); }

                            | error '='                             {   agregarErrorSemantico("Error  : identificador incorrecto ",yylineno);}
                            
;
declaracionDefinicionFuncion: IDENTIFICADOR parametrosCuerpoFuncion { 
                                                                        aux=buscoSimbolo($<cadena>1); 
                                                                        if (aux)  agregarErrorSemantico("Error: el identificador ya esta declarado",yylineno); 
                                                                        else {
                                                                                aux=agregoSimbolo($<cadena>1 , tipo, 2);   
                                                                                aux->tiposParametros = listaParametrosAux; 

                                                                                 }
                                                                       listaParametrosAux = NULL; }


                              | error parametrosCuerpoFuncion {  agregarErrorSemantico("Error: nombre de la funcion incorrecto",yylineno);}
;
                    
parametrosCuerpoFuncion:   '(' listaParametros ')' ';'    

;

listaParametros:         /* vacio */  { agregoParametro("void");} 
                | parametros
                | parametros ',' listaParametros 
;
               
parametros:      
                 TIPO_DE_DATO IDENTIFICADOR       { agregoParametro($<cadena>1);} 
                | TIPO_DE_DATO '*' IDENTIFICADOR   { agregoParametro(strcat(tipo,"*"));}
                | error IDENTIFICADOR              { agregarErrorSemantico("ERROR : falta tipo de dato del parametro",yylineno);}
                | error '*' IDENTIFICADOR          { agregarErrorSemantico("ERROR : falta tipo de dato del puntero parametro",yylineno);}
                | TIPO_DE_DATO error               { agregarErrorSemantico("ERROR : falta identificador en parametro",yylineno);}
                | TIPO_DE_DATO '*' error           { agregarErrorSemantico("ERROR : falta identificador del puntero parametro",yylineno);}

;

invocacionDeFuncion:  IDENTIFICADOR '(' listaArgumentos ')'     {
                                                               aux=buscoSimbolo($<cadena>1);  
                                                               if (aux) { 
                              if(aux->type == 1){
                                           printf ("Error: El IDENTIFICADOR esta declarado como variable");} 
                     
                        if (compararParametros(aux->tiposParametros, listaParametrosAux) == 1){
                        printf ("Error: cantidad o tipos de parametros incorrectos\n");} 
                        
                         if (compararParametros(aux->tiposParametros, listaParametrosAux) == 0){
                        printf ("\nCantidad y tipos de parametros correctos\n");} 

                         } 
                     else {
                          printf ("Error: No esta declarada la funcion\n"); 
                            }
                                                                
                         listaParametrosAux = NULL;
                         
                        }                                        
                                                             
                                                                                         
                                                               
                                                                                                                                                              
                     | IDENTIFICADOR error listaArgumentos ')' {agregarErrorSemantico("ERROR : falta '(' en la invocacion de la funcion",yylineno);}
                     | IDENTIFICADOR '(' listaArgumentos error {agregarErrorSemantico("ERROR : falta ')' en la invocacion de la funcion",yylineno);}
;

listaArgumentos: argumento                           
                | argumento ',' listaArgumentos      
;

argumento: /* vacio */ {agregoArgumento("void");}
        | IDENTIFICADOR        {        
                                        aux=buscoSimbolo($<cadena>1);    
                                        if (aux) 
                                                agregoArgumento(aux->tipo); 
                                        else 
                                                agregarErrorSemantico("ERROR : la variable no esta declarada\n",yylineno);
                                }
        | LITERAL_CADENA      { agregoArgumento("char*"); }
        | CONSTANTE_ENTERA    { agregoArgumento("int"); } 
        | CONSTANTE_CARACTER  { agregoArgumento("char"); }
        
;

expresion:               CONSTANTE_ENTERA  {$<mystruct>$.tipo=$<mystruct>1.tipo;$<mystruct>$.valor_entero=$<mystruct>1.valor_entero;}
	  		| CONSTANTE_REAL   {$<mystruct>$.tipo=$<mystruct>1.tipo;$<mystruct>$.valor_real=$<mystruct>1.valor_real;}	
	  		| expresion '+' expresion { if($<mystruct>1.tipo==$<mystruct>3.tipo)  { 

                                  if($<mystruct>1.tipo==1)  {$<mystruct>$.valor_entero=$<mystruct>1.valor_entero+$<mystruct>3.valor_entero;}
        
                                  else { $<mystruct>$.valor_real=$<mystruct>1.valor_real+$<mystruct>3.valor_real;}
                         }
        
                         else { printf("Los operandos son de distinto tipo no se realizo la operacion completa \n");}
        
                         }

                        | expresion '-' expresion { if($<mystruct>1.tipo==$<mystruct>3.tipo) { 
       
                                 if($<mystruct>1.tipo==1) {$<mystruct>$.valor_entero=$<mystruct>1.valor_entero+$<mystruct>3.valor_entero; }
        
                                  else   {$<mystruct>$.valor_real=$<mystruct>1.valor_real+$<mystruct>3.valor_real;}
                          }
        
                         else { printf("Los operandos son de distinto tipo no se realizo la operacion completa\n");}
        
                         }

	  		| expresion '*' expresion { if($<mystruct>1.tipo==$<mystruct>3.tipo)  { 

                            if($<mystruct>1.tipo==1) { $<mystruct>$.valor_entero=$<mystruct>1.valor_entero+$<mystruct>3.valor_entero; }
        
                            else  { $<mystruct>$.valor_real=$<mystruct>1.valor_real+$<mystruct>3.valor_real; }

                         }
        
                        else  { printf("Los operandos son de distinto tipo no se realizo la operacion completa \n");}
        
                         }
                        | expresion '/' expresion

                        | '(' expresion ')' { $<mystruct>$.valor_entero = $<mystruct>2.valor_entero ; }


;

%%

// Puntero que apunta a la tabla de símbolos
symrec *sym_table;

int main(){
        #ifdef BISON_DEBUG
        yydebug = 1;
        #endif

        yyin = fopen("archivo.c","r");
        printf("\n");
        yyparse();
        
        mostrarListaVariables();
        mostrarListaFunciones();
        mostrarErrorSintactico();
        mostrarErrorSemantico();
}