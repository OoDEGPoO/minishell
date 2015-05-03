#include "minishell.h"
#include "internas.h"
#include "ejecutar.h"
#include <string.h>
#include <stdbool.h>



int main (int argc, char *argv[])
{

   char buf[BUFSIZ];
   char *cadena; /*string para almacenar las ordenes introducidas*/

   while (1)
   {
   	imprimir_prompt(); /*Imprime el prompt*/
	leer_linea_ordenes(buf); /*lee la linea de ordena untroducida*/
	cadena = strtok(buf, ";"); /*almacena las ordenes separadas en tokens*/
	//printf("%s\n", cadena); /*para probar que se ha almacenado de forma adecuada "cadena"*/

	while (cadena != NULL){ //cuando se acaban las ordenes termina
		if ((strcmp(cadena,"exit"))!=0){ //compara la primera orden con "exit"
			if ((ord_interna(cadena))==0){
				/*si la orden es interna da 1 y la ejecuta, si es externa entra al if*/
				//printf("es externa\n"); /*para comprobar que la orden es externa*/
				ejecutar_linea_ordenes(cadena);
			}
		}
		else {
			return 0;
		}
		cadena = strtok(NULL, ";"); //pasamos al siguiente tokens y portanto la siguiente orden
	}
	fflush(stdin);
   }

   return 0;
}


