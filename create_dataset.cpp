//
// Created by Fei Li on 2018/5/16.
//
#include "DatasetGenerator.h"
#include "util.h"

int main() {
    DatasetGenerator datasetGenerator;
    for (int num = 100000; num < 10000000; num <<= 1) {
        std::vector<Point> dataset;
        dataset = datasetGenerator.generateRectangle(10.0, 10.0, num);
        util::writeDataset(dataset,
                           "dataset/square_" + std::to_string(num) + ".txt");
        dataset = datasetGenerator.generateCircle(5.0, num);
        util::writeDataset(dataset,
                           "dataset/circle_" + std::to_string(num) + ".txt");
        dataset = datasetGenerator.generateRectangle(20.0, 10.0, num);
        util::writeDataset(dataset,
                           "dataset/rectangle_" + std::to_string(num) + ".txt");

        dataset = datasetGenerator.generateNormalCircle(5.0, num, 0.0, 1.5);
        util::writeDataset(dataset,
                           "dataset/squareNormal_" + std::to_string(num) +
                           ".txt");
        dataset = datasetGenerator.generateReverseNormalCircle(5.0,
                                                               num,
                                                               0.0,
                                                               1.5);
        util::writeDataset(dataset,
                           "dataset/squareReverseNormal_" +
                           std::to_string(num) + ".txt");
    }
    return 0;
}