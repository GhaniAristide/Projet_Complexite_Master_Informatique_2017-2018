void maximum (graph g, ens_sommet *e)
{
	int i, j, n, ok, ref, temp, max;
	ens_sommet *p,*q;

	for (i=0; i<n; i++) //Parcourir chaque sommet
	{
		j=0; ok=1; temp=0;	*e = NULL;

		do
		{
			p = *e;
			do
			{
				if (arc (g, j, p->st)) ok = 0;
				p = p->suivant;
			}while( (p!=NULL)&&(ok) );

			if (!p) 
			{
				ajoute(e,j);
				temp++; //On compte la longueur du sous graphe desert
			}
			j++;
		}while(j<n);

		if (temp>max) //Si le sous graphe est plus grand que le precedent enregistré
		{
			max = temp; ref = i; //ref designe le sommet a partir duquel on peut trouver le sous graphe desert
								// max est la taille du sous graphe desert maximum provisoire
		}

	}

	ajoute(e,ref);
	j=0;

	*e = NULL;
	do
		{
			q = *e;
			do
			{
				if (arc (g, j, p->st)) ok = 0;
				p = p->suivant;
			}while( (p!=NULL)&&(ok) );

			if (!p) ajoute(e,j);
			j++;
		}while(j<temp);

}
