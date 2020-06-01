
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
    char[3] cadenaPush;
};

// 4 = q0, q1, q2, qr ; 2 = $, R ; 6 columnas + columna R
struct EST TT[4][2][6]

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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Nodo{
    int dato;
    struct Nodo* sig;
}Nodo;

void push(Nodo *,char);
void pop(Nodo *);
int cimaPila (Nodo *primero);

int main(){
    
    typedef struct estmatriz {
    int estado_sig;
    char cad_push [3];
    }
    struct estmatriz est_matriz [4][2][6] = {
        {3,""},{1,"$"},{3,""},{0,"R$"},{3,""},{1,"$"},
        {1,"$"},{0,"$"},{3,""},{3,""},{3,""},{1,"R"},
        {3,""},{0,"RR"},{3,""},{1,"R"},{1,"R"},{0,"R"},
        {3,""},{2,"E"},{3,""},{3,""},{0,"R"},{3,""},
        {2,"E"},{3,""},{3,""},{0,"$"},{3,""},{3,""}
    }

     char caracter;
     int estado_actual = 0;
     int i=0;
     int abre=0;
     int cierra=0;
     
     Nodo* primero = NULL;
     char caracter1 = '$';
     push (primero,caracter1);
     
     
     char operacion [128];

     printf("Ingrese la operacion: ");
     scanf("%s" , operacion);
     caracter=operacion[i];
     
    
    while (caracter != '\0'){

         a = est_matriz [estado_actual] [cimaPila(primero)] [determinar_columna(caracter)] ;
          
        if (caracter == '('){
                abre++;
               pop(primero);
              pushvec(primero,a.cad_push[1]);
              pushvec(primero,a.cad_push[0]);
            }
            
         if (caracter == ')'){
                cierra++;
                pop(primero);
            }
            
        estado_actual = a.estado_sig;
        i++;
        caracter =operacion[i];
    }
    
    
    if ((abre-cierra) == 0){
    printf("La Operacion Ingresada Es Correcta.");
    }else {
        printf("Syntax Error.");
    }

    
    return 0;
}


int cimaPila (Nodo *primero)
{
    
    if (primero!=NULL){
                
                int z; 
             if (primero-> dato == '$'){
                   z = 0 ;
            }
            
             if (primero-> dato == 'R'){
                 z = 1 ;
            }
               
        return z;
  }

}

void push(Nodo *primero,char n) 
{
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo)); 
    nuevoNodo->dato = n ;                             
    nuevoNodo->sig  = primero;
    primero = nuevoNodo;
}


void pop(Nodo *primero) 
{
   if(primero != NULL){
   Nodo* aux = primero;
   primero = aux->sig;                                   
   free(aux);               
}
}


int determinar_columna(char a)
{
    int col = 0;
    switch(a)

    {

      case '0': col=0; break;
      case '1'...'9': col=1; break;
      case '+': case '-': case '*': case '/':  col=2; break;
      case '(': col=3; break;
      case ')': col=4; break;
      default: col=5;

    }
    return col;
}
