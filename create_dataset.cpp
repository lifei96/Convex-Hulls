//
// Created by Fei Li on 2018/5/16.
//
#include "DatasetGenerator.h"
#include "util.h"

int main() {
    DatasetGenerator datasetGenerator;
    for (int num = 100000; num < 10000000; num <<= 1) {
        std::vector<Point> dataset = datasetGenerator.generateRectangle(1.0, 1.0, num);
        util::writeDataset(dataset, "dataset/square_" + std::to_string(num) + ".txt");
        dataset = datasetGenerator.generateCircle(1.0, num);
        util::writeDataset(dataset, "dataset/circle_" + std::to_string(num) + ".txt");
        dataset = datasetGenerator.generateRectangle(2.0, 1.0, num);
        util::writeDataset(dataset, "dataset/rectangle_" + std::to_string(num) + ".txt");
    }
    return 0;
}