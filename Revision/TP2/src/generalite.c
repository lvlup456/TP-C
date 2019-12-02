#include <stdio.h>
#include <stdlib.h>

#include "generalite.h"


float** allouerMatrice(int n, int m){
    float** matrice = malloc(n * sizeof(float));
    for (int i = 0; i < n; i++){
        matrice[i] = malloc(m * sizeof(float));
    } 
    return matrice;
}



