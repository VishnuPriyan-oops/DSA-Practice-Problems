#include <stdio.h>

int a[100005];

int main() {
    int n, i;
    int biggest, big, small, temp;
    long long product;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    biggest = -1;
    big = -1;
    small = -1;

    for (i = 0; i < n; i++) {
        if(a[i]>biggest) {
            small = big;
            big = biggest;
            biggest = a[i];
        } else if (a[i] > big) {
            small = big;
            big = a[i];
        } else if (a[i] > small) {
            small = a[i];
        }

        if(biggest<big) {
            temp = biggest;
            biggest = big;
            big = temp;
        }

        if (big == -1 || small == -1) {
            printf("-1\n");
        } else {
            product = (long long)biggest * big * small;
            printf("%lld\n", product);
        }
    }

    return 0;
}
