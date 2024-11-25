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
            grid[row][column] = 0;
        }
    }
}

void Grid::Print(){
    for(int row=0;row<numRows;row++){
        for(int column=0; column<numCols;column++){
           std::cout << grid[row][column] << " "; 
        }
        std::cout << "\n";
    }
}

void Grid::Draw(){
     for(int row=0;row<numRows;row++){
        for(int column=0; column<numCols;column++){
            int cellvalue = grid[row][column];
            if(cellvalue==0){    
                DrawRectangle(column*cellsize+1,row*cellsize+1,cellsize-1,cellsize-1,DARKGRAY);
            } else {
                DrawRectangle(column*cellsize+1,row*cellsize+1,cellsize-1,cellsize-1,YELLOW); 
            }
        }
    }
}