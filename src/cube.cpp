// cube.cpp
#include <GL/freeglut.h>
#include <vector>

#include "cube.hpp"
#include "game.hpp"

Vector* wallColor = new Vector(0.0f, 0.0f, 1.0f);

Cube::Cube(Vector const& pos, Vector const& size) : pos(pos), size(size) {
    color = wallColor;
};

// render
void Cube::render() const {
    Vector min = pos;
    Vector max = pos + size;
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

bool Cube::overlaps(Cube const& cube) const {
    // assumes 2d world, omitting z axis from collision
    return (
            pos.x < cube.pos.x + cube.size.x &&
            pos.x + size.x > cube.pos.x &&
            pos.y < cube.pos.y + cube.size.y &&
            pos.y + size.y > cube.pos.y
            );
}

Vector pelletColor = Vector(1.0f, 0.72f, 0.59f);

Pellet::Pellet(Vector const& pos, unsigned int flag) : Cube(pos, Vector(0.2f, 0.2f, 0.2f)), flag(flag) {
    color = &pelletColor;
    if (flag) {
        size = Vector(0.8f, 0.8f, 0.8f);
    }
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
