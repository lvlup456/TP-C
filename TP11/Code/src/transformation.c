/**
 * @file transformation.c
 * @author Durand Thomas
 * @brief enseble des fonctions lie a la transformation d'une image
 * @version 0.1
 * @date 2019-12-10
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
/**
 * @brief transforme une image en niveaux de gris
 * 
 * @param image 
 * @return sImage 
 */
sImage niveauDeGris(sImage image){
    int val;
    for (int j = 0; j < image.hauteur; j++){
        for (int i = 0; i < image.largeur  ; i++){
            val =  0.299*image.image[i][j].r + 0.587*image.image[i][j].v + 0.114*image.image[i][j].b;
            image.image[i][j].r = val;
            image.image[i][j].v = val;
            image.image[i][j].b = val;
        } 
    }
    return image;
}

/**
 * @brief applique le seuille sur une image
 * 
 * @param image 
 * @param val 
 * @return sImage 
 */
sImage seuillage(sImage image,int val){
    for (int j = 0; j < image.hauteur; j++){
        for (int i = 0; i < image.largeur  ; i++){
            if (image.image[i][j].r < val){
                image.image[i][j].r = 0;
                image.image[i][j].v = 0;
                image.image[i][j].b = 0;            
            }else{
                image.image[i][j].r = image.valMax;
                image.image[i][j].v = image.valMax;
                image.image[i][j].b = image.valMax;     
            }
        } 
    }
    return image;
}

/**
 * @brief calcule la nouvelle valeur d'un pixel d'une image 
 * 
 * @param image 
 * @param x 
 * @param y 
 * @param noyau 
 * @param matrice 
 */
void calcValeur(sImage image,int x, int y,sNoyau noyau,sPixel** matrice){

    int valr = 0;
    int valv = 0;
    int valb = 0;

    for (int k = -1 ; k <= 1;k++){
        for (int l = -1 ; l <= 1;l++){
            if ((x+k) > 0 && (x+k) < image.largeur && (y+l) > 0 && (y+l) < image.hauteur ){
                valr += noyau.matrice[k+1][l+1] * image.image[x+k][y+l].r;
                valv += noyau.matrice[k+1][l+1] * image.image[x+k][y+l].v;
                valb += noyau.matrice[k+1][l+1] * image.image[x+k][y+l].b;
            }
        }   
    }
    if (valr > image.valMax){
        valr = image.valMax;
    }
    if (valv > image.valMax){
        valv = image.valMax;
    }    
    if (valb > image.valMax){
        valb = image.valMax;
    }
    if (valr < 0){
        valr = 0;
    }
    if (valv < 0){
        valv = 0;
    }    
    if (valb < 0){
        valb = 0;
    }
    matrice[x][y].r = valr;
    matrice[x][y].v = valv;
    matrice[x][y].b = valb;
}

/**
 * @brief applique une matrice sur l'image
 * 
 * @param noyau 
 * @param image 
 * @return sImage 
 */
sImage applyMatrice(sNoyau noyau, sImage image){
    
    sPixel** matrice = malloc((image.largeur +1 ) * sizeof(sPixel*));
    for (int i = 0; i <= image.largeur; i++){
        matrice[i] = malloc(image.hauteur * sizeof(sPixel));
    }

    for (int j = 1; j < image.hauteur-1; j++){
        for (int i = 1; i < image.largeur-1; i++){
            calcValeur(image,i,j,noyau,matrice);
        }
    }
    for (int j = 0; j < image.hauteur; j++){
        for (int i = 0; i < image.largeur  ; i++){
            image.image[i][j].r = matrice[i][j].r;
            image.image[i][j].v = matrice[i][j].v;
            image.image[i][j].b = matrice[i][j].b;            
        }
    }

    for (int i = 0; i <= image.largeur; i++){
        free(matrice[i]);
    }
    free(matrice);
    return image;
}
