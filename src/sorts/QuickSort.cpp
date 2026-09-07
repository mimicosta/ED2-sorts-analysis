#include "sorts/QuickSort.hpp"

void QuickSort::quickSort(int* arr, int low, int high) {
    int i = low;
    int j = high;
    int pivot = arr[low + (high - low) / 2];

    while (i <= j) {
        while (arr[i] < pivot) {
            stats.incrementComparison();
            i++;
        }
        stats.incrementComparison();

        while (arr[j] > pivot) {
            stats.incrementComparison();
            j--;
        }
        stats.incrementComparison();

        if (i <= j) {
            if (i != j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                stats.incrementSwap();
            }
            i++;
            j--;
        }
    }

    if (low < j) {
        quickSort(arr, low, j);
    }
    if (i < high) {
        quickSort(arr, i, high);
    }
}

void QuickSort::sort(int* arr, int size) {
    if (arr != nullptr && size > 1) {
        quickSort(arr, 0, size - 1);
    }
}

