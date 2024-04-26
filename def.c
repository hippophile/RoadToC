#include <stdio.h>

int main(void) {
    int grid[5];
    int prod = 1;
    int num;

    printf("\nInsert 5 numbers one by one, please from 1 to 8:\n");
    
    for (int i = 0; i < 5; i++) {
        scanf("%d", &num);
        if (num < 1 || num > 8) {
            printf("Please enter a number between 1 and 8.\n");
            i--; // Επαναλάβετε την τρέχουσα επανάληψη για έγκυρη είσοδο.
            continue;
        }
        grid[i] = num;
    }
 
    for (int j = 0; j < 5; j++) {
        prod *= grid[j];
    }

    printf("\nYour product is %d\n", prod);

    return 0;
}
