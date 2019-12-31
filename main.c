#include <stdio.h>
#include <stdlib.h>
#include "BibGeneral.h"
#include "BibIndiv.h"
#include "BibPop.h"
#include <time.h>

int main()
{
    srand(time(NULL));

    Individu* indiv = malloc(sizeof(Individu));

    Population* Pop = creerPopulation();
    printf("oui\n");
    Pop = initPopulation(Pop, TAILLEPOP);
    afficherPopulation(Pop);



    Pop = quicksort(Pop, Pop->head, Pop->tail);
    printf("quicksort :\n");
    afficherPopulation(Pop);

    printf("selection : \n");

    Pop = SelectPop(Pop, 3);

    indiv = Pop->head->value;



    afficherPopulation(Pop);

    return 0;
}
