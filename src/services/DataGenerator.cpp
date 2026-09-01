#include "../include/DataGenerator.hpp"

DataGenerator::DataGenerator() : size(0), array(nullptr) {}

DataGenerator::~DataGenerator() {
    if (this->array != nullptr) {
        delete[] this->array;
        this->array = nullptr;
    }
}

void DataGenerator::generate(int size) {
    this->size = size;

    if (this->array != nullptr) {
        delete[] this->array;
    }
    this->array = new int[size];

    int mid = size / 2;

    std::thread t1([this, mid]() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distrib(1, 10000);

        for (int i = 0; i < mid; i++) {
            this->array[i] = distrib(gen);
        }
    });

    std::thread t2([this, mid, size]() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distrib(1, 10000);

        for (int i = mid; i < size; i++) {
            this->array[i] = distrib(gen);
        }
    });

    t1.join();
    t2.join();
}

void DataGenerator::setSize(int newSize) { this->size = newSize; }
int DataGenerator::getSize() { return this->size; }
int* DataGenerator::getArray() { return this->array; }

