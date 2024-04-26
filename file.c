#include <stdio.h>

#define MAXLEN 200
#define LINES 20

void press_enter(){
  int c;
  printf("Press enter to continue\n");
  while((c = getchar())!= '\n');
}

int main (int argc, char *argv[]){
 
   int i =1;
   char buf[MAXLEN+1];

   FILE *fp = fopen(argv[1],"r");
    if (fp == NULL) return 1;

     while(fgets(buf, MAXLEN,fp)!=NULL){
        if (i == 1 || (i-1) % LINES != 0)
          printf("%d:%s",i,buf);
        else{
            press_enter();
                printf("%d:%s", i , buf);
        }
        i++;
     }

  
    return 0;
}