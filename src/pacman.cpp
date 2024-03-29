// pacman.cpp
#include "pacman.hpp"
#include "sound.hpp"
#include "game.hpp"

float poweredTime = 1250;
float poweredTimer = 0;

Pacman::Pacman(Vector pos, void (*restart)(void)) : Cube(pos, Vector(1.3f, 1.3f, 1.3f)), restart(restart) {
    color = new Vector(1.0f, 0.81f, 0.03f);
}

void Pacman::update() {
    if (leewayTimer > 0) {
        leewayTimer --;
        tryTurn();
    } else {
        goalDir = NONE;
    }

    // move
    pos = pos.plus(vel.mulBy(speed));

    // check collisions
    for (Cube* wall : walls) {
        while(overlaps(wall)) {
            pos = pos.minus(vel.mulBy(speed));
        }
    }

    for (Pellet* pellet : pellets) {
        if (overlaps(pellet)) {
            char* filePath;
            switch (pellet->pickup()) { // deleting doesnt save much space while making working with the array difficult in other areas of code. true means we are picking up a powerup, false means we are picking up a regular pellet
                case 0:
                    break;
                case 1:
                    score += 10;
                    break;
                case 2:
                    score += 50;
                    multiplier = 1;
                    poweredTimer = poweredTime;
                    for (Ghost* ghost : ghosts) {
                        ghost->vulnerable = true;
                    }
                    break;
            }
        }
    }

    for (Ghost* ghost : ghosts) {
        if (overlaps(ghost)) {
            if (ghost->vulnerable) {
                score += 200 * multiplier;
                ghost->die(200 * multiplier);
                multiplier *= 2;
            } else {
                die();
            }
        }
    }

    // check out of bounds
    if (pos.x + size.x < -11.2f) {
        pos.x = 11.2f;
    } else {
        if (pos.x > 11.2f) {
            pos.x = -11.2f - size.x;
        }
    }
}

void Pacman::die() {
    restart();
}

void Pacman::tryTurn() {
    switch (goalDir) {
        case NONE:
            break;
        case UP:
            if (!shootRay(Cube(pos, size), UP, 1.0f)) {
                dir = UP;
                vel = Vector(0.0f, 1.0f, 0.0f);
            }
            break;
        case LEFT:
            if (!shootRay(Cube(pos, size), LEFT, 1.0f)) {
                dir = LEFT;
                vel = Vector(-1.0f, 0.0f, 0.0f);
            }
            break;
        case RIGHT:
            if (!shootRay(Cube(pos, size), RIGHT, 1.0f)) {
                dir = RIGHT;
                vel = Vector(1.0f, 0.0f, 0.0f);
            }
            break;
        case DOWN:
            if (!shootRay(Cube(pos, size), DOWN, 1.0)) {
                dir = DOWN;
                vel = Vector(0.0f, -1.0f, 0.0f);
            }
            break;
    }
}

void Pacman::goUp() {
    if (dir != UP) {
        goalDir = UP;
        leewayTimer = leewayTime;
    }
}

void Pacman::goLeft() {
    if (dir != LEFT) {
        goalDir = LEFT;
        leewayTimer = leewayTime;
    }
}

void Pacman::goDown() {
    if (dir != DOWN) {
        goalDir = DOWN;
        leewayTimer = leewayTime;
    }
}

void Pacman::goRight() {
    if (dir != RIGHT) {
        goalDir = RIGHT;
        leewayTimer = leewayTime;
    }
}
