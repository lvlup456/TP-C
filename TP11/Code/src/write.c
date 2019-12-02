#include <stdio.h> 
#include <stdlib.h>
#include "structures.h"

//marche pas encore :/

void retourLigne(int nbr,int* pose,FILE* fichier){
	if (nbr < 10){
		*pose += 4;
	}else if (nbr < 100){
		*pose += 5;
	}else{
		*pose += 6;
	}
	if (*pose >= 70){
		*pose = 0;
		if (nbr < 10){
			*pose += 4;
		}else if (nbr < 100){
			*pose += 5;
		}else{
			*pose += 6;
		}
		fprintf(fichier,"\n"); 
	}
}

void sortieImage(sImage image){ 
    
    FILE* fichier = NULL;
	fichier = fopen("./P1.pbm","w");
    if(fichier == NULL){
      printf("Error!");   
      exit(1);             
   	}

	char* type;

	if (image.type == '1'){
		type = "P1 ";
	}else if (image.type == '2'){
		type = "P2 ";
	}else{
		type = "P3 ";
	}

	fprintf(fichier, "%s \n",type); 

	fprintf(fichier, "%d %d \n", image.largeur, image.hauteur); 

	if (image.type == '2' || image.type == '3'){
		fprintf(fichier, "%d \n", image.valMax); 
	}

	int* pose = malloc(sizeof(int));
	*pose = 0;
    for (int j = 0; j < image.hauteur; j++){
        for (int i = 0; i < image.largeur  ; i++){
			retourLigne(image.image[i][j].r,pose,fichier);
			fprintf(fichier, "%d ", image.image[i][j].r);
			if (image.type == '3'){
				retourLigne(image.image[i][j].v,pose,fichier);
				fprintf(fichier, "%d ", image.image[i][j].v);
				retourLigne(image.image[i][j].b,pose,fichier);
				fprintf(fichier, "%d ", image.image[i][j].b);
			}
		}
	} 
	fclose(fichier); 
} 
