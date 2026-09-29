#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *f = NULL;
struct node *r = NULL;

void enqueue(int d) {
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = d;
    n->next = NULL;

    if (f == NULL) {
        f = n;
        r = n;
    } else {
        r->next = n;
        r = n;
    }
}

void dequeue() {
    struct node* t;
    if (f == NULL) {
        return;
    }
    t = f;
    f = f->next;
    if (f == NULL) {
        r = NULL;
    }
    free(t);
}

void display() {
    struct node* t;
    t = f;
    while (t != NULL) {
        printf("%d", t->data);
        if (t->next != NULL) {
            printf(" ");
        }
        t = t->next;
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

    printf("\n");
    display();
    dequeue();
    display();
    dequeue();
    display();

    return 0;
}
