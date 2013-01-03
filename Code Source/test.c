#include "fonctions.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[]){
	double probabilite = 0.5;
	L* skipList;
	int pas = 0;
	skipList = creerTete();
	printf(" -------------TEST--------------\n\n");
	
    printf("Ajout de 10 : \n");
    skipList = ajoutVal(10, skipList, nbPiles(probabilite, hauteur(skipList)));
    afficheListe(skipList);
    printf("Ajout de 8 : \n");
    skipList = ajoutVal(8, skipList, nbPiles(probabilite, hauteur(skipList)));
    afficheListe(skipList);
    printf("Ajout de 6 : \n");
    skipList = ajoutVal(6, skipList, nbPiles(probabilite, hauteur(skipList)));
    afficheListe(skipList);
    printf("Ajout de 15 : \n");
    skipList = ajoutVal(15, skipList, nbPiles(probabilite, hauteur(skipList)));
    afficheListe(skipList);
    printf("Ajout de 3 : \n");
    skipList = ajoutVal(3, skipList, nbPiles(probabilite, hauteur(skipList)));
    afficheListe(skipList);
    printf("Ajout de 7 : \n");
    skipList = ajoutVal(7, skipList,nbPiles(probabilite, hauteur(skipList)));
    afficheListe(skipList);
    printf("Ajout de 11 : \n");
    skipList = ajoutVal(11, skipList, nbPiles(probabilite, hauteur(skipList)));
    afficheListe(skipList);
    printf("Ajout de 20 : \n");
    skipList = ajoutVal(20, skipList, nbPiles(probabilite, hauteur(skipList)));
    afficheListe(skipList);
    printf("Ajout de 21 : \n");
    skipList = ajoutVal(21, skipList, nbPiles(probabilite, hauteur(skipList)));
    afficheListe(skipList);
    printf("Ajout de 2 : \n");
    skipList = ajoutVal(2, skipList, nbPiles(probabilite, hauteur(skipList)));
    afficheListe(skipList);
    printf("Ajout de 9 : \n");
    skipList = ajoutVal(9, skipList, nbPiles(probabilite, hauteur(skipList)));
    afficheListe(skipList);
	printf("\n============================= \n");
    printf("\nRecherche d'un element present : 10 \n");
    pas = recherche(10, skipList);
	if(pas>0){
		printf("l'element existe, nombre de pas pour y acceder : %d\n\n",pas);
	}else{
		printf("l'element n'existe pas\n");
	}
	
    printf("Recherche d'un element absent : 28 \n");
    pas = recherche(28, skipList);
	if(pas>0){
		printf("l'element existe, nombre de pas pour y acceder : %d\n",pas);
	}else{
		printf("l'element n'existe pas\n");
	}
	
    printf("\n============================= \n");
    printf("\nSuppression d'un element : 8 \n");
    skipList = SupprimerValeur(skipList, 8);
    afficheListe(skipList);
    printf("\nSuppression d'un element : 6 \n");
    skipList = SupprimerValeur(skipList, 6);
    afficheListe(skipList);
    printf("\nSuppression d'un element : 21 \n");
    skipList = SupprimerValeur(skipList, 21);
    afficheListe(skipList);
    printf("\nSuppression d'un element : 10 \n");
    skipList = SupprimerValeur(skipList, 10);
    afficheListe(skipList);
	printf("\nSuppression d'un element qui n'existe pas : 99 \n");
    skipList = SupprimerValeur(skipList, 99);
    afficheListe(skipList);
	

	return EXIT_SUCCESS;
}
