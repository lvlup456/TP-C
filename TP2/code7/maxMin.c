#include <stdio.h>
#include <stdlib.h>

int maxMin(){
    int n;
    printf("tu veux rentre cmb de nbr ?\n");
    scanf("%d",&n);
    int data[n];
    for (int i = 0; i < n; i++)
    {
        printf("rentre le %d eme element stp: ",i+1);
        scanf("%d",&data[i]);
    }
    int max,min;
    max = data[0];
    min = data[0];

    for (int i = 1; i < n; i++){
        if (data[i] > max){
            max = data[i]; 
        }else if (data[i] < min){
            min = data[i]; 
        }
    }
    printf("le max est %d et le min est %d \n",max,min);
}