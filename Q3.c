#include "header.h"
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

typedef struct Tcomp
{
	int Reg;
	int noReg;
	int priv;
}Tcomp;

typedef struct DataCDT
{
	struct Tnode * firstMove;
	struct Tnode * firstAlpha;

	struct Tmove movDays[7];
	struct Tcomp movComp[2];

}DataCDT;

struct DataCDT * DataADT;

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
		if (!strcmp(clasVuelo == 'Regular'))
			data->movComp[1]->Reg++;
		else if (!strcmp(clasVuelo, "No Regular"))
			data->movComp[1]->noReg++;
		else
			data->movComp[1]->priv++;
	}
}

	