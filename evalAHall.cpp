//
// Created by Fei Li on 2018/5/26.
//

#include "AHall.h"
#include "Timer.h"
#include "util.h"
#include <iostream>

int main() {
    int num = 100000;
    Timer timer;
    std::vector<Point> dataset = util::readDataset(
            "dataset/circle_" + std::to_string(num) + ".txt");
    timer.start();
    AHall aHall(dataset);
    aHall.aHall();
    timer.stop();
    std::cout << timer.getDuration() << std::endl;
    return 0;
}