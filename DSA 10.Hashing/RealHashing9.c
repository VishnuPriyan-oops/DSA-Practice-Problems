#include <stdio.h>
#include <stdlib.h>

#define MAX_VAL 1000000
#define HASH_SIZE 100003

int divisor_count[MAX_VAL + 1];

typedef struct HashNode {
    int div_cnt;
    long long freq;
    struct HashNode* next;
} HashNode;

HashNode* ht[HASH_SIZE];

unsigned int hash_func(int key) {
    return (unsigned int)key % HASH_SIZE;
}

void insert_hash(int div_cnt) {
    unsigned int idx = hash_func(div_cnt);
    HashNode* curr = ht[idx];
    while (curr != NULL) {
        if (curr->div_cnt == div_cnt) {
            curr->freq++;
            return;
        }
        curr = curr->next;
    }
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->div_cnt = div_cnt;
    newNode->freq = 1;
    newNode->next = ht[idx];
    ht[idx] = newNode;
}

void precompute() {
    for (int i = 1; i <= MAX_VAL; i++) {
        for (int j = i; j <= MAX_VAL; j += i) {
            divisor_count[j]++;
        }
    }
}

int main() {
    precompute();

    int N;
    if (scanf("%d", &N) != 1) return 0;

    int original_N = N;
    if (original_N > 0) {
        int val;
        scanf("%d", &val);
        insert_hash(divisor_count[val]);
        N--;
    }

    while (--N >= 0) {
        int val;
        scanf("%d", &val);
        insert_hash(divisor_count[val]);
    }

    long long total_pairs = 0;
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* curr = ht[i];
        while (curr != NULL) {
            if (curr->freq > 1) {
                total_pairs += (curr->freq * (curr->freq - 1)) / 2;
            }
            curr = curr->next;
        }
    }

    printf("%lld\n", total_pairs);

    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* curr = ht[i];
        while (curr != NULL) {
            HashNode* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }

    return 0;
}
