#include "Canvas.h"

Canvas::Canvas() { }

void Canvas::setWidth(int width) {
    this->width = width;
}

int Canvas::getWidth() const {
    return width;
}

void Canvas::setHeight(int height) {
    this->height = height;
}

int Canvas::getHeight() const {
    return height;
}

Points Canvas::getPoints() {
    return points;
}

void Canvas::initCanvas(int *argc, char **argv) {
    setWidth(1000);
    setHeight(1000);

    glutInitWindowSize(getWidth(), getHeight());

    glutInitDisplayMode(GLUT_DOUBLE);
    glutCreateWindow("OpenGL Template");
    glutPositionWindow(120, 120);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);

    addInitialPoints();
}

void Canvas::addInitialPoints() {
    //Same initial Points
    points.addPoint(0.5f, 0.5f);
    points.addPoint(0.5f, -0.5f);
    points.addPoint(-0.5f, -0.5f);
    points.addPoint(-0.5f, 0.5f);
}

void Canvas::render() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    unsigned long pointsSize = getPoints().size();
    if (pointsSize < 2) {
        return;
    }

    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_LINES);

    for (unsigned int i = 0; i < pointsSize - 1; i++) {
        renderLine(getPoints().at(i), getPoints().at(i + 1));
    }
    renderLine(getPoints().at(pointsSize - 1), getPoints().at(0));

    glEnd();
    glutSwapBuffers();
}

void Canvas::renderLine(Point &p1, Point &p2) {
    glVertex2f(p1.getX(), p1.getY());
    glVertex2f(p2.getX(), p2.getY());
}

void Canvas::keyboard(unsigned char key, int x, int y) {
    if (key == 'a') {
        points.addPoint(x, y, width, height);
    }
    if (key == 'd') {
        points.deletePoint(x, y, width, height);
    }
    if (key == 27) {
        exit(EXIT_SUCCESS);
    }
    render();
}

void Canvas::mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        points.addPoint(x, y, width, height);
        render();
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        points.deletePoint(x, y, width, height);
        render();
    }
}

void Canvas::changeSize(int w, int h) {
    setWidth(w);
    setHeight(h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, w, h);
}
