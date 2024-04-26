#include <stdio.h>

int main(void){

   int N,i,j,min;
   int arr[20];
   

   printf("\nplease provide the quantity of the following numbers (it should be between 2 and 20) :\n");
   
   scanf("%d",&N);

   if(N < 2 || N > 20){
    printf("\nI SAID 2 AND 20!\n\n");
   }
   else{
    printf("\nNow please proceed with the numbers\n");
    for(i = 0; i < N; i++ ){
     scanf("%d", &arr[i]); 
    }
     min = arr[0];

     for(j = 1; j < N; j++){
          if (arr[j] < min) {
            min = arr[j];
        }
     }
     printf("\nThe smallest number is %d\n\n",min);
   }

    return 0;
}