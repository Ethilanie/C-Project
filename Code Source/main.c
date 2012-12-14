#include "fonctions.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]){

int opt, nbopt;
int nbVal;
float proba;

nbopt=1;
L* skipList;
skipList = creerTete();
while ((opt = getopt(argc, argv, "tn:")) != -1) {
	switch (opt) {
		case 't':
			//si t, option sans argument 
			nbopt++;
			//printf("lol");
			break;
			
        case 'n': //nombre d'éléments a inserer
            printf("%s", argv[nbopt+1]);
			nbopt=nbopt+1;
			
            break;
		

	}
	
}
ajoutVal(5,skipList, 2);
//ajoutVal(5,skipList, 2);
afficheListe(skipList);
}