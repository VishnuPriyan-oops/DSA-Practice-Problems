#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int GetNth(struct node* head, int index) {
    struct node* current = head;
    int count = 1;

    while (current != NULL) {
        if (count == index) {
            return current->data;
        }
        count++;
        current = current->next;
    }
    return -1;
}

int main() {
    struct node *head = NULL;
    struct node *newNode, *t;
    int n, i, val, idx, result;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = val;
        newNode->next = head;
        head = newNode;
    }

    scanf("%d", &idx);

    printf("\n");

    printf("Linked list:");
    t = head;
    while (t != NULL) {
        printf("-->%d", t->data);
        t = t->next;
    }
    printf("\n");

    result = GetNth(head, idx);
    printf("Node at index=%d:%d\n", idx, result);

    return 0;
}
