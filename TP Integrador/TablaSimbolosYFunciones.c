#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <math.h>
#include <ctype.h>

// Tabla de símbolos 

// Nodo variable / función (esFuncion == 0 -> es variable)
typedef struct nodoTabla
{
    char* id;
    int esFuncion;
    char* tipo;
    struct nodoParam *parametros ;
    struct nodoTabla *sgte;
}elemento; 

// Nodo parámetro
typedef struct nodoParam
{
    char* nombreParametro;
    char* tipo;
    struct nodoParam *sgte;
}parametro;

elemento* tablaDeSimbolos = NULL;
parametro* listaParametros = NULL;

// Funciones

int existeElementoEnTabla(identificador, esFuncion) 
{
    elemento* e = tablaDeSimbolos;
    while (e && e->id != identificador && e->esFuncion == esFuncion) {
        e = e->sgte;
    }
    return e->sgte != NULL;
}

//Falta pasarle la lista de parametros
void agregarElementoATabla(char* id, int esFuncion, char* tipo) 
{
    if (existeElementoEnTabla(id, esFuncion)) {
        printf("Doble declaración");
        return;
    }

    elemento* e = (elemento*) malloc(sizeof(elemento));
    e->id = strdup(id);
    e->esFuncion = strdup(esFuncion);
    e->tipo = strdup(tipo);
    //e->nodoParam = parametros 
}

//Funcion validar Tipos operaciones binarias

