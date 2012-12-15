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
	nouvTete->tete = NULL;
	nouvTete->suite=NULL;
    return nouvTete;
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
if(skipList==NULL) return NULL; //si la skiplist est vide ou qu'il n'y a pas de parcours

int ht = hauteur(skipList);
CL* element = (CL*)malloc(sizeof(CL));
CL* temp = NULL;
L* TeteListe=skipList;
printf("je passe ici (la skip liste existe) %d %d  AJOUT DE %d \n",hauteur(skipList),nbinser, valeur );

if(hauteur(skipList)<nbinser){
	int i=0;
	TeteListe= creerTete();
	L* tempL;
	L* tempL2;
	while(i<(nbinser-ht)){
		if(i==0){
			tempL = creerTete();
			TeteListe->suite= tempL;
		}else{
			tempL2 = creerTete();
			tempL->suite = tempL2;
			tempL=tempL2;
		}
		i++;
	}
	tempL->suite = skipList;
	skipList = TeteListe;
}else{
	while(hauteur(skipList) != nbinser+1){ //tant qu'on est pas a la bonne ligne pour inserer la valeur
		skipList=skipList->suite;
	}
}
	while(hauteur(skipList)>=1){ //tant qu'on est pas arrivé a la derniere ligne
		temp = skipList->tete;
		//TETE DE LISTE
		if(temp==NULL || (temp!=NULL && temp->val>valeur)){//si la val de la tete de liste est sup a ce quon veut inserer
			element->val = valeur;
			element->suiv = temp;
			skipList->tete = element;
			if(hauteur(skipList)==1){
				element->bas=NULL;
			}else{
				element->bas = (CL*)malloc(sizeof(CL));
				element=element->bas;
				
			}
			
		}else{ //si en milieu de liste (ou fin)
			while(temp->suiv!= NULL && temp->suiv->val<valeur){ //tant que la valeur suivante existe et qu'elle est inférieure a celle qu'on veut inserer
				temp = temp->suiv; //on avance dans les cases (on se place a l'endroit ou on veut inserer ololol
			}
				element->val = valeur;
				element->suiv = temp->suiv;
				temp->suiv=element;
				if(hauteur(skipList)==1){
					element->bas=NULL;
				}else{
					element->bas = (CL*)malloc(sizeof(CL));
					element=element->bas;
				}
				
		}	
		skipList=skipList->suite;
	}
	return TeteListe;
}

void afficheListe(L* skipList){
    CL* temp;
    int ht = hauteur(skipList);
    while(ht >= 1 && skipList!=NULL){
		temp = skipList->tete;
		//printf("je passe dans la fonction ht>=1 ht=%d\n", ht);
        while(temp!=NULL){
				printf("valeur :%d -",temp->val);
				
				temp = temp->suiv;				
        }
		printf("\n");
        skipList= skipList->suite;		
        ht = ht - 1;
    }
	printf("\n");
}

void affichetest(L* skipList){
    CL* temp;
	CL* ligne;
	while(skipList!=NULL){
		ligne =skipList->tete;
		temp = skipList->tete;
		while(ligne!=NULL){
			while(temp!=NULL){
				printf("valeur :%d -",temp->val);
				temp = temp->bas;				
			}
			ligne=ligne->suiv;
			temp = ligne;
		}
		printf("\n");
		skipList = skipList->suite;
	}
    
}

