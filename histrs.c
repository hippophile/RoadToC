#include <stdio.h>
#include <string.h>

int main(void){

  char name [101];

    printf("\nWhat is your name sir?\n");

    fgets(name, sizeof(name), stdin);

    printf("\nOh Hi %s, your name is made up by %zu letters \n", name, strlen(name)-1);

    return 0;
}