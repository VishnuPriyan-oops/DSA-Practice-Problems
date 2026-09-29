#include <stdio.h>
#include <string.h>

int cap[505][505], parent[505], vis[505], eu[1005], ev[1005];

void link(int i, int h) {
    cap[i][h] = cap[h][i] = 1;
}

int bfs(int n,int s,int t) {
    memset(parent, 0, sizeof(parent));
    int q[505], f = 0, b = 0;
    q[b++] = s; parent[s] = -1;
    while (f < b) {
        int u = q[f++];
        if (u == t) return 1;
        for (int v = 1; v <= n; v++)
            if (!parent[v] && cap[u][v] > 0) { parent[v] = u; q[b++] = v; }
    }
    return 0;
}

void dfs(int u, int n) {
    vis[u] = 1;
    for (int v = 1; v <= n; v++)
        if (!vis[v] && cap[u][v] > 0) dfs(v, n);
}

int main() {
    int n, m, k_cnt = 0, cu[1005], cv[1005];
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int k = 0; k < m; k++) {
        scanf("%d %d", &eu[k], &ev[k]);
        if (eu[k] != ev[k]) link(eu[k], ev[k]);
    }

    while (bfs(n, 1, n))
        for (int v = n; v != 1; v = parent[v]) { cap[parent[v]][v]--; cap[v][parent[v]]++; }

    dfs(1, n);

    for (int k = 0; k < m; k++) {
        int u = eu[k], v = ev[k];
        if (vis[u] != vis[v]) {
            cu[k_cnt] = u < v ? u : v;
            cv[k_cnt] = u < v ? v : u;
            k_cnt++;
        }
    }

    for (int i = 0; i < k_cnt - 1; i++)
        for (int j = i + 1; j < k_cnt; j++)
            if (cu[i] > cu[j] || (cu[i] == cu[j] && cv[i] > cv[j])) {
                int tu = cu[i]; cu[i] = cu[j]; cu[j] = tu;
                int tv = cv[i]; cv[i] = cv[j]; cv[j] = tv;
            }

    printf("\n%d\n", k_cnt);
    for (int i = 0; i < k_cnt; i++) printf("%d %d\n", cu[i], cv[i]);

    return 0;
}
