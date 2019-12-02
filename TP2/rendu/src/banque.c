#include <stdio.h>
#include <stdlib.h>


/*! 
 *  \fn int banque ()
 *  \author Durand Thomas
 *  \version 0.1
 *  \date 14/10/19
 *
 *  \brief calcule le temps necessaire pour en entier donne pour atteindre 1000e d'interet
 * 
 *
 * \return 1   : le programme doit se terminer normalement
 *
 */
int banque(){
    float interet,somme;
    int annee;
    printf("Somme Initiale? \n");
    scanf("%f",&somme);
    interet = 0;
    annee = 0;
    do{
        interet += ((somme + interet) * 3.5) / 100;
        annee += 1;
    }while (interet < 1000);
    printf("il faudra %d anne avant de rapporter +1000 \n",annee);
    return 1;
}