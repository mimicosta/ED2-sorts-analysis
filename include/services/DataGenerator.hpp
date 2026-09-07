#pragma once
#include <iostream>
#include <random>
#include <thread>

class DataGenerator {
private:
    int size;
    int* array;
    void allocateArray(int newSize);

public:
    DataGenerator();
    ~DataGenerator();
    int getSize();
    void setSize(int newSize);
    int* getArray();

    int getSize() const;
    int* getArray() const;

    void generate(int size);
    void generateRandom(int size);
    void generateSorted(int size);
    void generateReverseSorted(int size);
    void generatePartiallySorted(int size);
};