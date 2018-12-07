#include "TAD.h"

//dias de la semana y tipos de vuelos (cabotaje o internacional)
enum DAYS {SUN = 0, MON, TUE, WED, THU, FRI, SAT};
enum FLIGHTTYPE {CAB = 0, INTER};

typedef struct Tmove
{
	size_t cab;
	size_t inter;
	size_t total;
}Tmove;

typedef struct Tcomp
{
	size_t Reg;
	size_t noReg;
	size_t priv;
}Tcomp;

typedef struct Tnode
{
	struct Tnode * prev;
	char oaci[5];
	char * denom;
	size_t total;
	struct Tnode * next;
}Tnode;

typedef struct dataCDT
{
	struct Tnode * first;
	struct Tmove movDays[7];
	struct Tcomp movComp[2];

}dataCDT;

typedef Tnode * Pnode;

dataADT new(){

	return calloc(1,sizeof(dataCDT));
}

/*Devuelve que dia de la semana es una fecha donde 0 es domingo. 
el formato de la fecha es dd/mm/yyyy.
(algoritmo de sakamoto)*/
static int dayWeek(const char *date){

	int day = atoi(date);
	int month = atoi(date+3);
	int year = atoi(date+6);

	int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
   	year -= month < 3;
   
   	return (year + year/4 - year/100 + year/400 + t[month-1] + day) % 7;
}

void MoveByDay(dataADT l, const char *date, const char *flightType){

	if(flightType[0] != 'N') //que la clasif sea distinta de N/A
	{
		int day = dayWeek(date);
		
		if(flightType[0] == 'C') //si es de cabotaje
			l->movDays[day].cab++;
		else
			l->movDays[day].inter++;

		l->movDays[day].total++;
	}
}


void composition(const char * flightType, const char * flightClass, dataADT l){

	if(flightType[0] != 'N') //chequea que la clasif no sea N/A
	{
		if(flightType[0] == 'C') //si el vuelo es de Cabotaje
		{
			if (flightClass[0] == 'R') //si es Regular
				l->movComp[CAB].Reg++;

			else if (flightClass[0] == 'N') //si es No Regular
				l->movComp[CAB].noReg++;

			else //Vuelo Privado
				l->movComp[CAB].priv++;
		}
		else
		{
			if (flightClass[0] == 'R')
				l->movComp[INTER].Reg++;

			else if (flightClass[0] == 'N')
				l->movComp[INTER].noReg++;
			
			else
				l->movComp[INTER].priv++;
		}
	}
}

void addAirport(dataADT l, const char * oaci, const char * denom){

	Pnode aux = calloc(1, sizeof(Tnode));

	if(errno != 0)
		error(errno, strerror(errno));

	strcpy(aux->oaci, oaci);

	aux->denom = malloc(strlen(denom) + 1);

	if(errno != 0)
		error(errno, strerror(errno));

	strcpy(aux->denom, denom);

	if(l->first != NULL)
	{
		l->first->prev = aux;
		aux->next = l->first;
	}

	l->first = aux;
}


static Pnode addCantR(Pnode n, const char * oaci)
{
	if(n == NULL){
		return n;
	}

	if(strcmp(oaci, n->oaci) != 0)
	{	
		n->next = addCantR(n->next, oaci);
		int c;		
		Pnode aux = n->next;
		
		if(aux != NULL && (((c = aux->total - n->total) > 0) || (c == 0 && strcmp(aux->oaci, n->oaci) < 0)))
		{

			aux->prev = n->prev;
			n->next = aux->next;
			n->prev = aux;
			aux->next = n;
			
			return aux;
		}
		
		return n;
	}
	
	n->total++;
	
	return n;
}

void addCant(dataADT l, const char * oaci){

	char s[5];

	if(sscanf(oaci, "SA%2[0-9]",s) != 1 && sscanf(oaci, "AR-%[0-9]",s) != 1)
		l->first = addCantR(l->first, oaci);
}


/*Obtiene la información relevante de los campos Origen o Destino del archivo
de Movimientos*/
static void getOriDest(FILE *moves, dataADT l, char *origen){

	int i, c, flag = 0;

	for(i = 0 ; i < 4 && !flag ; i++)
	{
		origen[i] = fgetc(moves);

		if(origen[i] == ';')
			flag = 1;
	}

	origen[i] = '\0';

	if(!flag && (c = fgetc(moves)) == ';')
		addCant(l, origen);

	else if(!flag && c != ';')
		fscanf(moves, "%*[^;];");

}

void getData(dataADT l, FILE *airports, FILE *moves){

	char oaci[5], denom[71], fecha[11], claseVuelo[2], clasifVuelo[2], tipoMov[2], origen[5], destino[5];

	fscanf(airports, "%*[^\n]\n"); //saltea la primer linea

	while(feof(airports) == 0)
	{
		fscanf(airports, "%*[^;];%[^;];%*[^;];%*[^;];%[^;];%*[^\n]\n", oaci, denom);

		if(strcmp(oaci, " ") != 0)
			addAirport(l, oaci, denom);
	}

	fscanf(moves, "%*[^\n]\n");

	while(feof(moves) == 0)
	{
		fscanf(moves, "%10[^;];%*[^;];%1s%*[^;];%1s%*[^;];%1s%*[^;];", fecha, claseVuelo, clasifVuelo, tipoMov);

		if(tipoMov[0] == 'D') //checkea si el tipo de movimiento es un despegue o aterrizaje
			getOriDest(moves, l, origen);
		else
		{
			fscanf(moves, "%*[^;];");
			getOriDest(moves, l, destino);
		}

		fscanf(moves, "%*[^\n]\n");

		MoveByDay(l, fecha, clasifVuelo);
		composition(clasifVuelo, claseVuelo, l);
	}
}

static void printMBARec(Pnode node, FILE *fp){

	if(node != NULL && node->total != 0)
	{
		fprintf(fp, "%s;%s;%ld\n", node->oaci, node->denom, node->total);

		printMBARec(node->next, fp);
	}
}

void printMovesbyAirports(const char *dir, dataADT l){

	FILE *fp = fopen(dir, "wt");

	fprintf(fp, "%s;%s;%s\n", "OACI", "Denominación", "Movimientos");

	printMBARec(l->first, fp);

	fclose(fp);
}

void printMovesbyDay(const char *dir, dataADT l){

	FILE *fp = fopen(dir, "wt");

	char *days[] = {"Domingo", "Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado"};

	int i;

	fprintf(fp, "%s;%s;%s;%s\n", "Día", "Cabotaje", "Internacional", "Total");

	for(i = SUN; i <= SAT ; i++)
		fprintf(fp, "%s;%ld;%ld;%ld\n", days[i], l->movDays[i].cab, l->movDays[i].inter, l->movDays[i].total);

	fclose(fp);
}

void printCompMoves(const char *dir, dataADT l){

	FILE *fp = fopen(dir, "wt");

	int i;

	char *clasif[] = {"Cabotaje", "Internacional"};

	fprintf(fp, "%s;%s;%s;%s\n", "Clasificación de Vuelo", "Regular", "No Regular", "Vuelo Privado");

	for(i = CAB; i <= INTER ; i++)
		fprintf(fp, "%s;%ld;%ld;%ld\n", clasif[i], l->movComp[i].Reg, l->movComp[i].noReg, l->movComp[i].priv);

	fclose(fp);

}

void freeList(dataADT l){

	Pnode curr=l->first;
	Pnode aux;

	while (curr != NULL) {
		aux = curr->next;
		free(curr->denom);
		free(curr);
		curr = aux;
	}

	free(l);
}