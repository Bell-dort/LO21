#ifndef BIBGENERAL_H_INCLUDED
#define BIBGENERAL_H_INCLUDED
// On place ici des constantes du préprocesseur
// pour faciliter le changement des paramètres du projet

#define LONGINDIV 32  // Longueur d'un individu:
#define PCROISE 0.5  // Probabilité de croisement:
#define TAILLEPOP 200  // Taille de la population:
#define TSELECT 180  // Taux de sélection:
#define NGEN 200  // Nombre de générations:

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char Bit; // définition d'un bit compris entre 0 et 1

typedef struct Elemb
{
	Bit value;
	struct Elemb* next;
} ElemBit; // Element de la liste de bits

typedef struct ListeBit
{
	ElemBit* head;
	int longIndiv; // Taille de la liste de bits
} Individu; // La liste de bits

typedef struct Elemi
{
    Individu* value;
	struct Elemi* precedent;
	struct Elemi* next;
}ElemIndiv; // Element de la liste d'individu

typedef struct ListeIndiv
{
	ElemIndiv* head;
	ElemIndiv* tail;
	int taillePop; // Taille de la liste d'indiv
}Population;  // Une population est une liste d'individu

#endif // BIBGENERAL_H_INCLUDED
