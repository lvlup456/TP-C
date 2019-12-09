/**
 * @file main.c
 * @author Durand Thomas
 * @brief fonction main
 * @version 0.1
 * @date 2019-12-09
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "init.h"
#include "affichage.h"
#include "regles.h"
#include "deroulement.h"

/**
 * @brief fonction main qui lance la partie apres initialisation
 * 
 * @return int 
 */
int main(){
    joueur* table = init();
    
    partieEnCours* jeuxEnCours = initPartieEnCours();
    int partie;
    int tour = 0;
    while (testAGagne(table) == 1){
        int premierJoueur = trouve2Trefle(table);
        partie = 1;
        //echangeDeCarte(tour%4,table);
        while (partie != 13){
            for (int i = premierJoueur; i < premierJoueur+4; i++){
                if (i%4 == 0){
                    deroulementTourJoueur(table,i%4,jeuxEnCours,premierJoueur);
                    //deroulementTourIA(table,i%4,jeuxEnCours,premierJoueur);   
                }else{
                    deroulementTourIA(table,i%4,jeuxEnCours,premierJoueur);   
                }        
            }
            reporterPlie(table,jeuxEnCours,premierJoueur);
            partie++;
        }
        tour++;
        calculePoints(table,jeuxEnCours);
        reinitialisationTable(table);
        reinitialisationPartieEnCours(jeuxEnCours); 
    }
    return 0;
}
