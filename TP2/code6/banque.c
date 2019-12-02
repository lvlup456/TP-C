#include <stdio.h>
#include <stdlib.h>

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
        printf("%f\n",interet);
    }while (interet < 1000);
    printf("il faudra %d anne avant de rapporter +1000 \n",annee);
    return 1;
}