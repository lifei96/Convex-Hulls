//
// Created by Fei Li on 2018/5/9.
//

#include "DatasetGenerator.h"
#include "Randomizer.h"
#include <iostream>

std::vector<Point> DatasetGenerator::generateRectangle(double width,
                                                       double height,
                                                       int num) {
    std::vector<Point> dataset;
    Randomizer randomizer = Randomizer();
    for (int i = 0; i < num; i++) {
        dataset.push_back(Point(randomizer.generate(0.0, width),
                                randomizer.generate(0.0, height)));
    }
    return dataset;
}

std::vector<Point> DatasetGenerator::generateCircle(double radius, int num) {
    std::vector<Point> dataset;
    Randomizer randomizer;
    for (int i = 0; i < num; i++) {
        double r = randomizer.generate(0.0, radius);
        double theta = randomizer.generate(0.0, 2.0 * M_PI);
        dataset.push_back(
                Point(r * cos(theta) + radius, r * sin(theta) + radius));
    }
    return dataset;
}

std::vector<Point> DatasetGenerator::generateNormalCircle(double radius,
                                                          int num,
                                                          double mean,
                                                          double stddev) {
    std::vector<Point> dataset;
    Randomizer randomizer = Randomizer();
    for (int i = 0; i < num; i++) {
        double r = abs(randomizer.generateNormal(mean, stddev));
        while (r > radius) {
            r = abs(randomizer.generateNormal(mean, stddev));
        }
        double theta = randomizer.generate(0.0, 2.0 * M_PI);
        dataset.push_back(
                Point(r * cos(theta) + radius, r * sin(theta) + radius));
    }
    return dataset;
}

std::vector<Point> DatasetGenerator::generateReverseNormalCircle(double radius,
                                                                 int num,
                                                                 double mean,
                                                                 double stddev) {
    std::vector<Point> dataset;
    Randomizer randomizer = Randomizer();
    for (int i = 0; i < num; i++) {
        double r = radius - abs(randomizer.generateNormal(mean, stddev));
        while (r < 0 || r > radius) {
            r = radius - abs(randomizer.generateNormal(mean, stddev));
        }
        double theta = randomizer.generate(0.0, 2.0 * M_PI);
        dataset.push_back(
                Point(r * cos(theta) + radius, r * sin(theta) + radius));
    }
    return dataset;
}
