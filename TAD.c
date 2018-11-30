#include "header.h"

enum DAYS {SUN = 0, MON, TUE, WED, THU, FRI, SAT};

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
	char * oaci;
	char * denom;
	int cantMoves;
	struct Tnode * nextAlpha;
	struct Tnode * nextMoves;

}Tnode;

typedef struct DataCDT
{
	struct Tnode * firstMove;
	struct Tnode * firstAlpha;

	struct Tmove movDays[7];
	struct Tcomp movComp[2];

}DataCDT;

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

	int day = dayWeek(date);

	if(strcmp(flightType, "Cabotaje") == 0)
		l->movDays[day].cab++;
	else
		l->movDays[day].inter++;

	l->movDays[day].total++;
}


/*q3*/

void agregamov(char * ClasificVuelo, char * clasVuelo, DataADT data){
	if(!strcmp(ClasificVuelo, "Cabotaje")){
		if (!strcmp(clasVuelo, "Regular"))
			data->movComp->Reg++;
		else if (!strcmp(clasVuelo, "No Regular"))
			data->movComp->noReg++;
		else
			data->movComp->priv++;
	}
	else{
		if (!strcmp(clasVuelo == "Regular"))
			data->movComp[1]->Reg++;
		else if (!strcmp(clasVuelo, "No Regular"))
			data->movComp[1]->noReg++;
		else
			data->movComp[1]->priv++;
	}
}



int main(void)
{
	
}