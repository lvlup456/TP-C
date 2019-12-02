#include <stdio.h>
#include <stdlib.h>

#include "constant.h"


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