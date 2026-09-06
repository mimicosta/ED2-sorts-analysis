#pragma once

#include "Sort.hpp"

class SelectionSort : public Sort
{
public:
    void sort(int* arr, int size) override;
};