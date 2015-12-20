#include <iostream>
#include <cmath>
#include "Point.h"

Point::Point(float x, float y) {
    this->x = x;
    this->y = y;

    calculateRandFi(x, y);
}


float Point::getX() {
    return x;
}

float Point::getY() {
    return y;
}

float Point::getR() {
    return r;
}

float Point::getFi() {
    return fi;
}

int Point::operator<(Point point) {
    return this->fi < point.fi;
}

float Point::distance(Point point) {
    return (float)sqrt(pow(point.getX() - getX(),2.0) + pow(point.getY() - getY(),2.0));
}

void Point::calculateRandFi(float x, float y) {
    r = std::sqrt(x * x + y * y);
    if (x != 0) {
        fi = std::atan(y / x);
    }
    else {
        fi = 0.0;
    }
    fi *= 180. / M_PI;
    if (x < 0.)
        fi = 180.f + fi;
};
