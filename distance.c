#include <stdio.h>
#include <math.h>

typedef struct {
    float x;
    float y;
}point;

void read_point(point *p) {
    printf("Enter the x coordinate: ");
    scanf("%f", &p->x);

    printf("Enter the y coordinate: ");
    scanf("%f", &p->y);
}

float eu_distance(point A, point B){
    return sqrt(pow(A.x-B.x,2)+pow(A.y-B.x,2));
}

int main() {
    
    point A,B;
    printf("1st point: \n");
    read_point(&A); 
    
    printf("2st point: \n");
    read_point(&B);

    printf("\nThe distacnce is : %.3f\n\n",eu_distance(A,B));

    return 0;
}


