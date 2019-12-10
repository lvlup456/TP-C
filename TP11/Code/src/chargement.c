/**
 * @file chargement.c
 * @author Durand Thomas
 * @brief ensemble des fonctions lie au chargement d'une image
 * @version 0.1
 * @date 2019-12-10
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "structures.h"
#include "transformation.h"

/**
 * @brief affiche la matrice d'une image
 * 
 * @param image 
 */
void afficheImage(sImage image){

    printf("largeur : %d  hauteur : %d \n",image.largeur,image.hauteur);
    printf("%d\n",image.image[1][1].r);
    
    for (int j = 0; j < image.hauteur; j++){
        for (int i = 0; i < image.largeur  ; i++){
            printf(" %d ",image.image[i][j].r);
            if (image.type == '3'){
                printf(" %d ",image.image[i][j].v);
                printf(" %d ",image.image[i][j].b);
            }
            printf("   ");
        }
        printf("\n");
    }
}

/**
 * @brief verifie si un caracthere est un nombre
 * 
 * @param caractere 
 * @return int 
 */
int isNumber(int caractere){
    if ((48 <= caractere && 57 >= caractere) || caractere == 45){
        return 1;
    }else{
        return 0;
    }
}

/**
 * @brief ouvre un fichier
 * 
 * @param path 
 * @return FILE* 
 */
FILE* lireFichier(char* path){
    FILE* fichier = NULL;
    fichier = fopen(path, "r+");
    if (fichier == NULL){
        printf("Impossible d'ouvrir le fichier : %s\n",path);
        exit(EXIT_SUCCESS);
    }
    return fichier;
}

/**
 * @brief transforme un char en int
 * 
 * @param ligne 
 * @param pose 
 * @return int 
 */
int charToInt(char* ligne,int* pose){
    char ligneRes[10];
    int i = 0;
    while(isNumber(ligne[*pose]) == 1 && ligne[*pose] != '\n'){
        ligneRes[i] = ligne[*pose];
        i++;
        *pose += 1;
    }
    ligneRes[i] = '\0';
    return atoi(ligneRes);
}

/**
 * @brief trouve la pose du prochain numero
 * 
 * @param pose 
 * @param ligne 
 * @param fichier 
 */
void getProchain(int* pose,char* ligne,FILE* fichier){
    while (isNumber(ligne[*pose]) == 0){
        *pose += 1;
        if (*pose > 70){
            *pose = 0;
            fgets(ligne,200,fichier);
        }
    }
}

/**
 * @brief ouvre une image et la transforme en une matrice
 * 
 * @param fichier 
 * @param type 
 * @return sImage 
 */
sImage regroupement(FILE* fichier,int type){
    sImage image;
    int test = 0;
    char ligne[200];
    int* pointPose = malloc(sizeof(int));
    fgets(ligne,200,fichier);
    //parse largeur et hauteur pour tlm
    while (ligne[0] != EOF && test == 0){
        if (ligne[0] != '#'){
            *pointPose = 0;
            getProchain(pointPose,ligne,fichier);
            image.largeur = charToInt(ligne,pointPose);
            getProchain(pointPose,ligne,fichier);
            image.hauteur = charToInt(ligne,pointPose);
            test = 1;
        }
        fgets(ligne,200,fichier);
    }
    //val Max pour 2 et 3
    if (type == 2 || type == 3 ){
        test = 0;
        while (ligne[0] != EOF && test == 0){
            if (ligne[0] != '#'){
                *pointPose = 0;
                getProchain(pointPose,ligne,fichier);
                image.valMax = charToInt(ligne,pointPose);
                test = 1;
            }
            fgets(ligne,200,fichier);
            *pointPose = 0;
        }
    }

    //init matrice avec largeur et hauter
    image.image = malloc((image.largeur +1 ) * sizeof(sPixel*));
    for (int i = 0; i <= image.largeur; i++){
        image.image[i] = malloc(image.hauteur * sizeof(sPixel));
    }
 
    for (int j = 0; j < image.hauteur; j++){
        for (int i = 0; i < image.largeur  ; i++){
            image.image[i][j].r = 0;
            image.image[i][j].v = 0; 
            image.image[i][j].b = 0; 
        }
    }
    int val;
    for (int j = 0; j < image.hauteur; j++){
        for (int i = 0; i < image.largeur  ; i++){
            getProchain(pointPose,ligne,fichier);
            val = charToInt(ligne,pointPose);
            if (type == 2 || type == 1){
                image.image[i][j].r = val;
                image.image[i][j].v = val;
                image.image[i][j].b = val;
            }else{
                image.image[i][j].r = val;
                getProchain(pointPose,ligne,fichier);
                val = charToInt(ligne,pointPose);
                image.image[i][j].v = val;
                getProchain(pointPose,ligne,fichier);
                val = charToInt(ligne,pointPose);
                image.image[i][j].b = val;
            }
        }
    }
    free(pointPose);
    return image;
}

/**
 * @brief charge une image
 * 
 * @param path 
 * @return sImage 
 */
sImage chargementMemoire(char* path){
    FILE* fichier = lireFichier(path);  
    sImage image;  
    int test = 0;
    char ligne[200];
    fgets(ligne,75,fichier);
    while (ligne[0] != EOF && test ==0){
        if (ligne[0] != '#'){
            if (ligne[1] == '1'){
                //marche pas 
                image = regroupement(fichier,1);                
                image.type = '1';
            }else if (ligne[1] == '2'){
                image = regroupement(fichier,2);                
                image.type = '2';
            }else if (ligne[1] == '3'){
                image = regroupement(fichier,3);
                image.type = '3';
            }else{
                printf("ya un soucis dans l'entete du fichier \n");
                exit(EXIT_SUCCESS);
            }
            test = 1;
        }
        fgets(ligne,75,fichier);
    }
    return image;

}
/**
 * @brief affiche le noyau d'une matrice
 * 
 * @param noyau 
 */
void afficheNoyau(sNoyau noyau){
    for (int i = 0 ; i < noyau.taille;i++){
        for (int j = 0 ; j < noyau.taille;j++){
            printf("%d",noyau.matrice[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief charge un noyau de matrice
 * 
 * @param path 
 * @return sNoyau 
 */
sNoyau chargementNoyau(char* path){
    FILE* fichier = lireFichier(path);  
    sNoyau noyau;
    char ligne[100];
    fgets(ligne,100,fichier);
    int* pose = malloc(sizeof(int));
    *pose = 0;
    noyau.taille = 3;
    
    noyau.matrice = malloc((noyau.taille ) * sizeof(int*));
    for (int i = 0; i <= noyau.taille; i++){
        noyau.matrice[i] = malloc(noyau.taille * sizeof(int));
    }    

    for (int i = 0 ; i < noyau.taille;i++){
        for (int j = 0 ; j < noyau.taille;j++){
            noyau.matrice[i][j] = 0;
        }
    }

    for (int i = 0 ; i < noyau.taille;i++){
        for (int j = 0 ; j < noyau.taille;j++){
            getProchain(pose,ligne,fichier);
            noyau.matrice[i][j] = charToInt(ligne,pose);
        }
        fgets(ligne,100,fichier);
        *pose = 0;
    }
    afficheNoyau(noyau);

    free(pose);

    return noyau;
}

