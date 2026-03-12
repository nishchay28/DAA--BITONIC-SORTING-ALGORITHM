#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bitonicMerge(int arr[], int low, int count, int dir) {
    if (count > 1) {
        int k = count / 2;
        for (int i = low; i < low + k; i++) {
            if (dir == (arr[i] > arr[i + k])) {
                swap(&arr[i], &arr[i + k]);
            }
        }
        bitonicMerge(arr, low, k, dir);
        bitonicMerge(arr, low + k, k, dir);
    }
}

void bitonicSort(int arr[], int low, int count, int dir) {
    if (count > 1) {
        int k = count / 2;

        bitonicSort(arr, low, k, 1);
        bitonicSort(arr, low + k, k, 0);

        bitonicMerge(arr, low, count, dir);
    }
}

int main() {
    int arr[] = {3, 7, 4, 8, 6, 2, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    bitonicSort(arr, 0, n, 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}