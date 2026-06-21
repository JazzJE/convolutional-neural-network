#include <iostream>
#include <random>
#include <string>

#include "raylib.h"
#include "Tensor.h"
#include "ImageProcessor.h"
#include "Configs.h"

void keepSpriteInScreen(Rectangle& sprite)
{
    if (sprite.x < 0) sprite.x = 0;
    if (sprite.y < 0) sprite.y = 0;
    if (sprite.x + sprite.width > GameConfigs::GAME_WIDTH) sprite.x = GameConfigs::GAME_WIDTH - sprite.width;
    if (sprite.y + sprite.height > GameConfigs::GAME_HEIGHT) sprite.y = GameConfigs::GAME_HEIGHT - sprite.height;
}

int main()
{
    // Construct the CNN first
    ImageProcessor p(2, 5, 3);
    char raw_data[] = { 1, 1, 1,
                      1, 1, 1,
                        1, 1, 1,
                       1, 1, 1,
                        1, 1, 1};
    p.grayscale_and_store_image(raw_data);
    Tensor<double>& image_buffer = p.get_image_buffer();
    std::cout << image_buffer;

    // Get the first kernel size and create an image processor with the given padding


    // Initialization
    InitWindow(GameConfigs::GAME_WIDTH, GameConfigs::GAME_HEIGHT, "Pong (vs. evil robot)");
    std::random_device rd;
    std::mt19937 gen(rd()); // Mersenne Twister engine
    std::uniform_int_distribution<int> dist(GameConfigs::MIN_BALL_DY, GameConfigs::MAX_BALL_DY);
    size_t player_score = 0;
    size_t evil_robot_score = 0;

    // Paddles
    Rectangle player = { 
        GameConfigs::SPAWN_OFFSET, 
        (GameConfigs::GAME_HEIGHT - GameConfigs::PADDLE_HEIGHT) / 2, 
        GameConfigs::PADDLE_WIDTH, 
        GameConfigs::PADDLE_HEIGHT 
    }; // x, y, width, height
    Color playerColor = BLUE;
    Rectangle evil_robot = { 
        GameConfigs::GAME_WIDTH - GameConfigs::SPAWN_OFFSET,
        (GameConfigs::GAME_HEIGHT - GameConfigs::PADDLE_HEIGHT) / 2, 
        GameConfigs::PADDLE_WIDTH, 
        GameConfigs::PADDLE_HEIGHT 
    };
    Color evilRobotColor = RED;

    // Ball
    float dx = GameConfigs::INIT_BALL_DX;
    float dy = dist(gen);
    Rectangle ball = { (GameConfigs::GAME_WIDTH - GameConfigs::BALL_WIDTH) / 2, (GameConfigs::GAME_HEIGHT - GameConfigs::BALL_HEIGHT) / 2, GameConfigs::BALL_WIDTH, GameConfigs::BALL_HEIGHT };
    Color ballColor = WHITE;

    SetTargetFPS(30);

    // Main game loop
    while (!WindowShouldClose()) {
        // Delta time for smooth movement
        float dt = GetFrameTime();

        /*
        // Player movement with arrow keys
        if (IsKeyDown(KEY_DOWN))  player.y += GameConfigs::PADDLE_SPEED * dt;
        if (IsKeyDown(KEY_UP))    player.y -= GameConfigs::PADDLE_SPEED * dt;
        */

        // Have the blue paddle auto follow the ball
        if (ball.y > player.y - GameConfigs::BALL_HEIGHT / 2) player.y += GameConfigs::PADDLE_SPEED * dt;
        if (ball.y < player.y - GameConfigs::BALL_HEIGHT / 2) player.y -= GameConfigs::PADDLE_SPEED * dt;

        // Move the ball
        ball.x += dx;
        ball.y += dy;

        // If the ball moved above or below the boundary, then make it move the opposite direction
        if (ball.y < 0 || ball.y > GameConfigs::GAME_HEIGHT - GameConfigs::BALL_HEIGHT)
            dy *= -1;

        // Keep the sprites in the screen
        keepSpriteInScreen(player);
        keepSpriteInScreen(evil_robot);
        keepSpriteInScreen(ball);

        // Collision detection
        bool player_collision = CheckCollisionRecs(player, ball);
        //bool evil_robot_collision = CheckCollisionRecs(evil_robot, ball);
        bool evil_robot_collision = false;
        if (ball.x > GameConfigs::GAME_WIDTH - 20)
            evil_robot_collision = true;

        // Rebound the ball if colliding with any paddle
        if (player_collision || evil_robot_collision)
        {
            if (player_collision) ball.x = player.x + 5;
            if (evil_robot_collision) ball.x = evil_robot.x - 5;
            dx *= -1;
            dy = dist(gen);
        }

        // Give points and reset if goes beyond boundary
        // If the ball goes behind the player, give point to robot
        if (ball.x < GameConfigs::SPAWN_OFFSET)
        {
            ball.x = (GameConfigs::GAME_WIDTH - GameConfigs::BALL_WIDTH) / 2;
            ball.y = (GameConfigs::GAME_HEIGHT - GameConfigs::BALL_HEIGHT) / 2;
            evil_robot_score += 1;
        }

        // If the ball goes after the robot, give point to the player
        if (ball.x > GameConfigs::GAME_WIDTH - GameConfigs::SPAWN_OFFSET)
        {
            ball.x = (GameConfigs::GAME_WIDTH - GameConfigs::BALL_WIDTH) / 2;
            ball.y = (GameConfigs::GAME_HEIGHT - GameConfigs::BALL_HEIGHT) / 2;
            player_score += 1;
        }
        // Draw
        BeginDrawing();
        ClearBackground(BLACK);

        std::string score_text = std::to_string(player_score) + " | " + std::to_string(evil_robot_score);
        DrawText(score_text.c_str(), GameConfigs::GAME_WIDTH / 2 - 20, 10, 20, WHITE);

        DrawRectangleRec(player, playerColor);
        DrawRectangleRec(evil_robot, evilRobotColor);
        DrawRectangleRec(ball, ballColor);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}