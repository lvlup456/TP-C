/**
 * @file main.c
 * @author Durand Thomas
 * @brief Menu a choix multiple pour choisir la bonne fonction
 * @version 0.1
 * @date 2019-10-14
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#include "banque.h"
#include "divEntier.h"
#include "maxMin.h"
#include "nbr.h"
#include "prediction.h"
#include "richter.h"
#include "saisirPersonne.h"



/*! 
 *  \fn int main ()
 *  \author Durand Thomas
 *  \version 0.1
 *  \date 14/10/19
 *
 *  \brief Fonction principale
 * \return 0   : le programme doit se terminer normalement
 *
 */
int main(){

    int entre;

    printf("coucou qu'es ce que je peux faire pour toi:\n");
    printf("1 pour la banque\n");
    printf("2 pour la division d'entier\n");
    printf("3 pour le minMax\n");
    printf("4 pour rentre un nombre\n");
    printf("5 pour la prediction du jour\n");
    printf("6 pour l'echelle de richeter\n");
    printf("7 pour saisir une personne\n");


    scanf("%d",&entre);

    switch (entre){
    case 1:
        banque();
        break;
    case 2:
        divEntier();
        break;
    case 3:
        maxMin();
        break;
    case 4:
        nbr();
        break;
    case 5:
        prediction();
        break;
    case 6:
        richeter();
        break;
    case 7:
        saisirPersonne();
        break;
    default:
        printf("rentres un nbr entre 1 et 7 stp \n");
        break;
    }
    return 0;
}