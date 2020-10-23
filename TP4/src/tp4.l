%option noyywrap
%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tp4.tab.h" 
%}


%%

"\n" {return '\n';}

" "|"\t"

"("|")"|"["|"]"|","|"?"|":"|";"|"{"|"}"|"&" {return yytext[0];}

if         { return IF;}
switch     { return SWITCH;}
else       { return ELSE;}
while      { return WHILE;}
for        { return FOR;}
do         { return DO;}
return     { return RETURN;}

"++"       { return INCREMENTO; }
"--"       { return DECREMENTO; }
"*"        { return '*'; }
"/"        { return '/'; }
"%"        { return '%'; }
"+"        { return '+'; }
"-"        { return '-'; }
"&&"       { return AND; }
"||"       { return OR; }

"char"|"int"|"float"|"double"|"long"|"short"|"signed"|"unsigned"|"void" {yylval.strval = strdup(yytext); return TIPO_DATO;}

">"        { return '>'; }
"<"        { return '<'; }
">="       { return MAYORIGUAL; }
"<="       { return MENORIGUAL; }
"=="       { return RELACIONALIGUAL; }
"!="       { return RELACIONALDIFERENTE; }
"="        { return '='; }
"+="       { return INCREMENTOASIGNACION; }
"-="       { return DECREMENTOASIGNACION; }
"->"       { return ACCESOPUNTERO; }

[a-zA-Z_][a-zA-Z0-9_]* { yylval.strval = strdup(yytext); return IDENTIFICADOR; }

\"[^\"]*\" {yylval.strval = strdup(yytext); return LITERALCADENA;}

[1-9][0-9]* {yylval.enteroval = atoi(yytext);return CONSTANTEDECIMAL;}

0[0-7]* {yylval.enteroval = strtol(yytext,NULL,0);return CONSTANTEOCTAL;}

0[xX][0-9a-fA-F]+ {yylval.enteroval = strtol(yytext,NULL,0);return CONSTANTEHEXADECIMAL;}

[0-9]+(\.)([eE][\+\-]?[0-9]+)? {yylval.dobleval = atof(yytext);return CONSTANTEREAL;}

\'[^']\'   {yylval.strval = strdup(yytext);return CONSTANTECARACTER;}

. {printf("\nCaracter no reconocido: %c", yytext[0]);}

%%
