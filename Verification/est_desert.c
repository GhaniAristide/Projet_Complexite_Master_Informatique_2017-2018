#include <stdio.h>
#include "est_desert.h"

/*
 *  Ecrit par Axel FAUCONNIER
 *  V�rifi� par
 *
 *  Renvoie 1 si l'ensemble de sommets e pass� en argument est un est sous-graphe d�sert du graphe g pass� en argument
 *  0 sinon
 *
 *  Complexit� de l'algorithme : O(|e|�)
 */

int est_desert(graph g, ens_sommets e)
{
    chain_list curr = e;
    while(curr->suiv != NULL)
    {
        chain_list tmp = curr->suiv;
        while(tmp != NULL)
        {
            if(arc(g, curr->st, tmp->st))
                return 0;
            tmp = tmp->suiv;
        }
        curr = curr->suiv;
    }
    return 1;
}
