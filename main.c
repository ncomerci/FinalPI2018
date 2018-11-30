#include "header.h"

int main(int cantArgs, char *args[]){

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

	return 0;
}