
void
freeList( dataADT data)
{
	Pnode curr=data->first;
	Pnode aux;
	Pmove aux2;
	Pcomp aux3;

	while (curr != NULL) {
		aux = curr->next;
		free(curr);
		curr = aux;
	}
	for (int i = 0; i < 7; i++)
	{
		aux2=data->movDays[i];
		free(aux);
	}
	for (i = 0; i < 2; i++)
	{
		aux3=data->movComp[i];
		free(aux);
	}


	free(data->movComp);
	free(data->movDays);
	free(data);
}

