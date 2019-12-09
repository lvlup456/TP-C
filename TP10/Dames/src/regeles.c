/**
 * @file regeles.c
 * @author Durand Thomas
 * @brief ensemble des fonction lie au relgle du jeux
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
#include "struct.h"
#include "init.h"

/**
 * @brief echange de carte avec le joueur d'en face
 * 
 * @param j1 id joueur 1
 * @param j2 id joueur 2
 * @param plateau 
 * @param carte1 carte a echanger
 * @param carte2 carte a echanger
 * @param carte3 carte a echanger
 */
void echangeEnFace(int j1,int j2, joueur* plateau, int carte1, int carte2, int carte3){
    carte temp;
    temp = plateau[j1].main[carte1];
    plateau[j1].main[carte1] = plateau[j2].main[carte1];
    plateau[j2].main[carte1] = temp;

    temp = plateau[j1].main[carte2];
    plateau[j1].main[carte2] = plateau[j2].main[carte2];
    plateau[j2].main[carte2] = temp;

    temp = plateau[j1].main[carte3];
    plateau[j1].main[carte3] = plateau[j2].main[carte3];
    plateau[j2].main[carte3] = temp;
}
/**
 * @brief echange les carte avec le joueur de droite
 * 
 * @param plateau 
 * @param carte1 carte a echanger
 * @param carte2 carte a echanger
 * @param carte3 carte a echanger
 */
void echangeDroite(joueur* plateau,int carte1,int carte2,int carte3){

    carte temp1 = plateau[1].main[carte1];
    carte temp2 = plateau[1].main[carte2];
    carte temp3 = plateau[1].main[carte3];

    plateau[1].main[carte1] = plateau[0].main[carte1];
    plateau[1].main[carte2] = plateau[0].main[carte2];
    plateau[1].main[carte3] = plateau[0].main[carte3];

    carte temp4 = plateau[2].main[carte1];
    carte temp5 = plateau[2].main[carte2];
    carte temp6 = plateau[2].main[carte3];

    plateau[2].main[carte1] = temp1;
    plateau[2].main[carte2] = temp2;
    plateau[2].main[carte3] = temp3;

    temp1 = plateau[3].main[carte1];
    temp2 = plateau[3].main[carte2];
    temp3 = plateau[3].main[carte3];

    plateau[3].main[carte1] = temp4;
    plateau[3].main[carte2] = temp5;
    plateau[3].main[carte3] = temp6;

    plateau[0].main[carte1] = temp1;
    plateau[0].main[carte2] = temp2;
    plateau[0].main[carte3] = temp3;
}
/**
 * @brief echange les carte avec le joueur de gauche
 * 
 * @param plateau 
 * @param carte1 carte a echanger
 * @param carte2 carte a echanger
 * @param carte3 carte a echanger
 */
void echangeGauche(joueur* plateau,int carte1,int carte2,int carte3){

    carte temp1 = plateau[0].main[carte1];
    carte temp2 = plateau[0].main[carte2];
    carte temp3 = plateau[0].main[carte3];

    plateau[0].main[carte1] = plateau[3].main[carte1];
    plateau[0].main[carte2] = plateau[3].main[carte2];
    plateau[0].main[carte3] = plateau[3].main[carte3];

    carte temp4 = plateau[2].main[carte1];
    carte temp5 = plateau[2].main[carte2];
    carte temp6 = plateau[2].main[carte3];

    plateau[2].main[carte1] = temp1;
    plateau[2].main[carte2] = temp2;
    plateau[2].main[carte3] = temp3;

    temp1 = plateau[1].main[carte1];
    temp2 = plateau[1].main[carte2];
    temp3 = plateau[1].main[carte3];

    plateau[1].main[carte1] = temp4;
    plateau[1].main[carte2] = temp5;
    plateau[1].main[carte3] = temp6;

    plateau[3].main[carte1] = temp1;
    plateau[3].main[carte2] = temp2;
    plateau[3].main[carte3] = temp3;
}
/**
 * @brief gere l'echnage de carte en demandant a l'utilisateur
 * 
 * @param tour tour en cours
 * @param plateau 
 */
void echangeDeCarte(int tour, joueur* plateau){
    if (tour != 3){
        printf("voici votre main:\n");
        printMain(13,plateau[0].main);
        int carte1 = -1;
        int carte2 = -1;
        int carte3 = -1;
        while ((carte1 > 13 || carte1 <=0) || (carte2 > 13 || carte2 <= 0) || (carte3 > 13 || carte3 <=0) || carte1 == carte2 || carte2 == carte3 || carte3 == carte1){
            printf("quelles cartes voulez vous echanger?\n");
            printf("rentrez la carte 1:\n");
            carte1 = saisiEnier();
            printf("rentrez la carte 2:\n");
            carte2 = saisiEnier();
            printf("rentrez la carte 3:\n");
            carte3 = saisiEnier();
        }
        switch (tour){
            case 0:
                echangeDroite(plateau,carte1,carte2,carte3);
                break;
            case 1:
                echangeGauche(plateau,carte1,carte2,carte3);
                break;
            case 2:
                echangeEnFace(0,3,plateau,carte1,carte2,carte3);
                echangeEnFace(2,1,plateau,carte1,carte2,carte3);
                break;
            default:
                break;
        }
    }
}
/**
 * @brief trouve le joueur qui possede le 2 de trefle
 * 
 * @param plateau 
 * @return int revoie id joueur
 */
int trouve2Trefle(joueur* plateau){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 13; j++){
            if (plateau[i].main[j].coul == TREFLE && plateau[i].main[j].val == DEUX){
                return i;
            }
        }   
    }
    return -1;
}
/**
 * @brief regarde si le joeur possede une certaine couleur dans sa main
 * 
 * @param main main du joueur
 * @param tailleMain taille de la main
 * @param couleurActuel couleur a trouver
 * @return int boolean
 */
int aCouleurDansMain(carte* main,int tailleMain,couleurs couleurActuel){
    for (int i = 0; i < tailleMain; i++){
        if (main[i].coul == couleurActuel){
            return 1 ;
        }
    }
    return 0;
}
/**
 * @brief test si une carte est jouable
 * 
 * @param couleurActuel couleur du jeux actuel
 * @param defauseCoeur boolean si un coeur a deja ete joue
 * @param main main du joueru
 * @param tailleMain taille main joueur
 * @param carteAJouer carte que le joueur veux jouer
 * @param tailleCartePrecedentes taille du plie
 * @return int 
 */
int estJouable(couleurs couleurActuel, int defauseCoeur,carte* main,int tailleMain,int carteAJouer, int tailleCartePrecedentes){
    //premiere carte jouer
    if (tailleCartePrecedentes == 0){
        //different coeur ou damme de pique
        if (main[carteAJouer].coul != COEUR && (main[carteAJouer].coul != PIQUE || main[carteAJouer].val != DAME)){
            return 1;
        //coeur deja defauser
        }else if(defauseCoeur == 1){
            return 1;
        }else{
            return 0;
        }
    //pas premiere carte a jouer
    }else{
        //couleur carte = couleur plie actuel
        if (main[carteAJouer].coul == couleurActuel){
            return 1;
        //a une carte de la couleur du plie dans la main
        }else if(aCouleurDansMain(main,tailleMain,couleurActuel) == 1){
            return 0;
        //n'as pas de carte de la couleur du plie dans la main
        }else{
            return 1;
        }
    }
}
/**
 * @brief ajoute le plie au plie gagne par le joueur
 * 
 * @param joueurQuiGagne joueur qiui a gagne le plie
 * @param jeuxEnCours 
 */
void ajoutPlie(int joueurQuiGagne, partieEnCours* jeuxEnCours){
    carte* nvxPlieGagne = malloc(sizeof(carte) * (4+jeuxEnCours->taillePlieRemporte[joueurQuiGagne]));
    for (int i = 0; i < jeuxEnCours->taillePlieRemporte[joueurQuiGagne]; i++){
        nvxPlieGagne[i] = jeuxEnCours->plieRemporte[joueurQuiGagne][i];
    }
    for (int i = 0; i < 4; i++){
        nvxPlieGagne[i+jeuxEnCours->taillePlieRemporte[joueurQuiGagne]] = jeuxEnCours->plie[i];
    }
    jeuxEnCours->plieRemporte[joueurQuiGagne] = nvxPlieGagne;
    jeuxEnCours->taillePlieRemporte[joueurQuiGagne] += 4;
    //free(jeuxEnCours->plie);
    jeuxEnCours->taillePartie = 0;    
}

/**
 * @brief remporte le plis par un joueur 
 * 
 * @param plateau 
 * @param jeuxEnCours 
 * @param premierJoueur 
 */
void reporterPlie(joueur* plateau,partieEnCours* jeuxEnCours,int premierJoueur){
    int joueurQuiGagne = 0;

    for (int i = 0; i < jeuxEnCours->taillePartie; i++){
        if (jeuxEnCours->plie[i].coul == jeuxEnCours->coulActuel && jeuxEnCours->plie[i].val > jeuxEnCours->plie[joueurQuiGagne].val){
            joueurQuiGagne = i;
        }
    }
    system("clear");
    printf("\n\nle Joueur %d remporte le plie\n\n",(premierJoueur+joueurQuiGagne)%4);
    sleep(2);
    ajoutPlie((premierJoueur+joueurQuiGagne)%4,jeuxEnCours);
}

/**
 * @brief regarde si un joueur a pris tout les plies
 * 
 * @param jeuxEnCours 
 * @return int 
 */
int prisToutPlies(partieEnCours* jeuxEnCours){
    for (int i = 0; i < 4; i++){
        if (jeuxEnCours->taillePlieRemporte[i] == 52){
            return i;
        }
    }
    return -1;
}

/**
 * @brief calcule les points apres un jeux
 * 
 * @param plateau 
 * @param jeuxEnCours 
 */
void calculePoints(joueur* plateau,partieEnCours* jeuxEnCours){
    int testToutPris = prisToutPlies(jeuxEnCours);
    if ( testToutPris == -1){
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < jeuxEnCours->taillePlieRemporte[i]; j++){
                if (jeuxEnCours->plieRemporte[i][j].coul == COEUR){
                    plateau[i].points += 1;
                }else if(jeuxEnCours->plieRemporte[i][j].coul == PIQUE && jeuxEnCours->plieRemporte[i][j].val == DAME){
                    plateau[i].points += 13;
                }
            }
        }
    }else{
        for (int i = 0; i < 4; i++){
            if (i != testToutPris){
                plateau[i].points += 26;
            }
        }
    }
}

/**
 * @brief test si un joueur a gagne
 * 
 * @param plateau 
 * @return int 
 */
int testAGagne(joueur* plateau){
    for (int i = 0; i < 4; i++){
        if (plateau[i].points >= 50){
            printf("le joueur %d a gagne ave %d points \n",i,plateau[i].points);
            return 0;
        }
    }
    return 1; 
}

/**
 * @brief reinitialise la partie pour en accuellir une nouvelle
 * 
 * @param jeuxEnCours 
 */
void reinitialisationPartieEnCours(partieEnCours* jeuxEnCours){
    jeuxEnCours->taillePartie = 0;
    jeuxEnCours->aJouerCoeur = 0;
    for (int i = 0; i < 4; i++){
        jeuxEnCours->taillePlieRemporte[i] = 0; 
        jeuxEnCours->plieRemporte[i] = malloc(0);
    }
}

/**
 * @brief reinitialise la table pour accuellir une nouvelle partie
 * 
 * @param table 
 */
void reinitialisationTable(joueur* table){
    carte* deck = initDeck();
    distributCarte(table,deck);
    for (int i = 0; i < 4; i++){
        table[i].tailleMain = 13;
    }
}