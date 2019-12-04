#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "struct.h"
#include "affichage.h"


void printMain(int taille,carte* main){
    for (int i = 0; i < taille; i++){
        printf("%d\t",i);
        printf("%d\t",main[i].val);

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

void printPlie(int taille,carte* main,int premierJoueur){
    for (int i = 0; i < taille; i++){
        printf("%d\t",(premierJoueur+i)%4);
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

void printPartie(carte* jeux,int tailleJeux,int premierJoueur){

    printf("Voici le jeux en cours:\n");
    printPlie(tailleJeux,jeux,premierJoueur);

} 