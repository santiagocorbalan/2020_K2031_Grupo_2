#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct nodo {
  char dato;
  struct nodo *siguiente;
};


void push(char caracter);  
char pop(void); 
int ultimo(void); 
bool vacia(void);  
struct nodo *superior = NULL;

int determinar_columna(char a);


int main()

{
    

    struct loc { 
        int estado; 
        char cad_push[3]; 
        };  
    
    struct loc TT[5][5][6];
    TT [0] [0] [0].estado = 3;
    strcpy(TT[0][0][0].cad_push, "");
    TT [0] [0] [1].estado = 1; 
    strcpy(TT[0][0][1].cad_push, "$");
    TT [0] [0] [2].estado = 3; 
    strcpy(TT[0][0][2].cad_push, "");
    TT [0] [0] [3].estado = 0; 
    strcpy(TT[0][0][3].cad_push, "R$");
    TT [0] [0] [4].estado = 3; 
    strcpy(TT[0][0][4].cad_push, "");
    TT [1] [0] [0].estado = 1; 
    strcpy(TT[1][0][0].cad_push, "$");
    TT [1] [0] [1].estado = 1; 
    strcpy(TT[1][0][1].cad_push, "$");
    TT [1] [0] [2].estado = 0; 
    strcpy(TT[1][0][2].cad_push, "$");
    TT [1] [0] [3].estado = 3; 
    strcpy(TT[1][0][3].cad_push, "");
    TT [1] [0] [4].estado = 3;     
    strcpy(TT[1][0][4].cad_push, "");
    TT [0] [1] [0].estado = 3; 
    strcpy(TT[0][1][0].cad_push, "");
    TT [0] [1] [1].estado = 1; 
    strcpy(TT[0][1][1].cad_push, "R");
    TT [0] [1] [2].estado = 3; 
    strcpy(TT[0][1][2].cad_push, "");
    TT [0] [1] [3].estado = 0; 
    strcpy(TT[0][1][3].cad_push, "RR");
    TT [0] [1] [4].estado = 3; 
    strcpy(TT[0][1][4].cad_push, "");
    TT [1] [1] [0].estado = 1; 
    strcpy(TT[1][1][0].cad_push, "R");
    TT [1] [1] [1].estado = 1; 
    strcpy(TT[1][1][1].cad_push, "R");
    TT [1] [1] [2].estado = 0; 
    strcpy(TT[1][1][2].cad_push, "R");
    TT [1] [1] [3].estado = 3; 
    strcpy(TT[1][1][3].cad_push, "");
    TT [1] [1] [4].estado = 2; 
    strcpy(TT[1][1][4].cad_push, "E");
    TT [2] [1] [0].estado = 3; 
    strcpy(TT[2][1][0].cad_push, "");
    TT [2] [1] [1].estado = 3; 
    strcpy(TT[2][1][1].cad_push, "");
    TT [2] [1] [2].estado = 0; 
    strcpy(TT[2][1][2].cad_push, "R");
    TT [2] [1] [3].estado = 3; 
    strcpy(TT[2][1][3].cad_push, "");
    TT [2] [1] [4].estado = 2; 
    strcpy(TT[2][1][4].cad_push, "E");
    TT [2] [0] [0].estado = 3; 
    strcpy(TT[2][0][0].cad_push, "");
    TT [2] [0] [1].estado = 3; 
    strcpy(TT[2][0][1].cad_push, "");
    TT [2] [0] [2].estado = 0; 
    strcpy(TT[2][0][2].cad_push, "$");
    TT [2] [0] [3].estado = 3; 
    strcpy(TT[2][0][3].cad_push, "");
    TT [2] [0] [4].estado = 3; 
    strcpy(TT[2][0][4].cad_push, "");
    
    int estado_actual = 0;
    int b = 0 ;
    int i=0;
    char operr[3];
    
    char caracter1 = '$';
    push(caracter1);
    
    
    char operacion [128];


    printf("Ingrese la operacion: ");
    scanf("%s" , operacion);
    char caracter = operacion[i];
    
     while (caracter != '\0'){
        
           b = TT[estado_actual] [ultimo()] [determinar_columna(caracter)].estado ;
           strcpy(operr,TT[estado_actual] [ultimo()] [determinar_columna(caracter)].cad_push);

          if (b == 3){
              
             printf("Syntax Error.\n");
              
             return 0;
            }

          if (caracter == '('){
             char val = pop();
             push(val);
             push(operr[0]);
            }
            
         if (caracter == ')'){
                pop();
            }
            
        
        estado_actual = b;
        i++;
        caracter =operacion[i];
    }

       pop();
               
        if (vacia()) {
            
            if (estado_actual != 0 ) {
        printf("La Operacion Ingresada Es Correcta.\n");
            }
            else {
        printf("Syntax Error.\n");
      }
      } else {
        printf("Syntax Error.\n");
      }
                    


    return 0;
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

    }
    return col;
}

char pop(void) {
    
    if (superior != NULL) {

        struct nodo *temporal = superior;
        char valor = superior->dato;
        superior = superior->siguiente;
 
        free(temporal);
        return valor;
    }
}


void push(char caracter) {

  struct nodo *nuevoNodo = malloc(sizeof(struct nodo));
  nuevoNodo->dato = caracter;
  nuevoNodo->siguiente = superior;
  superior = nuevoNodo;
}



int ultimo() {
              
         if (superior-> dato == '$'){
                   return 0 ;
            }
            
             if (superior-> dato == 'R'){
                 return 1 ;
            }

          }

bool vacia(void) { return superior == NULL; }