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
L* creerTete(){
    L* nouvTete;
    nouvTete = (L*)malloc(sizeof(L));
    return nouvTete;
}


int longueur(CL* parcoursSL){
	int i=0;
	for (i = 0 ; parcoursSL != NULL; i++){
	parcoursSL++;
	}
	return i;
}

int hauteur(L* skipList){
	int ht = 1;
	if(skipList==NULL) return 0;
	while(skipList->suite!=NULL){
		ht=ht +1;
		skipList= skipList->suite;
	}
	return ht;
}

L* ajoutVal(int valeur,L* skipList, int nbinser){
//ajout dans la skipListe d'une valeur
printf("je passe ici (entree de l'ajout) \n");
if(skipList==NULL) return NULL; //si la skiplist est vide ou qu'il n'y a pas de parcours

int ht = hauteur(skipList);
CL* element;
CL* temp = NULL;
CL* basTemp = NULL;
printf("je passe ici (la skip liste existe) %d %d \n",hauteur(skipList),nbinser );

if(hauteur(skipList)<nbinser){
	int i=0;
	L* TeteListe= creerTete();
	L* tempL;
	L* tempL2;
	while(i<(nbinser-hauteur(skipList))){
		if(i==0){
			printf("je passe ici (hauteur inf a nbpiles) \n");
			tempL = creerTete();
			TeteListe->suite= tempL;
		 }else{
		 printf("je passe ici (hauteur inf a nbpiles 2) \n");
		 tempL2 = (L*)malloc(sizeof(L));
		 tempL->suite = tempL2;
		 tempL=tempL2;
		 }
		 tempL->tete = (CL*)malloc(sizeof(CL));
		 tempL->tete->val = valeur;
		 tempL->tete->suiv = NULL;
		 tempL->tete->bas =  NULL;
		 printf("je passe ici (hauteur inf a nbpiles 3) \n");
		i++;
	}
	tempL->suite = skipList;
	skipList = TeteListe;
	printf("je passe ici (hauteur inf a nbpiles - sortie boucle) \n");
}else{

	while(hauteur(skipList) != (ht-nbinser)){ //tant qu'on est pas a la bonne ligne pour inserer la valeur
		printf("donnees : hauteur liste : %d, nbinser : %d\n, ht skipliste : %d", hauteur(skipList),nbinser, ht);
		printf("je passe ici (placement sur skipliste) \n");
		skipList=skipList->suite;
	}
}
while(hauteur(skipList)>=1){ //tant qu'on est pas arrivé a la derniere ligne
	printf("je passe ici (fonction) hauteur : %d \n", hauteur(skipList));
	temp = skipList->tete;
	//TETE DE LISTE
	if(temp==NULL || (temp!=NULL && temp->val>valeur)){//si la val de la tete de liste est sup a ce quon veut inserer
		printf("je passe ici (si tete de liste) \n");
		element =(CL*)malloc(sizeof(CL));
		element->val = valeur;
		element->suiv = temp;
		skipList->tete = element;
		element->bas = basTemp;
	}else{ //si en milieu de liste (ou fin)
		while(temp->suiv != NULL && temp->suiv->val<valeur){ //tant que la valeur suivante existe et qu'elle est inférieure a celle qu'on veut inserer
			printf("je passe ici (placement en milieu de liste) \n");
			temp = temp->suiv; //on avance dans les cases (on se place a l'endroit ou on veut inserer ololol
		}
			basTemp =(CL*)malloc(sizeof(CL));
			basTemp->val = valeur;
			basTemp->suiv = temp;
			temp->suiv = basTemp;
			element=basTemp;
			basTemp=NULL;
			element->bas = basTemp;		
			printf("je passe ici (ajout case voir pbm avec bas) \n");
	}	
	skipList=skipList->suite;
	}
}

void afficheListe(L* skipList){
    CL* temp;
    int ht = hauteur(skipList);
    temp = skipList->tete;
    while(ht >= 1){
        while(temp!=NULL){
            printf("%d", temp->val);
			getchar();
            temp = temp->suiv;
        }
        skipList= skipList->suite;
        ht = ht - 1;
    }
}

