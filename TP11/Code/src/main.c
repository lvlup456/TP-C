#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "structures.h"
#include "chargement.h"
#include "transformation.h"
#include "write.h"


int main(int argc, char **argv){

    char* out = NULL;
    char* in = NULL;
    char* matrice = NULL;
    int gris;
    int seuil[2]= {0,0};
    int i = 0;
    while (i < argc){
        if (strcmp(argv[i],"-in") == 0){
            in = malloc(strlen(argv[i+1]));
            strcpy(in,argv[i+1]);
        }else if(strcmp(argv[i],"-out") == 0){
            out = malloc(strlen(argv[i+1]));
            strcpy(out,argv[i+1]);
        }else if(strcmp(argv[i],"-gris") == 0){
            gris = 1;
        }else if(strcmp(argv[i],"-seuil") == 0){
            seuil[0] = 1;
            seuil[1] = atoi(argv[i+1]);
            i += 1; 
        }else if (strcmp(argv[i],"-matrice") == 0){
            matrice = malloc(strlen(argv[i+1]));
            strcpy(matrice,argv[i+1]);
        }
        i++;
    }


    if (in == NULL){
        printf("veillez rentre une image SVP\n");
        exit(EXIT_SUCCESS);
    }else{
        sImage image = chargementMemoire(in);
        if (gris == 1){
            niveauDeGris(image);
        }
        if (matrice != NULL){
            sNoyau noyau = chargementNoyau(matrice);
            applyMatrice(noyau,image);
        }
        if (seuil[0] != 0){
            seuillage(image,seuil[1]);
        }        
        if (out != NULL){
            sortieImage(image);
        }
    }
    
    return 0;
}
