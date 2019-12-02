#include <stdio.h>
#include <stdlib.h>

int estBissextille(int annee){
    if (((annee % 4 == 0) && (annee % 100 != 0)) || (annee % 400 ==0)){
        return 1;
    }else{
        return 0;
    }
}

void incrementeDate(int jour,int mois,int annee,int jourMax){
    jour += 1;
    if (jour > jourMax){
        mois += 1;
        jour = 1;
        if (mois > 12){
            mois = 1;
            annee += 1;
        }
    }
    printf("le jour suivant il sera le %d/%d/%d \n",jour,mois,annee);   
}

int prediction(){
    int jour,mois,annee;
    printf("retre une date je e donnerai la suivante chef\n");
    printf("rentre le jour mois annee\n");    
    scanf("%d %d %d",&jour,&mois,&annee);
    if (jour > 0 && jour <= 31 && mois > 0 && mois <= 12){
        if (mois == 2 ){
            if (jour <= 29 && estBissextille(annee)){
                incrementeDate(jour,mois,annee,29);
            }else if (mois == 2 && jour <= 28){
                incrementeDate(jour,mois,annee,28);
            }
        }else if (((mois == 1) || (mois == 3) || (mois == 5) || (mois == 7) ||(mois == 8) ||(mois == 10) ||(mois == 12)) && (jour <= 31)){
            incrementeDate(jour,mois,annee,31);
        }else if (((mois == 4) || (mois == 6) || (mois == 9) || (mois == 11)) && (jour <= 30)){
            incrementeDate(jour,mois,annee,30);            
        }
        return 1;
    }
    printf("deso rentre une info corect stp\n");
    return 1;
}