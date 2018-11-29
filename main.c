#include "header.h"

int main(int cantArgs, char *args[]){

	if(cantArgs != 3)
	{
		fprintf(stderr, "%s\n", "ERROR: Two arguments expected.");
		exit(EXIT_FAILURE);
	}	

	FILE *file1 = fopen(args[1], "r+t");
	FILE *file2 = fopen(args[2], "r+t");

	if(errno != 0)
	{
		fprintf(stderr, " ERROR %s: %s\n", file1 == NULL ? args[1] : args[2], strerror(errno));
		exit(EXIT_FAILURE);
	}

	FILE *moves;
	FILE *airports;
	char firstWord[10];

	fscanf(file1, "%[^;]", firstWord);

	printf("%s\n", firstWord);


	return 0;
}