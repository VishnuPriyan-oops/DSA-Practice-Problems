#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;
#define MAXN 100005

int head[MAXN], nxt[2 * MAXN], to[2 * MAXN], ecnt;

void addEdge(int u, int v) {
    to[ecnt] = v; nxt[ecnt] = head[u]; head[u] = ecnt; ecnt++;
    to[ecnt] = u; nxt[ecnt] = head[v]; head[v] = ecnt; ecnt++;
}

int cmpull(const void *a, const void *b) {
    ull x = *(ull *)a, y = *(ull *)b;
    return (x > y) - (x < y);
}

ull dfs(int u, int p) {
    ull arr[64];
    int cnt = 0;
    ull *big = NULL;
    for (int e = head[u]; e != -1; e = nxt[e]) if (to[e] != p) cnt++;

    ull *ch = (cnt <= 64) ? arr : (big = malloc(sizeof(ull) * cnt));
    int idx = 0;
    for (int e = head[u]; e != -1; e = nxt[e])
        if (to[e] != p) ch[idx++] = dfs(to[e], u);

    qsort(ch, idx, sizeof(ull), cmpull);
    ull h = 1469598103934665603ULL;
    for (int j = 0; j < idx; j++) h = (h ^ (ch[j] + 1000000007ULL)) * 1099511628211ULL;
    h = h * 1099511628211ULL + (ull)(idx + 1);

    if (big) free(big);
    return h;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) head[i] = -1;
        ecnt = 0;
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            addEdge(u, v);
        }
        ull h1 = dfs(1, 0);

        for (int i = 1; i <= n; i++) head[i] = -1;
        ecnt = 0;
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            addEdge(u, v);
        }
        ull h2 = dfs(1, 0);

        printf(h1 == h2 ? "YES\n" : "NO\n");
    }

    return 0;
}
