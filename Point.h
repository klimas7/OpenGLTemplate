#ifndef TEST_POINT_H
#define TEST_POINT_H


class Point {
private:
    //Cartesian coordinate
    double x;
    double y;
    //Polar coordinate
    double r;
    double fi;

public:
    Point(double x, double y);
    double getX();
    double getY();
    int operator<(Point);
    double distance(Point);
};


#endif //TEST_POINT_H
