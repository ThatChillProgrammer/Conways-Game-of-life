#pragma once
#include <vector>
#include <raylib.h>

class Grid{
public:
    Grid();
    void Initialize();
    void Print();
    void Draw();


    int* grid[20][20];
private:
    int numRows, numCols, cellsize;
};