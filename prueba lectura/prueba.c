
	#include <stdio.h>

	#include <stdlib.h>

	#include <ctype.h>

	#include <math.h>

	#include <string.h>

	#include <time.h>

	#include "getnum.h"

#include <errno.h>

void
skipLine(FILE *fp){

	int c;

	do
	{
		c = fgetc(fp);
	}
	while(c != '\n' && c != EOF);

}

int
main(int cantArgs, char *args[])
{
	if(cantArgs != 3)
	{
		fprintf(stderr, "ERROR: %s\n", "Two arguments expected.");
		exit(EXIT_FAILURE);
	}	

	FILE *file1 = fopen(args[1], "rt");
	FILE *file2 = fopen(args[2], "rt");

	if(errno != 0)
	{
		fprintf(stderr, "ERROR: %s %s\n", file1 == NULL ? args[1] : args[2], strerror(errno));
		exit(errno);
	}

	FILE *moves;
	FILE *airports;
	char firstWord[6];

	fscanf(file1, "%[^;]", firstWord);

	if(strcmp(firstWord, "Fecha") == 0)
	{
		moves = file1;
		airports = file2;
	}
	else
	{
		moves = file2;
		airports = file1;
	}

	char oaci[5], denom[71], fecha[11], claseVuelo[39], clasifVuelo[14], origen[5], destino[5];

	printf("\n================ AIRPORTS ================\n");

	skipLine(airports);

	printf("\nOACI - DENOMINACIÓN\n\n");

	while(feof(airports) == 0)
	{
		fscanf(airports, "%*[^;];%[^;];%*[^;];%*[^;];%[^;]", oaci, denom);
		skipLine(airports);

		if(strcmp(oaci, " ") != 0)
			printf("%s - %s\n", oaci, denom);
	}

	printf("\n================ MOVES ================\n");

	skipLine(moves);

	printf("\nFECHA - CLASE - CLASIF - ORIGEN - DESTINO\n\n");

	while(feof(moves) == 0)
	{
		fscanf(moves, "%[^;];%*[^;];%[^;];%[^;];%*[^;];%[^;];%[^;]", fecha, claseVuelo, clasifVuelo, origen, destino);
		fscanf(moves, "%[^;];%*[^;];%13[^;]", fecha, claseVuelo);
		
		if(claseVuelo[0] == 'V')
			fscanf(moves, "%*[^;];%[^;];%*[^;];%[^;];%[^;]", clasifVuelo, origen, destino);
		else
			fscanf(moves, ";%[^;];%*[^;];%[^;];%[^;]", clasifVuelo, origen, destino);

		skipLine(moves);

		printf("%s - %s - %s - %s - %s\n", fecha, claseVuelo, clasifVuelo, origen, destino);
	}

	return 0;
}