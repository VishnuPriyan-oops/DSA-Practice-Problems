#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
int counter = 1;
void insert_Data(struct node **head) {
    struct node *newNode, *temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = counter++;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void delete_Alt(struct node **head) {
    struct node *a, *b;
    a = *head;
    if (a == NULL) {
        return;
    }
    while (a != NULL && a->next != NULL) {
        b = a->next;
        a->next = b->next;
        free(b);
        a = a->next;
    }
}

int main() {
    int n, i;
    struct node *head = NULL;
    struct node *t;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        insert_Data(&head);
    }

    delete_Alt(&head);

    printf("\n");

    t = head;
    while (t != NULL) {
        printf("%d", t->data);
        if (t->next != NULL) {
            printf(" ");
        }
        t = t->next;
    }
    printf("\n");

    return 0;
}
