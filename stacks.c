#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10
#define FALSE 0
#define TRUE 1

typedef int elem;

typedef struct STACK{
    int arr[STACK_SIZE];
    int top;
}STACK;

void ST_init(STACK *s){

    s -> top = -1;
}

int ST_empty(STACK s){

    return s.top == -1;
}

int ST_full(STACK s){

    return s.top == STACK_SIZE - 1;
}

int ST_push(STACK *s, elem x){

    if(ST_full(*s))
    return FALSE;
    else{
        s->top++;
        s->arr[s->top] = x;
        return TRUE;
    }
}

int ST_pop(STACK *s,elem *x){

    if(ST_full(*s))
    return FALSE;
    else{
        *x = s -> arr[s->top];
        s->top--;
        return TRUE;
    }
}

int main (void){
     STACK *stack = (STACK *)malloc(sizeof(STACK)); // Allocate memory for the stack
    if (stack == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }
    ST_init(stack); // Initialize the stack

    printf("Stack operations:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Exit\n");

    int choice, data;
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                if (ST_push(stack, data))
                    printf("Pushed %d onto the stack.\n", data);
                else
                    printf("Stack overflow!\n");
                break;
            case 2:
                if (ST_pop(stack, &data))
                    printf("Popped %d from the stack.\n", data);
                else
                    printf("Stack underflow!\n");
                break;
            case 3:
                printf("Exiting...\n");
                free(stack); // Free dynamically allocated memory
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}