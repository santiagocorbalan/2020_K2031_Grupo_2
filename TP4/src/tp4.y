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

int flag_error = 0;
int flag_SentExpresion = 0;
int flag_SentCompuesta = 0;
int flag_Seleccion = 0;
int flag_Iteracion = 0;
int flag_DeSalto  = 0;

%}


%union {
    int enteroval;
    char* strval;
    float dobleval;
}

%token <strval> IDENTIFICADOR
%token <strval> TIPO_DATO
%token <strval> INCREMENTO
%token <strval> DECREMENTO                    //++ y --
%token <strval> INCREMENTOASIGNACION
%token <strval> DECREMENTOASIGNACION   // += y -=
%token <strval> AND
%token <strval> OR                                      // && y ||
%token <strval> RELACIONALIGUAL 
%token <strval> RELACIONALDIFERENTE         // == y !=
%token <strval> MAYORIGUAL 
%token <strval> MENORIGUAL                       // >= y <=
%token <strval> ACCESOPUNTERO                               // -> 
%token <enteroval> CONSTANTEDECIMAL
%token <enteroval> CONSTANTEOCTAL 
%token <enteroval> CONSTANTEHEXADECIMAL 
%token <dobleval> CONSTANTEREAL 
%token <strval> CONSTANTECARACTER
%token <strval> LITERALCADENA 
%token <strval> IF
%token <strval> ELSE
%token <strval> WHILE
%token <strval> DO
%token <strval> SWITCH
%token <strval> FOR 
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

%left '+' '-' '*' '/' '^' '%' ',' '<' '>' OR AND RELACIONALIGUAL RELACIONALDIFERENTE MAYORIGUAL MENORIGUAL
%right '=' ':' '&' '!' '(' ')' '[' ']' INCREMENTOASIGNACION DECREMENTOASIGNACION INCREMENTO DECREMENTO   

%%

input:    /* vacio */
        | input programa
;

programa:    
             sentencia '\n'
            | declaracion '\n'
;

// SENTENCIAS 

sentencia: 
    sent_expresion {if (flag_SentExpresion == 0) printf("Se declaro una sentencia simple\n"); flag_SentExpresion = 1;}
   | sent_compuesta {if (flag_SentCompuesta == 0) printf("Se declaro una sentencia compuesta\n"); flag_SentCompuesta = 1;}
   | sent_seleccion {if (flag_Seleccion == 0) printf("Se declaro una sentencia de seleccion\n"); flag_Seleccion = 1;}
   | sent_iteracion {if (flag_Iteracion == 0) printf("Se declaro una sentencia de iteración \n"); flag_Iteracion = 1;}
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

listaSentenciasOpcional:  /* vacio */
                        | sentencia
                        | listaSentencias sentencia
;

listaSentencias: sentencia
                | listaSentencias sentencia
     
;

sent_seleccion: 
    IF '(' expresion ')' sentencia  
    | IF '(' expresion ')' sentencia ELSE sentencia  
    | SWITCH '(' expresion ')' sentencia 
    // en vez de sentencia SWITCH la cambiamos por sentencia para acortar
    | error ';'
;

sent_iteracion: 
    WHILE '(' expresion ')' sentencia  {if (flag_Iteracion == 0) printf("Se declaro correctamente una sentencia \"while\" \n"); flag_Iteracion = 1;}
    | DO sentencia WHILE '(' expresion ')' ';'  {if (flag_Iteracion == 0) printf("Se declaro correctamente una sentencia \"do while\"\n"); flag_Iteracion = 1;}
    | FOR '(' expresionOpcional ';' expresionOpcional ';' expresionOpcional ')' sentencia  {if (flag_Iteracion == 0) printf("Se declaro correctamente una sentencia \"for\" \n"); flag_Iteracion = 1;}
 // | error ';'
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
                        | listaArgumentosOpcional ',' exp_asignacion
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

declaracionVariablesSimples: TIPO_DATO listaVariablesSimples ';' {printf(" de tipo %s.", $<strval>1);}
;

listaVariablesSimples: variableSimple        {printf("\nSe declara la variable %s", $<strval>1);}
                     | listaVariablesSimples ',' variableSimple {printf(", y la variable %s", $<strval>3);}
;

variableSimple: IDENTIFICADOR opcionInicializacion {strcpy($<strval>$, $<strval>1);}
;

opcionInicializacion:   /* vacio */
                     | op_asignacion exp_condicional // ojo con constante revisar
;

constante: CONSTANTEDECIMAL
        | CONSTANTEHEXADECIMAL
        | CONSTANTEOCTAL
        | CONSTANTEREAL
        | CONSTANTECARACTER
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

int main(void){

    int flag_parse;
  /*  
     #ifdef BISON_DEBUG
        yydebug = 1;
    #endif   
*/
    yyin = fopen ("docDePrueba.c","r");
    
    flag_parse = yyparse();
    puts("Sali del parse");

    fclose(yyin);

    return flag_parse;

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