#ifndef _HEADER_H_

	#define _HEADER_H_

	#include <stdio.h>

	#include <stdlib.h>

	#include <string.h>

	#include <errno.h>

	typedef struct dataCDT *dataADT;

	/* Recibe un código de error y mensaje.
	Muestra el mensaje de error y termina la ejecución del programa 
	devolviendo el código ingresado como parámetro.
	*/
	__attribute__((used)) static void error(int errorCode, const char *s) {

		fprintf(stderr, "\nERROR: %s.\n\n", s);
		exit(errorCode);
	}

		/* Funcion:  		new

 * Ejemplo:  	        head=new();

 * -------------------------------------------------------------------

 * Descripción: 	
 *				Crea una nueva lista.

 * -------------------------------------------------------------------

 */
	dataADT new(void);
	

	/* Funcion:  		MoveByDay

 * Parámetros:
 *				l: Lista utilizada.
 *				date: fecha del movimiento en formato dd/mm/yyyy.
 *				flightType: Clasificación de vuelo (Cabotaje, Internacional o N/A).

 * -------------------------------------------------------------------

 * Ejemplo:  	        MoveByDay(head, "11/12/2018","cabotaje");

 * -------------------------------------------------------------------

 * Descripción: 	
 *				Si la clasificación no es N/A agrega un movimiento, 
 *				en el día de la fecha, al correspondiente tipo de 
 *				vuelo a la lista dada.

 * -------------------------------------------------------------------

 */

	void MoveByDay(dataADT l, const char *date, const char *flightType);


	/* Funcion:  		composition

 * Parámetros:
 *				flightType: Clasificación de vuelo (Cabotaje, Internacional o N/A).
 *				flightClass: Clase de vuelo (Regular, No regular o Vuelo privado).
 *				l: Lista utilizada.

 * -------------------------------------------------------------------

 * Ejemplo:  	        composition("cabotaje","Regular", l);

 * -------------------------------------------------------------------

 * Descripción: 	
 *				Si la clasificación no es N/A, agrega a la lista dada 
 *		        un movimiento a la combinación 
 *				"clasificacion de Vuelo - clase vuelo" correspondiente.

 * -------------------------------------------------------------------

 */

	void composition(const char * flightType, const char * flightClass, dataADT l);



	/* Funcion:  		addAirport

 * Parámetros:
 *				l: Lista utilizada.
 *				oaci: OACI del aeropuerto.
 *				denom: Denominación del aeropuerto.

 * -------------------------------------------------------------------

 * Ejemplo:  	        addAirport(l, "SAEZ", "EZEIZA/MINISTRO PISTARINI");

 * -------------------------------------------------------------------

 * Descripción: 	
 *				 Agrega a la lista un aeropuerto con su oaci y 
 *				 denominación correspondiente.

 * -------------------------------------------------------------------
 */
  

	void addAirport(dataADT l, const char * oaci, const char * denom);


	/* Funcion:  		addCant

 * Parámetros:
 *				l: Lista utilizada.
 *				oaci: OACI del aeropuerto.

 * -------------------------------------------------------------------

 * Ejemplo:  	         addCant(l, "SAZA");

 * -------------------------------------------------------------------

 * Descripción: 	
 *				Si el OACI es válido, agrega al aeropuerto correspondiente 
 *				un movimiento realizado. Debe existir previamente el 
 *				aeropuerto en el registro.

 * -------------------------------------------------------------------
 */

	void addCant(dataADT l, const char * oaci);


	/* Funcion:  		getData

 * Parámetros:
 *				l: Lista utilizada.
 *				airports: Archivo de aeropuertos.
 *				moves: Archivo de movimientos.

 * -------------------------------------------------------------------

 * Ejemplo:  	        getData(l, airports, moves);


 * -------------------------------------------------------------------

 * Descripción: 
 *				Obtiene la información relevante de los archivos 
 *				recibidos y la transfiere a la lista dada.

 * -------------------------------------------------------------------
 */
	void getData(dataADT l, FILE *airports, FILE *moves);


	

	/* Funcion:  		printMovesbyDay

 * Parámetros:
 *				dir: Directorio del archivo a crear.
 *				l: Lista utilizada.

 * -------------------------------------------------------------------

 * Ejemplo:  	        printMovesbyDay("./dia_semana.csv", l);

 * -------------------------------------------------------------------

 * Descripción: 	
 *				Crea un archivo en directorio indicado e imprime en él, 
 *				en el día de la semana, la cantidad de movimientos de
 *				cabotaje para ese día, la cantidad de movimientos 
 *				internacionales para ese día y la suma de ambos.

 * -------------------------------------------------------------------
 */	
	void printMovesbyDay(const char *dir, dataADT l);


	

	/* Funcion:  		printCompMoves

 * Parámetros:
 *				dir: Directorio del archivo a crear.
 *				l: Lista utilizada.

 * -------------------------------------------------------------------

 * Ejemplo:  	        printCompMoves("./composicion.csv", l);

 * -------------------------------------------------------------------

 * Descripción: 	
 *				 Crea un archivo en directorio indicado e imprime en él 
 *				 los movimientos realizados por Clasificación de Vuelo 
 *				 (con las categorías Cabotaje e Internacional) y por 
 *				 Clase de Vuelo (con las categorías Regular, 
 *				 No Regular y Vuelo Privado).

 * -------------------------------------------------------------------
 */		

	void printCompMoves(const char *dir, dataADT l);




	/* Funcion:  		printMovesbyAirports

 * Parámetros:
 *				dir: Directorio del archivo a crear.
 *				l: Lista utilizada.

 * -------------------------------------------------------------------

 * Ejemplo:  	        printMovesbyAirports("./movimientos_aeropuerto.csv", info);

 * -------------------------------------------------------------------

 * Descripción: 	
 *				Crea un archivo en directorio indicado e imprime en él 
 *				los movimientos que realizaron los aeropuertos presentes 
 *				en el registro. El orden de impresión es descendente por 
 *				movimientos y luego alfabéticamente por código OACI.

 * -------------------------------------------------------------------
 */	
	void printMovesbyAirports(const char *dir, dataADT l);

	


	/* Funcion:  		freeList

 * Parámetros:
 *				l: Lista utilizada.

 * -------------------------------------------------------------------

 * Ejemplo:  	        freeList(l);

 * -------------------------------------------------------------------

 * Descripción: 	
 *				 Libera la memoria utilizada en la lista.

 * -------------------------------------------------------------------
 */
	void freeList(dataADT l);

#endif