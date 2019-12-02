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


int main(){
    int n;
    n = saisiEnier();
    printf("%d\n",n);
}