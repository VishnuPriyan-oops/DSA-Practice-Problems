#include <stdio.h>

void swap(int *xp, int *yp) {
    int t = *xp;
    *xp = *yp;
    *yp = t;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[m]) m = j;
        if (m != i) swap(&arr[i], &arr[m]);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d%c", arr[i], i == size - 1 ? '\n' : ' ');
}

int main() {
    int n;
    scanf("%d", &n);
    static int arr[100005];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("\n");

    selectionSort(arr, n);
    printArray(arr, n);
    return 0;
}
