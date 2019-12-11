#ifndef BIBGENERAL_H_INCLUDED
#define BIBGENERAL_H_INCLUDED
// On place ici des constantes du pr�processeur
// pour faciliter le changement des param�tres du projet

// Longueur d'un individu:
#define LONGINDIV 8
// Probabilit� de croisement:
#define PCROISE 0.5
// Taille de la population:
#define TAILLEPOP 5
// Taux de s�lection:
#define TSELECT 0.5
// Nombre de g�n�rations:
#define NGEN 20

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char Bit; // d�finition d'un bit compris entre 0 et 1

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
