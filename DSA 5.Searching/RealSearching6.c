#include <stdio.h>

void thirdLargest(int arr[], int arr_size) {
    int sorted[100];
    for (int i = 0; i < arr_size; i++) sorted[i] = arr[i];

    for (int i = 0; i < arr_size - 1; i++) {
        for (int j = 0; j < arr_size - 1 - i; j++) {
            if (sorted[j] < sorted[j + 1]) {
                int t = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = t;
            }
        }
    }

    printf("The third Largest element is %d\n", sorted[2]);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("\n");
    thirdLargest(arr, n);

    return 0;
}
