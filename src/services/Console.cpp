#pragma once
#include <iostream>
#include <iomanip>
#include <string>

namespace Console {

    inline void showHeader() {
        std::cout << "========================================================================\n";
        std::cout << "             ANALISE COMPARATIVA DE ALGORITMOS DE ORDENACAO             \n";
        std::cout << "========================================================================\n\n";
    }

    inline int promptArraySize() {
        int size = 0;
        std::cout << "Digite o tamanho do vetor para o teste: ";
        while (!(std::cin >> size) || size <= 0) {
            std::cout << "Entrada invalida. Digite um numero inteiro positivo: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        return size;
    }

    inline void showTableHeader() {
        std::cout << "\n"
                  << std::left  << std::setw(20) << "Algoritmo"
                  << std::right << std::setw(16) << "Comparacoes"
                  << std::right << std::setw(18) << "Movimentacoes"
                  << std::right << std::setw(20) << "Tempo de exec. (ms)" << "\n";
        std::cout << std::string(74, '-') << "\n";
    }

    inline void showTableRow(const std::string& name, unsigned long long comparisons, unsigned long long swaps, double timeMs) {
        std::cout << std::left  << std::setw(20) << name
                  << std::right << std::setw(16) << comparisons
                  << std::right << std::setw(18) << swaps
                  << std::right << std::setw(20) << std::fixed << std::setprecision(4) << timeMs 
                  << "\n";
    }

    inline void showTableFooter() {
        std::cout << std::string(74, '-') << "\n\n";
    }
}