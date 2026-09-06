#pragma once
#include <iostream>
#include <chrono>

class Statistics {
public:
    Statistics();
    void reset();
    void startTimer();
    void endTimer();
    double timeElapsed() const;
    unsigned long long getNComparisons() const;
    unsigned long long getNSwaps() const;
    void incrementComparison();
    void incrementSwap();

private:
    unsigned long long nComparisons;
    unsigned long long nSwaps;
    std::chrono::high_resolution_clock::time_point startTime;
    std::chrono::high_resolution_clock::time_point endTime;
};