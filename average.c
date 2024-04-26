#include <stdio.h>

int main(void){

   int N,i,j,sum,ave;
   int arr[20];
   

   printf("\nplease provide the quantity of the following numbers (it should be between 1 and 20) :\n");
   
   scanf("%d",&N);

   if(N < 1 || N > 20){
    printf("\nI SAID 1 AND 20!\n\n");
   }
   else{
    printf("\nNow please proceed with the numbers\n");
    for(i = 0; i < N; i++ ){
     scanf("%d", &arr[i]); 
    }
     sum = 0;

     for(j = 0; j < N; j++){
          sum += arr[j];
        }
        ave = (sum / N);
        printf("\nThe average is %d\n\n",ave);
     }
    

    return 0;
}