#ifndef CORE_H
#define CORE_H

const int GRID_WIDTH = 20;
const int GRID_HEIGHT = 20;

class GridData
{
    private:
        long double swap[GRID_WIDTH][GRID_HEIGHT];

    public:
        long double data[GRID_WIDTH][GRID_HEIGHT];

        GridData();
        void swapGrids();
        void print();
};

#endif
