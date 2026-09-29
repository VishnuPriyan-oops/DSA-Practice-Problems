#include <stdio.h>

int p[100005], sz[100005], comps, max_sz;
int ans_comps[200005], ans_max[200005];

int find(int i) {
    return p[i] == i ? i : (p[i] = find(p[i]));
}

int join(int i,int j) {
    int root_i = find(i);
    int root_j = find(j);
    if (root_i != root_j) {
        p[root_i] = root_j;
        sz[root_j] += sz[root_i];
        if (sz[root_j] > max_sz) max_sz = sz[root_j];
        comps--;
        return 1;
    }
    return 0;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    comps = n;
    max_sz = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        sz[i] = 1;
    }


    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        join(u, v);
        ans_comps[i] = comps;
        ans_max[i] = max_sz;
    }


    printf("\n");


    for (int i = 0; i < m; i++) {
        printf("%d %d\n", ans_comps[i], ans_max[i]);
    }

    return 0;
}
