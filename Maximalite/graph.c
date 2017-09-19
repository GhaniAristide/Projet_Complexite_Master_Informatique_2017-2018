#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void load_graph(graph * g, char namefile[64])
{
    FILE * f = NULL;
    f = fopen(namefile, "r");

    if(f != NULL)
    {
        int nb_sommets, nb_arcs;
        fscanf(f, "%d %d", &nb_sommets, &nb_arcs);

        g->nb_sommets = nb_sommets;

        //Allocation de la matrice
        g->mat_voisins = malloc((sizeof(int*) * nb_sommets));
        for(int i = 0; i < nb_sommets; i++)
            g->mat_voisins[i] = malloc(sizeof(int) * nb_sommets);

        //Initialisation de la matrice
        for(int i = 0; i < nb_sommets; i++)
        {
            for(int k = 0; k < nb_sommets; k++)
                g->mat_voisins[i][k] = 0;
        }

        //Allocation de la liste d'adjacence
        g->list_voisins = malloc(sizeof(maillon*) * nb_sommets);

        //Initialisation de la liste
        for(int i = 0; i < nb_sommets; i++)
            g->list_voisins[i] = NULL;

        //Remplissage de l'information
        for(int i = 0; i < nb_arcs; i++)
        {
            int x1, x2;
            fscanf(f, "%d %d", &x1, &x2);
            g->mat_voisins[x1][x2] = g->mat_voisins[x2][x1] = 1;

            ajoute(&g->list_voisins[x1], x2);
            ajoute(&g->list_voisins[x2], x1);
        }

        fclose(f);
    }
    else
    {
        printf("Cannot open file %s\n", namefile);
        exit(1);
    }
}

void free_graph(graph * g)
{
    //Désalocation de la matrice
    for(int i = 0; i < g->nb_sommets; i++)
        free(g->mat_voisins[i]);
    free(g->mat_voisins);

    //Désalocation de la liste d'adjacence
    for(int i = 0; i < g->nb_sommets; i++)
    {
        while(g->list_voisins[i] != NULL)
        {
            chain_list t = g->list_voisins[i]->suiv;
            free(g->list_voisins[i]);
            g->list_voisins[i] = t;
        }
    }
}

int arc(graph g, int x, int y)
{
    return g.mat_voisins[x][y];
}

void print_matrice(graph g)
{
    int n = g.nb_sommets;
    for(int i = 0; i < n; i++)
    {
        for(int k = 0; k < n; k++)
        {
            printf("%d\t", g.mat_voisins[i][k]);
        }
        printf("\n\n");
    }
}

void print_list(graph g)
{
    int n = g.nb_sommets;
    for(int i = 0; i < n; i++)
    {
        maillon * tmp = g.list_voisins[i];
        printf("Voisins du sommet %d : ", i);
        while(tmp != NULL)
        {
            printf("%d  ", tmp->st);
            tmp = tmp->suiv;
        }
        printf("\n\n");
    }
}

void ajoute(chain_list * m, int x) // Bien initialisé le pointeur à NULL lorsqu'on le commence une liste
{
    chain_list t = *m;
    *m = malloc(sizeof(maillon));
    (*m)->suiv = t;
    (*m)->st = x;
}

void enleve_tete(chain_list * m)
{
    chain_list t = *m;
    *m = (*m)->suiv;
    free(t);
}

void free_list(chain_list l)
{
    while(l != NULL)
    {
        chain_list t = l->suiv;
        free(l);
        l = t;
    }
}
