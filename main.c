#include <stdio.h>
#include <stdlib.h>
#include "BibGeneral.h"
#include "BibIndiv.h"
#include "BibPop.h"
#include <time.h>

int main()
{
    srand(time(NULL));

    ElemIndiv* elem = malloc(sizeof(ElemIndiv*));

    Population* Pop = creerPopulation(TAILLEPOP);
    Pop = initPopulation(Pop, TAILLEPOP);

    afficherPopulation(Pop);
    printf("quicksort: \n");
    Pop = quicksort(Pop, Pop->head, Pop->tail);
    afficherPopulation(Pop);
    elem = Pop->head;


    for(int i = 0; i<5; i++)
    {
        printf("element %d, qualite : %f\n", i+1, qualiteIndivf1(decodage(elem->value)));
        elem = elem->next;
    }

    return 0;
}
