#include <stdio.h>
#include<stdlib.h>
#include <string.h>

#define MAXN 200005
#define LOG 19

int up[LOG][MAXN];
int n, q;

void link(int i, int j) {
    up[0][i] = j;
}

int main() {
    scanf("%d %d", &n, &q);

    memset(up, 0, sizeof(up));

    for (int i = 2; i <= n; i++) {
        int e;
        scanf("%d", &e);
        link(i, e);
    }

    for (int j = 1; j < LOG; j++)
        for (int i = 1; i <= n; i++)
            up[j][i] = up[j - 1][i] ? up[j - 1][up[j - 1][i]] : 0;

    int *x = malloc(sizeof(int) * q), *k = malloc(sizeof(int) * q);
    for (int i = 0; i < q; i++) scanf("%d %d", &x[i], &k[i]);

    printf("\n");

    for (int i = 0; i < q; i++) {
        int cur = x[i], kk = k[i];
        for (int j = 0; j < LOG && cur; j++)
            if (kk & (1 << j)) cur = up[j][cur];
        printf("%d\n", cur ? cur : -1);
    }

    free(x); free(k);
    return 0;
}
