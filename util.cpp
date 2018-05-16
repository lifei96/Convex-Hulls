//
// Created by Fei Li on 2018/5/8.
//

#include <fstream>
#include <iomanip>
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

std::vector<Point> util::readDataset(std::string datasetPath) {
    std::vector<Point> dataset;
    std::ifstream infile;
    infile.open(datasetPath);
    double x, y;
    while (infile >> x >> y) {
        dataset.push_back(Point(x, y));
    }
    infile.close();
    return dataset;
}

void util::writeDataset(std::vector<Point> &dataset, std::string datasetPath) {
    std::ofstream outfile;
    outfile.open(datasetPath);
    for (Point p : dataset) {
        outfile << std::setiosflags(std::ios::fixed) << std::setprecision(6)
                << p.getX() << ' ' << p.getY() << std::endl;
    }
    outfile.close();
}
