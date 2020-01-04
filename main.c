#include <stdio.h>
#include <stdlib.h>
#include "BibGeneral.h"
#include "BibIndiv.h"
#include "BibPop.h"
#include <time.h>

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
        Pop = select_pop(Pop);
        Pop = croiser_pop(Pop);
    }
    printf("pop opti :\n");
    afficher_pop(Pop);


    return 0;
}
