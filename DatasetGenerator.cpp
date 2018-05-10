//
// Created by Fei Li on 2018/5/9.
//

#include "DatasetGenerator.h"
#include "Randomizer.h"

DatasetGenerator::DatasetGenerator(double _width, double _height,
                                   double _radius, int _num) {
    defaultWidth = _width;
    defaultHeight = _height;
    defaultRadius = _radius;
    defaultNum = _num;
}

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
    Randomizer randomizer = Randomizer();
    for (int i = 0; i < num; i++) {
        double r = randomizer.generate(0.0, radius);
        double theta = randomizer.generate(0.0, 2.0 * M_PI);
        dataset.push_back(Point(r * cos(theta), r * sin(theta)));
    }
    return dataset;
}