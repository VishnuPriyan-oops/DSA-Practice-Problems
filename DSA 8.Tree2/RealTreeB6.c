#include <stdio.h>
#include <stdlib.h>
#define MAXN 800005

long long treeSum[MAXN], lazyF[MAXN], lazyD[MAXN];
int n;

void build(int k, int l, int r) {
    if (l == r) { scanf("%lld", &treeSum[k]); return; }
    int mid = (l + r) / 2;
    build(2 * k, l, mid);
    build(2 * k + 1, mid + 1, r);
    treeSum[k] = treeSum[2 * k] + treeSum[2 * k + 1];
}

void apply(int k, int l, int r, long long F, long long D) {
    long long len = r - l + 1;
    treeSum[k] += len * F + D * (len * (len - 1) / 2);
    if (l != r) { lazyF[k] += F; lazyD[k] += D; }
}

void push(int k, int l, int r) {
    if (lazyF[k] == 0 && lazyD[k] == 0) return;
    int mid = (l + r) / 2;
    long long leftLen = mid - l + 1;
    apply(2 * k, l, mid, lazyF[k], lazyD[k]);
    apply(2 * k + 1, mid + 1, r, lazyF[k] + leftLen * lazyD[k], lazyD[k]);
    lazyF[k] = 0; lazyD[k] = 0;
}

void update(int k, int l, int r, int a, int b) {
    if (r < a || b < l) return;
    if (a <= l && r <= b) { apply(k, l, r, 1 + (l - a), 1); return; }
    push(k, l, r);
    int mid = (l + r) / 2;
    update(2 * k, l, mid, a, b);
    update(2 * k + 1, mid + 1, r, a, b);
    treeSum[k] = treeSum[2 * k] + treeSum[2 * k + 1];
}

long long query(int k, int l, int r, int a, int b) {
    if (r < a || b < l) return 0;
    if (a <= l && r <= b) return treeSum[k];
    push(k, l, r);
    int mid = (l + r) / 2;
    return query(2 * k, l, mid, a, b) + query(2 * k + 1, mid + 1, r, a, b);
}

int main() {
    int q;
    scanf("%d %d", &n, &q);

    build(1, 1, n);

    int *ta = malloc(sizeof(int) * q), *ty = malloc(sizeof(int) * q), *tb = malloc(sizeof(int) * q);
    for (int i = 0; i < q; i++) scanf("%d %d %d", &ty[i], &ta[i], &tb[i]);

    printf("\n");

    for (int i = 0; i < q; i++) {
        if (ty[i] == 1) update(1, 1, n, ta[i], tb[i]);
        else printf("%lld\n", query(1, 1, n, ta[i], tb[i]));
    }

    free(ta); free(ty); free(tb);
    return 0;
}
