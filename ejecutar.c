#include "minishell.h"
#include "parser.h"
#include "ejecutar.h"
#include "libmemoria.h"


pid_t ejecutar_orden (const char *orden, int *pbackgr)
{
   char **args;
   pid_t pid;
   int indice_entrada;
   int indice_salida;
  
   if ((args=parser_orden(orden,&indice_entrada,&indice_salida,pbackgr))== NULL)
   {
     return(-1);
   }

   /* si la orden tiene redirecciones o tuberias, puede incluir aqui, fuera del */
   /* ambito de esta practica, el codigo para tratamiento de esas redirecciones.*/                     

	pid = fork();/*Crea el proceso hijo*/
	if (pid!=0){/*Esto es el padre, ya que el pid 0 corresponde al hijo*/
		/*printf("soy el padre\n");*//*comprobación*/
	}
	else{/*Esto es el Hijo, ya que el pid de este es 0*/
		execvp(args[0], args);
	}
	free_argumentos(args);
	return pid;
}
 
void ejecutar_linea_ordenes(const char *orden)
{
	pid_t pid;
	int backgr;

	/* si la orden es compuesta, puede incluir aqui, fuera del ambito*/
	/* de esta practica, el codigo para tratamiento de tuberias.     */
      


	pid = ejecutar_orden(orden,&backgr);
	if (backgr!=0) {
		waitpid(pid,&backgr,WNOHANG);
		printf("Se está ejecutando en segundo plano, puede continuar usando la minishell mientras.\n");
	}
	else{
		wait(&backgr);
		printf("El Hijo ha terminado\n");
	}
	return;
}
