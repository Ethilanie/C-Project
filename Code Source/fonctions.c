#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fonctions.h"




CL* recherche(int valeur, CL* skipList){


    if(skipList==NULL) return NULL;
    else{
        while(valeur != skipList->val){ //Tant qu'on ne tombe pas sur la bonne valeur recherchée
            while(skipList->suiv != NULL && valeur<skipList->val){ //Tant que l'élément suivant le courant n'est pas NULL, et que la val recherchée est inférieure à la val courante
                skipList = skipList->suiv; //On va sur l'élément suivant
                }
            if(skipList->bas != NULL){ //Si on peut aller en bas, on y va
                skipList = skipList->bas;
            }
            else{ //Sinon, cela signifie qu'on a atteint le bout de la liste, et que la valeur recherchée n'est pas dans la SkipList
                printf("La valeur recherchée n'est pas dans la liste");
                return 0;
            }
            printf("La valeur recherchée est dans la liste !");
            return NULL;//a changer
        }
    }


}

int longueur(CL* parcoursSL){
	int i=0;
	for (i = 0 ; parcoursSL != NULL; i++){
	parcoursSL++;
	}
	return i;
}

CL* ajoutVal(int valeur, CL* parcoursSL,CL* skipList, int nbpile){
//ajout dans la skipListe d'une valeur
if(skipList==NULL) return NULL; //si la skiplist est vide ou qu'il n'y a pas de parcours
if(parcoursSL==NULL) return NULL;
int i;
CL* element; 
CL* temp = NULL;
int lg = longueur(parcoursSL);
i=lg;
	while(i > 0 && i< nbpile){
		//on créé une nouvelle case, avec la nouvelle valeur et nouveaux pointeurs
		element =(CL*)malloc(sizeof(CL));
		element->val = valeur;
		element->bas = temp;
		element->suiv = parcoursSL[i].suiv;
		parcoursSL[i].suiv = element;
		temp = element;
		i--;
	}
}




/*
>>>>>>> 01d7a3cd58d0c1cafb247ab15e6e8552e426e51f
void affiche_liste(liste l){
    if(l==NULL){
        printf("()");
    }
    else{
        printf("( %d ", l->val);
        CL* temp = l->suiv;
        while(temp != NULL){
            printf("%d ", temp->val);
            temp = temp->suiv;
        }
        printf(")\n");
    }
}

void insertion_debut(liste* l, int valeur){
    CL* deb = (CL*)malloc(1*sizeof(CL));
    deb->val = valeur;
    deb->suiv = *l;
    *l = deb;
}

void insertion_fin(liste* l, int valeur){
    if(*l==NULL){
        insertion_debut(l, valeur);
    }
    else{
        CL* fin = (CL*)malloc(1*sizeof(CL));
        CL* temp = *l;
        while(temp->suiv != NULL){
            temp = temp->suiv;
        }
        fin->val = valeur;
        fin->suiv = NULL;
        temp->suiv = fin;
    }
}*/
