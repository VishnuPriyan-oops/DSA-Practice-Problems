#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct mystack {
    Node* top;
} mystack;

void push(int data, mystack* ms) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->next = ms->top;
    ms->top = n;
}

int pop(mystack* ms) {
    if (ms->top == NULL) return -1;
    Node* t = ms->top;
    int val = t->data;
    ms->top = t->next;
    free(t);
    return val;
}

void merge(mystack* ms1, mystack* ms2) {
    Node* c = ms1->top;
    if (c == NULL) { ms1->top = ms2->top; ms2->top = NULL; return; }
    while (c->next != NULL) c = c->next;
    c->next = ms2->top;
    ms2->top = NULL;
}

void printStack(mystack* ms) {
    Node* c = ms->top;
    int first = 1;
    while (c != NULL) {
        printf(first ? "%d" : " %d", c->data);
        first = 0;
        c = c->next;
    }
    printf("\n");
}

int main() {
    int n, m, i, value;
    mystack s1 = {NULL}, s2 = {NULL};

    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) { scanf("%d", &value); push(value, &s1); }
    for (i = 0; i < m; i++) { scanf("%d", &value); push(value, &s2); }

    merge(&s1, &s2);
    printStack(&s1);

    return 0;
}
