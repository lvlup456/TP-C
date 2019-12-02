#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "structures.h"


solutionEqu2d resolutionEqq(float a,float b,float c){
    float delta = b*b - 4*a*c;
    printf("%f",delta);

    solutionEqu2d rez;
    if(delta < 0){
        rez.racine1.reelle = (-b) / (2 * a);
        rez.racine1.imaginaire = -sqrt(fabs(delta))/(2*a);  
        rez.racine2.reelle = (-b)/(2*a);
        rez.racine2.imaginaire = sqrt(fabs(delta))/(2*a);
    }else if( delta == 0){
        rez.racine1.reelle = -b/(2*a);
        rez.racine1.imaginaire = 0;
        rez.racine2.reelle = -b/(2*a);
        rez.racine2.imaginaire = 0;
    }else{
        rez.racine1.reelle = (-b-sqrt(delta))/(2*a);
        rez.racine1.imaginaire = 0;
        rez.racine2.reelle = (-b+sqrt(delta))/(2*a);
        rez.racine2.imaginaire = 0;
    }
    return rez;
}

void afficheResultat2d(solutionEqu2d solution){
    if (solution.racine1.imaginaire == 0){
        if (solution.racine1.reelle == solution.racine2.reelle){
            printf("il y a une seul solution reel qui est: %f\n",solution.racine2.reelle);
        }else{
            printf("il y a deux solutions reels qui sont : %f et %f\n",solution.racine1.reelle,solution.racine2.reelle);
        }
    }else{
            printf("il y a deux solutions complexes qui sont : %f+i*%f et %f+i*%f\n",solution.racine1.reelle,solution.racine1.imaginaire,solution.racine2.reelle,solution.racine2.imaginaire);
    }
}