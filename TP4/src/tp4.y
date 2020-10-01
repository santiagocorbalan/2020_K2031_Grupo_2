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
%token TYPEDEF STATIC AUTO REGISTER EXTERN
%token STRUCT UNION
%token VOID SIGNED UNSIGNED
%token VOLATILE CONST


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

declaracion: especificadores_declaracion lista_declaradores_opcional
; //preguntar si es necesario el punto y coma despues de cada produccion

lista_declaradores_opcional:    /* Vacio */
                                | lista_declaradores
;

especificadores_declaracion: especificador_declase_dealmacenamiento especificadores_declaracion_opcional
                             | especificador_tipo  especificadores_declaracion_opcional
                             | calificador_detipo  especificadores_declaracion_opcional //CALIFICADOR_DETIPO = CONST VOLATILE
;

especificadores_declaracion_opcional:   /* Vacio */
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

coma_opcional:   /* Vacio */
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

calificador_detipo:  CONST
                    | VOLATILE 

especificador_struct_union:   struct_union IDENTIFICADOR_opcional '{' lista_declaradores_struct '}'
                            | struct_union IDENTIFICADOR
;

IDENTIFICADOR_opcional:   /* Vacio */
                         | IDENTIFICADOR
;

struct_union: STRUCT
             | UNION


lista_declaradores_struct:   declaracion_struct
                           | lista_declaradores_struct declaracion_struct
;

declaracion_struct: lista_calificadores declaradores_struct ';'
;

lista_calificadores:   especificador_tipo lista_calificadores_opcional
                     | calificador_detipo lista_calificadores_opcional
;

lista_calificadores_opcional:   /* Vacio */
                             | lista_calificadores
;

declaradores_struct:   decla_struct
                     | declaradores_struct ',' decla_struct
;

decla_struct:   decla
              | decla_opcional ':' exp_constante
;

decla_opcional:   /* Vacio */
                | decla
;

decla: puntero_opcional declarador_directo
;

puntero_opcional:   /* Vacio */
                 | puntero
;

puntero:   '*' lista_calificadores_tipos_opcional
         | '*' lista_calificadores_tipos_opcional puntero
;

lista_calificadores_tipos_opcional:   /* Vacio */
                                    | lista_calificadores_tipos
;

lista_calificadores_tipos:   calificador_detipo
                           | lista_calificadores_tipos calificador_detipo
;

declarador_directo:   IDENTIFICADOR
                    | '(' decla ')'
                    | declarador_directo '[' exp_constante_opcional ']' //exp_constante_opcional no esta en el PDF 
                    | declarador_directo '(' lista_tipos_param ')'
                    | declarador_directo '(' lista_identificadores_opcional ')'
;

lista_identificadores_opcional:   /* Vacio */
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

declarador_abstracto_opcional:   /* Vacio */
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
            | const_de_enumeracion '=' exp_constante
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
                              | declarador_abstracto_directo_opcional '['   exp_constante_opcional   ']'
                              | declarador_abstracto_directo_opcional '(' lista_tipos_param_opcional ')' 
;

declarador_abstracto_directo_opcional:   /* Vacio */
                                     | declarador_abstracto_directo
;

lista_tipos_param_opcional:   /* Vacio */
                        | lista_tipos_param
;



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
