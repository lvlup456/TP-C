/**
 * @file tab1d.c
 * @author Durand Thomas
 * @brief ensemble des fonctions de l'exercice 1
 * @version 0.1
 * @date 2019-11-12
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#define N 20

/**
 * @brief cherche un element dans le tableau et renvoie son id
 * 
 * @param tab 
 * @param num 
 * @return int 
 */
int chercheElement(int tab[N], int num){
    for (int i = 0; i < N; i++){
        if (tab[i] == num){
            return i;
        }
    }
    return -1;
}

/**
 * @brief inverse un tableau
 * 
 * @param tab 
 */
void inverseTab(int tab[N]){
    int temp;
    for (int i = 0; i < (N / 2); i++){
        temp = tab[i];
        tab[i] = tab[N-i-1];
        tab[N-i-1] = temp;
    }
}

/**
 * @brief affiche un tableau
 * 
 * @param tab 
 */
void afficheTab(int tab[N]){
    printf("\n");
    for (int i = 0; i < N; i++){
        printf(" %d ",tab[i]);
    }
    printf("\n");
}

/**
 * @brief addition deux vecteur et met le resultat dans un troisieme
 * 
 * @param tab1 
 * @param tab2 
 * @param tabRes 
 */
void somme(int tab1[N],int tab2[N],int tabRes[N]){
    for (int i = 0; i < N; i++){
        tabRes[i] = tab1[i] + tab2[i];
    }
}