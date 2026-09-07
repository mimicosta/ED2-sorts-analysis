#include <iostream>

#include "sorts/InsertionSort.hpp"
#include "sorts/SelectionSort.hpp"
#include "sorts/ShellSort.hpp"
#include "sorts/QuickSort.hpp"

#include "services/DataGenerator.hpp"
#include "services/Console.hpp"

constexpr int MAX_SIZE = 100000;

int main() {
    Console::showHeader();

    int size = Console::promptArraySize();
    if (size > MAX_SIZE) {
        std::cout << "Aviso: Tamanho limitado ao maximo permitido na pilha (" << MAX_SIZE << ").\n";
        size = MAX_SIZE;
    }

    DataGenerator generator;
    generator.generate(size);
    int* originalData = generator.getArray();

    int workingArray[MAX_SIZE];

    InsertionSort insertion;
    SelectionSort selection;
    ShellSort     shell;
    QuickSort     quick;

    Sort* algorithms[] = {
        &selection,
        &insertion,
        &shell,
        &quick
    };

    Console::showTableHeader();

    for (Sort* algo : algorithms) {
        for (int i = 0; i < size; i++) {
            workingArray[i] = originalData[i];
        }
        algo->run(workingArray, size);


        Statistics stats = algo->getStats();
        Console::showTableRow(
            algo->getName(),
            stats.getNComparisons(),
            stats.getNSwaps(),
            stats.timeElapsed()
        );
    }

    Console::showTableFooter();

    return 0;
}