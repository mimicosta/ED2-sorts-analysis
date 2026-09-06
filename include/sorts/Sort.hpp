#pragma once
#include <string>
#include "../services/Statistics.hpp"

class Sort {
protected:
    Statistics stats;

public:
    virtual ~Sort() = default;

    virtual std::string getName() const = 0;
    virtual void sort(int* arr, int size) = 0;

    void run(int* arr, int size) {
        stats.reset();
        stats.startTimer();
        sort(arr, size);
        stats.endTimer();
    }

    Statistics getStats() const {
        return stats;
    }
};