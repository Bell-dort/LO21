#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BibIndiv.h"
#include <math.h>
#include "BibGeneral.h"

void p_croise(Individu* l1, Individu* l2)       //croise 2 individus entre eux en invertissant leurs Bits
{
    int pt, proba;
    double probaR,k=0;
    ElemBit* p = l1->head;
    ElemBit* m = l2->head;

    ElemBit* temp = malloc(sizeof(ElemBit*));

    pt = PCROISE * 100;                         //met la probabilité PCROISE sous forme de pourcentage

    while(p->next != NULL || m->next != NULL)      //on teste la probabilite pour chaque element des listes
    {
        proba = rand()%pt;

        if(proba<(pt/2))                        
        {
            temp->value = p->value;
            p->value = m->value;
            m->value = temp->value;
            k+=1;
        }
        p = p->next;
        m = m->next;
    }
    probaR = (k/LONGINDIV);
    printf(" Probabilite theorique : %d %%\n Probabilite observee : %.2lf %% \n",pt,probaR*100);

}

Individu* creerIndiv(int longIndiv)			//Creer un individu
{
	Individu* indiv = malloc(sizeof(Individu*));	//Alloue de la mémoire
	indiv->head = NULL;
	indiv->longIndiv = LONGINDIV;
	return indiv;
}

Individu* initialisation(Individu* indiv) //Initialisation de la liste de Bit d'un individu
{
    int i;
	for(i = 0; i < indiv->longIndiv; i++)	//Remplissage de la liste de Bit avec 0 ou 1 au hasard
	{
		indiv = ajouter_head(indiv,rand()%2);
	}
	return indiv;
}

Individu* initialisation_recur(Individu* indiv, int longlist) //Initialisation de la liste de Bit d'un individu (RECURSIF)
{
    if(longlist>0)                                  //condition d'arrêt : si on arrive à la fin de la liste, on arrête d'ajouter des élements
    {
        ElemBit* p = malloc(sizeof(ElemBit*));
        p = indiv->head;

        longlist = longlist - 1;
        indiv = ajouter_head(indiv,rand()%2);
        p = p->next;
        initialisation_recur(indiv,longlist);
    }
    return indiv;
}

int est_vide(Individu* l)                       //vérifie si une liste donnée l est vide ou non
{
	return (l == NULL);
}

Individu* ajouter_head(Individu* l,Bit a)       //ajoute une valeur a en tete de liste
{
	ElemBit *e = malloc(sizeof(ElemBit*));
	e->value = a;
	e->next = l->head;
	l->head = e;
	return l;
}

Individu* ajouter_queue(Individu* l,Bit a)      //ajoute une valeur a en fin de liste
{
    ElemBit* p = malloc(sizeof(ElemBit*));

    ElemBit* newel = malloc(sizeof(ElemBit*));

    newel->value = a;
    newel->next= NULL;

    if(est_vide(l))
    {
        l->head = newel;
    }
    else
    {
        p = l->head;
        while(p->next != NULL)
        {
            p=p->next;
        }
        p->next = newel;
    }
    return l;
}


void afficher_individu(Individu* l)         //affiche un individu
{
    int i;
    ElemBit* temp = malloc(sizeof(ElemBit*));

	if (!est_vide(l))
	{
		temp = l->head;
		printf("[");
		for (i = 0; i < l->longIndiv; i++)  //affiche 1 par 1 les éléments de la liste
		{
			printf(" %d ",temp->value);
			temp = temp->next;
		}
		printf("]");
	}
	else
	{
		printf("Individu vide.\n");
	}
	printf("\n\n");
}

int decodage(Individu* l)               //lit la liste de Bits d'un individu et en calcule sa valeur
{
	int valIndiv=0,i=LONGINDIV - 1;
	ElemBit* temp = l->head;

	while(temp->next != NULL)
    {
        valIndiv += (temp->value)*pow(2,i);         //calcule la valeur des Bits en commencant par le Bit le plus fort
        i--;
        temp = temp->next;
    }
	return valIndiv;
}

float qualiteIndivf1(int valIndiv, Individu* l)     /*première version de la fonction qui calcule la qualité d'un individu à partir de sa valeur,
                                                     obtenue par la fonction "decodage"*/
{
    int longIndiv = 8;
    int A = -1,B = 1;
	float resultat,X;

	X = (valIndiv / powf(2,longIndiv)) * (B - A) + A;
	resultat = - powf(X,2);

	return resultat;
}

float qualiteIndivf2(int valIndiv, Individu* l)     /*deuxieme version de la fonction qui calcule la qualité d'un individu à partir de sa valeur,
                                                     obtenue par la fonction "decodage"*/
{
    int longIndiv = 16;
    float A = 0.1,B = 5;
	float resultat,X;

	X = (valIndiv / powf(2,longIndiv)) * (B - A) + A;
	resultat = - log(X);

	return resultat;
}

float qualiteIndivf3(int valIndiv, Individu* l)     /*troisième version de la fonction qui calcule la qualité d'un individu à partir de sa valeur,
                                                     obtenue par la fonction "decodage"*/
{
    int longIndiv = 32;
    float A = (-M_PI),B = M_PI;
	float resultat,X;

	X = (valIndiv / powf(2,longIndiv)) * (B - A) + A;
	resultat = - cos(X);

	return resultat;
}


