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

#endif

typedef struct dataCDT *dataADT;

dataADT new();

void MoveByDay(dataADT l, const char *date, const char *flightType);

void agregamov(const char * ClasificVuelo, const char * clasVuelo, dataADT data);

dataADT addAirport(dataADT head, char * s1, char * s2);

void addCant(dataADT head, char * s1);

void gq1(dataADT head,FILE * q1);

void gq2(dataADT head,FILE * q2);

void gq3(dataADT head,FILE * q3);
/*agrega en el header los movimientos por dias. Recibe información válida*/

