#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "structures.h"

solutionEqu3d resolutionEqq(float a,float b,float c, float d){
    
    solutionEqu3d sol;
    sol.racine1.reelle = NAN;
    sol.racine1.imaginaire = NAN;
    sol.racine2.reelle = NAN;
    sol.racine2.imaginaire = NAN;
    sol.racine3.reelle = NAN;
    sol.racine3.imaginaire = NAN;
    
    float p = (c/a)-(pow(b,2)/(3*pow(a,2)));
    float q = (2*pow(b,3))/(27*pow(a,3)) + (d/a) - ((b*c)/(3*pow(a,2)));

    if (p == 0){
        if (q == 0){
            sol.racine1.reelle = (-b)/(3*a);
        }else{
            sol.racine1.reelle = pow(-q,1.0/3.0);        
        }
    }else{
        float D = (pow(q,2)/4) + (pow(p,3)/27);
        if (D < 0){
            sol.racine1.reelle = pow((-q/2) + sqrt(pow(q,2)/4 + pow(p,3)/27),3) + pow((-q/2) + sqrt(pow(q,2)/4 + pow(p,3)/27),3);

        }else of (D < 0){
            
        }
        
    }
    
}
