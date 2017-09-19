#include <stdio.h>
#include "est_maximal.h"
#include "est_desert.h"

int est_maximal(graph g, ens_sommets e)
{
    if(est_desert(g, e))
    {
        int n = g.nb_sommets;
        int sommets_libre[n];
        ens_sommets copie = NULL;

        for(int i = 0; i < n; i++)
            sommets_libre[i] = 1;

        maillon * tmp = e;
        while(tmp != NULL)
        {
            sommets_libre[tmp->st] = 0;
            ajoute(&copie, tmp->st);
            tmp = tmp->suiv;
        }

        for(int i = 0; i < n; i++)
        {
            if(sommets_libre[i])
            {
                ajoute(&copie, i);
                if(est_desert(g, copie))
                    return 0;
                else
                    enleve_tete(&copie);
            }
        }

        free_list(copie);
        return 1;
    }
    else
    {
        return 0;
    }
}
