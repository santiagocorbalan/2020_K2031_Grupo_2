#ifndef TP5_H
#define TP5_H


typedef struct parametro{
    char*  tipoParametro;
    struct parametro* sig;
} Parametro;


typedef struct symrec {
  char *nombre;
  int type;         
  char *tipo;  
  struct parametro* tiposParametros;    
  union
        {
         int      valEnt; 
         double   valReal;
         char     valChar;
         char*    valString;
        } value;
  struct symrec *next; 
} symrec;


extern symrec *sym_table;


symrec *agregoSimbolo (char const *,char const *, int);


symrec *buscoSimbolo (char const *);

void agregarErrorSintactico();

void mostrarErrorSintactico();

void agregarErrorSemantico();

void mostrarErrorSemantico();

#endif

