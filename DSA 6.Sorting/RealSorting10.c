#include <stdio.h>
#include <stdlib.h>

typedef struct { int x, y, h, d; } Pt;

int cmp(const void *a, const void *b) {
    return ((Pt *)a)->d - ((Pt *)b)->d;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t-->0) {
        int n;
        scanf("%d", &n);
        Pt *pt = malloc(n * sizeof(Pt));
        for (int i = 0;i < n;i++) {
            scanf("%d %d %d", &pt[i].x, &pt[i].y, &pt[i].h);
            pt[i].d = pt[i].y - pt[i].x;
        }
        qsort(pt, n, sizeof(Pt), cmp);


        long long *P = malloc((n + 1) * sizeof(long long));
        P[0] = 0;
        int k = 0;
        int idx = 0;
        while (idx < n) {
            long long s = 0;
            int dcur = pt[idx].d;
            while (idx < n && pt[idx].d == dcur) { s += pt[idx].h; idx++; }
            k++;
            P[k] = P[k - 1] + s;
        }
        long long S = P[k];

        int found = 0;

        /* binary search: gap split, 2*P[i] == S, i in [0,k] */
        int l = 0, r = k;
        while (l<= r) {
            int mid = (l+r)/2;
            long long v = 2 * P[mid];
            if (v == S) { found = 1; break; }
            else if (v < S) l = mid + 1;
            else r = mid - 1;
        }


        if (!found) {
            l = 1; r = k;
            while (l<= r) {
                int mid = (l+r)/2;
                long long v = P[mid - 1] + P[mid];
                if (v == S) { found = 1; break; }
                else if (v < S) l = mid + 1;
                else r = mid - 1;
            }
        }

        printf(found ? "YES\n" : "NO\n");
        free(pt);
        free(P);
    }
    return 0;
}
