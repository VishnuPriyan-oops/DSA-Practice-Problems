#include <stdio.h>
#include <stdlib.h>

typedef long long ll;
typedef struct { ll xl, xr; } Seg;

int cmp(const void *a, const void *b) {
    return ((Seg *)a)->xl - ((Seg *)b)->xl > 0 ? 1 : -1;
}

int solve(Seg *seg, ll n, ll L) {
    for (ll i = 0; i < n; i++) {
        ll target = seg[i].xl + L, cur_right = seg[i].xl, maxright;
        while (1) {
            maxright = cur_right;
            for (ll j = 0; j < n; j++)
                if (seg[j].xl <= cur_right && seg[j].xr <= target && seg[j].xr > maxright)
                    maxright = seg[j].xr;
            if (maxright == target) return 1;
            if (cur_right == maxright) break;
            cur_right = maxright;
        }
    }
    return 0;
}

int main() {
    int t;
    scanf("%d", &t);

    ll *L = malloc(t * sizeof(ll)), *n = malloc(t * sizeof(ll));
    Seg **segs = malloc(t * sizeof(Seg *));

    for (int i = 0; i < t; i++) {
        scanf("%lld %lld", &n[i], &L[i]);
        segs[i] = malloc(n[i] * sizeof(Seg));
        for (ll j = 0; j < n[i]; j++)
            scanf("%lld %lld", &segs[i][j].xl, &segs[i][j].xr);
        qsort(segs[i], n[i], sizeof(Seg), cmp);
    }

    printf("\n");

    int idx = 0;
    while (t--) {
        printf(solve(segs[idx], n[idx], L[idx]) ? "Yes\n" : "No\n");
        free(segs[idx]);
        idx++;
    }

    free(segs); free(n); free(L);
    return 0;
}
