/**
 * @file main.c
 * @author Duradn Thomas
 * @brief fonction principale avec un menu pour choisir la fonction appele 
 * @version 0.1
 * @date 2019-10-14
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <stdio.h>
#include <stdlib.h>

#include "plusGrand.h"
#include "partie2.h"


int main(){
    printf("bonhour que puis-je faire pour vous?\n");
    printf("1 pour table de multiplication\n");
    printf("2 pour le solveur d'equation\n");
    printf("3 pour la factoriel\n");
    printf("4 pour le sapin\n");
    printf("5 pour le rang de la factorielle\n");
    printf("6 pour l'ecriture binaire\n");
    printf("7 pour le coef binomiale\n");
    printf("8 pour savoir si un nombre est Amstrong\n");


    int rep = saisiEnier();
    int res;

    switch (rep)
    {
    case 1:
        printf("rentrez un numero \n");
        tabMultiplication(saisiEnier());
        break;
    case 2:
        solEquation();
        break;
    case 3:
        printf("rentrez un numero \n");
        long long int fac = factoriel(saisiEnier());
        printf("le resultat est : %lld\n",fac);
        break;
    case 4:
        printf("quel longueur tu veux? \n");        
        afficheSapin(saisiEnier());
        break;
    case 5:
        printf("quel rang tu veux? \n");
        res = maxFact(saisiEnier());
        printf("la reponse est: %d\n",res);
        break;
    case 6:
        printf("rentre un nombre\n");
        binaire(saisiEnier());
        break;
    case 7:
        printf("rentre n: ");
        int n = saisiEnier();
        printf("rentre p: ");
        int p = saisiEnier();
        res = coefBinomiale(n,p);
        printf("le resultat est : %d", res);
        break;
    case 8:
        printf("rentre un nombre ");
        estAmstrong(saisiEnier());
        break;

    default:
        printf("deole je n'ai pas ce que vous me demandez\n");
        break;
    }

}
