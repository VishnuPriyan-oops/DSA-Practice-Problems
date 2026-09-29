#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
void enqueue(int d) {
    struct node* new_n;
    new_n = (struct node*)malloc(sizeof(struct node));
    new_n->data = d;
    new_n->next = NULL;

    if (front == NULL) {
        front = new_n;
        rear = new_n;
    } else {
        rear->next = new_n;
        rear = new_n;
    }
}
void dequeue() {
    struct node *temp;

    if (front == NULL) {
        return;
    }
    temp = front;
    front = front->next;
    free(temp);
}
void print() {
    struct node *ptr;

    if (front == NULL) {
        printf("No data in the queue.\n");
        return;
    }
    ptr = front;
    while (ptr != NULL) {
        printf("%d", ptr->data);
        if (ptr->next != NULL) {
            printf(" ");
        }
        ptr = ptr->next;
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
    print();
    dequeue();
    print();
    return 0;
}
