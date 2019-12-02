#include <stdio.h>
#include <stdlib.h>

#include "constant.h"

void init(int plateau[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            plateau[i][j] = -1;
        }
    }
}
 
void affichage(int plateau[N][N]){

    printf("    0   1   2   3   4\n");
    printf("  +---+---+---+---+---+\n");
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
        printf("  +---+---+---+---+---+\n");
    }
}

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