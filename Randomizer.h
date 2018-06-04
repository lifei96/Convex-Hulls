//
// Created by Fei Li on 2018/5/9.
//

#ifndef CONVEX_HULLS_RANDOMIZER_H
#define CONVEX_HULLS_RANDOMIZER_H


#include <random>

class Randomizer {
public:
    double generate(double floor, double ceil);
    double generateNormal(double mean, double stddev);
    double generateReverseNormal(double mean, double stddev, double half);
};


#endif //CONVEX_HULLS_RANDOMIZER_H
