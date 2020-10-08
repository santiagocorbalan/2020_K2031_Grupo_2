%{
    #include <stdio.h>

int yylex();
int yyerror (char*);
int yywrap(){
    return (1);
}

extern FILE* yyin;
flag_ExpresionEncontrada = 0;

%}


%union {
    int enteroval;
    char* strval;
    double dobleval;
}

%token IDENTIFICADOR
%token INCREMENTO DECREMENTO //++ y --
%token INCREMENTOASIGNACION DECREMENTOASIGNACION  // += y -=
%token AND OR // && y ||
%token RELACIONALIGUAL RELACIONALDIFERENTE // == y !=
%token MAYORIGUAL MENORIGUAL // >= y <=
%token ACCESOPUNTERO // -> 
%token CONSTANTEDECIMAL CONSTANTEOCTAL CONSTANTEHEXADECIMAL  CONSTANTEREAL CONSTANTECARACTER
%token LITERALCADENA
%token CHAR INT DOUBLE FLOAT LONG SHORT
%token IF ELSE WHILE DO SWITCH FOR CASE BREAK DEFAULT 
%token RETURN
%token TYPEDEF STATIC AUTO REGISTER EXTERN
%token STRUCT UNION
%token VOID SIGNED UNSIGNED
%token VOLATILE CONST
%token TIPO_DATO
//token error //Lo implementamos al final de todo
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
%type <strval> sentenciaCase
%type <strval> sentenciaSwitch
%type <strval> sentenciaSwitchDefault
%type <strval> listaSentencias


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

programa:     '\n'
        | expresion '\n'
        | sentencia '\n'
        | expresion '\n'
;

// SENTENCIAS 

sentencia: 
    sent_expresion
   | sent_compuesta
   | sent_seleccion 
   | sent_iteracion
;

sent_expresion: 
    expresion ';'
    //| error ';'
;

sent_compuesta: 
    '{' listaDeDeclaracionesOpcional listaSentencias '}'
;

listaDeDeclaracionesOpcional: /* vacio */
                                | declaracion
                                | listaDeDeclaracionesOpcional declaracion
;
listaSentencias: 
    listaSentencias sentencia
    | sentencia // | vacio
;

sent_seleccion: 
    IF '(' expresion ')' sentencia 
    | IF '(' expresion ')' sentencia ELSE sentencia 
    | SWITCH '(' expresion ')' sentenciaSwitch
    | error ';'
;

sentenciaSwitch: 
    '{' sentenciaCase sentenciaSwitchDefault '}'
    | '{' sentenciaCase '}'
    | '{' sentenciaSwitchDefault '}'
    | '{' '}'
    | error '}'
;

sentenciaCase: 
  //  CASE num ':' sentencia 
    CASE constante ':' sentencia
    | error '}'
;

sentenciaSwitchDefault: 
    DEFAULT ':' sentencia
    | error '}'
;

sent_iteracion: 
    WHILE '(' expresion ')' sentencia
    | DO sentencia WHILE '(' expresion ')' ';'
    | FOR '(' expresion ';' expresion ';' expresion ')' sentencia
 //   | error ';'
;


//  EXPRESIONES //

expresion: exp_asignacion 
            | expresion ',' exp_asignacion
;
exp_asignacion:
    exp_condicional
    | exp_unaria op_asignacion exp_asignacion
;
exp_condicional:
    exp_o_logico
    | exp_o_logico '?' expresion ':' exp_condicional
;
op_asignacion: '=' | INCREMENTOASIGNACION | DECREMENTOASIGNACION ;
//Los demás no los agrego porque no son tan importantes.

exp_o_logico:
    exp_y_logico
    | exp_o_logico OR exp_y_logico
;
exp_y_logico:
    exp_y       //exp_o_inclusivo
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
exp_relacional:
    //exp_corrimiento
    exp_aditiva
    | exp_relacional '<' exp_aditiva
    | exp_relacional '>' exp_aditiva
    | exp_relacional MENORIGUAL exp_aditiva
    | exp_relacional MAYORIGUAL exp_aditiva
;
exp_aditiva:
    exp_multiplicativa
    | exp_aditiva '+' exp_multiplicativa
    | exp_aditiva '-' exp_multiplicativa
;
exp_multiplicativa:
    exp_unaria
    | exp_multiplicativa '*' exp_unaria
    | exp_multiplicativa '/' exp_unaria
    | exp_multiplicativa '%' exp_unaria
;

exp_unaria:
    exp_sufijo
    | INCREMENTO exp_unaria
    | DECREMENTO exp_unaria
;
exp_sufijo:
    exp_primaria    
    | exp_sufijo '[' expresion ']'
    | exp_sufijo '(' listaArgumentos ')'
    | exp_sufijo '.' IDENTIFICADOR
    | exp_sufijo ACCESOPUNTERO IDENTIFICADOR
    | exp_sufijo INCREMENTO
    | exp_sufijo DECREMENTO
;

listaArgumentos:
    exp_asignacion
    | listaArgumentos ',' exp_asignacion
;

exp_primaria:
    IDENTIFICADOR
    | constante
    | LITERALCADENA
    | '(' expresion ')'
;

constante:
     CONSTANTEDECIMAL
    | CONSTANTEOCTAL 
    | CONSTANTEHEXADECIMAL
    | CONSTANTEREAL
    | CONSTANTECARACTER
;    

exp_constante:
    exp_condicional
    ;


//  DECLARACIONES

declaracion:    
                  declaracionVariablesSimples 
                | declaracionFunciones
                | definicionFunciones
;

declaracionVariablesSimples: 
                            TIPO_DATO listaVariablesSimples ';'
;

listaVariablesSimples:  
                        unaVariableSimple       
                        | listaVariablesSimples ',' unaVariableSimple
;

unaVariableSimple:      
                        IDENTIFICADOR opcionInicializacion
;

opcionInicializacion:   /* vacio */
                            | opcionDeAsignacion constante
;

opcionDeAsignacion: 
                       = 
                    | *= 
                    | += 
                    | -= 
; 

constante: 
            | CONSTANTEDECIMAL
            | CONSTANTEHEXADECIMAL
            | CONSTANTEOCTAL
            | CONSTANTEREAL
            | CONSTANTECARACTER
            | LITERALCADENA

;

declaracionFunciones:   
                        TIPO_DATO IDENTIFICADOR '(' opcionArgumentosConTipo ')' ';' 
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

definicionFunciones:    
                        TIPO_DATO IDENTIFICADOR '(' opcionArgumentosConTipo ')' sentencia
;
%%
/*
int yyerror (char *mensaje)  // Funcion de error //
{
  printf ("Error: %s\n", mensaje);
}
*/

int main(){

/*
   #ifdef BISON_DEBUG
        yydebug = 1;
    #endif    
*/    
    yyin = fopen ("docDePrueba.c","r");
    printf("Entre al parse:\n");
    yyparse();
    return 0;
}
