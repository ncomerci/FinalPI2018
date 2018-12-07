#include "header.h"

enum DAYS {SUN = 0, MON, TUE, WED, THU, FRI, SAT};
enum FLIGHTTYPE {CAB = 0, INTER};

//directorios a guardar los archivos correspondientes
#define MBADIR "./movimientos_aeropuerto.csv"
#define MBDDIR "./dia_semana.csv"
#define CMDIR "./composicion.csv"

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

/*dice que dia de la semana es una fecha.
el formato de la fecha es dd/mm/yyyy
algoritmo de sakamoto*/
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


/*q3*/

void agregamov(const char * ClasificVuelo, const char * clasVuelo, dataADT data){

	if(ClasificVuelo[0] != 'N') //chequea que la clasif no sea N/A
	{
		if(ClasificVuelo[0] == 'C') //si el vuelo es de Cabotaje
		{
			if (clasVuelo[0] == 'R') //si es Regular
				data->movComp[CAB].Reg++;

			else if (clasVuelo[0] == 'N') //si es No Regular
				data->movComp[CAB].noReg++;

			else //Vuelo Privado
				data->movComp[CAB].priv++;
		}
		else
		{
			if (clasVuelo[0] == 'R')
				data->movComp[INTER].Reg++;

			else if (clasVuelo[0] == 'N')
				data->movComp[INTER].noReg++;
			
			else
				data->movComp[INTER].priv++;
		}
	}
}

/*Q1*/
void addAirport(dataADT head, const char * oaci, const char * denom){

	Pnode aux = calloc(1, sizeof(Tnode));

	if(errno != 0)
		error(errno, strerror(errno));

	strcpy(aux->oaci, oaci);

	aux->denom = malloc(strlen(denom) + 1);

	if(errno != 0)
		error(errno, strerror(errno));

	strcpy(aux->denom, denom);

	if(head->first != NULL)
	{
		head->first->prev = aux;
		aux->next = head->first;
	}

	head->first = aux;
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

void addCant(dataADT head, const char * oaci)
{
	head->first = addCantR(head->first, oaci);
}

//en string recibe orgien o destino
void addMove(const char *string, dataADT info){

	char s[5];

	if(sscanf(string, "SA%2[0-9]",s) != 1 && sscanf(string, "AR-%[0-9]",s) != 1)
		addCant(info, string);

}

//solo recibe origen o destino
static void getOriDest(FILE *moves, dataADT info, char *origen){

	int i, c, flag = 0;

	for(i = 0 ; i < 4 && !flag ; i++)
	{
		origen[i] = fgetc(moves);

		if(origen[i] == ';')
			flag = 1;
	}

	origen[i] = '\0';

	if(!flag && (c = fgetc(moves)) == ';')
		addMove(origen, info);

	else if(!flag && c != ';')
		fscanf(moves, "%*[^;];");

}

void getData(dataADT info, FILE *airports, FILE *moves){

	char oaci[5], denom[71], fecha[11], claseVuelo[2], clasifVuelo[2], tipoMov[2], origen[5], destino[5];

	fscanf(airports, "%*[^\n]\n");

	while(feof(airports) == 0)
	{
		fscanf(airports, "%*[^;];%[^;];%*[^;];%*[^;];%[^;];%*[^\n]\n", oaci, denom);

		if(strcmp(oaci, " ") != 0)
			addAirport(info, oaci, denom);
	}

	fscanf(moves, "%*[^\n]\n");

	while(feof(moves) == 0)
	{
		fscanf(moves, "%10[^;];%*[^;];%1s%*[^;];%1s%*[^;];%1s%*[^;];", fecha, claseVuelo, clasifVuelo, tipoMov);

		if(tipoMov[0] == 'D')
			getOriDest(moves, info, origen);
		else
		{
			fscanf(moves, "%*[^;];");
			getOriDest(moves, info, destino);
		}

		fscanf(moves, "%*[^\n]\n");

		MoveByDay(info, fecha, clasifVuelo);
		agregamov(clasifVuelo, claseVuelo, info);
	}
}

static void printMBARec(Pnode node, FILE *fp){

	if(node != NULL && node->total != 0)
	{
		fprintf(fp, "%s;%s;%ld\n", node->oaci, node->denom, node->total);

		printMBARec(node->next, fp);
	}
}

char * printMovesbyAirports(dataADT l){

	FILE *fp = fopen(MBADIR, "wt");

	fprintf(fp, "%s;%s;%s\n", "OACI", "Denominación", "Movimientos");

	printMBARec(l->first, fp);

	fclose(fp);

	return MBADIR;
}

char * printMovesbyDay(dataADT l){

	FILE *fp = fopen(MBDDIR, "wt");

	char *days[] = {"Domingo", "Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado"};

	int i;

	fprintf(fp, "%s;%s;%s;%s\n", "Día", "Cabotaje", "Internacional", "Total");

	for(i = SUN; i <= SAT ; i++)
		fprintf(fp, "%s;%ld;%ld;%ld\n", days[i], l->movDays[i].cab, l->movDays[i].inter, l->movDays[i].total);

	fclose(fp);

	return MBDDIR;
}

char * printCompMoves(dataADT l){

	FILE *fp = fopen(CMDIR, "wt");

	int i;

	char *clasif[] = {"Cabotaje", "Internacional"};

	fprintf(fp, "%s;%s;%s;%s\n", "Clasificación de Vuelo", "Regular", "No Regular", "Vuelo Privado");

	for(i = CAB; i <= INTER ; i++)
		fprintf(fp, "%s;%ld;%ld;%ld\n", clasif[i], l->movComp[i].Reg, l->movComp[i].noReg, l->movComp[i].priv);

	fclose(fp);

	return CMDIR;
}

void freeList(dataADT data){

	Pnode curr=data->first;
	Pnode aux;

	while (curr != NULL) {
		aux = curr->next;
		free(curr->denom);
		free(curr);
		curr = aux;
	}

	free(data);
}