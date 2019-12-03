#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "structures.h"


float calculeP(float a,float b,float c){
    return ((c/a)-((b*b)/(3*a*a)));
}

float calculeQ(float a,float b,float c,float d){
    return (((2*b*b*b)/(27*a*a*a)) + (d/a) - ((b*c)/(3*a*a)));
}

float calculeQ(float p,float q){
    return ((q*q)/4 + (p*p*p)/27);
}

float conj(float a){
    return -1 * a;
}

solutionEqu3d resolutionEqq(float a,float b,float c, float d){
    float p = calculeP(a,b,c);
    float q = calculeQ(a,b,c,d);

    float D = calculeD(p,q);

    solutionEqu3d sol;
    
    if (D > 0){
        sol.racine1.reelle = pow((-1*q/2)+(pow((q*q)/4+(p*p*p)/27,1.0/2.0)),1.0/3.0)+pow((-1*q)/2-sqrt((q*q)/4+(p*p*p)/27),1.0/3.0) ;
        sol.racine1.imaginaire = 0; 
    }else if (D < 0){

    }else if (D == 0){
        if (p == 0){
            sol.racine1.reelle = 0;
            sol.racine1.imaginaire=0;
            sol.racine2.reelle = 0;
            sol.racine2.imaginaire=0;            
            sol.racine3.reelle = 0;
            sol.racine3.imaginaire=0;
        }else{
            sol.racine1.reelle = (-3*q)/(2*p);
            sol.racine1.imaginaire=0;
            sol.racine2.reelle = sol.racine2.reelle;
            sol.racine2.imaginaire=0;            
            sol.racine3.reelle = (3*q)/p;
            sol.racine3.imaginaire=0;
        }
    }


}
