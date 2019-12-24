#include <stdio.h>
#include <stdlib.h>
#include "BibGeneral.h"
#include "BibIndiv.h"
#include "BibPop.h"
#include <time.h>
#include <math.h>

Population* creerPopulation(int taillePop)
{
    Population* Pop = malloc(sizeof(Population*));     //on déclare les variables
    ElemIndiv* element = malloc(sizeof(ElemIndiv*));

    Individu* indiv = creerIndiv(LONGINDIV);    //on créé un premier individu
    indiv = initialisation(indiv);

    element->next = NULL;               //on créé un premier élément
    element->precedent = NULL;
    element->value = indiv;

    Pop->taillePop = 1;         //on l'insère à la tete et fin de Pop
    Pop->head = element;
    Pop->tail = element;
    return Pop;
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


Population* initPopulation(Population* pop , int taillePop)
{
    int i;                                              //on declare les variables utilisées ensuite
    Individu* nvIndiv = malloc(sizeof(Individu*));

    for(i = 1; i < taillePop; i++)                  //on ajoute un individu jusquà ce que population soit de la bonne taille
    {
        nvIndiv = creerIndiv(LONGINDIV);            //on créé et initialise un individu à ajouter
        nvIndiv = initialisation(nvIndiv);
        ajouterTPopulation(pop, nvIndiv);
    }

    return pop;
}


void afficherPopulation(Population* Pop)
{
    ElemIndiv* ElemInd = malloc(sizeof(ElemIndiv*)); //on créé un element qui va parcourir la liste

    if(Pop != NULL)
    {
        ElemInd = Pop->head;

        for(int i = 0; i < Pop->taillePop; i++) //On affiche les individus
        {

            afficher_individu(ElemInd->value);
            ElemInd = ElemInd->next;
        }
    }
}


Population* quicksort(Population* Pop, ElemIndiv* debut, ElemIndiv* fin)
{

    float pivot, qGauche, qDroite;                          //initialisation des variables utilisées plus tard
    ElemIndiv* gauche = malloc(sizeof(ElemIndiv*));
    ElemIndiv* droite = malloc(sizeof(ElemIndiv*));
    Individu* temp = malloc(sizeof(ElemIndiv*));

    if(debut != fin)                                            //si la portion de liste étudiée ne comprends pas qu'un élément alors on la trie
    {
        pivot = qualiteIndivf1(decodage(debut->value));         //on choisit le premier élement comme pivot et on positionne droite et gauche à chaque extremité
        gauche = debut;
        droite = fin;
        //qGauche = pivot;
        //qDroite = qualiteIndivf1(decodage(droite->value));

        //printf("gauche: %f pivot : %f droite : %f\n", qGauche, pivot, qDroite);

        while(droite != gauche)
        {
            qGauche = qualiteIndivf1(decodage(gauche->value));          //on affecte les qualité correspondante à qGauvhe et qDroite pour effectuer les comparaisons
            qDroite = qualiteIndivf1(decodage(droite->value));

            while(qDroite < pivot)                                  //on positionne droite sur le premier individu dont la qualité est superieure au pivot
            {
                droite = droite->precedent;
                qDroite = qualiteIndivf1(decodage(droite->value));
            }
            while(qGauche > pivot)                              //on positionne gauche sur le premier individu dont la qualité est inferieure au pivot
            {
                gauche = gauche->next;
                qGauche = qualiteIndivf1(decodage(gauche->value));
            }
            if(qGauche == qDroite && droite != gauche)          //on verifie que les deux individus comparés ne sont pas identiques
            {
                gauche = gauche->next;
                qGauche = qualiteIndivf1(decodage(gauche->value));
            }
            else
            {
                if(qGauche < qDroite)           //si ils ne le sont pas et que qDroite est superieur à qGauche alors on echange les valeurs de droite et gauche
                {
                    temp = gauche->value;
                    gauche->value = droite->value;
                    droite->value = temp;
                }
            }

        }
        if(gauche != debut)                                     //si la partie de la liste à gauche du pivot ne contient pas qu'un élément
        {
            Pop = quicksort(Pop, debut, gauche->precedent);     //on trie la gauche du pivot
        }
        if(droite != fin)                                       //si la partie de la liste à droite du pivot ne contient pas qu'un élément
        {
            Pop = quicksort(Pop, droite->next, fin);            //on trie la droite du pivot
        }


    }



    return Pop;     //on renvoie la population tiée

}









