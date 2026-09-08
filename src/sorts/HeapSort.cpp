#include "sorts/HeapSort.hpp"

void HeapSort::heapify(int* arr, int n, int i) {
    //creates a max heap
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if((l < n) && arr[l] > arr[largest]){
        stats.incrementComparison();
        largest = l;
        stats.incrementSwap();
    } 
    if((r < n) && arr[r] > arr[largest]){
        stats.incrementComparison();
        largest = r;
        stats.incrementSwap();
    } 

    if(largest != i){
        stats.incrementComparison();
        int aux = arr[i];
        arr[i] = arr[largest];
        stats.incrementSwap();
        arr[largest] = aux;
        stats.incrementSwap(); //swaps the new largest and root

        heapify(arr, n, largest); //goes to the subtree
    }
}

void HeapSort::heapSort(int* arr, int n) {
    
}

void HeapSort::sort(int* arr, int size) {
    heapSort(arr, size);
}
