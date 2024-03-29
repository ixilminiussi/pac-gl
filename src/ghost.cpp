// ghost.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>

#include "ghost.hpp"
#include "game.hpp"
#include "wait.hpp"
#include "sound.hpp"

Ghost::Ghost(Vector pos, Vector* color, float iq) : Cube(pos, Vector(1.4f, 1.4f, 1.4f)), iq(iq) {
    Cube::color = color;
    regularColor = color;
    altColor = new Vector(0.13f, 0.13f, 1.0f);

    turn(RIGHT);
};

void Ghost::die(int score) {
    deadFrame = score;
    ::render();
    respawn();
    wait(1000);
}

void Ghost::respawn() {
    deadFrame = 0;
    pos = respawnPos;
    vulnerable = false;
}

void Ghost::update() {
    if (leewayTimer > 0) leewayTimer --;

    if (leewayTimer == 0 && atIntersection()) {
        leewayTimer = leewayTime;
        turn(pickDirection());
    }

    pos = pos.plus(vel.mulBy(speed));

    if (!vulnerable) {
        color = regularColor;
    } else {
        color = altColor;
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

void Ghost::render() {
    if (deadFrame == 0) {
        Cube::render();
    } else {
        glPushMatrix();
        glDepthFunc(GL_ALWAYS);
        glTranslatef(pos.x, pos.y + 0.2f, 1.41f);
        glScalef(0.006f, 0.006f, 1.0f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glLineWidth(5.0f);
        glutStrokeString(GLUT_STROKE_ROMAN, (const unsigned char*)(std::to_string(deadFrame)).c_str());
        glDepthFunc(GL_LEQUAL);
        glPopMatrix();
    }
}

bool Ghost::atIntersection() {
    if (shootRay(Cube(pos, size), dir, 0.1f)) { // impasse
        return true;
    }

    std::pair<DIRECTION, DIRECTION> sides = getSides(dir);
    if (!shootRay(Cube(pos, size), sides.first, 1.0f) || !shootRay(Cube(pos, size), sides.second, 1.0f)) {
        return true;
    }

    return false;
}

DIRECTION Ghost::pickDirection() {
    std::vector<DIRECTION> possibilities = { UP, LEFT, RIGHT, DOWN };

    // remove all obstructed directions;
    for (int i = 3; i > -1; i --) {
        if (shootRay(Cube(pos, size), possibilities[i], 1.0f)) {
            possibilities.erase(possibilities.begin() + i);
        }
    }

    // if we have more than one direction left, remove backtracking
    if (possibilities.size() > 1) {
        possibilities.erase(std::find(possibilities.begin(), possibilities.end(), getOpposite(dir)));
    }

    auto calcDistance = [&](DIRECTION dir1) {
        Vector newPos = Vector(pos.x, pos.y, pos.z);
        switch(dir1) {
            case UP:
                newPos.y += 1.0f;
                break;
            case DOWN:
                newPos.y -= 1.0f;
                break;
            case LEFT:
                newPos.x -= 1.0f;
                break;
            case RIGHT:
                newPos.x += 1.0f;
                break;
            case NONE:
                return 0.0f;
        }
        return ((newPos.x - pacman->pos.x) * (newPos.x - pacman->pos.x) + (newPos.y - pacman->pos.y) * (newPos.y - pacman->pos.y));
    };

    // if we only have one element, everything next is meaningless
    if (possibilities.size() == 1) {
        return *possibilities.begin();
    }

    // sorting in order of best to worst
    if (!vulnerable) { 
        sort(possibilities.begin(), possibilities.end(), [&](DIRECTION dir1, DIRECTION dir2) { return calcDistance(dir1) < calcDistance(dir2); });
    } else {
        sort(possibilities.begin(), possibilities.end(), [&](DIRECTION dir1, DIRECTION dir2) { return calcDistance(dir1) > calcDistance(dir2); });
        return possibilities[0];
    }

    // finally we coin toss, if we win, we return the best choice, if not, we return randomly from the remaining options
    std::srand(std::time(nullptr));
    float diceRoll = (double)rand() / RAND_MAX;
    if (diceRoll < iq) {
        return possibilities[0];
    } else {
        std::srand(std::time(nullptr));
        diceRoll = floor((rand() / RAND_MAX) * possibilities.size());
        return possibilities[diceRoll + 1];
    }
}

void Ghost::turn(DIRECTION newDir) {
    dir = newDir;
    switch(newDir) {
        case UP:
            vel = Vector(0.0f, 1.0f, 0.0f);
            break;
        case DOWN:
            vel = Vector(0.0f, -1.0f, 0.0f);
            break;
        case LEFT:
            vel = Vector(-1.0f, 0.0f, 0.0f);
            break;
        case RIGHT:
            vel = Vector(1.0f, 0.0f, 0.0f);
            break;
        default:
            break;
    }
}
