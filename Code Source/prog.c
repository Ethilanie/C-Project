#include "fonctions.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define RESET		0
#define BRIGHT 		1
#define DIM			2
#define UNDERLINE 	3
#define BLINK		4
#define REVERSE		7
#define HIDDEN		8

#define BLACK 		0
#define RED			1
#define GREEN		2
#define YELLOW		3
#define BLUE		4
#define MAGENTA		5
#define CYAN		6
#define	WHITE		7


int main(int argc, char* argv[]){

	int nombre_elements = 1000;
	double probabilite = 0.5;
	int opt, nbopt;
	int affichehauteur=0;
	int affichetexte = 0;
	int affichegraph = 0;
	int afficherecherche=0;
	int affichelongueur = 0;
	
	int opt_f=0;
	char* fichier;
	CL* elemtemp;
	nbopt=1;
	L* skipList;
	int* val_elements;
	skipList = creerTete();
	printf("-----------------------PROGRAMME----------------------\n");
	while ((opt = getopt(argc, argv, "h:p:f:n:ohltri")) != -1) {
		switch (opt) {
			case 'h' :
				AfficherAide();	
				nbopt++;
				break;
			case 'p':
				nbopt++;
				probabilite = atof(argv[nbopt]);
				nbopt++;
				break;
			case 'n': //nombre d'éléments a inserer
				nbopt++;
				nombre_elements = atoi(argv[nbopt]);
				nbopt=nbopt+1;
				break;
			case 'f' : //fichier
				nbopt++;
				fichier = argv[nbopt];
				printf("file : %s\n", fichier);
				nbopt=nbopt+1;
				opt_f=1;
				break;
			case 'o': //nombre d'éléments a inserer
				if(strchr (argv[nbopt], 'h')!=NULL){
					affichehauteur=1;
				}
				if(strchr (argv[nbopt], 'l')!=NULL){
					affichelongueur=1;
				}
				if(strchr (argv[nbopt], 't')!=NULL){
					affichetexte=1;
				}
				if(strchr (argv[nbopt], 'r')!=NULL){
					afficherecherche=1;
				}
				if(strchr (argv[nbopt], 'i')!=NULL){
					affichegraph=1;
				}
				break;
		}

	}
	printf("probabilite : %f, nb elements : %d \n", probabilite, nombre_elements);
	textcolor(UNDERLINE,MAGENTA, BLACK );	
    
	if(opt_f==0){ //si l'utilisateur n'a pas choisi de fichier
		val_elements = tableauAleatoire(nombre_elements);
	}else{
		val_elements = tableauFichier(fichier, &nombre_elements);
	}
	if(val_elements ==NULL){
		printf("erreur, tableau d'element NULL\n");
		return EXIT_FAILURE;
	}

	//on remplit la skiplist
    skipList = boucleAjout(skipList,val_elements,nombre_elements,probabilite);
	//on verifie les differentes options
	
	if(affichehauteur==1){
		printf("hauteur: %d\n", hauteur(skipList));
	}
	if(affichelongueur==1){
		//a faire
	}
	if(affichetexte==1){
		afficheListe(skipList);
	}
	if(afficherecherche==1){
		//a faire
	}
	if(affichegraph==1){
		printf("La fonction affichage graphique n'est pas disponible \n");
	}

	return EXIT_SUCCESS;
}
