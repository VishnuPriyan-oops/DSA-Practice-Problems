#include <stdio.h>

int search(int a, int b) {
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int hexDigitSum(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 16;
        x /= 16;
    }
    return sum;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int L, R;
        scanf("%d %d", &L, &R);

        int count = 0;
        for (int x = L; x <= R; x++) {
            int f = hexDigitSum(x);
            if (search(x, f) > 1) count++;
        }

        printf("\n");
        printf("%d\n", count);
    }

    return 0;
}
