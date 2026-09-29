#include <stdio.h>
#include <stdlib.h>

long long A[2005];
long long P[2005];

#define HASH_SIZE 4000037
long long ht[HASH_SIZE];
int used[HASH_SIZE];

int insert_hash(long long val) {
    unsigned long long h = (unsigned long long)val;
    int idx = h % HASH_SIZE;
    while (used[idx]) {
        if (ht[idx] == val) return 0;
        idx = (idx + 1) % HASH_SIZE;
    }
    used[idx] = 1;
    ht[idx] = val;
    return 1;
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    int NA[N];
    (void)NA;

    P[0] = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &A[i]);
        P[i] = P[i - 1] + A[i];
    }

    long long unique_sum = 0;

    for (int i = 1; i <= N; i++) {
        long long min_P = P[i - 1];
        long long max_sub = A[i];
        if (insert_hash(max_sub)) unique_sum += max_sub;

        for (int j = i + 1; j <= N; j++) {
            if (P[j - 1] < min_P) min_P = P[j - 1];
            long long S = P[j] - min_P;
            if (S > max_sub) max_sub = S;
            if (insert_hash(max_sub)) unique_sum += max_sub;
        }
    }

    printf("%lld\n", unique_sum);
    return 0;
}
