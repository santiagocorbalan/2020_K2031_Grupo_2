%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "Funciones.c"

void yyerror (char const *s) {          //Con yyerror se detecta el error sintáctico 
   fprintf (stderr, "%s\n", s);
}  

FILE* yyin;

int yylex();

int yywrap(){
    return(1);
}

Tabla *aux;
char* tipo;

%}

%union {

char* cadena;
int entero;
float real;
char caracter;

 struct yylval_struct
  {
      int tipo;
      int valor_entero;
      float valor_real;
      char valor_caracter;
  } mystruct;

}

%token <entero> CONSTANTE_DECIMAL
%token <entero> CONSTANTE_OCTAL
%token <entero> CONSTANTE_HEXADECIMAL
%token <real>   CONSTANTE_REAL
%token <caracter> CONSTANTE_CARACTER
%token <cadena> LITERAL_CADENA  
%token <cadena> TIPO_DATO 
%token <cadena> IDENTIFICADOR
%token SWITCH
%token BREAK
%token CONTINUE
%token WHILE
%token IF
%token ELSE
%token FOR
%token RETURN
%token error

%type <entero> exp

%%

input:    /* vacio */
        | input line
;


line:   '\n'
        | exp  '\n'                   
        | sentencia   '\n'             
        | declaracion  '\n'  
        | invocacionDeFuncion '\n'          
;

//------------------------ Expresiones ----------------------------

// Hace validación de tipos; le copia el tipo y el valor a la expresión

exp:	
      | CONSTANTE_CARACTER        {$<mystruct>$.tipo = $<mystruct>1.tipo; $<mystruct>$.valor_caracter = $<mystruct>1.valor_caracter;}  
			| CONSTANTE_DECIMAL				  {$<mystruct>$.tipo = $<mystruct>1.tipo; $<mystruct>$.valor_entero=$<mystruct>1.valor_entero;}
			| CONSTANTE_HEXADECIMAL     {$<mystruct>$.tipo = $<mystruct>1.tipo; $<mystruct>$.valor_entero=$<mystruct>1.valor_entero;}
			| CONSTANTE_OCTAL					  {$<mystruct>$.tipo = $<mystruct>1.tipo; $<mystruct>$.valor_entero=$<mystruct>1.valor_entero;}
			| CONSTANTE_REAL   				  {$<mystruct>$.tipo = $<mystruct>1.tipo; $<mystruct>$.valor_real=$<mystruct>1.valor_real;}
			| exp '+' exp               {if($<mystruct>1.tipo == $<mystruct>3.tipo)} // Validacion sobre operacion binaria de la suma
 
    { 
        if($<mystruct>1.tipo == 1) {  // Si es de tipo entero
          $<mystruct>$.valor_entero = $<mystruct>1.valor_entero + $<mystruct>3.valor_entero;
        }
        
        if{ ($<mystruct>1.tipo == 2) // Si es de tipo real
           $<mystruct>$.valor_real = $<mystruct>1.valor_real + $<mystruct>3.valor_real;
        }

        if {  ($<mystruct>1.tipo == 3) // Si es de tipo caracter
                $<mystruct>$.valor_caracter = $<mystruct>1.valor_caracter + $<mystruct>3.valor_caracter;
              }
    else
    {
        printf("Los operandos son de distinto tipo \n"); // Error semántico
    }

}

// Diferentes operaciones binarias, se repetiría el código anterior.
| exp '-' exp        { $$ = $1 - $3;                    	}
| exp '*' exp        { $$ = $1 * $3;                    	}
| exp '/' exp        { $$ = $1 / $3;                    	}
| '-' exp  %prec NEG { $$ = -$2;                        	}
| exp '^' exp        { $$ = pow ($1, $3);               	}
| '(' exp ')'        { $$ = $2;                         	}
;

// ------------- Sentencias ------------------------


sentencia:       sentenciaExpresion                                                       
                | sentenciaCompuesta                                                       
                | sentenciaDeSeleccion                                     
                | sentenciaDeIteracion           
                | sentenciaDeSalto                

;

sentenciaExpresion: opExpresion ';'                   
                                   
;

opExpresion: /* vacio */      {printf("Se encontro una sentencia vacia\n");}
             | expresion      {printf("Se encontro una sentencia con una expresion\n");}    
;

sentenciaCompuesta:     '{' opListaDeclaraciones opListaDeSentencias '}'
                      
;

opListaDeclaraciones:       /* vacio */                   
                            | listaDeclaraciones          {printf("Se encontro una sentencia compuesta con una lista de declaraciones\n");}
;

listaDeclaraciones:               declaracion                           
                                | listaDeclaraciones declaracion  
;


opListaDeSentencias:       /* vacio */
                         | listaDeSentencias                {printf("Se encontro una sentencia compuesta con una lista de sentencias\n");}
;

listaDeSentencias:              sentencia
                                | listaDeSentencias sentencia	

;


sentenciaDeSeleccion:     IF '(' expresion ')' sentencia                                          {printf("Se encontro una sentencia IF");} 
                        | IF '(' expresion ')' sentencia ELSE sentencia                           {printf("Se encontro una sentencia IF y ELSE\n");}   
                        | IF error expresion                                                      {agregarError("Error Sintactico: falta '(' en la sentencia IF"); }
                        | IF '(' expresion error sentencia                                        {agregarError("Error Sintactico: falta ')' en la sentencia IF"); }
                        | SWITCH '(' expresion ')' sentencia                                      {printf("Se encontro una sentencia SWITCH\n");}   
                        | SWITCH error expresion                                                  {agregarError("Error Sintactico: falta '(' en la sentencia SWITCH "); }
                        | SWITCH '(' expresion error sentencia                                    {agregarError("Error Sintactico: falta ')' en la sentencia SWITCH "); }
;
 
sentenciaDeIteracion:  WHILE '(' expresion ')' sentencia                                          {printf("Se encontro la sentencia WHILE\n");}   
                       | WHILE error expresion ')'                                                {agregarError("Error Sintactico: falta '(' en la sentencia WHILE "); }
                       | WHILE '(' expresion error sentencia                                      {agregarError("Error Sintactico: falta ')' en la sentencia WHILE "); }
                       | DO sentencia WHILE '(' expresion ')' ';'                                 {printf("Se encontro una sentencia DO\n");}   
                       | FOR '(' opExpresion ';' opExpresion ';' opExpresion ')' sentencia        {printf("Se encontro una sentencia FOR\n");}  
                       | FOR error opExpresion ';'                                                {agregarError("Error Sintactico: falta '(' en la sentencia FOR "); }
                       | FOR '(' opExpresion ';' opExpresion ';' opExpresion error sentencia      {agregarError("Error Sintactico: falta ')' en la sentencia FOR "); }
                      
;


sentenciaDeSalto:  CONTINUE ';'                   {printf("Se encontro la sentencia CONTINUE\n");}
                | BREAK ';'                       {printf("Se encontro la sentencia BREAK\n");}
                | RETURN opExpresion ';'          {printf("Se encontro la sentencia RETURN\n");}  
            
;  

/// ----------------- Declaraciones --------------

declaracion:      declaracionVariablesSimples
                | declaracionFunciones
                | definicionFunciones
;

// Me guardo el tipo de la variable en cuestión
declaracionVariablesSimples: TIPO_DATO {tipo=$<cadena>1;} listaVariablesSimples ';' 
;

listaVariablesSimples:  unaVariableSimple      
                        | unaVariableSimple  ',' listaVariablesSimples
;
// Validaciones semánticas sobre doble declaración de variables, cambia la validación según cómo sea la declaración de la variable
unaVariableSimple:   IDENTIFICADOR                             {aux = buscarSimbolo($<cadena>1); if (aux) agregarError("Error Semantico : la variable ya esta declarada "); else agregarsimbolo($<cadena>1,tipo);} 
                    | IDENTIFICADOR '=' IDENTIFICADOR          {aux=buscarSimbolo($<cadena>1); if (aux) agregarError("Error Semantico : la variable ya esta declarada "); declararVariableConElIgual($<cadena>1,tipo,$<cadena>3);}
                    // El control acá es doble primero si existe el segundo identificador en la tabla, y segundo si tiene el mismo tipo que el identificador al que se lo está asignando
                    | IDENTIFICADOR '=' CONSTANTE_DECIMAL      {aux=buscarSimbolo($<cadena>1); if (aux) agregarError("Error Semantico : la variable ya esta declarada "); else declararVariable($<strval>1,tipo,$<entero>3);}
                    | IDENTIFICADOR '=' CONSTANTE_CARACTER     {aux=buscarSimbolo($<cadena>1); if (aux) agregarError("Error Semantico : la variable ya esta declarada "); else declararVariable($<strval>1,tipo,$<caracter>3);}
                    | IDENTIFICADOR '=' CONSTANTE_REAL         {aux=buscarSimbolo($<cadena>1); if (aux) agregarError("Error Semantico : la variable ya esta declarada "); else declararVariable($<strval>1,tipo,$<real>3);}
                    | IDENTIFICADOR '=' error                  {agregarError("Error Sintactico : se inicializo con un valor incorrecto");}
                    | error '='                                {agregarError("Error Sintactico : identificador incorrecto");}
;

declaracionFuncion:    TIPO_DATO {tipo = $<cadena>1; }  IDENTIFICADOR {id = $<cadena>2;}  '(' listaParametro ')' ';' {aux=buscarSimbolo($<cadena>2); if (aux) agregarError("Error Semantico : el identificador ya esta declarado");  else declararFuncion(id, tipo); }
                      | error cuerpoParametros { agregarError("Error Sintactico : identificador incorrecto  en declaracion de funcion"); }
; 
                           
listaParametro: parametro
               | parametro ',' listaParametro
;

parametro:   TIPO_DATO IDENTIFICADOR           {aux=buscarEnListaFunciones(id); if(aux) agregoParametros(aux->lista_parametros,$<cadena>1)}                                                    
            | TIPO_DATO '*' IDENTIFICADOR   {aux=buscarEnListaFunciones(id); if(aux) agregoParametros(aux->lista_parametros,strcat($<cadena>1,"*")) }
            | error IDENTIFICADOR              {agregarError("Error sintactico : falta tipo de dato del parametro")}
            | error '*' IDENTIFICADOR          {agregarError("Error sintactico : falta tipo de dato del puntero parametro")}
            | TIPO_DATO error               {agregarError("Error sintactico : falta indentificador del parametro")}
            | TIPO_DATO '*' error           {agregarError("Error sintactico : falta identificador del puntero del  parametro")}
;
// Control de cantidad y tipos de parámetros en la invocación a funciones
invocacionDeFuncion:    IDENTIFICADOR '(' listaArgumentos ')'   {aux=buscarEnListaFuciones($<cadena>1); if (aux) verificarParametros(aux->lista_parametros) else listaArgumentosTemporal = NULL;}
                      // Falta completar funciones respecto a cantidad y tipos de parámetros
                     |  IDENTIFICADOR error listaArgumentos ')' {agregarError("Error Sintactico : falta '(' en la invocacion de la funcion"); }
                     |  IDENTIFICADOR '(' error ')'             {agregarError("Error Sintactico : argumentos no validos");}
                     |  IDENTIFICADOR '(' listaArgumentos error {agregarError("Error Sintactico : falta ')' en la invocacion de la funcion"); }
;

listaArgumentos:   argumento                           
                 | argumento ',' listaArgumentos      
;

argumento:        /* vacio */         
                | IDENTIFICADOR       {aux=buscarSimbolo($<cadena>1); if (aux) agregarArgumento(aux->tipo); else agregarError("Error Semantico : la variable %s no esta declarada \n",$<cadena>1);}
                | LITERAL_CADENA      {agregoArgumento("char*");}
                | CONSTANTE_DECIMAL   {agregoArgumento("int");} 
                | CONSTANTE_CARACTER  {agregoArgumento("char");}

definicionFunciones: TIPO_DATO IDENTIFICADOR '(' opcionArgumentosConTipo ')' sentenciaCompuesta 



%%


int main(){
/*         #ifdef BISON_DEBUG
        yydebug = 1;
        #endif */
        yyin = fopen("docDePrueba.c","r");
        printf("\n");
        yyparse();
        
}