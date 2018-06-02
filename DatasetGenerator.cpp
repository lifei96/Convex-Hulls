//
// Created by Fei Li on 2018/5/9.
//

#include "DatasetGenerator.h"
#include "Randomizer.h"

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

std::vector<Point> DatasetGenerator::generateNormalRectangle(double width,
                                                             double height,
                                                             int num,
                                                             double mean,
                                                             double stddev) {
    std::vector<Point> dataset;
    Randomizer randomizer = Randomizer();
    for (int i = 0; i < num; i++) {
        double x = randomizer.generateNormal(mean, stddev);
        double y = randomizer.generateNormal(mean, stddev);
        while (x < 0 || x > width) {
            x = randomizer.generateNormal(mean, stddev);
        }
        while (y < 0 || y > width) {
            y = randomizer.generateNormal(mean, stddev);
        }
        dataset.push_back(Point(x, y));
    }
    return dataset;
}