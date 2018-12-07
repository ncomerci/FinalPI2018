//sacar los include que no hayamos usado cuando terminemos el tp

#ifndef _HEADER_H_

	#define _HEADER_H_

	#include <stdio.h>

	#include <stdlib.h>

	#include <string.h>

	#include <errno.h>

	typedef struct dataCDT *dataADT;

	__attribute__((used)) static void error(int errorCode, const char *s) {

		fprintf(stderr, "\nERROR: %s.\n\n", s);
		exit(errorCode);
	}

		/* Funcion:  		new

 * Uso:  	        head=new();

 * -------------------------------------------------------------------

 * Descripción: 	
 *				Crea un nuevo header.

 * -------------------------------------------------------------------

 */
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

 * Uso:  	        addAirport(head, "SAZS", "aeropuerto ezeiza");

 * -------------------------------------------------------------------

 * Descripción: 	
 *				 Agrega a la lista un aeropuerto, donde tiene el oaci y su denominación.

 * -------------------------------------------------------------------
 */
  

	void addAirport(dataADT head, const char * oaci, const char * denom);


	/* Funcion:  		addCant

 * Uso:  	         addCant(head, "SAZA");

 * -------------------------------------------------------------------

 * Descripción: 	
 *				 Agrega al aeropuerto correspondiente según su oaci, 
 *				un movimiento realizado. Debe existir previamente el
 *				aeropuerto en el registro.

 * -------------------------------------------------------------------
 */
  		void addCant(dataADT head, const char * oaci);



/* Funcion:  		addMove

 * Uso:  	        addMove(string,info);

 * -------------------------------------------------------------------

 * Descripción: 	
 *				Corrobora los datos antes de llamar a la función
 *				addCant y pasarle los datos necesarios para su ejecución,
 *				controlando si se trata de un despeje o aterrizaje y
 *				agregando al aeropuerto correspondiente según su oaci un
 *				movimiento.

 * -------------------------------------------------------------------

 */
	
	void addMove(const char *string, dataADT info);

	
	

	/* Funcion:  		getData

 * Uso:  	        getData(info,airports, moves);


 * -------------------------------------------------------------------

 * Descripción: 
 *				Obtiene la información relevante de los dos 
 *				archivos recibidos.

 * -------------------------------------------------------------------
 */
	void getData(dataADT info, FILE *airports, FILE *moves);


	

	/* Funcion:  		printMovesbyDay

 * Uso:  	        s1=printMovesbyDay(dataADT l);

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

 * Uso:  	        s2=printCompMoves(dataADT l);

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

 * Uso:  	        s3=printMovesbyAirports(dataADT l);

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

 * Uso:  	        freeList(data);

 * -------------------------------------------------------------------

 * Descripción: 	
 *				 Libera el espacio.

 * -------------------------------------------------------------------
 */
	void freeList(dataADT data);

#endif