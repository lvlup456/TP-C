#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "struct.h"
#include "init.h"
#include "affichage.h"

carte* initDeck(){

    carte* deck = malloc((13*4)* sizeof(carte));

    for (int i = 1; i <= 13; i++){
        for (int j = 1; j <= 4; j++){
            deck[13*(j-1) + (i-1)].coul = j;
            deck[13*(j-1) + (i-1)].val = i;
        }
    }
    return deck;
}

joueur initJoueur(){
    joueur player;
    player.tailleMain = 13;
    player.points = 0;
    player.main = malloc(13*sizeof(carte));
    return player;
}

carte* retirePioche(carte* deck,int taille,int emplacement){
    carte* nvxDeck = malloc(sizeof(carte)*(taille-1));
    int place = 0;
    for (int i = 0; i < taille; i++){
        if (i != emplacement){
            nvxDeck[place] = deck[i];
            place++;
        }
    }
    free(deck);
    return nvxDeck;
}

void distributCarte(joueur* table,carte* deck){
    srand(time(NULL));
    int poseMain = 0;
    int player = 0;
    int pose;
    int taille = 52;
    for (int i = 0; i < 13*4; i++){
        pose = rand() % taille;
        table[player].main[poseMain] = deck[pose];
        deck = retirePioche(deck,taille,pose);
        taille--;
        player++;
        if (player >= 4){
            player = 0;
            poseMain++;
        }
    }    
}


joueur* init(){
    carte* deck = initDeck();
    joueur* table = malloc(sizeof(joueur)*4);
    for (int i = 0; i < 4; i++){
        table[i] = initJoueur();
    }
    distributCarte(table,deck);
    
    return table;
}

