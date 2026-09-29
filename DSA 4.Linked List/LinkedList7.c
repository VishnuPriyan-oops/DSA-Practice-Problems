#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
int n, p;

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

void del() {
    struct node *p1;
    int found = 0;

    p1 = head;
    while (p1 != NULL) {
        if (p1->data == p) {
            found = 1;
            break;
        }
        p1=p1->next;
    }

    if (found) {
        head = p1;
    } else {
        printf("Invalid Node! ");
    }
}

int main() {
    struct node *t;

    create();
    scanf("%d", &p);

    printf("\n");

    del();

    printf("Linked List:");
    t = head;
    while (t != NULL) {
        printf("->%d", t->data);
        t = t->next;
    }
    printf("\n");

    return 0;
}
