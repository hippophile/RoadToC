#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 1001

int arr[N];

int main(void){

    int l, a, b;

    printf("\nProvide me with the length of your array (1 - 1000) :  ");
    scanf("%d",&l);
      if(l <= 1 || l >= 1000){
        printf("Is this what I told you to do !?\n");
        return 0;
      }
    printf("\nProvide me with the first and the last number of your array (1 - 2.000.000) :  ");
    scanf("%d %d", &a, &b);
      if(a == b || b < a){
        printf("\nYou are kinda dumb...\n\n");
      }

       for (int i = 0; i < N; i++) {
        arr[i] = rand() % (b - a ) + a; // Τυχαίος αριθμός από το [α, β]
    }

       printf("\nHere lays your array:\n");
    for (int i = 0; i < N; i++) {
        printf("%5d ", arr[i]);
    }
    printf("\n");

    int max = 0;

    for(int i = 0; i < N; i++){    
        if(arr[i] > max){
            max = arr[i];
        }
    }

    printf("The largest number is: %d\n", max);

    return 0;
}