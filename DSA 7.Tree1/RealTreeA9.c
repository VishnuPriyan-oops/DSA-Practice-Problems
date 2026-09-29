#include <stdio.h>
#include <stdlib.h>

int parA[105], parB[105];

int find(int par[], int x) {
    while (par[x] != x) { par[x] = par[par[x]]; x = par[x]; }
    return x;
}

void uni(int par[], int x, int y) {
    x = find(par, x); y = find(par, y);
    if (x != y) par[x] = y;
}

int main() {
    int n, m1, m2;
    scanf("%d %d %d", &n, &m1, &m2);

    for (int i = 1; i <= n; i++) { parA[i] = i; parB[i] = i; }

    while (m1--) {
        int u, v;
        scanf("%d %d", &u, &v);
        uni(parA, u, v);
    }
    int m2c = m2;
    while (m2c--) {
        int u, v;
        scanf("%d %d", &u, &v);
        uni(parB, u, v);
    }

    printf("\n");

    int *ru = malloc(sizeof(int) * n), *rv = malloc(sizeof(int) * n);
    int h = 0;
    for (int i = 2; i <= n; i++) {
        if (find(parA, 1) != find(parA, i) && find(parB, 1) != find(parB, i)) {
            uni(parA, 1, i);
            uni(parB, 1, i);
            ru[h] = 1; rv[h] = i; h++;
        }
    }

    printf("%d\n", h);
    for (int i = 0; i < h; i++) printf("%d %d\n", ru[i], rv[i]);

    free(ru); free(rv);
    return 0;
}
