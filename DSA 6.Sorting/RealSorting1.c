#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    int *n = malloc(t * sizeof(int));
    int **g = malloc(t * sizeof(int *));
    int **b = malloc(t * sizeof(int *));

    for(int i = 0;i<t;i++) {
        scanf("%d", &n[i]);
        g[i] = malloc(n[i] * sizeof(int));
        b[i] = malloc(n[i] * sizeof(int));
        for(int j = 0;j<n[i];j++) scanf("%d", &g[i][j]);
        for(int j = 0;j<n[i];j++) scanf("%d", &b[i][j]);
    }

    printf("\n");

    for(int i = 0;i<t;i++) {
        qsort(g[i], n[i], sizeof(int), cmp);
        qsort(b[i], n[i], sizeof(int), cmp);
        int c = 0;
        for(int j = 0;j<n[i];j++) {
            int x = g[i][j], y = b[i][n[i] - 1 - j];
            if (x % y == 0 || y % x == 0) c++;
        }
        printf("%d\n", c);
        free(g[i]); free(b[i]);
    }

    free(g); free(b); free(n);
    return 0;
}
