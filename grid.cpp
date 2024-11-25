#include "grid.h"
#include <iostream>

Grid::Grid(){
    numRows = 20;
    numCols = 20;
    cellsize = 30;
    Initialize();
}   

void Grid::Initialize(){
    for(int row=0;row<numRows;row++){
        for(int column=0; column<numCols;column++){
            int* cellInfo = new int[2];
            cellInfo[0]=0;
            cellInfo[1]=0;
            grid[row][column] = cellInfo;
        }
    }
}

void Grid::Print(){
    for(int row=0;row<numRows;row++){
        for(int column=0; column<numCols;column++){
           std::cout << grid[row][column][0] << " "; 
        }
        std::cout << "\n";
    }
}

void Grid::Draw(){
     for(int row=0;row<numRows;row++){
        for(int column=0; column<numCols;column++){
            if(grid[row][column][0]==0){    
                DrawRectangle(column*cellsize+1,row*cellsize+1,cellsize-1,cellsize-1,DARKGRAY);
            } else {
                DrawRectangle(column*cellsize+1,row*cellsize+1,cellsize-1,cellsize-1,YELLOW);
            }      
        }
    }
}