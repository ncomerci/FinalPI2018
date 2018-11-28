//PRIMERO SE HACE TODA LA LISTA DE AEROPUERTOS CON EL PRIMER CSV Y SE INICIALIZAN EN 0, DESPUES SE CONTROLAN LOS VUELOS Y SE SUMA A CANT
//Y SE VAN ORDENANDO. 
//*Como en el de mov solo estan los que tienen OACI, desde el de aeropuertos,¿guardamos los que no tengan? PERDIDA DE MEMORIA
//¿puedo asumir que en aerop no hay repetidos? SINO, CAMBIO UN POCO ADD
/*#include <stdio.h>
#include "getnum.h"
#include <string.h>
#include <stdlib.h>*/
#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include "getnum.h"

typedef struct Tnode
{
	char oaci[3]; //es 5
	int total;
	struct Tnode * next;
	struct Tnode * prev;

}Tnode;

typedef Tnode * Pnode;

typedef struct dataCDT
{
	Pnode first;
	Pnode last;
	Pnode index; 		//¿ESTO SE BORRA?
	int cant; 			//ESTO SE BORRA;
}dataCDT;
typedef dataCDT * dataADT;
Pnode AddR(Pnode n,char * s1);
dataADT add(dataADT head, char * s1);
//dataADT New();
char * getO(dataADT head,int * f);
dataADT addCant(dataADT head,char * s1);
Pnode addCantR(Pnode n,char * s1,dataADT head);

dataADT New(){
	dataADT new=calloc(1,sizeof(dataCDT));
	return new;
}
/*int compAlpha(char * s1,char * s2){  //POR AHI CONVIENE USARLO DIRECTO;
	return strcmp(s1,s2)
}*/
Pnode AddR(Pnode n,char * s1){
	Pnode aux=calloc(1,sizeof(Tnode));
	aux->next=NULL;
	strcpy(aux->oaci,s1);
	if(n!=NULL){
	aux->prev=n;
	n->next=aux;
	}
return aux;
}

dataADT add(dataADT head, char * s1){
	head->last=AddR(head->last,s1);
	head->cant++;
	if(head->first==NULL)
		head->first=head->last;
	return head;
}

char * getO(dataADT head,int * f){
	char * aux=malloc(3);
	if(head->index==NULL)
		head->index=head->first;
	strcpy(aux,head->index->oaci);
	*f=head->index->total;
	head->index=head->index->next;
	
return aux;
}
Pnode addCantR(Pnode n,char * s1,dataADT head){
	if(n==NULL){
		return n;
	}
	if(strcmp(s1,n->oaci)!=0){
		n->next=addCantR(n->next,s1,head);
		int c;
		Pnode aux=n->next;
		if((c=aux->total-n->total)>0||(c==0 && (c=strcmp(s1,n->oaci))<0)){
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


int main(void){
	dataADT head;
	head=New();
	head=add(head,"SZ");
	head=add(head,"TR");
	head=add(head,"AA");
	head=add(head,"MT");
	head=add(head,"BV");
	head=add(head,"CS");
	head=add(head,"CC");
	head=add(head,"AX");
	head=add(head,"SR");
	head=add(head,"TA");
	head=add(head,"MI");
	head=add(head,"PU");
	head=add(head,"IG");
	head=add(head,"IN");
	head=add(head,"RE");
	head=add(head,"EL");
	head=add(head,"PR");
	head=add(head,"MR");

	head=addCant(head,"SZ");
	head=addCant(head,"TR");
	head=addCant(head,"AA");
	head=addCant(head,"MT");
	head=addCant(head,"BV");
	head=addCant(head,"MT");
	head=addCant(head,"BV");
	
	int i,f;
	for(i=0;i<head->cant;i++){
		char s[3];
		strcpy(s,getO(head,&f));
		if(f!=0)
			printf("%s %d\n",s,f);
	}

}