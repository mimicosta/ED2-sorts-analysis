#pragma once
#include <iostream>
#include <random>
#include <thread>

class DataGenerator {
private:
    int size;
    int* array;

public:
    DataGenerator();
    ~DataGenerator();
    int getSize();
    void setSize(int newSize);
    int* getArray();
    void generate(int size);
};