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
	char oaci[5];
	int total;
	struct Tnode * next;
	struct Tnode * prev;
	char * denom;
}Tnode;

typedef struct DataCDT
{
	struct Tnode * first;
	struct Tnode * last;
	struct Tnode * index;
	struct Tmove movDays[7];
	struct Tcomp movComp[2];

}DataCDT;

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

void MoveByDay(dataADT l, const char *date, const char *flightType){

	int day = dayWeek(date);

	if(strcmp(flightType, "Cabotaje") == 0)
		l->movDays[day].cab++;
	else
		l->movDays[day].inter++;

	l->movDays[day].total++;
}


/*q3*/

void agregamov(const char * ClasificVuelo, const char * clasVuelo, DataADT data){
	if(strcmp(ClasificVuelo, "Cabotaje") == 0){
		if (strcmp(clasVuelo, "Regular") == 0)
			data->movComp->Reg++; //movComp es un vector, faltaria el indice? (nico)
		else if (strcmp(clasVuelo, "No Regular") == 0)
			data->movComp->noReg++; //movComp es un vector, faltaria el indice? (nico)
		else
			data->movComp->priv++;
	}
	else{
		if (strcmp(clasVuelo == "Regular") == 0)
			data->movComp[1].Reg++;
		else if (strcmp(clasVuelo, "No Regular") == 0)
			data->movComp[1].noReg++;
		else
			data->movComp[1].priv++;
	}
}

/*Q1*/
Pnode AddR(Pnode n,char * s1,char * s2){
	Pnode aux=calloc(1,sizeof(Tnode));
	strcpy(aux->oaci,s1);	
	aux->denom=malloc(strlen(s2)+1);
	strcpy(aux->denom,s2);
	if(n!=NULL){
	aux->prev=n;
	n->next=aux;
	}
return aux;
}

dataADT add(dataADT head, char * s1,char * s2){
	head->last=AddR(head->last,s1,s2);
	if(head->first==NULL)
		head->first=head->last;
	return head;
}

Pnode addCantR(Pnode n,char * s1,dataADT head){
	if(n==NULL){
		return n;
	}
	if(strcmp(s1,n->oaci)!=0){
		n->next=addCantR(n->next,s1,head);
		int c;
		Pnode aux=n->next;
		if((aux!=NULL && (c=aux->total-n->total)>0)||(c==0 && (c=strcmp(s1,n->oaci))<0)){
			if(aux->next==NULL)
				head->last=n;
			aux->prev=n->prev;
			n->next=aux->next;
			n->prev=aux;
			aux->next=n;
			return aux;
		}
		return n;
	}
	n->total++;
	return n;

}

dataADT addCant(dataADT head,char * s1){
	head->first=addCantR(head->first,s1,head);
	return head;
}

void
skipLine(FILE *fp){

   int c;

   do
   {
      c = fgetc(fp);
      pos++;
   }
   while(c != '\n' && c != EOF);

}


int main(void)
{
	
}