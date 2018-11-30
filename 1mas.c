#include "header.h"

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
	dataADT head=new();

	char oaci[5], denom[71], fecha[11], claseVuelo[14], clasifVuelo[14], origen[5], destino[5],s[5];

	//printf("\n================ AIRPORTS ================\n");

	skipLine(airports);

	//printf("\nOACI - DENOMINACIÓN\n\n");
	int cant=0;
	while(feof(airports) == 0)
	{
		fscanf(airports, "%*[^;];%[^;];%*[^;];%*[^;];%[^;]", oaci, denom);
		skipLine(airports);

		if(strcmp(oaci, " ") != 0){
			head=addAirport(head,oaci,denom);
		}
			//printf("%s - %s\n", oaci, denom); ACA CHAU				
	}

	//printf("\n================ MOVES ================\n");

	skipLine(moves);

	//printf("\nFECHA - CLASE - CLASIF - ORIGEN - DESTINO\n\n");

	while(feof(moves) == 0)
	{
		fscanf(moves, "%[^;];%*[^;];%13[^;]", fecha, claseVuelo);
		
		if(strlen(claseVuelo) == 13)
			fscanf(moves, "%*[^;];%[^;];%*[^;];%[^;];%[^;]", clasifVuelo, origen, destino);
		else
			fscanf(moves, ";%[^;];%*[^;];%[^;];%[^;]", clasifVuelo, origen, destino);

		skipLine(moves);

		//printf("%s - %s - %s - %s - %s\n", fecha, claseVuelo, clasifVuelo, origen, destino);
		if(1!=sscanf(origen,"SA%[0-9]",s) && 1!=sscanf(origen,"AR-%[0-9]",s)){
			addCant(head,origen);
		}

		if(1!=sscanf(destino,"SA%[0-9]",s) && 1!=sscanf(destino,"AR-%[0-9]",s)){
			addCant(head,destino);
		}
		MoveByDay(head,fecha,clasifVuelo);
		agregamov(clasifVuelo,claseVuelo,head);
	}
	getAll(head);
	fclose(moves);
	fclose(airports);
	return 0;
}