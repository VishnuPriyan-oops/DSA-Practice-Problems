#include <stdio.h>

void bubble_sort(int arr[], int no) {
    for (int i = 0; i < no - 1; i++)
        for (int j = 0; j < no - 1 - i; j++)
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
}

int MEGA_SALE(int arr[], int no, int k) {
    bubble_sort(arr, no);
    int lim = (k < no) ? k : no;
    long long sum = 0;
    for (int i = 0; i < lim; i++) {
        if (arr[i] < 0) sum += -arr[i];
        else break;
    }
    return (int)sum;
}

int main() {
    int t;
    scanf("%d", &t);

    int qt = t;
    int nArr[10], mArr[10];
    static int data[10][100];

    for (int i = 0; i < t; i++) {
        int n, m;
        scanf("%d %d", &n, &m);
        nArr[i] = n;
        mArr[i] = m;
        for (int j = 0; j < n; j++) scanf("%d", &data[i][j]);
    }

    printf("\n");

    for (int i = 0; i < qt; i++) {
        printf("%d\n", MEGA_SALE(data[i], nArr[i], mArr[i]));
    }

    return 0;
}
