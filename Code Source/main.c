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
skipList = ajoutVal(5,skipList, 2);

skipList = ajoutVal(8,skipList, 8);
skipList = ajoutVal(4,skipList, 4);
skipList = ajoutVal(7,skipList, 3);
skipList = ajoutVal(1,skipList, 0);
skipList = ajoutVal(16,skipList, 2);
afficheListe(skipList);

affichetest(skipList);
}