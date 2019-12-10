#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BibIndiv.h"
#include "BibGeneral.h"
#include <math.h>


void p_croise(Individu* l1, Individu* l2)
{
    int pt, proba;
    double probaR,k=0;
    ElemBit* p = l1->head;
    ElemBit* m = l2->head;

    ElemBit* temp = malloc(sizeof(ElemBit*));

    pt = PCROISE * 100;

    while(p->next != NULL || m->next != NULL)
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
	Individu* indiv = malloc(sizeof(Individu*));	//Alloue de la m�moire
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
    if(longlist>0)
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

int est_vide(Individu* l)
{
	if(l == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

Individu* ajouter_head(Individu* l,Bit a)
{
	ElemBit *e = malloc(sizeof(ElemBit*));
	e->value = a;
	e->next = l->head;
	l->head = e;
	return l;
}

Individu* ajouter_queue(Individu* l,Bit a)
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


void afficher_individu(Individu* l)
{
    int i;
    ElemBit* temp = malloc(sizeof(ElemBit*));

	if (!est_vide(l))
	{
		temp = l->head;
		printf("[");
		for (i = 0; i < l->longIndiv; i++)
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



int decodage(Individu* l)
{
	int valIndiv=0,i=LONGINDIV - 1;
	ElemBit* temp = l->head;

	while(temp->next != NULL)
    {
        valIndiv += (temp->value)*pow(2,i);
        i--;
        temp = temp->next;
    }
	return valIndiv;
}

double qualiteIndiv(int valIndiv, Individu* l)
{
	double resultat,X;
	X = (valIndiv / powf(2,l->longIndiv)) * (B - A) + A;
	resultat = - powf(X,2);

	return resultat;
}


