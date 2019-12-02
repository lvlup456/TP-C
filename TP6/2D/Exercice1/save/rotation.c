#include <stdio.h>
#include <stdlib.h>

#include "constant.h" 


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

void descendre(int tableau[N][N],int x,int y,int pion){
    tableau[x][y] = -1;
    while ((y < N) && (tableau[x][y] == -1)){
        y ++;
    }
    tableau[x][y-1] = pion;
}

void gravite(int tableau[N][N]){
    for(int i = N-1;i >= 0; i--){
        for(int j = N-1;j >= 0; j--){
            descendre(tableau,i,j,tableau[i][j]);
        }
    }
}

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