#ifndef __INIT_H_
#define __INIT_H_

#include "struct.h"


int trouve2Trefle(joueur* plateau);
int estJouable(couleurs couleurActuel, int defauseCoeur,carte* main,int tailleMain,int carteAJouer, int tailleCartePrecedentes);




#endif