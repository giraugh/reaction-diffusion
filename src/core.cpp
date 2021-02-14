#include <iostream>
#include "core.h"

GridData::GridData()
{
    // Initialise grids
    for (int i = 0; i < GRID_WIDTH; i++)
    {
        for (int j = 0; j < GRID_HEIGHT; j++)
        {
            GridCell a {0.0f, 0.0f};
            GridCell b {0.0f, 0.0f};
            data[i][j] = a;
            swap[i][j] = b;
        }
    }
}

void GridData::swapGrids()
{
    for (int i = 0; i < GRID_WIDTH; i++)
    {
        for (int j = 0; j < GRID_HEIGHT; j++)
        {
            GridCell t = data[i][j];
            data[i][j] = swap[i][j];
            swap[i][j] = t;
        }
    }
}

long double GridData::laplaceA(RDConfig* config, int i, int j)
{
    long double s = 0;
    for (int di = 0; di < 3; di++)
    {
        for (int dj = 0; dj < 3; dj++)
        {
            int x = i + di - 1;
            int y = j + dj - 1;
            s += data[x][y].a * config->laplaceWeights[di][dj];
        }
    }

    return s;
}

long double GridData::laplaceB(RDConfig* config, int i, int j)
{
    long double s = 0;
    for (int di = 0; di < 3; di++)
    {
        for (int dj = 0; dj < 3; dj++)
        {
            int x = i + di - 1;
            int y = j + dj - 1;
            s += data[x][y].b * config->laplaceWeights[di][dj];
        }
    }

    return s;
}

void GridData::update(RDConfig* config)
{
    for (int i = 0; i < GRID_WIDTH; i++)
    {
        for (int j = 0; j < GRID_HEIGHT; j++)
        {
            // Calculate deltas
            long double a = data[i][j].a;
            long double b = data[i][j].b;
            long double deltaA =
                  (config->diffA * laplaceA(config, i, j))
                - (a * b * b)
                + (config->feed * (1 - a));
            long double deltaB =
                  (config->diffB * laplaceB(config, i, j))
                + (a * b * b)
                - (config->kill + config->feed) * b;

            // Update Step
            swap[i][j].a = a + deltaA * config->dt;
            swap[i][j].b = b + deltaB * config->dt;
        }
    }

    // Swap grids
    this->swapGrids();
}

void GridData::print()
{
    for (int i = 0; i < GRID_WIDTH; i++)
    {
        for (int j = 0; j < GRID_HEIGHT; j++)
        {
            std::cout << "[" << data[i][j].a << "|" << data[i][j].b << "]";
        }
        std::cout << std::endl;
    }
}
