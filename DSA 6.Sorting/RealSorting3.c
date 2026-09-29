#include <stdio.h>

void insertionSort(long int *p, long int n) {
    for (long int i = 1; i < n; i++) {
        long int key = p[i], j = i - 1;
        while (j >= 0 && p[j] > key) {
            p[j + 1] = p[j];
            j--;
        }
        p[j + 1] = key;
    }
}

int main() {
    int q;
    scanf("%d", &q);

    int qt = q;
    int nArr[10];
    static long long mat[100][100];
    int idx = 0;

    /* store all queries first */
    typedef struct { int n; long long m[100][100]; } Query;
    static Query qs[10];

    for (int i = 0; i < q; i++) {
        int n;
        scanf("%d", &n);
        qs[i].n = n;
        for (int r = 0; r < n; r++)
            for (int c = 0; c < n; c++)
                scanf("%lld", &qs[i].m[r][c]);
    }

    printf("\n");

    while (q--) {
        int n = qs[idx].n;
        long int rowSum[100], colSum[100];
        for (int i = 0; i < n; i++) {
            long int rs = 0, cs = 0;
            for (int j = 0; j < n; j++) {
                rs += qs[idx].m[i][j];
                cs += qs[idx].m[j][i];
            }
            rowSum[i] = rs;
            colSum[i] = cs;
        }
        insertionSort(rowSum, n);
        insertionSort(colSum, n);
        int ok = 1;
        for (int i = 0; i < n; i++)
            if (rowSum[i] != colSum[i]) { ok = 0; break; }
        printf(ok ? "Possible\n" : "Impossible\n");
        idx++;
    }
    return 0;
}
