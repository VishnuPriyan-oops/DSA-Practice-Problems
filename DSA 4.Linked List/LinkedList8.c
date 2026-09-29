#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
void create(struct node **head, int data) {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    struct node *t;
    n->data = data;
    n->next = NULL;
    if (*head == NULL) { *head = n; return; }
    t = *head;
    while (t->next) t = t->next;
    t->next = n;
}
void print(struct node *head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" ");
        head = head->next;
    }
    printf("\n");
}
struct node* reverseList(struct node* head) {
    struct node *prev = NULL, *curr = head, *next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void fold(struct node** head) {
    struct node *slow = *head, *fast = *head, *second, *first, *t1, *t2;
    if (!*head || !(*head)->next) return;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    second = slow->next;
    slow->next = NULL;
    second = reverseList(second);

    first = *head;
    while (second) {
        t1 = first->next;
        t2 = second->next;
        first->next = second;
        if (t1) second->next = t1;
        first = t1;
        second = t2;
    }
}
int main() {
    struct node *head = NULL;
    int n, i, val;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        create(&head, val);
    }
    printf("\n");
    printf("Link list data:");
    print(head);
    fold(&head);
    printf("Link list data after fold:");
    print(head);

    return 0;
}
