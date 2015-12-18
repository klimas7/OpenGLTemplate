#include "Canvas.h"

void InitCanvas();

Canvas::Canvas() { }

void Canvas::addPointD(double x, double y) {
    points.push_back(Point(x, y));
    sortPoints();
}

void Canvas::sortPoints() {
    sort(points.begin(), points.end());
}

vector<Point> Canvas::getPoints() {
    return points;
}

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

void Canvas::addPointI(int x, int y) {
    if (x <= 0 || y <= 0 || x >= width || y >= height)
        return;

    points.push_back(getPoint(x, y));
    sortPoints();
}

void Canvas::deletePoint(int x, int y) {
    if (points.size() <= 2)
        return;

    Point p = getPoint(x, y);

    int nearestPoint = 0;
    double minimalDistance = 2.0 * sqrt(2.0);

    for (int i = 0; i < points.size(); i++) {
        double distance = points.at(i).distance(p);
        if (distance < minimalDistance) {
            nearestPoint = i;
            minimalDistance = distance;
        }
    }
    points.erase(points.begin() + nearestPoint);
}

Point Canvas::getPoint(int x, int y) const {
    return Point(((double) x / (double) width) * 2. - 1., 1. - ((double) y / (double) height) * 2.);
}

void Canvas::initCanvas() {
    setWidth(1000);
    setHeight(1000);
    //Same initial Points
    addPointD(0.5, 0.5);
    addPointD(0.5, -0.5);
    addPointD(-0.5, -0.5);
    addPointD(-0.5, 0.5);
}

void Canvas::render() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    unsigned long pointsSize = getPoints().size();
    if (pointsSize < 2) {
        return;
    }

    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_LINES);

    for (int i = 0; i < pointsSize - 1; i++) {
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
        addPointI(x, y);
    }
    if (key == 'd') {
        deletePoint(x, y);
    }
    if (key == 27) {
        exit(EXIT_SUCCESS);
    }
    render();
}

void Canvas::mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        addPointI(x, y);
        render();
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        deletePoint(x, y);
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
