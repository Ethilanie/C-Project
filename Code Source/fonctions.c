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

int nbpiles(float prob){
    int face = 0;
    int res = -1;
    float n;
    while(face==0){
        res++;
        n = rand()%(100);
        if(n>=prob*100){
            face=1;
        }
    }
    return res;
}

int longueur(CL* parcoursSL){
	int i=0;
	for (i = 0 ; parcoursSL != NULL; i++){
	parcoursSL++;
	}
	return i;
}

int hauteur(L* skipList){
	int ht = 0;
	if(skipList==NULL) return 0;
	while(skipList!=NULL){
		ht=ht +1;
		skipList= skipList->suite;
	}
	return ht;	
}

L* ajoutVal(int valeur,L* skipList, int nbinser){
//ajout dans la skipListe d'une valeur
if(skipList==NULL) return NULL; //si la skiplist est vide ou qu'il n'y a pas de parcours

int ht = hauteur(skipList);
CL* element; 
CL* temp = NULL;
CL* basTemp = NULL;


if(hauteur(skipList)<nbinser){
	int i=0;
	L* TeteListe=(L*)malloc(sizeof(L));
	L* tempL;
	L* tempL2;
	while(i<(nbinser-hauteur(skipList))){
		if(i==0){
			tempL = creerTete();
			TeteListe->suite= tempL;
		 }else{
		 tempL2 = (L*)malloc(sizeof(L));
		 tempL->suite = tempL2;
		 tempL=tempL2;
		 }
		 tempL->tete = (CL*)malloc(sizeof(CL));
		 tempL->tete->val = valeur;
		 tempL->tete->suiv = NULL;
		 tempL->tete->bas =  NULL;
		i++;
	}
	tempL->suite = skipList;
}



while(hauteur(skipList) != (ht-nbinser)){ //tant qu'on a pas 
	skipList=skipList->suite;
}

while(hauteur(skipList)>=1){ //tant qu'on est pas arrivé a la derniere ligne
	temp = skipList->tete;
	//TETE DE LISTE
	if(temp==NULL || (temp!=NULL && temp->val>valeur)){//si la val de la tete de liste est sup a ce quon veut inserer
		element =(CL*)malloc(sizeof(CL));
		element->val = valeur;
		element->suiv = temp;
		skipList->tete = element;
		element->bas = basTemp;
	}else{ //si en milieu de liste (ou fin)
		while(temp->suiv != NULL && temp->suiv->val<valeur){ //tant que la valeur suivante existe et qu'elle est inférieure a celle qu'on veut inserer
			temp = temp->suiv; //on avance dans les cases (on se place a l'endroit ou on veut inserer ololol
		}
			basTemp =(CL*)malloc(sizeof(CL));
			basTemp->val = valeur;
			basTemp->suiv = temp;
			temp->suiv = basTemp;
			element=basTemp;
			basTemp=NULL;
			element->bas = basTemp;		
	}	
	skipList=skipList->suite;
	}
}
