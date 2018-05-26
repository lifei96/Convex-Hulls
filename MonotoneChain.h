//
// Created by Fei Li on 2018/5/26.
//

#ifndef CONVEX_HULLS_MONOTONECHAIN_H
#define CONVEX_HULLS_MONOTONECHAIN_H


class MonotoneChain {
private:
    class xOrder {
    public:
        xOrder() {}
        bool operator()(const Point &a, const Point &b) {
            return a.getX() < b.getX() || (a.getX() == b.getY() && a.getY() < b.getY());
        }
    };

public:

};


#endif //CONVEX_HULLS_MONOTONECHAIN_H
