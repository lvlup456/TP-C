#include <stdio.h>
#include <stdlib.h>

int divEntier(){
    int n,d;
    printf("enntre le numerateur et le denominateur chef\n");
    scanf("%d %d",&n,&d);
    if (d != 0){
        printf("%d/%d=%d",n,d,n/d);
    }else{
        printf("deso chef pas de div par 0 ");
    }
    return 0;
}