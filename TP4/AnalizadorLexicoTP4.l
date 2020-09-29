%option noyywrap
%option yylineno

%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ListasYFuncionesTP3.h"
%}

DIGITO_DECIMAL          [0-9] 
DIGITO_OCTAL            [0-7]
DIGITO_HEXADECIMAL      [0-9A-Fa-f]
LETRA                   [a-zA-Z]
TIPO_DATO               char|int|float|double|long|short|signed|unsigned|void|enum|struct|typedef|union|const
ESTRUCTURA_CONTROL      switch|case|break|default|continue|do|while|if|else|for|return|goto
OTROS                   volatile|extern|static|auto|register|sizeof
SIGNO                   [\+\-]
EXPONENCIAL             [eE]
PUNTUACION_OPERACION    "*"|")"|"-"|"%"|";"|"?"|"]"|"&"|"#"|"."|"<"|","|"^"|"'"|"+"|"/"|"="|"["|"("|"@"|":"|">"|">="|"<="|"=="|"&&"|"||"|"++"|"--"|"!="|"<<"|"<<="|">>"|">>="|"~"|"&="|"|="|"^="|"->"|"->*"|".*"|"{"|"}"|"$"|"\t"

%%
"//".*$ {}
"/*"[^"*/"]*"*/" {}
{TIPO_DATO} {}
{ESTRUCTURA_CONTROL}  {palabrasReservadas(}
{OTROS}      {palabrasReservadas(}
({LETRA}|_)({LETRA}|{DIGITO_DECIMAL}|_)* {}
\"[^\"]*\" {}
[1-9]{DIGITO_DECIMAL}* {}
0{DIGITO_OCTAL}* {}
0[xX]{DIGITO_HEXADECIMAL}+ {}
{DIGITO_DECIMAL}+(\.)({EXPONENCIAL}{SIGNO}?{DIGITO_DECIMAL}+)? {}
{DIGITO_DECIMAL}*(\.){DIGITO_DECIMAL}+({EXPONENCIAL}({SIGNO}?){DIGITO_DECIMAL}+)? {}
\'[^']\' {}
{PUNTUACION_OPERACION} {}
. {}
%%

int main(){
    yyin = fopen("docDePrueba.c","r");
    yylex();

    return 0;
}
