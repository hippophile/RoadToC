#include <stdio.h>
#include <stdlib.h>

int main(void){

    int *p;
    int i, N;

    printf("\nGive me the length of the array : \n\n");
    scanf("%d",&N);

    p = malloc(sizeof(int)*N);
    if(!p){
        printf("ERROR!\nMEMORY WAS NOT ALLOCATED\n");
        return 0;
    }

    for(i = 0; i < N; i++){
        p[i] = i*i*i;
        printf("\np[%d] = %d\n",i, p[i]);
    }

    free(p);

    return 0;
}