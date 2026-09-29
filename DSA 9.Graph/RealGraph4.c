#include <stdio.h>

int p[100005], roots[100005];

int find(int u) {
    return p[u] == u ? u : (p[u] = find(p[u]));
}

int main() {
    int n, m, cnt = 0;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) p[i] = i;

    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        p[find(u)] = find(v);
    }

    for (int i = 1; i <= n; i++) {
        if (p[i] == i) roots[cnt++] = i;
    }

    printf("\n%d\n", cnt - 1);
    for (int i = 0; i < cnt - 1; i++) {
        printf("%d %d\n", roots[i], roots[i + 1]);
    }

    return 0;
}
