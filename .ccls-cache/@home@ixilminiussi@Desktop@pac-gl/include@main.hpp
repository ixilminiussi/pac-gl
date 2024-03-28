// main.hpp
#pragma once
#include "./vector.hpp"
#include <GL/freeglut.h>

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
