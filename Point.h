//
// Created by Fei Li on 2018/5/8.
//

#ifndef CONVEX_HULLS_POINT_H
#define CONVEX_HULLS_POINT_H


class Point {
private:
    double x, y;
public:
    Point(double _x = 0.0, double _y = 0.0);
    double getX();
    double getY();
};


#endif //CONVEX_HULLS_POINT_H
