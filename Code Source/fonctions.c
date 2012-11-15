#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"



CL* recherche(int valeur, CL skipList){

if(skipList==NULL) return NULL;






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
