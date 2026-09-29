#include <stdio.h>

#define MAX 105

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int data) {
    if (rear == MAX - 1) {
        return;
    }
    rear++;
    queue[rear] = data;
    if (front == -1) {
        front = 0;
    }
}

void disp() {
    int i;
    for(i=front;i<=rear;i++) {
        printf("%d", queue[i]);
        if (i != rear) {
            printf(" ");
        }
    }
}

int main() {
    int size, i, data;

    scanf("%d", &size);

    for (i = 0; i < size; i++) {
        scanf("%d", &data);
        if (front != -1) {
            disp();
            printf(" ");
        }
        printf("Enqueuing %d\n", data);
        enqueue(data);
    }

    disp();
    printf("\n");

    return 0;
}
