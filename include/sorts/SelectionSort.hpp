#pragma once

#include "Sort.hpp"
#include <string>

class SelectionSort : public Sort
{
class SelectionSort : public Sort {
public:
    SelectionSort() = default;
    ~SelectionSort() override = default;

    std::string getName() const override {
        return "Selection Sort";
    }

    void sort(int* arr, int size) override;
};