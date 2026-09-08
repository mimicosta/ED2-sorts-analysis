#pragma once
#include "Sort.hpp"

class HeapSort : public Sort {
private:
    void heapify(int* arr, int n, int i);
    void heapSort(int* arr, int n);

public:
    HeapSort() = default;
    ~HeapSort() override = default;

    std::string getName() const override {
        return "Heap Sort";
    }

    void sort(int* arr, int size) override;
};