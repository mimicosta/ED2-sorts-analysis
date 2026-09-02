#pragma once

#include "Sort.hpp"

class InsertionSort : public Sort
{
public:
    void sort(int* arr, int size) override;
};