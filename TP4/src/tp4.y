%{
    #include <stdio.h>

int yylex();
int yyerror (char*);
int yywrap(){
    return (1);
}

extern FILE* yyin;

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
%token ENUM 
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
//  EXPRESIONES //

expresion: exp_asignacion {puts ("Encontre una expresión");}
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
// %% SENTENCIAS %%

sentencia: 
    sent_expresion
   | sent_compuesta
   | sent_seleccion 
   | sent_iteracion
   | sent_seleccion
;

sent_expresion: 
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
    | error ';'
;
// %% SENTENCIAS COMPUESTAS %%

sent_compuesta: 
    '{' listaSentencias '}'
;

listaSentencias: 
    listaSentencias sentencia
    | sentencia
// | vacio
;



//  Gramatica declaraciones 

declaracion: especificadores_declaracion lista_declaradores_opcional
; //preguntar si es necesario el punto y coma despues de cada produccion

lista_declaradores_opcional:    // Vacio //
                                | lista_declaradores
;

especificadores_declaracion: especificador_declase_dealmacenamiento especificadores_declaracion_opcional
                             | especificador_tipo  especificadores_declaracion_opcional
                             | calificador_detipo  especificadores_declaracion_opcional //CALIFICADOR_DETIPO = CONST VOLATILE
;

especificadores_declaracion_opcional:   // Vacio //
                                    | especificadores_declaracion
;

lista_declaradores:   declarador
                    | lista_declaradores ',' declarador
;

declarador:   decla
            | decla '=' inicializador
;

inicializador:   exp_asignacion
               | '{' lista_deinicializadores coma_opcional '}' // chequear si esta bien 
;

coma_opcional:  // Vacio //
                | ','
;

lista_deinicializadores:   inicializador
                       | lista_deinicializadores ',' inicializador
;

especificador_declase_dealmacenamiento:  TYPEDEF
                                        | STATIC  
                                        | AUTO
                                        | REGISTER
                                        | EXTERN
;


especificador_tipo:   tipo_dedato 
                    | especificador_struct_union
                    | especificador_enum
                    | nombre_detypedef
;

tipo_dedato:     VOID
                | CHAR
                | SHORT
                | INT
                | LONG
                | FLOAT
                | DOUBLE
                | SIGNED
                | UNSIGNED
;

especificador_struct_union:   struct_union IDENTIFICADOR_opcional '{' lista_declaradores_struct '}'
                            | struct_union IDENTIFICADOR
;

calificador_detipo:  CONST
                    | VOLATILE 
;


IDENTIFICADOR_opcional:   // Vacio //
                         | IDENTIFICADOR
;

struct_union: STRUCT
             | UNION
;

lista_declaradores_struct:   declaracion_struct
                           | lista_declaradores_struct declaracion_struct
;

declaracion_struct: lista_calificadores declaradores_struct ';'
;

lista_calificadores:   especificador_tipo lista_calificadores_opcional
                     | calificador_detipo lista_calificadores_opcional
;

lista_calificadores_opcional:   // Vacio //
                             | lista_calificadores
;

declaradores_struct:   decla_struct
                     | declaradores_struct ',' decla_struct
;

decla_struct:   decla
              //| decla_opcional ':' exp_constante
              | decla_opcional ':' constante
;


decla_opcional:   // Vacio //
                | decla
;

decla: puntero_opcional declarador_directo
;

puntero_opcional:   // Vacio //
                 | puntero
;

puntero:   '*' lista_calificadores_tipos_opcional
         | '*' lista_calificadores_tipos_opcional puntero
;

lista_calificadores_tipos_opcional:   // Vacio //
                                    | lista_calificadores_tipos
;

lista_calificadores_tipos:   calificador_detipo
                           | lista_calificadores_tipos calificador_detipo
;

declarador_directo:   IDENTIFICADOR
                    | '(' decla ')'
                    | declarador_directo '[' exp_constante ']' //exp_constante_opcional no esta en el PDF 
                    | declarador_directo '(' lista_tipos_param ')'
                    | declarador_directo '(' lista_identificadores_opcional ')'
;

lista_identificadores_opcional:   // Vacio //
                                | lista_identificadores
;

lista_tipos_param:   lista_parametros
                   | lista_parametros ',' '.' '.' '.'
;

lista_parametros:   declaracion_parametro
                  | lista_parametros ',' declaracion_parametro
;

declaracion_parametro:   especificadores_declaracion decla
                       | especificadores_declaracion declarador_abstracto_opcional
;

declarador_abstracto_opcional:   // Vacio //
                                 | declarador_abstracto
;   

lista_identificadores:   IDENTIFICADOR
                       | lista_identificadores ',' IDENTIFICADOR
;

especificador_enum:   ENUM IDENTIFICADOR_opcional '{' lista_enumeradores'}'
                    | ENUM IDENTIFICADOR //Agregar ENUM a %TOken
;

lista_enumeradores:   enumerador
                    | lista_enumeradores ',' enumerador
;

enumerador:   const_de_enumeracion
           // | const_de_enumeracion '=' exp_constante
              | const_de_enumeracion '=' constante
;

const_de_enumeracion: IDENTIFICADOR
;

nombre_detypedef: IDENTIFICADOR
;

nombre_tipo: lista_calificadores declarador_abstracto_opcional
;

declarador_abstracto:   puntero
                      | puntero_opcional declarador_abstracto_directo
;

declarador_abstracto_directo:   '(' declarador_abstracto ')'
                              | declarador_abstracto_directo_opcional '['   exp_constante   ']'
                              | declarador_abstracto_directo_opcional '(' lista_tipos_param_opcional ')' 
;

declarador_abstracto_directo_opcional:   // Vacio //
                                     | declarador_abstracto_directo
;

lista_tipos_param_opcional:   // Vacio //
                        | lista_tipos_param
;

%%

int yyerror (char *mensaje)  /* Funcion de error */
{
  printf ("Error: %s\n", mensaje);
}

int main(){

   #ifdef BISON_DEBUG
        yydebug = 1;
    #endif    
    yyin = fopen ("docDePrueba.c","r");
    printf("Entre al parse:\n");
    yyparse();
    return 0;
}
