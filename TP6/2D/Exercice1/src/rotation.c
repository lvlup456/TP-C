/**
 * @file rotation.c
 * @author Durand Thomas
 * @brief ensemble des fonctions lie a la rotation
 * @version 0.1
 * @date 2019-11-12
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <stdio.h>
#include <stdlib.h>

#include "constant.h" 

/**
 * @brief applique une rotation de 90 degre a la matrice
 * 
 * @param tableau 
 */
void rotation(int tableau[N][N]){

    for (int x = 0; x < N / 2; x++){
        for (int y = x ; y < N - x - 1; y++){
            int temp = tableau[x][y]; 
            tableau[x][y] = tableau[y][N-1-x]; 
            tableau[y][N-1-x] = tableau[N-1-x][N-1-y]; 
            tableau[N-1-x][N-1-y] = tableau[N-1-y][x]; 
            tableau[N-1-y][x] = temp; 
        }
    }
}
/**
 * @brief fais tomber un pions jusqu'a qu'il soit tout en bas
 * 
 * @param tableau 
 * @param x 
 * @param y 
 * @param pion 
 */
void descendre(int tableau[N][N],int x,int y,int pion){
    tableau[x][y] = -1;
    while ((y < N) && (tableau[x][y] == -1)){
        y ++;
    }
    tableau[x][y-1] = pion;
}

/**
 * @brief applique la gravite a tout les pions du plateau
 * 
 * @param tableau 
 */
void gravite(int tableau[N][N]){
    for(int i = N-1;i >= 0; i--){
        for(int j = N-1;j >= 0; j--){
            descendre(tableau,i,j,tableau[i][j]);
        }
    }
}

/**
 * @brief deroulement d'une rotation 
 * 
 * @param tableau 
 * @param joueur 
 * @param nbrRotation 
 * @return int 
 */
int deroulementRotaion(int tableau[N][N],int joueur,int nbrRotation){
    if (nbrRotation > 0 ){
        int reponse;
        printf("Voulez vous executer une rotaion? 1 pour oui 0 pour non");
        scanf("%d",&reponse);
        if(reponse == 1){
            rotation(tableau);
            gravite(tableau);
            return 1;
        }else{
            return 0; 
        }
    }
    return 0;
}