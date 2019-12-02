#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


float calculeAire(int r){
    return M_PI*r*r;
}

int testDansCercle(float x,float y,float r ){
    float res;
    res = (x*x) + (y*y);
    if (res < r){
        return 1;
    }else{
        return 0;
    }
}

float rand_a_b(int a,int b){
    return (rand() / (double)RAND_MAX) * (b-a) + a ;
}


float calculePiMonteCarlo(int n){
    int test;
    float x,y,res;
    res = 0;
    for (int i = 0; i < n; i++){
        x = rand_a_b(1,0);
        y = rand_a_b(1,0);
        test = testDansCercle(x,y,1);
        if (test == 1){
            res +=1;
        }
    }
    return (res*4)/n ;
}

float calculePiMadhava(int n){
    float res=0;
    for (int i = 0; i < n; i++)
    {
        res += pow(-1,i)/(2*i+1);
    }
    return res*4;
}

float calculePiJohnWallis(int n){
    float res=0;
    for (int i = 0; i < n; i++){
        res += pow(-1,i)/(2*i+1);
    }
    return res*4;
}
