/**
 * @file richter.c
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
 *  \fn void richeter ()
 *  \author Durand Thomas
 *  \version 0.1
 *  \date 14/10/19
 *
 *  \brief demande un nombre et affiche sont equivalent sur l'echelle de richetere
 * 
 *
 *
 */

void richeter(){
    int param;
    scanf("%d",&param);
    if (param < 1){
        printf("il ne se passe rien\n");
    }else if (param > 9){
        printf("C'est l'apocalypse\n");
    }else
    {      
        switch (param){
        case 1:
            printf("micro tremblement\n");
            break;
        case 2:
            printf("Tres mineur\n");
            break; 
        case 3:
            printf("Mineur\n");
            break; 
        case 4:
            printf("Legere\n");
            break; 
        case 5:
            printf("Modere\n");
            break; 
        case 6:
            printf("Fort\n");
            break; 
        case 7:
            printf("Majeur\n");
            break; 
        case 8:
            printf("Important\n");
            break; 
        case 9:
            printf("Devastateur\n");
            break; 
        default:
            printf("euh ya un soucis...\n");
            break;
        }
    }
}