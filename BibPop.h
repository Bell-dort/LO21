#ifndef BIBPOP_H_INCLUDED
#define BIBPOP_H_INCLUDED
#include "BibGeneral.h"
#include "BibIndiv.h"

// Fonctions pour les listes d'individus:
Population* creer_population(void);// Creer et initialiser un liste d'individus
Population* ajouterT_pop(Population*, Individu*); // Ajouter un individu à une population en tete
Population* ajouterQ_pop(Population*, Individu*); // Ajouter un individu à une population en queue
Population* supprimerQ_pop(Population* Pop)   // supprime l'individu en queue de la population
Population* init_pop(Population* , int); //initialise(rempli) une population
void afficher_pop(Population*); // Permet d'afficher la liste d'individus
int vide_pop(Population*); // Verifie si la liste d'individu est vide. Renvoie 1 si oui, 0 si non

Population* trier_pop(Population*, ElemIndiv*, ElemIndiv*); //trie la population par ordre décroissant selon la qualité des individu
Population* select_pop(Population*, int);    //selectionne les meilleurs individus et les recopies dans le reste de la lise
Population* croiser_pop(Population*);    //croise une population


#endif // BIBPOP_H_INCLUDED
