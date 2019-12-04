#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#include "regles.h"
#include "affichage.h"
#include "struct.h"


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

    plateau[0].main[carte1] = temp1;
    plateau[0].main[carte2] = temp2;
    plateau[0].main[carte3] = temp3;

}

void echangeDeCarte(int tour, joueur* plateau){
    
    if (tour != 3){
        printf("voici votre main:\n");
        printMain(13,plateau[0].main);
        int carte1 = -1;
        int carte2 = -1;
        int carte3 = -1;
        while (carte1 < 13 && carte1 >=0 && carte2 < 13 && carte2 >=0 && carte3 < 13 && carte3 >=0){
            printf("quelles cartes voulez vous echanger?\n");
            printf("rentrez la carte 1:\n");
            carte1 = saisiEnier();
            printf("rentrez la carte 3:\n");
            carte2 = saisiEnier();
            printf("rentrez la carte 2:\n");
            carte3 = saisiEnier();
        }

        switch (tour)
        {
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

int aCouleurDansMain(carte* main,int tailleMain,couleurs couleurActuel){
    for (int i = 0; i < tailleMain; i++){
        if (main[i].coul == couleurActuel){
            return 1 ;
        }
    }
    return 0;
}

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

void ajoutPlie(int joueurQuiGagne, partieEnCours* jeuxEnCours){
    carte* nvxPlieGagne = malloc(sizeof(carte) * (4+jeuxEnCours->taillePlieRemporte[joueurQuiGagne]));
    for (int i = 0; i < jeuxEnCours->taillePlieRemporte[joueurQuiGagne]; i++){
        nvxPlieGagne[i] = jeuxEnCours->plieRemporte[joueurQuiGagne][i];
    }
    for (int i = 0; i < 4; i++){
        nvxPlieGagne[i+jeuxEnCours->taillePlieRemporte[joueurQuiGagne]] = jeuxEnCours->plie[i];
    }
    free(jeuxEnCours->plie);
    jeuxEnCours->taillePartie = 0;    
}

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

int prisToutPlies(partieEnCours* jeuxEnCours){
    for (int i = 0; i < 4; i++){
        if (jeuxEnCours->taillePlieRemporte[i] == 52){
            return i;
        }
    }
    return -1;
}

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

int testAGagne(joueur* plateau){
    for (int i = 0; i < 4; i++){
        if (plateau[i].points >= 50){
            printf("le joueur %d a gagne ave %d points",i,plateau[i].points);
            exit(EXIT_FAILURE);
        }
    }
    return 1; 
}