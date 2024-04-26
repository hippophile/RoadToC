#include <stdio.h>
#include <stdlib.h>

void UNUSED(int result) {
    (void)result;
}

#define MAX_NODES 100

struct Node {
    int value;
    struct Node* next;
};

struct Queue {
    int items[MAX_NODES];
    int front;
    int rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(struct Queue* q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX_NODES - 1)
        printf("Queue is full");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

int peek(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty");
        return -1;
    } else {
        return q->items[q->front];
    }
}

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* nodes[], int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = nodes[src];
    nodes[src] = newNode;
}

void BFS(struct Node* nodes[], int startNode, int endNode, int visited[], int parents[], int roomSize) {
    struct Queue* q = createQueue();

    visited[startNode] = 1;
    enqueue(q, startNode);

    while (!isEmpty(q)) {
        int currentNode = dequeue(q);

        if (currentNode == endNode) {
            printf("Shortest Path: ");
            int current = endNode;
            while (current != startNode) {
                int parent = parents[current];
                int diff = current - parent;

                // Κατεύθυνση του βήματος
                char direction = 0; // Αρχικοποίηση σε μια τιμή που δεν θα χρησιμοποιηθεί ποτέ
                if (diff == roomSize) {
                    direction = 'D'; // DOWN
                } else if (diff == -roomSize) {
                    direction = 'U'; // UP
                } else if (diff == 1) {
                    direction = 'R'; // RIGHT
                } else if (diff == -1) {
                    direction = 'L'; // LEFT
                }
                printf("%c", direction);
                current = parent;
            }
            printf("\n");
            return;
        }

        struct Node* temp = nodes[currentNode];
        while (temp != NULL) {
            int adjNode = temp->value;
            if (visited[adjNode] == 0) {
                visited[adjNode] = 1;
                enqueue(q, adjNode);
                parents[adjNode] = currentNode;
            }
            temp = temp->next;
        }
    }
}

int main() {
    struct Node* nodes[MAX_NODES] = { NULL };
    int visited[MAX_NODES] = { 0 };
    int parents[MAX_NODES] = { -1 };

    int roomSize, startX, startY, targetX, targetY;
    UNUSED(scanf("%d", &roomSize));
    UNUSED(scanf("%d %d %d %d", &startX, &startY, &targetX, &targetY));

    // Add edges to the graph based on the room's grid
    for (int i = 0; i < roomSize; i++) {
        for (int j = 0; j < roomSize; j++) {
            char c;
            UNUSED(scanf(" %c", &c));
            if (c == '0') {
                int nodeIndex = i * roomSize + j;
                if (i > 0 && roomSize[i - 1][j] == '0')
                    addEdge(nodes, nodeIndex, (i - 1) * roomSize + j);
                if (i < roomSize - 1 && roomSize[i + 1][j] == '0')
                    addEdge(nodes, nodeIndex, (i + 1) * roomSize + j);
                if (j > 0 && roomSize[i][j - 1] == '0')
                    addEdge(nodes, nodeIndex, i * roomSize + (j - 1));
                if (j < roomSize - 1 && roomSize[i][j + 1] == '0')
                    addEdge(nodes, nodeIndex, i * roomSize + (j + 1));
            }
        }
    }

    BFS(nodes, startY * roomSize + startX, targetY * roomSize + targetX, visited, parents, roomSize);

    return 0;
}
