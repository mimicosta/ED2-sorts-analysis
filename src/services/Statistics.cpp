#include "services/Statistics.hpp"

Statistics::Statistics() {
    reset();
}

void Statistics::reset() {
    this->nComparisons = 0;
    this->nSwaps = 0;
    this->startTime = std::chrono::high_resolution_clock::now();
    this->endTime = this->startTime;
}

void Statistics::startTimer() {
    this->startTime = std::chrono::high_resolution_clock::now();
}

void Statistics::endTimer() {
    this->endTime = std::chrono::high_resolution_clock::now();
}

double Statistics::timeElapsed() const {
    std::chrono::duration<double, std::milli> duration = this->endTime - this->startTime;
    return duration.count();
}

unsigned long long Statistics::getNComparisons() const {
    return this->nComparisons;
}

unsigned long long Statistics::getNSwaps() const {
    return this->nSwaps;
}

void Statistics::incrementSwap() {
    this->nSwaps++;
}

void Statistics::incrementComparison() {
    this->nComparisons++;
}