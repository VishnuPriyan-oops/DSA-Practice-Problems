#include <stdio.h>

void sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
}

int main() {
    int t;
    scanf("%d", &t);

    int qt = t;
    int nArr[100], kArr[100];
    static int A[100][1000];

    for (int i = 0; i < t; i++) {
        int n, k;
        scanf("%d %d", &n, &k);
        nArr[i] = n;
        kArr[i] = k;
        for (int j = 0; j < n; j++) scanf("%d", &A[i][j]);
    }

    printf("\n");

    for (int i = 0; i < qt; i++) {
        int n = nArr[i], k = kArr[i];
        sort(A[i], n);
        int maxD = A[i][n - 1];
        int ans = maxD - k;
        printf("%d\n", ans > 0 ? ans : -1);
    }

    return 0;
}
