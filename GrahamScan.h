//
// Created by Fei Li on 2018/5/16.
//

#ifndef CONVEX_HULLS_GRAHAMSCAN_H
#define CONVEX_HULLS_GRAHAMSCAN_H

#include <stack>
#include <vector>
#include "Point.h"
#include "util.h"

class GrahamScan {
private:
    class yOrder {
    public:
        yOrder() {}

        bool operator()(const Point &a, const Point &b) {
            return a.getY() < b.getY() ||
                   (a.getY() == b.getY() && a.getX() < b.getX());
        }
    };

    class polarOrder {
    private:
        Point O;
    public:
        polarOrder(Point O) : O(O) {}

        bool operator()(const Point &a, const Point &b) {
            int order = util::ccw(O, a, b);
            if (order == 0)
                return util::getSqrDist(O, a) <
                       util::getSqrDist(O, b);
            return (order == -1);
        }
    };

public:
    std::stack<Point> grahamScan(std::vector<Point> &dataset);
};


#endif //CONVEX_HULLS_GRAHAMSCAN_H
