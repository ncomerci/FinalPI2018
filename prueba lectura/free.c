
void
freeList( listADT list)
{
	Pnode curr=list->first;
	Pnode aux;
	Pmove aux2;
	Pcomp aux3;

	while (curr != NULL) {
		aux = curr->tail;
		free(curr);
		curr = aux;
	}
	for (int i = 0; i < 7; i++)
	{
		aux2=list->movDays[i];
		free(aux);
	}
	for (i = 0; i < 2; i++)
	{
		aux3=list->movComp[i];
		free(aux);
	}


	free(list->movComp);
	free(list->movDays);
	free(list);
}

