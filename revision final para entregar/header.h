//sacar los include que no hayamos usado cuando terminemos el tp

#ifndef _HEADER_H_

	#define _HEADER_H_

	#include <stdio.h>

	#include <stdlib.h>

	#include <ctype.h>

	#include <math.h>

	#include <string.h>

	#include <time.h>

	#include <errno.h>

	typedef struct dataCDT *dataADT;

	__attribute__((used)) static void error(int errorCode, const char *s) {

		fprintf(stderr, "\nERROR: %s.\n\n", s);
		exit(errorCode);
	}

	dataADT new(void);
	/* Funcion:  		MoveByDay

 * Uso:  	        MoveByDay(head, "11/12/2018","cabotaje");

 * -------------------------------------------------------------------

 * Descripción: 	
 *				Agrega un movimiento al 
 *			    correspondiente tipo de vuelo a la lista dada.

 * -------------------------------------------------------------------

 */

void MoveByDay(dataADT l, const char *date, const char *flightType);


	/* Funcion:  		agregamov

 * Uso:  	        agregamov("cabotaje","internacional", data);

 * -------------------------------------------------------------------

 * Descripción: 	
 *				Agrega a la lista dada un movimiento a la combinacion 
 *		        "clasificacion de Vuelo - clase vuelo" correspondiente.

 * -------------------------------------------------------------------

 */

	void agregamov(const char * ClasificVuelo, const char * clasVuelo, dataADT data);



	/* Funcion:  		addAirport

 * Uso:  	        void addAirport(head, "SAZS", "aeropuerto ezeiza");

 * -------------------------------------------------------------------

 * Descripción: 	
 *				 Agrega a la lista un aeropuerto, donde tiene el oaci y su denominación.

 * -------------------------------------------------------------------
 */
  

	void addAirport(dataADT head, const char * s1, const char * s2);


	/* Funcion:  		addCant

 * Uso:  	        void addCant(head, "SAZA");

 * -------------------------------------------------------------------

 * Descripción: 	
 *				 Agrega al aeropuerto correspondiente según su oaci, 
 *				un movimiento realizado. Debe existir previamente el
 *				aeropuerto en el registro.

 * -------------------------------------------------------------------
 */
  

	void addCant(dataADT head, const char * s1);


	void addMove(const char *string, dataADT info);

	
	

	/* Funcion:  		addCant

 * Uso:  	        void addCant(head, "SAZA");

 * -------------------------------------------------------------------

 * Descripción: 	
 *				 Agrega al aeropuerto correspondiente según su oaci, 
 *				un movimiento realizado. Debe existir previamente el
 *				aeropuerto en el registro.

 * -------------------------------------------------------------------
 */
	void getData(dataADT info, FILE *airports, FILE *moves);


	

	/* Funcion:  		printMovesbyDay

 * Uso:  	        char * printMovesbyDay(dataADT l);

 * -------------------------------------------------------------------

 * Descripción: 	
 *				 Imprime en un archivo, el día de la semana,
 *				la cantidad de movimientos de cabotaje para ese día, 
 *				la cantidad de movimientos internacionales para ese día 
 *				y la suma de ambos movimientos.

 * -------------------------------------------------------------------
 */	
	char * printMovesbyDay(dataADT l);


	

	/* Funcion:  		printCompMoves

 * Uso:  	        char * printCompMoves(dataADT l);

 * -------------------------------------------------------------------

 * Descripción: 	
 *				 Imprime en un archivo los movimientos realizados por
 *				 el total de movimientos por Clasificación de Vuelo 
 *				(con las categorías Cabotaje e Internacional) y por 
 *				 Clase de Vuelo (con las categorías Regular, 
 *				 No Regular y Vuelo Privado)..

 * -------------------------------------------------------------------
 */		char * printCompMoves(dataADT l);




	/* Funcion:  		printMovesbyAirports

 * Uso:  	        char * printMovesbyAirports(dataADT l);

 * -------------------------------------------------------------------

 * Descripción: 	
 *				 Imprime en un archivo los movimientos que realizaron 
 *				los aeropuertos presentes en el registro. El orden de 
 *				impresión es descendente por movimientos y luego 
 *				alfabéticamente por código OACI.

 * -------------------------------------------------------------------
 */	
	char * printMovesbyAirports(dataADT l);

	


	/* Funcion:  		freeList

 * Uso:  	        void freeList(data);

 * -------------------------------------------------------------------

 * Descripción: 	
 *				 Libera el espacio.

 * -------------------------------------------------------------------
 */
	void freeList(dataADT data);

#endif