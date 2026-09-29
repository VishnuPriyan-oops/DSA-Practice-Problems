#include <stdio.h>
#include <stdlib.h>

#define MAXH 200010

typedef struct { long long val; int id; } Item;
Item H[2][MAXH]; int sz[2];
char deleted[MAXH];

void push(int t, Item x, int isMax) {
    int i = ++sz[t];
    H[t][i] = x;
    while (i > 1) {
        int p = i / 2;
        int cond = isMax ? (H[t][p].val < H[t][i].val) : (H[t][p].val > H[t][i].val);
        if (!cond) break;
        Item tmp = H[t][i]; H[t][i] = H[t][p]; H[t][p] = tmp; i = p;
    }
}
void pop(int t, int isMax) {
    H[t][1] = H[t][sz[t]--];
    int i = 1;
    while (1) {
        int l = 2 * i, r = 2 * i + 1, b = i;
        if (l <= sz[t] && (isMax ? H[t][l].val > H[t][b].val : H[t][l].val < H[t][b].val)) b = l;
        if (r <= sz[t] && (isMax ? H[t][r].val > H[t][b].val : H[t][r].val < H[t][b].val)) b = r;
        if (b == i) break;
        Item tmp = H[t][i]; H[t][i] = H[t][b]; H[t][b] = tmp; i = b;
    }
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    long long *arr = malloc(sizeof(long long) * n);
    long long sum = 0;
    for (int i = 0; i < n; i++) { scanf("%lld", &arr[i]); sum += arr[i]; }

    int *K = malloc(sizeof(int) * q);
    for (int i = 0; i < q; i++) scanf("%d", &K[i]);

    printf("\n");

    long long *S = malloc(sizeof(long long) * n);
    S[0] = sum;

    sz[0] = 0; sz[1] = 0;
    int idc = 0;
    for (int i = 0; i < n; i++) {
        idc++;
        deleted[idc] = 0;
        push(0, (Item){arr[i], idc}, 1);
        push(1, (Item){arr[i], idc}, 0);
    }

    for (int op = 1; op < n; op++) {
        while (deleted[H[0][1].id]) pop(0, 1);
        while (deleted[H[1][1].id]) pop(1, 0);
        long long vmax = H[0][1].val, vmin = H[1][1].val;
        deleted[H[0][1].id] = 1; deleted[H[1][1].id] = 1;
        idc++;
        deleted[idc] = 0;
        push(0, (Item){vmax - vmin, idc}, 1);
        push(1, (Item){vmax - vmin, idc}, 0);
        sum -= 2 * vmin;
        S[op] = sum;
    }

    for (int i = 0; i < q; i++)
        printf("%lld\n", S[K[i]]);

    free(arr); free(K); free(S);
    return 0;
}
