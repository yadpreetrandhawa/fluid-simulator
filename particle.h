#ifndef PARTICLE_H
#define PARTICLE_H

#include "raylib.h"
#include <stddef.h>

// 2D partical struct
typedef struct {
    Vector2 position;
    Vector2 velocity;
    Vector2 acceleration;
    float radius;
    float elasticity; // 0 = no bounce, 1 = full bounce.
    Color color;
} Particle;

void InitParticle(Particle *p, Vector2 position, float radius);
void UpdateParticle(Particle *p, float dt);
void DrawParticle(const Particle *p);

void ResolveWallCollision(Particle *p, int width, int height);
void ResolveParticleCollision(Particle *a, Particle *b);

#endif
