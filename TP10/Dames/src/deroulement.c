#include <stdio.h>
#include <stdlib.h>

#include "regles.h"
#include "affichage.h"
#include "deroulement.h"



void deroulementTourJoueur(joueur* table,int numJoueur,carte* jeuxEnCours,int tailleJeuxEnCours){
    
    printPartie(jeuxEnCours,tailleJeuxEnCours);
    printMain(table[numJoueur].tailleMain,table[numJoueur].main);

    int idCarte = -1;
    while (idCarte <= -1 && idCarte > table[numJoueur].tailleMain){
        idCarte = saisiEnier();
    }

}