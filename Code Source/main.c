#include "fonctions.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char* argv[]){
int nombre_elements = 1000;
double probabilite = 0.5;
int opt, nbopt;
int affiche=0;

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
			affiche=1;

            break;


	}

}
printf("probabilite : %f, nb elements : %d \n", probabilite, nombre_elements);

 int* val_elements = tableauAleatoire(nombre_elements);

   
	
    skipList = boucleAjout(skipList,val_elements,nombre_elements,probabilite);
	
	if(affiche==1){
		afficheListe(skipList);
	}

	//affichetest(skipList);


  
int i =0;
/*
for(i=0;i<10;i++){
	recherche(i, skipList);
}*/

}
