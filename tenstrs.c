#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 200

int main(void){

    char string [SIZE];

    printf("\nGive a string : ");
    fgets(string, sizeof(string), stdin);


    int count = strlen(string);

    char *p = malloc(sizeof(char)*count);
    if(!p){
        printf("ERROR!\nMEMORY WAS NOT ALLOCATED\n");
        return 0;
    }

    strcpy(p, string);

    printf("\nYou just allocated some memory for this string : %s and by some I mean %zu bytes\n", p, sizeof(count)*count);

    free(p);

    return 0;
}