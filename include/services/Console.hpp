#pragma once

#include <iostream>
#include <string>
#include <cstddef>

namespace Console {

    inline void showHeader();
    inline int promptArraySize();
    inline void showTableHeader();
    inline void showTableRow(const std::string& name, unsigned long long comparisons, unsigned long long swaps, double timeMs);
    inline void showTableFooter();

}