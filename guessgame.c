#include <stdio.h>
#include <stdlib.h>

int hidden, p;

int main (void){

    hidden = rand() % 101;
    
    printf("\nguess the integer I am thinking of between 0 and 100\n");
    scanf("%d",&p);

    if (p == hidden){
        printf("\nYou are right %d is my number\n",hidden);
    }
    else if (p > hidden)
    {
        printf("\nNo, my number is smaller than %d try again!\n",p);
    }
    else {
        printf("\nNo, my number is bigger than %d try again!\n",p);
    }

    return 0;
}