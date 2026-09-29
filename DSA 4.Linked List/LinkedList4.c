#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

void display() {
    struct node *t;
    printf("Linked List:");
    t = start;
    while (t != NULL) {
        printf("->%d", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() {
    int n, i, val, p, x, found;
    struct node *p1, *p2, *tail, *cur, *prev, *newNode;

    tail = NULL;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        p1 = (struct node*)malloc(sizeof(struct node));
        p1->data = val;
        p1->next = NULL;

        if (start == NULL) {
            start = p1;
            tail = p1;
        } else {
            p2 = tail;
            p2->next=p1;
            tail = p1;
        }
    }

    scanf("%d", &p);
    scanf("%d", &x);

    found = 0;
    cur = start;
    prev = NULL;
    while (cur != NULL) {
        if (cur->data == p) {
            found = 1;
            break;
        }
        prev = cur;
        cur = cur->next;
    }

    printf("\n");

    if (found) {
        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = x;
        newNode->next = cur;

        if (prev == NULL) {
            start = newNode;
        } else {
            prev->next = newNode;
        }
        display();
    } else {
        printf("Node not found!\n");
        display();
    }

    return 0;
}
