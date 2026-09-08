#include "sorts/HeapSort.hpp"

void HeapSort::heapify(int* arr, int n, int i) {
    //creates a max heap
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int aux;

    if((l < n)){   
        stats.incrementComparison();
        if (arr[l] > arr[largest]) {
            largest = l;
        }
    }

    if((r < n)){
        stats.incrementComparison();
        if(arr[r] > arr[largest]) {
            largest = r;
        }
    }

    if(largest != i){
        aux = arr[i];
        arr[i] = arr[largest];
        arr[largest] = aux;
        stats.incrementSwap();

        heapify(arr, n, largest); //goes to the subtree
    }
}

void HeapSort::heapSort(int* arr, int n) {
    int aux;
    for (int i = n/2-1; i >= 0; i--){
        heapify(arr, n, i);
    }

    for(int i = n-1; i > 0; i--){
        aux = arr[0];
        arr[0] = arr[i];
        arr[i] = aux;
        stats.incrementSwap();

        heapify(arr, i, 0);
    }
}

void HeapSort::sort(int* arr, int size) {
    if (arr != nullptr && size > 1) {
        heapSort(arr, size);
    }
}
