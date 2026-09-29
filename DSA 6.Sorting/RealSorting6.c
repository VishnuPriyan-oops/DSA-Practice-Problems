#include <stdio.h>

void printArray(int arr[], int n) {
    for (int k = 0; k < n; k++)
        printf("%d%c", arr[k], k == n - 1 ? '\n' : ' ');
}

void insertionSort(int arr[], int n) {
    int snapDone = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            int key = arr[i], j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
        if (i == 2) { printArray(arr, n); snapDone = 1; }
    }
    if (!snapDone) printArray(arr, n);
    printArray(arr, n);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[100005];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("\n");

    insertionSort(arr, n);
    return 0;
}
