#include "fonctions.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

int main(int argc, char* argv[]){
int nombre_elements = 1000;
double probabilite = 0.5;
int opt, nbopt;
int affichehauteur=0;
int affichetexte = 0;
int affichegraph = 0;
nbopt=1;
L* skipList;
skipList = creerTete();
while ((opt = getopt(argc, argv, "p:n:ohltri")) != -1) {
	switch (opt) {
		case 'p':
			//si t, option sans argument
			nbopt++;
			probabilite = atof(argv[nbopt]);
			//printf("%s", argv[nbopt]);
			nbopt++;
			break;

        case 'n': //nombre d'éléments a inserer
            //printf("%s", argv[nbopt+1]);
			nbopt++;
			nombre_elements = atoi(argv[nbopt]);
			nbopt=nbopt+1;

            break;
		case 'o': //nombre d'éléments a inserer
			printf("%s", argv[nbopt]);
			getchar();
			if(strchr (argv[nbopt], 'h')!=NULL){
				affichehauteur=1;
			}
			if(strchr (argv[nbopt], 't')!=NULL){
				affichetexte=1;
			}
			if(strchr (argv[nbopt], 'i')!=NULL){
				affichegraph=1;
			}
            break;


	}

}
printf("probabilite : %f, nb elements : %d \n", probabilite, nombre_elements);

 int* val_elements = tableauAleatoire(nombre_elements);

   
	
    skipList = boucleAjout(skipList,val_elements,nombre_elements,probabilite);
	
	if(affichetexte==1){
		afficheListe(skipList);
	}
	if(affichehauteur==1){
		printf("hauteur: %d\n", hauteur(skipList));
	}
	if(affichegraph==1){
		printf("La fonction affichage graphique n'est pas disponible \n");
	}
	
  
int i =0;

for(i=9;i<19;i++){
	printf("recherche : : %d ",recherche(i, skipList));
}



}
