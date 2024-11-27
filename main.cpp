#include <raylib.h>
#include "grid.h"

int main() {

    InitWindow(600,600,"Connoway's Game Of Life");

    SetTargetFPS(25);

    Grid grid = Grid();
    grid.Initialize();

    grid.grid[7][7][0] = 1;
    grid.grid[8][7][0] = 1;
    grid.grid[7][8][0] = 1;
    grid.grid[6][7][0] = 1;

    grid.grid[7][5][0] = 1;
    grid.grid[7][7][0] = 1;
    grid.grid[7][7][0] = 1;
    grid.grid[7][7][0] = 1;
    grid.grid[7][7][0] = 1;

    grid.Print();
    
    while(!WindowShouldClose()){
        BeginDrawing();

        
        ClearBackground(BLACK);
        grid.Draw();
        EndDrawing();
    }

    CloseWindow();
}


