#include <stdio.h>

#define MAX 105

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int data, int l) {
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = data;
}

void reverse() {
    int i, j, temp;
    for (i = front, j = rear; i < j; i++, j--) {
        temp = queue[i];
        queue[i] = queue[j];
        queue[j] = temp;
    }
}

int main() {
    int n, i, t;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &t);
        enqueue(t, n);
    }

    printf("\n");

    printf("Queue:");
    for (i = front; i <= rear; i++) {
        printf("%d", queue[i]);
        if (i != rear) {
            printf(" ");
        }
    }
    printf("\n");

    reverse();

    printf("Reversed Queue:");
    for (i = front; i <= rear; i++) {
        printf("%d", queue[i]);
        if (i != rear) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
