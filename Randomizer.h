//
// Created by Fei Li on 2018/5/9.
//

#ifndef CONVEX_HULLS_RANDOMIZER_H
#define CONVEX_HULLS_RANDOMIZER_H


#include <random>

class Randomizer {
private:
    std::random_device rd;
    std::mt19937 gen;
public:
    Randomizer();

    double generate(double floor, double ceil);
};


#endif //CONVEX_HULLS_RANDOMIZER_H
