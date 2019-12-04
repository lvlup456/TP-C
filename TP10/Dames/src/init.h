#ifndef __INIT_H_
#define __INIT_H_

joueur* init();
carte* retirerCarte(carte* deck,int taille,int emplacement);
partieEnCours* initPartieEnCours();
carte* initDeck();
void distributCarte(joueur* table,carte* deck);


#endif