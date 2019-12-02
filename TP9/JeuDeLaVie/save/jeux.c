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
        return N-1;
    }else if (x >= N){
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
 * @param N taille de la matrice
 * @return int 
 */
int compteCellulesVoisines(int** tab,int x, int y, int N){
    int rez = 0;
    for (int i = -1; i < 2; i++){
        for (int j = -1; j < 2; j++){
            if (i != 0 || j != 0){
                int xtemp = bonneCoord(x + i,N);
                int ytemp = bonneCoord(y + j,N);
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
 * @param N taille de la matrice
 * @return int 
 */
int calculerNouvelleValeur(int** tab,int x ,int y,int N){
    int voisin = compteCellulesVoisines(tab,x,y,N);
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
 * @param N taille de la matrice
 */
void calculerNouvelleGrille(int** tab,int N){
    int** nvltab = malloc(sizeof(int)*N);
    for (size_t i = 0; i < N; i++){
        nvltab[i] = malloc(sizeof(int)*N);
    }

    for (int i = 1; i < N; i++){
        for (int j = 1; j < N; j++){
            nvltab[i][j] = calculerNouvelleValeur(tab,i,j,N);   
        }
    }

    for (int i = 1; i < N; i++){
        for (int j = 1; j < N; j++){
            tab[i][j] = nvltab[i][j];   
        }
    }
    free(nvltab);
}