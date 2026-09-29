#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Queue {
    struct Node* front;
    struct Node* rear;
} Queue;

void enQueue(Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (q->front == NULL) {
        q->front = newNode;
        q->rear = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = q->front;
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int deQueue(Queue* q) {
    int val;
    struct Node* temp;

    if (q->front == NULL) {
        return -1;
    }

    temp = q->front;
    val = temp->data;

    if (q->front == q->rear) {
        q->front = NULL;
        q->rear = NULL;
    } else {
        q->front = q->front->next;
        q->rear->next = q->front;
    }

    free(temp);
    return val;
}

void displayQueue(struct Queue* q) {
    struct Node* ptr;

    printf("Elements in Circular Queue are:");

    if (q->front == NULL) {
        printf("\n");
        return;
    }

    ptr = q->front;
    do {
        printf("%d", ptr->data);
        ptr = ptr->next;
        if (ptr != q->front) {
            printf(" ");
        }
    } while (ptr != q->front);

    printf("\n");
}

int main() {
    int n, i, value, d1, d2;
    Queue q;
    q.front = NULL;
    q.rear = NULL;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        enQueue(&q, value);
    }

    displayQueue(&q);

    d1 = deQueue(&q);
    printf("Deleted value = %d\n", d1);

    d2 = deQueue(&q);
    printf("Deleted value = %d", d2);

    displayQueue(&q);

    return 0;
}
