/**
 * @file inutil.c
 * @author Durand Thomas
 * @brief ensemble des fonctions demande dans le TP
 * @version 0.1
 * @date 2019-11-12
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief exercice inutile
 * 
 */
void exerciceInutile(){
    int i = 8;
    int* p = &i;
    *p = 5;
    printf("%d\n",i);
}

void pointDePoint(){
    int a=0;
    int b=1;
    int* p = &a;
    int** pp;
    a += b;
    pp = &p;
    printf("a=%d,p=%d,pp=%d\n",a,*p,**pp);
}

/**
 * @brief imprime les indexs des elements nul
 * 
 */
void moinsFacile(){
    int tab[5] = {1,0,2,0,3};
    int* i;
    int* debut= tab;

    printf("Les positions sont : ");
    for(i=&tab[0];i<&tab[5];i++){
        if (*i == 0){
            printf("%ld ",i - debut + 1);
        }
    }
    printf("\n");
}