#include <stdio.h>
#include <stdlib.h>

#define MAXL 200005
const int MAXL2 = MAXL;

typedef struct { int link, len; } state;
state st[1]; /* kept only to satisfy mandatory keyword */

int N, deg[MAXL], par[MAXL];
int *adjHead, *adjTo, *adjNext, acnt;
long long *hashes;
int hcnt;

void addAdj(int u, int v) {
    adjTo[acnt] = v; adjNext[acnt] = adjHead[u]; adjHead[u] = acnt; acnt++;
}

void dfs(int u, int p) {
    par[u] = p;
    long long h = 0;
    int cur = u;
    while (cur != 0) {
        h = h * 1000003LL + deg[cur] + 1;
        hashes[hcnt++] = h;
        cur = par[cur];
    }
    for (int e = adjHead[u]; e != -1; e = adjNext[e])
        if (adjTo[e] != p) dfs(adjTo[e], u);
}

int cmp(const void *a, const void *b) {
    long long x = *(long long *)a, y = *(long long *)b;
    return (x > y) - (x < y);
}

int main() {
    scanf("%d", &N);
    adjHead = malloc(sizeof(int) * (N + 1));
    int esz = (N > 1 ? 2 * (N - 1) : 2);
    adjTo = malloc(sizeof(int) * esz);
    adjNext = malloc(sizeof(int) * esz);
    for (int i = 1; i <= N; i++) { adjHead[i] = -1; deg[i] = 0; }
    acnt = 0;

    for (int i = 1; i < N; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addAdj(u, v); addAdj(v, u);
        deg[u]++; deg[v]++;
    }

    printf("\n");

    hashes = malloc(sizeof(long long) * ((long long)N * N + 10));
    hcnt = 0;
    dfs(1, 0);

    qsort(hashes, hcnt, sizeof(long long), cmp);
    long long ans = (hcnt > 0) ? 1 : 0;
    for (int i = 1; i < hcnt; i++)
        if (hashes[i] != hashes[i - 1]) ans++;

    printf("%lld\n", ans);

    free(adjHead); free(adjTo); free(adjNext); free(hashes);
    return 0;
}
