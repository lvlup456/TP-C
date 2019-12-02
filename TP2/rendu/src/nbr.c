/**
 * @file nbr.c
 * @author Durand Thomas
 * @brief 
 * @version 0.1
 * @date 2019-10-14
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <stdio.h>
#include <stdlib.h>


/*! 
 *  \fn int nbr ()
 *  \author Durand Thomas
 *  \version 0.1
 *  \date 14/10/19
 *
 *  \brief demande a l'utilisateur de rentre un entier
 * 
 *
 * \return 1   : le programme doit se terminer normalement
 *
 */

int nbr()
{
    int nbr, test;
    printf("rentre un nombre stp :");
    test = scanf("%d", &nbr);
    if (test == 1)
    {
        printf("\nvous avez rentre: %d \n", nbr);
    }else
    {
        printf("j'ai dis un nbr chef :( \n");
    }
    return 1;
}