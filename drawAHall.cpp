//
// Created by Fei Li on 2018/5/26.
//

#include "AHall.h"
#include "Timer.h"
#include "util.h"
#include <iostream>
#include <fstream>
#include <iomanip>

std::string SHAPES[] = {"square", "rectangle", "circle"};

int main() {
    std::ofstream outfile;
    for (std::string shape: SHAPES) {
        for (int num = 50; num < 60; num <<= 1) {
            Timer timer;
            std::vector<Point> dataset = util::readDataset(
                    "dataset/" + shape + "_" + std::to_string(num) + ".txt");
            timer.start();
            AHall aHall(dataset);
            aHall.aHall();
            timer.stop();
            outfile.open("result/DrawAHall_" + shape + ".txt");
            outfile << aHall.print();
            outfile.close();
        }
    }
    return 0;
}