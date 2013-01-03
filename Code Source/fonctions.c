#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fonctions.h"

void textcolor(int attr, int fg, int bg)
{	char command[13];
	/* Command is the control command to the terminal */
	sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
	printf("%s", command);
}

//creer une liste
L* creerTete(){
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

//creer une case
CL* creeCase(){
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

//boucle qui ajoute le tableau val_elements dans une skiplist
L* boucleAjout(L* skipList, int* val_elements,int nbelts, double proba){

int i=0;

int nbjetes=0;
for(i=0;i<nbelts;i++){

if(recherche(val_elements[i], skipList)==0){

nbjetes=nbPiles(proba, hauteur(skipList));
skipList = ajoutVal(val_elements[i],skipList, nbjetes);
}
}

return skipList;
}

//ajout d'une valeur
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

//renvoie le nombre de tirage avant d'avoir un face
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

//renvoie un tableau de nombres aléatoires
int* tableauAleatoire(int nbelements){
    int* tab = (int*)malloc(nbelements*sizeof(int));
    int i=0;
    srand(time(NULL));
    for(i=0;i<nbelements;i++){

        tab[i] = rand()%(nbelements-1) +1;
    }
    return tab;
}

//renvoie la hauteur de la skiplist
int hauteur(L* skipList){
	int ht = 1;
	if(skipList==NULL) return 0;
	while(skipList->suite!=NULL){
		ht=ht +1;
		skipList= skipList->suite;
	}
	return ht;
}

//recherche une valeur dans la skip list
int recherche(int valeur, L* skipList){
    CL* temp;
    int trouve = 0;
    int pas = 1;
    temp = skipList->tete;
    if(skipList != NULL) //On vérifie que la liste n'est pas vide
    {
        while(trouve == 0) //On mets en place la boucle principale
        {
            while (skipList !=NULL && temp!=NULL && temp->val > valeur && skipList->suite !=NULL )  //Tant que la valeur courante est supérieure à la valeur cherchée et qu'on est pas à la fin de la skipliste
            {
                skipList = skipList->suite; //On va sur la liste en dessous
                temp = skipList->tete;//On replace temp au début de la liste
                pas = pas +1; //On ajoute un pas
            }
            while(temp!=NULL && temp->suiv != NULL && temp->suiv->val<=valeur)  //Tant que l'élément suivant le courant n'est pas NULL, et que la val recherchée est inférieure à la val suivante
            {
                temp= temp->suiv; //On va sur l'élément suivant
                pas = pas+1; //On augmente le nombre de pas
            }
            if(temp!=NULL && temp->val == valeur) //Si on est sur la bonne valeur
            {
               // printf("Valeur presente dans la liste ! %d \n",temp->val);
               // printf("Avec le nombre de pas : %d \n\n\n", pas);
                trouve = 1;
                return pas; //On retourne le nombre de pas
            }
            else //Sinon
            {
                if(temp!=NULL && temp->bas != NULL)  //Si on peut aller en bas, on y va
                {
                    temp = temp->bas;
                    pas = pas + 1; //On augmente le nombre de pas
                }
                else
                {
                   // printf("Valeur non presente dans la liste : %d \n", valeur);
                    trouve=1;//Sinon, on est au bout de la liste, la valeur n'est pas présente
                    return 0;
                }

            }

        }


    }
}

//recherche toutes les valeurs de la skiplist
int boucleRecherche(L* skipList, int nbElements){
    int pas = 0;
    int i = 0;
    int tabPas[nbElements];
    for (i = 0; i<nbElements; i++)
    {
        tabPas[i] = recherche(i, skipList);
    }

    printf("==========================\n");
    printf("||  Cases || Nombre de pas ||\n");
    for (i = 1; i <= nbElements; i++)
    {
        printf("||       %d || %d       ||\n",i, tabPas[i]);
    }
    printf("=========================");
    for(i = 1; i<=nbElements; i++)
    {
        pas = pas + tabPas[i];
    }
    printf("\n \n Somme des pas : %d", pas);
}

//supprime une valeur
L* SupprimerValeur(L* SkipList, int valeur){
	L* NouvelleTete = SkipList;
	CL* temp;
	CL* tempSupp;
	int placev=0;
	int i=0;
	if(SkipList==NULL) return NULL;
	if(recherche(valeur,SkipList)==0) return SkipList;

	while(hauteur(SkipList)>0){ //on va passer dans toutes les hauteurs
		temp=SkipList->tete;//on recupere la tete de la skiplist
		if(place(SkipList,valeur)==1){ //si c'est la premiere place dans la liste
			SkipList->tete = temp->suiv; //on change la tete de la skipList
			free(temp);//on libere la case
			printf("je passe ici\n");
			if(SkipList->tete==NULL){//si c'était la seule case de la liste
				NouvelleTete = SkipList->suite; //il faut supprimer la liste
				free(SkipList); //et donner une nouvelle tete a la skipListe
			}
		}else if(place(SkipList,valeur)>1){//si elle existe dans la liste
											//et que ce n'est pas la tete
			placev = place(SkipList,valeur);//on recupere la place de la valeur
			for(i=1;i<placev-1;i++){ //on se place sur la case avant la valeur
				temp=temp->suiv;						
			}
			tempSupp = temp->suiv; //on met un pointeur sur la case a supprimer
			temp->suiv = tempSupp->suiv; //on fait pointer la case precedente sur le suiv de la case a supp
			free(tempSupp);	//on supprime la case
		}	
		//on passe a la liste du dessous
		SkipList = SkipList->suite;
	}
	return NouvelleTete;
}

//renvoie l'indice de la place d'une valeur dans la liste
int place(L*SkipList, int valeur){
    int i=0;
    CL*temp;
    int trouve=0;
    temp=SkipList->tete;
    while(temp!=NULL && trouve ==0){
        if(valeur == temp->val){
            trouve=1;
        }
            i++;
        temp=temp->suiv;
    }
	if(trouve==0){
		return 0;
	}else{
		return i;
	}

}

//affiche la liste en mode texte
void afficheListe(L* skipList){
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

//affiche l'option h
void AfficherAide(){
	printf("	");


}

//renvoie un tableau avec les valeurs des elements du fichier passé en argument
int* tableauFichier(char* nomFichier, int* nb_elem){
    FILE* fichier = fopen(nomFichier, "r+");
printf("fonction fichier : %s \n", nomFichier);
 if(fichier==NULL){
	printf("erreur, impossible d'ouvrir le fichier\n");
	return NULL;
}
 printf("fichier ouvert\n");
    char carac;
    char * nombre=(char*)malloc(sizeof(char));
    int nbc=0;
    int* tab = (int*)malloc(sizeof(int));
    int i=0;
    while(!feof(fichier)){

        carac = fgetc(fichier);
        if(isNumeric(carac)==1){
            nombre=(char*)realloc(nombre,sizeof(char)*(nbc+1));
            nombre[nbc] = carac;
            nombre[nbc+1]='\0';
            nbc++;
        }else{
            if(nbc!=0){
                tab = (int*)realloc(tab,sizeof(int)*(i+1));
                tab[i]=atoi(nombre);
                nombre=(char*)realloc(nombre,sizeof(char));
                nbc=0;
                i++;
            }
        }
    }
    *nb_elem = i;
	fclose(fichier);
return tab;
}


int isNumeric(char caractere){
    //int i;
    /*
    for(i=0;i<10;i++){
        printf("car : %c, i : %d\n",caractere, i);
        if(caractere==i){
            return 1;
        }
    }*/
    if(caractere=='0'){
        return 1;
    }
    if(caractere=='1'){
        return 1;
    }
     if(caractere=='2'){
        return 1;
    }
     if(caractere=='3'){
        return 1;
    }
     if(caractere=='4'){
        return 1;
    }
     if(caractere=='5'){
        return 1;
    }
     if(caractere=='6'){
        return 1;
    }
     if(caractere=='7'){
        return 1;
    }
     if(caractere=='8'){
        return 1;
    }
     if(caractere=='9'){
        return 1;
    }
    return 0;
}
