// pacman.cpp
#include "../include/pacman.hpp"
#include "../include/sound.hpp"
#include "../include/game.hpp"


Pacman::Pacman() : Cube(Vector(0.0f, 0.0f, 0.0f), Vector(1.3f, 1.3f, 1.3f)) {
    color = new Vector(1.0f, 0.81f, 0.03f);
}

void Pacman::update() {
    Labyrinth &labyrinth = Labyrinth::getInstance();

    if (leewayTimer > 0) {
        leewayTimer --;
        tryTurn();
    } else {
        goalDir = NONE;
    }

    // move
    pos += vel * speed;

    // check collisions
    for (Cube wall : labyrinth.walls) {
        while(overlaps(wall)) {
            pos -= vel * speed;
        }
    }

    auto it = labyrinth.pellets.begin();
    while (it != labyrinth.pellets.end()) {
        if (overlaps(*it)) {
            if (it->flag) {
                score += 50;
                multiplier += 1;
                labyrinth.powerup();
            } else {
                score += 10;
            }
            it = labyrinth.pellets.erase(it);
        } else {
            it ++;
        }
    }

    for (Ghost ghost : labyrinth.ghosts) {
        if (overlaps(ghost)) {
            if (ghost.vulnerable) {
                score += 200 * multiplier;
                ghost.die(200 * multiplier);
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

void Pacman::spawn() {
    pos = Vector(-0.65f, -7.0f, 0.0f);
}

void Pacman::die() {
    Labyrinth::getInstance().restart();
}

void Pacman::tryTurn() {
    Labyrinth &labyrinth = Labyrinth::getInstance();

    switch (goalDir) {
        case NONE:
            break;
        case UP:
            if (!labyrinth.shootRay(Cube(pos, size), UP, 1.0f)) {
                dir = UP;
                vel = Vector(0.0f, 1.0f, 0.0f);
            }
            break;
        case LEFT:
            if (!labyrinth.shootRay(Cube(pos, size), LEFT, 1.0f)) {
                dir = LEFT;
                vel = Vector(-1.0f, 0.0f, 0.0f);
            }
            break;
        case RIGHT:
            if (!labyrinth.shootRay(Cube(pos, size), RIGHT, 1.0f)) {
                dir = RIGHT;
                vel = Vector(1.0f, 0.0f, 0.0f);
            }
            break;
        case DOWN:
            if (!labyrinth.shootRay(Cube(pos, size), DOWN, 1.0)) {
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
