#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
int n;

void create() {
    int i, val;
    struct node *newNode, *temp;

    scanf("%d", &n);
    for(i=0;i<n;i++) {
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

int main() {
    int d, i;
    struct node *temp, *t;

    create();
    scanf("%d", &d);

    printf("\n");

    for (i = 0; i < d; i++) {
        if (head != NULL) {
            temp = head;
            head = head->next;
            free(temp);
        }
    }

    printf("Linked List:");
    t = head;
    while (t != NULL) {
        printf("->%d", t->data);
        t = t->next;
    }
    printf("\n");

    return 0;
}
