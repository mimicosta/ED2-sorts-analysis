#include "sorts/SelectionSort.hpp"

void SelectionSort::sort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++) {
            stats.incrementComparison();
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        int aux = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = aux;
        if (minIdx != i) {
            int aux = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = aux;
            stats.incrementSwap();
        }
    }
}

