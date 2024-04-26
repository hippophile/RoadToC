#include <stdio.h>

int main (void){

int x = 1;
int y = 1;

printf("\n%d,%d",x++,++y);
printf("\n%d,%d",x++,y++);
printf("\n%d,%d",x++,++y);
printf("\n%d,%d",x,y);

    return 0;
}