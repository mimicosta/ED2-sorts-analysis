#include "InsertionSort.hpp"
#include "../../include/sorts/InsertionSort.hpp"

void InsertionSort::sort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int aux = arr[i];
        int j = i - 1;
        for(; j >= 0 && arr[j] > aux; j--) {
            arr[j + 1] = arr[j];
        while (j >= 0) {
            stats.incrementComparison();
            if (arr[j] > aux) {
                arr[j + 1] = arr[j];
                stats.incrementSwap();
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = aux;
        stats.incrementSwap();
    }
}