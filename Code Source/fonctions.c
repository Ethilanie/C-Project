#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
            return 1;
        }
    }


}






/*
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
