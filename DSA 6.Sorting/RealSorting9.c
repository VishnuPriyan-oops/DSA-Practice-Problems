#include <stdio.h>
#include <string.h>

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int t;
    scanf("%d", &t);

    int qt = t;
    int Narr[100], Karr[100], Parr[100];
    static int leaf[100][50][30];

    for (int q = 0; q < t; q++) {
        int n, k, p;
        scanf("%d %d %d", &n, &k, &p);
        Narr[q] = n; Karr[q] = k; Parr[q] = p;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < k; j++)
                scanf("%d", &leaf[q][i][j]);
    }

    printf("\n");

    for (int q = 0; q < qt; q++) {
        int n = Narr[q], k = Karr[q], p = Parr[q];
        static int pref[50][31];
        for (int i = 0; i < n; i++) {
            pref[i][0] = 0;
            for (int j = 0; j < k; j++)
                pref[i][j + 1] = pref[i][j] + leaf[q][i][j];
        }

        static int dp[1501];
        for (int j = 0; j <= p; j++) dp[j] = -1;
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            static int ndp[1501];
            for (int j = 0; j <= p; j++) ndp[j] = -1;
            for (int j = 0; j <= p; j++) {
                if (dp[j] < 0) continue;
                for (int c = 0; c <= k && j + c <= p; c++) {
                    int val = dp[j] + pref[i][c];
                    if (val > ndp[j + c]) ndp[j + c] = val;
                }
            }
            memcpy(dp, ndp, sizeof(int) * (p + 1));
        }

        printf("%d\n", dp[p]);
    }

    return 0;
}
