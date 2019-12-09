#ifndef __REGLES_H_
#define __REGLES_H_

#include "struct.h"


int trouve2Trefle(joueur* plateau);
int estJouable(couleurs couleurActuel, int defauseCoeur,carte* main,int tailleMain,int carteAJouer, int tailleCartePrecedentes);
void reporterPlie(joueur* plateau,partieEnCours* jeuxEnCours,int premierJoueur);
void calculePoints(joueur* plateau,partieEnCours* jeuxEnCours);
int testAGagne(joueur* plateau);
void reinitialisationPartieEnCours(partieEnCours* jeuxEnCours);
void reinitialisationTable(joueur* table);
void echangeDeCarte(int tour, joueur* plateau);




#endif