#include <stdio.h>
#include <stdlib.h>

int saisiEnier(){
    int n,test;
    test = scanf("%d",&n);
    if (test == 1){
        return n;
    }else{
        printf("rentre un vrai numero stp chef \n");
        exit(EXIT_SUCCESS);
    }
}

void tabMultiplication(int n){
    for (int i = 1; i <= 10; i++)
    {
        printf("%d * %d = %d\n",i,n,i*n);
    }
}

void solEquation(){
    float calcule,x,a,b;
    a = -15;
    b = -10;
    
    do{    
        x = (a + b)/2;
        calcule = x*x*x + 12*x*x + 1;
        if (calcule <= 0){
            a = (a+b)/2;
        }else{
            b = (a+b)/2;
        }
    } while (calcule > 0.00001 || calcule < -0.00001);
    printf("[%f,%f]\n",a,b);
}

int factoriel(int n){
    if (n == 0){
        return 1;
    }else{
        return factoriel(n-1) * n;
    }
}

