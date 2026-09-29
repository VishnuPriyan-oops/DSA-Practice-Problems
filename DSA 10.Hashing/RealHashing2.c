#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define HASH_SIZE 200003

typedef struct HashNode {
    int x;
    int y;
    int ans;
    struct HashNode* next;
} HashNode;

HashNode* ht[HASH_SIZE];

unsigned int hash_func(int x, int y) {
    return ((unsigned int)x * 31 + (unsigned int)y) % HASH_SIZE;
}

int find_in_hash(int x, int y, int* ans) {
    unsigned int h = hash_func(x, y);
    HashNode* curr = ht[h];
    while (curr != NULL) {
        if (curr->x == x && curr->y == y) {
            *ans = curr->ans;
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

void insert_into_hash(int x, int y, int ans) {
    unsigned int h = hash_func(x, y);
    HashNode* node = (HashNode*)malloc(sizeof(HashNode));
    node->x = x;
    node->y = y;
    node->ans = ans;
    node->next = ht[h];
    ht[h] = node;
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        int a, b;
        scanf("%d %d", &a, &b);
        int x = a < b ? a : b;
        int y = a < b ? b : a;

        int cached_ans;
        if (find_in_hash(x, y, &cached_ans)) {
            if (cached_ans == 1) {
                printf("sami\n");
            } else {
                printf("canthi\n");
            }
            continue;
        }

        int diff = y - x;
        int cold_x = (int)(diff * (1.0 + sqrt(5.0)) / 2.0);

        int res = (x == cold_x) ? 1 : 0;
        insert_into_hash(x, y, res);

        if (res == 1) {
            printf("sami\n");
        } else {
            printf("canthi\n");
        }
    }

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
