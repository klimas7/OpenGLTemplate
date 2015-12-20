#include <GL/glut.h>
#include "Canvas.h"

Canvas canvas;

/**
 * Render method, delegates responsibility to Canvas
 */
void Render() {
    canvas.render();
}

/**
 * ChangeSize window method, delegates responsibility to Canvas
 */
void ChangeSize(int w, int h) {
    canvas.changeSize(w, h);
}

/**
 * Keyboard support method, delegates responsibility to Canvas
 */
void Keyboard(unsigned char key, int x, int y) {
    canvas.keyboard(key, x, y);
}

/**
 * Mouse support method, delegates responsibility to Canvas
 */
void Mouse(int button, int state, int x, int y) {
    canvas.mouse(button, state, x, y);
}

/**
 * Initialize glut functions
 */
void InitFunctions() {
    glutDisplayFunc(Render);
    glutReshapeFunc(ChangeSize);
    glutKeyboardFunc(Keyboard);
    glutMouseFunc(Mouse);
}

/**
 * Main method
 */
int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    canvas.initCanvas(&argc, argv);

    InitFunctions();

    glutMainLoop();

    return EXIT_SUCCESS;
}
