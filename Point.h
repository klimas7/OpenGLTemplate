#include <cmath>

#ifndef TEST_POINT_H
#define TEST_POINT_H

class Point {
private:
    //Cartesian coordinate
    float x;
    float y;
    //Polar coordinate
    float r;
    float fi;

    /**
     * Method calculate radius 'r' and angle 'fi' in plar coordinate
     */
    void calculateRandFi(float x, float y);

public:
    Point(float x, float y);

    float getX();

    float getY();

    float getR();

    float getFi();

    /**
     * use to sort points, point is smaller than the other point, if angle 'fi' is smaller
     */
    int operator<(Point);

    /**
     * calculate distance between to points
     */
    float distance(Point);
};


#endif //TEST_POINT_H
