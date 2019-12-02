/**
 * @file partie2.c
 * @author Durand Thomas
 * @brief ensemble des fonction de la 2eme partie du td
 * @version 0.1
 * @date 2019-10-14
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <stdio.h>
#include <stdlib.h>

#include "plusGrand.h"
/**
 * @brief affiche un jolie sapin de n de longueur
 * 
 * @param n 
 */
void afficheSapin(int n){
    if (n <=1){
        n =2;
    }
    int debut = n - 1;
    int fin = n + 1;
    
    for (int i = 0; i < n; i++){
        for (int j =0 ; j < debut; j++ ){
            printf(" ");
        }
        for (int j = debut ; j < fin-1; j++ ){
            printf("*");
        }
        for (int j = fin ; j < n; j++ ){
            printf(" ");
        }
        printf("\n");
        debut--;
        fin++;
    }
    debut = n - 2;
    fin = n + 2;
    for (int i = 0; i < 3; i++)
    {
        for (int j =0 ; j < debut; j++ ){
            printf(" ");
        }
        for (int j = debut ; j < fin-1; j++ ){
            printf("@");
        }
        for (int j = fin ; j < n; j++ ){
            printf(" ");
        }
        printf("\n");
    }
    
}
/**
 * @brief affiche le rang auquel la factoriel est superieur a k
 * 
 * @param k 
 * @return int 
 */
int maxFact(int k){
    int facto = 0;
    int rang = 0;
    do{
        rang++;
        facto = factoriel(rang);
    } while (facto < k);
    return rang;
}
/**
 * @brief affiche l'ecriture binaire d'un nombre
 * 
 * @param n 
 */
void binaire(int n){
    int k;
    for (int i = 31; i >= 0; i--)
    {
        k = n >> i; 
        if (k & 1){
            printf("1");
        }
        else{
            printf("0");
        }
    }
    printf("\n");
}

/**
 * @brief calcule le coefficient binomiale avec n et p
 * 
 * @param n 
 * @param p 
 * @return int 
 */
int coefBinomiale(int n,int p){
    if (n == p || n < p){
        return 0;
    }else{    
        int res;
        res = factoriel(n)/(factoriel(n-p)*factoriel(p));
        return res;    
    }
}

/**
 * @brief verifie si un nombre est Amstrong ou pas 
 * @param n 
 */
void estAmstrong(int n){

    int test = n;
    int i = 1;
    int pos = 0;
    int aAjouter;
    int res=0;

    while (i < n){
        i = i * 10;
    }
    
    while (n > 0){
        aAjouter = n/i;
        n = n - (aAjouter*i);
        res += aAjouter * aAjouter * aAjouter ;  
        pos++;
        i = i / 10;
    }
    
    if (res == test){
        printf("oui il l'est \n");
    }else{
        printf("non il ne l'est pas \n");
    }
}