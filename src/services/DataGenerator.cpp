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

void DataGenerator::generate(int size) {
    this->size = size;

void DataGenerator::allocateArray(int newSize) {
    if (this->array != nullptr) {
        delete[] this->array;
        this->array = nullptr;
    }
    this->array = new int[size];
    this->size = newSize;
    if (newSize > 0) {
        this->array = new int[newSize];
    }
}

    int mid = size / 2;
void DataGenerator::generate(int size) {
    generateRandom(size);
}

    std::thread t1([this, mid, size]() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distrib(1, size);
void DataGenerator::generateRandom(int size) {
    allocateArray(size);

        for (int i = 0; i < mid; i++) {
            this->array[i] = distrib(gen);
        }
    });
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1, size * 10);

    std::thread t2([this, mid, size]() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distrib(1, size);
    for (int i = 0; i < size; i++) {
        this->array[i] = distrib(gen);
    }
}

        for (int i = mid; i < size; i++) {
            this->array[i] = distrib(gen);
        }
    });
void DataGenerator::generateSorted(int size) {
    allocateArray(size);
    for (int i = 0; i < size; i++) {
        this->array[i] = i + 1;
    }
}

    t1.join();
    t2.join();
void DataGenerator::generateReverseSorted(int size) {
    allocateArray(size);
    for (int i = 0; i < size; i++) {
        this->array[i] = size - i;
    }
}

void DataGenerator::setSize(int newSize) { this->size = newSize; }
int DataGenerator::getSize() { return this->size; }
int* DataGenerator::getArray() { return this->array; }
void DataGenerator::generatePartiallySorted(int size) {
    generateSorted(size);

    if (size <= 1) return;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(0, size - 1);

    // Troca ~5% a 10% dos elementos para simular dados parcialmente ordenados
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
