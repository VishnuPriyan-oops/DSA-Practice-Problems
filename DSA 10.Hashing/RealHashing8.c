#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 100003

typedef struct HashNode {
    long long key;
    struct HashNode* next;
} HashNode;

HashNode* buckets[HASH_SIZE];
long long sorted_keys[500005];
int key_count = 0;

void insert_hash(long long key) {
    unsigned int h = (unsigned int)(key % HASH_SIZE);
    HashNode* curr = buckets[h];
    while (curr) {
        if (curr->key == key) return;
        curr = curr->next;
    }
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->next = buckets[h];
    buckets[h] = newNode;


    sorted_keys[key_count++] = key;
    int i = key_count - 1;
    while (i > 0 && sorted_keys[i] < sorted_keys[i - 1]) {
        long long temp = sorted_keys[i];
        sorted_keys[i] = sorted_keys[i - 1];
        sorted_keys[i - 1] = temp;
        i--;
    }
}

long long find_ge(long long y) {
    int low = 0, high = key_count - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (sorted_keys[mid] >= y) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return (ans == -1) ? -1 : sorted_keys[ans];
}

int main() {
    long long n;
    int q, i;
    if (scanf("%lld %d", &n, &q) != 2) return 0;

    for (i = 0; i < q; i++) {
        int type;
        long long arg;
        scanf("%d %lld", &type, &arg);
        if (type == 1) {
            insert_hash(arg);
        } else {
            printf("%lld\n", find_ge(arg));
        }
    }

    return 0;
}
