#include <iostream>
#include <cmath>
#include "Point.h"

Point::Point(float x, float y) {
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
    if (x < 0.)
        fi = 180.f + fi;
};

float Point::getX() {
    return x;
}

float Point::getY() {
    return y;
}

int Point::operator<(Point point) {
    return this->fi < point.fi;
}

float Point::distance(Point point) {
    return (float)sqrt(pow(point.getX() - getX(),2.0) + pow(point.getY() - getY(),2.0));
}
