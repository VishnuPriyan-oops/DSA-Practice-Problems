#include <stdio.h>

#define MAXN 300005

int pG[MAXN], head[MAXN], to[2 * MAXN], nxt[2 * MAXN], wt[2 * MAXN], rm[2 * MAXN], ecnt;
int target, path_edges[MAXN], path_cnt;

int findG(int u) {
    return pG[u] == u ? u : (pG[u] = findG(pG[u]));
}

void add_edge(int u, int v, int x) {
    ecnt++; to[ecnt] = v; wt[ecnt] = x; nxt[ecnt] = head[u]; head[u] = ecnt;
    ecnt++; to[ecnt] = u; wt[ecnt] = x; nxt[ecnt] = head[v]; head[v] = ecnt;
}

int dfs1(int np,int lst) {
    if (np == target) return 1;
    for (int e = head[np]; e; e = nxt[e]) {
        if (rm[e]) continue;
        int v = to[e];
        if (v != lst) {
            path_edges[path_cnt++] = e;
            if (dfs1(v, np)) return 1;
            path_cnt--;
        }
    }
    return 0;
}

int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 0;

    for (int i = 1; i <= n; i++) pG[i] = i;

    printf("\n");

    while (q--) {
        int u, v, x;
        scanf("%d %d %d", &u, &v, &x);

        int ru = findG(u), rv = findG(v);
        if (ru != rv) {
            pG[ru] = rv;
            add_edge(u, v, x);
            printf("YES\n");
        } else {
            target = v;
            path_cnt = 0;
            if (dfs1(u, 0)) {
                int path_xor = 0;
                for (int i = 0; i < path_cnt; i++) {
                    path_xor ^= wt[path_edges[i]];
                }
                if ((path_xor ^ x) == 1) {
                    for (int i = 0; i < path_cnt; i++) {
                        int e = path_edges[i];
                        rm[e] = 1;
                        rm[e % 2 ? e + 1 : e - 1] = 1;
                    }
                    printf("YES\n");
                } else {
                    printf("NO\n");
                }
            } else {
                printf("NO\n");
            }
        }
    }
    return 0;
}
