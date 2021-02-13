#include <iostream>
#include "core.h"

GridData::GridData()
{
    // Initialise grids
    for (int i = 0; i < GRID_WIDTH; i++)
    {
        for (int j = 0; j < GRID_HEIGHT; j++)
        {
            data[i][j] = 0.0f;
            swap[i][j] = 0.0f;
        }
    }
}

void GridData::swapGrids()
{
    for (int i = 0; i < GRID_WIDTH; i++)
    {
        for (int j = 0; j < GRID_HEIGHT; j++)
        {
            long double t = data[i][j];
            data[i][j] = swap[i][j];
            swap[i][j] = t;
        }
    }
}

void GridData::print()
{
    for (int i = 0; i < GRID_WIDTH; i++)
    {
        for (int j = 0; j < GRID_HEIGHT; j++)
        {
            std::cout << data[i][j];
        }
        std::cout << std::endl;
    }
}
