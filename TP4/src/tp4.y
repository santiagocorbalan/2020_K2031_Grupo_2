%{
    #include <stdio.h>

int yylex();
int yyerror (char*);
int yywrap(){
    return (1);
}

%}


%union {
    int enteroval;
    char* stringval;
    double dobleval;
}

%token IDENTIFICADOR
%token <strval> INCREMENTO DECREMENTO //++ y --
%token <strval> INCREMENTOASIGNACION DECREMENTOASIGNACION  // += y -=
%token <strval> AND OR // && y ||
%token <strval> RELACIONALIGUAL RELACIONALDIFERENTE // == y !=
%token <strval> MAYORIGUAL MENORIGUAL // >= y <=
%token ACCESOPUNTERO // -> 
%token CONSTANTE CONSTANTEDECIMAL CONSTANTEOCTAL CONSTANTEHEXADECIMAL CONSTANTEPUNTOFIJO CONSTANTEREAL CONSTANTECARACTER
%token CHAR INT DOUBLE FLOAT LONG SHORT
%token <strval> IF ELSE WHILE DO SWITCH FOR CASE BREAK DEFAULT 
%token <strval> RETURN 
%token error //Lo implementamos al final de todo

%type expresion
%type exp_asignacion
%type exp_igualdad
%type exp_o_inclusivo
%type exp_o_logico
%type exp_y
%type exp_y_logico
%type exp_unaria
%type op_asignacion
%type num
%type sentencia
%type sent_iteracion
%type sent_compuesta
%type sentenciaCase
%type sentenciaSwitch
%type sentenciaSwitchDefault
%type listaSentencias

%left '='
%right AND OR
%right '<' '>' MAYORIGUAL MENORIGUAL
%right RELACIONALIGUAL RELACIONALDIFERENTE
%right '+' '-'
%right '*' '/' '^' '%'

// %% EXPRESIONES %%

expresion: 
    exp_asignacion 
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
operador_asignacion: '=' | INCREMENTOASIGNACION | DECREMENTOASIGNACION ;
//Los demás no los agrego porque no son tan importantes.

exp_o_logico:
    exp_y_logico
    | exp_o_logico OR exp_y_logico
;
exp_y_logico:
    exp_o_inclusivo
    | exp_y_logico AND exp_o_inclusivo
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
    exp_corrimiento
    | exp_relacional '<' exp_corrimiento
    | exp_relacional '>' exp_corrimiento
    | exp_relacional MENORIGUAL exp_corrimiento
    | exp_relacional MAYORIGUAL exp_corrimiento
;
exp_aditiva:
    exp_multiplicativa
    | exp_aditiva '+' exp_multiplicativa
    | exp_aditiva '-' exp_multiplicativa
;
exp_multiplicativa:
    exp_conversion
    | exp_multiplicativa '*' exp_conversion
    | exp_multiplicativa '/' exp_conversion
    | exp_multiplicativa '%' exp_conversion
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
    | CONSTANTE
//| CONSTANTE CADENA
    | '(' expresion ')'
;

// %% SENTENCIAS %%

sentencia: 
    sent_expresion
   | sent_compuesta
   | sent_seleccion 
   | sent_iteracion
   | sent_seleccion
;

sentExpresion: 
    expresion ';'
    | error ';'
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
    CASE num ':' sentencia 
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
    | error ';'

// %% SENTENCIAS COMPUESTAS %%

sent_compuesta: 
    '{' listaSentencias '}'
;

listaSentencias: 
    listaSentencias sentencia
    | sentencia
// | vacio
;

// %% Gramatica declaraciones %%


int yyerror (char *mensaje)  /* Funcion de error */
{
  printf ("Error: %s\n", mensaje);
}

void main(){

   #ifdef BISON_DEBUG
        yydebug = 1;
#endif    
 
   printf("Entre al parse:\n");
   yyparse();
}
