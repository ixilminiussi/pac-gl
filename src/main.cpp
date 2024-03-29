// main.cpp
#include <vector>
#include <iostream>

#include "game.hpp"
#include "sound.hpp"

constexpr int WIDTH = 900;
constexpr int HEIGHT = 1280;
constexpr int FRAME_TIMER = 16; // ~60fps

static const std::string TITLE   = "Pacman";

void display() {
    Labyrinth& labyrinth = Labyrinth::getInstance();

    labyrinth.render();
    labyrinth.update();
}

void clock(int value) {
    glutPostRedisplay();
    glutTimerFunc(FRAME_TIMER, clock, 0);
}

void onReshape(GLsizei width, GLsizei height) {
    if (height == 0)
        height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void onKeyInput(unsigned char key, int x, int y) {
    Labyrinth& labyrinth = Labyrinth::getInstance();

    switch(key) {
        case 27:
            exit(EXIT_SUCCESS);
            break;
        case 'z':
            labyrinth.onKeyInput(GLUT_KEY_UP);
            break;
        case 'q':
            labyrinth.onKeyInput(GLUT_KEY_LEFT);
            break;
        case 's':
            labyrinth.onKeyInput(GLUT_KEY_DOWN);
            break;
        case 'd':
            labyrinth.onKeyInput(GLUT_KEY_RIGHT);
            break;
    }
}

void onSpecialKeyInput(int key, int x, int y) {
    Labyrinth::getInstance().onKeyInput(key);
}

void glSettings() {
    Labyrinth& labyrinth = Labyrinth::getInstance();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glutKeyboardFunc(onKeyInput);
    glutSpecialFunc(onSpecialKeyInput);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    alutInit();
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(50, 50);
    glutCreateWindow(TITLE.c_str());
    glutDisplayFunc(display);
    glutReshapeFunc(onReshape);
    glSettings();
    Labyrinth::getInstance().init();
    glutTimerFunc(0, clock, 0);
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
    glutMainLoop();
    alutWrapUp();
    return 0;
}
