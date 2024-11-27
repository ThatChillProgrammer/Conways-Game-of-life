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

void Grid::CgolRules(int row, int cols){
    int cellStatus=grid[row][cols][0], cellNeighbor=grid[row][cols][1]; 
    if(cellStatus == 1){
        if(cellNeighbor<2){
            grid[row][cols][0] = 0;
        }
        if(cellNeighbor > 3){
            grid[row][cols][0] = 0;
        }
    }
    if(cellStatus==0 and cellNeighbor==3){
        grid[row][cols][0] = 1;
    }
    grid[row][cols][1] = 0;
}

void Grid::Borders(int row, int cols){
    if((row == 0 or row == 19) and (cols == 0 or cols == 19)){
        if(row==0 and cols==0){
            for(int i=row;i<row+2;i++){
                for(int j=cols;j<cols+2;j++){
                    if(i!=row or j!=cols){ 
                    grid[row][cols][1] = grid[row][cols][1] + 1;
                    }
                }
            }
        }
        if(row==0 and cols==19){
            for(int i=row;i<row+2;i++){
                for(int j=cols-1;j<cols+1;j++){
                    if(i!=row or j!=cols){
                        grid[row][cols][1]++;
                    }
                }
            }
        }
        if(row==19 and cols==0){
            for(int i=row-1;i<row+1;i++){
                for(int j=cols;j<cols+2;j++){
                    if(i!=row or j!=cols){
                        grid[row][cols][1]++;
                    }
                }
            }
        }
        if(row==19 and cols==19){
            for(int i=row-1;i<row;i++){
                for(int j=cols-1;j<cols+2;j++){
                    if(i!=row or j!=cols){
                        grid[row][cols][1]++;
                    }
                }
            }
        }
    } else {
        if(row==0){
            for(int i=row;i<row+2;i++){
                for(int j=cols-1;j<cols+2;j++){
                    if(i!=row or j!=cols){
                        grid[row][cols][1]++;
                    }
                }
            }
        }
        if(cols==0){
            for(int i=row-1;i<row+2;i++){
                for(int j=cols;j<cols+2;j++){
                    if(i!=row or j!=cols){
                       grid[row][cols][1]++;
                    }
                }
            }
        }
        if(row==19){
            for(int i=row-1;i<row+1;i++){
                for(int j=cols-1;j<cols+2;j++){
                    if(i!=row or j!=cols){
                        grid[row][cols][1]++;
                    }
                    
                }
            }
        }
        if(cols==19){
            for(int i=row-1;i<row+2;i++){
                for(int j=cols-1;j<cols+1;j++){
                    if(i!=row or j!=cols){
                        grid[row][cols][1]++;
                    }
                    
                }
            }
        }

    }    
}


void Grid::StatusFunction(int row, int cols){
   if((row!=19 and row!=0) and (cols!=19 and cols!=0)){
        for(int i=row-1; i<row+2;i++){
            for(int j=cols-1;i<cols+2;i++){
                if(i!=row or i!=cols){
                     if(grid[i][j][0]==1){
                        grid[row][cols][1]++;
                    }
                }
            }
        }
    } else {
        std::cout << "check";
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
            CgolRules(row,column);
            std::cout << grid[1][0][0];
        }
    }
}


