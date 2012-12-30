#include "fonctions.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

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

int* val_elements = (int*)malloc(10*sizeof(int));

int i;
for(i=0;i<10;i++){
val_elements[i]=i;
}

skipList = boucleAjout(skipList,val_elements,10,0.2);

afficheListe(skipList);

affichetest(skipList);


    srand(time(NULL));


for(i=0;i<10;i++){
recherche(i, skipList);
}

}
