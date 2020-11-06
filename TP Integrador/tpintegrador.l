%{
    #include "tpintegrador.tab.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
%}

option noyywrap


%%

"\n" {return '\n';}

" "|"\t"

"("|")"|"["|"]"|","|"?"|":"|";"|"{"|"}"|"&" {return yytext[0];}

"if" {return IF;}

"switch" {return SWITCH;}

"else" {return ELSE;}

"sizeof" {return OPER_SIZEOF;}

"while" {return WHILE;}

"for" {return FOR;}

"do" {return DO;}

"return" {return RETURN;}

"++"|"--" {return OPER_INCREMENTO;}

"*"|"/"|"%" {return OPER_MULTIPLICATIVO;}

"+"|"-" {return OPER_ADITIVO;}

"&&" {return AND;}

"||" {return OR;}

"int"|"double"|"float"|"char"|"void" {strcpy(yylval.cadena, yytext); return TIPO_DATO;}

">"|"<"|"<="|">=" {strcpy(yylval.cadena, yytext); return OPER_RELACIONAL;}

"=="|"!=" {return OPER_IGUALDAD;}

"="|"+="|"-=" {return OPER_ASIGNACION;}

[a-zA-Z_][a-zA-Z0-9_]* {strcpy(yylval.cadena, yytext); return IDENTIFICADOR;}

\"[^\"]*\" {strcpy(yylval.cadena, yytext); return LITERAL_CADENA;}

[1-9][0-9]* {yylval.entero = atoi(yytext); return CONSTANTE_DECIMAL;}

0[0-7]* {yylval.entero = atoi(yytext); return CONSTANTE_OCTAL;}

0[xX][0-9a-fA-F]+ {yylval.entero = atoi(yytext); return CONSTANTE_HEXADECIMAL;}

[0-9]+(\.)([eE][\+\-]?[0-9]+)? {yylval.real = strtol(yytext, NULL, 0); return CONSTANTE_REAL;}

[0-9]*(\.)[0-9]+([eE]([\+\-]?)[0-9]+)? {yylval.real = strtol(yytext, NULL, 0); return CONSTANTE_REAL;}

\'[^']*\' {yylval.entero = yytext[1]; return CONSTANTE_CARACTER;}

. {printf("\nCaracter no reconocido: %c", yytext[0]);}

%%