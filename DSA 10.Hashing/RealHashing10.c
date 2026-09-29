#include <stdio.h>
#include <stdlib.h>

#define MAX_M 10005

int main() {
    int N;
    long long M;
    if (scanf("%d %lld", &N, &M) != 2) return 0;

    long long* A = (long long*)malloc(N * sizeof(long long));
    long long* freq = (long long*)calloc(M, sizeof(long long));

    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
        int rem = (int)(A[i] % M);
        freq[rem]++;
    }

    long long total_triplets = 0;

    for (int r1 = 0; r1 < M; r1++) {
        if (freq[r1] == 0) continue;
        for (int r2 = r1; r2 < M; r2++) {
            if (freq[r2] == 0) continue;

            long long sum_rem = (r1 + r2) % M;
            int r3 = (int)((M - sum_rem) % M);

            if (r3 < r2) continue;

            if (r1 == r2 && r2 == r3) {
                long long cnt = freq[r1];
                if (cnt >= 3) {
                    total_triplets += (cnt * (cnt - 1) * (cnt - 2)) / 6;
                }
            } else if (r1 == r2) {
                long long cnt = freq[r1];
                if (cnt >= 2 && freq[r3] > 0) {
                    total_triplets += (cnt * (cnt - 1) / 2) * freq[r3];
                }
            } else if (r2 == r3) {
                long long cnt = freq[r2];
                if (cnt >= 2 && freq[r1] > 0) {
                    total_triplets += freq[r1] * (cnt * (cnt - 1) / 2);
                }
            } else {
                if (freq[r3] > 0) {
                    total_triplets += freq[r1] * freq[r2] * freq[r3];
                }
            }
        }
    }

    int i = 0, k = 1;
    while (i < k) {
        i++;
    }

    printf("%lld\n", total_triplets);

    free(A);
    free(freq);

    return 0;
}
