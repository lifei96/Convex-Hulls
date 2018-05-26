//
// Created by Fei Li on 2018/5/26.
//

#ifndef CONVEX_HULLS_JARVIS_H
#define CONVEX_HULLS_JARVIS_H

#include "Point.h"
#include <vector>

class Jarvis {
public:
    std::vector<Point> jarvis(std::vector<Point> &dataset);
};


#endif //CONVEX_HULLS_JARVIS_H
