#include <stdio.h>
#include <stdlib.h>


#include "struct.h"
#include "init.h"
#include "affichage.h"
#include "regles.h"
#include "deroulement.h"

int main(){
    joueur* table = init();
    
    partieEnCours* jeuxEnCours = initPartieEnCours();
    carte* deck;

    while (testAGagne(table) == 1){
        int premierJoueur = trouve2Trefle(table);
        int partie = 1;
        while (partie != 13){
            for (int i = premierJoueur; i < premierJoueur+4; i++){
                if (i%4 == 0){
                    deroulementTourJoueur(table,i%4,jeuxEnCours,premierJoueur);
                }else{
                    deroulementTourIA(table,i%4,jeuxEnCours,premierJoueur);   
                }        
            }
            reporterPlie(table,jeuxEnCours,premierJoueur);
            partie++;
        }
        calculePoints(table,jeuxEnCours);
        deck = initDeck();
        distributCarte(table,deck);       
    }
    return 0;
}
