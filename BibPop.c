#include "BibPop.h"
#include "BibGeneral.h"
#include "BibIndiv.h"

Population* creerPopulation(int taillePop)
{
    Population* Pop = malloc(sizeof(Population*));

    ElemIndiv* element = malloc(sizeof(ElemIndiv*)); //allocation de la mémoire
    Individu* indiv = creerIndiv(LONGINDIV);
    indiv = initialisation(indiv);

    element->next = NULL;
    element->precedent = NULL;
    element->value = indiv;

    Pop->taillePop = 1;
    Pop->head = element;
    //afficherPopulation(Pop);
    return Pop;
}

Population* initPopulation(Population* pop , int taillePop)
{
    int i;
    Individu* nvIndiv = malloc(sizeof(Individu*));
    for(i = 1; i < taillePop; i++)
    {
        nvIndiv = creerIndiv(LONGINDIV);
        nvIndiv = initialisation(nvIndiv);
        ajouterTPopulation(pop, nvIndiv);
        afficherPopulation(pop);
    }

    return pop;
}

Population* ajouterTPopulation(Population* Pop, Individu* Indiv)
{
    ElemIndiv* element1 = malloc(sizeof(ElemIndiv*)); //allocation de la mémoire

    element1->value = Indiv;
    element1->next = Pop->head;    //on initialise le premier élément
    element1->precedent = NULL;
    Pop->head->precedent = element1;

    Pop->taillePop++;
    Pop->head = element1;

    return Pop;
}

void afficherPopulation(Population* Pop)
{
    ElemIndiv* ElemInd = malloc(sizeof(ElemIndiv*));
    Individu* affInd = malloc(sizeof(Individu*));
    if(Pop != NULL)
    {
        ElemInd = Pop->head;
        printf("taille pop: %d\nPop: \n",Pop->taillePop);

        for(int i = 0; i < Pop->taillePop; i++)
        {
            affInd = ElemInd->value;
            printf("ca va\n");
            afficher_individu(affInd);
            printf("ca va pas\n");
            printf("\n");
            ElemInd = ElemInd->next;
        }
    }
}


