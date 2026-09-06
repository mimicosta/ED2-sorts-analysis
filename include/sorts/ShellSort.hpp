#pragma once
#include "Sort.hpp"
#include <string>

class ShellSort : public Sort {
public:
    ShellSort() = default;
    ~ShellSort() override = default;

    std::string getName() const override {
        return "Shell Sort";
    }

    void sort(int* arr, int size) override;
};