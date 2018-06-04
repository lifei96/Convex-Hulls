//
// Created by Fei Li on 2018/5/9.
//

#include "Randomizer.h"

double Randomizer::generate(double floor, double ceil) {
    std::random_device rd;
    std::mt19937 gen;
    gen.seed(rd());
    std::uniform_real_distribution<> dis(floor, ceil);
    return dis(gen);
}

double Randomizer::generateNormal(double mean, double stddev) {
    std::random_device rd;
    std::mt19937 gen;
    gen.seed(rd());
    std::normal_distribution<double> dis(mean, stddev);
    return dis(gen);
}

double Randomizer::generateReverseNormal(double mean, double stddev, double half) {
    std::random_device rd;
    std::mt19937 gen;
    gen.seed(rd());
    std::normal_distribution<double> dis(mean, stddev);
    double t = dis(gen);
    if (t > mean) return half - t + mean * 2.0;
    return mean * 2.0 - half - t;
}