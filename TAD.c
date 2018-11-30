#include "header.h"

enum DAYS {SUN = 0, MON, TUE, WED, THU, FRI, SAT};
enum FLIGHTTYPE {CAB = 0, INTER};

typedef struct Tmove
{
	int cab;
	int inter;
	int total;
}Tmove;

typedef struct Tcomp
{
	int Reg;
	int noReg;
	int priv;
}Tcomp;

typedef struct Tnode
{
	char oaci[5];
	int total;
	struct Tnode * next;
	struct Tnode * prev;
	char * denom;
}Tnode;

typedef struct dataCDT
{
	struct Tnode * first;
	struct Tnode * last;
	struct Tnode * index;
	struct Tmove movDays[7];
	struct Tcomp movComp[2];

}dataCDT;

typedef Tnode * Pnode;
dataADT new(){
	dataADT aux=calloc(1,sizeof(dataCDT));
	return aux;
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

void MoveByDay(DataADT l, const char *date, const char *flightType){

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
DataADT addAirport(DataADT head, char * s1, char * s2){

	Pnode aux = calloc(1, sizeof(Tnode));
	strcpy(aux->oaci, s1);	
	aux->denom = malloc(strlen(s2) + 1);
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

static Pnode addCantR(Pnode n, const char * s1, DataADT head)
{
	if(n == NULL){
		return n;
	}

	if(strcmp(s1, n->oaci) != 0)
	{	
		n->next = addCantR(n->next, s1, head);
		int c;		
		Pnode aux = n->next;
		
		if((aux!=NULL) && (((c = aux->total - n->total) > 0)||(c == 0 && strcmp(s1, n->oaci) < 0)))
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

void addCant(DataADT head, char * s1)
{
	head->first = addCantR(head->first,s1,head);
}
void getR(Pnode n){
	if(n->next==NULL){
		if(n->total!=0){
		printf("%s;%s;%d\n",n->oaci,n->denom,n->total);
		}
	}
	else{
		if(n->total!=0){
			printf("%s;%s;%d\n",n->oaci,n->denom,n->total);
		}
		getR(n->next);
	}
}

void getAll(dataADT head){
	printf("Oaci;Denominacion;Total\n");
	getR(head->first);
	printf("Dia;Cabotaje;Internacional;Total\n");
	int i;
	char * v1[7]={"SUNDAY","MONDAY","TUESDAY","WEDNESDAY","THURSDAY","FRIDAY","SATURDAY"};
	char * v2[2]={"Cabotaje","Internacional"};
	for(i=SUN;i<=SAT;i++){
		printf("%s;%d;%d;%d\n",v1[i],head->movDays[i].cab,head->movDays[i].inter,head->movDays[i].total);
	}
	printf("Tipo;REGULAR;NO REGULAR;PRIVADO\n");

	for(i=0;i<2;i++){
		printf("%s;%d;%d;%d\n",v2[i],head->movComp[i].Reg,head->movComp[i].noReg,head->movComp[i].priv);
	}
}

void
skipLine(FILE *fp){

   int c;

   do
   {
      c = fgetc(fp);
   }
   while(c != '\n' && c != EOF);

}

void printMovesbyDay(DataADT l, FILE *dia_semana){

	char *days[] = {"Domingo", "Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado"};

	int i;

	fprintf(dia_semana, "%s;%s;%s;%s\n", "Día", "Cabotaje", "Internacional", "Total");

	for(i = SUN; i <= SAT ; i++)
		fprintf(dia_semana, "%s;%d;%d;%d\n", days[i], l->movDays[i].cab, l->movDays[i].inter, l->movDays[i].total);
}


int main(void)
{
	
}
