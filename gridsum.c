#include <stdio.h>

int main(void){

    int grid[9];
    int sum = 0;
    int num;
   
    printf("\nincert 10 numbers one by one pleas\n");
    
    for(int i = 0; i < 10; i++){
        scanf("%d", &num);
        grid[i] = num;
    }
 
    for(int j = 0; j < 10; j++){
        sum += grid[j];
    }

    printf("\nYour sum is %d\n",sum);

    return 0;
}