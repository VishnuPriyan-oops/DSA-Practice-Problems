#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int tree[800005];
int n;

void build(int *aa, int k, int l, int r) {
    if (l == r) { tree[k] = aa[l]; return; }
    int mid = (l + r) / 2;
    build(aa, 2 * k, l, mid);
    build(aa, 2 * k + 1, mid + 1, r);
    tree[k] = (tree[2 * k] < tree[2 * k + 1]) ? tree[2 * k] : tree[2 * k + 1];
}

int query(int k, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return INT_MAX;
    if (ql <= l && r <= qr) return tree[k];
    int mid = (l + r) / 2;
    int left = query(2 * k, l, mid, ql, qr);
    int right = query(2 * k + 1, mid + 1, r, ql, qr);
    return (left < right) ? left : right;
}

int main() {
    int q;
    scanf("%d %d", &n, &q);

    int *arr = malloc(sizeof(int) * (n + 1));
    for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);

    int *a = malloc(sizeof(int) * q), *b = malloc(sizeof(int) * q);
    for (int i = 0; i < q; i++) scanf("%d %d", &a[i], &b[i]);

    printf("\n");

    build(arr, 1, 1, n);

    for (int i = 0; i < q; i++)
        printf("%d\n", query(1, 1, n, a[i], b[i]));

    free(arr); free(a); free(b);
    return 0;
}
