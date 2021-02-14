#include <iostream>
#include "core.h"

int main(int argc, char* argv[])
{
    // Construct grid data
    GridData* gd = new GridData();
    RDConfig* config = new RDConfig();

    for (int i = 0; i < 9999; i++)
    gd->update(config);

    gd->print();

    return 0;
}
