#include <iostream>

#include "raylib.h"
#include "Tensor.h"
#include "ImageProcessor.h"

int main()
{
    // Construct the CNN first
    ImageProcessor p(2, 5, 3);
    char raw_data[] = { 1, 1, 1,
                      1, 1, 1,
                        1, 1, 1 };
    p.grayscale_and_store_image(raw_data);
    Tensor<double>& image_buffer = p.get_image_buffer();
    std::cout << image_buffer;

    // Get the first kernel size and create an image processor with the given padding


    // Run the game
    /*
    InitWindow(800, 600, "CNN");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("Raylib works!", 250, 280, 30, BLACK);

        EndDrawing();
    }

    CloseWindow();
    */

    return 0;
}