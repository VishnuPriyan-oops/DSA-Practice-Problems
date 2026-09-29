#include <stdio.h>
#include <stdlib.h>

typedef struct { int a, b, c; } Edge;
int par[5005];
int find(int x) { while (par[x] != x) { par[x] = par[par[x]]; x = par[x]; } return x; }

int cmp(const void *p, const void *q) {
    return ((Edge *)q)->c - ((Edge *)p)->c; /* descending */
}

int printheap(int N) {
    printf("%d\n", N);
    return N;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);

        Edge *e = malloc(sizeof(Edge) * m);
        for (int i = 0; i < m; i++) scanf("%d %d %d", &e[i].a, &e[i].b, &e[i].c);

        printf("\n");

        for (int i = 1; i <= n; i++) par[i] = i;
        qsort(e, m, sizeof(Edge), cmp);

        long long total = 0;
        int used = 0;
        for (int i = 0; i < m && used < n - 1; i++) {
            int ra = find(e[i].a), rb = find(e[i].b);
            if (ra != rb) { par[ra] = rb; total += e[i].c; used++; }
        }

        printf("%lld\n", total);
        free(e);
    }

    return 0;
}
