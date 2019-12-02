#include <stdio.h>
#include <stdlib.h>

int saisirPersonne()
{
    char nom[29],prenom[29];
    int jour,mois,annee;
    printf("ton nom stp :");
    scanf("%29s", nom);
    printf("ton prenom stp :");
    scanf("%29s", prenom);
    printf("ta date de naissance avec:\n");
    printf("jour :");
    scanf("%d",&jour);
    if (jour > 0 && jour <= 31){
        printf("mois :");
        scanf("%d",&mois);
        if (mois > 0 && mois <= 12){
            printf("annee :");
            scanf("%d",&annee);
            
            printf("Nom : %s \n",nom);
            printf("prenom: %s \n",prenom);
            printf("Date de Naissance %d/%d/%d \n",jour,mois,annee);
            return 0;            
        }   
    }
    printf("reviens quand tu voudras bien rentre un truc corect chef \n");
    return 0;
}