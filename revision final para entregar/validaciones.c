#include "validaciones.h"

#define CLEAN_BUFFER while (getchar() != '\n')

int checkFiles(FILE *moves, FILE *airports){

	char fecha[6], local[6];
	
	fscanf(moves, "%5[^;];", fecha);
	fscanf(airports, "%5[^;];", local);
	
	fseek(moves, 0, SEEK_SET);
	fseek(airports, 0, SEEK_SET);

	if(strcmp(fecha, "Fecha") == 0 && strcmp(local, "local") == 0)
		return 1;

	return 0;
}

int getOption(void){

	int aux, resp;

	do
	{
		aux = fscanf(stdin, "%d", &resp);

		if(aux != 1)
		{
			printf("\nIngrese un número.\n\n");
			CLEAN_BUFFER;
		}
	}
	while(aux != 1);

	CLEAN_BUFFER;

	return resp;
}

int Confirmation(const char * msg){

	int c, flag = 1;

	do
	{
		printf("%s", msg);

		c = getchar();

		if(strchr("sSnN", c) == NULL)
		{
			printf("\nIngrese 'S' para si o 'N' para no.\n");

			if(c != '\n')
				CLEAN_BUFFER;
		}
		else
			flag = 0;

	}
	while(flag);

	CLEAN_BUFFER;

	return c == 's' || c == 'S';
}