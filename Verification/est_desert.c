#include <stdio.h>
#include "est_desert.h"

/*
 *  Ecrit par Axel FAUCONNIER
 *  Vérifié par
 *
 *  Renvoie 1 si l'ensemble de sommets e passé en argument est un est sous-graphe désert du graphe g passé en argument
 *  0 sinon
 *
 *  Complexité de l'algorithme : O(|e|²)
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
