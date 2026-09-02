#include "InsertionSort.hpp"

void InsertionSort::sort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int aux = arr[i];
        int j = i - 1;
        for(; j >= 0 && arr[j] > aux; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = aux;
    }
}