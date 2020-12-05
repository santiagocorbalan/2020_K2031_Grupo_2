#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ---------------- Declaración de estructuras ----------------- //

typedef struct errorres{
	char*  cadenaDeErrores;
	struct errorres* sig;		
}Errores;

Errores *listaErrores = NULL;

typedef struct tabla{
    	char*  nombre;
        char*  tipo;
        int variableOfuncion;
        struct parametro* tiposParametros;
        union
        {
         int      valEnt; 
         double   valReal;
         char     valChar;
         char*    valString;
        } value;
        struct tabla* sig;
} Tabla;

Tabla *listaSimbolos = NULL;

typedef struct parametro{
    char*  tipoParametro;
    struct parametro* sig;
} Parametro;

Parametro *listaParametrosAux = NULL;

// ---------------- Declaración de funciones ----------------- //

void agregarError(char* cadenaError);
void mostrarErrores( Errores*listaDeErrores);
void agregoSimbolo(char* name , char* type, int nuevaVariableOfuncion);
Tabla *buscarSimbolo(char *name);
Tabla *agregoSimbolo2(char* name2 , char* type2, int nuevaVariableOfuncion2);
void agregoParametro(char* tipoArgumentooo);
int cantidadParametros(Parametro* listaAuxiliar);
int compararParametros(Parametro* lista1, Parametro* lista2);
void agregoArgumento(char* tipoArgumentooo);
void mostrarParametros(Parametro*listaParametros);
void mostrarSimbolos(Tabla* lista);

void agregarError(char* cadenaError){  
     
    Errores *nuevo_nodo = (Errores *)malloc(sizeof(Errores));
    nuevo_nodo->cadenaDeErrores = (char *) malloc (strlen (cadenaError) + 1);
    strcpy (nuevo_nodo->cadenaDeErrores,cadenaError);
    nuevo_nodo->sig = NULL;

    if (listaErrores == NULL) {
        listaErrores  = nuevo_nodo;
    } else {
        Errores *aux;
        aux = listaErrores ;

        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo_nodo;
    }
}

void agregoSimbolo(char* name , char* type, int nuevaVariableOfuncion){
    
    Tabla *nuevo_nodo = (Tabla *)malloc(sizeof(Tabla));
    nuevo_nodo->nombre = (char *) malloc (strlen (name) + 1);
    strcpy (nuevo_nodo->nombre,name);
    nuevo_nodo->tipo = (char *) malloc (strlen (type) + 1);
    strcpy (nuevo_nodo->tipo,type);

    nuevo_nodo->variableOfuncion = nuevaVariableOfuncion; 
    nuevo_nodo->tiposParametros = NULL;

    nuevo_nodo->sig = NULL;

    if (listaSimbolos == NULL) {
        listaSimbolos  = nuevo_nodo;
    } else {
        Tabla *aux;
        aux = listaSimbolos ;

        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo_nodo;
    }
  
}

Tabla *buscarSimbolo(char *name) {
    Tabla *ptr;
    for (ptr = listaSimbolos; ptr != (Tabla *) 0; ptr = (Tabla *)ptr->sig)
        if (strcmp (ptr->nombre, name) == 0)
            return ptr;
        return 0;
}

Tabla *agregoSimbolo2(char* name2 , char* type2, int nuevaVariableOfuncion2){
    
    Tabla *nuevo_nodo = (Tabla *)malloc(sizeof(Tabla));
    nuevo_nodo->nombre = (char *) malloc (strlen (name2) + 1);
    strcpy (nuevo_nodo->nombre,name2);
    nuevo_nodo->tipo = (char *) malloc (strlen (type2) + 1);
    strcpy (nuevo_nodo->tipo,type2);

    nuevo_nodo->variableOfuncion = nuevaVariableOfuncion2; 
    nuevo_nodo->tiposParametros = NULL;

    nuevo_nodo->sig = NULL;

    if(listaSimbolos == NULL){
        listaSimbolos  = nuevo_nodo;
    } else {
        Tabla *aux;
        aux = listaSimbolos ;

        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo_nodo;
    }
  
    return listaSimbolos;
}

void agregoParametro(char* tipoArgumentooo){
    
    Parametro *nuevo_nodo = (Parametro *)malloc(sizeof(Parametro));
    nuevo_nodo->tipoParametro = (char *) malloc (strlen (tipoArgumentooo) + 1);
    strcpy (nuevo_nodo->tipoParametro,tipoArgumentooo);
    nuevo_nodo->sig = NULL;

    if (listaParametrosAux == NULL){
        listaParametrosAux  = nuevo_nodo;
    } else {
        Parametro *aux;
        aux = listaParametrosAux ;

        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo_nodo;
    }
}

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
    } else {
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

void agregoArgumento(char* tipoArgumentooo){
    
    Parametro *nuevo_nodo = (Parametro *)malloc(sizeof(Parametro));
    nuevo_nodo->tipoParametro = (char *) malloc (strlen (tipoArgumentooo) + 1);
    strcpy (nuevo_nodo->tipoParametro,tipoArgumentooo);
    nuevo_nodo->sig = NULL;

    if(listaParametrosAux == NULL){
        listaParametrosAux  = nuevo_nodo;
    } else {
        Parametro *aux;
        aux = listaParametrosAux ;

        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo_nodo;
    }
}

void mostrarErrores( Errores*listaDeErrores){

    if(listaDeErrores == NULL) {
        printf("No se encontro ningun Error\n");
    }

    else {
        while (listaDeErrores != NULL) {
            printf( "%s" , listaDeErrores->cadenaDeErrores);
            listaDeErrores = listaDeErrores->sig;
        }
    }
}

void mostrarParametros( Parametro*listaParametros){
    if(listaParametros == NULL){
        printf("Lista de Parametros Vacia\n");
    } else {
        while (listaParametros != NULL) {
            printf("Tipo de parametro: %s\n" , listaParametros->tipoParametro);
            listaParametros = listaParametros->sig;
        }
    }
}

void mostrarSimbolos(Tabla* lista){

    if (lista == NULL){
        printf("Tabla de Simbolos Vacia\n");
    } else {

        while (lista != NULL) {

            switch (lista->variableOfuncion) {
            case 1:
                printf("Nombre de la variable: %s , Tipo: %s", lista->nombre, lista->tipo);
                break;

            case 2:
                printf("Nombre de la funcion: %s , Tipo: %s", lista->nombre, lista->tipo);
                printf("Cantidad de parametros: %i", cantidadParametros(lista->tiposParametros));
                mostrarParametros(lista->tiposParametros);
                break;
            }
        lista = lista->sig;
        }
    }
}