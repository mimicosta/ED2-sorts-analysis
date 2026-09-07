#include <iostream>
#include <string>

#include "sorts/InsertionSort.hpp"
#include "sorts/SelectionSort.hpp"
#include "sorts/ShellSort.hpp"
#include "sorts/QuickSort.hpp"

#include "services/DataGenerator.hpp"
#include "services/Console.hpp"

constexpr int MAX_SIZE = 100000;

typedef void (DataGenerator::*GeneratorMethod)(int);

struct Scenario {
    std::string name;
    GeneratorMethod generatorFunc;
};

int main() {
    Console::showHeader();

    int size = Console::promptArraySize();
    if (size > MAX_SIZE) {
        std::cout << "Aviso: Tamanho limitado ao maximo permitido (" << MAX_SIZE << ").\n";
        size = MAX_SIZE;
    }

    DataGenerator generator;

    InsertionSort insertion;
    SelectionSort selection;
    ShellSort     shell;
    QuickSort     quick;

    Sort* algorithms[4] = {
        &selection,
        &insertion,
        &shell,
        &quick
    };

    Scenario scenarios[4] = {
        {"Aleatorio",             &DataGenerator::generateRandom},
        {"Ordenado",              &DataGenerator::generateSorted},
        {"Invertido",             &DataGenerator::generateReverseSorted},
        {"Parcialmente Ordenado", &DataGenerator::generatePartiallySorted}
    };

    int workingArray[MAX_SIZE];

    for (int s = 0; s < 4; s++) {
        Scenario currentScenario = scenarios[s];
        
        GeneratorMethod method = currentScenario.generatorFunc;
        (generator.*method)(size);
        
        int* originalData = generator.getArray();

        Console::showScenarioHeader(currentScenario.name);
        Console::showTableHeader();

        for (int a = 0; a < 4; a++) {
            Sort* algo = algorithms[a];

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
    }

    return 0;
}