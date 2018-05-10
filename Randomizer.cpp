//
// Created by Fei Li on 2018/5/9.
//

#include "Randomizer.h"

Randomizer::Randomizer() {
    gen.seed(rd());
}

double Randomizer::generate(double floor, double ceil) {
    std::uniform_real_distribution<> dis(floor, ceil);
    return dis(gen);
}