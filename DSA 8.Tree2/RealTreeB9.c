#include <stdio.h>
#include <stdlib.h>
#define MAXN 100005

int head[MAXN], nxt[2*MAXN], to[2*MAXN], ec;
int tin[MAXN], tout[MAXN], tm;
char s[MAXN];
int sN[MAXN], sE[MAXN], vis[MAXN];
int ct[26][MAXN], cc[26];

void add(int u, int v) {
    to[ec] = v; nxt[ec] = head[u]; head[u] = ec++;
    to[ec] = u; nxt[ec] = head[v]; head[v] = ec++;
}

void dfs(int r) {
    int top = 0;
    sN[0] = r; sE[0] = head[r]; vis[r] = 1; tin[r] = tm++;
    while (top >= 0) {
        int u = sN[top], e = sE[top];
        if (e == -1) { tout[u] = tm - 1; top--; continue; }
        sE[top] = nxt[e];
        int v = to[e];
        if (!vis[v]) { vis[v] = 1; tin[v] = tm++; sN[++top] = v; sE[top] = head[v]; }
    }
}

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int cnt(int c, int lo, int hi) {
    int n = cc[c], l = 0, h = n, left;
    while (l < h) { int m = (l + h) / 2; if (ct[c][m] < lo) l = m + 1; else h = m; }
    left = l; l = 0; h = n;
    while (l < h) { int m = (l + h) / 2; if (ct[c][m] <= hi) l = m + 1; else h = m; }
    return l - left;
}

int main() {
    int n, Q;
    scanf("%d %d", &n, &Q);
    scanf("%s", s + 1);

    for (int i = 1; i <= n; i++) head[i] = -1;
    ec = 0;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add(u, v);
    }

    tm = 1;
    dfs(1);

    for (int i = 1; i <= n; i++) { int c = s[i] - 'a'; ct[c][cc[c]++] = tin[i]; }
    for (int c = 0; c < 26; c++) qsort(ct[c], cc[c], sizeof(int), cmp);

    int *qu = malloc(sizeof(int) * Q);
    char *qc = malloc(Q);
    for (int i = 0; i < Q; i++) scanf("%d %c", &qu[i], &qc[i]);

    printf("\n");

    int i = 0;
    while (Q--) {
        int u = qu[i]; char c = qc[i]; i++;
        printf("%d\n", cnt(c - 'a', tin[u], tout[u]));
    }

    free(qu); free(qc);
    return 0;
}
