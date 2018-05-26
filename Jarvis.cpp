//
// Created by Fei Li on 2018/5/26.
//

#include "Jarvis.h"
#include "util.h"

std::vector<Point> Jarvis::jarvis(std::vector<Point> &dataset) {
    std::vector<int> pos;
    int pointOnHull = 0;
    for (int i = 1; i < dataset.size(); i++) {
        if (dataset[i].getX() < dataset[pointOnHull].getX()) {
            pointOnHull = i;
        }
    }
    do {
        pos.push_back(pointOnHull);
        int endpoint = 0;
        for (int i = 1; i < dataset.size(); i++) {
            if (endpoint == pointOnHull || util::ccw(dataset[pointOnHull], dataset[i], dataset[endpoint]) == 1) {
                endpoint = i;
            }
        }
        pointOnHull = endpoint;
    } while (pointOnHull != pos[0]);
    std::vector<Point> CH;
    for (auto i = pos.begin(); i != pos.end(); i++) {
        CH.push_back(dataset[*i]);
    }
    return CH;
}