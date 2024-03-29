// game.hpp
#if !defined(GAME_HPP)
#define GAME_HPP

#include <GL/freeglut.h>

#include "vector.hpp"
#include "pacman.hpp"
#include "ghost.hpp"
#include "cube.hpp"

extern Pacman* pacman;
extern Cube* walls[54];
extern Pellet* pellets[246]; // INITIALLY this was a vector, and that would work better for a more adaptable code, but arrays have better performance and there is only one level anyways.
extern Ghost* ghosts[4];


void populateArea(Vector min, Vector max);

void restart();

void start();

void init();

void update();

void render();

void onKeyInput(unsigned char key, int x, int y);

void onSpecialKeyInput(int key, int x, int y);

void display();

void glSettings();

void onReshape(GLsizei width, GLsizei height);

void checkWin();

#endif
