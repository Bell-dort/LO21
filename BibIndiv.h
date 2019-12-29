#ifndef BIBPOP_H_INCLUDED
#define BIBPOP_H_INCLUDED
#include "BibGeneral.h"

// Fonction pour les listes de bits :
Individu* creerIndiv(int);// Creer une liste de bits

void ajouterTIndividu(Individu*, Bit); // Ajouter un bit à la liste de bits
Individu* ajouter_head(Individu*,Bit);
Individu* ajouter_queue(Individu*,Bit);
Individu* suppr_head(Individu*);
Individu* suppr_queue(Individu*);

Individu* initialisation(Individu*);; //initialiser la liste de bits
Individu* initialisation_recur(Individu*, int);
int est_vide(Individu*); // Verifie si la liste de bits est vide. Renvoie 1 si oui, 0 si non

void afficher_individu(Individu*); // Permet d'afficher la liste de bits


void trouver_elem(Individu*,int);
int decodage(Individu*);
float qualiteIndivf1(int);
float qualiteIndivf2(int);
float qualiteIndivf3(int);
void p_croise(Individu*, Individu*);

void croiserIndiv(Individu*, Individu*, double);

#endif // BIBPOP_H_INCLUDED
