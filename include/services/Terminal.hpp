#pragma once

#include <iostream>
#include <string>

class TerminalInterface {
private:
    void printHeader(const std::string& titulo) const;
    void printArray(const int arr[], size_t tamanho) const;

public:
    void showMenu() const;
    void showData(const int dados[], size_t tamanho) const;
    void applyInsertionSort(const int dados[], size_t tamanho) const;
    void applySelectionSort(const int dados[], size_t tamanho) const;
};