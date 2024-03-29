/**
 * @file deroulement.c
 * @author Durand Thomas
 * @brief ensemble des fonctions lie au deroulement d'une partie
 * @version 0.1
 * @date 2019-12-09
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#include "regles.h"
#include "affichage.h"
#include "deroulement.h"
#include "init.h"
#include "struct.h"

/**
 * @brief ajoute un ecarte au jeux en cours
 * 
 * @param jeuxEnCours 
 * @param nvlcarte 
 * @param taille 
 * @return carte* 
 */
carte* ajouterCarte(carte* jeuxEnCours,carte nvlcarte,int taille){
    carte* nvxJeuxEnCours = malloc((taille+1)*sizeof(carte));
    for (int i = 0; i < taille; i++){
        nvxJeuxEnCours[i] = jeuxEnCours[i];
    }
    nvxJeuxEnCours[taille] = nvlcarte;
    return nvxJeuxEnCours;
}

/**
 * @brief update la partie en cours
 * 
 * @param jeuxEnCours 
 * @param table 
 * @param numJoueur 
 * @param idCarte 
 */
void updatePartieEncours(partieEnCours* jeuxEnCours,joueur* table,int numJoueur,int idCarte ){

    jeuxEnCours->plie = ajouterCarte(jeuxEnCours->plie,table[numJoueur].main[idCarte],jeuxEnCours->taillePartie);
    jeuxEnCours->taillePartie ++;

    if (jeuxEnCours->taillePartie == 1){
        jeuxEnCours->coulActuel = jeuxEnCours->plie[0].coul;
    }
    if (jeuxEnCours->aJouerCoeur == 0 && table[numJoueur].main[idCarte].coul == COEUR ){
        jeuxEnCours->aJouerCoeur = 1;
    }
}

/**
 * @brief deroulement du tour d'un joueur
 * 
 * @param table 
 * @param numJoueur 
 * @param jeuxEnCours 
 * @param premierJoueur 
 */
void deroulementTourJoueur(joueur* table,int numJoueur,partieEnCours* jeuxEnCours,int premierJoueur){
    system("clear");
    printf("Vous avez actuellement %d points\n\n",table[numJoueur].points);
    printPartie(jeuxEnCours->plie,jeuxEnCours->taillePartie,premierJoueur);
    printf("\n\nvoici votre main:\n");
    printMain(table[numJoueur].tailleMain,table[numJoueur].main);

    int idCarte = -1;
    printf("\n\n");
    while (idCarte <= -1 || idCarte > table[numJoueur].tailleMain || (0 == estJouable(jeuxEnCours->coulActuel,jeuxEnCours->aJouerCoeur,table[numJoueur].main,table[numJoueur].tailleMain,idCarte,jeuxEnCours->taillePartie))){
        printf("quelle carte voulez vous jouer?\n");
        idCarte = saisiEnier();
    }
    
    updatePartieEncours(jeuxEnCours,table,numJoueur,idCarte);

    table[numJoueur].main = retirerCarte(table[numJoueur].main,table[numJoueur].tailleMain,idCarte);
    table[numJoueur].tailleMain --;

}

/**
 * @brief deroulement du tour d'une IA
 * 
 * @param table 
 * @param numJoueur 
 * @param jeuxEnCours 
 * @param premierJoueur 
 */
void deroulementTourIA(joueur* table,int numJoueur,partieEnCours* jeuxEnCours,int premierJoueur){
    system("clear");
    int idCarte = 0;
    while (0 == estJouable(jeuxEnCours->coulActuel,jeuxEnCours->aJouerCoeur,table[numJoueur].main,table[numJoueur].tailleMain,idCarte,jeuxEnCours->taillePartie)){
        idCarte++;
    }
    
    updatePartieEncours(jeuxEnCours,table,numJoueur,idCarte);

    table[numJoueur].main = retirerCarte(table[numJoueur].main,table[numJoueur].tailleMain,idCarte);
    table[numJoueur].tailleMain --;
    printPartie(jeuxEnCours->plie,jeuxEnCours->taillePartie,premierJoueur);
    printf("le joueur %d a %d points\n",numJoueur+1,table[numJoueur].points);
    sleep(1);
}