//
// Created by Fei Li on 2018/5/16.
//

#include "GrahamScan.h"
#include "util.h"

bool GrahamScan::yOrder(const Point &a, const Point &b) {
    return a.getY() < b.getY() || (a.getY() == b.getY() && a.getX() < b.getX());
}

bool GrahamScan::polarOrder(const Point &a, const Point &b) {
    int order = util::ccw(Point(0.0, 0.0), a, b);
    if (order == 0)
        return util::getSqrDist(Point(0.0, 0.0), a) <
               util::getSqrDist(Point(0.0, 0.0), b);
    return (order == -1);
}

std::stack<Point> GrahamScan::grahamScan(std::vector<Point> &dataset) {
    std::stack<Point> S;
    std::sort(dataset.begin(), dataset.end(), yOrder);
    sort(dataset.begin() + 1, dataset.end(), polarOrder);
    S.push(dataset[0]);
    S.push(dataset[1]);
    S.push(dataset[2]);
    for (int i = 3; i < dataset.size(); ++i) {
        Point top = S.top();
        S.pop();
        while (S.size() && util::ccw(S.top(), top, dataset[i]) != -1) {
            top = S.top();
            S.pop();
        }
        S.push(top);
        S.push(dataset[i]);
    }
    return S;
}
