/**
 * @file triInsertion.c
 * @author Durand Thomas
 * @brief ensemble des fonxtions lie au tri par insertion
 * @version 0.1
 * @date 2019-11-12
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <stdio.h>
#include <stdlib.h>


/**
 * @brief execute le tri par insertion sur un tableau
 * 
 * @param t le tableau
 * @param len la longueur du tableau
 */
void tri_insertion(int* t,int len){
    int i, j;
    int temp;
 
    for (i = 1; i < len; i++) {
        temp = t[i];
        for (j = i; j > 0 && t[j - 1] > temp; j--) {
            t[j] = t[j - 1];
        }
        t[j] = temp;
    }
}
