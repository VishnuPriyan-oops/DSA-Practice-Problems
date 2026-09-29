#include <stdio.h>

void sort(int a[], int n, int flag) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++) {
            int swapNeeded = flag ? (a[j] < a[j + 1]) : (a[j] > a[j + 1]);
            if (swapNeeded) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
}

int main() {
    int t;
    scanf("%d", &t);

    int qt = t;
    int nArr[100];
    static int A[100][50], B[100][50];

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        nArr[i] = n;
        for (int j = 0; j < n; j++) scanf("%d", &A[i][j]);
        for (int j = 0; j < n; j++) scanf("%d", &B[i][j]);
    }

    printf("\n");

    for (int i = 0; i < qt; i++) {
        int n = nArr[i];
        sort(A[i], n, 0);   /* ascending */
        sort(B[i], n, 1);   /* descending */
        long long sum = 0;
        for (int j = 0; j < n; j++) sum += (long long)A[i][j] * B[i][j];
        printf("%lld\n", sum);
    }

    return 0;
}
