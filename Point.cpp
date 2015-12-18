#include <iostream>
#include <cmath>
#include "Point.h"

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
    r = std::sqrt(x*x + y*y);
    if (x != 0) {
        fi = std::atan(y/x);
    }
    else {
        fi = 0.0;
    }
    fi *= 180./M_PI;
    if (x < 0)
        fi = 180. + fi;
};

double Point::getX() {
    return x;
}

double Point::getY() {
    return y;
}

int Point::operator<(Point point) {
    return this->fi < point.fi;
}

double Point::distance(Point point) {
    return sqrt(pow(point.getX() - getX(),2.0) + pow(point.getY() - getY(),2.0));
}
