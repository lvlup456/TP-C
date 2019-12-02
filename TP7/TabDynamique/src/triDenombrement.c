/**
 * @file triDenombrement.c
 * @author Durand Thomas
 * @brief ensemble des fonction lie au tri par denombrement
 * @version 0.1
 * @date 2019-11-12
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief trouve le min et le max d'un tableau
 * 
 * @param tab le tableau 
 * @param taille taille du tableau
 * @param min pointeur pour le minimum
 * @param max pointeur pour le maximum
 */
void minMaxTableau(int* tab, int taille, int* min, int* max){
    for (int i = 1; i < taille; i++){
        if(tab[i] > *max){
            *max = tab[i];
        }
        if(tab[i] < *min){
            *min = tab[i];
        }
    }
}

/**
 * @brief creer l'histogramme d'un tableau
 * 
 * @param tab le tableau
 * @param taille la taille du tableau
 * @param histo pointeur de l'histogramme a cree
 * @param tailleH taile de l'histogramme
 * @param min valeur min de tab
 */
void histogramme(int* tab, int taille, int* histo, int tailleH, int min){
    for (int i = 0; i < taille; i++){
        histo[tab[i] - min]++;
    }
    int place=0;
    for (int i = 0; i < tailleH;i++){
        for (int j = 0; j < histo[i]; j++){
            tab[place] = i+1;
            place++;
        }
    }
}

/**
 * @brief applique le tri par denombrement sur un tableau
 * 
 * @param tab le tableau
 * @param taille taille du tableau
 */
void triDenombrement(int* tab,int taille){
    int min = tab[0];
    int max = tab[0];

    minMaxTableau(tab,taille,&min,&max);

    int tailleH = (max - min + 1 );
    int* histo = malloc(tailleH * sizeof(int));

    for (int i = 0; i < tailleH; i++){
        histo[i] = 0;
    }

    histogramme(tab,taille,histo,tailleH,min);

    free(histo);
}