#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fonctions.h"




CL* recherche(int valeur, CL* skipList){


    if(skipList==NULL) return NULL;
    else{
        while(valeur != skipList->val){ //Tant qu'on ne tombe pas sur la bonne valeur recherch�e
            while(skipList->suiv != NULL && valeur<skipList->val){ //Tant que l'�l�ment suivant le courant n'est pas NULL, et que la val recherch�e est inf�rieure � la val courante
                skipList = skipList->suiv; //On va sur l'�l�ment suivant
                }
            if(skipList->bas != NULL){ //Si on peut aller en bas, on y va
                skipList = skipList->bas;
            }
            else{ //Sinon, cela signifie qu'on a atteint le bout de la liste, et que la valeur recherch�e n'est pas dans la SkipList
                printf("La valeur recherch�e n'est pas dans la liste");
                return 0;
            }
            printf("La valeur recherch�e est dans la liste !");
            return NULL;//a changer
        }
    }


}


 /*float frand() {
     return (float) rand() / RAND_MAX;
 }*/

 int tirage(double proba) {
     static int init = 1;
     if(init) {
         srand((unsigned)time(NULL));
         init = 0;
     }
	int etages = 0;
    while(((float) rand() / RAND_MAX)> proba){
 		etages++;
    }
	return etages;
}

int nbpiles(double prob){
    printf("Valeur de prob � la base : %f", prob);
    int face = 0;
    int res = 0;
    int n = 0;
    srand(time(NULL));
    while(face==0){

        n = rand()%(int)(1/prob);
        printf("Valeur de n : %d \n",n);
        if(n>=1){
            face=1;
            printf("Valeur de n dans la boucle : %d \n", n);
            printf("Youpi �a passe dans le face = 1 !");
        }else{
            res++;
        }
    }
    return res;
}


L* creerTete(){
    L* nouvTete;
    nouvTete = (L*)malloc(sizeof(L));
    if(nouvTete == NULL){
        printf("Erreur d'allocation, t�te non cr��e");
        return NULL;
        }
	nouvTete->tete = NULL;
	nouvTete->suite=NULL;
    return nouvTete;
}

CL* creeCase(){
    CL* nouvCase;
    nouvCase = (CL*)malloc(sizeof(CL));
    if(nouvCase == NULL){
        printf("Erreur d'allocation, case non cr��e");
        return NULL;
        }
    nouvCase->suiv = NULL;
    nouvCase->bas = NULL;
    return nouvCase;
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
	while(hauteur(skipList)>=1){ //tant qu'on est pas arriv� a la derniere ligne
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
			while(temp->suiv!= NULL && temp->suiv->val<valeur){ //tant que la valeur suivante existe et qu'elle est inf�rieure a celle qu'on veut inserer
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

