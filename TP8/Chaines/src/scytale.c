/**
 * @file scytale.c
 * @author Durand Thomas
 * @brief ensemble des fonctions lie a Scytale
 * @version 0.1
 * @date 2019-11-18
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief cryptage et decryptage de Scytale
 * 
 * @param chaine chaine a crypter ou decrypter 
 * @return char* 
 */
char* cryptageScytale(char* chaine){

    int lenchaine = strlen(chaine);
    int lenCarre = 1;
    int pose = 0;
    while((lenCarre*lenCarre) < lenchaine){
        lenCarre++;
    }
    char** matrice = malloc(lenCarre*sizeof(char*));
    for (int i = 0; i < lenCarre; i++){
        matrice[i] = malloc(lenCarre*sizeof(char));
    }

    for (int i = 0; i < lenCarre; i++){
        for (int j = 0; j < lenCarre; j++){
            if (pose < lenchaine){
                matrice[i][j] = chaine[pose];
                pose++;
            }else{
                matrice[i][j] = 32;
            }
        }    
    }
    char* nvlChaine = malloc(lenCarre*lenCarre*sizeof(char));
    pose = 0;
    for (int i = 0; i < lenCarre; i++){
        for (int j = 0; j < lenCarre; j++){
            nvlChaine[pose] = matrice[j][i];
            pose++;
        }
    }
    return nvlChaine;
}
