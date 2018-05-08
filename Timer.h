//
// Created by Fei Li on 2018/5/8.
//

#ifndef CONVEX_HULLS_TIMER_H
#define CONVEX_HULLS_TIMER_H


#include <ctime>

class Timer {
private:
    std::clock_t startClock;
    std::clock_t stopClock;
public:
    void start();

    void stop();

    double getDuration();
};


#endif //CONVEX_HULLS_TIMER_H
