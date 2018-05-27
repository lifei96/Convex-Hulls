//
// Created by Fei Li on 2018/5/26.
//

#ifndef CONVEX_HULLS_AHALL_H
#define CONVEX_HULLS_AHALL_H

#include "Point.h"
#include <vector>


class AHall {
private:
    class xOrder {
    public:
        xOrder() {}

        bool operator()(const Point &a, const Point &b) {
            return a.getX() < b.getX() ||
                   (a.getX() == b.getX() && a.getY() < b.getY());
        }
    };

    std::vector<Point> dataset;
    std::vector<int> ld;
    std::vector<int> rd;
    std::vector<int> lu;
    std::vector<int> ru;
    std::vector<int> ACH;
    std::vector<Point> CH;
    int l, r, u, d;

    void getPoles();

    void getld();

    void getrd();

    void getlu();

    void getru();

    void getACH();

    void getCH();

public:
    AHall(std::vector<Point> &dataset);

    std::vector<Point> aHall();

    std::string print();
};


#endif //CONVEX_HULLS_AHALL_H
