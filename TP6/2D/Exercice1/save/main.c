/**
 * @file main.c
 * @author Durand Thomas
 * @brief 
 * @version 0.1
 * @date 2019-10-15
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "plateau.h"
#include "logique.h"
#include "rotation.h"
#include "constant.h"
 

int main(){
    int plateau[5][5];
    int joueur,rep,testJouer,testRot;

    printf("combien de rotaion voulez vous par joueuer?\n");
    int rotation;
    scanf("%d",&rotation);
    int tabRotaion[2] = {rotation,rotation};
    
    init(plateau);
    joueur = 1;
    while(1){
        affichage(plateau);
        do{ 
            printf("joueur %d a toi de jouer, tu veux placer ton pion dans quel collone?",joueur);
            scanf("%d",&rep);
            testJouer = jouer(plateau,joueur,rep);
            if (testJouer == 1){
                printf("desole, il n'y a plus de place sur cette ligne\n");
            }else if(testJouer == 2){
                printf("desole, mais vous avez essayez de jouer hors du plateau\n");
            }   
        }while(testJouer != 0);
        
        if (aGagner(plateau) == 1){
            affichage(plateau);
            printf("Bravo joueur %d tu as gagner!!! \n",joueur);
            exit(EXIT_SUCCESS);
        }

        testRot = deroulementRotaion(plateau,joueur,tabRotaion[joueur-1]);
        
        if (testRot == 1 && aGagner(plateau) == 1){
            affichage(plateau);
            printf("Bravo joueur %d tu as gagner!!! \n",joueur);
            exit(EXIT_SUCCESS);
        }

        joueur = (joueur % 2) + 1;
    }
    return 0;
}
