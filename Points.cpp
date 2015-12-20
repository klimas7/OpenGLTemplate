#include "Points.h"

void Points::addPoint(float x, float y) {
    points.push_back(Point(x, y));
    sortPoints();
}

void Points::addPoint(int x, int y, int width, int height) {
    if (x <= 0 || y <= 0 || x >= width || y >= height)
        return;

    points.push_back(getPoint(x, y, width, height));
    sortPoints();
}

void Points::sortPoints() {
    sort(points.begin(), points.end());
}

Point Points::getPoint(int x, int y, int width, int height) {
    return Point(((float) x / (float) width) * 2.f - 1.f, 1.f - ((float) y / (float) height) * 2.f);;
}

void Points::deletePoint(int x, int y, int width, int height) {
    if (points.size() <= 2)
        return;

    Point p = getPoint(x, y, width, height);

    int nearestPoint = 0;
    double minimalDistance = 2.0 * sqrt(2.0);

    for (unsigned int i = 0; i < points.size(); i++) {
        double distance = points.at(i).distance(p);
        if (distance < minimalDistance) {
            nearestPoint = i;
            minimalDistance = distance;
        }
    }
    points.erase(points.begin() + nearestPoint);
}

unsigned int Points::size() {
    return points.size();
}

Point &Points::at(unsigned int i) {
    return points.at(i);
}
