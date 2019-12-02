#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** tabDePascale(int n){
    int** matrice = malloc(n*sizeof(int*));
    for(int i =0; i < n ; i++){
        matrice[i] = malloc((i+1)*sizeof(int));
    }
    for(int i =0;i <n ;i++){
        matrice[i][0] = 1;
        for(int j = 1; j < i+1; j++){
            if(j < i ){
                matrice[i][j] = matrice[i-1][j] + matrice[i-1][j-1];
            }else{
                matrice[i][j] = matrice[i-1][j-1];
            }
        }
    }
    return matrice;
}

int chance(int n){
    srand(time(NULL));
    int ok = 0;
    int* tab = malloc(n*sizeof(int));
    for (int i =0; i < n; i++){
        tab[i] = 0;
    }

    int nbrEssaies = 0;
    int aleatoire;
    while (ok != n){
        aleatoire = rand() % n;
        if (tab[aleatoire] == 0){
            tab[aleatoire] = 1;
            ok++;
        }
        nbrEssaies++;
    }
    free(tab);
    printf("nbr : %d\n",nbrEssaies);
    return nbrEssaies;
}

int decalage(){
    int n = 10;
    int* tab = {0,3,5,6,8,7,4,5,2,1};
    int decalage = 3;

    int* nvxtab = malloc(n*sizeof(int));
    for (int i = 0; i < n; i++){
        nvxtab[i] = tab[]
    }
}

int main(){
    
    
    int** matrice = tabDePascale(8);

    for(int i =0;i < 8 ;i++){
        printf("ligne %d      ",i);
        for(int j = 0; j < i+1; j++){    
            printf(" %d ",matrice[i][j]);
        }
        printf("\n");
    }

    chance(15);

}
