%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

int yylex();

FILE* yyin;

int yyerror (char*);

int yywrap(){
    return (1);
}


int flag_ExpresionEncontrada = 0;

%}


%union {
    int enteroval;
    char* strval;
    double dobleval;
}

%token <strval> IDENTIFICADOR
%token <strval> TIPO_DATO
%token <strval> INCREMENTO DECREMENTO                       //++ y --
%token <strval> INCREMENTOASIGNACION DECREMENTOASIGNACION   // += y -=
%token <strval> AND OR                                      // && y ||
%token <strval> RELACIONALIGUAL RELACIONALDIFERENTE         // == y !=
%token <strval> MAYORIGUAL MENORIGUAL                       // >= y <=
%token <strval> ACCESOPUNTERO                               // -> 
%token <enteroval> CONSTANTEDECIMAL CONSTANTEOCTAL CONSTANTEHEXADECIMAL 
%token <dobleval> CONSTANTEREAL 
%token <strval> CONSTANTECARACTER
%token <strval> LITERALCADENA 
%token <strval> IF ELSE WHILE DO SWITCH FOR 
%token <strval> RETURN
%token <strval> error


/*
%type <strval> expresion
%type <strval> exp_asignacion
%type <strval> exp_igualdad
%type <strval> exp_o_inclusivo
%type <strval> exp_o_logico
%type <strval> exp_y
%type <strval> exp_y_logico
%type <strval> exp_unaria
%type <strval> exp_relacional
%type <strval> exp_corrimiento
%type <strval> exp_condicional
%type <strval> op_asignacion
%type <enteroval> num
%type <strval> sentencia
%type <strval> sent_iteracion
%type <strval> sent_compuesta
%type <strval> listaSentencias
%type <strval> variableSimple
%type <strval> definicionFunciones
*/


%left '='
%right AND OR
%right '<' '>' MAYORIGUAL MENORIGUAL
%right RELACIONALIGUAL RELACIONALDIFERENTE
%right '+' '-'
%right '*' '/' '^' '%'

%%

input:    /* vacio */
        | input programa
;

programa:     expresion '\n'
            | sentencia '\n'
            | declaracion '\n'
;

// SENTENCIAS 

sentencia: 
    sent_expresion
   | sent_compuesta
   | sent_seleccion 
   | sent_iteracion
   | sent_deSalto
;

sent_expresion: ';'
                | expresion ';'

;

sent_compuesta: 
    '{' listaDeDeclaracionesOpcional listaSentenciasOpcional '}' // ambas sentencias en la llave son opcionales
;

listaDeDeclaracionesOpcional: /* vacio */
                                | declaracion
                                | listaDeDeclaracionesOpcional declaracion
;
listaSentencias: sentencia
                | listaSentencias sentencia
     
;

listaSentenciasOpcional:  /* vacio */
                        | sentencia
                        | listaSentencias sentencia
;

sent_seleccion: 
    IF '(' expresion ')' sentencia 
    | IF '(' expresion ')' sentencia ELSE sentencia 
    | SWITCH '(' expresion ')' sentencia // en vez de sentencia SWITCH la cambiamos por sentencia para acortar
    | error ';'
;

sent_iteracion: 
    WHILE '(' expresion ')' sentencia
    | DO sentencia WHILE '(' expresion ')' ';'
    | FOR '(' expresion ';' expresion ';' expresion ')' sentencia
 //   | error ';'
;

sent_deSalto: RETURN expresionOpcional ';' // contemplamos el caso del Return ya que es el mas conocido
;

expresionOpcional: /* vacio */
                    | expresion
;


//  EXPRESIONES //

expresion: exp_asignacion 
            | expresion ',' exp_asignacion
;

exp_asignacion: exp_condicional
            | exp_unaria op_asignacion exp_asignacion
;

exp_condicional: exp_o_logico
                | exp_o_logico '?' expresion ':' exp_condicional
;
op_asignacion: '=' 
                | INCREMENTOASIGNACION 
                | DECREMENTOASIGNACION 
;
//Los demás no los agrego porque no son tan importantes.

exp_o_logico: exp_y_logico
            | exp_o_logico OR exp_y_logico
;
exp_y_logico: exp_y       //exp_o_inclusivo
            | exp_y_logico AND exp_y
;
exp_y:
    exp_igualdad
    | exp_y '&' exp_igualdad
;
exp_igualdad:
    exp_relacional
    | exp_igualdad RELACIONALIGUAL exp_relacional
    | exp_igualdad RELACIONALDIFERENTE exp_relacional
;
exp_relacional: exp_aditiva
                | exp_relacional '<' exp_aditiva
                | exp_relacional '>' exp_aditiva
                | exp_relacional MENORIGUAL exp_aditiva
                | exp_relacional MAYORIGUAL exp_aditiva
;
exp_aditiva: exp_multiplicativa
            | exp_aditiva '+' exp_multiplicativa
            | exp_aditiva '-' exp_multiplicativa
;
exp_multiplicativa: exp_unaria
    | exp_multiplicativa '*' exp_unaria
    | exp_multiplicativa '/' exp_unaria
    | exp_multiplicativa '%' exp_unaria
;

exp_unaria: exp_sufijo
            | INCREMENTO exp_unaria
            | DECREMENTO exp_unaria
;

exp_sufijo:
    exp_primaria    
    | exp_sufijo '[' expresion ']'
    | exp_sufijo '(' listaArgumentosOpcional ')'
    | exp_sufijo '.' IDENTIFICADOR
    | exp_sufijo ACCESOPUNTERO IDENTIFICADOR
    | exp_sufijo INCREMENTO
    | exp_sufijo DECREMENTO
;

listaArgumentosOpcional: /* vacio */
                        | exp_asignacion
                        | listaArgumentos ',' exp_asignacion
;

exp_primaria: IDENTIFICADOR
            | constante
            | LITERALCADENA
            | '(' expresion ')'
;


//  DECLARACIONES


declaracion: declaracionVariablesSimples 
            | declaracionFunciones
            | definicionFunciones
;

declaracionVariablesSimples: TIPO_DATO listaVariablesSimples ';'
;

listaVariablesSimples: variableSimple       
                     | listaVariablesSimples ',' variableSimple
;

variableSimple: IDENTIFICADOR opcionInicializacion
;

opcionInicializacion:   /* vacio */
                     | op_asignacion constante // ojo con constante revisar
;

constante: CONSTANTEDECIMAL
        | CONSTANTEHEXADECIMAL
        | CONSTANTEOCTAL
        | CONSTANTEREAL
        | CONSTANTECARACTER
        | LITERALCADENA

;

declaracionFunciones: TIPO_DATO IDENTIFICADOR '(' opcionArgumentosConTipo ')' ';' 
;

opcionArgumentosConTipo:        /* vacio */ 
                                | TIPO_DATO opcionReferencia IDENTIFICADOR
                                | TIPO_DATO opcionReferencia IDENTIFICADOR ',' argumentosConTipo 
;

argumentosConTipo: TIPO_DATO opcionReferencia IDENTIFICADOR
                 | TIPO_DATO opcionReferencia IDENTIFICADOR ',' argumentosConTipo
;

opcionReferencia: /* vacio */
                  | '&'
;

definicionFunciones: TIPO_DATO IDENTIFICADOR '(' opcionArgumentosConTipo ')' sentencia
;
%%


int main(){


    yyin = fopen ("docDePrueba.c","r");
    printf("Entre al parse:\n");
    yyparse();
    
    return 0;
}

/*
int yyerror (char *mensaje)  // Funcion de error //
{
  printf ("Error: %s\n", mensaje);
}
*/

/*
   #ifdef BISON_DEBUG
        yydebug = 1;
    #endif    
*/    