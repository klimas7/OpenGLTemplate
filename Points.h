#include <vector>
#include <algorithm>
#include "Point.h"

#ifndef OPENGLTEMPLATE_POINTS_H
#define OPENGLTEMPLATE_POINTS_H


class Points {
private:
    std::vector<Point> points;

    void sortPoints();

    Point getPoint(int, int, int, int);
public:
    void addPoint(float, float);

    void addPoint(int, int, int, int);

    void deletePoint(int, int, int, int);

    unsigned int size();

    Point &at(unsigned int i);
};


#endif //OPENGLTEMPLATE_POINTS_H
