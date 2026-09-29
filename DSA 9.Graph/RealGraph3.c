#include <stdio.h>
#include <string.h>

#define MAXN 505

int cap[MAXN][MAXN], orig_cap[MAXN][MAXN], parent[MAXN];

int bfs(int n,int s,int t) {
    memset(parent, 0, sizeof(parent));
    int q[MAXN], front = 0, back = 0;
    q[back++] = s;
    parent[s] = -1;
    while (front < back) {
        int u = q[front++];
        if (u == t) return 1;
        for (int v = n; v >= 1; v--) {
            if (!parent[v] && cap[u][v] > 0) {
                parent[v] = u;
                q[back++] = v;
            }
        }
    }
    return 0;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        cap[u][v]++;
        orig_cap[u][v]++;
    }

    int k = 0;
    while (bfs(n, 1, n)) {
        int v = n;
        while (v != 1) {
            int u = parent[v];
            cap[u][v]--;
            cap[v][u]++;
            v = u;
        }
        k++;
    }

    printf("%d\n", k);

    int used[MAXN][MAXN];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            used[i][j] = orig_cap[i][j] > cap[i][j] ? orig_cap[i][j] - cap[i][j] : 0;
        }
    }

    for (int i = 0; i < k; i++) {
        int path[MAXN], len = 0, curr = 1;
        path[len++] = curr;
        while (curr != n) {
            for (int v = n; v >= 1; v--) {
                if (used[curr][v] > 0) {
                    used[curr][v]--;
                    curr = v;
                    path[len++] = curr;
                    break;
                }
            }
        }
        printf("%d\n", len);
        for (int j = 0; j < len; j++) {
            printf("%d%c", path[j], j == len - 1 ? '\n' : ' ');
        }
    }

    return 0;
}
