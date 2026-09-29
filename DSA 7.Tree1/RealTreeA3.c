#include <stdio.h>
#include <stdlib.h>
#define MAXN 1005

int BIT[MAXN][MAXN];
int n;

void update(int x, int y, int val) {
    for (int i = x; i <= n; i += i & (-i))
        for (int j = y; j <= n; j += j & (-j))
            BIT[i][j] += val;
}

int query(int x, int y) {
    int s = 0;
    for (int i = x; i > 0; i -= i & (-i))
        for (int j = y; j > 0; j -= j & (-j))
            s += BIT[i][j];
    return s;
}

int rectSum(int x1, int y1, int x2, int y2) {
    return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
}

int main() {
    int q;
    scanf("%d %d", &n, &q);

    char row[1005];
    for (int i = 1; i <= n; i++) {
        scanf("%s", row);
        for (int j = 1; j <= n; j++)
            if (row[j - 1] == '*') update(i, j, 1);
    }

    int *y1 = malloc(q * sizeof(int)), *x1 = malloc(q * sizeof(int));
    int *y2 = malloc(q * sizeof(int)), *x2 = malloc(q * sizeof(int));
    for (int i = 0; i < q; i++)
        scanf("%d %d %d %d", &y1[i], &x1[i], &y2[i], &x2[i]);

    printf("\n");

    for (int i = 0; i < q; i++)
        printf("%d\n", rectSum(y1[i], x1[i], y2[i], x2[i]));

    free(y1); free(x1); free(y2); free(x2);
    return 0;
}
