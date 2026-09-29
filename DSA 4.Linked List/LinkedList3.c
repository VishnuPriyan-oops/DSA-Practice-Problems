#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void sortedInsert(struct Node** head_ref, struct Node* new_node) {
    struct Node* present = *head_ref;

    if (present == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
        return;
    }

    if (present->data >= new_node->data) {
        while (present->next != *head_ref) {
            present = present->next;
        }
        present->next = new_node;
        new_node->next = *head_ref;
        *head_ref = new_node;
    } else {
        while (present->next != *head_ref && present->next->data < new_node->data) {
            present = present->next;
        }
        new_node->next = present->next;
        present->next = new_node;
    }
}

int main() {
    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *t;
    int n, i, val;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        sortedInsert(&head, newNode);
    }

    printf("\n");

    t = head;
    do {
        printf("%d", t->data);
        t = t->next;
        if (t != head) {
            printf(" ");
        }
    } while (t != head);
    printf("\n");

    return 0;
}
