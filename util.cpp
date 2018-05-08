//
// Created by Fei Li on 2018/5/8.
//

#include "util.h"

double util::getSqrDist(Point a, Point b) {
    double dx = a.getX() - b.getX();
    double dy = a.getY() - b.getY();
    return dx * dx + dy * dy;
}

double util::getArea(Point a, Point b, Point c) {
    return (b.getX() - a.getX()) * (c.getY() - a.getY()) -
           (b.getY() - a.getY()) * (c.getX() - a.getX());
}

int util::ccw(Point a, Point b, Point c) {
    double area = util::getArea(a, b, c);
    if (area > 0)
        return -1;
    else if (area < 0)
        return 1;
    return 0;
}
