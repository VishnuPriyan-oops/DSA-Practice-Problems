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

int main() {
    int size, i, data;
    struct node* t;

    scanf("%d", &size);

    for (i = 0; i < size; i++) {
        scanf("%d", &data);
        enqueue(data);
    }

    t = f;
    while (t != NULL) {
        printf("%d\n", t->data);
        t = t->next;
    }

    return 0;
}
