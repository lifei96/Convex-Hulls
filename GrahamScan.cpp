//
// Created by Fei Li on 2018/5/16.
//

#include "GrahamScan.h"

std::stack<Point> GrahamScan::grahamScan(std::vector<Point> &dataset) {
    std::stack<Point> S;
    std::sort(dataset.begin(), dataset.end(), GrahamScan::yOrder());
    sort(dataset.begin() + 1, dataset.end(),
         GrahamScan::polarOrder(dataset[0]));
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
