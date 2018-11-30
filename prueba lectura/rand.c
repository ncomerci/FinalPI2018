#include <stdlib.h>
#include <stdio.h>

int
randEntre(int izq, int der){

	return rand() % (der - izq + 1) + izq;

}

void
Getline(char *s, int dim){

	int c, i;

	do
	{
		i = 0;

		while((c = getchar()) != '\n')
		{
			if(i < dim-1)
				s[i] = c;

			i++;
		}

		if(i <= dim-1)
			s[i] = '\0';

		if(i >= dim)
			printf("Error en la cantidad de datos, ingrese nuevamente.\n");
	}
	while(i >= dim);
}