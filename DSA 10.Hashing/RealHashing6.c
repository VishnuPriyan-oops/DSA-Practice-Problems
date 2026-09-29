#include <stdio.h>

int A[1000050];
int hash[2000050];
int visited[2000050];

int main() {
    int M, Q, N, i, d;
    if (scanf("%d", &M) != 1) return 0;
    if (scanf("%d", &Q) != 1) return 0;
    if (scanf("%d", &N) != 1) return 0;

    for(i=0;i<N;i++) {
        scanf("%d", &A[i]);
        hash[A[i]]++;
    }

    int max_rating = 0;

    for(i=0;i<N;i++) {
        for(d = -Q; d <= Q; d++) {
            int T = A[i] + d * M;
            if (T < 0 || visited[T]) continue;
            visited[T] = 1;

            int current_rating = 0;
            for(int k = -Q; k <= Q; k++) {
                int src = T - k * M;
                if (src >= 0 && src <= 1000000) {
                    current_rating += hash[src];
                }
            }
            if (current_rating > max_rating) {
                max_rating = current_rating;
            }
        }
    }

    printf("%d\n", max_rating);
    return 0;
}
