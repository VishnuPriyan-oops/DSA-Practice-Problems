#include <stdio.h>
#include <string.h>

int cap[505][505], orig[505][505], parent[505], route[505][505], rlen[505];
int bfs(int n,int s,int t) {
    memset(parent, 0, sizeof(parent));
    int q[505], f = 0, b = 0;
    q[b++] = s; parent[s] = -1;
    while (f < b) {
        int u = q[f++];
        if (u == t) return 1;
        for (int v = n; v >= 1; v--)
            if (!parent[v] && cap[u][v] > 0) { parent[v] = u; q[b++] = v; }
    }
    return 0;
}

int main() {
    int n, m, u, v, k = 0;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    while (m--) { scanf("%d %d", &u, &v); cap[u][v]++; orig[u][v]++; }

    while (bfs(n, 1, n)) {
        for (v = n; v != 1; v = parent[v]) { cap[parent[v]][v]--; cap[v][parent[v]]++; }
        k++;
    }

    for (u = 1; u <= n; u++)
        for (v = 1; v <= n; v++)
            orig[u][v] = orig[u][v] > cap[u][v] ? orig[u][v] - cap[u][v] : 0;

    for (int i = 0; i < k; i++) {
        int curr = 1, l = 0;
        route[i][l++] = 1;
        while (curr != n) {
            for (v = n; v >= 1; v--)
                if (orig[curr][v] > 0) { orig[curr][v]--; curr = v; route[i][l++] = curr; break; }
        }
        rlen[i] = l;
    }

    for (int i = 0; i < k - 1; i++)
        for (int j = i + 1; j < k; j++)
            if (rlen[i] < rlen[j]) {
                int t = rlen[i]; rlen[i] = rlen[j]; rlen[j] = t;
                for (int x = 0; x < 505; x++) { t = route[i][x]; route[i][x] = route[j][x]; route[j][x] = t; }
            }

    printf("\n%d\n", k);
    for (int i = 0; i < k; i++) {
        printf("%d\n", rlen[i]);
        for (int j = 0; j < rlen[i]; j++)
            printf("%d%c", route[i][j], j == rlen[i] - 1 ? '\n' : ' ');
    }
    return 0;
}
