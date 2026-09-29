#include <stdio.h>
#include <string.h>

int cap[1005][1005], orig[1005][1005], parent[1005];

void link(int u,int v) {
    cap[u][v] = 1;
    orig[u][v] = 1;
}

int bfs(int n) {
    memset(parent, -1, sizeof(parent));
    int q[1005], f = 0, b = 0;
    q[b++] = 0;
    parent[0] = 0;
    while (f < b) {
        int u = q[f++];
        if (u == n) return 1;
        for (int v = 1; v <= n; v++) {
            if (parent[v] == -1 && cap[u][v] > 0) {
                parent[v] = u;
                q[b++] = v;
            }
        }
    }
    return 0;
}

int main() {
    int n, m, k;
    if (scanf("%d %d %d", &n, &m, &k) != 3) return 0;

    int max_g = m;
    for (int i = 0; i < k; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (v > max_g) max_g = v;
        link(u, n + v);
    }

    int T = n + max_g + 1;
    for (int i = 1; i <= n; i++) link(0, i);
    for (int j = 1; j <= max_g; j++) link(n + j, T);

    int flow = 0;
    while (bfs(T)) {
        int v = T;
        while (v != 0) {
            int u = parent[v];
            cap[u][v]--;
            cap[v][u]++;
            v = u;
        }
        flow++;
    }

    printf("\n%d\n", flow);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= max_g; j++) {
            if (orig[i][n + j] && cap[i][n + j] == 0) {
                printf("%d %d\n", i, j);
            }
        }
    }
    return 0;
}
