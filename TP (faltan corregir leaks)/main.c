#include "header.h"

#define OPTIONS 3

typedef struct itemMenu {

	char *messege;
	char * (*fn) (dataADT l);

}itemMenu;

typedef struct tMenu {

	int totalOptions;
	itemMenu *items;
	
}tMenu;

static itemMenu items[OPTIONS] = {{"Movimientos por aeropuerto", printMovesbyAirports}, {"Movimientos por día de la semana", printMovesbyDay}, {"Composición de Movimientos", printCompMoves}};
static tMenu ppalMenu = {OPTIONS, items};

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

	printf("\n=======================================================\n\tTRABAJO FINAL PROG. IMP. DICIEMBRE 2018\n=======================================================\n");
	printf("\nINTEGRANTES:\n\n*Lucía Torrusio\t\tLegajo: 59489\n*Tamara Puig\t\tLegajo: 59820\n*Nicolás Comerci\tLegajo: 59520\n");

	dataADT info = new();

	Menu(info, moves, airports);

	fclose(moves);
	fclose(airports);

	return 0;
}

void Menu(dataADT info, FILE *moves, FILE *airports){

	int i, opt, resp, load = 0;

	do
	{
		do
		{
			printf("\nESCOJA UNA OPCIÓN:\n\n");

			for(i=0 ; i < ppalMenu.totalOptions ; i++)
				printf("%d) %s\n", i+1, ppalMenu.items[i].messege);

			printf("%d) Realizar todo lo anterior\n%d) Salir\n", i+1, i+2);

			opt = getint("\n");
		}
		while(opt < 1 || opt > ppalMenu.totalOptions+2);

		if(opt == ppalMenu.totalOptions+2)
		{
			freeList(info);
			return;
		}

		if( !load )
		{
			getData(info, airports, moves,opt);
			load = 1;
		}

		if(opt == ppalMenu.totalOptions+1)
		{
			for(i = 0 ; i < ppalMenu.totalOptions ; i++)
				printf("%s created.\n", ppalMenu.items[i].fn (info));
		}
		else
			printf("%s created.\n", ppalMenu.items[opt-1].fn (info));

		resp = yesNo("Desea realizar otra acción? (S/N)\n");

	}
	while(resp);

	freeList(info);
}