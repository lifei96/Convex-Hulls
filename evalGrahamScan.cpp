//
// Created by Fei Li on 2018/5/16.
//

#include "GrahamScan.h"
#include "util.h"
#include "Timer.h"
#include <iostream>

int main() {
    GrahamScan grahamScan;
    int num = 100000;
    Timer timer;
    std::vector<Point> dataset = util::readDataset(
            "dataset/circle_" + std::to_string(num) + ".txt");
    timer.start();
    grahamScan.grahamScan(dataset);
    timer.stop();
    std::cout << timer.getDuration() << std::endl;
    return 0;
}