#ifndef BIBGENERAL_H_INCLUDED
#define BIBGENERAL_H_INCLUDED
// On place ici des constantes du préprocesseur
// pour faciliter le changement des paramètres du projet

// Longueur d'un individu:
#define LONGINDIV 8
// Probabilité de croisement:
#define PCROISE 0.5
// Taille de la population:
#define TAILLEPOP 5
// Taux de sélection:
#define TSELECT 0.5
// Nombre de générations:
#define NGEN 20

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char Bit; // définition d'un bit compris entre 0 et 1

typedef struct Elem
{
	Bit value;
	struct Elem* next;
} ElemBit; // Element de la liste de bits (= un bit)

typedef struct ListeBit
{
	ElemBit* head;
	int longIndiv; // Taille de la liste de bits
} Individu; // La liste de bits

//typedef ListeBit* Individu; // Un individu est une liste de bits


typedef struct Elem2
{
    Individu* value;
	struct Elem2* precedent;
	struct Elem2* next;
}ElemIndiv; // Element de la liste d'individu

typedef struct ListeIndiv
{
	ElemIndiv* head;
	ElemIndiv* tail;
	int taillePop; // Taille de la liste de bits
}Population;  // Une population est une liste d'individu

#endif // BIBGENERAL_H_INCLUDED
