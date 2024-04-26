#include <stdio.h>

int main() {
    char buffer[5]; // Buffer of size 5

    printf("Enter a string: ");
    gets(buffer); // Dangerous use of gets

    printf("You entered: %s\n", buffer);

    return 0;
}
//THAT IS WHY fgets >> gets!    