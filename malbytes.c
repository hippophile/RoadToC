#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double **p;
    int N, M, i, j, area;

    printf("\nGive me the length of the array : ");
    scanf("%d", &N);
    printf("\nGive me the depth of the array : ");
    scanf("%d", &M);

    p = malloc(sizeof(double *) * M);
    if (!p) {
        printf("ERROR!\nMEMORY WAS NOT ALLOCATED\n");
        return 0;
    }

    for (i = 0; i < M; i++) {
        p[i] = malloc(sizeof(double) * N);
        if (!p[i]) { // Check if allocation failed for p[i], not just p
            printf("ERROR!\nMEMORY WAS NOT ALLOCATED\n");
            // Free the allocated memory before exiting
            for (j = 0; j < i; j++) {
                free(p[j]);
            }
            free(p);
            return 0;
        }
    }

    printf("\nThe size of your array is %ld bytes\n", sizeof(double) * M * N + M * sizeof(double *) + sizeof(double **));

    // Deallocate memory properly
    for (i = 0; i < M; i++) {
        free(p[i]);
    }
    free(p);

    return 0;
}