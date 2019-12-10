#include <stdio.h>
#include <stdlib.h>
#include "BibGeneral.h"
#include "BibIndiv.h"
#include "BibPop.h"
#include <time.h>

int main()
{
    srand(time(NULL));

    Individu* indiv1 = malloc(sizeof(Individu*));
    Population* Pop = creerPopulation(TAILLEPOP);


    afficherPopulation(Pop);

    for(int i = 0; i < 10; i++)
    {
        indiv1 = creerIndiv(LONGINDIV);
        indiv1 = initialisation(indiv1);
        Pop = ajouterTPopulation(Pop, indiv1);
        afficherPopulation(Pop);
    }

    return 0;
}
