/**
 * @file main.c
 * @author Durand Thomas
 * @brief main qui permet de lancer le jeux de la vie grace au chemin d'un fichier d'initialisation de plateau
 * @version 0.1
 * @date 2019-10-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#include "plateau.h"
#include "jeux.h"
/**
 * @brief main qui lance le jeux de la vie en fonction d'un fichier de config
 * 
 * @param argc nombre d'arguments 
 * @param argv 1: chemin du fichier de configuration
 * @return int 
 */
int main(int argc, char *argv[]){

    if (argc == 2){
        char* path = argv[1];
        int X = calculeX(path);
        int Y = calculeY(path);
        int** plateau = init(X,Y,path);
        while (1){
            affichage(plateau,X,Y);
            calculerNouvelleGrille(plateau,X,Y);
            sleep(1);
        }
    }else{
        printf("veillez rentre un fichier d'initialisation\n");
    }
}
