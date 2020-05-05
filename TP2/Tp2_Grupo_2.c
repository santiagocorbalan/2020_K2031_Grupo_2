
#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    Char info;
    Nodo* sig;
};

int tipos (char a);
char pop (Nodo*&);
void push (Nodo*&, char);

int main(){

	    int matriz[6][5]={
					  {3,1,3,0,3},
                      {1,1,0,3,3},
                      {3,1,3,1,3},
                      {1,1,0,3,2},
                      {3,3,0,3,2},
                      {3,3,0,3,3}
					  };

    int columna = 0;
    int estadoActual = 0;
    int estadoFinal = 0;
    char cimaDeLaPila
    
    char str[50];
    printf("Ingrese una expresión: ");
    gets(str);
    
    //Acá habría que empezar a recorrer el string e ir iterando por los diferentes estados


	return 0;
}


int tipos (char a)
{
    int col = 0;
    switch(a)

    {
      case '0': col=0; break;

      case '1'...'9': col=1; break;

      case '+','-','*','/': col=2; break;

      case '(': col=3; break;

      default: col=4;

    }
    return col;
}

string pop(Nodo* &p) {
    char c;
    Nodo* aux = p;
    c = aux->info;
    p = aux->sig;
    delete aux;
    return c;
}

void push(Nodo* &p, char c){
    Nodo* aux = new Nodo();
    aux->info = c;
    aux->sig = p;
    p = aux;
}
