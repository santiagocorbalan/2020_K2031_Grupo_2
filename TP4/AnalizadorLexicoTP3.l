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



"//".*$ {comentarios(yytext,"Comentario de una linea");}

"/*"[^"*/"]*"*/" {comentarios(yytext,"Comentario de multiples lineas");}

{TIPO_DATO} {palabrasReservadas(yytext,"Tipo de dato");}

{ESTRUCTURA_CONTROL}  {palabrasReservadas(yytext,"Estructura de control");}

{OTROS}      {palabrasReservadas(yytext,"Tipo de dato");}

({LETRA}|_)({LETRA}|{DIGITO_DECIMAL}|_)* {identificadores(yytext);}

\"[^\"]*\" {}

[1-9]{DIGITO_DECIMAL}* {constantesDecimales(yytext);} //defino la regla y hago que muestre que constante encontró yytext y de que longitud es yyleng.

0{DIGITO_OCTAL}* {constantesOctales(yytext);}

0[xX]{DIGITO_HEXADECIMAL}+ {constantesHexadecimales(yytext);}

{DIGITO_DECIMAL}+(\.)({EXPONENCIAL}{SIGNO}?{DIGITO_DECIMAL}+)? {constantesReales(yytext);}

{DIGITO_DECIMAL}*(\.){DIGITO_DECIMAL}+({EXPONENCIAL}({SIGNO}?){DIGITO_DECIMAL}+)? {constantesReales(yytext);}

\'[^']\' {constantesCaracter(yytext);}

{PUNTUACION_OPERACION} {operadoresCaracteresPuntc(yytext);}

. {printf(caracNoReconocidos(yytext,yylineno);}


%%


int main(){

    yyin = fopen("docDePrueba.c","r");

     yylex();
    
    reportes();

    return 0;

}
