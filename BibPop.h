#ifndef BIBPOP_H_INCLUDED
#define BIBPOP_H_INCLUDED
#include "BibGeneral.h"
#include "BibIndiv.h"

// Fonctions pour les listes d'individus:
Population* creerPopulation(int);// Creer et initialiser un liste d'individus
Population* ajouterTPopulation(Population*, Individu*);
void afficherPopulation(Population*); // Permet d'afficher la liste d'individus
int videPopulation(Population*); // Verifie si la liste d'individu est vide. Renvoie 1 si oui, 0 si non
Population* initPopulation(Population* , int);
Population* quicksort(Population*, ElemIndiv*, ElemIndiv*);

#endif // BIBPOP_H_INCLUDED
