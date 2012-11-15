#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fonctions.h"



CL* recherche(int valeur, CL skipList){

<<<<<<< HEAD
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

=======
if(skipList==NULL) return NULL;






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
