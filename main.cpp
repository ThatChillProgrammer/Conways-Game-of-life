#include <raylib.h>
#include "grid.h"

int main() {

    InitWindow(700,700,"RayLib Wind");

    SetTargetFPS(60);

    Grid grid = Grid();
    grid.grid[0][1] = 1;
    grid.Print();
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);

        grid.Draw();
        EndDrawing();
    }

    CloseWindow();
}


