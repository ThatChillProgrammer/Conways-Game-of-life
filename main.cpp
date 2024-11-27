#include <raylib.h>
#include "grid.h"

int main() {

    InitWindow(700,700,"RayLib Wind");

    SetTargetFPS(1);

    Grid grid = Grid();
    grid.Initialize();
    grid.grid[0][0][0] = 1;
    grid.grid[1][0][0] = 1;
    grid.grid[0][1][0] = 1;

    grid.grid[10][19][0]= 1;

    grid.grid[7][7][0] = 1;
    grid.grid[7][8][0] = 1;
    grid.grid[8][7][0] = 1;

    grid.Print();
    while(!WindowShouldClose()){
        BeginDrawing();

        
        ClearBackground(BLACK);
        grid.Draw();
        EndDrawing();
    }

    CloseWindow();
}


