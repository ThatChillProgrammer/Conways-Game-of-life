#include <raylib.h>
#include "grid.h"

int main() {

    InitWindow(700,700,"RayLib Wind");

    SetTargetFPS(60);

    Grid grid = Grid();
    grid.grid[0][0] = 1;
    grid.grid[1][0] = 1;
    grid.grid[0][1] = 1;

    grid.grid[0][19] = 1;
    grid.grid[19][0] = 1;
    grid.grid[19][19] = 1;

    grid.Print();
    while(!WindowShouldClose()){
        BeginDrawing();

        
        ClearBackground(BLACK);
        grid.Draw();
        EndDrawing();
    }

    CloseWindow();
}


