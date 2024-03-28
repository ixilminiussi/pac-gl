// main.cpp
#include "./game.cpp"
#include "./pacman.cpp"
#include "./cube.cpp"
#include <vector>

#define WIDTH 900
#define HEIGHT 1280
#define TITLE "Pacman"
#define FRAME_TIMER 16 // ~60fps

void display() {
    update();
    render();
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

void glSettings() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glutKeyboardFunc(onKeyInput);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(50, 50);
    glutCreateWindow(TITLE);
    glutDisplayFunc(display);
    glutReshapeFunc(onReshape);
    glSettings();
    init();
    glutTimerFunc(0, clock, 0);
    glutMainLoop();
    return 0;
}
