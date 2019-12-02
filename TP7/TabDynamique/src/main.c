/**
 * @file main.c
 * @author Durand Thomas
 * @brief fonction main avec preuve de concept des differents tris
 * @version 0.1
 * @date 2019-11-12
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "triDenombrement.h"
#include "triFusion.h"
#include "trisInsertion.h"
#include "operationTab.h"

/**
 * @brief fonction main pour preuve de concept des tris
 * 
 * @return int 
 */
int main(){
    int N = 20;
    int tab[] = {2,3,7,9,8,6,4,1,2,5,8,9,6,3,4,8,9,6,5,45};

    afficheTab(tab,N);
    printf("tri insertion:\n");
    tri_insertion(tab,N);
    afficheTab(tab,N);

    int tab2[] = {2,3,7,9,8,6,4,1,2,5,8,9,6,3,4,8,9,6,5,45};
    printf("tri fusion:\n");
    triFusion(tab2,N);
    afficheTab(tab2,N);

    int tab3[] = {2,3,7,9,8,6,4,1,2,5,8,9,6,3,4,8,9,6,5,45};
    printf("tri denombrement:\n");
    triDenombrement(tab3,N);
    afficheTab(tab3,N);
}
