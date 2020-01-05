#include "BibGeneral.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BibIndiv.h"
#include "BibPop.h"


int main()
{
    srand(time(NULL));

    Population* Pop = init_pop(creer_pop(), TAILLEPOP);	//initialisation de la Population 
    int i;

    for(i = 0; i < NGEN; i++)	//repetition NGEN fois
    {
	Pop = croiser_pop(Pop);		//croisement de la population
        Pop = trier_pop(Pop, Pop->head, Pop->tail); //tri de la population
        Pop = select_pop(Pop, TSELECT);		//selection de la population
    }

    printf("\nLe meilleur individu de cette population est :\n");	//affichage du meilleur individu
    afficher_indiv(Pop->head->value);
    printf("\nQualite : %f\n",qualiteIndivf3(decodage_indiv(Pop->head->value)));//affichage de sa qualité pour faciliter l'étude 
    return 0;
}
