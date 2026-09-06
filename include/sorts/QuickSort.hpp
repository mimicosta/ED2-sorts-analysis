#pragma once
#include "Sort.hpp"
#include <string>

class QuickSort : public Sort {
private:
    void quickSort(int* arr, int low, int high);

public:
    QuickSort() = default;
    ~QuickSort() override = default;
    

    std::string getName() const override {
        return "Quick Sort";
    }

    void sort(int* arr, int size) override;
};