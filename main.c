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


	return 0;
}