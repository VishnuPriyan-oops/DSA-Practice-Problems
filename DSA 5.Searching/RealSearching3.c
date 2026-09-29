#include <stdio.h>
#include <stdbool.h>

#define MAXN 309

int A[MAXN][MAXN];
bool ok[MAXN][MAXN][MAXN];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int R, C, L;
        scanf("%d %d %d", &R, &C, &L);

        for (int r = 1; r <= R; r++)
            for (int c = 1; c <= C; c++)
                scanf("%d", &A[r][c]);

        for (int r = 1; r <= R; r++) {
            for (int c1 = 1; c1 <= C; c1++) {
                int mx = A[r][c1], mn = A[r][c1];
                for (int c2 = c1; c2 <= C; c2++) {
                    if (A[r][c2] > mx) mx = A[r][c2];
                    if (A[r][c2] < mn) mn = A[r][c2];
                    ok[r][c1][c2] = (mx - mn <= L);
                }
            }
        }

        int best = 0;
        for (int c1 = 1; c1 <= C; c1++) {
            for (int c2 = c1; c2 <= C; c2++) {
                int run = 0;
                for (int r = 1; r <= R; r++) {
                    if (ok[r][c1][c2]) {
                        run++;
                        int area = run * (c2 - c1 + 1);
                        if (area > best) best = area;
                    } else {
                        run = 0;
                    }
                }
            }
        }

        printf("\n");
        printf("%d\n", best);
    }

    return 0;
}
