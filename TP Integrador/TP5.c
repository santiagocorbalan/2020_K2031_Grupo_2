#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TP5.h"

symrec *aux;
symrec *aux2;
Parametro *listaParametrosAux = NULL;

symrec *agregoSimbolo (char const *sym_name, char const *sym_tipo, int sym_type)
{
  symrec *ptr = (symrec *) malloc (sizeof (symrec));
  ptr->nombre = (char *) malloc (strlen (sym_name) + 1);
  strcpy (ptr->nombre,sym_name);
  ptr->tipo = (char *) malloc (strlen (sym_tipo) + 1);
  strcpy (ptr->tipo,sym_tipo);
  ptr->type = sym_type;
  ptr->next = (struct symrec *)sym_table;
  sym_table = ptr;
  return ptr;
}


symrec *buscoSimbolo (char const *sym_name)
{
    symrec *ptr;
    for (ptr = sym_table; ptr != (symrec *) 0; ptr = (symrec *)ptr->next)
        if (strcmp (ptr->nombre, sym_name) == 0 )
            return ptr;
        return 0;
}


void declararVariable1(char* nombre,char* tipo){
    aux = agregoSimbolo(nombre,tipo,1);

                                               if(strcmp("int", aux->tipo) == 0)  {
                                                    aux->value.valEnt = 0;
                                                }
                                                 if(strcmp("float", aux->tipo) == 0)  {
                                                    aux->value.valReal = 0.0;
                                                }
                                                 if(strcmp("char", aux->tipo) == 0)  {
                                                    aux->value.valChar = '\0';
                                                }
                                                 if(strcmp("char*", aux->tipo) == 0)  {
                                                    aux->value.valString = NULL;
                                                }
                                                
                                                
}



void agregoParametro(char* tipoArgumentooo){
    
    Parametro *nuevo_nodo = (Parametro *)malloc(sizeof(Parametro));
    nuevo_nodo->tipoParametro = (char *) malloc (strlen (tipoArgumentooo) + 1);
    strcpy (nuevo_nodo->tipoParametro,tipoArgumentooo);
    nuevo_nodo->sig = NULL;

    if(listaParametrosAux == NULL){
        listaParametrosAux  = nuevo_nodo;
    }
    else{
        Parametro *aux;
        aux = listaParametrosAux ;

        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo_nodo;
    }
  
}

void agregoArgumento(char* tipoArgumentooo){
    
    Parametro *nuevo_nodo = (Parametro *)malloc(sizeof(Parametro));
    nuevo_nodo->tipoParametro = (char *) malloc (strlen (tipoArgumentooo) + 1);
    strcpy (nuevo_nodo->tipoParametro,tipoArgumentooo);
    nuevo_nodo->sig = NULL;

    if(listaParametrosAux == NULL){
        listaParametrosAux  = nuevo_nodo;
    }
    else{
        Parametro *aux;
        aux = listaParametrosAux ;

        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo_nodo;
    }
  
}


int cantidadParametros(Parametro* listaAuxiliar);

int cantidadParametros(Parametro* listaAuxiliar) {
    Parametro* aux = listaAuxiliar;
    int cantidad = 0;
    while (aux != NULL) {
        cantidad++;
        aux = aux->sig;
    }
    return cantidad;
}

int compararParametros(Parametro* lista1, Parametro* lista2) {
    int retorna = 0;    
    if (cantidadParametros(lista1) != cantidadParametros(lista2)) {
        retorna = 1;
    }
    else {
        Parametro* aux1 = lista1;
        Parametro* aux2 = lista2;
        while (aux1 != NULL) {
            if (strcmp(aux1->tipoParametro, aux2->tipoParametro) != 0) {
                retorna = 1;
            }
            aux1 = aux1->sig;
            aux2 = aux2->sig;
        }
    }
    return retorna;
}




void mostrarListaVariables(){
    symrec * auxTabla = sym_table;
    
     printf("\nLISTA DE VARIABLES DECLARADAS:\n");
    if(auxTabla == NULL)
        printf("NO Se Encontraron Variables\n");
    else
        while(auxTabla != NULL){
            if(auxTabla->type == 1){
                
                if(strcmp("int", auxTabla->tipo) == 0)  {
                        printf("\nTipo De Dato:   %s   -   Nombre: %s   -   Valor: %i\n",auxTabla->tipo,auxTabla->nombre, auxTabla->value.valEnt);    
                                                }
                if(strcmp("float", auxTabla->tipo) == 0)  {
                        printf("\nTipo De Dato:   %s   -   Nombre: %s   -   Valor: %f\n",auxTabla->tipo,auxTabla->nombre, auxTabla->value.valReal);
                                                }

                if(strcmp("char", auxTabla->tipo) == 0)  {
                        printf("\nTipo De Dato:   %s   -   Nombre: %s   -   Valor: %c\n",auxTabla->tipo,auxTabla->nombre, auxTabla->value.valChar);
                                                }
                if(strcmp("char*", auxTabla->tipo) == 0)  {
                        printf("\nTipo De Dato:   %s   -   Nombre: %s   -   Valor: %s\n",auxTabla->tipo,auxTabla->nombre, auxTabla->value.valString);
                                                }
                                                       
                                      }
                       auxTabla = auxTabla->next;
        }
        printf("\n");
    }


void mostrarParametros( Parametro*listaParametros){

if(listaParametros == NULL){
   printf("Lista de Parametros Vacia\n");
}

else
{
   while (listaParametros != NULL) {
   printf("Tipo de parametro: %s\n" , listaParametros->tipoParametro);
    listaParametros = listaParametros->sig;
 }
}
}


void mostrarListaFunciones(){
    symrec * auxTabla = sym_table;
    
    printf("\nLISTA DE FUNCIONES:\n");
    if(auxTabla == NULL)
        printf("NO Se Encontraron Funciones\n");
    else
        while(auxTabla != NULL){
            if(auxTabla->type == 2){
                 printf("\nRetorna: %s   -   Nombre: %s\n", auxTabla->tipo, auxTabla->nombre);
                 mostrarParametros(auxTabla->tiposParametros);
            }
            auxTabla = auxTabla->next;
        }
        printf("\n");
    }



struct Errores{
	char cadenaError[100]; 
	int linea;
	struct Errores* sig;		
};

struct Errores *listaErrorSintactico = NULL;

void agregarErrorSintactico(char* cadenaError,int linea){   
    struct Errores *nuevo;
    nuevo = (struct Errores*)malloc(sizeof(struct Errores));
    strcpy(nuevo->cadenaError,cadenaError);
    nuevo->linea = linea;
    nuevo->sig = NULL;

    if(listaErrorSintactico == NULL){
        listaErrorSintactico = nuevo;
    }
    else{
        struct Errores* aux;
        aux = listaErrorSintactico;

        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void mostrarErrorSintactico(){ 
    
    printf("\n\nERRORES SINTACTICOS:\n\n");
    if(listaErrorSintactico == NULL)
        printf("No Se Encontraron Errores Sintacticos\n\n");
    else{
        struct Errores* aux;
        aux = listaErrorSintactico;
        while(aux != NULL){
            
            printf("Linea %d:  %s\n\n",aux->linea, aux->cadenaError);
            aux = aux->sig;
        }
    }
}



struct Errores *listaErrorSemantico = NULL;

void agregarErrorSemantico(char* cadenaError,int linea){   
    struct Errores *nuevo;
    nuevo = (struct Errores*)malloc(sizeof(struct Errores));
    strcpy(nuevo->cadenaError,cadenaError);
    nuevo->linea = linea;
    nuevo->sig = NULL;

    if(listaErrorSemantico == NULL){
        listaErrorSemantico = nuevo;
    }
    else{
        struct Errores* aux;
        aux = listaErrorSemantico;

        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void mostrarErrorSemantico(){
    printf("\n\nERRORES SEMANTICOS:\n\n");
    if(listaErrorSemantico == NULL)
        printf("No Se Encontraron Errores Semanticos\n\n");
    else{
        struct Errores* aux;
        aux = listaErrorSemantico;
        while(aux != NULL){
            printf("Linea %d:  %s\n\n",aux->linea, aux->cadenaError);
            aux = aux->sig;
        }
    }
}



