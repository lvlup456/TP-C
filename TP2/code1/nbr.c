#include <stdio.h>
#include <stdlib.h>

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
}