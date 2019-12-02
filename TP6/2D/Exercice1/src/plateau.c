/**
 * @file plateau.c
 * @author Durand Thomas
 * @brief ensemble des fonctions lie au plateau
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
 * @brief initialise le plateau de N*N a -1
 * 
 * @param plateau 
 */
void init(int plateau[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            plateau[i][j] = -1;
        }
    }
}
/**
 * @brief fonction d'affichage du plateau de N*N
 * 
 * @param plateau 
 */
void affichage(int plateau[N][N]){

    printf("    ");
    for (int i = 0; i < N; i++){
        printf("%d   ",i);
    }
    printf("\n");
    printf("  +");
    for (int i = 0; i < N; i++){
        printf("---+");
    }
    printf("\n");
    for (int i = 0; i < N; i++){
        printf("%d ",i);
        for (int j = 0; j < N; j++){
            if (plateau[j][i] == -1){
                printf("|   ");
            }else{
                printf("| %d ",plateau[j][i]);                
            }
            
        }
        printf("|\n");
        printf("  +");
        for (int i = 0; i < N; i++){
            printf("---+");
        }
        printf("\n");
    }
}

/**
 * @brief joue un pion et le fait tomber tout en bas 
 * 
 * @param plateau 
 * @param joueur 
 * @param colone 
 * @return int 
 */
int jouer(int plateau[N][N],int joueur, int colone){
    if( colone < 0 || colone > N){
        return 2;
    }else if ((plateau[colone][0] != -1)){
        return 1;
    } 

    int i = 0;
    while ((i < N) && (plateau[colone][i] == -1)){
        i ++;
    }
    plateau[colone][i-1] = joueur;
    return 0;
}