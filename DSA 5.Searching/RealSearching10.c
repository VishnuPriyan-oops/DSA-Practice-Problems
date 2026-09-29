#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXV 1000000

long long S[MAXV + 1];

int isqrt_(long long x) {
    long long r = (long long)sqrtl((long double)x);
    while (r * r > x) r--;
    while ((r + 1) * (r + 1) <= x) r++;
    return (int)r;
}

void build(void) {
    S[0] = 0;
    for (int i = 1; i <= MAXV; i++) {
        long long fs = isqrt_(i);
        long long ch = (i + 1) / 2;
        long long cnt = (long long)i * fs + ch;
        S[i] = S[i - 1] + cnt;
    }
}

long long findValue(long long p) {
    int l = 1, ans1 = MAXV;
    while (l < ans1) {
        int mid = l + (ans1 - l) / 2;
        if (S[mid] >= p) ans1 = mid; else l = mid + 1;
    }
    return l;
}

int main() {
    build();

    int Q;
    scanf("%d", &Q);

    long long *L = malloc(sizeof(long long) * Q), *R = malloc(sizeof(long long) * Q);
    for (int i = 0; i < Q; i++) scanf("%lld %lld", &L[i], &R[i]);

    printf("\n");

    for (int i = 0; i < Q; i++) {
        long long vl = findValue(L[i]);
        long long vr = findValue(R[i]);
        printf("%lld\n", vr - vl + 1);
    }
    free(L); free(R);
    return 0;
}
