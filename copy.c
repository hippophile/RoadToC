#include <stdio.h>
#include <string.h>

int main(void){

  char name [100];
  char fname [50];
  char sname [50];
  char copied [50];
  int ans;

    printf("\nWhat is your name full sir?(first name and surname)\n");

    fgets(name, sizeof(name), stdin);

    if(sscanf(name, "%s %s", fname, sname) != 2){
        printf("\nGive me two names!\n\n");
        return 0;
    }

    printf("\n%s\n",fname);   
    printf("\nFor copying your fname press 1.");
    printf("\nFor copying your sname press 0.\n");

    scanf("%d", &ans);

    if(ans == 1){
        strcpy(copied, fname);
        printf("\n Your fanme is %s, your sname is %s and you copy is %s\n", fname, sname, copied);
    }
    else if (ans == 0){
        strcpy(copied, sname);
        printf("\n Your fanme is %s, your sname is %s and you copy is %s\n", fname, sname, copied);
    }
    else{
        printf("\nI only said 1 or 2\n");
    }
 

    return 0;
}