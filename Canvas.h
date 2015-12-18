#include <vector>
#include <algorithm>
#include <GL/gl.h>
#include <GL/glut.h>
#include "Point.h"

#ifndef TEST_POINTS_H
#define TEST_POINTS_H

using namespace std;

class Canvas {
private:
    int width;
    int height;
    vector<Point> points;

    void sortPoints();
    void renderLine(Point &p1, Point &p2);

public:
    Canvas();

    void addPointD(double, double);
    void addPointI(int, int);
    void deletePoint(int, int);
    Point getPoint(int x, int y) const;
    vector<Point> getPoints();

    void setWidth(int);
    void setHeight(int);
    int getWidth() const;
    int getHeight() const;

    void initCanvas();
    void render();
    void keyboard(unsigned char key, int x, int y);
    void mouse(int button, int state, int x, int y);
    void changeSize(int w, int h);
};


#endif //TEST_POINTS_H
