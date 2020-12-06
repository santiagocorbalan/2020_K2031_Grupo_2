%option noyywrap

%{
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "TP5.tab.h"
%}

%%
"\n"    {return '\n';}

" "|"\t"

"("|")"|"["|"]"|","|"?"|":"|";"|"{"|"}"|"&"|"*"|"=" {return yytext[0];}

"if" {return IF;}

"switch" {return SWITCH;}

"else" {return ELSE;}

"while" {return WHILE;}

"for" {return FOR;}

"do" {return DO;}

"break"  {return BREAK;}

"continue"  {return CONTINUE;}

"return" {return RETURN;}

"int"|"double"|"float"|"char"|"void" {printf("encontre un tipodedato \n");strcpy(yylval.cadena, yytext); return TIPO_DE_DATO;}

[a-zA-Z_][a-zA-Z0-9_]* {printf("Encontre un identificador /n"); strcpy(yylval.cadena, yytext); return IDENTIFICADOR;}

\"[^\"]*\" {strcpy(yylval.cadena, yytext); return LITERAL_CADENA;}

[1-9][0-9]* {printf("encontre un entero"); yylval.mystruct.valor_entero=atoi(yytext); yylval.mystruct.tipo=1;yylval.entero = atoi(yytext); return CONSTANTE_ENTERA;}

0[0-7]* {yylval.mystruct.valor_entero=atoi(yytext); yylval.mystruct.tipo=1; yylval.entero = atoi(yytext); return CONSTANTE_ENTERA;}

0[xX][0-9a-fA-F]+ {yylval.mystruct.valor_entero=atoi(yytext); yylval.mystruct.tipo=1; yylval.entero = atoi(yytext); return CONSTANTE_ENTERA;}

[0-9]+\.[0-9]+ {yylval.mystruct.valor_real=atof(yytext); yylval.mystruct.tipo=2; yylval.real = strtol(yytext, NULL, 0); return CONSTANTE_REAL;}

\'[^']*\' {yylval.mystruct.valor_caracter=atof(yytext); yylval.mystruct.tipo=3; yylval.caracter = yytext[1]; return CONSTANTE_CARACTER;}

. {printf("Caracter no reconocido: %c", yytext[0]);}

%%