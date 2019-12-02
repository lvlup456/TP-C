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

int saisiEnier(){
    int n,test;
    test = scanf("%d",&n);
    if (test == 1){
        return n;
    }else{
        printf("rentre un vrai numero\n");
        exit(EXIT_SUCCESS);
    }
}

/**
 * @brief preuve de concept des differents tris
 * 
 * @return int 
 */
int main(int argc, char const *argv[]){

    if (argc != 2){
        printf("veillez rentre un parametre pour ctrypter\n");
        return 0;
    }

    char mot[100];
    
    if (strcmp(argv[1],"cesar") == 0){
        printf("le mot: ");
        fgets (mot, 100, stdin);
        printf("le decalage: ");
        int decalage = saisiEnier();
        cryptageCesar(decalage,mot);
        printf("le mot crypte est : ");
        printf("%s\n",mot);
    }else if (strcmp(argv[1],"vigenere") == 0){
        printf("le mot: ");
        fgets (mot, 100, stdin);
        char cle[200];
        printf("la cle: ");
        fgets (cle, 100, stdin);
        cryptageVigenere(cle,mot);
        printf("le mot crypte est : ");
        printf("%s\n",mot);
    }else if (strcmp(argv[1],"scytale") == 0){
        printf("le mot: ");
        fgets (mot, 100, stdin);
        mot[strlen(mot)-1]='\0';
        char* nvxMot = cryptageScytale(mot);
        printf("le mot crypte est : %s\n",nvxMot);
    }else{
        printf("veillez rentre un parametre correcte\n");
    }
    

    return 0;
}
