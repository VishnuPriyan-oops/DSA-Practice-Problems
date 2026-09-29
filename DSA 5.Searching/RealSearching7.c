#include <stdio.h>

#define MAXN 100005

int main() {
    int n;
    scanf("%d", &n);

    double warr[MAXN], harr[MAXN];
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &warr[i], &harr[i]);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        double width = warr[i], height = harr[i];
        if (width / height >= 1.6 && width / height <= 1.7) {
            count++;
        } else if (height / width >= 1.6 && height / width <= 1.7) {
            count++;
        }
    }

    printf("\n");
    printf("%d\n", count);

    return 0;
}
