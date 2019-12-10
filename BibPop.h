#ifndef BIBPOP_H_INCLUDED
#define BIBPOP_H_INCLUDED
#include "BibGeneral.h"

// Fonctions pour les listes d'individus:
Population* creerPopulation(int);// Creer et initialiser un liste d'individus
Population* ajouterTPopulation(Population*, Individu*); // Ajouter un individu à la liste d'individus
void afficherPopulation(Population*); // Permet d'afficher la liste d'individus
int videPopulation(Population*); // Verifie si la liste d'individu est vide. Renvoie 1 si oui, 0 si non
Population* initPopulation(Population* , int);

#endif // BIBPOP_H_INCLUDED
