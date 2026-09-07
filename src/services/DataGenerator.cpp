#include "../../include/services/DataGenerator.hpp"
#include <random>
#include <algorithm>

DataGenerator::DataGenerator() : size(0), array(nullptr) {}

DataGenerator::~DataGenerator() {
    if (this->array != nullptr) {
        delete[] this->array;
        this->array = nullptr;
    }
}

void DataGenerator::allocateArray(int newSize) {
    if (this->array != nullptr) {
        delete[] this->array;
        this->array = nullptr;
    }
    this->size = newSize;
    if (newSize > 0) {
        this->array = new int[newSize];
    }
}

void DataGenerator::generateRandom(int size) {
    allocateArray(size);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1, size * 10);

    for (int i = 0; i < size; i++) {
        this->array[i] = distrib(gen);
    }
}

void DataGenerator::generateSorted(int size) {
    allocateArray(size);
    for (int i = 0; i < size; i++) {
        this->array[i] = i + 1;
    }
}

void DataGenerator::generateReverseSorted(int size) {
    allocateArray(size);
    for (int i = 0; i < size; i++) {
        this->array[i] = size - i;
    }
}

void DataGenerator::generatePartiallySorted(int size) {
    generateSorted(size);

    if (size <= 1) return;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(0, size - 1);

    int swaps = std::max(1, static_cast<int>(size * 0.05));
    for (int i = 0; i < swaps; i++) {
        int idx1 = distrib(gen);
        int idx2 = distrib(gen);
        std::swap(this->array[idx1], this->array[idx2]);
    }
}

int DataGenerator::getSize() const {
    return this->size;
}

int* DataGenerator::getArray() const {
    return this->array;
}
