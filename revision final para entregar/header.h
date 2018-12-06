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
//Recibe la lista del censo de los aeropuertos, la fecha del movimiento y el tipo de vuelo realizado en esa fecha,y agrega un movimiento al correspondiente tipo de vuelo a la lista dada.
	void MoveByDay(dataADT l, const char *date, const char *flightType);

//Recibe la clasificacion del vuelo, la clase de vuelo, y el header de la lista del censo de los aeropuertos. Agrega a la lista dada un movimiento a la combinacion "clasificacion de Vuelo - clase vuelo" correspondiente.
	void agregamov(const char * ClasificVuelo, const char * clasVuelo, dataADT data);
  
 //Agrega a la lista un aeropuerto, donde tiene el oaci y su denominación.
	void addAirport(dataADT head, const char * s1, const char * s2);

//Agrega al aeropuerto
	void addCant(dataADT head, const char * s1);

	void addMove(const char *string, dataADT info);

	void getData(dataADT info, FILE *airports, FILE *moves);

	char * printMovesbyDay(dataADT l);

	char * printCompMoves(dataADT l);

	char * printMovesbyAirports(dataADT l);

	void freeList(dataADT data);

#endif