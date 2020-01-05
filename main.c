#include "BibGeneral.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BibIndiv.h"
#include "BibPop.h"


int main()
{
    srand(time(NULL));

    Population* Pop = init_pop(creer_pop(), TAILLEPOP);
    int i;

    printf("pop : \n");
    afficher_pop(Pop);

    for(i = 0; i < NGEN; i++)
    {

        Pop = trier_pop(Pop, Pop->head, Pop->tail);
        Pop = select_pop(Pop, TSELECT);
        Pop = croiser_pop(Pop);
    }
    printf("pop opti :\n");
    afficher_pop(Pop);

    printf("\nLe meilleur individu de cette population est :\n");
    afficher_indiv(Pop->head->value);
    printf("\ndecode : %u, Qualite : %f\n",decodage_indiv(Pop->head->value),qualiteIndivf2(decodage_indiv(Pop->head->value)));
    return 0;
}
