/**
 * @file main.c
 * @author Durand Thomas
 * @brief fonction main avec exemple d'utilisation des fonctins demande dans le TD
 * @version 0.1
 * @date 2019-11-12
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "tab1d.h"
#include "chaine.h"

#define N 20


int main(){

    int tab1[N],tab2[N],tabRes[N];

    for (int i = 0; i < N; i++){
        tab1[i] = i;
        tab2[i] = i;
        tabRes[i] = 0;
    }
    inverseTab(tab1);
    somme(tab1,tab2,tabRes);
    afficheTab(tabRes);
    
    char chaine[] = "coucou je m'appele Thomas";

    printf("longueur chaine: %d\n",longueurChaine(chaine));
    
    afficheChaine(chaine);    
    supprimeChar(chaine);
    afficheChaine(chaine);


    return 0;
}
