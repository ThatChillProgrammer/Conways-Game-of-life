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

void Grid::Borders(int row, int cols){
    if((row != 0 or row != 19) and (cols!=0 or cols!=19)){

    } else {

    }
}

void Grid::StatusFunction(int row, int cols){
   if((row!=19 and row!=0) and (cols!=19 and cols!=0)){
        for(int i=row-1; i<row+2;i++){
            for(int j=cols-1;i<cols+2;i++){
                if(i!=row or i!=cols){
                     if(grid[i][j][0]==1){
                        grid[i][j][1]++;
                    }
                }
            }
        }
    } else {
        Borders(row,cols);
    }
};

void Grid::Draw(){
     for(int row=0;row<numRows;row++){
        for(int column=0; column<numCols;column++){
            StatusFunction(row, column);
            if(grid[row][column][0]==0){    
                DrawRectangle(column*cellsize+1,row*cellsize+1,cellsize-1,cellsize-1,DARKGRAY);
            } else {
                DrawRectangle(column*cellsize+1,row*cellsize+1,cellsize-1,cellsize-1,YELLOW);
            }
        }
    }
}