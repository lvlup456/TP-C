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
    int i,pose = 0;
    while((lenCarre*lenCarre) < lenchaine){
        lenCarre++;
    }
    char* nvlChaine = malloc((lenCarre*lenCarre + 1)*sizeof(char) );

    while((lenCarre*lenCarre) != i){
        if (pose >= lenchaine || chaine[pose] == '\0'){
            nvlChaine[i] = 32;
        }else{
            nvlChaine[i] = chaine[pose];
        }
        pose += lenCarre;
        if ((pose >= (lenCarre*lenCarre))){
            pose = (pose % (lenCarre*lenCarre)) + 1;
        }
        i++;
    }    
    nvlChaine[i] = '\0';
    return nvlChaine;
}
