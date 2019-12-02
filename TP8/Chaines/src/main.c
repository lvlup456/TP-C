/**
 * @file main.c
 * @author Durand Thomas
 * @brief fonction main avec preuve de concept des differents tri
 * @version 0.1
 * @date 2019-11-18
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "cesar.h"
#include "vigenere.h"
#include "scytale.h"

/**
 * @brief preuve de concept des differents tris
 * 
 * @return int 
 */
int main(){

    char chaine[20] = "coucou a tous";

    cryptageCesar(8,chaine);
    printf("%s\n",chaine);
    decryptageCesar(8,chaine);
    printf("%s\n",chaine);

    char cle[20] = "teSt";
    char chaine2[20] = "couCou A toUs";
    cryptageVigenere(cle,chaine2);
    
    printf("%s\n",chaine2);
    decryptageVigenere(cle,chaine2);
    printf("%s\n",chaine2);

    char* chaine3 = malloc(37*sizeof(char));
    strcpy(chaine3,"RENDEZ VOUS DEMAIN SOIR A LA TIREUSE");
    
    chaine3 = cryptageScytale(chaine3);
    printf("%s\n",chaine3);
    chaine3 = cryptageScytale(chaine3);
    printf("%s\n",chaine3);


    return 0;
}
