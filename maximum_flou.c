void maximum_flou(graphe g, ens_sommet *e)
{
	int i, j, n, ok, ref, temp, min;
	ens_sommet *p,*q;

	min = n;
	for (i=0; i <n; i++)
	{
		p = g.a[i]; count = 0;
		while (p!=NULL)
			count++;

		if (count<min)
		{
			min = count;
			ref = i;
		}
	}

	ajoute(e,ref);
	
	do{
		q=*e;
		do{
			if(arc(g,i,q->st)) ok=0;
			q=q->suivant;
		}while((q!=NULL) && (ok));
		
		if(!q) ajoute(e,i);
		i++;
	}while(i<n);
}