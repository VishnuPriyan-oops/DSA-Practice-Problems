#include <stdio.h>
#include <stdlib.h>

long long cv[100005];
int fr[100005], cn;

int idx(long long x) {
    int lo = 0, hi = cn - 1;
    while (lo <= hi) {
        int m = (lo + hi) / 2;
        if (cv[m] == x) return m;
        if (cv[m] < x) lo = m + 1; else hi = m - 1;
    }
    return -1;
}

int cmp(const void *a, const void *b) {
    long long x = *(long long *)a, y = *(long long *)b;
    return (x > y) - (x < y);
}

int main() {
    int n; long long m;
    scanf("%d %lld", &n, &m);

    long long *g = malloc(sizeof(long long) * n);
    for (int i = 0; i < n; i++) scanf("%lld", &g[i]);

    printf("\n");

    long long *t = malloc(sizeof(long long) * n);
    for (int i = 0; i < n; i++) t[i] = g[i];
    qsort(t, n, sizeof(long long), cmp);
    cn = 0;
    for (int i = 0; i < n; i++) if (i == 0 || t[i] != t[i - 1]) cv[cn++] = t[i];
    for (int i = 0; i < cn; i++) fr[i] = 0;

    long long leadAge = 0;
    int leadCnt = 0;

    if (n >= 1) {
        int id = idx(g[0]);
        fr[id]++;
        leadAge = g[0]; leadCnt = fr[id];
        printf("%lld %d\n", leadAge, leadCnt);
    }

    for (int i = 0; i < n - 1; i++) {
        int id = idx(g[i + 1]);
        fr[id]++;
        long long age = g[i + 1];
        int c = fr[id];
        if (c > leadCnt || (c == leadCnt && age > leadAge)) {
            leadCnt = c; leadAge = age;
        }
        printf("%lld %d\n", leadAge, leadCnt);
    }

    free(g); free(t);
    return 0;
}
