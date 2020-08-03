%option noyywrap

%{

#include <stdio.h>
#include <stdlib.h>
//Listado de identificadores encontrados indicando la cantidad de veces que aparece cada uno de ellos.
// El listado debe estar ordenado alfabéticamente.

struct ListaIdentificador{
   string palabra;
   ListaIdentificador *siguiente;     
}

ListaIdentificadores *ListaIdentificadores = NULL;


void lista(ListaIdentificador *&lista, string data){
    ListaIdentificador *p,*anterior,*n = new ListaIdentificador;
    n->palabra=data; 
    p=lista; 
    while(p!=NULL && (strcmp(p->info,data)>0))
    {
        anterior=p;
        p=p->siguiente;
    }
    n->siguiente=p;
    if(p != lista)
        anterior->siguiente=n;
    else
        lista=n;

}


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


"//".*$ {printf("Encontre un comentario: %s de longitud %d \n", yytext, yyleng);}

"/*"[^"*/"]*"*/" {printf("Encontre un comentario de multiples lineas: %s de longitud %d \n", yytext, yyleng);}

{TIPO_DATO} {printf("Encontre una palabra reservada (tipo de dato): %s de longitud %d\n",yytext, yyleng);}

{ESTRUCTURA_CONTROL}  {printf("Encontre una palabra reservada (estructuras de control): %s de longitud %d\n",yytext, yyleng);}

{OTROS} {printf("Encontre una palabra reservada (otros): %s de longitud %d\n",yytext, yyleng);}

({LETRA}|"_")({LETRA}|{DIGITO_DECIMAL}|"_")* {printf("Encontre un identificador: %s de longitud %d \n", yytext, yyleng);}

\"[^\"]*\" {printf("Encontre un literal cadena: %s de longitud %d \n", yytext, yyleng);}// probar

[1-9]{DIGITO_DECIMAL}* {printf("Encontre la constante entera decimal: %s de longitud %d \n",yytext,yyleng);} //defino la regla y hago que muestre que constante encontró yytext y de que longitud es yyleng.

0{DIGITO_OCTAL}* {printf("Encontre una constante entera octal: %s de longitud %d \n", yytext, yyleng);}

0[xX]{DIGITO_HEXADECIMAL}+ {printf("Encontre una constante entera hexadecimal: %s de longitud %d \n", yytext, yyleng);}

{DIGITO_DECIMAL}+(\.)({EXPONENCIAL}{SIGNO}?{DIGITO_DECIMAL}+)? {printf("Encontre una constante real: %s de longitud %d \n", yytext, yyleng);}

{DIGITO_DECIMAL}*(\.){DIGITO_DECIMAL}+({EXPONENCIAL}({SIGNO}?){DIGITO_DECIMAL}+)? {printf("Encontre una constante real: %s de longitud %d \n", yytext, yyleng);}

\'[^']\' {printf("Encontre una constante caracter %s de longitud %d \n", yytext, yyleng);}

{PUNTUACION_OPERACION} {printf("Encontre un caracter de puntuacion/operador: %s de longitud %d \n",yytext,yyleng);} // probar

. {printf("Encontre una cadena no reconocida: %s de longitud %d \n",yytext,yyleng);}


%%





int main(){
    
    yylex();
    return 0;
}