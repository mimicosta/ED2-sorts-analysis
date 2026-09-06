#include "../../include/sorts/ShellSort.hpp"

void ShellSort::sort(int* arr, int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int aux = arr[i];
            int j = i;
            while (j >= gap) {
                stats.incrementComparison();
                if (arr[j - gap] > aux) {
                    arr[j] = arr[j - gap];
                    stats.incrementSwap();
                    j -= gap;
                } else {
                    break;
                }
            }
            arr[j] = aux;
            stats.incrementSwap();
        }
    }
}