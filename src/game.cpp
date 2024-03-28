// game.cpp
#pragma once

#include "../include/game.hpp"
#include "ghost.cpp"
#include <iostream>

const float depth = -30.0f;

unsigned int score = 0;

int lives = 3;

unsigned int wallIndex = 0; // used to populate walls
unsigned int pelletIndex = 0; // used to populate pellets

/**
 * creates pellets at regular intervals and removes those that collide with a wall
 */
void populateArea(Vector min, Vector max) {
    auto overlapsWorld = [](Pellet* pellet) {
        for (Cube* wall : walls) {
            if (pellet->overlaps(wall)) {
                return true;
            }
        }
        // first 4 are powerups
        for (int i = 0; i < 4; i ++) {
            if (pellet->overlaps(pellets[i])) {
                return true;
            }
        }
        return false;
    };

    for (float x = min.x; x < max.x; x += 0.8f) {
        for (float y = min.y; y < max.y; y += 0.8f) {
            Pellet* pellet = new Pellet(Vector(x, y, 0.0f));

            if (!overlapsWorld(pellet)) {
                pellets[pelletIndex++] = pellet;
            }
        }
    }
}

void restart() {
    lives --;

    if (lives == 0) {
        exit(1);
    }

    Ghost* dumbGhost = new Ghost(Vector(0.0f, 0.0f, -1000.0f), new Vector(0.0f, 0.0f, 0.0f), 0.0f);
    for (Ghost* ghost : ghosts) {
        ghost = dumbGhost;
    }

    render();
    wait(1000);

    start();
};

void start() {
    pacman = new Pacman(Vector(-0.65f, -7.0f, 0.0f), &restart);
    ghosts[0] = new Ghost(Vector(-0.7f, -2.3f, 0.0f), new Vector(1.0f, 0.0f, 0.0f), 0.80f);
    ghosts[1] = new Ghost(Vector(-0.7f, -0.1f, 0.0f), new Vector(1.0f, 0.72f, 0.28f), 0.60f);
    ghosts[2] = new Ghost(Vector(-2.2f, -0.1f, 0.0f), new Vector(1.0f, 0.72f, 0.87f), 0.40f);
    ghosts[3] = new Ghost(Vector(0.8f, -0.1f, 0.0f), new Vector(0.0f, 1.0f, 0.87f), 0.20f);
}

void init() {
    // create walls
    walls[wallIndex++] = new Cube(Vector(-11.2f, 12.0f,  0.0f), Vector(22.4f, 0.4f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(-0.4f,  8.8f,   0.0f), Vector(0.8f,  3.2f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(10.8f,  4.8f,   0.0f), Vector(0.4f,  7.3f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(-11.2f, 4.8f,   0.0f), Vector(0.4f,  7.2f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(-9.2f,  8.8f,   0.0f), Vector(2.4f,  1.6f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(-5.2f,  8.8f,   0.0f), Vector(3.2f,  1.6f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(2.0f,   8.8f,   0.0f), Vector(3.2f,  1.6f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(6.8f,   8.8f,   0.0f), Vector(2.4f,  1.6f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(-9.2f,  6.4f,   0.0f), Vector(2.4f,  0.8f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(-5.2f,  1.6f,   0.0f), Vector(0.8f,  5.6f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(-2.8f,  6.4f,   0.0f), Vector(5.6f,  0.8f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(4.4f,   1.6f,   0.0f), Vector(0.8f,  5.6f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(6.8f,   6.4f,   0.0f), Vector(2.4f,  0.8f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(-0.4f,  4.0f,   0.0f), Vector(0.8f,  2.4f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(-11.2f, 4.4f,   0.0f), Vector(4.4f,  0.4f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(-4.4f,  4.0f,   0.0f), Vector(2.4f,  0.8f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(2.0f,   4.0f,   0.0f), Vector(2.4f,  0.8f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(6.8f,   4.4f,   0.0f), Vector(4.4f,  0.4f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(-7.2f,  2.0f,   0.0f), Vector(0.4f,  2.4f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(6.8f,   2.0f,   0.0f), Vector(0.4f,  2.4f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(-13.2f, 1.6f,   0.0f), Vector(6.4f,  0.4f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(6.8f,   1.6f,   0.0f), Vector(6.4f,  0.4f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(-13.2f, -0.4f,  0.0f), Vector(6.4f,  0.4f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(-5.2f,  -3.2f,  0.0f), Vector(0.8f,  3.2f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(4.4f,   -3.2f,  0.0f), Vector(0.8f,  3.2f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(6.8f,   -0.4f,  0.0f), Vector(6.4f,  0.4f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(-7.2f,  -2.8f,  0.0f), Vector(0.4f,  2.4f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(6.8f,   -2.8f,  0.0f), Vector(0.4f,  2.4f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(-11.2f, -3.2f,  0.0f), Vector(4.4f,  0.4f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(-2.8f,  -3.2f,  0.0f), Vector(5.6f,  0.8f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(6.8f,   -3.2f,  0.0f), Vector(4.4f,  0.4f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(-11.2f, -12.0f, 0.0f), Vector(0.4f,  8.8f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(-0.4f,  -5.6f,  0.0f), Vector(0.8f,  2.4f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(10.8f,  -12.0f, 0.0f), Vector(0.4f,  8.8f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(-9.2f,  -5.6f,  0.0f), Vector(2.4f,  0.8f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(-5.2f,  -5.6f,  0.0f), Vector(3.2f,  0.8f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(2.0f,   -5.6f,  0.0f), Vector(3.2f,  0.8f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(6.8f,   -5.6f,  0.0f), Vector(2.4f,  0.8f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(-7.6f,  -8.0f,  0.0f), Vector(0.8f,  2.4f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(6.8f,   -8.0f,  0.0f), Vector(0.8f,  2.4f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(-10.8f, -8.0f,  0.0f), Vector(1.6f,  0.8f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(-5.2f,  -9.6f,  0.0f), Vector(0.8f,  2.4f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(-2.8f,  -8.0f,  0.0f), Vector(5.6f,  0.8f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(4.4f,   -9.6f,  0.0f), Vector(0.8f,  2.4f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(9.2f,   -8.0f,  0.0f), Vector(1.6f,  0.8f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(-0.4f,  -10.4f, 0.0f), Vector(0.8f,  2.4f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(-9.2f,  -10.4f, 0.0f), Vector(7.2f,  0.8f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(2.0f,   -10.4f, 0.0f), Vector(7.2f,  0.8f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(-11.2f, -12.4f, 0.0f), Vector(22.4f, 0.4f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(-2.8f,  -0.8f,  0.0f), Vector(5.6f,  0.4f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(-2.8f,  -0.6f,  0.0f), Vector(0.4f,  2.4f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(2.4f,   -0.6f,  0.0f), Vector(0.4f,  2.4f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(-2.8f,  1.8f,   0.0f), Vector(2.0f,  0.4f, 2.0f));
    walls[wallIndex++] = new Cube(Vector(0.8f,   1.8f,   0.0f), Vector(2.0f,  0.4f, 2.0f));

    // create powerups
    pellets[pelletIndex++] = new PowerUp(Vector(9.6f,   -6.8f, 0.0f));
    pellets[pelletIndex++] = new PowerUp(Vector(-10.4f, -6.8f, 0.0f));
    pellets[pelletIndex++] = new PowerUp(Vector(9.6f,   9.2f,  0.0f));
    pellets[pelletIndex++] = new PowerUp(Vector(-10.4f, 9.2f,  0.0f));

    // create other pellets
    populateArea(Vector(-10.1f, -11.3f, 0.0f), Vector(10.1f, -3.9f, 0.0f));
    populateArea(Vector(-10.1f, 5.5f, 0.0f), Vector(10.1f, 11.3f, 0.0f));
    populateArea(Vector(-6.1f, -3.3f, 0.0f), Vector(-5.9f, 4.9f, 0.0f));
    populateArea(Vector(5.9f, -3.3f, 0.0f), Vector(6.1f, 4.9f, 0.0f));

    start();
}

void update() {
    if (poweredTimer > 0) {
        poweredTimer --;
        if (poweredTimer == 0) {
            for (Ghost* ghost : ghosts) {
                ghost->vulnerable = false;
            }
        }
    }
    pacman->update();

    for (Ghost* ghost : ghosts) {
        ghost->update();
    }
}

void render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glTranslatef(0.0f, 0.0f, depth);
    glScalef(0.7f, 0.7f, 0.7f);
    pacman->render();

    for (Cube* wall : walls) {
        wall->render();
    }

    for (Pellet* pellet : pellets) {
        if (pellet != nullptr) pellet->render();
    }

    for (Ghost* ghost : ghosts) {
        ghost->render();
    }

    //HUD
    glTranslatef(0.0f, 0.0f, 10.0f);
    //black bars on the side in case of window resize, just to hide some of the magic
    glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-15.0f, 15.0f);
    glVertex2f(-9.0f, 15.0f);
    glVertex2f(-9.0f, -15.0f);
    glVertex2f(-15.0f, -15.0f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(15.0f, 15.0f);
    glVertex2f(9.0f, 15.0f);
    glVertex2f(9.0f, -15.0f);
    glVertex2f(15.0f, -15.0f);
    glEnd();

    //TOP bar
    glPushMatrix();
    glTranslatef(-6.0f, 11.0f, 0.0f);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glScalef(0.01f, 0.01f, 1.0f);
    glLineWidth(10.0f);
    glutStrokeString(GLUT_STROKE_ROMAN, (const unsigned char*)("Score: " + std::to_string(pacman->score)).c_str());
    glPopMatrix();

    //BOTTOM bar
    glTranslatef(7.0f, -12.0f, 0.0f);
    glColor4f(1.0f, 0.81f, 0.03f, 1.0f);
    for (int i = 0; i < lives; i ++) {
        glBegin(GL_QUADS);
        glVertex2f(0.0f - (i * 2), 1.0f);
        glVertex2f(1.0f - (i * 2), 1.0f);
        glVertex2f(1.0f - (i * 2), 0.0f);
        glVertex2f(0.0f - (i * 2), 0.0f);
        glEnd();
    }

    glPopMatrix();
    glutSwapBuffers();
}

void onKeyInput(unsigned char key, int x, int y) {
    switch(key) {
        case 27: // ESC
            exit(0);
            break;
        case 'w':
            pacman->goUp();
            break;
        case 'a':
            pacman->goLeft();
            break;
        case 's':
            pacman->goDown();
            break;
        case 'd':
            pacman->goRight();
            break;
    }
}
