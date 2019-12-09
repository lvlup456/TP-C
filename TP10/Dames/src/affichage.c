/**
 * @file affichage.c
 * @author Durand Thomas
 * @brief ensembles des fonctions lie a l'affichage 
 * @version 0.1
 * @date 2019-12-09
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "struct.h"
#include "affichage.h"

/**
 * @brief affiche une main
 * 
 * @param taille 
 * @param main 
 */
void printMain(int taille,carte* main){
    for (int i = 0; i < taille; i++){
        printf("%d\t",i);
        switch (main[i].val){
        case 14:
            printf(" As ");
            break;
        case 2:
            printf(" Deux ");
            break;
        case 3:
            printf(" Trois ");
            break;
        case 4:
            printf(" Quatre");
            break;
        case 5:
            printf(" Cinque");
            break;
        case 6:
            printf(" Six ");
            break;
        case 7:
            printf(" Sept ");
            break;
        case 8:
            printf(" Huit ");
            break;
        case 9:
            printf(" Neuf ");
            break;
        case 10:
            printf(" Dix ");
            break;
        case 11:
            printf(" Valet ");
            break;
        case 12:
            printf(" Dame ");
            break;
        case 13:
            printf(" Roix ");
            break;
        default:
            printf(" ya pb... ");
            break;
        }
        
        
        switch (main[i].coul){
        case 3:
            printf("\t\ttrefle ");
            break;
        case 1:
            printf("\t\tpique ");
            break;
        case 2:
            printf("\t\tcoeur ");
            break;
        case 4:
            printf("\t\tcarreau ");
            break;
        default:
            printf("\t\tya pb...");
            break;
        }
        printf("\n");
    }
}

/**
 * @brief affiche le plie en cours
 * 
 * @param taille 
 * @param main 
 * @param premierJoueur 
 */
void printPlie(int taille,carte* main,int premierJoueur){
    for (int i = 0; i < taille; i++){
        printf("joueur: %d\t",(premierJoueur+i)%4+1);
        switch (main[i].val){
            case 2:
                printf(" Deux ");
                break;
            case 3:
                printf(" Trois ");
                break;
            case 4:
                printf(" Quatre");
                break;
            case 5:
                printf(" Cinque");
                break;
            case 6:
                printf(" Six ");
                break;
            case 7:
                printf(" Sept ");
                break;
            case 8:
                printf(" Huit ");
                break;
            case 9:
                printf(" Neuf ");
                break;
            case 10:
                printf(" Dix ");
                break;
            case 11:
                printf(" Valet ");
                break;
            case 12:
                printf(" Dame ");
                break;
            case 13:
                printf(" Roix ");
                break;
            case 14:
                printf(" As ");
                break;
            default:
                printf(" ya pb... ");
                break;
        }
        
        
        switch (main[i].coul){
        case 3:
            printf("\t\ttrefle ");
            break;
        case 1:
            printf("\t\tpique ");
            break;
        case 2:
            printf("\t\tcoeur ");
            break;
        case 4:
            printf("\t\tcarreau ");
            break;
        default:
            printf("\t\tya pb...");
            break;
        }
        printf("\n");
    }
}

/**
 * @brief fonction pour saisir un entier
 * 
 * @return int 
 */
int saisiEnier(){
    int n,test;
    test = scanf("%d",&n);
    if (test == 1){
        return n;
    }else{
        printf("rentrez un vrai numero svp \n");
        exit(EXIT_SUCCESS);
    }
}

/**
 * @brief affiche une partie
 * 
 * @param jeux 
 * @param tailleJeux 
 * @param premierJoueur 
 */
void printPartie(carte* jeux,int tailleJeux,int premierJoueur){

    printf("Voici le jeux en cours:\n");
    printPlie(tailleJeux,jeux,premierJoueur);

} 