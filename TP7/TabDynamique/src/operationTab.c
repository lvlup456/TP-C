/**
 * @file operationTab.c
 * @author Durand Thomas
 * @brief ensemble des fonctions lie au tableau
 * @version 0.1
 * @date 2019-11-12
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief affichage d'un tableau
 * 
 * @param tab tableau a afficher
 * @param len longueur du tableau
 */
void afficheTab(int tab[],int len){
    for (int i = 0; i < len; i++){
        printf(" %d ",tab[i]);
    }
    printf("\n");
}