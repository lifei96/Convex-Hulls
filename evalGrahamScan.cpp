//
// Created by Fei Li on 2018/5/16.
//

#include "GrahamScan.h"
#include "Timer.h"
#include <iostream>
#include <fstream>
#include <iomanip>

std::string SHAPES[] = {"square", "rectangle", "circle", "squareNormal",
                        "squareReverseNormal"};
std::string RESULT_PATH = "result/GrahamScan.txt";

int main() {
    std::ofstream outfile;
    outfile.open(RESULT_PATH);
    for (std::string shape: SHAPES) {
        for (int num = 100000; num < 10000000; num <<= 1) {
            Timer timer;
            std::vector<Point> dataset = util::readDataset(
                    "dataset/" + shape + "_" + std::to_string(num) + ".txt");
            timer.start();
            GrahamScan grahamScan;
            grahamScan.grahamScan(dataset);
            timer.stop();
            std::cout << shape << " " << num << " " << timer.getDuration()
                      << std::endl;
            outfile << std::setiosflags(std::ios::fixed) << std::setprecision(6)
                    << shape << " " << num << " " << timer.getDuration()
                    << std::endl;

        }
    }
    outfile.close();
    return 0;
}