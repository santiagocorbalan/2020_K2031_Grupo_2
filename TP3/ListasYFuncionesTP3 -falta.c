#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <math.h>
#include <ctype.h> 

/////////////////////////////////   CONSTANTES   /////////////////////////////////

typedef struct nodoConstante{
    char* cadena;
    int valor;
    struct nodoConstante *sig; 
}constantes;

constantes *primerDecimal = NULL;
constantes *primerOctal = NULL;
constantes *primerHexadecimal = NULL;
constantes *primerReal = NULL;
constantes *primerCaracter = NULL;

/////////////////////////////////   CONSTANTES DECIMALES   /////////////////////////////////

void insertarConstanteDecimal(char* cadena){
    constantes *nuevo;
    nuevo = (constantes*)malloc(sizeof(constantes));
    
    nuevo->cadena = strdup(cadena);
    // strdup hace malloc((strlen(cadena)+1)*sizeof(char)); y strcpy(nuevo->cadena,cadena);
    
    nuevo->valor = atoi(cadena);
    nuevo->sig = NULL;


    if(primerDecimal == NULL){
        primerDecimal = nuevo;
    }
    else{
        constantes * aux;
        aux = primerDecimal;

        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void constantesDecimales(char* cadena){
    insertarConstanteDecimal(cadena);
}

void reporteConstantesDecimales(){
    printf("\nReporte Constantes Decimales\n\n");
    if(primerDecimal==NULL)
        printf("\tNo se encontraron constantes decimales\n");
    else{
        int totalAcumulado = 0;
        constantes* aux; 
        aux = primerDecimal; 
        
        while(aux != NULL){
            printf("Cadena: %s\tValor: %d\n",aux->cadena,aux->valor);
            totalAcumulado += aux->valor;
            aux = aux->sig;
        }    
        printf("Total acumulado: %d\n",totalAcumulado);
    }    
}

/////////////////////////////////   CONSTANTES OCTALES   /////////////////////////////////

void insertarConstanteOctal(char* cadena){
    constantes *nuevo;
    nuevo = (constantes*)malloc(sizeof(constantes));
    nuevo->cadena = strdup(cadena);
    nuevo->valor = strtol(cadena,NULL,8); // long int strtol (const char* str, char** endptr, int base); Convertir cadena en entero largo
    nuevo->sig = NULL;

    if(primerOctal == NULL){
        primerOctal = nuevo;
    }
    else{
        constantes* aux;
        aux = primerOctal;

        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void constantesOctales(char* cadena){
    insertarConstanteOctal(cadena);
}

void reporteConstantesOctales(){
    printf("\nReporte Constantes Octales\n\n");
    if(primerOctal==NULL)
        printf("\tNo se encontraron constantes octales\n");
    else{
        constantes* aux; 
        aux = primerOctal; 
        while(aux != NULL){
            printf("Cadena: %s\tValor: %d\n",aux->cadena,aux->valor);
            aux = aux->sig;
        }
    }
}

/////////////////////////////////   CONSTANTES HEXADECIMALES   /////////////////////////////////

void insertarConstanteHexadecimal(char* cadena){
    constantes *nuevo;
    nuevo = (constantes*)malloc(sizeof(constantes));
    nuevo->cadena = strdup(cadena);
    nuevo->valor = strtol(cadena,NULL,16);
    nuevo->sig = NULL;

    if(primerHexadecimal == NULL){
        primerHexadecimal = nuevo;
    }
    else{
        constantes* aux;
        aux = primerHexadecimal;

        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void constantesHexadecimales(char* cadena){
    insertarConstanteHexadecimal(cadena);
}

void reporteConstantesHexadecimales(){
    printf("\nReporte Constantes Hexadecimales\n\n");
    if(primerHexadecimal==NULL)
        printf("\tNo se encontraron constantes hexadecimales\n");
    else{
        constantes* aux; 
        aux = primerHexadecimal; 
        while(aux != NULL){
            printf("Cadena: %s\tValor: %d\n",aux->cadena,aux->valor);
            aux = aux->sig;
        }
    }
}

/////////////////////////////////   CONSTANTES REALES  /////////////////////////////////

void insertarConstanteReal(char* cadena){
    constantes *nuevo;
    nuevo = (constantes*)malloc(sizeof(constantes));
    nuevo->cadena = strdup(cadena); //Devuelve un puntero a una cadena de bytes terminada en null, que es un duplicado de la cadena a la que apunta Cadena
    nuevo->sig = NULL;

    if(primerReal == NULL){
        primerReal = nuevo;
    }
    else{
        constantes* aux;
        aux = primerReal;

        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void constantesReales(char* cadena){
    insertarConstanteReal(cadena);
}

void reporteConstantesReales(){
    int parteEntera;
    double parteDecimal;
    double valor;

    printf("\nReporte Constantes Reales\n\n");
    constantes* aux; 
    if(primerReal==NULL)
        printf("\tNo se encontraron constantes reales\n");
    else{
        aux = primerReal; 
        while(aux != NULL)
        {
            valor = atof(aux->cadena); //convierte una cadena a su valor numérico pero en coma flotante
            parteEntera = (int) valor; // convertir valor a tipo int - entero
            parteDecimal = valor - parteEntera;

            printf("Cadena: %s\tParte entera: %d\tParte decimal: %f\n", aux->cadena, parteEntera, parteDecimal);
            aux = aux->sig;
        }
    }
}

////////////////////   CONSTANTES CARACTER   ///////////////////

void insertarConstanteCaracter(char* cadena){
    constantes *nuevo;
    nuevo = (constantes*)malloc(sizeof(constantes));
    nuevo->cadena = strdup(cadena);
    nuevo->sig = NULL;

    if(primerCaracter == NULL){
        primerCaracter = nuevo;
    }
    else{
        constantes* aux;
        aux = primerCaracter;

        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void constantesCaracter(char* cadena){
    insertarConstanteCaracter(cadena);
}

void reporteConstantesCaracter(){
    printf("\nReporte Constantes Caracter\n\n");
    if(primerCaracter==NULL)
        printf("\tNo se encontraron constantes caracter\n");
    else{
        constantes* aux;
        aux = primerCaracter; 
        while(aux != NULL){
            printf("%s\n",aux->cadena);
            aux = aux->sig;
        }
    }
}

/////////////////////////////////   LITERALES CADENAS   /////////////////////////////////

typedef struct nodoLiteralCadena{
    char* cadena;
    int longitud;
    struct nodoLiteralCadena *sig; 
}literalCadena;

literalCadena *primerLiteralCadena = NULL;

void insertarLiteralCadena(char* cadena){
    literalCadena *nuevo;
    nuevo = (literalCadena*)malloc(sizeof(literalCadena)); // reservo memoria con malloc
    
    nuevo->cadena = strdup(cadena);
    nuevo->longitud = strlen(cadena)-2; // strlen te da la longitud de una cadena ¿menos 2?
    nuevo->sig = NULL;

    if(primerLiteralCadena == NULL){
        primerLiteralCadena = nuevo;
    }
    else{
        literalCadena* aux;
        aux = primerLiteralCadena;

        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void literalesCadena(char* cadena){
    insertarLiteralCadena(cadena);
}

void reporteLiteralesCadena(){
    printf("\nReporte Literales cadena\n\n");
    if(primerLiteralCadena==NULL)
        printf("\tNo se encontraron literales cadena\n");
    else{
        literalCadena* aux; 
        aux = primerLiteralCadena; 
        while(aux != NULL){
            printf("La cadena encontrada es %s\tY su Longitud es: %d\n",aux->cadena,aux->longitud);
            aux = aux->sig;
        }
    }
}

/////////////////////////////////   PALABRAS RESERVADAS    /////////////////////////////////

typedef struct nodoPalabraReservada{
    char* cadena;
    char* tipo;
    struct nodoPalabraReservada *sig; 
}palabraReservada;

palabraReservada *primerPalabraReservada = NULL;

void insertarPalabraReservada(char* cadena,char* tipo){
    palabraReservada *nuevo;
    nuevo = (palabraReservada*)malloc(sizeof(palabraReservada));
    nuevo->cadena = strdup(cadena);
    nuevo->tipo = tipo;
    nuevo->sig = NULL;

    if(primerPalabraReservada == NULL){
        primerPalabraReservada = nuevo;
    }
    else{
        palabraReservada* aux;
        aux = primerPalabraReservada;

        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void palabrasReservadas(char* cadena,char* tipo){
    insertarPalabraReservada(cadena,tipo);
}

void reportePalabrasReservadas(){
    printf("\nReporte Palabras Reservadas\n\n");
    if(primerPalabraReservada==NULL)
        printf("\tNo se encontraron palabras reservadas\n");
    else{
        palabraReservada* aux;
        aux = primerPalabraReservada;
        while(aux != NULL){
            printf("La palabra reservada es :%s\t (%s)\n",aux->cadena,aux->tipo);
            aux = aux->sig;
        }
    }
}

/////////////////////////////////   OPERADORES Y CARACTERES DE PUNTUACION   /////////////////////////////////

typedef struct nodoOperador_CaracterDePuntuacion{
    char* cadena;
    int cantidad;
    struct nodoOperador_CaracterDePuntuacion *sig; 
}operadorCaracter;

operadorCaracter* punteroOperadorCaracter = NULL;

void insertarOperadorCaracterPuntc(char* cadena){
    if(punteroOperadorCaracter == NULL){
        
        operadorCaracter* nuevo;
        nuevo = (operadorCaracter*)malloc(sizeof(operadorCaracter));
        nuevo->cadena = strdup(cadena);
        // strdup hace malloc((strlen(cadena)+1)*sizeof(char)); y strcpy(nuevo->cadena,cadena);
        nuevo->cantidad = 1;
        nuevo->sig = NULL;
        punteroOperadorCaracter = nuevo; 
    }
    else{
        operadorCaracter* aux = punteroOperadorCaracter;
        while((strcmp(cadena,aux->cadena) != 0) && aux->sig != NULL){  // strcmp si devuelve 0 entonces el contenido de ambas cadenas son iguales
            // si no existe el caracter y NO estoy parado en el ultimo de la lista
            aux = aux->sig;
        }

        if(aux->sig == NULL){ // si estoy parado en el ultimo de la lista
            operadorCaracter* nuevo;
            nuevo = (operadorCaracter*)malloc(sizeof(operadorCaracter));
            nuevo->cadena = strdup(cadena);
            // strdup hace malloc((strlen(cadena)+1)*sizeof(char)); y strcpy(nuevo->cadena,cadena);
            nuevo->cantidad = 1;
            nuevo->sig = NULL;
            aux->sig = nuevo;
        }
        else{ // si ya existe el caracter
            aux->cantidad = aux->cantidad +1;
        }
    }
}

void operadoresCaracteresPuntc(char* cadena){
    insertarOperadorCaracterPuntc(cadena);
}

void reporteOperadoresCaracteresPuntc(){
    printf("\nReporte Operadores/Caracteres de Puntuacion\n\n");
    operadorCaracter *aux = punteroOperadorCaracter;
    if(punteroOperadorCaracter==NULL)
        printf("\tNo se encontraron Operadores/Caracteres de Puntuacion\n");
    while(aux != NULL){
        printf("Operador/Caracter: %s\tCantidad de veces que aparece: %d\n",aux->cadena,aux->cantidad);
        aux = aux->sig;
    }
} 

//////////////////////////  REPORTES  ////////////////////////////////////

void reportes(){
    reportePalabrasReservadas();
    reporteLiteralesCadena();
    reporteConstantesDecimales();
    reporteConstantesOctales();
    reporteConstantesHexadecimales();
    reporteConstantesReales();
    reporteConstantesCaracter();
    reporteOperadoresCaracteresPuntc();
}