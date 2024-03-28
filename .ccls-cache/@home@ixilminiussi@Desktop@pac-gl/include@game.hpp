// game.hpp
#pragma once

#include "vector.hpp"
#include "pacman.hpp"
#include "ghost.hpp"
#include "cube.hpp"
#include <GL/freeglut.h>

Pacman* pacman;
Cube* walls[54];
Pellet* pellets[246]; // INITIALLY this was a vector, and that would work better for a more adaptable code, but arrays have better performance and there is only one level anyways.
Ghost* ghosts[4];

void populateArea(Vector min, Vector max);

void restart();

void start();

void init();

void update();

void render();

void onKeyInput(unsigned char key, int x, int y);

void display();

void glSettings();

void onReshape(GLsizei width, GLsizei height);
