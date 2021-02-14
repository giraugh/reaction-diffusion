#ifndef CORE_H
#define CORE_H

const int GRID_WIDTH = 20;
const int GRID_HEIGHT = 20;

class RDConfig
{
    public:
        double diffA = 1.0; // Diffusion rate (a)
        double diffB = 0.5; // Diffusion rate (b)
        double feed = 0.055; // feed rate
        double kill = 0.062; // kill rate
        double dt = 1.0; // time scale

        double laplaceWeights[3][3] = {
            {.05, .2, .05},
            {.2,  -1, .20},
            {.05, .2, .05}
        };
};

struct GridCell
{
    long double a;
    long double b;
};

enum CellType {
    A,
    B
};

class GridData
{
    private:
        GridCell swap[GRID_WIDTH][GRID_HEIGHT];

    public:
        GridCell data[GRID_WIDTH][GRID_HEIGHT];

        GridData();
        void swapGrids();
        void print();
        void update(RDConfig* config);
        long double laplace(RDConfig* config, CellType cellType, int i, int j);
        long double getCellValue(CellType cellType, int i, int j);
};

#endif
