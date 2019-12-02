/**
 * @file plusGrand.c
 * @author Durand Thomas
 * @brief ensemble des fonction demande dans la partie 1 du Tp3
 * @version 0.1
 * @date 2019-10-14
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief demande un int a l'utilisateur
 * 
 * @return int 
 */
int saisiEnier(){
    int n,test;
    test = scanf("%d",&n);
    if (test == 1){
        return n;
    }else{
        printf("rentre un vrai numero stp chef \n");
        exit(EXIT_SUCCESS);
    }
}

/**
 * @brief affiche la table de multiplication d'un entier demande
 * 
 * @param n 
 */
void tabMultiplication(int n){
    for (int i = 1; i <= 10; i++)
    {
        printf("%d * %d = %d\n",i,n,i*n);
    }
}

/**
 * @brief solveur d'equation par dicotomie
 * 
 */
void solEquation(){
    float calcule,x,a,b;
    a = -15;
    b = -10;
    
    do{    
        x = (a + b)/2;
        calcule = x*x*x + 12*x*x + 1;
        if (calcule <= 0){
            a = (a+b)/2;
        }else{
            b = (a+b)/2;
        }
    } while (calcule > 0.00001 || calcule < -0.00001);
    printf("[%f,%f]\n",a,b);
}
/**
 * @brief fonction factoriel recursive
 * 
 * @param n 
 * @return int 
 */
long long int factoriel(long long int n){
    if (n == 0){
        return 1;
    }else{
        return factoriel(n-1) * n;
    }
}

