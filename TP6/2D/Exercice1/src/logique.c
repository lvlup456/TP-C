/**
 * @file logique.c
 * @author Durand Thomas
 * @brief ensemble des fonctions de logique du jeux 
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
 * @brief test si une ligne (verticale horizontale diagonale etc...) comporte 4 pions identique (condition de victoire)
 * 
 * @param plateau 
 * @param x 
 * @param y 
 * @param sensx 
 * @param sensy 
 * @param score 
 * @param joueur 
 * @return int 
 */
int testWin(int plateau[N][N],int x,int y, int sensx,int sensy,int score,int joueur){
    x += sensx;
    y += sensy; 
    if (score == 4){
        return 1;
    }else if((x < 0) || (y < 0) || (x > N) || (y > N) || (plateau[x][y] != joueur)){
        return 0;
    }else{
        return testWin(plateau,x,y,sensx,sensy,score+1,joueur);
    }
}

/**
 * @brief applique la fonction testWin dans toutes les directions a tout les points 
 * 
 * @param plateau 
 * @return int 
 */
int aGagner(int plateau[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if(plateau[i][j] != -1){
                for (int k = -1; k < 2; k++){
                    for (int l = -1; l < 2; l++){
                        if (((k != 0) || (l != 0)) && (testWin(plateau,i,j,k,l,1,plateau[i][j]) == 1)){
                            return 1;
                        }
                    }
                }
            }       
        }
    }
    return 0;
}