#include <stdio.h>
#include <stdlib.h>

struct n {
    int data;
    struct n *next;
};

struct n *head = NULL;

void insert(int data) {
    struct n *newNode = (struct n*)malloc(sizeof(struct n));
    struct n *t;
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        t = head;
        while (t->next != head) {
            t = t->next;
        }
        t->next = newNode;
        newNode->next = head;
    }
}

void display(struct n *h) {
    struct n *t = h;
    printf("[h]");
    do {
        printf("=>%d", t->data);
        t = t->next;
    } while (t != h);
    printf("=>[h]\n");
}

int main() {
    int n, i;
    struct n *t, *newNode;
    struct n *oddHead = NULL, *oddTail = NULL;
    struct n *evenHead = NULL, *evenTail = NULL;

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        insert(i);
    }

    printf("\n");

    printf("Complete linked_list:\n");
    display(head);

    t = head;
    i = 1;
    do {
        newNode = (struct n*)malloc(sizeof(struct n));
        newNode->data = t->data;

        if (i % 2 == 1) {
            if (oddHead == NULL) {
                oddHead = newNode;
                oddTail = newNode;
            } else {
                oddTail->next = newNode;
                oddTail = newNode;
            }
        } else {
            if (evenHead == NULL) {
                evenHead = newNode;
                evenTail = newNode;
            } else {
                evenTail->next = newNode;
                evenTail = newNode;
            }
        }

        t = t->next;
        i++;
    } while (t != head);

    if (oddTail != NULL) {
        oddTail->next = oddHead;
    }
    if (evenTail != NULL) {
        evenTail->next = evenHead;
    }

    printf("Odd:\n");
    display(oddHead);

    printf("Even:\n");
    display(evenHead);

    return 0;
}
