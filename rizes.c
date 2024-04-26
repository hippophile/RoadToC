#include <stdio.h>
#include <math.h>

int rizes(float a, float b, float c, float *x1, float *x2){
    int d;
    d = (b * b) - (4 * a * c);

    if(d > 0){
        *x1 = (-b + sqrt((double) d)) / (2 * a);
        *x2 = (-b - sqrt((double) d)) / (2 * a);
         int results = 2;
        return results;
    } else if(0 == d){
        *x2 = (-b) / (2 * a);
        *x1 = *x2;
         int results = 1;
        return results;
    }else{
        int results = 0;
        return results;
    }
}

int main(void){

 float a,b,c,x1,x2;

    printf("\nPlease provide the a:  ");
    scanf("%f",&a);

    printf("\nPlease provide the b:  ");
    scanf("%f",&b);

    printf("\nPlease provide the c:  ");
    scanf("%f",&c);

     int result = rizes(a, b, c, &x1, &x2);
     
    if (result == 2) {
        printf("\nΟι ρίζες της εξίσωσης είναι: %.2f και %.2f\n", x1, x2);
    } else if (result == 1) {
        printf("\nΗ διπλή ρίζα της εξίσωσης είναι: %.2f\n", x1);
    } else {
        printf("\nΗ εξίσωση δεν έχει πραγματικές ρίζες.\n");
    }
    return 0;
}