//
// Created by Fei Li on 2018/5/26.
//

#include "MonotoneChain.h"
#include "Timer.h"
#include "util.h"
#include <iostream>

int main() {
    MonotoneChain monotoneChain;
    int num = 100000;
    Timer timer;
    std::vector<Point> dataset = util::readDataset(
            "dataset/circle_" + std::to_string(num) + ".txt");
    timer.start();
    monotoneChain.monotoneChain(dataset);
    timer.stop();
    std::cout << timer.getDuration() << std::endl;
    return 0;
}