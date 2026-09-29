#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int n, int i) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        int t = arr[i]; arr[i] = arr[largest]; arr[largest] = t;
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
}

int main() {
    long long M, N;
    scanf("%lld %lld", &M, &N);

    int *arr = malloc(sizeof(int) * M);
    for (int i = 0; i < M; i++) scanf("%d", &arr[i]);

    printf("\n");

    buildHeap(arr, M);

    long long total = 0;
    for (long long k = 0; k < N; k++) {
        total += arr[0];
        arr[0]--;
        heapify(arr, M, 0);
    }

    printf("%lld\n", total);

    free(arr);
    return 0;
}
