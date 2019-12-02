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
 * @brief calcul axe X
 * 
 * @param path chemin du fichier
 * @return int 
 */
int calculeX(char* path){
    FILE* fichier = lireFichier(path);
    char ligne[200];
    fgets(ligne,200,fichier);
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
 * @brief calcul axe Y
 * 
 * @param path chemin du fichier
 * @return int 
 */
int calculeY(char* path){
    FILE* fichier = lireFichier(path);
    int N=1;
    int c;
    for (c = getc(fichier); c != EOF; c = getc(fichier)) 
            if (c == '\n') // Increment count if this character is newline 
                N++;
    fclose(fichier);
    return N;
}

/**
 * @brief initialise la matrice de jeu
 * 
 * @param X taille axe X
 * @param Y taille axe Y
 * @param path chemin du fichier
 * @return int** 
 */
int** init(int X,int Y,char* path){
    int** plateau = malloc(Y*sizeof(int*));
    for (int i = 0; i <= Y; i++){
        plateau[i] = malloc(X*sizeof(int));
    }
    FILE* fichier = lireFichier(path);
    char ligne[200];
    int placei = 1;
    int placej = 1;
    int j;
    for (int i = 1; i <= Y; i++){
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
 * @brief affiche la matrice dan sle terminal
 * 
 * @param plateau matrice de jeu
 * @param X taille axe X
 * @param Y taille axe Y
 */
void affichage(int** plateau,int X,int Y){
    system("clear");
    for (int i = 1; i <= X; i++){
            printf("+---");
    }
    printf("+\n");
    for (int i = 1; i <= Y; i++){
        for (int j = 1; j <= X; j++){
            if (plateau[i][j] == 0){
                printf("|   ");
            }else{
                printf("| %d ",plateau[i][j]);                
            }
        }
        printf("|\n");
        for (int i = 1; i <= X; i++){
            printf("+---");
        }
        printf("+\n");
    }
}
