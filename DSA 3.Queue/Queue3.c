#include <stdio.h>

#define MAX 105

int queue[MAX];
int front = 0, rear = -1;

void enqueue(int data) {
    queue[++rear] = data;
}

void dequeue() {
    if (front <= rear) {
        front++;
    }
}

void display() {
    int i;
    for(i=front;i<=rear;i++) {
        printf("%d", queue[i]);
        if (i != rear) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int size, i, data;

    scanf("%d", &size);

    for (i = 0; i < size; i++) {
        scanf("%d", &data);
        enqueue(data);
    }

    printf("Dequeuing elements:\n");

    while (rear - front + 1 > 1) {
        dequeue();
        display();
    }

    return 0;
}
