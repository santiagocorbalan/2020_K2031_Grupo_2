%option noyywrap

%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tp4.tab.h" 

%}

DIGITO_DECIMAL          [0-9] 
DIGITO_OCTAL            [0-7]
DIGITO_HEXADECIMAL      [0-9A-Fa-f]
LETRA                   [a-zA-Z]
TIPO_DATO               char|int|float|double|long|short|signed|unsigned|void
SIGNO                   [\+\-]
EXPONENCIAL             [eE]

%%

"\n" {return '\n';}

" "|"\t"

"("        { return '('; }
")"        { return ')'; }
"["        { return '['; }
"]"        { return '['; }
","        { return ','; }
"?"        { return '?';}
":"        { return ':'; }
";"        { return ';'; }
"{"        { return '{'; }
"}"        { return '}'; }
"&"        { return '&'; }

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

TIPO_DATO {yylval.strval = strdup(yytext); return TIPO_DATO;}

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

({LETRA}|_)({LETRA}|{DIGITO_DECIMAL}|_)* { yylval.strval = strdup(yytext); return IDENTIFICADOR; }

\"[^\"]*\" {yylval.strval = strdup(yytext); return LITERALCADENA;}

[1-9]{DIGITO_DECIMAL}* {yylval.enteroval = atoi(yytext);return CONSTANTEDECIMAL;}

0{DIGITO_OCTAL}* {yylval.enteroval = strtol(yytext,NULL,0);return CONSTANTEOCTAL;}

0[xX]{DIGITO_HEXADECIMAL}+ {yylval.enteroval = strtol(yytext,NULL,0);return CONSTANTEHEXADECIMAL;}

{DIGITO_DECIMAL}*"."{DIGITO_DECIMAL}*(EXPONENCIAL(SIGNO)?{DIGITO_DECIMAL}+)? {yylval.dobleval = atof(yytext);return CONSTANTEREAL;}

\'[^']\'   {yylval.strval = strdup(yytext);return CONSTANTECARACTER;}

. {printf("\nCaracter no reconocido: %c", yytext[0]);}

%%
