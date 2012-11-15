#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fonctions.h"

int nbpiles(float prob){
    int face = 0;
    int res = -1;
    float n;
    //srand(time(NULL));
    while(face==0){
        res++;
        n = rand()%(100);
        if(n>=prob*100){
            face=1;
        }
    }
    return res;
}

int main(int argc, char*argv[]){
    int i;
    for(i=0; i<10;i++){
        printf("%d\n",nbpiles(0.5));
    }
}
