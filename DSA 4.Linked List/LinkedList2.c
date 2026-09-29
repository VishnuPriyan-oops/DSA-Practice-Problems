#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

void insertStart(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;

    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

int main() {
    struct Node *head = NULL;
    struct Node *t;
    int n, i, val;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        insertStart(&head, val);
    }

    printf("\n");

    t = head;
    while (t != NULL) {
        printf("%d", t->data);
        if (t->next != NULL) {
            printf(" ");
        }
        if (t->next == NULL) {
            break;
        }
        t = t->next;
    }
    printf("\n");

    while (t != NULL) {
        printf("%d", t->data);
        if (t->prev != NULL) {
            printf(" ");
        }
        t = t->prev;
    }
    printf("\n");

    return 0;
}
