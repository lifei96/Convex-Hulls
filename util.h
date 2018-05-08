//
// Created by Fei Li on 2018/5/8.
//

#ifndef CONVEX_HULLS_UTIL_H
#define CONVEX_HULLS_UTIL_H

#include "Point.h"

namespace util {
    double getSqrDist(Point a, Point b);

    double getArea(Point a, Point b, Point c);

    int ccw(Point a, Point b, Point c);
};


#endif //CONVEX_HULLS_UTIL_H
