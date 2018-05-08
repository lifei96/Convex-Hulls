//
// Created by Fei Li on 2018/5/8.
//

#ifndef CONVEX_HULLS_UTIL_H
#define CONVEX_HULLS_UTIL_H

#include <vector>
#include <string>
#include "Point.h"

namespace util {
    double getSqrDist(Point a, Point b);

    double getArea(Point a, Point b, Point c);

    int ccw(Point a, Point b, Point c);

    std::vector<Point> readDataset(std::string datasetPath);

    void writeDataset(std::vector<Point> &dataset, std::string datasetPath);

};


#endif //CONVEX_HULLS_UTIL_H
