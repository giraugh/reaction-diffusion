#include <iostream>
#include "core.h"

int main(int argc, char* argv[])
{
    // Construct grid data
    GridData* gd = new GridData();
    std::cout << "--" << std::endl;
    gd->print();
    gd->data[0][0] = 1.0f;
    std::cout << "--" << std::endl;
    gd->print();
    gd->swapGrids();
    std::cout << "--" << std::endl;
    gd->print();

    return 0;
}
