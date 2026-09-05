#include "raylib.h"
#include "particle.h"

int main(void)
{
    // initialize
    const int screenWidth = 800;
    const int screenHeight = 450;

    SetConfigFlags(FLAG_MSAA_4X_HINT);

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    Particle ballTest = {};

    Vector2 initPos = {(float) screenWidth / 2.0, (float) screenHeight / 2.0f};

    InitParticle(&ballTest, initPos, 20.0f);

    ballTest.acceleration = (Vector2){1.0f, 2.0f};

    SetTargetFPS(60);

    // main loop
    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        // update
        UpdateParticle(&ballTest, dt);

        // draw
        BeginDrawing();

            ClearBackground(GetColor(0x181818FF));

            DrawParticle(&ballTest);

        EndDrawing();
    }

    // de-initialize
    CloseWindow();

    return 0;
}