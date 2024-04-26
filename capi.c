#include <stdio.h>
#include <string.h>

#define SIZE 200

int main(void){

char input [SIZE];

    printf("\nProvide me with a sentence.\n");

    fgets(input, sizeof(input), stdin);

    for(int i = 0; input[i] != '\0'; i++){
        if(input[i] >= 'A' && input[i] <= 'Z'){
            input[i] += 32;
        }
        else if(input[i] >= 'a' && input[i] <= 'z'){
            input[i] -= 32;
        }
    }

   
        printf("\n%s\n", input);


    return 0;
}