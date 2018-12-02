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

	#include "getnum.h"

	typedef struct dataCDT *dataADT;

	__attribute__((used)) static void error(int errorCode, const char * s) {

		fprintf(stderr, "\nERROR: %s.\n", s);
		exit(errorCode);
	}

	dataADT new(void);

	void MoveByDay(dataADT l, const char *date, const char *flightType);

	void agregamov(const char * ClasificVuelo, const char * clasVuelo, dataADT data);

	dataADT addAirport(dataADT head, const char * s1, const char * s2);

	void addCant(dataADT head, const char * s1);

	void addMove(const char *string, dataADT info);

	void getData(dataADT info, FILE *airports, FILE *moves,int option);

	char * printMovesbyDay(dataADT l);

	char * printCompMoves(dataADT l);

	char * printMovesbyAirports(dataADT l);

	void freeList(dataADT data);

#endif