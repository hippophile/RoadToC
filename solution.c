#include <stdio.h>

int main (){
   int num, max;

   if(scanf("%d", &max) !=1){
   fprintf(stderr, "error\n");
   return 1;
   }

	while(scanf("%d", &num) == 1){
	  if (num > max){
	      max = num;
	   }
	}

      printf("%d",max);

return 0;
}
