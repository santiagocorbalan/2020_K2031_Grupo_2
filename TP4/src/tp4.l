%option noyywrap

%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tp4.tab.h" //Archivo que va a generar Bison
extern FILE* yyin;
%}

DIGITO_DECIMAL          [0-9] 
DIGITO_OCTAL            [0-7]
DIGITO_HEXADECIMAL      [0-9A-Fa-f]
LETRA                   [a-zA-Z]
TIPO_DATO               char|int|float|double|long|short|signed|unsigned|void
SIGNO                   [\+\-]
EXPONENCIAL             [eE]
PUNTUACION_OPERACION    "*"|")"|"-"|"%"|";"|"?"|"]"|"&"|"#"|"."|"<"|","|"^"|"'"|"+"|"/"|"="|"["|"("|"@"|":"|">"|">="|"<="|"=="|"&&"|"||"|"++"|"--"|"!="|"<<"|"<<="|">>"|">>="|"~"|"&="|"|="|"^="|"->"|"->*"|".*"|"{"|"}"|"$"|"\t"

%%

"\n" {return '\n';}

" "|"\t" {}

[1-9]{DIGITO_DECIMAL}* {yylval.enteroval = atoi(yytext);return CONSTANTEDECIMAL;}

0{DIGITO_OCTAL}* {yylval.enteroval = strtol(yytext,NULL,0);return CONSTANTEOCTAL;}

0[xX]{DIGITO_HEXADECIMAL}+ {yylval.enteroval = strtol(yytext,NULL,0);return CONSTANTEHEXADECIMAL;}

{DIGITO_DECIMAL}*"."{DIGITO_DECIMAL}*(EXPONENCIAL(SIGNO)?{DIGITO_DECIMAL}+)? {yylval.dobleval = atof(yytext);return CONSTANTEREAL;}

\'[^']\'   {yylval.strval = strdup(yytext);return CONSTANTECARACTER;}

\"[^\"]*\" {yylval.strval = strdup(yytext); return LITERALCADENA;}

TIPO_DATO {yylval.strval = strdup(yytext); return TIPO_DATO;}

({LETRA}|_)({LETRA}|{DIGITO_DECIMAL}|_)* { yylval.strval = strdup(yytext); return IDENTIFICADOR; }
 
if         { return IF;}
while      { return WHILE;}
for        { return FOR;}
else       { return ELSE;}
do         { return DO;}
switch     { return SWITCH;}
return     { return RETURN;}
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
"->"       { return ACCESOPUNTERO; }
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
")"        { return ')'; }
"{"        { return '{'; }
"("        { return '('; }
"}"        { return '}'; }


%%
