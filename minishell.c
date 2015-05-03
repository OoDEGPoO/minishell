#include "minishell.h"
#include "internas.h"
#include "ejecutar.h"
#include <string.h>
#include <stdbool.h>



int main (int argc, char *argv[])
{

   char buf[BUFSIZ];
   char *cadena; /*string para almacenar las ordenes introducidas*/
   bool continuar = true; /*Booleano para cuando se introduzca exit terminar la ejecución*/
   int salida;

   while (continuar)
   {
   	imprimir_prompt(); /*Imprime el prompt*/
	leer_linea_ordenes(buf); /*lee la linea de ordena untroducida*/
	cadena = strtok(buf, ";"); /*almacena las ordenes separadas en tokens*/
	//printf("%s\n", cadena); /*para probar que se ha almacenado de forma adecuada "cadena"*/

	//while (cadena != NULL){ //cuando se acaban las ordenes termina
		if ((strcmp(cadena,"exit"))!=0){ //compara la primera orden con "exit"
			if ((ord_interna(cadena))==0){
				/*si la orden es interna da 1 y la ejecuta, si es externa entra al if*/
				//printf("es externa\n"); /*para comprobar que la orden es externa*/
				ejecutar_linea_ordenes(cadena);
			}
			//cadena = strtok(NULL, ";"); //pasamos al siguiente tokens y portanto la siguiente orden
			salida = main(argc, argv);
			if (salida == 0) continuar = false;
		}
		else {
			continuar = false;
			salida = 0;
		}
	//}
   }

   return salida;
}


