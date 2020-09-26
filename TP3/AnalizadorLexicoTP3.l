%option noyywrap

%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ListasYFuncionesTP3.h"
//Listado de identificadores encontrados indicando la cantidad de veces que aparece cada uno de ellos.
// El listado debe estar ordenado alfabéticamente.  printf("Encontre un identificador: %s de longitud %d \n", yytext, yyleng);


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



"//".*$ {printf("Encontré un comentario: %s de longitud %d \n", yytext, yyleng);}

"/*"[^"*/"]*"*/" {printf("Encontré un comentario de multiples lineas: %s de longitud %d \n", yytext, yyleng);}

{TIPO_DATO} {printf("Encontré una palabra reservada (tipo de dato): %s de longitud %d\n",yytext, yyleng);}

{ESTRUCTURA_CONTROL}  {printf("Encontré una palabra reservada (estructuras de control): %s de longitud %d\n",yytext, yyleng);}

{OTROS} {printf("Encontré una palabra reservada (otros): %s de longitud %d\n",yytext, yyleng);}

({LETRA}|_)({LETRA}|{DIGITO_DECIMAL}|_)* {printf("Encontré un identificador: %s de longitud %d \n", yytext, yyleng);listaIdentificadores(yytext);}

\"[^\"]*\" {printf("Encontré un literal cadena: %s de longitud %d \n", yytext, yyleng);}

[1-9]{DIGITO_DECIMAL}* {printf("Encontré la constante entera decimal: %s de longitud %d \n",yytext,yyleng);constantesDecimales(yytext);} //defino la regla y hago que muestre que constante encontró yytext y de que longitud es yyleng.

0{DIGITO_OCTAL}* {printf("Encontré una constante entera octal: %s de longitud %d \n", yytext, yyleng);constantesOctales(yytext);}

0[xX]{DIGITO_HEXADECIMAL}+ {printf("Encontré una constante entera hexadecimal: %s de longitud %d \n", yytext, yyleng);constantesHexadecimales(yytext);}

{DIGITO_DECIMAL}+(\.)({EXPONENCIAL}{SIGNO}?{DIGITO_DECIMAL}+)? {printf("Encontré una constante real: %s de longitud %d \n", yytext, yyleng);constantesReales(yytext);}

{DIGITO_DECIMAL}*(\.){DIGITO_DECIMAL}+({EXPONENCIAL}({SIGNO}?){DIGITO_DECIMAL}+)? {printf("Encontré una constante real: %s de longitud %d \n", yytext, yyleng);constantesReales(yytext);}

\'[^']\' {printf("Encontré una constante caracter %s de longitud %d \n", yytext, yyleng); constantesCaracter(yytext);}

{PUNTUACION_OPERACION} {printf("Encontré un caracter de puntuación/operador: %s de longitud %d \n",yytext,yyleng);operadoresCaracteresPuntc(yytext);}

. {printf("Encontré una cadena no reconocida: %s de longitud %d \n",yytext,yyleng);}


%%


int main(){

    fopen("docDePrueba.c","r");

    yylex();
    
    reportes();

    return 0;

}
