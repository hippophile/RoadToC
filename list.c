#include <stdio.h>
#include <stdlib.h>

typedef int elem;

struct node{
    elem data;
    struct node *next;
};

typedef struct node LIST_NODE;
typedef struct *LIST_PTR;

void LL_init(LIST_PTR *head){
    *head = NULL;
}

void LL_empty(LIST_PTR  head){
    return head == NULL;
}

elem LL_data(LIST_PTR p){
    return p->data;
}