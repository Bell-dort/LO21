#include <stdio.h>
#include <stdlib.h>
#include "BibGeneral.h"
#include "BibIndiv.h"
#include "BibPop.h"
#include <time.h>
#include <math.h>

Population* creerPopulation(void)
{
    Population* Pop = malloc(sizeof(Population));     //on d�clare la structure

    if (Pop != NULL)            //on verifie que �a a march�
    {
        Pop->taillePop = 0;     //on remplie la structure
        Pop->head = NULL;
        Pop->tail = NULL;
    }

    return Pop;
}

Population* ajouterTPopulation(Population* Pop, Individu* Indiv)
{
    ElemIndiv* nvElem = malloc(sizeof(ElemIndiv)); //allocation de la m�moire

    nvElem->value = Indiv;
    nvElem->next = Pop->head;
    nvElem->precedent = NULL;

    if(Pop->head != NULL)
    {
        Pop->head->precedent = nvElem;
    }
    else
    {
        Pop->tail = nvElem;
    }


    Pop->head = nvElem;
    Pop->taillePop++;


    return Pop;
}

Population* ajouterQPopulation(Population* Pop, Individu* Indiv)
{
    ElemIndiv* nvElem = malloc(sizeof(ElemIndiv)); //allocation de la m�moire

    printf("l'indiv ? : ");

    nvElem->value = Indiv;
    nvElem->next = NULL;
    nvElem->precedent = Pop->tail;

    if(Pop->head != NULL)
    {
        Pop->tail->next = nvElem;
    }
    else
    {
        Pop->head = nvElem;
    }

    Pop->tail = nvElem;

    Pop->taillePop++;
    afficher_individu(Pop->tail->value);

    return Pop;
}

Population* supprimerQPopulation(Population* Pop)
{
    Pop->tail = Pop->tail->precedent;
    free(Pop->tail->next);
    Pop->tail->next = NULL;

    Pop->taillePop--;

    return Pop;
}



Population* initPopulation(Population* pop , int taillePop)
{
    int i;                                              //on declare les variables utilis�es ensuite
    Individu* nvIndiv = malloc(sizeof(Individu));

    for(i = 0; i < taillePop; i++)                  //on ajoute un individu jusqu� ce que population soit de la bonne taille
    {
        nvIndiv = creerIndiv(LONGINDIV);            //on cr�� et initialise un individu � ajouter
        nvIndiv = initialisation(nvIndiv);
        pop = ajouterTPopulation(pop, nvIndiv);
    }

    return pop;
}


void afficherPopulation(Population* Pop)
{
    ElemIndiv* ElemInd = malloc(sizeof(ElemIndiv)); //on cr�� un element qui va parcourir la liste

    if(Pop != NULL)
    {
        ElemInd = Pop->head;
        printf("taille : %d\n", Pop->taillePop);
        for(int i = 0; i < Pop->taillePop; i++) //On affiche les individus
        {
            afficher_individu(ElemInd->value);
            ElemInd = ElemInd->next;
        }
    }
}


Population* quicksort(Population* Pop, ElemIndiv* debut, ElemIndiv* fin)
{

    float pivot, qGauche, qDroite;                          //initialisation des variables utilis�es plus tard
    ElemIndiv* gauche = malloc(sizeof(ElemIndiv));
    ElemIndiv* droite = malloc(sizeof(ElemIndiv));
    Individu* temp = malloc(sizeof(ElemIndiv));

    if(debut != fin)                                            //si la portion de liste �tudi�e ne comprends pas qu'un �l�ment alors on la trie
    {
        pivot = qualiteIndivf1(decodage(debut->value));         //on choisit le premier �lement comme pivot et on positionne droite et gauche � chaque extremit�
        gauche = debut;
        droite = fin;

        while(droite != gauche)
        {
            qGauche = qualiteIndivf1(decodage(gauche->value));          //on affecte les qualit� correspondante � qGauvhe et qDroite pour effectuer les comparaisons
            qDroite = qualiteIndivf1(decodage(droite->value));

            while(qDroite < pivot)                                  //on positionne droite sur le premier individu dont la qualit� est superieure au pivot
            {
                droite = droite->precedent;
                qDroite = qualiteIndivf1(decodage(droite->value));
            }

            while(qGauche > pivot)                              //on positionne gauche sur le premier individu dont la qualit� est inferieure au pivot
            {
                gauche = gauche->next;
                qGauche = qualiteIndivf1(decodage(gauche->value));
            }

            if(qGauche == qDroite && droite != gauche)          //on verifie que les deux individus compar�s ne sont pas identiques
            {
                gauche = gauche->next;
                qGauche = qualiteIndivf1(decodage(gauche->value));
            }
            else
            {
                if(qGauche < qDroite)           //si ils ne le sont pas et que qDroite est superieur � qGauche alors on echange les valeurs de droite et gauche
                {
                    temp = gauche->value;
                    gauche->value = droite->value;
                    droite->value = temp;
                }
            }
        }

        if(gauche != debut)                                     //si la partie de la liste � gauche du pivot ne contient pas qu'un �l�ment
        {
            Pop = quicksort(Pop, debut, gauche->precedent);     //on trie la gauche du pivot
        }
        if(droite != fin)                                       //si la partie de la liste � droite du pivot ne contient pas qu'un �l�ment
        {
            Pop = quicksort(Pop, droite->next, fin);            //on trie la droite du pivot
        }
    }
    return Pop;     //on renvoie la population ti�e
}

Population* SelectPop(Population* Pop, int tSelect)
{
    ElemIndiv* ElemCopy = malloc(sizeof(ElemIndiv));
    int i;

    ElemCopy = Pop->head;

    for(i = 0; i < TAILLEPOP - tSelect; i++)
    {
        Pop = supprimerQPopulation(Pop);
    }

    for(i = 0; i < TAILLEPOP - tSelect; i++)
    {
        Pop = ajouterQPopulation(Pop, ElemCopy->value);
        ElemCopy = ElemCopy->next;
    }

    return Pop;
}








