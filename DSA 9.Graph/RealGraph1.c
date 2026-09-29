#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

int n, m, k;
int *eu, *ev; ull *em;
long long *c;
int *par;

int find(int x) { while (par[x] != x) { par[x] = par[par[x]]; x = par[x]; } return x; }
void uni(int a, int b) { a = find(a); b = find(b); if (a != b) par[a] = b; }

int chk(ull allowed) {
    for (int i = 1; i <= n; ++i) par[i] = i;
    for (int i = 0; i < m; ++i)
        if ((em[i] & ~allowed) == 0ULL) uni(eu[i], ev[i]);
    int r = find(1);
    for (int i = 2; i <= n; ++i) if (find(i) != r) return 0;
    return 1;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    c = malloc(sizeof(long long) * (k + 1));
    for (int i = 1; i <= k; ++i) scanf("%lld", &c[i]);

    eu = malloc(sizeof(int) * m); ev = malloc(sizeof(int) * m); em = malloc(sizeof(ull) * m);
    for (int i = 0; i < m; ++i) {
        int u, v, l;
        scanf("%d %d %d", &u, &v, &l);
        ull mask = 0;
        for (int j = 0; j < l; ++j) { int t; scanf("%d", &t); mask |= (1ULL << (t - 1)); }
        eu[i] = u; ev[i] = v; em[i] = mask;
    }
    par = malloc(sizeof(int) * (n + 1));

    printf("\n");

    ull T = 0; long long cost = 0;
    for (int i = k; i >= 1; --i) {
        ull allowed = T | ((i - 1 >= 1) ? ((1ULL << (i - 1)) - 1) : 0ULL);
        if (chk(allowed)) { /* token i not needed */ }
        else { T |= (1ULL << (i - 1)); cost += c[i]; }
    }

    if (chk(T)) printf("%lld\n", cost); else printf("-1\n");

    free(c); free(eu); free(ev); free(em); free(par);
    return 0;
}
