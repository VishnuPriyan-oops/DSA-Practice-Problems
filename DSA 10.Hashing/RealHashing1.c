#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 400009

typedef struct HashNode {
    long long key;
    int visited;
    struct HashNode* next;
} HashNode;

HashNode* table_r[HASH_SIZE];
HashNode* table_l[HASH_SIZE];

void insert_hash(HashNode* table[], long long key) {
    unsigned int idx = (unsigned int)(key % HASH_SIZE);
    HashNode* curr = table[idx];
    while (curr != NULL) {
        if (curr->key == key) {
            curr->visited = 1;
            return;
        }
        curr = curr->next;
    }
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->visited = 1;
    newNode->next = table[idx];
    table[idx] = newNode;
}

int search_hash(HashNode* table[], long long key) {
    unsigned int idx = (unsigned int)(key % HASH_SIZE);
    HashNode* curr = table[idx];
    while (curr != NULL) {
        if (curr->key == key) return 1;
        curr = curr->next;
    }
    return 0;
}

int arr[200005];
int suffix_distinct[200005];

int main() {
    int n, i;
    if (scanf("%d", &n) != 1) return 0;

    int max = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max) max = arr[i];
    }

    int distinct_cnt = 0;
    for (i = n - 1; i >= 0; i--) {
        if (!search_hash(table_r, arr[i])) {
            insert_hash(table_r, arr[i]);
            distinct_cnt++;
        }
        suffix_distinct[i] = distinct_cnt;
    }

    long long total_pairs = 0;
    for (i = 0; i < n; i++) {
        if (!search_hash(table_l, arr[i])) {
            insert_hash(table_l, arr[i]);
            total_pairs += suffix_distinct[i + 1];
        }
    }

    printf("%lld\n", total_pairs);

    for (int j = 0; j < HASH_SIZE; j++) {
        HashNode* curr = table_r[j];
        while (curr != NULL) {
            HashNode* temp = curr;
            curr = curr->next;
            free(temp);
        }
        curr = table_l[j];
        while (curr != NULL) {
            HashNode* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }

    return 0;
}
