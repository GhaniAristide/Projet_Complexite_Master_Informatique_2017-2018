#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "est_desert.h"


int main(int argc, char * argv[])
{
    if(argc < 3)
    {
        printf("Utilisation : $ %s fichierGraph x1 x2 ... xn\n\n", argv[0]);
        exit(1);
    }

    graph g;
    load_graph(&g, argv[1]);

    ens_sommets e = NULL;

    for(int i = 2; i < argc; i++)
    {
        ajoute(&e, atoi(argv[i]));
    }

    int r = est_desert(g, e);

    if(r)
    {
        printf("L'ensemble de sommets donné constitue un sous-graphe désert de G\n");
    }
    else
    {
        printf("L'ensemble de sommets donné ne constitue pas un sous-graphe désert de G\n");
    }

    free_list(e);
    free_graph(&g);

    return 0;
}
