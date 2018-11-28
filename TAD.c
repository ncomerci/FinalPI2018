#include "header.h"

enum DAYS {MON = 0, TUE, WED, THU, FRI, SAT, SUN};

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


