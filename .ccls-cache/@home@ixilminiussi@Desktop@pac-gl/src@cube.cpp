// cube.cpp
#pragma once

#include "../include/cube.hpp"
#include <GL/freeglut.h>
#include <vector>

Vector wallColor = Vector(0.0f, 0.0f, 1.0f);

Cube::Cube(Vector pos, Vector size) : pos(pos), size(size) {
    color = &wallColor;
};

// render
void Cube::render() {
    Vector min = pos;
    Vector max = pos.plus(size);
    glBegin(GL_QUADS);
    glColor3f(color->x, color->y, color->z);
    glVertex3f(max.x, max.y, min.z);
    glVertex3f(min.x, max.y, min.z);
    glVertex3f(min.x, max.y, max.z);
    glVertex3f(max.x, max.y, max.z);

    glVertex3f(max.x, min.y, max.z);
    glVertex3f(min.x, min.y, max.z);
    glVertex3f(min.x, min.y, min.z);
    glVertex3f(max.x, min.y, min.z);

    glVertex3f(max.x, max.y, max.z);
    glVertex3f(min.x, max.y, max.z);
    glVertex3f(min.x, min.y, max.z);
    glVertex3f(max.x, min.y, max.z);

    glVertex3f(max.x, min.y, min.z);
    glVertex3f(min.x, min.y, min.z);
    glVertex3f(min.x, max.y, min.z);
    glVertex3f(max.x, max.y, min.z);

    glVertex3f(min.x, max.y, max.z);
    glVertex3f(min.x, max.y, min.z);
    glVertex3f(min.x, min.y, min.z);
    glVertex3f(min.x, min.y, max.z);

    glVertex3f(max.x, max.y, min.z);
    glVertex3f(max.x, max.y, max.z);
    glVertex3f(max.x, min.y, max.z);
    glVertex3f(max.x, min.y, min.z);
    glEnd();
}

bool Cube::overlaps(Cube *cube) {
    // assumes 2d world, omitting z axis from collision
    return (
            pos.x < cube->pos.x + cube->size.x &&
            pos.x + size.x > cube->pos.x &&
            pos.y < cube->pos.y + cube->size.y &&
            pos.y + size.y > cube->pos.y
            );
}

Vector pelletColor = Vector(1.0f, 0.72f, 0.59f);

Pellet::Pellet(Vector pos) : Cube(pos, Vector(0.2f, 0.2f, 0.2f)) {
    color = &pelletColor;
}

void Pellet::render() {
    if (!picked) {
        Cube::render();
    }
}

int Pellet::pickup() {
    if (picked) return 0;

    picked = true;
    return 1;
}

PowerUp::PowerUp(Vector pos) : Pellet(pos) {
    size = Vector(0.8f, 0.8f, 0.8f);
}

int PowerUp::pickup() {
    if (picked) return 0;

    picked = true;
    return 2;
}

bool shootRay(Cube rayCube, DIRECTION dir, float dist) {
    switch(dir) {
        case NONE:
            return false;
            break;
        case UP:
            rayCube.pos.y += dist;
            break;
        case LEFT:
            rayCube.pos.x -= dist;
            rayCube.size.x += dist;
            break;
        case RIGHT:
            rayCube.size.x += dist;
            break;
        case DOWN:
            rayCube.pos.y -= dist;
            rayCube.size.y += dist;
            break;
    }

    for (Cube* wall : walls) {
        if (rayCube.overlaps(wall)) {
            return true;
        }
    }

    return false;
}

DIRECTION getOpposite(DIRECTION dir) {
    switch(dir) {
        case UP:
            return DOWN;
            break;
        case DOWN:
            return UP;
            break;
        case LEFT:
            return RIGHT;
            break;
        case RIGHT:
            return LEFT;
            break;
        default:
            return NONE;
            break;
    }
}

std::pair<DIRECTION, DIRECTION> getSides(DIRECTION dir) {
    if (dir == UP || dir == DOWN) {
        return std::pair<DIRECTION, DIRECTION>(LEFT, RIGHT);
    } else {
        return std::pair<DIRECTION, DIRECTION>(UP, DOWN);
    }
}
