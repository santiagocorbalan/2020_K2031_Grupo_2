
#include <stdio.h>
#include <stdlib.h>

//Pila
struct Nodo {
    char info;
    nodo* sig;
};

//Lo que va a devolver la TT
struct EST {
    int estadoSiguiente;
    char [3] cadenaPush;
};

// 4 = q0, q1, q2, qr ; 2 = $, R ; 6 columnas + columna R
struct EST TT[4][2][6];

int tipos (char a);
char pop (Nodo*&);
void push (Nodo*&, char);

int main(){

    int matriz[6][5]= {
                        {3,1,3,0,3},
                        {1,1,0,3,3},
                        {3,1,3,1,3},
                        {1,1,0,3,2},
                        {3,3,0,3,2},
                        {3,3,0,3,3}
                      };
    
    //Arreglo de 3 dimensiones: tabla de transición
    //int tablaTransicion = [][][];

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
