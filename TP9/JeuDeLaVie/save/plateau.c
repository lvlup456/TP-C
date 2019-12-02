/**
 * @file plateau.c
 * @author Durand Thomas
 * @brief ensemble des fonctions permettant de gerer le plateu (initialisation et affichage)
 * @version 0.1
 * @date 2019-10-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief ouvre un fichier 
 * 
 * @param path chemin du fichier 
 * @return FILE* 
 */
FILE* lireFichier(char* path){
    FILE* fichier = NULL;
    fichier = fopen(path, "r+");
    if (fichier == NULL){
        printf("Impossible d'ouvrir le fichier\n");
        exit(EXIT_SUCCESS);
    }
    return fichier;
}

/**
 * @brief calcule la taille de la matrice 
 * 
 * @param path chemin du fichier 
 * @return int 
 */
int calculeN(char* path){
    FILE* fichier = lireFichier(path);
    char ligne[200];
    fgets(ligne,200,fichier);
    printf("%s",ligne);
    int i = 0;
    int N;
    while (ligne[i] != '\n'){
        if(ligne[i] != ' '){
            N ++;
        }
        i++;
    }
    fclose(fichier);
    return N;
}

/**
 * @brief initialise la matrice de jeu
 * 
 * @param N taille de la matrice  
 * @param path chemin du fichier
 * @return int** 
 */
int** init(int N,char* path){
    int** plateau = malloc(N*sizeof(int));
    for (int i = 0; i < N; i++){
        plateau[i] = malloc(N*sizeof(int));
    }
    FILE* fichier = lireFichier(path);
    char ligne[200];
    int placei = 1;
    int placej = 1;
    int j;
    for (int i = 1; i < N; i++){
        fgets(ligne,200,fichier);
        j=0;
        while (ligne[j] != '\n'){
            if (ligne[j] == 48){
                plateau[placei][placej] = 0;
                placej++;        
            }else if (ligne[j] == 49){
                plateau[placei][placej] = 1;                
                placej++;
            }
            j++;
        }
        placej = 1;
        placei++;
    }
    return plateau;
}


/**
 * @brief affichage de la matrice 
 * 
 * @param plateau matrice de jeu
 * @param N  taille de la matrice
 */
void affichage(int** plateau,int N){
    system("clear");
    printf("%d\n",N);
    for (int i = 1; i < N; i++){
            printf("+---");
    }
    printf("+\n");
    for (int i = 1; i < N; i++){
        for (int j = 1; j < N; j++){
            if (plateau[j][i] == 0){
                printf("|   ");
            }else{
                printf("| %d ",plateau[j][i]);                
            }
        }
        printf("|\n");
        for (int i = 1; i < N; i++){
            printf("+---");
        }
        printf("+\n");
    }
}
