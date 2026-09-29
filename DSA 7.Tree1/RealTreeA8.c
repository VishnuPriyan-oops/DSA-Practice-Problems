#include <stdio.h>
#include <stdlib.h>

#define MAXV 800005
long long BIT[MAXV];
int SZ;

int compare(const void *a, const void *b) {
    long long x = *(long long *)a, y = *(long long *)b;
    return (x > y) - (x < y);
}

void update(int i, int n, int x) {
    for (; i <= n; i += i & (-i)) BIT[i] += x;
}

long long prefQ(int i) {
    long long s = 0;
    for (; i > 0; i -= i & (-i)) s += BIT[i];
    return s;
}

int lowerBound(long long *arr, int sz, long long val) {
    int lo = 0, hi = sz;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (arr[mid] < val) lo = mid + 1; else hi = mid;
    }
    return lo;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    long long *p = malloc(sizeof(long long) * (n + 1));
    for (int i = 1; i <= n; i++) scanf("%lld", &p[i]);

    char *type = malloc(q);
    long long *A = malloc(sizeof(long long) * q), *B = malloc(sizeof(long long) * q);
    for (int i = 0; i < q; i++) {
        char c;
        scanf(" %c %lld %lld", &c, &A[i], &B[i]);
        type[i] = c;
    }


    long long *vals = malloc(sizeof(long long) * (n + 2 * q + 1));
    int vc = 0;
    for (int i = 1; i <= n; i++) vals[vc++] = p[i];
    for (int i = 0; i < q; i++) {
        vals[vc++] = A[i];
        if (type[i] == '?') vals[vc++] = B[i];
    }
    qsort(vals, vc, sizeof(long long), compare);
    int uc = 0;
    for (int i = 0; i < vc; i++)
        if (i == 0 || vals[i] != vals[i - 1]) vals[uc++] = vals[i];
    SZ = uc;

    printf("\n");

    for (int i = 1; i <= n; i++) {
        int pos = lowerBound(vals, uc, p[i]) + 1;
        update(pos, SZ, 1);
    }

    for (int i = 0; i < q; i++) {
        if (type[i] == '!') {
            int k = (int)A[i];
            long long x = B[i];
            int oldPos = lowerBound(vals, uc, p[k]) + 1;
            update(oldPos, SZ, -1);
            p[k] = x;
            int newPos = lowerBound(vals, uc, x) + 1;
            update(newPos, SZ, 1);
        } else {
            long long a = A[i], b = B[i];
            int lo = lowerBound(vals, uc, a) + 1;
            int hiIdx = lowerBound(vals, uc, b + 1);
            long long res = prefQ(hiIdx) - prefQ(lo - 1);
            printf("%lld\n", res);
        }
    }

    free(p); free(type); free(A); free(B); free(vals);
    return 0;
}
