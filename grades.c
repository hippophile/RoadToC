#include <stdio.h>

int main(){

  FILE *fp;

  int grade;
  int i, n=2; 
  char name[50]; 

  fp =  fopen( "grades.dat", "wb+");

  

for (i = 0; i < n; i++) 
    { 
        puts("Enter a name"); 
        scanf("%[^\n]%*c", name);
        fprintf(fp,"%d.%s\n", i, name); 
    } 

  

  

    return 0;
}