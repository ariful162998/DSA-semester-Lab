#include <stdio.h>

// Swap function
void swap(int arr[], int i, int j) {
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Partition
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(arr, i, j);
        }
    }
    swap(arr, low, j);
    return j;
}

// Quicksort
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quicksort(arr, low, pivot_index - 1);
        quicksort(arr, pivot_index + 1, high);
    }
}

// Main function
int main() {
    int i, n, arr[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    quicksort(arr, 0, n - 1);

    // Largest gap
    int large_gap = 0;
    for (i = 0; i < n - 1; i++) { // Corrected loop to prevent out-of-bound error
        if ((arr[i + 1] - arr[i]) > large_gap) {
            large_gap = arr[i + 1] - arr[i];
        }
    }
    printf("%d", large_gap);
    return 0;
}
