%option noyywrap
%option yylineno

%{

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "TP5.tab.h"   

%}

DIGITO_DECIMAL      [0-9] 
LETRA               [a-zA-Z] 

TIPO_DE_DATO        (char|int|float)
CONSTANTE_CARACTER  \'.\'
LITERAL_CADENA      \".+\"
CONSTANTE_DECIMAL   [1-9]{DIGITO_DECIMAL}*
CONSTANTE_OCTAL     0[0-7]*
CONSTANTE_HEXA      0[xX][a-fA-F0-9]+
CONSTANTE_REAL      {DIGITO_DECIMAL}+\.{DIGITO_DECIMAL}+

%%  

" "|"\t"
"\n"        { return '\n';}
   
"void"      {return TKN_VOID; }

"continue"  { return CONTINUE; }
"break"     { return BREAK;    }
"return"    { return RETURN;   }
"while"     { return WHILE;    }
"do"        { return DO;       }
"for"       { return FOR;      }
"if"        { return IF;       }
"else"      { return ELSE;     }
"switch"    { return SWITCH;   }

";"         { return ';'; }
","         { return ','; }
"("         { return '('; }
")"         { return ')'; }
"{"         { return '{'; }
"}"         { return '}'; }
":"         { return ':'; }

"["         { return '['; }
"]"         { return ']'; }
"."         { return '.'; }
"~"         { return '~'; }
"!"         { return '!'; }
"-"         { return '-'; }
"+"         { return '+'; }
"&"         { return '&'; }
"*"         { return '*'; }
"/"         { return '/'; }   
"<"         { return '<'; }
">"         { return '>'; }
"="         { return '='; }         
"^"         { return '^'; }
"|"         { return '|'; }

{TIPO_DE_DATO}                            { yylval.cadena = strdup(yytext); return TIPO_DE_DATO;    }
({LETRA}|_)({LETRA}|{DIGITO_DECIMAL}|_)*  { yylval.cadena = strdup(yytext); return IDENTIFICADOR;   } 
{CONSTANTE_CARACTER}                      { yylval.caracter = yytext[1]; return CONSTANTE_CARACTER; }
{LITERAL_CADENA}                          { yylval.cadena = strdup(yytext); return LITERAL_CADENA;  }

{CONSTANTE_HEXA}      { yylval.mystruct.valor_entero=strtoll(yytext, NULL, 16); yylval.mystruct.tipo=1; return CONSTANTE_ENTERA; }
{CONSTANTE_OCTAL}     { yylval.mystruct.valor_entero=strtoll(yytext, NULL, 8); yylval.mystruct.tipo=1; return CONSTANTE_ENTERA;  }
{CONSTANTE_DECIMAL}	  { yylval.mystruct.valor_entero=atoi(yytext); yylval.mystruct.tipo=1; return CONSTANTE_ENTERA;              }
{CONSTANTE_REAL}      { yylval.mystruct.valor_real=atof(yytext); yylval.mystruct.tipo=2; return CONSTANTE_REAL;                  }

.                     { printf("\nEl caracter %c no fue reconocido.", yytext[0]); }

%%