#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 8


int arr[ROWS][COLS];

int i, j;

int main (void){

// Ορίζουμε το seed της συνάρτησης rand() με την τρέχουσα χρονική στιγμή
    srand(time(NULL));

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            arr[i][j] = rand() % 201;
        }
        
    }
    
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}