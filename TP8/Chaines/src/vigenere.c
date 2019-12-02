/**
 * @file vigenere.c
 * @author Durand Thomas
 * @brief ensemble des fonctions lie a Vigenere
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
 * @brief cryptage de Vigenere
 * 
 * @param cle cle de cryptage 
 * @param chaine chaine a crypter
 */
void cryptageVigenere(char* cle, char* chaine){
    int j = 0;
    int lencle = strlen(cle);
    //passe la cle en minuscule
    for (int i = 0; i < lencle; i++){
        if (cle[i] >= 65 && cle[i] <= 90){
            cle[i] += 32;
        }
    }
    for (int i = 0; i < strlen(chaine);i++){
        if (chaine[i] != 32){
            //minuscule
            if (chaine[i] >= 97 && chaine[i] <= 122){
                chaine[i] = (chaine[i] + (cle[j] - 97)) % 122;
                if (chaine[i] < 97){
                    chaine[i] += 97;
                }
            }else if (chaine[i] >= 65 && chaine[i] <= 90){
                chaine[i] = (chaine[i] + (cle[j] - 97)) % 90;
                if (chaine[i] < 65){
                    chaine[i] += 65;
                }
            }
            j++;
            j = j % lencle;
        }
    }
}
/**
 * @brief decryptage de Vigenere
 * 
 * @param cle cle de cryptage 
 * @param chaine chaine a decrypter
 */
void decryptageVigenere(char* cle, char* chaine){
    int j = 0;
    int lencle = strlen(cle);
    //passe la cle en minuscule
    for (int i = 0; i < lencle; i++){
        if (cle[i] >= 65 && cle[i] <= 90){
            cle[i] += 32;
        }
    }
    
    for (int i = 0; i < strlen(chaine);i++){
        if (chaine[i] != 32){
            //minuscule
            if (chaine[i] >= 97 && chaine[i] <= 122){
                chaine[i] = chaine[i] - (cle[j] - 97);
                if (chaine[i] < 97){
                    chaine[i] = 122 - (97 - chaine[i]);
                }
            }else if (chaine[i] >= 65 && chaine[i] <= 90){
                chaine[i] = chaine[i] - (cle[j] - 97);
                if (chaine[i] < 65 ){
                    chaine[i] = 90 -(65 - chaine[i]);
                }
                
            }
            j++;
            j = j % lencle;
        }
    }
}