/**
 * @file divEntier.c
 * @author Durand Thomas
 * @brief division d'enier
 * @version 0.1
 * @date 2019-10-14
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <stdio.h>
#include <stdlib.h>

/*! 
 *  \fn int divEntier ()
 *  \author Durand Thomas
 *  \version 0.1
 *  \date 14/10/19
 *
 *  \brief divise deux entier donnees
 * 
 *
 * \return 0   : le programme doit se terminer normalement
 *
 */

int divEntier(){
    int n,d;
    printf("entre le numerateur\n");
    scanf("%d",&n);
    printf("et le denominateur\n");

    scanf("%d",&d);
    if (d != 0){
        printf("%d/%d=%d",n,d,n/d);
    }else{
        printf("deso chef pas de div par 0 ");
    }
    return 0;
}