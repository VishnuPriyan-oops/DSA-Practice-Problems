#include <stdio.h>
#include <stdlib.h>

typedef struct QNode {
    struct QNode *prev, *next;
    unsigned pageNumber;
} QNode;

typedef struct Queue {
    unsigned count, numberOfFrames;
    QNode *head, *tail;
} Queue;

QNode* hashArr[10] = {NULL};

QNode* newQNode(unsigned pageNumber) {
    QNode* n = (QNode*)malloc(sizeof(QNode));
    n->pageNumber = pageNumber;
    n->prev = n->next = NULL;
    return n;
}

Queue* createQueue(int numberOfFrames) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->count = 0;
    q->numberOfFrames = numberOfFrames;
    q->head = q->tail = NULL;
    return q;
}

void refer(Queue* q, unsigned page) {
    QNode* node = hashArr[page];
    QNode* old;

    if (node == NULL) {
        if (q->count == q->numberOfFrames) {
            hashArr[q->tail->pageNumber] = NULL;
            old = q->tail;
            q->tail = q->tail->prev;
            if (q->tail) q->tail->next = NULL; else q->head = NULL;
            free(old);
            q->count--;
        }
        node = newQNode(page);
        node->next = q->head;
        if (q->head) q->head->prev = node; else q->tail = node;
        q->head = node;
        hashArr[page] = node;
        q->count++;
    } else if (node != q->head) {
        if (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;
        if (node == q->tail) q->tail = node->prev;
        node->prev = NULL;
        node->next = q->head;
        q->head->prev = node;
        q->head = node;
    }
}

int main() {
    int n, m, i, page, first = 1;
    Queue* q;
    QNode* t;

    scanf("%d %d", &n, &m);
    q = createQueue(m);

    for (i = 0; i < n; i++) {
        scanf("%d", &page);
        refer(q, page);
    }

    printf("\n");
    t = q->head;
    while (t) {
        printf(first ? "%u" : " %u", t->pageNumber);
        first = 0;
        t = t->next;
    }
    printf("\n");

    return 0;
}
