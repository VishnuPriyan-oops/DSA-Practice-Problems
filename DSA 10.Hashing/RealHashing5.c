#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 313

typedef struct HashNode {
    int ascii_val;
    int freq;
    struct HashNode* next;
} HashNode;

HashNode* ht[HASH_SIZE];

unsigned int hash_func(int val) {
    return (unsigned int)val % HASH_SIZE;
}

void insert_hash(int val) {
    unsigned int idx = hash_func(val);
    HashNode* curr = ht[idx];
    while (curr != NULL) {
        if (curr->ascii_val == val) {
            curr->freq++;
            return;
        }
        curr = curr->next;
    }
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->ascii_val = val;
    newNode->freq = 1;
    newNode->next = ht[idx];
    ht[idx] = newNode;
}

int main() {
    char str[1005];
    if (!fgets(str, sizeof(str), stdin)) return 0;

    str[strcspn(str, "\r\n")] = 0;
    int l = strlen(str);

    for (int i = 0; i < l; i++) {
        insert_hash((unsigned char)str[i]);
    }

    char max_char = 0;
    int max_freq = 0;

    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* curr = ht[i];
        while (curr != NULL) {
            if (curr->freq > max_freq) {
                max_freq = curr->freq;
                max_char = (char)curr->ascii_val;
            } else if (curr->freq == max_freq) {
                if (max_char == 0 || curr->ascii_val < (unsigned char)max_char) {
                    max_char = (char)curr->ascii_val;
                }
            }
            curr = curr->next;
        }
    }

    printf("%c %d\n", max_char, max_freq);


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
