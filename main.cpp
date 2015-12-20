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

void InitFunctions() {
    glutDisplayFunc(Render);
    glutReshapeFunc(ChangeSize);
    glutKeyboardFunc(Keyboard);
    glutMouseFunc(Mouse);
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    canvas.initCanvas(&argc, argv);

    InitFunctions();

    glutMainLoop();

    return EXIT_SUCCESS;
}
