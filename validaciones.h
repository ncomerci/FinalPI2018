#ifndef _VALIDACIONES_H_

	#define _VALIDACIONES_H_

	#include <stdio.h>

	#include <stdlib.h>

	#include <string.h>

		
		/* Funcion:  		checkFiles

 * Parámetros:
 *				moves: Archivo de movimientos.
 *				airports: Archivo de aeropuertos

 * -------------------------------------------------------------------

 * Ejemplo:  	        int flag = checkFiles(moves, airports);

 * -------------------------------------------------------------------

 * Descripción: 	
 *				 Corrobora los archivos ingresados tengan el formato esperado
 *				 y devuelve 1 si es así o 0 si no.

 * -------------------------------------------------------------------
 */

	int checkFiles(FILE *moves, FILE *airports);



	/* Funcion:  		getOption

 * Parámetros:
 *				Ninguno.

 * -------------------------------------------------------------------

 * Ejemplo:  	        int opt = getOption();

 * -------------------------------------------------------------------

 * Descripción: 	
 *				 Lee de entrada estandar un número entero ingresado
 * 				 y lo devuelve en su nombre.

 * -------------------------------------------------------------------
 */

	int getOption(void);



	/* Funcion:  		Confirmation

 * Parámetros:
 *				msg: Mensaje a mostrar en pantalla.

 * -------------------------------------------------------------------

 * Ejemplo:  	        int flag = Confirmation("Salir? (s/n)\n");

 * -------------------------------------------------------------------

 * Descripción: 	
 *				 Lee de entrada estandar las letras 's', 'S', 'n' o 'N'.
 *				 Devuelve 1 si leyó 's' o 'S'.
 *				 Devuelve 0 si leyó 'n' o 'N'.

 * -------------------------------------------------------------------
 */
	
	int Confirmation(const char * msg);

#endif