#include <iostream>
#include <string>
#include "../../include/ui/Terminal.hpp"

void TerminalInterface::printHeader(const std::string& titulo) const {
    std::cout << "\n========================================\n";
    std::cout << "  " << titulo << "\n";
    std::cout << "========================================\n";
}

void TerminalInterface::printArray(const int arr[], size_t tamanho) const {
    std::cout << "[ ";
    for (size_t i = 0; i < tamanho; ++i) {
        std::cout << arr[i] << (i + 1 < tamanho ? ", " : " ");
    }
    std::cout << "]\n";
}

void TerminalInterface::showMenu() const {
    printHeader("PAINEL DE ORDENACAO");
    std::cout << "1. Mostrar Dados Gerados\n";
    std::cout << "2. Aplicar Insertion Sort\n";
    std::cout << "3. Aplicar Selection Sort\n";
    std::cout << "0. Sair\n";
    std::cout << "----------------------------------------\n";
    std::cout << "Escolha uma opcao: ";
}

void TerminalInterface::showData(const int dados[], size_t tamanho) const {
    printHeader("DADOS ATUAIS");
    
    if (tamanho == 0) {
        std::cout << "Nenhum dado gerado ainda.\n";
        return;
    }
    
    printArray(dados, tamanho);
}

void TerminalInterface::applyInsertionSort(const int dados[], size_t tamanho) const {
    printHeader("EXECUTANDO INSERTION SORT");

    if (tamanho == 0) {
        std::cout << "Nenhum dado para ordenar.\n";
        return;
    }

    int copia[tamanho];
    for (size_t i = 0; i < tamanho; ++i) {
        copia[i] = dados[i];
    }

    std::cout << "Resultado ordenado:\n";
    printArray(copia, tamanho);
}

void TerminalInterface::applySelectionSort(const int dados[], size_t tamanho) const {
    printHeader("EXECUTANDO SELECTION SORT");

    if (tamanho == 0) {
        std::cout << "Nenhum dado para ordenar.\n";
        return;
    }

    int copia[tamanho];
    for (size_t i = 0; i < tamanho; ++i) {
        copia[i] = dados[i];
    }

    std::cout << "Resultado ordenado:\n";
    printArray(copia, tamanho);
}