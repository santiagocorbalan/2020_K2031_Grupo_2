
#include <stdio.h>
#include <stdlib.h>


int tipos (char a);

int main(){


	    int matriz[7][5]={
					  {2,1,1,6,6},
                      {1,1,1,6,6},
                      {5,5,6,3,6},
                      {4,4,4,6,4},
                      {4,4,4,6,4},
                      {5,5,6,6,6},
                      {6,6,6,6,6}
					  };


	  FILE* entrada=fopen("entrada.txt","rt");
    FILE* salida=fopen("salida.txt","wt");

    int columna=0;
    int estadoActual = 0;
    int estadoFinal = 0;
    char caracter ;
    caracter = getc(entrada);
    while(!feof(entrada))
            {
              if (caracter!=',')

			  	{
			       putc(caracter, salida);
                   columna = tipos(caracter);
                   estadoActual = matriz[estadoActual][columna];
		      	}

              if (caracter == ',')
			  	{
			       estadoFinal = estadoActual ;
                   estadoActual = 0;
                   switch(estadoFinal)

				   	{

                        case 1:  fputs(" -> Decimal\n", salida);break;

                        case 4:  fputs(" -> Hexadecimal\n", salida);break;

                        case 5:  fputs(" -> Octal\n", salida);break;

						default: fputs(" -> No Reconocido\n", salida);

                   	}
		      	}
		       	       caracter = getc(entrada);
            }

    fclose(entrada);
    fclose(salida);

	return 0;
}


int tipos (char a)
{
    int col = 0;
    switch(a)

    {

      case '0': col=0; break;

      case '1'...'7': col=1; break;

      case '8'...'9': col=2; break;

      case 'x': case 'X': col=3; break;

      case 'a'...'f': case 'A'...'F': col=4; break;

      default: col=5;

    }
    return col;
}
