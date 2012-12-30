#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fonctions.h"



int* tableauAleatoire(int nbelements){
    int* tab = (int*)malloc(nbelements*sizeof(int));
    int i=0;
    srand(time(NULL));
    for(i=0;i<nbelements;i++){

        tab[i] = rand()%(nbelements-1) +1;
    }
    return tab;
}

int recherche(int valeur, L* skipList)
{
    CL* temp;
    int trouve = 0;
    int pas = 0;
    temp = skipList->tete;
    if(skipList != NULL)//On vérifie que la liste n'est pas vide
        while(trouve == 0) //On mets en place la boucle principale
        {
            while (temp->val > valeur){ //Tant que la valeur courante est supérieure à la valeur cherchée et
                pas = pas +1; //On ajoute un pas
                skipList = skipList->suite; //On va sur la liste en dessous
                temp = skipList->tete; //On replace temp au début de la liste
                }
            while(temp->suiv != NULL && temp->suiv->val<=valeur)  //Tant que l'élément suivant le courant n'est pas NULL, et que la val recherchée est inférieure à la val suivante
            {
                temp= temp->suiv; //On va sur l'élément suivant
                pas = pas+1; //On augmente le nombre de pas
            }
            if(temp->val == valeur) //Si on est sur la bonne valeur
            {
                printf("Valeur présente dans la liste ! %d \n",temp->val);
                printf("Avec le nombre de pas : %d \n", pas);
                trouve = 1;
                return pas; //On retourne le nombre de pas
            }
            else //Sinon
            {
                if(temp->bas != NULL)  //Si on peut aller en bas, on y va
                {
                    temp = temp->bas;
                    pas = pas + 1; //On augmente le nombre de pas
                }
                else{
                    printf("Valeur non présente dans la liste : %d \n", valeur); //Sinon, on est au bout de la liste, la valeur n'est pas présente
                }

            }

            }
        
}





 int nbPiles(double proba, int hauteur) {
     static int init = 1;
     int stop = 0;
     if(init) {
         srand((unsigned)time(NULL));
         init = 0;
     }
	int etages = 0;
    while(((float) rand() / RAND_MAX)> proba && stop ==0){
 		etages++;
 		if(etages>=hauteur+1){stop=1;}
    }
    //printf("nb pile : %d\n", etages);
	return etages;
}



L* creerTete()
{
    L* nouvTete;
    nouvTete = (L*)malloc(sizeof(L));
    if(nouvTete == NULL)
    {
        printf("Erreur d'allocation, tête non créée");
        return NULL;
    }
    nouvTete->tete = NULL;
    nouvTete->suite=NULL;
    return nouvTete;
}

CL* creeCase()
{
    CL* nouvCase;
    nouvCase = (CL*)malloc(sizeof(CL));
    if(nouvCase == NULL)
    {
        printf("Erreur d'allocation, case non créée");
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
    if(skipList==NULL) return NULL; //si la skiplist est vide

    CL* element = creeCase();
    CL* temp = NULL;
    L* TeteListe=skipList;
   /* getchar();
    printf("je passe ici (la skip liste existe) %d %d  AJOUT DE %d \n",hauteur(skipList),nbinser, valeur );
*/
    //Ajout de Liste dans le cas d'un nombre d'insertion supérieur a la hauteur de la skipListe
    if(hauteur(skipList)<nbinser+1){
        TeteListe= creerTete();
        TeteListe->suite= skipList;
        skipList = TeteListe;
    }else{
        //s'il n'a pas besoin d'ajouter (nbinsertion inferieur a la hauteur), il faut se placer sur la bonne liste
        while(hauteur(skipList) > nbinser+1){ //tant qu'on est pas a la bonne ligne pour inserer la valeur
            skipList=skipList->suite;
        }
    }

    //Ajout de la valeur
    while(hauteur(skipList)>=1){ //tant qu'on est pas arrivé a la derniere ligne
		temp = skipList->tete;
		//Si ajout en tete de liste
		if(temp==NULL || (temp!=NULL && temp->val>valeur)){//si la val de la tete de liste est sup a ce quon veut inserer
			element->val = valeur;
			element->suiv = temp;
			skipList->tete = element;
		}else{ //si en milieu de liste (ou fin)
			while(temp->suiv!= NULL && temp->suiv->val<valeur){ //tant que la valeur suivante existe et qu'elle est inférieure a celle qu'on veut inserer
				temp = temp->suiv; //on avance dans les cases (on se place a l'endroit ou on veut inserer ololol
			}
            element->val = valeur;
            element->suiv = temp->suiv;
            temp->suiv=element;
		}
		if(hauteur(skipList)==1){
            element->bas=NULL;
        }else{
            element->bas = creeCase();
            element=element->bas;

        }
        skipList=skipList->suite;

	}
	element= NULL;
	return TeteListe;
}

void afficheListe(L* skipList)
{
    CL* temp;
    int ht = hauteur(skipList);
    while(ht >= 1 && skipList!=NULL)
    {
        temp = skipList->tete;
        //printf("je passe dans la fonction ht>=1 ht=%d\n", ht);
        while(temp!=NULL)
        {
            printf("valeur :%d -",temp->val);

            temp = temp->suiv;
        }
        printf("\n");
        skipList= skipList->suite;
        ht = ht - 1;
    }
    printf("\n");
}

void affichetest(L* skipList)
{
    CL* temp;
    CL* ligne;
    while(skipList!=NULL)
    {
        ligne =skipList->tete;
        temp = skipList->tete;
        while(ligne!=NULL)
        {
            while(temp!=NULL)
            {
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

L* boucleAjout(L* skipList, int* val_elements,int nbelts, double proba){

int i=0;

int nbjetes=0;
for(i=0;i<nbelts;i++){
    nbjetes=nbPiles(proba, hauteur(skipList));
    skipList = ajoutVal(val_elements[i],skipList, nbjetes);
}

    return skipList;
}

