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


            if((column==0 or column==19) and (row==0 or row ==19)){
                if (column==0 and column==row){
                    if (grid[row+1][column] == 1 and grid[row][column+1] == 1){
                        DrawRectangle(column*cellsize+1,row*cellsize+1,cellsize-1,cellsize-1,YELLOW);
                    } else {
                        DrawRectangle(column*cellsize+1,row*cellsize+1,cellsize-1,cellsize-1,DARKGRAY);
                    }
                } else if (column==19 and column==row){
                    if (grid[row-1][column] == 1 and grid[row][column-1] == 1){
                        DrawRectangle(column*cellsize+1,row*cellsize+1,cellsize-1,cellsize-1,YELLOW);
                    } else {
                        DrawRectangle(column*cellsize+1,row*cellsize+1,cellsize-1,cellsize-1,DARKGRAY);
                    }}}
            
        }
    }
}