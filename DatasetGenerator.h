//
// Created by Fei Li on 2018/5/9.
//

#ifndef CONVEX_HULLS_DATASETGENERATOR_H
#define CONVEX_HULLS_DATASETGENERATOR_H


#include <vector>
#include "Point.h"

class DatasetGenerator {
public:
    std::vector<Point> generateRectangle(double width, double height, int num);

    std::vector<Point> generateCircle(double radius, int num);

    std::vector<Point> generateNormalCircle(double radius,
                                            int num,
                                            double mean,
                                            double stddev);

    std::vector<Point> generateReverseNormalCircle(double radius,
                                                   int num,
                                                   double mean,
                                                   double stddev);
};


#endif //CONVEX_HULLS_DATASETGENERATOR_H
