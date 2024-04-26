#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

    node* create(int value) {
        node* newNode = malloc(sizeof(node));
        if (newNode == NULL) {
            fprintf(stderr, "Out of memory!\n");
            exit(1);
        }
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

node* insert(node* root, int value) {
    if (root == NULL) {
        return create(value);
    }
    // Simple insert logic: smaller values go left, larger or equal values go right
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

void printLevels(node* root) {
    if (!root) return;

    typedef struct queueNode {
        node* treeNode;
        struct queueNode* next;
    } queueNode;

    queueNode *front = NULL, *rear = NULL;
    front = rear = malloc(sizeof(queueNode));
    if (front == NULL) exit(1);

    front->treeNode = root;
    front->next = NULL;

    while (front) {
        const node* const temp_node = front->treeNode;
        queueNode* temp = front;
        printf("%d ", temp_node->data);
        if (temp_node->left) {
            rear->next = malloc(sizeof(queueNode));
            rear = rear->next;
            rear->treeNode = temp_node->left;
            rear->next = NULL;
        }
        if (temp_node->right) {
            rear->next = malloc(sizeof(queueNode));
            rear = rear->next;
            rear->treeNode = temp_node->right;
            rear->next = NULL;
        }
        front = front->next;
        free(temp);
    }
    printf("\n");
}

int main(void) {
    node* root = NULL;
    int choice, value;

    while (1) {
        printf("1. Insert Value\n");
        printf("2. Print Tree\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Current Tree:\n");
                printLevels(root);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
