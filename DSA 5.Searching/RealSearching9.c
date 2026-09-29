#include <stdio.h>

#define MAXT 105
#define MAXN 1005

int main() {
    int T;
    scanf("%d", &T);

    int ns[MAXT];
    long long Ds[MAXT];
    long long xs[MAXT][MAXN];

    int t;
    for (t = 0; t < T; t++) {
        int n;
        long long D;
        scanf("%d %lld", &n, &D);
        ns[t] = n;
        Ds[t] = D;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &xs[t][i]);
        }
    }

    long long answers[MAXT];
    for (t = 0; t < T; t++) {
        int n = ns[t];
        long long bound = Ds[t];
        for (int i = n - 1; i >= 0; i--) {
            bound = (bound / xs[t][i]) * xs[t][i];
        }
        answers[t] = bound;
    }

    for (t = 0; t < T; t++) {
        printf("\n");
        printf("%lld\n", answers[t]);
    }

    return 0;
}
