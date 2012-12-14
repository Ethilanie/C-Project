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

int hauteur(L* skipList){
	int ht = 0;
	if(skipList==NULL) return 0;
	while(skipList!=NULL){
		ht=ht +1;
		skipList= skipList->suite;
	}
	return ht;	
}

CL* ajoutVal(int valeur,L* skipList, int nbinser){
//ajout dans la skipListe d'une valeur
if(skipList==NULL) return NULL; //si la skiplist est vide ou qu'il n'y a pas de parcours

int i;
int ht = hauteur(skipList);
CL* element; 
CL* temp = NULL;
CL* basTemp = NULL;
i=lg;
while(hauteur(skipList) != (ht-nbinser)){ //tant qu'on a pas 
	skipList=skipList->suiv;
}

while(hauteur(skipList)>=1){ //tant qu'on est pas arrivé a la derniere ligne
	temp = skipList->tete;
	//TETE DE LISTE
	if(temp==NULL || (temp!=NULL && temp->val>valeur)){//si la val de la tete de liste est sup a ce quon veut inserer
		element =(CL*)malloc(sizeof(CL));
		element->val = valeur;
		element->suiv = temp;
		skipList->tete = element;
		basTemp = (CL*)malloc(sizeof(CL));
		if(hauteur(skipList)!=1){
			element->bas = basTemp;
			basTemp->val = valeur;
		}else{
			element->bas = NULL;
		}
	}else{ //si en milieu de liste (ou fin)
		while(temp->suiv != NULL && temp->suiv->val<valeur){ //tant que la valeur suivante existe et qu'elle est inférieure a celle qu'on veut inserer
			temp = temp->suiv; //on avance dans les cases (on se place a l'endroit ou on veut inserer ololol
		}
		if (basTemp == NULL){
			element =(CL*)malloc(sizeof(CL));
			element->val = valeur;
			element->suiv = temp;
			basTemp = (CL*)malloc(sizeof(CL));
			
			element->suiv = temp;
			temp->suiv = element;
		}else{
			
			
		}	
		if(hauteur(skipList)!=1){
			element->bas = basTemp;
			basTemp->val = valeur;
		}else{
			element->bas = NULL;
		}
}
skipList=skipList->suite;
}

