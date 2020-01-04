#ifndef BIBINDIV_H_INCLUDED
#define BIBINDIV_H_INCLUDED
#include "BibGeneral.h"

// Fonction pour les listes de bits :

Individu* creer_indiv(void);// Creer une liste de bits


Individu* ajouterT_indiv(Individu*,Bit); // Ajouter un bit à la liste de bits en tete
Individu* ajouterQ_indiv(Individu*,Bit); // Ajouter un bit à la liste de bits en queue
Individu* copy_indiv(Individu*);  //Copie un individu


Individu* init_indiv(Individu*, int); //initialiser la liste de bits
Individu* initRecur_indiv(Individu*, int); //version recursive de la fonction précedente
int vide_indiv(Individu*); // Verifie si la liste de bits est vide. Renvoie 1 si oui, 0 si non
void afficher_indiv(Individu*); // Permet d'afficher la liste de bits

int decodage_indiv(Individu*);    //décode la liste de bit en un nombre entier
float qualiteIndivf1(int);  //calcule la qualtité d'un individu avec la fonction f1 en fonction de son décodage
float qualiteIndivf2(int);  //calcule la qualtité d'un individu avec la fonction f2 en fonction de son décodage
float qualiteIndivf3(int);  //calcule la qualtité d'un individu avec la fonction f3 en fonction de son décodage
void croiser_indiv(Individu*, Individu*);  //croise deux individus entres eux

#endif // BIBINDIV_H_INCLUDED
