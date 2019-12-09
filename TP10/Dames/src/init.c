/**
 * @file init.c
 * @author Durand Thomas
 * @brief ensemble des fonctions lie a l'initialisation d'une partie
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
#include "init.h"
#include "affichage.h"

/**
 * @brief initialise un deck
 * 
 * @return carte* 
 */
carte* initDeck(){
    carte* deck = malloc((13*4)* sizeof(carte));
    for (int i = 2; i <= 14; i++){
        for (int j = 1; j <= 4; j++){
            deck[13*(j-1) + (i-2)].coul = j;
            deck[13*(j-1) + (i-2)].val = i;
        }
    }
    return deck;
}

/**
 * @brief initialise un joueur
 * 
 * @return joueur 
 */
joueur initJoueur(){
    joueur player;
    player.tailleMain = 13;
    player.points = 0;
    player.main = malloc(13*sizeof(carte));
    return player;
}
/**
 * @brief retire une carte d'une liste de carte
 * 
 * @param deck 
 * @param taille 
 * @param emplacement 
 * @return carte* 
 */
carte* retirerCarte(carte* deck,int taille,int emplacement){
    carte* nvxDeck = malloc(sizeof(carte)*(taille-1));
    int place = 0;
    for (int i = 0; i < taille; i++){
        if (i != emplacement){
            nvxDeck[place] = deck[i];
            place++;
        }
    }
    //free(deck);
    return nvxDeck;
}
/**
 * @brief distribut le deck au joueurs
 * 
 * @param table 
 * @param deck 
 */
void distributCarte(joueur* table,carte* deck){
    srand(time(NULL));
    int poseMain = 0;
    int player = 0;
    int pose;
    int taille = 52;
    for (int i = 0; i < 13*4; i++){
        pose = rand() % taille;
        table[player].main[poseMain] = deck[pose];
        deck = retirerCarte(deck,taille,pose);
        taille--;
        player++;
        if (player >= 4){
            player = 0;
            poseMain++;
        }
    }    
}

/**
 * @brief initialise touts les joueurs
 * 
 * @return joueur* 
 */
joueur* init(){
    carte* deck = initDeck();
    joueur* table = malloc(sizeof(joueur)*4);
    for (int i = 0; i < 4; i++){
        table[i] = initJoueur();
    }
    distributCarte(table,deck);
    
    return table;
}

/**
 * @brief initialise une partieEnCours
 * 
 * @return partieEnCours* 
 */
partieEnCours* initPartieEnCours(){
    partieEnCours* jeuxEnCours = malloc(sizeof(partieEnCours));
    jeuxEnCours->taillePartie = 0;
    jeuxEnCours->aJouerCoeur = 0;
    jeuxEnCours->coulActuel = 5;
    jeuxEnCours->taillePlieRemporte = malloc(sizeof(int)*4);
    for (int i = 0; i < 4; i++){
        jeuxEnCours->taillePlieRemporte[i] = 0;
    }
    jeuxEnCours->plieRemporte = malloc(4*sizeof(carte*));
    return jeuxEnCours;
}
