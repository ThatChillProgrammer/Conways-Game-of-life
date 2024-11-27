#pragma once
#include <vector>
#include <raylib.h>

class Grid{
public:
    Grid();
    void Initialize();
    void Print();
    void StatusFunction(int row, int cols);
    void Borders(int row, int cols);
    void CgolRules(int row, int cols);
    void Draw();


    int* grid[20][20];
private:
    int numRows, numCols, cellsize;
};