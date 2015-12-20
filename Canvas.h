#include <vector>
#include <GL/gl.h>
#include <GL/glut.h>
#include "Point.h"
#include "Points.h"

#ifndef TEST_POINTS_H
#define TEST_POINTS_H

using namespace std;

class Canvas {
private:
    int width;
    int height;

    Points points;

    Points getPoints();

    void addInitialPoints();

    void renderLine(Point &p1, Point &p2);
public:

    Canvas();

    void setWidth(int);

    void setHeight(int);

    int getWidth() const;

    int getHeight() const;

    void initCanvas(int *argc, char **argv);

    void render();

    void keyboard(unsigned char key, int x, int y);

    void mouse(int button, int state, int x, int y);

    void changeSize(int w, int h);
};


#endif //TEST_POINTS_H
