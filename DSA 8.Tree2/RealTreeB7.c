#include <stdio.h>
#include <stdlib.h>

long long cv[400005];
int st[400005], cn;
long long mx, sz;

int cmp(const void *a, const void *b) {
    long long x = *(long long *)a, y = *(long long *)b;
    return (x > y) - (x < y);
}

int idx(long long x) {
    int lo = 0, hi = cn - 1;
    while (lo <= hi) {
        int m = (lo + hi) / 2;
        if (cv[m] == x) return m;
        if (cv[m] < x) lo = m + 1; else hi = m - 1;
    }
    return -1;
}

int main() {
    int n, q, i;
    scanf("%d", &n);
    long long *a = malloc(sizeof(long long) * n);
    for (i = 0; i < n; i++) scanf("%lld", &a[i]);

    scanf("%d", &q);
    long long *v = malloc(sizeof(long long) * q);
    for (i = 0; i < q; i++) scanf("%lld", &v[i]);

    printf("\n");

    long long *t = malloc(sizeof(long long) * (n + q));
    int tc = 0;
    for (i = 0; i < n; i++) t[tc++] = a[i];
    for (i = 0; i < q; i++) t[tc++] = v[i];
    qsort(t, tc, sizeof(long long), cmp);
    cn = 0;
    for (i = 0; i < tc; i++) if (i == 0 || t[i] != t[i - 1]) cv[cn++] = t[i];
    for (i = 0; i < cn; i++) st[i] = 0;

    mx = a[0];
    for (i = 1; i < n; i++) if (a[i] > mx) mx = a[i];
    for (i = 0; i < n; i++) if (a[i] != mx) st[idx(a[i])]++;
    sz = n;

    for (i = 0; i < q; i++) {
        long long val = v[i];
        if (val == mx) { /* reject */ }
        else if (val > mx) {
            int id = idx(val);
            if (st[id] == 0) { st[idx(mx)]++; mx = val; sz++; }
        } else {
            int id = idx(val);
            if (st[id] < 2) { st[id]++; sz++; }
        }
        printf("%lld\n", sz);
    }

    int f = 1;
    for (i = 0; i < cn; i++) {
        if (cv[i] == mx || st[i] == 0) continue;
        printf(f ? "%lld" : " %lld", cv[i]);
        f = 0;
    }
    printf(f ? "%lld" : " %lld", mx);
    for (i = cn - 1; i >= 0; i--)
        if (cv[i] != mx && st[i] == 2) printf(" %lld", cv[i]);
    printf("\n");

    free(a); free(v); free(t);
    return 0;
}
