<<<<<<< HEAD:TP3/ListasYFuncionesTP3 -falta.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <math.h>
#include <ctype.h>

// CONSTANTES

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

// CONSTANTES DECIMALES

void insertarConstanteDecimal(char* cadena){
    constantes *nuevo = NULL;
    nuevo = (constantes*)malloc(sizeof(constantes));
    
    nuevo->cadena = strdup(cadena);
    // strdup hace malloc((strlen(cadena)+1)*sizeof(char)); y strcpy(nuevo->cadena,cadena);
    
    nuevo->valor = atoi(cadena);
    nuevo->sig = NULL;


    if (primerDecimal == NULL) {
        primerDecimal = nuevo;
    } else {
        constantes * aux;
        aux = primerDecimal;

        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void constantesDecimales(char* cadena) {
    insertarConstanteDecimal(cadena);
}

void reporteConstantesDecimales() {
    printf("\nReporte Constantes Decimales\n\n");
    if (primerDecimal == NULL)
        printf("\tNo se encontraron constantes decimales\n");
    else {
        int totalAcumulado = 0;
        constantes* aux; 
        aux = primerDecimal; 
        
        while(aux != NULL) {
            printf("Cadena: %s\tValor: %d\n",aux->cadena,aux->valor);
            totalAcumulado += aux->valor;
            aux = aux->sig;
        }    
        printf("Total acumulado: %d\n",totalAcumulado);
    }    
}

// CONSTANTES OCTALES

void insertarConstanteOctal(char* cadena) {
    constantes *nuevo = NULL;
    nuevo = (constantes*)malloc(sizeof(constantes));
    nuevo->cadena = strdup(cadena);
    nuevo->valor = strtol(cadena,NULL,8); // long int strtol (const char* str, char** endptr, int base); Convertir cadena en entero largo
    nuevo->sig = NULL;

    if (primerOctal == NULL) {
        primerOctal = nuevo;
    } else {
        constantes* aux;
        aux = primerOctal;

        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void constantesOctales(char* cadena) {
    insertarConstanteOctal(cadena);
}

void reporteConstantesOctales() {
    printf("\nReporte Constantes Octales\n\n");
    if (primerOctal == NULL) {
        printf("\tNo se encontraron constantes octales\n");
    } else {
        constantes* aux; 
        aux = primerOctal; 
        while (aux != NULL) {
            printf("Cadena: %s\tValor: %d\n",aux->cadena,aux->valor);
            aux = aux->sig;
        }
    }
}

// CONSTANTES HEXADECIMALES

void insertarConstanteHexadecimal(char* cadena) {
    constantes *nuevo = NULL;
    nuevo = (constantes*)malloc(sizeof(constantes));
    nuevo->cadena = strdup(cadena);
    nuevo->valor = strtol(cadena,NULL,16);
    nuevo->sig = NULL;

    if (primerHexadecimal == NULL) {
        primerHexadecimal = nuevo;
    } else {
        constantes* aux;
        aux = primerHexadecimal;

        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void constantesHexadecimales(char* cadena) {
    insertarConstanteHexadecimal(cadena);
}

void reporteConstantesHexadecimales() {
    printf("\nReporte Constantes Hexadecimales\n\n");
    if (primerHexadecimal == NULL) {
        printf("\tNo se encontraron constantes hexadecimales\n");
    } else {
        constantes* aux; 
        aux = primerHexadecimal; 
        while (aux != NULL) {
            printf("Cadena: %s\tValor: %d\n",aux->cadena,aux->valor);
            aux = aux->sig;
        }
    }
}

// CONSTANTES REALES

void insertarConstanteReal(char* cadena) {
    constantes *nuevo = NULL;
    nuevo = (constantes*)malloc(sizeof(constantes));
    nuevo->cadena = strdup(cadena); //Devuelve un puntero a una cadena de bytes terminada en null, que es un duplicado de la cadena a la que apunta Cadena
    nuevo->sig = NULL;

    if (primerReal == NULL) {
        primerReal = nuevo;
    } else {
        constantes* aux;
        aux = primerReal;

        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void constantesReales(char* cadena) {
    insertarConstanteReal(cadena);
}

void reporteConstantesReales() {
    int parteEntera;
    double parteDecimal;
    double valor;

    printf("\nReporte Constantes Reales\n\n");
    constantes* aux;
    
    if (primerReal == NULL) {
        printf("\tNo se encontraron constantes reales\n");
    } else {
        aux = primerReal; 
        while (aux != NULL) {
            valor = atof(aux->cadena); //convierte una cadena a su valor numérico pero en coma flotante
            parteEntera = (int) valor; // convertir valor a tipo int - entero
            parteDecimal = valor - parteEntera;

            printf("Cadena: %s\tParte entera: %d\tParte decimal: %f\n", aux->cadena, parteEntera, parteDecimal);
            aux = aux->sig;
        }
    }
}

// CONSTANTES CARACTER

void insertarConstanteCaracter(char* cadena){
    constantes *nuevo = NULL;
    nuevo = (constantes*)malloc(sizeof(constantes));
    nuevo->cadena = strdup(cadena);
    nuevo->sig = NULL;

    if (primerCaracter == NULL) {
        primerCaracter = nuevo;
    } else {
        constantes* aux;
        aux = primerCaracter;

        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void constantesCaracter(char* cadena) {
    insertarConstanteCaracter(cadena);
}

void reporteConstantesCaracter() {
    printf("\nReporte Constantes Caracter\n\n");
    if (primerCaracter == NULL) {
        printf("\tNo se encontraron constantes caracter\n");
    } else {
        constantes* aux;
        aux = primerCaracter;
        
        while (aux != NULL) {
            printf("%s\n",aux->cadena);
            aux = aux->sig;
        }
    }
}

// LITERALES CADENA

typedef struct nodoLiteralCadena{
    char* cadena;
    int longitud;
    struct nodoLiteralCadena *sig; 
}literalCadena;

literalCadena *primerLiteralCadena = NULL;

void insertarLiteralCadena(char* cadena) {
    literalCadena *nuevo;
    nuevo = (literalCadena*)malloc(sizeof(literalCadena)); // reservo memoria con malloc
    
    nuevo->cadena = strdup(cadena);
    nuevo->longitud = strlen(cadena)-2; // strlen te da la longitud de una cadena ¿menos 2?
    nuevo->sig = NULL;

    if (primerLiteralCadena == NULL) {
        primerLiteralCadena = nuevo;
    } else {
        literalCadena* aux;
        aux = primerLiteralCadena;

        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void literalesCadena(char* cadena) {
    insertarLiteralCadena(cadena);
}

void reporteLiteralesCadena() {
    printf("\nReporte Literales cadena\n\n");
    if (primerLiteralCadena == NULL) {
        printf("\tNo se encontraron literales cadena\n");
    } else {
        literalCadena* aux; 
        aux = primerLiteralCadena; 
        while (aux != NULL) {
            printf("La cadena encontrada es %s\tY su Longitud es: %d\n",aux->cadena,aux->longitud);
            aux = aux->sig;
        }
    }
}

// PALABRAS RESERVADAS

typedef struct nodoPalabraReservada{
    char* cadena;
    char* tipo;
    struct nodoPalabraReservada *sig; 
}palabraReservada;

palabraReservada *primerPalabraReservada = NULL;

void insertarPalabraReservada(char* cadena,char* tipo){
    palabraReservada *nuevo = NULL;
    nuevo = (palabraReservada*)malloc(sizeof(palabraReservada));
    nuevo->cadena = strdup(cadena);
    nuevo->tipo = tipo;
    nuevo->sig = NULL;

    if (primerPalabraReservada == NULL) {
        primerPalabraReservada = nuevo;
    } else {
        palabraReservada* aux;
        aux = primerPalabraReservada;

        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void palabrasReservadas(char* cadena,char* tipo) {
    insertarPalabraReservada(cadena,tipo);
}

void reportePalabrasReservadas() {
    printf("\nReporte Palabras Reservadas\n\n");
    if (primerPalabraReservada == NULL) {
        printf("\tNo se encontraron palabras reservadas\n");
    } else {
        palabraReservada* aux;
        aux = primerPalabraReservada;
        
        while (aux != NULL) {
            printf("La palabra reservada es :%s\t (%s)\n",aux->cadena,aux->tipo);
            aux = aux->sig;
        }
    }
}

// IDENTIFICADORES


typedef struct nodoID{
	char* cadena;
	int cantidad;
	struct nodoID* sig;		
}identificador;

identificador* primerID = NULL;

int buscarIdentificador(char* cadena){
	identificador* aux = primerID;
	while(strcmp(cadena,aux->cadena)!=0 && aux->sig != NULL){ // que cadena y aux -> cadena sea distinto de 0 nos garantisamos que el contenido no sea igual
		aux = aux->sig;
	}                                                 // se guarda la cantidad de veces que aparece el ID
	
	if(strcmp(cadena,aux->cadena)==0){ //  si devuelve 0 entonces el contenido de ambas cadenas son iguales (con strcmp)
		aux->cantidad += 1;
		return 1;
	}
	else if(aux->sig == NULL){
		return 0;
	}		
}

int criterioOrdenamiento(char* cadena1,char* cadena2){
	
	int resultado = strcasecmp(cadena1,cadena2);  // compara sus argumentos después de traducir cada carácter a su correspondiente en minúscul
	
	if(resultado < 0)		// Si minuscula1 tiene menor ascii devuelve < 0    	ej: a y z 
		    return 0;
	    else if(resultado > 0)	// Si minuscula1 tiene mayor ascii devuelve > 0		ej: z y a
		    return 1;
	else{ // Caso cuando en minusculas son iguales			ej: A y a
		resultado = strcmp(cadena1,cadena2); // Comparo con las cadenas originales
		if(resultado < 0)
			return 0;   // Devuelve 0 cuando cadena1 es mayuscula antes de cadena2 	ej: A y a
		else 
			return 1;	// Devuelve 1 cuando cadena1 es mayuscula despues de cadena2 ej: a y A
	}
}

void insertarIdentificadorOrdenado(char* cadena){
	if(primerID == NULL){ // si la lista esta vacia
		struct nodoID* nuevo;
		nuevo = (struct nodoID*)malloc(sizeof(struct nodoID));
        nuevo->cadena = strdup(cadena);
        // strdup hace malloc((strlen(cadena)+1)*sizeof(char)); y strcpy(nuevo->cadena,cadena);
		primerID = nuevo;
		strcpy(primerID->cadena,cadena);
		primerID->cantidad = 1;
		primerID->sig = NULL;
	}
	else{
		if(!(criterioOrdenamiento(cadena,primerID->cadena))){ // si el ID a insertar es el nuevo primero (o sea no tendria que avanzar con el criterio de ordenamiento)
			identificador* nuevo;
			nuevo = (identificador*)malloc(sizeof(identificador));
        	nuevo->cadena = strdup(cadena);
        	// strdup hace malloc((strlen(cadena)+1)*sizeof(char)); y strcpy(nuevo->cadena,cadena);
			nuevo->sig = primerID;
			nuevo->cantidad = 1;
			primerID = nuevo;
		}
		else if(!buscarIdentificador(cadena)){ // si el ID ya estaba en la lista lo incremento de cantidad
			// si el ID no estaba en la lista lo inserto ordenado
			identificador* aux = primerID;
			while(aux->sig != NULL && criterioOrdenamiento(cadena,aux->sig->cadena)){ // busco la posicion donde insertar el ID
				aux = aux->sig;
			}
			identificador* nuevo;
			nuevo = (identificador*)malloc(sizeof(identificador));
        	nuevo->cadena = strdup(cadena);
        	// strdup hace malloc((strlen(cadena)+1)*sizeof(char)); y strcpy(nuevo->cadena,cadena);
			nuevo->cantidad = 1;
			nuevo->sig = aux->sig;
			aux->sig = nuevo;				
		}	
	}
}

void identificadores(char* cadena){
    insertarIdentificadorOrdenado(cadena);
}

// OPERADORES Y CARACTERES DE PUNTUACION

typedef struct nodoOperador_CaracterDePuntuacion{
    char* cadena;
    int cantidad;
    struct nodoOperador_CaracterDePuntuacion *sig; 
}operadorCaracter;

operadorCaracter* punteroOperadorCaracter = NULL;

void insertarOperadorCaracterPuntc(char* cadena) {
    if (punteroOperadorCaracter == NULL) {
        
        operadorCaracter* nuevo = NULL;
        nuevo = (operadorCaracter*)malloc(sizeof(operadorCaracter));
        nuevo->cadena = strdup(cadena);
        // strdup hace malloc((strlen(cadena)+1)*sizeof(char)); y strcpy(nuevo->cadena,cadena);
        nuevo->cantidad = 1;
        nuevo->sig = NULL;
        punteroOperadorCaracter = nuevo; 
    } else {
        
        operadorCaracter* aux = punteroOperadorCaracter;
        
        while((strcmp(cadena,aux->cadena) != 0) && aux->sig != NULL){  // strcmp si devuelve 0 entonces el contenido de ambas cadenas son iguales
            // si no existe el caracter y NO estoy parado en el ultimo de la lista
            aux = aux->sig;
        }

        if (aux->sig == NULL) { // si estoy parado en el ultimo de la lista
            operadorCaracter* nuevo;
            nuevo = (operadorCaracter*)malloc(sizeof(operadorCaracter));
            nuevo->cadena = strdup(cadena);
            // strdup hace malloc((strlen(cadena)+1)*sizeof(char)); y strcpy(nuevo->cadena,cadena);
            nuevo->cantidad = 1;
            nuevo->sig = NULL;
            aux->sig = nuevo;
            
        } else { // si ya existe el caracter
            aux->cantidad = aux->cantidad +1;
        }
    }
}

void operadoresCaracteresPuntc(char* cadena) {
    insertarOperadorCaracterPuntc(cadena);
}

void reporteOperadoresCaracteresPuntc() {
    printf("\nReporte Operadores/Caracteres de Puntuacion\n\n");
    operadorCaracter *aux = punteroOperadorCaracter;
    if (punteroOperadorCaracter == NULL)
        printf("\tNo se encontraron Operadores/Caracteres de Puntuacion\n");
    while (aux != NULL) {
        printf("Operador/Caracter: %s\tCantidad de veces que aparece: %d\n",aux->cadena,aux->cantidad);
        aux = aux->sig;
    }
} 

// COMENTARIOS

typedef struct nodoComentarios{
	char* cadena;
	char* tipo;
	struct nodoComentarios* sig;		
}comentario;

comentario *primerComentario = NULL;

void insertarComentarios(char* cadena,char* tipo){
    comentario *nuevo;
    nuevo = (comentario*)malloc(sizeof(comentario));
    nuevo->cadena = strdup(cadena);
    nuevo->tipo = tipo;
    nuevo->sig = NULL;

    if(primerComentario == NULL){
        primerComentario = nuevo;
    }
    else{
        struct nodoComentarios* aux;
        aux = primerComentario;

        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void comentarios(char* cadena,char* tipo){
    insertarComentarios(cadena,tipo);
}

void reporteComentarios(){
    printf("\nReporte Comentarios\n\n");
    if(primerComentario == NULL)
        printf("\tNo se encontraron comentarios\n");
    else{
        struct nodoComentarios* aux;
        aux = primerComentario;
        while(aux != NULL){
            printf("%s\n%s\n\n",aux->tipo,aux->cadena);
            aux = aux->sig;
        }
    }
}

//  CARACTERES NO RECONOCIDOS

typedef struct nodoCarNoReconocidos{
	char* cadena;
	int linea;
	struct nodoCarNoReconocidos* sig;		
}caracterNoReconocido;

caracterNoReconocido *primerCarNoReconocido = NULL;

void insertarCarNoReconocidos(char* cadena,int linea){
    caracterNoReconocido *nuevo;
    nuevo = (caracterNoReconocido*)malloc(sizeof(caracterNoReconocido));
    nuevo->cadena = strdup(cadena);
    nuevo->linea = linea;
    nuevo->sig = NULL;

    if(primerCarNoReconocido == NULL){
        primerCarNoReconocido = nuevo;
    }
    else{
        caracterNoReconocido* aux;
        aux = primerCarNoReconocido;

        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

char cadenaNoReconocidos[100]="";

void caracNoReconocidos(char* caracterNoReconocido,int linea){
    
    // Cuando el caracter no reconocido NO es un espacio y NO es un salto de linea
    if(strcmp(caracterNoReconocido," ")!=0 && strcmp(caracterNoReconocido,"\n")!=0){ 
        strcat(cadenaNoReconocidos,caracterNoReconocido);
    }
    else{            
        if(strcmp(cadenaNoReconocidos,"")!=0){ // Cuando la cadena de no reconocidos no está vacia
            if(strcmp(caracterNoReconocido," ")==0) // Cuando el caracter no reconocido es un espacio
                insertarCarNoReconocidos(cadenaNoReconocidos,linea);
            else                                    // Cuando el caracter no reconocido es un salto de linea
                insertarCarNoReconocidos(cadenaNoReconocidos,linea-1);
            
            strcpy(cadenaNoReconocidos,"");
        }
    }
}

void reporteCaracNoReconocidos(){
    printf("\nReporte Cadenas de caracteres no reconocidos\n\n");
    if(primerCarNoReconocido == NULL)
        printf("\tNo se encontraron cadenas de caracteres no reconocidos\n\n");
    else{
        struct nodoCarNoReconocidos* aux;
        aux = primerCarNoReconocido;
        while(aux != NULL){
            printf("Cadena: %s\tlinea: %d\n",aux->cadena,aux->linea);
            aux = aux->sig;
        }
    }
}



// REPORTES

void reportes(){
    reportePalabrasReservadas();
    reporteLiteralesCadena();
    reporteConstantesDecimales();
    reporteConstantesOctales();
    reporteConstantesHexadecimales();
    reporteConstantesReales();
    reporteConstantesCaracter();
    reporteOperadoresCaracteresPuntc();
    reporteIdentificadores();
    reporteComentarios();
    reporteCaracNoReconocidos();
}
=======
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <math.h>
#include <ctype.h>

// CONSTANTES

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

// CONSTANTES DECIMALES

void insertarConstanteDecimal(char* cadena){
    constantes *nuevo = NULL;
    nuevo = (constantes*)malloc(sizeof(constantes));
    
    nuevo->cadena = strdup(cadena);
    // strdup hace malloc((strlen(cadena)+1)*sizeof(char)); y strcpy(nuevo->cadena,cadena);
    
    nuevo->valor = atoi(cadena);
    nuevo->sig = NULL;


    if (primerDecimal == NULL) {
        primerDecimal = nuevo;
    } else {
        constantes * aux;
        aux = primerDecimal;

        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void constantesDecimales(char* cadena) {
    insertarConstanteDecimal(cadena);
}

void reporteConstantesDecimales() {
    printf("\nReporte Constantes Decimales\n\n");
    if (primerDecimal == NULL)
        printf("\tNo se encontraron constantes decimales\n");
    else {
        int totalAcumulado = 0;
        constantes* aux; 
        aux = primerDecimal; 
        
        while(aux != NULL) {
            printf("Cadena: %s\tValor: %d\n",aux->cadena,aux->valor);
            totalAcumulado += aux->valor;
            aux = aux->sig;
        }    
        printf("Total acumulado: %d\n",totalAcumulado);
    }    
}

// CONSTANTES OCTALES

void insertarConstanteOctal(char* cadena) {
    constantes *nuevo = NULL;
    nuevo = (constantes*)malloc(sizeof(constantes));
    nuevo->cadena = strdup(cadena);
    nuevo->valor = strtol(cadena,NULL,8); // long int strtol (const char* str, char** endptr, int base); Convertir cadena en entero largo
    nuevo->sig = NULL;

    if (primerOctal == NULL) {
        primerOctal = nuevo;
    } else {
        constantes* aux;
        aux = primerOctal;

        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void constantesOctales(char* cadena) {
    insertarConstanteOctal(cadena);
}

void reporteConstantesOctales() {
    printf("\nReporte Constantes Octales\n\n");
    if (primerOctal == NULL) {
        printf("\tNo se encontraron constantes octales\n");
    } else {
        constantes* aux; 
        aux = primerOctal; 
        while (aux != NULL) {
            printf("Cadena: %s\tValor: %d\n",aux->cadena,aux->valor);
            aux = aux->sig;
        }
    }
}

// CONSTANTES HEXADECIMALES

void insertarConstanteHexadecimal(char* cadena) {
    constantes *nuevo = NULL;
    nuevo = (constantes*)malloc(sizeof(constantes));
    nuevo->cadena = strdup(cadena);
    nuevo->valor = strtol(cadena,NULL,16);
    nuevo->sig = NULL;

    if (primerHexadecimal == NULL) {
        primerHexadecimal = nuevo;
    } else {
        constantes* aux;
        aux = primerHexadecimal;

        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void constantesHexadecimales(char* cadena) {
    insertarConstanteHexadecimal(cadena);
}

void reporteConstantesHexadecimales() {
    printf("\nReporte Constantes Hexadecimales\n\n");
    if (primerHexadecimal == NULL) {
        printf("\tNo se encontraron constantes hexadecimales\n");
    } else {
        constantes* aux; 
        aux = primerHexadecimal; 
        while (aux != NULL) {
            printf("Cadena: %s\tValor: %d\n",aux->cadena,aux->valor);
            aux = aux->sig;
        }
    }
}

// CONSTANTES REALES

void insertarConstanteReal(char* cadena) {
    constantes *nuevo = NULL;
    nuevo = (constantes*)malloc(sizeof(constantes));
    nuevo->cadena = strdup(cadena); //Devuelve un puntero a una cadena de bytes terminada en null, que es un duplicado de la cadena a la que apunta Cadena
    nuevo->sig = NULL;

    if (primerReal == NULL) {
        primerReal = nuevo;
    } else {
        constantes* aux;
        aux = primerReal;

        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void constantesReales(char* cadena) {
    insertarConstanteReal(cadena);
}

void reporteConstantesReales() {
    int parteEntera;
    double parteDecimal;
    double valor;

    printf("\nReporte Constantes Reales\n\n");
    constantes* aux;
    
    if (primerReal == NULL) {
        printf("\tNo se encontraron constantes reales\n");
    } else {
        aux = primerReal; 
        while (aux != NULL) {
            valor = atof(aux->cadena); //convierte una cadena a su valor numérico pero en coma flotante
            parteEntera = (int) valor; // convertir valor a tipo int - entero
            parteDecimal = valor - parteEntera;

            printf("Cadena: %s\tParte entera: %d\tParte decimal: %f\n", aux->cadena, parteEntera, parteDecimal);
            aux = aux->sig;
        }
    }
}

// CONSTANTES CARACTER

void insertarConstanteCaracter(char* cadena){
    constantes *nuevo = NULL;
    nuevo = (constantes*)malloc(sizeof(constantes));
    nuevo->cadena = strdup(cadena);
    nuevo->sig = NULL;

    if (primerCaracter == NULL) {
        primerCaracter = nuevo;
    } else {
        constantes* aux;
        aux = primerCaracter;

        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void constantesCaracter(char* cadena) {
    insertarConstanteCaracter(cadena);
}

void reporteConstantesCaracter() {
    printf("\nReporte Constantes Caracter\n\n");
    if (primerCaracter == NULL) {
        printf("\tNo se encontraron constantes caracter\n");
    } else {
        constantes* aux;
        aux = primerCaracter;
        
        while (aux != NULL) {
            printf("%s\n",aux->cadena);
            aux = aux->sig;
        }
    }
}

// LITERALES CADENA

typedef struct nodoLiteralCadena{
    char* cadena;
    int longitud;
    struct nodoLiteralCadena *sig; 
}literalCadena;

literalCadena *primerLiteralCadena = NULL;

void insertarLiteralCadena(char* cadena) {
    literalCadena *nuevo;
    nuevo = (literalCadena*)malloc(sizeof(literalCadena)); // reservo memoria con malloc
    
    nuevo->cadena = strdup(cadena);
    nuevo->longitud = strlen(cadena)-2; // strlen te da la longitud de una cadena ¿menos 2?
    nuevo->sig = NULL;

    if (primerLiteralCadena == NULL) {
        primerLiteralCadena = nuevo;
    } else {
        literalCadena* aux;
        aux = primerLiteralCadena;

        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void literalesCadena(char* cadena) {
    insertarLiteralCadena(cadena);
}

void reporteLiteralesCadena() {
    printf("\nReporte Literales cadena\n\n");
    if (primerLiteralCadena == NULL) {
        printf("\tNo se encontraron literales cadena\n");
    } else {
        literalCadena* aux; 
        aux = primerLiteralCadena; 
        while (aux != NULL) {
            printf("La cadena encontrada es %s\tY su Longitud es: %d\n",aux->cadena,aux->longitud);
            aux = aux->sig;
        }
    }
}

// PALABRAS RESERVADAS

typedef struct nodoPalabraReservada{
    char* cadena;
    char* tipo;
    struct nodoPalabraReservada *sig; 
}palabraReservada;

palabraReservada *primerPalabraReservada = NULL;

void insertarPalabraReservada(char* cadena,char* tipo){
    palabraReservada *nuevo = NULL;
    nuevo = (palabraReservada*)malloc(sizeof(palabraReservada));
    nuevo->cadena = strdup(cadena);
    nuevo->tipo = tipo;
    nuevo->sig = NULL;

    if (primerPalabraReservada == NULL) {
        primerPalabraReservada = nuevo;
    } else {
        palabraReservada* aux;
        aux = primerPalabraReservada;

        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void palabrasReservadas(char* cadena,char* tipo) {
    insertarPalabraReservada(cadena,tipo);
}

void reportePalabrasReservadas() {
    printf("\nReporte Palabras Reservadas\n\n");
    if (primerPalabraReservada == NULL) {
        printf("\tNo se encontraron palabras reservadas\n");
    } else {
        palabraReservada* aux;
        aux = primerPalabraReservada;
        
        while (aux != NULL) {
            printf("La palabra reservada es :%s\t (%s)\n",aux->cadena,aux->tipo);
            aux = aux->sig;
        }
    }
}

// IDENTIFICADORES

typedef struct nodoIdentificador{
    char* cadena;
    int cantidad;
    struct nodoIdentificador *sig;
}identificador;

identificador* punteroIdentificador = NULL;

void insertarIdentificador(char* cadena) {
    if (punteroIdentificador == NULL) {
        identificador* nuevo = NULL;
        nuevo = (identificador*)malloc(sizeof(identificador));
        nuevo->cadena = strdup(cadena);
        nuevo->cantidad = 1;
        nuevo->sig = NULL;
        punteroIdentificador = nuevo;
    } else {
        identificador* aux = punteroIdentificador;
        
        while ((strcmp(cadena,aux->cadena) != 0) && aux->sig != NULL) {
            aux = aux->sig;
        }

        if (aux->sig == NULL) {
            identificador* nuevo = NULL;
            nuevo = (identificador*)malloc(sizeof(identificador));
            nuevo->cadena = strdup(cadena);
        
            nuevo->cantidad = 1;
            nuevo->sig = NULL;
            aux->sig = nuevo;
        } else {
            aux->cantidad = aux->cantidad + 1;
        }
    }
}

void listaIdentificadores(char* cadena){
    insertarIdentificador(cadena);
}

void ordenarAlfabeticamente(identificador* listaIds) {
    if (listaIds != NULL) { //Si la lista no es vacía
        identificador *aux = NULL;
        identificador *actual = NULL;
        identificador *tmp = NULL; // Temporal para el traspaso de datos
        
        aux = listaIds; //El primero
        while( listaIds->sig != NULL ) {
            actual = aux->sig;
            while (actual != NULL) {
                if (strcmp(aux->cadena, actual->cadena) > 0) { //Si la primer cadena es mayor a la segunda (alfabeticamente)
                    tmp->cadena = aux->cadena;
                    //tmp-> cantidad = aux->cadena;
                    aux->cadena = actual->cadena;
                    aux->cantidad = actual->cantidad;
                }
                actual = actual->sig;
            }
            aux = aux->sig;
        }
        
    }
}

void reporteIdentificadores(){
    printf("\nReporte identificadores\n\n");
    identificador* aux = punteroIdentificador;
    if (punteroIdentificador == NULL)
        printf("\tNo se encontraron identificadores\n");
    ordenarAlfabeticamente(punteroIdentificador);
    while (aux != NULL) {
        printf("Identificador: %s\tCantidad de veces que aparece: %d\n",aux->cadena,aux->cantidad);
        aux = aux->sig;
    }
}



// OPERADORES Y CARACTERES DE PUNTUACION

typedef struct nodoOperador_CaracterDePuntuacion{
    char* cadena;
    int cantidad;
    struct nodoOperador_CaracterDePuntuacion *sig; 
}operadorCaracter;

operadorCaracter* punteroOperadorCaracter = NULL;

void insertarOperadorCaracterPuntc(char* cadena) {
    if (punteroOperadorCaracter == NULL) {
        
        operadorCaracter* nuevo = NULL;
        nuevo = (operadorCaracter*)malloc(sizeof(operadorCaracter));
        nuevo->cadena = strdup(cadena);
        // strdup hace malloc((strlen(cadena)+1)*sizeof(char)); y strcpy(nuevo->cadena,cadena);
        nuevo->cantidad = 1;
        nuevo->sig = NULL;
        punteroOperadorCaracter = nuevo; 
    } else {
        
        operadorCaracter* aux = punteroOperadorCaracter;
        
        while((strcmp(cadena,aux->cadena) != 0) && aux->sig != NULL){  // strcmp si devuelve 0 entonces el contenido de ambas cadenas son iguales
            // si no existe el caracter y NO estoy parado en el ultimo de la lista
            aux = aux->sig;
        }

        if (aux->sig == NULL) { // si estoy parado en el ultimo de la lista
            operadorCaracter* nuevo;
            nuevo = (operadorCaracter*)malloc(sizeof(operadorCaracter));
            nuevo->cadena = strdup(cadena);
            // strdup hace malloc((strlen(cadena)+1)*sizeof(char)); y strcpy(nuevo->cadena,cadena);
            nuevo->cantidad = 1;
            nuevo->sig = NULL;
            aux->sig = nuevo;
            
        } else { // si ya existe el caracter
            aux->cantidad = aux->cantidad +1;
        }
    }
}

void operadoresCaracteresPuntc(char* cadena) {
    insertarOperadorCaracterPuntc(cadena);
}

void reporteOperadoresCaracteresPuntc() {
    printf("\nReporte Operadores/Caracteres de Puntuacion\n\n");
    operadorCaracter *aux = punteroOperadorCaracter;
    if (punteroOperadorCaracter == NULL)
        printf("\tNo se encontraron Operadores/Caracteres de Puntuacion\n");
    while (aux != NULL) {
        printf("Operador/Caracter: %s\tCantidad de veces que aparece: %d\n",aux->cadena,aux->cantidad);
        aux = aux->sig;
    }
} 

// COMENTARIOS

typedef struct nodoComentarios{
	char* cadena;
	char* tipo;
	struct nodoComentarios* sig;		
}comentario;

comentario *primerComentario = NULL;

void insertarComentarios(char* cadena,char* tipo){
    comentario *nuevo;
    nuevo = (comentario*)malloc(sizeof(comentario));
    nuevo->cadena = strdup(cadena);
    nuevo->tipo = tipo;
    nuevo->sig = NULL;

    if(primerComentario == NULL){
        primerComentario = nuevo;
    }
    else{
        struct nodoComentarios* aux;
        aux = primerComentario;

        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void comentarios(char* cadena,char* tipo){
    insertarComentarios(cadena,tipo);
}

void reporteComentarios(){
    printf("\nReporte Comentarios\n\n");
    if(primerComentario == NULL)
        printf("\tNo se encontraron comentarios\n");
    else{
        struct nodoComentarios* aux;
        aux = primerComentario;
        while(aux != NULL){
            printf("%s\n%s\n\n",aux->tipo,aux->cadena);
            aux = aux->sig;
        }
    }
}

//  CARACTERES NO RECONOCIDOS

typedef struct nodoCarNoReconocidos{
	char* cadena;
	int linea;
	struct nodoCarNoReconocidos* sig;		
}caracterNoReconocido;

caracterNoReconocido *primerCarNoReconocido = NULL;

void insertarCarNoReconocidos(char* cadena,int linea){
    caracterNoReconocido *nuevo;
    nuevo = (caracterNoReconocido*)malloc(sizeof(caracterNoReconocido));
    nuevo->cadena = strdup(cadena);
    nuevo->linea = linea;
    nuevo->sig = NULL;

    if(primerCarNoReconocido == NULL){
        primerCarNoReconocido = nuevo;
    }
    else{
        caracterNoReconocido* aux;
        aux = primerCarNoReconocido;

        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

char cadenaNoReconocidos[100]="";

void caracNoReconocidos(char* caracterNoReconocido,int linea){
    
    // Cuando el caracter no reconocido NO es un espacio y NO es un salto de linea
    if(strcmp(caracterNoReconocido," ")!=0 && strcmp(caracterNoReconocido,"\n")!=0){ 
        strcat(cadenaNoReconocidos,caracterNoReconocido);
    }
    else{            
        if(strcmp(cadenaNoReconocidos,"")!=0){ // Cuando la cadena de no reconocidos no está vacia
            if(strcmp(caracterNoReconocido," ")==0) // Cuando el caracter no reconocido es un espacio
                insertarCarNoReconocidos(cadenaNoReconocidos,linea);
            else                                    // Cuando el caracter no reconocido es un salto de linea
                insertarCarNoReconocidos(cadenaNoReconocidos,linea-1);
            
            strcpy(cadenaNoReconocidos,"");
        }
    }
}

void reporteCaracNoReconocidos(){
    printf("\nReporte Cadenas de caracteres no reconocidos\n\n");
    if(primerCarNoReconocido == NULL)
        printf("\tNo se encontraron cadenas de caracteres no reconocidos\n\n");
    else{
        struct nodoCarNoReconocidos* aux;
        aux = primerCarNoReconocido;
        while(aux != NULL){
            printf("Cadena: %s\tlinea: %d\n",aux->cadena,aux->linea);
            aux = aux->sig;
        }
    }
}



// REPORTES

void reportes(){
    reportePalabrasReservadas();
    reporteLiteralesCadena();
    reporteConstantesDecimales();
    reporteConstantesOctales();
    reporteConstantesHexadecimales();
    reporteConstantesReales();
    reporteConstantesCaracter();
    reporteOperadoresCaracteresPuntc();
    reporteIdentificadores();
    reporteComentarios();
    reporteCaracNoReconocidos();
}
>>>>>>> cf520f1556909cfc457eed9a76a76a99a31b7d80:TP3/ListasYFuncionesTP3.h
