#include "header.h"

int main(int cantArgs, char *args[]){

	if(cantArgs != 3)
	{
		fprintf(stderr, "ERROR: %s\n", "Two arguments expected.");
		exit(EXIT_FAILURE);
	}	

	FILE *file1 = fopen(args[1], "r+t");
	FILE *file2 = fopen(args[2], "r+t");

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
	

	char *datos[6];
	char line[MAXCHAR +1];
	while(!feof(moves)){
		fegets(line, MAXCHAR+1, moves);
		lineToStrings(datos,line);
		agregamov(datos[2], datos[1], l);
		MoveByDay(l,datos[0], datos[2]);
	}



	return 0;
}

void lineToStrings(char **datos, char* string){
	int k=0;
	char * Spointer;
	Spointer=strtok(string, ";");
	for (int i = 0; i < 7; ++i)
	{
		if(i!=1 && i!=4)
			datos[k++]=Spointer;
		Spointer=strtok(NULL, ";");
	}

}

