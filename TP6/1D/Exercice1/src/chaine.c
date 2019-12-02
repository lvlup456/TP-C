/**
 * @file chaine.c
 * @author Durand Thomas
 * @brief ensemble des fonctions de l'exercice 2
 * @version 0.1
 * @date 2019-11-12
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief calcule la longueur d'une string
 * 
 * @param chaine 
 * @return int 
 */
int longueurChaine(char chaine[]){
    int i = 0;
    while (chaine[i] != '\0'){
        i++;
    }
    return i;
}

/**
 * @brief suprime les espaces et les tabulations d'une strig
 * 
 * @param chaine 
 */
void supprimeChar(char chaine[]){
    int i = 0;
    int j = 0;
    while (chaine[j] != '\0'){
        if (chaine[j] == ' ' || chaine[j] == 9){
            j++; 
        }
        if (i != j){
            chaine[i] = chaine[j];
        }
        i++;
        j++;
    }
    chaine[i] = '\0';
}

/**
 * @brief affiche une string
 * 
 * @param chaine 
 */
void afficheChaine(char chaine[]){
    printf("%s",chaine);
    printf("\n");
} 