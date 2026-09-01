#pragma once
#include <iostream>
#include <chrono>

class Statistics {

    public:
        Statistics();
        int timeElapsed();
        void startTimer();
        void endTimer();
        int getNComparisons();
        int getNSwaps();
        void incrementComparison();
        void incrementSwap();

    private:
        int nComparisons;
        int nSwaps;
        std::chrono::high_resolution_clock::timepoint startTime;
        std::chrono::high_resolution_clock::timepoint endTime;

};