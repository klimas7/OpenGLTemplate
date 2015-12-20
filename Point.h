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

public:
    Point(float x, float y);
    float getX();
    float getY();
    int operator<(Point);
    float distance(Point);
};


#endif //TEST_POINT_H
