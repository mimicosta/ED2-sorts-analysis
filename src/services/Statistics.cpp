#include "../include/Statistics.hpp"

Statistics::Statistics(){
    this->nComparisons = 0;
    this->nSwaps = 0;
    this->startTime = std::chrono::high_resolution_clock::now();
    this->endTime = std::chrono::high_resolution_clock::now();
}

void Statistics::startTimer(){
    this->startTime = std::chrono::high_resolution_clock::now();
}

void Statistics::endTimer(){
    this->endTime = std::chrono::high_resolution_clock::now();
}

int Statistics::timeElapsed(){
    std::chrono::duration<double, std::milli> duration = this->endTime - this->startTime;
    duration /= 1000;
    return duration;
}

int Statistics::getNComparisons(){ return this->nComparisons; }
int Statistics::getNSwaps(){ return this->nSwaps; }

void Statistics::incrementSwap(){ this->nSwaps++; }
void Statistics::incrementComparison(){ this->nComparison++; }
