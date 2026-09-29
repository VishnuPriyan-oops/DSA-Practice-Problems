#include <stdio.h>

#define N 200005

int head[N], to[N], nxt[N], ecnt;
int dfn[N], low[N], st[N], in_st[N], scc[N];
int timer, top, scc_cnt;

void link(int i,int j) {
    to[++ecnt] = j;
    nxt[ecnt] = head[i];
    head[i] = ecnt;
}

int min(int a, int b) { return a < b ? a : b; }

void dfs(int u) {
    dfn[u] = low[u] = ++timer;
    st[++top] = u;
    in_st[u] = 1;
    for (int e = head[u]; e; e = nxt[e]) {
        int v = to[e];
        if (!dfn[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (in_st[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        scc_cnt++;
        while (1) {
            int v = st[top--];
            in_st[v] = 0;
            scc[v] = scc_cnt;
            if (u == v) break;
        }
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    for (int i = 0; i < n; i++) {
        char c1, c2;
        int u, v;
        scanf(" %c %d %c %d", &c1, &u, &c2, &v);
        int a = 2 * u + (c1 == '-');
        int b = 2 * v + (c2 == '-');
        link(a ^ 1, b);
        link(b ^ 1, a);
    }


    for (int i = 1; i <= m; i++) if (!dfn[2 * i + 1]) dfs(2 * i + 1);
    for (int i = 1; i <= m; i++) if (!dfn[2 * i]) dfs(2 * i);

    for (int i = 1; i <= m; i++) {
        if (scc[2 * i] == scc[2 * i + 1]) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        printf("%c%c", scc[2 * i] < scc[2 * i + 1] ? '+' : '-', i == m ? '\n' : ' ');
    }
    return 0;
}
