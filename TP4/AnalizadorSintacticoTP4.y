%{
    #include <stdio.h>

int yylex();
int yywrap(){
    return (1);
}

}

%)

%union {
    int ival;
    char* strval;
}

%token <strval> OP_INC //++
%token <strval> OP_INC_ASIG //+=
%token <strval> OP_DEC_ASIG //-=
%token <strval> OP_AND //&&
%token <strval> OP_OR //||
%token <strval> OP_REL_IG //==
%token <strval> OP_REL_DIF //!=
%token <strval> OP_MEN_IGUAL //<=
%token <strval> OP_MAY_IGUAL //>=

expresion: 
    exp_asignacion 
    | expresion , exp_asignacion
;
exp_asignacion:
    exp_condicional
    | exp_unaria op_asignacion exp_asignacion
;
exp_condicional:
    exp_o_logico
    | exp_o_logico ? expresion : exp_condicional
;
operador_asignacion:
    = //Esto no creo que esté bien expresado solo..
    | OP_INC_ASIG
    | OP_DEC_ASIG
//Los demás no los agrego porque no son tan importantes.
;
exp_o_logico:
    exp_y_logico
    | exp_o_logico OP_OR exp_y_logico
;
exp_y_logico:
    exp_o_inclusivo
    | exp_y_logico OP_AND exp_o_inclusivo
;
//Acá faltan algunos lógicos

exp_y:
    exp_igualdad
    | exp_y & exp_igualdad
;
exp_igualdad:
    exp_relacional
    | exp_igualdad OP_REL_IG exp_relacional
    | exp_igualdad OP_REL_DIF exp_relacional
;
exp_relacional:
    exp_corrimiento
    | exp_relacional < exp_corrimiento
    | exp_relacional > exp_corrimiento
    | exp_relacional OP_MEN_IGUAL exp_corrimiento
    | exp_relacional OP_MAY_IGUAL exp_corrimiento
;

