/**
 * @file cesar.c
 * @author Durand Thomas
 * @brief ensemble des fonctions de cesar
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
 * @brief cryptage de cesar
 * 
 * @param decalage decalage de la chaine 
 * @param chaine chaine a crypter
 */
void cryptageCesar(int decalage,char* chaine){
    for (int i = 0; i < strlen(chaine);i++){
        if (chaine[i] != 32){
            //minuscule
            if (chaine[i] >= 97 && chaine[i] <= 122){
                chaine[i] = chaine[i] + decalage;
                if (chaine[i] > 122){
                    chaine[i] = (chaine[i] % 122) + 97;
                }
            }else if (chaine[i] >= 65 && chaine[i] <= 90){
                chaine[i] = chaine[i] + decalage;
                if (chaine[i] > 90){
                    chaine[i] = (chaine[i] % 90) + 65;
                }
            }
        }
    }
}

/**
 * @brief decryptage de cesar
 * 
 * @param decalage decalage de la chaine
 * @param chaine chaine a decypter
 */
void decryptageCesar(int decalage,char* chaine){
    for (int i = 0; i < strlen(chaine);i++){
        if (chaine[i] != 32){
            //minuscule
            if (chaine[i] >= 97 && chaine[i] <= 122){
                chaine[i] = chaine[i] - decalage;
                if (chaine[i] < 97){
                    chaine[i] = 122 - (97 - chaine[i]);
                }
            }else if (chaine[i] >= 65 && chaine[i] <= 90){
                chaine[i] = chaine[i] + decalage;
                if (chaine[i] < 65 ){
                    chaine[i] = 90 -(65 - chaine[i]);
                }
            }
        }
    }
}