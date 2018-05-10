//
// Created by Fei Li on 2018/5/9.
//

#ifndef CONVEX_HULLS_DATASETGENERATOR_H
#define CONVEX_HULLS_DATASETGENERATOR_H


#include <vector>
#include "Point.h"

class DatasetGenerator {
private:
    double defaultWidth;
    double defaultHeight;
    double defaultRadius;
    int defaultNum;
public:
    DatasetGenerator(double _width = 1.0, double _height = 1.0,
                     double _radius = 1.0, int _num = 100000);

    std::vector<Point> generateRectangle(double width = defaultWidth,
                                         double height = defaultHeight,
                                         int num = defaultNum);

    std::vector<Point>
    generateCircle(double radius = defaultRadius, int num = defaultNum);

};


#endif //CONVEX_HULLS_DATASETGENERATOR_H
