#include "raylib.h"
#include "particle.h"
#include <stdlib.h>
#include <time.h>

enum { PARTICLE_COUNT = 35 };

int randInt(int min, int max);

int main(void)
{
    // initialize
    srand((unsigned int)time(NULL));

    const int screenWidth = 800;
    const int screenHeight = 450;

    // Small initial drift (pixels/s), with no sideways acceleration.
    int minV = -10;
    int maxV = 10;
    int minA = 0;
    int maxA = 0;
    const float gravity = 400.0f; // Downward acceleration in pixels/s^2.

    int radius = 5;

    SetConfigFlags(FLAG_MSAA_4X_HINT);

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    Particle particles[PARTICLE_COUNT] = {0};

    for (int i = 0; i < PARTICLE_COUNT; i++)
    {
        Vector2 initPos = {
            (float)randInt(radius, screenWidth - radius),
            (float)randInt(radius, screenHeight - radius)
        };
        InitParticle(&particles[i], initPos, (float)radius);
        particles[i].velocity = (Vector2){randInt(minV, maxV), randInt(minV, maxV)};
        particles[i].acceleration = (Vector2){randInt(minA, maxA), gravity};
    }

    SetTargetFPS(60);

    // main loop
    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        // update
        for (int i = 0; i < PARTICLE_COUNT; i++)
        {
            UpdateParticle(&particles[i], dt);
            ResolveWallCollision(&particles[i], screenWidth, screenHeight);
        }

        // draw
        BeginDrawing();

            ClearBackground(GetColor(0x181818FF));

            for (int i = 0; i < PARTICLE_COUNT; i++)
            {
                DrawParticle(&particles[i]);
            }

        EndDrawing();
    }

    // de-initialize
    CloseWindow();

    return 0;
}

int randInt(int min, int max)
{
    return (min + (rand() % (max - min + 1)));
}
