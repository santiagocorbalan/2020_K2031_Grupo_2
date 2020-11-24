void declararVariableSinInicializar(char* nombre,char* tipo){
    aux = ; 
    aux->tipo = tipo;
    strcpy(aux->value.valor,"");
    printf("\n\tSe declara la variable %s de tipo %s sin valor inicial\n\n",aux->name, aux->tipo);
}

typedef struct argu{
    char*  tipoArgumento;
    struct argu* sig;
} Argu;


Argu *listaArgumentosTemporal = NULL;
void agregoArgumento(char* tipoArgumentooo);

void agregoArgumento(char* tipoArgumentooo){
    
    Argu *nuevo_nodo = (Argu *)malloc(sizeof(Argu));
     nuevo_nodo->tipoArgumento = (char *) malloc (strlen (tipoArgumentooo) + 1);
     strcpy (nuevo_nodo->tipoArgumento,tipoArgumentooo);
    nuevo_nodo->sig = NULL;

    if(listaArgumentosTemporal == NULL){
        listaArgumentosTemporal  = nuevo_nodo;
    }
    else{
        Argu *aux;
        aux = listaArgumentosTemporal ;

        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo_nodo;
    }
  
}

typedef struct errorres{
	char*  cadenaDeErrores;
	struct errorres* sig;		
}Errores;

Errorres *listaErrores = NULL;


void agregarError(char* cadenaError){  
     
    Errores *nuevo_nodo = (Errores *)malloc(sizeof(Errores));
     nuevo_nodo->cadenaDeErrores = (char *) malloc (strlen (cadenaError) + 1);
     strcpy (nuevo_nodo->cadenaDeErrores,cadenaError);
    nuevo_nodo->sig = NULL;

    if(listaErrores == NULL){
        listaErrores  = nuevo_nodo;
    }
    else{
        Errores *aux;
        aux = listaErrores ;

        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo_nodo;
    }
  
}

typedef struct tabla{
    	char*  nombre;
        char*  tipo;
    struct tabla* sig;
} Tabla;


Tabla *listaSimbolos = NULL;
void agregoSimbolo(char* name , char* type);

void agregoSimbolo(char* name , char* type){
    
    Tabla *nuevo_nodo = (Tabla *)malloc(sizeof(Tabla));
     nuevo_nodo->nombre = (char *) malloc (strlen (name) + 1);
     strcpy (nuevo_nodo->nombre,name);
          nuevo_nodo->tipo = (char *) malloc (strlen (type) + 1);
     strcpy (nuevo_nodo->tipo,type);
    nuevo_nodo->sig = NULL;

    if(listaSimbolos == NULL){
        listaSimbolos  = nuevo_nodo;
    }
    else{
        Tabla *aux;
        aux = listaSimbolos ;

        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo_nodo;
    }
  
}

typedef struct tabla{
    	char*  nombre;
        char*  tipo;
    struct tabla* sig;
} Tabla;


Tabla *listaSimbolos = NULL;

Tabla *buscarSimbolo(char *name);


Tabla *buscarSimbolo(char *name)
{
    Tabla *ptr;
    for (ptr = listaSimbolos; ptr != (Tabla *) 0; ptr = (Tabla *)ptr->sig)
        if (strcmp (ptr->nombre, name) == 0 )
            return ptr;
        return 0;
}

typedef struct parametro
{
    char* tipoParam;
    struct parametro* sig;
}parametro;


typedef struct funciones{
    	char*  nombre;
        char*  tipo;
     struct parametro* lista_parametros; 
    struct funciones* sig;
} Funciones;


Funciones *listadefunciones = NULL;


void agregoFunciones(char* name , char* type);
void agregoFunciones(char* name , char* type){
    
    Funciones *nuevo_nodo = (Funciones *)malloc(sizeof(Funciones));
     nuevo_nodo->nombre = (char *) malloc (strlen (name) + 1);
     strcpy (nuevo_nodo->nombre,name);
          nuevo_nodo->tipo = (char *) malloc (strlen (type) + 1);
     strcpy (nuevo_nodo->tipo,type);
    nuevo_nodo->lista_parametros = NULL ;
    nuevo_nodo->sig = NULL;

    if(listadefunciones == NULL){
        (listadefunciones = nuevo_nodo;
    }
    else{
        Funciones *aux;
        aux = listadefunciones ;

        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo_nodo;
    }
  
}

void agregoFunciones(char* name , char* type){
    
    Funciones *nuevo_nodo = (Funciones *)malloc(sizeof(Funciones));
     nuevo_nodo->nombre = (char *) malloc (strlen (name) + 1);
     strcpy (nuevo_nodo->nombre,name);
          nuevo_nodo->tipo = (char *) malloc (strlen (type) + 1);
     strcpy (nuevo_nodo->tipo,type);
    nuevo_nodo->lista_parametros = NULL ;
    nuevo_nodo->sig = NULL;

    if(listadefunciones == NULL){
        (listadefunciones = nuevo_nodo;
    }
    else{
        Funciones *aux;
        aux = listadefunciones ;

        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo_nodo;
    }
  
}

typedef struct argu{
    char*  tipoArgumento;
    struct argu* sig;
} Argu;


Argu *listaArgumentosTemporal = NULL;
void agregoParametro(char* tipoArgumentooo);



void agregoParamtero(char* tipoArgumentooo){
    
    Argu *nuevo_nodo = (Argu *)malloc(sizeof(Argu));
     nuevo_nodo->tipoArgumento = (char *) malloc (strlen (tipoArgumentooo) + 1);
     strcpy (nuevo_nodo->tipoArgumento,tipoArgumentooo);
    nuevo_nodo->sig = NULL;

    if(listaArgumentosTemporal == NULL){
        listaArgumentosTemporal  = nuevo_nodo;
    }
    else{
        Argu *aux;
        aux = listaArgumentosTemporal ;

        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo_nodo;
    }
  
}


void declararVariableConElIgual(char * nombre1,char* tipo,char * nombre2){
    auxiliar = getsym(nombre2,TYP_VAR);
 
    if(auxiliar && mismoTipo(tipo, auxiliar->tipo)){

        aux = putsym(strdup(nombre1),TYP_VAR);
        strcpy(aux->value.valor,aux2->value.valor);
        aux->tipo = tipo;  
        printf("Se declara la variable %s de tipo %s con valor inicial %s\n", aux->name, aux->tipo, aux->value.valor);
    }
    if(auxiliar && !mismoTipo(tipo, auxiliar->tipo))
    {
        agregarError("Error Semantico: en control de tipos de datos en la asignacion");
    }
    if(auxiliar = NULL){

        agregarError("no existe la variable que quiere asignarse" );
    }
    
};



int mismoTipo(char* tipo, char* tipo2){
    
    if(strcmp(tipo,tipo2) == 0)
        return 1;
    else 
        return 0;
};



void declararVariable(char* nombre,char* tipo,char* valor){
    
    aux = putsym(strdup(nombre),TYP_VAR);
    aux->tipo = tipo;
    strcpy(aux->value.valor,valor);
    printf("\n\tSe declara la variable %s de tipo %s con valor inicial %s\n\n",aux->name, aux->tipo, aux->value.valor);
}



void verificarParametros(Simbolo* unaFuncion, Funcion* unaListaDeParam) {
    Funcion* parametros = aux->lista_parametros;

    if(cantidadDeParametros(parametros) != cantidadDeParametros(unaListaDeParam)){

agregarError("La cantidad de parametros ingresados no coinciden en la funcion");

  
    } 
    else
        for(Funcion* aux = parametros; aux != NULL; aux = aux -> sig){
            if(strcmp(unaListaDeParam -> tipoDatoParam, aux -> tipoDatoParam)){
               agregarError("El tipo de dato de los argumentos ingresados no coinciden con los esperados por la funcion");

                break;
            }   
            unaListaDeParam = unaListaDeParam -> sig;
        }
        
}