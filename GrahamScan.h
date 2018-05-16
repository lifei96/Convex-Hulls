//
// Created by Fei Li on 2018/5/16.
//

#ifndef CONVEX_HULLS_GRAHAMSCAN_H
#define CONVEX_HULLS_GRAHAMSCAN_H

#include <stack>
#include <vector>
#include "Point.h"

class GrahamScan {
private:
    static bool yOrder(const Point &a, const Point &b);
    static bool polarOrder(const Point &a, const Point &b);
public:
    std::stack<Point> grahamScan(std::vector<Point> &dataset);
};


#endif //CONVEX_HULLS_GRAHAMSCAN_H
