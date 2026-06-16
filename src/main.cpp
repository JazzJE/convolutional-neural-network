#include <iostream>

#include "raylib.h"
#include "Tensor.h"

int main()
{
    InitWindow(800, 600, "CNN");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("Raylib works!", 250, 280, 30, BLACK);

        EndDrawing();
    }

    CloseWindow();
}