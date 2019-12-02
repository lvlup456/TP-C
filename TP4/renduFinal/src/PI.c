/**
 * @file PI.c
 * @author Durand Thomas
 * @brief ensemble des fonctions pour aprocimer PI
 * @version 0.1
 * @date 2019-10-14
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/**
 * @brief calcul l'aire d'un cercle de rayon r
 * 
 * @param r 
 * @return float 
 */
float calculeAire(int r){
    return M_PI*r*r;
}

/**
 * @brief test si les coordonnees (x,y) sot dans le cercle de rayon r et de centre (0,0)
 * 
 * @param x 
 * @param y 
 * @param r 
 * @return int 
 */
int testDansCercle(float x,float y,float r ){
    float res;
    res = (x*x) + (y*y);
    if (res < r){
        return 1;
    }else{
        return 0;
    }
}

/**
 * @brief pick un float random entre a et b
 * 
 * @param a 
 * @param b 
 * @return float 
 */
float rand_a_b(int a,int b){
    return (rand() / (double)RAND_MAX) * (b-a) + a ;
}

/**
 * @brief calcule PI avec la methode de Monte Carol
 * 
 * @param n 
 * @return float 
 */
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
/**
 * @brief calcule Pi avec la methode de Madhava
 * 
 * @param n 
 * @return float 
 */
float calculePiMadhava(int n){
    float res=0;
    for (int i = 0; i < n; i++)
    {
        res += pow(-1,i)/(2*i+1);
    }
    return res*4;
}
/**
 * @brief calcule Pi avec la methode de John Wallis
 * 
 * @param n 
 * @return float 
 */
float calculePiJohnWallis(int n){
    float res=0;
    for (int i = 0; i < n; i++){
        res += pow(-1,i)/(2*i+1);
    }
    return res*4;
}
