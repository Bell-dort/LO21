#include "BibGeneral.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "BibIndiv.h"


void croiser_indiv(Individu* l1, Individu* l2)       //croise 2 individus entre eux en invertissant leurs Bits
{
    int pt, proba;
    double k = 0;
    //double probaR;
    ElemBit* p = l1->head;
    ElemBit* m = l2->head;

    ElemBit* temp = malloc(sizeof(ElemBit));

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
    //probaR = (k/LONGINDIV);
    //printf(" Probabilite theorique : %d %%\n Probabilite observee : %.2lf %% \n",pt,probaR*100);

}

Individu* creer_indiv(void)			//Creer un individu
{
	Individu* indiv = malloc(sizeof(Individu));	//Alloue de la mémoire
	indiv->head = NULL;
	indiv->longIndiv = 0;
	return indiv;
}

Individu* init_indiv(Individu* indiv, int longindiv) //Initialisation de la liste de Bit d'un individu
{
    int i;
	for(i = 0; i < longindiv; i++)	//Remplissage de la liste de Bit avec 0 ou 1 au hasard
	{
		indiv = ajouterT_indiv(indiv, rand()%2);
	}
	return indiv;
}

Individu* initialisation_recur(Individu* indiv, int longlist) //Initialisation de la liste de Bit d'un individu (RECURSIF)
{
    if(longlist > 0)                                  //condition d'arrêt : si on arrive à la fin de la liste, on arrête d'ajouter des élements
    {
        ElemBit* elemParc = malloc(sizeof(ElemBit));
        elemParc = indiv->head;

        longlist = longlist - 1;
        indiv = ajouterT_indiv(indiv,rand()%2);
        elemParc = elemParc->next;
        initialisation_recur(indiv,longlist);
    }
    return indiv;
}

int est_vide(Individu* indiv)                       //vérifie si une liste donnée l est vide ou non
{
	return (indiv->head == NULL);
}

Individu* ajouterT_indiv(Individu* indiv, Bit bit)       //ajoute une valeur a en tete de liste
{
	ElemBit* nvElem = malloc(sizeof(ElemBit));
	nvElem->value = bit;
	nvElem->next = indiv->head;
	indiv->head = nvElem;

	indiv->longIndiv++;
	return indiv;
}

Individu* ajouterQ_indiv(Individu* indiv,Bit bit)      //ajoute une valeur a en fin de liste
{
    ElemBit* elemParc = malloc(sizeof(ElemBit));

    ElemBit* nvElem = malloc(sizeof(ElemBit));

    nvElem->value = bit;
    nvElem->next= NULL;

    if(est_vide(indiv))
    {
        indiv->head = nvElem;
    }
    else
    {
        elemParc = indiv->head;
        while(elemParc->next != NULL)
        {
            elemParc = elemParc->next;
        }
        elemParc->next = nvElem;
    }

    indiv->longIndiv++;
    return indiv;
}


void afficher_indiv(Individu* indiv)         //affiche un individu
{
    int i;
    ElemBit* temp = malloc(sizeof(ElemBit));

	if (!est_vide(indiv))
	{
		temp = indiv->head;
		printf("[");
		for (i = 0; i < indiv->longIndiv; i++)  //affiche 1 par 1 les éléments de la liste
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

int decodage_indiv(Individu* indiv)               //lit la liste de Bits d'un individu et en calcule sa valeur
{
	int valIndiv = 0, i = LONGINDIV - 1;
	ElemBit* temp = indiv->head;

	while(temp->next != NULL)
    {
        valIndiv += (temp->value)*pow(2,i);         //calcule la valeur des Bits en commencant par le Bit le plus fort
        i--;
        temp = temp->next;
    }
	return valIndiv;
}

float qualiteIndivf1(int valIndiv)     /*première version de la fonction qui calcule la qualité d'un individu à partir de sa valeur,
                                                obtenue par la fonction "decodage"*/
{
    int longIndiv = 8;
    int A = -1,B = 1;
	double resultat,X;

	X = (valIndiv / powf(2,longIndiv)) * (B - A) + A;
	resultat = - powf(X,2);
	return resultat;
}


float qualiteIndivf2(int valIndiv)     /*deuxieme version de la fonction qui calcule la qualité d'un individu à partir de sa valeur,
                                                     obtenue par la fonction "decodage"*/
{
    int longIndiv = 16;
    float A = 0.1,B = 5;
	float resultat,X;

	X = (valIndiv / powf(2,longIndiv)) * (B - A) + A;
	resultat = - log(X);

	return resultat;
}

float qualiteIndivf3(int valIndiv)     /*troisième version de la fonction qui calcule la qualité d'un individu à partir de sa valeur,
                                                     obtenue par la fonction "decodage"*/
{
    int longIndiv = 32;
    float A = (-M_PI),B = M_PI;
	float resultat,X;

	X = (valIndiv / powf(2,longIndiv)) * (B - A) + A;
	resultat = - cos(X);

	return resultat;
}

Individu* copy_indiv(Individu* indiv1)    //Copie un individu
{
    Individu* indiv2 = creer_indiv();    //declaration des variables
    ElemBit* elemParc = indiv1->head;
    int i;

    for(i = 0; i < LONGINDIV; i++)  //on ajoute dans indiv2 chaque bit de indiv1
    {
        indiv2 = ajouterQ_indiv(indiv2, elemParc->value);
        elemParc = elemParc->next;
    }

    return indiv2;
}
