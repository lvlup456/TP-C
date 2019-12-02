#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float methodeNewton(int n){
    float res = (1/2)+(1); 
    for (int i = 0; i < n; i++){
        res = (res/2) + (1/res);
    }
    return res;
}

float methodeHalley(int n){
    float res = (1+6)/(3+2);
    for (int i = 0; i < n; i++){
        res = res * (res * res + 6) / ( 3 * res * res + 2 );
    }
    return res;
}

float methodeTheon(int n){
    double pn = 1 + 2;
    double qn = 1 + 1;
    float temp;
    for (int i = 0; i < n; i++){
        temp = pn;
        pn = pn + 2 * qn;
        qn = temp + qn; 
    }

    return (pn / qn);
}
