%option noyywrap
%option yylineno

%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ListasYFuncionesTP4.h" //Esto no va más
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
//  {ESTRUCTURA_CONTROL}  {palabrasReservadas(} //ESTO NO SIRVE MAS
{OTROS}      {palabrasReservadas(}
({LETRA}|_)({LETRA}|{DIGITO_DECIMAL}|_)* {}
\"[^\"]*\" {}
{PUNTUACION_OPERACION} {}
. {}

// CONSTANTES
[1-9]{DIGITO_DECIMAL}* {return CONSTANTEDECIMAL;}
0{DIGITO_OCTAL}* {return CONSTANTEOCTAL}
0[xX]{DIGITO_HEXADECIMAL}+ {return CONSTANTEHEXADECIMAL}
{DIGITO_DECIMAL}+(\.)({EXPONENCIAL}{SIGNO}?{DIGITO_DECIMAL}+)? {return CONSTANTEREAL}
{DIGITO_DECIMAL}*(\.){DIGITO_DECIMAL}+({EXPONENCIAL}({SIGNO}?){DIGITO_DECIMAL}+)? {return CONSTANTEREAL}
\'[^']\' {return CONSTANTECARACTER}

// PALABRAS RESERVADAS 
if         { return IF; }
while      { return WHILE; }
for        { return FOR; }
else       { return ELSE; }
do         { return DO; }
switch     { return SWITCH; }
case       { return CASE; }
default    { return DEFAULT; }
break      { return BREAK; }
char       { return CHAR; }
int        { return INT; }
double     { return DOUBLE; }
float      { return FLOAT; }
long       { return LONG; }
short      { return SHORT; }

// CARACTERES SIMPLES
"("        { return '('; }
")"        { return ')'; }
"{"        { return '{'; }
"}"        { return '}'; }
";"        { return ';'; }
":"        { return ':'; }
","        { return ','; }
"="        { return '='; }
"<"        { return '<'; }
">"        { return '>'; }
"+"        { return '+'; }
"-"        { return '-'; }
"*"        { return '*'; }
"/"        { return '/'; }
"%"        { return '%'; }

// OPERADORES MULTIPLES
"++"       { return INCREMENTO; }
"--"       { return DECREMENTO; }
"+="       { return INCREMENTOASIGNACION; }
"-="       { return DECREMENTOASIGNACION; }
"=="       { return RELACIONALIGUAL; }
"!="       { return RELACIONALDIFERENTE; }
">="       { return MAYORIGUAL; }
"<="       { return MENORIGUAL; }
"&&"       { return AND; }
"||"       { return OR; }

%%

int main(){
    yyin = fopen("docDePrueba.c","r");
    yylex();

    return 0;
}
