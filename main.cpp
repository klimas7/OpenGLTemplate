#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include "Canvas.h"

using namespace std;

Canvas canvas;

void Render() {
    canvas.render();
}

void ChangeSize(int w, int h) {
    canvas.changeSize(w, h);
}

void Keyboard(unsigned char key, int x, int y) {
    canvas.keyboard(key, x, y);
}

void Mouse(int button, int state, int x, int y) {
    canvas.mouse(button, state, x, y);
}

void Init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);

    glutPositionWindow(120, 120);
    glutReshapeWindow(canvas.getWidth(), canvas.getHeight());

    glutDisplayFunc(Render);
    glutReshapeFunc(ChangeSize);
    glutKeyboardFunc(Keyboard);
    glutMouseFunc(Mouse);
}

int main(int argc, char *argv[]) {
    canvas.initCanvas();

    glutInit(&argc, argv);

    glutInitWindowSize(canvas.getWidth(), canvas.getHeight());

    glutInitDisplayMode(GLUT_DOUBLE);
    glutCreateWindow("OpenGL Template");
    Init();

    glutMainLoop();
    return EXIT_SUCCESS;
}
