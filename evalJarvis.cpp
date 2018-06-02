//
// Created by Fei Li on 2018/5/26.
//

#include "Jarvis.h"
#include "Timer.h"
#include "util.h"
#include <iostream>
#include <fstream>
#include <iomanip>

std::string SHAPES[] = {"square", "rectangle", "circle", "squareNormal"};
std::string RESULT_PATH = "result/Jarvis.txt";

int main() {
    std::ofstream outfile;
    outfile.open(RESULT_PATH);
    for (std::string shape: SHAPES) {
        for (int num = 100000; num < 10000000; num <<= 1) {
            Timer timer;
            std::vector<Point> dataset = util::readDataset(
                    "dataset/" + shape + "_" + std::to_string(num) + ".txt");
            timer.start();
            Jarvis jarvis;
            jarvis.jarvis(dataset);
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