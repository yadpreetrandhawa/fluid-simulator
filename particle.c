#include "particle.h"
#include <stddef.h>

void InitParticle(Particle *p, Vector2 position, float radius) {
    if (p == NULL) return;

    p->position = position;
    p->radius = radius;
    p->elasticity = 0.3f;
    p->color = WHITE;
    p->velocity = (Vector2){ 0.0f, 0.0f };
    p->acceleration = (Vector2){ 0.0f, 0.0f };

    return;
}

void UpdateParticle(Particle *p, float dt) {
    if (p == NULL) return;

    p->velocity.x += p->acceleration.x * dt;
    p->velocity.y += p->acceleration.y * dt;

    p->position.x += p->velocity.x * dt;
    p->position.y += p->velocity.y * dt;

    return;
}

void ResolveWallCollision(Particle *p, int width, int height) {
    if (p == NULL) return;

    if (p->position.x <= p->radius) {
        p->position.x = p->radius;
        if (p->velocity.x < 0.0f) p->velocity.x = -p->velocity.x * p->elasticity;
    } else if (p->position.x >= width - p->radius) {
        p->position.x = width - p->radius;
        if (p->velocity.x > 0.0f) p->velocity.x = -p->velocity.x * p->elasticity;
    }

    if (p->position.y <= p->radius) {
        p->position.y = p->radius;
        if (p->velocity.y < 0.0f) p->velocity.y = -p->velocity.y * p->elasticity;
    } else if (p->position.y >= height - p->radius) {
        p->position.y = height - p->radius;
        if (p->velocity.y > 0.0f) p->velocity.y = -p->velocity.y * p->elasticity;
    }
}

void DrawParticle(const Particle *p) {
    if (p == NULL) return;

    DrawCircleV(p->position, p->radius, p->color);

    return;
}

void ResolveParticleCollision(Particle *a, Particle *b)
{
    if (p == NULL) return;
}
