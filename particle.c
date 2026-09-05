#include "particle.h"
#include <stddef.h>

void InitParticle(Particle *p, Vector2 position, float radius) {
    if (p == NULL) return;

    p->position = position;
    p->radius = radius;
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

void DrawParticle(const Particle *p) {
    if (p == NULL) return;

    DrawCircleV(p->position, p->radius, p->color);

    return;
}