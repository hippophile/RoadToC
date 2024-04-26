#include <stdio.h>

void agegroup(int a){
    if (a < 18){
        printf("\nYou are underage.\n");
    }
    else if (a > 65){
        printf("\nYou are retired.\n");
    }
    else {
        printf("\nYou are an adult.\n");
    }
}   

int main (void){

    int age;

    printf("\nPlease inform us with your legal age:");
    
    scanf("%d", &age);
    
    agegroup(age);

    return 0;
}