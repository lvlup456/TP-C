#include <stdio.h>
#include <stdlib.h>

#include "structure.h"

maillon* creeMaillon(int val){
    maillon* retour = malloc(sizeof(maillon*));
    retour->val = val;
    retour->suivant = NULL;
    return retour;
}

void affichageListe(maillon* tete){
    maillon* temp = tete;
    while( temp != NULL){
        printf("%d\n",temp->val);
        if (temp->suivant != NULL){
            temp = temp->suivant;
        }else{
            temp = NULL;
        }
    }
}

maillon* ajoutTete(maillon* tete,int val){
    maillon* nvlTete = creeMaillon(val);
    nvlTete->suivant = tete;
    return nvlTete;
}

void ajoutQueu(maillon* tete,int val){
    maillon* temp;
    while( temp->suivant != NULL){
        temp = temp->suivant;
    }
    temp->suivant = creeMaillon(val);
}

void ajouterPosition(maillon* tete,int val,int pose){
    maillon* temp = tete;
    while( pose != 1 && temp->suivant != NULL){
        temp = temp->suivant;
        pose -= 1;
    }
    if (pose == 1){
        maillon* temp2 = creeMaillon(val);
        temp2->suivant = temp->suivant;
        temp->suivant = temp2;
    }else{
        printf("La chaine n'est pas assez longue\n");
    }
}

void ajouterTrie(maillon* tete,int val){
    maillon* temp;
    while( temp-> val > val && temp->suivant != NULL){
        temp = temp->suivant;
    }
    maillon* temp2 = creeMaillon(val);
    temp2->suivant = temp->suivant;
    temp->suivant = temp2;
}

void suppremierTete(maillon* tete){
    maillon* temp = tete->suivant;
    free(tete);

    tete = temp;
}

void suppremierPosition(maillon* tete,int pose){
    maillon* temp = tete;
    while( pose != 1 && temp->suivant != NULL){
        temp = temp->suivant;
        pose -= 1;
    }
    if (pose == 1){
        maillon* temp2 = temp->suivant;
        temp->suivant = temp2->suivant;
        free(temp2);
    }else{
        printf("La chaine n'est pas assez longue\n");
    }
}

void detruireListe(maillon* tete){
    maillon* temp = tete;
    while (temp != NULL){
        tete = temp;
        temp = tete->suivant;
        tete->suivant = NULL;
        free(tete);
    }
}

int main(){

    maillon* tete = creeMaillon(0);
    maillon* temp = tete;
    for (int i = 1; i < 10; i++){
        temp->suivant = creeMaillon(i);
        temp=temp->suivant;
    }
    temp = NULL;

    tete = ajoutTete(tete,-15);
    ajoutQueu(tete,16);
    ajouterPosition(tete,5,4);

    suppremierTete(tete);
    suppremierPosition(tete,1);
    affichageListe(tete);
    detruireListe(tete);

    return 0;

}