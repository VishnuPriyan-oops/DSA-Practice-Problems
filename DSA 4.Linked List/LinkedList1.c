#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
int n, d;

void create() {
    int i, val;
    struct node *newNode, *temp;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void del() {
    struct node *p1, *p2, *temp;

    while (head != NULL && head->data == d) {
        temp = head;
        head = head->next;
        free(temp);
    }
    if (head == NULL) {
        return;
    }

    p1 = head;
    p2 = head->next;
    while (p2 != NULL) {
        if (p2->data == d) {
            p1->next = p2->next;
            temp = p2;
            p2=p2->next;
            free(temp);
        } else {
            p1 = p2;
            p2=p2->next;
        }
    }
}
int main() {
    struct node *t;
    create();
    scanf("%d", &d);

    del();

    printf("\n");

    printf("Linked List:");
    t = head;
    while (t != NULL) {
        printf("->%d", t->data);
        t = t->next;
    }
    printf("\n");

    return 0;
}
