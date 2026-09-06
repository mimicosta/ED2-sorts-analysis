#pragma once

#include "Sort.hpp"
#include <string>

class InsertionSort : public Sort
{
class InsertionSort : public Sort {
public:
    InsertionSort() = default;
    ~InsertionSort() override = default;

    std::string getName() const override {
        return "Insertion Sort";
    }

    void sort(int* arr, int size) override;
};