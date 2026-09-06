#include "../include/Statistics.hpp"
#include "../../include/services/Statistics.hpp"

Statistics::Statistics(){
Statistics::Statistics() {
    reset();
}

void Statistics::reset() {
    this->nComparisons = 0;
    this->nSwaps = 0;
    this->startTime = std::chrono::high_resolution_clock::now();
    this->endTime = std::chrono::high_resolution_clock::now();
    this->endTime = this->startTime;
}

void Statistics::startTimer(){
void Statistics::startTimer() {
    this->startTime = std::chrono::high_resolution_clock::now();
}

void Statistics::endTimer(){
void Statistics::endTimer() {
    this->endTime = std::chrono::high_resolution_clock::now();
}

int Statistics::timeElapsed(){
double Statistics::timeElapsed() const {
    std::chrono::duration<double, std::milli> duration = this->endTime - this->startTime;
    duration /= 1000;
    return duration;
    return duration.count();
}

int Statistics::getNComparisons(){ return this->nComparisons; }
int Statistics::getNSwaps(){ return this->nSwaps; }
unsigned long long Statistics::getNComparisons() const {
    return this->nComparisons;
}

void Statistics::incrementSwap(){ this->nSwaps++; }
void Statistics::incrementComparison(){ this->nComparison++; }
unsigned long long Statistics::getNSwaps() const {
    return this->nSwaps;
}

void Statistics::incrementSwap() {
    this->nSwaps++;
}

void Statistics::incrementComparison() {
    this->nComparisons++;
}

