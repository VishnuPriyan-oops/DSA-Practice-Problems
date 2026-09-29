#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005
#define MAXM 200005

int headF[MAXN], nxtF[MAXM], toF[MAXM], ecF;
int headR[MAXN], nxtR[MAXM], toR[MAXM], ecR;
int n, m, *eu, *ev;
int vis[MAXN], comp[MAXN], order_[MAXN], ocnt, cc;
int stk[MAXN], stkE[MAXN];

void dfs(int s, int useF) {
    int top = 0;
    stk[0] = s; stkE[0] = useF ? headF[s] : headR[s]; vis[s] = 1;
    while (top >= 0) {
        int u = stk[top], e = stkE[top];
        if (e == -1) { if (useF) order_[ocnt++] = u; top--; continue; }
        stkE[top] = useF ? nxtF[e] : nxtR[e];
        int v = useF ? toF[e] : toR[e];
        if (!vis[v]) {
            vis[v] = 1; if (!useF) comp[v] = comp[u];
            stk[++top] = v; stkE[top] = useF ? headF[v] : headR[v];
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    eu = malloc(sizeof(int) * m); ev = malloc(sizeof(int) * m);
    for (int i = 1; i <= n; i++) { headF[i] = -1; headR[i] = -1; }
    ecF = ecR = 0;

    int mm = m;
    while (mm--) {
        int a, b; scanf("%d %d", &a, &b);
        eu[m - mm - 1] = a; ev[m - mm - 1] = b;
        toF[ecF] = b; nxtF[ecF] = headF[a]; headF[a] = ecF++;
        toR[ecR] = a; nxtR[ecR] = headR[b]; headR[b] = ecR++;
    }

    printf("\n");

    ocnt = 0;
    for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i, 1);

    for (int i = 1; i <= n; i++) vis[i] = 0;
    cc = 0;
    for (int i = ocnt - 1; i >= 0; i--) {
        int u = order_[i];
        if (!vis[u]) { comp[u] = cc; dfs(u, 0); cc++; }
    }

    int *indeg = calloc(cc, sizeof(int)), *outdeg = calloc(cc, sizeof(int));
    int *rep = malloc(sizeof(int) * cc);
    char *seen = calloc(cc, 1);
    for (int i = 1; i <= n; i++) if (!seen[comp[i]]) { rep[comp[i]] = i; seen[comp[i]] = 1; }
    for (int i = 0; i < m; i++) {
        int cu = comp[eu[i]], cv = comp[ev[i]];
        if (cu != cv) { outdeg[cu] = 1; indeg[cv] = 1; }
    }

    if (cc == 1) { printf("0\n"); return 0; }

    int *src = malloc(sizeof(int) * cc), sc = 0;
    int *snk = malloc(sizeof(int) * cc), kc = 0;
    for (int i = 0; i < cc; i++) {
        if (!indeg[i]) src[sc++] = rep[i];
        if (!outdeg[i]) snk[kc++] = rep[i];
    }
    int k = (sc > kc) ? sc : kc;
    printf("%d\n", k);
    for (int i = 0; i < k; i++)
        printf("%d %d\n", snk[i % kc], src[(i + 1) % sc]);

    return 0;
}
