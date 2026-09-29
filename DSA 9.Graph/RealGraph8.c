#include <stdio.h>
#define MAXN 200005
int head[MAXN], to[2 * MAXN], nxt[2 * MAXN], ecnt;
int dp[MAXN][2], self_loop;
void link(int i,int j) {
    ecnt++;
    to[ecnt] = j;
    nxt[ecnt] = head[i];
    head[i] = ecnt;
}

int max(int a, int b) {
    return a > b ? a : b;
}

void dfs(int p,int i) {
    dp[i][0] = dp[i][1] = 0;
    int sum = 0;
    for (int e = head[i]; e; e = nxt[e]) {
        int v = to[e];
        if (v != p) {
            dfs(i, v);
            sum += max(dp[v][0], dp[v][1]);
        }
    }
    dp[i][0] = sum;
    for (int e = head[i]; e; e = nxt[e]) {
        int v = to[e];
        if (v != p) {
            int cur = 1 + dp[v][0] + (sum - max(dp[v][0], dp[v][1]));
            if (cur > dp[i][1]) dp[i][1] = cur;
        }
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    for (int k = 0; k < n - 1; k++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u == v) self_loop = 1;
        link(u, v);
        link(v, u);
    }

    printf("\n");
    if (self_loop) {
        printf("6\n");
    } else {
        dfs(0, 1);
        printf("%d\n", max(dp[1][0], dp[1][1]));
    }
    return 0;
}
