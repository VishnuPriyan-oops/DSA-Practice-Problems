#include <stdio.h>
#include <stdlib.h>

int heapArr[200005], heapSz;

void hpush(int x) {
    int i = ++heapSz;
    heapArr[i] = x;
    while (i > 1 && heapArr[i / 2] > heapArr[i]) {
        int t = heapArr[i]; heapArr[i] = heapArr[i / 2]; heapArr[i / 2] = t;
        i /= 2;
    }
}

int hpop_impl(void) {
    int top = heapArr[1];
    heapArr[1] = heapArr[heapSz--];
    int i = 1;
    while (1) {
        int l = 2 * i, r = 2 * i + 1, b = i;
        if (l <= heapSz && heapArr[l] < heapArr[b]) b = l;
        if (r <= heapSz && heapArr[r] < heapArr[b]) b = r;
        if (b == i) break;
        int t = heapArr[i]; heapArr[i] = heapArr[b]; heapArr[b] = t;
        i = b;
    }
    return top;
}

struct Queue { int (*pop)(void); };
struct Queue q;

int main() {
    int n;
    scanf("%d", &n);

    int *code = malloc(sizeof(int) * (n > 2 ? n - 2 : 1));
    for (int i = 0; i < n - 2; i++) scanf("%d", &code[i]);

    printf("\n");

    int *deg = calloc(n + 1, sizeof(int));
    for (int i = 1; i <= n; i++) deg[i] = 1;
    for (int i = 0; i < n - 2; i++) deg[code[i]]++;

    heapSz = 0;
    q.pop = hpop_impl;
    for (int i = 1; i <= n; i++) if (deg[i] == 1) hpush(i);

    for (int i = 0; i < n - 2; i++) {
        int leaf = q.pop();
        int other = code[i];
        printf("%d %d\n", leaf, other);
        deg[leaf]--;
        deg[other]--;
        if (deg[other] == 1) hpush(other);
    }

    int a = q.pop();
    int b = q.pop();
    printf("%d %d\n", a, b);

    free(code); free(deg);
    return 0;
}
