#include <stdio.h>

void swap(int *ptrA, int *ptrB){
    
    int k;
    k = *ptrA;
    *ptrA = *ptrB;
    *ptrB = k;
    printf("\nswap : a = %d and b = %d",*ptrA, *ptrB);
}

int main(void){
    int a = 5, b = 10;
    printf("\nMain : a = %d and b = %d",a,b);
    swap(&a, &b);
    printf("\nMain : a = %d and b = %d\n",a,b);
}