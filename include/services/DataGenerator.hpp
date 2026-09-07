#pragma once

class DataGenerator {
private:
    int size;
    int* array;
    void allocateArray(int newSize);

public:
    DataGenerator();
    ~DataGenerator();

    int getSize() const;
    int* getArray() const;
    void generateRandom(int size);
    void generateSorted(int size);
    void generateReverseSorted(int size);
    void generatePartiallySorted(int size);
};