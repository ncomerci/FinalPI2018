#include "header.h"

#define OPTIONS 3 //cantidad de opciones con funciones propias para relizar queries

typedef struct itemMenu {

	char *messege;
	char * (*fn) (dataADT l);

}itemMenu;

static itemMenu items[OPTIONS] = {{"Movimientos por aeropuerto", printMovesbyAirports}, {"Movimientos por día de la semana", printMovesbyDay}, {"Composición de Movimientos", printCompMoves}};

int checkFiles(FILE *moves, FILE *airports);
void Menu(dataADT info, FILE *moves, FILE *airports);

int
main(int cantArgs, char *args[]){

	if(cantArgs != 3)
		error(EXIT_FAILURE, "Two arguments expected");

	FILE *file1 = fopen(args[1], "rt");
	FILE *file2 = fopen(args[2], "rt");

	if(errno != 0)
		error(errno, strerror(errno));

	FILE *moves;
	FILE *airports;
//se fija cuál es el archivo de movimientos y cual el de aeropuertos.
	if(checkFiles(file1, file2))
	{
		moves = file1;
		airports = file2;
	}
	else if(checkFiles(file2, file1))
	{
		moves = file2;
		airports = file1;
	}
	else
	{
		fclose(file1);
		fclose(file2);
		error(EXIT_FAILURE, "Wrong file");
	}

	printf("\n=======================================================\n\tTRABAJO FINAL PROG. IMP. DICIEMBRE 2018\n=======================================================\n");
	printf("\nINTEGRANTES:\n\n*Lucía Torrusio\t\tLegajo: 59489\n*Tamara Puig\t\tLegajo: 59820\n*Nicolás Comerci\tLegajo: 59520\n");

	dataADT info = new();

	Menu(info, moves, airports);
	
	freeList(info);
	fclose(moves);
	fclose(airports);

	return 0;
}

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

void Menu(dataADT info, FILE *moves, FILE *airports){

	int i, opt, resp, load = 0;

	do
	{
		do
		{
			printf("\nESCOJA UNA OPCIÓN:\n\n");

			for(i=0 ; i < OPTIONS ; i++)
				printf("%d) %s\n", i+1, items[i].messege);

			printf("%d) Realizar todo lo anterior\n%d) Salir\n", i+1, i+2);

			opt = getchar() - '0';
			putchar("\n");
		}
		while(opt < 1 || opt > OPTIONS+2);

		if(opt == OPTIONS+2)			
			return;

		if( !load )
		{
			printf("Cargando...\n");
			getData(info, airports, moves);
			load = 1;
		}

		if(opt == OPTIONS+1)
		{
			for(i = 0 ; i < OPTIONS ; i++)
				printf("%s creado.\n", items[i].fn (info));
		}
		else
		{
			printf("%s creado.\n", items[opt-1].fn (info));
			resp = yesNo("Desea realizar otra acción? (S/N)\n");
		}
	}
	while(opt != OPTIONS+1 && resp);
}