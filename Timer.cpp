//
// Created by Fei Li on 2018/5/8.
//

#include "Timer.h"

void Timer::start() {
    startClock = std::clock();
}

void Timer::stop() {
    stopClock = std::clock();
}

double Timer::getDuration() {
    return (stopClock - startClock) / (double) CLOCKS_PER_SEC;
}
