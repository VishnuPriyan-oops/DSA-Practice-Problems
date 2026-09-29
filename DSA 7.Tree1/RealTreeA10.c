#include <stdio.h>
#include <stdlib.h>

int cnt[800005];
int n;
long long xv[200005];

void build(int k, int l, int r) {
    if (l == r) { cnt[k] = 1; return; }
    int mid = (l + r) / 2;
    build(2 * k, l, mid);
    build(2 * k + 1, mid + 1, r);
    cnt[k] = cnt[2 * k] + cnt[2 * k + 1];
}

int findKth(int k, int l, int r, int p) {
    if (l == r) { cnt[k] = 0; return l; }
    int mid = (l + r) / 2;
    int res;
    if (cnt[2 * k] >= p) res = findKth(2 * k, l, mid, p);
    else res = findKth(2 * k + 1, mid + 1, r, p - cnt[2 * k]);
    cnt[k] = cnt[2 * k] + cnt[2 * k + 1];
    return res;
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) scanf("%lld", &xv[i]);

    int *pos = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d", &pos[i]);

    printf("\n");

    build(1, 1, n);

    for (int i = 0; i < n; i++) {
        int idx = findKth(1, 1, n, pos[i]);
        printf("%lld%c", xv[idx], i == n - 1 ? '\n' : ' ');
    }

    free(pos);
    return 0;
}
