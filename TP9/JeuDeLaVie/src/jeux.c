/**
 * @file jeux.c
 * @author Durand Thomas
 * @brief ensemble des fonctions permetant le calcul d'une iteration de la grille
 * @version 0.1
 * @date 2019-10-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief change les coordonnes passe en parametre pour permettre d'avoir une grille torique 
 * 
 * @param x coordonne a change
 * @param N taille de la matrice
 * @return int 
 */
int bonneCoord(int x,int N){
    if (x < 1){
        return N;
    }else if (x > N){
        return 1;
    }else{
        return x;
    }
}

/**
 * @brief compte le nombre de cellule voisine  a une cellule
 * 
 * @param tab matrice de jeu
 * @param x coordonne x
 * @param y coordonne y
 * @param X taille X de la matrice
 * @param Y taille Y de la matrice
 * @return int 
 */
int compteCellulesVoisines(int** tab,int x, int y, int X,int Y){
    int rez = 0;
    for (int i = -1; i < 2; i++){
        for (int j = -1; j < 2; j++){
            if (i != 0 || j != 0){
                //inversion X Y
                int xtemp = bonneCoord(x + i,Y);
                int ytemp = bonneCoord(y + j,X);
                if (tab[xtemp][ytemp] == 1){
                    rez += 1;
                }
            }
        }
    }
    return rez;
} 

/**
 * @brief calcule la nouvelle valeur d'une cellule apres un tour de jeu
 * 
 * @param tab matrice de jeu 
 * @param x coordonne x
 * @param y coordonne y
 * @param X taille X de la matrice
 * @param Y taille Y de la matrice
 * 
 * @return int 
 */
int calculerNouvelleValeur(int** tab,int x ,int y,int X,int Y){

    int voisin = compteCellulesVoisines(tab,x,y,X,Y);

    if (tab[x][y] == 1){
        if (voisin == 2 || voisin ==3){
            return 1;
        }else{
            return 0;
        }
    }else{
        if (voisin == 3){
            return 1;
        }else{
            return 0;
        }
    }
}

/**
 * @brief calcule la nouvelle grille apres un tour de jeu
 * 
 * @param tab matrice de jeu
 * @param X taille X de la matrice
 * @param Y taille Y de la matrice
 */
void calculerNouvelleGrille(int** tab,int X,int Y){
    int** nvltab = malloc(Y*sizeof(int*));
    for (int i = 0; i <= Y; i++){
        nvltab[i] = malloc(X*sizeof(int));
    }

    for (int i = 1; i <= Y; i++){
        for (int j = 1; j <= X; j++){
            nvltab[i][j] = calculerNouvelleValeur(tab,i,j,X,Y); 
        }
    }

    for (int i = 1; i <= Y; i++){
        for (int j = 1; j <= X; j++){
            tab[i][j] = nvltab[i][j];   
        }
    }
    free(nvltab);
}