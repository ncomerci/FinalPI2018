#include "header.h"

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
	char oaci[5];
	size_t total;
	struct Tnode * next;
	struct Tnode * prev;
	char * denom;
}Tnode;

typedef struct dataCDT
{
	struct Tnode * first;
	struct Tnode * last;
	struct Tmove movDays[7];
	struct Tcomp movComp[2];

}dataCDT;

typedef Tnode * Pnode;

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

dataADT new(){

	return calloc(1,sizeof(dataCDT));
}

void MoveByDay(dataADT l, const char *date, const char *flightType){

	int day;

	if(flightType[0] != 'N') //que la clasif sea distinta de N/A
	{
		day = dayWeek(date);
		
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
dataADT addAirport(dataADT head, const char * s1, const char * s2){

	Pnode aux = calloc(1, sizeof(Tnode));

	if(errno != 0)
		error(errno, strerror(errno));

	strcpy(aux->oaci, s1);

	aux->denom = malloc(strlen(s2) + 1);

	if(errno != 0)
		error(errno, strerror(errno));

	strcpy(aux->denom, s2);

	if(head->last != NULL)
	{
		aux->prev = head->last;
		head->last->next = aux;
	}

	head->last = aux;
	
	if(head->first == NULL)
		head->first=head->last;

	return head;
}

static Pnode addCantR(Pnode n, const char * s1, dataADT head)
{
	if(n == NULL){
		return n;
	}

	if(strcmp(s1, n->oaci) != 0)
	{	
		n->next = addCantR(n->next, s1, head);
		int c;		
		Pnode aux = n->next;
		
		if(aux != NULL && (((c = aux->total - n->total) > 0) || (c == 0 && strcmp(aux->oaci, n->oaci) < 0)))
		{
			if(aux->next == NULL)
				head->last = n;
			
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

void addCant(dataADT head, const char * s1)
{
	head->first = addCantR(head->first,s1,head);
}

//en string recibe orgien o destino
void addMove(const char *string, dataADT info){

	char s[5];

	if(sscanf(string,"SA%[0-9]",s) != 1 && sscanf(string,"AR-%[0-9]", s) != 1)
		addCant(info, string);
}

void getData(dataADT info, FILE *airports, FILE *moves){

	char oaci[5], denom[71], fecha[11], claseVuelo[2], clasifVuelo[2], origen[8], destino[8];

	fscanf(airports, "%*[^\n]\n");

	while(feof(airports) == 0)
	{
		fscanf(airports, "%*[^;];%[^;];%*[^;];%*[^;];%[^;];%*[^\n]\n", oaci, denom);

		if(strcmp(oaci, " ") != 0)
			info = addAirport(info, oaci, denom);
	}

	fscanf(moves, "%*[^\n]\n");

	while(feof(moves) == 0)
	{
		fscanf(moves, "%[^;];%*[^;];%1s%*[^;];%1s%*[^;];%*[^;];%[^;];%[^;];%*[^\n]\n", fecha, claseVuelo, clasifVuelo, origen, destino);

		addMove(origen, info);
		addMove(destino, info);

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

	char *filedir = "./movimientos_aeropuerto.csv";

	FILE *fp = fopen(filedir, "wt");

	fprintf(fp, "%s;%s;%s\n", "OACI", "Denominación", "Movimientos");

	printMBARec(l->first, fp);

	fclose(fp);

	return filedir;
}

char * printMovesbyDay(dataADT l){

	char *filedir = "./dia_semana.csv";

	FILE *fp = fopen(filedir, "wt");

	char *days[] = {"Domingo", "Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado"};

	int i;

	fprintf(fp, "%s;%s;%s;%s\n", "Día", "Cabotaje", "Internacional", "Total");

	for(i = SUN; i <= SAT ; i++)
		fprintf(fp, "%s;%ld;%ld;%ld\n", days[i], l->movDays[i].cab, l->movDays[i].inter, l->movDays[i].total);

	fclose(fp);

	return filedir;
}

char * printCompMoves(dataADT l){

	char *filedir = "./composicion.csv";

	FILE *fp = fopen(filedir, "wt");

	int i;

	char *clasif[] = {"Cabotaje", "Internacional"};

	fprintf(fp, "%s;%s;%s;%s\n", "Clasificación de Vuelo", "Regular", "No Regular", "Vuelo Privado");

	for(i = CAB; i <= INTER ; i++)
		fprintf(fp, "%s;%ld;%ld;%ld\n", clasif[i], l->movComp[i].Reg, l->movComp[i].noReg, l->movComp[i].priv);

	fclose(fp);

	return filedir;
}

void freeList(dataADT data){

	Pnode curr=data->first;
	Pnode aux;

	while (curr != NULL) {
		aux = curr->next;
		free(curr);
		curr = aux;
	}

	free(data);
}