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

movCompo(){
	
}
