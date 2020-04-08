
/*
===============================================================================
 Name        : tp_v1.3.c
 Author      : M Gerez
 Version     : 1.3
 Copyright   : $(copyright)
 Description : Apertura y lectura de las palabras generadas en el csv
===============================================================================
*/
#include <stdio.h>

#define CANTW	1000 // es la cantidad de palabras que leerá el array
#define LONGW	10 // la max longitud de caracteres que admitira la cadena

void DespliegaArreglo(const char a[][LONGW]); //Todavia nada

//int AbrirArchivo( FILE *b); // Hacer modular 
void DespliegaMenu(void);

int main()
{ 
   char array[CANTW][LONGW]; /*auxiliar*/
   char c; /*aux*/	   
   int consulta; /*aux para el menu de seleccion*/
   int i=0;
   int j=0;
   FILE *ptrCf;     /* ptrCf = apuntador al archivo dato_de_entrada.csv */

   /* fopen abre el archivo; si no se puede abrir el archivo, abandona el programa */ 
   if ( ( ptrCf = fopen( "dato_de_entrada.csv", "r" ) ) == NULL ) {
      printf( "El archivo no pudo abrirse\n" );
   } /* fin de if */
   else { 
   
   /* Seleccion de operaci�n */ 	
   	DespliegaMenu();
   	
   	scanf("%d",&consulta);
	while(consulta != 6)
	{
			
		switch(consulta)
		{
			
			/*Despliega todo el txt */
			case 0:
				      /* mientras no sea fin de archivo */
				      printf("\t\tLista Completa\n\n");
				      while ( !feof( ptrCf ) ) 
					  	{ 
				      		c=fgetc(ptrCf);
				      		printf("%c",c);
 				    	} /* fin de while */
			break;
			
			/*Muestro solo los enteros*/
			// case 1:
			// 			printf("Lista las palabras del array sin la coma");
			// 			while ( !feof( ptrCf ) ) { 
			// 			c=fgetc(ptrCf);
			// 			 while (c!=',')
			// 			  	{
			// 			  		c=fgetc(ptrCf);
			// 			  		array[i][j] = c ;
			// 			  		j++;
						  		
			// 				} /* fin de while */
			// 				  i++;		  
			// 	   			} /* fin de while */
 			// 	     		DespliegaArreglo(array);
			// break;
			
						
		}/* fin del switch*/		
		rewind(ptrCf);
		printf("\n?");
		scanf("%d",&consulta);
	}	/* fin de while */	
	
	  printf("Fin de la ejecucion.\n");
      fclose( ptrCf ); /* fclose cierra el archivo */
   } /* fin de else */

   return 0; /* indica terminaci�n exitosa */

} /*cierro main*/

// void DespliegaArreglo(const char a[][LONGW]){
	
// 	int i,j;
	
// 	printf("entre a Despliega Arreglo\n");
// 	for(i=0;i<CANTW;i++){
	
// 		for(j=0;j<LONGW;j++)
// 			printf("array[%d][%d] = %c",i,j,a[i][j]);
// 	}
// 		printf("\n");
// }
void DespliegaMenu(void ){
	
	 	  printf ("\t\tIntroduzca la consulta\n\n"
		 		"0)\tListar todas las palabras del archivo\n"
		 		"1)\tGuardar palabras en array  \n"
		 		"2)\tListar solo las palabras enteras\n"
		 		"3)\tListar solo las palabras octales\n"
		 		"4)\tListar solo las palabras hexadecimales\n"
		 		"5)\tListar palabras no reconocidas\n"
		 		"6)\tGenerar archivo de salida\n"
		 		"7)\tFin del programa\n? " );
   	  
			return;
}
