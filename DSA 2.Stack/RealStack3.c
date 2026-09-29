#include <stdio.h>

int digitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int n, q, i, x, y, query;
    int arr[100005], arr2[100005], result[100005];

    scanf("%d %d", &n, &q);

    for (i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        arr2[i] = digitSum(arr[i]);
    }

    for (i = 0; i < q; i++) {
        scanf("%d", &query);
        x = query;
        result[i] = -1;
        for (y = x + 1; y <= n; y++) {
            if (arr[x] < arr[y] && arr2[x] > arr2[y]) {
                result[i] = y;
                break;
            }
        }
    }

    for (i = 0; i < q; i++) {
        printf(i == 0 ? "%d" : " %d", result[i]);
    }
    printf("\n");

    return 0;
}
